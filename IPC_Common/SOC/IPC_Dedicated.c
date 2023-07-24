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
 *                 File:  IPC_Dedicated.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Dedicated source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/
#include "IPC_Dedicated.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Dedicated */
/* Message Major: SocManager */
/* Pack function of sub message HandshakeResponse */
int32_t IPC_M2S_DedicatedSocManagerHandshakeResponse_Pack(IPC_M2S_DedicatedSocManagerHandshakeResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DEDICATED_ID;
        payload[3] = IPC_M2S_DEDICATED_MSGMAJOR_SOCMANAGER_ID;
        payload[4] = IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->u8Reserved[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message HandshakeResponse */
int32_t IPC_M2S_DedicatedSocManagerHandshakeResponse_Parse(IPC_M2S_DedicatedSocManagerHandshakeResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->u8Reserved[arrIndex], 0) = payload[0 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message HandshakeRequest */
int32_t IPC_S2M_DedicatedSocManagerHandshakeRequest_Pack(IPC_S2M_DedicatedSocManagerHandshakeRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DEDICATED_ID;
        payload[3] = IPC_S2M_DEDICATED_MSGMAJOR_SOCMANAGER_ID;
        payload[4] = IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->u8Reserved[arrIndex], 0);
            }
        }
        totalLength = IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message HandshakeRequest */
int32_t IPC_S2M_DedicatedSocManagerHandshakeRequest_Parse(IPC_S2M_DedicatedSocManagerHandshakeRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->u8Reserved[arrIndex], 0) = payload[0 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Heath */
int32_t IPC_S2M_DedicatedSocManagerHeath_Pack(IPC_S2M_DedicatedSocManagerHeath_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HEATH_LENGTH))
    {
        payload[2] = IPC_GROUP_DEDICATED_ID;
        payload[3] = IPC_S2M_DEDICATED_MSGMAJOR_SOCMANAGER_ID;
        payload[4] = IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HEATH_ID;
        payload[5] = IPC_GET_BYTE(data->u8Reserved, 0);
        totalLength = IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HEATH_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Heath */
int32_t IPC_S2M_DedicatedSocManagerHeath_Parse(IPC_S2M_DedicatedSocManagerHeath_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HEATH_LENGTH == length))
    {
        IPC_GET_BYTE(data->u8Reserved, 0) = payload[0];
        ret = 0;
    }
    return ret;
}

