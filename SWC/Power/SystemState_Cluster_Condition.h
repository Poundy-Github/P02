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
 * @file:      SystemState_Cluster_Condition.h
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

#ifndef __SYSTEMSTATE_CLUSTER_CONDITION_H_
#define __SYSTEMSTATE_CLUSTER_CONDITION_H_

#include "StateMachine.h"
#include "SystemState_InitCfg.h"


typedef uint8 SystemState_Cluster_PA_t;


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

extern void SystemState_Cluster_Init(void);
extern SystemState_Cluster_PA_t SystemState_ClusterSts(void);
extern void SystemState_Cluster_MainFunc(void);
extern void SystemState_ClusterEnableSet(boolean Enabled);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"



#endif
