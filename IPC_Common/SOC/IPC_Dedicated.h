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
*                 File:  IPC_Dedicated.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_SOC.h.tem
*          Description:  IPC group Dedicated  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/
#ifndef _IPC_DEDICATED_H_
#define _IPC_DEDICATED_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_DEDICATED_ID                                                   (2u)

/* MCU to SOC Message major id */
#define IPC_M2S_DEDICATED_MSGMAJOR_SOCMANAGER_ID                                 (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_ID                 (0u)
/* MCU to SOC Message sub length */
#define IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH             (4u)
/* SOC to MCU Message major id */
#define IPC_S2M_DEDICATED_MSGMAJOR_SOCMANAGER_ID                                 (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_ID                  (0u)
#define IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HEATH_ID                             (1u)
/* SOC to MCU Message sub length */
#define IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH              (4u)
#define IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HEATH_LENGTH                         (1u)
/* Group: : Dedicated */
/* Message Major: SocManager */
/* Message Sub: HandshakeResponse */
typedef struct
{
    uint8_t u8Reserved[4];
}IPC_M2S_DedicatedSocManagerHandshakeResponse_t;

/* Pack function of sub message HandshakeResponse */
int32_t IPC_M2S_DedicatedSocManagerHandshakeResponse_Pack(IPC_M2S_DedicatedSocManagerHandshakeResponse_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message HandshakeResponse */
int32_t IPC_M2S_DedicatedSocManagerHandshakeResponse_Parse(IPC_M2S_DedicatedSocManagerHandshakeResponse_t *data, uint8_t *payload, uint16_t length);

/* Group: : Dedicated */
/* Group: : Dedicated */
/* Message Major: SocManager */
/* Message Sub: HandshakeRequest */
typedef struct
{
    uint8_t u8Reserved[4];
}IPC_S2M_DedicatedSocManagerHandshakeRequest_t;

/* Pack function of sub message HandshakeRequest */
int32_t IPC_S2M_DedicatedSocManagerHandshakeRequest_Pack(IPC_S2M_DedicatedSocManagerHandshakeRequest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message HandshakeRequest */
int32_t IPC_S2M_DedicatedSocManagerHandshakeRequest_Parse(IPC_S2M_DedicatedSocManagerHandshakeRequest_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: Heath */
typedef struct
{
    uint8_t u8Reserved;
}IPC_S2M_DedicatedSocManagerHeath_t;

/* Pack function of sub message Heath */
int32_t IPC_S2M_DedicatedSocManagerHeath_Pack(IPC_S2M_DedicatedSocManagerHeath_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Heath */
int32_t IPC_S2M_DedicatedSocManagerHeath_Parse(IPC_S2M_DedicatedSocManagerHeath_t *data, uint8_t *payload, uint16_t length);

/* Group: : Dedicated */
#ifdef __cplusplus
}
#endif

#endif
