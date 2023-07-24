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
 *                 File:  IPC_CAN.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group CAN source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_CAN.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: CAN */
/* Message Major: Message */
/* Pack function of sub message Receive */
int32_t IPC_M2S_CANMessageReceive_Pack(IPC_M2S_CANMessageReceive_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_M2S_CAN_MSGMAJOR_MESSAGE_ID;
        payload[4] = IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_ID;
        if((data->DataLength <= IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->FrameId, 3);
            payload[8] = IPC_GET_BYTE(data->FrameId, 2);
            payload[9] = IPC_GET_BYTE(data->FrameId, 1);
            payload[10] = IPC_GET_BYTE(data->FrameId, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message Receive */
int32_t IPC_M2S_CANMessageReceive_Parse(IPC_M2S_CANMessageReceive_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH >= length) &&
        (IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->FrameId, 3) = payload[2];
                IPC_GET_BYTE(data->FrameId, 2) = payload[3];
                IPC_GET_BYTE(data->FrameId, 1) = payload[4];
                IPC_GET_BYTE(data->FrameId, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[6 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message Status */
int32_t IPC_M2S_CANMessageStatus_Pack(IPC_M2S_CANMessageStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_M2S_CAN_MSGMAJOR_MESSAGE_ID;
        payload[4] = IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_ID;
        payload[5] = IPC_GET_BYTE(data->FrameId, 3);
        payload[6] = IPC_GET_BYTE(data->FrameId, 2);
        payload[7] = IPC_GET_BYTE(data->FrameId, 1);
        payload[8] = IPC_GET_BYTE(data->FrameId, 0);
        payload[9] = IPC_GET_BYTE(data->Status, 0);
        totalLength = IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Status */
int32_t IPC_M2S_CANMessageStatus_Parse(IPC_M2S_CANMessageStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameId, 3) = payload[0];
        IPC_GET_BYTE(data->FrameId, 2) = payload[1];
        IPC_GET_BYTE(data->FrameId, 1) = payload[2];
        IPC_GET_BYTE(data->FrameId, 0) = payload[3];
        IPC_GET_BYTE(data->Status, 0) = payload[4];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Request */
int32_t IPC_M2S_CANMessageRequest_Pack(IPC_M2S_CANMessageRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_M2S_CAN_MSGMAJOR_MESSAGE_ID;
        payload[4] = IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->FrameId, 3);
        payload[6] = IPC_GET_BYTE(data->FrameId, 2);
        payload[7] = IPC_GET_BYTE(data->FrameId, 1);
        payload[8] = IPC_GET_BYTE(data->FrameId, 0);
        totalLength = IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Request */
int32_t IPC_M2S_CANMessageRequest_Parse(IPC_M2S_CANMessageRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameId, 3) = payload[0];
        IPC_GET_BYTE(data->FrameId, 2) = payload[1];
        IPC_GET_BYTE(data->FrameId, 1) = payload[2];
        IPC_GET_BYTE(data->FrameId, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Message Major: Signal */
/* Pack function of sub message Receive */
int32_t IPC_M2S_CANSignalReceive_Pack(IPC_M2S_CANSignalReceive_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_M2S_CAN_MSGMAJOR_SIGNAL_ID;
        payload[4] = IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_ID;
        if((data->DataPoolLength <= IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataPoolLength >> 8);
            payload[6] = (uint8_t)(data->DataPoolLength);
            payload[7] = IPC_GET_BYTE(data->Number, 0);
            flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
                {
                    payload[8 + arrIndex * 1] = IPC_GET_BYTE(data->DataPool[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message Receive */
int32_t IPC_M2S_CANSignalReceive_Parse(IPC_M2S_CANSignalReceive_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH >= length) &&
        (IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH_MIN <= length))
    {
        data->DataPoolLength = (payload[0] << 8) | payload[1];
        if(data->DataPoolLength <= IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
            if(length == flexLength + IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->Number, 0) = payload[2];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->DataPool[arrIndex], 0) = payload[3 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message Request */
int32_t IPC_M2S_CANSignalRequest_Pack(IPC_M2S_CANSignalRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_M2S_CAN_MSGMAJOR_SIGNAL_ID;
        payload[4] = IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->SignalId, 3);
        payload[6] = IPC_GET_BYTE(data->SignalId, 2);
        payload[7] = IPC_GET_BYTE(data->SignalId, 1);
        payload[8] = IPC_GET_BYTE(data->SignalId, 0);
        totalLength = IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Request */
int32_t IPC_M2S_CANSignalRequest_Parse(IPC_M2S_CANSignalRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->SignalId, 3) = payload[0];
        IPC_GET_BYTE(data->SignalId, 2) = payload[1];
        IPC_GET_BYTE(data->SignalId, 1) = payload[2];
        IPC_GET_BYTE(data->SignalId, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TransmitCallback */
int32_t IPC_M2S_CANSignalTransmitCallback_Pack(IPC_M2S_CANSignalTransmitCallback_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_M2S_CAN_MSGMAJOR_SIGNAL_ID;
        payload[4] = IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_ID;
        if((data->DataPoolLength <= IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataPoolLength >> 8);
            payload[6] = (uint8_t)(data->DataPoolLength);
            payload[7] = IPC_GET_BYTE(data->Number, 0);
            flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
                {
                    payload[8 + arrIndex * 1] = IPC_GET_BYTE(data->DataPool[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message TransmitCallback */
int32_t IPC_M2S_CANSignalTransmitCallback_Parse(IPC_M2S_CANSignalTransmitCallback_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH >= length) &&
        (IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH_MIN <= length))
    {
        data->DataPoolLength = (payload[0] << 8) | payload[1];
        if(data->DataPoolLength <= IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
            if(length == flexLength + IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->Number, 0) = payload[2];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->DataPool[arrIndex], 0) = payload[3 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message Transmit */
int32_t IPC_S2M_CANMessageTransmit_Pack(IPC_S2M_CANMessageTransmit_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_S2M_CAN_MSGMAJOR_MESSAGE_ID;
        payload[4] = IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_ID;
        if((data->DataLength <= IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->FrameId, 3);
            payload[8] = IPC_GET_BYTE(data->FrameId, 2);
            payload[9] = IPC_GET_BYTE(data->FrameId, 1);
            payload[10] = IPC_GET_BYTE(data->FrameId, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message Transmit */
int32_t IPC_S2M_CANMessageTransmit_Parse(IPC_S2M_CANMessageTransmit_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH >= length) &&
        (IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->FrameId, 3) = payload[2];
                IPC_GET_BYTE(data->FrameId, 2) = payload[3];
                IPC_GET_BYTE(data->FrameId, 1) = payload[4];
                IPC_GET_BYTE(data->FrameId, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[6 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Request */
int32_t IPC_S2M_CANMessageRequest_Pack(IPC_S2M_CANMessageRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_S2M_CAN_MSGMAJOR_MESSAGE_ID;
        payload[4] = IPC_S2M_CAN_MESSAGE_MSGSUB_REQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->FrameId, 3);
        payload[6] = IPC_GET_BYTE(data->FrameId, 2);
        payload[7] = IPC_GET_BYTE(data->FrameId, 1);
        payload[8] = IPC_GET_BYTE(data->FrameId, 0);
        totalLength = IPC_S2M_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Request */
int32_t IPC_S2M_CANMessageRequest_Parse(IPC_S2M_CANMessageRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameId, 3) = payload[0];
        IPC_GET_BYTE(data->FrameId, 2) = payload[1];
        IPC_GET_BYTE(data->FrameId, 1) = payload[2];
        IPC_GET_BYTE(data->FrameId, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Message Major: Signal */
/* Pack function of sub message Transmit */
int32_t IPC_S2M_CANSignalTransmit_Pack(IPC_S2M_CANSignalTransmit_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_S2M_CAN_MSGMAJOR_SIGNAL_ID;
        payload[4] = IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_ID;
        if((data->DataPoolLength <= IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataPoolLength >> 8);
            payload[6] = (uint8_t)(data->DataPoolLength);
            payload[7] = IPC_GET_BYTE(data->Number, 0);
            flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
                {
                    payload[8 + arrIndex * 1] = IPC_GET_BYTE(data->DataPool[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message Transmit */
int32_t IPC_S2M_CANSignalTransmit_Parse(IPC_S2M_CANSignalTransmit_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH >= length) &&
        (IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH_MIN <= length))
    {
        data->DataPoolLength = (payload[0] << 8) | payload[1];
        if(data->DataPoolLength <= IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
            if(length == flexLength + IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->Number, 0) = payload[2];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->DataPool[arrIndex], 0) = payload[3 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Request */
int32_t IPC_S2M_CANSignalRequest_Pack(IPC_S2M_CANSignalRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_CAN_ID;
        payload[3] = IPC_S2M_CAN_MSGMAJOR_SIGNAL_ID;
        payload[4] = IPC_S2M_CAN_SIGNAL_MSGSUB_REQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->SignalId, 3);
        payload[6] = IPC_GET_BYTE(data->SignalId, 2);
        payload[7] = IPC_GET_BYTE(data->SignalId, 1);
        payload[8] = IPC_GET_BYTE(data->SignalId, 0);
        totalLength = IPC_S2M_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Request */
int32_t IPC_S2M_CANSignalRequest_Parse(IPC_S2M_CANSignalRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->SignalId, 3) = payload[0];
        IPC_GET_BYTE(data->SignalId, 2) = payload[1];
        IPC_GET_BYTE(data->SignalId, 1) = payload[2];
        IPC_GET_BYTE(data->SignalId, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
