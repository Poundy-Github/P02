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
 * @file:      VConfig.h
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
#ifndef __VCONFIG_H
#define __VCONFIG_H

/*
 *  %header file%
 */
#include "Rte_Type.h"
#include "Compiler.h"
#include "Platform_Types.h"
#include "Vconfig_Cfg.h"

/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */
#define VCONFIG_DEV_ERROR_DETECT (STD_ON)

/* kind config */
typedef struct VConfig_KindConfigTypeTag
{
    uint16 byte;        /* byte location in raw config data */
    uint8 startBit;     /* start bit in byte */
    uint8 endBit;       /* end bit in byte */
} VConfig_KindConfigType;

/* kind runtime data */
typedef struct VConfig_KindTypeTag
{
    uint8 configGet;    /* kind config converted from raw data */
} VConfig_KindType;

/* module config */
typedef struct VConfig_ConfigTypeTag
{
    uint16 kindNumber;                              /* kind number */
    const VConfig_KindConfigType *kindConfigs;      /* kind configs */
    VConfig_KindType *kindDatas;                    /* kind datas */
    uint16 rawDataSize;                             /* config raw data length */
    uint8 *rawData;                                 /* config raw data buffer */
    uint8 *rawDataBackup;                           /* config raw data backup buffer */
} VConfig_ConfigType;

/* module runtime data */
typedef struct VConfig_TypeTag
{
    boolean isInit;                                 /* initialized flag */
    TimeInMicrosecondsType updateTime;              /* last update tick */
    VConfig_ConfigType *config;                     /* module config */
} VConfig_Type;

/*
 *  %function declaration%
 */
extern uint8 Get_Vconfig_Flag;
extern uint8 Vconfig_Response_Flag;
//extern IPC_M2S_MiscServiceVreply_Usb_t Response_Data;
extern VConfig_ConfigType vconfig_config;



FUNC(void, Vconfig_CODE) VConfig_Init(void); 

void VConfig_MainFunction(void);
Std_ReturnType VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig);
Std_ReturnType VConfig_GetUpdateTick(TimeInMicrosecondsType  *updateTick);

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
