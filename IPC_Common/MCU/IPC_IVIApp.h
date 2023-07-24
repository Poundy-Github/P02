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
*                 File:  IPC_IVIApp.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group IVIApp  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_IVIAPP_H_
#define _IPC_IVIAPP_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_IVIAPP_ID                                                      (16u)

/* MCU to SOC Message major id */
#define IPC_M2S_IVIAPP_MSGMAJOR_INFO_ID                                          (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_ID                      (0u)
#define IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_ID                       (1u)
/* MCU to SOC Message sub length */
#define IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH                  (61u)
#define IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH_MIN              (11u)
#define IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_FLEX_NUMBER             (50u)
#define IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH                   (62u)
#define IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH_MIN               (12u)
#define IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_FLEX_NUMBER              (50u)


/* SOC to MCU Message major id */
#define IPC_S2M_IVIAPP_MSGMAJOR_INFO_ID                                          (2u)
/* SOC to MCU Message sub id */
#define IPC_S2M_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALREQ_ID                       (0u)
#define IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_ID                        (1u)
/* SOC to MCU Message sub length */
#define IPC_S2M_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALREQ_LENGTH                   (9u)
#define IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH                    (61u)
#define IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH_MIN                (11u)
#define IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_FLEX_NUMBER               (50u)
/* Group: : IVIApp */
/* Message Major: Info */
/* Message Sub: ReadSettingSignalResp */
typedef struct
{
    uint16_t DataLength;
    /*ReadSettingSignalResp*/
    uint32_t ClientID;
    uint8_t ModuleID;
    uint32_t InfoID;
    uint8_t Data[50];
}IPC_M2S_IVIAppInfoReadSettingSignalResp_t;

/* Transmit function of sub message ReadSettingSignalResp */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_IVIAppInfoReadSettingSignalResp_Transmit(IPC_M2S_IVIAppInfoReadSettingSignalResp_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SetSettingSignalResp */
typedef struct
{
    uint16_t DataLength;
    /*SetSettingSignalResp*/
    uint32_t ClientID;
    uint8_t ModuleID;
    uint32_t InfoID;
    uint8_t Result;
    uint8_t Data[50];
}IPC_M2S_IVIAppInfoSetSettingSignalResp_t;

/* Transmit function of sub message SetSettingSignalResp */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_IVIAppInfoSetSettingSignalResp_Transmit(IPC_M2S_IVIAppInfoSetSettingSignalResp_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : IVIApp */
/* Group: : IVIApp */
/* Message Major: Info */
/* Message Sub: ReadSettingSignalReq */
typedef struct
{
    /*0£ºNot requirement  1£ºrerequirement £»0xff:Invaid*/
    uint32_t ClientID;
    uint8_t ModuleID;
    uint32_t InfoID;
}IPC_S2M_IVIAppInfoReadSettingSignalReq_t;

/* Receive function of sub message ReadSettingSignalReq */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_IVIAppInfoReadSettingSignalReq_Receive(uint8_t *receiveData, IPC_S2M_IVIAppInfoReadSettingSignalReq_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SetSettingSignalReq */
typedef struct
{
    uint16_t DataLength;
    uint32_t ClientID;
    uint8_t ModuleID;
    uint32_t InfoID;
    uint8_t Data[50];
}IPC_S2M_IVIAppInfoSetSettingSignalReq_t;

/* Receive function of sub message SetSettingSignalReq */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_IVIAppInfoSetSettingSignalReq_Receive(uint8_t *receiveData, IPC_S2M_IVIAppInfoSetSettingSignalReq_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : IVIApp */
#ifdef __cplusplus
}
#endif

#endif
