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
 * @file:      SystemState_Cluster_Condition.c
 * @author:    Nobo
 * @date:      2020-7-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-7-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "SystemState_Cluster_Condition.h"
#include "power.h"
#include "SystemState_Conditon_Element.h"
#include "Logger_Cfg.h"
#include "logger.h"

#define SM_DEV_ERROR_DETECT                             (STD_ON)

#define SM_STATEMACHINE_INVALID                         (0xFFu)
#define SM_STATE_ORIGIN                                 (0xFFu)

#define SM_Cluster_STATE_MACHINE_NUMBER                 (1u)
#define SM_Cluster_STATE_NUMBER                         (5u)
#define SM_Cluster_TRANSFER_CONDITION_NUMBER            (4u)
#define SM_Cluster_TRANSFER_ELEMENT_NUMBER              (8u)
#define SM_Cluster_TRANSFER_ACTION_NUMBER               (40u)

#define SM_Cluster_FEATURE_CONFIG_VALUE_NUMBER          (8u)
#define SM_Cluster_FEATURE_VALUE_NUMBER                 (1u)

#define SM_Cluster_ENTRY_NUMBER                         SM_Cluster_STATE_MACHINE_NUMBER
#define SM_Cluster_TRANSFER_NUMBER                      SM_Cluster_STATE_MACHINE_NUMBER
#define SM_Cluster_STAY_NUMBER                          SM_Cluster_STATE_MACHINE_NUMBER

#define SM_CLUSTER_SHUTDOWN_TIMEOUT                     (3000)/*3s*/

#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void SM_EntryCallbackCluster(void);
static void SM_TransferCallbackCluster(SM_StateType previous, SM_StateType next);
static void SM_StayCallbackCluster(SM_StateType state);

static uint8 SM_ConditionClusterNM_Status(void);
static uint8 SM_ConditionClusterVoltage_State(void);
static uint8 SM_ConditionClusterKL15(void);
static uint8 SM_ConditionClusterCluster_Response(void);
static void Power_Cluster_OfftoStandby(void);
static void Power_Cluster_ShutDowntoOFF(void);
static void Power_Cluster_ONtoStandby(void);
static void Power_Cluster_StandbytoON(void);
static void Power_Cluster_ReceiveClusterShutDownResponse(void);

extern FUNC(void, TM_CODE) TM_TimerElapsed(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp, P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) TimeElapsed);
extern FUNC(void, TM_CODE) TM_TimerStartStamp(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"



#define POWER_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" 


static SM_StateMachineType ClusterstateMachineDatas[SM_Cluster_STATE_MACHINE_NUMBER];
static SystemState_Cluster_PA_t SystemState_Cluster_PA;
static SM_Type Sm_Cluster;
static uint8 ClusterfeatureValues[SM_Cluster_FEATURE_VALUE_NUMBER];
static uint32 Cluster_TMStart;
static uint32 Cluster_TMEnd;
static boolean CLusterShutDownResponse;
static boolean Systemstate_ClusterStartupDone;
static uint32 TMTestStart;
static uint32 TMTestEnd;
static uint32 ClusterShutDownStart;
static uint32 ClusterShutDownEnd;
static boolean ClusterShutDownTimeout;
static uint32 TimerFlg;


#define POWER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" 


#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"

static const SM_Type Sm_ClusterInit = {SM_STATEMACHINE_INVALID, SM_SEQUENCE_IDLE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, NULL_PTR};

static const uint8 ClusterfeatureConfigValues[SM_Cluster_FEATURE_CONFIG_VALUE_NUMBER] =
{
    0x76, 
    0xB6, 
    0xBD, 
    0x7D, 
    0x5A, 
    0x9A, 
    0x6A, 
    0xAA, 
};

static const SM_StateType Clustertargets[SM_Cluster_TRANSFER_ACTION_NUMBER] =
{
    0, 4, 4, 3, 4, 
    0, 4, 4, 4, 0, 
    0, 4, 1, 1, 0, 
    0, 4, 1, 3, 4, 
    3, 2, 2, 3, 4, 
    3, 2, 2, 1, 0, 
    3, 1, 1, 3, 4, 
    3, 1, 1, 1, 0, 
};

static const SM_TransferElementConfigType ClustertransferElementConfigs[SM_Cluster_TRANSFER_ELEMENT_NUMBER] =
{
    {0, 1, 0, 5},/*0*/
    {1, 2, 5, 10},/*1*/
    {2, 3, 10, 15},/*2*/
    {3, 4, 15, 20},/*3*/
    {4, 5, 20, 25},/*4*/
    {5, 6, 25, 30},/*5*/
    {6, 7, 30, 35},/*6*/
    {7, 8, 35, 40},/*7*/
};

static const SM_TransferConditionConfigType ClustertransferConditionConfigs[SM_Cluster_TRANSFER_CONDITION_NUMBER] =
{
    {0, 0, 2},
    {1, 2, 4},
    {2, 4, 6},
    {3, 6, 8},
};

static const SM_StateConfigType ClusterstateConfigs[SM_Cluster_STATE_NUMBER] =
{
    {"Cluster_OFF", 0xFF},
    {"Cluster_STANDBY", 0xFF},
    {"Cluster_ON", 0xFF},
    {"Cluster_StartUp", 0xFF},
    {"Cluster_ShutDown", 0xFF},
};

static const SM_StateMachineConfigType ClusterstateMachineConfigs[SM_Cluster_STATE_MACHINE_NUMBER] =
{
    {(boolean)TRUE, 0, 5, 0, 4, 0, 8, 0, 1, 0, 0, 0},
};


static const SM_TransferConditionType ClustertransferConditions[SM_Cluster_TRANSFER_CONDITION_NUMBER] =
{
    SM_ConditionClusterNM_Status, 
    SM_ConditionClusterVoltage_State, 
    SM_ConditionClusterKL15, 
    SM_ConditionClusterCluster_Response, 
};


static const SM_EntryCallbackType Clusterentrys[SM_Cluster_ENTRY_NUMBER] =
{
    SM_EntryCallbackCluster, 
};


static const SM_TransferCallbackType Clustertransfers[SM_Cluster_TRANSFER_NUMBER] =
{
    SM_TransferCallbackCluster, 
};


static const SM_StayCallbackType Clusterstays[SM_Cluster_STAY_NUMBER] =
{
    SM_StayCallbackCluster, 
};



static const SM_ConfigType sm_Cluster_config =
{
    SM_Cluster_STATE_MACHINE_NUMBER,
    ClusterstateMachineConfigs,
    ClusterstateMachineDatas,
    SM_Cluster_TRANSFER_ELEMENT_NUMBER,
    ClustertransferElementConfigs,
    SM_Cluster_TRANSFER_CONDITION_NUMBER,
    ClustertransferConditionConfigs,
    SM_Cluster_TRANSFER_ACTION_NUMBER,
    Clustertargets,
    SM_Cluster_FEATURE_CONFIG_VALUE_NUMBER,
    ClusterfeatureConfigValues,
    SM_Cluster_FEATURE_VALUE_NUMBER,
    ClusterfeatureValues,
    SM_Cluster_STATE_NUMBER,
    ClusterstateConfigs,
    SM_Cluster_TRANSFER_CONDITION_NUMBER,
    ClustertransferConditions,
    SM_Cluster_ENTRY_NUMBER,
    Clusterentrys,
    SM_Cluster_TRANSFER_NUMBER,
    Clustertransfers,
    SM_Cluster_STAY_NUMBER,
    Clusterstays
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
static void SM_EntryCallbackCluster(void)
{
    SM_StateCurrentSet(&Sm_Cluster, SYSTEMSTATE_Cluster_OFF);
    //power_warn("State machine Cluster entry SYSTEMSTATE_SM_STATE_CLUSTER_OFF!!\r\n");
    SystemState_Cluster_PA = SYSTEMSTATE_Cluster_OFF;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_TransferCallbackCluster(SM_StateType previous, SM_StateType next)
{
    const char *previousName;
    const char *nextName;

    SystemState_Cluster_PA = next;

    if ((SYSTEMSTATE_Cluster_OFF == previous) && (SYSTEMSTATE_Cluster_STARTUP == next))
    {
        Power_Cluster_OfftoStandby();
    }
    else if ((SYSTEMSTATE_Cluster_SHUTDOWN == previous) && (SYSTEMSTATE_Cluster_OFF == next))
    {
        Power_Cluster_ShutDowntoOFF();
    }

    if(SYSTEMSTATE_Cluster_SHUTDOWN == next)
    {
        POWER_GET_OSTiCK(&Cluster_TMStart);
        POWER_GET_OSTiCK(&ClusterShutDownStart);
    }
    

    if ((SYSTEMSTATE_Cluster_ON == previous) && (SYSTEMSTATE_Cluster_STANDBY == next))
    {
        Power_Cluster_ONtoStandby();
    }
    else if ((SYSTEMSTATE_Cluster_STANDBY == previous) && (SYSTEMSTATE_Cluster_ON == next))
    {
        Power_Cluster_StandbytoON();
    }

    
    (void)SM_StateNameGet(&Sm_Cluster, previous, &previousName);
    (void)SM_StateNameGet(&Sm_Cluster, next, &nextName);
    
    POWER_GET_OSTiCK(&TimerFlg);
    power_warn("[%ld Ms]SM %s->%s", TimerFlg, previousName, nextName);
    power_warn("Cluster trans reasonID:%d \r\n",ClusterstateMachineDatas[0].transferElement);
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_StayCallbackCluster(SM_StateType state)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();

    if(SYSTEMSTATE_Cluster_SHUTDOWN == state)
    {
        POWER_GET_OSTiCK(&Cluster_TMEnd);
        if((Cluster_TMEnd - Cluster_TMStart) >= SM_CLUSTER_SHUTDOWN_TIMEOUT)
        {
            ClusterShutDownTimeout = TRUE;
        }
        
		if(SYSTEMSTATE_NMFULLCOMMUNICATION == Systemstate_Condition_element_local.NMState)
		{
			ClusterShutDownTimeout = TRUE;/*nm come, clear shutdowntimeout*/
		}        
    }
    else
    {
        Cluster_TMStart = 0u;
        Cluster_TMEnd = 0u;
    }
    
    if(SYSTEMSTATE_Cluster_STARTUP != state)
    {
        Systemstate_ClusterStartupDone = FALSE;
    }

    SystemState_Cluster_PA = state;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :   0: Full_Communication
                    1: No_Communication 
 ***********************************************************************/
static uint8 SM_ConditionClusterNM_Status(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    if (SYSTEMSTATE_NMFULLCOMMUNICATION == Systemstate_Condition_element_local.NMState)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :       0: Receive Response
                        1: No Receive Response
 ***********************************************************************/
static uint8 SM_ConditionClusterCluster_Response(void)
{
    Power_Cluster_ReceiveClusterShutDownResponse();
    if ((TRUE == Systemstate_ClusterStartupDone) || (TRUE == ClusterShutDownTimeout) || (TRUE == CLusterShutDownResponse))
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 SM_ConditionClusterKL15(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    return Systemstate_Condition_element_local.KL15;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                 0x0: Vol_Normal
                 0x1: Vol_Sleep
 ***********************************************************************/
static uint8 SM_ConditionClusterVoltage_State(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    if((SYSTEMSTATE_VOLNORMAL == Systemstate_Condition_element_local.Voltage_State) ||\
        (SYSTEMSTATE_VOLALARM == Systemstate_Condition_element_local.Voltage_State))
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_Cluster_Init(void)
{
    memset(ClusterfeatureValues,0,SM_Cluster_FEATURE_VALUE_NUMBER);
    memset(ClusterstateMachineDatas,0,sizeof(ClusterstateMachineDatas));
    Sm_Cluster = Sm_ClusterInit;
    Cluster_TMStart = 0u;
    Cluster_TMEnd = 0u;
    CLusterShutDownResponse = FALSE;
    Systemstate_ClusterStartupDone = FALSE;
    TMTestStart = 0u;
    TMTestEnd   = 0u;
    ClusterShutDownStart = 0u;
    ClusterShutDownEnd = 0u;
    ClusterShutDownTimeout = FALSE;
    SM_Init(&Sm_Cluster,&sm_Cluster_config);
}





/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
SystemState_Cluster_PA_t SystemState_ClusterSts(void)
{
    return SystemState_Cluster_PA;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_Cluster_MainFunc(void)
{
    SM_MainFunction(&Sm_Cluster);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_ClusterEnableSet(boolean Enabled)
{
    SM_EnabledSet(&Sm_Cluster, Enabled);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_Cluster_OfftoStandby(void)
{
    TM_TimerStartStamp(&TMTestStart);
    SystemState_ClusterInitFunc();
    TM_TimerElapsed(&TMTestStart,&TMTestEnd);
    //power_info("Systemstate Cluster init function called, Exe time is %.4f ms",(float)TMTestEnd / 10000);
    if(TMTestEnd > 2000)
    {
        power_warn("Cluster initfunc toolong:%.4fms",(float)(TMTestEnd)/10000);
    }
    Systemstate_ClusterStartupDone = TRUE;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_Cluster_ShutDowntoOFF(void)
{
    
    TM_TimerStartStamp(&TMTestStart);
    SystemState_ClusterDeInitFunc();
    TM_TimerElapsed(&TMTestStart,&TMTestEnd);
    
//    power_info("Systemstate Cluster Deinit function called, Exe time is %.4f ms",(float)TMTestEnd / 10000);
    if(TMTestEnd > 2000)
    {
        power_warn("Cluster Deinit toolong:%.4fms",(float)(TMTestEnd)/10000);
    }
    if(TRUE == ClusterShutDownTimeout)
    {
//        power_warn("Cluster ShutDowm request more than %d ms, So Force Enter OFF",SM_CLUSTER_SHUTDOWN_TIMEOUT);
    }

    TMTestStart = 0u;
    TMTestEnd = 0u;

    if(TRUE == CLusterShutDownResponse)
    {
        power_warn("PM got ShutDown resp,shutdown");
    }

    POWER_GET_OSTiCK(&ClusterShutDownEnd);
    power_warn("CLuster ShutDown usetime: %dms NoNM->Cluster OFF",ClusterShutDownEnd - ClusterShutDownStart);
    ClusterShutDownTimeout = (boolean)0;
    ClusterShutDownStart = 0u;
    ClusterShutDownEnd = 0u;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_Cluster_ONtoStandby(void)
{
    TM_TimerStartStamp(&TMTestStart);
    SysTemState_ClusterNormal2Standby();
    TM_TimerElapsed(&TMTestStart,&TMTestEnd);
    if(TMTestEnd > 2000)/*0.2ms*/
    {
        power_warn("Cluster on->standby func toolong:%.4fms",(float)(TMTestEnd)/10000);
    }
    else
    {
        power_info("Cluster on->standby func time:%.4fms",(float)TMTestEnd / 10000);
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_Cluster_StandbytoON(void)
{
    TM_TimerStartStamp(&TMTestStart);
    SysTemState_ClusterStandby2Normal();
    TM_TimerElapsed(&TMTestStart,&TMTestEnd);
    if(TMTestEnd > 2000)
    {
        //power_warn("Cluster standby->on func toolong:%.1fms",(float)(TMTestEnd)/10000);
    }
    else
    {
        //power_info("Cluster Standby->On func time:%.1fms",(float)TMTestEnd / 10000);
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_Cluster_ReceiveClusterShutDownResponse(void)
{
    /*wait cluster team provide rte write interface */
    CLusterShutDownResponse = FALSE;
}



#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"

