/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*File Name   : SWC_Gear_config.h                                                                          *
*                                                                                                         *
*Description : Gear module config file.                                                                   *
*                                                                                                         *
*Author      : hai hu                                                                                     *
*                                                                                                         *
*Compiler    : Green Hills  [MULTI IDE 6.1.6]                                                             *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family [RH850/D1M2]                                          *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef GEAR_CFG_H
#define GEAR_CFG_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Std_Types.h"
#include "Vconfig.h"
#include "SWC_Gear_Adapt.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
*																								          *
*																								          *
*	Project Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/
#define GEAR_CFG_PROJECT			(GearMdl_get_vehicle_config())
#define GEAR_CFG_D077_PROJECT		(0U)
#define GEAR_CFG_7DCT_PROJECT		(1U)
#define GEAR_CFG_9DCT_PROJECT		(2U)
#define GEAR_CFG_9HDCT_PROJECT		(3U)
#define GEAR_CFG_8AT_PROJECT		(4U)
#define GEAR_CFG_PHEV_DHT_PROJECT	(5U)
#define GEAR_CFG_HEV_DHT_PROJECT	(6U)
#define GEAR_CFG_EV_PROJECT			(7U)
#define GEAR_CFG_MT_PROJECT			(8U)
#define GEAR_CFG_7DCT300S_PROJECT	(9U)
#define GEAR_CFG_9AT_PROJECT		(10U)
#define GEAR_CFG_NULL_PROJECT		(0xFFU)

#define GEAR_CFG_TRANSMISSION_7DCT		(0x7U)
#define GEAR_CFG_TRANSMISSION_7DCT_300S	(0x26U)
#define GEAR_CFG_TRANSMISSION_7DCT_400S	(0x29U)
#define GEAR_CFG_TRANSMISSION_9DCT		(0xFU)
#define GEAR_CFG_TRANSMISSION_9HDCT		(0x10U)
#define GEAR_CFG_TRANSMISSION_8AT		(0x8U)
#define GEAR_CFG_TRANSMISSION_DHT1		(0x12U)/* 串联DHT */
#define GEAR_CFG_TRANSMISSION_DHT2		(0x13U)/* 混联DHT */
#define GEAR_CFG_TRANSMISSION_9AT		(0x27U)
#define GEAR_CFG_TRANSMISSION_9HAT		(0x28U)
#define GEAR_CFG_TRANSMISSION_5MT_0x1	(0x1U)
#define GEAR_CFG_TRANSMISSION_5MT_0xC	(0xCU)
#define GEAR_CFG_TRANSMISSION_6MT_0x2	(0x2U)
#define GEAR_CFG_TRANSMISSION_6MT_0xD	(0xDU)
#define GEAR_CFG_TRANSMISSION_6MT_0xE	(0xEU)
#define GEAR_CFG_TRANSMISSION_6MT_0x25	(0x25U)

#define GEAR_CFG_FUEL_DIESEL			(0x0U)
#define GEAR_CFG_FUEL_GASOLINE			(0x1U)
#define GEAR_CFG_FUEL_GASOLINE_NATURL	(0x2U)
#define GEAR_CFG_FUEL_HEV				(0x3U)
#define GEAR_CFG_FUEL_PHEV				(0x4U)
#define GEAR_CFG_FUEL_EV				(0x5U)
#define GEAR_CFG_FUEL_NATURL_GAS		(0x7U)

#define GEAR_CFG_POSITION_PS			(0x5U)
#define GEAR_CFG_POSITION_PS_P4			(0x6U)

//#define GEAR_CFG_ENGINE_CONTROL_UNIT	()
#define GEAR_VCONFIG_FEATURE_CAC00	(0x0U)  /* 无发动机控制单元 */
#define GEAR_VCONFIG_FEATURE_CAC10	(0x1U)  /* 联电-汽油 */
#define GEAR_VCONFIG_FEATURE_CAC20	(0x2U)  /* 西门子-汽油 */
#define GEAR_VCONFIG_FEATURE_CAC30	(0x3U)  /* 博世-柴油 */
#define GEAR_VCONFIG_FEATURE_CAC35	(0x4U)  /* 博世-CB18-柴油 */
#define GEAR_VCONFIG_FEATURE_CAC40	(0x5U)  /* 德尔福-柴油 */
#define GEAR_VCONFIG_FEATURE_CAC45	(0x6U)  /* 德尔福-汽油 */
#define GEAR_VCONFIG_FEATURE_CAC50	(0x7U)  /* 新风-柴油 */

#define GEAR_VCONFIG_KIND_TRANSMISSION	                (VCONFIG_KIND_TRANSMISSION)
#define GEAR_VCONFIG_KIND_ENGINE_CONTROL_UNIT           (VCONFIG_KIND_ENGINE_CONTROL_UNIT)
#define GEAR_VCONFIG_KIND_FUEL                          (VCONFIG_KIND_FUEL)
#define GEAR_VCONFIG_KIND_ELECTROMOTOR_POSITION         (VCONFIG_KIND_ELECTROMOTOR_POSITION)

/**********************************************************************************************************
*																								          *
*	Network Configuration																				  *
*																								          *
**********************************************************************************************************/
#define GET_GEAR_MESSAGE_MISSING(status)		((status) != RTE_E_OK)//(((RTE_E_NEVER_RECEIVED & status) == RTE_E_NEVER_RECEIVED) || ((RTE_E_MAX_AGE_EXCEEDED & status) == RTE_E_MAX_AGE_EXCEEDED) || ((RTE_E_COM_STOPPED & status) == RTE_E_COM_STOPPED))
#define Rte_Read_Gear_SINGAL_VCU_FD3_VCU_GearStsIP(y)   (0)//(Rte_Read_Gear_CanSignals(GEAR_CFG_COM_SINGAL_RX_HCU_HP5_DRVMODDISP_, y))

/**********************************************************************************************************
*																								          *
*	Internal Configuration																				  *
*																								          *
**********************************************************************************************************/
#define FIXDISPLAY_1_GEAR_ENABLE                        (gear_vcfg.boCcfgFixDisplayGearEnable)
#define FIXDISPLAY_2_SHIFT_GEAR_RECOMMEND_ENABLE        (gear_vcfg.boCcfgFixDisplayShiftGearRecommendEnable)
#define FIXDISPLAY_6_GEAR_ENABLE                        (gear_vcfg.boCcfgFixDisplay6GearEnable)
#define FIXDISPLAY_6_SHIFT_GEAR_RECOMMEND_ENABLE        (gear_vcfg.boCcfgFixDisplay6ShiftGearRecommendEnable)

#define GEAR_TRUE     (TRUE)
#define GEAR_FALSE    (FALSE)

#define GearMdl_GEAR_R_COUNT           1U//(NVM_R_Gear_Filter_time_VAR_U8)
#define GearMdl_GEAR_N_COUNT           1U//(NVM_N_Gear_Filter_time_VAR_U8)
#define GearMdl_GEAR_OTHER_COUNT       1U//(NVM_Not_R_and_N_Gear_Filter_time_VAR_U8)

#define GEAR_CFG_TIME_TASK_CYCLE    (50u)//ms
#define GEAR_CFG_TIME_3_SEC         (3000u/GEAR_CFG_TIME_TASK_CYCLE)

/**********************************************************************************************************
*	CRC table Configuration																				  *
**********************************************************************************************************/
#define GEAR_CRC_ACK_OK		(1)
#define GEAR_CRC_ACK_ERROR	(0)

#define GEAR_CFG_CRC_TABLE5	\
{		 /*       gear id                        gear crc  */\
		{(uint8) (GearMdl_GEAR_P), (uint32) (0xec0cUL)}, \
		{(uint8) (GearMdl_GEAR_R), (uint32) (0xa1e3UL)}, \
		{(uint8) (GearMdl_GEAR_N), (uint32) (0xc449UL)}, \
		{(uint8) (GearMdl_GEAR_D), (uint32) (0x1842UL)}, \
		{(uint8) (GearMdl_GEAR_D1), (uint32) (0xf93fUL)}, \
		{(uint8) (GearMdl_GEAR_D2), (uint32) (0x505cUL)}, \
		{(uint8) (GearMdl_GEAR_D3), (uint32) (0x7e9dUL)}, \
		{(uint8) (GearMdl_GEAR_D4), (uint32) (0xae1cUL)}, \
		{(uint8) (GearMdl_GEAR_D5), (uint32) (0x4068UL)}, \
		{(uint8) (GearMdl_GEAR_D6), (uint32) (0x4e16UL)}, \
		{(uint8) (GearMdl_GEAR_D7), (uint32) (0x551UL)}, \
		{(uint8) (GearMdl_GEAR_D8), (uint32) (0x5ef3UL)}, \
		{(uint8) (GearMdl_GEAR_D9), (uint32) (0x4f35UL)}, \
		{(uint8) (GearMdl_GEAR_M), (uint32) (0xebe7UL)}, \
		{(uint8) (GearMdl_GEAR_M1), (uint32) (0x78c9UL)}, \
		{(uint8) (GearMdl_GEAR_M2), (uint32) (0xd1aaUL)}, \
		{(uint8) (GearMdl_GEAR_M3), (uint32) (0xff6bUL)}, \
		{(uint8) (GearMdl_GEAR_M4), (uint32) (0x2feaUL)}, \
		{(uint8) (GearMdl_GEAR_M5), (uint32) (0xc19eUL)}, \
		{(uint8) (GearMdl_GEAR_M6), (uint32) (0xcfe0UL)}, \
		{(uint8) (GearMdl_GEAR_M7), (uint32) (0x6127UL)}, \
		{(uint8) (GearMdl_GEAR_M8), (uint32) (0xdf05UL)}, \
 		{(uint8) (GearMdl_GEAR_M9), (uint32) (0xcec3UL)} \
}

#define GEAR_CFG_CRC_TABLE4	\
{		 /*       gear id                        gear crc  */\
		{(uint8) (GearMdl_GEAR_P), (uint32) (0xe094UL)}, \
		{(uint8) (GearMdl_GEAR_R), (uint32) (0x9b31UL)}, \
		{(uint8) (GearMdl_GEAR_N), (uint32) (0x9bbeUL)}, \
		{(uint8) (GearMdl_GEAR_D), (uint32) (0xe024UL)}, \
		{(uint8) (GearMdl_GEAR_D1), (uint32) (0x52baUL)}, \
		{(uint8) (GearMdl_GEAR_D2), (uint32) (0x17edUL)}, \
		{(uint8) (GearMdl_GEAR_D3), (uint32) (0xe8b5UL)}, \
		{(uint8) (GearMdl_GEAR_D4), (uint32) (0x9648UL)}, \
		{(uint8) (GearMdl_GEAR_D5), (uint32) (0xe200UL)}, \
		{(uint8) (GearMdl_GEAR_D6), (uint32) (0xc3bUL)}, \
		{(uint8) (GearMdl_GEAR_D7), (uint32) (0x4110UL)}, \
		{(uint8) (GearMdl_GEAR_D8), (uint32) (0xe535UL)}, \
		{(uint8) (GearMdl_GEAR_D9), (uint32) (0xd3cfUL)}, \
		{(uint8) (GearMdl_GEAR_M), (uint32) (0xec1cUL)}, \
		{(uint8) (GearMdl_GEAR_M1), (uint32) (0x788eUL)}, \
		{(uint8) (GearMdl_GEAR_M2), (uint32) (0x67cbUL)}, \
		{(uint8) (GearMdl_GEAR_M3), (uint32) (0x72dUL)}, \
		{(uint8) (GearMdl_GEAR_M4), (uint32) (0x44bdUL)}, \
		{(uint8) (GearMdl_GEAR_M5), (uint32) (0xc922UL)}, \
		{(uint8) (GearMdl_GEAR_M6), (uint32) (0xe294UL)}, \
		{(uint8) (GearMdl_GEAR_M7), (uint32) (0x5d5cUL)}, \
		{(uint8) (GearMdl_GEAR_M8), (uint32) (0x44d6UL)}, \
 		{(uint8) (GearMdl_GEAR_M9), (uint32) (0x736aUL)} \
}

#define GEAR_CFG_CRC_TABLE3	\
{		 /*       gear id                        gear crc  */\
		{(uint8) (GearMdl_GEAR_P), (uint32) (0xc99bUL)}, \
		{(uint8) (GearMdl_GEAR_R), (uint32) (0x19ccUL)}, \
		{(uint8) (GearMdl_GEAR_N), (uint32) (0xa058UL)}, \
		{(uint8) (GearMdl_GEAR_D), (uint32) (0xe931UL)}, \
		{(uint8) (GearMdl_GEAR_D1), (uint32) (0x77cdUL)}, \
		{(uint8) (GearMdl_GEAR_D2), (uint32) (0xdf17UL)}, \
		{(uint8) (GearMdl_GEAR_D3), (uint32) (0xbd9dUL)}, \
		{(uint8) (GearMdl_GEAR_D4), (uint32) (0x30faUL)}, \
		{(uint8) (GearMdl_GEAR_D5), (uint32) (0xa27dUL)}, \
		{(uint8) (GearMdl_GEAR_D6), (uint32) (0x3a45UL)}, \
		{(uint8) (GearMdl_GEAR_D7), (uint32) (0x5d2UL)}, \
		{(uint8) (GearMdl_GEAR_D8), (uint32) (0xbfdeUL)}, \
		{(uint8) (GearMdl_GEAR_D9), (uint32) (0xc759UL)}, \
		{(uint8) (GearMdl_GEAR_M), (uint32) (0x4211UL)}, \
		{(uint8) (GearMdl_GEAR_M1), (uint32) (0x9c4aUL)}, \
		{(uint8) (GearMdl_GEAR_M2), (uint32) (0xbc53UL)}, \
		{(uint8) (GearMdl_GEAR_M3), (uint32) (0xfafbUL)}, \
		{(uint8) (GearMdl_GEAR_M4), (uint32) (0x43e0UL)}, \
		{(uint8) (GearMdl_GEAR_M5), (uint32) (0x84baUL)}, \
		{(uint8) (GearMdl_GEAR_M6), (uint32) (0xb75eUL)}, \
		{(uint8) (GearMdl_GEAR_M7), (uint32) (0xb2d7UL)}, \
		{(uint8) (GearMdl_GEAR_M8), (uint32) (0xa6a2UL)}, \
 		{(uint8) (GearMdl_GEAR_M9), (uint32) (0x1f6cUL)} \
}

#define GEAR_CFG_CRC_TABLE2	\
{		 /*       gear id                        gear crc  */\
		{(uint8) (GearMdl_GEAR_P), (uint32) (0x8d6dUL)}, \
		{(uint8) (GearMdl_GEAR_R), (uint32) (0xd62dUL)}, \
		{(uint8) (GearMdl_GEAR_N), (uint32) (0x8461UL)}, \
		{(uint8) (GearMdl_GEAR_D), (uint32) (0x60fUL)}, \
		{(uint8) (GearMdl_GEAR_D1), (uint32) (0xe324UL)}, \
		{(uint8) (GearMdl_GEAR_D2), (uint32) (0x30c8UL)}, \
		{(uint8) (GearMdl_GEAR_D3), (uint32) (0xe210UL)}, \
		{(uint8) (GearMdl_GEAR_D4), (uint32) (0x7de4UL)}, \
		{(uint8) (GearMdl_GEAR_D5), (uint32) (0xa16fUL)}, \
		{(uint8) (GearMdl_GEAR_D6), (uint32) (0x258dUL)}, \
		{(uint8) (GearMdl_GEAR_D7), (uint32) (0x5791UL)}, \
		{(uint8) (GearMdl_GEAR_D8), (uint32) (0x22c8UL)}, \
		{(uint8) (GearMdl_GEAR_D9), (uint32) (0x1b43UL)}, \
		{(uint8) (GearMdl_GEAR_M), (uint32) (0x555aUL)}, \
		{(uint8) (GearMdl_GEAR_M1), (uint32) (0xb2bcUL)}, \
		{(uint8) (GearMdl_GEAR_M2), (uint32) (0x6150UL)}, \
		{(uint8) (GearMdl_GEAR_M3), (uint32) (0xb388UL)}, \
		{(uint8) (GearMdl_GEAR_M4), (uint32) (0x2c7cUL)}, \
		{(uint8) (GearMdl_GEAR_M5), (uint32) (0xf0f7UL)}, \
		{(uint8) (GearMdl_GEAR_M6), (uint32) (0x7415UL)}, \
		{(uint8) (GearMdl_GEAR_M7), (uint32) (0x609UL)}, \
		{(uint8) (GearMdl_GEAR_M8), (uint32) (0x7350UL)}, \
 		{(uint8) (GearMdl_GEAR_M9), (uint32) (0x4adbUL)} \
}

#define GEAR_CFG_CRC_TABLE1	\
{		 /*       gear id                        gear crc  */\
		{(uint8) (GearMdl_GEAR_P), (uint32) (0xC99BUL)}, \
		{(uint8) (GearMdl_GEAR_R), (uint32) (0x19CCUL)}, \
		{(uint8) (GearMdl_GEAR_N), (uint32) (0xA058UL)}, \
		{(uint8) (GearMdl_GEAR_D), (uint32) (0xE931UL)}, \
		{(uint8) (GearMdl_GEAR_D1), (uint32) (0x2AC0UL)}, \
		{(uint8) (GearMdl_GEAR_D2), (uint32) (0xDF17UL)}, \
		{(uint8) (GearMdl_GEAR_D3), (uint32) (0xBD9DUL)}, \
		{(uint8) (GearMdl_GEAR_D4), (uint32) (0x30FAUL)}, \
		{(uint8) (GearMdl_GEAR_D5), (uint32) (0xA27DUL)}, \
		{(uint8) (GearMdl_GEAR_D6), (uint32) (0x3A45UL)}, \
		{(uint8) (GearMdl_GEAR_D7), (uint32) (0x9339UL)}, \
		{(uint8) (GearMdl_GEAR_D8), (uint32) (0xBFDEUL)}, \
		{(uint8) (GearMdl_GEAR_D9), (uint32) (0xC759UL)}, \
		{(uint8) (GearMdl_GEAR_M), (uint32) (0x4211UL)}, \
		{(uint8) (GearMdl_GEAR_M1), (uint32) (0xB342UL)}, \
		{(uint8) (GearMdl_GEAR_M2), (uint32) (0xBC53UL)}, \
		{(uint8) (GearMdl_GEAR_M3), (uint32) (0xFAFBUL)}, \
		{(uint8) (GearMdl_GEAR_M4), (uint32) (0x43E0UL)}, \
		{(uint8) (GearMdl_GEAR_M5), (uint32) (0x84BAUL)}, \
		{(uint8) (GearMdl_GEAR_M6), (uint32) (0xB75EUL)}, \
		{(uint8) (GearMdl_GEAR_M7), (uint32) (0x00D4UL)}, \
		{(uint8) (GearMdl_GEAR_M8), (uint32) (0xA6A2UL)}, \
 		{(uint8) (GearMdl_GEAR_M9), (uint32) (0x1F6CUL)} \
}


typedef struct
{
	uint8 GR_DrvModDisp;
	uint8 GR_DrvModDispSts;
	uint8 GR_DrvGearDispSts;
	uint8 GR_DrvAutoGearDisp;
	uint8 GR_DCT_ShftRecom_M;
}GR_CFG_SG_DCT7;

typedef struct
{
	uint8 GR_DrvModDisp;
	uint8 GR_DrvModDispSts;
	uint8 GR_DrvGearDispSts;
	uint8 GR_DrvAutoGearDisp;
	uint8 GR_DCT_ShftRecom_M;
}GR_CFG_SG_DCT_FD4;

typedef struct
{
	uint8 GR_DrvModDisp;
	uint8 GR_DisplayGear;
	uint8 GR_TCUGearFlashing;
	uint8 GR_ShftRecom_M;
}GR_CFG_DCT9;

typedef struct
{
	uint8 GR_DrvModDisp;
	uint8 GR_DrvModDispSts;
}GR_CFG_SG_HCU_HP5;

typedef struct
{
	uint8 TgtgearUp;
	uint8 TgtgearDown;
}GR_CFG_ECM10;


/*********************************************************************************************************/
#endif //GEAR_CFG_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
