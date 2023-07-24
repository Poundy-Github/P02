/**********************************************************************************************************************
 *  Copyright (C) 2020 GWM Automotive Inc.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *  The code contains GWM Confidential Proprietary Information.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *                 File:  IPC_AUDIO_MQ.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group AUDIO_MQ source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_AUDIO_MQ.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: AUDIO_MQ */
/* Message Major: Qnx */
/* Pack function of sub message MuteAudio */
int32_t IPC_M2S_AUDIO_MQQnxMuteAudio_Pack(IPC_M2S_AUDIO_MQQnxMuteAudio_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_MQ_ID;
        payload[3] = IPC_M2S_AUDIO_MQ_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_ID;
        payload[5] = IPC_GET_BYTE(in_data->ecall_mute_req, 0);
        totalLength = IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message MuteAudio */
int32_t IPC_M2S_AUDIO_MQQnxMuteAudio_Parse(IPC_M2S_AUDIO_MQQnxMuteAudio_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_LENGTH)
        {
            length = IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->ecall_mute_req, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message HUTInformation */
int32_t IPC_M2S_AUDIO_MQQnxHUTInformation_Pack(IPC_M2S_AUDIO_MQQnxHUTInformation_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_MQ_ID;
        payload[3] = IPC_M2S_AUDIO_MQ_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_ID;
        payload[5] = IPC_GET_BYTE(in_data->get_hut_info, 0);
        totalLength = IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message HUTInformation */
int32_t IPC_M2S_AUDIO_MQQnxHUTInformation_Parse(IPC_M2S_AUDIO_MQQnxHUTInformation_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_LENGTH)
        {
            length = IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->get_hut_info, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Reserved */
int32_t IPC_S2M_AUDIO_MQQnxReserved_Pack(IPC_S2M_AUDIO_MQQnxReserved_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_MQ_ID;
        payload[3] = IPC_S2M_AUDIO_MQ_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_ID;
        payload[5] = IPC_GET_BYTE(in_data->Reserved, 0);
        totalLength = IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Reserved */
int32_t IPC_S2M_AUDIO_MQQnxReserved_Parse(IPC_S2M_AUDIO_MQQnxReserved_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->Reserved, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
