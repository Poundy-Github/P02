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
*File Name   : TT_Process.h                                                                               *
*                                                                                                         *
*Description : Telltale module logic process source file.                                                 *
*                                                                                                         *
*Author      : Chao Feng                                                                                  *
*                                                                                                         *
*Platform    : Free Rtos System                                                    						  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

#include "Rte_Common_Normal.h"
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TT_Config.h"
#include "SWC_TT_Interface.h"
#include "Dio.h"
#include "Com.h"
#include "VConfig.h"
//#include "IoHwAb.h"
#include "IoHwAb_Cfg_RI.h"
#include <string.h>
#include "SWC_TT_Adapt.h"

/**********************************************************************************************************
*																										  *
*																										  *
*	Telltale Control Macro Definition																	  *
*																										  *
*																										  *
**********************************************************************************************************/
//请注: 不要修改如下这些报警灯控制宏定义!!!


#define ON  1
#define OFF 0

#define TT_SET(TelltaleID,SetLogicStatus) \
	if((TelltaleID) < TT_enTELLTALE_TOTAL_NUMBER) {stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.LogicType = (SetLogicStatus);}

#define FTT_SET(TelltaleID,SetLogicStatus) \
	if((TelltaleID) < TT_enTELLTALE_TOTAL_NUMBER) {stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.LogicType = (SetLogicStatus);}

//这个宏用于设置报警灯逻辑状态,输入为报警灯索引
/*********************************************************************************************************/

#define TT_GET(TelltaleID) \
	((TelltaleID) < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.LogicType : TT_enTURN_OFF

#define TT_GET_E(TelltaleID) \
	(TelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.ExternalLogicType : TT_enTURN_OFF

#define TT_GET_R(TelltaleID) \
	(TelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.ResultLogicType : TT_enTURN_OFF

//这组宏用于获取报警灯逻辑状态,输入为报警灯索引,输出为报警灯逻辑状态
/*********************************************************************************************************/

#define TT_GET_L(TelltaleID) \
	(TelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.LightType : TT_enLAMP_OFF_EDGE

//这个宏用于获取报警灯点亮熄灭状态,输入为报警灯索引,输出为点亮熄灭状态
/*********************************************************************************************************/

#define TT_SET_CFG(TelltaleID,SetSwitchStatus) \
	if((TelltaleID) < TT_enTELLTALE_TOTAL_NUMBER) {stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.DynamicConfigration = (SetSwitchStatus);}

#define FTT_SET_CFG(TelltaleID,SetSwitchStatus) \
	if((TelltaleID) < TT_enTELLTALE_TOTAL_NUMBER) {stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.DynamicConfigration = (SetSwitchStatus);}


//这个宏用于设置报警灯动态开关,输入为报警灯索引号和开关状态
/*********************************************************************************************************/

#define TT_GET_CFG(TelltaleID)  \
	(TelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.DynamicConfigration : FALSE

//这个宏用于获取报警灯动态开关,输入为报警灯索引,输出为开关状态
/*********************************************************************************************************/

/*********************************************************************************************************/

#define TT_SET_DID(TelltaleID,SetDidConfig) \
	if((TelltaleID) < TT_enTELLTALE_TOTAL_NUMBER) {stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.DidConfigEnable = (SetDidConfig);}

#define FTT_SET_DID(TelltaleID,SetDidConfig) \
	if((TelltaleID) < TT_enTELLTALE_TOTAL_NUMBER) {stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.DidConfigEnable = (SetDidConfig);}

//这个宏用于设置报警灯的配置使能状态
/*********************************************************************************************************/

#define TT_GET_DID(TelltaleID)  \
	(TelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.DidConfigEnable : FALSE

//这个宏用于获取报警灯的配置使能状态
/*********************************************************************************************************/

#define FTT_SET_Report_DID(TelltaleID,SetDidConfig) \
		if((TelltaleID) < TT_enTELLTALE_TOTAL_NUMBER) {stMainObject->stTelltaleControlStatus[TelltaleID].unStatus.stStatus.Vehselfchecksts = (SetDidConfig);}

//这个宏用于设置报警灯的自检播报状态
/*********************************************************************************************************/

#define TT_SET_SYSTEM(SystemStatus)  \
	stMainObject->unSystemErrorStatus.u32SystemErrorStatus |= SystemStatus

#define TT_CLEAR_SYSTEM(SystemStatus)  \
	stMainObject->unSystemErrorStatus.u32SystemErrorStatus &= (~enStatus)

#define TT_CHECK_SYSTEM(SystemStatus)  \
	((stMainObject->unSystemErrorStatus.u32SystemErrorStatus & (uint32)enStatus) != FALSE) ? TRUE : FALSE

//这组宏用于获取或检查模块状态,输入为状态,输出为是否存在该状态
/*********************************************************************************************************/

#define TT_COUNT(Object)  stMainObject->stCount.#Object

#define TT_TIMER(Object)  stMainObject->stTimer.#Object

#define TT_FLAG(Object)  stMainObject->unFunctionFlag.stFuncFlag.#Object

//这组宏用于表示模块内计数,输入计时器或标志位对象,输入为对象
//Example: TT_COUNT(u16ExitAbnormalResponseDelayMaxTickCount)
/**********************************************************************************************************
*																										  *
*																										  *
*	Custom  Macro Definition																			  *
*																										  *
*																										  *
**********************************************************************************************************/
/**********************************************************************************************************
* CAN Message Macro Definition 																			  *
**********************************************************************************************************/
#if 0
/*Test Signal*/
#define TT_CFG_TEST_MSG_HAS_RECEIVED    ((!VNIM_GWMSG300_MSG_NEVER_RECVD()) && (!VNIM_GWMSG300_MSG_MISSING()))

#define TT_CFG_TEST_MSG_VALUE           (VNIM_GWMSG300_RX_ECM_ENGN()/2)
/*********************************************************************************************************/
#endif

#define TT_500ms_LowFuelPress_COUNT (500/20)

#define TT_GET_IGN_OFF_STATUS		0
#define TT_GET_IGN_ON_STATUS		1

#define TT_SPEED_UP					1
#define TT_SPEED_DOWN				2
#define TT_SPEED_STABLE				0
#define TT_SPEED_TRIGGER_KM			120
#define TT_SPEED_RELEASE_KM			115
#define TT_SPEED_TRIGGER_MPH		75
#define TT_SPEED_RELEASE_MPH		70
#define TT_SPEED_UNIT_KM			1
#define TT_SPEED_UNIT_MPH			2

#define TT_TSR_STS_OFF					0
#define TT_TSR_STS_FUSION				1
#define TT_TSR_STS_VISION				2
#define TT_TSR_STS_NAVIGATION_ONLY		3
#define TT_TSR_SPEED_LIMIT_NONE         0
#define TT_TSR_SPEED_LIMIT				1
#define TT_TSR_SPEED_LIMIT_CANCEL		2
#define TT_TSR_SPEED_LIMIT_WARN			1

#define TT_LOWFUEL_TACHO_200RPM			200
#define TT_LOWFUEL_TACHO_400RPM			400

#define RBS_DISABLE         (0)
#define RBS_ENABLE_CASE1    (1)
#define RBS_ENABLE_CASE2    (2)
#define RBS_ENABLE_CASE3    (3)

/* Over Speed Warning */
#define TT_OVER_SPEED_ON	(120u)
#define TT_OVER_SPEED_OFF	(115u)
#define TT_OVER_SPEED_MPH_ON  (75u)
#define TT_OVER_SPEED_MPH_OFF (70u)

#define FTT_TESTBIT( operand, bit_mask )        (((operand) &  (bit_mask)) != ((bit_mask) - (bit_mask)))
#define FTT_SETBIT( operand, bit_mask )         ((operand) |= (bit_mask))
#define FTT_CLEARBIT( operand, bit_mask )       ((operand) &= ((UINT32)~(bit_mask)))

/* log output */
#define TT_Hardwired_NUM	(2u)
#define TT_TurnLight_NUM	(2u)
#define TT_LogOutput_NUM	TT_Hardwired_NUM
#define TT_LogOutput_SIZE   (sizeof(uint8) * TT_LogOutput_NUM)
#define TT_TurnLight_TASK   TT_CFG_TIME_TASK_CYCLE

typedef enum
{
	TT_SIGNAL_NEVERRECEIVE = 0,
	TT_SIGNAL_RECEIVED,
	TT_SIGNAL_TIMEOUT,
	TT_SIGNAL_SIGNAL_ERROR
}TT_SIGNAL_STS_ENUM;


typedef enum
{
	TT_FUN_INACTIVE = 0,
	TT_FUN_ACTIVE,
	TT_FUN_STANDBY,
	TT_FUN_RESERVE,
	TT_FUN_FAILURE
}TT_FUN_ENUM;

typedef enum
{
	TT_ACC_PASSIVE = 1,
	TT_ACC_STANDBY,
	TT_ACC_ACTIVE_CONTROL,
	TT_ACC_BREAK_ONLY,
	TT_ACC_OVERRIDE,
	TT_ACC_PEPS_FAILURE = (uint8)7,
	TT_ACC_FAILURE
}TT_ACC_FUN_ENUM;

typedef enum
{
	TT_TJA_PASSIVE = 1,
	TT_TJA_ACTIVE,
	TT_TJA_READY,
	TT_TJA_FAILURE
}TT_TJA_FUN_ENUM;

typedef enum
{
	TT_EPB_UNDEFINED = 0,
	TT_EPB_NO_ERROR,
	TT_EPB_ERROR,
	TT_EPB_DIAG
}TT_EPB_FUN_ENUM;

typedef enum
{
	TT_EBD_HW_LOW = 0,
	TT_EBD_HW_HIGH
}TT_EBD_FUN_ENUM;

typedef enum
{
	TT_LDW_STS = 1,
	TT_LKA_STS,
	TT_LCK_STS
}TT_LDW_FUN_ENUM;

typedef enum
{
	TT_PBF_INSTRUMENT_DISPLAY = (uint8)3,
	TT_PBF_RANGE_LIMITED,
	TT_PBF_PRECHARGE_LOCKED,
	TT_PBF_DELAYED_OPEN,
	TT_PBF_EMERGENCY_OPEN
}TT_PBF_FUN_ENUM;

typedef enum
{
	TT_SBT_LAMP_OFF = 0,
	TT_SBT_LAMP_ON,
	TT_SBT_RESERVED,
	TT_SBT_LAMP_BLINK
}TT_SBT_FUN_ENUM;

typedef enum
{
	TT_SEAT_BELT_DRV = 0,
	TT_SEAT_BELT_FRONT,
	TT_SEAT_BELT_ALL
}TT_SEAT_BELT_CFG;

typedef enum
{
	TT_LOWFUEL_INVALID = 0,
	TT_LOWFUEL_NOERROR,
	TT_SHORT_TO_BAT,
	TT_SHORT_TO_GND
}TT_LOWFUEL_FUN_ENUM;

typedef enum
{
	TT_CHARGE_OFF = 0,
	TT_CHARGE_GREEN,
	TT_CHARGE_RED,
	TT_CHARGE_E_YELLOW,
	TT_CHARGE_E_RED
}TT_CHARGE_FUN_ENUM;

typedef enum
{
	TT_ALERT_OFF = 0,
	TT_ALERT_SECONDARY,
	TT_ALERT_HIGH
}TT_ALERT_FUN_ENUM;

typedef enum
{
	TT_FEDL_UNLOCK = 0,
	TT_FEDL_LOCKED,
	TT_FEDL_OVERSPEED,
	TT_FEDL_RESERVED,
	TT_FEDL_LOCK_DENY,
	TT_FEDL_FAULT = (uint8)14
}TT_FEDL_FUN_ENUM;

typedef enum
{
	TT_CDLL_ModeUnkown = 0,
	TT_CDLL_SystemFault,
	TT_CDLL_Mode_2WD,
	TT_CDLL_Mode_4WD,
	TT_CDLL_Modeactive,
	TT_CDLL_Reserved,
	TT_CDLL_Mode_4WD_lowRange,
	TT_CDLL_SportMode,
	TT_CDLL_Unused
}TT_CDLL_FUN_ENUM;

typedef enum
{
	TT_HSAP_OFF = 0,
	TT_HSAP_IDLE,
	TT_HSAP_READY,
	TT_HSAP_ACTIVE,
	TT_HSAP_RESERVED,
	TT_HSAP_WARNING_1,
	TT_HSAP_WARNING_2,
	TT_HSAP_WARNING_3
}TT_HSAP_FUN_ENUM;

typedef enum
{
	TT_HSAS_OFF = 0,
	TT_HSAS_SAFE_STOP,
	TT_HSAS_STANDBY,
	TT_HSAS_READY,
	TT_HSAS_ACTIVE,
	TT_HSAS_OVERRIDE,
	TT_HSAS_SLOW_RETREAT,
	TT_HSAS_FAULT = (uint8)15
}TT_HSAS_FUN_ENUM;

typedef enum
{
	TT_STEER_OFF = 0,
	TT_STEER_STANDBY,
	TT_STEER_ACTIVE,
	TT_STEER_FAILURE
}TT_STEER_FUN_ENUM;

typedef enum
{
	TT_BMS_DISCHARGE = 0,
	TT_BMS_CHARGING = 4,
	TT_BMS_REDUCED_POWER = 9
}TT_BMS_FUN_ENUM;

typedef enum
{
	TT_MODE_2WD = 2,
	TT_MODE_4WD = 3,
	TT_MODE_4WD_LOW = 6
}TT_2H4H4L_FUN_ENUM;

typedef enum
{
	TT_BUL_VSG_OFF = 0,
	TT_BUL_VSG_ON,
	TT_BUL_VSG_FAIL,
	TT_BUL_VSG_UNKNOWN
}TT_BUL_VSG_ENUM;

// TODO: < REPLACE START >

/*Battery Pack Charge     0x2F6 and 0x316*/
#define TT_CFG_CAN_BMS_FD10_HAS_RECEIVED                0
#define TT_CFG_CAN_CONDITION_BMS_CHARGE_TURN_ON         0

/*Battery Off     0x2F6*/
#define TT_CFG_CAN_CONDITION_BMS_SAFETY_STS_TURN_ON     0

/*2H4H4L   0x251*/
#define TT_CFG_CAN_2H4H4L_TOD1_HAS_RECEIVED             0
#define TT_CFG_CAN_CONDITION_SYSTEMOPERMOD_TURN_ON      0

// TODO: < REPLACE END >

/**********************************************************************************************************
*																										  *
*																										  *
*				              Macro																		  *
*																										  *
*																										  *
**********************************************************************************************************/
#define SWC_TT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TT_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static uint8 u8PowerMode_Pre;
static uint16 u16LowFuelCheckTime;
static uint16 u16LowFuelDelayTime;
static boolean u8PowerChangeFlag;
static uint8 u8GetEngineRunningStsPre;
static uint16 u16TimeCountTpms;
static uint16 u8TimeCountEPBOn;
static uint16 u8TimeCountEPBFlash;
static TT_TSR_Info tsr_value;
static TT_V2X_Info v2x_Info;
static uint16 u8GetConfig_LowFuelDelayTime;
static uint16 u8Getonfig_LowFuelCheckTime;
static uint16 u16Getonfig_EPBlightorflashtime;
static uint16 u16Getonfig_Tpms_flashtime;

#define SWC_TT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TT_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define SWC_TT_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"
static uint8 u8EngVdtyPre = 0;
static uint8 u8Oil_HW_C3 = 0;
static uint8 u8TTNormalselfchecksts = 1;
static uint8 u8LowFuelPressTime = 0;
static boolean boLowFuelPressTimeflg = FALSE;
static uint8 u8TpmsSelfchecksts = 1;
#define SWC_TT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"


#define SWC_TT_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_TT_MemMap.h"
static uint8 u8TurnLeftFlashOnResult = 1;
static uint8 u8TurnLeftFlashOnTimeFlag = 0;
static uint32 u32TurnLeftFlashOnTime = 0;
static uint8 u8TurnRightFlashOnResult = 1;
static uint8 u8TurnRightFlashOnTimeFlag = 0;
static uint32 u32TurnRightFlashOnTime = 0;
static uint8 u8SAS_ReceivedTime = 0;
static uint8 u8SAS_ReceivedPre = RTE_E_OK;

static uint8 u8OilPressLowSts = 0;  // enFTT_LowFuelPress: C3 Hardwired TT status

// log output: key variables buffer
static uint8 u8LogOut_CurSts[TT_LogOutput_NUM] = {0};
static uint8 u8LogOut_PreSts[TT_LogOutput_NUM] = {0};

// log output: turn light
static uint8 u8TurnLight_PreSts[TT_TurnLight_NUM] = {0};
static uint32 u32TLTimeTick[TT_TurnLight_NUM] = {0};

#define SWC_TT_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_TT_MemMap.h"

/**********************************************************************************************************
*																										  *
*																										  *
*	Telltale Process Function  Definition																  *
*																										  *
*																										  *
**********************************************************************************************************/

#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"
/*******************************************************************************
*	Function name		: FTT_vBatteryCharge_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_BatteryChargeFuel_ENABLE  1
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_BatteryChargeFuel_ENABLE  1
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_BatteryChargeFuel_ENABLE  1
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_BatteryChargeFuel_ENABLE  1
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_BatteryChargeFuel_ENABLE  1
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_BatteryChargeFuel_ENABLE  0
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_BatteryChargeFuel_ENABLE  0
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_BatteryChargeFuel_ENABLE  0
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_BatteryChargeFuel_ENABLE  0
	#define TT_BatteryChargeP0_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_BatteryChargeFuel_ENABLE  1
	#define TT_BatteryChargeP0_ENABLE  0
#else
	#define TT_BatteryChargeFuel_ENABLE  0
	#define TT_BatteryChargeP0_ENABLE  0
#endif

void FTT_vBatteryCharge_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Battery_Received = RTE_E_INVALID;
	uint8 u8Battery_Value = 0;
	uint8 u8Battery_Config_Byte39 = 0;
	uint8 u8Battery_Config_Byte2 = 0;
	uint8 u8Battery_Config_Byte30 = 0;
	uint32 u32Battery_HW_C2 = 0;
	uint8 u8PowerMode = 0;
	boolean bBattery_Config_Byte39_Sts = FALSE;
	boolean bBattery_Config_Byte2_Sts = FALSE;
	uint8 u8BattChrgLmpStsOutPut = 0;
	TT_CFG_enStatusType u8BatteryChargeFuel_State = TT_enTURN_OFF;
	TT_CFG_enStatusType u8BatteryChargeP0_State = TT_enTURN_OFF;

	FTT_SET_CFG(enFTT_BatteryCharge,ON);
	FTT_SET_DID(enFTT_BatteryCharge,OFF);
	u8PowerMode = FTT_Adapt_GetPowerMode_State();
	u8Battery_Received = FTT_Adapt_GetMessage_GentrWarnLmpSts(&u8Battery_Value);
	u8Battery_Config_Byte39 = FTT_Adapt_GetVconfig(VCONFIG_KIND_AC_GENERATOR_PROPERTIES);
	u8Battery_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8Battery_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	(void)FTT_Adapt_GetHW_C2(&u32Battery_HW_C2);

	if ((1 == u8Battery_Config_Byte39) || (2 == u8Battery_Config_Byte39))
	{
		bBattery_Config_Byte39_Sts = TRUE;
	}
	else
	{
	 	bBattery_Config_Byte39_Sts = FALSE;
	}

	if ((0 == u8Battery_Config_Byte2) || (1 == u8Battery_Config_Byte2) || (2 == u8Battery_Config_Byte2) || (7 == u8Battery_Config_Byte2))
	{
	 	bBattery_Config_Byte2_Sts = TRUE;
	}
	else
	{
	 	bBattery_Config_Byte2_Sts = FALSE;
	}
	if(TT_BatteryChargeFuel_ENABLE)
	{	//traditional fuel car
		if ((bBattery_Config_Byte39_Sts) && (bBattery_Config_Byte2_Sts))
		{
		 	if (1 == u8Battery_Config_Byte39)
			{
				if (u32Battery_HW_C2 < 300)
				{
					u8BatteryChargeFuel_State = TT_enTURN_ON;
				}
				else
				{
					u8BatteryChargeFuel_State = TT_enTURN_OFF;
				}

				// log ouput
				if (TRUE == SWC_TT_LOGOUT_ENBLE)
				{
					if (u8LogOut_CurSts[0] != u8BatteryChargeFuel_State)
					{
						u8LogOut_CurSts[0] = (uint8)u8BatteryChargeFuel_State;
					}
				}
			}
		 	else
		 	{
		 		if (u8Battery_Received == RTE_E_OK)
		 		{
		 			if(u8Battery_Value == 0x1)
		 			{
						u8BatteryChargeFuel_State = TT_enTURN_ON;
		 			}
					else
					{
						u8BatteryChargeFuel_State = TT_enTURN_OFF;
					}
		 		}
				else
		 		{
					u8BatteryChargeFuel_State = TT_enTURN_OFF;
		 		}
		 	}
		 }
	}

	if(TT_BatteryChargeP0_ENABLE)
	{ // P0
		if (1 == u8Battery_Config_Byte30)
		{
		 	if (u8Battery_Received == RTE_E_OK)
		 	{
		 		if(u8Battery_Value == 0x1)
		 		{
					u8BatteryChargeP0_State = TT_enTURN_ON;
		 		}
				else
				{
					u8BatteryChargeP0_State = TT_enTURN_OFF;
				}
		 	}
		 	else
		 	{
				u8BatteryChargeP0_State = TT_enTURN_OFF;
		 	}
		}
	}

	if((u8BatteryChargeP0_State == TT_enTURN_ON) || (u8BatteryChargeFuel_State == TT_enTURN_ON))
	{
		FTT_SET(enFTT_BatteryCharge,TT_enTURN_ON);
		u8BattChrgLmpStsOutPut = 1;
	}
	else
	{
		FTT_SET(enFTT_BatteryCharge,TT_enTURN_OFF);
		u8BattChrgLmpStsOutPut = 0;
	}

	if (u8PowerMode == SYSTEMSTATE_Cluster_ON)
	{
		(void)Rte_Write_Sd_CanOutputViaGateway_IP_BattChrgLmpSts(u8BattChrgLmpStsOutPut);
	}
	else
	{
		(void)Rte_Write_Sd_CanOutputViaGateway_IP_BattChrgLmpSts(0);
	}
}

/*******************************************************************************
*	Function name		: FTT_vLowFuelPress_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_LowFuelPress_ENABLE  1
	#define TT_LowFuelPressCAN_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_LowFuelPress_ENABLE  1
	#define TT_LowFuelPressCAN_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_LowFuelPress_ENABLE  1
	#define TT_LowFuelPressCAN_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_LowFuelPress_ENABLE  1
	#define TT_LowFuelPressCAN_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_LowFuelPress_ENABLE  1
	#define TT_LowFuelPressCAN_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_LowFuelPress_ENABLE  0
	#define TT_LowFuelPressCAN_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_LowFuelPress_ENABLE  0
	#define TT_LowFuelPressCAN_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_LowFuelPress_ENABLE  0
	#define TT_LowFuelPressCAN_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_LowFuelPress_ENABLE  1
	#define TT_LowFuelPressCAN_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_LowFuelPress_ENABLE  1
	#define TT_LowFuelPressCAN_ENABLE  0
#else
	#define TT_LowFuelPress_ENABLE	0
	#define TT_LowFuelPressCAN_ENABLE  0
#endif

void FTT_vLowFuelPress_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8PowerMode = 0;
	uint8 u8EngVdty = 0;
	uint8 u8LowFuelReceived = RTE_E_INVALID;
	uint8 u8GetEngineRunningSts = 0;
	uint8 u8Byte42 = 0;
	s_TachoInfo_t EngineRunningInfo;
	uint8 u8EngSpd_TimeOutFlg = 0;

	uint8 u8Byte92 = 0;
	uint8 u8ECM24_Received = RTE_E_INVALID;
	uint8 u8EngOilLowPresWrn = 0;

	//uint8 u8OilPressLowSts = 0;
	uint8 u8OilPressLowCANSts = 0;
	uint8 u8EngOilPressLowLmpStsOutPut = 0;

	u8PowerMode = FTT_Adapt_GetPowerMode_State();
	(void)FTT_Adapt_GetHW_C3(&u8Oil_HW_C3);
	u8Byte42 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ENGINE_CONTROL_UNIT);
	u8LowFuelReceived = FTT_Adapt_GetMessage_EngSpdVldty(&u8EngVdty);
	FTT_RteAdaptGetAllConfig();
	u8GetConfig_LowFuelDelayTime = FTT_AdaptGetInternalconfig(TTconfigLowFuelDelayTime);
	u8Getonfig_LowFuelCheckTime = FTT_AdaptGetInternalconfig(TTconfigLowFuelCheckTime);

	(void)FTT_Adapt_GetMessage_TachoInfo(&EngineRunningInfo);
	u8GetEngineRunningSts = FTT_Adapt_GetEngRunSts();
	u8EngSpd_TimeOutFlg = EngineRunningInfo.TimeOutFlag;

	u8Byte92 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ENGINE_OIL_PRESSURE_ALARM_AND_DISPLAY);
	u8ECM24_Received = FTT_Adapt_GetMessage_EngOilLowPresWrn(&u8EngOilLowPresWrn);

	TT_SET_CFG(enFTT_LowFuelPress,ON);
	TT_SET_DID(enFTT_LowFuelPress,OFF);

	if ((u8PowerMode == SYSTEMSTATE_Cluster_ON) && (u8PowerMode_Pre != SYSTEMSTATE_Cluster_ON))
	{
		u8PowerChangeFlag = TRUE;
		u16LowFuelCheckTime = 0;
		u8LowFuelPressTime = 0;
		u16LowFuelDelayTime = 0;
		u8OilPressLowSts = 0;
	}
	else if ((u8PowerMode != SYSTEMSTATE_Cluster_ON) && (u8PowerMode_Pre == SYSTEMSTATE_Cluster_ON))
	{
		u8PowerChangeFlag = FALSE;
		u16LowFuelCheckTime = 0;
		u16LowFuelDelayTime = 0;
	}
	else
	{

	}
	u8PowerMode_Pre = u8PowerMode;

	if ((u8PowerChangeFlag == TRUE) && (u8PowerMode == SYSTEMSTATE_Cluster_ON) && (u16LowFuelCheckTime <= u8Getonfig_LowFuelCheckTime))
	{
		u16LowFuelCheckTime ++;
	}
	// check time logic  above

	if ((1 == u8GetEngineRunningSts) && (0 == u8GetEngineRunningStsPre))
	{
		u16LowFuelDelayTime = 0;
	}
	 u8GetEngineRunningStsPre = u8GetEngineRunningSts;

	if (u8LowFuelReceived == RTE_E_OK)
	{
		if ((u8EngVdty == TT_FUN_ACTIVE) && (u8EngVdtyPre == TT_FUN_INACTIVE))
		{
			u16LowFuelDelayTime = 0;
		}
	}
	else
	{
		u16LowFuelDelayTime = 0;
	}
	u8EngVdtyPre = u8EngVdty;

	if ((u8Oil_HW_C3 == TT_EBD_HW_LOW) && (u16LowFuelDelayTime <= u8GetConfig_LowFuelDelayTime))
	{
		u16LowFuelDelayTime ++;
	}
	else if(u8Oil_HW_C3 != TT_EBD_HW_LOW)
	{
		u16LowFuelDelayTime = 0;
	}

	// delay time logic above
	if(TT_LowFuelPress_ENABLE)
	{
		// log ouput
		if (TRUE == SWC_TT_LOGOUT_ENBLE)
		{
			if (u8LogOut_CurSts[1] != u8Oil_HW_C3)
			{
				u8LogOut_CurSts[1] = u8Oil_HW_C3;
			}
		}

		if((u8Byte42 == 1) || (u8Byte42 == 2) || (u8Byte42 == 3) || (u8Byte42 == 4)\
			|| (u8Byte42 == 5) || (u8Byte42 == 6) || (u8Byte42 == 7))
		{
			if ((u16LowFuelCheckTime < u8Getonfig_LowFuelCheckTime) && (1 == u8EngSpd_TimeOutFlg) && \
				((u8EngVdty != TT_FUN_ACTIVE) || ((u8EngVdty == TT_FUN_ACTIVE) && (u8GetEngineRunningSts == 0))))
			{
				if (u8Oil_HW_C3 == TT_EBD_HW_LOW)
				{
					u8OilPressLowSts = 1;
					boLowFuelPressTimeflg = TRUE;
					if((u8LowFuelPressTime < TT_500ms_LowFuelPress_COUNT) && (u8PowerChangeFlag))
					{
						u8LowFuelPressTime ++;
					}
				}
				else
				{
					if(u8LowFuelPressTime >= TT_500ms_LowFuelPress_COUNT)
					{
						u8OilPressLowSts = 0;
						u8LowFuelPressTime = 0;
						boLowFuelPressTimeflg = FALSE;
					}
					else
					{
						if(boLowFuelPressTimeflg)
						{
							u8LowFuelPressTime ++;
						}
						else
						{
							u8OilPressLowSts = 0;
						}
					}
				}

				FTT_SET_Report_DID(enFTT_LowFuelPress,OFF);
			}//stategy 1
			else
			{
				if (u8LowFuelReceived == RTE_E_OK)
				{
					if ((u8EngVdty == TT_FUN_ACTIVE) && (u8GetEngineRunningSts == 1) \
						&& (u16LowFuelDelayTime >= u8GetConfig_LowFuelDelayTime) \
						&& (u8Oil_HW_C3 == TT_EBD_HW_LOW))
					{
						u8OilPressLowSts = 1;
						FTT_SET_Report_DID(enFTT_LowFuelPress,ON);
					}
					else
					{
						u8OilPressLowSts = 0;
						FTT_SET_Report_DID(enFTT_LowFuelPress,OFF);
					}
				}
				else
				{
					u8OilPressLowSts = 0;
					FTT_SET_Report_DID(enFTT_LowFuelPress,OFF);
				}
			}//stategy 2
		}
	}

	if(TT_LowFuelPressCAN_ENABLE)
	{
		if(1 == u8Byte92)
		{
			if (RTE_E_OK == u8ECM24_Received)
			{
				if (1 == u8EngOilLowPresWrn)
				{
					u8OilPressLowCANSts = 1;
				}
				else
				{
					u8OilPressLowCANSts = 0;
				}
			}
			else
			{
				u8OilPressLowCANSts = 0;
			}
		}
	}

	if ((1 == u8OilPressLowSts) || (1 == u8OilPressLowCANSts))
	{
		TT_SET(enFTT_LowFuelPress,TT_enTURN_ON);
		u8EngOilPressLowLmpStsOutPut = 1;
	}
	else
	{
		TT_SET(enFTT_LowFuelPress,TT_enTURN_OFF);
		u8EngOilPressLowLmpStsOutPut = 0;
	}

	//can output here
	if (u8PowerMode == SYSTEMSTATE_Cluster_ON)
	{
		(void)Rte_Write_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts(u8EngOilPressLowLmpStsOutPut);
	}
	else
	{
		(void)Rte_Write_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts(0);
	}

}


/*******************************************************************************
*	Function name		: FTT_vEngine_System_Error_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Engine_SystemError_ENABLE  1
	#define TT_Engine_SystemError_8AT_ENABLE  0
#else
	#define TT_Engine_SystemError_ENABLE  0
	#define TT_Engine_SystemError_8AT_ENABLE  0
#endif

void FTT_vEngine_System_Error_Process(TT_tstMainObject* stMainObject)
{
	 uint8 u8Engine_ECM2_Received = RTE_E_INVALID;
	 uint8 u8Engine_DCT5_Received = RTE_E_INVALID;
	 uint8 u8Engine_MilSts = 0;
	 uint8 u8Engine_TRANS_Lamp = 0;
	 uint8 u8Engine_Byte42 = 0;
	 uint8 u8Engine_Byte3 = 0;
	 boolean bEngine_Byte42_Sts = FALSE;
	 boolean bEngine_Byte3_Sts = FALSE;
	 TT_SET_CFG(enFTT_EngineSysFault,ON);

	 u8Engine_Byte42 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ENGINE_CONTROL_UNIT);
	 u8Engine_Byte3 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TRANSMISSION);
	 u8Engine_ECM2_Received = FTT_Adapt_GetMessage_MILSts(&u8Engine_MilSts);
	 u8Engine_DCT5_Received = FTT_Adapt_GetMessage_TRANS_Warning_LAMP(&u8Engine_TRANS_Lamp);

	 if ((u8Engine_Byte42 == 1) || (u8Engine_Byte42 == 2) || (u8Engine_Byte42 == 3) \
	 	|| (u8Engine_Byte42 == 4) || (u8Engine_Byte42 == 5) || (u8Engine_Byte42 == 6) || (u8Engine_Byte42 == 7))
	 {
	 	bEngine_Byte42_Sts = TRUE;
	 }
	 else
	 {
	 	bEngine_Byte42_Sts = FALSE;
	 }

	 if ((u8Engine_Byte3 == 0) || (u8Engine_Byte3 == 1) || (u8Engine_Byte3 == 12) || (u8Engine_Byte3 == 2) \
	 	|| (u8Engine_Byte3 == 13) || (u8Engine_Byte3 == 3) || (u8Engine_Byte3 == 14) || (u8Engine_Byte3 == 4) \
	 	|| (u8Engine_Byte3 == 5) || (u8Engine_Byte3 == 6) || (u8Engine_Byte3 == 10) || (u8Engine_Byte3 == 7) \
	 	|| (u8Engine_Byte3 == 11) || (u8Engine_Byte3 == 15) || (u8Engine_Byte3 == 16) || (u8Engine_Byte3 == 20) \
	 	|| (u8Engine_Byte3 == 9) || (u8Engine_Byte3 == 17) || (u8Engine_Byte3 == 18) || (u8Engine_Byte3 == 19) \
	 	|| (u8Engine_Byte3 == 37) || (u8Engine_Byte3 == 38) || (u8Engine_Byte3 == 39) || (u8Engine_Byte3 == 40) \
	 	|| (u8Engine_Byte3 == 41))
	 {
	 	bEngine_Byte3_Sts = TRUE;
	 }
	 else
	 {
	 	bEngine_Byte3_Sts = FALSE;
	 }
	 //not 8AT
	 if(TT_Engine_SystemError_ENABLE)
	 {
		 if ((bEngine_Byte42_Sts) && (bEngine_Byte3_Sts))
		 {
			TT_SET_DID(enFTT_EngineSysFault,ON);
		 	if (u8Engine_ECM2_Received == RTE_E_OK)
		 	{
		 		if(u8Engine_MilSts == 0x1)
		 		{
		 			TT_SET(enFTT_EngineSysFault,TT_enTURN_ON);
					FTT_SET_Report_DID(enFTT_EngineSysFault,ON);
		 		}
				else
				{
					TT_SET(enFTT_EngineSysFault,TT_enTURN_OFF);
					FTT_SET_Report_DID(enFTT_EngineSysFault,OFF);
				}
		 	}
		 	else
		 	{
				TT_SET(enFTT_EngineSysFault,TT_enTURN_ON);
				FTT_SET_Report_DID(enFTT_EngineSysFault,ON);
		 	}
		 }
	}

	if(TT_Engine_SystemError_8AT_ENABLE)//8AT
	{
		if ((bEngine_Byte42_Sts) && (u8Engine_Byte3 == 0x8))
		{
			TT_SET_DID(enFTT_EngineSysFault,ON);
			if ((u8Engine_ECM2_Received == RTE_E_OK) && (u8Engine_DCT5_Received == RTE_E_OK))
			{
				if((TT_FUN_ACTIVE == u8Engine_MilSts) || (TT_FUN_ACTIVE == u8Engine_TRANS_Lamp))
				{
					TT_SET(enFTT_EngineSysFault,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_EngineSysFault,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_EngineSysFault,TT_enTURN_ON);
			}
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vEngine_Fix_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Engine_Fix_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Engine_Fix_ENABLE  1
#else
	#define TT_Engine_Fix_ENABLE  0
#endif

void FTT_vEngine_Fix_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Engine_ECM2_Received = RTE_E_INVALID;
	uint8 u8Engine_SVSSig = 0;
	uint8 u8Engine_Config_Byte42 = 0;
	TT_SET_CFG(enFTT_EngineFix,ON);
	u8Engine_ECM2_Received = FTT_Adapt_GetMessage_EngSVSSig(&u8Engine_SVSSig);
	u8Engine_Config_Byte42 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ENGINE_CONTROL_UNIT);
	if(TT_Engine_Fix_ENABLE)
	{
		if ((u8Engine_Config_Byte42 == 1) || (u8Engine_Config_Byte42 == 2) || (u8Engine_Config_Byte42 == 3) \
		 	|| (u8Engine_Config_Byte42 == 4) || (u8Engine_Config_Byte42 == 5) || (u8Engine_Config_Byte42 == 6) || (u8Engine_Config_Byte42 == 7))
		{
			TT_SET_DID(enFTT_EngineFix,ON);
		 	if ((u8Engine_ECM2_Received == RTE_E_OK) && (u8Engine_SVSSig == 0x1))
		 	{
		 		TT_SET(enFTT_EngineFix,TT_enTURN_ON);
		 	}
		 	else
		 	{
		 		TT_SET(enFTT_EngineFix,TT_enTURN_OFF);
		 	}
		}
		else
		{
			TT_SET_DID(enFTT_EngineFix,OFF);
			TT_SET(enFTT_EngineFix,TT_enTURN_OFF);
		}
	}

}

/*******************************************************************************
*	Function name		: FTT_vEngine_High_Temp_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Engine_High_Temp_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Engine_High_Temp_ENABLE  1
#else
	#define TT_Engine_High_Temp_ENABLE  0
#endif

void FTT_vEngine_High_Temp_Process(TT_tstMainObject* stMainObject)
{
	 uint8 u8Engine_Received = RTE_E_INVALID;
	 uint8 u8Engine_TempWarn = 0;
	 uint8 u8Engine_Byte42 = 0;
	 TT_SET_CFG(enFTT_EngineHighTemp,ON);

	 u8Engine_Received = FTT_Adapt_GetMessage_EngClntTempWarn(&u8Engine_TempWarn);
	 u8Engine_Byte42 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ENGINE_CONTROL_UNIT);
	 if(TT_Engine_High_Temp_ENABLE)
	 {
		if ((u8Engine_Byte42 == 1) || (u8Engine_Byte42 == 2) || (u8Engine_Byte42 == 3) \
		 	|| (u8Engine_Byte42 == 4) || (u8Engine_Byte42 == 5) || (u8Engine_Byte42 == 6) || (u8Engine_Byte42 == 7))
		{
			TT_SET_DID(enFTT_EngineHighTemp,ON);
			if ((u8Engine_Received == RTE_E_OK) && (u8Engine_TempWarn == 0x1))
		 	{
		 		TT_SET(enFTT_EngineHighTemp,TT_enTURN_ON);
		 	}
		 	else
		 	{
		 		TT_SET(enFTT_EngineHighTemp,TT_enTURN_OFF);
		 	}
		 }
		 else
		 {
			TT_SET_DID(enFTT_EngineHighTemp,OFF);
		 	TT_SET(enFTT_EngineHighTemp,TT_enTURN_OFF);
		 }
	 }

}

/*******************************************************************************
*	Function name		: FTT_vCruise_Control_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Cruise_Control_ENABLE  1
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  1
	#define TT_Cruise_Control_EV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Cruise_Control_ENABLE  1
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  1
	#define TT_Cruise_Control_PHEVP2_ENABLE  0
	#define TT_Cruise_Control_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Cruise_Control_ENABLE  1
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  1
	#define TT_Cruise_Control_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Cruise_Control_ENABLE  1
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  0
	#define TT_Cruise_Control_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Cruise_Control_ENABLE  1
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  1
	#define TT_Cruise_Control_PHEVP2_ENABLE  0
	#define TT_Cruise_Control_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Cruise_Control_ENABLE  0
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  1
	#define TT_Cruise_Control_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Cruise_Control_ENABLE  0
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  1
	#define TT_Cruise_Control_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Cruise_Control_ENABLE  0
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  1
	#define TT_Cruise_Control_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Cruise_Control_ENABLE  0
	#define TT_Cruise_Control_P0_ENABLE  1
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  1
	#define TT_Cruise_Control_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Cruise_Control_ENABLE  1
	#define TT_Cruise_Control_P0_ENABLE  0
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  1
	#define TT_Cruise_Control_EV_ENABLE  0
#else
	#define TT_Cruise_Control_ENABLE  0
	#define TT_Cruise_Control_P0_ENABLE  0
	#define TT_Cruise_Control_HEV_PHEV_ENABLE  0
	#define TT_Cruise_Control_PHEVP2_ENABLE  0
	#define TT_Cruise_Control_EV_ENABLE  0
#endif

void FTT_vCruise_Control_Process(TT_tstMainObject* stMainObject)
{
	 uint8 u8CC_Received = RTE_E_INVALID;
	 uint8 u8CC_PHEV_Received = RTE_E_INVALID;
	 uint8 u8CC_EV_Received = RTE_E_INVALID;
	 uint8 u8CC_CruiseCtrlSts = 0;
	 uint8 u8CC_CruiseCtrl_PHEV_Sts = 0;
	 uint8 u8CC_CruiseCtrl_EV_Sts = 0;
	 uint8 u8CC_Config_Byte28 = 0;
	 uint8 u8CC_Config_Byte2 = 0;
	 uint8 u8CC_Config_Byte30 = 0;
	 TT_SET_CFG(enFTT_CruiseControl,ON);
	 TT_SET_DID(enFTT_CruiseControl,OFF);

	 u8CC_Received = FTT_Adapt_GetMessage_CruiseCtrlSts(&u8CC_CruiseCtrlSts);
	 u8CC_PHEV_Received = FTT_Adapt_GetMessage_CruiseCtrlSts_PHEV(&u8CC_CruiseCtrl_PHEV_Sts);

	 u8CC_Config_Byte28 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CRUISE_CONTROL);
	 u8CC_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	 u8CC_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);

	 if(TT_Cruise_Control_ENABLE)
	 { //traditional fuel car
		 if ((1 == u8CC_Config_Byte28) && ((0 == u8CC_Config_Byte2) || (1 == u8CC_Config_Byte2)\
		 	|| (2 == u8CC_Config_Byte2) || (7 == u8CC_Config_Byte2)))
		 {
		 	if ((u8CC_Received == RTE_E_OK) && \
				((u8CC_CruiseCtrlSts == TT_FUN_ACTIVE) || (u8CC_CruiseCtrlSts == TT_FUN_STANDBY)))
		 	{
		 		TT_SET(enFTT_CruiseControl,TT_enTURN_ON);

		 	}
		 	else
		 	{
		 		TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
		 	}
		 }
	 }

	 if(TT_Cruise_Control_P0_ENABLE)
	 { //P0
		 if ((1 == u8CC_Config_Byte28) && (1 == u8CC_Config_Byte30))
		 {
		 	if ((u8CC_Received == RTE_E_OK) && \
				((u8CC_CruiseCtrlSts == TT_FUN_ACTIVE) || (u8CC_CruiseCtrlSts == TT_FUN_STANDBY)))
		 	{
		 		TT_SET(enFTT_CruiseControl,TT_enTURN_ON);
		 	}
		 	else
		 	{
		 		TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
		 	}
		 }
	 }

	 //P2/P2+P4
	 if(TT_Cruise_Control_PHEVP2_ENABLE)
	 {
	 	if ((1 == u8CC_Config_Byte28) && ((2 == u8CC_Config_Byte30) || (4 == u8CC_Config_Byte30) \
			|| (8 == u8CC_Config_Byte30)) && ((4 == u8CC_Config_Byte2) || (3 == u8CC_Config_Byte2)))
		{
		 	if(u8CC_PHEV_Received == RTE_E_OK)
		 	{
		 		if ((1 <= u8CC_CruiseCtrl_PHEV_Sts) && (u8CC_CruiseCtrl_PHEV_Sts <= 8))
		 		{
		 			TT_SET(enFTT_CruiseControl,TT_enTURN_ON);
		 		}
		 		else
		 		{
		 			TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
		 		}
		 	}
		 	else
		 	{
		 		TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
		 	}
		 }
	 }

	 //PHEV-RE300
	 if(TT_Cruise_Control_HEV_PHEV_ENABLE)
	 {
		 if ((1 == u8CC_Config_Byte28) && (4 == u8CC_Config_Byte2) && \
		  ((5 == u8CC_Config_Byte30) || (6 == u8CC_Config_Byte30) || (8 == u8CC_Config_Byte30)))
		 {
		 	if(u8CC_PHEV_Received == RTE_E_OK)
		 	{
		 		if ((1 <= u8CC_CruiseCtrl_PHEV_Sts) && (u8CC_CruiseCtrl_PHEV_Sts <= 8))
		 		{
		 			TT_SET(enFTT_CruiseControl,TT_enTURN_ON);
		 		}
		 		else
		 		{
		 			TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
		 		}
		 	}
		 	else
		 	{
		 		TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
		 	}
		 }
		 //HEV-RE300
		 else if ((1 == u8CC_Config_Byte28) && (3 == u8CC_Config_Byte2) && \
		  ((5 == u8CC_Config_Byte30) || (6 == u8CC_Config_Byte30)))
		 {
		 	if(u8CC_PHEV_Received == RTE_E_OK)
		 	{
		 		if ((1 <= u8CC_CruiseCtrl_PHEV_Sts) && (u8CC_CruiseCtrl_PHEV_Sts <= 8))
		 		{
		 			TT_SET(enFTT_CruiseControl,TT_enTURN_ON);
		 		}
		 		else
		 		{
		 			TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
		 		}
		 	}
		 	else
		 	{
		 		TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
		 	}
		 }
	 }

	 //EV
	 if(TT_Cruise_Control_EV_ENABLE)
	 {
		 if (((1 == u8CC_Config_Byte28) || (12 == u8CC_Config_Byte28)) && (5 == u8CC_Config_Byte2))
		 {
			if((u8CC_EV_Received == RTE_E_OK) && \
				((u8CC_CruiseCtrl_EV_Sts == TT_FUN_ACTIVE) || (u8CC_CruiseCtrl_EV_Sts == TT_FUN_STANDBY)))
			{
				TT_SET(enFTT_CruiseControl,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_CruiseControl,TT_enTURN_OFF);
			}
		 }
	 }

}

/*******************************************************************************
*	Function name		: FTT_vSS_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_SS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_SS_ENABLE  1

#else
	#define TT_SS_ENABLE  0
#endif

void FTT_vSS_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8SS_Received = RTE_E_INVALID;
	uint8 u8SS_Enable_Lamp = 0;
	uint8 u8SS_Fault_Lamp = 0;
	uint8 u8SS_Config_SS = 0;

	TT_SET_CFG(enFTT_SS_Enable,ON);
	TT_SET_CFG(enFTT_SS_Fault,ON);
	TT_SET_DID(enFTT_SS_Enable,OFF);
	TT_SET_DID(enFTT_SS_Fault,OFF);

	u8SS_Received = FTT_Adapt_GetMessage_SS_Enable_Lamp(&u8SS_Enable_Lamp);
	(void)FTT_Adapt_GetMessage_SS_Fault_Lamp(&u8SS_Fault_Lamp);

	u8SS_Config_SS = FTT_Adapt_GetVconfig(VCONFIG_KIND_IDLE_STOP_AND_GO);

	if(TT_SS_ENABLE)
	{
		if (1 == u8SS_Config_SS)
		{
			if(u8SS_Received == RTE_E_OK)
			{
				if ((u8SS_Enable_Lamp == TT_FUN_ACTIVE) && (u8SS_Fault_Lamp == TT_FUN_INACTIVE))
				{
					TT_SET(enFTT_SS_Enable,TT_enTURN_ON);
					TT_SET(enFTT_SS_Fault,TT_enTURN_OFF);

				}
				else if (u8SS_Fault_Lamp == TT_FUN_ACTIVE)
				{
					TT_SET(enFTT_SS_Fault,TT_enTURN_ON);
					TT_SET(enFTT_SS_Enable,TT_enTURN_OFF);
				}
				else
				{
					TT_SET(enFTT_SS_Enable,TT_enTURN_OFF);
					TT_SET(enFTT_SS_Fault,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_SS_Enable,TT_enTURN_OFF);
				TT_SET(enFTT_SS_Fault,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_SS_Enable,TT_enTURN_OFF);
			TT_SET(enFTT_SS_Fault,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vTPMS_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_TPMS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_TPMS_ENABLE  1

#else
	#define TT_TPMS_ENABLE  0
#endif

void FTT_vTPMS_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8TPMS_Received = RTE_E_INVALID;
	uint8 u8TPMS_SysFailIndcn = 0;
	uint8 u8TPMS_FLTirePressIndSts = 0;
	uint8 u8TPMS_FRTirePressIndSts = 0;
	uint8 u8TPMS_RLTirePressIndSts = 0;
	uint8 u8TPMS_RRTirePressIndSts = 0;
	uint8 u8TPMS_FLTireTempSts = 0;
	uint8 u8TPMS_FRTireTempSts = 0;
	uint8 u8TPMS_RLTireTempSts = 0;
	uint8 u8TPMS_RRTireTempSts = 0;
	uint8 u8TPMS_Config_Byte39 = 0;
	uint8 u8IgnSts = 0;
	uint8 u8Selfchecksts = 1;

	FTT_RteAdaptGetAllConfig();
	u16Getonfig_Tpms_flashtime = FTT_AdaptGetInternalconfig(TTconfigTpms_flashtime);
	u8IgnSts =FTT_Adapt_GetPowerMode_State();
	u8TPMS_Received = FTT_Adapt_GetMessage_TirePressSysFailrIndcn(&u8TPMS_SysFailIndcn);
	(void)FTT_Adapt_GetMessage_FLTirePressIndSts(&u8TPMS_FLTirePressIndSts);
	(void)FTT_Adapt_GetMessage_FRTirePressIndSts(&u8TPMS_FRTirePressIndSts);
	(void)FTT_Adapt_GetMessage_RLTirePressIndSts(&u8TPMS_RLTirePressIndSts);
	(void)FTT_Adapt_GetMessage_RRTirePressIndSts(&u8TPMS_RRTirePressIndSts);

	(void)FTT_Adapt_GetMessage_FLTireTempSts(&u8TPMS_FLTireTempSts);
	(void)FTT_Adapt_GetMessage_FRTireTempSts(&u8TPMS_FRTireTempSts);
	(void)FTT_Adapt_GetMessage_RLTireTempSts(&u8TPMS_RLTireTempSts);
	(void)FTT_Adapt_GetMessage_RRTireTempSts(&u8TPMS_RRTireTempSts);
	u8TPMS_Config_Byte39 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TPMS);

	if (0 == FTT_Adapt_GetSelfChecksts(&u8Selfchecksts))
	{
		u8TpmsSelfchecksts = u8Selfchecksts;
		if(u8TpmsSelfchecksts == 1)
		{
			u16TimeCountTpms = 0;
		}
	}

	TT_SET_CFG(enFTT_TPMS,ON);
	if(TT_TPMS_ENABLE)
	{
		if (1 == u8TPMS_Config_Byte39)
		{
			TT_SET_DID(enFTT_TPMS,ON);
			if(u8IgnSts == SYSTEMSTATE_Cluster_ON)
			{
				if (u8TPMS_Received == RTE_E_OK)
				{
					if (u8TPMS_SysFailIndcn == TT_FUN_ACTIVE)
					{
						if (u8TpmsSelfchecksts == 1)
						{
							TT_SET(enFTT_TPMS,TT_enFLASH_1_HZ);
						}
						else
						{
							if (u16TimeCountTpms <= u16Getonfig_Tpms_flashtime)
							{
								u16TimeCountTpms++;
								TT_SET(enFTT_TPMS,TT_enFLASH_1_HZ);
							}
							else
							{
								TT_SET(enFTT_TPMS,TT_enTURN_ON);
							}
						}
					}
					else
					{
						if ((u8TPMS_FLTirePressIndSts == TT_FUN_ACTIVE) \
						|| (u8TPMS_FRTirePressIndSts == TT_FUN_ACTIVE) \
						|| (u8TPMS_RLTirePressIndSts == TT_FUN_ACTIVE) \
						|| (u8TPMS_RRTirePressIndSts == TT_FUN_ACTIVE) \
						|| (u8TPMS_FLTireTempSts == TT_FUN_ACTIVE) \
						|| (u8TPMS_FRTireTempSts == TT_FUN_ACTIVE) \
						|| (u8TPMS_RLTireTempSts == TT_FUN_ACTIVE) \
						|| (u8TPMS_RRTireTempSts == TT_FUN_ACTIVE))
						{
							TT_SET(enFTT_TPMS,TT_enTURN_ON);
							u16TimeCountTpms = 0;
						}
						else
						{
							TT_SET(enFTT_TPMS,TT_enTURN_OFF);
							u16TimeCountTpms = 0;
						}
					}
				}
				else
				{
					TT_SET(enFTT_TPMS,TT_enTURN_ON);
					u16TimeCountTpms = 0;
				}
			}
			else
			{
				TT_SET(enFTT_TPMS,TT_enTURN_OFF);
				u16TimeCountTpms = 0;
			}
		}
		else
		{
			TT_SET_DID(enFTT_TPMS,OFF);
			TT_SET(enFTT_TPMS,TT_enTURN_OFF);
			u16TimeCountTpms = 0;
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vLDW_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_LDW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_LDW_ENABLE  1

#else
	#define TT_LDW_ENABLE  0
#endif

void FTT_vLDW_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8LDW_Received = RTE_E_INVALID;
	uint8 u8LDW_LSSFuncSts = 0;
	uint8 u8LDW_LSSErrSts = 0;
	uint8 u8LDW_IFCCalibrationSts = 0;
	uint8 u8LDW_CameraBlockSts = 0;
	uint8 u8LDW_Config_Byte12 = 0;
	boolean u8LDW_Config_Byte12_Sts = FALSE;

	TT_SET_CFG(enFTT_LDW_Enable,ON);
	TT_SET_CFG(enFTT_LDW_Error,ON);
	TT_SET_DID(enFTT_LDW_Enable,OFF);
	TT_SET_DID(enFTT_LDW_Error,OFF);

	u8LDW_Received = FTT_Adapt_GetMessage_LSSFuncSts(&u8LDW_LSSFuncSts);
	(void)FTT_Adapt_GetMessage_LSSErrSts(&u8LDW_LSSErrSts);
	(void)FTT_Adapt_GetMessage_IFCCalibrationSts(&u8LDW_IFCCalibrationSts);
	(void)FTT_Adapt_GetMessage_CameraBlockageSts(&u8LDW_CameraBlockSts);

	u8LDW_Config_Byte12 = FTT_Adapt_GetVconfig(VCONFIG_KIND_LDW_LKA);
	if ((u8LDW_Config_Byte12 >= 1) && (u8LDW_Config_Byte12 <= 13))
	{
		u8LDW_Config_Byte12_Sts = TRUE;
	}
	else
	{
		u8LDW_Config_Byte12_Sts = FALSE;
	}

	if(TT_LDW_ENABLE)
	{
		if (u8LDW_Config_Byte12_Sts)
		{
			if ((u8LDW_Received == RTE_E_OK) && (u8LDW_LSSFuncSts == TT_LDW_STS))
			{
				if ((u8LDW_LSSErrSts == TT_FUN_INACTIVE) \
					&& (u8LDW_IFCCalibrationSts == TT_FUN_INACTIVE) && (u8LDW_CameraBlockSts == TT_FUN_INACTIVE))
				{
					TT_SET(enFTT_LDW_Enable,TT_enTURN_ON);
					TT_SET(enFTT_LDW_Error,TT_enTURN_OFF);
				}
				else if (u8LDW_LSSErrSts == TT_LDW_STS)
				{
					TT_SET(enFTT_LDW_Error,TT_enTURN_ON);
					TT_SET(enFTT_LDW_Enable,TT_enTURN_OFF);
				}
				else if ((u8LDW_LSSErrSts != TT_LDW_STS) \
						&& ((u8LDW_IFCCalibrationSts == TT_FUN_ACTIVE) || (u8LDW_IFCCalibrationSts == TT_FUN_STANDBY)))
				{
					TT_SET(enFTT_LDW_Error,TT_enTURN_ON);
					TT_SET(enFTT_LDW_Enable,TT_enTURN_OFF);
				}
				else if ((u8LDW_LSSErrSts != TT_LDW_STS) && ((u8LDW_IFCCalibrationSts == TT_FUN_INACTIVE) \
					|| (u8LDW_IFCCalibrationSts == TT_FUN_RESERVE)) && (u8LDW_CameraBlockSts == TT_FUN_ACTIVE))
				{
					TT_SET(enFTT_LDW_Error,TT_enTURN_ON);
					TT_SET(enFTT_LDW_Enable,TT_enTURN_OFF);
				}
				else
				{
					TT_SET(enFTT_LDW_Error,TT_enTURN_OFF);
					TT_SET(enFTT_LDW_Enable,TT_enTURN_OFF);
				}


			}
			else
			{
				TT_SET(enFTT_LDW_Error,TT_enTURN_OFF);
				TT_SET(enFTT_LDW_Enable,TT_enTURN_OFF);
			}

		}
		else
		{
			TT_SET(enFTT_LDW_Error,TT_enTURN_OFF);
			TT_SET(enFTT_LDW_Enable,TT_enTURN_OFF);
		}
	}

}


/*******************************************************************************
*	Function name		: FTT_vLKA_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_LKA_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_LKA_ENABLE  1

#else
	#define TT_LKA_ENABLE  0
#endif

void FTT_vLKA_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8LKA_Received = RTE_E_INVALID;
	uint8 u8LKA_LSSFuncSts = 0;
	uint8 u8LKA_LSSErrSts = 0;
	uint8 u8LKA_IFCCalibrationSts = 0;
	boolean u8LKA_CameraBlockSts = FALSE;
	uint8 u8LKA_Config_Byte12 = 0;
	boolean u8LKA_Config_Byte12_Sts = FALSE;

	TT_SET_CFG(enFTT_LKA_Enable,ON);
	TT_SET_CFG(enFTT_LKA_Error,ON);
	TT_SET_DID(enFTT_LKA_Enable,OFF);
	TT_SET_DID(enFTT_LKA_Error,OFF);

	u8LKA_Received = FTT_Adapt_GetMessage_LSSFuncSts(&u8LKA_LSSFuncSts);
	(void)FTT_Adapt_GetMessage_LSSErrSts(&u8LKA_LSSErrSts);
	(void)FTT_Adapt_GetMessage_IFCCalibrationSts(&u8LKA_IFCCalibrationSts);
	(void)FTT_Adapt_GetMessage_CameraBlockageSts(&u8LKA_CameraBlockSts);

	u8LKA_Config_Byte12  = FTT_Adapt_GetVconfig(VCONFIG_KIND_LDW_LKA);

	if ((u8LKA_Config_Byte12 >= 1) && (u8LKA_Config_Byte12 <= 13))
	{
		u8LKA_Config_Byte12_Sts = TRUE;
	}
	else
	{
		u8LKA_Config_Byte12_Sts = FALSE;
	}

	if(TT_LKA_ENABLE)
	{
		if (u8LKA_Config_Byte12_Sts)
		{
			if ((u8LKA_Received == RTE_E_OK) && (u8LKA_LSSFuncSts == TT_LKA_STS))
			{
				if (((u8LKA_LSSErrSts == TT_FUN_INACTIVE) \
					|| (u8LKA_LSSErrSts == TT_FUN_FAILURE)) \
					&& (u8LKA_IFCCalibrationSts == TT_FUN_INACTIVE) \
					&& (u8LKA_CameraBlockSts == TT_FUN_INACTIVE))
				{
					TT_SET(enFTT_LKA_Enable,TT_enTURN_ON);
					TT_SET(enFTT_LKA_Error,TT_enTURN_OFF);
				}
				else if (u8LKA_LSSErrSts == TT_LKA_STS)
				{
					TT_SET(enFTT_LKA_Error,TT_enTURN_ON);
					TT_SET(enFTT_LKA_Enable,TT_enTURN_OFF);
				}
				else if ((u8LKA_LSSErrSts != TT_LKA_STS) \
						&& ((u8LKA_IFCCalibrationSts == TT_FUN_ACTIVE) \
							|| (u8LKA_IFCCalibrationSts == TT_FUN_STANDBY)))
				{
					TT_SET(enFTT_LKA_Error,TT_enTURN_ON);
					TT_SET(enFTT_LKA_Enable,TT_enTURN_OFF);
				}
				else if ((u8LKA_LSSErrSts != TT_LKA_STS) \
						&& ((u8LKA_IFCCalibrationSts == TT_FUN_INACTIVE) \
							|| (u8LKA_IFCCalibrationSts == TT_FUN_RESERVE)) \
						&& (u8LKA_CameraBlockSts == TT_FUN_ACTIVE))
				{
					TT_SET(enFTT_LKA_Error,TT_enTURN_ON);
					TT_SET(enFTT_LKA_Enable,TT_enTURN_OFF);
				}
				else
				{
					TT_SET(enFTT_LKA_Error,TT_enTURN_OFF);
					TT_SET(enFTT_LKA_Enable,TT_enTURN_OFF);
				}


			}
			else
			{
				TT_SET(enFTT_LKA_Error,TT_enTURN_OFF);
				TT_SET(enFTT_LKA_Enable,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_LKA_Error,TT_enTURN_OFF);
			TT_SET(enFTT_LKA_Enable,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vLCK_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_LCK_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_LCK_ENABLE  1

#else
	#define TT_LCK_ENABLE  0
#endif

void FTT_vLCK_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8LCK_Received = RTE_E_INVALID;
	uint8 u8LCK_LSSFuncSts = 0;
	uint8 u8LCK_LSSErrSts = 0;
	uint8 u8LCK_IFCCalibrationSts = 0;
	boolean u8LCK_CameraBlockSts = FALSE;
	uint8 u8LCK_Config_Byte12 = 0;
	boolean u8LCK_Config_Byte12_Sts = FALSE;

	TT_SET_CFG(enFTT_LCK_Enable,ON);
	TT_SET_CFG(enFTT_LCK_Error,ON);
	TT_SET_DID(enFTT_LCK_Enable,OFF);
	TT_SET_DID(enFTT_LCK_Error,OFF);

	u8LCK_Received = FTT_Adapt_GetMessage_LSSFuncSts(&u8LCK_LSSFuncSts);
	(void)FTT_Adapt_GetMessage_LSSErrSts(&u8LCK_LSSErrSts);
	(void)FTT_Adapt_GetMessage_IFCCalibrationSts(&u8LCK_IFCCalibrationSts);
	(void)FTT_Adapt_GetMessage_CameraBlockageSts(&u8LCK_CameraBlockSts);
	u8LCK_Config_Byte12 = FTT_Adapt_GetVconfig(VCONFIG_KIND_LDW_LKA);

	if ((u8LCK_Config_Byte12 >= 1) && (u8LCK_Config_Byte12 <= 13))
	{
		u8LCK_Config_Byte12_Sts = TRUE;
	}
	else
	{
		u8LCK_Config_Byte12_Sts = FALSE;
	}

	if(TT_LCK_ENABLE)
	{
		if (u8LCK_Config_Byte12_Sts)
		{
			if ((u8LCK_Received == RTE_E_OK) && (u8LCK_LSSFuncSts == TT_LCK_STS))
			{
				if (((u8LCK_LSSErrSts == TT_FUN_INACTIVE) \
					|| (u8LCK_LSSErrSts == TT_FUN_FAILURE)) \
					&& (u8LCK_IFCCalibrationSts == TT_FUN_INACTIVE) \
					&& (u8LCK_CameraBlockSts == TT_FUN_INACTIVE))
				{
					TT_SET(enFTT_LCK_Enable,TT_enTURN_ON);
					TT_SET(enFTT_LCK_Error,TT_enTURN_OFF);
				}
				else if (u8LCK_LSSErrSts == TT_LCK_STS)
				{
					TT_SET(enFTT_LCK_Error,TT_enTURN_ON);
					TT_SET(enFTT_LCK_Enable,TT_enTURN_OFF);
				}
				else if ((u8LCK_LSSErrSts != TT_LCK_STS) \
						&& ((u8LCK_IFCCalibrationSts == TT_FUN_ACTIVE) \
							|| (u8LCK_IFCCalibrationSts == TT_FUN_STANDBY)))
				{
					TT_SET(enFTT_LCK_Error,TT_enTURN_ON);
					TT_SET(enFTT_LCK_Enable,TT_enTURN_OFF);
				}
				else if ((u8LCK_LSSErrSts != TT_LCK_STS) \
						&& ((u8LCK_IFCCalibrationSts == TT_FUN_INACTIVE) \
							|| (u8LCK_IFCCalibrationSts == TT_FUN_RESERVE)) \
						&& (u8LCK_CameraBlockSts == TT_FUN_ACTIVE))
				{
					TT_SET(enFTT_LCK_Error,TT_enTURN_ON);
					TT_SET(enFTT_LCK_Enable,TT_enTURN_OFF);
				}
				else
				{
					TT_SET(enFTT_LCK_Error,TT_enTURN_OFF);
					TT_SET(enFTT_LCK_Enable,TT_enTURN_OFF);
				}


			}
			else
			{
				TT_SET(enFTT_LCK_Error,TT_enTURN_OFF);
				TT_SET(enFTT_LCK_Enable,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_LCK_Error,TT_enTURN_OFF);
			TT_SET(enFTT_LCK_Enable,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vAuto_Park_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Auto_Park_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Auto_Park_ENABLE  1

#else
	#define TT_Auto_Park_ENABLE  0
#endif

void FTT_vAuto_Park_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Auto_CAN_Received = RTE_E_INVALID;
	uint8 u8Auto_CAN_AVHErrSts = 0;
	uint8 u8Auto_CAN_AVHSts = 0;
	uint8 u8Auto_Config_Byte33 = 0;

	TT_SET_CFG(enFTT_AutoPark_Enable,ON);
	TT_SET_CFG(enFTT_AutoPark_Fault,ON);
	TT_SET_DID(enFTT_AutoPark_Fault,OFF);
	TT_SET_DID(enFTT_AutoPark_Enable,OFF);

	u8Auto_Config_Byte33 = FTT_Adapt_GetVconfig(VCONFIG_KIND_AVH);
	u8Auto_CAN_Received = FTT_Adapt_GetMessage_AVHSts(&u8Auto_CAN_AVHErrSts,&u8Auto_CAN_AVHSts);

	if(TT_Auto_Park_ENABLE)
	{
		if (1 == u8Auto_Config_Byte33)
		{
			if (u8Auto_CAN_Received == RTE_E_OK)
			{
				if ((u8Auto_CAN_AVHErrSts == TT_FUN_INACTIVE) \
					|| (u8Auto_CAN_AVHErrSts == TT_FUN_RESERVE))
				{
					if (u8Auto_CAN_AVHSts == TT_FUN_ACTIVE)
					{
						TT_SET(enFTT_AutoPark_Fault,TT_enTURN_ON);
						TT_SET(enFTT_AutoPark_Enable,TT_enTURN_OFF);
					}
					else if (u8Auto_CAN_AVHSts == TT_FUN_STANDBY)
					{
						TT_SET(enFTT_AutoPark_Enable,TT_enTURN_ON);
						TT_SET(enFTT_AutoPark_Fault,TT_enTURN_OFF);
					}
					else
					{
						TT_SET(enFTT_AutoPark_Enable,TT_enTURN_OFF);
						TT_SET(enFTT_AutoPark_Fault,TT_enTURN_OFF);
					}

				}
				else
				{
					TT_SET(enFTT_AutoPark_Enable,TT_enTURN_OFF);
					TT_SET(enFTT_AutoPark_Fault,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_AutoPark_Enable,TT_enTURN_OFF);
				TT_SET(enFTT_AutoPark_Fault,TT_enTURN_OFF);
			}
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vHSD_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		: Function Safety
						Epark indicator  (TBD)
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_HSD_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_HSD_ENABLE  1
#else
	#define TT_HSD_ENABLE  0
#endif

void FTT_vHSD_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8HSD_CAN_Received = RTE_E_INVALID;
	uint8 u8HSD_CAN_HDCFault = 0;
	uint8 u8HSD_CAN_HDCCtrl = 0;
	uint8 u8HSD_Config_Byte31 = 0;
	TT_SET_CFG(enFTT_HSD,ON);
	TT_SET_DID(enFTT_HSD,OFF);

	u8HSD_CAN_Received = FTT_Adapt_GetMessage_HDCSts(&u8HSD_CAN_HDCFault,&u8HSD_CAN_HDCCtrl);
	u8HSD_Config_Byte31 = FTT_Adapt_GetVconfig(VCONFIG_KIND_UP_DOWN_HILL);

	if(TT_HSD_ENABLE)
	{
		if ((2 == u8HSD_Config_Byte31) || (3 == u8HSD_Config_Byte31))
		{
			if (u8HSD_CAN_Received == RTE_E_OK)
			{
				if ((u8HSD_CAN_HDCFault == TT_FUN_INACTIVE) || (u8HSD_CAN_HDCFault == TT_FUN_RESERVE))
				{
					if (u8HSD_CAN_HDCCtrl == TT_FUN_ACTIVE)
					{
						TT_SET(enFTT_HSD,TT_enFLASH_1_HZ);
					}
					else if (u8HSD_CAN_HDCCtrl == TT_FUN_STANDBY)
					{
						TT_SET(enFTT_HSD,TT_enTURN_ON);
					}
					else
					{
						TT_SET(enFTT_HSD,TT_enTURN_OFF);
					}
				}
				else
				{
					TT_SET(enFTT_HSD,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_HSD,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_HSD,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vEPB_Enable_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_EPB_Enable_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_EPB_Enable_ENABLE  1

#else
	#define TT_EPB_Enable_ENABLE  0
#endif

void FTT_vEPB_Enable_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8EPB1_CAN_Received = RTE_E_INVALID;
	uint8 u8EPB2_CAN_Received = RTE_E_INVALID;
	uint8 u8EPB_CAN_RedLmpSts = 0;
	uint8 u8EPB_CAN_CDPActv = 0;
	uint8 u8EPB_Config_Byte26 = 0;
	TT_DOMAIN_INFO Domain_Info = TT_DOMAIN_CH;
	TT_CFG_enStatusType u8EpbEnableSts = TT_enTURN_OFF;
	uint8 u8IgnSts = 0;//get ign status
	uint16 u16EPBlightorflashtimeOffset = 0;

	TT_SET_CFG(enFTT_EPB_Enable_CH,ON);
	TT_SET_CFG(enFTT_EPB_Enable_US,ON);

	FTT_RteAdaptGetAllConfig();
	u16Getonfig_EPBlightorflashtime = FTT_AdaptGetInternalconfig(TTconfigEPBlightorflashtime);
	u16EPBlightorflashtimeOffset = u16Getonfig_EPBlightorflashtime - 10u;
	u8IgnSts = FTT_Adapt_GetPowerMode_State();

	u8EPB1_CAN_Received = FTT_Adapt_GetMessage_EPBRedLmpSts(&u8EPB_CAN_RedLmpSts);
	u8EPB2_CAN_Received = FTT_Adapt_GetMessage_CDPActv(&u8EPB_CAN_CDPActv);

	u8EPB_Config_Byte26 = FTT_Adapt_GetVconfig(VCONFIG_KIND_PARKING_BRAKE);
	Domain_Info = FTT_vDomain_Logic_Process();

	if(TT_EPB_Enable_ENABLE)
	{
		if ((2 == u8EPB_Config_Byte26) && (Domain_Info != TT_NO_DOMAIN))
		{
			TT_SET_DID(enFTT_EPB_Enable_CH,ON);
			TT_SET_DID(enFTT_EPB_Enable_US,ON);
			if (u8IgnSts == SYSTEMSTATE_Cluster_ON)		//IGN ON
			{
				if ((u8EPB1_CAN_Received == RTE_E_OK) && (u8EPB2_CAN_Received == RTE_E_OK))
				{
					if (u8EPB_CAN_RedLmpSts == TT_FUN_ACTIVE)
					{
						u8EpbEnableSts = TT_enTURN_ON;
					}
					else if (u8EPB_CAN_RedLmpSts == TT_FUN_STANDBY)
					{
						u8EpbEnableSts = TT_enFLASH_1_HZ;
					}
					else
					{
						u8EpbEnableSts = TT_enTURN_OFF;
					}

				}
				else if ((u8EPB2_CAN_Received != RTE_E_OK) && (u8EPB1_CAN_Received == RTE_E_OK))
				{
					if (u8EPB_CAN_RedLmpSts == TT_FUN_ACTIVE)
					{
						u8EpbEnableSts = TT_enTURN_ON;
					}
					else if (u8EPB_CAN_RedLmpSts == TT_FUN_STANDBY)
					{
						u8EpbEnableSts = TT_enFLASH_1_HZ;
					}
					else
					{
						u8EpbEnableSts = TT_enTURN_OFF;
					}

				}
				else
				{
					u8EpbEnableSts = TT_enTURN_OFF;
				}
				u8TimeCountEPBOn = 0;
				u8TimeCountEPBFlash = 0;
			}
			else		//IGN OFF
			{
				if (u8EPB1_CAN_Received == RTE_E_OK)
				{
					if (u8EPB_CAN_RedLmpSts == TT_FUN_ACTIVE)
					{
						if (u8TimeCountEPBOn <= u16Getonfig_EPBlightorflashtime)
						{
							u8TimeCountEPBOn++;
							u8EpbEnableSts = TT_enTURN_ON;
						}
						else
						{
							u8EpbEnableSts = TT_enTURN_OFF;
						}
						u8TimeCountEPBFlash = 0;
					}
					else if (u8EPB_CAN_RedLmpSts == TT_FUN_STANDBY)
					{
						if (u8TimeCountEPBFlash <= u16EPBlightorflashtimeOffset)
						{
							u8TimeCountEPBFlash++;
							u8EpbEnableSts = TT_enFLASH_1_HZ;
						}
						else
						{
							u8EpbEnableSts = TT_enTURN_OFF;
						}
						u8TimeCountEPBOn = 0;
					}
					else
					{
						u8EpbEnableSts = TT_enTURN_OFF;
						u8TimeCountEPBOn = 0;
						u8TimeCountEPBFlash = 0;
					}

				}
				else
				{
					u8EpbEnableSts = TT_enTURN_OFF;
					u8TimeCountEPBOn = 0;
					u8TimeCountEPBFlash = 0;
				}
			}
		}
		else
		{
			u8EpbEnableSts = TT_enTURN_OFF;

			TT_SET_DID(enFTT_EPB_Enable_CH,OFF);
			TT_SET_DID(enFTT_EPB_Enable_US,OFF);
		}
	}
	if (Domain_Info == TT_DOMAIN_CH)
	{
		TT_SET(enFTT_EPB_Enable_CH,u8EpbEnableSts);
		TT_SET(enFTT_EPB_Enable_US,TT_enTURN_OFF);

	}
	else if (Domain_Info == TT_DOMAIN_US)
	{
		TT_SET(enFTT_EPB_Enable_US,u8EpbEnableSts);
		TT_SET(enFTT_EPB_Enable_CH,TT_enTURN_OFF);
	}
	else
	{
		TT_SET(enFTT_EPB_Enable_CH,TT_enTURN_OFF);
		TT_SET(enFTT_EPB_Enable_US,TT_enTURN_OFF);
	}

}

/*******************************************************************************
*	Function name		: FTT_vDPB_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_DPB_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_DPB_ENABLE  1

#else
	#define TT_DPB_ENABLE  0
#endif

void FTT_vDPB_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8DPB_CAN_Received = RTE_E_INVALID;
	uint8 u8DPB_CAN_CDPActv = 0;
	uint8 u8DPB_Config_Byte26 = 0;
	TT_DOMAIN_INFO Domain_Info = TT_DOMAIN_CH;
	TT_CFG_enStatusType u8DPBFaultSts = TT_enTURN_OFF;

	TT_SET_CFG(enFTT_DPB_Enable_CH,ON);
	TT_SET_CFG(enFTT_DPB_Enable_US,ON);

	u8DPB_CAN_Received = FTT_Adapt_GetMessage_CDPActv(&u8DPB_CAN_CDPActv);
	u8DPB_Config_Byte26 = FTT_Adapt_GetVconfig(VCONFIG_KIND_PARKING_BRAKE);
	Domain_Info = FTT_vDomain_Logic_Process();

	if(TT_DPB_ENABLE)
	{
		if ((2 == u8DPB_Config_Byte26) && (Domain_Info != TT_NO_DOMAIN))
		{
			TT_SET_DID(enFTT_DPB_Enable_CH,ON);
			TT_SET_DID(enFTT_DPB_Enable_US,ON);
			if (u8DPB_CAN_Received == RTE_E_OK)
			{
				if (u8DPB_CAN_CDPActv == TT_FUN_ACTIVE)
				{
					u8DPBFaultSts = TT_enTURN_ON;
				}
				else
				{
					u8DPBFaultSts = TT_enTURN_OFF;
				}
			}
			else
			{
				u8DPBFaultSts = TT_enTURN_OFF;
			}
		}
		else
		{
			u8DPBFaultSts = TT_enTURN_OFF;
			TT_SET_DID(enFTT_DPB_Enable_CH,OFF);
			TT_SET_DID(enFTT_DPB_Enable_US,OFF);
		}
	}

	if (Domain_Info == TT_DOMAIN_CH)
	{
		TT_SET(enFTT_DPB_Enable_CH,u8DPBFaultSts);
		TT_SET(enFTT_DPB_Enable_US,TT_enTURN_OFF);
	}
	else if (Domain_Info == TT_DOMAIN_US)
	{
		TT_SET(enFTT_DPB_Enable_US,u8DPBFaultSts);
		TT_SET(enFTT_DPB_Enable_CH,TT_enTURN_OFF);
	}
	else
	{
		TT_SET(enFTT_DPB_Enable_CH,TT_enTURN_OFF);
		TT_SET(enFTT_DPB_Enable_US,TT_enTURN_OFF);
	}

}

/*******************************************************************************
*	Function name		: FTT_vIboost_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Iboost_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Iboost_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Iboost_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Iboost_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Iboost_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Iboost_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Iboost_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Iboost_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Iboost_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Iboost_ENABLE  1

#else
	#define TT_Iboost_ENABLE  0
#endif

void FTT_vIboost_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8IBoost_CAN_Received = RTE_E_INVALID;
	uint8 u8IBoost_FD2_Received = RTE_E_INVALID;
	uint8 u8ESP_HMI_WarningOn = 0;
	uint8 u8IBoost_Warn = 0;
	uint8 u8Iboost_Config_Byte37 = 0;
	uint8 u8Breakerror_Byte26 = 0;
	TT_DOMAIN_INFO Domain_Info = TT_DOMAIN_CH;
	TT_CFG_enStatusType u8IboostYellowSts = TT_enTURN_OFF;
	TT_CFG_enStatusType u8IboostRedSts = TT_enTURN_OFF;
	TT_SET_CFG(enFTT_Ibooster_Yellow_CH,ON);
	TT_SET_CFG(enFTT_Ibooster_Red_CH,ON);
	TT_SET_CFG(enFTT_Ibooster_Yellow_US,ON);
	TT_SET_CFG(enFTT_Ibooster_Red_US,ON);

	u8IBoost_CAN_Received = FTT_Adapt_GetMessage_ESP_HMI_WarningOn(&u8ESP_HMI_WarningOn);
	u8IBoost_FD2_Received = FTT_Adapt_GetMessage_IB_Warn(&u8IBoost_Warn);

	u8Iboost_Config_Byte37 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TYPE_OF_BOOSTER_BRAKE_PUMP);
	u8Breakerror_Byte26 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SERVICE_BRAKE);
	Domain_Info = FTT_vDomain_Logic_Process();

	if(TT_Iboost_ENABLE)
	{
		if (1 == u8Iboost_Config_Byte37)
		{
			if ((1 == u8Breakerror_Byte26) || (2 == u8Breakerror_Byte26))
			{
				TT_SET_DID(enFTT_Ibooster_Yellow_CH,OFF);
				TT_SET_DID(enFTT_Ibooster_Red_CH,OFF);
				TT_SET_DID(enFTT_Ibooster_Yellow_US,OFF);
				TT_SET_DID(enFTT_Ibooster_Red_US,OFF);
			}
			else
			{
				TT_SET_DID(enFTT_Ibooster_Yellow_CH,ON);
				TT_SET_DID(enFTT_Ibooster_Red_CH,ON);
				TT_SET_DID(enFTT_Ibooster_Yellow_US,ON);
				TT_SET_DID(enFTT_Ibooster_Red_US,ON);
			}
			if ((u8IBoost_CAN_Received == RTE_E_OK) && (u8IBoost_FD2_Received == RTE_E_OK))
			{
				if ((((u8ESP_HMI_WarningOn == TT_FUN_INACTIVE) || (u8ESP_HMI_WarningOn == TT_FUN_RESERVE)) \
					&& (u8IBoost_Warn == TT_FUN_ACTIVE)) || (u8ESP_HMI_WarningOn == TT_FUN_ACTIVE))
				{
					u8IboostYellowSts = TT_enTURN_ON;
					u8IboostRedSts = TT_enTURN_OFF;
				}
				else if (u8ESP_HMI_WarningOn == TT_FUN_STANDBY)
				{
					u8IboostRedSts = TT_enTURN_ON;
					u8IboostYellowSts = TT_enTURN_OFF;
				}
				else
				{
					u8IboostYellowSts = TT_enTURN_OFF;
					u8IboostRedSts = TT_enTURN_OFF;
				}
			}
			else if ((u8IBoost_CAN_Received != RTE_E_OK) && (u8IBoost_FD2_Received == RTE_E_OK))
			{
				u8IboostYellowSts = TT_enTURN_OFF;
				u8IboostRedSts = TT_enTURN_ON;
			}
			else if ((u8IBoost_CAN_Received == RTE_E_OK) && (u8IBoost_FD2_Received != RTE_E_OK))
			{
				if (u8ESP_HMI_WarningOn == TT_FUN_STANDBY)
				{
					u8IboostYellowSts = TT_enTURN_OFF;
					u8IboostRedSts = TT_enTURN_ON;
				}
				else
				{
					u8IboostYellowSts = TT_enTURN_ON;
					u8IboostRedSts = TT_enTURN_OFF;
				}
			}
			else
			{
				u8IboostYellowSts = TT_enTURN_OFF;
				u8IboostRedSts = TT_enTURN_ON;
			}
		}
		else
		{
			u8IboostYellowSts = TT_enTURN_OFF;
			u8IboostRedSts = TT_enTURN_OFF;

			TT_SET_DID(enFTT_Ibooster_Yellow_CH,OFF);
			TT_SET_DID(enFTT_Ibooster_Red_CH,OFF);
			TT_SET_DID(enFTT_Ibooster_Yellow_US,OFF);
			TT_SET_DID(enFTT_Ibooster_Red_US,OFF);
		}
	}
	//priority logic should added
	//制动系统故障指示灯点亮 ＞ i-booster红色指示灯 ＞ i-booster黄色指示灯

	if (Domain_Info == TT_DOMAIN_CH)
	{
		TT_SET(enFTT_Ibooster_Yellow_CH,u8IboostYellowSts);
		TT_SET(enFTT_Ibooster_Red_CH,u8IboostRedSts);
		TT_SET(enFTT_Ibooster_Yellow_US,TT_enTURN_OFF);
		TT_SET(enFTT_Ibooster_Red_US,TT_enTURN_OFF);
	}
	else if (Domain_Info == TT_DOMAIN_US)
	{
		TT_SET(enFTT_Ibooster_Yellow_CH,TT_enTURN_OFF);
		TT_SET(enFTT_Ibooster_Red_CH,TT_enTURN_OFF);
		TT_SET(enFTT_Ibooster_Yellow_US,u8IboostYellowSts);
		TT_SET(enFTT_Ibooster_Red_US,u8IboostRedSts);
	}
	else
	{
		TT_SET(enFTT_Ibooster_Yellow_CH,TT_enTURN_OFF);
		TT_SET(enFTT_Ibooster_Red_CH,TT_enTURN_OFF);
		TT_SET(enFTT_Ibooster_Yellow_US,TT_enTURN_OFF);
		TT_SET(enFTT_Ibooster_Red_US,TT_enTURN_OFF);
	}
}


/*******************************************************************************
*	Function name		: FTT_vFront_Fog_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  1

#else
	#define TT_Front_FogNopbox_ENABLE  0
	#define TT_Front_FogPbox_ENABLE  0
#endif

void FTT_vFront_Fog_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8FrontFog_P_Received = RTE_E_INVALID;
	uint8 u8FrontFog_Received = RTE_E_INVALID;
	uint8 u8FrontFog_LmpSts = 0;
	uint8 u8FrontFog_Lmp_Pbox = 0;
	uint8 u8FrontFog_Config_Byte38 = 0;
	uint8 u8FrontFog_Config_Byte80 = 0;

	TT_SET_CFG(enFTT_Front_Fog,ON);
	TT_SET_DID(enFTT_Front_Fog,OFF);

	u8FrontFog_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8FrontFog_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);
	u8FrontFog_P_Received = FTT_Adapt_GetMessage_FFogLmpSts(&u8FrontFog_Lmp_Pbox);

	if(TT_Front_FogNopbox_ENABLE)
	{	//no pbox
		if ((0 == u8FrontFog_Config_Byte38) && (0 == u8FrontFog_Config_Byte80))
		{
			if ((u8FrontFog_Received == RTE_E_OK) && (1 == u8FrontFog_LmpSts))
			{
				TT_SET(enFTT_Front_Fog,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Front_Fog,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Front_FogPbox_ENABLE)
	{//pbox
		if((1 == u8FrontFog_Config_Byte38) || (1 == u8FrontFog_Config_Byte80))
		{
			if ((u8FrontFog_P_Received == RTE_E_OK) && (1 == u8FrontFog_Lmp_Pbox))
			{
				TT_SET(enFTT_Front_Fog,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Front_Fog,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Front_Fog,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vRear_Fog_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  1

#else
	#define TT_Rear_FogNopbox_ENABLE  0
	#define TT_Rear_FogPbox_ENABLE  0
#endif

void FTT_vRear_Fog_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8RearFog_P_Received = RTE_E_INVALID;
	uint8 u8RearFog_Received = RTE_E_INVALID;
	uint8 u8RearFog_LmpSts = 0;
	uint8 u8RearFog_Lmp_Pbox = 0;
	uint8 u8RearFog_Config_Byte38 = 0;
	uint8 u8RearFog_Config_Byte80 = 0;
	TT_SET_CFG(enFTT_Rear_Fog,ON);
	TT_SET_DID(enFTT_Rear_Fog,OFF);

	u8RearFog_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8RearFog_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);
	u8RearFog_P_Received = FTT_Adapt_GetMessage_RFogLmpSts(&u8RearFog_Lmp_Pbox);

	if(TT_Rear_FogNopbox_ENABLE)
	{	//no pbox
		if ((0 == u8RearFog_Config_Byte38) && (0 == u8RearFog_Config_Byte80))
		{
			if ((u8RearFog_Received == RTE_E_OK) && (1 == u8RearFog_LmpSts))
			{
				TT_SET(enFTT_Rear_Fog,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Rear_Fog,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Rear_FogPbox_ENABLE)
	{	//pbox
		if((1 == u8RearFog_Config_Byte38) || (1 == u8RearFog_Config_Byte80))
		{
			if ((u8RearFog_P_Received == RTE_E_OK) && (1 == u8RearFog_Lmp_Pbox))
			{
				TT_SET(enFTT_Rear_Fog,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Rear_Fog,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Rear_Fog,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vHigh_Beam_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	1
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	1
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	0
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	0
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	0
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	0
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	1
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	1
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	0
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_High_Beampbox_ENABLE  0
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	1
	#define TT_High_BeamFCM_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_High_Beampbox_ENABLE  1
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	0
	#define TT_High_BeamFCM_ENABLE	0

#else
	#define TT_High_Beampbox_ENABLE  0
	#define TT_High_BeamHC_ENABLE	0
	#define TT_High_BeamBCM_ENABLE	0
	#define TT_High_BeamHCM_ENABLE	0
	#define TT_High_BeamFCM_ENABLE	0
#endif

void FTT_vHigh_Beam_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8HighBeam_BCM_Received = RTE_E_INVALID;
	uint8 u8HighBeam_Pbox_Received = RTE_E_INVALID;
	uint8 u8HighBeam_HC_Received = RTE_E_INVALID;
	uint8 u8HighBeam_HCM_L1_Received = RTE_E_INVALID;
	uint8 u8HighBeam_HCM_R1_Received = RTE_E_INVALID;
	uint8 u8HighBeam_FCM_Received = RTE_E_INVALID;
	uint8 u8HighBeamSts_BCM = 0;
	uint8 u8HighBeamSts_Pbox = 0;
	uint8 u8HighBeamSts_HC = 0;
	uint8 u8LHiBeamSts_HCM = 0;
	uint8 u8RHiBeamSts_HCM = 0;
	uint8 u8HighBeamSts_FCM = 0;
	uint8 u8HighBeam_Config_Byte38 = 0;
	uint8 u8HighBeam_Config_Byte33 = 0;
	uint8 u8HighBeam_Config_Byte37 = 0;
	uint8 u8HighBeam_Config_Byte60 = 0;
	uint8 u8HighBeam_Config_Byte80 = 0;

	TT_SET_CFG(enFTT_High_Beam,ON);
	TT_SET_DID(enFTT_High_Beam,OFF);

	u8HighBeam_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8HighBeam_Config_Byte33 = FTT_Adapt_GetVconfig(VCONFIG_KIND_HEAD_LAMP_BEAM_SYSTEM);
	u8HighBeam_Config_Byte37 = FTT_Adapt_GetVconfig(VCONFIG_KIND_HEAD_LAMP_LIGHTING);
	u8HighBeam_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);
	u8HighBeam_Config_Byte60 = FTT_Adapt_GetVconfig(VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION);
	u8HighBeam_HCM_L1_Received = FTT_Adapt_GetMessage_LHiBeamSts(&u8LHiBeamSts_HCM);
	u8HighBeam_HCM_R1_Received = FTT_Adapt_GetMessage_RHiBeamSts(&u8RHiBeamSts_HCM);
	u8HighBeam_Pbox_Received = FTT_Adapt_GetMessage_HiBeamSts_F_PBOX(&u8HighBeamSts_Pbox);
	u8HighBeam_HC_Received = FTT_Adapt_GetMessage_HighBeamSts_HC(&u8HighBeamSts_HC);
	//u8HighBeam_FCM_Received = FTT_Adapt_GetMessage_HighBeamSts_FCM(&u8HighBeamSts_FCM);

	if(TT_High_BeamBCM_ENABLE)
	{	//BCM
		if ((0 == u8HighBeam_Config_Byte38) && (0 == u8HighBeam_Config_Byte80) && ((0 == u8HighBeam_Config_Byte33)\
			|| (1 == u8HighBeam_Config_Byte33) || (2 == u8HighBeam_Config_Byte33)))
		{
			if ((u8HighBeam_BCM_Received == RTE_E_OK) && (1 == u8HighBeamSts_BCM))
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_OFF);
			}
		}
	}

	if((0 != (TT_High_Beampbox_ENABLE)) || (0 != (TT_High_BeamHCM_ENABLE)))
	{	//pbox
		if (((1 == u8HighBeam_Config_Byte38) || (1 == u8HighBeam_Config_Byte80)) && ((0 == u8HighBeam_Config_Byte33)\
			|| (1 == u8HighBeam_Config_Byte33) || (2 == u8HighBeam_Config_Byte33)) && (2 == u8HighBeam_Config_Byte60))
		{
			if ((u8HighBeam_Pbox_Received == RTE_E_OK) && (1 == u8HighBeamSts_Pbox))
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_ON);
			}
			else if ((u8HighBeam_HCM_L1_Received == RTE_E_OK) && (u8HighBeam_HCM_R1_Received == RTE_E_OK) \
				&& ((1 == u8LHiBeamSts_HCM) || (1 == u8RHiBeamSts_HCM)))
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_OFF);
			}
		}
		else if (((1 == u8HighBeam_Config_Byte38) || (1 == u8HighBeam_Config_Byte80)) && ((0 == u8HighBeam_Config_Byte33)\
			|| (1 == u8HighBeam_Config_Byte33) || (2 == u8HighBeam_Config_Byte33)))
		{
			if ((u8HighBeam_Pbox_Received == RTE_E_OK) && (1 == u8HighBeamSts_Pbox))
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_OFF);
			}
		}
		else if (2 == u8HighBeam_Config_Byte60)
		{
			if((u8HighBeam_HCM_L1_Received == RTE_E_OK) && (u8HighBeam_HCM_R1_Received == RTE_E_OK))
			{
				if((1 == u8LHiBeamSts_HCM) || (1 == u8RHiBeamSts_HCM))
				{
					TT_SET(enFTT_High_Beam,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_High_Beam,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_OFF);
			}
		}
	}
	//HC
	if(TT_High_BeamHC_ENABLE)
	{
		 if ((3 == u8HighBeam_Config_Byte33) && (1 == u8HighBeam_Config_Byte60))
		{
			if ((u8HighBeam_HC_Received == RTE_E_OK) && (1 == u8HighBeamSts_HC))
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_OFF);
			}
		}
	}

	if(TT_High_BeamFCM_ENABLE)
	{//FCM
		if (6 == u8HighBeam_Config_Byte37)
		{
			if((u8HighBeam_FCM_Received == RTE_E_OK) && (1 == u8HighBeamSts_FCM))
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_High_Beam,TT_enTURN_OFF);
			}
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vTurn_Left_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  1
#else
	#define TT_Turn_LeftNopbox_ENABLE  0
	#define TT_Turn_LeftPbox_ENABLE  0
#endif

void FTT_vTurn_Left_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8TurnLeft_Received = RTE_E_INVALID;
	uint8 u8TurnLeft_P_Received = RTE_E_INVALID;
	uint8 u8TurnLeft_LampSts = 0;
	uint8 u8TurnLeft_P_LampSts = 0;
	uint8 u8TurnLeft_Config_Byte38 = 0;
	uint8 u8TurnLeft_Config_Byte80 = 0;
	uint8 u8TurnLeftHmiAliveSts = 0;
	TT_CFG_enStatusType TurnLeft_Status = TT_enTURN_OFF;
	uint8 u8TurnLeftOsTimeStatus = 0;
	uint32 u8TurnLeftoldTime = 0;
	uint32 u8TurnLeftpassTime = 0;

	TT_SET_CFG(enFTT_Turn_Left,ON);
	TT_SET_DID(enFTT_Turn_Left,OFF);

	u8TurnLeft_P_Received = FTT_Adapt_GetMessage_LTurnLmpSts_R_PBOX(&u8TurnLeft_P_LampSts);
	u8TurnLeft_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8TurnLeft_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);

	if(TT_Turn_LeftNopbox_ENABLE)
	{	//no pbox
		if ((0 == u8TurnLeft_Config_Byte38) && (0 == u8TurnLeft_Config_Byte80))
		{
			if ((u8TurnLeft_Received == RTE_E_OK) && (1 == u8TurnLeft_LampSts))
			{
				TurnLeft_Status = TT_enTURN_ON;
			}
			else
			{
				TurnLeft_Status = TT_enTURN_OFF;
			}
		}
	}

	if(TT_Turn_LeftPbox_ENABLE)
	{	//pbox
		if((1 == u8TurnLeft_Config_Byte38) || (1 == u8TurnLeft_Config_Byte80))
		{
			if ((u8TurnLeft_P_Received == RTE_E_OK) && (1 == u8TurnLeft_P_LampSts))
			{
				TurnLeft_Status = TT_enTURN_ON;
			}
			else
			{
				TurnLeft_Status = TT_enTURN_OFF;
			}
		}
		else
		{
			TurnLeft_Status = TT_enTURN_OFF;
		}
	}

	if(RTE_E_OK != Rte_Read_SocReadyFlag_Element(&u8TurnLeftHmiAliveSts))
	{
		u8TurnLeftHmiAliveSts = 0;
	}

	// log output: timetick
	if (TRUE == SWC_TT_LOGOUT_ENBLE)
	{
		u32TLTimeTick[0]++;
	}

	if((FALSE != (u8TurnLeftHmiAliveSts & 0x40U)) && (FALSE != u8TurnLeftFlashOnResult))
	{
		TT_SET(enFTT_Turn_Left,TurnLeft_Status);
	}
	else
	{
		if(TT_enTURN_ON == TurnLeft_Status)
		{
			if(FALSE == u8TurnLeftFlashOnTimeFlag)
			{
				u8TurnLeftOsTimeStatus = Rte_Call_Os_Service_GetCounterValue(&u32TurnLeftFlashOnTime);
				if(RTE_E_Os_Service_E_OK == u8TurnLeftOsTimeStatus)
				{
					u8TurnLeftFlashOnTimeFlag = 1;//TRUE;
				}
				u8TurnLeftFlashOnResult = 0;//FALSE;
			}
			else
			{
				u8TurnLeftoldTime = u32TurnLeftFlashOnTime;
				u8TurnLeftOsTimeStatus = Rte_Call_Os_Service_GetElapsedValue(&u8TurnLeftoldTime,&u8TurnLeftpassTime);
				if(RTE_E_Os_Service_E_OK == u8TurnLeftOsTimeStatus)
				{
					if(u8TurnLeftpassTime >= 500)
					{
						u8TurnLeftFlashOnResult = 1;//TRUE;
					}
				}
			}
		}
		else
		{
			u8TurnLeftFlashOnTimeFlag = 0;//FALSE;
			u8TurnLeftFlashOnResult = 1;//TRUE;
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vTurn_Right_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  1
#else
	#define TT_Turn_RightNopbox_ENABLE  0
	#define TT_Turn_RightPbox_ENABLE  0
#endif

void FTT_vTurn_Right_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8TurnRight_Received = RTE_E_INVALID;
	uint8 u8TurnRight_P_Received = RTE_E_INVALID;
	uint8 u8TurnRight_LampSts = 0;
	uint8 u8TurnRight_P_LampSts = 0;
	uint8 u8TurnRight_Config_Byte38 = 0;
	uint8 u8TurnRight_Config_Byte80 = 0;
	uint8 u8TurnRightHmiAliveSts = 0;
	TT_CFG_enStatusType TurnRight_Status = TT_enTURN_OFF;
	uint8 u8TurnRightOsTimeStatus = 0;
	uint32 u8TurnRightoldTime = 0;
	uint32 u8TurnRightpassTime = 0;
	TT_SET_CFG(enFTT_Turn_Right,ON);
	TT_SET_DID(enFTT_Turn_Right,OFF);

	u8TurnRight_P_Received = FTT_Adapt_GetMessage_RTurnLmpSts_R_PBOX(&u8TurnRight_P_LampSts);
	u8TurnRight_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8TurnRight_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);

	if(TT_Turn_RightNopbox_ENABLE)
	{
		//no pbox
		if ((0 == u8TurnRight_Config_Byte38) && (0 == u8TurnRight_Config_Byte80))
		{
			if ((u8TurnRight_Received == RTE_E_OK) && (1 == u8TurnRight_LampSts))
			{
				TurnRight_Status = TT_enTURN_ON;
			}
			else
			{
				TurnRight_Status = TT_enTURN_OFF;
			}
		}
	}

	if(TT_Turn_RightPbox_ENABLE)
	{	//pbox
		if((1 == u8TurnRight_Config_Byte38) || (1 == u8TurnRight_Config_Byte80))
		{
			if ((u8TurnRight_P_Received == RTE_E_OK) && (1 == u8TurnRight_P_LampSts))
			{
				TurnRight_Status = TT_enTURN_ON;
			}
			else
			{
				TurnRight_Status = TT_enTURN_OFF;
			}
		}
		else
		{
			TurnRight_Status = TT_enTURN_OFF;
		}
	}

	if(RTE_E_OK != Rte_Read_SocReadyFlag_Element(&u8TurnRightHmiAliveSts))
	{
		u8TurnRightHmiAliveSts = 0;
	}

	// log output: timetick
	if (TRUE == SWC_TT_LOGOUT_ENBLE)
	{
		u32TLTimeTick[1]++;
	}

	if((FALSE != (u8TurnRightHmiAliveSts & 0x40U)) && (FALSE != u8TurnRightFlashOnResult))
	{
		TT_SET(enFTT_Turn_Right,TurnRight_Status);
	}
	else
	{
		if(TT_enTURN_ON == TurnRight_Status)
		{
			if(FALSE == u8TurnRightFlashOnTimeFlag)
			{
				u8TurnRightOsTimeStatus = Rte_Call_Os_Service_GetCounterValue(&u32TurnRightFlashOnTime);
				if(RTE_E_Os_Service_E_OK == u8TurnRightOsTimeStatus)
				{
					u8TurnRightFlashOnTimeFlag = 1;//TRUE;
				}
				u8TurnRightFlashOnResult = 0;//FALSE;
			}
			else
			{
				u8TurnRightoldTime = u32TurnRightFlashOnTime;
				u8TurnRightOsTimeStatus = Rte_Call_Os_Service_GetElapsedValue(&u8TurnRightoldTime,&u8TurnRightpassTime);
				if(RTE_E_Os_Service_E_OK == u8TurnRightOsTimeStatus)
				{
					if(u8TurnRightpassTime >= 500)
					{
						u8TurnRightFlashOnResult = 1;//TRUE;
					}
				}
			}
		}
		else
		{
			u8TurnRightFlashOnTimeFlag = 0;//FALSE;
			u8TurnRightFlashOnResult = 1;//TRUE;
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vPosition_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  1

#else
	#define TT_Position_Nopbox_ENABLE  0
	#define TT_Position_Pbox_ENABLE  0
#endif

void FTT_vPosition_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Position_Received = RTE_E_INVALID;
	uint8 u8Position_P_Received = RTE_E_INVALID;
	uint8 u8Position_LampSts = 0;
	uint8 u8Position_P_LampSts = 0;
	uint8 u8Position_Config_Byte38 = 0;
	uint8 u8Position_Config_Byte80 = 0;
	TT_SET_CFG(enFTT_Position,ON);
	TT_SET_DID(enFTT_Position,OFF);

	u8Position_P_Received = FTT_Adapt_GetMessage_PosnLmpOutpSts_R_PBOX(&u8Position_P_LampSts);
	u8Position_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8Position_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);

	if(TT_Position_Nopbox_ENABLE)
	{	//no pbox
		if ((0 == u8Position_Config_Byte38) && (0 == u8Position_Config_Byte80))
		{
			if ((u8Position_Received == RTE_E_OK) && (1 == u8Position_LampSts))
			{
				TT_SET(enFTT_Position,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Position,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Position_Pbox_ENABLE)
	{	//pbox
		if((1 == u8Position_Config_Byte38) || (1 == u8Position_Config_Byte80))
		{
			if ((u8Position_P_Received == RTE_E_OK) && (1 == u8Position_P_LampSts))
			{
				TT_SET(enFTT_Position,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Position,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Position,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vLight_Switch_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  1

#else
	#define TT_Light_Switch_Nopbox_ENABLE  0
	#define TT_Light_Switch_Pbox_ENABLE  0
#endif

void FTT_vLight_Switch_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Switch_Received = RTE_E_INVALID;
	uint8 u8Switch_P_Received = RTE_E_INVALID;
	uint8 u8Switch_LampSts = 0;
	uint8 u8Switch_P_LampSts = 0;
	uint8 u8Switch_Config_Byte38 = 0;
	uint8 u8Switch_Config_Byte80 = 0;
	TT_SET_CFG(enFTT_LightSwitch,ON);
	TT_SET_DID(enFTT_LightSwitch,OFF);

	u8Switch_P_Received = FTT_Adapt_GetMessage_PosnLmpOutpSts_R_PBOX(&u8Switch_P_LampSts);
	u8Switch_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8Switch_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);

	if(TT_Light_Switch_Nopbox_ENABLE)
	{	//no pbox
		if ((0 == u8Switch_Config_Byte38) && (0 == u8Switch_Config_Byte80))
		{
			if ((u8Switch_Received == RTE_E_OK) && (1 == u8Switch_LampSts))
			{
				TT_SET(enFTT_LightSwitch,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_LightSwitch,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Light_Switch_Pbox_ENABLE)
	{	//pbox
		if((1 == u8Switch_Config_Byte38) || (1 == u8Switch_Config_Byte80))
		{
			if ((u8Switch_P_Received == RTE_E_OK) && (1 == u8Switch_P_LampSts))
			{
				TT_SET(enFTT_LightSwitch,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_LightSwitch,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_LightSwitch,TT_enTURN_OFF);
		}
	}

}


/*******************************************************************************
*	Function name		: FTT_vTrailer_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  0

#else
	#define TT_Trailer_Nopbox_ENABLE  0
	#define TT_Trailer_Pbox_ENABLE  0
#endif

void FTT_vTrailer_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Trailer_TBD_Receved = RTE_E_INVALID;
	uint8 u8Trailer_Received = RTE_E_INVALID;
	uint8 u8Trailer_P_Received = RTE_E_INVALID;
	uint8 u8Trailer_LampSts = 0;
	uint8 u8Trailer_LeftTurnSts = 0;
	uint8 u8Trailer_RightTurnSts = 0;
	uint8 u8Trailer_P_LeftTurnSts = 0;
	uint8 u8Trailer_P_RightTurnSts = 0;
	uint8 u8Trailer_Config_Byte38 = 0;
	uint8 u8Trailer_Config_Byte23 = 0;
	uint8 u8Trailer_Config_Byte80 = 0;
	TT_SET_CFG(enFTT_Trailer,ON);
	TT_SET_DID(enFTT_Trailer,OFF);

	u8Trailer_Received = FTT_Adapt_GetMessage_TrailerSts(&u8Trailer_LampSts);
	(void)FTT_Adapt_GetMessage_RTurnLmpSts_R_PBOX(&u8Trailer_P_RightTurnSts);
	u8Trailer_P_Received = FTT_Adapt_GetMessage_LTurnLmpSts_R_PBOX(&u8Trailer_P_LeftTurnSts);
	u8Trailer_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8Trailer_Config_Byte23 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TRAILING_HOOK);
	u8Trailer_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);

	if(TT_Trailer_Nopbox_ENABLE)
	{	// no pbox
		if ((0 == u8Trailer_Config_Byte38) && (0 == u8Trailer_Config_Byte80) && \
			((2 == u8Trailer_Config_Byte23) || (4 == u8Trailer_Config_Byte23) || \
			(5 == u8Trailer_Config_Byte23) || (6 == u8Trailer_Config_Byte23)))
		{
			if ((u8Trailer_TBD_Receved == RTE_E_OK) && (u8Trailer_Received == RTE_E_OK))
			{
				if ((u8Trailer_LampSts == TT_FUN_ACTIVE) && ((u8Trailer_LeftTurnSts == TT_FUN_ACTIVE) \
					|| (u8Trailer_RightTurnSts == TT_FUN_ACTIVE)))
				{
					TT_SET(enFTT_Trailer,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Trailer,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_Trailer,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Trailer_Pbox_ENABLE)
	{	//with pbox
		if(((2 == u8Trailer_Config_Byte23) || (4 == u8Trailer_Config_Byte23) ||\
			(5 == u8Trailer_Config_Byte23) || (6 == u8Trailer_Config_Byte23)) &&\
			((1 == u8Trailer_Config_Byte38) || (1 == u8Trailer_Config_Byte80)))
		{
			if ((u8Trailer_P_Received == RTE_E_OK) && (u8Trailer_Received == RTE_E_OK))
			{
				if ((u8Trailer_LampSts == TT_FUN_ACTIVE) && ((u8Trailer_P_LeftTurnSts == TT_FUN_ACTIVE) \
					|| (u8Trailer_P_RightTurnSts == TT_FUN_ACTIVE)))
				{
					TT_SET(enFTT_Trailer,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Trailer,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_Trailer,TT_enTURN_OFF);
			}
		}
	}
	//拖车转向灯和左右转向灯的闪烁频率相同

}


/*******************************************************************************
*	Function name		: FTT_vDoor_Open_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  1

#else
	#define TT_Door_Open_Nopbox_ENABLE  0
	#define TT_Door_Open_Pbox_ENABLE  0
#endif

void FTT_vDoor_Open_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8DoorOpen_Received = RTE_E_INVALID;
	uint8 u8DoorOpen_P_Received = RTE_E_INVALID;
	uint8 u8TrunkSts_Y_Received = RTE_E_INVALID;
	uint8 u8Drv_DoorSts = 0;
	uint8 u8PassDoorSts = 0;
	uint8 u8LRDoorSts = 0;
	uint8 u8RRDoorSts = 0;
	uint8 u8TrunkSts = 0;
	uint8 u8HoodSts = 0;
	uint8 u8Hood_P_Sts = 0;
	uint8 u8TrunkSts_Y = 0;//TBD BDCv4.0 add
	uint8 u8Door_Config_Byte38 = 0;
	uint8 u8Door_Config_Byte80 = 0;
	uint8 u8Door_Config_Byte93 = 0;
	TT_SET_CFG(enFTT_DoorOpen,ON);
	TT_SET_DID(enFTT_DoorOpen,OFF);

	u8DoorOpen_Received = FTT_Adapt_GetMessage_DrvDoorSts(&u8Drv_DoorSts);
	u8DoorOpen_P_Received = FTT_Adapt_GetMessage_HoodSts_F_Pbox(&u8Hood_P_Sts);
	u8TrunkSts_Y_Received = FTT_Adapt_GetMessage_TrunkSts_Y(&u8TrunkSts_Y);
	(void)FTT_Adapt_GetMessage_PassengerDoorSts(&u8PassDoorSts);
	(void)FTT_Adapt_GetMessage_LRDoorSts(&u8LRDoorSts);
	(void)FTT_Adapt_GetMessage_RRDoorSts(&u8RRDoorSts);
	(void)FTT_Adapt_GetMessage_TrunkSts(&u8TrunkSts);
	u8Door_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8Door_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);
	u8Door_Config_Byte93 = FTT_Adapt_GetVconfig(VCONFIG_KIND_DECK_RR_PLATE);

	if(TT_Door_Open_Nopbox_ENABLE)
	{	//no pbox
		if ((0 == u8Door_Config_Byte38) && (0 == u8Door_Config_Byte80))
		{
			if (u8DoorOpen_Received == RTE_E_OK)
			{
				if ((1 == u8Drv_DoorSts) || (1 == u8PassDoorSts) || (1 == u8LRDoorSts) || (1 == u8RRDoorSts) || (1 == u8TrunkSts) || (1 == u8HoodSts))
				{
					TT_SET(enFTT_DoorOpen,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Door_Open_Pbox_ENABLE)
	{	// with pbox
		if((1 == u8Door_Config_Byte38) || (1 == u8Door_Config_Byte80))
		{
		 	if((u8Door_Config_Byte93 == 0) || (u8Door_Config_Byte93 == 1))//case 1 and yitishi case2
		 	{
				if ((u8DoorOpen_Received == RTE_E_OK) && (u8DoorOpen_P_Received == RTE_E_OK))
				{
					if ((1 == u8Drv_DoorSts) || (1 == u8PassDoorSts) || (1 == u8LRDoorSts) || (1 == u8RRDoorSts) || (1 == u8TrunkSts) || (1 == u8Hood_P_Sts))
					{
						TT_SET(enFTT_DoorOpen,TT_enTURN_ON);
					}
					else
					{
						TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);
					}
				}
				else if((u8DoorOpen_Received == RTE_E_OK) && (u8DoorOpen_P_Received != RTE_E_OK))
				{
					if ((1 == u8Drv_DoorSts) || (1 == u8PassDoorSts) || (1 == u8LRDoorSts) || (1 == u8RRDoorSts) || (1 == u8TrunkSts))
					{
						TT_SET(enFTT_DoorOpen,TT_enTURN_ON);
					}
					else
					{
						TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);
					}
				}
				else if((u8DoorOpen_Received != RTE_E_OK) && (u8DoorOpen_P_Received == RTE_E_OK))
				{
					if (1 == u8Hood_P_Sts)
					{
						TT_SET(enFTT_DoorOpen,TT_enTURN_ON);
					}
					else
					{
						TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);
					}
				}
				else
				{
					TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);
				}
		 	}
			else if((u8Door_Config_Byte93 == 2) || (u8Door_Config_Byte93 == 3))
			{	//fentishi case 2 P05

				TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);

				if(u8DoorOpen_Received == RTE_E_OK)
				{
					if ((1 == u8Drv_DoorSts) || (1 == u8PassDoorSts) || (1 == u8LRDoorSts) || (1 == u8RRDoorSts)|| (1 == u8TrunkSts))
					{
						TT_SET(enFTT_DoorOpen,TT_enTURN_ON);
					}
				}
				if(u8DoorOpen_P_Received == RTE_E_OK)
				{
					if (1 == u8Hood_P_Sts)
					{
						TT_SET(enFTT_DoorOpen,TT_enTURN_ON);
					}
				}
				if(u8TrunkSts_Y_Received == RTE_E_OK)
				{
					if(1 == u8TrunkSts_Y)
					{		
						TT_SET(enFTT_DoorOpen,TT_enTURN_ON);
					}
				}
			}
			else
			{
				TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_DoorOpen,TT_enTURN_OFF);
		}
	}
}
/*******************************************************************************
*	Function name		: FTT_vSeat_Belt_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		: seat belt 在北美配置不需要自检 ,相关逻辑在TT_interface.c的cold init和warm_init里面
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Seat_Belt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Seat_Belt_ENABLE  1

#else
	#define TT_Seat_Belt_ENABLE  0
#endif

void FTT_vSeat_Belt_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8SeatBelt_Received = RTE_E_INVALID;
	uint8 u8DrvSBR_Visual = 0;
	uint8 u8PassSBR_Visual = 0;
	uint8 u8SecRowLSBR_Visual = 0;
	uint8 u8SecRowMSBR_Visual = 0;
	uint8 u8SecRowRSBR_Visual = 0;
	uint8 u8Seat_Config_Byte32 = 0;
	TT_SET_CFG(enFTT_Seat_Belt,ON);

	u8SeatBelt_Received = FTT_Adapt_GetMessage_DrvSBR_Visual(&u8DrvSBR_Visual);
	(void)FTT_Adapt_GetMessage_PassSBR_Visual(&u8PassSBR_Visual);
	(void)FTT_Adapt_GetMessage_SecRowLSBR_Visual(&u8SecRowLSBR_Visual);
	(void)FTT_Adapt_GetMessage_SecRowMidSBR_Visual(&u8SecRowMSBR_Visual);
	(void)FTT_Adapt_GetMessage_SecRowRSBR_Visual(&u8SecRowRSBR_Visual);

	u8Seat_Config_Byte32 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SEAT_BELT);

	if(TT_Seat_Belt_ENABLE)
	{
		if (u8SeatBelt_Received == RTE_E_OK)
		{
			switch(u8Seat_Config_Byte32)
			{
				case (uint8)TT_SEAT_BELT_DRV:
				TT_SET_DID(enFTT_Seat_Belt,ON);
				if (u8DrvSBR_Visual == TT_SBT_LAMP_ON)
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_ON);
				}
				else if (u8DrvSBR_Visual == TT_SBT_LAMP_BLINK)
				{
					TT_SET(enFTT_Seat_Belt,TT_enFLASH_1_HZ);
				}
				else
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_OFF);
				}
				break;

				case (uint8)TT_SEAT_BELT_FRONT:
				TT_SET_DID(enFTT_Seat_Belt,ON);
				if (((u8DrvSBR_Visual == TT_SBT_LAMP_ON) && (u8PassSBR_Visual != TT_SBT_LAMP_BLINK)) \
					|| ((u8DrvSBR_Visual != TT_SBT_LAMP_BLINK) && (u8PassSBR_Visual == TT_SBT_LAMP_ON)))
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_ON);
				}
				else if ((u8DrvSBR_Visual == TT_SBT_LAMP_BLINK) || (u8PassSBR_Visual == TT_SBT_LAMP_BLINK))
				{
					TT_SET(enFTT_Seat_Belt,TT_enFLASH_1_HZ);
				}
				else
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_OFF);
				}
				break;

				case (uint8)TT_SEAT_BELT_ALL:
				TT_SET_DID(enFTT_Seat_Belt,ON);
				if ((u8DrvSBR_Visual == TT_SBT_LAMP_ON) && (u8PassSBR_Visual != TT_SBT_LAMP_BLINK) \
					&& (u8SecRowLSBR_Visual != TT_SBT_LAMP_BLINK) && (u8SecRowMSBR_Visual != TT_SBT_LAMP_BLINK) \
					&& (u8SecRowRSBR_Visual != TT_SBT_LAMP_BLINK))
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_ON);
				}
				else if ((u8DrvSBR_Visual != TT_SBT_LAMP_BLINK) && (u8PassSBR_Visual == TT_SBT_LAMP_ON) \
					&& (u8SecRowLSBR_Visual != TT_SBT_LAMP_BLINK) && (u8SecRowMSBR_Visual != TT_SBT_LAMP_BLINK) \
					&& (u8SecRowRSBR_Visual != TT_SBT_LAMP_BLINK))
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_ON);
				}
				else if ((u8DrvSBR_Visual != TT_SBT_LAMP_BLINK) && (u8PassSBR_Visual != TT_SBT_LAMP_BLINK) \
					&& (u8SecRowLSBR_Visual == TT_SBT_LAMP_ON) && (u8SecRowMSBR_Visual != TT_SBT_LAMP_BLINK) \
					&& (u8SecRowRSBR_Visual != TT_SBT_LAMP_BLINK))
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_ON);
				}
				else if ((u8DrvSBR_Visual != TT_SBT_LAMP_BLINK) && (u8PassSBR_Visual != TT_SBT_LAMP_BLINK) \
					&& (u8SecRowLSBR_Visual != TT_SBT_LAMP_BLINK) && (u8SecRowMSBR_Visual == TT_SBT_LAMP_ON) \
					&& (u8SecRowRSBR_Visual != TT_SBT_LAMP_BLINK))
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_ON);
				}
				else if ((u8DrvSBR_Visual != TT_SBT_LAMP_BLINK) && (u8PassSBR_Visual != TT_SBT_LAMP_BLINK) \
					&& (u8SecRowLSBR_Visual != TT_SBT_LAMP_BLINK) && (u8SecRowMSBR_Visual != TT_SBT_LAMP_BLINK) \
					&& (u8SecRowRSBR_Visual == TT_SBT_LAMP_ON))
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_ON);
				}
				else if ((u8DrvSBR_Visual == TT_SBT_LAMP_BLINK) || (u8PassSBR_Visual == TT_SBT_LAMP_BLINK) \
					|| (u8SecRowLSBR_Visual == TT_SBT_LAMP_BLINK) || (u8SecRowMSBR_Visual == TT_SBT_LAMP_BLINK) \
					|| (u8SecRowRSBR_Visual == TT_SBT_LAMP_BLINK))
				{
					TT_SET(enFTT_Seat_Belt,TT_enFLASH_1_HZ);
				}
				else
				{
					TT_SET(enFTT_Seat_Belt,TT_enTURN_OFF);
				}
				break;
				default :
					TT_SET(enFTT_Seat_Belt,TT_enTURN_OFF);
					TT_SET_DID(enFTT_Seat_Belt,OFF);
				break;
			}
			if(TT_DOMAIN_US == FTT_vDomain_Logic_Process())
			{
				TT_SET_DID(enFTT_Seat_Belt,OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Seat_Belt,TT_enTURN_ON);
		}
		(void)Rte_Write_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts(0);
		(void)Rte_Write_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts(0);
	}
}


/*******************************************************************************
*	Function name		: FTT_vTransmission_Over_Heat_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Transmission_OverHeat_7DCT_ENABLE  1
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   1
	#define TT_Transmission_OverHeat_9AT_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Transmission_OverHeat_7DCT_ENABLE  1
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   1
	#define TT_Transmission_OverHeat_9AT_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Transmission_OverHeat_7DCT_ENABLE  0
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   0
	#define TT_Transmission_OverHeat_9AT_ENABLE   1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Transmission_OverHeat_7DCT_ENABLE  0
	#define TT_Transmission_OverHeat_8AT_ENABLE   1
	#define TT_Transmission_OverHeat_DHT_ENABLE   0
	#define TT_Transmission_OverHeat_9AT_ENABLE   1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Transmission_OverHeat_7DCT_ENABLE  1
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   1
	#define TT_Transmission_OverHeat_9AT_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Transmission_OverHeat_7DCT_ENABLE  0
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   0
	#define TT_Transmission_OverHeat_9AT_ENABLE   1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Transmission_OverHeat_7DCT_ENABLE  0
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   0
	#define TT_Transmission_OverHeat_9AT_ENABLE   1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Transmission_OverHeat_7DCT_ENABLE  0
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   0
	#define TT_Transmission_OverHeat_9AT_ENABLE   1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Transmission_OverHeat_7DCT_ENABLE  0
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   0
	#define TT_Transmission_OverHeat_9AT_ENABLE   1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Transmission_OverHeat_7DCT_ENABLE  0
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   0
	#define TT_Transmission_OverHeat_9AT_ENABLE   1

#else
	#define TT_Transmission_OverHeat_7DCT_ENABLE  0
	#define TT_Transmission_OverHeat_8AT_ENABLE   0
	#define TT_Transmission_OverHeat_DHT_ENABLE   0
	#define TT_Transmission_OverHeat_9AT_ENABLE   0
#endif

void FTT_vTransmission_Over_Heat_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Trans_Received = RTE_E_INVALID;
	uint8 u8Trans_DHT_Received = RTE_E_INVALID;
	uint8 u8Trans_Received_8AT = RTE_E_INVALID;
	uint8 u8Trans_Config_Byte3 = 0;
	uint8 u8Trans_DrvWarnMsg = 0;
	uint8 u8TCU_ClutchHotWarning = 0;
	uint8 u8WarnHighTemp = 0;
	uint8 u8TransPowerMode = 0;
	TT_SET_CFG(enFTT_Trans_OverHeat,ON);

	u8Trans_Config_Byte3 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TRANSMISSION);
	u8Trans_Received = FTT_Adapt_GetMessage_DrvWarnMsg(&u8Trans_DrvWarnMsg);
	u8Trans_DHT_Received = FTT_Adapt_GetMessage_ClutchHotWarning(&u8TCU_ClutchHotWarning);
	u8Trans_Received_8AT = FTT_Adapt_GetMessage_Warn_high_temp(&u8WarnHighTemp);
	u8TransPowerMode = FTT_Adapt_GetPowerMode_State();

	if(TT_Transmission_OverHeat_7DCT_ENABLE)
	{	//7DCT/9DCT/9HDCT
		if ((7 == u8Trans_Config_Byte3) || (15 == u8Trans_Config_Byte3) \
			|| (16 == u8Trans_Config_Byte3) || (38 == u8Trans_Config_Byte3) \
			|| (41 == u8Trans_Config_Byte3))
		{
			TT_SET_DID(enFTT_Trans_OverHeat,ON);
			if (u8Trans_Received == RTE_E_OK)
			{
				if ((1 == u8Trans_DrvWarnMsg) || (2 == u8Trans_DrvWarnMsg))
				{
					TT_SET(enFTT_Trans_OverHeat,TT_enTURN_ON);
					FTT_SET_Report_DID(enFTT_Trans_OverHeat,ON);
				}
				else
				{
					TT_SET(enFTT_Trans_OverHeat,TT_enTURN_OFF);
					FTT_SET_Report_DID(enFTT_Trans_OverHeat,OFF);
				}
			}
			else
			{
				// keep previous status
			}
		}
	}

	if(TT_Transmission_OverHeat_8AT_ENABLE)
	{
		if (8 == u8Trans_Config_Byte3)   //8AT
		{
			TT_SET_DID(enFTT_Trans_OverHeat,ON);
			if (u8Trans_Received_8AT == RTE_E_OK)
			{
				if (u8WarnHighTemp == TT_FUN_ACTIVE)
				{
					TT_SET(enFTT_Trans_OverHeat,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Trans_OverHeat,TT_enTURN_OFF);
				}
			}
			else
			{
				//TT_SET(enFTT_Trans_OverHeat,TT_enTURN_OFF);
				/*超时保持状态不变，因此不需要添加逻辑*/
			}
		}
	}

	if(TT_Transmission_OverHeat_DHT_ENABLE)
	{
		if (19 == u8Trans_Config_Byte3)   //DHT
		{
			TT_SET_DID(enFTT_Trans_OverHeat,ON);
			if (u8Trans_DHT_Received == RTE_E_OK)
			{
				if (u8TCU_ClutchHotWarning == TT_FUN_RESERVE)
				{
					TT_SET(enFTT_Trans_OverHeat,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Trans_OverHeat,TT_enTURN_OFF);
				}
			}
			else
			{
				/*超时保持状态不变，因此不需要添加逻辑*/
			}
		}
	}

	if(TT_Transmission_OverHeat_9AT_ENABLE)
	{	//9AT/9HAT
		if ((39 == u8Trans_Config_Byte3) || (40 == u8Trans_Config_Byte3))
		{
			TT_SET_DID(enFTT_Trans_OverHeat,ON);
			if (u8Trans_Received == RTE_E_OK)
			{
				if ((1 == u8Trans_DrvWarnMsg) || (2 == u8Trans_DrvWarnMsg))
				{
					TT_SET(enFTT_Trans_OverHeat,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Trans_OverHeat,TT_enTURN_OFF);
				}
			}
			else
			{
				// keep previous status
			}
		}
	}

	if(u8TransPowerMode != SYSTEMSTATE_Cluster_ON)
	{
		TT_SET(enFTT_Trans_OverHeat,TT_enTURN_OFF);
	}
}


/*******************************************************************************
*	Function name		: FTT_vAuto_Light_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  1
	#define TT_Auto_Light_HC_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  1
	#define TT_Auto_Light_HC_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Auto_Light_BCM_ENABLE  1
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   0

#else
	#define TT_Auto_Light_BCM_ENABLE  0
	#define TT_Auto_Light_HCM_ENABLE  0
	#define TT_Auto_Light_HC_ENABLE   0
#endif

void FTT_vAuto_Light_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8AutoLight_BCM_Received = RTE_E_INVALID;
	uint8 u8AutoLight_HCM_L1_Received = RTE_E_INVALID;
	uint8 u8AutoLight_HCM_R1_Received = RTE_E_INVALID;
	uint8 u8AutoLight_HC_Received = RTE_E_INVALID;
	uint8 u8Autolight_HilowBeam = 0;
	uint8 u8AutoLight_LADBSts = 0;
	uint8 u8AutoLight_RADBSts = 0;
	uint8 u8AutoLight_ADBSts = 0;
	uint8 u8Auto_Config_Byte33 = 0;
	uint8 u8Auto_Config_Byte60 = 0;

	TT_SET_CFG(enFTT_Auto_Yellow,ON);
	TT_SET_CFG(enFTT_Auto_Green,ON);
	TT_SET_DID(enFTT_Auto_Yellow,OFF);
	TT_SET_DID(enFTT_Auto_Green,OFF);

	u8AutoLight_BCM_Received = FTT_Adapt_GetMessage_HiLowBeamSts(&u8Autolight_HilowBeam);
	u8AutoLight_HC_Received = FTT_Adapt_GetMessage_ADBstatus(&u8AutoLight_ADBSts);
	u8AutoLight_HCM_L1_Received = FTT_Adapt_GetMessage_LADBstatus(&u8AutoLight_LADBSts);
	u8AutoLight_HCM_R1_Received = FTT_Adapt_GetMessage_RADBstatus(&u8AutoLight_RADBSts);
	u8Auto_Config_Byte33 = FTT_Adapt_GetVconfig(VCONFIG_KIND_HEAD_LAMP_BEAM_SYSTEM);
	u8Auto_Config_Byte60 = FTT_Adapt_GetVconfig(VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION);

	if(TT_Auto_Light_BCM_ENABLE)
	{	//BCM
		if ((1 == u8Auto_Config_Byte33) || (2 == u8Auto_Config_Byte33))
		{
			if (u8AutoLight_BCM_Received == RTE_E_OK)
			{
				if (u8Autolight_HilowBeam == TT_FUN_ACTIVE)
				{
					TT_SET(enFTT_Auto_Green,TT_enTURN_ON);
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_OFF);
				}
				else if (u8Autolight_HilowBeam == TT_FUN_STANDBY)
				{
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_ON);
					TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
				}
				else
				{
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_Auto_Yellow,TT_enTURN_ON);
				TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
			}
		}
	}

	//HC
	if(TT_Auto_Light_HC_ENABLE)
	{
		if((3 == u8Auto_Config_Byte33) && (1 == u8Auto_Config_Byte60))
		{
			if (u8AutoLight_HC_Received == RTE_E_OK)
			{
				if (u8AutoLight_ADBSts == TT_FUN_ACTIVE)
				{
					TT_SET(enFTT_Auto_Green,TT_enTURN_ON);
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_OFF);
				}
				else if (u8AutoLight_ADBSts == TT_FUN_STANDBY)
				{
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_ON);
					TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
				}
				else
				{
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_Auto_Yellow,TT_enTURN_ON);
				TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Auto_Light_HCM_ENABLE)
	{	//HCM
		if ((3 == u8Auto_Config_Byte33) && (2 == u8Auto_Config_Byte60))
		{
			if ((u8AutoLight_HCM_L1_Received == RTE_E_OK) && (u8AutoLight_HCM_R1_Received == RTE_E_OK))
			{
				if (((1 == u8AutoLight_LADBSts) || (1 == u8AutoLight_RADBSts)) && ((2 != u8AutoLight_LADBSts) && (2!= u8AutoLight_RADBSts)))
				{
					TT_SET(enFTT_Auto_Green,TT_enTURN_ON);
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_OFF);
				}
				else if ((2 == u8AutoLight_LADBSts) || (2 == u8AutoLight_RADBSts))
				{
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_ON);
					TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
				}
				else
				{
					TT_SET(enFTT_Auto_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_Auto_Yellow,TT_enTURN_ON);
				TT_SET(enFTT_Auto_Green,TT_enTURN_OFF);
			}
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vLow_Fuel_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Low_Fuel_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Low_Fuel_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Low_Fuel_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Low_Fuel_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Low_Fuel_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Low_Fuel_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Low_Fuel_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Low_Fuel_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Low_Fuel_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Low_Fuel_ENABLE	1

#else
	#define TT_Low_Fuel_ENABLE  0
#endif

void FTT_vLow_Fuel_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8LowFuel_Config_Byte2 = 0;
	FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE ReadFuelSts;
	uint8 u8LowFuelSts = 0;
	uint8 u8IgnSts = 0;//get ign status
	uint8 u8ttselfRTEsts = 1;
	uint8 u8FuelLvlLowLmpStsOutPut = 0;
	TT_SET_CFG(enFTT_LowFuel,ON);

	u8IgnSts = FTT_Adapt_GetPowerMode_State();
	u8LowFuel_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	(void)FTT_Adapt_GetFuelModule_Data(&ReadFuelSts);

	if (0 == FTT_Adapt_GetSelfChecksts(&u8ttselfRTEsts))
	{
		u8TTNormalselfchecksts = u8ttselfRTEsts;
	}
	u8LowFuelSts = ReadFuelSts.Fuel_Warning_Status;

	if(TT_Low_Fuel_ENABLE)
	{	//config is ok ,interface is miss
		if ((0 == u8LowFuel_Config_Byte2) || (1 == u8LowFuel_Config_Byte2) || (2 == u8LowFuel_Config_Byte2) \
			|| (3 == u8LowFuel_Config_Byte2) || (4 == u8LowFuel_Config_Byte2) || (7 == u8LowFuel_Config_Byte2))
		{
			TT_SET_DID(enFTT_LowFuel,ON);
			if ((u8LowFuelSts == TT_SHORT_TO_BAT) || (u8LowFuelSts == TT_SHORT_TO_GND))
			{
				u8LowFuelSts = (uint8)TT_enFLASH_1_HZ;
			}
			else if (u8LowFuelSts == TT_LOWFUEL_NOERROR)
			{
				u8LowFuelSts = (uint8)TT_enTURN_ON;
			}
			else
			{
				u8LowFuelSts = (uint8)TT_enTURN_OFF;
			}
			/*行车后电源状态切换至ACC、OFF，仪表需要记忆ACC、OFF之前的报警状态，如果再次上电（KL15 reset）后，
			仪表检测到燃油量处于报警值和解报值之间时，需要判断上次是否处于报警状，如果是，则继续保持报警状态，如果不是，不进行报警提示*/
			if (u8LowFuelSts == TT_enTURN_ON)
			{
				TT_SET(enFTT_LowFuel,TT_enTURN_ON);
				u8FuelLvlLowLmpStsOutPut = 1;
			}
			else if (u8LowFuelSts == TT_enFLASH_1_HZ)
			{
				TT_SET(enFTT_LowFuel,TT_enFLASH_1_HZ);
				u8FuelLvlLowLmpStsOutPut = 2;
			}
			else
			{
				TT_SET(enFTT_LowFuel,TT_enTURN_OFF);
				u8FuelLvlLowLmpStsOutPut = 0;
			}
		}
		else
		{
			TT_SET(enFTT_LowFuel,TT_enTURN_OFF);
			TT_SET_DID(enFTT_LowFuel,OFF);
			u8FuelLvlLowLmpStsOutPut = 0;
		}

		if (u8IgnSts == SYSTEMSTATE_Cluster_ON)
		{
			if (u8TTNormalselfchecksts == 1)
			{
				(void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts(0);
			}
			else
			{
				(void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts(u8FuelLvlLowLmpStsOutPut);
			}
		}
		else
		{
			(void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts(0);
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vREADY_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_READY_HEVPHEV_ENABLE  1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_READY_HEVPHEV_ENABLE  1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_READY_HEVPHEV_ENABLE	1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_READY_HEVPHEV_ENABLE	1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_READY_HEVPHEV_ENABLE	1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_READY_HEVPHEV_ENABLE	1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_READY_HEVPHEV_ENABLE	1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_READY_HEVPHEV_ENABLE	1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_READY_HEVPHEV_ENABLE	1
	#define TT_READY_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_READY_HEVPHEV_ENABLE	1
	#define TT_READY_EV_ENABLE	0

#else
	#define TT_READY_HEVPHEV_ENABLE  0
	#define TT_READY_EV_ENABLE	0
#endif

void FTT_vREADY_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8READY_Mix_Received = RTE_E_INVALID;
	uint8 u8READY_EV_Received = RTE_E_INVALID;
	uint8 u8READY_LmpSts = 0;
	uint8 u8READY_LEDSts = 0;
	uint8 u8READY_Config_Byte2 = 0;
	uint8 u8READY_Config_Byte30 = 0;

	TT_SET_CFG(enFTT_Ready_Light,ON);
	TT_SET_DID(enFTT_Ready_Light,OFF);

	u8READY_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8READY_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	u8READY_Mix_Received = FTT_Adapt_GetMessage_RdyLmpSts(&u8READY_LmpSts);

	if(TT_READY_HEVPHEV_ENABLE)
	{	//mix
		if ((((3 == u8READY_Config_Byte2) || (4 == u8READY_Config_Byte2)) \
			&& ((5 == u8READY_Config_Byte30) || (6 == u8READY_Config_Byte30))) \
			||((4 == u8READY_Config_Byte2) && ((2 == u8READY_Config_Byte30) \
			|| (4 == u8READY_Config_Byte30) || (8 == u8READY_Config_Byte30))) \
			|| (((0 == u8READY_Config_Byte2) || (1 == u8READY_Config_Byte2) || (2 == u8READY_Config_Byte2) \
			|| (7 == u8READY_Config_Byte2)) && (1 == u8READY_Config_Byte30)) \
			|| ((3 == u8READY_Config_Byte2) && ((2 == u8READY_Config_Byte30) || (8 == u8READY_Config_Byte30))))
		{
			if ((u8READY_Mix_Received == RTE_E_OK) && (u8READY_LmpSts == 1))
			{
				TT_SET(enFTT_Ready_Light,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Ready_Light,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Ready_Light,TT_enTURN_OFF);
		}
	}

	if(TT_READY_EV_ENABLE)
	{	//EV
		if (5 == u8READY_Config_Byte2)
		{
			if (u8READY_EV_Received == RTE_E_OK)
			{
				if (TT_FUN_ACTIVE == u8READY_LEDSts)
				{
					TT_SET(enFTT_Ready_Light,TT_enTURN_ON);
				}
				else if (TT_FUN_STANDBY == u8READY_LEDSts)
				{
					TT_SET(enFTT_Ready_Light,TT_enFLASH_1_HZ);
				}
				else
				{
					TT_SET(enFTT_Ready_Light,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_Ready_Light,TT_enTURN_OFF);
			}

		}
		else
		{
			TT_SET(enFTT_Ready_Light,TT_enTURN_OFF);
		}
	}

}


/*******************************************************************************
*	Function name		: FTT_vEV_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_EV_Indicator_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_EV_Indicator_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_EV_Indicator_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_EV_Indicator_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_EV_Indicator_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_EV_Indicator_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_EV_Indicator_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_EV_Indicator_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_EV_Indicator_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_EV_Indicator_ENABLE	1

#else
	#define TT_EV_Indicator_ENABLE  0
#endif

void FTT_vEV_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8EV_Mix_Received = RTE_E_INVALID;
	boolean u8EV_LmpSts = FALSE;
	uint8 u8EV_Config_Byte2 = 0;
	uint8 u8EV_Config_Byte30 = 0;

	TT_SET_CFG(enFTT_EV_Indicator,ON);
	TT_SET_DID(enFTT_EV_Indicator,OFF);

	u8EV_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8EV_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	u8EV_Mix_Received = FTT_Adapt_GetMessage_EVLmpSts(&u8EV_LmpSts);

	if(TT_EV_Indicator_ENABLE)
	{
		if ((((3 == u8EV_Config_Byte2) || (4 == u8EV_Config_Byte2)) \
			&& ((5 == u8EV_Config_Byte30) || (6 == u8EV_Config_Byte30))) \
			|| ((4 == u8EV_Config_Byte2) && ((2 == u8EV_Config_Byte30) \
			|| (4 == u8EV_Config_Byte30) || (8 == u8EV_Config_Byte30))) \
			|| ((3 == u8EV_Config_Byte2) && ((2 == u8EV_Config_Byte30) || (8 == u8EV_Config_Byte30))))
		{
			if ((u8EV_Mix_Received == RTE_E_OK) && (1 == u8EV_LmpSts))
			{
				TT_SET(enFTT_EV_Indicator,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_EV_Indicator,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_EV_Indicator,TT_enTURN_OFF);
		}
	}

}


/*******************************************************************************
*	Function name		: FTT_vCharge_Status_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Charge_Status_PHEV_ENABLE  1
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Charge_Status_PHEV_ENABLE  1
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Charge_Status_PHEV_ENABLE	1
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Charge_Status_PHEV_ENABLE	0
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Charge_Status_PHEV_ENABLE	1
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Charge_Status_PHEV_ENABLE	1
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Charge_Status_PHEV_ENABLE	1
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Charge_Status_PHEV_ENABLE	1
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Charge_Status_PHEV_ENABLE	0
	#define TT_Charge_Status_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Charge_Status_PHEV_ENABLE	0
	#define TT_Charge_Status_EV_ENABLE	0

#else
	#define TT_Charge_Status_PHEV_ENABLE  0
	#define TT_Charge_Status_EV_ENABLE	0
#endif

void FTT_vCharge_Status_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Charge_Received = RTE_E_INVALID;
	uint8 u8Charge_LmpSts = 0;
	uint8 u8Charge_Config_Byte2 = 0;
	uint8 u8Charge_Config_Byte30 = 0;
	uint8 u8Charge_Config_V2VTBD = 0;
	uint8 u8Charge_Config_V2LTBD = 0;
	uint8 u8Charge_OBC_CCLine = 0;
	uint8 u8Charge_BMS_DCChrg = 0;
	uint8 u8Charge_OBC_Dchrg = 0;

	TT_SET_CFG(enFTT_Charging_Green,ON);
	TT_SET_CFG(enFTT_Charging_Red,ON);
	TT_SET_CFG(enFTT_Charging_E_Yellow,ON);
	TT_SET_CFG(enFTT_Charging_E_Red,ON);
	TT_SET_DID(enFTT_Charging_Green,OFF);
	TT_SET_DID(enFTT_Charging_Red,OFF);
	TT_SET_DID(enFTT_Charging_E_Yellow,OFF);
	TT_SET_DID(enFTT_Charging_E_Red,OFF);

	u8Charge_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8Charge_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);

	u8Charge_Received = FTT_Adapt_GetMessage_ChrgSysLmpSts(&u8Charge_LmpSts);

	if(TT_Charge_Status_PHEV_ENABLE)
	{
		if ((4 == u8Charge_Config_Byte2) && ((2 == u8Charge_Config_Byte30) || (4 == u8Charge_Config_Byte30) \
			|| (5 == u8Charge_Config_Byte30) || (6 == u8Charge_Config_Byte30) || (8 == u8Charge_Config_Byte30)))
		{
			if (u8Charge_Received == RTE_E_OK)
			{
				if (u8Charge_LmpSts == TT_CHARGE_GREEN)
				{
					TT_SET(enFTT_Charging_Green,TT_enTURN_ON);
					TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
				}
				else if (u8Charge_LmpSts == TT_CHARGE_RED)
				{
					TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_Red,TT_enTURN_ON);
					TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
				}
				else if (u8Charge_LmpSts == TT_CHARGE_E_YELLOW)
				{
					TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_ON);
					TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
				}
				else if (u8Charge_LmpSts == TT_CHARGE_E_RED)
				{
					TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_E_Red,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
			TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
			TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
			TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
		}
	}

	if(TT_Charge_Status_EV_ENABLE)
	{	//EV
		if((2 == u8Charge_Config_Byte2) && ((1 == u8Charge_Config_V2VTBD) || (1 == u8Charge_Config_V2LTBD)))
		{
			if ((1 == u8Charge_BMS_DCChrg) || (1 == u8Charge_OBC_CCLine) || (2 == u8Charge_OBC_CCLine)\
				|| (1 == u8Charge_OBC_Dchrg) || (2 == u8Charge_OBC_Dchrg))
			{
				TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_Red,TT_enTURN_ON);
				TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
			}
			else
			{
				TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
			}
		}
		else if((2 == u8Charge_Config_Byte2) && (1 == u8Charge_Config_V2VTBD) && (1 == u8Charge_Config_V2LTBD))
		{
			if((1 == u8Charge_BMS_DCChrg) || ((1 == u8Charge_OBC_CCLine) || (2 == u8Charge_OBC_CCLine)))
			{
				TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_Red,TT_enTURN_ON);
				TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
			}
			else
			{
				TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
				TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Charging_Green,TT_enTURN_OFF);
			TT_SET(enFTT_Charging_Red,TT_enTURN_OFF);
			TT_SET(enFTT_Charging_E_Yellow,TT_enTURN_OFF);
			TT_SET(enFTT_Charging_E_Red,TT_enTURN_OFF);
		}
	}

}


 /*******************************************************************************
 *	Function name		: FTT_vPower_Reduce_Process
 *
 *	Parameters		: void/void
 *
 *	Return Type 		: void/SINT8
 *
 *	Global Variables	:
 *
 *	External interface	:
 *
 *-----------------------------------------------------------------------------
 *	Invocation		: Called by the Telltale manager.
 *
 *	Description 		: function safety
 *
 ********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Power_Reduce_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Power_Reduce_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Power_Reduce_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Power_Reduce_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Power_Reduce_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Power_Reduce_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Power_Reduce_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Power_Reduce_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Power_Reduce_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Power_Reduce_ENABLE	1

#else
	#define TT_Power_Reduce_ENABLE  0
#endif

 void FTT_vPower_Reduce_Process(TT_tstMainObject* stMainObject)
 {
	uint8 u8Power_Mix_Received = RTE_E_INVALID;
	uint8 u8Power_LmpCmd = 0;
	uint8 u8Power_Config_Byte2 = 0;
	uint8 u8Power_Config_Byte30 = 0;
	TT_SET_CFG(enFTT_Power_Reduction,ON);

	u8Power_Mix_Received = FTT_Adapt_GetMessage_PowerRedWarnLmpCmd(&u8Power_LmpCmd);
	u8Power_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8Power_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);

	if(TT_Power_Reduce_ENABLE)
	{
		if (((4 == u8Power_Config_Byte2) && ((2 == u8Power_Config_Byte30) \
			|| (4 == u8Power_Config_Byte30) || (8 == u8Power_Config_Byte30))) \
			|| (((4 == u8Power_Config_Byte2) || (3 == u8Power_Config_Byte2)) \
			&& ((5 == u8Power_Config_Byte30) || (6 == u8Power_Config_Byte30))) \
			|| (((0 == u8Power_Config_Byte2) || (1 == u8Power_Config_Byte2) || (2 == u8Power_Config_Byte2) \
			|| (7 == u8Power_Config_Byte2)) && (1 == u8Power_Config_Byte30)) \
			|| ((3 == u8Power_Config_Byte2) && ((2 == u8Power_Config_Byte30) || (8 == u8Power_Config_Byte30))))
		{
			TT_SET_DID(enFTT_Power_Reduction,ON);
			if ((u8Power_Mix_Received == RTE_E_OK) && (u8Power_LmpCmd == 0x1))
			{
				TT_SET(enFTT_Power_Reduction,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Power_Reduction,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET_DID(enFTT_Power_Reduction,OFF);
			TT_SET(enFTT_Power_Reduction,TT_enTURN_OFF);
		}
	}

}

/*******************************************************************************
*	Function name		: FTT_vParking_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Parking_pbox_ENABLE  1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Parking_pbox_ENABLE  1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Parking_pbox_ENABLE	1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Parking_pbox_ENABLE	1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Parking_pbox_ENABLE	1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Parking_pbox_ENABLE	1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Parking_pbox_ENABLE	1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Parking_pbox_ENABLE	1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Parking_pbox_ENABLE	1
	#define TT_Parking_nopbox_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Parking_pbox_ENABLE	1
	#define TT_Parking_nopbox_ENABLE 0

#else
	#define TT_Parking_pbox_ENABLE  0
	#define TT_Parking_nopbox_ENABLE 0
#endif

void FTT_vParking_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Park_Received = RTE_E_INVALID;
	uint8 u8Park_P_Received = RTE_E_INVALID;
	uint8 u8Park_LampSts = 0;
	uint8 u8Park_P_LampSts = 0;
	uint8 u8Park_Config_Byte38 = 0;
	uint8 u8Park_Config_Byte32 = 0;
	uint8 u8Park_Config_Byte80 = 0;

	TT_SET_CFG(enFTT_Parking,ON);
	TT_SET_DID(enFTT_Parking,OFF);

	u8Park_Config_Byte32 = FTT_Adapt_GetVconfig(VCONFIG_KIND_PARKING_LAMP);
	u8Park_Config_Byte38 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8Park_Config_Byte80 = FTT_Adapt_GetVconfig(VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);
	u8Park_P_Received = FTT_Adapt_GetMessage_ParkLmpSts_R_Pbox(&u8Park_P_LampSts);

	if(TT_Parking_nopbox_ENABLE)//no pbox
	{
		if ((0 == u8Park_Config_Byte38) && (0 == u8Park_Config_Byte80) && (1 == u8Park_Config_Byte32))
		{
			if ((u8Park_Received == RTE_E_OK) && (u8Park_LampSts == 0x1))
			{
				TT_SET(enFTT_Parking,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Parking,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Parking_pbox_ENABLE)// with pbox
	{
		if ((1 == u8Park_Config_Byte32) && ((1 == u8Park_Config_Byte38) || (1 == u8Park_Config_Byte80)))
		{
			if ((u8Park_P_Received == RTE_E_OK) && (u8Park_P_LampSts == 0x1))
			{
				TT_SET(enFTT_Parking,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Parking,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Parking,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vRBS_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_BrakePad_Worn_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_BrakePad_Worn_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_BrakePad_Worn_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_BrakePad_Worn_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_BrakePad_Worn_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_BrakePad_Worn_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_BrakePad_Worn_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_BrakePad_Worn_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_BrakePad_Worn_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_BrakePad_Worn_ENABLE	1

#else
	#define TT_BrakePad_Worn_ENABLE  0
#endif

void FTT_vRBS_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8RBS_Config_Byte17 = 0;
	uint8 u8RBS_Received = RTE_E_INVALID;
	uint8 u8RBS_TgtRcptnSts = 0;
	uint8 u8RBS_Config_Byte2 = 0;
	uint8 u8RBS_Config_Byte30 = 0;
	uint8 u8RBS_Config_Byte91 = 0;
	uint8 u8RBS_Enable_Case = RBS_DISABLE;

	TT_SET_CFG(enFTT_RBS,ON);

	u8RBS_Config_Byte17 = FTT_Adapt_GetVconfig(VCONFIG_KIND_BRAKING_ENERGY_RECOVERY);
	u8RBS_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8RBS_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	u8RBS_Config_Byte91 = FTT_Adapt_GetVconfig(VCONFIG_KIND_IBOOSTER_CONFIG);

	if(TT_BrakePad_Worn_ENABLE)
	{
		if((1 == u8RBS_Config_Byte17) || (2 == u8RBS_Config_Byte17))
		{
			if ((1 == u8RBS_Config_Byte30) && ((0 == u8RBS_Config_Byte2) \
				|| (1 == u8RBS_Config_Byte2) || (2 == u8RBS_Config_Byte2) \
				|| (7 == u8RBS_Config_Byte2)))
			{
				u8RBS_Enable_Case = RBS_ENABLE_CASE1;
			}
			else if ((3 == u8RBS_Config_Byte2) && ((2 == u8RBS_Config_Byte30) \
				|| (4 == u8RBS_Config_Byte30) || (5 == u8RBS_Config_Byte30) \
				|| (6 == u8RBS_Config_Byte30) || (8 == u8RBS_Config_Byte30)))
			{
				if (2 == u8RBS_Config_Byte91)
				{
					u8RBS_Enable_Case = RBS_ENABLE_CASE2;
				}
				else if (1 == u8RBS_Config_Byte91)
				{
					u8RBS_Enable_Case = RBS_ENABLE_CASE3;
				}
				else
				{
					u8RBS_Enable_Case = RBS_DISABLE;
				}
			}
			else if ((4 == u8RBS_Config_Byte2) || (5 == u8RBS_Config_Byte2) \
				|| (8 == u8RBS_Config_Byte2) || (9 == u8RBS_Config_Byte2) \
				|| (10 == u8RBS_Config_Byte2))
			{
				if (2 == u8RBS_Config_Byte91)
				{
					u8RBS_Enable_Case = RBS_ENABLE_CASE2;
				}
				else if (1 == u8RBS_Config_Byte91)
				{
					u8RBS_Enable_Case = RBS_ENABLE_CASE3;
				}
				else
				{
					u8RBS_Enable_Case = RBS_DISABLE;
				}
			}
			else
			{
				u8RBS_Enable_Case = RBS_DISABLE;
			}
		}
		else
		{
			u8RBS_Enable_Case = RBS_DISABLE;
		}

		switch(u8RBS_Enable_Case)
		{
		case RBS_ENABLE_CASE1 :
			u8RBS_Received = FTT_Adapt_GetMessage_HCU_TgtRcprtnTrqSts(&u8RBS_TgtRcptnSts);
			break;
		case RBS_ENABLE_CASE2 :
			u8RBS_Received = FTT_Adapt_GetMessage_ESP_TgtRcprtnTrqSts(&u8RBS_TgtRcptnSts);
			break;
		case RBS_ENABLE_CASE3 :
			u8RBS_Received = FTT_Adapt_GetMessage_EB_TgtRcprtnTrqSts(&u8RBS_TgtRcptnSts);
			break;
		default:
			// Static compilation: if the default clause is empty, comments must be added.
			break;
		}

		if (u8RBS_Enable_Case != RBS_DISABLE)
		{
			TT_SET_DID(enFTT_RBS,ON);
			if ((u8RBS_Received == RTE_E_OK) && (u8RBS_TgtRcptnSts == TT_FUN_STANDBY))
			{
				TT_SET(enFTT_RBS,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_RBS,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_RBS,TT_enTURN_OFF);
			TT_SET_DID(enFTT_RBS,OFF);
		}
	}

}

/*******************************************************************************
*	Function name		: FTT_vEngine_Warmup_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Engine_Warmup_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Engine_Warmup_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Engine_Warmup_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Engine_Warmup_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Engine_Warmup_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Engine_Warmup_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Engine_Warmup_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Engine_Warmup_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Engine_Warmup_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Engine_Warmup_ENABLE	1

#else
	#define TT_Engine_Warmup_ENABLE  0
#endif

void FTT_vEngine_Warmup_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Engine_Warmup_Config_Byte2 = 0;
	uint8 u8EngineWarmup_Received = RTE_E_INVALID;
	uint8 u8EngineWarmup_GlowPlugLmpCmd = 0;
	TT_SET_CFG(enFTT_Engine_Warmup,ON);

	u8Engine_Warmup_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8EngineWarmup_Received = FTT_Adapt_GetMessage_GlowPlugLmpCmd(&u8EngineWarmup_GlowPlugLmpCmd);

	if(TT_Engine_Warmup_ENABLE)
	{
		if(u8Engine_Warmup_Config_Byte2 == 0)
		{
			TT_SET_DID(enFTT_Engine_Warmup,ON);
			if(u8EngineWarmup_Received == RTE_E_OK)
			{
				if(u8EngineWarmup_GlowPlugLmpCmd == 1)
				{
					TT_SET(enFTT_Engine_Warmup,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Engine_Warmup,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_Engine_Warmup,TT_enTURN_ON);
			}
		}
		else
		{
			TT_SET_DID(enFTT_Engine_Warmup,OFF);
			TT_SET(enFTT_Engine_Warmup,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vCCO_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_CCO_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_CCO_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_CCO_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_CCO_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_CCO_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_CCO_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_CCO_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_CCO_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_CCO_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_CCO_ENABLE	1

#else
	#define TT_CCO_ENABLE  0
#endif

void FTT_vCCO_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8CCO_Config_Byte25 = 0;
	uint8 u8CCO_Received = RTE_E_INVALID;
	uint8 u8CCO_Active = 0;

	TT_SET_CFG(enFTT_CCO_Active,ON);
	TT_SET_CFG(enFTT_CCO_Standby,ON);
	TT_SET_CFG(enFTT_CCO_Inactive,ON);
	TT_SET_DID(enFTT_CCO_Active,OFF);
	TT_SET_DID(enFTT_CCO_Standby,OFF);
	TT_SET_DID(enFTT_CCO_Inactive,OFF);

	u8CCO_Config_Byte25 = FTT_Adapt_GetVconfig(VCONFIG_KIND_OFF_ROAD_CRUISE_CONTROL);
	u8CCO_Received = FTT_Adapt_GetMessage_CCO_Active(&u8CCO_Active);

	if(TT_CCO_ENABLE)
	{
		if ((1 == u8CCO_Config_Byte25) || (2 == u8CCO_Config_Byte25))
		{
			if (u8CCO_Received == RTE_E_OK)
			{
				if (u8CCO_Active == TT_FUN_ACTIVE)
				{
					TT_SET(enFTT_CCO_Active,TT_enTURN_ON);
					TT_SET(enFTT_CCO_Standby,TT_enTURN_OFF);
					TT_SET(enFTT_CCO_Inactive,TT_enTURN_OFF);
				}
				else if (u8CCO_Active == TT_FUN_STANDBY)
				{
					TT_SET(enFTT_CCO_Active,TT_enTURN_OFF);
					TT_SET(enFTT_CCO_Standby,TT_enTURN_ON);
					TT_SET(enFTT_CCO_Inactive,TT_enTURN_OFF);
				}
				else if (u8CCO_Active == TT_FUN_RESERVE)
				{
					TT_SET(enFTT_CCO_Active,TT_enTURN_OFF);
					TT_SET(enFTT_CCO_Standby,TT_enTURN_OFF);
					TT_SET(enFTT_CCO_Inactive,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_CCO_Active,TT_enTURN_OFF);
					TT_SET(enFTT_CCO_Standby,TT_enTURN_OFF);
					TT_SET(enFTT_CCO_Inactive,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_CCO_Active,TT_enTURN_OFF);
				TT_SET(enFTT_CCO_Standby,TT_enTURN_OFF);
				TT_SET(enFTT_CCO_Inactive,TT_enTURN_OFF);
			}

		}
		else
		{
			TT_SET(enFTT_CCO_Active,TT_enTURN_OFF);
			TT_SET(enFTT_CCO_Standby,TT_enTURN_OFF);
			TT_SET(enFTT_CCO_Inactive,TT_enTURN_OFF);
		}
	}

}

/*******************************************************************************
*	Function name		: FTT_vFEDL_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_FEDL_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_FEDL_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_FEDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_FEDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_FEDL_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_FEDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_FEDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_FEDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_FEDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_FEDL_ENABLE	1

#else
	#define TT_FEDL_ENABLE  0
#endif

void FTT_vFEDL_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8FEDL_Config_Byte28 = 0;
	uint8 u8FEDL_Received = RTE_E_INVALID;
	uint8 u8FEDL_FLckSts = 0;

	TT_SET_CFG(enFTT_FEDL_Active,ON);
	TT_SET_CFG(enFTT_FEDL_Inactive,ON);
	TT_SET_DID(enFTT_FEDL_Active,OFF);
	TT_SET_DID(enFTT_FEDL_Inactive,OFF);

	u8FEDL_Config_Byte28 = FTT_Adapt_GetVconfig(VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL);
	u8FEDL_Received = FTT_Adapt_GetMessage_FrntELDLckSts(&u8FEDL_FLckSts);

	if(TT_FEDL_ENABLE)
	{
		if ((2 == u8FEDL_Config_Byte28) || (4 == u8FEDL_Config_Byte28))
		{
			if (u8FEDL_Received == RTE_E_OK)
			{
				if (u8FEDL_FLckSts == TT_FEDL_LOCKED)
				{
					TT_SET(enFTT_FEDL_Active,TT_enTURN_ON);
					TT_SET(enFTT_FEDL_Inactive,TT_enTURN_OFF);
				}
				else if (u8FEDL_FLckSts == TT_FEDL_OVERSPEED)
				{
					TT_SET(enFTT_FEDL_Active,TT_enFLASH_1_HZ);
					TT_SET(enFTT_FEDL_Inactive,TT_enTURN_OFF);
				}
				else if (u8FEDL_FLckSts == TT_FEDL_FAULT)
				{
					TT_SET(enFTT_FEDL_Active,TT_enTURN_OFF);
					TT_SET(enFTT_FEDL_Inactive,TT_enTURN_ON);
				}
				else if (u8FEDL_FLckSts == TT_FEDL_LOCK_DENY)
				{
					TT_SET(enFTT_FEDL_Inactive,TT_enFLASH_1_HZ);
					TT_SET(enFTT_FEDL_Active,TT_enTURN_OFF);
				}
				else
				{
					TT_SET(enFTT_FEDL_Active,TT_enTURN_OFF);
					TT_SET(enFTT_FEDL_Inactive,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_FEDL_Active,TT_enTURN_OFF);
				TT_SET(enFTT_FEDL_Inactive,TT_enTURN_ON);
			}
		}
		else
		{
			TT_SET(enFTT_FEDL_Active,TT_enTURN_OFF);
			TT_SET(enFTT_FEDL_Inactive,TT_enTURN_OFF);
		}
	}

}


/*******************************************************************************
*	Function name		: FTT_vREDL_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_REDL_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_REDL_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_REDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_REDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_REDL_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_REDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_REDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_REDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_REDL_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_REDL_ENABLE	1

#else
	#define TT_REDL_ENABLE  0
#endif

void FTT_vREDL_Handle_Process(TT_tstMainObject* stMainObject)
{

	uint8 u8FEDL_Config_Byte28 = 0;
	uint8 u8FEDL_Received = RTE_E_INVALID;
	uint8 u8FEDL_RLckSts = 0;

	TT_SET_CFG(enFTT_REDL_Active,ON);
	TT_SET_CFG(enFTT_REDL_Inactive,ON);
	TT_SET_DID(enFTT_REDL_Active,OFF);
	TT_SET_DID(enFTT_REDL_Inactive,OFF);

	u8FEDL_Config_Byte28 = FTT_Adapt_GetVconfig(VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL);
	u8FEDL_Received = FTT_Adapt_GetMessage_RearELDLckSts(&u8FEDL_RLckSts);

	if(TT_REDL_ENABLE)
	{
		if ((3 == u8FEDL_Config_Byte28) || (4 == u8FEDL_Config_Byte28))
		{
			if (u8FEDL_Received == RTE_E_OK)
			{
				if (u8FEDL_RLckSts == TT_FEDL_LOCKED)
				{
					TT_SET(enFTT_REDL_Active,TT_enTURN_ON);
					TT_SET(enFTT_REDL_Inactive,TT_enTURN_OFF);
				}
				else if (u8FEDL_RLckSts == TT_FEDL_OVERSPEED)
				{
					TT_SET(enFTT_REDL_Active,TT_enFLASH_1_HZ);
					TT_SET(enFTT_REDL_Inactive,TT_enTURN_OFF);
				}
				else if (u8FEDL_RLckSts == TT_FEDL_FAULT)
				{
					TT_SET(enFTT_REDL_Active,TT_enTURN_OFF);
					TT_SET(enFTT_REDL_Inactive,TT_enTURN_ON);
				}
				else if (u8FEDL_RLckSts == TT_FEDL_LOCK_DENY)
				{
					TT_SET(enFTT_REDL_Inactive,TT_enFLASH_1_HZ);
					TT_SET(enFTT_REDL_Active,TT_enTURN_OFF);

				}
				else
				{
					TT_SET(enFTT_REDL_Active,TT_enTURN_OFF);
					TT_SET(enFTT_REDL_Inactive,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_REDL_Active,TT_enTURN_OFF);
				TT_SET(enFTT_REDL_Inactive,TT_enTURN_ON);
			}
		}
		else
		{
			TT_SET(enFTT_REDL_Active,TT_enTURN_OFF);
			TT_SET(enFTT_REDL_Inactive,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vAUX_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_AUX_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_AUX_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_AUX_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_AUX_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_AUX_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_AUX_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_AUX_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_AUX_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_AUX_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_AUX_ENABLE	1

#else
	#define TT_REDL_ENABLE  0
#endif

void FTT_vAUX_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8AUX_Config_Byte14 = 0;
	uint8 u8AUX_Received = RTE_E_INVALID;
	uint8 u8AUX_CTA_Actv = 0;
	uint8 u8AUX_LCAResp = 0;
	uint8 u8SAS_Handle_Status = 0;

	TT_SET_CFG(enFTT_AUX,ON);
	TT_SET_DID(enFTT_AUX,OFF);

	u8AUX_Config_Byte14 = FTT_Adapt_GetVconfig(VCONFIG_KIND_LANE_CHANGE_ASSIST);
	u8AUX_Received = FTT_Adapt_GetMessage_RSDS_CTA_Actv(&u8AUX_CTA_Actv);
	(void)FTT_Adapt_GetMessage_RSDS_LCAResp(&u8AUX_LCAResp);
	u8SAS_Handle_Status = Get_vSAS_Handle_Status();

	if(TT_AUX_ENABLE)
	{
		if ((1 == u8AUX_Config_Byte14) && (u8SAS_Handle_Status != 1))
		{
			if (u8AUX_Received == RTE_E_OK)
			{
				if ((u8AUX_LCAResp == TT_FUN_ACTIVE) && (u8AUX_CTA_Actv == TT_FUN_INACTIVE))
				{
					TT_SET(enFTT_AUX,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_AUX,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_AUX,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_AUX,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vRSW_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_RSW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_RSW_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_RSW_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_RSW_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_RSW_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_RSW_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_RSW_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_RSW_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_RSW_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_RSW_ENABLE	1

#else
	#define TT_RSW_ENABLE  0
#endif

void FTT_vRSW_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8RSW_Config_Byte20 = 0;
	uint8 u8RSW_Received = RTE_E_INVALID;
	uint8 u8RSW_CTA_Actv = 0;
	uint8 u8SAS_Handle_Status = 0;
	TT_SET_CFG(enFTT_RSW,ON);
	TT_SET_DID(enFTT_RSW,OFF);

	u8RSW_Config_Byte20 = FTT_Adapt_GetVconfig(VCONFIG_KIND_PAS_CTA);
	u8RSW_Received = FTT_Adapt_GetMessage_RSDS_CTA_Actv(&u8RSW_CTA_Actv);
	u8SAS_Handle_Status = Get_vSAS_Handle_Status();

	if(TT_RSW_ENABLE)
	{
		if (((2 == u8RSW_Config_Byte20) || (3 == u8RSW_Config_Byte20) || (4 == u8RSW_Config_Byte20) || (5 == u8RSW_Config_Byte20))\
			&& (u8SAS_Handle_Status != 1))
		{
			if (u8RSW_Received == RTE_E_OK)
			{
				if (u8RSW_CTA_Actv == TT_FUN_ACTIVE)
				{
					TT_SET(enFTT_RSW,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_RSW,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_RSW,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_RSW,TT_enTURN_OFF);
		}
	}

}


/*******************************************************************************
*	Function name		: FTT_vSAS_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_SAS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_SAS_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_SAS_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_SAS_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_SAS_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_SAS_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_SAS_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_SAS_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_SAS_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_SAS_ENABLE	1

#else
	#define TT_SAS_ENABLE  0
#endif

void FTT_vSAS_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8SAS_Config_Byte14 = 0;
	uint8 u8SAS_Received = RTE_E_INVALID;
	uint8 u8SAS_BCM8_Received = RTE_E_INVALID;
	uint8 u8SAS_ErrSts = 0;
	uint8 u8SAS_BliSts = 0;
	uint8 u8SAS_RemoteModSts = 0;
	uint8 u8SAS_KL30BRelaySts = 0;
	uint8 u8IgnSts = 0;

	TT_SET_CFG(enFTT_SAS_Error,ON);
	TT_SET_CFG(enFTT_SAS_Limit,ON);
	TT_SET_DID(enFTT_SAS_Error,OFF);
	TT_SET_DID(enFTT_SAS_Limit,OFF);

	u8IgnSts = FTT_Adapt_GetPowerMode_State();
	u8SAS_Config_Byte14 = FTT_Adapt_GetVconfig(VCONFIG_KIND_LANE_CHANGE_ASSIST);
	u8SAS_Received = FTT_Adapt_GetMessage_RSDS_ErrSts(&u8SAS_ErrSts);
	u8SAS_BCM8_Received = FTT_Adapt_GetMessage_RemoteModSts(&u8SAS_RemoteModSts);
	(void)FTT_Adapt_GetMessage_RSDS_BliSts(&u8SAS_BliSts);
	(void)FTT_Adapt_GetMessage_KL30BRelaySts(&u8SAS_KL30BRelaySts);

	if(TT_SAS_ENABLE)
	{
		if (1 == u8SAS_Config_Byte14)
		{
			if (u8SAS_Received == RTE_E_OK)
			{
				if (u8SAS_ErrSts == TT_FUN_ACTIVE)
				{
					TT_SET(enFTT_SAS_Error,TT_enTURN_ON);
					TT_SET(enFTT_SAS_Limit,TT_enTURN_OFF);
				}
				else if ((u8SAS_ErrSts == TT_FUN_INACTIVE) && (u8SAS_BliSts == TT_FUN_ACTIVE))
				{
					TT_SET(enFTT_SAS_Error,TT_enTURN_OFF);
					TT_SET(enFTT_SAS_Limit,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_SAS_Error,TT_enTURN_OFF);
					TT_SET(enFTT_SAS_Limit,TT_enTURN_OFF);
				}
				if(u8IgnSts != SYSTEMSTATE_Cluster_ON)	//fix B04-677
				{
					if((u8SAS_ReceivedPre != RTE_E_OK) && (u8SAS_ReceivedTime < 3))
					{
						TT_SET(enFTT_SAS_Error,TT_enTURN_OFF);
						TT_SET(enFTT_SAS_Limit,TT_enTURN_OFF);
						u8SAS_ReceivedTime ++;
					}
				}
				else
				{
					u8SAS_ReceivedPre = u8SAS_Received;
				}
			}
			else
			{
				if(u8IgnSts == SYSTEMSTATE_Cluster_ON)
				{
					if ((u8SAS_BCM8_Received == RTE_E_OK) && \
						((0 == u8SAS_RemoteModSts) || (1 == u8SAS_KL30BRelaySts)))
					{
						TT_SET(enFTT_SAS_Error,TT_enTURN_ON);
						TT_SET(enFTT_SAS_Limit,TT_enTURN_OFF);
					}
					else
					{
						TT_SET(enFTT_SAS_Error,TT_enTURN_OFF);
						TT_SET(enFTT_SAS_Limit,TT_enTURN_OFF);
					}
					u8SAS_ReceivedTime = 0;
					u8SAS_ReceivedPre = u8SAS_Received;
				}
				else
				{
					TT_SET(enFTT_SAS_Error,TT_enTURN_OFF);
					TT_SET(enFTT_SAS_Limit,TT_enTURN_OFF);
				}
			}
		}
		else
		{
			TT_SET(enFTT_SAS_Error,TT_enTURN_OFF);
			TT_SET(enFTT_SAS_Limit,TT_enTURN_OFF);
		}
	}
}




/*******************************************************************************
*	Function name		: FTT_vSteer_Assit_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Steer_Assit_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Steer_Assit_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Steer_Assit_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Steer_Assit_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Steer_Assit_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Steer_Assit_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Steer_Assit_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Steer_Assit_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Steer_Assit_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Steer_Assit_ENABLE	1

#else
	#define TT_Steer_Assit_ENABLE  0
#endif

void FTT_vSteer_Assit_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Steer_Config_Byte44 = 0;
	uint8 u8Steer_Received = RTE_E_INVALID;
	uint8 u8Steer_TAB_Sts = 0;

	TT_SET_CFG(enFTT_Steer_Assit_Open,ON);
	TT_SET_CFG(enFTT_Steer_Assit_Work,ON);
	TT_SET_CFG(enFTT_Steer_Assit_Error,ON);

	TT_SET_DID(enFTT_Steer_Assit_Open,OFF);
	TT_SET_DID(enFTT_Steer_Assit_Work,OFF);
	TT_SET_DID(enFTT_Steer_Assit_Error,OFF);

	u8Steer_Config_Byte44 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TAB);
	u8Steer_Received = FTT_Adapt_GetMessage_TAB_Sts(&u8Steer_TAB_Sts);

	if(TT_Steer_Assit_ENABLE)
	{
		if (1 == u8Steer_Config_Byte44)
		{
			if (u8Steer_Received == RTE_E_OK)
			{
				if (u8Steer_TAB_Sts == TT_STEER_STANDBY)
				{
					TT_SET(enFTT_Steer_Assit_Open,TT_enTURN_ON);
					TT_SET(enFTT_Steer_Assit_Work,TT_enTURN_OFF);
					TT_SET(enFTT_Steer_Assit_Error,TT_enTURN_OFF);
				}
				else if (u8Steer_TAB_Sts == TT_STEER_ACTIVE)
				{
					TT_SET(enFTT_Steer_Assit_Open,TT_enTURN_OFF);
					TT_SET(enFTT_Steer_Assit_Work,TT_enTURN_ON);
					TT_SET(enFTT_Steer_Assit_Error,TT_enTURN_OFF);
				}
				else if (u8Steer_TAB_Sts == TT_STEER_FAILURE)
				{
					TT_SET(enFTT_Steer_Assit_Open,TT_enTURN_OFF);
					TT_SET(enFTT_Steer_Assit_Work,TT_enTURN_OFF);
					TT_SET(enFTT_Steer_Assit_Error,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Steer_Assit_Open,TT_enTURN_OFF);
					TT_SET(enFTT_Steer_Assit_Work,TT_enTURN_OFF);
					TT_SET(enFTT_Steer_Assit_Error,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_Steer_Assit_Open,TT_enTURN_OFF);
				TT_SET(enFTT_Steer_Assit_Work,TT_enTURN_OFF);
				TT_SET(enFTT_Steer_Assit_Error,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Steer_Assit_Open,TT_enTURN_OFF);
			TT_SET(enFTT_Steer_Assit_Work,TT_enTURN_OFF);
			TT_SET(enFTT_Steer_Assit_Error,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: FTT_vSound_Reminder_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Sound_Reminder_PHEVExt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Sound_Reminder_PHEVExt_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Sound_Reminder_PHEVExt_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Sound_Reminder_PHEVExt_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Sound_Reminder_PHEVExt_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Sound_Reminder_PHEVExt_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Sound_Reminder_PHEVExt_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Sound_Reminder_PHEVExt_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Sound_Reminder_PHEVExt_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Sound_Reminder_PHEVExt_ENABLE	0

#else
	#define TT_Sound_Reminder_PHEVExt_ENABLE  0
#endif

void FTT_vSound_Reminder_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Sound_BulVsgSts = 0;
	uint8 u8Sound_Config_Byte2 = 0;
	uint8 u8Sound_Config_Byte30 = 0;
	uint8 u8Sound_Config_Byte67 = 0;

	TT_SET_CFG(enFTT_Sound_Reminder_Red,ON);
	TT_SET_CFG(enFTT_Sound_Reminder_Yellow,ON);
	TT_SET_DID(enFTT_Sound_Reminder_Red,OFF);
	TT_SET_DID(enFTT_Sound_Reminder_Yellow,OFF);

	u8Sound_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8Sound_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	u8Sound_Config_Byte67 = FTT_Adapt_GetVconfig(VCONFIG_KIND_VSG_TYPE);
	(void)FTT_Adapt_GetMessage_Builtin_VSG_Sts(&u8Sound_BulVsgSts);

	if(TT_Sound_Reminder_PHEVExt_ENABLE)
	{
		if ((2 == u8Sound_Config_Byte67)
			&& (((4 == u8Sound_Config_Byte2) && ((2 == u8Sound_Config_Byte30) || (4 == u8Sound_Config_Byte30) \
			|| (5 == u8Sound_Config_Byte30) || (6 == u8Sound_Config_Byte30) || (8 == u8Sound_Config_Byte30))) \
			|| ((10 == u8Sound_Config_Byte2) && ((2 == u8Sound_Config_Byte30) || (4 == u8Sound_Config_Byte30) \
			|| (8 == u8Sound_Config_Byte30)))))
		{
			if(TT_BUL_VSG_ON == u8Sound_BulVsgSts)
			{
				TT_SET(enFTT_Sound_Reminder_Red,TT_enTURN_OFF);
				TT_SET(enFTT_Sound_Reminder_Yellow,TT_enTURN_ON);
			}
			else if (TT_BUL_VSG_FAIL == u8Sound_BulVsgSts)
			{
				TT_SET(enFTT_Sound_Reminder_Red,TT_enTURN_ON);
				TT_SET(enFTT_Sound_Reminder_Yellow,TT_enTURN_OFF);
			}
			else
			{
				TT_SET(enFTT_Sound_Reminder_Red,TT_enTURN_OFF);
				TT_SET(enFTT_Sound_Reminder_Yellow,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Sound_Reminder_Red,TT_enTURN_OFF);
			TT_SET(enFTT_Sound_Reminder_Yellow,TT_enTURN_OFF);
		}
	}

}


/*******************************************************************************
*	Function name		: FTT_vBatteryPack_Charge_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_BatteryPack_Charge_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_BatteryPack_Charge_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_BatteryPack_Charge_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_BatteryPack_Charge_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_BatteryPack_Charge_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_BatteryPack_Charge_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_BatteryPack_Charge_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_BatteryPack_Charge_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_BatteryPack_Charge_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_BatteryPack_Charge_ENABLE	0

#else
	#define TT_BatteryPack_Charge_ENABLE  0
#endif

void FTT_vBatteryPack_Charge_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Battery_Config_Byte2 = 0;
	//uint8 u8Battery_OBC_Received = RTE_E_INVALID;
	//uint8 u8Battery_ModSts = 0;

	TT_SET_CFG(enFTT_BatteryPack_Charge,ON);
	TT_SET_DID(enFTT_BatteryPack_Charge,OFF);

	u8Battery_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);

	if(TT_BatteryPack_Charge_ENABLE)
	{
		if (5 == u8Battery_Config_Byte2)
		{
			//if ((TT_CFG_CAN_BMS_FD10_HAS_RECEIVED) && (TT_CFG_CAN_CONDITION_BMS_CHARGE_TURN_ON))
			//{
			//	TT_SET(enFTT_BatteryPack_Charge,TT_enTURN_ON);
			//}
			//else if ((u8Battery_OBC_Received) && ((u8Battery_ModSts == TT_BMS_CHARGING) || (u8Battery_ModSts == TT_BMS_REDUCED_POWER)))
			//{
			//	TT_SET(enFTT_BatteryPack_Charge,TT_enTURN_ON);
			//}
			//else
			//{
			//	TT_SET(enFTT_BatteryPack_Charge,TT_enTURN_OFF);
			//}
		}
		else
		{
			TT_SET(enFTT_BatteryPack_Charge,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vBattery_Off_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		: EV
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Battery_Off_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Battery_Off_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Battery_Off_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Battery_Off_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Battery_Off_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Battery_Off_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Battery_Off_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Battery_Off_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Battery_Off_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Battery_Off_ENABLE	0

#else
	#define TT_Battery_Off_ENABLE  0
#endif

void FTT_vBattery_Off_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8BatteryOff_Config_Byte2 = 0;

	TT_SET_CFG(enFTT_Battery_Off,ON);

	u8BatteryOff_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	//config is ok ,signal BMS_FD10 miss
	if(TT_Battery_Off_ENABLE)
	{
		if (5 == u8BatteryOff_Config_Byte2)
		{
			TT_SET_DID(enFTT_Battery_Off,ON);
			//if ((TT_CFG_CAN_BMS_FD10_HAS_RECEIVED) && (TT_CFG_CAN_CONDITION_BMS_SAFETY_STS_TURN_ON == TT_FUN_INACTIVE))
			//{
			//	TT_SET(enFTT_Battery_Off,TT_enTURN_ON);
			//}

			//else
			//{
			//	TT_SET(enFTT_Battery_Off,TT_enTURN_OFF);
			//}
		}
		else
		{
			TT_SET(enFTT_Battery_Off,TT_enTURN_OFF);

			TT_SET_DID(enFTT_Battery_Off,OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vLow_Battery_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Low_Battery_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Low_Battery_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Low_Battery_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Low_Battery_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Low_Battery_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Low_Battery_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Low_Battery_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Low_Battery_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Low_Battery_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Low_Battery_ENABLE	0

#else
	#define TT_Low_Battery_ENABLE  0
#endif

void FTT_vLow_Battery_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8LowBat_Config_Byte2 = 0;
	uint8 u8LowBat_Config_Byte30 = 0;
	uint8 u8LowBat_Received = RTE_E_INVALID;
	uint8 u8LowBat_BMS_SOCLowWarn = 0;

	TT_SET_CFG(enFTT_Low_Battery,ON);
	TT_SET_DID(enFTT_Low_Battery,OFF);

	u8LowBat_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8LowBat_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	u8LowBat_Received = FTT_Adapt_GetMessage_SOCLowWarn(&u8LowBat_BMS_SOCLowWarn);

	if(TT_Low_Battery_ENABLE)
	{
		if ((4 == u8LowBat_Config_Byte2) && ((2 == u8LowBat_Config_Byte30) || (4 == u8LowBat_Config_Byte30) \
			|| (5 == u8LowBat_Config_Byte30) || (6 == u8LowBat_Config_Byte30) || (8 == u8LowBat_Config_Byte30)))
		{
			if (u8LowBat_Received == RTE_E_OK)
			{
				if(u8LowBat_BMS_SOCLowWarn == TT_FUN_ACTIVE)
				{
					TT_SET(enFTT_Low_Battery,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_Low_Battery,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_Low_Battery,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_Low_Battery,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vRSCA_OFF_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_RSCA_OFF_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_RSCA_OFF_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_RSCA_OFF_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_RSCA_OFF_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_RSCA_OFF_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_RSCA_OFF_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_RSCA_OFF_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_RSCA_OFF_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_RSCA_OFF_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_RSCA_OFF_ENABLE	0

#else
	#define TT_RSCA_OFF_ENABLE  0
#endif

void FTT_vRSCA_OFF_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8RSCA_OFF_Config_Byte60 = 0;
	uint8 u8RSCA_Received = RTE_E_INVALID;
	uint8 u8RSCAOFFSts = 0;

	TT_SET_CFG(enFTT_RSCA_Off,ON);
	TT_SET_DID(enFTT_RSCA_Off,OFF);
	u8RSCA_OFF_Config_Byte60 = FTT_Adapt_GetVconfig(VCONFIG_KIND_RSCA_PROTECTION_FUNCTION);
	u8RSCA_Received = FTT_Adapt_GetMessage_RSCAOFFSts(&u8RSCAOFFSts);

	if(TT_RSCA_OFF_ENABLE)
	{
		if(1 == u8RSCA_OFF_Config_Byte60)
		{
			if (RTE_E_OK == u8RSCA_Received)
			{
				if (1 == u8RSCAOFFSts)
				{
					TT_SET(enFTT_RSCA_Off,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_RSCA_Off,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_RSCA_Off,TT_enTURN_ON);
			}
		}
		else
		{
			TT_SET(enFTT_RSCA_Off,TT_enTURN_OFF);
		}
	}
	//TODO: IP 输出CAN 信号始终输出IP_RSCAOFFWarnLmpSts = 0x0
}


/*******************************************************************************
*	Function name		: FTT_v2H4H2L_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:  P01
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_2H4H4L_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_2H4H4L_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_2H4H4L_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_2H4H4L_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_2H4H4L_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_2H4H4L_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_2H4H4L_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_2H4H4L_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_2H4H4L_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_2H4H4L_ENABLE	1

#else
	#define TT_2H4H4L_ENABLE  0
#endif

void FTT_v2H4H4L_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u82H4H4L_Config_Byte30 = 0;

	TT_SET_CFG(enFTT_2H_Indicator,ON);
	TT_SET_CFG(enFTT_4H_Indicator,ON);
	TT_SET_CFG(enFTT_4L_Indicator,ON);
	TT_SET_DID(enFTT_2H_Indicator,OFF);
	TT_SET_DID(enFTT_4H_Indicator,OFF);
	TT_SET_DID(enFTT_4L_Indicator,OFF);

	u82H4H4L_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TRANSFER_CASE);


	//config is ok ,signal is miss
	if(TT_2H4H4L_ENABLE)
	{
		if (1 == u82H4H4L_Config_Byte30)
		{
			if (TT_CFG_CAN_2H4H4L_TOD1_HAS_RECEIVED)
			{
				if (TT_CFG_CAN_CONDITION_SYSTEMOPERMOD_TURN_ON == TT_MODE_2WD)
				{
					TT_SET(enFTT_2H_Indicator,TT_enTURN_ON);
					TT_SET(enFTT_4H_Indicator,TT_enTURN_OFF);
					TT_SET(enFTT_4L_Indicator,TT_enTURN_OFF);

				}
				else if (TT_CFG_CAN_CONDITION_SYSTEMOPERMOD_TURN_ON == TT_MODE_4WD)
				{
					TT_SET(enFTT_2H_Indicator,TT_enTURN_OFF);
					TT_SET(enFTT_4H_Indicator,TT_enTURN_ON);
					TT_SET(enFTT_4L_Indicator,TT_enTURN_OFF);
				}
				else if (TT_CFG_CAN_CONDITION_SYSTEMOPERMOD_TURN_ON == TT_MODE_4WD_LOW)
				{
					TT_SET(enFTT_2H_Indicator,TT_enTURN_OFF);
					TT_SET(enFTT_4H_Indicator,TT_enTURN_OFF);
					TT_SET(enFTT_4L_Indicator,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_2H_Indicator,TT_enTURN_OFF);
					TT_SET(enFTT_4H_Indicator,TT_enTURN_OFF);
					TT_SET(enFTT_4L_Indicator,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_2H_Indicator,TT_enTURN_OFF);
				TT_SET(enFTT_4H_Indicator,TT_enTURN_OFF);
				TT_SET(enFTT_4L_Indicator,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_2H_Indicator,TT_enTURN_OFF);
			TT_SET(enFTT_4H_Indicator,TT_enTURN_OFF);
			TT_SET(enFTT_4L_Indicator,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vSingle_Pedal_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Single_Pedal_PHEV_ENABLE  1
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Single_Pedal_PHEV_ENABLE  1
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Single_Pedal_PHEV_ENABLE	1
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Single_Pedal_PHEV_ENABLE	0
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Single_Pedal_PHEV_ENABLE	1
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Single_Pedal_PHEV_ENABLE	0
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Single_Pedal_PHEV_ENABLE	0
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Single_Pedal_PHEV_ENABLE	0
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Single_Pedal_PHEV_ENABLE	0
	#define TT_Single_Pedal_EV_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Single_Pedal_PHEV_ENABLE	0
	#define TT_Single_Pedal_EV_ENABLE	0

#else
	#define TT_Single_Pedal_PHEV_ENABLE  0
	#define TT_Single_Pedal_EV_ENABLE	0
#endif

void FTT_vSingle_Pedal_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Single_Config_Byte2 = 0;
	uint8 u8Single_Config_Byte30 = 0;
	uint8 u8Single_Config_Byte53 = 0;
	uint8 u8Single_HCU_Received = RTE_E_INVALID;
	uint8 u8Single_OPDLmpSts = 0;
	TT_SET_CFG(enFTT_Single_Pedal,ON);

	u8Single_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8Single_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	u8Single_Config_Byte53 = FTT_Adapt_GetVconfig(VCONFIG_KIND_PEDAL_CONTROL);
	u8Single_HCU_Received = FTT_Adapt_GetMessage_OPDLmpSts(&u8Single_OPDLmpSts);

	if(TT_Single_Pedal_PHEV_ENABLE)//Mix
	{
		if ((1 == u8Single_Config_Byte53) && (((3 == u8Single_Config_Byte2) \
			&& ((2 == u8Single_Config_Byte30) || (5 == u8Single_Config_Byte30) || (6 == u8Single_Config_Byte30))) \
			|| ((4 == u8Single_Config_Byte2) && ((2 == u8Single_Config_Byte30) \
			|| (4 == u8Single_Config_Byte30) || (5 == u8Single_Config_Byte30) \
			|| (6 == u8Single_Config_Byte30)))))
		{
			if ((u8Single_HCU_Received == RTE_E_OK) && (u8Single_OPDLmpSts == 1))
			{

				TT_SET(enFTT_Single_Pedal,TT_enTURN_ON);
			}
			else
			{
				TT_SET(enFTT_Single_Pedal,TT_enTURN_OFF);
			}
		}
	}

	if(TT_Single_Pedal_EV_ENABLE)//EV + Single pedal
	{
		if ((5 == u8Single_Config_Byte2) && (1 == u8Single_Config_Byte53))
		{
			//signal miss
			TT_SET_DID(enFTT_Single_Pedal,ON);
		}
		else
		{
			TT_SET(enFTT_Single_Pedal,TT_enTURN_OFF);

			TT_SET_DID(enFTT_Single_Pedal,OFF);
		}
	}

}



/*******************************************************************************
*	Function name		: FTT_v120KMH_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_120KMH_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_120KMH_ENABLE  1

#else
	#define TT_120KMH_ENABLE  0
#endif

void FTT_v120KMH_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Speed120_Limit_Config_Byte32 = 0;
	boolean bSpeedflag = FALSE;
	TT_SET_CFG(enFTT_120KMH,ON);

	u8Speed120_Limit_Config_Byte32 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SPEEDOMETER);
	(void)FTT_Adapt_GetOverSpdWrnFlg(&bSpeedflag);

	if(TT_120KMH_ENABLE)
	{
		if((bSpeedflag == TRUE) && (u8Speed120_Limit_Config_Byte32 == 1))
		{
			TT_SET(enFTT_120KMH,TT_enFLASH_1_HZ);
		}
		else
		{
			TT_SET(enFTT_120KMH,TT_enTURN_OFF);
		}
	}
}



/*******************************************************************************
*	Function name		: FTT_vTSR_Handle_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_TSR_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_TSR_ENABLE  1

#else
	#define TT_TSR_ENABLE  0
#endif


void FTT_vTSR_Handle_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8TSR_Received = RTE_E_INVALID;
	uint8 u8TSR_Config_Byte2 = 0;
	uint8 u8TSR_Sts = 0;
	uint8 u8TSR_SpdLimSts = 0;
	uint8 u8TSR_SpdLim = 0;
	uint8 u8TSR_SpdLimWarn = 0;
	uint8 u8TSR_TrfcSignVal = 0;
	uint8 u8Speed120_Config_Byte32 = 0;
	boolean bSpeedflag = FALSE;
	TT_SET_CFG(enFTT_TSR_Speed_Limit,ON);
	TT_SET_CFG(enFTT_TSR_Traffic_Sign,ON);
	TT_SET_DID(enFTT_TSR_Speed_Limit,OFF);
	TT_SET_DID(enFTT_TSR_Traffic_Sign,OFF);

	(void)FTT_Adapt_GetOverSpdWrnFlg(&bSpeedflag);
	u8TSR_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TRAFFIC_SIGN_WARNING);
	u8Speed120_Config_Byte32 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SPEEDOMETER);
	u8TSR_Received = FTT_Adapt_GetMessage_TSRSts(&u8TSR_Sts);
	(void)FTT_Adapt_GetMessage_TSRSpdLimSts(&u8TSR_SpdLimSts);
	(void)FTT_Adapt_GetMessage_TSRSpdLim(&u8TSR_SpdLim);
	(void)FTT_Adapt_GetMessage_TSRSpdLimWarn(&u8TSR_SpdLimWarn);
	(void)FTT_Adapt_GetMessage_TSRTrfcSignVal(&u8TSR_TrfcSignVal);

	if(TT_TSR_ENABLE)
	{
		if ((1 == u8TSR_Config_Byte2) || (2 == u8TSR_Config_Byte2) || (3 == u8TSR_Config_Byte2) || (4 == u8TSR_Config_Byte2))
		{
			if (u8TSR_Received == RTE_E_OK)
			{
				if ((u8TSR_Sts == TT_TSR_STS_FUSION) || (u8TSR_Sts == TT_TSR_STS_VISION) || (u8TSR_Sts == TT_TSR_STS_NAVIGATION_ONLY))
				{
					if((!bSpeedflag) || (u8Speed120_Config_Byte32 != 1))
					{
						if ((u8TSR_SpdLimSts == TT_TSR_SPEED_LIMIT) && (u8TSR_SpdLimWarn == TT_TSR_STS_OFF))
						{
							if ((u8TSR_SpdLim > 0) && (u8TSR_SpdLim <= 30))
							{
								tsr_value.u8TSR_Speed_Limit_Value = u8TSR_SpdLim;
								TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_ON);
							}
							else
							{
								tsr_value.u8TSR_Speed_Limit_Value = u8TSR_SpdLim;
								TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_OFF);
							}
						}
						else if ((u8TSR_SpdLimSts == TT_TSR_SPEED_LIMIT) && (u8TSR_SpdLimWarn == TT_TSR_SPEED_LIMIT_WARN))
						{
							if ((u8TSR_SpdLim > 0) && (u8TSR_SpdLim <= 30))
							{
								tsr_value.u8TSR_Speed_Limit_Value = u8TSR_SpdLim;
								TT_SET(enFTT_TSR_Speed_Limit,TT_enFLASH_1_HZ);
							}
							else
							{
								tsr_value.u8TSR_Speed_Limit_Value = u8TSR_SpdLim;
								TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_OFF);
							}

						}
						else if (u8TSR_SpdLimSts == TT_TSR_SPEED_LIMIT_CANCEL)
						{
							TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_ON);
							tsr_value.u8TSR_Speed_Limit_Value = 31;
						}
						else if (u8TSR_SpdLimSts == TT_TSR_SPEED_LIMIT_NONE)	//R15 add
						{
							TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_ON);
							tsr_value.u8TSR_Speed_Limit_Value = 32;
						}
						else
						{
							TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_OFF);
						}
					}
					else
					{
						TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_OFF);
					}

					if((u8TSR_TrfcSignVal > 0) && (u8TSR_TrfcSignVal <= 0x45))
					{
						tsr_value.u8TSR_Road_Sign = u8TSR_TrfcSignVal;
						TT_SET(enFTT_TSR_Traffic_Sign,TT_enTURN_ON);
					}
					else
					{
						TT_SET(enFTT_TSR_Traffic_Sign,TT_enTURN_OFF);
					}
				}
				else
				{
					TT_SET(enFTT_TSR_Traffic_Sign,TT_enTURN_OFF);
					TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_OFF);
				}

			}
			else
			{
				TT_SET(enFTT_TSR_Traffic_Sign,TT_enTURN_OFF);
				TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_TSR_Traffic_Sign,TT_enTURN_OFF);
			TT_SET(enFTT_TSR_Speed_Limit,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vOilWaterSeparation_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_OilWaterSeparation_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_OilWaterSeparation_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_OilWaterSeparation_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_OilWaterSeparation_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_OilWaterSeparation_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_OilWaterSeparation_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_OilWaterSeparation_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_OilWaterSeparation_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_OilWaterSeparation_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_OilWaterSeparation_ENABLE  1
#else
	#define TT_OilWaterSeparation_ENABLE  0
#endif

void FTT_vOilWaterSeparation_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8OilWaterSeparation_Config_Byte2 = 0;
	uint8 u8WIFSensorFailSts = 0;
	uint8 u8WIFFullLmpCmd = 0;
	uint8 u8Oil_Received = RTE_E_INVALID;
	TT_SET_CFG(enFTT_OilWaterSeparation,ON);

	u8OilWaterSeparation_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8Oil_Received = FTT_Adapt_GetMessage_WIFSensorFailSts(&u8WIFSensorFailSts);
	(void)FTT_Adapt_GetMessage_WIFFullLmpCmd(&u8WIFFullLmpCmd);
	if(TT_OilWaterSeparation_ENABLE)
	{
		if(u8OilWaterSeparation_Config_Byte2 == 0)
		{
			TT_SET_DID(enFTT_OilWaterSeparation,ON);
			if(u8Oil_Received == RTE_E_OK)
			{
				if((u8WIFSensorFailSts == 1) || (u8WIFFullLmpCmd == 1))
				{
					TT_SET(enFTT_OilWaterSeparation,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_OilWaterSeparation,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_OilWaterSeparation,TT_enTURN_ON);
			}
		}
		else
		{
			TT_SET_DID(enFTT_OilWaterSeparation,OFF);
			TT_SET(enFTT_OilWaterSeparation,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_vOilWaterSeparation_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Adblue_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Adblue_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Adblue_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Adblue_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Adblue_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_Adblue_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_Adblue_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_Adblue_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_Adblue_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_Adblue_ENABLE  1

#else
	#define TT_Adblue_ENABLE  0
#endif

void FTT_vAdblue_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8Adblue_Config_Byte2 = 0;
	uint8 u8Adblue_Config_Byte31 = 0;
	uint8 u8UreaLampCmd = 0;
	uint8 u8Adblue_Received = RTE_E_INVALID;
	TT_SET_CFG(enFTT_Adblue,ON);

	u8Adblue_Config_Byte2 = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8Adblue_Config_Byte31 = FTT_Adapt_GetVconfig(VCONFIG_KIND_EMISSION_LEVEL);
	u8Adblue_Received = FTT_Adapt_GetMessage_UreaLampCmd(&u8UreaLampCmd);

	if(TT_Adblue_ENABLE)
	{
		if((u8Adblue_Config_Byte2 == 0) && ((u8Adblue_Config_Byte31 == 5) \
			|| (u8Adblue_Config_Byte31 == 6) || (u8Adblue_Config_Byte31 == 7) \
			|| (u8Adblue_Config_Byte31 == 8) || (u8Adblue_Config_Byte31 == 9) \
			|| (u8Adblue_Config_Byte31 == 10)))
		{
			TT_SET_DID(enFTT_Adblue,ON);
			if(u8Adblue_Received == RTE_E_OK)
			{
				if(u8UreaLampCmd == 1)
				{
					TT_SET(enFTT_Adblue,TT_enTURN_ON);
				}
				else if(u8UreaLampCmd == 2)
				{
					TT_SET(enFTT_Adblue,TT_enFLASH_1_HZ);
				}
				else if(u8UreaLampCmd == 3)
				{
					if((u8Adblue_Config_Byte31 == 9) || (u8Adblue_Config_Byte31 == 10))
					{
						TT_SET(enFTT_Adblue,TT_enFLASH_1_HZ_50);//0.5HZ flash
					}
					else
					{
						TT_SET(enFTT_Adblue,TT_enTURN_OFF);
					}
				}
				else
				{
					TT_SET(enFTT_Adblue,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_Adblue,TT_enTURN_ON);
			}
		}
		else
		{
			TT_SET_DID(enFTT_Adblue,OFF);
			TT_SET(enFTT_Adblue,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_V2XGuideSpeed_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_V2XGuideSpeed_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_V2XGuideSpeed_ENABLE  0

#else
	#define TT_V2XGuideSpeed_ENABLE  0
#endif

void FTT_V2XGuideSpeed_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8V2X_Config_Byte84 = 0;
	uint8 u8V2XGLOSA = 0;
	uint8 u8V2X_Received = RTE_E_INVALID;

	TT_SET_CFG(enFTT_V2X_GLOSA, ON);
	TT_SET_DID(enFTT_V2X_GLOSA, OFF);

	u8V2X_Config_Byte84 = FTT_Adapt_GetVconfig(VCONFIG_KIND_VEHICLE_TO_X);
	u8V2X_Received = FTT_Adapt_GetMessage_V2XGLOSA(&u8V2XGLOSA);

	if(TT_V2XGuideSpeed_ENABLE)
	{
		if(1 == u8V2X_Config_Byte84)
		{
			if(u8V2X_Received == RTE_E_OK)
			{
				if (u8V2XGLOSA <= 150)
				{
					v2x_Info.u8V2X_GuideSpeed = u8V2XGLOSA;
					TT_SET(enFTT_V2X_GLOSA,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_V2X_GLOSA,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_V2X_GLOSA,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_V2X_GLOSA,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_V2XSpeedLimit_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_V2XSpeedLimit_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_V2XSpeedLimit_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_V2XSpeedLimit_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_V2XSpeedLimit_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_V2XSpeedLimit_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_V2XSpeedLimit_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_V2XSpeedLimit_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_V2XSpeedLimit_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_V2XSpeedLimit_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_V2XSpeedLimit_ENABLE  1
#else
	#define TT_V2XSpeedLimit_ENABLE  0
#endif

void FTT_V2XSpeedLimit_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8V2X_Config_Byte84 = 0;
	uint8 u8V2XSLW = 0;
	uint8 u8V2X_Received = RTE_E_INVALID;
	TT_CFG_enStatusType enOverSpd = TT_enTURN_OFF;
	TT_CFG_enStatusType enTSRSpd = TT_enTURN_OFF;

	TT_SET_CFG(enFTT_V2X_SpeedLimit, ON);
	TT_SET_DID(enFTT_V2X_SpeedLimit, OFF);

	u8V2X_Config_Byte84 = FTT_Adapt_GetVconfig(VCONFIG_KIND_VEHICLE_TO_X);
	u8V2X_Received = FTT_Adapt_GetMessage_V2XSLW(&u8V2XSLW);
	enOverSpd = TT_GET(enFTT_120KMH);
	enTSRSpd = TT_GET(enFTT_TSR_Speed_Limit);

	if(TT_V2XSpeedLimit_ENABLE)
	{
		if ((TT_enTURN_OFF == enOverSpd) && (TT_enTURN_OFF == enTSRSpd))
		{
			if(1 == u8V2X_Config_Byte84)
			{
				if(u8V2X_Received == RTE_E_OK)
				{
					if ((u8V2XSLW > 0) && (u8V2XSLW <= 30))
					{
						v2x_Info.u8V2X_SpeedLimit = u8V2XSLW;
						TT_SET(enFTT_V2X_SpeedLimit,TT_enTURN_ON);
					}
					else
					{
						TT_SET(enFTT_V2X_SpeedLimit,TT_enTURN_OFF);
					}
				}
				else
				{
					TT_SET(enFTT_V2X_SpeedLimit,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_V2X_SpeedLimit,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_V2X_SpeedLimit,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_V2XTrafficSign_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_V2XTrafficSign_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_V2XTrafficSign_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_V2XTrafficSign_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_V2XTrafficSign_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_V2XTrafficSign_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_V2XTrafficSign_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_V2XTrafficSign_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_V2XTrafficSign_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_V2XTrafficSign_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_V2XTrafficSign_ENABLE  0

#else
	#define TT_V2XTrafficSign_ENABLE  0
#endif

void FTT_V2XTrafficSign_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8V2X_Config_Byte84 = 0;
	uint8 u8V2XIVSW = 0;
	uint8 u8V2X_Received = RTE_E_INVALID;
	TT_CFG_enStatusType enTSRTrafSign = TT_enTURN_OFF;

	TT_SET_CFG(enFTT_V2X_TrafficSign, ON);
	TT_SET_DID(enFTT_V2X_TrafficSign, OFF);

	u8V2X_Config_Byte84 = FTT_Adapt_GetVconfig(VCONFIG_KIND_VEHICLE_TO_X);
	u8V2X_Received = FTT_Adapt_GetMessage_V2XIVSW(&u8V2XIVSW);
	enTSRTrafSign = TT_GET(enFTT_TSR_Traffic_Sign);

	if(TT_V2XTrafficSign_ENABLE)
	{
		if (TT_enTURN_OFF == enTSRTrafSign)
		{
			if(1 == u8V2X_Config_Byte84)
			{
				if(u8V2X_Received == RTE_E_OK)
				{
					if ((u8V2XIVSW > 0) && (u8V2XIVSW <= 36))
					{
						v2x_Info.u8V2X_TrafficSign = u8V2XIVSW;
						TT_SET(enFTT_V2X_TrafficSign,TT_enTURN_ON);
					}
					else
					{
						TT_SET(enFTT_V2X_TrafficSign,TT_enTURN_OFF);
					}
				}
				else
				{
					TT_SET(enFTT_V2X_TrafficSign,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_V2X_TrafficSign,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_V2X_TrafficSign,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_V2XTrafficLight_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_V2XTrafficLight_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_V2XTrafficLight_ENABLE  0

#else
	#define TT_V2XTrafficLight_ENABLE  0
#endif

void FTT_V2XTrafficLight_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8V2X_Config_Byte84 = 0;
	uint8 u8LaneNum = 0;
	uint8 u8V2XSLV = 0;
	uint8 u8V2XSL_Type[8] = {0};
	uint8 u8V2XSL_Color[8] = {0};
	uint16 u16V2XSL_Time[8] = {0};
	uint8 u8V2X_RLightId = 0;
	uint8 u8V2X_GLightId = 0;
	uint8 u8V2X_YLightId = 0;
	uint8 u8V2X_Received = RTE_E_INVALID;

	for (u8LaneNum = 0u; u8LaneNum < 7; u8LaneNum++)
	{
		u8V2X_RLightId = (uint8)((uint8)enFTT_V2X_RLight1 + (3u * u8LaneNum));
		u8V2X_YLightId = (uint8)((uint8)enFTT_V2X_YLight1 + (3u * u8LaneNum));
		u8V2X_GLightId = (uint8)((uint8)enFTT_V2X_GLight1 + (3u * u8LaneNum));

		TT_SET_CFG(u8V2X_RLightId, ON);
		TT_SET_DID(u8V2X_RLightId, OFF);
		TT_SET_CFG(u8V2X_YLightId, ON);
		TT_SET_DID(u8V2X_YLightId, OFF);
		TT_SET_CFG(u8V2X_GLightId, ON);
		TT_SET_DID(u8V2X_GLightId, OFF);
	}

	u8V2X_Config_Byte84 = FTT_Adapt_GetVconfig(VCONFIG_KIND_VEHICLE_TO_X);
	u8V2X_Received = FTT_Adapt_GetMessage_V2XSLV(&u8V2XSLV);

	// traffic light 8: Reserved
	for (u8LaneNum = 0u; u8LaneNum < 7; u8LaneNum++)
	{
		(void)FTT_Adapt_GetMessage_V2XSLXL((u8LaneNum + 1u), &(u8V2XSL_Type[u8LaneNum]),
			&(u8V2XSL_Color[u8LaneNum]), &(u16V2XSL_Time[u8LaneNum]));
	}

	if(TT_V2XTrafficLight_ENABLE)
	{
		if(1 == u8V2X_Config_Byte84)
		{
			if(u8V2X_Received == RTE_E_OK)
			{
				if ((u8V2XSLV > 0) && (u8V2XSLV <= 7))
				{
					v2x_Info.u8V2X_VehPosition = u8V2XSLV;
				}
				else
				{
					v2x_Info.u8V2X_VehPosition = 0u;    //不显示本车位置
				}

				for (u8LaneNum = 0u; u8LaneNum < 7; u8LaneNum++)
				{
					if ((u16V2XSL_Time[u8LaneNum] > 0) && (u16V2XSL_Time[u8LaneNum] <= 999))
					{
						v2x_Info.u8V2X_LightTime[u8LaneNum] = u16V2XSL_Time[u8LaneNum];
					}
					else
					{
						v2x_Info.u8V2X_LightTime[u8LaneNum] = 0u;    //不显示倒计时
					}

					u8V2X_RLightId = (uint8)((uint8)enFTT_V2X_RLight1 + (3u * u8LaneNum));
					u8V2X_YLightId = (uint8)((uint8)enFTT_V2X_YLight1 + (3u * u8LaneNum));
					u8V2X_GLightId = (uint8)((uint8)enFTT_V2X_GLight1 + (3u * u8LaneNum));

					switch(u8V2XSL_Color[u8LaneNum])
					{
					case 1 :
						TT_SET(u8V2X_RLightId, TT_enTURN_ON);
						TT_SET(u8V2X_YLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_GLightId, TT_enTURN_OFF);
						break;
					case 2 :
						TT_SET(u8V2X_RLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_YLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_GLightId, TT_enTURN_ON);
						break;
					case 3 :
						TT_SET(u8V2X_RLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_YLightId, TT_enTURN_ON);
						TT_SET(u8V2X_GLightId, TT_enTURN_OFF);
						break;
					case 4 :
						TT_SET(u8V2X_RLightId, TT_enFLASH_1_HZ);
						TT_SET(u8V2X_YLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_GLightId, TT_enTURN_OFF);
						break;
					case 5 :
						TT_SET(u8V2X_RLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_YLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_GLightId, TT_enFLASH_1_HZ);
						break;
					case 6 :
						TT_SET(u8V2X_RLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_YLightId, TT_enFLASH_1_HZ);
						TT_SET(u8V2X_GLightId, TT_enTURN_OFF);
						break;
					default :
						TT_SET(u8V2X_RLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_YLightId, TT_enTURN_OFF);
						TT_SET(u8V2X_GLightId, TT_enTURN_OFF);
						break;
					}
				}
			}
			else
			{
				for (u8LaneNum = 0u; u8LaneNum < 7; u8LaneNum++)
				{
					u8V2X_RLightId = (uint8)((uint8)enFTT_V2X_RLight1 + (3u * u8LaneNum));
					u8V2X_YLightId = (uint8)((uint8)enFTT_V2X_YLight1 + (3u * u8LaneNum));
					u8V2X_GLightId = (uint8)((uint8)enFTT_V2X_GLight1 + (3u * u8LaneNum));

					TT_SET(u8V2X_RLightId, TT_enTURN_OFF);
					TT_SET(u8V2X_YLightId, TT_enTURN_OFF);
					TT_SET(u8V2X_GLightId, TT_enTURN_OFF);
				}
			}
		}
		else
		{
			for (u8LaneNum = 0u; u8LaneNum < 7; u8LaneNum++)
			{
				u8V2X_RLightId = (uint8)((uint8)enFTT_V2X_RLight1 + (3u * u8LaneNum));
				u8V2X_YLightId = (uint8)((uint8)enFTT_V2X_YLight1 + (3u * u8LaneNum));
				u8V2X_GLightId = (uint8)((uint8)enFTT_V2X_GLight1 + (3u * u8LaneNum));

				TT_SET(u8V2X_RLightId, TT_enTURN_OFF);
				TT_SET(u8V2X_YLightId, TT_enTURN_OFF);
				TT_SET(u8V2X_GLightId, TT_enTURN_OFF);
			}
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_AirSuspension_Process
*
*	Parameters		: void/void
*
*	Return Type 		: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_AirSuspension_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_AirSuspension_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_AirSuspension_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_AirSuspension_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_AirSuspension_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_AirSuspension_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_AirSuspension_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_AirSuspension_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_AirSuspension_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_AirSuspension_ENABLE  0

#else
	#define TT_AirSuspension_ENABLE  0
#endif

void FTT_AirSuspension_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8AirSus_Config_Byte108 = 0;
	uint8 u8LvlCtrlWarnLmp = 0;
	uint8 u8VDC_Received = RTE_E_INVALID;

	TT_SET_CFG(enFTT_AirSus_Yellow, ON);
	TT_SET_CFG(enFTT_AirSus_Red, ON);
	TT_SET_DID(enFTT_AirSus_Yellow, OFF);
	TT_SET_DID(enFTT_AirSus_Red, OFF);

	u8AirSus_Config_Byte108 = FTT_Adapt_GetVconfig(VCONFIG_KIND_SUSPENSION_SPRING_TYPE);
	u8VDC_Received = FTT_Adapt_GetMessage_LvlCtrlWarnLmpReq(&u8LvlCtrlWarnLmp);

	if(TT_AirSuspension_ENABLE)
	{
		if(4 == u8AirSus_Config_Byte108)
		{
			if(u8VDC_Received == RTE_E_OK)
			{
				if (1 == u8LvlCtrlWarnLmp)
				{
					TT_SET(enFTT_AirSus_Yellow,TT_enTURN_ON);
					TT_SET(enFTT_AirSus_Red,TT_enTURN_OFF);
				}
				else if (2 == u8LvlCtrlWarnLmp)
				{
					TT_SET(enFTT_AirSus_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_AirSus_Red,TT_enTURN_ON);
				}
				else
				{
					TT_SET(enFTT_AirSus_Yellow,TT_enTURN_OFF);
					TT_SET(enFTT_AirSus_Red,TT_enTURN_OFF);
				}
			}
			else
			{
				TT_SET(enFTT_AirSus_Yellow,TT_enTURN_ON);
				TT_SET(enFTT_AirSus_Red,TT_enTURN_OFF);
			}
		}
		else
		{
			TT_SET(enFTT_AirSus_Yellow,TT_enTURN_OFF);
			TT_SET(enFTT_AirSus_Red,TT_enTURN_OFF);
		}
	}
}

/*******************************************************************************
*	Function name		: FTT_TT_Process_LogOutput
*
*	Parameters			: void/void
*
*	Return Type			: void/SINT8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation			: process log output
*
*	Description			:
*
********************************************************************************/
void FTT_TT_Process_LogOutput(TT_tstMainObject* stMainObject)
{
	uint8 u8TurnLeftCur = 0;
	uint8 u8TurnRightCur = 0;

	if (TRUE != SWC_TT_LOGOUT_ENBLE)
	{
		return;
	}

	// log output: Hardwired status
	if (0 != memcmp(u8LogOut_PreSts, u8LogOut_CurSts, TT_LogOutput_SIZE))
	{
		(void)memcpy(u8LogOut_PreSts, u8LogOut_CurSts, TT_LogOutput_SIZE);
		(void)SWC_TT_PRINT_WARN("TT: [HW_C2:%d, HW_C3: %d]", u8LogOut_PreSts[0], u8LogOut_PreSts[1]);
	}

	// log output: turn light
	u8TurnLeftCur = (uint8)TT_GET(enFTT_Turn_Left);
	u8TurnRightCur = (uint8)TT_GET(enFTT_Turn_Right);
	if ((u8TurnLight_PreSts[0] != u8TurnLeftCur) || (u8TurnLight_PreSts[1] != u8TurnRightCur))
	{
		u8TurnLight_PreSts[0] = u8TurnLeftCur;
		u8TurnLight_PreSts[1] = u8TurnRightCur;

		(void)SWC_TT_PRINT_WARN("TT: [LTurn:%d, %u; RTurn:%d, %u]", u8TurnLight_PreSts[0], (u32TLTimeTick[0] * TT_TurnLight_TASK), \
			u8TurnLight_PreSts[1], (u32TLTimeTick[1] * TT_TurnLight_TASK));

		u32TLTimeTick[0] = 0;
		u32TLTimeTick[1] = 0;
	}
}

/*******************************************************************************
*	Function name		: Get_vSAS_Handle_Status
*
*	Parameters		: void/void
*
*	Return Type 		: uint8
*
*	Global Variables	:
*
*	External interface	:
*
*-----------------------------------------------------------------------------
*	Invocation		: Called by the Telltale manager.
*
*	Description 		:
*
********************************************************************************/

uint8 Get_vSAS_Handle_Status(void)
{
	uint8 u8SAS_Config_Byte14 = 0;
	uint8 u8SAS_Received = RTE_E_INVALID;
	uint8 u8SAS_BCM8_Received = RTE_E_INVALID;
	uint8 u8SAS_ErrSts = 0;
	uint8 u8SAS_BliSts = 0;
	uint8 u8SAS_RemoteModSts = 0;
	uint8 u8SAS_KL30BRelaySts = 0;
	uint8 u8SAS_Handle_Status = 0;

	u8SAS_Config_Byte14 = FTT_Adapt_GetVconfig(VCONFIG_KIND_LANE_CHANGE_ASSIST);
	u8SAS_Received = FTT_Adapt_GetMessage_RSDS_ErrSts(&u8SAS_ErrSts);
	u8SAS_BCM8_Received = FTT_Adapt_GetMessage_RemoteModSts(&u8SAS_RemoteModSts);
	(void)FTT_Adapt_GetMessage_RSDS_BliSts(&u8SAS_BliSts);
	(void)FTT_Adapt_GetMessage_KL30BRelaySts(&u8SAS_KL30BRelaySts);

	if (1 == u8SAS_Config_Byte14)
	{
		if (u8SAS_Received == RTE_E_OK)
		{
			if (u8SAS_ErrSts == TT_FUN_ACTIVE)
			{
				u8SAS_Handle_Status = 1;
			}
			else if ((u8SAS_ErrSts == TT_FUN_INACTIVE) && (u8SAS_BliSts == TT_FUN_ACTIVE))
			{
				u8SAS_Handle_Status = 1;
			}
			else
			{
				u8SAS_Handle_Status = 0;
			}
		}
		else
		{
			if ((u8SAS_BCM8_Received == RTE_E_OK) && \
				((0 == u8SAS_RemoteModSts) || (1 == u8SAS_KL30BRelaySts)))
			{
				u8SAS_Handle_Status = 1;
			}
			else
			{
				u8SAS_Handle_Status = 0;
			}
		}
	}
	else
	{
		u8SAS_Handle_Status = 0;
	}

	return u8SAS_Handle_Status;

}

void ETC_get_TSR_tt_inf(TT_TSR_Info *pf_tsr_tt_inf)
{
	pf_tsr_tt_inf->u8TSR_Speed_Limit_Value = tsr_value.u8TSR_Speed_Limit_Value;
	pf_tsr_tt_inf->u8TSR_Road_Sign = tsr_value.u8TSR_Road_Sign;
}

/**********************************************************************************************************
*Function   : Get_V2X_TT_Info                                                                             *
*                                                                                                         *
*Description: xxx                                                                                         *
*                                                                                                         *
*Parameter	: TT_V2X_Info		                                                                          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: xxx                                                                                         *
*                                                                                                         *
*Date		: 2021-6-8                                                                                         *
**********************************************************************************************************/
void Get_V2X_TT_Info(TT_V2X_Info *pf_v2x_tt_info)
{
	uint8 u8LaneNum = 0;
	pf_v2x_tt_info->u8V2X_GuideSpeed = v2x_Info.u8V2X_GuideSpeed;
	pf_v2x_tt_info->u8V2X_SpeedLimit = v2x_Info.u8V2X_SpeedLimit;
	pf_v2x_tt_info->u8V2X_TrafficSign = v2x_Info.u8V2X_TrafficSign;
	pf_v2x_tt_info->u8V2X_VehPosition = v2x_Info.u8V2X_VehPosition;

	for (u8LaneNum = 0u; u8LaneNum < 7; u8LaneNum++)
	{
		pf_v2x_tt_info->u8V2X_LightTime[u8LaneNum] = v2x_Info.u8V2X_LightTime[u8LaneNum];
	}
}


/**********************************************************************************************************
*Function   : Central differential lock indicator light                                                                             *
*                                                                                                         *
*Description: xxx                                                                                         *
*                                                                                                         *
*Parameter	: Central differential lock indicator light		                                                                          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: xxx                                                                                         *
*                                                                                                         *
*Date		: 2022-1-5                                                                                         *
**********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_CDLL_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_CDLL_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_CDLL_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_CDLL_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_CDLL_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_CDLL_ENABLE 1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_CDLL_ENABLE 1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_CDLL_ENABLE 1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_CDLL_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_CDLL_ENABLE 0

#else
	#define TT_CDLL_ENABLE 0
#endif

void FTT_CentralDiffLockLight_Process(TT_tstMainObject* stMainObject)
{
	uint8 u8CDLL_Config_Byte30 = 0;
	uint8 u8CDLL_Received = RTE_E_INVALID;
	uint8 u8CDLL_SystemOperMod = 0;

	TT_SET_CFG(enFTT_CDLL_Green,ON);
	TT_SET_CFG(enFTT_CDLL_Yellow,ON);
	TT_SET_DID(enFTT_CDLL_Green,OFF);
    TT_SET_DID(enFTT_CDLL_Yellow,OFF);

	u8CDLL_Config_Byte30 = FTT_Adapt_GetVconfig(VCONFIG_KIND_TRANSFER_CASE);
	u8CDLL_Received = FTT_Adapt_GetMessage_CentralDiffLockLightSts(&u8CDLL_SystemOperMod);

	if(TT_CDLL_ENABLE)
	{
		if(5 == u8CDLL_Config_Byte30)
		{
			
			if(u8CDLL_Received == RTE_E_OK)
			{
				if((3 == u8CDLL_SystemOperMod) || (6 == u8CDLL_SystemOperMod))
				{
					TT_SET(enFTT_CDLL_Green,TT_enTURN_ON);
					TT_SET(enFTT_CDLL_Yellow,TT_enTURN_OFF);
				}
				else if(1 == u8CDLL_SystemOperMod)
				{
					TT_SET(enFTT_CDLL_Green,TT_enTURN_OFF);
					TT_SET(enFTT_CDLL_Yellow,TT_enTURN_ON);
				}
				else if((2 == u8CDLL_SystemOperMod) || (4 == u8CDLL_SystemOperMod))
				{
					TT_SET(enFTT_CDLL_Green,TT_enTURN_OFF);
					TT_SET(enFTT_CDLL_Yellow,TT_enTURN_OFF);
				}
				else
				{
					// do nothing, keep
				}
			}
			else
			{
				TT_SET(enFTT_CDLL_Green,TT_enTURN_OFF);
				TT_SET(enFTT_CDLL_Yellow,TT_enTURN_ON);
			}
		}
		else
		{
			TT_SET(enFTT_CDLL_Green,TT_enTURN_OFF);
			TT_SET(enFTT_CDLL_Yellow,TT_enTURN_OFF);
		}
	}
}


/**********************************************************************************************************
*Function   : TT_TEST_enFlashTestProcess                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: (TT_CFG_enStatusType)Telltale current logic status                                          *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TT_CFG_DEBUG == TRUE)
void TT_TEST_vFlashTestProcess(TT_tstMainObject* stMainObject)
{

}
void TT_TEST_vOnCountPlus(void)
{
    static uint8 u8TickOn = 0;
    u8TickOn++;
}
void TT_TEST_vOffCountPlus(void)
{
    static uint8 u8TickOff = 0;
    u8TickOff++;
}
#endif //(TT_CFG_DEBUG == TRUE)
#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
