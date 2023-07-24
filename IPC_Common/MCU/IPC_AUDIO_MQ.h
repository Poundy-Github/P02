/**********************************************************************************************************************
 *  Copyright (C) 2020 GWM Automotive Inc.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *  The code contains GWM Confidential Proprietary Information.
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*                 File:  IPC_AUDIO_MQ.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group AUDIO_MQ  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef IPC_AUDIO_MQ_H
#define IPC_AUDIO_MQ_H

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_AUDIO_MQ_ID                                                    (19u)

/* MCU to SOC Message major id */
#define IPC_M2S_AUDIO_MQ_MSGMAJOR_QNX_ID                                         (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_ID                                 (1u)
#define IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_ID                            (2u)
/* MCU to SOC Message sub length */
#define IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_LENGTH                             (1u)
#define IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_LENGTH                        (1u)


/* SOC to MCU Message major id */
#define IPC_S2M_AUDIO_MQ_MSGMAJOR_QNX_ID                                         (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_ID                                  (0u)
/* SOC to MCU Message sub length */
#define IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_LENGTH                              (1u)
/* Group: : AUDIO_MQ */
/* Message Major: Qnx */
/* Message Sub: MuteAudio */
typedef struct
{
    /*T_BOX_FD1(0x033) T_BOX_AudioMuteReq*/
    uint8_t ecall_mute_req;
}IPC_M2S_AUDIO_MQQnxMuteAudio_t;

/* Transmit function of sub message MuteAudio */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_AUDIO_MQQnxMuteAudio_Transmit(IPC_M2S_AUDIO_MQQnxMuteAudio_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: HUTInformation */
typedef struct
{
    /*AMP2(0x3E3) GetHUtInfoSts*/
    uint8_t get_hut_info;
}IPC_M2S_AUDIO_MQQnxHUTInformation_t;

/* Transmit function of sub message HUTInformation */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_AUDIO_MQQnxHUTInformation_Transmit(IPC_M2S_AUDIO_MQQnxHUTInformation_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : AUDIO_MQ */
/* Group: : AUDIO_MQ */
/* Message Major: Qnx */
/* Message Sub: Reserved */
typedef struct
{
    uint8_t Reserved;
}IPC_S2M_AUDIO_MQQnxReserved_t;

/* Receive function of sub message Reserved */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_AUDIO_MQQnxReserved_Receive(uint8_t *receiveData, IPC_S2M_AUDIO_MQQnxReserved_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : AUDIO_MQ */
#ifdef __cplusplus
}
#endif

#endif
