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
*File Name   : SWC_Gear.c                                                                                 *
*                                                                                                         *
*Description : Gear module application source file.                                                       *
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
#include <string.h> /* memcpy */
#include "SWC_IPC_Config.h"
#include "SWC_Gear_Adapt.h"
#include "SWC_Gear.h"
#include "CConfig_Cfg.h"

//#include "Rte_Common_Safety.h"

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/
//#include "Platform_Types.h"
//#include "system.h"



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
#define Common_Safety_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Safety_MemMap.h"

static GEAR_DISP_str gear_disp;
static GEAR_INFO_str gear_inf;
static GEAR_VCfg_str gear_vcfg;
static uint8 gear_Vconfig;
static IPC_M2S_SAFETYAPPSafetyGearCheck_t ipcGearCrcAck;
static IPC_S2M_SAFETYAPPSafetyGearCRC_t GearCRCData;

#define Common_Safety_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Safety_MemMap.h"
/*****************************************************************************
*                                 Init Variable                             *
******************************************************************************/
#define Common_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Safety_MemMap.h"

static boolean boGearIpcCallback = FALSE;
static TimerCfg_str timerCfg[enTimerMax];
static uint8 u8GearErrorSwitch = 0;
//log output
static uint8 gear_e2e_Flag = 0;
static uint8 gear_print_Flg = 0;
static uint8 gear_3s_delay_count = 0;

#define Common_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Safety_MemMap.h"

/*****************************************************************************
*                                 Const Variable                             *
******************************************************************************/
#define Common_Safety_START_SEC_CONST_UNSPECIFIED
#include "Common_Safety_MemMap.h"

static const SafetyGearCRC_str gearCrc[enGEAR_NUM] = GEAR_CFG_CRC_TABLE;

#define Common_Safety_STOP_SEC_CONST_UNSPECIFIED
#include "Common_Safety_MemMap.h"

/*****************************************************************************
*                                 Functions                                  *
******************************************************************************/
#define Common_GateWay_START_SEC_CODE
#include "Common_Safety_MemMap.h"

static void GearMdl_Set_vehicle_config(void);
static void GearMdl_vCheckPowerMode(GEAR_POWER_MODE *enPowerMode);

static void GearMdl_Gear_delay_proc_tsk(void);
static void GearMdl_Gear_of_VCfg_7DCT(void);
static void GearMdl_Gear_of_VCfg_9DCT(void);
static void GearMdl_Gear_of_VCfg_8AT(void);
static void GearMdl_Gear_of_VCfg_PHEV_DHT(void);
static void GearMdl_Gear_of_VCfg_EV(void);
static void GearMdl_Gear_val_process(void);

static void GearMdl_Gear_shift_delay_proc_tsk(void);
static void GearMdl_Gear_shift_of_VCfg_7DCT(void);
static void GearMdl_Gear_shift_of_VCfg_9DCT(void);
static void GearMdl_Gear_shift_of_VCfg_8AT(void);
static void GearMdl_Gear_shift_of_VCfg_MT(void);
static void GearMdl_Gear_shift_val_process(void);

static void GearMdl_SOCManager_send_Gear_inf(void);
static void GearMdl_SBUS_send_Gear_inf(void);
static void Gear_FunctionSafety_CRC_Check(void);


/*******************************************************************************
*
*   Function:           GearMdl_Gear_cold_init
*
*   Description:        This function performs a Cold reset Initialization
*                       of the Gear.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void GearMdl_Gear_cold_init(void)
{
	gear_disp.gear_val = GearMdl_GEAR_NO_DISPLAY;
	gear_disp.gear_status = GearMdl_GEAR_NO_SHOW;
	gear_disp.gear_shift_val = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;

	gear_inf.gear_cnt_u8 = 0;
	gear_inf.gear_pre_val_u8 = GearMdl_GEAR_NO_DISPLAY;
	gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
	gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;

	gear_inf.gear_shift_cnt_u8 = 0;
	gear_inf.gear_shift_pre_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	gear_vcfg.u8InitFlag = 0;

	GearMdl_Adapt_E2EPW_AllReadInit();
	GearMdl_Set_vehicle_config();
}

/*******************************************************************************
*
*   Function:           GearMdl_Gear_warm_init
*
*   Description:        This function performs a warm reset Initialization
*                       of the Gear.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void GearMdl_Gear_warm_init(void)
{
	gear_disp.gear_val = GearMdl_GEAR_NO_DISPLAY;
	gear_disp.gear_status = GearMdl_GEAR_NO_SHOW;
	gear_disp.gear_shift_val = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;

	gear_inf.gear_cnt_u8 = 0;
	gear_inf.gear_pre_val_u8 = GearMdl_GEAR_NO_DISPLAY;
	gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
	gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;

	gear_inf.gear_shift_cnt_u8 = 0;
	gear_inf.gear_shift_pre_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;

	//GearMdl_Set_vehicle_config();
}

/*******************************************************************************
*
*   Function:           GearMdl_Gear_delay_proc_tsk
*
*   Description:        This function performs implementation of the process gear delay.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
static void GearMdl_Gear_delay_proc_tsk(void)
{
	uint8 fl_total_count_u8 = 0;

	if (GearMdl_GEAR_R == gear_inf.gear_actual_val_u8)
	{
		fl_total_count_u8 = GearMdl_GEAR_R_COUNT;
	}
	else if (GearMdl_GEAR_N == gear_inf.gear_actual_val_u8)
	{
		fl_total_count_u8 = GearMdl_GEAR_N_COUNT;
	}
	else
	{
		fl_total_count_u8 = GearMdl_GEAR_OTHER_COUNT;
	}

	if (gear_inf.gear_pre_val_u8 == gear_inf.gear_actual_val_u8)
	{
		if (gear_inf.gear_cnt_u8 >= 0xFFU)
		{
			/* do nothing */
		}
		else
		{
			gear_inf.gear_cnt_u8++;
		}
	}
	else
	{
		gear_inf.gear_cnt_u8 = 0;
	}
	if (gear_inf.gear_cnt_u8 >= fl_total_count_u8)
	{
		gear_disp.gear_val = gear_inf.gear_actual_val_u8;
		gear_disp.gear_status = gear_inf.gear_status;
	}
	else
	{
		/* do nothing */
	}
}

static void GearMdl_Gear_shift_delay_proc_tsk(void)
{
	if (gear_inf.gear_shift_pre_val_u8 == gear_inf.gear_shift_actual_val_u8)
	{
		if (gear_inf.gear_shift_cnt_u8 >= 0xFFU)
		{
			/* do nothing */
		}
		else
		{
			gear_inf.gear_shift_cnt_u8++;
		}
	}
	else
	{
		gear_inf.gear_shift_cnt_u8 = 0;
	}

	if (gear_inf.gear_shift_cnt_u8 >= GearMdl_GEAR_OTHER_COUNT)
	{
		gear_disp.gear_shift_val = gear_inf.gear_shift_actual_val_u8;
	}
	else
	{
		/* do nothing */
	}
}

/*******************************************************************************
*
*   Function:           GearMdl_Gear_app_tsk
*
*   Description:        This function performs implementation of the Gear.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void GearMdl_Gear_app_tsk(void)
{
	GEAR_POWER_MODE PowerMode;
	GearMdl_vCheckPowerMode(&PowerMode);
	GearMdl_Set_vehicle_config();

	if(u8GearErrorSwitch == 1U)
	{
		gear_disp.gear_val = GearMdl_GEAR_NO_DISPLAY;
		gear_disp.gear_status = GearMdl_GEAR_NO_SHOW;
		if(PowerMode == CLUSTER_NORMAL)
		{
			GearMdl_Gear_shift_val_process();
		}
		else
		{
			GearMdl_Gear_warm_init();
		}
	}
	else
	{
		if(PowerMode == CLUSTER_NORMAL)
		{
			GearMdl_Gear_val_process();
			GearMdl_Gear_shift_val_process();
		}
		else if(PowerMode == CLUSTER_15OFF)
		{
			GearMdl_Gear_val_process();
			GearMdl_Gear_shift_val_process();
			gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			gear_disp.gear_status = gear_inf.gear_status;
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
			gear_disp.gear_shift_val = gear_inf.gear_shift_actual_val_u8;
			/* In order to ensure that the gear value is issued when the power is off, the gear is not displayed */
		}
		else if(PowerMode == CLUSTER_OFF)
		{
			GearMdl_Gear_warm_init();
		}
		else
		{
			/* clear */
			GearMdl_Gear_warm_init();
		}
	}
	GearMdl_SOCManager_send_Gear_inf();
	GearMdl_SBUS_send_Gear_inf();

	/* when cold or warm init,print gear vconfig,but should delay 3s  */
	if(gear_print_Flg == 0)
	{
		if(gear_3s_delay_count >= GEAR_CFG_TIME_3_SEC)
		{
			(void)Gear_warn("GEAR: [Vconfg = %d]",gear_Vconfig);
			gear_print_Flg = 1;
			gear_3s_delay_count = 0;
		}
		else
		{
			gear_3s_delay_count ++;
		}
	}
 }

static void GearMdl_vCheckPowerMode(GEAR_POWER_MODE *enPowerMode)
{
	const SystemState_RecordType* u8PowerMode = GearMdl_Adapt_GetPowerMode();

	if((u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_NORMAL) \
		&& (u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_LOWALARM) \
		&& (u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_HIGHALARM))
	{
		*enPowerMode = CLUSTER_ABNORMAL;
	}
	else
	{
		if(SYSTEMSTATE_Cluster_OFF == u8PowerMode->ClusterState)
		{
			*enPowerMode = CLUSTER_SLEEP;
		}
		else if(SYSTEMSTATE_Cluster_ON == u8PowerMode->ClusterState)
		{
			*enPowerMode = CLUSTER_NORMAL;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == u8PowerMode->ClusterState)
		{
			*enPowerMode = CLUSTER_15OFF;
		}
		else
		{
			*enPowerMode = CLUSTER_OFF;
		}
	}
}

static void GearMdl_Gear_of_VCfg_7DCT(void)
{
	uint8 u8DrvModDisp = 0U;
	uint8 u8DrvModDispSts = 0U;
	uint8 u8DrvGearDispSts = 0U;
	uint8 u8DrvAutoGearDisp = 0U;
	uint8 DCT7StatusRet = 0U;
	uint8 u8E2ESwitchCfg = E2E_SWITCH_OFF;
	uint32 E2ERetSts = E2E_OK;
	uint8 u8Gear_M_Val_Max = GearMdl_GEAR_M_VAL_MAX;
	GR_CFG_SG_DCT7 Gear_SG_DCT7 = {0};
	GR_CFG_SG_DCT_FD4 Gear_DCT_FD4 = {0};
	GearMdl_Adapt_GetE2ESwitchChangeTrigger(&u8E2ESwitchCfg);

	if(gear_vcfg.boPTCAN != FALSE)//CANFD
	{
		E2ERetSts = GearMdl_Adapt_GetE2EPW_DCT_FD4();
		DCT7StatusRet = GearMdl_Adapt_GetCANMessage_DCT_FD4(&Gear_DCT_FD4);
		u8DrvModDisp = Gear_DCT_FD4.GR_DrvModDisp;
		u8DrvModDispSts = Gear_DCT_FD4.GR_DrvModDispSts;
		u8DrvGearDispSts = Gear_DCT_FD4.GR_DrvGearDispSts;
		u8DrvAutoGearDisp = Gear_DCT_FD4.GR_DrvAutoGearDisp;
	}
	else //CAN
	{
		E2ERetSts = GearMdl_Adapt_GetE2EPW_DCT7();
		DCT7StatusRet = GearMdl_Adapt_GetCANMessage_7DCT(&Gear_SG_DCT7);
		u8DrvModDisp = Gear_SG_DCT7.GR_DrvModDisp;
		u8DrvModDispSts = Gear_SG_DCT7.GR_DrvModDispSts;
		u8DrvGearDispSts = Gear_SG_DCT7.GR_DrvGearDispSts;
		u8DrvAutoGearDisp = Gear_SG_DCT7.GR_DrvAutoGearDisp;
	}

	if(E2E_SWITCH_ON == u8E2ESwitchCfg)
	{
		//do nothing
	}
	else
	{
		E2ERetSts = E2E_OK;
	}

	gear_inf.gear_pre_val_u8 = gear_inf.gear_actual_val_u8;
	if(FALSE == GET_GEAR_MESSAGE_MISSING(DCT7StatusRet))
	{
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_NORMAL;

		if((E2E_OK == E2ERetSts) || (E2E_INITIAL == E2ERetSts))
		{
			if((u8DrvModDispSts == (uint8)GEAR_ON) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_P) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if ((u8DrvModDispSts == (uint8)GEAR_ON) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_R) && (u8DrvAutoGearDisp == (uint8)0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if ((u8DrvModDispSts == (uint8)GEAR_ON) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_N) && (u8DrvAutoGearDisp == (uint8)0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			} //D、D1~D7 ON
			else if ((u8DrvModDispSts == (uint8)GEAR_ON) && (u8DrvGearDispSts == 0x0u) && (u8DrvModDisp == (uint8)GEAR_D) \
						&& (u8DrvAutoGearDisp <= GearMdl_GEAR_D_VAL_MAX))
			{
				gear_inf.gear_actual_val_u8 = u8DrvAutoGearDisp + GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			//P,R,N,D  Flash
			else if((u8DrvModDispSts == (uint8)GEAR_FLASH) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_P) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if ((u8DrvModDispSts == (uint8)GEAR_FLASH) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_R) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if ((u8DrvModDispSts == (uint8)GEAR_FLASH) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == 0x2u) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			} //D、D1~D7 FLASH
			else if ((u8DrvModDispSts == (uint8)GEAR_FLASH) && (u8DrvGearDispSts == 0x0u) && (u8DrvModDisp == 0x3u) \
						&& (u8DrvAutoGearDisp <= GearMdl_GEAR_D_VAL_MAX))
			{
				gear_inf.gear_actual_val_u8 = u8DrvAutoGearDisp + GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			//M1~M7 ON
			else if ((u8DrvModDispSts == (uint8)GEAR_BLANK) && (u8DrvGearDispSts == (uint8)GEAR_ON) && (u8DrvModDisp == (uint8)GEAR_M) \
						&& (u8DrvAutoGearDisp >= 0x1u) && (u8DrvAutoGearDisp <= u8Gear_M_Val_Max))
			{
				gear_inf.gear_actual_val_u8 = u8DrvAutoGearDisp + GearMdl_GEAR_M1 - 1U;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}//M1~M7 FLASH
			else if ((u8DrvModDispSts == (uint8)GEAR_BLANK) && (u8DrvGearDispSts == (uint8)GEAR_FLASH) && (u8DrvModDisp == (uint8)GEAR_M) \
						&& (u8DrvAutoGearDisp >= 0x1u) && (u8DrvAutoGearDisp <= u8Gear_M_Val_Max))
			{
				gear_inf.gear_actual_val_u8 = u8DrvAutoGearDisp + GearMdl_GEAR_M1 - 1U;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
				gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			}
		}
		else if((E2E_SYNC == E2ERetSts) || (E2E_OK_SOMELOST == E2ERetSts) || (E2E_NONEWDATA == E2ERetSts))
		{
			/* Indicates that new Data is available for E2E to be checked, and keep previous state */
		}
		else
		{
			gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
			gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			gear_disp.gear_msg_Status = (uint8)GEAR_MSG_E2E_ERROR;
		}
	}
	else
	{
		gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
		gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;
	}

	GearMdl_Gear_delay_proc_tsk();

	// log output
	if(gear_disp.gear_msg_Status != gear_e2e_Flag)
	{
		(void)Gear_warn("GEAR: [CANMsgSts %d,GVal %d, GSts %d]", gear_e2e_Flag, gear_inf.gear_actual_val_u8, gear_inf.gear_status);
		gear_e2e_Flag = gear_disp.gear_msg_Status;
	}
}

static void GearMdl_Gear_of_VCfg_9DCT(void)
{
	uint8 u8DrvModDisp = 0;
	uint8 u8DrvModDispSts = 0;
	uint8 u8DrvGearDispSts = 0;
	uint8 u8DrvAutoGearDisp = 0;
	uint8 DCTStatusRet = 0;
	uint8 u8E2ESwitchCfg = E2E_SWITCH_OFF;
	uint32 E2ERetSts = E2E_OK;
	uint8 u8Gear_M_Val_Max = GearMdl_GEAR_M_VAL_MAX;
	GR_CFG_SG_DCT_FD4 Gear_DCT_FD4 = {0};

	GearMdl_Adapt_GetE2ESwitchChangeTrigger(&u8E2ESwitchCfg);

	E2ERetSts = GearMdl_Adapt_GetE2EPW_DCT_FD4();
	DCTStatusRet = GearMdl_Adapt_GetCANMessage_DCT_FD4(&Gear_DCT_FD4);

	if(E2E_SWITCH_ON == u8E2ESwitchCfg)
	{
		//do nothing
	}
	else
	{
		E2ERetSts = E2E_OK;
	}

	u8DrvModDisp = Gear_DCT_FD4.GR_DrvModDisp;
	u8DrvModDispSts = Gear_DCT_FD4.GR_DrvModDispSts;
	u8DrvGearDispSts = Gear_DCT_FD4.GR_DrvGearDispSts;
	u8DrvAutoGearDisp = Gear_DCT_FD4.GR_DrvAutoGearDisp;

	gear_inf.gear_pre_val_u8 = gear_inf.gear_actual_val_u8;

	if(FALSE == GET_GEAR_MESSAGE_MISSING(DCTStatusRet))
	{
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_NORMAL;

		if((E2E_OK == E2ERetSts) || (E2E_INITIAL == E2ERetSts))
		{
			if((u8DrvModDispSts == (uint8)GEAR_ON) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_P) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if ((u8DrvModDispSts == (uint8)GEAR_ON) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_R) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if ((u8DrvModDispSts == (uint8)GEAR_ON) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_N) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			} //D、D1~D7 ON
			else if ((u8DrvModDispSts == (uint8)GEAR_ON) && (u8DrvGearDispSts == 0x0u) && (u8DrvModDisp == (uint8)GEAR_D) \
						&& (u8DrvAutoGearDisp <= GearMdl_GEAR_D_VAL_MAX))
			{
				gear_inf.gear_actual_val_u8 = u8DrvAutoGearDisp + GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			//P,R,N,D  Flash
			else if((u8DrvModDispSts == (uint8)GEAR_FLASH) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_P) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if ((u8DrvModDispSts == (uint8)GEAR_FLASH) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == (uint8)GEAR_R) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if ((u8DrvModDispSts == (uint8)GEAR_FLASH) && (u8DrvGearDispSts == (uint8)GEAR_BLANK) && (u8DrvModDisp == 0x2u) && (u8DrvAutoGearDisp == 0x1u))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			} //D、D1~D7 FLASH
			else if ((u8DrvModDispSts == (uint8)GEAR_FLASH) && (u8DrvGearDispSts == 0x0u) && (u8DrvModDisp == 0x3u) \
						&& (u8DrvAutoGearDisp <= GearMdl_GEAR_D_VAL_MAX))
			{
				gear_inf.gear_actual_val_u8 = u8DrvAutoGearDisp + GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			//M1~M7 ON
			else if ((u8DrvModDispSts == (uint8)GEAR_BLANK) && (u8DrvGearDispSts == (uint8)GEAR_ON) && (u8DrvModDisp == (uint8)GEAR_M) \
						&& (u8DrvAutoGearDisp >= 0x1u) && (u8DrvAutoGearDisp <= u8Gear_M_Val_Max))
			{
				gear_inf.gear_actual_val_u8 = u8DrvAutoGearDisp + GearMdl_GEAR_M1 - 1U;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}//M1~M7 FLASH
			else if ((u8DrvModDispSts == (uint8)GEAR_BLANK) && (u8DrvGearDispSts == (uint8)GEAR_FLASH) && (u8DrvModDisp == (uint8)GEAR_M) \
						&& (u8DrvAutoGearDisp >= 0x1u) && (u8DrvAutoGearDisp <= u8Gear_M_Val_Max))
			{
				gear_inf.gear_actual_val_u8 = u8DrvAutoGearDisp + GearMdl_GEAR_M1 - 1U;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
				gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			}
		}
		else if((E2E_SYNC == E2ERetSts) || (E2E_OK_SOMELOST == E2ERetSts) || (E2E_NONEWDATA == E2ERetSts))
		{
			/* Indicates that new Data is available for E2E to be checked, and keep previous state */
		}
		else
		{
			gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
			gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			gear_disp.gear_msg_Status = (uint8)GEAR_MSG_E2E_ERROR;
		}
	}
	else
	{
		gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
		gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;
	}

	GearMdl_Gear_delay_proc_tsk();

	// log output
	if(gear_disp.gear_msg_Status != gear_e2e_Flag)
	{
		(void)Gear_warn("GEAR: [CANMsgSts %d,GVal %d, GSts %d]", gear_e2e_Flag, gear_inf.gear_actual_val_u8, gear_inf.gear_status);
		gear_e2e_Flag = gear_disp.gear_msg_Status;
	}
}

static void GearMdl_Gear_of_VCfg_8AT(void)
{
	uint8 u8DrvModDisp = 0;
	uint8 u8DisplayGear = 0;
	uint8 u8TCUGearFlashing = 0;
	uint8 DCT9StatusRet = 0;
	GR_CFG_DCT9 GearDCT9 = {0};
	uint8 u8E2ESwitchCfg = E2E_SWITCH_OFF;
	uint32 E2ERetSts = E2E_OK;

	GearMdl_Adapt_GetE2ESwitchChangeTrigger(&u8E2ESwitchCfg);
	E2ERetSts = GearMdl_Adapt_GetE2EPW_DCT9();
	DCT9StatusRet = GearMdl_Adapt_GetCANMessage_9DCT(&GearDCT9);
	u8DisplayGear = GearDCT9.GR_DisplayGear;
	u8DrvModDisp = GearDCT9.GR_DrvModDisp;
	u8TCUGearFlashing = GearDCT9.GR_TCUGearFlashing;

	if(E2E_SWITCH_ON == u8E2ESwitchCfg)
	{
		//do nothing
	}
	else
	{
		E2ERetSts = E2E_OK;
	}

	gear_inf.gear_pre_val_u8 = gear_inf.gear_actual_val_u8;

	if (FALSE == GET_GEAR_MESSAGE_MISSING(DCT9StatusRet))
	{
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_NORMAL;

		if((E2E_OK == E2ERetSts) || (E2E_INITIAL == E2ERetSts))
		{
			if((u8DrvModDisp == (uint8)GEAR_P) && (u8DisplayGear == 0xDU) && (u8TCUGearFlashing == 0x0U))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_R) && (u8DisplayGear == 0xBU) && (u8TCUGearFlashing == 0x0U))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_N) && (u8DisplayGear == 0x0U) && (u8TCUGearFlashing == 0x0U))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			} //D1~D8 ON
			else if((u8DrvModDisp == (uint8)GEAR_D) && (u8DisplayGear != 0x0U) && (u8DisplayGear <= 0x8U)\
				&& (u8TCUGearFlashing == 0x0U))
			{
				gear_inf.gear_actual_val_u8 = u8DisplayGear + GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			//P,R,N,D  Flash
			else if((u8DrvModDisp == (uint8)GEAR_P) && (u8DisplayGear == 0xDU) && (u8TCUGearFlashing == 0x1U))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_R) && (u8DisplayGear == 0xBU) && (u8TCUGearFlashing == 0x1U))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_N) && (u8DisplayGear == 0x0U) && (u8TCUGearFlashing == 0x1U))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			} //D1~D8 ON
			else if((u8DrvModDisp == (uint8)GEAR_D) && (u8DisplayGear != 0x0U) && (u8DisplayGear <= 0x8U)\
				&& (u8TCUGearFlashing == 0x1U))
			{
				gear_inf.gear_actual_val_u8 = u8DisplayGear + GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			//M1~M7 ON
			else if((u8DrvModDisp == (uint8)GEAR_M) && (u8DisplayGear != 0x0U) && (u8DisplayGear <= 0x8U))
			{
				gear_inf.gear_actual_val_u8 = u8DisplayGear + GearMdl_GEAR_M1 - 1U;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
				gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			}
		}
		else if((E2E_SYNC == E2ERetSts) || (E2E_OK_SOMELOST == E2ERetSts) || (E2E_NONEWDATA == E2ERetSts))
		{
			/* Indicates that new Data is available for E2E to be checked, and keep previous state */
		}
		else
		{
			gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
			gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			gear_disp.gear_msg_Status = (uint8)GEAR_MSG_E2E_ERROR;
		}
	}
	else
	{
		gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
		gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;
	}

	GearMdl_Gear_delay_proc_tsk();

	// log output
	if(gear_disp.gear_msg_Status != gear_e2e_Flag)
	{
		(void)Gear_warn("GEAR: [CANMsgSts %d,GVal %d, GSts %d]", gear_e2e_Flag, gear_inf.gear_actual_val_u8, gear_inf.gear_status);
		gear_e2e_Flag = gear_disp.gear_msg_Status;
	}
}

static void GearMdl_Gear_of_VCfg_PHEV_DHT(void)
{
	uint8 u8DrvModDisp = 0;
	uint8 u8DrvModDispSts = 0;
	uint8 HCU_HP5StatusRet = 0;
	uint8 u8E2ESwitchCfg = E2E_SWITCH_OFF;
	uint32 E2ERetSts = E2E_OK;
	GR_CFG_SG_HCU_HP5 HCU_HP5 = {0};

	GearMdl_Adapt_GetE2ESwitchChangeTrigger(&u8E2ESwitchCfg);
	E2ERetSts = GearMdl_Adapt_GetE2EPW_HCU_HP5();
	HCU_HP5StatusRet = GearMdl_Adapt_GetCANMessage_HCU_HP5(&HCU_HP5);
	u8DrvModDisp = HCU_HP5.GR_DrvModDisp;
	u8DrvModDispSts = HCU_HP5.GR_DrvModDispSts;

	if(E2E_SWITCH_ON == u8E2ESwitchCfg)
	{
		//do nothing
	}
	else
	{
		E2ERetSts = E2E_OK;
	}

	gear_inf.gear_pre_val_u8 = gear_inf.gear_actual_val_u8;
	if(FALSE == GET_GEAR_MESSAGE_MISSING(HCU_HP5StatusRet))
	{
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_NORMAL;

		if((E2E_OK == E2ERetSts) || (E2E_INITIAL == E2ERetSts))
		{
			if((u8DrvModDisp == (uint8)GEAR_P) && (u8DrvModDispSts == (uint8)GEAR_ON))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_R) && (u8DrvModDispSts == (uint8)GEAR_ON))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_N) && (u8DrvModDispSts == (uint8)GEAR_ON))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_D) && (u8DrvModDispSts == (uint8)GEAR_ON))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_P) && (u8DrvModDispSts == (uint8)GEAR_FLASH))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_R) && (u8DrvModDispSts == (uint8)GEAR_FLASH))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_N) && (u8DrvModDispSts == (uint8)GEAR_FLASH))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else if((u8DrvModDisp == (uint8)GEAR_D) && (u8DrvModDispSts == (uint8)GEAR_FLASH))
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_1HZ_FLASH;
			}
			else
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
				gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			}
		}
		else if((E2E_SYNC == E2ERetSts) || (E2E_OK_SOMELOST == E2ERetSts) || (E2E_NONEWDATA == E2ERetSts))
		{
			/* Indicates that new Data is available for E2E to be checked, and keep previous state */
		}
		else
		{
			gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
			gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			gear_disp.gear_msg_Status = (uint8)GEAR_MSG_E2E_ERROR;
		}
	}
	else
	{
		gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
		gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;
	}

	GearMdl_Gear_delay_proc_tsk();

	// log output
	if(gear_disp.gear_msg_Status != gear_e2e_Flag)
	{
		(void)Gear_warn("GEAR: [CANMsgSts %d,GVal %d, GSts %d]", gear_e2e_Flag, gear_inf.gear_actual_val_u8, gear_inf.gear_status);
		gear_e2e_Flag = gear_disp.gear_msg_Status;
	}
}

static void GearMdl_Gear_of_VCfg_EV(void)
{
	uint8 u8VCUGearStsIP = 0U;
	uint8 u8DrvModDisp = 0U;
	uint8 HCU_HP5StatusRet = 0U;
	uint8 u8E2ESwitchCfg = E2E_SWITCH_OFF;
	uint32 E2ERetSts = E2E_OK;
	GR_CFG_SG_HCU_HP5 HCU_HP5 = {0};

	GearMdl_Adapt_GetE2ESwitchChangeTrigger(&u8E2ESwitchCfg);
	E2ERetSts = GearMdl_Adapt_GetE2EPW_HCU_HP5();
	HCU_HP5StatusRet = GearMdl_Adapt_GetCANMessage_HCU_HP5(&HCU_HP5);
	u8DrvModDisp = HCU_HP5.GR_DrvModDisp;

	if(E2E_SWITCH_ON == u8E2ESwitchCfg)
	{
		//do nothing
	}
	else
	{
		E2ERetSts = E2E_OK;
	}

	/*VCU_FDd3StatusRet = Rte_Read_Gear_SINGAL_VCU_FD3_VCU_GearStsIP(&u8VCUGearStsIP);*/

	gear_inf.gear_pre_val_u8 = gear_inf.gear_actual_val_u8;

	if(FALSE == GET_GEAR_MESSAGE_MISSING(HCU_HP5StatusRet))
	{
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_NORMAL;

		if ((E2E_OK == E2ERetSts) || (E2E_INITIAL == E2ERetSts))
		{
			u8VCUGearStsIP = u8DrvModDisp;

			if(u8VCUGearStsIP == 0x1U)
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if(u8VCUGearStsIP == 0x2U)
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_R;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if(u8VCUGearStsIP == 0x3U)
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if(u8VCUGearStsIP == 0x4U)
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_D;
				gear_inf.gear_status = GearMdl_GEAR_NO_FLASH;
			}
			else if(u8VCUGearStsIP == 0x7U)
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_P;
				gear_inf.gear_status = GearMdl_GEAR_0_5HZ_FLASH;
			}
			else if(u8VCUGearStsIP == 0x8U)
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_N;
				gear_inf.gear_status = GearMdl_GEAR_0_5HZ_FLASH;
			}
			else
			{
				gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
				gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			}
		}
		else if ((E2E_SYNC == E2ERetSts) || (E2E_OK_SOMELOST == E2ERetSts) || (E2E_NONEWDATA == E2ERetSts))
		{
			/* Indicates that new Data is available for E2E to be checked, and keep previous state */
		}
		else
		{
			gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
			gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
			gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;
		}
	}
	else
	{
		gear_inf.gear_actual_val_u8 = GearMdl_GEAR_NO_DISPLAY;
		gear_inf.gear_status = GearMdl_GEAR_NO_SHOW;
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;
	}
	GearMdl_Gear_delay_proc_tsk();

	// log output
	if(gear_disp.gear_msg_Status != gear_e2e_Flag)
	{
		(void)Gear_warn("GEAR: [CANMsgSts %d,GVal %d, GSts %d]", gear_e2e_Flag, gear_inf.gear_actual_val_u8, gear_inf.gear_status);
		gear_e2e_Flag = gear_disp.gear_msg_Status;
	}
}
/*******************************************************************************
*
*   Function:           GearMdl_Gear_val_process
*
*   Description:        This function performs implementation of the Gear value process.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
static void GearMdl_Gear_val_process(void)
{
	if (((GEAR_CFG_PROJECT == GEAR_CFG_7DCT_PROJECT)) \
		&& (FIXDISPLAY_1_GEAR_ENABLE == GEAR_TRUE))
	{
		/* B03,B02,B06 燃油车型 Y */
		GearMdl_Gear_of_VCfg_7DCT();
	}
	else if (((GEAR_CFG_PROJECT == GEAR_CFG_9DCT_PROJECT) \
		|| (GEAR_CFG_PROJECT == GEAR_CFG_9AT_PROJECT)) \
		&& (FIXDISPLAY_1_GEAR_ENABLE == GEAR_TRUE))
	{
		/* B03,B02,B06 燃油/HEV/PHEV车型 N*/
		GearMdl_Gear_of_VCfg_9DCT();
	}
	else if ((GEAR_CFG_PROJECT == GEAR_CFG_8AT_PROJECT) \
		&& (FIXDISPLAY_1_GEAR_ENABLE == GEAR_TRUE))
	{
		/* B03,B02,B06 燃油/HEV/PHEV车型 N*/
		GearMdl_Gear_of_VCfg_8AT();
	}
	else if (((GEAR_CFG_PROJECT == GEAR_CFG_PHEV_DHT_PROJECT)) \
		&& (FIXDISPLAY_6_GEAR_ENABLE == GEAR_TRUE))
	{
		/* B02,B06 HEV/PHEV车型 Y */
		GearMdl_Gear_of_VCfg_PHEV_DHT();
	}
	else if ((GEAR_CFG_PROJECT == GEAR_CFG_EV_PROJECT) \
		&& (FIXDISPLAY_6_GEAR_ENABLE == GEAR_TRUE))
	{
		/* All project No Feature */
		GearMdl_Gear_of_VCfg_EV();
	}
	else
	{
		gear_disp.gear_val = GearMdl_GEAR_NO_DISPLAY;
		gear_disp.gear_status = GearMdl_GEAR_NO_SHOW;
		gear_disp.gear_msg_Status = (uint8)GEAR_MSG_MISSING;
	}
}

/*******************************************************************************
*
*   Function:           GearMdl_Gear_shift_of_VCfg_7DCT
*
*   Description:        This function performs implementation of the Gear ....
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           7/17/2020 HH
*******************************************************************************/
static void GearMdl_Gear_shift_of_VCfg_7DCT(void)
{
	uint8 u8DCT_ShftRecom_M = 0;
	uint8 DCT7StatusRet = 0;
	GR_CFG_SG_DCT7 Gear_SG_DCT7 = {0};
	GR_CFG_SG_DCT_FD4 Gear_DCT_FD4 = {0};

	if(gear_vcfg.boPTCAN != FALSE)//CANFD
	{
		DCT7StatusRet = GearMdl_Adapt_GetCANMessage_DCT_FD4(&Gear_DCT_FD4);
		u8DCT_ShftRecom_M = Gear_DCT_FD4.GR_DCT_ShftRecom_M;
	}
	else
	{
		DCT7StatusRet = GearMdl_Adapt_GetCANMessage_7DCT(&Gear_SG_DCT7);
		u8DCT_ShftRecom_M = Gear_SG_DCT7.GR_DCT_ShftRecom_M;
	}

	gear_inf.gear_shift_pre_val_u8 = gear_inf.gear_shift_actual_val_u8;

	if(FALSE == GET_GEAR_MESSAGE_MISSING(DCT7StatusRet))
	{
		if (u8DCT_ShftRecom_M == 0x1u)
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_UP;
		}
		else if (u8DCT_ShftRecom_M == 0x2u)
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_DOWN;
		}
		else
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
		}
	}
	else
	{
		gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	}

	GearMdl_Gear_shift_delay_proc_tsk();
}

static void GearMdl_Gear_shift_of_VCfg_9DCT(void)
{
	uint8 u8DCT_ShftRecom_M = 0;
	uint8 DCTStatusRet = 0;
	GR_CFG_SG_DCT_FD4 Gear_DCT_FD4 = {0};

	DCTStatusRet = GearMdl_Adapt_GetCANMessage_DCT_FD4(&Gear_DCT_FD4);
	u8DCT_ShftRecom_M = Gear_DCT_FD4.GR_DCT_ShftRecom_M;

	gear_inf.gear_shift_pre_val_u8 = gear_inf.gear_shift_actual_val_u8;

	if(FALSE == GET_GEAR_MESSAGE_MISSING(DCTStatusRet))
	{
		if (u8DCT_ShftRecom_M == 0x1u)
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_UP;
		}
		else if (u8DCT_ShftRecom_M == 0x2u)
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_DOWN;
		}
		else
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
		}
	}
	else
	{
		gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	}

	GearMdl_Gear_shift_delay_proc_tsk();
}

static void GearMdl_Gear_shift_of_VCfg_8AT(void)
{
	uint8 u8ShftRecom_M = 0;
	uint8 DCT9StatusRet = 0;
	GR_CFG_DCT9 GearDCT9 = {0};

	DCT9StatusRet = GearMdl_Adapt_GetCANMessage_9DCT(&GearDCT9);
	u8ShftRecom_M = GearDCT9.GR_ShftRecom_M;

	gear_inf.gear_shift_pre_val_u8 = gear_inf.gear_shift_actual_val_u8;

	if (FALSE == GET_GEAR_MESSAGE_MISSING(DCT9StatusRet))
	{
		if (u8ShftRecom_M == 0x1u)
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_UP;
		}
		else if (u8ShftRecom_M == 0x2u)
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_DOWN;
		}
		else
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
		}
	}
	else
	{
		gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	}

	GearMdl_Gear_shift_delay_proc_tsk();
}

static void GearMdl_Gear_shift_of_VCfg_MT(void)
{
	uint8 u8TgtgearUp = 0;
	uint8 u8TgtgearDown = 0;
	uint8 ECM10StatusRet = 0;
	GR_CFG_ECM10 GearECM10 = {0};

	ECM10StatusRet = GearMdl_Adapt_GetCANMessaage_ECM10(&GearECM10);
	u8TgtgearDown = GearECM10.TgtgearDown;
	u8TgtgearUp = GearECM10.TgtgearUp;

	gear_inf.gear_shift_pre_val_u8 = gear_inf.gear_shift_actual_val_u8;

	if(FALSE == GET_GEAR_MESSAGE_MISSING(ECM10StatusRet))
	{
		if((u8TgtgearUp == 0x1U) && (u8TgtgearDown == 0x0U))
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_UP;
		}
		else if((u8TgtgearUp == 0x0U) && (u8TgtgearDown == 0x1U))
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_DOWN;
		}
		else
		{
			gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
		}
	}
	else
	{
		gear_inf.gear_shift_actual_val_u8 = GearMdl_GEAR_SHIFT_NO_DISPLAY;
	}
	//Gear_info("gear shift actual value:%d \n",gear_inf.gear_shift_actual_val_u8);
	GearMdl_Gear_shift_delay_proc_tsk();
}

/*******************************************************************************
*
*   Function:           GearMdl_Gear_shift_val_process
*
*   Description:        This function performs implementation of the Gear shift value process.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
static void GearMdl_Gear_shift_val_process(void)
{
	if (((GEAR_CFG_PROJECT == GEAR_CFG_7DCT_PROJECT)) \
		&& (FIXDISPLAY_2_SHIFT_GEAR_RECOMMEND_ENABLE == GEAR_TRUE))
	{
		GearMdl_Gear_shift_of_VCfg_7DCT();
	}
	else if (((GEAR_CFG_PROJECT == GEAR_CFG_9DCT_PROJECT) \
		|| (GEAR_CFG_PROJECT == GEAR_CFG_9AT_PROJECT)) \
		&& (FIXDISPLAY_2_SHIFT_GEAR_RECOMMEND_ENABLE == GEAR_TRUE))
	{
		GearMdl_Gear_shift_of_VCfg_9DCT();
	}
	else if ((GEAR_CFG_PROJECT == GEAR_CFG_8AT_PROJECT) \
		&& (FIXDISPLAY_2_SHIFT_GEAR_RECOMMEND_ENABLE == GEAR_TRUE))
	{
		GearMdl_Gear_shift_of_VCfg_8AT();
	}
	else if ((GEAR_CFG_PROJECT == GEAR_CFG_MT_PROJECT) \
		&& (FIXDISPLAY_2_SHIFT_GEAR_RECOMMEND_ENABLE == GEAR_TRUE))
	{
		GearMdl_Gear_shift_of_VCfg_MT();
	}
	else
	{
		gear_disp.gear_shift_val = GearMdl_GEAR_NO_DISPLAY;
	}

}

/*******************************************************************************
*
*   Function:           GearMdl_get_Gear_disp
*
*   Description:        This function get the information from Gear.
*
*   Input Arguments:    GearMdl_GEAR_str_type
*
*   Return Value:       None
*
*   Modified:            6/24/2020 HH
*******************************************************************************/
void GearMdl_get_Gear_disp(IPC_M2S_SAFETYAPPGear_t *pf_gear_inf)
{
	pf_gear_inf->gear_vlaue = gear_disp.gear_val;
	pf_gear_inf->gear_status = gear_disp.gear_status;
	pf_gear_inf->gear_shift_value = gear_disp.gear_shift_val;
}

/*******************************************************************************
*
*   Function:           GearMdl_get_Gear_val_inf
*
*   Description:        This function get the information from Gear value.
*
*   Input Arguments:    None
*
*   Return Value:       gear value
*
*   Modified:            6/24/2020 HH
*******************************************************************************/
uint8 GearMdl_get_Gear_val_inf(void)
{
	return gear_disp.gear_val;
}

/*******************************************************************************
*
*   Function:           GearMdl_get_Gear_Not_P_Status
*
*   Description:        This function get the status of not P gear.
*
*   Input Arguments:    None
*
*   Return Value:
*
*   Modified:            6/24/2020 HH
*******************************************************************************/
uint8 GearMdl_get_Gear_not_P_status(void)
{
	uint8 NonPGearSts = 0U;

	if((uint8)GEAR_P != gear_disp.gear_val)
	{
		NonPGearSts = 1U;
	}
	else
	{
		NonPGearSts = 0U;
	}
	return NonPGearSts;
}

static void GearMdl_Set_vehicle_config(void)
{
	CconfigKind_400Bytes CconfigKind;
	VconfigKind_Allbuffers VCfg_kindBuffers;
	boolean boCcfgFixDisplayGearEnable = FALSE;
	boolean boCcfgFixDisplayShiftGearRecommendEnable = FALSE;
	boolean boCcfgFixDisplay6GearEnable = FALSE;
	boolean boCcfgFixDisplay6ShiftGearRecommendEnable = FALSE;

	/*get cconfig*/
	if(E_OK == GearMdl_Adapt_GetCconfig(CconfigKind))
	{
		boCcfgFixDisplayGearEnable = (CConfig_GetConfig(CCONFIG_KIND_FIXDISPLAY_1_GEAR_ENABLE, CconfigKind) != 0U) ? TRUE : FALSE;
		boCcfgFixDisplayShiftGearRecommendEnable = (CConfig_GetConfig(CCONFIG_KIND_FIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE, CconfigKind) != 0U) ? TRUE : FALSE;;
		boCcfgFixDisplay6GearEnable = (CConfig_GetConfig(CCONFIG_KIND_DISPLAY_6_GEAR_ENABLE, CconfigKind) != 0U) ? TRUE : FALSE;
		boCcfgFixDisplay6ShiftGearRecommendEnable = (CConfig_GetConfig(CCONFIG_KIND_DISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE, CconfigKind) != 0U) ? TRUE : FALSE;
	}
	else
	{
		boCcfgFixDisplayGearEnable = TRUE;
		boCcfgFixDisplayShiftGearRecommendEnable = TRUE;
		boCcfgFixDisplay6GearEnable = TRUE;
		boCcfgFixDisplay6ShiftGearRecommendEnable = TRUE;
	}

	gear_vcfg.boCcfgFixDisplayGearEnable = boCcfgFixDisplayGearEnable;
	gear_vcfg.boCcfgFixDisplayShiftGearRecommendEnable = boCcfgFixDisplayShiftGearRecommendEnable;
	gear_vcfg.boCcfgFixDisplay6GearEnable = boCcfgFixDisplay6GearEnable;
	gear_vcfg.boCcfgFixDisplay6ShiftGearRecommendEnable = boCcfgFixDisplay6ShiftGearRecommendEnable;

	/*get vconfig*/
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VCfg_kindBuffers);
	if(gear_vcfg.u8InitFlag == 0U)
	{
		gear_vcfg.u8InitFlag = VCfg_kindBuffers[VCONFIG_KIND_INIT_FLAG];
		gear_vcfg.u8transmission = VCfg_kindBuffers[GEAR_VCONFIG_KIND_TRANSMISSION];
		//gear_vcfg.u8engineControlUnit = VCfg_kindBuffers[GEAR_VCONFIG_KIND_ENGINE_CONTROL_UNIT];
		gear_vcfg.u8fuel = VCfg_kindBuffers[GEAR_VCONFIG_KIND_FUEL];
		gear_vcfg.u8electromotorPosition = VCfg_kindBuffers[GEAR_VCONFIG_KIND_ELECTROMOTOR_POSITION];
		gear_vcfg.boPTCAN = (VCfg_kindBuffers[VCONFIG_KIND_PT_CAN_BUS_TYPE] == 1U) ? TRUE : FALSE;
	}

	/*judge project enable*/
	if((gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_7DCT) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_7DCT_300S) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_7DCT_400S))
	{
		gear_Vconfig = GEAR_CFG_7DCT_PROJECT;
	}
	else if((gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_9DCT) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_9HDCT))
	{
		gear_Vconfig = GEAR_CFG_9DCT_PROJECT;
	}
	else if(gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_8AT)
	{
		gear_Vconfig = GEAR_CFG_8AT_PROJECT;
	}
	else if((gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_9AT) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_9HAT))
	{
		gear_Vconfig = GEAR_CFG_9AT_PROJECT;
	}
	else if(((gear_vcfg.u8fuel == GEAR_CFG_FUEL_DIESEL) \
		|| (gear_vcfg.u8fuel == GEAR_CFG_FUEL_GASOLINE) \
		|| (gear_vcfg.u8fuel == GEAR_CFG_FUEL_GASOLINE_NATURL) \
		|| (gear_vcfg.u8fuel == GEAR_CFG_FUEL_NATURL_GAS)) \
		&& ((gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_5MT_0x1) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_5MT_0xC) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_6MT_0xD) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_6MT_0xE) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_6MT_0x25) \
		|| (gear_vcfg.u8transmission == GEAR_CFG_TRANSMISSION_6MT_0x2)))
	{
		gear_Vconfig = GEAR_CFG_MT_PROJECT;
	}
	else if(((gear_vcfg.u8fuel == GEAR_CFG_FUEL_PHEV) || (gear_vcfg.u8fuel == GEAR_CFG_FUEL_HEV)) \
		&& ((gear_vcfg.u8electromotorPosition == GEAR_CFG_POSITION_PS) || (gear_vcfg.u8electromotorPosition == GEAR_CFG_POSITION_PS_P4)))
	{
		gear_Vconfig = GEAR_CFG_PHEV_DHT_PROJECT;
	}
	else if(gear_vcfg.u8fuel == GEAR_CFG_FUEL_EV)
	{
		gear_Vconfig = GEAR_CFG_EV_PROJECT;
	}
	else
	{
		gear_Vconfig = GEAR_CFG_NULL_PROJECT;
	}

}

uint8 GearMdl_get_vehicle_config(void)
{
	return gear_Vconfig;
}


/*******************************************************************************
*
*   Function:           GearMdl_SOCManager_send_Gear_inf
*
*   Description:        This function send gear info to mcu
*
*   Input Arguments:    None
*
*   Return Value:
*
*   Modified:            4/07/2021 HH
*******************************************************************************/
static void GearMdl_SOCManager_send_Gear_inf(void)
{
	(void)Rte_Write_ppSR_SWCSafety_DrvGearDisp_Element(gear_disp.gear_val);
	(void)Rte_Write_ppSR_SWCSafety_GearMsgMiss_Element(gear_disp.gear_msg_Status);
}

static void GearMdl_SBUS_send_Gear_inf(void)
{
	IPC_M2S_SAFETYAPPGear_t ipc_sendData;
// #define Common_Safety_START_SEC_VAR_NOINIT_UNSPECIFIED
// #include "Common_Safety_MemMap.h"
// 	static IPC_M2S_ClusterAppAPPGear_t ipc_sendDataPre;
// #define Common_Safety_STOP_SEC_VAR_NOINIT_UNSPECIFIED
// #include "Common_Safety_MemMap.h"
	GearMdl_get_Gear_disp(&ipc_sendData);
#if 0
	if(ipc_sendData.gear_status == GearMdl_GEAR_NO_FLASH)
	{
		if(ipc_sendData.gear_vlaue != ipc_sendDataPre.gear_vlaue)
		{
			Os_Timer_Start(enGearTimerA);

			memcpy(&ipc_sendDataPre, &ipc_sendData, sizeof(IPC_M2S_ClusterAppAPPGear_t));
		}
	}
	else
	{
		if(FALSE == Os_Timer_IsStarted(enGearTimerA))
		{
			Os_Timer_Start(enGearTimerA);
		}
	}

	if((FALSE != Os_Timer_IsElapsed(enGearTimerA, CRC_TIMEOUT)) && (ipc_sendData.gear_vlaue != GearMdl_GEAR_NO_DISPLAY))
	{
		Rte_Call_IPC_Send_IPC_Send(SWC_IPC_CLUSTER_APP_M2S_GEAR, (uint8 *)&ipc_sendData,sizeof(IPC_M2S_ClusterAppAPPGear_t),TRUE);//TRUE

		Os_Timer_IsElapsedRestart(enGearTimerA, CRC_TIMEOUT);

		//Os_Timer_IsElapsedRestart(enGearTimerB, CRC_TIMEOUT);
	}
#endif
	/* IPC send */
	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_GEAR, (uint8 *)&ipc_sendData,(uint16)sizeof(IPC_M2S_SAFETYAPPGear_t),FALSE);//TRUE

	if(TRUE == boGearIpcCallback)
	{
		Gear_FunctionSafety_CRC_Check();
		boGearIpcCallback = FALSE;
	}
}

extern void Os_Timer_Start(const GR_TimerID TimerId)
{
	uint8 u8status = 0;
	u8status = Rte_Call_Gear_Os_Service_GetCounterValue(&timerCfg[TimerId].TimerTicks);
	if(u8status == RTE_E_Os_Service_E_OK)
	{
		timerCfg[TimerId].TimerStatus = OSTM_TIMER_RUNING;
	}
	else
	{
		timerCfg[TimerId].TimerStatus = OSTM_TIMER_START_ERROR;
	}
}

extern void Os_Timer_Stop(const GR_TimerID TimerId)
{
	timerCfg[TimerId].TimerStatus = OSTM_TIMER_CLEAR;
}

extern boolean Os_Timer_IsStarted(const GR_TimerID TimerId)
{
	boolean IsStarted = FALSE;

	IsStarted = (boolean)(timerCfg[TimerId].TimerStatus == OSTM_TIMER_RUNING);

	return IsStarted;
}

extern boolean Os_Timer_IsElapsed(const GR_TimerID TimerId, const uint32 Timeout)
{
	boolean IsElapsed = FALSE;
	uint8 u8status = 0;
	uint32 oldTimerTicks = 0;
	uint32 ElapsedTime = 0;

	oldTimerTicks = timerCfg[TimerId].TimerTicks;
	u8status = Rte_Call_Gear_Os_Service_GetElapsedValue(&oldTimerTicks, &ElapsedTime);

	if(OSTM_TIMER_CLEAR == timerCfg[TimerId].TimerStatus)
	{
		ElapsedTime = 0;
	}
	else if(OSTM_TIMER_START_ERROR == timerCfg[TimerId].TimerStatus)
	{
		ElapsedTime = 0;
	}
	else
	{
		if(u8status != RTE_E_Os_Service_E_OK)
		{
			ElapsedTime = 0;
		}
	}

	IsElapsed = (boolean)(ElapsedTime >= (Timeout*OSTM_TIMER_FACTOR));

	return IsElapsed;
}

extern boolean Os_Timer_IsElapsedRestart(const GR_TimerID TimerId, const uint32 Timeout)
{
	boolean Ret = FALSE;

	Ret = Os_Timer_IsElapsed(TimerId, Timeout);

	if(FALSE != Ret)
	{
		timerCfg[TimerId].TimerTicks += (Timeout * OSTM_TIMER_FACTOR);

	}

	return Ret;
}

extern uint32 Os_Timer_GetElapsedTime(const GR_TimerID TimerId)
{
	uint8 u8status = 0;
	uint32 oldTimerTicks = 0;
	uint32 ElapsedTime = 0;

	oldTimerTicks = timerCfg[TimerId].TimerTicks;
	u8status = Rte_Call_Gear_Os_Service_GetElapsedValue(&oldTimerTicks, &ElapsedTime);

	if(OSTM_TIMER_CLEAR == timerCfg[TimerId].TimerStatus)
	{
		ElapsedTime = OSTM_TIMER_MAX_COUNTER;
	}
	else if(OSTM_TIMER_START_ERROR == timerCfg[TimerId].TimerStatus)
	{
		ElapsedTime = OSTM_TIMER_MAX_COUNTER;
	}
	else
	{
		if(u8status != RTE_E_Os_Service_E_OK)
		{
			ElapsedTime = OSTM_TIMER_MAX_COUNTER;
		}
	}

	return ElapsedTime;
}

static void Gear_FunctionSafety_CRC_Check(void)
{
	//Rte_Enter_ExclusiveArea();
	//Os_Timer_Stop(enGearTimerA);
	//Os_Timer_IsElapsedRestart(enGearTimerB, CRC_TIMEOUT);

 	if(gearCrc[GearCRCData.Gear_ID].CRC_Value == GearCRCData.CRC_Value)
	{

		ipcGearCrcAck.u_SafetyGearCheckGear_ACK_t.s_Gear_ACK_t.Gear_ID = GearCRCData.Gear_ID;
		ipcGearCrcAck.u_SafetyGearCheckGear_ACK_t.s_Gear_ACK_t.ACK_Value = GEAR_CRC_ACK_OK;
	}
	else
	{
		ipcGearCrcAck.u_SafetyGearCheckGear_ACK_t.s_Gear_ACK_t.Gear_ID = GearCRCData.Gear_ID;
		ipcGearCrcAck.u_SafetyGearCheckGear_ACK_t.s_Gear_ACK_t.ACK_Value = GEAR_CRC_ACK_ERROR;
	}

	(void)IPC_M2S_SAFETYAPPSafetyGearCheck_Transmit(&ipcGearCrcAck);
	//Rte_Exit_ExclusiveArea();
}

FUNC(void, RTE_CODE) IPC_API_ReceiveSafetyGearCRCCallback(uint8 *data)
{
	if(NULL != data)
	{
	 	const IPC_S2M_SAFETYAPPSafetyGearCRC_t* RcGearCRCData = (IPC_S2M_SAFETYAPPSafetyGearCRC_t *)data;
		(void)memcpy(&GearCRCData, RcGearCRCData, sizeof(IPC_S2M_SAFETYAPPSafetyGearCRC_t));
		boGearIpcCallback = TRUE;
	}
}

FUNC(void, RTE_CODE) RTE_API_GearErrorCallback(const uint8 *data)
{
	u8GearErrorSwitch = *data;
}

/*
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Os_Service_GetCounterValue(uint32* Value)
{
	return 0;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Os_Service_GetElapsedValue(uint32* Value, uint32* ElapsedValue)
{
	return 0;
}
*/

#define Common_GateWay_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

