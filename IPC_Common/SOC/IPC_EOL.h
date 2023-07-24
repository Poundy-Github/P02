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
*     Description file:  IPC_SOC.h.tem
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

/* Pack function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLQNXSessionControlRequest_Pack(IPC_M2S_EOLQNXSessionControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLQNXSessionControlRequest_Parse(IPC_M2S_EOLQNXSessionControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidReadRequest */
typedef struct
{
    /*服务id：0x22*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_M2S_EOLQNXDidReadRequest_t;

/* Pack function of sub message DidReadRequest */
int32_t IPC_M2S_EOLQNXDidReadRequest_Pack(IPC_M2S_EOLQNXDidReadRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidReadRequest */
int32_t IPC_M2S_EOLQNXDidReadRequest_Parse(IPC_M2S_EOLQNXDidReadRequest_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLQNXDidWriteRequest_Pack(IPC_M2S_EOLQNXDidWriteRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLQNXDidWriteRequest_Parse(IPC_M2S_EOLQNXDidWriteRequest_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLQNXRoutineControlRequest_Pack(IPC_M2S_EOLQNXRoutineControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLQNXRoutineControlRequest_Parse(IPC_M2S_EOLQNXRoutineControlRequest_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLIVISessionControlRequest_Pack(IPC_M2S_EOLIVISessionControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLIVISessionControlRequest_Parse(IPC_M2S_EOLIVISessionControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidReadRequest */
typedef struct
{
    /*服务id：0x22*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_M2S_EOLIVIDidReadRequest_t;

/* Pack function of sub message DidReadRequest */
int32_t IPC_M2S_EOLIVIDidReadRequest_Pack(IPC_M2S_EOLIVIDidReadRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidReadRequest */
int32_t IPC_M2S_EOLIVIDidReadRequest_Parse(IPC_M2S_EOLIVIDidReadRequest_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLIVIDidWriteRequest_Pack(IPC_M2S_EOLIVIDidWriteRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLIVIDidWriteRequest_Parse(IPC_M2S_EOLIVIDidWriteRequest_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLIVIRoutineControlRequest_Pack(IPC_M2S_EOLIVIRoutineControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLIVIRoutineControlRequest_Parse(IPC_M2S_EOLIVIRoutineControlRequest_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message SessionControlResponse */
int32_t IPC_S2M_EOLQNXSessionControlResponse_Pack(IPC_S2M_EOLQNXSessionControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SessionControlResponse */
int32_t IPC_S2M_EOLQNXSessionControlResponse_Parse(IPC_S2M_EOLQNXSessionControlResponse_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message DidReadResponse */
int32_t IPC_S2M_EOLQNXDidReadResponse_Pack(IPC_S2M_EOLQNXDidReadResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidReadResponse */
int32_t IPC_S2M_EOLQNXDidReadResponse_Parse(IPC_S2M_EOLQNXDidReadResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidWriteResponse */
typedef struct
{
    /*服务id：0x6E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_S2M_EOLQNXDidWriteResponse_t;

/* Pack function of sub message DidWriteResponse */
int32_t IPC_S2M_EOLQNXDidWriteResponse_Pack(IPC_S2M_EOLQNXDidWriteResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidWriteResponse */
int32_t IPC_S2M_EOLQNXDidWriteResponse_Parse(IPC_S2M_EOLQNXDidWriteResponse_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message RoutineControlResponse */
int32_t IPC_S2M_EOLQNXRoutineControlResponse_Pack(IPC_S2M_EOLQNXRoutineControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RoutineControlResponse */
int32_t IPC_S2M_EOLQNXRoutineControlResponse_Parse(IPC_S2M_EOLQNXRoutineControlResponse_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message SessionControlResponse */
int32_t IPC_S2M_EOLIVISessionControlResponse_Pack(IPC_S2M_EOLIVISessionControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SessionControlResponse */
int32_t IPC_S2M_EOLIVISessionControlResponse_Parse(IPC_S2M_EOLIVISessionControlResponse_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message DidReadResponse */
int32_t IPC_S2M_EOLIVIDidReadResponse_Pack(IPC_S2M_EOLIVIDidReadResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidReadResponse */
int32_t IPC_S2M_EOLIVIDidReadResponse_Parse(IPC_S2M_EOLIVIDidReadResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidWriteResponse */
typedef struct
{
    /*服务id：0x6E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_S2M_EOLIVIDidWriteResponse_t;

/* Pack function of sub message DidWriteResponse */
int32_t IPC_S2M_EOLIVIDidWriteResponse_Pack(IPC_S2M_EOLIVIDidWriteResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidWriteResponse */
int32_t IPC_S2M_EOLIVIDidWriteResponse_Parse(IPC_S2M_EOLIVIDidWriteResponse_t *data, uint8_t *payload, uint16_t length);

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

/* Pack function of sub message RoutineControlResponse */
int32_t IPC_S2M_EOLIVIRoutineControlResponse_Pack(IPC_S2M_EOLIVIRoutineControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RoutineControlResponse */
int32_t IPC_S2M_EOLIVIRoutineControlResponse_Parse(IPC_S2M_EOLIVIRoutineControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Group: : EOL */
#ifdef __cplusplus
}
#endif

#endif
