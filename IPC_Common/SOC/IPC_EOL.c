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
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group EOL source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_EOL.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: EOL */
/* Message Major: QNX */
/* Pack function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLQNXSessionControlRequest_Pack(IPC_M2S_EOLQNXSessionControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_M2S_EOL_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLQNXSessionControlRequest_Parse(IPC_M2S_EOLQNXSessionControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_EOL_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidReadRequest */
int32_t IPC_M2S_EOLQNXDidReadRequest_Pack(IPC_M2S_EOLQNXDidReadRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_M2S_EOL_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        totalLength = IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message DidReadRequest */
int32_t IPC_M2S_EOLQNXDidReadRequest_Parse(IPC_M2S_EOLQNXDidReadRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_EOL_QNX_MSGSUB_DIDREADREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Did, 1) = payload[1];
        IPC_GET_BYTE(data->Did, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLQNXDidWriteRequest_Pack(IPC_M2S_EOLQNXDidWriteRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_M2S_EOL_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_ID;
        if((data->PayloadLength <= IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->PayloadLength >> 8);
            payload[6] = (uint8_t)(data->PayloadLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Did, 1);
            payload[9] = IPC_GET_BYTE(data->Did, 0);
            flexLength = data->PayloadLength * sizeof(data->Payload[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
                {
                    payload[10 + arrIndex * 1] = IPC_GET_BYTE(data->Payload[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLQNXDidWriteRequest_Parse(IPC_M2S_EOLQNXDidWriteRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH >= length) &&
        (IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN <= length))
    {
        data->PayloadLength = (payload[0] << 8) | payload[1];
        if(data->PayloadLength <= IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->PayloadLength * sizeof(data->Payload[0]);
            if(length == flexLength + IPC_M2S_EOL_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Did, 1) = payload[3];
                IPC_GET_BYTE(data->Did, 0) = payload[4];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Payload[arrIndex], 0) = payload[5 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLQNXRoutineControlRequest_Pack(IPC_M2S_EOLQNXRoutineControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_M2S_EOL_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_ID;
        if((data->OptionLength <= IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->OptionLength >> 8);
            payload[6] = (uint8_t)(data->OptionLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Type, 0);
            payload[9] = IPC_GET_BYTE(data->RoutineId, 1);
            payload[10] = IPC_GET_BYTE(data->RoutineId, 0);
            flexLength = data->OptionLength * sizeof(data->Option[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->OptionLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->Option[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLQNXRoutineControlRequest_Parse(IPC_M2S_EOLQNXRoutineControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH >= length) &&
        (IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN <= length))
    {
        data->OptionLength = (payload[0] << 8) | payload[1];
        if(data->OptionLength <= IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->OptionLength * sizeof(data->Option[0]);
            if(length == flexLength + IPC_M2S_EOL_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Type, 0) = payload[3];
                IPC_GET_BYTE(data->RoutineId, 1) = payload[4];
                IPC_GET_BYTE(data->RoutineId, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->OptionLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Option[arrIndex], 0) = payload[6 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Message Major: IVI */
/* Pack function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLIVISessionControlRequest_Pack(IPC_M2S_EOLIVISessionControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_M2S_EOL_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SessionControlRequest */
int32_t IPC_M2S_EOLIVISessionControlRequest_Parse(IPC_M2S_EOLIVISessionControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_EOL_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidReadRequest */
int32_t IPC_M2S_EOLIVIDidReadRequest_Pack(IPC_M2S_EOLIVIDidReadRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_M2S_EOL_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        totalLength = IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message DidReadRequest */
int32_t IPC_M2S_EOLIVIDidReadRequest_Parse(IPC_M2S_EOLIVIDidReadRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_EOL_IVI_MSGSUB_DIDREADREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Did, 1) = payload[1];
        IPC_GET_BYTE(data->Did, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLIVIDidWriteRequest_Pack(IPC_M2S_EOLIVIDidWriteRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_M2S_EOL_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_ID;
        if((data->PayloadLength <= IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->PayloadLength >> 8);
            payload[6] = (uint8_t)(data->PayloadLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Did, 1);
            payload[9] = IPC_GET_BYTE(data->Did, 0);
            flexLength = data->PayloadLength * sizeof(data->Payload[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
                {
                    payload[10 + arrIndex * 1] = IPC_GET_BYTE(data->Payload[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message DidWriteRequest */
int32_t IPC_M2S_EOLIVIDidWriteRequest_Parse(IPC_M2S_EOLIVIDidWriteRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH >= length) &&
        (IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN <= length))
    {
        data->PayloadLength = (payload[0] << 8) | payload[1];
        if(data->PayloadLength <= IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->PayloadLength * sizeof(data->Payload[0]);
            if(length == flexLength + IPC_M2S_EOL_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Did, 1) = payload[3];
                IPC_GET_BYTE(data->Did, 0) = payload[4];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Payload[arrIndex], 0) = payload[5 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLIVIRoutineControlRequest_Pack(IPC_M2S_EOLIVIRoutineControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_M2S_EOL_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_ID;
        if((data->OptionLength <= IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->OptionLength >> 8);
            payload[6] = (uint8_t)(data->OptionLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Type, 0);
            payload[9] = IPC_GET_BYTE(data->RoutineId, 1);
            payload[10] = IPC_GET_BYTE(data->RoutineId, 0);
            flexLength = data->OptionLength * sizeof(data->Option[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->OptionLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->Option[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message RoutineControlRequest */
int32_t IPC_M2S_EOLIVIRoutineControlRequest_Parse(IPC_M2S_EOLIVIRoutineControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH >= length) &&
        (IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN <= length))
    {
        data->OptionLength = (payload[0] << 8) | payload[1];
        if(data->OptionLength <= IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->OptionLength * sizeof(data->Option[0]);
            if(length == flexLength + IPC_M2S_EOL_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Type, 0) = payload[3];
                IPC_GET_BYTE(data->RoutineId, 1) = payload[4];
                IPC_GET_BYTE(data->RoutineId, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->OptionLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Option[arrIndex], 0) = payload[6 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message SessionControlResponse */
int32_t IPC_S2M_EOLQNXSessionControlResponse_Pack(IPC_S2M_EOLQNXSessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_EOL_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_S2M_EOL_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_EOL_QNX_MSGSUB_SESSIONCONTROLRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_S2M_EOL_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SessionControlResponse */
int32_t IPC_S2M_EOLQNXSessionControlResponse_Parse(IPC_S2M_EOLQNXSessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_EOL_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidReadResponse */
int32_t IPC_S2M_EOLQNXDidReadResponse_Pack(IPC_S2M_EOLQNXDidReadResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_S2M_EOL_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_ID;
        if((data->DataLength <= IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Did, 1);
            payload[9] = IPC_GET_BYTE(data->Did, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[10 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message DidReadResponse */
int32_t IPC_S2M_EOLQNXDidReadResponse_Parse(IPC_S2M_EOLQNXDidReadResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH >= length) &&
        (IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Did, 1) = payload[3];
                IPC_GET_BYTE(data->Did, 0) = payload[4];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[5 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidWriteResponse */
int32_t IPC_S2M_EOLQNXDidWriteResponse_Pack(IPC_S2M_EOLQNXDidWriteResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_EOL_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_S2M_EOL_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_EOL_QNX_MSGSUB_DIDWRITERESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        totalLength = IPC_S2M_EOL_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message DidWriteResponse */
int32_t IPC_S2M_EOLQNXDidWriteResponse_Parse(IPC_S2M_EOLQNXDidWriteResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_EOL_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Did, 1) = payload[1];
        IPC_GET_BYTE(data->Did, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message RoutineControlResponse */
int32_t IPC_S2M_EOLQNXRoutineControlResponse_Pack(IPC_S2M_EOLQNXRoutineControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_S2M_EOL_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_ID;
        if((data->StateLength <= IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->StateLength >> 8);
            payload[6] = (uint8_t)(data->StateLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Type, 0);
            payload[9] = IPC_GET_BYTE(data->RoutineId, 1);
            payload[10] = IPC_GET_BYTE(data->RoutineId, 0);
            flexLength = data->StateLength * sizeof(data->State[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->StateLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->State[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message RoutineControlResponse */
int32_t IPC_S2M_EOLQNXRoutineControlResponse_Parse(IPC_S2M_EOLQNXRoutineControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH >= length) &&
        (IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN <= length))
    {
        data->StateLength = (payload[0] << 8) | payload[1];
        if(data->StateLength <= IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateLength * sizeof(data->State[0]);
            if(length == flexLength + IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Type, 0) = payload[3];
                IPC_GET_BYTE(data->RoutineId, 1) = payload[4];
                IPC_GET_BYTE(data->RoutineId, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->StateLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->State[arrIndex], 0) = payload[6 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
/* Message Major: IVI */
/* Pack function of sub message SessionControlResponse */
int32_t IPC_S2M_EOLIVISessionControlResponse_Pack(IPC_S2M_EOLIVISessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_EOL_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_S2M_EOL_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_EOL_IVI_MSGSUB_SESSIONCONTROLRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_S2M_EOL_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SessionControlResponse */
int32_t IPC_S2M_EOLIVISessionControlResponse_Parse(IPC_S2M_EOLIVISessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_EOL_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidReadResponse */
int32_t IPC_S2M_EOLIVIDidReadResponse_Pack(IPC_S2M_EOLIVIDidReadResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_S2M_EOL_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_ID;
        if((data->DataLength <= IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Did, 1);
            payload[9] = IPC_GET_BYTE(data->Did, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[10 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message DidReadResponse */
int32_t IPC_S2M_EOLIVIDidReadResponse_Parse(IPC_S2M_EOLIVIDidReadResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH >= length) &&
        (IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Did, 1) = payload[3];
                IPC_GET_BYTE(data->Did, 0) = payload[4];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[5 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidWriteResponse */
int32_t IPC_S2M_EOLIVIDidWriteResponse_Pack(IPC_S2M_EOLIVIDidWriteResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_EOL_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_S2M_EOL_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_EOL_IVI_MSGSUB_DIDWRITERESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        totalLength = IPC_S2M_EOL_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message DidWriteResponse */
int32_t IPC_S2M_EOLIVIDidWriteResponse_Parse(IPC_S2M_EOLIVIDidWriteResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_EOL_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Did, 1) = payload[1];
        IPC_GET_BYTE(data->Did, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message RoutineControlResponse */
int32_t IPC_S2M_EOLIVIRoutineControlResponse_Pack(IPC_S2M_EOLIVIRoutineControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_EOL_ID;
        payload[3] = IPC_S2M_EOL_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_ID;
        if((data->StateLength <= IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->StateLength >> 8);
            payload[6] = (uint8_t)(data->StateLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Type, 0);
            payload[9] = IPC_GET_BYTE(data->RoutineId, 1);
            payload[10] = IPC_GET_BYTE(data->RoutineId, 0);
            flexLength = data->StateLength * sizeof(data->State[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->StateLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->State[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message RoutineControlResponse */
int32_t IPC_S2M_EOLIVIRoutineControlResponse_Parse(IPC_S2M_EOLIVIRoutineControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH >= length) &&
        (IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN <= length))
    {
        data->StateLength = (payload[0] << 8) | payload[1];
        if(data->StateLength <= IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateLength * sizeof(data->State[0]);
            if(length == flexLength + IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Type, 0) = payload[3];
                IPC_GET_BYTE(data->RoutineId, 1) = payload[4];
                IPC_GET_BYTE(data->RoutineId, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->StateLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->State[arrIndex], 0) = payload[6 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
