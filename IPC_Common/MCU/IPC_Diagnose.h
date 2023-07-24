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
*     Description file:  IPC_MCU.h.tem
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

/* Transmit function of sub message SessionControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseQNXSessionControlRequest_Transmit(IPC_M2S_DiagnoseQNXSessionControlRequest_t *data);

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
}IPC_M2S_DiagnoseQNXDidReadRequest_t;

/* Transmit function of sub message DidReadRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseQNXDidReadRequest_Transmit(IPC_M2S_DiagnoseQNXDidReadRequest_t *data);

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
}IPC_M2S_DiagnoseQNXDidWriteRequest_t;

/* Transmit function of sub message DidWriteRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseQNXDidWriteRequest_Transmit(IPC_M2S_DiagnoseQNXDidWriteRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Transmit function of sub message IoControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseQNXIoControlRequest_Transmit(IPC_M2S_DiagnoseQNXIoControlRequest_t *data);

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
    uint8_t Option[10];
}IPC_M2S_DiagnoseQNXRoutineControlRequest_t;

/* Transmit function of sub message RoutineControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseQNXRoutineControlRequest_Transmit(IPC_M2S_DiagnoseQNXRoutineControlRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ReportEventResponse */
typedef struct
{
    /*服务id：0x70*/
    uint8_t ServiceId;
    /*DTC码*/
    uint8_t DtcCode[3];
}IPC_M2S_DiagnoseQNXReportEventResponse_t;

/* Transmit function of sub message ReportEventResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseQNXReportEventResponse_Transmit(IPC_M2S_DiagnoseQNXReportEventResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DtcReinitRequest */
typedef struct
{
    /*服务id：0x14*/
    uint8_t ServiceId;
    /*类型*/
    uint8_t Type;
}IPC_M2S_DiagnoseQNXDtcReinitRequest_t;

/* Transmit function of sub message DtcReinitRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseQNXDtcReinitRequest_Transmit(IPC_M2S_DiagnoseQNXDtcReinitRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Transmit function of sub message SessionControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseIVISessionControlRequest_Transmit(IPC_M2S_DiagnoseIVISessionControlRequest_t *data);

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
}IPC_M2S_DiagnoseIVIDidReadRequest_t;

/* Transmit function of sub message DidReadRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseIVIDidReadRequest_Transmit(IPC_M2S_DiagnoseIVIDidReadRequest_t *data);

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
    /*总包长*/
    uint16_t TotalLenth;
    /*包的序列号*/
    uint8_t number;
    /*数据*/
    uint8_t Payload[500];
}IPC_M2S_DiagnoseIVIDidWriteRequest_t;

/* Transmit function of sub message DidWriteRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseIVIDidWriteRequest_Transmit(IPC_M2S_DiagnoseIVIDidWriteRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Transmit function of sub message IoControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseIVIIoControlRequest_Transmit(IPC_M2S_DiagnoseIVIIoControlRequest_t *data);

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
    uint8_t Option[10];
}IPC_M2S_DiagnoseIVIRoutineControlRequest_t;

/* Transmit function of sub message RoutineControlRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseIVIRoutineControlRequest_Transmit(IPC_M2S_DiagnoseIVIRoutineControlRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ReportEventResponse */
typedef struct
{
    /*服务id：0x70*/
    uint8_t ServiceId;
    uint8_t DtcCode[3];
}IPC_M2S_DiagnoseIVIReportEventResponse_t;

/* Transmit function of sub message ReportEventResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseIVIReportEventResponse_Transmit(IPC_M2S_DiagnoseIVIReportEventResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DtcReinitRequest */
typedef struct
{
    /*服务id：0x14*/
    uint8_t ServiceId;
    /*类型*/
    uint8_t Type;
}IPC_M2S_DiagnoseIVIDtcReinitRequest_t;

/* Transmit function of sub message DtcReinitRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_DiagnoseIVIDtcReinitRequest_Transmit(IPC_M2S_DiagnoseIVIDtcReinitRequest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message SessionControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseQNXSessionControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXSessionControlResponse_t *data, uint32_t payloadLength);
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
    uint8_t Data[300];
}IPC_S2M_DiagnoseQNXDidReadResponse_t;

/* Receive function of sub message DidReadResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseQNXDidReadResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXDidReadResponse_t *data, uint32_t payloadLength);
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
}IPC_S2M_DiagnoseQNXDidWriteResponse_t;

/* Receive function of sub message DidWriteResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseQNXDidWriteResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXDidWriteResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message IoControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseQNXIoControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXIoControlResponse_t *data, uint32_t payloadLength);
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
    uint8_t State[10];
}IPC_S2M_DiagnoseQNXRoutineControlResponse_t;

/* Receive function of sub message RoutineControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseQNXRoutineControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXRoutineControlResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message ReportEventRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseQNXReportEventRequest_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXReportEventRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DtcReinitResponse */
typedef struct
{
    /*服务id：0x54*/
    uint8_t ServiceId;
    /*类型*/
    uint8_t Type;
}IPC_S2M_DiagnoseQNXDtcReinitResponse_t;

/* Receive function of sub message DtcReinitResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseQNXDtcReinitResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXDtcReinitResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message SessionControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseIVISessionControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVISessionControlResponse_t *data, uint32_t payloadLength);
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
    /*总包长*/
    uint16_t TotalLength;
    /*包序列号*/
    uint8_t Number;
    /*数据*/
    uint8_t Data[500];
}IPC_S2M_DiagnoseIVIDidReadResponse_t;

/* Receive function of sub message DidReadResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseIVIDidReadResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIDidReadResponse_t *data, uint32_t payloadLength);
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
}IPC_S2M_DiagnoseIVIDidWriteResponse_t;

/* Receive function of sub message DidWriteResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseIVIDidWriteResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIDidWriteResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message IoControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseIVIIoControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIIoControlResponse_t *data, uint32_t payloadLength);
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
    uint16_t State[10];
}IPC_S2M_DiagnoseIVIRoutineControlResponse_t;

/* Receive function of sub message RoutineControlResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseIVIRoutineControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIRoutineControlResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message ReportEventRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseIVIReportEventRequest_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIReportEventRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DtcReinitResponse */
typedef struct
{
    /*服务id：0x54 负反馈0x7F*/
    uint8_t ServiceId;
    /*类型*/
    uint8_t Type;
}IPC_S2M_DiagnoseIVIDtcReinitResponse_t;

/* Receive function of sub message DtcReinitResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_DiagnoseIVIDtcReinitResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIDtcReinitResponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Diagnose */
#ifdef __cplusplus
}
#endif

#endif
