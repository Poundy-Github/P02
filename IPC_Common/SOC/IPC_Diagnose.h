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
*                 File:  IPC_Diagnose.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_SOC.h.tem
*          Description:  IPC group Diagnose  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_DIAGNOSE_H_
#define _IPC_DIAGNOSE_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_DIAGNOSE_ID                                                    (5u)

/* MCU to SOC Message major id */
#define IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID                                         (0u)
#define IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID                                         (1u)
/* MCU to SOC Message sub id */
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_ID                     (0u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_ID                            (1u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_ID                           (2u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_ID                          (3u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_ID                     (4u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_ID                       (5u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_ID                          (6u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_ID                     (0u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_ID                            (1u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_ID                           (2u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_ID                          (3u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_ID                     (4u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_ID                       (5u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_ID                          (6u)
/* MCU to SOC Message sub length */
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH                 (2u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_LENGTH                        (3u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH                       (55u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN                   (5u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER                  (50u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH                      (14u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN                  (6u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_FLEX_NUMBER                 (8u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH                 (16u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN             (6u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER            (10u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_LENGTH                   (4u)
#define IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_LENGTH                      (2u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH                 (2u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_LENGTH                        (3u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH                       (508u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN                   (8u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER                  (500u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH                      (14u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN                  (6u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_FLEX_NUMBER                 (8u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH                 (16u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN             (6u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER            (10u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_LENGTH                   (4u)
#define IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_LENGTH                      (2u)
/* SOC to MCU Message major id */
#define IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID                                         (0u)
#define IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID                                         (1u)
/* SOC to MCU Message sub id */
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_ID                    (0u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_ID                           (1u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_ID                          (2u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_ID                         (3u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_ID                    (4u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_ID                        (5u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_DTCREINITRESPONSE_ID                         (6u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLRESPONSE_ID                    (0u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_ID                           (1u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_ID                          (2u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_IOCONTROLRESPONSE_ID                         (3u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_ID                    (4u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_ID                        (5u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_DTCREINITRESPONSE_ID                         (6u)
/* SOC to MCU Message sub length */
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH                (2u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH                       (305u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN                   (5u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER                  (300u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH                      (3u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_LENGTH                     (8u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH                (16u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN            (6u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER           (10u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_LENGTH                    (5u)
#define IPC_S2M_DIAGNOSE_QNX_MSGSUB_DTCREINITRESPONSE_LENGTH                     (2u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH                (2u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH                       (508u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN                   (8u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER                  (500u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH                      (3u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_IOCONTROLRESPONSE_LENGTH                     (8u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH                (26u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN            (6u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER           (10u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_LENGTH                    (5u)
#define IPC_S2M_DIAGNOSE_IVI_MSGSUB_DTCREINITRESPONSE_LENGTH                     (2u)
/* Group: : Diagnose */
/* Message Major: QNX */
/* Message Sub: SessionControlRequest */
typedef struct
{
    /*服务id：0x10*/
    uint8_t ServiceId;
    /*会话类型*/
    uint8_t Type;
}IPC_M2S_DiagnoseQNXSessionControlRequest_t;

/* Pack function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseQNXSessionControlRequest_Pack(IPC_M2S_DiagnoseQNXSessionControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseQNXSessionControlRequest_Parse(IPC_M2S_DiagnoseQNXSessionControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidReadRequest */
typedef struct
{
    /*服务id：0x22*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_M2S_DiagnoseQNXDidReadRequest_t;

/* Pack function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseQNXDidReadRequest_Pack(IPC_M2S_DiagnoseQNXDidReadRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseQNXDidReadRequest_Parse(IPC_M2S_DiagnoseQNXDidReadRequest_t *data, uint8_t *payload, uint16_t length);

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
}IPC_M2S_DiagnoseQNXDidWriteRequest_t;

/* Pack function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseQNXDidWriteRequest_Pack(IPC_M2S_DiagnoseQNXDidWriteRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseQNXDidWriteRequest_Parse(IPC_M2S_DiagnoseQNXDidWriteRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: IoControlRequest */
typedef struct
{
    uint16_t StateAndMaskLength;
    /*服务id：0x2F*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t DataId;
    /*控制参数*/
    uint8_t Parameter;
    /*状态和掩码*/
    uint8_t StateAndMask[8];
}IPC_M2S_DiagnoseQNXIoControlRequest_t;

/* Pack function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseQNXIoControlRequest_Pack(IPC_M2S_DiagnoseQNXIoControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseQNXIoControlRequest_Parse(IPC_M2S_DiagnoseQNXIoControlRequest_t *data, uint8_t *payload, uint16_t length);

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
    uint8_t Option[10];
}IPC_M2S_DiagnoseQNXRoutineControlRequest_t;

/* Pack function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseQNXRoutineControlRequest_Pack(IPC_M2S_DiagnoseQNXRoutineControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseQNXRoutineControlRequest_Parse(IPC_M2S_DiagnoseQNXRoutineControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: ReportEventResponse */
typedef struct
{
    /*服务id：0x70*/
    uint8_t ServiceId;
    /*DTC码*/
    uint8_t DtcCode[3];
}IPC_M2S_DiagnoseQNXReportEventResponse_t;

/* Pack function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseQNXReportEventResponse_Pack(IPC_M2S_DiagnoseQNXReportEventResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseQNXReportEventResponse_Parse(IPC_M2S_DiagnoseQNXReportEventResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DtcReinitRequest */
typedef struct
{
    /*服务id：0x14*/
    uint8_t ServiceId;
    /*类型*/
    uint8_t Type;
}IPC_M2S_DiagnoseQNXDtcReinitRequest_t;

/* Pack function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseQNXDtcReinitRequest_Pack(IPC_M2S_DiagnoseQNXDtcReinitRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseQNXDtcReinitRequest_Parse(IPC_M2S_DiagnoseQNXDtcReinitRequest_t *data, uint8_t *payload, uint16_t length);

/* Group: : Diagnose */
/* Message Major: IVI */
/* Message Sub: SessionControlRequest */
typedef struct
{
    /*服务id：0x10*/
    uint8_t ServiceId;
    /*会话类型*/
    uint8_t Type;
}IPC_M2S_DiagnoseIVISessionControlRequest_t;

/* Pack function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseIVISessionControlRequest_Pack(IPC_M2S_DiagnoseIVISessionControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseIVISessionControlRequest_Parse(IPC_M2S_DiagnoseIVISessionControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidReadRequest */
typedef struct
{
    /*服务id：0x22*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_M2S_DiagnoseIVIDidReadRequest_t;

/* Pack function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseIVIDidReadRequest_Pack(IPC_M2S_DiagnoseIVIDidReadRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseIVIDidReadRequest_Parse(IPC_M2S_DiagnoseIVIDidReadRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidWriteRequest */
typedef struct
{
    uint16_t PayloadLength;
    /*服务id：0x2E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
    /*总包长*/
    uint16_t TotalLenth;
    /*包的序列号*/
    uint8_t number;
    /*数据*/
    uint8_t Payload[500];
}IPC_M2S_DiagnoseIVIDidWriteRequest_t;

/* Pack function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseIVIDidWriteRequest_Pack(IPC_M2S_DiagnoseIVIDidWriteRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseIVIDidWriteRequest_Parse(IPC_M2S_DiagnoseIVIDidWriteRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: IoControlRequest */
typedef struct
{
    uint16_t StateAndMaskLength;
    /*服务id：0x2F*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t DataId;
    /*控制参数*/
    uint8_t Parameter;
    /*状态和掩码*/
    uint8_t StateAndMask[8];
}IPC_M2S_DiagnoseIVIIoControlRequest_t;

/* Pack function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseIVIIoControlRequest_Pack(IPC_M2S_DiagnoseIVIIoControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseIVIIoControlRequest_Parse(IPC_M2S_DiagnoseIVIIoControlRequest_t *data, uint8_t *payload, uint16_t length);

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
    uint8_t Option[10];
}IPC_M2S_DiagnoseIVIRoutineControlRequest_t;

/* Pack function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseIVIRoutineControlRequest_Pack(IPC_M2S_DiagnoseIVIRoutineControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseIVIRoutineControlRequest_Parse(IPC_M2S_DiagnoseIVIRoutineControlRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: ReportEventResponse */
typedef struct
{
    /*服务id：0x70*/
    uint8_t ServiceId;
    uint8_t DtcCode[3];
}IPC_M2S_DiagnoseIVIReportEventResponse_t;

/* Pack function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseIVIReportEventResponse_Pack(IPC_M2S_DiagnoseIVIReportEventResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseIVIReportEventResponse_Parse(IPC_M2S_DiagnoseIVIReportEventResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DtcReinitRequest */
typedef struct
{
    /*服务id：0x14*/
    uint8_t ServiceId;
    /*类型*/
    uint8_t Type;
}IPC_M2S_DiagnoseIVIDtcReinitRequest_t;

/* Pack function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseIVIDtcReinitRequest_Pack(IPC_M2S_DiagnoseIVIDtcReinitRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseIVIDtcReinitRequest_Parse(IPC_M2S_DiagnoseIVIDtcReinitRequest_t *data, uint8_t *payload, uint16_t length);

/* Group: : Diagnose */
/* Group: : Diagnose */
/* Message Major: QNX */
/* Message Sub: SessionControlResponse */
typedef struct
{
    /*服务id：0x50*/
    uint8_t ServiceId;
    /*会话类型*/
    uint8_t Type;
}IPC_S2M_DiagnoseQNXSessionControlResponse_t;

/* Pack function of sub message SessionControlResponse */
int32_t IPC_S2M_DiagnoseQNXSessionControlResponse_Pack(IPC_S2M_DiagnoseQNXSessionControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SessionControlResponse */
int32_t IPC_S2M_DiagnoseQNXSessionControlResponse_Parse(IPC_S2M_DiagnoseQNXSessionControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidReadResponse */
typedef struct
{
    uint16_t DataLength;
    /*服务id：0x62*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
    /*数据*/
    uint8_t Data[300];
}IPC_S2M_DiagnoseQNXDidReadResponse_t;

/* Pack function of sub message DidReadResponse */
int32_t IPC_S2M_DiagnoseQNXDidReadResponse_Pack(IPC_S2M_DiagnoseQNXDidReadResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidReadResponse */
int32_t IPC_S2M_DiagnoseQNXDidReadResponse_Parse(IPC_S2M_DiagnoseQNXDidReadResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidWriteResponse */
typedef struct
{
    /*服务id：0x6E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_S2M_DiagnoseQNXDidWriteResponse_t;

/* Pack function of sub message DidWriteResponse */
int32_t IPC_S2M_DiagnoseQNXDidWriteResponse_Pack(IPC_S2M_DiagnoseQNXDidWriteResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidWriteResponse */
int32_t IPC_S2M_DiagnoseQNXDidWriteResponse_Parse(IPC_S2M_DiagnoseQNXDidWriteResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: IoControlResponse */
typedef struct
{
    /*服务id：0x6F*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t DataId;
    /*控制参数*/
    uint8_t Parameter;
    /*状态*/
    uint8_t State[4];
}IPC_S2M_DiagnoseQNXIoControlResponse_t;

/* Pack function of sub message IoControlResponse */
int32_t IPC_S2M_DiagnoseQNXIoControlResponse_Pack(IPC_S2M_DiagnoseQNXIoControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IoControlResponse */
int32_t IPC_S2M_DiagnoseQNXIoControlResponse_Parse(IPC_S2M_DiagnoseQNXIoControlResponse_t *data, uint8_t *payload, uint16_t length);

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
    uint8_t State[10];
}IPC_S2M_DiagnoseQNXRoutineControlResponse_t;

/* Pack function of sub message RoutineControlResponse */
int32_t IPC_S2M_DiagnoseQNXRoutineControlResponse_Pack(IPC_S2M_DiagnoseQNXRoutineControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RoutineControlResponse */
int32_t IPC_S2M_DiagnoseQNXRoutineControlResponse_Parse(IPC_S2M_DiagnoseQNXRoutineControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: ReportEventRequest */
typedef struct
{
    /*服务id：0x30*/
    uint8_t ServiceId;
    /*DTC码*/
    uint8_t DtcCode[3];
    /*DTC测试结果*/
    uint8_t Result;
}IPC_S2M_DiagnoseQNXReportEventRequest_t;

/* Pack function of sub message ReportEventRequest */
int32_t IPC_S2M_DiagnoseQNXReportEventRequest_Pack(IPC_S2M_DiagnoseQNXReportEventRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ReportEventRequest */
int32_t IPC_S2M_DiagnoseQNXReportEventRequest_Parse(IPC_S2M_DiagnoseQNXReportEventRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DtcReinitResponse */
typedef struct
{
    /*服务id：0x54*/
    uint8_t ServiceId;
    /*类型*/
    uint8_t Type;
}IPC_S2M_DiagnoseQNXDtcReinitResponse_t;

/* Pack function of sub message DtcReinitResponse */
int32_t IPC_S2M_DiagnoseQNXDtcReinitResponse_Pack(IPC_S2M_DiagnoseQNXDtcReinitResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DtcReinitResponse */
int32_t IPC_S2M_DiagnoseQNXDtcReinitResponse_Parse(IPC_S2M_DiagnoseQNXDtcReinitResponse_t *data, uint8_t *payload, uint16_t length);

/* Group: : Diagnose */
/* Message Major: IVI */
/* Message Sub: SessionControlResponse */
typedef struct
{
    /*服务id：0x50*/
    uint8_t ServiceId;
    /*会话类型*/
    uint8_t Type;
}IPC_S2M_DiagnoseIVISessionControlResponse_t;

/* Pack function of sub message SessionControlResponse */
int32_t IPC_S2M_DiagnoseIVISessionControlResponse_Pack(IPC_S2M_DiagnoseIVISessionControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SessionControlResponse */
int32_t IPC_S2M_DiagnoseIVISessionControlResponse_Parse(IPC_S2M_DiagnoseIVISessionControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidReadResponse */
typedef struct
{
    uint16_t DataLength;
    /*服务id：0x62*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
    /*总包长*/
    uint16_t TotalLength;
    /*包序列号*/
    uint8_t Number;
    /*数据*/
    uint8_t Data[500];
}IPC_S2M_DiagnoseIVIDidReadResponse_t;

/* Pack function of sub message DidReadResponse */
int32_t IPC_S2M_DiagnoseIVIDidReadResponse_Pack(IPC_S2M_DiagnoseIVIDidReadResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidReadResponse */
int32_t IPC_S2M_DiagnoseIVIDidReadResponse_Parse(IPC_S2M_DiagnoseIVIDidReadResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DidWriteResponse */
typedef struct
{
    /*服务id：0x6E*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t Did;
}IPC_S2M_DiagnoseIVIDidWriteResponse_t;

/* Pack function of sub message DidWriteResponse */
int32_t IPC_S2M_DiagnoseIVIDidWriteResponse_Pack(IPC_S2M_DiagnoseIVIDidWriteResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DidWriteResponse */
int32_t IPC_S2M_DiagnoseIVIDidWriteResponse_Parse(IPC_S2M_DiagnoseIVIDidWriteResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: IoControlResponse */
typedef struct
{
    /*服务id：0x6F*/
    uint8_t ServiceId;
    /*数据id*/
    uint16_t DataId;
    /*控制参数*/
    uint8_t Parameter;
    /*状态和掩码*/
    uint8_t State[4];
}IPC_S2M_DiagnoseIVIIoControlResponse_t;

/* Pack function of sub message IoControlResponse */
int32_t IPC_S2M_DiagnoseIVIIoControlResponse_Pack(IPC_S2M_DiagnoseIVIIoControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IoControlResponse */
int32_t IPC_S2M_DiagnoseIVIIoControlResponse_Parse(IPC_S2M_DiagnoseIVIIoControlResponse_t *data, uint8_t *payload, uint16_t length);

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
    uint16_t State[10];
}IPC_S2M_DiagnoseIVIRoutineControlResponse_t;

/* Pack function of sub message RoutineControlResponse */
int32_t IPC_S2M_DiagnoseIVIRoutineControlResponse_Pack(IPC_S2M_DiagnoseIVIRoutineControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RoutineControlResponse */
int32_t IPC_S2M_DiagnoseIVIRoutineControlResponse_Parse(IPC_S2M_DiagnoseIVIRoutineControlResponse_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: ReportEventRequest */
typedef struct
{
    /*服务id：0x70*/
    uint8_t ServiceId;
    /*DTC码*/
    uint8_t DtcCode[3];
    /*DTC测试结果*/
    uint8_t Result;
}IPC_S2M_DiagnoseIVIReportEventRequest_t;

/* Pack function of sub message ReportEventRequest */
int32_t IPC_S2M_DiagnoseIVIReportEventRequest_Pack(IPC_S2M_DiagnoseIVIReportEventRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ReportEventRequest */
int32_t IPC_S2M_DiagnoseIVIReportEventRequest_Parse(IPC_S2M_DiagnoseIVIReportEventRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: DtcReinitResponse */
typedef struct
{
    /*服务id：0x54 负反馈0x7F*/
    uint8_t ServiceId;
    /*类型*/
    uint8_t Type;
}IPC_S2M_DiagnoseIVIDtcReinitResponse_t;

/* Pack function of sub message DtcReinitResponse */
int32_t IPC_S2M_DiagnoseIVIDtcReinitResponse_Pack(IPC_S2M_DiagnoseIVIDtcReinitResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DtcReinitResponse */
int32_t IPC_S2M_DiagnoseIVIDtcReinitResponse_Parse(IPC_S2M_DiagnoseIVIDtcReinitResponse_t *data, uint8_t *payload, uint16_t length);

/* Group: : Diagnose */
#ifdef __cplusplus
}
#endif

#endif
