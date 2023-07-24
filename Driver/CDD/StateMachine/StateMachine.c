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
 * @file:      StateMachine.c
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
static SM_ReturnType SM_StateMachineHandle(SM_Type *sm, SM_StateMachineIdType stateMachine);
static SM_ReturnType SM_FeatureValueCalculate(SM_Type *sm, SM_StateMachineIdType stateMachine);
static void SM_FeatureValueClear(SM_Type *sm, SM_StateMachineIdType stateMachine);
static void SM_FeatureValueFill(SM_Type *sm, uint8 start, uint8 value, SM_FeatureValueIdType bufferIndex);
static SM_ReturnType SM_CheckFeatureVaule(SM_Type *sm, SM_StateMachineIdType stateMachine, SM_TransferElementIdType *elementChecked);
static SM_ReturnType SM_CheckFeatureVauleSingle(SM_Type *sm, SM_StateMachineIdType stateMachine, SM_TransferElementIdType element, boolean *isFound);
static void SM_StateTransfer(SM_Type *sm, SM_StateMachineIdType stateMachine, SM_StateType target);


/*
 *  %global definition%
 */



/*
 *  %function definition%
 */
#define SM_START_SEC_CODE
#include "StateMachine_MemMap.h"
/*
* @brief   :   init state machine
* @param   :   sm[IN]: runtime data of state machine
* @param   :   config[IN]: config of state machine
* @retval  :   SM_E_NO_ERROR: initialize success
* @retval  :   SM_E_PARAM_POINTER: zero pointer error
* @retval  :   SM_E_UNINIT: already initialized
*/
void SM_Init(SM_Type *sm, const SM_ConfigType *config)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;

#if(SM_DEV_ERROR_DETECT == STD_ON)
    if((NULL_PTR == config) || (NULL_PTR == sm))
    {
        retFsm = SM_E_PARAM_POINTER;
    }
    else if(FALSE != sm->initFlag)
    {
        retFsm = SM_E_UNINIT;
    }
    else
#endif
    {
        SM_StateMachineIdType index;
        const SM_StateMachineConfigType *stateMachineConfig;
        SM_StateMachineType *stateMachineData;

        sm->config = config;
        sm->initFlag = TRUE;
        sm->enabledBackground = FALSE;
        sm->enabled = FALSE;

        for(index = 0u; index  < config->stateMachineNumber; index++)
        {
            stateMachineConfig = &config->stateMachineConfigs[index];
            stateMachineData = &config->stateMachineDatas[index];

            sm->currentStateMachine = index;
            stateMachineData->transferElement = stateMachineConfig->transferElementStart;
            stateMachineData->stateCurrent = SM_STATE_ORIGIN;
            stateMachineData->activate = stateMachineConfig->topLevel;
        }

        for(index = 0u; index  < config->stateMachineNumber; index++)
        {
            stateMachineConfig = &config->stateMachineConfigs[index];
            stateMachineData = &config->stateMachineDatas[index];

            sm->currentStateMachine = index;
            sm->sequence = SM_SEQUENCE_ENTRY;
            if(TRUE == stateMachineData->activate)
            {
                sm->config->entrys[stateMachineConfig->entry]();
            }
            sm->sequence = SM_SEQUENCE_IDLE;
        }
        sm->currentStateMachine = SM_STATEMACHINE_INVALID;
    }

    if(SM_E_NO_ERROR != retFsm)
    {
        /* RetReport */
    }
}


/*
* @brief   :   main function of state machine
*              this function should be run every certain cycle
* @param   :   sm[IN]: runtime data of state machine
* @retval  :   none
*/
void SM_MainFunction(SM_Type *sm)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;

#if(SM_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == sm)
    {
        retFsm = SM_E_PARAM_POINTER;
    }
    else if(FALSE == sm->initFlag)
    {
        retFsm = SM_E_UNINIT;
    }
    else
#endif
    {
        SM_StateMachineIdType index;

        if(sm->enabledBackground != sm->enabled)
        {
            sm->enabled = sm->enabledBackground;
        }

        if(TRUE == sm->enabled)
        {
            for(index = 0; index  < sm->config->stateMachineNumber; index++)
            {
                const SM_StateMachineType *stateMachineData = &sm->config->stateMachineDatas[index];

                if(TRUE == stateMachineData->activate)
                {
                    retFsm = SM_StateMachineHandle(sm, index);
                    if(SM_E_NO_ERROR != retFsm)
                    {
                        break;
                    }
                }
            }
        }
    }

    if(SM_E_NO_ERROR != retFsm)
    {
        /* RetReport */
    }
}


/*
* @brief   :   handle single state machine
* @param   :   sm[IN]: runtime data of state machine
* @param   :   stateMachine[IN]: id of stateMachine to handle
* @retval  :   SM_E_NO_ERROR: init success
* @retval  :   SM_E_PARAM: parameter error
*/
static SM_ReturnType SM_StateMachineHandle(SM_Type *sm, SM_StateMachineIdType stateMachine)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;
    const SM_StateMachineConfigType *stateMachineConfig = &sm->config->stateMachineConfigs[stateMachine];
    SM_StateMachineType *stateMachineData = &sm->config->stateMachineDatas[stateMachine];

    sm->currentStateMachine = stateMachine;

    /* calculate feature value */
    retFsm = SM_FeatureValueCalculate(sm, stateMachine);
    if(SM_E_NO_ERROR == retFsm)
    {
        /* check which tranfer element fulfill */
        SM_TransferElementIdType element;
        retFsm = SM_CheckFeatureVaule(sm, stateMachine, &element);
        if(SM_E_NO_ERROR == retFsm)
        {
            SM_ActionIdType nextState = sm->config->targets[sm->config->transferElementConfigs[element].actionIdStart + (stateMachineData->stateCurrent - stateMachineConfig->stateStart)];

            stateMachineData->transferElement = element;
            if(nextState == stateMachineData->stateCurrent)
            {
                sm->config->stays[stateMachineConfig->stay](stateMachineData->stateCurrent);
            }
            else
            {
                /* target state is not same as state now, state transfer */
                SM_StateTransfer(sm, stateMachine, nextState);
            }
        }
    }
    sm->currentStateMachine = SM_STATEMACHINE_INVALID;
    return retFsm;
}


/*
* @brief   :   calculate feature value of current state machine
* @param   :   sm[IN]: runtime data of state machine
* @param   :   stateMachine[IN]: id of stateMachine to calculate feature value
* @retval  :   SM_E_NO_ERROR: init success
* @retval  :   SM_E_PARAM: parameter error
*/
static SM_ReturnType SM_FeatureValueCalculate(SM_Type *sm, SM_StateMachineIdType stateMachine)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;
    const SM_StateMachineConfigType *stateMachineConfig = &sm->config->stateMachineConfigs[stateMachine];
    uint8 condition;

    SM_FeatureValueClear(sm, stateMachine);
    for(condition = stateMachineConfig->transferConditionStart; condition < stateMachineConfig->transferConditionEnd; condition++)
    {
        const SM_TransferConditionConfigType *transferConfig = &sm->config->transferConditionConfigs[condition];
        uint8 result = sm->config->transferConditions[transferConfig->transferCondition]();

        /* check result */
        if(result > transferConfig->featureBitLength)
        {
            retFsm = SM_E_PARAM;
            break;
        }
        else
        {
            SM_FeatureValueFill(sm, transferConfig->featureBitStart, result, stateMachineConfig->featureValueStart);
        }
    }
    return retFsm;
}


/*
* @brief   :   clear feature value storage
* @param   :   sm[IN]: runtime data of state machine
* @param   :   stateMachine[IN]: id of stateMachine to calculate feature value
* @retval  :   none
*/
static void SM_FeatureValueClear(SM_Type *sm, SM_StateMachineIdType stateMachine)
{
    const SM_StateMachineConfigType *stateMachineConfig = &sm->config->stateMachineConfigs[stateMachine];
    SM_FeatureValueIdType valueIndex;

    for(valueIndex = stateMachineConfig->featureValueStart; valueIndex < stateMachineConfig->featureValueEnd; valueIndex++)
    {
        sm->config->featureValues[valueIndex] = 0u;
    }
}


/*
* @brief   :   fill feature value of single transfer condition to state machine feature value storage
* @param   :   start[IN]: start bit of feature value
* @param   :   length[IN]: bit length of feature value
* @param   :   value[IN]: value of feature value
* @param   :   bufferIndex[IN]: index of feature value storage
* @retval  :   none
*/
static void SM_FeatureValueFill(SM_Type *sm, uint8 start, uint8 value, SM_FeatureValueIdType bufferIndex)
{
    uint8 position = start + value;
    uint8 byte = position >> 3;
    uint8 bit = position & 0x7;

    sm->config->featureValues[bufferIndex + byte] |= (1u << bit);
}


/*
* @brief   :   pair calculated feature value to configured feature matrix
* @param   :   sm[IN]: runtime data of state machine
* @param   :   stateMachine[IN]: id of stateMachine to calculate feature value
* @param   :   elementChecked[OUT]: element which passed check
* @retval  :   SM_E_NO_ERROR: pair feature value successfully
* @retval  :   SM_E_PARAM: can not pair any feature, the configured feature matrix is not full
*/
static SM_ReturnType SM_CheckFeatureVaule(SM_Type *sm, SM_StateMachineIdType stateMachine, SM_TransferElementIdType *elementChecked)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;
    const SM_StateMachineConfigType *stateMachineConfig = &sm->config->stateMachineConfigs[stateMachine];
    SM_StateMachineType *stateMachineData = &sm->config->stateMachineDatas[stateMachine];
    SM_TransferElementIdType element;
    boolean isFound = FALSE;

    /* first check last element */
    element = stateMachineData->transferElement;
    retFsm = SM_CheckFeatureVauleSingle(sm, stateMachine, stateMachineData->transferElement, &isFound);

    if((SM_E_NO_ERROR == retFsm) && (FALSE == isFound))
    {
        /* not same as last, iterate all transferElement */
        for(element = stateMachineConfig->transferElementStart; element < stateMachineConfig->transferElementEnd; element++)
        {
            retFsm = SM_CheckFeatureVauleSingle(sm, stateMachine, element, &isFound);

            if(((SM_E_NO_ERROR == retFsm) && (TRUE == isFound)) || (SM_E_NO_ERROR != retFsm)) 
            {
                break;
            }
        }

        /* no find */
        if((FALSE == isFound) && (SM_E_NO_ERROR == retFsm))
        {
            retFsm = SM_E_PARAM;
        }
    }

    if(SM_E_NO_ERROR == retFsm)
    {
        *elementChecked = element;
    }
    return retFsm;
}


/*
* @brief   :   pair single calculated feature value to configured feature matrix
* @param   :   sm[IN]: runtime data of state machine
* @param   :   stateMachine[IN]: id of stateMachine to calculate feature value
* @param   :   element[IN]: element id try to pair
* @param   :   isFound[OUT]: indicate if this element can match or not
* @retval  :   SM_E_NO_ERROR: pair process with no error
* @retval  :   SM_E_PARAM: configure error with wrong feature value lenght
*/
static SM_ReturnType SM_CheckFeatureVauleSingle(SM_Type *sm, SM_StateMachineIdType stateMachine, SM_TransferElementIdType element, boolean *isFound)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;
    const SM_StateMachineConfigType *stateMachineConfig = &sm->config->stateMachineConfigs[stateMachine];
    const SM_TransferElementConfigType *elementConfig = &sm->config->transferElementConfigs[element];
    SM_FeatureValueByteIdType length = (SM_FeatureValueByteIdType)stateMachineConfig->featureValueEnd - stateMachineConfig->featureValueStart;
    SM_FeatureValueByteIdType lengthConfig = elementConfig->featureValueEnd - elementConfig->featureValueStart;

    *isFound = FALSE;
    if(length != lengthConfig)
    {
        retFsm = SM_E_PARAM;
    }
    else
    {
        uint8 *featureValuePosition = &sm->config->featureValues[stateMachineConfig->featureValueStart];
        const uint8 *featureConfigValuePosition = &sm->config->featureConfigValues[elementConfig->featureValueStart];
        SM_FeatureValueByteIdType index;

        /* check byte by byte */
        for(index = 0; index < length; index++)
        {
            if((featureConfigValuePosition[index] | featureValuePosition[index]) != 0xFF)
            {
                break;
            }
        }

        /* find it */
        if(index == length)
        {
            *isFound = TRUE;
        }
    }
    return retFsm;
}


/*
* @brief   :   transfer state from current to target
* @param   :   sm[IN]: runtime data of state machine
* @param   :   stateMachine[IN]: id of stateMachine to transfer state
* @param   :   target[IN]: transfer state to this state
* @retval  :   none
*/
static void SM_StateTransfer(SM_Type *sm, SM_StateMachineIdType stateMachine, SM_StateType target)
{
    const SM_StateMachineConfigType *stateMachineConfig = &sm->config->stateMachineConfigs[stateMachine];
    SM_StateMachineType *stateMachineData = &sm->config->stateMachineDatas[stateMachine];
    SM_StateMachineIdType subStateMachine = sm->config->stateConfigs[target].subStateMachine;
    SM_StateType stateSource;
    SM_StateMachineIdType stateMachineSource;

    (void)SM_StateCurrentGet(sm, &stateSource);
    if(stateSource < sm->config->stateNumber)
    {
        stateMachineSource = sm->config->stateConfigs[stateSource].subStateMachine;
        if(stateMachineSource < sm->config->stateMachineNumber)
        {
            /* exited state is a state machine */
            sm->config->stateMachineDatas[stateMachineSource].activate = FALSE;
        }
    }

    sm->sequence = SM_SEQUENCE_TRANSFER;
    sm->config->transfers[stateMachineConfig->transfer](stateMachineData->stateCurrent, target);
    stateMachineData->stateCurrent = target;
    sm->sequence = SM_SEQUENCE_IDLE;

    if(subStateMachine < sm->config->stateMachineNumber)
    {
        /* entered state is a state machine */
        const SM_StateMachineConfigType *subStateMachineConfig = &sm->config->stateMachineConfigs[subStateMachine];
        SM_StateMachineType *subStateMachineData = &sm->config->stateMachineDatas[subStateMachine];

        sm->currentStateMachine = subStateMachine;
        sm->sequence = SM_SEQUENCE_ENTRY;
        sm->config->entrys[subStateMachineConfig->entry]();
        subStateMachineData->activate = TRUE;
        sm->sequence = SM_SEQUENCE_IDLE;
    }
}


/*
* @brief   :   set current state
*              This function can only be called during state machine entry
* @param   :   sm[IN]: runtime data of state machine
* @param   :   state[IN]: state to set for current state machine
* @retval  :   SM_E_NO_ERROR: set state successfully
* @retval  :   SM_E_PARAM: wrong state to set
* @retval  :   SM_E_UNINIT: module is not initialized
* @retval  :   SM_E_SEQUENCE: call this function in wrong context
*/
SM_ReturnType SM_StateCurrentSet(SM_Type *sm, SM_StateType state)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;

#if(SM_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == sm)
    {
        retFsm = SM_E_PARAM_POINTER;
    }
    else if(FALSE == sm->initFlag)
    {
        retFsm = SM_E_UNINIT;
    }
    else if(sm->currentStateMachine >= sm->config->stateMachineNumber)
    {
        retFsm = SM_E_PARAM;
    }
    else 
#endif
    if(sm->sequence != SM_SEQUENCE_ENTRY)
    {
        retFsm = SM_E_SEQUENCE;
    }
    else
    {
        const SM_StateMachineConfigType *stateMachineConfig = &sm->config->stateMachineConfigs[sm->currentStateMachine];

        if((state >= stateMachineConfig->stateEnd) || (state < stateMachineConfig->stateStart))
        {
            retFsm = SM_E_PARAM;
        }
        else
        {
            SM_StateTransfer(sm, sm->currentStateMachine, state);
        }
    }
    return retFsm;
}


/*
* @brief   :   get current state of current statemachine
* @param   :   sm[IN]: runtime data of state machine
* @param   :   state[OUT]: pointer of state to get state
* @retval  :   SM_E_NO_ERROR: get state successfully
* @retval  :   SM_E_PARAM: state is NULL
* @retval  :   SM_E_UNINIT: module is not initialized
*/
SM_ReturnType SM_StateCurrentGet(SM_Type *sm, SM_StateType *state)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;

#if(SM_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == sm)
    {
        retFsm = SM_E_PARAM_POINTER;
    }
    else if(FALSE == sm->initFlag)
    {
        retFsm = SM_E_UNINIT;
    }
    else if((sm->currentStateMachine >= sm->config->stateMachineNumber) || (NULL_PTR == state))
    {
        retFsm = SM_E_PARAM;
    }
    else
#endif
    {
        SM_StateMachineType *stateMachineData = &sm->config->stateMachineDatas[sm->currentStateMachine];

        *state = stateMachineData->stateCurrent;
    }
    return retFsm;
}


/*
* @brief   :   get state name
* @param   :   sm[IN]: runtime data of state machine
* @param   :   state[IN]: state id want to get name
* @param   :   name[OUT]: pointer of name string
* @retval  :   SM_E_NO_ERROR: get name successfully
* @retval  :   SM_E_PARAM: state id error or
* @retval  :   SM_E_UNINIT: module is not initialized
*/
SM_ReturnType SM_StateNameGet(SM_Type *sm, SM_StateType state, const char** name)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;

#if(SM_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == sm)
    {
        retFsm = SM_E_PARAM_POINTER;
    }
    else if(FALSE == sm->initFlag)
    {
        retFsm = SM_E_UNINIT;
    }
    else if((NULL_PTR == name) || ((state >= sm->config->stateNumber) && (SM_STATE_ORIGIN != state)))
    {
        retFsm = SM_E_PARAM;
    }
    else
#endif
    {
        if(SM_STATE_ORIGIN == state)
        {
            *name = "Origin";
        }
        else
        {
            *name = sm->config->stateConfigs[state].name;
        }
    }
    return retFsm;
}


/*
* @brief   :   set state machine enabled status
* @param   :   sm[IN]: runtime data of state machine
* @param   :   enabled[IN]: enabled state to set
* @retval  :   SM_E_NO_ERROR: set enabled state successfully
* @retval  :   SM_E_PARAM: state id error or
* @retval  :   SM_E_UNINIT: module is not initialized
*/
SM_ReturnType SM_EnabledSet(SM_Type *sm, boolean enabled)
{
    SM_ReturnType retFsm = SM_E_NO_ERROR;

#if(SM_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == sm)
    {
        retFsm = SM_E_PARAM_POINTER;
    }
    else if(FALSE == sm->initFlag)
    {
        retFsm = SM_E_UNINIT;
    }
    else
#endif
    {
        sm->enabledBackground = enabled;
        if(SM_STATEMACHINE_INVALID == sm->currentStateMachine)
        {
            sm->enabled = enabled;
        }
    }
    return retFsm;
}


#define SM_STOP_SEC_CODE
#include "StateMachine_MemMap.h"
