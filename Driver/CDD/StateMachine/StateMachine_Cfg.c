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
 * @file:      StateMachine_Cfg.c
 * @author:    Nobo
 * @date:      2020-6-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %header file%
 */
#include "StateMachine.h"


/*
 *  %typedef/macro defintion%
 */



/*
 *  %forward declaration%
 */
static void SM_EntryCallbackVoltage(void);
static void SM_EntryCallbackHighM(void);
static void SM_EntryCallbackLowM(void);
static void SM_TransferCallbackVoltage(SM_StateType previous, SM_StateType next);
static void SM_TransferCallbackHighM(SM_StateType previous, SM_StateType next);
static void SM_TransferCallbackLowM(SM_StateType previous, SM_StateType next);
static void SM_StayCallbackVoltage(SM_StateType state);
static void SM_StayCallbackHighM(SM_StateType state);
static void SM_StayCallbackLowM(SM_StateType state);
static uint8 SM_ConditionVoltageT3(void);
static uint8 SM_ConditionVoltageT5(void);
static uint8 SM_ConditionHighMT3(void);
static uint8 SM_ConditionHighMT4(void);
static uint8 SM_ConditionHighMT6(void);
static uint8 SM_ConditionLowMT5(void);
static uint8 SM_ConditionLowMT7(void);


/*
 *  %global definition%
 */
//extern uint8 timerT3;
//extern uint8 timerT4;
//extern uint8 timerT5;
//extern uint8 timerT6;
//extern uint8 timerT7;

#define SM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "StateMachine_MemMap.h"

static uint8 featureValues[SM_FEATURE_VALUE_NUMBER] = {0};

#define SM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "StateMachine_MemMap.h"

#define SM_START_SEC_CONST_UNSPECIFIED
#include "StateMachine_MemMap.h"

static const uint8 featureConfigValues[SM_FEATURE_CONFIG_VALUE_NUMBER] =
{
    0xFA,
    0xFD,
    0xF6,
    0x7F,
    0x9F,
    0xAB,
    0xB3,
    0xAD,
    0xAE,
    0xB5,
    0xB6,
    0xF7,
    0xF9,
    0xFA,
};

static const SM_StateType targets[SM_TRANSFER_ACTION_NUMBER] =
{
    0, 0, 0,
    1, 1, 1,
    2, 2, 2,
    5, 5, 5,
    5, 5, 5,
    5, 5, 5,
    5, 5, 5,
    4, 4, 4,
    4, 4, 4,
    4, 4, 4,
    3, 3, 3,
    7, 7,
    7, 7,
    6, 6,
};

static const SM_TransferElementConfigType transferElementConfigs[SM_TRANSFER_ELEMENT_NUMBER] =
{
    {0, 1, 0, 3},
    {1, 2, 3, 6},
    {2, 3, 6, 9},
    {3, 4, 9, 12},
    {4, 5, 12, 15},
    {5, 6, 15, 18},
    {6, 7, 18, 21},
    {7, 8, 21, 24},
    {8, 9, 24, 27},
    {9, 10, 27, 30},
    {10, 11, 30, 33},
    {11, 12, 33, 35},
    {12, 13, 35, 37},
    {13, 14, 37, 39},
};

static const SM_TransferConditionConfigType transferConditionConfigs[SM_TRANSFER_CONDITION_NUMBER] =
{
    {0, 0, 2},
    {1, 2, 4},
    {2, 0, 3},
    {3, 3, 6},
    {4, 6, 8},
    {5, 0, 2},
    {6, 2, 4},
};

static const SM_StateConfigType stateConfigs[SM_STATE_NUMBER] =
{
    {"VOLTAGE Normal", 0xFF},
    {"VOLTAGE High", 0x01},
    {"VOLTAGE Low", 0x02},
    {"HIGHM High Normal", 0xFF},
    {"HIGHM High Alarm", 0xFF},
    {"HIGHM High Sleep", 0xFF},
    {"LOWM Low Normal", 0xFF},
    {"LOWM Low Sleep", 0xFF},
};

static const SM_StateMachineConfigType stateMachineConfigs[SM_STATE_MACHINE_NUMBER] =
{
    {TRUE, 0, 3, 0, 2, 0, 3, 0, 1, 0, 0, 0},
    {FALSE, 3, 6, 2, 5, 3, 11, 1, 2, 1, 1, 1},
    {FALSE, 6, 8, 5, 7, 11, 14, 2, 3, 2, 2, 2},
};
#define SM_STOP_SEC_CONST_UNSPECIFIED
#include "StateMachine_MemMap.h"

#define SM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "StateMachine_MemMap.h"

static SM_StateMachineType stateMachineDatas[SM_STATE_MACHINE_NUMBER] = {0};

#define SM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "StateMachine_MemMap.h"

#define SM_START_SEC_CONST_UNSPECIFIED
#include "StateMachine_MemMap.h"
static const SM_TransferConditionType transferConditions[SM_TRANSFER_CONDITION_NUMBER] =
{
    SM_ConditionVoltageT3,
    SM_ConditionVoltageT5,
    SM_ConditionHighMT3,
    SM_ConditionHighMT4,
    SM_ConditionHighMT6,
    SM_ConditionLowMT5,
    SM_ConditionLowMT7,
};

static const SM_EntryCallbackType entrys[SM_ENTRY_NUMBER] =
{
    SM_EntryCallbackVoltage,
    SM_EntryCallbackHighM,
    SM_EntryCallbackLowM,
};

static const SM_TransferCallbackType transfers[SM_TRANSFER_NUMBER] =
{
    SM_TransferCallbackVoltage,
    SM_TransferCallbackHighM,
    SM_TransferCallbackLowM,
};

static const SM_StayCallbackType stays[SM_STAY_NUMBER] =
{
    SM_StayCallbackVoltage,
    SM_StayCallbackHighM,
    SM_StayCallbackLowM,
};

const SM_ConfigType sm_config =
{
    SM_STATE_MACHINE_NUMBER,
    stateMachineConfigs,
    stateMachineDatas,
    SM_TRANSFER_ELEMENT_NUMBER,
    transferElementConfigs,
    SM_TRANSFER_CONDITION_NUMBER,
    transferConditionConfigs,
    SM_TRANSFER_ACTION_NUMBER,
    targets,
    SM_FEATURE_CONFIG_VALUE_NUMBER,
    featureConfigValues,
    SM_FEATURE_VALUE_NUMBER,
    featureValues,
    SM_STATE_NUMBER,
    stateConfigs,
    SM_TRANSFER_CONDITION_NUMBER,
    transferConditions,
    SM_ENTRY_NUMBER,
    entrys,
    SM_TRANSFER_NUMBER,
    transfers,
    SM_STAY_NUMBER,
    stays
};

#define SM_STOP_SEC_CONST_UNSPECIFIED
#include "StateMachine_MemMap.h"

#define SM_START_SEC_VAR_INIT_UNSPECIFIED
#include "StateMachine_MemMap.h"

SM_Type Sm = {SM_STATEMACHINE_INVALID, SM_SEQUENCE_IDLE, FALSE, FALSE, FALSE, NULL_PTR};

#define SM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "StateMachine_MemMap.h"

/*
 *  %function definition%
 */
static void SM_EntryCallbackVoltage(void)
{
    SM_StateCurrentSet(&Sm, 0);
}

static void SM_EntryCallbackHighM(void)
{
    SM_StateCurrentSet(&Sm, 3);
}

static void SM_EntryCallbackLowM(void)
{
    SM_StateCurrentSet(&Sm, 6);
}

static void SM_TransferCallbackVoltage(SM_StateType previous, SM_StateType next)
{

}

static void SM_TransferCallbackHighM(SM_StateType previous, SM_StateType next)
{

}

static void SM_TransferCallbackLowM(SM_StateType previous, SM_StateType next)
{

}

static void SM_StayCallbackVoltage(SM_StateType state)
{

}

static void SM_StayCallbackHighM(SM_StateType state)
{

}

static void SM_StayCallbackLowM(SM_StateType state)
{

}

static uint8 SM_ConditionVoltageT3(void)
{
    uint8 ret = 0;

    return ret;
}

static uint8 SM_ConditionVoltageT5(void)
{
    uint8 ret = 0;

    return ret;
}

static uint8 SM_ConditionHighMT3(void)
{
    uint8 ret = 0;

    return ret;
}

static uint8 SM_ConditionHighMT4(void)
{
    uint8 ret = 0;

    return ret;
}

static uint8 SM_ConditionHighMT6(void)
{
    uint8 ret = 0;

    return ret;
}

static uint8 SM_ConditionLowMT5(void)
{
    uint8 ret = 0;

    return ret;
}

static uint8 SM_ConditionLowMT7(void)
{
    uint8 ret = 0;

    return ret;
}
