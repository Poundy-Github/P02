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
 *                 File:  IPC_Diagnose.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Diagnose source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Diagnose.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Diagnose */
/* Message Major: QNX */
/* Pack function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseQNXSessionControlRequest_Pack(IPC_M2S_DiagnoseQNXSessionControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseQNXSessionControlRequest_Parse(IPC_M2S_DiagnoseQNXSessionControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseQNXDidReadRequest_Pack(IPC_M2S_DiagnoseQNXDidReadRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        totalLength = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseQNXDidReadRequest_Parse(IPC_M2S_DiagnoseQNXDidReadRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Did, 1) = payload[1];
        IPC_GET_BYTE(data->Did, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseQNXDidWriteRequest_Pack(IPC_M2S_DiagnoseQNXDidWriteRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_ID;
        if((data->PayloadLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER))
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
            totalLength = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseQNXDidWriteRequest_Parse(IPC_M2S_DiagnoseQNXDidWriteRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH >= length) &&
        (IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN <= length))
    {
        data->PayloadLength = (payload[0] << 8) | payload[1];
        if(data->PayloadLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->PayloadLength * sizeof(data->Payload[0]);
            if(length == flexLength + IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN)
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
/* Pack function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseQNXIoControlRequest_Pack(IPC_M2S_DiagnoseQNXIoControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_ID;
        if((data->StateAndMaskLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->StateAndMaskLength >> 8);
            payload[6] = (uint8_t)(data->StateAndMaskLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->DataId, 1);
            payload[9] = IPC_GET_BYTE(data->DataId, 0);
            payload[10] = IPC_GET_BYTE(data->Parameter, 0);
            flexLength = data->StateAndMaskLength * sizeof(data->StateAndMask[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->StateAndMaskLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->StateAndMask[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseQNXIoControlRequest_Parse(IPC_M2S_DiagnoseQNXIoControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH >= length) &&
        (IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN <= length))
    {
        data->StateAndMaskLength = (payload[0] << 8) | payload[1];
        if(data->StateAndMaskLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateAndMaskLength * sizeof(data->StateAndMask[0]);
            if(length == flexLength + IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->DataId, 1) = payload[3];
                IPC_GET_BYTE(data->DataId, 0) = payload[4];
                IPC_GET_BYTE(data->Parameter, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->StateAndMaskLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->StateAndMask[arrIndex], 0) = payload[6 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseQNXRoutineControlRequest_Pack(IPC_M2S_DiagnoseQNXRoutineControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_ID;
        if((data->OptionLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER))
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
            totalLength = IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseQNXRoutineControlRequest_Parse(IPC_M2S_DiagnoseQNXRoutineControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH >= length) &&
        (IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN <= length))
    {
        data->OptionLength = (payload[0] << 8) | payload[1];
        if(data->OptionLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->OptionLength * sizeof(data->Option[0]);
            if(length == flexLength + IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN)
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
/* Pack function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseQNXReportEventResponse_Pack(IPC_M2S_DiagnoseQNXReportEventResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->DtcCode[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseQNXReportEventResponse_Parse(IPC_M2S_DiagnoseQNXReportEventResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                IPC_GET_BYTE(data->DtcCode[arrIndex], 0) = payload[1 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseQNXDtcReinitRequest_Pack(IPC_M2S_DiagnoseQNXDtcReinitRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseQNXDtcReinitRequest_Parse(IPC_M2S_DiagnoseQNXDtcReinitRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Message Major: IVI */
/* Pack function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseIVISessionControlRequest_Pack(IPC_M2S_DiagnoseIVISessionControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseIVISessionControlRequest_Parse(IPC_M2S_DiagnoseIVISessionControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseIVIDidReadRequest_Pack(IPC_M2S_DiagnoseIVIDidReadRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        totalLength = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseIVIDidReadRequest_Parse(IPC_M2S_DiagnoseIVIDidReadRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Did, 1) = payload[1];
        IPC_GET_BYTE(data->Did, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseIVIDidWriteRequest_Pack(IPC_M2S_DiagnoseIVIDidWriteRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_ID;
        if((data->PayloadLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->PayloadLength >> 8);
            payload[6] = (uint8_t)(data->PayloadLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Did, 1);
            payload[9] = IPC_GET_BYTE(data->Did, 0);
            payload[10] = IPC_GET_BYTE(data->TotalLenth, 1);
            payload[11] = IPC_GET_BYTE(data->TotalLenth, 0);
            payload[12] = IPC_GET_BYTE(data->number, 0);
            flexLength = data->PayloadLength * sizeof(data->Payload[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
                {
                    payload[13 + arrIndex * 1] = IPC_GET_BYTE(data->Payload[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseIVIDidWriteRequest_Parse(IPC_M2S_DiagnoseIVIDidWriteRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH >= length) &&
        (IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN <= length))
    {
        data->PayloadLength = (payload[0] << 8) | payload[1];
        if(data->PayloadLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->PayloadLength * sizeof(data->Payload[0]);
            if(length == flexLength + IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Did, 1) = payload[3];
                IPC_GET_BYTE(data->Did, 0) = payload[4];
                IPC_GET_BYTE(data->TotalLenth, 1) = payload[5];
                IPC_GET_BYTE(data->TotalLenth, 0) = payload[6];
                IPC_GET_BYTE(data->number, 0) = payload[7];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Payload[arrIndex], 0) = payload[8 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseIVIIoControlRequest_Pack(IPC_M2S_DiagnoseIVIIoControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_ID;
        if((data->StateAndMaskLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->StateAndMaskLength >> 8);
            payload[6] = (uint8_t)(data->StateAndMaskLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->DataId, 1);
            payload[9] = IPC_GET_BYTE(data->DataId, 0);
            payload[10] = IPC_GET_BYTE(data->Parameter, 0);
            flexLength = data->StateAndMaskLength * sizeof(data->StateAndMask[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->StateAndMaskLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->StateAndMask[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseIVIIoControlRequest_Parse(IPC_M2S_DiagnoseIVIIoControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH >= length) &&
        (IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN <= length))
    {
        data->StateAndMaskLength = (payload[0] << 8) | payload[1];
        if(data->StateAndMaskLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateAndMaskLength * sizeof(data->StateAndMask[0]);
            if(length == flexLength + IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->DataId, 1) = payload[3];
                IPC_GET_BYTE(data->DataId, 0) = payload[4];
                IPC_GET_BYTE(data->Parameter, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->StateAndMaskLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->StateAndMask[arrIndex], 0) = payload[6 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseIVIRoutineControlRequest_Pack(IPC_M2S_DiagnoseIVIRoutineControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_ID;
        if((data->OptionLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER))
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
            totalLength = IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseIVIRoutineControlRequest_Parse(IPC_M2S_DiagnoseIVIRoutineControlRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH >= length) &&
        (IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN <= length))
    {
        data->OptionLength = (payload[0] << 8) | payload[1];
        if(data->OptionLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->OptionLength * sizeof(data->Option[0]);
            if(length == flexLength + IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN)
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
/* Pack function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseIVIReportEventResponse_Pack(IPC_M2S_DiagnoseIVIReportEventResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->DtcCode[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseIVIReportEventResponse_Parse(IPC_M2S_DiagnoseIVIReportEventResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                IPC_GET_BYTE(data->DtcCode[arrIndex], 0) = payload[1 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseIVIDtcReinitRequest_Pack(IPC_M2S_DiagnoseIVIDtcReinitRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseIVIDtcReinitRequest_Parse(IPC_M2S_DiagnoseIVIDtcReinitRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* MCU to SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Diagnose */
/* Message Major: QNX */
/* Pack function of sub message SessionControlResponse */
int32_t IPC_S2M_DiagnoseQNXSessionControlResponse_Pack(IPC_S2M_DiagnoseQNXSessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SessionControlResponse */
int32_t IPC_S2M_DiagnoseQNXSessionControlResponse_Parse(IPC_S2M_DiagnoseQNXSessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidReadResponse */
int32_t IPC_S2M_DiagnoseQNXDidReadResponse_Pack(IPC_S2M_DiagnoseQNXDidReadResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_ID;
        if((data->DataLength <= IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER))
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
            totalLength = IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message DidReadResponse */
int32_t IPC_S2M_DiagnoseQNXDidReadResponse_Parse(IPC_S2M_DiagnoseQNXDidReadResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH >= length) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN)
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
int32_t IPC_S2M_DiagnoseQNXDidWriteResponse_Pack(IPC_S2M_DiagnoseQNXDidWriteResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        totalLength = IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message DidWriteResponse */
int32_t IPC_S2M_DiagnoseQNXDidWriteResponse_Parse(IPC_S2M_DiagnoseQNXDidWriteResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Did, 1) = payload[1];
        IPC_GET_BYTE(data->Did, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message IoControlResponse */
int32_t IPC_S2M_DiagnoseQNXIoControlResponse_Pack(IPC_S2M_DiagnoseQNXIoControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->DataId, 1);
        payload[7] = IPC_GET_BYTE(data->DataId, 0);
        payload[8] = IPC_GET_BYTE(data->Parameter, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                payload[9 + arrIndex * 1] = IPC_GET_BYTE(data->State[arrIndex], 0);
            }
        }
        totalLength = IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message IoControlResponse */
int32_t IPC_S2M_DiagnoseQNXIoControlResponse_Parse(IPC_S2M_DiagnoseQNXIoControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->DataId, 1) = payload[1];
        IPC_GET_BYTE(data->DataId, 0) = payload[2];
        IPC_GET_BYTE(data->Parameter, 0) = payload[3];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->State[arrIndex], 0) = payload[4 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message RoutineControlResponse */
int32_t IPC_S2M_DiagnoseQNXRoutineControlResponse_Pack(IPC_S2M_DiagnoseQNXRoutineControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_ID;
        if((data->StateLength <= IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER))
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
            totalLength = IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message RoutineControlResponse */
int32_t IPC_S2M_DiagnoseQNXRoutineControlResponse_Parse(IPC_S2M_DiagnoseQNXRoutineControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH >= length) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN <= length))
    {
        data->StateLength = (payload[0] << 8) | payload[1];
        if(data->StateLength <= IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateLength * sizeof(data->State[0]);
            if(length == flexLength + IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN)
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
/* Pack function of sub message ReportEventRequest */
int32_t IPC_S2M_DiagnoseQNXReportEventRequest_Pack(IPC_S2M_DiagnoseQNXReportEventRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->DtcCode[arrIndex], 0);
            }
        }
        payload[9] = IPC_GET_BYTE(data->Result, 0);
        totalLength = IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ReportEventRequest */
int32_t IPC_S2M_DiagnoseQNXReportEventRequest_Parse(IPC_S2M_DiagnoseQNXReportEventRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                IPC_GET_BYTE(data->DtcCode[arrIndex], 0) = payload[1 + arrIndex * 1];
            }
        }
        IPC_GET_BYTE(data->Result, 0) = payload[4];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DtcReinitResponse */
int32_t IPC_S2M_DiagnoseQNXDtcReinitResponse_Pack(IPC_S2M_DiagnoseQNXDtcReinitResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_QNX_MSGSUB_DTCREINITRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_DIAGNOSE_QNX_MSGSUB_DTCREINITRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_S2M_DIAGNOSE_QNX_MSGSUB_DTCREINITRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message DtcReinitResponse */
int32_t IPC_S2M_DiagnoseQNXDtcReinitResponse_Parse(IPC_S2M_DiagnoseQNXDtcReinitResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DTCREINITRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Message Major: IVI */
/* Pack function of sub message SessionControlResponse */
int32_t IPC_S2M_DiagnoseIVISessionControlResponse_Pack(IPC_S2M_DiagnoseIVISessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_S2M_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SessionControlResponse */
int32_t IPC_S2M_DiagnoseIVISessionControlResponse_Parse(IPC_S2M_DiagnoseIVISessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidReadResponse */
int32_t IPC_S2M_DiagnoseIVIDidReadResponse_Pack(IPC_S2M_DiagnoseIVIDidReadResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_ID;
        if((data->DataLength <= IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->ServiceId, 0);
            payload[8] = IPC_GET_BYTE(data->Did, 1);
            payload[9] = IPC_GET_BYTE(data->Did, 0);
            payload[10] = IPC_GET_BYTE(data->TotalLength, 1);
            payload[11] = IPC_GET_BYTE(data->TotalLength, 0);
            payload[12] = IPC_GET_BYTE(data->Number, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[13 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message DidReadResponse */
int32_t IPC_S2M_DiagnoseIVIDidReadResponse_Parse(IPC_S2M_DiagnoseIVIDidReadResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH >= length) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Did, 1) = payload[3];
                IPC_GET_BYTE(data->Did, 0) = payload[4];
                IPC_GET_BYTE(data->TotalLength, 1) = payload[5];
                IPC_GET_BYTE(data->TotalLength, 0) = payload[6];
                IPC_GET_BYTE(data->Number, 0) = payload[7];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[8 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DidWriteResponse */
int32_t IPC_S2M_DiagnoseIVIDidWriteResponse_Pack(IPC_S2M_DiagnoseIVIDidWriteResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        totalLength = IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message DidWriteResponse */
int32_t IPC_S2M_DiagnoseIVIDidWriteResponse_Parse(IPC_S2M_DiagnoseIVIDidWriteResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Did, 1) = payload[1];
        IPC_GET_BYTE(data->Did, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message IoControlResponse */
int32_t IPC_S2M_DiagnoseIVIIoControlResponse_Pack(IPC_S2M_DiagnoseIVIIoControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_IVI_MSGSUB_IOCONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_DIAGNOSE_IVI_MSGSUB_IOCONTROLRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->DataId, 1);
        payload[7] = IPC_GET_BYTE(data->DataId, 0);
        payload[8] = IPC_GET_BYTE(data->Parameter, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                payload[9 + arrIndex * 1] = IPC_GET_BYTE(data->State[arrIndex], 0);
            }
        }
        totalLength = IPC_S2M_DIAGNOSE_IVI_MSGSUB_IOCONTROLRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message IoControlResponse */
int32_t IPC_S2M_DiagnoseIVIIoControlResponse_Parse(IPC_S2M_DiagnoseIVIIoControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_IOCONTROLRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->DataId, 1) = payload[1];
        IPC_GET_BYTE(data->DataId, 0) = payload[2];
        IPC_GET_BYTE(data->Parameter, 0) = payload[3];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->State[arrIndex], 0) = payload[4 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message RoutineControlResponse */
int32_t IPC_S2M_DiagnoseIVIRoutineControlResponse_Pack(IPC_S2M_DiagnoseIVIRoutineControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_ID;
        if((data->StateLength <= IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER))
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
                    payload[11 + arrIndex * 2] = IPC_GET_BYTE(data->State[arrIndex], 1);
                    payload[12 + arrIndex * 2] = IPC_GET_BYTE(data->State[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message RoutineControlResponse */
int32_t IPC_S2M_DiagnoseIVIRoutineControlResponse_Parse(IPC_S2M_DiagnoseIVIRoutineControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH >= length) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN <= length))
    {
        data->StateLength = (payload[0] << 8) | payload[1];
        if(data->StateLength <= IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateLength * sizeof(data->State[0]);
            if(length == flexLength + IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = payload[2];
                IPC_GET_BYTE(data->Type, 0) = payload[3];
                IPC_GET_BYTE(data->RoutineId, 1) = payload[4];
                IPC_GET_BYTE(data->RoutineId, 0) = payload[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->StateLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->State[arrIndex], 1) = payload[6 + arrIndex * 2];
                        IPC_GET_BYTE(data->State[arrIndex], 0) = payload[7 + arrIndex * 2];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ReportEventRequest */
int32_t IPC_S2M_DiagnoseIVIReportEventRequest_Pack(IPC_S2M_DiagnoseIVIReportEventRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->DtcCode[arrIndex], 0);
            }
        }
        payload[9] = IPC_GET_BYTE(data->Result, 0);
        totalLength = IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ReportEventRequest */
int32_t IPC_S2M_DiagnoseIVIReportEventRequest_Parse(IPC_S2M_DiagnoseIVIReportEventRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                IPC_GET_BYTE(data->DtcCode[arrIndex], 0) = payload[1 + arrIndex * 1];
            }
        }
        IPC_GET_BYTE(data->Result, 0) = payload[4];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DtcReinitResponse */
int32_t IPC_S2M_DiagnoseIVIDtcReinitResponse_Pack(IPC_S2M_DiagnoseIVIDtcReinitResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_DIAGNOSE_IVI_MSGSUB_DTCREINITRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_DIAGNOSE_ID;
        payload[3] = IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_DIAGNOSE_IVI_MSGSUB_DTCREINITRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_S2M_DIAGNOSE_IVI_MSGSUB_DTCREINITRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message DtcReinitResponse */
int32_t IPC_S2M_DiagnoseIVIDtcReinitResponse_Parse(IPC_S2M_DiagnoseIVIDtcReinitResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DTCREINITRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
