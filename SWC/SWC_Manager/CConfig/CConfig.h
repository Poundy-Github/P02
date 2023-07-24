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
 * @file:      CConfig.h
 * @author:    Nobo
 * @date:      2020-10-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-10-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %head of header file guard%
 */
#ifndef __CCONFIG_H
#define __CCONFIG_H

/*
 *  %header file%
 */
#include "Rte_Type.h"
#include "Compiler.h"
#include "Platform_Types.h"


/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */
#define CCONFIG_DEV_ERROR_DETECT (STD_ON)

#ifndef TRUE
#define TRUE            ((boolean)1)
# endif

#ifndef FALSE
#define FALSE           ((boolean)0)
#endif


/* kind config */
typedef struct CConfig_KindConfigTypeTag
{
    uint16 byteStart;       /* byte start in raw config data */
    uint8 mask1;            /* mask in start byte */
    uint8 mask2;            /* mask in end byte */
    uint8 offset;           /* offset for last byte */
    uint8 byteNumberRaw;    /* byte numbers in raw data */
    uint16 bufferStart;      /* start of buffer to store kind config */
    uint16 bufferEnd;        /* end of buffer to store kind config */
} CConfig_KindConfigType;

/* module config */
typedef struct CConfig_ConfigTypeTag
{
    uint16 kindNumber;                              /* kind number */
    const CConfig_KindConfigType *kindConfigs;      /* kind configs */
    uint16 kindBufferSize;                          /* kind config buffer size */
    uint8 *kindBuffer;                              /* kind config buffer */
    uint16 rawDataSize;                             /* config raw data length */
    uint8 *rawData;                                 /* config raw data buffer */
    uint8 *rawDataBackup;                           /* config raw data backup buffer */
} CConfig_ConfigType;

/* module runtime data */
typedef struct CConfig_TypeTag
{
    boolean isInit;                                 /* initialized flag */
    uint8 updateCount;                              /* update flag for  */
    CConfig_ConfigType *config;                     /* module config */
} CConfig_Type;




/*
 *  %function declaration%
 */
FUNC(void, Vconfig_CODE) CConfig_Init(void); 

void CConfig_MainFunction(void);
/*
Std_ReturnType CConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig);
Std_ReturnType CConfig_GetUpdateTick(uint32 *updateTick);
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
