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
 * @file:      SystemState_HUD_Condition.c
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

#include "SystemState_HUD_Condition.h"
#include "Logger_Cfg.h"
#include "logger.h"
#include "StateMachine.h"
#include "string.h"
#include "SystemState_Conditon_Element.h"


#define SM_HUD_STATE_MACHINE_NUMBER                     (1u)
#define SM_HUD_STATE_NUMBER                             (3u)
#define SM_HUD_TRANSFER_CONDITION_NUMBER                (3u)
#define SM_HUD_TRANSFER_ELEMENT_NUMBER                  (6u)
#define SM_HUD_TRANSFER_ACTION_NUMBER                   (18u)
#define SM_HUD_FEATURE_CONFIG_VALUE_NUMBER              (6u)
#define SM_HUD_FEATURE_VALUE_NUMBER                     (1u)
#define SM_HUD_ENTRY_NUMBER                             SM_HUD_STATE_MACHINE_NUMBER
#define SM_HUD_TRANSFER_NUMBER                          SM_HUD_STATE_MACHINE_NUMBER
#define SM_HUD_STAY_NUMBER                              SM_HUD_STATE_MACHINE_NUMBER
#define SYSTEMSTATE_HUDIPCSENDGAP                       (200u)

#define POWER_START_SEC_CODE 
#include "Power_MemMap.h"


static void SM_EntryCallbackHUD(void);
static void SM_TransferCallbackHUD(SM_StateType previous, SM_StateType next);
static void SM_StayCallbackHUD(SM_StateType state);
static uint8 SM_ConditionHUD_Voltage_Sts(void);
static uint8 SM_ConditionHUD_Enter_Other(void);
static uint8 SM_ConditionHUD_NMState(void);


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"



#define POWER_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" 

static uint8 HUDfeatureValues[SM_HUD_FEATURE_VALUE_NUMBER];
static SM_StateMachineType HUDstateMachineDatas[SM_HUD_STATE_MACHINE_NUMBER];
static SystemState_HUD_PA_t SystemState_HUD_PA;
static SM_Type Sm_HUD;


#define POWER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */






#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"

static const SystemState_HUD_PA_t HUD_PA_Init = {SYSTEMSTATE_SP_OFF};

static const SM_Type Sm_HUDInit = {SM_STATEMACHINE_INVALID, SM_SEQUENCE_IDLE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, NULL_PTR};

static const uint8 HUDfeatureConfigValues[SM_HUD_FEATURE_CONFIG_VALUE_NUMBER] =
{
    0xDF, 
    0x77, 
    0x6F, 
    0xB5, 
    0xB6, 
    0xAF, 
};

static const SM_StateType HUDtargets[SM_HUD_TRANSFER_ACTION_NUMBER] =
{
    0, 0, 1, 
    0, 0, 1, 
    0, 0, 1, 
    1, 2, 2, 
    1, 1, 1, 
    1, 1, 1, 
};

static const SM_TransferElementConfigType HUDtransferElementConfigs[SM_HUD_TRANSFER_ELEMENT_NUMBER] =
{
    {0, 1, 0, 3},/*0*/
    {1, 2, 3, 6},/*1*/
    {2, 3, 6, 9},/*2*/
    {3, 4, 9, 12},/*3*/
    {4, 5, 12, 15},/*4*/
    {5, 6, 15, 18},/*5*/
};

static const SM_TransferConditionConfigType HUDtransferConditionConfigs[SM_HUD_TRANSFER_CONDITION_NUMBER] =
{
    {0, 0, 3},
    {1, 3, 6},
    {2, 6, 8},
};

static const SM_StateConfigType HUDstateConfigs[SM_HUD_STATE_NUMBER] =
{
    {"HUD HUD_OFF", 0xFF},
    {"HUD HUD_STANDBY", 0xFF},
    {"HUD HUD_ON", 0xFF},
};

static const SM_StateMachineConfigType HUDstateMachineConfigs[SM_HUD_STATE_MACHINE_NUMBER] =
{
    {(boolean)TRUE, 0, 3, 0, 3, 0, 6, 0, 1, 0, 0, 0},
};


static const SM_TransferConditionType HUDtransferConditions[SM_HUD_TRANSFER_CONDITION_NUMBER] =
{
    SM_ConditionHUD_Enter_Other,
    SM_ConditionHUD_Voltage_Sts,
    SM_ConditionHUD_NMState,
};

static const SM_EntryCallbackType HUDentrys[SM_HUD_ENTRY_NUMBER] =
{
    SM_EntryCallbackHUD,
};

static const SM_TransferCallbackType HUDtransfers[SM_HUD_TRANSFER_NUMBER] =
{
    SM_TransferCallbackHUD,
};

static const SM_StayCallbackType HUDstays[SM_HUD_STAY_NUMBER] =
{
    SM_StayCallbackHUD,
};

static const SM_ConfigType sm_HUD_config =
{
    SM_HUD_STATE_MACHINE_NUMBER,
    HUDstateMachineConfigs,
    HUDstateMachineDatas,
    SM_HUD_TRANSFER_ELEMENT_NUMBER,
    HUDtransferElementConfigs,
    SM_HUD_TRANSFER_CONDITION_NUMBER,
    HUDtransferConditionConfigs,
    SM_HUD_TRANSFER_ACTION_NUMBER,
    HUDtargets,
    SM_HUD_FEATURE_CONFIG_VALUE_NUMBER,
    HUDfeatureConfigValues,
    SM_HUD_FEATURE_VALUE_NUMBER,
    HUDfeatureValues,
    SM_HUD_STATE_NUMBER,
    HUDstateConfigs,
    SM_HUD_TRANSFER_CONDITION_NUMBER,
    HUDtransferConditions,
    SM_HUD_ENTRY_NUMBER,
    HUDentrys,
    SM_HUD_TRANSFER_NUMBER,
    HUDtransfers,
    SM_HUD_STAY_NUMBER,
    HUDstays
};

#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"





#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void SM_EntryCallbackHUD(void)
{
    SM_StateCurrentSet(&Sm_HUD,SYSTEMSTATE_HUD_OFF);
    //power_info("State machine HUD entry SYSTEMSTATE_SM_STATE_HUD_OFF!!\r\n");
    SystemState_HUD_PA.State = SYSTEMSTATE_HUD_OFF;
}


static void SM_TransferCallbackHUD(SM_StateType previous, SM_StateType next)
{
    const char *previousName;
    const char *nextName;

    (void)SM_StateNameGet(&Sm_HUD,previous,&previousName);
    (void)SM_StateNameGet(&Sm_HUD,next,&nextName);

    //power_info("State machine HUD state %s --> state %s", previousName,nextName);
    //power_info("HUD transfer reason ID is %d\r\n",HUDstateMachineDatas[0].transferElement);
    SystemState_HUD_PA.State = next;
}


static void SM_StayCallbackHUD(SM_StateType state)
{
    if(LOGTIMERTIMEOUT == PowerLogStsFunc(TIMER2S))
    {
        const char *StateName;
        (void)SM_StateNameGet(&Sm_HUD,state,&StateName);
        power_verbose("State machine HUD stay in state %s\r\n",StateName);
    }
}

/*
    0: enter standby
    1: enter on
    2: keep
*/
static uint8 SM_ConditionHUD_Enter_Other(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();

    if((SYSTEMSTATE_KL15_ON == Systemstate_Condition_element_local.KL15) &&\
        (SYSTEMSTATE_TRANP_MODE_OFF == Systemstate_Condition_element_local.TransPMode)&&
        (SYSTEMSTATE_HUD_OPEN == Systemstate_Condition_element_local.HUD_State))
    {
        return 1;/*enter on*/
    }
    else if((SYSTEMSTATE_TRANP_MODE_ON == Systemstate_Condition_element_local.TransPMode)||\
        (SYSTEMSTATE_KL15_OFF == Systemstate_Condition_element_local.KL15)||\
        (SYSTEMSTATE_HUD_CLOSE == Systemstate_Condition_element_local.HUD_State))
    {
        return 0;/* enter standby */
    }
    else
    {
        return 2;/* no change */
    }
}



static uint8 SM_ConditionHUD_Voltage_Sts(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    return Systemstate_Condition_element_local.Voltage_State;
}


static uint8 SM_ConditionHUD_NMState(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    if((SYSTEMSTATE_NMFULLCOMMUNICATION == Systemstate_Condition_element_local.NMState) &&\
        (SYSTEMSTATE_IPCREADY == Systemstate_Condition_element_local.IPCSts))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void SystemState_HUDInit(void)
{
    memset(HUDfeatureValues,0,sizeof(HUDfeatureValues));
    memset(HUDstateMachineDatas,0,sizeof(HUDstateMachineDatas));
    SystemState_HUD_PA = HUD_PA_Init;
    Sm_HUD = Sm_HUDInit;
    SM_Init(&Sm_HUD,&sm_HUD_config);
}


SystemState_HUD_PA_t SystemState_HUDSts(void)
{
    return SystemState_HUD_PA;
}

void SystemState_HUD_MainFunc(void)
{
    SM_MainFunction(&Sm_HUD);
}

void SystemState_HUDEnableSet(boolean Enabled)
{
    SM_EnabledSet(&Sm_HUD, Enabled);
}


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"


