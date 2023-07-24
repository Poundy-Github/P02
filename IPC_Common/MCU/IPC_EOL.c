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
 *                 File:  IPC_EOL.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group EOL source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_EOL.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: EOL */
/* Message Major: QNX */
/* Transmit function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLQNXSessionControlRequest_Transmit(IPC_M2S_EOLQNXSessionControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_EOL_ID;
        payload[1] = IPC_M2S_EOL_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Type, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DidReadRequest */
int32_t IPC_M2S_EOLQNXDidReadRequest_Transmit(IPC_M2S_EOLQNXDidReadRequest_t *data)
{
    uint8_t payload[IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_EOL_ID;
        payload[1] = IPC_M2S_EOL_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Did, 1);
        payload[5] = IPC_GET_BYTE(data->Did, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLQNXDidWriteRequest_Transmit(IPC_M2S_EOLQNXDidWriteRequest_t *data)
{
    uint8_t payload[IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->PayloadLength <= IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_EOL_ID;
        payload[1] = IPC_M2S_EOL_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_ID;
        payload[3] = (uint8_t)(data->PayloadLength >> 8);
        payload[4] = (uint8_t)(data->PayloadLength);
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        flexLength = data->PayloadLength * sizeof(data->Payload[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
            {
                payload[8 + arrIndex * 1] = IPC_GET_BYTE(data->Payload[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLQNXRoutineControlRequest_Transmit(IPC_M2S_EOLQNXRoutineControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->OptionLength <= IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_EOL_ID;
        payload[1] = IPC_M2S_EOL_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_ID;
        payload[3] = (uint8_t)(data->OptionLength >> 8);
        payload[4] = (uint8_t)(data->OptionLength);
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        payload[7] = IPC_GET_BYTE(data->RoutineId, 1);
        payload[8] = IPC_GET_BYTE(data->RoutineId, 0);
        flexLength = data->OptionLength * sizeof(data->Option[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->OptionLength; arrIndex++)
            {
                payload[9 + arrIndex * 1] = IPC_GET_BYTE(data->Option[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: IVI */
/* Transmit function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLIVISessionControlRequest_Transmit(IPC_M2S_EOLIVISessionControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_EOL_ID;
        payload[1] = IPC_M2S_EOL_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Type, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DidReadRequest */
int32_t IPC_M2S_EOLIVIDidReadRequest_Transmit(IPC_M2S_EOLIVIDidReadRequest_t *data)
{
    uint8_t payload[IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_EOL_ID;
        payload[1] = IPC_M2S_EOL_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Did, 1);
        payload[5] = IPC_GET_BYTE(data->Did, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLIVIDidWriteRequest_Transmit(IPC_M2S_EOLIVIDidWriteRequest_t *data)
{
    uint8_t payload[IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->PayloadLength <= IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_EOL_ID;
        payload[1] = IPC_M2S_EOL_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_ID;
        payload[3] = (uint8_t)(data->PayloadLength >> 8);
        payload[4] = (uint8_t)(data->PayloadLength);
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        flexLength = data->PayloadLength * sizeof(data->Payload[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
            {
                payload[8 + arrIndex * 1] = IPC_GET_BYTE(data->Payload[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLIVIRoutineControlRequest_Transmit(IPC_M2S_EOLIVIRoutineControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->OptionLength <= IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_EOL_ID;
        payload[1] = IPC_M2S_EOL_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_ID;
        payload[3] = (uint8_t)(data->OptionLength >> 8);
        payload[4] = (uint8_t)(data->OptionLength);
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        payload[7] = IPC_GET_BYTE(data->RoutineId, 1);
        payload[8] = IPC_GET_BYTE(data->RoutineId, 0);
        flexLength = data->OptionLength * sizeof(data->Option[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->OptionLength; arrIndex++)
            {
                payload[9 + arrIndex * 1] = IPC_GET_BYTE(data->Option[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message SessionControlResponse */
void IPC_S2M_EOLQNXSessionControlResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLQNXSessionControlResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_EOL_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Type, 0) = receiveData[1];
    }

}

/* Receive function of sub message DidReadResponse */
void IPC_S2M_EOLQNXDidReadResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLQNXDidReadResponse_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH>= payloadLength) &&
        (IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN <= payloadLength))
    {
        data->DataLength = (receiveData[0] << 8) | receiveData[1];
        if(data->DataLength <= IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(payloadLength == flexLength + IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = receiveData[2];
                IPC_GET_BYTE(data->Did, 1) = receiveData[3];
                IPC_GET_BYTE(data->Did, 0) = receiveData[4];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = receiveData[5 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

/* Receive function of sub message DidWriteResponse */
void IPC_S2M_EOLQNXDidWriteResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLQNXDidWriteResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_EOL_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Did, 1) = receiveData[1];
        IPC_GET_BYTE(data->Did, 0) = receiveData[2];
    }

}

/* Receive function of sub message RoutineControlResponse */
void IPC_S2M_EOLQNXRoutineControlResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLQNXRoutineControlResponse_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH>= payloadLength) &&
        (IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN <= payloadLength))
    {
        data->StateLength = (receiveData[0] << 8) | receiveData[1];
        if(data->StateLength <= IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateLength * sizeof(data->State[0]);
            if(payloadLength == flexLength + IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = receiveData[2];
                IPC_GET_BYTE(data->Type, 0) = receiveData[3];
                IPC_GET_BYTE(data->RoutineId, 1) = receiveData[4];
                IPC_GET_BYTE(data->RoutineId, 0) = receiveData[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->StateLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->State[arrIndex], 0) = receiveData[6 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

/* Message Major: IVI */
/* Receive function of sub message SessionControlResponse */
void IPC_S2M_EOLIVISessionControlResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLIVISessionControlResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_EOL_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Type, 0) = receiveData[1];
    }

}

/* Receive function of sub message DidReadResponse */
void IPC_S2M_EOLIVIDidReadResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLIVIDidReadResponse_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH>= payloadLength) &&
        (IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN <= payloadLength))
    {
        data->DataLength = (receiveData[0] << 8) | receiveData[1];
        if(data->DataLength <= IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(payloadLength == flexLength + IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = receiveData[2];
                IPC_GET_BYTE(data->Did, 1) = receiveData[3];
                IPC_GET_BYTE(data->Did, 0) = receiveData[4];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = receiveData[5 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

/* Receive function of sub message DidWriteResponse */
void IPC_S2M_EOLIVIDidWriteResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLIVIDidWriteResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_EOL_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Did, 1) = receiveData[1];
        IPC_GET_BYTE(data->Did, 0) = receiveData[2];
    }

}

/* Receive function of sub message RoutineControlResponse */
void IPC_S2M_EOLIVIRoutineControlResponse_Receive(uint8_t *receiveData, IPC_S2M_EOLIVIRoutineControlResponse_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH>= payloadLength) &&
        (IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN <= payloadLength))
    {
        data->StateLength = (receiveData[0] << 8) | receiveData[1];
        if(data->StateLength <= IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateLength * sizeof(data->State[0]);
            if(payloadLength == flexLength + IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = receiveData[2];
                IPC_GET_BYTE(data->Type, 0) = receiveData[3];
                IPC_GET_BYTE(data->RoutineId, 1) = receiveData[4];
                IPC_GET_BYTE(data->RoutineId, 0) = receiveData[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->StateLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->State[arrIndex], 0) = receiveData[6 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
