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
*                 File:  IPC_SWUM.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group SWUM  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_SWUM_H_
#define _IPC_SWUM_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_SWUM_ID                                                        (4u)

/* MCU to SOC Message major id */
#define IPC_M2S_SWUM_MSGMAJOR_SWUM_UDS_ID                                        (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_ID                   (0u)
#define IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_ID                                 (1u)
/* MCU to SOC Message sub length */
#define IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH               (2u)
#define IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH                             (103u)
#define IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH_MIN                         (3u)
#define IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_FLEX_NUMBER                        (100u)


/* SOC to MCU Message major id */
#define IPC_S2M_SWUM_MSGMAJOR_SWUM_UDS_ID                                        (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROL_ID                           (0u)
#define IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_ID                                  (1u)
/* SOC to MCU Message sub length */
#define IPC_S2M_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROL_LENGTH                       (2u)
#define IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH                              (602u)
#define IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH_MIN                          (3u)
#define IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_FLEX_NUMBER                         (599u)
/* Group: : SWUM */
/* Message Major: SWUM_UDS */
/* Message Sub: SessionControlResponse */
typedef struct
{
    uint8_t Service;
    uint8_t SessionType;
}IPC_M2S_SWUMSWUM_UDSSessionControlResponse_t;

/* Transmit function of sub message SessionControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_SWUMSWUM_UDSSessionControlResponse_Transmit(IPC_M2S_SWUMSWUM_UDSSessionControlResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Response */
typedef struct
{
    uint16_t ResponseLength;
    uint8_t SID;
    uint8_t Response[100];
}IPC_M2S_SWUMSWUM_UDSResponse_t;

/* Transmit function of sub message Response */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_SWUMSWUM_UDSResponse_Transmit(IPC_M2S_SWUMSWUM_UDSResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : SWUM */
/* Group: : SWUM */
/* Message Major: SWUM_UDS */
/* Message Sub: SessionControl */
typedef struct
{
    uint8_t Service;
    uint8_t Type;
}IPC_S2M_SWUMSWUM_UDSSessionControl_t;

/* Receive function of sub message SessionControl */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_SWUMSWUM_UDSSessionControl_Receive(uint8_t *receiveData, IPC_S2M_SWUMSWUM_UDSSessionControl_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Request */
typedef struct
{
    uint16_t RequestLength;
    uint8_t SID;
    uint8_t Request[599];
}IPC_S2M_SWUMSWUM_UDSRequest_t;

/* Receive function of sub message Request */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_SWUMSWUM_UDSRequest_Receive(uint8_t *receiveData, IPC_S2M_SWUMSWUM_UDSRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : SWUM */
#ifdef __cplusplus
}
#endif

#endif
