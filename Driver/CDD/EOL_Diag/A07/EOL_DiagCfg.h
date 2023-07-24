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
 * @file:      EOL_DiagCfg.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef __EOL_DIAGCFG_H
#define __EOL_DIAGCFG_H

/*
 *  %header file in this project/library%
 */
#include "Platform_Types.h"
#include "Std_Types.h"
#include "EOL_Diag.h"


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
#define   cByte46              46u;

#define E_PENDING           ((Std_ReturnType)2)


/*
 *  %type definition%
 */
typedef uint8 Dcm_OpStatusType;
typedef uint8 Dcm_NegativeResponseCodeType;

#define IPC_M2S_EOL_MSGMAJOR_EOL_ID    (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_EOL_EOL_MSGSUB_SESSIONCONTROLREQUEST_ID    (0u)
#define IPC_M2S_EOL_EOL_MSGSUB_DIDREADREQUEST_ID    (1u)
#define IPC_M2S_EOL_EOL_MSGSUB_DIDWRITEREQUEST_ID    (2u)

typedef struct IPC_M2S_EOLEOLDidReadRequest 
{
    /* Signal 1: ServiceId number: 1 */
    uint8 ServiceId;
    /* Signal 2: Did number: 1 */
    uint16 Did;
} IPC_M2S_EOLEOLDidReadRequest_t;

typedef struct IPC_S2M_EOLEOLSessionControlResponse 
{
    /* Signal 1: ServiceId number: 1 */
    uint8 ServiceId;
    /* Signal 2: Type number: 1 */
    uint8 Type;
} IPC_S2M_EOLEOLSessionControlResponse_t;

typedef struct IPC_M2S_EOLEOLDidWriteRequest 
{
    /* Signal 3 length location */
    uint16 payloadLength;
    /* Signal 1: ServiceId number: 1 */
    uint8 ServiceId;
    /* Signal 2: Did number: 1 */
    uint16 Did;
    /* Signal 3: payload number: 50 */
    uint8 payload[50];
} IPC_M2S_EOLEOLDidWriteRequest_t;

typedef struct IPC_M2S_EOLEOLSessionControlRequest 
{
    /* Signal 1: ServiceId number: 1 */
    uint8 ServiceId;
    /* Signal 2: Type number: 1 */
    uint8 Type;
} IPC_M2S_EOLEOLSessionControlRequest_t;

/* Message Sub: DidReadResponse */
typedef struct IPC_S2M_EOLEOLDidReadResponse 
{
    /* Signal 3 length location */
    uint16 DataLength;
    /* Signal 1: ServiceId number: 1 */
    uint8 ServiceId;
    /* Signal 2: Did number: 1 */
    uint16 Did;
    /* Signal 3: Data number: 50 */
    uint8 Data[50];
} IPC_S2M_EOLEOLDidReadResponse_t;

typedef struct IPC_S2M_EOLEOLDidWriteResponse 
{
    /* Signal 1: ServiceId number: 1 */
    uint8 ServiceId;
    /* Signal 2: Did number: 1 */
    uint16 Did;
} IPC_S2M_EOLEOLDidWriteResponse_t;



/*
 *  %function declaration%
 */
extern void EOL_DiagTransferDidRead_Transmit_0x22(uint16 Did);
extern Std_ReturnType EOL_DiagTransferDidRead_0x22_0xF189(Dcm_OpStatusType OpStatus, uint8 * pu8ValueP);
extern Std_ReturnType EOL_DiagTransferDidWrite_0x2E_0x02CC( const uint8 Data[],
    Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode );
extern Std_ReturnType EOL_DiagTransferSessionControl_0x10_0x03( Dcm_OpStatusType OpStatus,
Dcm_NegativeResponseCodeType* ErrorCode );


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

