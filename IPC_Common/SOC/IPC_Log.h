/**********************************************************************************************************************
*  COPYRIGHT
*  -------------------------------------------------------------------------------------------------------------------
*
*  This software is copyright protected and proprietary to Noch Automotive Technology(Shanghai) Co. , Ltd.
*  Noch Automotive Technology(Shanghai) Co. , Ltd. grants to you only those rights as set out in the license 
*  conditions.All other rights remain with Noch Automotive Technology(Shanghai) Co. , Ltd.
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*                 File:  IPC_Log.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_SOC.h.tem
*          Description:  IPC group Log  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_LOG_H_
#define _IPC_LOG_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_LOG_ID                                                         (6u)

/* MCU to SOC Message major id */
#define IPC_M2S_LOG_MSGMAJOR_DEFAULT_ID                                          (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_ID                                        (0u)
/* MCU to SOC Message sub length */
#define IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH                                    (127u)
#define IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH_MIN                                (27u)
#define IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_FLEX_NUMBER                               (100u)
/* SOC to MCU Message major id */
#define IPC_S2M_LOG_MSGMAJOR_DEFAULT_ID                                          (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_LOG_DEFAULT_MSGSUB_SETLOGLEVEL_ID                                (0u)
/* SOC to MCU Message sub length */
#define IPC_S2M_LOG_DEFAULT_MSGSUB_SETLOGLEVEL_LENGTH                            (17u)
/* Group: : Log */
/* Message Major: Default */
/* Message Sub: Log */
typedef struct
{
    uint16_t payloadLength;
    /*module name*/
    uint8_t Id[16];
    /*0: OFF;
    1: fatal;
    2: error;
    3: warn;
    4: info;
    5: debug;
    6: verbose;*/
    uint8_t level;
    /*UTC Time*/
    uint64_t timestamp;
    /*log data*/
    uint8_t payload[100];
}IPC_M2S_LogDefaultLog_t;

/* Pack function of sub message Log */
int32_t IPC_M2S_LogDefaultLog_Pack(IPC_M2S_LogDefaultLog_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Log */
int32_t IPC_M2S_LogDefaultLog_Parse(IPC_M2S_LogDefaultLog_t *data, uint8_t *payload, uint16_t length);

/* Group: : Log */
/* Group: : Log */
/* Message Major: Default */
/* Message Sub: SetLogLevel */
typedef struct
{
    /*module name:
    "ALL":Set all Mode.*/
    uint8_t Id[16];
    /*0: OFF;
    1: fatal;
    2: error;
    3: warn;
    4: info;
    5: debug;
    6: verbose;*/
    uint8_t level;
}IPC_S2M_LogDefaultSetLogLevel_t;

/* Pack function of sub message SetLogLevel */
int32_t IPC_S2M_LogDefaultSetLogLevel_Pack(IPC_S2M_LogDefaultSetLogLevel_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SetLogLevel */
int32_t IPC_S2M_LogDefaultSetLogLevel_Parse(IPC_S2M_LogDefaultSetLogLevel_t *data, uint8_t *payload, uint16_t length);

/* Group: : Log */
#ifdef __cplusplus
}
#endif

#endif
