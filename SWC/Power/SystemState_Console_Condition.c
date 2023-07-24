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
 * @file:      SystemState_Console_Condition.c
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

#include "SystemState_Console_Condition.h"
#include "SystemState_Conditon_Element.h"

#include "Logger_Cfg.h"
#include "logger.h"
#include "string.h"


#define SM_CONSOLE_STATE_MACHINE_NUMBER                         (1u)
#define SM_CONSOLE_STATE_NUMBER                                 (3u)
#define SM_CONSOLE_TRANSFER_CONDITION_NUMBER                    (3u)
#define SM_CONSOLE_TRANSFER_ELEMENT_NUMBER                      (6u)
#define SM_CONSOLE_TRANSFER_ACTION_NUMBER                       (18u)
#define SM_CONSOLE_FEATURE_CONFIG_VALUE_NUMBER                  (6u)
#define SM_CONSOLE_FEATURE_VALUE_NUMBER                         (1u)
#define SM_CONSOLE_ENTRY_NUMBER                                 SM_CONSOLE_STATE_MACHINE_NUMBER
#define SM_CONSOLE_TRANSFER_NUMBER                              SM_CONSOLE_STATE_MACHINE_NUMBER
#define SM_CONSOLE_STAY_NUMBER                                  SM_CONSOLE_STATE_MACHINE_NUMBER


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void SM_EntryCallbackConsole(void);
static void SM_TransferCallbackConsole(SM_StateType previous, SM_StateType next);
static void SM_StayCallbackConsole(SM_StateType state);

static uint8 SM_ConditionConsole_Voltage_Sts(void);
static uint8 SM_ConditionConsole_Enter_Other(void);
static uint8 SM_ConditionConsole_NM_State(void);


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"



#define POWER_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
static uint8 ConsolefeatureValues[SM_CONSOLE_FEATURE_VALUE_NUMBER];
static SM_StateMachineType ConsolestateMachineDatas[SM_CONSOLE_STATE_MACHINE_NUMBER];
static SystemState_Console_PA_t SystemState_Console_PA;



static SM_Type Sm_Console;


#define POWER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"

static const SystemState_Console_PA_t Console_PAInit = {SYSTEMSTATE_CONSOLE_OFF};

static const SM_Type Sm_ConsoleInit = {SM_STATEMACHINE_INVALID, SM_SEQUENCE_IDLE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, NULL_PTR};

static const uint8 ConsolefeatureConfigValues[SM_CONSOLE_FEATURE_CONFIG_VALUE_NUMBER] =
{
    0x7F, 
    0xD7, 
    0xB7, 
    0xCE, 
    0xCD, 
    0xAF, 
};

static const SM_StateType Consoletargets[SM_CONSOLE_TRANSFER_ACTION_NUMBER] =
{
    0, 0, 1, 
    0, 0, 1, 
    0, 0, 1, 
    1, 2, 2, 
    1, 1, 1, 
    1, 1, 1, 
};

static const SM_TransferElementConfigType ConsoletransferElementConfigs[SM_CONSOLE_TRANSFER_ELEMENT_NUMBER] =
{
    {0, 1, 0, 3},/*0*/
    {1, 2, 3, 6},/*1*/
    {2, 3, 6, 9},/*2*/
    {3, 4, 9, 12},/*3*/
    {4, 5, 12, 15},/*4*/
    {5, 6, 15, 18},/*5*/
};

static const SM_TransferConditionConfigType ConsoletransferConditionConfigs[SM_CONSOLE_TRANSFER_CONDITION_NUMBER] =
{
    {0, 0, 3},
    {1, 3, 5},
    {2, 5, 8},
};

static const SM_StateConfigType ConsolestateConfigs[SM_CONSOLE_STATE_NUMBER] =
{
    {"CONSOLE Console_OFF", 0xFF},
    {"CONSOLE Console_STANDBY", 0xFF},
    {"CONSOLE Console_ON", 0xFF},
};

static const SM_StateMachineConfigType ConsolestateMachineConfigs[SM_CONSOLE_STATE_MACHINE_NUMBER] =
{
    {(boolean)TRUE, 0, 3, 0, 3, 0, 6, 0, 1, 0, 0, 0},
};


static const SM_TransferConditionType ConsoletransferConditions[SM_CONSOLE_TRANSFER_CONDITION_NUMBER] =
{
    SM_ConditionConsole_Enter_Other,
    SM_ConditionConsole_NM_State,
    SM_ConditionConsole_Voltage_Sts,
};

static const SM_EntryCallbackType Consoleentrys[SM_CONSOLE_ENTRY_NUMBER] =
{
    SM_EntryCallbackConsole,
};

static const SM_TransferCallbackType Consoletransfers[SM_CONSOLE_TRANSFER_NUMBER] =
{
    SM_TransferCallbackConsole,
};

static const SM_StayCallbackType Consolestays[SM_CONSOLE_STAY_NUMBER] =
{
    SM_StayCallbackConsole,
};

static const SM_ConfigType sm_Console_config =
{
    SM_CONSOLE_STATE_MACHINE_NUMBER,
    ConsolestateMachineConfigs,
    ConsolestateMachineDatas,
    SM_CONSOLE_TRANSFER_ELEMENT_NUMBER,
    ConsoletransferElementConfigs,
    SM_CONSOLE_TRANSFER_CONDITION_NUMBER,
    ConsoletransferConditionConfigs,
    SM_CONSOLE_TRANSFER_ACTION_NUMBER,
    Consoletargets,
    SM_CONSOLE_FEATURE_CONFIG_VALUE_NUMBER,
    ConsolefeatureConfigValues,
    SM_CONSOLE_FEATURE_VALUE_NUMBER,
    ConsolefeatureValues,
    SM_CONSOLE_STATE_NUMBER,
    ConsolestateConfigs,
    SM_CONSOLE_TRANSFER_CONDITION_NUMBER,
    ConsoletransferConditions,
    SM_CONSOLE_ENTRY_NUMBER,
    Consoleentrys,
    SM_CONSOLE_TRANSFER_NUMBER,
    Consoletransfers,
    SM_CONSOLE_STAY_NUMBER,
    Consolestays
};
#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void SM_EntryCallbackConsole(void)
{
    SM_StateCurrentSet(&Sm_Console,SYSTEMSTATE_CONSOLE_OFF);
    //power_info("State machine Console entry SYSTEMSTATE_SM_STATE_CONSOLE_OFF!!");
    SystemState_Console_PA.State = SYSTEMSTATE_CONSOLE_OFF;
}

static void SM_TransferCallbackConsole(SM_StateType previous, SM_StateType next)
{
    const char *previousName;
    const char *nextName;

    (void)SM_StateNameGet(&Sm_Console,previous,&previousName);
    (void)SM_StateNameGet(&Sm_Console,next,&nextName);

    //power_info("State machine Console state %s --> state %s", previousName,nextName);
    //power_info("Console transfer reason ID is %d \r\n",ConsolestateMachineDatas[0].transferElement);
    SystemState_Console_PA.State = next;
}

static void SM_StayCallbackConsole(SM_StateType state)
{
    if(LOGTIMERTIMEOUT == PowerLogStsFunc(TIMER10S))
    {
        const char *StateName;
        (void)SM_StateNameGet(&Sm_Console,state,&StateName);
        power_verbose("State machine Console stay in state %s\r\n",StateName);
    }

}






/*
    0: Enter_ON	
    1: Enter_Standby
    2: Keep_Previous
*/
static uint8 SM_ConditionConsole_Enter_Other(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    if ((SYSTEMSTATE_KL15_ON == Systemstate_Condition_element_local.KL15) &&\
        (SYSTEMSTATE_TRANP_MODE_OFF == Systemstate_Condition_element_local.TransPMode))
    {
        return 0;
    }
    else if ((SYSTEMSTATE_TRANP_MODE_ON == Systemstate_Condition_element_local.TransPMode) ||\
        (SYSTEMSTATE_KL15_OFF == Systemstate_Condition_element_local.KL15))
    {
        return 1;
    }
    else 
    {
        return 2;
    }
}


/*
0: No_Communication
1: Full_Communication
*/
static uint8 SM_ConditionConsole_NM_State(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    if ((SYSTEMSTATE_NMFULLCOMMUNICATION == Systemstate_Condition_element_local.NMState) &&\
        (SYSTEMSTATE_IPCREADY == Systemstate_Condition_element_local.IPCSts))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


static uint8 SM_ConditionConsole_Voltage_Sts(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    return Systemstate_Condition_element_local.Voltage_State;
}

void SystemState_ConsoleInit(void)
{
    memset(ConsolefeatureValues,0,SM_CONSOLE_FEATURE_VALUE_NUMBER);
    memset(ConsolestateMachineDatas,0,sizeof(SM_StateMachineType));
    SystemState_Console_PA = Console_PAInit;
    Sm_Console = Sm_ConsoleInit;
    SM_Init(&Sm_Console,&sm_Console_config);
}

SystemState_Console_PA_t SystemState_ConsoleSts(void)
{
    return SystemState_Console_PA;
}

void SystemState_Console_MainFunc(void)
{
    SM_MainFunction(&Sm_Console);


}

void SystemState_ConsoleEnableSet(boolean Enabled)
{
    SM_EnabledSet(&Sm_Console, Enabled);
}

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"





