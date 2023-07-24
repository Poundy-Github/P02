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
 * @file:      IoHwAb_HsLsDrv.c
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

#include "IoHwAb_HsLsDrv.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"
#include <string.h>
#include <Pwm.h>
#include <Dio.h>

#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static void HsLs_Chip_Init(uint8 Chip_type, uint8 Chip_id);
static void HsLs_Chip_Cfg(EIoHwAb_HsLs_Chip_Type Chip_type, uint8 Chip_id, uint8 Chip_chn, uint32 Output_Type);
static uint16 gcd(uint16 input1, uint16 input2);
static uint64 lcm(uint64 input1, uint64 input2);
static uint64 HSLS_Period_lcm(void);

static uint64 HsLs_Period_LCM;
static uint64 HsLs_Period_Running;
#define FACTOR_100MS			100
#define COUNTER_EVERY_CYCLE		5

/**********************************************************************************************************************
 * IoHwAb_HsLsDrv_Init
 **********************************************************************************************************************/
/*! \brief      This method is the IoHwAb_Dio initialization function. If initialization is needed, add the code to this
 *              function.call by IoHwAb init process
 *  \return     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_HsLsDrv_Init (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/
	uint8 Chip_type_cnt;
	uint8 Chip_number;
	uint8 ChannelIndex;

	HsLs_Period_LCM = HSLS_Period_lcm()*FACTOR_100MS;
	HsLs_Period_Running = HsLs_Period_LCM;
	
	for(ChannelIndex = 0; ChannelIndex < IoHwAb_HsLs_Cfg_Count; ChannelIndex++)
	{
		HsLs_Chip_Cfg(CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.Type, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.HwId, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.HwIdEx,CIoHwAb_HSLS_Cfg[ChannelIndex].DirectHwType);
	}

	for(Chip_type_cnt = 0; Chip_type_cnt < IoHwAb_HsLs_Chip_Type_Count; Chip_type_cnt++)
	{
		for(Chip_number = 0; Chip_number < CIoHwAb_HsLs_Chip_Count[Chip_type_cnt]; Chip_number++)
		{
			HsLs_Chip_Init(Chip_type_cnt,Chip_number);
		}
	}
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* IoHwAb_HsLsDrv_Init() */

/**********************************************************************************************************************
 * IoHwAb_HsLsDrv_MainFunction
 **********************************************************************************************************************/
/*! \brief      This method is the IoHwAb main function. trigeered every 10(tbd) ms by IoHwAb
 *  \return     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_HsLsDrv_MainFunction (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/
    uint16 ChannelIndex;
    THwData HwValue;
    uint8 TmpFilter;

	
	for (ChannelIndex = 0u; ChannelIndex < IoHwAb_HsLs_Cfg_Count; ChannelIndex++)
	{
		if(TRUE == CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.IsPeriod)
		{

			if(0 == (HsLs_Period_Running % (CIoHwAb_HSLS_Cfg[ChannelIndex].RefreshPeriod*FACTOR_100MS)))
			{
				/******************** convert implementation *********************************/
			
				TmpFilter = CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.FilterId;
				HwValue = CIoHwAb_Output_Convert(CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.pRAM->AppValue);

				/******************** filter implementation *********************************/

				if(IOHWAB_MAX_FILTER_COUNT > TmpFilter)
				{
					(void)IoHwAb_FiltersWrapper_ApplyFilter(TmpFilter, HwValue, &HwValue); 
					
					CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.pRAM->HwValue = HwValue;
				}

				/********************* output update ****************************************/
				switch(CIoHwAb_HSLS_Cfg[ChannelIndex].DirectHwType)
				{
					case cIoHwAb_HsLs_Spi:
						
						HsLs_Chip_SetOutput(CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.Type, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.HwId, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.HwIdEx, HwValue);

						break;
					case cIoHwAb_HsLs_Direct_Pwm:

						Pwm_SetDutyCycle((Pwm_ChannelType)CIoHwAb_HSLS_Cfg[ChannelIndex].DirectHwId, (uint16)HwValue);					
						HsLs_Chip_SetOutput(CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.Type, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.HwId, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.HwIdEx, HwValue);

						break;
					case cIoHwAb_HsLs_Direct_Dio:
						
						Dio_WriteChannel((Dio_ChannelType)CIoHwAb_HSLS_Cfg[ChannelIndex].DirectHwId, (Dio_LevelType)HwValue);
						HsLs_Chip_SetOutput(CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.Type, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.HwId, CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.HwIdEx, HwValue);

						break;
					default:
						/* nothing to do */
						break;

				}		
			}
		}
	}

	if(HsLs_Period_Running < HsLs_Period_LCM)
	{
		HsLs_Period_Running = HsLs_Period_Running + COUNTER_EVERY_CYCLE;
	}
	else
	{
		HsLs_Period_Running = 0;
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* IoHwAb_HsLsDrv_MainFunction() */


static void HsLs_Chip_Init(uint8 Chip_type , uint8 Chip_id)
{
	/*send the chip cfg init info via spi*/

	switch (Chip_type)
	{
		case cIoHwAb_HsLs_ChipType0:
			/*cfg and init VNQ7004SY chip with Chip_id */
			break;
		case cIoHwAb_HsLs_ChipType1:
			/*cfg and init VNQ7050AJ chip with Chip_id  */
			break;
		case cIoHwAb_HsLs_ChipType2:
			/*cfg and init TLE75080ESH chip with Chip_id */
			break;
		default:
			/* nothing to do */
			break;
	}

}

void HsLs_Chip_SetOutput(EIoHwAb_HsLs_Chip_Type Chip_type, uint8 Chip_id, uint8 Chip_chn, uint32 Output_value)
{
	/*send the channel outpuut value to driver, this function will has two usages:
	  1.notify the driver of the channel state: ON or OFF
	  2.change the channel value which is chontrolled by spi , then wait the chip driver to update the output in it's mainfunction*/
	  
	switch (Chip_type)
	{
		case cIoHwAb_HsLs_ChipType0:
			/*set VNQ7004SY chip with Chip_id,Chip_chn and value */
			break;
		case cIoHwAb_HsLs_ChipType1:
			/*set VNQ7050AJ chip with Chip_id ,Chip_chn and value  */
			break;
		case cIoHwAb_HsLs_ChipType2:
			/*set TLE75080ESH chip with Chip_id ,Chip_chn and value */
			break;
		default:
			/* nothing to do */
			break;
	}

}

static void HsLs_Chip_Cfg(EIoHwAb_HsLs_Chip_Type Chip_type, uint8 Chip_id, uint8 Chip_chn, uint32 Output_Type)
{
	/*cfg the chip to indicate the channel type:SPI or Direct IO or Direct Pwm*/
	/*the chip driver set the mask for the channel type for two usages:
	  1. do chip config in HsLs_Chip_Init function
	  2. decide if send the SPI to fullfill the outptut according to the mask*/
	  
	switch (Chip_type)
	{
		case cIoHwAb_HsLs_ChipType0:
			/*set VNQ7004SY chip with Chip_id,Chip_chn and type */
			break;
		case cIoHwAb_HsLs_ChipType1:
			/*set VNQ7050AJ chip with Chip_id ,Chip_chn and type  */
			break;
		case cIoHwAb_HsLs_ChipType2:
			/*set TLE75080ESH chip with Chip_id ,Chip_chn and type */
			break;
		default:
			/* nothing to do */
			break;
	}

}
/*Greatest Common Dividend*/
static uint16 gcd(uint16 input1, uint16 input2)
{
	uint16 temp;
	uint16 temp_b,temp_s;
	
	if(input1>=input2)
	{
		temp_b = input1;
		temp_s = input2;
	}
	else
	{		
		temp_b = input2;
		temp_s = input1;
	}
	
	while(0 != temp_s)
	{
		 temp = temp_s;
		 temp_s = temp_b%temp_s;
		 temp_b = temp;
	}
	return temp_b;

}

/*Least Common Multiple*/
static uint64 lcm(uint64 input1, uint64 input2)
{
	if(input2 != 0)
	{
		return (input1/gcd((uint16)input1, (uint16)input2))*(uint64)input2;
	}
	else
	{
		return input1;
	}

}

static uint64 HSLS_Period_lcm(void)
{
    uint16 ChannelIndex;
	uint16 period[IoHwAb_HsLs_Cfg_Count];
	uint16 period_index;
	uint16 temp_index;
	uint8 same_flag;
	uint64 temp_lcm;
	uint64 lcm_period;
	

	(void)memset((uint8 *)period,0,sizeof(period));
	period_index = 0U; /* MISRA C-2012 Rule 14.3 */

	for (ChannelIndex = 0u; ChannelIndex < IoHwAb_HsLs_Cfg_Count; ChannelIndex++)
	{
		if(TRUE == CIoHwAb_HSLS_Cfg[ChannelIndex].BasicCfg.IsPeriod)
		{
			same_flag = 0U;

			for(temp_index = 0u; temp_index < period_index ; temp_index++)
			{
				if(CIoHwAb_HSLS_Cfg[ChannelIndex].RefreshPeriod == period[temp_index])
				{
					same_flag = 1U;
					break;
				}
			}
			
			/*if no same data in buffer , copy period value into temp buffer*/
			if(0U == same_flag)
			{
				period[period_index++] = CIoHwAb_HSLS_Cfg[ChannelIndex].RefreshPeriod;
			}
			
		}
	}
	
	if(period_index == 0U)
	{
		lcm_period = 0U;
	}
	else if(period_index == 1U)
	{
		lcm_period = period[0];
	}
	else
	{	
		temp_lcm = period[0];
		
		for(temp_index = 1u; temp_index < period_index ; temp_index++)
		{
			temp_lcm = lcm(temp_lcm,period[temp_index]);
		}
		lcm_period = temp_lcm;
	}

	return lcm_period;
}

#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

