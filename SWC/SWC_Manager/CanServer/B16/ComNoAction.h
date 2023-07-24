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
 * @file:      ComNoAction.h
 * @author:    Nobo
 * @date:      2020-9-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %head of header file guard%
 */
#ifndef __COM_NO_ACTION_H
#define __COM_NO_ACTION_H

/*
 *  %header file in this project/library%
 */
#include "Platform_Types.h"
#include "ComEx_Type.h"
#include "Com.h"

/*
 *  %third-party header file%
 */

/*
 *  %system/C-run-time header file%
 */



/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */
#define CNA_DEV_ERROR_DETECT            STD_ON

typedef uint8 CNA_Behavior_t;
#define CNA_BEHAVIOR_NONE               (0u)
#define CNA_BEHAVIOR_UNSEND             (1u)
#define CNA_BEHAVIOR_SEND               (2u)
#define CNA_BEHAVIOR_CYCLE              (3u)

typedef struct CNA_SignalConfig
{
    uint8 repetition;
    CNA_Behavior_t behavior;
    Com_SignalIdType comSignalId;
    PduIdType comIPduId;
    uint16 noActionStart;
    uint16 noActionSize;
    uint16 currentStart;
    uint8 currentSize;
} CNA_SignalConfigType;

typedef struct CNA_Signal
{
    uint8 counter;
} CNA_SignalType;

typedef struct CNA_Config
{
    uint16 signalNumber;
    const CNA_SignalConfigType *signalConfigs;
    CNA_SignalType *signalDatas;
    uint16 noActionBufferSize;
    const uint8 *noActionBuffer;
    uint16 currentBufferSize;
    uint8 *currentBuffer;
    ComEx_SignalIdType CNAIdTableSize;
    const ComEx_SignalIdType *CNAIdTable;
} CNA_ConfigType;

typedef struct CNA
{
    boolean isInit;
    const CNA_ConfigType *config;
} CNA_Type;

extern const CNA_ConfigType cna_config;

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
