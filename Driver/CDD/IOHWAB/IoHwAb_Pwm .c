/**
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.
* All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are NOT permitted except as agreed by
* Nobo Automotive Technologies Co.,Ltd.
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
/**
 **********************************************************************************************************************
 * @file:      IoHwAb_Pwm.c
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "IoHwAb_Pwm.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"
#include <string.h>

#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * IoHwAb_Pwm_Init
 **********************************************************************************************************************/
/*! \brief      This method is the IoHwAb_Pwm initialization function. If initialization is needed, add the code to this
 *              function.call by IoHwAb init process
 *  \return     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_Pwm_Init (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/

	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* IoHwAb_Pwm_Init() */

/**********************************************************************************************************************
 * IoHwAb_Pwm_MainFunction
 **********************************************************************************************************************/
/*! \brief      This method is the IoHwAb main function. trigeered every 10(tbd) ms by IoHwAb
 *  \return     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_Pwm_MainFunction (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/
    uint16 ChannelIndex;
    THwData HwPeriodValue;
	THwData HwDutyValue;
    uint8 TmpFilter;

	/**********************PERIOD******************************************************/	
	
	for (ChannelIndex = 0u; ChannelIndex < IoHwAb_Pwm_PeriodOutCfg_Count; ChannelIndex++)
	{
		if(TRUE == CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex].IsPeriod)
		{
			/* Dio Pins */
			if((EIoHwAb_Signal_Type)cIoHwAb_Signal_PwmOutputPeriod == CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex].Type)
			{
				TmpFilter = CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex].FilterId;
				HwPeriodValue = CIoHwAb_Output_Convert(CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex], CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex].pRAM->AppValue);
				HwDutyValue =  (uint32)(((uint64)CIoHwAb_Pwm_DutyOutCfg[ChannelIndex].pRAM->AppValue*0x8000)/1000);

				/*do filter */
				if(IOHWAB_MAX_FILTER_COUNT > TmpFilter)
				{
					(void)IoHwAb_FiltersWrapper_ApplyFilter(TmpFilter, HwPeriodValue, &HwPeriodValue); 
					CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex].pRAM->HwValue = HwPeriodValue;
					
					(void)IoHwAb_FiltersWrapper_ApplyFilter(TmpFilter, HwDutyValue, &HwDutyValue); 				
					CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex].pRAM->HwValue = HwDutyValue;
				}

							
	        	Pwm_SetPeriodAndDuty((Pwm_ChannelType)CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex].HwId, (Pwm_PeriodType)HwPeriodValue,(uint16)HwDutyValue);
			}
		}
	}
	/**********************DUTY******************************************************/ 
	for (ChannelIndex = 0u; ChannelIndex < IoHwAb_Pwm_DutyOutCfg_Count; ChannelIndex++)
	{
		if(TRUE == CIoHwAb_Pwm_DutyOutCfg[ChannelIndex].IsPeriod)
		{
			/* Dio Pins */
			if((EIoHwAb_Signal_Type)cIoHwAb_Signal_PwmOutputDuty == CIoHwAb_Pwm_DutyOutCfg[ChannelIndex].Type)
			{
				TmpFilter = CIoHwAb_Pwm_DutyOutCfg[ChannelIndex].FilterId;
				HwDutyValue = (uint32)(((uint64)CIoHwAb_Pwm_DutyOutCfg[ChannelIndex].pRAM->AppValue*0x8000)/1000);

				/*do filter */
				if(IOHWAB_MAX_FILTER_COUNT > TmpFilter)
				{
					(void)IoHwAb_FiltersWrapper_ApplyFilter(TmpFilter, HwDutyValue, &HwDutyValue); 
					
					CIoHwAb_Pwm_DutyOutCfg[ChannelIndex].pRAM->HwValue = HwDutyValue;
				}
			
				Pwm_SetDutyCycle((Pwm_ChannelType)(CIoHwAb_Pwm_PeriodOutCfg[ChannelIndex].HwId + 1U), (uint16)HwDutyValue);

			}
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* IoHwAb_Pwm_MainFunction() */


#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

