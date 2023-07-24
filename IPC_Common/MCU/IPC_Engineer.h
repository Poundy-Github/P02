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
*                 File:  IPC_Engineer.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group Engineer  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_ENGINEER_H_
#define _IPC_ENGINEER_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_ENGINEER_ID                                                    (11u)

/* MCU to SOC Message major id */
#define IPC_M2S_ENGINEER_MSGMAJOR_IVI_ID                                         (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_ID                          (0u)
#define IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_ID                           (1u)
/* MCU to SOC Message sub length */
#define IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH                      (106u)
#define IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH_MIN                  (6u)
#define IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_FLEX_NUMBER                 (100u)
#define IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_LENGTH                       (4u)


/* SOC to MCU Message major id */
#define IPC_S2M_ENGINEER_MSGMAJOR_IVI_ID                                         (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_ENGINEER_IVI_MSGSUB_READINFOREQUEST_ID                           (0u)
#define IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_ID                            (1u)
/* SOC to MCU Message sub length */
#define IPC_S2M_ENGINEER_IVI_MSGSUB_READINFOREQUEST_LENGTH                       (3u)
#define IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH                        (105u)
#define IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH_MIN                    (5u)
#define IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_FLEX_NUMBER                   (100u)
/* Group: : Engineer */
/* Message Major: IVI */
/* Message Sub: ReadInfoResponse */
typedef struct
{
    uint16_t DataLength;
    uint8_t ModuleId;
    uint16_t InfoId;
    uint8_t Result;
    uint8_t Data[100];
}IPC_M2S_EngineerIVIReadInfoResponse_t;

/* Transmit function of sub message ReadInfoResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EngineerIVIReadInfoResponse_Transmit(IPC_M2S_EngineerIVIReadInfoResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SetParaResponse */
typedef struct
{
    uint8_t ModuleId;
    uint16_t InfoId;
    uint8_t Result;
}IPC_M2S_EngineerIVISetParaResponse_t;

/* Transmit function of sub message SetParaResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EngineerIVISetParaResponse_Transmit(IPC_M2S_EngineerIVISetParaResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Engineer */
/* Group: : Engineer */
/* Message Major: IVI */
/* Message Sub: ReadInfoRequest */
typedef struct
{
    uint8_t ModuleId;
    uint16_t InfoId;
}IPC_S2M_EngineerIVIReadInfoRequest_t;

/* Receive function of sub message ReadInfoRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EngineerIVIReadInfoRequest_Receive(uint8_t *receiveData, IPC_S2M_EngineerIVIReadInfoRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SetParaRequest */
typedef struct
{
    uint16_t DataLength;
    uint8_t ModuleId;
    uint16_t InfoId;
    uint8_t Data[100];
}IPC_S2M_EngineerIVISetParaRequest_t;

/* Receive function of sub message SetParaRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EngineerIVISetParaRequest_Receive(uint8_t *receiveData, IPC_S2M_EngineerIVISetParaRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Engineer */
#ifdef __cplusplus
}
#endif

#endif
