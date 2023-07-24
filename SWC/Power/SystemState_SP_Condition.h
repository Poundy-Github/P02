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
 * @file:      SystemState_SP_Condition.h
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

#ifndef __SYSTEMSTATE_SP_CONDITION_H_
#define __SYSTEMSTATE_SP_CONDITION_H_

#include "StateMachine.h"
#include "SystemState_InitCfg.h"

#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

extern uint8 SystemState_SP_State;
extern SM_Type Sm_SP;

extern void SystemState_SPInit(void);
extern void SystemState_SP_MainFunc(void);
extern void SystemState_SPEnableSet(boolean Enabled);
extern uint8 SystemState_SP_Sts(void);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"



#endif
