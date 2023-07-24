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
 * @file:      SystemState_Console_Condition.h
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

#ifndef __SYSTEMSTATE_CONSOLE_CONDITION_H_
#define __SYSTEMSTATE_CONSOLE_CONDITION_H_
#include "StateMachine.h"

typedef struct
{
    uint8 State;
}SystemState_Console_PA_t;

#define POWER_START_SEC_CODE
#include "Power_MemMap.h"


extern void SystemState_ConsoleInit(void);
extern SystemState_Console_PA_t SystemState_ConsoleSts(void);
extern void SystemState_Console_MainFunc(void);
extern void SystemState_ConsoleEnableSet(boolean Enabled);


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"


#endif
