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
 * @file:      SystemState_IVI_Condition.h
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

#ifndef __SYSTEMSTATE_IVI_CONDITION_H_
#define __SYSTEMSTATE_IVI_CONDITION_H_

#include "StateMachine.h"
#include "IPC_POWER.h"


typedef struct
{
    uint8 State;
    uint8 Force;
}s_Systemstate_IVI_PA_t;

#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

extern FUNC(boolean, Can_Server_CODE) Com_IPduEnableHandle(uint16 CanId, boolean EnableFlag);
extern void SystemState_IVIInit(void);
extern s_Systemstate_IVI_PA_t SystemState_IVISts(void);
extern void SystemState_IVI_MainFunc(void);
extern void SystemState_IVIEnableSet(boolean Enabled);
extern void IVI_FOTASts(uint8 *FOTAReceive);
extern uint8  Power_FotaSts_Get(void);
extern void PM_ClearRemoteflag(void);
extern void PM_ClearKL5Onceflag(void);
extern IPC_S2M_POWERSystemStateAPP_INFOSM_t Power_NMcbksts_Get(void);
extern IPC_S2M_POWERSystemStateAPP_INFOSM_t Power_QNXReqFlg_Get(void);


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"





#endif
