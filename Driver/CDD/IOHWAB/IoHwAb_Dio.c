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
 * @file:      IoHwAb_Dio.c
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

#include "IoHwAb_Dio.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"
#include <string.h>

#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * IoHwAb_Dio_Init
 **********************************************************************************************************************/
/*! \brief      This method is the IoHwAb_Dio initialization function. If initialization is needed, add the code to this
 *              function.call by IoHwAb init process
 *  \return     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_Dio_Init (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/

	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* IoHwAb_Dio_Init() */

/**********************************************************************************************************************
 * IoHwAb_Dio_MainFunction
 **********************************************************************************************************************/
/*! \brief      This method is the IoHwAb main function. trigeered every 10(tbd) ms by IoHwAb
 *  \return     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_Dio_MainFunction (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/
    uint16 ChannelIndex;
    THwData HwValue;
    uint8 TmpFilter;
	Std_ReturnType Ret = E_OK;

	/**********************INPUT******************************************************/	
	
	for (ChannelIndex = 0u; ChannelIndex < IoHwAb_DIn_PinInCfg_Count; ChannelIndex++)
	{
		/* Dio Pins */
		if((EIoHwAb_Signal_Type)cIoHwAb_Signal_DigitalInput == CIoHwAb_DIn_PinInCfg[ChannelIndex].Type)
		{
			/* Read Input*/
			HwValue = (Dio_LevelType)Dio_ReadChannel((Dio_ChannelType)CIoHwAb_DIn_PinInCfg[ChannelIndex].HwId);

			CIoHwAb_DIn_PinInCfg[ChannelIndex].pRAM->HwValue = HwValue;
			TmpFilter = CIoHwAb_DIn_PinInCfg[ChannelIndex].FilterId;
			
			/*do filter */
			if(IOHWAB_MAX_FILTER_COUNT > TmpFilter)
			{
				Ret = IoHwAb_FiltersWrapper_ApplyFilter(TmpFilter, HwValue, &HwValue); 
				CIoHwAb_DIn_PinInCfg[ChannelIndex].pRAM->Status = Ret;
				
				CIoHwAb_DIn_PinInCfg[ChannelIndex].pRAM->AppValue = CIoHwAb_Input_Convert(CIoHwAb_DIn_PinInCfg[ChannelIndex], HwValue);
			}
		}
	}
	/**********************OUTPUT******************************************************/ 
	for (ChannelIndex = 0u; ChannelIndex < IoHwAb_DOut_PinOutCfg_Count; ChannelIndex++)
	{
		if(TRUE == CIoHwAb_DOut_PinOutCfg[ChannelIndex].IsPeriod)
		{
			/* Dio Pins */
			if((EIoHwAb_Signal_Type)cIoHwAb_Signal_DigitalOutput == CIoHwAb_DOut_PinOutCfg[ChannelIndex].Type)
			{
				TmpFilter = CIoHwAb_DOut_PinOutCfg[ChannelIndex].FilterId;
				HwValue = CIoHwAb_Output_Convert(CIoHwAb_DOut_PinOutCfg[ChannelIndex], CIoHwAb_DOut_PinOutCfg[ChannelIndex].pRAM->AppValue);

				/*do filter */
				if(IOHWAB_MAX_FILTER_COUNT > TmpFilter)
				{
					(void)IoHwAb_FiltersWrapper_ApplyFilter(TmpFilter, HwValue, &HwValue); 
					
					CIoHwAb_DOut_PinOutCfg[ChannelIndex].pRAM->HwValue = HwValue;
				}
			
	        	Dio_WriteChannel((Dio_ChannelType)CIoHwAb_DOut_PinOutCfg[ChannelIndex].HwId, (Dio_LevelType)HwValue);

			}
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* IoHwAb_Dio_MainFunction() */


#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

