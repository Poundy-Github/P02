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
*File Name   : SWC_TT_Safety.c                                                                            *
*                                                                                                         *
*Description : Telltale module logic process source file.                                                 *
*                                                                                                         *
*Author      : li yafei                                                                                   *
*                                                                                                         *
*Platform    : Free Rtos System                                                                           *
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
#include "Compiler.h"
#include "Platform_Types.h"
#include "SWC_IPC_Application.h"
#include "SWC_TT_Safety_Adaptor.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TT_Safety.h"
#include "Dio.h"
#include "Com.h"
#include "VConfig.h"
#include "IoHwAb.h"
#include "IoHwAb_Cfg_RI.h"
#include <string.h> /* memset */
#include "IPC_ClusterApp.h"
#include "Rte_Common_Safety.h"
#include "IPC_SAFETY.h"
#include "DevConfig.h"

#ifdef FUEL_TC_VEHICLE_TEST
#include "Can.h"
#include "Can_DrvGeneralTypes.h"
extern void Fuel_Trace_Debug (void);
#endif


/****************************************************************************************
*																						*
*				Macro Definition														*
*																						*
*****************************************************************************************/
//power definition
#define STT_CLUSTER_ABNORMAL   (0u)
#define STT_CLUSTER_ON         (1u)
#define STT_CLUSTER_STANDBY    (2u)

//E2E status
#define STT_E2E_OK       (0u)
#define STT_E2E_NOTOK    (1u)

//callback self check status
#define TT_SELFCHECKING    (1u)
#define TT_SELFCHECK_OK    (0u)

//PIN4 status
#define STT_EBD_HW_LOW     (0u)
#define STT_EBD_HW_HIGH    (1u)

//STT status control
#define STT_ALLON         (0u)
#define STT_ALLOFF        (1u)
#define STT_KL15ON_OFF    (2u)

/*vconfig redefinition*/
#define Config_VcfgInit         STT_Vconfig.u8VcfgInit
#define Config_Byte4_Domain     STT_Vconfig.u8Byte4_Domain
#define Config_Byte26_Service   STT_Vconfig.u8Byte26_Service
#define Config_Byte26_Parking   STT_Vconfig.u8Byte26_Parking
#define Config_Byte25_Steering  STT_Vconfig.u8Byte25_Steering
#define Config_Byte10_FCW       STT_Vconfig.u8Byte10_FCW
#define Config_Byte46_Junction  STT_Vconfig.u8Byte46_Junction
#define Config_Byte2_Fuel       STT_Vconfig.u8Byte2_Fuel
#define Config_Byte30_Electro   STT_Vconfig.u8Byte30_Electro
#define Config_Byte41_Epark     STT_Vconfig.u8Byte41_Epark0

/*获取E2E状态*/
#define STT_GET_E2E(CanMessage)  \
        (((CanMessage) < STT_enCANNUM_MAX) ? TT_E2E_Flag[(CanMessage)].Safety_TT_E2E_Flag : STT_E2E_OK)

/*设置报警灯状态*/
#define STT_SET(TelltaleID,SetLogicStatus)  \
        if ((TelltaleID) < TT_SAFETY_TOTAL_NUMBER) {TT_status[(TelltaleID)].Safety_TT_Data = (uint8)(SetLogicStatus);}

/*CRC check*/
#define getByteData(arr,n) ((uint32)(arr)[(n)+1u]<<24)|((uint32)(arr)[(n)+2u]<<16)|((uint32)(arr)[(n)+3u]<<8)|((arr)[(n)+4u])



#define Common_Safety_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Safety_MemMap.h"

static SAFETY_TT_ST TT_status[TT_SAFETY_TOTAL_NUMBER];
static SAFETY_TT_E2E_FLAG TT_E2E_Flag[STT_enCANNUM_MAX];
static IPC_M2S_SAFETYAPPTT_Safety_t ToSBUS_TT_Safety_status32;
//static IPC_M2S_SAFETYAPPTT_Safety_t ToSBUS_TT_Safety_status32_Pre;
static IPC_M2S_SAFETYAPPSafetyTelltaleCheck_t ipcTTACKData;
static IPC_S2M_SAFETYAPPSafetyTTCRC_t TTCRCData;
static TT_SAFETY_CRC_t crcData[TT_enTELLTALE_TOTAL_NUMBER];

#define Common_Safety_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Safety_MemMap.h"


#define Common_Safety_START_SEC_CONST_UNSPECIFIED
#include "Common_Safety_MemMap.h"

static const uint32 TTCrcTable[TT_enTELLTALE_TOTAL_NUMBER] = SEFETY_TT_CFG_CRC_TABLE;
static const TT_SAFETY_enTelltaleID STT__SelfcheckReport[STT_CFG_SelfcheckReport_COUNT] = STT_CFG_SelfcheckReport_LIST;

#define Common_Safety_STOP_SEC_CONST_UNSPECIFIED
#include "Common_Safety_MemMap.h"


#define Common_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Safety_MemMap.h"

static uint8 u8PowerSts = 0;
static uint8 u8TTErrorSwitch = 0;
static uint8 u8E2ECheckCfg = 0;

static uint8 u8TTselfchecksts = TT_SELFCHECKING;
static uint8 u8Break_HW_Pin4 = STT_EBD_HW_HIGH;
static boolean boSTTIpcCallback = FALSE;
static boolean STT_boSelfcheckReportsts = FALSE;
static uint16 u16SttIgnOnDelayTimeTick = 0;
static SAFETY_TT_CFG  STT_Vconfig;

#define Common_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Safety_MemMap.h"

#define SWC_TT_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_TT_MemMap.h"

static STT_ABS_EBD_CONFIG ESP_Config_Sts = STT_EBD_UNDEFINED;
static STT_ABS_EBD_CONFIG ABS_Config_Sts = STT_EBD_UNDEFINED;
static STT_ABS_EBD_CONFIG Break_Config_Sts = STT_EBD_UNDEFINED;

//STT log output
static SAFETY_TT_E2E_FLAG TT_E2E_FlagPre[STT_enCANNUM_MAX];
static uint8 u8Break_HW_Pin4Pre = STT_EBD_HW_HIGH;
static uint8 u8TTErrorSwitchPre = 0;

#define SWC_TT_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_TT_MemMap.h"


/**********************************************************************************************************
* Process Function Configuration 																		  *
**********************************************************************************************************/
#define Common_Safety_START_SEC_CODE
#include "Common_Safety_MemMap.h"


static void STT_Function_GetPower(void);
static void STT_Function_GetConfig(void);

static void STT_Function_Safety_LogicTask(void);
static void STT_Function_Safety_Cluster_StandbyLogicTask(void);
static void STT_Function_Safety_SBUS(void);

static void STT_vABS_Failure_Process(void);
static void STT_vESP_Enable_Process(void);
static void STT_vESP_Disable_Process(void);
static void STT_vEPB_Failure_Process(void);
static void STT_vBreak_Error_Handle_Process(void);
static void STT_vEPS_Error_Handle_Process(void);
static void STT_vABM_Error_Handle_Process(void);
static void STT_vFCW_Handle_Process(void);
static void STT_vPBF_Handle_Process(void);
static void STT_vHEV_Handle_Process(void);
static void STT_vTPF_Handle_Process(void);
//static void STT_vEPark_Handle_Process(void);
//static void STT_vDC_Handle_Process(void);
//static void STT_vMotor_Failure_Process(void);

static void STT_SafetyTT_CRC_Check(void);
static void STT_SetAllTellTaleSts(uint8 u8CtrlCmd);
static void STT_Get_All_E2ESts(void);
static void STT_Set_All_E2ESts(void);
static void STT_Function_Safety_SelfCheck_Sts(void);
static void STT_GetSelfcheckReportStatus(void);


/**********************************************************************************************************
*																										  *
*																										  *
*	Telltale Process Function  Definition																  *
*																										  *
*																										  *
**********************************************************************************************************/

void STT_Function_GetPower(void)
{
	uint8 PowerVoltageSts = 0;
	uint8 u8PowerMode = 0;
	SystemState_RecordType Power_State;

	(void)memcpy(&Power_State,Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut(),sizeof(SystemState_RecordType));
	PowerVoltageSts = Power_State.s_PowerVoltage.state;
	u8PowerMode = Power_State.ClusterState;

	if ((VOLTAGE_OUT_NORMAL == PowerVoltageSts) || (VOLTAGE_OUT_LOWALARM == PowerVoltageSts) \
		|| (VOLTAGE_OUT_HIGHALARM  == PowerVoltageSts))
	{
		if (SYSTEMSTATE_Cluster_ON == u8PowerMode)
		{
			u8PowerSts = STT_CLUSTER_ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == u8PowerMode)
		{
			u8PowerSts = STT_CLUSTER_STANDBY;
		}
		else
		{
			u8PowerSts = STT_CLUSTER_ABNORMAL;
		}
	}
	else
	{
		u8PowerSts = STT_CLUSTER_ABNORMAL;
	}
}

void STT_Function_GetConfig(void)
{
	if (0 == Config_VcfgInit)
	{
		Config_VcfgInit = ATT_Adapt_GetVconfig(VCONFIG_KIND_INIT_FLAG);
		if (Config_VcfgInit != 0)
		{
			Config_Byte4_Domain = ATT_Adapt_GetVconfig(VCONFIG_KIND_REGIONAL);
			Config_Byte26_Service = ATT_Adapt_GetVconfig(VCONFIG_KIND_SERVICE_BRAKE);
			Config_Byte26_Parking = ATT_Adapt_GetVconfig(VCONFIG_KIND_PARKING_BRAKE);
			Config_Byte25_Steering = ATT_Adapt_GetVconfig(VCONFIG_KIND_STEERING_SYSTEM);
			Config_Byte10_FCW = ATT_Adapt_GetVconfig(VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING);
			Config_Byte46_Junction = ATT_Adapt_GetVconfig(VCONFIG_KIND_AEB_JUNCTION_ASSIST);
			Config_Byte2_Fuel = ATT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
			Config_Byte30_Electro = ATT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
			Config_Byte41_Epark = ATT_Adapt_GetVconfig(VCONFIG_KIND_E_PARK);
		}
	}
}

void STT_Function_Safety_TimeTask(void)
{
#ifdef FUEL_TC_VEHICLE_TEST
  Fuel_Trace_Debug();
#endif

	STT_Function_GetPower();
	if (u8TTErrorSwitch == 1u)
	{
		STT_SetAllTellTaleSts(STT_ALLON);
	}
	else
	{
		if (STT_CLUSTER_ON == u8PowerSts)
		{
			STT_Get_All_E2ESts();
			STT_Function_Safety_LogicTask();
		}
		else if(STT_CLUSTER_STANDBY == u8PowerSts)
		{
			STT_Set_All_E2ESts();//KL15 OFF, not judge E2E
			STT_Function_Safety_Cluster_StandbyLogicTask();
		}
		else
		{
			STT_Function_Safety_Init();
		}
	}
    STT_Function_Safety_SBUS();
}

void  STT_SetAllTellTaleSts(uint8 u8CtrlCmd)
{
	uint8 u8Index;

	switch(u8CtrlCmd)
	{
		case STT_ALLON:
			for (u8Index = 1; u8Index < (uint8)TT_SAFETY_TOTAL_NUMBER; u8Index++)
			{
				TT_status[u8Index].Safety_TT_Data = (uint8)TT_enTURN_ON;
			}
			break;
		case STT_ALLOFF:
			for (u8Index = 1; u8Index < (uint8)TT_SAFETY_TOTAL_NUMBER; u8Index++)
			{
				TT_status[u8Index].Safety_TT_Data = (uint8)TT_enTURN_OFF;
			}
			break;
		case STT_KL15ON_OFF:
			for (u8Index = 1; u8Index < (uint8)TT_SAFETY_TOTAL_NUMBER; u8Index++)
			{
				if ((enSTT_PBF_Red == u8Index) || (enSTT_PBF_Yellow == u8Index) \
					|| (enSTT_HEV_Yellow == u8Index) || (enSTT_HEV_Red == u8Index) \
					|| (enSTT_TPF == u8Index))
				{
					continue;
				}
				TT_status[u8Index].Safety_TT_Data = (uint8)TT_enTURN_OFF;
			}
			break;
		default:
			// do nothing
			break;
	}
}

void  STT_TTErrorCallback(const uint8 *data)
{
	u8TTErrorSwitch = *data;

	// log output
	if(TRUE == SWC_STT_LOGOUT_ENBLE)
	{
		if(u8TTErrorSwitch != u8TTErrorSwitchPre)
		{
			(void)SWC_STT_PRINT_WARN("STT_Error: %d",u8TTErrorSwitch);
			u8TTErrorSwitchPre = u8TTErrorSwitch;
		}
	}
}

void STT_Function_Safety_LogicTask(void)
{
	if(u16SttIgnOnDelayTimeTick < 300u )
	{
		u16SttIgnOnDelayTimeTick ++;
	}

	STT_vABS_Failure_Process();
	STT_vESP_Enable_Process();
	STT_vESP_Disable_Process();
	STT_vEPB_Failure_Process();
	STT_vBreak_Error_Handle_Process();
	STT_vEPS_Error_Handle_Process();
	STT_vABM_Error_Handle_Process();
	STT_vFCW_Handle_Process();
	STT_vPBF_Handle_Process();
	STT_vHEV_Handle_Process();
	STT_vTPF_Handle_Process();
	//STT_vEPark_Handle_Process();
	//STT_vDC_Handle_Process();
	//STT_vMotor_Failure_Process();

	STT_GetSelfcheckReportStatus();//获取自检播报状态

}

void STT_Function_Safety_Init(void)
{
	u8TTErrorSwitch = 0;
	u16SttIgnOnDelayTimeTick = 0;
	STT_boSelfcheckReportsts = FALSE;

	STT_Function_GetConfig();
	STT_Set_All_E2ESts();
	STT_SetAllTellTaleSts(STT_ALLOFF);
	STT_Function_Safety_SelfCheck_Sts();
	STT_Function_Safety_SBUS();
	//ATT_vE2E_Message_init();

}


#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			0
	#define TT_ESP_ENABLE  				1
	#define TT_ESP_IBC_ENABLE   		0
	#define TT_ABS_Failure_ENABLE  		1
	#define TT_ABS_Failure_IBC_ENABLE	0
	#define TT_Break_Error_ENABLE		1
	#define TT_Break_Error_IBC_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			0
	#define TT_ESP_ENABLE  				1
	#define TT_ESP_IBC_ENABLE   		0
	#define TT_ABS_Failure_ENABLE  		1
	#define TT_ABS_Failure_IBC_ENABLE	0
	#define TT_Break_Error_ENABLE		1
	#define TT_Break_Error_IBC_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			1
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		1
	#define TT_ABS_Failure_ENABLE		0
	#define TT_ABS_Failure_IBC_ENABLE	1
	#define TT_Break_Error_ENABLE		1
	#define TT_Break_Error_IBC_ENABLE 	0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_PBF_PHEV_ENABLE  		0
	#define TT_PBF_P0_ENABLE			1
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		1
	#define TT_ABS_Failure_ENABLE		0
	#define TT_ABS_Failure_IBC_ENABLE	1
	#define TT_Break_Error_ENABLE  		1
	#define TT_Break_Error_IBC_ENABLE 	0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			0
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		1
	#define TT_ABS_Failure_ENABLE		0
	#define TT_ABS_Failure_IBC_ENABLE	1
	#define TT_Break_Error_ENABLE		1
	#define TT_Break_Error_IBC_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			1
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		1
	#define TT_ABS_Failure_ENABLE		0
	#define TT_ABS_Failure_IBC_ENABLE	1
	#define TT_Break_Error_ENABLE  		0
	#define TT_Break_Error_IBC_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			1
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		1
	#define TT_ABS_Failure_ENABLE 		0
	#define TT_ABS_Failure_IBC_ENABLE 	1
	#define TT_Break_Error_ENABLE  		0
	#define TT_Break_Error_IBC_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			1
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		1
	#define TT_ABS_Failure_ENABLE		0
	#define TT_ABS_Failure_IBC_ENABLE	1
	#define TT_Break_Error_ENABLE		0
	#define TT_Break_Error_IBC_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			1
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		1
	#define TT_ABS_Failure_ENABLE  		0
	#define TT_ABS_Failure_IBC_ENABLE	1
	#define TT_Break_Error_ENABLE		1
	#define TT_Break_Error_IBC_ENABLE 	0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_PBF_PHEV_ENABLE  		1
	#define TT_PBF_P0_ENABLE			0
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		1
	#define TT_ABS_Failure_ENABLE  		0
	#define TT_ABS_Failure_IBC_ENABLE	1
	#define TT_Break_Error_ENABLE		1
	#define TT_Break_Error_IBC_ENABLE 	1

#else
	#define TT_PBF_PHEV_ENABLE  		0
	#define TT_PBF_P0_ENABLE			0
	#define TT_ESP_ENABLE  				0
	#define TT_ESP_IBC_ENABLE   		0
	#define TT_ABS_Failure_ENABLE  		0
	#define TT_ABS_Failure_IBC_ENABLE   0
	#define TT_Break_Error_ENABLE		0
	#define TT_Break_Error_IBC_ENABLE	0
#endif

void STT_Function_Safety_SelfCheck_Sts(void)
{
	/*ESP&ESP OFF*/
	if ((2u == Config_Byte26_Service) && (TT_ESP_ENABLE != 0))
	{
		ESP_Config_Sts = STT_EBD_ABS_ESP;	//case1
	}
	else if (((2u == Config_Byte26_Service) || (3u == Config_Byte26_Service) \
		|| (4u == Config_Byte26_Service)) && (TT_ESP_IBC_ENABLE != 0))
	{
		ESP_Config_Sts = STT_EBD_IBC;		//case2
	}
	else
	{
		ESP_Config_Sts = STT_EBD_UNDEFINED;
	}
	/*ABS*/
	if (((1u == Config_Byte26_Service) || (2u == Config_Byte26_Service)) && (TT_ABS_Failure_ENABLE != 0))
	{
		ABS_Config_Sts = STT_EBD_ABS_ESP;	//case1
	}
	else if (((1u == Config_Byte26_Service) || (2u == Config_Byte26_Service) \
		|| (3u == Config_Byte26_Service) || (4u == Config_Byte26_Service)) \
		&& (TT_ABS_Failure_IBC_ENABLE != 0))
	{
		ABS_Config_Sts = STT_EBD_IBC;		//case2
	}
	else
	{
		ABS_Config_Sts = STT_EBD_UNDEFINED;
	}
	/*break error*/
	if (((0u == Config_Byte26_Service) || (1u == Config_Byte26_Service) || (2u == Config_Byte26_Service)) && (TT_Break_Error_ENABLE != 0))
	{
		Break_Config_Sts = STT_EBD_ABS_ESP;
	}
	else if((3u == Config_Byte26_Service) && (TT_Break_Error_IBC_ENABLE != 0))
	{
		Break_Config_Sts = STT_EBD_IBC;
	}
	else
	{
		Break_Config_Sts = STT_EBD_UNDEFINED;
	}

	if ((STT_EBD_IBC == ABS_Config_Sts) || (STT_EBD_ABS_ESP == ABS_Config_Sts))
	{
		TT_status[enSTT_ABS_Fault_CH].SelfCheckSts = TRUE;
		TT_status[enSTT_ABS_Fault_US].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_ABS_Fault_CH].SelfCheckSts = FALSE;
		TT_status[enSTT_ABS_Fault_US].SelfCheckSts = FALSE;
	}

	if ((STT_EBD_IBC == ESP_Config_Sts) || (STT_EBD_ABS_ESP == ESP_Config_Sts))
	{
		TT_status[enSTT_ESP_Enable].SelfCheckSts = TRUE;
		TT_status[enSTT_ESP_Disable].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_ESP_Enable].SelfCheckSts = FALSE;
		TT_status[enSTT_ESP_Disable].SelfCheckSts = FALSE;
	}

	if ((STT_EBD_IBC == Break_Config_Sts) || (STT_EBD_ABS_ESP == Break_Config_Sts))
	{
		TT_status[enSTT_BreakError_CH].SelfCheckSts = TRUE;
		TT_status[enSTT_BreakError_US].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_BreakError_CH].SelfCheckSts = FALSE;
		TT_status[enSTT_BreakError_US].SelfCheckSts = FALSE;
	}

	/*EPB*/
	if (2u == Config_Byte26_Parking)
	{
		TT_status[enSTT_EPB_Fault_CH].SelfCheckSts = TRUE;
		TT_status[enSTT_EPB_Fault_US].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_EPB_Fault_CH].SelfCheckSts = FALSE;
		TT_status[enSTT_EPB_Fault_US].SelfCheckSts = FALSE;
	}

	/*EPS*/
	if (Config_Byte25_Steering == 1u)
	{
		TT_status[enSTT_EPS_Red_Error].SelfCheckSts = TRUE;
		TT_status[enSTT_EPS_Yellow_Error].SelfCheckSts = FALSE;
	}
	else
	{
		TT_status[enSTT_EPS_Red_Error].SelfCheckSts = FALSE;
		TT_status[enSTT_EPS_Yellow_Error].SelfCheckSts = FALSE;
	}
	/*ABM  no config limit*/
	TT_status[enSTT_ABM_Error].SelfCheckSts = TRUE;
	/*FCW no selfcheck*/
	TT_status[enSTT_FCW_Error].SelfCheckSts = FALSE;
	TT_status[enSTT_FCW_Enable].SelfCheckSts = FALSE;
	TT_status[enSTT_FCW_Off].SelfCheckSts = FALSE;
	/*PBF*/
	if ((((3u == Config_Byte2_Fuel) || (4u == Config_Byte2_Fuel)) \
		&& ((5u == Config_Byte30_Electro) || (6u == Config_Byte30_Electro))) \
		|| ((4u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) \
		|| (4u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))) \
		|| ((3u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))))
	{
		if(TT_PBF_PHEV_ENABLE != 0)
		{
			TT_status[enSTT_PBF_Red].SelfCheckSts = TRUE;
			TT_status[enSTT_PBF_Yellow].SelfCheckSts = FALSE;
		}
		else
		{
			TT_status[enSTT_PBF_Red].SelfCheckSts = FALSE;
			TT_status[enSTT_PBF_Yellow].SelfCheckSts = FALSE;
		}
	}
	else if (((0u == Config_Byte2_Fuel) || (1u == Config_Byte2_Fuel) || (2u == Config_Byte2_Fuel) \
			|| (7u == Config_Byte2_Fuel)) && (1u == Config_Byte30_Electro))
	{
		if(TT_PBF_P0_ENABLE != 0)
		{
			TT_status[enSTT_PBF_Red].SelfCheckSts = TRUE;
			TT_status[enSTT_PBF_Yellow].SelfCheckSts = FALSE;
		}
		else
		{
			TT_status[enSTT_PBF_Red].SelfCheckSts = FALSE;
			TT_status[enSTT_PBF_Yellow].SelfCheckSts = FALSE;
		}
	}
	else
	{
		TT_status[enSTT_PBF_Red].SelfCheckSts = FALSE;
		TT_status[enSTT_PBF_Yellow].SelfCheckSts = FALSE;
	}
	/*HEV*/
	if (((4u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) \
		|| (4u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))) \
		|| (((4u == Config_Byte2_Fuel) || (3u == Config_Byte2_Fuel)) \
		&& ((5u == Config_Byte30_Electro) || (6u == Config_Byte30_Electro))) \
		|| (((0u == Config_Byte2_Fuel) || (1u == Config_Byte2_Fuel) || (2u == Config_Byte2_Fuel) \
		|| (7u == Config_Byte2_Fuel)) && (1u == Config_Byte30_Electro)) \
		|| ((3u == Config_Byte2_Fuel) && (8u == Config_Byte30_Electro)))
	{
		TT_status[enSTT_HEV_Red].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_HEV_Red].SelfCheckSts = FALSE;
	}
	/*TPF*/
	if (((4u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) || (4u == Config_Byte30_Electro) \
		|| (5u == Config_Byte30_Electro) || (6u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))) \
		|| ((3u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) || (5u == Config_Byte30_Electro) \
		|| (6u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))))
	{
		TT_status[enSTT_TPF].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_TPF].SelfCheckSts = FALSE;
	}
	/*EPARK*/
	if ((5u == Config_Byte2_Fuel) && (1u == Config_Byte41_Epark))
	{
		TT_status[enSTT_EPark].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_EPark].SelfCheckSts = FALSE;
	}
	/*DC*/
	if (5u == Config_Byte2_Fuel)
	{
		TT_status[enSTT_DC_Alert].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_DC_Alert].SelfCheckSts = FALSE;
	}
	/*Motor failure*/
	if (5u == Config_Byte2_Fuel)
	{
		TT_status[enSTT_Motor_Failure].SelfCheckSts = TRUE;
	}
	else
	{
		TT_status[enSTT_Motor_Failure].SelfCheckSts = FALSE;
	}
}

void STT_Function_Safety_Cluster_StandbyLogicTask(void)
{
	u16SttIgnOnDelayTimeTick = 0;
	STT_boSelfcheckReportsts = FALSE;

	STT_SetAllTellTaleSts(STT_ALLOFF);
	STT_vPBF_Handle_Process();
	STT_vHEV_Handle_Process();
	STT_vTPF_Handle_Process();
	(void)Rte_Write_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts(0);
}

void STT_Function_Safety_PreOff_Logic(void)
{
	STT_SetAllTellTaleSts(STT_KL15ON_OFF);
	STT_Function_Safety_SBUS();
}

void STT_Get_All_E2ESts(void)
{
	uint8 u8Index = 0;
	uint8 u8ChangeFlag = 0;
	uint32 u32E2EReceived = 0;
	uint32 u32CAN_E2EReceived[STT_enCANNUM_MAX] = {0};
	char cLogBuffer[64] = {0};
	char cTempBuffer[4] = {0};

	(void)Rte_Read_piSR_E2ESwitchChangeTrigger_Element(&u8E2ECheckCfg);
	(void)ATT_GetMessage_E2E_ABS_Sts(&u32CAN_E2EReceived[u8Index++]);
	(void)ATT_GetMessage_E2E_ESP_Sts(&u32CAN_E2EReceived[u8Index++]);
	(void)ATT_GetMessage_E2E_EPB_Sts(&u32CAN_E2EReceived[u8Index++]);
	(void)ATT_GetMessage_E2E_EPS_Sts(&u32CAN_E2EReceived[u8Index++]);
	(void)ATT_GetMessage_E2E_ABM_Sts(&u32CAN_E2EReceived[u8Index++]);
	//(void)ATT_GetMessage_E2E_AEB3_FD_Sts(&u32CAN_E2EReceived[u8Index++]);
	(void)ATT_GetMessage_E2E_SG_BMS4_Sts(&u32CAN_E2EReceived[u8Index++]);
	(void)ATT_GetMessage_E2E_HCU_PT7_Sts(&u32CAN_E2EReceived[u8Index++]);

	for (u8Index = 0; u8Index < (uint8)STT_enCANNUM_MAX; u8Index++)
	{
		if (1u == u8E2ECheckCfg)
		{
			u32E2EReceived = u32CAN_E2EReceived[u8Index];
			if ((E2E_OK == u32E2EReceived) || (E2E_INITIAL == u32E2EReceived))
			{
				TT_E2E_Flag[u8Index].Safety_TT_E2E_Flag = STT_E2E_OK;
			}
			else if ((E2E_NONEWDATA == u32E2EReceived) || (E2E_SYNC == u32E2EReceived) \
				|| (E2E_OK_SOMELOST == u32E2EReceived))
			{
				//keep last value
			}
			else
			{
				TT_E2E_Flag[u8Index].Safety_TT_E2E_Flag = STT_E2E_NOTOK;
			}
		}
		else
		{
			TT_E2E_Flag[u8Index].Safety_TT_E2E_Flag = STT_E2E_OK;
		}

		if (TT_E2E_Flag[u8Index].Safety_TT_E2E_Flag != TT_E2E_FlagPre[u8Index].Safety_TT_E2E_Flag)
		{
			u8ChangeFlag = 1;
			TT_E2E_FlagPre[u8Index].Safety_TT_E2E_Flag = TT_E2E_Flag[u8Index].Safety_TT_E2E_Flag;
		}
	}

	// log output
	if((TRUE == SWC_STT_LOGOUT_ENBLE) && (0 != u8ChangeFlag))
	{
		for(u8Index = 0; u8Index < STT_enCANNUM_MAX; u8Index++)
		{
			(void)memset(cTempBuffer, 0, sizeof(cTempBuffer));
			(void)sprintf(cTempBuffer, "%2d", TT_E2E_Flag[u8Index].Safety_TT_E2E_Flag);
			(void)strcat(cLogBuffer,cTempBuffer);
		}
		SWC_STT_PRINT_WARN("STT [E2Ests: %s]", cLogBuffer);
	}
}

void STT_Set_All_E2ESts(void)
{
	uint8 u8Index;
	for (u8Index = 0; u8Index < (uint8)STT_enCANNUM_MAX; u8Index++)
	{
		TT_E2E_Flag[u8Index].Safety_TT_E2E_Flag = STT_E2E_OK;
	}
}

void TT_Api_Get_TTSelfCheck_Sts(const uint8 *data)
{
	u8TTselfchecksts = *data;
	Rte_Write_tiSR_SWC_TT_SelfCheck_Element(u8TTselfchecksts);
}

/*-------------function safety--------------*/
/*******************************************************************************
*	Function name		: STT_vABS_Failure_Process
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
*
********************************************************************************/
void STT_vABS_Failure_Process(void)
{
	uint8 u8ABS_Received = RTE_E_INVALID;
	uint8 u8ABS_FailSts = 0;
	ATT_DOMAIN_INFO enABS_Domain_Sts = ATT_DOMAIN_CH;
	TT_Safety_CFG_enStatType u8ABSFaultSts = TT_enTURN_OFF;

	enABS_Domain_Sts = ATT_vDomain_Logic_Process();
	u8ABS_Received = ATT_GetMessage_ABS_Sts(&u8ABS_FailSts);

	if((STT_EBD_ABS_ESP == ABS_Config_Sts) || (STT_EBD_IBC == ABS_Config_Sts))
	{
		if (STT_GET_E2E(STT_enABS3_ESPFD2) == STT_E2E_OK)
		{
			if (ATT_NO_DOMAIN != enABS_Domain_Sts)
			{
				if (u8ABS_Received == RTE_E_OK)
				{
					if (u8ABS_FailSts == (uint8)STT_FUN_ACTIVE)
					{
						u8ABSFaultSts = TT_enTURN_ON;
					}
					else
					{
						u8ABSFaultSts = TT_enTURN_OFF;
					}
				}
				else
				{
					u8ABSFaultSts = TT_enTURN_ON;
				}

			}
			else
			{
				u8ABSFaultSts = TT_enTURN_OFF;
			}


			if (enABS_Domain_Sts == ATT_DOMAIN_CH)
			{
				STT_SET(enSTT_ABS_Fault_CH,u8ABSFaultSts);
				STT_SET(enSTT_ABS_Fault_US,TT_enTURN_OFF);
			}
			else if (enABS_Domain_Sts == ATT_DOMAIN_US)
			{
				STT_SET(enSTT_ABS_Fault_US,u8ABSFaultSts);
				STT_SET(enSTT_ABS_Fault_CH,TT_enTURN_OFF);
			}
			else
			{
				STT_SET(enSTT_ABS_Fault_US,TT_enTURN_OFF);
				STT_SET(enSTT_ABS_Fault_CH,TT_enTURN_OFF);
			}
		}
		else
		{
			if (enABS_Domain_Sts == ATT_DOMAIN_CH)
			{
				STT_SET(enSTT_ABS_Fault_CH,TT_enTURN_ON);
			}
			else
			{
				STT_SET(enSTT_ABS_Fault_US,TT_enTURN_ON);
			}
		}
	}
}


/*******************************************************************************
*	Function name		: STT_vESP_Enable_Process
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
*
********************************************************************************/

void STT_vESP_Enable_Process(void)
{
	uint8 u8ESP_FailSts = 0;
	uint8 u8ESP_ActvInfo = 0;
	uint8 u8ESP_Received = RTE_E_INVALID;

	u8ESP_Received = ATT_GetMessage_ESP_Enable_Sts(&u8ESP_FailSts,&u8ESP_ActvInfo);

	if((STT_EBD_ABS_ESP == ESP_Config_Sts) || (STT_EBD_IBC == ESP_Config_Sts))
	{
		if (STT_GET_E2E(STT_enESP1_ESFD2) == STT_E2E_OK)
		{
			if (u8ESP_Received == RTE_E_OK)
			{
				if (u8ESP_FailSts == (uint8)STT_FUN_ACTIVE)
				{
					STT_SET(enSTT_ESP_Enable,TT_enTURN_ON);
				}
				else if ((u8ESP_FailSts == (uint8)STT_FUN_INACTIVE) && (u8ESP_ActvInfo == (uint8)STT_FUN_ACTIVE))
				{
					STT_SET(enSTT_ESP_Enable,TT_enFLASH_1_HZ);
				}
				else
				{
					STT_SET(enSTT_ESP_Enable,TT_enTURN_OFF);
				}
			}
			else
			{
				STT_SET(enSTT_ESP_Enable,TT_enTURN_ON);
			}
		}
		else
		{
			STT_SET(enSTT_ESP_Enable,TT_enTURN_ON);
		}
	}
}

/*******************************************************************************
*	Function name		: STT_vESP_Disable_Process
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
*
********************************************************************************/
void STT_vESP_Disable_Process(void)
{
	uint8 u8ESP_FunctionOffSts = 0;
	uint8 u8ESP_Received = RTE_E_INVALID;

	u8ESP_Received = ATT_GetMessage_ESP_Disable_Sts(&u8ESP_FunctionOffSts);
	//enum ESP_Enable is same as ESP_disable in E2E
	if((STT_EBD_ABS_ESP == ESP_Config_Sts) || (STT_EBD_IBC == ESP_Config_Sts))
	{
		if (STT_GET_E2E(STT_enESP1_ESFD2) == STT_E2E_OK)
		{
			if (u8ESP_Received == RTE_E_OK)
			{
				if(u8ESP_FunctionOffSts == (uint8)STT_FUN_ACTIVE)
				{
					STT_SET(enSTT_ESP_Disable,TT_enTURN_ON);
				}
				else
				{
					STT_SET(enSTT_ESP_Disable,TT_enTURN_OFF);
				}
			}
			else
			{
				STT_SET(enSTT_ESP_Disable,TT_enTURN_ON);
			}
		}
		else
		{
			STT_SET(enSTT_ESP_Disable,(uint8)TT_enTURN_ON);
		}
	}
}

/*******************************************************************************
*	Function name		: STT_vEPB_Failure_Process
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
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_EPB_Failure_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_EPB_Failure_ENABLE  1

#else
	#define TT_EPB_Failure_ENABLE  0
#endif

void STT_vEPB_Failure_Process(void)
{
	uint8 u8EPB_ERRSts = 0;
	uint8 u8EPB_Received = RTE_E_INVALID;
	boolean u8EPB_Config_Byte26_Sts = FALSE;
	ATT_DOMAIN_INFO u8EPB_Domain_Sts = ATT_DOMAIN_CH;
	TT_Safety_CFG_enStatType u8EpbErrorSts = TT_enTURN_OFF;

	u8EPB_Domain_Sts = ATT_vDomain_Logic_Process();
	if(TT_EPB_Failure_ENABLE != 0)
	{
		if (STT_GET_E2E(STT_enEPB1) == STT_E2E_OK)
		{
			u8EPB_Received = ATT_GetMessage_EPB_Sts(&u8EPB_ERRSts);

			if (2u == Config_Byte26_Parking)
			{
				u8EPB_Config_Byte26_Sts = TRUE;
			}
			else
			{
				u8EPB_Config_Byte26_Sts = FALSE;
			}

			if ((u8EPB_Config_Byte26_Sts) && (u8EPB_Domain_Sts != ATT_NO_DOMAIN))
			{
				if (u8EPB_Received == RTE_E_OK)
				{
					if (u8EPB_ERRSts == (uint8)STT_EPB_ERROR)
					{
						u8EpbErrorSts = TT_enTURN_ON;
					}
					else if (u8EPB_ERRSts == (uint8)STT_EPB_DIAG)
					{
						u8EpbErrorSts = TT_enFLASH_1_HZ;
					}
					else
					{
						u8EpbErrorSts = TT_enTURN_OFF;
					}
				}
				else
				{
					u8EpbErrorSts = TT_enTURN_ON;
				}
			}

			if (u8EPB_Domain_Sts == ATT_DOMAIN_CH)
			{
				STT_SET(enSTT_EPB_Fault_CH,u8EpbErrorSts);
				STT_SET(enSTT_EPB_Fault_US,TT_enTURN_OFF);
			}
			else if (u8EPB_Domain_Sts == ATT_DOMAIN_US)
			{
				STT_SET(enSTT_EPB_Fault_US,u8EpbErrorSts);
				STT_SET(enSTT_EPB_Fault_CH,TT_enTURN_OFF);
			}
			else
			{
				STT_SET(enSTT_EPB_Fault_CH,TT_enTURN_OFF);
				STT_SET(enSTT_EPB_Fault_US,TT_enTURN_OFF);
			}
		}
		else
		{
			if (2u == Config_Byte26_Parking)
			{
				if (u8EPB_Domain_Sts == ATT_DOMAIN_CH)
				{
					STT_SET(enSTT_EPB_Fault_CH,TT_enTURN_ON);
				}
				else
				{
					STT_SET(enSTT_EPB_Fault_US,TT_enTURN_ON);
				}
			}
			else
			{
				STT_SET(enSTT_EPB_Fault_CH,TT_enTURN_OFF);
				STT_SET(enSTT_EPB_Fault_US,TT_enTURN_OFF);
			}
		}
	}
}

/*******************************************************************************
*	Function name		: STT_vBreak_Error_Handle_Process
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
*
********************************************************************************/
void STT_vBreak_Error_Handle_Process(void)
{
	uint8 u8Break_EBDFailSts = 0;
	uint8 u8Break_Received = RTE_E_INVALID;
	ATT_DOMAIN_INFO Domain_Info = ATT_DOMAIN_CH;
	TT_Safety_CFG_enStatType u8BreakErrorSts = TT_enTURN_OFF;
	uint8 u8Break_OutPut = 0;

	Domain_Info = ATT_vDomain_Logic_Process();
	u8Break_Received = ATT_GetMessage_Break_Erro_Sts(&u8Break_EBDFailSts);
	(void)Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &u8Break_HW_Pin4);

	//Break error is same as ABS in E2E
	if((STT_EBD_ABS_ESP == Break_Config_Sts) || (STT_EBD_IBC == Break_Config_Sts))
	{
		if (STT_GET_E2E(STT_enABS3_ESPFD2) == STT_E2E_OK)
		{
			if ((STT_EBD_ABS_ESP == Break_Config_Sts) && (Domain_Info != ATT_NO_DOMAIN))
			{
				if (u8Break_HW_Pin4 == (uint8)STT_EBD_HW_LOW)
				{
					u8BreakErrorSts = TT_enTURN_ON;
					u8Break_OutPut = 1;
				}
				else
				{
					if (u8Break_Received == RTE_E_OK)
					{
						if(u8Break_EBDFailSts == (uint8)STT_FUN_ACTIVE)
						{
							u8BreakErrorSts = TT_enTURN_ON;
							u8Break_OutPut = 1;
						}
						else
						{
							u8BreakErrorSts = TT_enTURN_OFF;
							u8Break_OutPut = 0;
						}
					}
					else
					{
						u8BreakErrorSts = TT_enTURN_ON;
						u8Break_OutPut = 1;
					}
				}
			}
			else if((STT_EBD_IBC == Break_Config_Sts) && (Domain_Info != ATT_NO_DOMAIN))
			{
				//D01、D02、D03、signal TBD;
			}
			else
			{
				u8BreakErrorSts = TT_enTURN_OFF;
				u8Break_OutPut = 0;
			}


			if (Domain_Info == ATT_DOMAIN_CH)
			{
				STT_SET(enSTT_BreakError_CH,u8BreakErrorSts);
				STT_SET(enSTT_BreakError_US,TT_enTURN_OFF);
			}
			else if (Domain_Info == ATT_DOMAIN_US)
			{
				STT_SET(enSTT_BreakError_US,u8BreakErrorSts);
				STT_SET(enSTT_BreakError_CH,TT_enTURN_OFF);
			}
			else
			{
				STT_SET(enSTT_BreakError_CH,TT_enTURN_OFF);
				STT_SET(enSTT_BreakError_US,TT_enTURN_OFF);
			}
		}
		else
		{
			if (Domain_Info == ATT_DOMAIN_CH)
			{
				STT_SET(enSTT_BreakError_CH,TT_enTURN_ON);
			}
			else
			{
				STT_SET(enSTT_BreakError_US,TT_enTURN_ON);
			}

			u8Break_OutPut = 1;
		}
	}

	if(TRUE == SWC_STT_LOGOUT_ENBLE)
	{
		if(u8Break_HW_Pin4Pre != u8Break_HW_Pin4)
		{
			(void)SWC_STT_PRINT_WARN("STT_BreakErrorPin4: %d",u8Break_HW_Pin4);
			u8Break_HW_Pin4Pre = u8Break_HW_Pin4;
		}
	}

	if (u8TTselfchecksts == TT_SELFCHECKING)
	{
		(void)Rte_Write_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts(0);
	}
	else
	{
		(void)Rte_Write_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts(u8Break_OutPut);
	}

}


/*******************************************************************************
*	Function name		: STT_vEPS_Error_Handle_Process
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
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_EPS_Red_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_EPS_Red_Error_ENABLE  1

#else
	#define TT_EPS_Red_Error_ENABLE  0
#endif

void STT_vEPS_Error_Handle_Process(void)
{
	uint8 EPS_FailStatus = 0;
	uint8 u8EPS_Received = RTE_E_INVALID;

	if(TT_EPS_Red_Error_ENABLE != 0)
	{
		if (STT_GET_E2E(STT_enEPS1_EPSFD1) == STT_E2E_OK)
		{
			u8EPS_Received = ATT_GetMessage_EPS_Sts(&EPS_FailStatus);

			if (Config_Byte25_Steering == 1u)
			{
				if (u8EPS_Received == RTE_E_OK)
				{
					if (EPS_FailStatus == (uint8)STT_FUN_ACTIVE)
					{
						STT_SET(enSTT_EPS_Red_Error,TT_enTURN_ON);
						STT_SET(enSTT_EPS_Yellow_Error,TT_enTURN_OFF);
					}
					else if (EPS_FailStatus == (uint8)STT_FUN_STANDBY)
					{
						STT_SET(enSTT_EPS_Yellow_Error,TT_enTURN_ON);
						STT_SET(enSTT_EPS_Red_Error,TT_enTURN_OFF);
					}
					else
					{
						STT_SET(enSTT_EPS_Yellow_Error,TT_enTURN_OFF);
						STT_SET(enSTT_EPS_Red_Error,TT_enTURN_OFF);
					}
				}
				else
				{
					STT_SET(enSTT_EPS_Red_Error,TT_enTURN_ON);
					STT_SET(enSTT_EPS_Yellow_Error,TT_enTURN_OFF);
				}
			}
			else
			{
				STT_SET(enSTT_EPS_Yellow_Error,TT_enTURN_OFF);
				STT_SET(enSTT_EPS_Red_Error,TT_enTURN_OFF);
			}
		}
		else
		{
			if (Config_Byte25_Steering == 1u)
			{
				STT_SET(enSTT_EPS_Red_Error,TT_enTURN_ON);
				STT_SET(enSTT_EPS_Yellow_Error,TT_enTURN_OFF);
			}
			else
			{
				STT_SET(enSTT_EPS_Red_Error,TT_enTURN_OFF);
				STT_SET(enSTT_EPS_Yellow_Error,TT_enTURN_OFF);
			}
		}
	}
}

/*******************************************************************************
*	Function name		: STT_vABM_Error_Handle_Process
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
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_ABM_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_ABM_Error_ENABLE  1

#else
	#define TT_ABM_Error_ENABLE  0
#endif

void STT_vABM_Error_Handle_Process(void)
{
	uint8 u8ABM_FailLmpCmd = 0;
	uint8 u8ABM_Received = RTE_E_INVALID;
	uint8 u8ABMWarnLmpFailrStsOut =   0;

	if(TT_ABM_Error_ENABLE != 0)
	{
		if (STT_GET_E2E(STT_enABM1) == STT_E2E_OK)
		{
			u8ABM_Received = ATT_GetMessage_ABM_Sts(&u8ABM_FailLmpCmd);

			if (u8ABM_Received == RTE_E_OK)
			{
				if (u8ABM_FailLmpCmd == (uint8)STT_FUN_ACTIVE)
				{
					STT_SET(enSTT_ABM_Error,TT_enTURN_ON);
				}
				else
				{
					STT_SET(enSTT_ABM_Error,TT_enTURN_OFF);
				}
			}
			else
			{
				STT_SET(enSTT_ABM_Error,TT_enTURN_ON);
			}
		}
		else
		{
			STT_SET(enSTT_ABM_Error,TT_enTURN_ON);
		}
	}
	#if (!defined GWM_V35_PROJECT_TYPE_P03)
	(void)Rte_Write_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element(u8ABMWarnLmpFailrStsOut);
	#endif
}

/*******************************************************************************
*	Function name		: STT_vFCW_Handle_Process
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
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_FCW_Error_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_FCW_Error_ENABLE  1

#else
	#define TT_FCW_Error_ENABLE  0
#endif

// tips: requirement change, FCW non safety telltale.
void STT_vFCW_Handle_Process(void)
{
	uint8 u8FCW_AEB_VehFctSts = 0;
	uint8 u8FCW_AEB_VehResp = 0;
	uint8 u8FCW_AEB_PedResp = 0;
	uint8 u8FCW_AEB_JA_Resp = 0;
	uint8 u8FCW_Received = RTE_E_INVALID;

	if(TT_FCW_Error_ENABLE != 0)
	{
		u8FCW_Received = ATT_GetMessage_FCW_Sts(&u8FCW_AEB_VehFctSts,&u8FCW_AEB_VehResp,&u8FCW_AEB_PedResp,&u8FCW_AEB_JA_Resp);
		if ((1u == Config_Byte10_FCW) || (2u == Config_Byte10_FCW) || (3u == Config_Byte10_FCW)\
			|| (4u == Config_Byte10_FCW) || (5u == Config_Byte10_FCW) || (1u == Config_Byte46_Junction))
		{
			if (u8FCW_Received == RTE_E_OK)
			{
				STT_SET(enSTT_FCW_Enable,TT_enTURN_OFF);
				STT_SET(enSTT_FCW_Error,TT_enTURN_OFF);
				STT_SET(enSTT_FCW_Off,TT_enTURN_OFF);

				if (u8FCW_AEB_VehFctSts == (uint8)STT_FUN_ACTIVE)
				{
					STT_SET(enSTT_FCW_Error,TT_enTURN_ON);
				}
				else if ((u8FCW_AEB_VehFctSts == (uint8)STT_FUN_STANDBY) || (u8FCW_AEB_VehFctSts == (uint8)STT_FUN_RESERVE))
				{
					STT_SET(enSTT_FCW_Off,TT_enTURN_ON);
				}
				else if ((u8FCW_AEB_VehResp == (uint8)STT_FUN_INACTIVE) && (u8FCW_AEB_PedResp == (uint8)STT_FUN_INACTIVE) \
					&& (u8FCW_AEB_JA_Resp == (uint8)STT_FUN_INACTIVE))
				{
					STT_SET(enSTT_FCW_Off,TT_enTURN_ON);
				}
				else if((u8FCW_AEB_VehFctSts == (uint8)STT_FUN_INACTIVE) && ((u8FCW_AEB_VehResp == (uint8)STT_FUN_ACTIVE) \
					|| (u8FCW_AEB_PedResp == (uint8)STT_FUN_ACTIVE) || (u8FCW_AEB_JA_Resp == (uint8)STT_FUN_ACTIVE)))
				{
					STT_SET(enSTT_FCW_Enable,TT_enTURN_ON);
				}
			}
			else
			{
				STT_SET(enSTT_FCW_Error,TT_enTURN_ON);
				STT_SET(enSTT_FCW_Enable,TT_enTURN_OFF);
				STT_SET(enSTT_FCW_Off,TT_enTURN_OFF);
			}
		}
		else
		{
			STT_SET(enSTT_FCW_Error,TT_enTURN_OFF);
			STT_SET(enSTT_FCW_Enable,TT_enTURN_OFF);
			STT_SET(enSTT_FCW_Off,TT_enTURN_OFF);
		}

		if(u16SttIgnOnDelayTimeTick < 300u)
		{
			STT_SET(enSTT_FCW_Error,TT_enTURN_OFF);
			STT_SET(enSTT_FCW_Enable,TT_enTURN_OFF);
			STT_SET(enSTT_FCW_Off,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: STT_vPBF_Handle_Process
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
*	Description 		: PBF Derating Function Safety

*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_PBF_Red_PHEV_ENABLE	0
	#define TT_PBF_Red_P0_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_PBF_Red_PHEV_ENABLE	1
	#define TT_PBF_Red_P0_ENABLE	0

#else
	#define TT_PBF_Red_PHEV_ENABLE	0
	#define TT_PBF_Red_P0_ENABLE	0
#endif

void STT_vPBF_Handle_Process(void)
{
	uint8 u8PBF_Received = 0;
	uint8 u8PBF_ERRCategory = 0;

	u8PBF_Received = ATT_GetMessage_PBF_Sts(&u8PBF_ERRCategory);

	if(TT_PBF_Red_PHEV_ENABLE != 0)
	{	//PHEV
		if ((((3u == Config_Byte2_Fuel) || (4u == Config_Byte2_Fuel)) \
			&& ((5u == Config_Byte30_Electro) || (6u == Config_Byte30_Electro))) \
			|| ((4u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) \
			|| (4u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))) \
			|| ((3u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))))
		{
			if (STT_GET_E2E(STT_enBMS4) == STT_E2E_OK)
			{
				if (u8PBF_Received == RTE_E_OK)
				{
					if ((u8PBF_ERRCategory == (uint8)STT_PBF_INSTRUMENT_DISPLAY) || (u8PBF_ERRCategory == (uint8)STT_PBF_RANGE_LIMITED))
					{
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_ON);
						STT_SET(enSTT_PBF_Red,TT_enTURN_OFF);
					}
					else if ((u8PBF_ERRCategory == (uint8)STT_PBF_PRECHARGE_LOCKED) || (u8PBF_ERRCategory == (uint8)STT_PBF_DELAYED_OPEN) \
						|| (u8PBF_ERRCategory == (uint8)STT_PBF_EMERGENCY_OPEN))
					{
						STT_SET(enSTT_PBF_Red,TT_enTURN_ON);
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
					}
					else
					{
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
						STT_SET(enSTT_PBF_Red,TT_enTURN_OFF);
					}
				}
				else
				{
					if (u8PowerSts == STT_CLUSTER_ON)
					{
						STT_SET(enSTT_PBF_Red,TT_enTURN_ON);
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
					}
					else
					{
						STT_SET(enSTT_PBF_Red,TT_enTURN_OFF);
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
					}
				}
			}
			else
			{
				STT_SET(enSTT_PBF_Red,TT_enTURN_ON);
				STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
			}
		}
	}

	if(TT_PBF_Red_P0_ENABLE != 0)//P0
	{
		if (((0u == Config_Byte2_Fuel) || (1u == Config_Byte2_Fuel) || (2u == Config_Byte2_Fuel) \
			|| (7u == Config_Byte2_Fuel)) && (1u == Config_Byte30_Electro))
		{
			if (STT_GET_E2E(STT_enBMS4) == STT_E2E_OK)
			{
				if (u8PBF_Received == RTE_E_OK)
				{
					if ((uint8)STT_PBF_PRECHARGE_LOCKED == u8PBF_ERRCategory)
					{
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_ON);
						STT_SET(enSTT_PBF_Red,TT_enTURN_OFF);
					}
					else if ((uint8)STT_PBF_EMERGENCY_OPEN == u8PBF_ERRCategory)
					{
						STT_SET(enSTT_PBF_Red,TT_enTURN_ON);
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
					}
					else
					{
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
						STT_SET(enSTT_PBF_Red,TT_enTURN_OFF);
					}
				}
				else
				{
					if (u8PowerSts == STT_CLUSTER_ON)
					{
						STT_SET(enSTT_PBF_Red,TT_enTURN_ON);
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
					}
					else
					{
						STT_SET(enSTT_PBF_Red,TT_enTURN_OFF);
						STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
					}
				}
			}
			else
			{
				STT_SET(enSTT_PBF_Red,TT_enTURN_ON);
				STT_SET(enSTT_PBF_Yellow,TT_enTURN_OFF);
			}
		}
	}
}


/*******************************************************************************
*	Function name		: STT_vHEV_Handle_Process
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
						Hybrid electric vehicle
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_HEV_Handle_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_HEV_Handle_ENABLE  1

#else
	#define TT_HEV_Handle_ENABLE  0
#endif

void STT_vHEV_Handle_Process(void)
{
	uint8 u8HEV_Received = 0;
	uint8 u8HEV_HybSysErrLmp = 0;

	u8HEV_Received = ATT_GetMessage_HEV_Sts(&u8HEV_HybSysErrLmp);

	if(TT_HEV_Handle_ENABLE != 0)
	{
		if (((4u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) \
			|| (4u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))) \
			|| (((4u == Config_Byte2_Fuel) || (3u == Config_Byte2_Fuel)) \
			&& ((5u == Config_Byte30_Electro) || (6u == Config_Byte30_Electro))) \
			|| (((0u == Config_Byte2_Fuel) || (1u == Config_Byte2_Fuel) || (2u == Config_Byte2_Fuel) \
			|| (7u == Config_Byte2_Fuel)) && (1u == Config_Byte30_Electro)) \
			|| ((3u == Config_Byte2_Fuel) && (8u == Config_Byte30_Electro)))
		{
			if (STT_GET_E2E(STT_enHCUPT7) == STT_E2E_OK)
			{
				if (u8HEV_Received == RTE_E_OK)
				{
					if (u8HEV_HybSysErrLmp == (uint8)STT_FUN_ACTIVE)
					{
						STT_SET(enSTT_HEV_Yellow,TT_enTURN_ON);
						STT_SET(enSTT_HEV_Red,TT_enTURN_OFF);
					}
					else if (u8HEV_HybSysErrLmp == (uint8)STT_FUN_STANDBY)
					{
						STT_SET(enSTT_HEV_Red,TT_enTURN_ON);
						STT_SET(enSTT_HEV_Yellow,TT_enTURN_OFF);
					}
					else
					{
						STT_SET(enSTT_HEV_Yellow,TT_enTURN_OFF);
						STT_SET(enSTT_HEV_Red,TT_enTURN_OFF);
					}
				}
				else
				{
					if (u8PowerSts == STT_CLUSTER_ON)
					{
						STT_SET(enSTT_HEV_Yellow,TT_enTURN_OFF);
						STT_SET(enSTT_HEV_Red,TT_enTURN_ON);
					}
					else
					{
						STT_SET(enSTT_HEV_Yellow,TT_enTURN_OFF);
						STT_SET(enSTT_HEV_Red,TT_enTURN_OFF);
					}
				}
			}
			else
			{
				STT_SET(enSTT_HEV_Yellow,TT_enTURN_OFF);
				STT_SET(enSTT_HEV_Red,TT_enTURN_ON);
			}
		}
		else
		{
			STT_SET(enSTT_HEV_Yellow,TT_enTURN_OFF);
			STT_SET(enSTT_HEV_Red,TT_enTURN_OFF);
		}
	}
}


/*******************************************************************************
*	Function name		: STT_vTPF_Handle_Process
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
						twelve power failure
*
********************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_TPF_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_TPF_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_TPF_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_TPF_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_TPF_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define TT_TPF_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define TT_TPF_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define TT_TPF_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define TT_TPF_ENABLE  1
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define TT_TPF_ENABLE  1

#else
	#define TT_TPF_ENABLE  0
#endif

void STT_vTPF_Handle_Process(void)
{
	uint8 u8TPF_Received = 0;
	uint8 u8TPF_SysErrLmpSts = 0;

	u8TPF_Received = ATT_GetMessage_TPF_Sts(&u8TPF_SysErrLmpSts);

	if(TT_TPF_ENABLE != 0)
	{
		if (((4u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) || (4u == Config_Byte30_Electro) \
			|| (5u == Config_Byte30_Electro) || (6u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))) \
			|| ((3u == Config_Byte2_Fuel) && ((2u == Config_Byte30_Electro) || (5u == Config_Byte30_Electro) \
			|| (6u == Config_Byte30_Electro) || (8u == Config_Byte30_Electro))))
		{
			if (STT_GET_E2E(STT_enHCUPT7) == STT_E2E_OK)
			{
				if (u8TPF_Received == RTE_E_OK)
				{
					if (u8TPF_SysErrLmpSts == (uint8)STT_FUN_ACTIVE)
					{
						STT_SET(enSTT_TPF,TT_enTURN_ON);
					}
					else
					{
						STT_SET(enSTT_TPF,TT_enTURN_OFF);
					}
				}
				else
				{
					if (u8PowerSts == STT_CLUSTER_ON)
					{
						STT_SET(enSTT_TPF,TT_enTURN_ON);
					}
					else
					{
						STT_SET(enSTT_TPF,TT_enTURN_OFF);
					}
				}
			}
			else
			{
				STT_SET(enSTT_TPF,TT_enTURN_ON);
			}
		}
	}
	else
	{
		STT_SET(enSTT_TPF,TT_enTURN_OFF);
	}
}


/*******************************************************************************
*	Function name		: STT_vEPark_Handle_Process
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
#if 0
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_EPark_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_EPark_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_EPark_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_EPark_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_EPark_ENABLE  0
#else
	#define TT_EPark_ENABLE  0
#endif

void STT_vEPark_Handle_Process(void)
{
	//uint8 u8EPARK_Received = 0;
	//uint8 u8EPARK_FaultSts = 0;

	//static uint8 test_byte2 = 5;
	//static uint8 test_byte41 = 1;

	//u8EPARK_Config_Byte2 = test_byte2;
	//u8EPARK_Config_Byte41 = test_byte41;
	// config is ok ,signal miss

	if(TT_EPark_ENABLE != 0)
	{
		if ((5u == Config_Byte2_Fuel) && (1u == Config_Byte41_Epark))
		{
			if (TT_CFG_CAN_EPARK_STS_MSG_HAS_RECEIVED)
			{
				if (TT_CFG_CAN_CONDITION_OF_PARK_FAULT_LMP_STS_TURN_ON == STT_FUN_ACTIVE)
				{
					STT_SET(enSTT_EPark,TT_enTURN_ON);
				}
				else
				{
					STT_SET(enSTT_EPark,TT_enTURN_OFF);
				}

			}
			else
			{
				STT_SET(enSTT_EPark,TT_enTURN_OFF);
			}
		}
		else
		{
			STT_SET(enSTT_EPark,TT_enTURN_OFF);

		}
	}
	//config is ok ,but signal can't found in dbc;
}
#endif

/*******************************************************************************
*	Function name		: STT_vDC_Handle_Process
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
*
********************************************************************************/
#if 0
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_DC_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_DC_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_DC_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_DC_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_DC_ENABLE  0
#else
	#define TT_DC_ENABLE  0
#endif

void STT_vDC_Handle_Process(void)
{

	//config is ok ,signal miss
	if(TT_DC_ENABLE != 0)
	{
		if (5u == Config_Byte2_Fuel)
		{
			if (TT_CFG_CAN_DCDC_FD1_HAS_RECEIVED)
			{
				if ((TT_CFG_CAN_CONDITION_DCDC_FAIL_STS_TURN_ON == STT_FUN_STANDBY) || (TT_CFG_CAN_CONDITION_DCDC_FAIL_STS_TURN_ON == STT_FUN_RESERVE))
				{
					STT_SET(enSTT_DC_Alert,TT_enTURN_ON);
				}
				else
				{
					STT_SET(enSTT_DC_Alert,TT_enTURN_OFF);
				}
			}
			else
			{
				STT_SET(enSTT_DC_Alert,TT_enTURN_OFF);
			}
		}
		else
		{
			STT_SET(enSTT_DC_Alert,TT_enTURN_OFF);
		}
	}
}
#endif
/*******************************************************************************
*	Function name		: STT_vMotor_Failure_Process
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
*
********************************************************************************/
#if 0
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define TT_Motor_Failure_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define TT_Motor_Failure_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define TT_Motor_Failure_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define TT_Motor_Failure_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define TT_Motor_Failure_ENABLE  0
#else
	#define TT_Motor_Failure_ENABLE  0
#endif

void STT_vMotor_Failure_Process(void)
{

	//config is ok ,signal is miss
	if(TT_Motor_Failure_ENABLE != 0)
	{
		if (5u == Config_Byte2_Fuel)
		{
			if ((TT_CFG_CAN_MOTOR_FAILURE_HAS_RECEIVED) && (TT_CFG_CAN_CONDITION_MOTOR_FAILURE_TURN_ON))
			{
				STT_SET(enSTT_Motor_Failure,TT_enTURN_ON);
			}
			else
			{
				STT_SET(enSTT_Motor_Failure,TT_enTURN_OFF);
			}
		}
		else
		{
			STT_SET(enSTT_Motor_Failure,TT_enTURN_OFF);

		}
	}
}
#endif

void STT_GetSelfcheckReportStatus(void)
{
	uint8 u8Index = 0;

	if(u8TTselfchecksts == TT_SELFCHECK_OK)
	{
		for(u8Index = 0; u8Index < STT_CFG_SelfcheckReport_COUNT; u8Index ++)
		{
			if(TT_status[STT__SelfcheckReport[u8Index]].Safety_TT_Data == TT_enTURN_ON)
			{
				STT_boSelfcheckReportsts = TRUE;
			}
		}
	}
	else
	{
		/*tips: self check & KL15ON within 3s different*/
		if(TT_status[enSTT_FCW_Error].Safety_TT_Data == TT_enTURN_ON)
		{
			STT_boSelfcheckReportsts = TRUE;
		}
	}
}

boolean STT_boSendSelfcheckReportsts(void)
{
	return STT_boSelfcheckReportsts;
}

void STT_Function_Safety_SBUS(void)
{
	if (ATT_DOMAIN_CH == ATT_vDomain_Logic_Process())
	{
		ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ABS_Fault_US_Data_selfcheck = 0;
		ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPB_Fault_US_Data_selfcheck = 0;
		ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.BreakError_US_Data_selfcheck = 0;
    	ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ABS_Fault_CH_Data_selfcheck =  TT_status[enSTT_ABS_Fault_CH].SelfCheckSts ? 1u:0u;
    	ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPB_Fault_CH_Data_selfcheck  = TT_status[enSTT_EPB_Fault_CH].SelfCheckSts ? 1u:0u;
    	ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.BreakError_CH_Data_selfcheck = TT_status[enSTT_BreakError_CH].SelfCheckSts? 1u:0u;
	}
	else
	{
		ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ABS_Fault_CH_Data_selfcheck = 0;
    	ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPB_Fault_CH_Data_selfcheck = 0;
    	ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.BreakError_CH_Data_selfcheck = 0;
		ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ABS_Fault_US_Data_selfcheck  = TT_status[enSTT_ABS_Fault_US].SelfCheckSts ? 1u:0u;
		ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPB_Fault_US_Data_selfcheck  = TT_status[enSTT_EPB_Fault_US].SelfCheckSts ? 1u:0u;
		ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.BreakError_US_Data_selfcheck = TT_status[enSTT_BreakError_US].SelfCheckSts? 1u:0u;
	}


    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ABS_Fault_CH_Data = TT_status[enSTT_ABS_Fault_CH].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ABS_Fault_US_Data = TT_status[enSTT_ABS_Fault_US].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ESP_Enable_Data_selfcheck = TT_status[enSTT_ESP_Enable].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ESP_Enable_Data = TT_status[enSTT_ESP_Enable].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ESP_Disable_Data_selfcheck = TT_status[enSTT_ESP_Disable].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ESP_Disable_Data = TT_status[enSTT_ESP_Disable].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPB_Fault_CH_Data = TT_status[enSTT_EPB_Fault_CH].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPB_Fault_US_Data = TT_status[enSTT_EPB_Fault_US].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.BreakError_CH_Data = TT_status[enSTT_BreakError_CH].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.BreakError_US_Data = TT_status[enSTT_BreakError_US].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPS_Red_Error_Data_selfcheck = TT_status[enSTT_EPS_Red_Error].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPS_Red_Error_Data = TT_status[enSTT_EPS_Red_Error].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPS_Yellow_Error_Data_selfcheck = TT_status[enSTT_EPS_Yellow_Error].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPS_Yellow_Error_Data = TT_status[enSTT_EPS_Yellow_Error].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ABM_Error_Data_selfcheck = TT_status[enSTT_ABM_Error].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.ABM_Error_Data = TT_status[enSTT_ABM_Error].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.FCW_Error_Data_selfcheck = TT_status[enSTT_FCW_Error].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.FCW_Error_Data = TT_status[enSTT_FCW_Error].Safety_TT_Data;
	ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.FCW_Enable_Data_selfcheck = TT_status[enSTT_FCW_Enable].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.FCW_Enable_Data = TT_status[enSTT_FCW_Enable].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.PBF_Derating_Data_selfcheck = TT_status[enSTT_PBF_Red].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.PBF_Derating_Data = TT_status[enSTT_PBF_Red].Safety_TT_Data;
	ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.PBF_Warning_Data_selfcheck = TT_status[enSTT_PBF_Yellow].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.PBF_Warning_Data = TT_status[enSTT_PBF_Yellow].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.HEV_Yellow_Data_selfcheck = TT_status[enSTT_HEV_Yellow].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.HEV_Yellow_Data = TT_status[enSTT_HEV_Yellow].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.HEV_Red_Data_selfcheck = TT_status[enSTT_HEV_Red].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.HEV_Red_Data = TT_status[enSTT_HEV_Red].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.TPF_Data_selfcheck = TT_status[enSTT_TPF].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.TPF_Data = TT_status[enSTT_TPF].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPark_Data_selfcheck = TT_status[enSTT_EPark].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.EPark_Data = TT_status[enSTT_EPark].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.DC_Alert_Data_selfcheck = TT_status[enSTT_DC_Alert].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.DC_Alert_Data = TT_status[enSTT_DC_Alert].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.Motor_Failure_Data_selfcheck = TT_status[enSTT_Motor_Failure].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.Motor_Failure_Data = TT_status[enSTT_Motor_Failure].Safety_TT_Data;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.FCW_Off_Data_selfcheck = TT_status[enSTT_FCW_Off].SelfCheckSts ? 1u:0u;
    ToSBUS_TT_Safety_status32.u_TT_Safetyu32Telltales_status_t.s_u32Telltales_status_t.FCW_Off_Data = TT_status[enSTT_FCW_Off].Safety_TT_Data;

	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_SAFTY_TELLTALE,(uint8*)&ToSBUS_TT_Safety_status32,(uint16)(sizeof(IPC_M2S_SAFETYAPPTT_Safety_t)),FALSE);
    //  if (memcmp(&ToSBUS_TT_Safety_status32,&ToSBUS_TT_Safety_status32_Pre,sizeof(ToSBUS_TT_Safety_status32)) != 0)
    // {
    //     IPC_M2S_ClusterAppAPPTT_Safety_Transmit(&ToSBUS_TT_Safety_status32);
    //     memcpy(&ToSBUS_TT_Safety_status32_Pre,&ToSBUS_TT_Safety_status32,sizeof(ToSBUS_TT_Safety_status32));
    // }
	if(TRUE == boSTTIpcCallback)
	{
		STT_SafetyTT_CRC_Check();

		boSTTIpcCallback = FALSE;
	}
}

void STT_SafetyTT_CRC_Check(void)
{
	uint16 ttNum = 0;
	uint16 index = 0;

	//Rte_Enter_ExclusiveArea_Safety();
	ttNum = (uint16)(TTCRCData.TT_CRCLength / 5u);
	(void)memset(&ipcTTACKData, 0, sizeof(IPC_M2S_SAFETYAPPSafetyTelltaleCheck_t));
	for(index = 0; index < (uint16)TTCRCData.TT_CRCLength; index+=5u)
	{
		crcData[index].TT_ID = TTCRCData.TT_CRC[index];
		crcData[index].CRC_Value = getByteData(TTCRCData.TT_CRC,index);
		if(TTCrcTable[crcData[index].TT_ID] == crcData[index].CRC_Value)
		{
			ipcTTACKData.TT_ACK[index*2u/5u] = crcData[index].TT_ID;
			ipcTTACKData.TT_ACK[(((index*2u)/5u)+1u)] = 1u;
		}
		else
		{
			ipcTTACKData.TT_ACK[index*2u/5u] = crcData[index].TT_ID;
			ipcTTACKData.TT_ACK[(((index*2u)/5u)+1u)] = 0u;
		}
	}

	ipcTTACKData.TT_ACKLength = (uint16)(2u * ttNum * (uint16)sizeof(uint8));
	(void)IPC_M2S_SAFETYAPPSafetyTelltaleCheck_Transmit(&ipcTTACKData);
	//Rte_Exit_ExclusiveArea_Safety();
}

FUNC(void, RTE_CODE) IPC_API_ReceiveSafetyTTCRCCallback(uint8 *data)
{
	if(data != NULL)
	{
		const IPC_S2M_SAFETYAPPSafetyTTCRC_t *RcTTCRC;
		RcTTCRC = (IPC_S2M_SAFETYAPPSafetyTTCRC_t *)data;
		(void)memcpy(&TTCRCData, RcTTCRC, sizeof(IPC_S2M_SAFETYAPPSafetyTTCRC_t));
		boSTTIpcCallback = TRUE;
	}
}


#define Common_Safety_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"


/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

