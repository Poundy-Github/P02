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

/**********************************************************************************************************
*File Name   : SWC_TPMS.h                                                                                 *
*                                                                                                         *
*Description : TPMS module application head file.                                                         *
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
#ifndef TPMS_app_H
#define TPMS_app_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
*	Output Application Interface Accuary            													  *
**********************************************************************************************************/

#include "Std_Types.h"
//#include "Platform_Types.h"
#include "IPC_ClusterApp.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/* unit */
#define UNIT_METRIC			(0U)
#define UNIT_JAPANESE_METRIC	(1U)
#define UNIT_UK_IMPERIAL	(2U)
#define UNIT_US_IMPERIAL	(3U)
#define TPMS_KPA			(0U)	//factor:1
#define TPMS_PSI			(1U)	//factor:0.1
#define TPMS_BAR			(2U)	//factor:0.1

#define TPMS_CELSIUS		(0U)
#define TPMS_FAHRENHEIT	    (1U)

/* TPMS format */
#define TPMS_OFF			(0U)  // no display
#define TPMS_NORMAL			(1U)  // normal dispaly value
#define TPMS_DASH			(2U)  // display --- + unit

/* tire  behavior and color */
#define TPMS_TIRE_OFF 		(0U) // 0|1  0|0  1|0 1|1
#define TPMS_TIRE_RED1HZ	(1U)

/* TPMS numeric color status */
#define TPMS_WHITE	(0x0U)
#define TPMS_RED	(0x1U)

/* Cluster Internal Configuration */
#define TPMS_TASK_TIME_CYCLE	(100) /* 100ms */
#define TPMS_REFRESH_RATE	(TPMS_VCfg.u16CcfgRefreshRateTPMS/10*1000)  /* 胎压信息更新周期：3s  TPMS task Cycle is 100ms */
#define TPMS_DISPLAY_ENABLE (0x1U) /* 0x1:Enable */

/**/
#define TPMS_PRESSURE_INVALID_VALUE    (0xFFU)
#define TPMS_TEMPERATURE_INVALID_VALUE (0xFFU)

#define TPMS_PRESSURE_FACTOR_1	(13725U)
#define TPMS_PRESSURE_FACTOR_2	(1000U)
#define TPMS_PRESSURE_FACTOR_PSI (6895U)
#define TPMS_PRESSURE_FACTOR_BAR (100*TPMS_PRESSURE_FACTOR_2)

/**/
#define TPMS_PRESSURE_KPA_MAX	(349U)
#define TPMS_PRESSURE_PSI_MAX	(506U)
#define TPMS_PRESSURE_BAR_MAX	(35U)

#define TPMS_TEMPERATURE_C_MAX	(254U)/* offset:-50 */
#define TPMS_TEMPERATURE_F_MAX	(457U)/* offset:-58 */

/**********************************************************************************************************
*																								          *
*																								          *
*	System Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/
#pragma pack(push)
#pragma pack(1)

#pragma pack(pop)

typedef enum
{
	TPMS_FL = 0,
	TPMS_FR,
	TPMS_RL,
	TPMS_RR,
	TPMS_COUNT
}TPMS_enTireCount;

typedef enum
{
   TPMS_CLUSTER_SLEEP    = 1,
   TPMS_CLUSTER_OFF      = 2,
   TPMS_CLUSTER_NORMAL   = 4,
   TPMS_CLUSTER_ABNORMAL = 8,
   TPMS_CLUSTER_MAX      = 16
}TPMS_POWER_MODE;

typedef struct
{
	uint8  tire_press_status;
	uint16 tire_press_value;
	uint8  tire_press_color;
	uint8  tire_temp_status;
	uint16 tire_temp_value;
	uint8  tire_temp_color;
	uint8  tire_behavior_color;//tire_behavior_color  pressure/temperature
}TPMS_subTPMS_str;

typedef struct
{
	TPMS_subTPMS_str fl_tpms;
	TPMS_subTPMS_str fr_tpms;
	TPMS_subTPMS_str rl_tpms;
	TPMS_subTPMS_str rr_tpms;
	//TPMS_subTPMS_str subTPMS[TPMS_COUNT];
	uint8 tire_press_unit;
	uint8 tire_temp_unit;
} TPMS_str;

typedef struct
{
	uint8 u8UnitSystem;
	uint8 u8TPMSSystem;
	uint8 u8InitFlag;	
	uint8 u8CcfgTPMSDisplayEnable;
	uint16 u16CcfgRefreshRateTPMS;/*range:0~255 factor:0.1 default:30*/
}TPMS_VCfg_str;
/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
extern void TPMSMdl_TPMS_cold_init(void);
extern void TPMSMdl_TPMS_warm_init(void);
extern void TPMSMdl_TPMS_app_tsk(void);
extern uint8 TPMSMdl_get_vehicle_config(void);

#endif
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

