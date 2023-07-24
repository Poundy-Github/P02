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
 *                 File:  INFRA_Engineer.h
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.h.tem
 *          Description:  IPC group Engineer header file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#ifndef _INFRA_ENGINEER_H_
#define _INFRA_ENGINEER_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_ENGINEER_ID   (11u)

/* MCU to SOC Message major id */
#define INFRA_S2A_ENGINEER_MSGMAJOR_HMI_ID    (0u)
/* MCU to SOC Message sub id */
#define INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_ID    (0u)
#define INFRA_S2A_ENGINEER_HMI_MSGSUB_SETPARARESPONSE_ID    (1u)
/* MCU to SOC Message sub length */
#define INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_LENGTH    (56u)
#define INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_LENGTH_MIN    (6u)
#define INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_FLEX_NUMBER    (50u)
#define INFRA_S2A_ENGINEER_HMI_MSGSUB_SETPARARESPONSE_LENGTH    (4u)
/* SOC to MCU Message major id */
#define INFRA_A2S_ENGINEER_MSGMAJOR_HMI_ID    (0u)
/* SOC to MCU Message sub id */
#define INFRA_A2S_ENGINEER_HMI_MSGSUB_READINFOREQUEST_ID    (0u)
#define INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_ID    (1u)
/* SOC to MCU Message sub length */
#define INFRA_A2S_ENGINEER_HMI_MSGSUB_READINFOREQUEST_LENGTH    (3u)
#define INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_LENGTH    (55u)
#define INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_LENGTH_MIN    (5u)
#define INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_FLEX_NUMBER    (50u)

/* Group: Engineer */
/* Message Major: HMI */
/* Message Sub: ReadInfoResponse */
typedef struct INFRA_S2A_EngineerHMIReadInfoResponse 
{
    /* Signal 4 length location */
    uint16_t DataLength;
    /* Signal 1: ModuleId number: 1 */
    uint8_t ModuleId;
    /* Signal 2: InfoId number: 1 */
    uint16_t InfoId;
    /* Signal 3: Result number: 1 */
    uint8_t Result;
    /* Signal 4: Data number: 50 */
    uint8_t Data[50];
} INFRA_S2A_EngineerHMIReadInfoResponse_t;

int32_t INFRA_S2A_EngineerHMIReadInfoResponse_Pack(INFRA_S2A_EngineerHMIReadInfoResponse_t *data, uint8_t *payload, uint16_t length);  
int32_t INFRA_S2A_EngineerHMIReadInfoResponse_Parse(INFRA_S2A_EngineerHMIReadInfoResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: SetParaResponse */
typedef struct INFRA_S2A_EngineerHMISetParaResponse 
{
    /* Signal 1: ModuleId number: 1 */
    uint8_t ModuleId;
    /* Signal 2: InfoId number: 1 */
    uint16_t InfoId;
    /* Signal 3: Result number: 1 */
    uint8_t Result;
} INFRA_S2A_EngineerHMISetParaResponse_t;

int32_t INFRA_S2A_EngineerHMISetParaResponse_Pack(INFRA_S2A_EngineerHMISetParaResponse_t *data, uint8_t *payload, uint16_t length);  
int32_t INFRA_S2A_EngineerHMISetParaResponse_Parse(INFRA_S2A_EngineerHMISetParaResponse_t *data, uint8_t *payload, uint16_t length);

/* Group: Engineer */
/* Message Major: HMI */
/* Message Sub: ReadInfoRequest */
typedef struct INFRA_A2S_EngineerHMIReadInfoRequest 
{
    /* Signal 1: ModuleId number: 1 */
    uint8_t ModuleId;
    /* Signal 2: InfoId number: 1 */
    uint16_t InfoId;
} INFRA_A2S_EngineerHMIReadInfoRequest_t;

int32_t INFRA_A2S_EngineerHMIReadInfoRequest_Pack(INFRA_A2S_EngineerHMIReadInfoRequest_t *data, uint8_t *payload, uint16_t length);
int32_t INFRA_A2S_EngineerHMIReadInfoRequest_Parse(INFRA_A2S_EngineerHMIReadInfoRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: SetParaRequest */
typedef struct INFRA_A2S_EngineerHMISetParaRequest 
{
    /* Signal 3 length location */
    uint16_t DataLength;
    /* Signal 1: ModuleId number: 0 */
    uint8_t ModuleId;
    /* Signal 2: InfoId number: 0 */
    uint16_t InfoId;
    /* Signal 3: Data number: 50 */
    uint8_t Data[50];
} INFRA_A2S_EngineerHMISetParaRequest_t;

int32_t INFRA_A2S_EngineerHMISetParaRequest_Pack(INFRA_A2S_EngineerHMISetParaRequest_t *data, uint8_t *payload, uint16_t length);
int32_t INFRA_A2S_EngineerHMISetParaRequest_Parse(INFRA_A2S_EngineerHMISetParaRequest_t *data, uint8_t *payload, uint16_t length);

#ifdef __cplusplus
}
#endif

#endif
