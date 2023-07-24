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
*File Name   : SWC_TC_NE_Process.h                                                                        *
*                                                                                                         *
*Description : TC new energy module application head file.                                                *
*                                                                                                         *
*Author      : Deng Jiangbo                                                                               *
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


/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

#ifndef TC_NE_H
#define TC_NE_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Com.h"
#include "VConfig.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TC_Pkg_Cfg.h"
#include "SWC_TC_Process.h"

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TC_NE_Power_P0_ENABLE  0
	#define TC_NE_ChargSts_Output_EN  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TC_NE_Power_P0_ENABLE  0
	#define TC_NE_ChargSts_Output_EN  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TC_NE_Power_P0_ENABLE  1
	#define TC_NE_ChargSts_Output_EN  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TC_NE_Power_P0_ENABLE  1
	#define TC_NE_ChargSts_Output_EN  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TC_NE_Power_P0_ENABLE  0
	#define TC_NE_ChargSts_Output_EN  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TC_NE_Power_P0_ENABLE  1
	#define TC_NE_ChargSts_Output_EN  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TC_NE_Power_P0_ENABLE  1
	#define TC_NE_ChargSts_Output_EN  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TC_NE_Power_P0_ENABLE  1
	#define TC_NE_ChargSts_Output_EN  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TC_NE_Power_P0_ENABLE  1
	#define TC_NE_ChargSts_Output_EN  1
#else
	#define TC_NE_Power_P0_ENABLE  0
	#define TC_NE_ChargSts_Output_EN  0
#endif

typedef struct
{
	uint8 u8VehicleType;
	uint8 u8MotorType;
	uint8 u8StabilizerBarEnable;

	/*Power P0/HEV/PHEV */
	uint8 u8AvailablePowerDisplayEnable;    // disable:0; enable:1
	uint8 u8PHEVSOCDisplayEnable;
	uint8 u8EnrgFlowDisplayEnable;
	uint8 u8PHEV_HEVCurrentDisplayEnable;

	uint16 u16MaxAvailablePower;            // AvailablePower: Max value
	uint16 u16RefreshRateAvailablePower;    // update frequency
	uint16 u16RefreshRatePower;
	uint16 u16RefreshRatePHEVSOC;           // Ig on
	uint16 u16RefreshRateDigitalPHEVSOC;    // Ig off
	uint16 u16RefreshRateECODrvHabit;
	uint16 u16RefreshRateCurrent;
	uint16 u16RefreshRateChrgDuration;
	uint16 u16RefreshRateEnrgFlow;
}TC_NE_VCONFIG_DATA;

typedef struct
{
	uint8 u8BatSocValCur;
	uint8 u8BatSocValPre;
	uint8 u8BattLevelStatus;
}TC_NE_BattLevel_Data;

typedef struct
{
	uint8 u8BattSocStatus;       // 动力电池电量显示状态 1:Red; 2:Yellow; 3:Green
	uint8 u8BattSocValue;        // 动力电池电量显示 0~100%
	uint8 u8ChrgStsDsp;          // LCD充电状态显示 0xFE:not display; 0xFF:不显示充电卡片
	uint8 u8ChrgTimeHour;        // 预计充电时间显示 0xFE:not display; 0xFF:--h--min
	uint8 u8ChrgTimeMin;         // 预计充电时间显示 0xFE:not display; 0xFF:--h--min
	uint8 u8EnergyFlow_Value;    // 能量流显示 0xFE:not display; 0xFF:"暂时无法获取能量流信息"
	uint8 u8StabilizerBarStatus; // 电子稳定杆 0x0:连接断开; 0x1:非预期断开; 0x02:连接状态

	uint16 u16TotDrvReqPowerValue;        // 功率指示 0xEFFE:not display; other:offset -100
	uint16 u16AvailPowerValue;            // 电机可用功率 0xEFFE:not display; Resolution:0.1
	uint16 u16DrvHabitValue;              // 驾驶效率显示 0xEFFE:not display; other:offset -100
	uint16 u16ChrgStsCurr;                // 充电电流显示 0xEFFE:not display; 0xEFFF:---A; other:offset -1000
}TC_NE_PHEV_DATA;

typedef struct
{
	/*Power P0/HEV/PHEV */
	uint16 u16RateAvailablePowerTimeTick;
	uint16 u16RatePowerTimeTick;
	uint16 u16RatePHEVSOCTimeTick;
	uint16 u16RateDigitalPHEVSOCTimeTick;
	uint16 u16RateECODrvHabitTimeTick;
	uint16 u16RateCurrentTimeTick;
	uint16 u16RateChrgDurationTimeTick;
	uint16 u16RateEnergyFlowTimeTick;
}TC_NE_TimeTick;

#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************
*Function   : TC_NE_Process_Init                                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: NONE                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Deng Jiangbo                                                                                *
*                                                                                                         *
*Date       : 2021-04-19                                                                                  *
**********************************************************************************************************/
extern void TC_NE_Process_Init(void);

/**********************************************************************************************************
*Function   : TC_NE_Process_Task                                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: NONE                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Deng Jiangbo                                                                                *
*                                                                                                         *
*Date       : 2021-04-19                                                                                  *
**********************************************************************************************************/
extern void TC_NE_Process_Task(void);

#define SWC_TC_STOP_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif //TC_NE_H
