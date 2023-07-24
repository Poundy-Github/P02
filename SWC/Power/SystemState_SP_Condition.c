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
 * @file:      SystemState_SP_Condition.c
 * @author:    Nobo
 * @date:      2020-8-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "SystemState_SP_Condition.h"
#include "SystemState_InitCfg.h"
#include "Rte_Power.h"
#include "Logger_Cfg.h"
#include "logger.h"
#include "SOCManager_Type.h"
#include "Power_Volt_monitor.h"
#include "SystemState_HUD_Condition.h"
#include "SystemState_Console_Condition.h"
#include "SystemState_IVI_Condition.h"
#include "SystemState_Conditon_Element.h"
#include "SystemState_Cluster_Condition.h"
#include "Power_OutMgr.h"
#include "string.h"
#include "Power_Temp_Monitor.h"
#include "SOCManager.h"


#define SYSTEMSTATE_SP_SUBSTATE_ALL_OFF             (0u)
#define SYSTEMSTATE_SP_QNX_CLOSE_ALL                (1u)
#define SYSTEMSTATE_SP_STATE_NO_CHANGE              (2u)
#define SYSTEMSTATE_SP_IPCOFF                       (3u)
#define SYSTEM_STATE_TRANSFER_OK                    (0u)//transfer success
#define SYSTEM_STATE_TRANSFER_PENDING               (1u)//transfer pending
#define SM_SP_STATE_MACHINE_NUMBER                  (1u)
#define SM_SP_STATE_NUMBER                          (4u)
#define SM_SP_TRANSFER_CONDITION_NUMBER             (6u)
#define SM_SP_TRANSFER_ELEMENT_NUMBER               (19u)
#define SM_SP_TRANSFER_ACTION_NUMBER                (76u)
#define SM_SP_FEATURE_CONFIG_VALUE_NUMBER           (38u)
#define SM_SP_FEATURE_VALUE_NUMBER                  (2u)
#define SM_SP_ENTRY_NUMBER                          SM_SP_STATE_MACHINE_NUMBER
#define SM_SP_TRANSFER_NUMBER                       SM_SP_STATE_MACHINE_NUMBER
#define SM_SP_STAY_NUMBER                           SM_SP_STATE_MACHINE_NUMBER
#define SYSTEMSTATE_SP_VOLTAGERECIVER_RESET         (1u)
#define SYSTEMSTATE_SP_OFF_STAY_TIMEOUT             (1000u)
#define ENTEROFF             						(1u)
#define STILLWAIT             						(0u)
#define SM_SP_TemporVol_Sleep						(1u)
#define SM_SP_TemporVol_Sleep_Clear					(0u)


#define POWER_TEST_LOG(X)                          {\
if(X != ret)\
{\
    power_debug("%s change from %d to %d\n",#X, X, ret);\
}\
X = ret;\
}


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void SM_EntryCallbackSP(void);
static void SM_TransferCallbackSP(SM_StateType previous, SM_StateType next);
static void SM_StayCallbackSP(SM_StateType state);
static uint8 SM_ConditionSP_StateCOM(void);
static uint8 SM_ConditionSP_StateSubSM(void);
static uint8 SM_ConditionSP_StateQnxStatus(void);
static uint8 SM_ConditionSP_StateCDDStatus(void);
static uint8 SM_ConditionSP_StateSOCStatus(void);
static void SystemState_SP_EnterOffLogic(void);
static uint8 SM_ConditionSP_StateEnvironment(void);
static uint8 SystemState_SP_OffStayReset_judg(void);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"

#pragma ghs startdata
#pragma ghs section bss = ".rram_misc" 

//static uint8 ShutDownReason;

#pragma ghs section bss = default
#pragma ghs enddata


#define POWER_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "POWER_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
uint8 SystemState_SP_State;


static uint8 SPfeatureValues[SM_SP_FEATURE_VALUE_NUMBER];
static boolean SystemState_ChangetoOFF;
static SM_StateMachineType SPstateMachineDatas[SM_SP_STATE_MACHINE_NUMBER];

static uint32 SystemState_QNXCloseTimer = 0u;
static uint32 SystemState_SOCOFFTimer = 0u;
static uint32 Power_CDDTimer = 0u;
static uint8 SystemState_QNXCloseTimerSts = SYSTEMSTATE_TIMERNORMAL;
static uint8 SystemState_SOCOFFTimerSts = SYSTEMSTATE_TIMERNORMAL;
static uint8 Power_CDDTimerSts = SYSTEMSTATE_TIMERNORMAL;
static uint32 TimerFlg = 0u;
static uint8 StateCom;
static uint8 StateSubSM;
static uint8 QnxSts;
static uint8 CDDSts;
static uint8 SOCSts;
static uint16 PM_StayOff_Timer = 0u;
static uint8 SP_Enter_Shutdown_Reason;
static uint8 SP_Enter_Shutdown_Reason_flg;


extern s_PowerOut_t Power_OutDataCurrent; 


SM_Type Sm_SP = {(SM_StateMachineIdType)SM_STATEMACHINE_INVALID, (SM_SequenceType)SM_SEQUENCE_IDLE,\
				(boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (SM_ConfigType*)NULL_PTR};

static uint32 SM_MCU_Statrt = 0u;
static uint32 SM_MCU_End = 0u;

#define POWER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "POWER_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"

static const uint8 SPfeatureConfigValues[SM_SP_FEATURE_CONFIG_VALUE_NUMBER] =
{
    0xF9, 0xFF, 
    0x95, 0xFD, 
    0x95, 0xFE, 
    0x65, 0xFD, 
    0x55, 0xFD, 
    0x55, 0xFE, 
    0xA5, 0xFE, 
    0xA5, 0xFD, 
    0xFA, 0xFB, 
    0x76, 0xFA, 
    0xB6, 0xFA, 
    0x76, 0xF9, 
    0xB6, 0xF9, 
    0x65, 0xFE, 
    0xFA, 0xF7, 
    0x76, 0xF6, 
    0xB6, 0xF6, 
    0x76, 0xF5, 
    0xB6, 0xF5, 
};

static const SM_StateType SPtargets[SM_SP_TRANSFER_ACTION_NUMBER] =
{
    0, 1, 2, 3, 
    0, 1, 1, 3, 
    0, 1, 1, 0, 
    0, 1, 1, 3, 
    0, 1, 1, 3, 
    0, 1, 1, 0, 
    0, 3, 1, 0, 
    0, 3, 1, 3, 
    2, 1, 2, 3, 
    2, 1, 2, 0, 
    2, 2, 2, 0, 
    2, 1, 1, 3, 
    2, 2, 2, 3, 
    0, 1, 1, 0, 
    0, 1, 2, 3, 
    0, 1, 1, 0, 
    0, 3, 1, 0, 
    0, 1, 1, 3, 
    0, 3, 1, 3, 
};

static const SM_TransferElementConfigType SPtransferElementConfigs[SM_SP_TRANSFER_ELEMENT_NUMBER] =
{
    {0, 2, 0, 4},
    {2, 4, 4, 8},
    {4, 6, 8, 12},
    {6, 8, 12, 16},
    {8, 10, 16, 20},
    {10, 12, 20, 24},
    {12, 14, 24, 28},
    {14, 16, 28, 32},
    {16, 18, 32, 36},
    {18, 20, 36, 40},
    {20, 22, 40, 44},
    {22, 24, 44, 48},
    {24, 26, 48, 52},
    {26, 28, 52, 56},
    {28, 30, 56, 60},
    {30, 32, 60, 64},
    {32, 34, 64, 68},
    {34, 36, 68, 72},
    {36, 38, 72, 76},
};

static const SM_TransferConditionConfigType SPtransferConditionConfigs[SM_SP_TRANSFER_CONDITION_NUMBER] =
{
    {0, 0, 2},
    {1, 2, 4},
    {2, 4, 6},
    {3, 6, 8},
    {4, 8, 10},
    {5, 10, 12},
};

static const SM_StateConfigType SPstateConfigs[SM_SP_STATE_NUMBER] =
{
    {"SP_Off", 0xFF},
    {"SP_ShutDown", 0xFF},
    {"SP_Standby", 0xFF},
    {"SP_SOCOFF", 0xFF},
};

static const SM_StateMachineConfigType SPstateMachineConfigs[SM_SP_STATE_MACHINE_NUMBER] =
{
    {(boolean)TRUE, 0, 4, 0, 6, 0, 19, 0, 2, 0, 0, 0},
};


static const SM_TransferConditionType SPtransferConditions[SM_SP_TRANSFER_CONDITION_NUMBER] =
{
    SM_ConditionSP_StateCOM,
    SM_ConditionSP_StateSubSM,
    SM_ConditionSP_StateQnxStatus,
    SM_ConditionSP_StateCDDStatus,
    SM_ConditionSP_StateSOCStatus,
    SM_ConditionSP_StateEnvironment,
};

static const SM_EntryCallbackType SPentrys[SM_SP_ENTRY_NUMBER] =
{
    SM_EntryCallbackSP,
};

static const SM_TransferCallbackType SPtransfers[SM_SP_TRANSFER_NUMBER] =
{
    SM_TransferCallbackSP,
};

static const SM_StayCallbackType SPstays[SM_SP_STAY_NUMBER] =
{
    SM_StayCallbackSP,
};

static const SM_ConfigType sm_SP_config =
{
    SM_SP_STATE_MACHINE_NUMBER,
    SPstateMachineConfigs,
    SPstateMachineDatas,
    SM_SP_TRANSFER_ELEMENT_NUMBER,
    SPtransferElementConfigs,
    SM_SP_TRANSFER_CONDITION_NUMBER,
    SPtransferConditionConfigs,
    SM_SP_TRANSFER_ACTION_NUMBER,
    SPtargets,
    SM_SP_FEATURE_CONFIG_VALUE_NUMBER,
    SPfeatureConfigValues,
    SM_SP_FEATURE_VALUE_NUMBER,
    SPfeatureValues,
    SM_SP_STATE_NUMBER,
    SPstateConfigs,
    SM_SP_TRANSFER_CONDITION_NUMBER,
    SPtransferConditions,
    SM_SP_ENTRY_NUMBER,
    SPentrys,
    SM_SP_TRANSFER_NUMBER,
    SPtransfers,
    SM_SP_STAY_NUMBER,
    SPstays
};
#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   
 ***********************************************************************/
static void SM_EntryCallbackSP(void)
{
    //power_warn("State machine Power entry SYSTEMSTATE_SM_STATE_SP_OFF");
    SM_StateCurrentSet(&Sm_SP,SYSTEMSTATE_SP_OFF);
    SystemState_SP_State = SYSTEMSTATE_SP_OFF;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   
 ***********************************************************************/
static void SM_TransferCallbackSP(SM_StateType previous, SM_StateType next)
{
    const char *previousName;
    const char *nextName;

    (void)SM_StateNameGet(&Sm_SP, previous, &previousName);
    (void)SM_StateNameGet(&Sm_SP, next, &nextName);
    POWER_GET_OSTiCK(&TimerFlg);
    power_warn("[%ld Ms]SM %s->%s", TimerFlg, previousName, nextName);
    power_info("SP trans reasonID:%d", SPstateMachineDatas[0].transferElement);
    SystemState_SP_State = next;

    if (SYSTEMSTATE_SP_STANDBY == next)
    {
        //Tell CDD Init, Not need Response
        SystemState_CDDInitFunc();
        //SocManager receive State Change from off -->Standby, Soc Init
        SystemState_IVIEnableSet(TRUE);
        SystemState_ClusterEnableSet(TRUE);
        SystemState_HUDEnableSet(TRUE);
        SystemState_ConsoleEnableSet(TRUE);
    }
    
    if ((SYSTEMSTATE_SP_STANDBY == previous) && (SYSTEMSTATE_SP_SHUTDOWN == next))
    {
        SystemState_IVIEnableSet(FALSE);
        SystemState_HUDEnableSet(FALSE);
        SystemState_ConsoleEnableSet(FALSE);
        SystemState_ClusterEnableSet(FALSE);
        SystemState_CDDDeInitFunc();
        PM_ClearKL5Onceflag();
		if(SM_SP_TemporVol_Sleep == SP_Enter_Shutdown_Reason)
        {
        	SP_Enter_Shutdown_Reason_flg = SM_SP_TemporVol_Sleep;
        }
        if(Power_CDDTimer != 0)
        {
            power_err("Power_CDDTimer not clear");
        }
        Power_CDDTimer ++;

        if (0u != SystemState_QNXCloseTimer)
        {
            power_err("SystemState_QNXCloseTimer not clear");
        }
        SystemState_QNXCloseTimer++;
        POWER_GET_OSTiCK(&SM_MCU_Statrt);
    }
    
    if ((SYSTEMSTATE_SP_SHUTDOWN == previous) && (SYSTEMSTATE_SP_SOCOFF == next))
    {
        POWER_GET_OSTiCK(&SM_MCU_End);
        power_warn("SM SP shutdown->SOCoff use %dms\r\n",SM_MCU_End - SM_MCU_Statrt);
        SystemState_SOCOFFTimer ++;
        POWER_GET_OSTiCK(&SM_MCU_Statrt);
    }
    
    if ((SYSTEMSTATE_SP_SOCOFF == previous)&&(SYSTEMSTATE_SP_OFF == next))
    {
        POWER_GET_OSTiCK(&SM_MCU_End);
        power_warn("SM SP SOCOFF->OFF use %dms\r\n",SM_MCU_End - SM_MCU_Statrt);
        SystemState_ChangetoOFF = TRUE;
		PM_StayOff_Timer = 0u;        
        SystemState_SOCOFFTimer = 0u;
        SystemState_SOCOFFTimerSts = SYSTEMSTATE_TIMERNORMAL;
    }

    if(SYSTEMSTATE_SP_SHUTDOWN == previous) 
    {
        SystemState_QNXCloseTimer = 0u;
        Power_CDDTimerSts = SYSTEMSTATE_TIMERNORMAL;
        SystemState_QNXCloseTimerSts = SYSTEMSTATE_TIMERNORMAL;
        Power_CDDTimer = 0u;
    }
    if((SYSTEMSTATE_SP_SHUTDOWN == previous)&&(SYSTEMSTATE_SP_SOCOFF != next))
    {
		SP_Enter_Shutdown_Reason_flg = SM_SP_TemporVol_Sleep_Clear;
    }
    if(SYSTEMSTATE_SP_OFF == previous)
    {
		SystemState_ChangetoOFF = FALSE;
    }
	

    
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   
 ***********************************************************************/
static void SM_StayCallbackSP(SM_StateType state)
{
    if(LOGTIMERTIMEOUT == PowerLogStsFunc(TIMER2S))
    {
        const char *StateName;
        (void)SM_StateNameGet(&Sm_SP,state,&StateName);
        power_verbose("SM SP stay in state %s",StateName);
    }
    SystemState_SP_State = state;
    SystemState_SP_EnterOffLogic();
}

/***********************************************************************
this func prevent  defect:P05-1145&V35-53717
 ***********************************************************************/
static uint8 SystemState_SP_OffStayReset_judg(void)
{
	uint8 ret = STILLWAIT;
	static uint8 logflag;
	if(SystemState_SP_State == SYSTEMSTATE_SP_OFF)
	{
		if(PM_StayOff_Timer < SYSTEMSTATE_SP_OFF_STAY_TIMEOUT)
		{
			PM_StayOff_Timer++;
			ret = STILLWAIT;
		}
		else
		{
			ret = ENTEROFF;
			if(0 ==logflag)
			{
				power_warn("SP stay off more than 5s!");
				logflag = 1;
			}
		}		
	}
	return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   
 ***********************************************************************/
static void SystemState_SP_EnterOffLogic(void)
{
	uint8 Stay_Off_ret = 0;
	static uint8 SPoff_logflag = 0u;
	Stay_Off_ret = SystemState_SP_OffStayReset_judg();
    if((TRUE == SystemState_ChangetoOFF)||(ENTEROFF == Stay_Off_ret))
    {   
        Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
        if(SYSTEMSTATE_NMNOCOMMUNICATION == Systemstate_Condition_element_local.NMState)
        {
        	PM_ClearRemoteflag();
            (void)Rte_Write_Power_Ecum_Set_SystemState_Run_Element((boolean)0u);
            (void)Rte_Write_Request_PowerModeShutdownReq_requestedMode(BswMReqSleep);
            power_warn("SP off, NOCOM Sleep!");
            SM_EnabledSet(&Sm_SP, FALSE);
            PM_StayOff_Timer = 0u;
            SystemState_ChangetoOFF = FALSE;
        }
        else if ((SM_SP_TemporVol_Sleep == SP_Enter_Shutdown_Reason_flg)||(ENTEROFF == Stay_Off_ret))
        {
            uint8 Power_VoltageFlg      = Power_VoltageRecoverFlg();
            uint8 Power_TempetureFlg    = Power_TempStateRTUFlg();
            if(0u == SPoff_logflag)
            {
            	power_err("enter_spoff reason:vol%d,temp%d,eol%d",Power_VoltageFlg,Power_TempetureFlg,Power_EolSleepflag);
            	SPoff_logflag = 1;
			}
            if((POWER_VOLTAGE_NORMAL == Power_VoltageFlg) && (POWER_TEMP_NORMAL == Power_TempetureFlg))
            {
                (void)Rte_Write_Power_Ecum_Set_SystemState_Run_Element((boolean)0u);

                power_err("volt high/lowsleep->noraml,shutdown");
                Rte_Write_Request_PowerModeShutdownReq_requestedMode(BswMReqShutdown);
                SM_EnabledSet(&Sm_SP, FALSE);
				PM_StayOff_Timer = 0u;
                SystemState_ChangetoOFF = FALSE;
                SP_Enter_Shutdown_Reason_flg = SM_SP_TemporVol_Sleep_Clear;
            }
            else
            {
                /*Wait Voltage recover Normal*/
            }
        }
        else
       	{
			/*soc off,nm awake, exit*/
       	}
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   
 ***********************************************************************/
void SystemState_SPInit(void)
{
    SystemState_ChangetoOFF = FALSE;
    PM_StayOff_Timer = 0u;
    SystemState_SP_State = SYSTEMSTATE_SP_OFF;
    memset(SPfeatureValues,0,SM_SP_FEATURE_VALUE_NUMBER);
    memset(SPstateMachineDatas,0,sizeof(SM_StateMachineType)*SM_SP_STATE_MACHINE_NUMBER);
    SystemState_QNXCloseTimer = 0u;
    Power_CDDTimer = 0u;
    SystemState_SOCOFFTimer = 0u;
    SystemState_QNXCloseTimerSts = SYSTEMSTATE_TIMERNORMAL;
    SystemState_SOCOFFTimerSts = SYSTEMSTATE_TIMERNORMAL;
    Power_CDDTimerSts = SYSTEMSTATE_TIMERNORMAL;
    SP_Enter_Shutdown_Reason_flg = SM_SP_TemporVol_Sleep_Clear;
    SP_Enter_Shutdown_Reason = SM_SP_TemporVol_Sleep_Clear;
    SM_Init(&Sm_SP,&sm_SP_config);
    SystemState_IVIInit();
    SystemState_Cluster_Init();
    SystemState_HUDInit();
    SystemState_ConsoleInit();
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   
 ***********************************************************************/
void SystemState_SP_MainFunc(void)
{
    Power_CDDTimerSts = SystemState_TimerKernel(&Power_CDDTimer, POWER_CDDCLOSETIMEOUT);
    SystemState_QNXCloseTimerSts = SystemState_TimerKernel(&SystemState_QNXCloseTimer, SYSTEMSTATE_QNXCLOSETIMEOUT);
    SystemState_SOCOFFTimerSts = SystemState_TimerKernel(&SystemState_SOCOFFTimer,SYSTEMSTATE_SOCOFF_5S);
    SM_MainFunction(&Sm_SP);
    SystemState_IVI_MainFunc();
    SystemState_Cluster_MainFunc();
    SystemState_HUD_MainFunc();
    SystemState_Console_MainFunc();
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   
 ***********************************************************************/
void SystemState_SPEnableSet(boolean Enabled)
{
    SM_EnabledSet(&Sm_SP, Enabled);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   
 ***********************************************************************/
uint8 SystemState_SP_Sts(void)
{
    return SystemState_SP_State;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   0x0: FullCOM
                    0x1: NoCOM
 ***********************************************************************/
static uint8 SM_ConditionSP_StateCOM(void)
{
    uint8 ret;
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    if(SYSTEMSTATE_NMFULLCOMMUNICATION == Systemstate_Condition_element_local.NMState)
    {
        ret = 0x0u;
    }
    else 
    {
        ret = 0x1u;
    }
    POWER_TEST_LOG(StateCom);
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   0x0:RUN
                    0x1:OFF
 ***********************************************************************/
static uint8 SM_ConditionSP_StateSubSM(void)
{
    uint8 ret;
    SystemState_HUD_PA_t SystemState_HUD_PA = SystemState_HUDSts();
    SystemState_Console_PA_t SystemState_Console_PA = SystemState_ConsoleSts();
    s_Systemstate_IVI_PA_t SystemState_IVI_PA = SystemState_IVISts();
    SystemState_Cluster_PA_t SystemState_Cluster_PA_local = SystemState_ClusterSts();
    
    if ((SYSTEMSTATE_IVI_OFF == SystemState_IVI_PA.State) &&
        (SYSTEMSTATE_Cluster_OFF == SystemState_Cluster_PA_local) &&
        (SYSTEMSTATE_HUD_OFF == SystemState_HUD_PA.State) &&
        (SYSTEMSTATE_CONSOLE_OFF == SystemState_Console_PA.State))
    {
        ret = 0x1u;
    }
    else 
    {
        ret = 0x0u;
    }
    POWER_TEST_LOG(StateSubSM);
    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   0x0: Receive
                    0x1: Pending
 ***********************************************************************/
static uint8 SM_ConditionSP_StateQnxStatus(void)
{
    uint8 ret;
    uint8 SystemState_QnxCloseResponse = Power_QnxCloseResponse();
    if ((SYSTEMSTATE_TIMEOUT == SystemState_QNXCloseTimerSts)||(1u == SystemState_QnxCloseResponse))
    {
        if(SYSTEMSTATE_TIMEOUT == SystemState_QNXCloseTimerSts)
        {
            //power_info("not receive qnx close responst, 10s timeout");
        }
        if(1u == SystemState_QnxCloseResponse)
        {
            //power_info("receive qnx close response");
        }
        ret = 0x0u;
    }
    else
    {
        ret = 0x1u;
    }
    POWER_TEST_LOG(QnxSts);
    return ret;
}

/***********************************************************************
 * @brief       :   timeout 1s
 * @param       : 
 * @retval      :   0x0: Finish
                    0x1: Pending
 ***********************************************************************/
static uint8 SM_ConditionSP_StateCDDStatus(void)
{
    uint8 ret;
    if((SYSTEMSTATE_TIMEOUT == Power_CDDTimerSts))
    {        
        ret = 0x0u; 
    }
    else 
    {
        ret = 0x1u;
    }
    POWER_TEST_LOG(CDDSts);
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   0x0:    Finish
                    0x1:    Pending
 ***********************************************************************/
static uint8 SM_ConditionSP_StateSOCStatus(void)
{
    uint8 ret;
    if(SYSTEMSTATE_SP_SOCOFF == SystemState_SP_State)
    {
        Rte_Read_rpSR_SocManager_SystemState(&RTE_SocManagerSystemState);
        if((SYSTEMSTATE_TIMEOUT == SystemState_SOCOFFTimerSts) || (eSOC_MANAGER_STATE_CLOSE == RTE_SocManagerSystemState))
        {
            if(SYSTEMSTATE_TIMEOUT == SystemState_SOCOFFTimerSts)
            {
                //power_info("socmanager not give response, timeout 1s");
            }
            if(eSOC_MANAGER_STATE_CLOSE == RTE_SocManagerSystemState)
            {
                //power_info("power receive socmanager response");
            }
            SystemState_SOCOFFTimer = 0u;
            ret = 0x0u;
        }
        else
        {
            ret = 0x1u;
        }
    }
    else
    {
        ret = 0x1u;
    }
    POWER_TEST_LOG(SOCSts);
    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   0x0:    Environment Normal
                    0x1:    Environment Sleep
 ***********************************************************************/
static uint8 SM_ConditionSP_StateEnvironment(void)
{
    uint8 ret = 0u;
    uint8 Power_TempetureFlg = Power_TempStateTempFlg();
	SP_Enter_Shutdown_Reason = SM_SP_TemporVol_Sleep_Clear;
    if ((VOLTAGE_OUT_LOWSLEEP == Power_OutDataCurrent.state) ||
        (VOLTAGE_OUT_HIGHSLEEP == Power_OutDataCurrent.state)||
        (POWER_TEMP_ABNORMAL == Power_TempetureFlg))
    {
    	SP_Enter_Shutdown_Reason = SM_SP_TemporVol_Sleep;
        ret = 1u;
    }
    return ret;
}


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"


