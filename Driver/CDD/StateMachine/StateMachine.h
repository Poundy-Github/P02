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
 * @file:      StateMachine.h
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
#ifndef __STATEMACHINE_H_
#define __STATEMACHINE_H_


/*
 *  %header file%
 */
#include "StateMachine_Cfg.h"

/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */
typedef uint8 SM_ReturnType;
#define SM_E_NO_ERROR                                  (0u)
#define SM_E_PARAM                                     (1u)
#define SM_E_UNINIT                                    (2u)
#define SM_E_PARAM_POINTER                             (3u)
#define SM_E_SEQUENCE                                  (4u)

typedef uint8 SM_SequenceType;
#define SM_SEQUENCE_IDLE                               (0u)
#define SM_SEQUENCE_TRANSFER                           (1u)
#define SM_SEQUENCE_ENTRY                              (2u)

typedef uint16 SM_TimerType;

typedef uint8 (*SM_TransferConditionType)(void);
typedef void (*SM_EntryCallbackType)(void);
typedef void (*SM_TransferCallbackType)(SM_StateType, SM_StateType);
typedef void (*SM_StayCallbackType)(SM_StateType);


/* transfer element config data */ 
typedef struct SM_TransferElementConfigTypeTag
{
    SM_FeatureValueByteIdType featureValueStart;        /* feature value location start index */
    SM_FeatureValueByteIdType featureValueEnd;          /* feature value location end index */
    SM_ActionIdType actionIdStart;                      /* action location start index */
    SM_ActionIdType actionIdEnd;                        /* action location end index */
} SM_TransferElementConfigType;

/* transfer condition config data */ 
typedef struct SM_TransferConditionConfigTypeTag
{
    SM_TransferConditionIdType transferCondition;       /* callback id */
    uint8 featureBitStart;                              /* bit start in feature byte array */
    uint8 featureBitLength;                             /* bit length in feature byte array */
} SM_TransferConditionConfigType;

/* state machine config data */
typedef struct SM_StateMachineConfigTypeTag
{
    boolean topLevel;                                           /* top level flag */
    SM_StateType stateStart;                                    /* state id start */
    SM_StateType stateEnd;                                      /* state id end */
    SM_TransferConditionConfigIdType transferConditionStart;    /* transfer condition id start */
    SM_TransferConditionConfigIdType transferConditionEnd;      /* transfer condition id end */
    SM_TransferElementIdType transferElementStart;              /* transfer element id start */
    SM_TransferElementIdType transferElementEnd;                /* transfer element id end */
    SM_FeatureValueIdType featureValueStart;                    /* feature value id start */
    SM_FeatureValueIdType featureValueEnd;                      /* feature value id end */
    SM_EntryCallbackIdType entry;                               /* entry callback id */
    SM_StayCallbackIdType stay;                                 /* state stay callback id */
    SM_TransferCallbackIdType transfer;                         /* state transfer callback id */
} SM_StateMachineConfigType;

/* state machine runtime data */
typedef struct SM_StateMachineTypeTag 
{
    SM_StateType stateCurrent;                  /* current state */
    boolean activate;                           /* activate flag */
    SM_TransferElementIdType transferElement;   /* cached transfer element id */
} SM_StateMachineType;

/* state config data */
typedef struct SM_StateConfigTypeTag
{
    char* name;                                 /* name of state */
    SM_StateMachineIdType subStateMachine;      /* sub statemachine id; If no sub state mahine, set SM_STATEMACHINE_INVALID */
} SM_StateConfigType;

/* state machine module config */
typedef struct SM_ConfigTypeTag
{
    SM_StateMachineIdType stateMachineNumber;                       /* state machine number */
    const SM_StateMachineConfigType *stateMachineConfigs;           /* state machine config array */
    SM_StateMachineType *stateMachineDatas;                         /* state machine data array */
    SM_TransferElementIdType transferElementNumber;                 /* transfer element number */
    const SM_TransferElementConfigType *transferElementConfigs;     /* transfer element config array */
    SM_TransferConditionConfigIdType transferConditionConfigNumber; /* transfer condition number */
    const SM_TransferConditionConfigType *transferConditionConfigs; /* transfer condition config array */
    SM_ActionIdType actionTargetNumber;                             /* action number */
    const SM_StateType *targets;                                    /* action config array */
    SM_FeatureValueIdType featureConfigValueNumber;                 /* feature value number */
    const uint8 *featureConfigValues;                               /* feature value config array */
    SM_FeatureValueIdType featureValueNumber;                       /* calculate feature value */
    uint8 *featureValues;                                           /* calculate feature value buffer array */
    SM_StateType stateNumber;                                       /* state number */
    const SM_StateConfigType *stateConfigs;                         /* state config array */
    SM_TransferConditionIdType transferConditionNumber;             /* transfer condition number */
    const SM_TransferConditionType *transferConditions;             /* transfer condition config array */
    SM_EntryCallbackIdType entryNumber;                             /* entry callback number */
    const SM_EntryCallbackType *entrys;                             /* entry callback array */
    SM_TransferCallbackIdType transferNumber;                       /* transfer callback number */
    const SM_TransferCallbackType *transfers;                       /* transfer callback array */
    SM_StayCallbackIdType stayNumber;                               /* stay callback number */
    const SM_StayCallbackType *stays;                               /* stay callback array */
} SM_ConfigType;

/* state machine module data */
typedef struct SM_TypeTag
{
    SM_StateMachineIdType currentStateMachine;  /* current state machine id */
    SM_SequenceType sequence;                   /* state machine current handle sequence */
    boolean initFlag;                           /* module init flag */
    boolean enabled;                            /* enabled flag */
    boolean enabledBackground;                  /* enabled background flag */
    const SM_ConfigType *config;                /* config pointer */
} SM_Type;

/*
 *  %function declaration%
 */
void SM_Init(SM_Type *sm, const SM_ConfigType *config);
void SM_MainFunction(SM_Type *sm);
SM_ReturnType SM_StateCurrentSet(SM_Type *sm, SM_StateType state);
SM_ReturnType SM_StateCurrentGet(SM_Type *sm, SM_StateType *state);
SM_ReturnType SM_StateNameGet(SM_Type *sm, SM_StateType state, const char** name);
SM_ReturnType SM_EnabledSet(SM_Type *sm, boolean enabled);


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
