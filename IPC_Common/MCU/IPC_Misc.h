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
*                 File:  IPC_Misc.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group Misc  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_MISC_H_
#define _IPC_MISC_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_MISC_ID                                                        (10u)

/* MCU to SOC Message major id */
#define IPC_M2S_MISC_MSGMAJOR_RTC_ID                                             (0u)
#define IPC_M2S_MISC_MSGMAJOR_SERVICE_ID                                         (1u)
#define IPC_M2S_MISC_MSGMAJOR_IVIINFO_ID                                         (2u)
/* MCU to SOC Message sub id */
#define IPC_M2S_MISC_RTC_MSGSUB_ACK_ID                                           (0u)
#define IPC_M2S_MISC_RTC_MSGSUB_TIME_ID                                          (1u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_ID                                     (0u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_ID                                   (1u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_ID                                (2u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_ID                                (3u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_ID                                   (4u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_ID                                    (5u)
#define IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_ID                           (0u)
#define IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_ID                          (1u)
/* MCU to SOC Message sub length */
#define IPC_M2S_MISC_RTC_MSGSUB_ACK_LENGTH                                       (1u)
#define IPC_M2S_MISC_RTC_MSGSUB_TIME_LENGTH                                      (8u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_LENGTH                                 (1u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_LENGTH                               (200u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_LENGTH                            (3u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_LENGTH                            (1u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_LENGTH                               (300u)
#define IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_LENGTH                                (8u)
#define IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_LENGTH                       (4u)
#define IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_LENGTH                      (4u)


/* SOC to MCU Message major id */
#define IPC_S2M_MISC_MSGMAJOR_RTC_ID                                             (0u)
#define IPC_S2M_MISC_MSGMAJOR_SERVICE_ID                                         (1u)
#define IPC_S2M_MISC_MSGMAJOR_IVIINFO_ID                                         (2u)
/* SOC to MCU Message sub id */
#define IPC_S2M_MISC_RTC_MSGSUB_GET_TIME_REQUEST_ID                              (0u)
#define IPC_S2M_MISC_RTC_MSGSUB_SET_TIME_REQUEST_ID                              (1u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_WIRTCHANNEL_ID                               (0u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_GET_VCONFIG_ID                               (1u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_REPONSE_ID                           (2u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_CHECKTRIGGERMSG_ID                           (3u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_CCONFIG_RESPONSE_ID                          (4u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_USB_ID                               (5u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_GET_CCONFIG_ID                               (6u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_GET_OFFSET_ID                                (7u)
#define IPC_S2M_MISC_IVIINFO_MSGSUB_READDRVMODEREQ_ID                            (0u)
#define IPC_S2M_MISC_IVIINFO_MSGSUB_WRITEDRVMODEREQ_ID                           (1u)
/* SOC to MCU Message sub length */
#define IPC_S2M_MISC_RTC_MSGSUB_GET_TIME_REQUEST_LENGTH                          (1u)
#define IPC_S2M_MISC_RTC_MSGSUB_SET_TIME_REQUEST_LENGTH                          (8u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_WIRTCHANNEL_LENGTH                           (2u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_GET_VCONFIG_LENGTH                           (1u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_REPONSE_LENGTH                       (1u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_CHECKTRIGGERMSG_LENGTH                       (1u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_CCONFIG_RESPONSE_LENGTH                      (1u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_USB_LENGTH                           (200u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_GET_CCONFIG_LENGTH                           (1u)
#define IPC_S2M_MISC_SERVICE_MSGSUB_GET_OFFSET_LENGTH                            (1u)
#define IPC_S2M_MISC_IVIINFO_MSGSUB_READDRVMODEREQ_LENGTH                        (3u)
#define IPC_S2M_MISC_IVIINFO_MSGSUB_WRITEDRVMODEREQ_LENGTH                       (4u)
/* Group: : Misc */
/* Message Major: RTC */
/* Message Sub: ACK */
typedef struct
{
    /*0 ok;1 not ok*/
    uint8_t States;
}IPC_M2S_MiscRTCACK_t;

/* Transmit function of sub message ACK */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscRTCACK_Transmit(IPC_M2S_MiscRTCACK_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TIME */
typedef struct
{
    uint64_t UTC_Time;
}IPC_M2S_MiscRTCTIME_t;

/* Transmit function of sub message TIME */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscRTCTIME_Transmit(IPC_M2S_MiscRTCTIME_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Misc */
/* Message Major: Service */
/* Message Sub: Reply */
typedef struct
{
    uint8_t u8Channel;
}IPC_M2S_MiscServiceReply_t;

/* Transmit function of sub message Reply */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscServiceReply_Transmit(IPC_M2S_MiscServiceReply_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Vconfig */
typedef struct
{
    uint8_t Vconfig_Buffer[200];
}IPC_M2S_MiscServiceVconfig_t;

/* Transmit function of sub message Vconfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscServiceVconfig_Transmit(IPC_M2S_MiscServiceVconfig_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TriggerMsg */
typedef struct
{
    /*[TriggerSource] 0:Tuber Debug [Value] 0:Debug Mode;1: Normal mode.*/
    uint8_t TriggerSource;
    uint16_t Value;
}IPC_M2S_MiscServiceTriggerMsg_t;

/* Transmit function of sub message TriggerMsg */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscServiceTriggerMsg_Transmit(IPC_M2S_MiscServiceTriggerMsg_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Vreply_Usb */
typedef struct
{
    uint8_t u8Channel;
}IPC_M2S_MiscServiceVreply_Usb_t;

/* Transmit function of sub message Vreply_Usb */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscServiceVreply_Usb_Transmit(IPC_M2S_MiscServiceVreply_Usb_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Cconfig */
typedef struct
{
    uint8_t Cconfig_Buffer[300];
}IPC_M2S_MiscServiceCconfig_t;

/* Transmit function of sub message Cconfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscServiceCconfig_Transmit(IPC_M2S_MiscServiceCconfig_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Offset */
typedef struct
{
    uint8_t Offset_Buffer[8];
}IPC_M2S_MiscServiceOffset_t;

/* Transmit function of sub message Offset */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscServiceOffset_Transmit(IPC_M2S_MiscServiceOffset_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Misc */
/* Message Major: IVIInfo */
/* Message Sub: ReadDrvModeResp */
typedef struct
{
    uint8_t ModuleID;
    uint16_t InfoID;
    uint8_t Switch;
}IPC_M2S_MiscIVIInfoReadDrvModeResp_t;

/* Transmit function of sub message ReadDrvModeResp */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscIVIInfoReadDrvModeResp_Transmit(IPC_M2S_MiscIVIInfoReadDrvModeResp_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: WriteDrvModeResp */
typedef struct
{
    uint8_t ModuleID;
    uint16_t InfoID;
    /*0:Success
    1:Faild*/
    uint8_t Result;
}IPC_M2S_MiscIVIInfoWriteDrvModeResp_t;

/* Transmit function of sub message WriteDrvModeResp */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_MiscIVIInfoWriteDrvModeResp_Transmit(IPC_M2S_MiscIVIInfoWriteDrvModeResp_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Misc */
/* Group: : Misc */
/* Message Major: RTC */
/* Message Sub: Get_Time_Request */
typedef struct
{
    uint8_t Reserve;
}IPC_S2M_MiscRTCGet_Time_Request_t;

/* Receive function of sub message Get_Time_Request */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscRTCGet_Time_Request_Receive(uint8_t *receiveData, IPC_S2M_MiscRTCGet_Time_Request_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Set_Time_Request */
typedef struct
{
    uint64_t UTC_Time;
}IPC_S2M_MiscRTCSet_Time_Request_t;

/* Receive function of sub message Set_Time_Request */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscRTCSet_Time_Request_Receive(uint8_t *receiveData, IPC_S2M_MiscRTCSet_Time_Request_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Misc */
/* Message Major: Service */
/* Message Sub: WirtChannel */
typedef struct
{
    /*0: VIP_ID_EN_ODH
    1: VIP_CD_EN_ODH
    2: VIP_PD_EN_ODH
    3: VIP_469X_RST_3V3
    4: VIP_47961_RST_3V3
    5: VIP_479XX_RST_3V3
    6: VIP_4624_RST_3V3
    7: VIP_HD_EN_ODH*/
    uint8_t u8Channel;
    /*0: Low
    1: High*/
    uint8_t u8Level;
}IPC_S2M_MiscServiceWirtChannel_t;

/* Receive function of sub message WirtChannel */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscServiceWirtChannel_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceWirtChannel_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Get_Vconfig */
typedef struct
{
    uint8_t request;
}IPC_S2M_MiscServiceGet_Vconfig_t;

/* Receive function of sub message Get_Vconfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscServiceGet_Vconfig_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceGet_Vconfig_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Vconfig_Reponse */
typedef struct
{
    uint8_t result;
}IPC_S2M_MiscServiceVconfig_Reponse_t;

/* Receive function of sub message Vconfig_Reponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscServiceVconfig_Reponse_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceVconfig_Reponse_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: CheckTriggerMsg */
typedef struct
{
    uint8_t TriggerSource;
}IPC_S2M_MiscServiceCheckTriggerMsg_t;

/* Receive function of sub message CheckTriggerMsg */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscServiceCheckTriggerMsg_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceCheckTriggerMsg_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Cconfig_Response */
typedef struct
{
    uint8_t result;
}IPC_S2M_MiscServiceCconfig_Response_t;

/* Receive function of sub message Cconfig_Response */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscServiceCconfig_Response_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceCconfig_Response_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Vconfig_Usb */
typedef struct
{
    uint8_t Vconfig_Usb_Buffer[200];
}IPC_S2M_MiscServiceVconfig_Usb_t;

/* Receive function of sub message Vconfig_Usb */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscServiceVconfig_Usb_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceVconfig_Usb_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Get_Cconfig */
typedef struct
{
    uint8_t request;
}IPC_S2M_MiscServiceGet_Cconfig_t;

/* Receive function of sub message Get_Cconfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscServiceGet_Cconfig_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceGet_Cconfig_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Get_Offset */
typedef struct
{
    uint8_t request;
}IPC_S2M_MiscServiceGet_Offset_t;

/* Receive function of sub message Get_Offset */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscServiceGet_Offset_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceGet_Offset_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Misc */
/* Message Major: IVIInfo */
/* Message Sub: ReadDrvModeReq */
typedef struct
{
    uint8_t ModuleID;
    uint16_t InfoID;
}IPC_S2M_MiscIVIInfoReadDrvModeReq_t;

/* Receive function of sub message ReadDrvModeReq */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscIVIInfoReadDrvModeReq_Receive(uint8_t *receiveData, IPC_S2M_MiscIVIInfoReadDrvModeReq_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: WriteDrvModeReq */
typedef struct
{
    uint8_t ModuleID;
    uint16_t InfoID;
    /*0:Off 
    1:On*/
    uint8_t Switch;
}IPC_S2M_MiscIVIInfoWriteDrvModeReq_t;

/* Receive function of sub message WriteDrvModeReq */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_MiscIVIInfoWriteDrvModeReq_Receive(uint8_t *receiveData, IPC_S2M_MiscIVIInfoWriteDrvModeReq_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Misc */
#ifdef __cplusplus
}
#endif

#endif
