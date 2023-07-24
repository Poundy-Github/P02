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
*                 File:  IPC_CAN.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group CAN  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_CAN_H_
#define _IPC_CAN_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_CAN_ID                                                         (1u)

/* MCU to SOC Message major id */
#define IPC_M2S_CAN_MSGMAJOR_MESSAGE_ID                                          (0u)
#define IPC_M2S_CAN_MSGMAJOR_SIGNAL_ID                                           (1u)
/* MCU to SOC Message sub id */
#define IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_ID                                    (0u)
#define IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_ID                                     (1u)
#define IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_ID                                    (2u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_ID                                     (0u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_ID                                     (1u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_ID                            (2u)
/* MCU to SOC Message sub length */
#define IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH                                (70u)
#define IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH_MIN                            (6u)
#define IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_FLEX_NUMBER                           (64u)
#define IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_LENGTH                                 (5u)
#define IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH                                (4u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH                                 (71u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH_MIN                             (3u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_FLEX_NUMBER                            (68u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH                                 (4u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH                        (71u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH_MIN                    (3u)
#define IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_FLEX_NUMBER                   (68u)


/* SOC to MCU Message major id */
#define IPC_S2M_CAN_MSGMAJOR_MESSAGE_ID                                          (0u)
#define IPC_S2M_CAN_MSGMAJOR_SIGNAL_ID                                           (1u)
/* SOC to MCU Message sub id */
#define IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_ID                                   (0u)
#define IPC_S2M_CAN_MESSAGE_MSGSUB_REQUEST_ID                                    (1u)
#define IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_ID                                    (0u)
#define IPC_S2M_CAN_SIGNAL_MSGSUB_REQUEST_ID                                     (1u)
/* SOC to MCU Message sub length */
#define IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH                               (70u)
#define IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH_MIN                           (6u)
#define IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_FLEX_NUMBER                          (64u)
#define IPC_S2M_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH                                (4u)
#define IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH                                (259u)
#define IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH_MIN                            (3u)
#define IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_FLEX_NUMBER                           (256u)
#define IPC_S2M_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH                                 (4u)
/* Group: : CAN */
/* Message Major: Message */
/* Message Sub: Receive */
typedef struct
{
    uint16_t DataLength;
    /*message frame id,example:0x23A*/
    uint32_t FrameId;
    /*can message data,max length 64 byte*/
    uint8_t Data[64];
}IPC_M2S_CANMessageReceive_t;

/* Transmit function of sub message Receive */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_CANMessageReceive_Transmit(IPC_M2S_CANMessageReceive_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Status */
typedef struct
{
    /*message id,example:0x23A*/
    uint32_t FrameId;
    /*can message Status
    #define GWM_MSG_STATUS_IS_OK(Data)                          (0u == (uint8_t)Data[0])
    #define GWM_MSG_STATUS_IS_TIME_OUT(Data)               ((64u & (uint8_t)Data[0]) == 64u)
    #define GWM_MSG_STATUS_IS_NEVER_RECEIVED(Data)    ((133u & (uint8_t)Data[0]) == 133u)*/
    uint8_t Status;
}IPC_M2S_CANMessageStatus_t;

/* Transmit function of sub message Status */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_CANMessageStatus_Transmit(IPC_M2S_CANMessageStatus_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Request */
typedef struct
{
    /*FrameId = 0 :request all download messages(Reserved)*/
    uint32_t FrameId;
}IPC_M2S_CANMessageRequest_t;

/* Transmit function of sub message Request */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_CANMessageRequest_Transmit(IPC_M2S_CANMessageRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : CAN */
/* Message Major: Signal */
/* Message Sub: Receive */
typedef struct
{
    uint16_t DataPoolLength;
    /*Message data contain signal number*/
    uint8_t Number;
    /*can signal data, uint32 signal index+ uint8* data ,max length 64 byte*/
    uint8_t DataPool[68];
}IPC_M2S_CANSignalReceive_t;

/* Transmit function of sub message Receive */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_CANSignalReceive_Transmit(IPC_M2S_CANSignalReceive_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Request */
typedef struct
{
    /*SignalId由protobuf内的CodeId定义*/
    uint32_t SignalId;
}IPC_M2S_CANSignalRequest_t;

/* Transmit function of sub message Request */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_CANSignalRequest_Transmit(IPC_M2S_CANSignalRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TransmitCallback */
typedef struct
{
    uint16_t DataPoolLength;
    /*Message data contain signal number*/
    uint8_t Number;
    /*can signal data, uint32 signal index+ uint8* data ,max length 64 byte*/
    uint8_t DataPool[68];
}IPC_M2S_CANSignalTransmitCallback_t;

/* Transmit function of sub message TransmitCallback */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_CANSignalTransmitCallback_Transmit(IPC_M2S_CANSignalTransmitCallback_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : CAN */
/* Group: : CAN */
/* Message Major: Message */
/* Message Sub: Transmit */
typedef struct
{
    uint16_t DataLength;
    /*message frame id,example:0x23A*/
    uint32_t FrameId;
    /*can message data,max length 64 byte*/
    uint8_t Data[64];
}IPC_S2M_CANMessageTransmit_t;

/* Receive function of sub message Transmit */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_CANMessageTransmit_Receive(uint8_t *receiveData, IPC_S2M_CANMessageTransmit_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Request */
typedef struct
{
    /*FrameId = 0 :request all update messages*/
    uint32_t FrameId;
}IPC_S2M_CANMessageRequest_t;

/* Receive function of sub message Request */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_CANMessageRequest_Receive(uint8_t *receiveData, IPC_S2M_CANMessageRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : CAN */
/* Message Major: Signal */
/* Message Sub: Transmit */
typedef struct
{
    uint16_t DataPoolLength;
    /*Message data contain signal number*/
    uint8_t Number;
    /*can signal data, uint32 signal index+ uint8* data ,max length 64 byte*/
    uint8_t DataPool[256];
}IPC_S2M_CANSignalTransmit_t;

/* Receive function of sub message Transmit */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_CANSignalTransmit_Receive(uint8_t *receiveData, IPC_S2M_CANSignalTransmit_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Request */
typedef struct
{
    /*SignalId由protobuf内的CodeId定义*/
    uint32_t SignalId;
}IPC_S2M_CANSignalRequest_t;

/* Receive function of sub message Request */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_CANSignalRequest_Receive(uint8_t *receiveData, IPC_S2M_CANSignalRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : CAN */
#ifdef __cplusplus
}
#endif

#endif
