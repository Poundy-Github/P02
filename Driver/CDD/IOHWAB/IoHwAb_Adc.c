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
 * @file:      IoHwAb_Adc.c
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

#include "IoHwAb_Adc.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"
#include <string.h>

#define IoHwAb_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

IOHWAB_ADC_DATA_STR IoHwAb_Adc_Data;

#define IoHwAb_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * IoHwAb_Adc_Init
 **********************************************************************************************************************/
/*! \brief      This method is the IoHwAb_Adc initialization function. If initialization is needed, add the code to this
 *              function.call by IoHwAb init process
 *  \return     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_Adc_Init (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/

	uint8 adc_group_cnt;
	
	for(adc_group_cnt = 0u; adc_group_cnt < IoHwAb_Adc_MaxGroups; adc_group_cnt++)
	{
		(void)Adc_SetupResultBuffer(adc_group_cnt,IoHwAb_Adc_Data.AdcRaw[adc_group_cnt]);
		Adc_StartGroupConversion(adc_group_cnt);
	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* IoHwAb_Adc_Init() */

/**********************************************************************************************************************
 * IoHwAb_Adc_MainFunction
 **********************************************************************************************************************/
/*! \brief      This method is the IoHwAb main function. trigeered every 10(tbd) ms by IoHwAb
 *  \return     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_Adc_MainFunction (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/
	Adc_StatusType adc_st[2] = {ADC_IDLE,ADC_IDLE};
	uint8 adc_group_cnt;
	uint8 adc_group_channel;	
	uint8 adc_hw_channel_cnt;/*hw channel id*/
	uint8 adc_channel_cnt;/*ad cfg channnel id */
	uint8 TmpFilterId;
    uint32 TmpValue;
    Std_ReturnType Ret = E_OK;


	
	for(adc_group_cnt = 0u; adc_group_cnt < IoHwAb_Adc_MaxGroups; adc_group_cnt++)
	{
		adc_st[adc_group_cnt] = Adc_GetGroupStatus(adc_group_cnt);

		if(ADC_STREAM_COMPLETED == adc_st[adc_group_cnt])
		{
			(void)Adc_ReadGroup(adc_group_cnt,IoHwAb_Adc_Data.AdcRaw[adc_group_cnt]);
			
		}

		if((ADC_IDLE == adc_st[adc_group_cnt])||(ADC_STREAM_COMPLETED == adc_st[adc_group_cnt]))
		{
			Adc_StartGroupConversion(adc_group_cnt);
		}
	}
	
	for(adc_channel_cnt = 0u; adc_channel_cnt < IoHwAb_AIn_Cfg_Count; adc_channel_cnt++)
	{
				
		adc_group_channel = CIoHwAb_AIn_VoltageInCfg[adc_channel_cnt].HwId;
		adc_hw_channel_cnt = CIoHwAb_AIn_VoltageInCfg[adc_channel_cnt].HwIdEx;
		
		TmpValue = IoHwAb_Adc_Data.AdcRaw[adc_group_channel][adc_hw_channel_cnt];  
		CIoHwAb_AIn_VoltageInCfg[adc_channel_cnt].pRAM->HwValue = TmpValue;
		TmpFilterId = CIoHwAb_AIn_VoltageInCfg[adc_channel_cnt].FilterId;

		/*do filter */
		if(IOHWAB_MAX_FILTER_COUNT > TmpFilterId)
		{
			Ret = IoHwAb_FiltersWrapper_ApplyFilter(TmpFilterId, TmpValue, &TmpValue); 
			
			CIoHwAb_AIn_VoltageInCfg[adc_channel_cnt].pRAM->Status = Ret;
			CIoHwAb_AIn_VoltageInCfg[adc_channel_cnt].pRAM->AppValue = CIoHwAb_Input_Convert(CIoHwAb_AIn_VoltageInCfg[adc_channel_cnt], TmpValue);
		}
			
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* IoHwAb_Adc_MainFunction() */

#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

