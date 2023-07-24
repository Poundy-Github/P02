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
*                 File:  IPC_EOL.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group EOL  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_EOL_H_
#define _IPC_EOL_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_EOL_ID                                                         (3u)

/* MCU to SOC Message major id */
#define IPC_M2S_EOL_MSGMAJOR_QNX_ID                                              (0u)
#define IPC_M2S_EOL_MSGMAJOR_IVI_ID                                              (1u)
/* MCU to SOC Message sub id */
#define IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_ID                          (0u)
#define IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_ID                                 (1u)
#define IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_ID                                (2u)
#define IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_ID                          (3u)
#define IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_ID                          (0u)
#define IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_ID                                 (1u)
#define IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_ID                                (2u)
#define IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_ID                          (3u)
/* MCU to SOC Message sub length */
#define IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH                      (2u)
#define IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_LENGTH                             (3u)
#define IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH                            (55u)
#define IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN                        (5u)
#define IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER                       (50u)
#define IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH                      (56u)
#define IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN                  (6u)
#define IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER                 (50u)
#define IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH                      (2u)
#define IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_LENGTH                             (3u)
#define IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH                            (55u)
#define IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN                        (5u)
#define IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER                       (50u)
#define IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH                      (56u)
#define IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN                  (6u)
#define IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER                 (50u)


/* SOC to MCU Message major id */
#define IPC_S2M_EOL_MSGMAJOR_QNX_ID                                              (0u)
#define IPC_S2M_EOL_MSGMAJOR_IVI_ID                                              (1u)
/* SOC to MCU Message sub id */
#define IPC_S2M_EOL_QNX_MSGSUB_SESSIONCONTROLRESPONSE_ID                         (0u)
#define IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_ID                                (1u)
#define IPC_S2M_EOL_QNX_MSGSUB_DIDWRITERESPONSE_ID                               (2u)
#define IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_ID                         (3u)
#define IPC_S2M_EOL_IVI_MSGSUB_SESSIONCONTROLRESPONSE_ID                         (0u)
#define IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_ID                                (1u)
#define IPC_S2M_EOL_IVI_MSGSUB_DIDWRITERESPONSE_ID                               (2u)
#define IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_ID                         (3u)
/* SOC to MCU Message sub length */
#define IPC_S2M_EOL_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH                     (2u)
#define IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH                            (55u)
#define IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN                        (5u)
#define IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER                       (50u)
#define IPC_S2M_EOL_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH                           (3u)
#define IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH                     (56u)
#define IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN                 (6u)
#define IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER                (50u)
#define IPC_S2M_EOL_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH                     (2u)
#define IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH                            (55u)
#define IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN                        (5u)
#define IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER                       (50u)
#define IPC_S2M_EOL_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH                           (3u)
#define IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH                     (56u)
#define IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN                 (6u)
#define IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER                (50u)
/* Group: : EOL */
/* Message Major: QNX */
/* Message Sub: SessionControlRequest */
typedef struct
{
    /*服务id：0x10*/
    uint8_t ServiceId;
    /*会话类型*/
    uint8_t Type;
}IPC_M2S_EOLQNXSessionControlRequest_t;

/* Transmit function of sub message SessionControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EOLQNXSessionControlRequest_Transmit(IPC_M2S_EOLQNXSessionControlRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DidReadRequest */
typedef struct
{
    /*服务id：0x22*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_M2S_EOLQNXDidReadRequest_t;

/* Transmit function of sub message DidReadRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EOLQNXDidReadRequest_Transmit(IPC_M2S_EOLQNXDidReadRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DidWriteRequest */
typedef struct
{
    uint16_t PayloadLength;
    /*服务id：0x2E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
    /*数据*/
    uint8_t Payload[50];
}IPC_M2S_EOLQNXDidWriteRequest_t;

/* Transmit function of sub message DidWriteRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EOLQNXDidWriteRequest_Transmit(IPC_M2S_EOLQNXDidWriteRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: RoutineControlRequest */
typedef struct
{
    uint16_t OptionLength;
    /*服务id：0x31*/
    uint8_t ServiceId;
    /*例程类型*/
    uint8_t Type;
    /*例程id*/
    uint16_t RoutineId;
    /*选项*/
    uint8_t Option[50];
}IPC_M2S_EOLQNXRoutineControlRequest_t;

/* Transmit function of sub message RoutineControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EOLQNXRoutineControlRequest_Transmit(IPC_M2S_EOLQNXRoutineControlRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : EOL */
/* Message Major: IVI */
/* Message Sub: SessionControlRequest */
typedef struct
{
    /*服务id：0x10*/
    uint8_t ServiceId;
    /*会话类型*/
    uint8_t Type;
}IPC_M2S_EOLIVISessionControlRequest_t;

/* Transmit function of sub message SessionControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EOLIVISessionControlRequest_Transmit(IPC_M2S_EOLIVISessionControlRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DidReadRequest */
typedef struct
{
    /*服务id：0x22*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_M2S_EOLIVIDidReadRequest_t;

/* Transmit function of sub message DidReadRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EOLIVIDidReadRequest_Transmit(IPC_M2S_EOLIVIDidReadRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DidWriteRequest */
typedef struct
{
    uint16_t PayloadLength;
    /*服务id：0x2E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
    /*数据*/
    uint8_t Payload[50];
}IPC_M2S_EOLIVIDidWriteRequest_t;

/* Transmit function of sub message DidWriteRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EOLIVIDidWriteRequest_Transmit(IPC_M2S_EOLIVIDidWriteRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: RoutineControlRequest */
typedef struct
{
    uint16_t OptionLength;
    /*服务id：0x31*/
    uint8_t ServiceId;
    /*例程类型*/
    uint8_t Type;
    /*例程id*/
    uint16_t RoutineId;
    /*选项*/
    uint8_t Option[50];
}IPC_M2S_EOLIVIRoutineControlRequest_t;

/* Transmit function of sub message RoutineControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_EOLIVIRoutineControlRequest_Transmit(IPC_M2S_EOLIVIRoutineControlRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : EOL */
/* Group: : EOL */
/* Message Major: QNX */
/* Message Sub: SessionControlResponse */
typedef struct
{
    /*服务id：0x50*/
    uint8_t ServiceId;
    /*会话类型*/
    uint8_t Type;
}IPC_S2M_EOLQNXSessionControlResponse_t;

/* Receive function of sub message SessionControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EOLQNXSessionControlResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLQNXSessionControlResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DidReadResponse */
typedef struct
{
    uint16_t DataLength;
    /*服务id：0x62*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
    /*数据*/
    uint8_t Data[50];
}IPC_S2M_EOLQNXDidReadResponse_t;

/* Receive function of sub message DidReadResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EOLQNXDidReadResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLQNXDidReadResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DidWriteResponse */
typedef struct
{
    /*服务id：0x6E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_S2M_EOLQNXDidWriteResponse_t;

/* Receive function of sub message DidWriteResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EOLQNXDidWriteResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLQNXDidWriteResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: RoutineControlResponse */
typedef struct
{
    uint16_t StateLength;
    /*服务id：0x71*/
    uint8_t ServiceId;
    /*例程类型*/
    uint8_t Type;
    /*例程id*/
    uint16_t RoutineId;
    /*状态*/
    uint8_t State[50];
}IPC_S2M_EOLQNXRoutineControlResponse_t;

/* Receive function of sub message RoutineControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EOLQNXRoutineControlResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLQNXRoutineControlResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : EOL */
/* Message Major: IVI */
/* Message Sub: SessionControlResponse */
typedef struct
{
    /*服务id：0x50*/
    uint8_t ServiceId;
    /*会话类型*/
    uint8_t Type;
}IPC_S2M_EOLIVISessionControlResponse_t;

/* Receive function of sub message SessionControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EOLIVISessionControlResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLIVISessionControlResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DidReadResponse */
typedef struct
{
    uint16_t DataLength;
    /*服务id：0x62*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
    /*数据*/
    uint8_t Data[50];
}IPC_S2M_EOLIVIDidReadResponse_t;

/* Receive function of sub message DidReadResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EOLIVIDidReadResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLIVIDidReadResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DidWriteResponse */
typedef struct
{
    /*服务id：0x6E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_S2M_EOLIVIDidWriteResponse_t;

/* Receive function of sub message DidWriteResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EOLIVIDidWriteResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLIVIDidWriteResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: RoutineControlResponse */
typedef struct
{
    uint16_t StateLength;
    /*服务id：0x71*/
    uint8_t ServiceId;
    /*例程类型*/
    uint8_t Type;
    /*例程id*/
    uint16_t RoutineId;
    /*状态*/
    uint8_t State[50];
}IPC_S2M_EOLIVIRoutineControlResponse_t;

/* Receive function of sub message RoutineControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_EOLIVIRoutineControlResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLIVIRoutineControlResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : EOL */
#ifdef __cplusplus
}
#endif

#endif
