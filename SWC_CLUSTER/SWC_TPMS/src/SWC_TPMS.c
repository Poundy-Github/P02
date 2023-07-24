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
*File Name   : SWC_TPMS.c                                                                                 *
*                                                                                                         *
*Description : TPMS module application source file.                                                       *
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


/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/
#include "SWC_TPMS.h"
#include "SWC_TPMS_config.h"
#include "SWC_IPC_Manager.h"
#include "Rte_Common_Normal.h"
#include "SWC_IPC_Config.h"
#include "CConfig_Cfg.h"

/*****************************************************************************
*                                 Globally  accessed Variable Declarations   *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/
/*****************************************************************************
*                               No Init Variable                             *
******************************************************************************/
#define Common_Normal_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"
static TPMS_str TPMS_Info;
static TPMS_VCfg_str  TPMS_VCfg;
static uint16 tpmsUpdateCnt;
#define Common_Normal_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"
/*****************************************************************************
*                                 Init Variable                             *
******************************************************************************/
#define Common_Normal_START_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"

#define Common_Normal_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"

/*****************************************************************************
*                                 Const Variable                             *
******************************************************************************/
#define Common_Normal_START_SEC_CONST_UNSPECIFIED
#include "Common_Normal_MemMap.h"

#define Common_Normal_STOP_SEC_CONST_UNSPECIFIED
#include "Common_Normal_MemMap.h"

/*****************************************************************************
*                                 Functions                                  *
******************************************************************************/
#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h" 

static void TPMSMdl_TPMS_process(void);
static void TPMSMdl_Set_vehicle_config(void);
static void TPMSMdl_SBUS_send_TPMS_inf(void);
static void TPMSMdl_TPMS_unit_check(void);
static uint16 TPMSMdl_TireTemperature_calculate(uint8 u8TireTempVal);
static uint16 TPMSMdl_TirePressure_calculate(uint8 u8TirePressVal);
static void TPMSMdl_vCheckPowerMode(TPMS_POWER_MODE *enPowerMode);

/*******************************************************************************
*
*   Function:           TPMSMdl_TPMS_cold_init
*
*   Description:        This function performs a Cold reset Initialization
*                       of the TPMS.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void TPMSMdl_TPMS_cold_init(void)
{
	TPMSMdl_Set_vehicle_config();
	
	switch(TPMS_VCfg.u8UnitSystem)
	{
		case UNIT_METRIC:
			TPMS_Info.tire_press_unit = TPMS_KPA;
			TPMS_Info.tire_temp_unit = TPMS_CELSIUS;
			break;
		case UNIT_JAPANESE_METRIC:
			TPMS_Info.tire_press_unit = TPMS_KPA;
			TPMS_Info.tire_temp_unit = TPMS_CELSIUS;
			break;
		case UNIT_UK_IMPERIAL:
			TPMS_Info.tire_press_unit = TPMS_PSI;
			TPMS_Info.tire_temp_unit = TPMS_CELSIUS;
			break;
		case UNIT_US_IMPERIAL:
			TPMS_Info.tire_press_unit = TPMS_PSI;
			TPMS_Info.tire_temp_unit = TPMS_FAHRENHEIT;
			break;
		default:
			TPMS_Info.tire_press_unit = TPMS_KPA;
			TPMS_Info.tire_temp_unit = TPMS_CELSIUS;
			break;
	}
	TPMS_Info.fl_tpms.tire_press_status = TPMS_OFF;
	TPMS_Info.fl_tpms.tire_press_value = 0;
	TPMS_Info.fl_tpms.tire_temp_status = TPMS_OFF;
	TPMS_Info.fl_tpms.tire_temp_value = 0;
	TPMS_Info.fr_tpms.tire_press_status = TPMS_OFF;
	TPMS_Info.fr_tpms.tire_press_value = 0;
	TPMS_Info.fr_tpms.tire_temp_status = TPMS_OFF;
	TPMS_Info.fr_tpms.tire_temp_value = 0;
	TPMS_Info.rl_tpms.tire_press_status = TPMS_OFF;
	TPMS_Info.rl_tpms.tire_press_value = 0;
	TPMS_Info.rl_tpms.tire_temp_status = TPMS_OFF;
	TPMS_Info.rl_tpms.tire_temp_value = 0;
	TPMS_Info.rr_tpms.tire_press_status = TPMS_OFF;
	TPMS_Info.rr_tpms.tire_press_value = 0;
	TPMS_Info.rr_tpms.tire_temp_status = TPMS_OFF;
	TPMS_Info.rr_tpms.tire_temp_value = 0;
	TPMS_Info.tire_press_unit = TPMS_KPA;
	TPMS_Info.tire_temp_unit = TPMS_CELSIUS;
	TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
	TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
	TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
	TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
	TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
	TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
	TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
	TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
	TPMS_Info.rr_tpms.tire_behavior_color = TPMS_TIRE_OFF;
	TPMS_Info.fl_tpms.tire_behavior_color = TPMS_TIRE_OFF;
	TPMS_Info.fr_tpms.tire_behavior_color = TPMS_TIRE_OFF;
	TPMS_Info.rl_tpms.tire_behavior_color = TPMS_TIRE_OFF;
	tpmsUpdateCnt = 0;
}

/*******************************************************************************
*
*   Function:           TPMSMdl_TPMS_warm_init
*
*   Description:        This function performs a warm reset Initialization
*                       of the TPMS.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void TPMSMdl_TPMS_warm_init(void)
{	
	TPMS_Info.fl_tpms.tire_press_status = TPMS_DASH;
	TPMS_Info.fr_tpms.tire_press_status = TPMS_DASH;
	TPMS_Info.rl_tpms.tire_press_status = TPMS_DASH;
	TPMS_Info.rr_tpms.tire_press_status = TPMS_DASH;
	TPMS_Info.fl_tpms.tire_temp_status = TPMS_DASH;
	TPMS_Info.fr_tpms.tire_temp_status = TPMS_DASH;
	TPMS_Info.rl_tpms.tire_temp_status = TPMS_DASH;
	TPMS_Info.rr_tpms.tire_temp_status = TPMS_DASH;
	TPMS_Info.fl_tpms.tire_press_value = 0;
	TPMS_Info.fr_tpms.tire_press_value = 0;
	TPMS_Info.rl_tpms.tire_press_value = 0;
	TPMS_Info.rr_tpms.tire_press_value = 0;
	TPMS_Info.fl_tpms.tire_temp_value = 0;
	TPMS_Info.fr_tpms.tire_temp_value = 0;
	TPMS_Info.rl_tpms.tire_temp_value = 0;
	TPMS_Info.rr_tpms.tire_temp_value = 0;
	
	TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
	TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
	TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
	TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
	TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
	TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
	TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
	TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
	TPMS_Info.rr_tpms.tire_behavior_color = TPMS_TIRE_OFF;
	TPMS_Info.fl_tpms.tire_behavior_color = TPMS_TIRE_OFF;
	TPMS_Info.fr_tpms.tire_behavior_color = TPMS_TIRE_OFF;
	TPMS_Info.rl_tpms.tire_behavior_color = TPMS_TIRE_OFF;
	
}

/*******************************************************************************
*
*   Function:           TPMSMdl_TPMS_app_tsk
*
*   Description:        This function performs implementation of the TPMS.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void TPMSMdl_TPMS_app_tsk(void)
{
	TPMS_POWER_MODE PowerMode;
	
	TPMSMdl_vCheckPowerMode(&PowerMode);
	TPMSMdl_Set_vehicle_config();
	
	if((TPMS_VCfg.u8TPMSSystem == 0x1) \
		&& (TPMS_VCfg.u8CcfgTPMSDisplayEnable == 0x1)) /* 01:胎压监测系统Enable */
	{
		if(PowerMode == TPMS_CLUSTER_NORMAL)
		{
			/* TPMS Unit */
			TPMSMdl_TPMS_unit_check();
			TPMSMdl_TPMS_process();
			TPMSMdl_SBUS_send_TPMS_inf();
		}
		else
		{
			//TPMSMdl_TPMS_warm_init();
			tpmsUpdateCnt = 0;			
		}
	}
	else
	{
		//TPMSMdl_TPMS_warm_init();
		tpmsUpdateCnt = 0;
	}

	//TPMSMdl_SBUS_send_TPMS_inf();
}


static void TPMSMdl_Set_vehicle_config(void)
{
	VconfigKind_Allbuffers VCfg_kindBuffers;
	CconfigKind_400Bytes CconfigKind;
	uint16 u16CcfgRefreshRateTPMS = 0;
	uint8 u8CcfgTPMSDisplayEnable = 1;
	
	if (E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(CconfigKind))
    {
        u16CcfgRefreshRateTPMS = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateTPMS, CconfigKind);
        u8CcfgTPMSDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_TPMSDisplayEnable, CconfigKind);
    }
    else
    {
        u16CcfgRefreshRateTPMS = 30;
        u8CcfgTPMSDisplayEnable = 1;
    }

    (void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VCfg_kindBuffers);
	TPMS_VCfg.u8InitFlag = VCfg_kindBuffers[VCONFIG_KIND_INIT_FLAG];
	
	if(TPMS_VCfg.u8InitFlag == TRUE)
	{
		TPMS_VCfg.u8UnitSystem = VCfg_kindBuffers[VCONFIG_KIND_CLUSTER_UNIT_SYSTEM];
		TPMS_VCfg.u8TPMSSystem = VCfg_kindBuffers[VCONFIG_KIND_TPMS];/* byte39 bit4-3:01 */
	}
	TPMS_VCfg.u16CcfgRefreshRateTPMS = u16CcfgRefreshRateTPMS;
	TPMS_VCfg.u8CcfgTPMSDisplayEnable = u8CcfgTPMSDisplayEnable;
}

uint8 TPMSMdl_get_vehicle_config(void)
{
	return 0;
}

static void TPMSMdl_vCheckPowerMode(TPMS_POWER_MODE *enPowerMode)
{
	SystemState_RecordType *u8PowerMode;
	
	u8PowerMode = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
	if((u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_NORMAL) \
		&& (u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_LOWALARM) \
		&& (u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_HIGHALARM))
	{
		*enPowerMode = TPMS_CLUSTER_ABNORMAL;
	}
	else
	{
		if(SYSTEMSTATE_Cluster_OFF == u8PowerMode->ClusterState)			
		{
			*enPowerMode = TPMS_CLUSTER_SLEEP;		
		}
		else if(SYSTEMSTATE_Cluster_ON == u8PowerMode->ClusterState)
		{
			*enPowerMode = TPMS_CLUSTER_NORMAL;
		}		
		else
		{
			*enPowerMode = TPMS_CLUSTER_OFF;
		}
	}	
}

static void TPMSMdl_SBUS_send_TPMS_inf(void)
{
	IPC_M2S_ClusterAppAPPTPMS_t ipc_sendTPMS;
	
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fl_tire_press_status = TPMS_Info.fl_tpms.tire_press_status;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fl_tire_press_value = TPMS_Info.fl_tpms.tire_press_value;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fl_tire_press_color = TPMS_Info.fl_tpms.tire_press_color;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fl_tire_temp_status = TPMS_Info.fl_tpms.tire_temp_status;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fl_tire_temp_value = TPMS_Info.fl_tpms.tire_temp_value;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fl_tire_temp_color = TPMS_Info.fl_tpms.tire_temp_color;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fl_tire_behavior_color = TPMS_Info.fl_tpms.tire_behavior_color;
	
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fr_tire_press_status = TPMS_Info.fr_tpms.tire_press_status;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fr_tire_press_value = TPMS_Info.fr_tpms.tire_press_value;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fr_tire_press_color = TPMS_Info.fr_tpms.tire_press_color;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fr_tire_temp_status = TPMS_Info.fr_tpms.tire_temp_status;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fr_tire_temp_value = TPMS_Info.fr_tpms.tire_temp_value;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fr_tire_temp_color = TPMS_Info.fr_tpms.tire_temp_color;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.fr_tire_behavior_color = TPMS_Info.fr_tpms.tire_behavior_color;
	
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rl_tire_press_status = TPMS_Info.rl_tpms.tire_press_status;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rl_tire_press_value = TPMS_Info.rl_tpms.tire_press_value;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rl_tire_press_color = TPMS_Info.rl_tpms.tire_press_color;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rl_tire_temp_status = TPMS_Info.rl_tpms.tire_temp_status;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rl_tire_temp_value = TPMS_Info.rl_tpms.tire_temp_value;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rl_tire_temp_color = TPMS_Info.rl_tpms.tire_temp_color;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rl_tire_behavior_color = TPMS_Info.rl_tpms.tire_behavior_color;
	
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rr_tire_press_status = TPMS_Info.rr_tpms.tire_press_status;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rr_tire_press_value = TPMS_Info.rr_tpms.tire_press_value;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rr_tire_press_color = TPMS_Info.rr_tpms.tire_press_color;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rr_tire_temp_status = TPMS_Info.rr_tpms.tire_temp_status;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rr_tire_temp_value = TPMS_Info.rr_tpms.tire_temp_value;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rr_tire_temp_color = TPMS_Info.rr_tpms.tire_temp_color;	
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.rr_tire_behavior_color = TPMS_Info.rr_tpms.tire_behavior_color;

	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.tire_press_unit = TPMS_Info.tire_press_unit;
	ipc_sendTPMS.u_TPMSTPMS_Inf_t.s_TPMS_Inf_t.tire_temp_unit = TPMS_Info.tire_temp_unit;

	if(tpmsUpdateCnt % (TPMS_REFRESH_RATE/TPMS_TASK_TIME_CYCLE))
	{
		/*Do nothing*/
	}
	else
	{
		(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_TPMS, (uint8 *)&ipc_sendTPMS, (uint16)sizeof(IPC_M2S_ClusterAppAPPTPMS_t), FALSE);
		tpmsUpdateCnt = 0;
	}

	
	tpmsUpdateCnt++;
}

static void TPMSMdl_TPMS_unit_check(void)
{
    MenuSetData_t MenuSetData_Tmp = {0};   
    (void)Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&MenuSetData_Tmp);
	switch(MenuSetData_Tmp.TirePressureUnit)
	{
		case TPMS_KPA:
			TPMS_Info.tire_press_unit = TPMS_KPA;
			break;
		case TPMS_BAR:
			TPMS_Info.tire_press_unit = TPMS_BAR;
			break;
		case TPMS_PSI:
			TPMS_Info.tire_press_unit = TPMS_PSI;
			break;
		default:
			TPMS_Info.tire_press_unit = TPMS_KPA;
			break;			
	}

	switch(MenuSetData_Tmp.TemperatureUnit)
	{
		case TPMS_CELSIUS:
			TPMS_Info.tire_temp_unit = TPMS_CELSIUS;
			break;
		case TPMS_FAHRENHEIT:
			TPMS_Info.tire_temp_unit = TPMS_FAHRENHEIT;
			break;
		default:
			TPMS_Info.tire_temp_unit = TPMS_CELSIUS;
			break;			
	}
}

static void TPMSMdl_TPMS_process(void)
{
	uint8 TirePressSysFailrIndcn_temp = 0;
	uint8 FLTirePressIndSts_temp = 0;
	uint8 FRTirePressIndSts_temp = 0;
	uint8 RLTirePressIndSts_temp = 0;
	uint8 RRTirePressIndSts_temp = 0;
	uint8 FLTirePress_temp = 0;
	uint8 FRTirePress_temp = 0;
	uint8 RLTirePress_temp = 0;
	uint8 RRTirePress_temp = 0;
	uint8 FLTireTempSts_temp = 0; 
	uint8 FRTireTempSts_temp = 0; 
	uint8 RLTireTempSts_temp = 0; 
	uint8 RRTireTempSts_temp = 0; 
	uint8 FLTireTemp_temp = 0; 
	uint8 FRTireTemp_temp = 0; 
	uint8 RLTireTemp_temp = 0; 
	uint8 RRTireTemp_temp = 0; 
	
	uint8 TPMS1StsRet = 0;
	uint8 TPMS2StsRet = 0;
	
#ifdef GWM_V35_PROJECT_TYPE_B02_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#elif defined GWM_V35_PROJECT_TYPE_B03_TPMS
    TPMS1StsRet = Rte_Read_TirePressSysFailrIndcn_TirePressSysFailrIndcn(&TirePressSysFailrIndcn_temp);
	Rte_Read_FLTirePressIndSts_FLTirePressIndSts(&FLTirePressIndSts_temp);
	Rte_Read_FRTirePressIndSts_FRTirePressIndSts(&FRTirePressIndSts_temp);
	Rte_Read_RLTirePressIndSts_RLTirePressIndSts(&RLTirePressIndSts_temp);
	Rte_Read_RRTirePressIndSts_RRTirePressIndSts(&RRTirePressIndSts_temp);
	Rte_Read_RRTireTempSts_RRTireTempSts(&RRTireTempSts_temp);
	Rte_Read_FLTireTempSts_FLTireTempSts(&FLTireTempSts_temp);
	Rte_Read_FRTireTempSts_FRTireTempSts(&FRTireTempSts_temp);
	Rte_Read_RLTireTempSts_RLTireTempSts(&RLTireTempSts_temp);

	TPMS2StsRet = Rte_Read_FLTirePress_FLTirePress(&FLTirePress_temp);
	Rte_Read_FRTirePress_FRTirePress(&FRTirePress_temp);
	Rte_Read_RLTirePress_RLTirePress(&RLTirePress_temp);
	Rte_Read_RRTirePress_RRTirePress(&RRTirePress_temp);
	Rte_Read_FLTireTemp_FLTireTemp(&FLTireTemp_temp);
	Rte_Read_FRTireTemp_FRTireTemp(&FRTireTemp_temp);
	Rte_Read_RLTireTemp_RLTireTemp(&RLTireTemp_temp);
	Rte_Read_RRTireTemp_RRTireTemp(&RRTireTemp_temp);
#elif defined GWM_V35_PROJECT_TYPE_P03_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#elif defined GWM_V35_PROJECT_TYPE_P05_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#elif defined GWM_V35_PROJECT_TYPE_A07_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#elif defined GWM_V35_PROJECT_TYPE_D01_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#elif defined GWM_V35_PROJECT_TYPE_D02_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#elif defined GWM_V35_PROJECT_TYPE_D03_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#elif defined GWM_V35_PROJECT_TYPE_P02_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#elif defined GWM_V35_PROJECT_TYPE_P01_TPMS
	TPMS1StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, (uint8 *)&TirePressSysFailrIndcn_temp, (uint8)sizeof(TirePressSysFailrIndcn_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)&FLTirePressIndSts_temp, (uint8)sizeof(FLTirePressIndSts_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)&FRTirePressIndSts_temp, (uint8)sizeof(FRTirePressIndSts_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)&RLTirePressIndSts_temp, (uint8)sizeof(RLTirePressIndSts_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)&RRTirePressIndSts_temp, (uint8)sizeof(RRTirePressIndSts_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)&FLTireTempSts_temp, (uint8)sizeof(FLTireTempSts_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)&FRTireTempSts_temp, (uint8)sizeof(FRTireTempSts_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)&RLTireTempSts_temp, (uint8)sizeof(RLTireTempSts_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)&RRTireTempSts_temp, (uint8)sizeof(RRTireTempSts_temp));

	TPMS2StsRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESS, (uint8 *)&FLTirePress_temp, (uint8)sizeof(FLTirePress_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESS, (uint8 *)&FRTirePress_temp, (uint8)sizeof(FRTirePress_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESS, (uint8 *)&RLTirePress_temp, (uint8)sizeof(RLTirePress_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESS, (uint8 *)&RRTirePress_temp, (uint8)sizeof(RRTirePress_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMP, (uint8 *)&FLTireTemp_temp, (uint8)sizeof(FLTireTemp_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMP, (uint8 *)&FRTireTemp_temp, (uint8)sizeof(FRTireTemp_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMP, (uint8 *)&RLTireTemp_temp, (uint8)sizeof(RLTireTemp_temp));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMP, (uint8 *)&RRTireTemp_temp, (uint8)sizeof(RRTireTemp_temp));
#else
#endif
	
	if((FALSE == (GET_CAN_TPMS1_TPMS_MISSING(TPMS1StsRet))) && (FALSE == (GET_CAN_TPMS2_TPMS_MISSING(TPMS2StsRet))))
	{
		/* TirePressure */
		if((FLTirePress_temp == TPMS_PRESSURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x1u))
		{
			TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_press_status = TPMS_DASH;
		}
		else if((FLTirePress_temp == TPMS_PRESSURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x0u))
		{
			TPMS_Info.fl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_press_status = TPMS_DASH;
		}
		else if((FLTirePress_temp < TPMS_PRESSURE_INVALID_VALUE) && (FLTirePressIndSts_temp != 0x1u))
		{
			TPMS_Info.fl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.fl_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(FLTirePress_temp);
		}
		else if((FLTirePress_temp < TPMS_PRESSURE_INVALID_VALUE) && (FLTirePressIndSts_temp == 0x1u))//0x1:Tire Pressure Low
		{
			TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.fl_tpms.tire_press_color = TPMS_RED;
			TPMS_Info.fl_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.fl_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(FLTirePress_temp);
		}else{}

		if((FRTirePress_temp == TPMS_PRESSURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x1u))
		{
			TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_press_status = TPMS_DASH;
		}
		else if((FRTirePress_temp == TPMS_PRESSURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x0u))
		{
			TPMS_Info.fr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_press_status = TPMS_DASH;
		}
		else if((FRTirePress_temp < TPMS_PRESSURE_INVALID_VALUE) && (FRTirePressIndSts_temp != 0x1u))
		{
			TPMS_Info.fr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.fr_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(FRTirePress_temp);
		}
		else if((FRTirePress_temp < TPMS_PRESSURE_INVALID_VALUE) && (FRTirePressIndSts_temp == 0x1u))//0x1:Tire Pressure Low
		{
			TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.fr_tpms.tire_press_color = TPMS_RED;
			TPMS_Info.fr_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.fr_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(FRTirePress_temp);
		}else{}

		if((RLTirePress_temp == TPMS_PRESSURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x1u))
		{
			TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_press_status = TPMS_DASH;
		}
		else if((RLTirePress_temp == TPMS_PRESSURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x0u))
		{
			TPMS_Info.rl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_press_status = TPMS_DASH;
		}
		else if((RLTirePress_temp < TPMS_PRESSURE_INVALID_VALUE) && (RLTirePressIndSts_temp != 0x1u))
		{
			TPMS_Info.rl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.rl_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(RLTirePress_temp);
		}
		else if((RLTirePress_temp < TPMS_PRESSURE_INVALID_VALUE) && (RLTirePressIndSts_temp == 0x1u))//0x1:Tire Pressure Low
		{
			TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.rl_tpms.tire_press_color = TPMS_RED;
			TPMS_Info.rl_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.rl_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(RLTirePress_temp);
		}else{}

		if((RRTirePress_temp == TPMS_PRESSURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x1u))
		{
			TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_press_status = TPMS_DASH;
		}
		else if((RRTirePress_temp == TPMS_PRESSURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x0u))
		{
			TPMS_Info.rr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_press_status = TPMS_DASH;
		}
		else if((RRTirePress_temp < TPMS_PRESSURE_INVALID_VALUE) && (RRTirePressIndSts_temp != 0x1u))
		{
			TPMS_Info.rr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.rr_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(RRTirePress_temp);
		}
		else if((RRTirePress_temp < TPMS_PRESSURE_INVALID_VALUE) && (RRTirePressIndSts_temp == 0x1u))//0x1:Tire Pressure Low
		{
			TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);			
			TPMS_Info.rr_tpms.tire_press_color = TPMS_RED;
			TPMS_Info.rr_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.rr_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(RRTirePress_temp);
		}else{}

		/* TireTemperature */
		if((FLTireTemp_temp == TPMS_TEMPERATURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x1u))
		{
			TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_temp_status = TPMS_DASH;
		}
		else if((FLTireTemp_temp == TPMS_TEMPERATURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x0u))
		{
			TPMS_Info.fl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_temp_status = TPMS_DASH;
		}
		else if((FLTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE) && (FLTireTempSts_temp != 0x1u))
		{
			TPMS_Info.fl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.fl_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(FLTireTemp_temp);
		}
		else if((FLTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE) && (FLTireTempSts_temp == 0x1u))//Tire Temperature high
		{
			TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.fl_tpms.tire_temp_color = TPMS_RED;
			TPMS_Info.fl_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.fl_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(FLTireTemp_temp);
		}else{}

		if((FRTireTemp_temp == TPMS_TEMPERATURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x1u))
		{
			TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_temp_status = TPMS_DASH;
		}
		else if((FRTireTemp_temp == TPMS_TEMPERATURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x0u))
		{
			TPMS_Info.fr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_temp_status = TPMS_DASH;
		}
		else if((FRTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE) && (FRTireTempSts_temp != 0x1u))
		{
			TPMS_Info.fr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);	
			TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.fr_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(FRTireTemp_temp);
		}
		else if((FRTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE) && (FRTireTempSts_temp == 0x1u))
		{
			TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);		
			TPMS_Info.fr_tpms.tire_temp_color = TPMS_RED;
			TPMS_Info.fr_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.fr_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(FRTireTemp_temp);
		}else{}

		if((RLTireTemp_temp == TPMS_TEMPERATURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x1u))
		{
			TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_temp_status = TPMS_DASH;
		}
		else if((RLTireTemp_temp == TPMS_TEMPERATURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x0u))
		{
			TPMS_Info.rl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_temp_status = TPMS_DASH;
		}
		else if((RLTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE) && (RLTireTempSts_temp != 0x1u))
		{
			TPMS_Info.rl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);	
			TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.rl_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(RLTireTemp_temp);
		}
		else if((RLTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE) && (RLTireTempSts_temp == 0x1u))
		{
			TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);		
			TPMS_Info.rl_tpms.tire_temp_color = TPMS_RED;
			TPMS_Info.rl_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.rl_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(RLTireTemp_temp);
		}else{}

		if((RRTireTemp_temp == TPMS_TEMPERATURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x1u))
		{
			TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_temp_status = TPMS_DASH;
		}
		else if((RRTireTemp_temp == TPMS_TEMPERATURE_INVALID_VALUE) && (TirePressSysFailrIndcn_temp == 0x0u))
		{
			TPMS_Info.rr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);			
			TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_temp_status = TPMS_DASH;
		}
		else if((RRTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE) && (RRTireTempSts_temp != 0x1u))
		{
			TPMS_Info.rr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);	
			TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.rr_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(RRTireTemp_temp);
		}
		else if((RRTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE) && (RRTireTempSts_temp == 0x1u))
		{
			TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);		
			TPMS_Info.rr_tpms.tire_temp_color = TPMS_RED;
			TPMS_Info.rr_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.rr_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(RRTireTemp_temp);
		}else{}

	}
	else if((FALSE == (GET_CAN_TPMS1_TPMS_MISSING(TPMS1StsRet))) && (FALSE != (GET_CAN_TPMS2_TPMS_MISSING(TPMS2StsRet))))
	{
		if(TirePressSysFailrIndcn_temp == 0x1u)
		{
			TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_press_status = TPMS_DASH;
			TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_press_status = TPMS_DASH;
			
			TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_press_status = TPMS_DASH;
			TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_press_status = TPMS_DASH;
			
			TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_temp_status = TPMS_DASH;
			TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_temp_status = TPMS_DASH;
			
			TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_temp_status = TPMS_DASH;
			TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_temp_status = TPMS_DASH;
			
			TPMS_Info.fl_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
			TPMS_Info.fr_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
			TPMS_Info.rl_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
			TPMS_Info.rr_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
		}
		else if(TirePressSysFailrIndcn_temp == 0x0u)
		{
			/* Tire Pressure */
			if(FLTirePressIndSts_temp == 0x1u)
			{
				TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
				TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
				TPMS_Info.fl_tpms.tire_press_status = TPMS_DASH;
			}
			else
			{
				TPMS_Info.fl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);
				TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
				TPMS_Info.fl_tpms.tire_press_status = TPMS_DASH;
			}
			
			if(FRTirePressIndSts_temp == 0x1u)
			{
				TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
				TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
				TPMS_Info.fr_tpms.tire_press_status = TPMS_DASH;
			}
			else
			{
				TPMS_Info.fr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);
				TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
				TPMS_Info.fr_tpms.tire_press_status = TPMS_DASH;
			}
			
			if(RLTirePressIndSts_temp == 0x1u)
			{
				TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
				TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
				TPMS_Info.rl_tpms.tire_press_status = TPMS_DASH;
			}
			else
			{
				TPMS_Info.rl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);
				TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
				TPMS_Info.rl_tpms.tire_press_status = TPMS_DASH;
			}
			
			if(RRTirePressIndSts_temp == 0x1u)
			{
				TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
				TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
				TPMS_Info.rr_tpms.tire_press_status = TPMS_DASH;
			}
			else
			{
				TPMS_Info.rr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 0);
				TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
				TPMS_Info.rr_tpms.tire_press_status = TPMS_DASH;
			}
			
			/* Tire Temperature */
			if(FLTireTempSts_temp == 0x1u)
			{
				TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
				TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
				TPMS_Info.fl_tpms.tire_temp_status = TPMS_DASH;
			}
			else
			{
				TPMS_Info.fl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);
				TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
				TPMS_Info.fl_tpms.tire_temp_status = TPMS_DASH;
			}
			
			if(FRTireTempSts_temp == 0x1u)
			{
				TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
				TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
				TPMS_Info.fr_tpms.tire_temp_status = TPMS_DASH;
			}
			else
			{
				TPMS_Info.fr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);
				TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
				TPMS_Info.fr_tpms.tire_temp_status = TPMS_DASH;
			}
			
			if(RLTireTempSts_temp == 0x1u)
			{
				TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
				TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
				TPMS_Info.rl_tpms.tire_temp_status = TPMS_DASH;
			}
			else
			{
				TPMS_Info.rl_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);
				TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
				TPMS_Info.rl_tpms.tire_temp_status = TPMS_DASH;
			}
			
			if(RRTireTempSts_temp == 0x1u)
			{
				TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
				TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
				TPMS_Info.rr_tpms.tire_temp_status = TPMS_DASH;
			}
			else
			{
				TPMS_Info.rr_tpms.tire_behavior_color &= (uint8)~(TPMS_TIRE_RED1HZ << 1);
				TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
				TPMS_Info.rr_tpms.tire_temp_status = TPMS_DASH;
			}

		}
		else
		{}
	}
	else if((FALSE != (GET_CAN_TPMS1_TPMS_MISSING(TPMS1StsRet))) && (FALSE == (GET_CAN_TPMS2_TPMS_MISSING(TPMS2StsRet))))
	{
		/* Tire Pressure */
		if((FLTirePress_temp < TPMS_PRESSURE_INVALID_VALUE))
		{
			TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
			TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.fl_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(FLTirePress_temp);
		}
		else
		{
			TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
			TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_press_status = TPMS_DASH;
		}
		
		if((FRTirePress_temp < TPMS_PRESSURE_INVALID_VALUE))
		{
			TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
			TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.fr_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(FRTirePress_temp);
		}
		else
		{
			TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
			TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_press_status = TPMS_DASH;
		}

		if((RLTirePress_temp < TPMS_PRESSURE_INVALID_VALUE))
		{
			TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
			TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.rl_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(RLTirePress_temp);
		}
		else
		{
			TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
			TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_press_status = TPMS_DASH;
		}
		
		if((RRTirePress_temp < TPMS_PRESSURE_INVALID_VALUE))
		{
			TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
			TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_press_status = TPMS_NORMAL;
			TPMS_Info.rr_tpms.tire_press_value = TPMSMdl_TirePressure_calculate(RRTirePress_temp);
		}
		else
		{
			TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 0);
			TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_press_status = TPMS_DASH;
		}
		
		/* Tire Temperature */
		if((FLTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE))
		{
			TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
			TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.fl_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(FLTireTemp_temp);
		}
		else
		{
			TPMS_Info.fl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
			TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fl_tpms.tire_temp_status = TPMS_DASH;
		}
		
		if((FRTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE))
		{
			TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
			TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.fr_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(FRTireTemp_temp);
		}
		else
		{
			TPMS_Info.fr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
			TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.fr_tpms.tire_temp_status = TPMS_DASH;
		}

		if((RLTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE))
		{
			TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
			TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.rl_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(RLTireTemp_temp);
		}
		else
		{
			TPMS_Info.rl_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
			TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rl_tpms.tire_temp_status = TPMS_DASH;
		}
		
		if((RRTireTemp_temp < TPMS_TEMPERATURE_INVALID_VALUE))
		{
			TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
			TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_temp_status = TPMS_NORMAL;
			TPMS_Info.rr_tpms.tire_temp_value = TPMSMdl_TireTemperature_calculate(RRTireTemp_temp);
		}
		else
		{
			TPMS_Info.rr_tpms.tire_behavior_color |= (TPMS_TIRE_RED1HZ << 1);
			TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
			TPMS_Info.rr_tpms.tire_temp_status = TPMS_DASH;
		}

	}
	else
	{
		TPMS_Info.fl_tpms.tire_press_status = TPMS_DASH;
		TPMS_Info.fl_tpms.tire_temp_status = TPMS_DASH;
		
		TPMS_Info.fr_tpms.tire_press_status = TPMS_DASH;
		TPMS_Info.fr_tpms.tire_temp_status = TPMS_DASH;
		
		TPMS_Info.rl_tpms.tire_press_status = TPMS_DASH;
		TPMS_Info.rl_tpms.tire_temp_status = TPMS_DASH;
		
		TPMS_Info.rr_tpms.tire_press_status = TPMS_DASH;
		TPMS_Info.rr_tpms.tire_temp_status = TPMS_DASH;
		
		TPMS_Info.fl_tpms.tire_press_color = TPMS_WHITE;
		TPMS_Info.fr_tpms.tire_press_color = TPMS_WHITE;
		TPMS_Info.rl_tpms.tire_press_color = TPMS_WHITE;
		TPMS_Info.rr_tpms.tire_press_color = TPMS_WHITE;
		
		TPMS_Info.fl_tpms.tire_temp_color = TPMS_WHITE;
		TPMS_Info.fr_tpms.tire_temp_color = TPMS_WHITE;
		TPMS_Info.rl_tpms.tire_temp_color = TPMS_WHITE;
		TPMS_Info.rr_tpms.tire_temp_color = TPMS_WHITE;
		
		TPMS_Info.rr_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
		TPMS_Info.fl_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
		TPMS_Info.fr_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
		TPMS_Info.rl_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
	}
	
	
	switch(TPMS_Info.fl_tpms.tire_behavior_color)
	{
		case 0x0:
			TPMS_Info.fl_tpms.tire_behavior_color = TPMS_TIRE_OFF;
			break;
		case 0x1:
		case 0x2:
		case 0x3:
			TPMS_Info.fl_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
			break;
		default:
			TPMS_Info.fl_tpms.tire_behavior_color = TPMS_TIRE_OFF;
			break;
	
	}
	switch(TPMS_Info.fr_tpms.tire_behavior_color)
	{
		case 0x0:
			TPMS_Info.fr_tpms.tire_behavior_color = TPMS_TIRE_OFF;
			break;
		case 0x1:
		case 0x2:
		case 0x3:
			TPMS_Info.fr_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
			break;
		default:
			TPMS_Info.fr_tpms.tire_behavior_color = TPMS_TIRE_OFF;
			break;
	
	}
	switch(TPMS_Info.rl_tpms.tire_behavior_color)
	{
		case 0x0:
			TPMS_Info.rl_tpms.tire_behavior_color = TPMS_TIRE_OFF;
			break;
		case 0x1:
		case 0x2:
		case 0x3:
			TPMS_Info.rl_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
			break;
		default:
			TPMS_Info.rl_tpms.tire_behavior_color = TPMS_TIRE_OFF;
			break;
	
	}
	switch(TPMS_Info.rr_tpms.tire_behavior_color)
	{
		case 0x0:
			TPMS_Info.rr_tpms.tire_behavior_color = TPMS_TIRE_OFF;
			break;
		case 0x1:
		case 0x2:
		case 0x3:
			TPMS_Info.rr_tpms.tire_behavior_color = TPMS_TIRE_RED1HZ;
			break;
		default:
			TPMS_Info.rr_tpms.tire_behavior_color = TPMS_TIRE_OFF;
			break;
	
	}
}

static uint16 TPMSMdl_TirePressure_calculate(uint8 u8TirePressVal)
{
	uint16 tire_press_value_u16 = 0;
	
	if(TPMS_Info.tire_press_unit == TPMS_PSI)
	{
		tire_press_value_u16 = (uint16)(((u8TirePressVal * TPMS_PRESSURE_FACTOR_1 * 10 / TPMS_PRESSURE_FACTOR_PSI) + 5) /10);	//0.1 psi	
		if(tire_press_value_u16 > TPMS_PRESSURE_PSI_MAX)
		{
			tire_press_value_u16 = TPMS_PRESSURE_PSI_MAX;
		}
	}
	else if(TPMS_Info.tire_press_unit == TPMS_BAR)
	{
		tire_press_value_u16 = (uint16)(((u8TirePressVal * TPMS_PRESSURE_FACTOR_1 * 10 / TPMS_PRESSURE_FACTOR_BAR) + 5) /10);	//0.1 bar	
		
		if(tire_press_value_u16 > TPMS_PRESSURE_BAR_MAX)
		{
			tire_press_value_u16 = TPMS_PRESSURE_BAR_MAX;
		}
	}
	else
	{
		tire_press_value_u16 = (uint16)(((u8TirePressVal * TPMS_PRESSURE_FACTOR_1 / TPMS_PRESSURE_FACTOR_2) + 5) /10);		
		
		if(tire_press_value_u16 > TPMS_PRESSURE_KPA_MAX)
		{
			tire_press_value_u16 = TPMS_PRESSURE_KPA_MAX;
		}
	}
	
	return tire_press_value_u16;
}

static uint16 TPMSMdl_TireTemperature_calculate(uint8 u8TireTempVal)
{
	uint16 tire_temp_value_u16 = 0;

	if(TPMS_Info.tire_temp_unit != TPMS_FAHRENHEIT)
	{
		tire_temp_value_u16 = (uint16)(u8TireTempVal); //offset: -50
		if(tire_temp_value_u16 > TPMS_TEMPERATURE_C_MAX)
		{
			tire_temp_value_u16 = TPMS_TEMPERATURE_C_MAX;
		}
	}
	else
	{
		tire_temp_value_u16 = ((((uint16)u8TireTempVal * 18u) + 5u) / 10u);//offset: -58 
		
		if(tire_temp_value_u16 > TPMS_TEMPERATURE_F_MAX)
		{
			tire_temp_value_u16 = TPMS_TEMPERATURE_F_MAX;
		}
	}

	return tire_temp_value_u16;
}

#if 0

static void TPMSMdl_subTPMS(void)
{
	TPMS_enTireCount tire_loop = (TPMS_enTireCount)0;

	for(tire_loop = TPMS_FL; tire_loop < TPMS_COUNT; tire_loop++)
	{
		TPMS_Info.subTPMS[tire_loop].tire_behavior_color = TPMS_TIRE_OFF;
		TPMS_Info.subTPMS[tire_loop].tire_press_color = TPMS_WHITE;
		TPMS_Info.subTPMS[tire_loop].tire_press_status = TPMS_NORMAL;
		TPMS_Info.subTPMS[tire_loop].tire_press_value = 0;

		TPMS_Info.subTPMS[tire_loop].tire_temp_color = TPMS_WHITE;
		TPMS_Info.subTPMS[tire_loop].tire_temp_status = TPMS_NORMAL;
		TPMS_Info.subTPMS[tire_loop].tire_temp_value = 0;
	}
}
#endif
#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" 

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

