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
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group AUDIO_MQ source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_AUDIO_MQ.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: AUDIO_MQ */
/* Message Major: Qnx */
/* Transmit function of sub message MuteAudio */
int32_t IPC_M2S_AUDIO_MQQnxMuteAudio_Transmit(IPC_M2S_AUDIO_MQQnxMuteAudio_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_MQ_ID;
        payload[1] = IPC_M2S_AUDIO_MQ_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_ID;
        payload[3] = IPC_GET_BYTE(data->ecall_mute_req, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_MQ_QNX_MSGSUB_MUTEAUDIO_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message HUTInformation */
int32_t IPC_M2S_AUDIO_MQQnxHUTInformation_Transmit(IPC_M2S_AUDIO_MQQnxHUTInformation_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_MQ_ID;
        payload[1] = IPC_M2S_AUDIO_MQ_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_ID;
        payload[3] = IPC_GET_BYTE(data->get_hut_info, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_MQ_QNX_MSGSUB_HUTINFORMATION_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Receive function of sub message Reserved */
void IPC_S2M_AUDIO_MQQnxReserved_Receive(uint8_t *receiveData, IPC_S2M_AUDIO_MQQnxReserved_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_LENGTH)
        {
            payloadLength = IPC_S2M_AUDIO_MQ_QNX_MSGSUB_RESERVED_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->Reserved, 0) = receiveBuffer[0];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
