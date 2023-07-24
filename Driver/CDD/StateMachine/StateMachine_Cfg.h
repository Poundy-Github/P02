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
 * @file:      StateMachine_Cfg.h
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
 *  %head of header file guard%
 */
#ifndef __STATEMACHINE_CFG_H_
#define __STATEMACHINE_CFG_H_


/*
 *  %header file%
 */
#include "Std_Types.h"
#include "Cdd_Common.h"


/*
 *  %head of extern "C" declaration%
 */
typedef uint8 SM_StateType;
typedef uint16 SM_ActionIdType;
typedef uint8 SM_TransferConditionIdType;
typedef uint8 SM_EntryCallbackIdType;
typedef uint8 SM_TransferCallbackIdType;
typedef uint8 SM_StayCallbackIdType;
typedef uint8 SM_FeatureValueByteIdType;
typedef uint8 SM_StateMachineIdType;
typedef uint16 SM_TransferElementIdType;
typedef uint8 SM_TransferConditionConfigIdType;
typedef uint16 SM_FeatureValueIdType;

#define SM_DEV_ERROR_DETECT                     (STD_ON)

#define SM_STATEMACHINE_INVALID                 (0xFFu)
#define SM_STATE_ORIGIN                         (0xFFu)

#define SM_STATE_MACHINE_NUMBER                 (3u)
#define SM_STATE_NUMBER                         (8u)
#define SM_TRANSFER_CONDITION_NUMBER            (7u)
#define SM_TRANSFER_ELEMENT_NUMBER              (14u)
#define SM_TRANSFER_ACTION_NUMBER               (39u)

#define SM_FEATURE_CONFIG_VALUE_NUMBER          (14u)
#define SM_FEATURE_VALUE_NUMBER                 (3u)

#define SM_ENTRY_NUMBER                         SM_STATE_MACHINE_NUMBER
#define SM_TRANSFER_NUMBER                      SM_STATE_MACHINE_NUMBER
#define SM_STAY_NUMBER                          SM_STATE_MACHINE_NUMBER

/*
 *  %function declaration%
 */



 /*
  *  %bottom of extern "C" declaration%
  */
#ifdef __cplusplus
 }
#endif
 
 /*
  *  %bottom of header file guard%
  */
#endif
