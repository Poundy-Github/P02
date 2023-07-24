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
*File Name   : SWC_TC_NE_Process.c                                                                        *
*                                                                                                         *
*Description : TC new energy module application source file.                                      		  *
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
#include <time.h>
#include <string.h>
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Common_Normal.h"
#include "IPC_ClusterApp.h"
#include "SWC_IPC_Config.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TC_NE_Process.h"
#include "SWC_TC_Rte_Adapt.h"
#include "CConfig_Cfg.h"

#define TC_NE_U8_NotDisp               (0xFEu)
#define TC_NE_U8_InvalidDisp           (0xFFu)
#define TC_NE_U16_NotDisp              (0xEFFEu)
#define TC_NE_U16_InvalidDisp          (0xEFFFu)

#define TC_NE_CONFIG_CASE1    (1u)
#define TC_NE_CONFIG_CASE2    (2u)
#define TC_NE_CONFIG_CASE3    (3u)
#define TC_NE_CONFIG_CASE4    (4u)
#define TC_NE_CONFIG_CASE5    (5u)
#define TC_NE_CONFIG_CASE6    (6u)

#define TC_NE_BATT_LEVEL_UP      (1u)
#define TC_NE_BATT_LEVEL_DOWN    (0u)

#define TC_NE_BATT_PSP4_STAGE    (6u)
#define TC_NE_BATT_PP2_STAGE1    (8u)
#define TC_NE_BATT_PP2_STAGE2    (17u)
#define TC_NE_BATT_P2P4_STAGE1   (8u)
#define TC_NE_BATT_P2P4_STAGE2   (14u)

#define TC_NE_BATT_DIS_RED       (1u)
#define TC_NE_BATT_DIS_YELLOW    (2u)
#define TC_NE_BATT_DIS_GREEN     (3u)
#define TC_NE_BATT_DIS_GREY      (4u)

#define TC_NE_STABAR_DISCONN    (0u)
#define TC_NE_STABAR_UNEXPECT   (1u)
#define TC_NE_STABAR_CONNECT    (2u)

#if (1 == TC_NE_ChargSts_Output_EN)
	typedef TC_NE_ChargStsOutput RTE_TC_NE_ChargStsData;
#else
	typedef uint8 RTE_TC_NE_ChargStsData;
#endif

#define TC_NE_Vehicle_Type_Data	VCONFIG_DATA.u8VehicleType
#define TC_NE_Motor_Type_Data VCONFIG_DATA.u8MotorType
#define TC_NE_StabilizerBarEn VCONFIG_DATA.u8StabilizerBarEnable

/**********************************************************************************************************
*																										  *
*																										  *
*				  Type Definition																		  *
*																										  *
*																										  *
**********************************************************************************************************/
#pragma ghs section bss=".buram" 

static TC_NE_BattLevel_Data NE_BattLevel_Data;
static uint8 u8FristFalg;

#pragma ghs section bss=default


#define SWC_TC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static TC_NE_VCONFIG_DATA VCONFIG_DATA;
static TC_NE_PHEV_DATA	NE_PHEV_DATA;
static TC_NE_TimeTick NE_TimeTick;
static IPC_M2S_ClusterAppAPPNewEnergy_t NE_ipc;

//static TC_NE_BattLevel_Data NE_BattLevel_Data;
//static uint8 u8FristFalg = 0;

#define SWC_TC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define SWC_TC_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static uint8 u8ChrgStsDispPre = TC_NE_U8_InvalidDisp;

#define SWC_TC_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

// tc new erengy process
void TC_NE_Power_Process(void);
void TC_NE_BattSoc_Process(void);
void TC_NE_DrvHabit_Process(void);
void TC_NE_ChrgStatus_Process(void);
void TC_NE_ChrgTime_Process(uint8 u8ChrgSts);
void TC_NE_EnergyFlow_Process(void);
void TC_NE_StabilizerBar_Process(void);

void TC_NE_Config_Data(void);
void TC_NE_RTE_SBUSUpdate(void);
void TC_NE_KL15OFF_Init(void);

// get display value function
uint16 Get_TotDrvReqPowerVal(uint8 u8Case);
uint16 Get_AvailPowerVal(void);
uint8 Get_BattSocCalVal(void);
uint8 Get_BattSocStatus(uint8 u8case);
uint16 Get_EcodrvHabitVal(void);
uint8 Get_ChrgStsVal(void);
uint16 Get_ChrgCurrVal(uint8 u8ChrgSts);
void Get_ChrgTimeVal(uint16 u16ChrgTimeRaw, uint8 *pChrgTimeHour, uint8 *pChrgTimeMin);
uint8 Get_EnergyFlow_Value(uint8 u8Case);

/**********************************************************************************************************
*Function   : TC_NE_Process_Init                                                                     	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Deng Jiangbo			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/

void TC_NE_Process_Init(void)
{
	TC_NE_Config_Data();

	NE_PHEV_DATA.u8BattSocStatus = TC_NE_BATT_DIS_RED;
	NE_PHEV_DATA.u8BattSocValue = 0;

	NE_PHEV_DATA.u8ChrgStsDsp = TC_NE_U8_InvalidDisp;
	NE_PHEV_DATA.u8ChrgTimeHour = TC_NE_U8_NotDisp;
	NE_PHEV_DATA.u8ChrgTimeMin = TC_NE_U8_NotDisp;
	NE_PHEV_DATA.u16ChrgStsCurr = TC_NE_U16_NotDisp;

	NE_PHEV_DATA.u16AvailPowerValue = TC_NE_U16_InvalidDisp;
	NE_PHEV_DATA.u16TotDrvReqPowerValue = TC_NE_U16_InvalidDisp;
	NE_PHEV_DATA.u16DrvHabitValue = TC_NE_U16_InvalidDisp;
	NE_PHEV_DATA.u8EnergyFlow_Value = TC_NE_U8_InvalidDisp;
	NE_PHEV_DATA.u8StabilizerBarStatus = TC_NE_U8_InvalidDisp;

	// clear refresh timetick
	NE_TimeTick.u16RateAvailablePowerTimeTick = 0;
	NE_TimeTick.u16RatePowerTimeTick = 0;
	NE_TimeTick.u16RatePHEVSOCTimeTick = 0;
	NE_TimeTick.u16RateDigitalPHEVSOCTimeTick = 0;
	NE_TimeTick.u16RateECODrvHabitTimeTick = 0;
	NE_TimeTick.u16RateCurrentTimeTick = 0;
	NE_TimeTick.u16RateChrgDurationTimeTick = 0;
	NE_TimeTick.u16RateEnergyFlowTimeTick = 0;

	if (1 != u8FristFalg)
	{
		u8FristFalg = 1;
		NE_BattLevel_Data.u8BatSocValCur = 0;
		NE_BattLevel_Data.u8BatSocValPre = 0;
		NE_BattLevel_Data.u8BattLevelStatus = TC_NE_BATT_LEVEL_UP;
	}
}

/**********************************************************************************************************
*Function   : TC_NE_KL15OFF_Init                                                                          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: ZJ         			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/
void TC_NE_KL15OFF_Init(void)
{
	// KL15 OFF, data set to no display
	{
		NE_PHEV_DATA.u16AvailPowerValue = TC_NE_U16_NotDisp;
		NE_PHEV_DATA.u16TotDrvReqPowerValue = TC_NE_U16_NotDisp;
		NE_PHEV_DATA.u16DrvHabitValue = TC_NE_U16_NotDisp;
		NE_PHEV_DATA.u8EnergyFlow_Value = TC_NE_U8_NotDisp;
	}

	// KL15 OFF, refresh timetick set
	{
		NE_TimeTick.u16RateAvailablePowerTimeTick = VCONFIG_DATA.u16RefreshRateAvailablePower;
		NE_TimeTick.u16RatePowerTimeTick = VCONFIG_DATA.u16RefreshRatePower;
		NE_TimeTick.u16RateECODrvHabitTimeTick = VCONFIG_DATA.u16RefreshRateECODrvHabit;
		NE_TimeTick.u16RateEnergyFlowTimeTick = VCONFIG_DATA.u16RefreshRateEnrgFlow;
	}
}

/**********************************************************************************************************
*Function   : TC_NE_Process_Task                                                                     	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Deng Jiangbo			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/

void TC_NE_Process_Task(void)
{
	if(CLUSTER_KL15ON == TC_NE_RTE_API_Get_Power_Mode_State())
	{
		TC_NE_Power_Process();                //1.21 功率指示显示(HEV+PHEV) 1.22 功率指示显示(P0)
		TC_NE_DrvHabit_Process();             //1.23 驾驶效率显示(HEV+PHEV)(经济指引)
		TC_NE_EnergyFlow_Process();           //1.18 能量流显示

		TC_NE_BattSoc_Process();              //1.20 PHEV动力电池电量 SOC 显示(PHEV)：电量表显示
		TC_NE_ChrgStatus_Process();           //1.24 充电状态显示(PHEV)：充电状态/预计充电时长/充电电流
		TC_NE_StabilizerBar_Process();        //1.67 电子稳定杆-无本地配置限制刷新
	}
	else if(CLUSTER_KL15OFF == TC_NE_RTE_API_Get_Power_Mode_State())
	{
		TC_NE_KL15OFF_Init();
		TC_NE_BattSoc_Process();              //1.24 充电状态显示(PHEV)：电量数字显示
		TC_NE_ChrgStatus_Process();           //1.24 充电状态显示(PHEV)：充电状态/预计充电时长/充电电流
		// PHEV DTE: not here
	}
	else
	{
		TC_NE_Process_Init();
	}

	TC_NE_RTE_SBUSUpdate();
}


/**********************************************************************************************************
*Function   : TC_NE_Config_Data                                                                     	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Deng Jiangbo			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/

void TC_NE_Config_Data(void)
{
	VconfigKind_Allbuffers VconfigTemp;
	CconfigKind_400Bytes config_data;
	boolean config_status = FALSE;
	uint8 u8Byte2FuelType = 0;
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VconfigTemp);
	if(0u != VconfigTemp[VCONFIG_KIND_INIT_FLAG])
	{
		u8Byte2FuelType = VconfigTemp[VCONFIG_KIND_FUEL];
		TC_NE_Motor_Type_Data = VconfigTemp[VCONFIG_KIND_ELECTROMOTOR_POSITION];
		TC_NE_StabilizerBarEn = VconfigTemp[VCONFIG_KIND_FRT_STABILIZER];
	}

	if(0 == u8Byte2FuelType)
	{
		TC_NE_Vehicle_Type_Data = TC_VEHICLE_FUEL_DIESEL;
	}
	else if((1 == u8Byte2FuelType) || (2 == u8Byte2FuelType) || (7 == u8Byte2FuelType))
	{
		TC_NE_Vehicle_Type_Data = TC_VEHICLE_FUEL;
	}
	else if(3 == u8Byte2FuelType)
	{
		TC_NE_Vehicle_Type_Data = TC_VEHICLE_HEV;
	}
	else if(4 == u8Byte2FuelType)
	{
		TC_NE_Vehicle_Type_Data = TC_VEHICLE_PHEV;
	}	
	else if(5 == u8Byte2FuelType)
	{
		TC_NE_Vehicle_Type_Data = TC_VEHICLE_EV;
	}
	else
	{
		TC_NE_Vehicle_Type_Data = TC_VEHICLE_NONE;
	}

	config_status = TC_Rte_Api_Get_Cconfig_Cfg(config_data);
	if(FALSE != config_status)
	{
		VCONFIG_DATA.u8AvailablePowerDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_AvailablePowerDisplayEnable, config_data);
		VCONFIG_DATA.u8PHEVSOCDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_PHEVSOCDisplayEnable, config_data);
		VCONFIG_DATA.u8EnrgFlowDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_EnrgFlowDisplayEnable, config_data);
		VCONFIG_DATA.u8PHEV_HEVCurrentDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_PHEV_HEVCurrentDisplayEnable, config_data);

		VCONFIG_DATA.u16MaxAvailablePower = (uint16)(CConfig_GetConfig(CCONFIG_KIND_MaxAvailablePower, config_data) * 5u);        //Resolution: 0.1%
		VCONFIG_DATA.u16RefreshRateAvailablePower = (uint16)(CConfig_GetConfig(CCONFIG_KIND_RefreshRateAvailablePower, config_data) * 5u);    // 0.1s
		VCONFIG_DATA.u16RefreshRatePower = (uint16)(CConfig_GetConfig(CCONFIG_KIND_RefreshRatePower, config_data) * 5u);
		VCONFIG_DATA.u16RefreshRatePHEVSOC = (uint16)(CConfig_GetConfig(CCONFIG_KIND_RefreshRatePHEVSOC, config_data) * 5u);
		VCONFIG_DATA.u16RefreshRateDigitalPHEVSOC = (uint16)(CConfig_GetConfig(CCONFIG_KIND_RefreshRateDigitalPHEVSOC, config_data) * 5u);
		VCONFIG_DATA.u16RefreshRateECODrvHabit = (uint16)(CConfig_GetConfig(CCONFIG_KIND_RefreshRateECODrvHabit, config_data) * 5u);
		VCONFIG_DATA.u16RefreshRateCurrent = (uint16)(CConfig_GetConfig(CCONFIG_KIND_RefreshRateCurrent, config_data) * 5u);
		VCONFIG_DATA.u16RefreshRateChrgDuration = (uint16)(CConfig_GetConfig(CCONFIG_KIND_RefreshRateChrgDuration, config_data) * 5u);
		VCONFIG_DATA.u16RefreshRateEnrgFlow = (uint16)(CConfig_GetConfig(CCONFIG_KIND_RefreshRateEnrgFlow, config_data) / 2u);    // task: 20ms, 50ms->40ms
	}
	else
	{
		VCONFIG_DATA.u8AvailablePowerDisplayEnable = 1;
		VCONFIG_DATA.u8PHEVSOCDisplayEnable = 1;
		VCONFIG_DATA.u8EnrgFlowDisplayEnable = 1;
		VCONFIG_DATA.u8PHEV_HEVCurrentDisplayEnable = 1;

		VCONFIG_DATA.u16MaxAvailablePower = 500;    //Resolution: 0.1%
		VCONFIG_DATA.u16RefreshRateAvailablePower = 10;
		VCONFIG_DATA.u16RefreshRatePower = 10;
		VCONFIG_DATA.u16RefreshRatePHEVSOC = 50;
		VCONFIG_DATA.u16RefreshRateDigitalPHEVSOC = 50;
		VCONFIG_DATA.u16RefreshRateECODrvHabit = 10;
		VCONFIG_DATA.u16RefreshRateCurrent = 50;
		VCONFIG_DATA.u16RefreshRateChrgDuration = 50;
		VCONFIG_DATA.u16RefreshRateEnrgFlow = 2;
	}
}


/**********************************************************************************************************
*Function   : TC_NE_Power_Process                                                                     	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Deng Jiangbo			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/

void TC_NE_Power_Process(void)
{
	uint16 u16AvailablePower = 0;
	uint16 u16TotdrvReqPower = 0;

	if ((0 != TC_NE_Power_P0_ENABLE) && ((TC_VEHICLE_FUEL ==TC_NE_Vehicle_Type_Data) || (TC_VEHICLE_FUEL_DIESEL ==TC_NE_Vehicle_Type_Data))\
		&& (TC_VEHICLE_MOTOR_P0 == TC_NE_Motor_Type_Data))
	{
		u16TotdrvReqPower = Get_TotDrvReqPowerVal(TC_NE_CONFIG_CASE1);
		u16AvailablePower = TC_NE_U16_NotDisp;
	}
	else if ((TC_VEHICLE_HEV == TC_NE_Vehicle_Type_Data) && ((TC_VEHICLE_MOTOR_P2 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_PS == TC_NE_Motor_Type_Data) || (TC_VEHICLE_MOTOR_PS_P4 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_PARA_P2 == TC_NE_Motor_Type_Data)))
	{
		u16TotdrvReqPower = Get_TotDrvReqPowerVal(TC_NE_CONFIG_CASE2);
		u16AvailablePower = TC_NE_U16_NotDisp;
	}
	else if ((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) && ((TC_VEHICLE_MOTOR_P2 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_P2_P4 == TC_NE_Motor_Type_Data) || (TC_VEHICLE_MOTOR_PS == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_PS_P4 == TC_NE_Motor_Type_Data) || (TC_VEHICLE_MOTOR_PARA_P2 == TC_NE_Motor_Type_Data)))
	{
		#if 0
		if(VCONFIG_DATA.u8AvailablePowerDisplayEnable == 1)
		{
			u16AvailablePower = Get_AvailPowerVal();
		}
		else
		{
			u16AvailablePower = TC_NE_U16_NotDisp;
		}
		u16TotdrvReqPower = Get_TotDrvReqPowerVal(TC_NE_CONFIG_CASE2);
		#endif

		u16TotdrvReqPower = Get_TotDrvReqPowerVal(TC_NE_CONFIG_CASE2);
		u16AvailablePower = Get_AvailPowerVal();
	}
	else
	{
		u16AvailablePower = TC_NE_U16_NotDisp;
		u16TotdrvReqPower = TC_NE_U16_NotDisp;
	}

	if(NE_TimeTick.u16RateAvailablePowerTimeTick >= VCONFIG_DATA.u16RefreshRateAvailablePower)
	{
		NE_TimeTick.u16RateAvailablePowerTimeTick = 0;
		NE_PHEV_DATA.u16AvailPowerValue = u16AvailablePower;
	}
	else
	{
		NE_TimeTick.u16RateAvailablePowerTimeTick ++;
	}

	if(NE_TimeTick.u16RatePowerTimeTick >= VCONFIG_DATA.u16RefreshRatePower)
	{
		NE_TimeTick.u16RatePowerTimeTick = 0;
		NE_PHEV_DATA.u16TotDrvReqPowerValue = u16TotdrvReqPower;
	}
	else
	{
		NE_TimeTick.u16RatePowerTimeTick ++;
	}
}

/**********************************************************************************************************
*Function   : Get_TotDrvReqPowerVal                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: uint8													          							  *
*                                                                                                         *
*Return 	: uint16                                                                                      *
*                                                                                                         *
*Author 	: Deng Jiangbo			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/

uint16 Get_TotDrvReqPowerVal(uint8 u8Case)
{
	uint8 u8MsgStatus = RTE_E_INVALID;
	uint16 u16TotDrvValue = 0;

	if(TC_NE_CONFIG_CASE1 == u8Case)
	{
		u8MsgStatus = TC_RTE_API_Get_HCU_TotDrvReqPower_P0(&u16TotDrvValue);
	}
	else if (TC_NE_CONFIG_CASE2 == u8Case)
	{
		u8MsgStatus = TC_RTE_API_Get_HCU_TotDrvReqPower(&u16TotDrvValue);
	}

	if(RTE_E_OK == u8MsgStatus)
	{
		if((u16TotDrvValue >= 0xC9) && (u16TotDrvValue <= 0xFF))
		{
			u16TotDrvValue = 100;    //Offset 100
		}
	}
	else
	{
		u16TotDrvValue = 100;
	}

	return u16TotDrvValue;

}


/**********************************************************************************************************
*Function   : Get_AvailPowerVal                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: uint16                                                                                      *
*                                                                                                         *
*Author 	: Deng Jiangbo			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/

uint16 Get_AvailPowerVal(void)
{
	uint8 u8MsgStatus = RTE_E_INVALID;
	uint16 u16AvailPowerValue = 0;

	u8MsgStatus =TC_RTE_API_Get_HCU_AvailPower_TM(&u16AvailPowerValue);

	if(RTE_E_OK == u8MsgStatus)
	{
		if(u16AvailPowerValue <= 0x64)
		{
			u16AvailPowerValue = u16AvailPowerValue * 5u;    //Resolution 0.1%
		}
		else if((u16AvailPowerValue >= 0x65) && (u16AvailPowerValue <= 0xFF))
		{
			u16AvailPowerValue = 0;
		}
		else
		{
			u16AvailPowerValue = 0;
		}
	}
	else
	{
		u16AvailPowerValue = 0;
	}

	u16AvailPowerValue = ((u16AvailPowerValue + 5u) / 10u) * 10u;
	if(u16AvailPowerValue >= VCONFIG_DATA.u16MaxAvailablePower)
	{
		u16AvailPowerValue = VCONFIG_DATA.u16MaxAvailablePower;
	}

	return u16AvailPowerValue;

}


/**********************************************************************************************************
*Function   : TC_NE_BattSoc_Process                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Deng Jiangbo			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/

void TC_NE_BattSoc_Process(void)
{
	uint8 u8BattSocDisVal = 0;
	uint8 u8BattSocStatus = 0;

	if((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) \
		&& ((TC_VEHICLE_MOTOR_PS == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_PS_P4 == TC_NE_Motor_Type_Data)))
	{
		u8BattSocDisVal = Get_BattSocCalVal();
		u8BattSocStatus = Get_BattSocStatus(TC_NE_CONFIG_CASE1);
	}
	else if((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) \
		&& ((TC_VEHICLE_MOTOR_P2 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_P2_P4 == TC_NE_Motor_Type_Data)))
	{
		u8BattSocDisVal = Get_BattSocCalVal();
		u8BattSocStatus = Get_BattSocStatus(TC_NE_CONFIG_CASE2);
	}
	else if((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) \
		&& (TC_VEHICLE_MOTOR_PARA_P2 == TC_NE_Motor_Type_Data))
	{
		u8BattSocDisVal = Get_BattSocCalVal();
		u8BattSocStatus = Get_BattSocStatus(TC_NE_CONFIG_CASE3);
	}
	else
	{
		u8BattSocDisVal = TC_NE_U8_NotDisp;    //not display
		u8BattSocStatus = TC_NE_U8_NotDisp;
	}

	// Ig on 刷新, Ig off 数字电量刷新
	if(NE_TimeTick.u16RatePHEVSOCTimeTick >= VCONFIG_DATA.u16RefreshRatePHEVSOC)
	{
		NE_TimeTick.u16RatePHEVSOCTimeTick = 0;
		NE_PHEV_DATA.u8BattSocValue = u8BattSocDisVal;
		NE_PHEV_DATA.u8BattSocStatus = u8BattSocStatus;
	}
	else
	{
		NE_TimeTick.u16RatePHEVSOCTimeTick ++;
	}
}


/**********************************************************************************************************
*Function   : Get_BattSocCalVal                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: uint8                                                                                       *
*                                                                                                         *
*Author 	: Deng Jiangbo			                                                              		  *
*                                                                                                         *
*Date		: 2021-04-19                                                                                  *
**********************************************************************************************************/

uint8 Get_BattSocCalVal(void)
{
	uint8 u8BattSocVal = 0;
	uint8 u8MsgStatus = RTE_E_INVALID;

	u8MsgStatus = TC_RTE_API_Get_BMS_DisSOC(&u8BattSocVal);

	if(RTE_E_OK == u8MsgStatus)
	{
		if(u8BattSocVal <= 0x64)
		{
			// do nothing
		}
		else if((u8BattSocVal >= 0x65) && (u8BattSocVal <= 0xFE))
		{
			u8BattSocVal = NE_BattLevel_Data.u8BatSocValPre;    //keep the last value
		}
		else
		{
			u8BattSocVal = 0;
		}

		NE_BattLevel_Data.u8BatSocValCur = u8BattSocVal;
		if (u8BattSocVal > NE_BattLevel_Data.u8BatSocValPre)
		{
			NE_BattLevel_Data.u8BattLevelStatus = TC_NE_BATT_LEVEL_UP;
		}
		else if (u8BattSocVal < NE_BattLevel_Data.u8BatSocValPre)
		{
			NE_BattLevel_Data.u8BattLevelStatus = TC_NE_BATT_LEVEL_DOWN;
		}
		else
		{
			// do nothing
		}

		NE_BattLevel_Data.u8BatSocValPre = NE_BattLevel_Data.u8BatSocValCur;
	}
	else
	{
		u8BattSocVal = 0;
		NE_BattLevel_Data.u8BatSocValCur = 0;
	}

	return u8BattSocVal;
}

 /**********************************************************************************************************
 *Function	 : Get_BattSocStatus																		   *
 *																										   *
 *Description: TBD																						   *
 *																										   *
 *Parameter  : uint8 																					   *
 *																										   *
 *Return	 : uint8 																					   *
 *																										   *
 *Author	 : Deng Jiangbo 																			   *
 *																										   *
 *Date		 : 2021-04-19																				   *
 **********************************************************************************************************/

 uint8 Get_BattSocStatus(uint8 u8case)
{
	uint8 u8BattSocStatus = 0;
	uint8 u8Stage1 = 0;
	uint8 u8Stage2 = 0;
	uint8 u8BattSocDisVal = NE_BattLevel_Data.u8BatSocValCur;

	if (TC_NE_CONFIG_CASE1 == u8case)
	{
		u8Stage1 = TC_NE_BATT_PSP4_STAGE;
	}
	else if (TC_NE_CONFIG_CASE2 == u8case)
	{
		u8Stage1 = TC_NE_BATT_P2P4_STAGE1;
		u8Stage2 = TC_NE_BATT_P2P4_STAGE2;
	}
	else if (TC_NE_CONFIG_CASE3 == u8case)
	{
		u8Stage1 = TC_NE_BATT_PP2_STAGE1;
		u8Stage2 = TC_NE_BATT_PP2_STAGE2;
	}
	else
	{
		// do nothing
	}


	// update battsoc diaplay status
	switch(NE_BattLevel_Data.u8BattLevelStatus)
	{
	case TC_NE_BATT_LEVEL_UP :
		if(TC_NE_CONFIG_CASE1 == u8case)
		{
			if(u8BattSocDisVal <= u8Stage1)
			{
				u8BattSocStatus = TC_NE_BATT_DIS_RED;
			}
			else
			{
				u8BattSocStatus = TC_NE_BATT_DIS_GREEN;
			}
		}
		else
		{
			if (u8BattSocDisVal <= u8Stage1)
			{
				u8BattSocStatus = TC_NE_BATT_DIS_GREY;
			}
			else if((u8BattSocDisVal > u8Stage1) && (u8BattSocDisVal <= u8Stage2))
			{
				u8BattSocStatus = TC_NE_BATT_DIS_RED;
			}
			else
			{
				u8BattSocStatus = TC_NE_BATT_DIS_GREEN;
			}
		}
		break;
	case TC_NE_BATT_LEVEL_DOWN :
		if(TC_NE_CONFIG_CASE1 == u8case)
		{
			if(u8BattSocDisVal < u8Stage1)
			{
				u8BattSocStatus = TC_NE_BATT_DIS_RED;
			}
			else
			{
				u8BattSocStatus = TC_NE_BATT_DIS_GREEN;
			}
		}
		else
		{
			if(u8BattSocDisVal < u8Stage1)
			{
				u8BattSocStatus = TC_NE_BATT_DIS_GREY;
			}
			else if((u8BattSocDisVal >= u8Stage1) && (u8BattSocDisVal < u8Stage2))
			{
				u8BattSocStatus = TC_NE_BATT_DIS_RED;
			}
			else
			{
				u8BattSocStatus = TC_NE_BATT_DIS_GREEN;
			}
		}
		break;
	default :
		// do nothing
		break;
	}

	return u8BattSocStatus;
}

/**********************************************************************************************************
*Function	: TC_NE_DrvHabit_Process																	  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: NONE																						  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-04-19																				  *
**********************************************************************************************************/

void TC_NE_DrvHabit_Process(void)
{
	uint16 u16EDrvHabitValue = 0;

	if((((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) || (TC_VEHICLE_HEV == TC_NE_Vehicle_Type_Data)) \
		&& ((TC_VEHICLE_MOTOR_PS == TC_NE_Motor_Type_Data) || (TC_VEHICLE_MOTOR_PS_P4 == TC_NE_Motor_Type_Data))) \
		|| ((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) && ((TC_VEHICLE_MOTOR_P2_P4 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_P2 == TC_NE_Motor_Type_Data) || (TC_VEHICLE_MOTOR_PARA_P2 == TC_NE_Motor_Type_Data))) \
		|| ((TC_VEHICLE_HEV == TC_NE_Vehicle_Type_Data) && ((TC_VEHICLE_MOTOR_P2 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_PARA_P2 == TC_NE_Motor_Type_Data))))
	{
		u16EDrvHabitValue = Get_EcodrvHabitVal();    //(N)*0.1-10
	}
	else
	{
		u16EDrvHabitValue = TC_NE_U16_NotDisp;    //不显示
	}

	if(NE_TimeTick.u16RateECODrvHabitTimeTick >= VCONFIG_DATA.u16RefreshRateECODrvHabit)
	{
		NE_TimeTick.u16RateECODrvHabitTimeTick = 0;
		NE_PHEV_DATA.u16DrvHabitValue = u16EDrvHabitValue;
	}
	else
	{
		NE_TimeTick.u16RateECODrvHabitTimeTick ++;
	}
}

/**********************************************************************************************************
*Function	: Get_EcodrvHabitVal																		  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: void																						  *
*																										  *
*Return 	: uint16																					  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-04-19																				  *
**********************************************************************************************************/

uint16 Get_EcodrvHabitVal(void)
{
	uint16 u16EDrvHabitValue = 0;
	uint8 u8MsgStatus = RTE_E_INVALID;

	u8MsgStatus = TC_RTE_API_Get_HCU_ECODrvHabit(&u16EDrvHabitValue);
	if(RTE_E_OK == u8MsgStatus)
	{
		if(u16EDrvHabitValue <= 0xC8)
		{
			// do nothing
		}
		else if((u16EDrvHabitValue >= 0xC9) && (u16EDrvHabitValue <= 0xFF))
		{
			u16EDrvHabitValue = 100;    //0x64 ECO
		}
	}
	else
	{
		u16EDrvHabitValue = 100;
	}
	return u16EDrvHabitValue;
}


/**********************************************************************************************************
*Function	: TC_NE_BMSChrgTime_Process																	  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: uint8																						  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-04-19																				  *
**********************************************************************************************************/

void TC_NE_ChrgTime_Process(uint8 u8ChrgSts)
{
	uint8 u8ChrgTimeHour;
	uint8 u8ChrgTimeMin;
	uint8 u8MsgStatus = RTE_E_INVALID;
	uint16 u16ChrgTimeVal;

	u8MsgStatus = TC_RTE_API_Get_BMS_ChrgDurationTime(&u16ChrgTimeVal);

	if ((1 == u8ChrgSts) || (2 == u8ChrgSts) || (6 == u8ChrgSts))
	{
		if (RTE_E_OK == u8MsgStatus)
		{
			if (u16ChrgTimeVal <= 0x3FE)
			{
				Get_ChrgTimeVal(u16ChrgTimeVal, &u8ChrgTimeHour, &u8ChrgTimeMin);
			}
			else
			{
				u8ChrgTimeHour = TC_NE_U8_InvalidDisp;    // --h -- min
				u8ChrgTimeMin = TC_NE_U8_InvalidDisp;
			}
		}
		else
		{
			u8ChrgTimeHour = TC_NE_U8_InvalidDisp;    // --h -- min
			u8ChrgTimeMin = TC_NE_U8_InvalidDisp;
		}

	}
	else if ((4 == u8ChrgSts) || (7 == u8ChrgSts))
	{
		u8ChrgTimeHour = TC_NE_U8_InvalidDisp;    // --h -- min
		u8ChrgTimeMin = TC_NE_U8_InvalidDisp;
	}
	else
	{
		u8ChrgTimeHour = TC_NE_U8_NotDisp;    // not display
		u8ChrgTimeMin = TC_NE_U8_NotDisp;
	}

	if(NE_TimeTick.u16RateChrgDurationTimeTick >= VCONFIG_DATA.u16RefreshRateChrgDuration)
	{
		NE_TimeTick.u16RateChrgDurationTimeTick = 0;
		NE_PHEV_DATA.u8ChrgTimeHour = u8ChrgTimeHour;
		NE_PHEV_DATA.u8ChrgTimeMin = u8ChrgTimeMin;
	}
	else
	{
		NE_TimeTick.u16RateChrgDurationTimeTick ++;
	}

}

/**********************************************************************************************************
*Function	: Get_ChrgTimeVal																		      *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: uint16, uint8, uint8																		  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-04-19																				  *
**********************************************************************************************************/

void Get_ChrgTimeVal(uint16 u16ChrgTimeRaw, uint8 *pChrgTimeHour, uint8 *pChrgTimeMin)
{
	uint8 u8ChrgTimeMin = 0;
	uint8 u8Remainder = 0;

	*pChrgTimeHour = (uint8)(u16ChrgTimeRaw / 60u);
	u8ChrgTimeMin = (uint8)(u16ChrgTimeRaw % 60u);

	u8Remainder = u8ChrgTimeMin % 5u;
	if (u8Remainder < 3)    // < 2.5min
	{
		u8ChrgTimeMin = (u8ChrgTimeMin / 5u) * 5u;
	}
	else    // > 2.5min
	{
		u8ChrgTimeMin = ((u8ChrgTimeMin / 5u) * 5u) + 5u;
		if (60 == u8ChrgTimeMin)
		{
			u8ChrgTimeMin = 0;
			*pChrgTimeHour = *pChrgTimeHour + 1u;
		}
	}

	*pChrgTimeMin = u8ChrgTimeMin;
}

/**********************************************************************************************************
*Function	: TC_NE_ChrgStatus_Process																	  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: NONE																						  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-04-19																				  *
**********************************************************************************************************/

void TC_NE_ChrgStatus_Process(void)
{
	uint8 u8ChrgStsDisp = TC_NE_U8_InvalidDisp;
	uint16 u16ChrgCurr = TC_NE_U16_NotDisp;

#if (1 == TC_NE_ChargSts_Output_EN)
	RTE_TC_NE_ChargStsData sTC_NE_ChargStsOut;
#endif

	if((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) \
		&& ((TC_VEHICLE_MOTOR_PS == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_PS_P4 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_P2 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_P2_P4 == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_PARA_P2 == TC_NE_Motor_Type_Data)))
	{
		u8ChrgStsDisp = Get_ChrgStsVal();

		// timetick set
		if (u8ChrgStsDisp != u8ChrgStsDispPre)
		{
			u8ChrgStsDispPre = u8ChrgStsDisp;
			NE_TimeTick.u16RateCurrentTimeTick = VCONFIG_DATA.u16RefreshRateCurrent;
			NE_TimeTick.u16RateChrgDurationTimeTick = VCONFIG_DATA.u16RefreshRateChrgDuration;
		}

		u16ChrgCurr = Get_ChrgCurrVal(u8ChrgStsDisp);
		TC_NE_ChrgTime_Process(u8ChrgStsDisp);
	}
	else
	{
		u16ChrgCurr = TC_NE_U16_NotDisp;
		u8ChrgStsDisp = TC_NE_U8_InvalidDisp;
		TC_NE_ChrgTime_Process(u8ChrgStsDisp);
	}

	if(NE_TimeTick.u16RateCurrentTimeTick >= VCONFIG_DATA.u16RefreshRateCurrent)
	{
		NE_TimeTick.u16RateCurrentTimeTick = 0;
		NE_PHEV_DATA.u16ChrgStsCurr = u16ChrgCurr;
	}
	else
	{
		NE_TimeTick.u16RateCurrentTimeTick ++;
	}

	// PHEV: charge fault status output
#if (1 == TC_NE_ChargSts_Output_EN)
	if (7 == u8ChrgStsDisp)
	{
		sTC_NE_ChargStsOut.ChargFaultSts = 1;
	}
	else
	{
		sTC_NE_ChargStsOut.ChargFaultSts = 0;
	}

	(void)Rte_Write_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element((const TC_NE_ChargStsOutput *)&sTC_NE_ChargStsOut);
#endif

	NE_PHEV_DATA.u8ChrgStsDsp = u8ChrgStsDisp;
}

/**********************************************************************************************************
*Function	: Get_ChrgCurrVal																	          *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: uint8																						  *
*																										  *
*Return 	: uint16																					  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-04-19																				  *
**********************************************************************************************************/

uint16 Get_ChrgCurrVal(uint8 u8ChrgSts)
{
	uint16 u16ChrgCurrRaw = 0;
	uint16 u16ChrgCurrVal = 0;
	uint8 u8Remainder = 0;
	uint8 u8Msgatus = RTE_E_INVALID;

	u8Msgatus = TC_RTE_API_Get_BMS_PackCurr(&u16ChrgCurrRaw);

	if (1 == u8ChrgSts)
	{
		if (RTE_E_OK == u8Msgatus)
		{
			if (u16ChrgCurrRaw <= 0x2710)
			{
				u8Remainder = (uint8)((u16ChrgCurrRaw * 2u) % 10u);
				if (u8Remainder < 5)
				{
					u16ChrgCurrVal = (u16ChrgCurrRaw * 2u) / 10u;
				}
				else
				{
					u16ChrgCurrVal = ((u16ChrgCurrRaw * 2u) / 10u) + 1u;
				}
			}
			else
			{
				u16ChrgCurrVal = TC_NE_U16_InvalidDisp;    // display ---A
			}
		}
		else
		{
			u16ChrgCurrVal = TC_NE_U16_InvalidDisp;    // display ---A
		}

	}
	else if ((2 == u8ChrgSts) || (4 == u8ChrgSts) \
		|| (6 == u8ChrgSts) || (7 == u8ChrgSts))
	{
		u16ChrgCurrVal = TC_NE_U16_InvalidDisp;    // display ---A
	}
	else
	{
		u16ChrgCurrVal = TC_NE_U16_NotDisp;    // not display
	}

	return u16ChrgCurrVal;
}

/**********************************************************************************************************
*Function	: Get_ChrgStsVal																		      *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: NONE																						  *
*																										  *
*Return 	: uint8																						  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-04-19																				  *
**********************************************************************************************************/

uint8 Get_ChrgStsVal(void)
{
	uint8 u8ChrgSts = 0;
	uint8 u8Msgatus = RTE_E_INVALID;
	uint8 u8OBCConSts = 0;
	uint8 u8BMSConSts = 0;

	u8ChrgSts = (uint8)TC_RTE_API_Get_HCU_Charge_Status();    //timeout, defeult value 0

	if (((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) \
		|| (TC_VEHICLE_HEV == TC_NE_Vehicle_Type_Data)) \
		&& ((TC_VEHICLE_MOTOR_PS == TC_NE_Motor_Type_Data) \
		|| (TC_VEHICLE_MOTOR_PS_P4 == TC_NE_Motor_Type_Data)))
	{
		u8Msgatus = TC_RTE_API_Get_BMS_StsCC2Line(&u8BMSConSts);
		u8Msgatus &= TC_RTE_API_Get_OBC_ConnectSts(&u8OBCConSts);
		if ((RTE_E_OK == u8Msgatus) && ((1 == u8BMSConSts) || (1 == u8OBCConSts)))
		{
			u8OBCConSts = 1;
		}
		else
		{
			u8OBCConSts = 0;
		}
	}
	else
	{
		u8Msgatus = TC_RTE_API_Get_OBC_ConnectSts(&u8OBCConSts);
	}

	if (RTE_E_OK == u8Msgatus)
	{
		if (1 != u8OBCConSts)
		{
			u8ChrgSts = TC_NE_U8_NotDisp;	// 充电状态文字不显示
		}
		else if ((1 == u8OBCConSts) && ((u8ChrgSts > 7) || (0 == u8ChrgSts) || (5 == u8ChrgSts)))
		{
			u8ChrgSts = TC_NE_U8_NotDisp;	// 充电状态文字不显示
		}
		else
		{
			//do nothing
		}
	}
	else
	{
		u8ChrgSts = TC_NE_U8_InvalidDisp;	//充电卡片不显示
	}

	return u8ChrgSts;
}

/**********************************************************************************************************
*Function	: TC_NE_EnergyFlow_Process																	  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: NONE																						  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-05-26																				  *
**********************************************************************************************************/

void TC_NE_EnergyFlow_Process(void)
{
	uint8 u8EnergyFlowValue = TC_NE_U8_NotDisp;

	if ((TC_VEHICLE_HEV == TC_NE_Vehicle_Type_Data) && (TC_VEHICLE_MOTOR_PS == TC_NE_Motor_Type_Data))
	{
		u8EnergyFlowValue = Get_EnergyFlow_Value(TC_NE_CONFIG_CASE1);
	}
	else if ((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) && (TC_VEHICLE_MOTOR_PS == TC_NE_Motor_Type_Data))
	{
		u8EnergyFlowValue = Get_EnergyFlow_Value(TC_NE_CONFIG_CASE2);
	}
	else if(((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) || (TC_VEHICLE_HEV == TC_NE_Vehicle_Type_Data)) \
		&& (TC_VEHICLE_MOTOR_P2 == TC_NE_Motor_Type_Data))
	{
		u8EnergyFlowValue = Get_EnergyFlow_Value(TC_NE_CONFIG_CASE3);
	}
	else if(((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) || (TC_VEHICLE_HEV == TC_NE_Vehicle_Type_Data)) \
		&& (TC_VEHICLE_MOTOR_PARA_P2 == TC_NE_Motor_Type_Data))
	{
		u8EnergyFlowValue = Get_EnergyFlow_Value(TC_NE_CONFIG_CASE4);
	}
	else if((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) && (TC_VEHICLE_MOTOR_P2_P4 == TC_NE_Motor_Type_Data))
	{
		u8EnergyFlowValue = Get_EnergyFlow_Value(TC_NE_CONFIG_CASE5);
	}
	else if ((TC_VEHICLE_PHEV == TC_NE_Vehicle_Type_Data) && (TC_VEHICLE_MOTOR_PS_P4 == TC_NE_Motor_Type_Data))
	{
		u8EnergyFlowValue = Get_EnergyFlow_Value(TC_NE_CONFIG_CASE6);
	}
	else
	{
		u8EnergyFlowValue = TC_NE_U8_NotDisp;    // not display
	}

	if(NE_TimeTick.u16RateEnergyFlowTimeTick >= VCONFIG_DATA.u16RefreshRateEnrgFlow)
	{
		NE_TimeTick.u16RateEnergyFlowTimeTick = 0;
		NE_PHEV_DATA.u8EnergyFlow_Value = u8EnergyFlowValue;
	}
	else
	{
		NE_TimeTick.u16RateEnergyFlowTimeTick ++;
	}
}

/**********************************************************************************************************
*Function	: Get_EnergyFlow_Value																	  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: NONE																						  *
*																										  *
*Return 	: uint8																						  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-05-26																				  *
**********************************************************************************************************/

uint8 Get_EnergyFlow_Value(uint8 u8Case)
{
	uint8 u8Msgatus = RTE_E_INVALID;
	uint8 u8EnergyFlowValue = TC_NE_U8_NotDisp;

	if ((TC_NE_CONFIG_CASE1 == u8Case) || (TC_NE_CONFIG_CASE2 == u8Case) \
		|| (TC_NE_CONFIG_CASE6 == u8Case))
	{
		u8Msgatus = TC_RTE_API_Get_HCU_EnrgFlowInd_DHT(&u8EnergyFlowValue);
	}
	else if ((TC_NE_CONFIG_CASE3 == u8Case) || (TC_NE_CONFIG_CASE4 == u8Case) \
		|| (TC_NE_CONFIG_CASE5 == u8Case))
	{
		u8Msgatus = TC_RTE_API_Get_HCU_EnrgFlowInd_P2(&u8EnergyFlowValue);
	}
	else
	{
		// do nothing
	}

	switch (u8Case)
	{
		case TC_NE_CONFIG_CASE1 :	// HEV+PS
			if(RTE_E_OK == u8Msgatus)
			{
				if(u8EnergyFlowValue > 0x0B)
				{
					u8EnergyFlowValue = TC_NE_U8_InvalidDisp;    //"暂时无法获取能量流信息"
				}
				else
				{
					// do nothing
				}
			}
			else
			{
				u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
			}
			break;
		case TC_NE_CONFIG_CASE2 :	// PHEV+PS
			if(RTE_E_OK == u8Msgatus)
			{
				if((u8EnergyFlowValue > 0x0F) && (0x23 != u8EnergyFlowValue) && (0x24 != u8EnergyFlowValue))
				{
					u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
				}
				else
				{
					// do nothing
				}
			}
			else
			{
				u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
			}
			break;
		case TC_NE_CONFIG_CASE3 :	// HEV/PEHV+P2
			if(RTE_E_OK == u8Msgatus)
			{
				if((0x0 == u8EnergyFlowValue) || (0x3 == u8EnergyFlowValue) \
					|| (0x6 == u8EnergyFlowValue) || (0x8 == u8EnergyFlowValue))
				{
					// do nothing
				}
				else if (((u8EnergyFlowValue >= 0xA) && (u8EnergyFlowValue <= 0xC)) \
					|| ((u8EnergyFlowValue >= 0xF) && (u8EnergyFlowValue <= 0x13)))
				{
					// do nothing
				}
				else
				{
					u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
				}
			}
			else
			{
				u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
			}
			break;
		case TC_NE_CONFIG_CASE4 :	// HEV/PHEV+PP2
			if(RTE_E_OK == u8Msgatus)
			{
				if((0x0 == u8EnergyFlowValue) || (0x3 == u8EnergyFlowValue) \
					|| (0x6 == u8EnergyFlowValue) || (0x8 == u8EnergyFlowValue) \
					|| (0xA == u8EnergyFlowValue) || (0xB == u8EnergyFlowValue))
				{
					// do nothing
				}
				else if ((u8EnergyFlowValue >= 0xF) && (u8EnergyFlowValue <= 0x19))
				{
					// do nothing
				}
				else
				{
					u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
				}
			}
			else
			{
				u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
			}
			break;
		case TC_NE_CONFIG_CASE5 :	// PHEV+P2_P4
			if(RTE_E_OK == u8Msgatus)
			{
				if(u8EnergyFlowValue <= 0x13)
				{
					// do nothing
				}
				else
				{
					u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
				}
			}
			else
			{
				u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
			}
			break;
		case TC_NE_CONFIG_CASE6 :	//PHEV+PS_P4
			if(RTE_E_OK == u8Msgatus)
			{
				if(u8EnergyFlowValue > 0x24)
				{
					u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
				}
				else
				{
					// do nothing
				}
			}
			else
			{
				u8EnergyFlowValue = TC_NE_U8_InvalidDisp;
			}
			break;
		default :
			// do nothing
			break;
	}

	return u8EnergyFlowValue;
}

/**********************************************************************************************************
*Function	: TC_NE_StabilizerBar_Process																  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: NONE																						  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: ZJ																						  *
*																										  *
*Date		: 2022-02-21																				  *
**********************************************************************************************************/
void TC_NE_StabilizerBar_Process(void)
{
	uint8 u8BarConSts = 0;
	uint8 u8Msgatus = RTE_E_INVALID;

	if (2u == TC_NE_StabilizerBarEn)
	{
		u8Msgatus = TC_RTE_API_Get_BarConnSts(&u8BarConSts);
		if (RTE_E_OK == u8Msgatus)
		{
			if (2u == u8BarConSts)
			{
				NE_PHEV_DATA.u8StabilizerBarStatus = TC_NE_STABAR_DISCONN;
			}
			else if (5u == u8BarConSts)
			{
				NE_PHEV_DATA.u8StabilizerBarStatus = TC_NE_STABAR_UNEXPECT;
			}
			else
			{
				NE_PHEV_DATA.u8StabilizerBarStatus = TC_NE_STABAR_CONNECT;
			}
		}
		else
		{
			NE_PHEV_DATA.u8StabilizerBarStatus = TC_NE_STABAR_CONNECT;
		}
	}
}

/**********************************************************************************************************
*Function	: TC_NE_RTE_SBUSUpdate																		  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: NONE																						  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Deng Jiangbo																				  *
*																										  *
*Date		: 2021-05-26																				  *
**********************************************************************************************************/

void TC_NE_RTE_SBUSUpdate(void)
{
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.PowerPointer= NE_PHEV_DATA.u16TotDrvReqPowerValue;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.AvailPower= NE_PHEV_DATA.u16AvailPowerValue;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.PowerBattery_Status= NE_PHEV_DATA.u8BattSocStatus;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.PowerBattery_Percent= NE_PHEV_DATA.u8BattSocValue;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.DriveHabit= NE_PHEV_DATA.u16DrvHabitValue;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.ChrgTime_Hour= NE_PHEV_DATA.u8ChrgTimeHour;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.ChrgTime_Min= NE_PHEV_DATA.u8ChrgTimeMin;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.ChargeCurrent= NE_PHEV_DATA.u16ChrgStsCurr;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.ChargeStatus= NE_PHEV_DATA.u8ChrgStsDsp;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.EnergyFlow_Data = NE_PHEV_DATA.u8EnergyFlow_Value;
	NE_ipc.u_NewEnergyu32NewEnergy_data_t.s_u32NewEnergy_data_t.ElectronicStabilizerBar_Status = NE_PHEV_DATA.u8StabilizerBarStatus;
	(void) Rte_Call_IPC_Send_IPC_Send((uint8)M2S_NEWENERGY,(uint8 *)&NE_ipc,(uint16)sizeof(IPC_M2S_ClusterAppAPPNewEnergy_t),FALSE);
}

#define SWC_TC_STOP_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

