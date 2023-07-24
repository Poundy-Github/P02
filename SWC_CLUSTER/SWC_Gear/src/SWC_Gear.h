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
*File Name   : SWC_Gear.h                                                                                 *
*                                                                                                         *
*Description : Gear module application head file.                                                         *
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
#ifndef Gear_app_H
#define Gear_app_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Std_Types.h"
#include "IPC_SAFETY.h"
#include "SWC_Gear_Adapt.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
*	Output Application Interface Accuary            													  *
**********************************************************************************************************/
//#include <stdint.h>

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
//gear value
#define GearMdl_GEAR_P					(0U)
#define GearMdl_GEAR_R					(1U)
#define GearMdl_GEAR_N					(2U)
#define GearMdl_GEAR_D					(3U)
#define GearMdl_GEAR_D1					(4U)
#define GearMdl_GEAR_D2					(5U)
#define GearMdl_GEAR_D3					(6U)
#define GearMdl_GEAR_D4					(7U)
#define GearMdl_GEAR_D5					(8U)
#define GearMdl_GEAR_D6					(9U)
#define GearMdl_GEAR_D7					(10U)
#define GearMdl_GEAR_D8					(11U)
#define GearMdl_GEAR_D9					(12U)
#define GearMdl_GEAR_M					(13u)
#define GearMdl_GEAR_M1					(14U)
#define GearMdl_GEAR_M2					(15U)
#define GearMdl_GEAR_M3					(16U)
#define GearMdl_GEAR_M4					(17U)
#define GearMdl_GEAR_M5					(18U)
#define GearMdl_GEAR_M6					(19U)
#define GearMdl_GEAR_M7					(20U)
#define GearMdl_GEAR_M8					(21U)
#define GearMdl_GEAR_M9					(22U)
#define GearMdl_GEAR_NO_DISPLAY			(255U)
//gear status
#define GearMdl_GEAR_NO_SHOW			(0U)
#define GearMdl_GEAR_NO_FLASH			(1U)
#define GearMdl_GEAR_1HZ_FLASH			(2U)
#define GearMdl_GEAR_0_5HZ_FLASH		(3U)
//gear shift value
#define GearMdl_GEAR_SHIFT_UP			(0U)
#define GearMdl_GEAR_SHIFT_DOWN			(1U)
#define GearMdl_GEAR_SHIFT_NO_DISPLAY	(255U)

#define GearMdl_GEAR_D_VAL_MAX		((GearMdl_get_vehicle_config() == GEAR_CFG_7DCT_PROJECT) ? 7U : 9U)//(7u)
#define GearMdl_GEAR_M_VAL_MAX		(GearMdl_GEAR_D_VAL_MAX)//(7u)
//#define GearMdl_GEAR_TEST_MODE

//#define Gear_info(...)   Logger_String(LOGGER_MODULE_GENERAL, LOGGER_LEVEL_INFO, __VA_ARGS__)
//#define Gear_warn(...)   Logger_String(LOGGER_MODULE_GENERAL, LOGGER_LEVEL_WARN, __VA_ARGS__)
//#define Gear_err(...)    Logger_String(LOGGER_MODULE_GENERAL, LOGGER_LEVEL_ERR, __VA_ARGS__)

#define OSTM_TIMER_CLEAR 				(0u)
#define OSTM_TIMER_OVER					(2u)
#define OSTM_TIMER_RUNING				(4u)
#define OSTM_TIMER_PENNDING				(8u)
#define OSTM_TIMER_START_ERROR			(16u)
#define OSTM_TIMER_MAX_COUNTER			(0xffffffffu)
#define OSTM_TIMER_FACTOR				(1u)
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

typedef struct
{
	uint8 gear_val;
	uint8 gear_status;
	uint8 gear_shift_val;
	uint8 gear_msg_Status;
	//uint8 gear_not_p_flag;
} GEAR_DISP_str;

#pragma pack(pop)

typedef struct
{
	uint8 gear_cnt_u8;
	uint8 gear_pre_val_u8;
	uint8 gear_actual_val_u8;
	uint8 gear_shift_cnt_u8;
	uint8 gear_shift_pre_val_u8;
	uint8 gear_shift_actual_val_u8;
	uint8 gear_status;
}GEAR_INFO_str;

typedef struct
{
	uint8 u8transmission;
	//uint8 u8engineControlUnit;
	uint8 u8fuel;
	uint8 u8electromotorPosition;
	uint8 u8InitFlag;
	boolean boPTCAN;
	boolean boCcfgFixDisplayGearEnable;
	boolean boCcfgFixDisplayShiftGearRecommendEnable;
	boolean boCcfgFixDisplay6GearEnable;
	boolean boCcfgFixDisplay6ShiftGearRecommendEnable;
}GEAR_VCfg_str;

typedef enum
{
   CLUSTER_SLEEP    = 1,
   CLUSTER_OFF      = 2,
   CLUSTER_15OFF    = 3,
   CLUSTER_NORMAL   = 4,
   CLUSTER_ABNORMAL = 8,
   CLUSTER_MAX      = 16
} GEAR_POWER_MODE;

typedef enum
{
   GEAR_MSG_NORMAL  = 0,
   GEAR_MSG_E2E_ERROR,
   GEAR_MSG_MISSING
} GEAR_MSG_STATUS;

typedef enum
{
	GEAR_BLANK   = 0,
	GEAR_ON,
	GEAR_FLASH
}GEAR_DISP_STATUS;

typedef enum
{
	GEAR_P   = 0,
	GEAR_R,
	GEAR_N,
	GEAR_D,
	GEAR_M,
	GEAR_MAX
}GEAR_DISP_MODE;

typedef enum
{
	enGEAR_P = 0,
	enGEAR_R,
	enGEAR_N,
	enGEAR_D,
	enGEAR_D1,
	enGEAR_D2,
	enGEAR_D3,
	enGEAR_D4,
	enGEAR_D5,
	enGEAR_D6,
	enGEAR_D7,
	enGEAR_D8,
	enGEAR_D9,
	enGEAR_M,
	enGEAR_M1,
	enGEAR_M2,
	enGEAR_M3,
	enGEAR_M4,
	enGEAR_M5,
	enGEAR_M6,
	enGEAR_M7,
	enGEAR_M8,
	enGEAR_M9,
	enGEAR_NUM
}GEAR_ID;

typedef struct
{
    uint8_t Gear_ID;
	uint32_t CRC_Value;
}SafetyGearCRC_str;

typedef enum
{
	enOsServiceTimer = 0,
	enGearTimerA,
	enGearTimerB,
	enTimerMax
}GR_TimerID;

typedef struct
{
	uint32 TimerTicks;
	uint8 TimerStatus;
}TimerCfg_str;

#define Common_GateWay_START_SEC_CODE
#include "Common_Safety_MemMap.h"

//FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Os_Service_GetCounterValue(uint32* Value);
//FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Os_Service_GetElapsedValue(uint32* Value, uint32* ElapsedValue);
FUNC(void, RTE_CODE) IPC_API_ReceiveSafetyGearCRCCallback(uint8 *data);
FUNC(void, CANTP_CODE) RTE_API_GearErrorCallback(const uint8 *data);
#define Rte_Call_Gear_Os_Service_GetCounterValue Rte_Call_Os_Service_GetCounterValue
#define Rte_Call_Gear_Os_Service_GetElapsedValue Rte_Call_Os_Service_GetElapsedValue

#define CRC_TIMEOUT	1000
#define RTE_E_Os_Service_E_OK (0U)

/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
extern void GearMdl_Gear_cold_init(void);
extern void GearMdl_Gear_warm_init(void);
extern void GearMdl_Gear_app_tsk(void);
extern void GearMdl_get_Gear_disp(IPC_M2S_SAFETYAPPGear_t *pf_gear_inf);
extern uint8 GearMdl_get_Gear_val_inf(void);
extern uint8 GearMdl_get_Gear_not_P_status(void);
extern uint8 GearMdl_get_vehicle_config(void);

extern void Os_Timer_Start(const GR_TimerID TimerId);
extern void Os_Timer_Stop(const GR_TimerID TimerId);
extern boolean Os_Timer_IsStarted(const GR_TimerID TimerId);
extern boolean Os_Timer_IsElapsed(const GR_TimerID TimerId, const uint32 Timeout);
extern boolean Os_Timer_IsElapsedRestart(const GR_TimerID TimerId, const uint32 Timeout);
extern uint32 Os_Timer_GetElapsedTime(const GR_TimerID TimerId);

#define Common_GateWay_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"

#endif
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

