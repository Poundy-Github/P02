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
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group CAN source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_CAN.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: CAN */
/* Message Major: Message */
/* Transmit function of sub message Receive */
int32_t IPC_M2S_CANMessageReceive_Transmit(IPC_M2S_CANMessageReceive_t *data)
{
    uint8_t payload[IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataLength <= IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_CAN_ID;
        payload[1] = IPC_M2S_CAN_MSGMAJOR_MESSAGE_ID;
        payload[2] = IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_ID;
        payload[3] = (uint8_t)(data->DataLength >> 8);
        payload[4] = (uint8_t)(data->DataLength);
        payload[5] = IPC_GET_BYTE(data->FrameId, 3);
        payload[6] = IPC_GET_BYTE(data->FrameId, 2);
        payload[7] = IPC_GET_BYTE(data->FrameId, 1);
        payload[8] = IPC_GET_BYTE(data->FrameId, 0);
        flexLength = data->DataLength * sizeof(data->Data[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
            {
                payload[9 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CAN_MESSAGE_MSGSUB_RECEIVE_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Status */
int32_t IPC_M2S_CANMessageStatus_Transmit(IPC_M2S_CANMessageStatus_t *data)
{
    uint8_t payload[IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CAN_ID;
        payload[1] = IPC_M2S_CAN_MSGMAJOR_MESSAGE_ID;
        payload[2] = IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_ID;
        payload[3] = IPC_GET_BYTE(data->FrameId, 3);
        payload[4] = IPC_GET_BYTE(data->FrameId, 2);
        payload[5] = IPC_GET_BYTE(data->FrameId, 1);
        payload[6] = IPC_GET_BYTE(data->FrameId, 0);
        payload[7] = IPC_GET_BYTE(data->Status, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CAN_MESSAGE_MSGSUB_STATUS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Request */
int32_t IPC_M2S_CANMessageRequest_Transmit(IPC_M2S_CANMessageRequest_t *data)
{
    uint8_t payload[IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CAN_ID;
        payload[1] = IPC_M2S_CAN_MSGMAJOR_MESSAGE_ID;
        payload[2] = IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->FrameId, 3);
        payload[4] = IPC_GET_BYTE(data->FrameId, 2);
        payload[5] = IPC_GET_BYTE(data->FrameId, 1);
        payload[6] = IPC_GET_BYTE(data->FrameId, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: Signal */
/* Transmit function of sub message Receive */
int32_t IPC_M2S_CANSignalReceive_Transmit(IPC_M2S_CANSignalReceive_t *data)
{
    uint8_t payload[IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataPoolLength <= IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_CAN_ID;
        payload[1] = IPC_M2S_CAN_MSGMAJOR_SIGNAL_ID;
        payload[2] = IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_ID;
        payload[3] = (uint8_t)(data->DataPoolLength >> 8);
        payload[4] = (uint8_t)(data->DataPoolLength);
        payload[5] = IPC_GET_BYTE(data->Number, 0);
        flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->DataPool[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CAN_SIGNAL_MSGSUB_RECEIVE_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Request */
int32_t IPC_M2S_CANSignalRequest_Transmit(IPC_M2S_CANSignalRequest_t *data)
{
    uint8_t payload[IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CAN_ID;
        payload[1] = IPC_M2S_CAN_MSGMAJOR_SIGNAL_ID;
        payload[2] = IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->SignalId, 3);
        payload[4] = IPC_GET_BYTE(data->SignalId, 2);
        payload[5] = IPC_GET_BYTE(data->SignalId, 1);
        payload[6] = IPC_GET_BYTE(data->SignalId, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message TransmitCallback */
int32_t IPC_M2S_CANSignalTransmitCallback_Transmit(IPC_M2S_CANSignalTransmitCallback_t *data)
{
    uint8_t payload[IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataPoolLength <= IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_CAN_ID;
        payload[1] = IPC_M2S_CAN_MSGMAJOR_SIGNAL_ID;
        payload[2] = IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_ID;
        payload[3] = (uint8_t)(data->DataPoolLength >> 8);
        payload[4] = (uint8_t)(data->DataPoolLength);
        payload[5] = IPC_GET_BYTE(data->Number, 0);
        flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->DataPool[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CAN_SIGNAL_MSGSUB_TRANSMITCALLBACK_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message Transmit */
void IPC_S2M_CANMessageTransmit_Receive(uint8_t *receiveData, IPC_S2M_CANMessageTransmit_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH>= payloadLength) &&
        (IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH_MIN <= payloadLength))
    {
        data->DataLength = (receiveData[0] << 8) | receiveData[1];
        if(data->DataLength <= IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(payloadLength == flexLength + IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->FrameId, 3) = receiveData[2];
                IPC_GET_BYTE(data->FrameId, 2) = receiveData[3];
                IPC_GET_BYTE(data->FrameId, 1) = receiveData[4];
                IPC_GET_BYTE(data->FrameId, 0) = receiveData[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = receiveData[6 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

/* Receive function of sub message Request */
void IPC_S2M_CANMessageRequest_Receive(uint8_t *receiveData, IPC_S2M_CANMessageRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_CAN_MESSAGE_MSGSUB_REQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->FrameId, 3) = receiveData[0];
        IPC_GET_BYTE(data->FrameId, 2) = receiveData[1];
        IPC_GET_BYTE(data->FrameId, 1) = receiveData[2];
        IPC_GET_BYTE(data->FrameId, 0) = receiveData[3];
    }

}

/* Message Major: Signal */
/* Receive function of sub message Transmit */
void IPC_S2M_CANSignalTransmit_Receive(uint8_t *receiveData, IPC_S2M_CANSignalTransmit_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH>= payloadLength) &&
        (IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH_MIN <= payloadLength))
    {
        data->DataPoolLength = (receiveData[0] << 8) | receiveData[1];
        if(data->DataPoolLength <= IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataPoolLength * sizeof(data->DataPool[0]);
            if(payloadLength == flexLength + IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->Number, 0) = receiveData[2];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataPoolLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->DataPool[arrIndex], 0) = receiveData[3 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

/* Receive function of sub message Request */
void IPC_S2M_CANSignalRequest_Receive(uint8_t *receiveData, IPC_S2M_CANSignalRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_CAN_SIGNAL_MSGSUB_REQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->SignalId, 3) = receiveData[0];
        IPC_GET_BYTE(data->SignalId, 2) = receiveData[1];
        IPC_GET_BYTE(data->SignalId, 1) = receiveData[2];
        IPC_GET_BYTE(data->SignalId, 0) = receiveData[3];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
