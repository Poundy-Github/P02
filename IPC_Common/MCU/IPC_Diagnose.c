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
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group Diagnose source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Diagnose.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Diagnose */
/* Message Major: QNX */
/* Transmit function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseQNXSessionControlRequest_Transmit(IPC_M2S_DiagnoseQNXSessionControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Type, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseQNXDidReadRequest_Transmit(IPC_M2S_DiagnoseQNXDidReadRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Did, 1);
        payload[5] = IPC_GET_BYTE(data->Did, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDREADREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseQNXDidWriteRequest_Transmit(IPC_M2S_DiagnoseQNXDidWriteRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->PayloadLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_ID;
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
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_QNX_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseQNXIoControlRequest_Transmit(IPC_M2S_DiagnoseQNXIoControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->StateAndMaskLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_ID;
        payload[3] = (uint8_t)(data->StateAndMaskLength >> 8);
        payload[4] = (uint8_t)(data->StateAndMaskLength);
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->DataId, 1);
        payload[7] = IPC_GET_BYTE(data->DataId, 0);
        payload[8] = IPC_GET_BYTE(data->Parameter, 0);
        flexLength = data->StateAndMaskLength * sizeof(data->StateAndMask[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->StateAndMaskLength; arrIndex++)
            {
                payload[9 + arrIndex * 1] = IPC_GET_BYTE(data->StateAndMask[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_QNX_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseQNXRoutineControlRequest_Transmit(IPC_M2S_DiagnoseQNXRoutineControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->OptionLength <= IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_ID;
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
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseQNXReportEventResponse_Transmit(IPC_M2S_DiagnoseQNXReportEventResponse_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                payload[4 + arrIndex * 1] = IPC_GET_BYTE(data->DtcCode[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_QNX_MSGSUB_REPORTEVENTRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseQNXDtcReinitRequest_Transmit(IPC_M2S_DiagnoseQNXDtcReinitRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_QNX_ID;
        payload[2] = IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Type, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_QNX_MSGSUB_DTCREINITREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: IVI */
/* Transmit function of sub message SessionControlRequest */
int32_t IPC_M2S_DiagnoseIVISessionControlRequest_Transmit(IPC_M2S_DiagnoseIVISessionControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Type, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DidReadRequest */
int32_t IPC_M2S_DiagnoseIVIDidReadRequest_Transmit(IPC_M2S_DiagnoseIVIDidReadRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Did, 1);
        payload[5] = IPC_GET_BYTE(data->Did, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDREADREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DidWriteRequest */
int32_t IPC_M2S_DiagnoseIVIDidWriteRequest_Transmit(IPC_M2S_DiagnoseIVIDidWriteRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->PayloadLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_ID;
        payload[3] = (uint8_t)(data->PayloadLength >> 8);
        payload[4] = (uint8_t)(data->PayloadLength);
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->Did, 1);
        payload[7] = IPC_GET_BYTE(data->Did, 0);
        payload[8] = IPC_GET_BYTE(data->TotalLenth, 1);
        payload[9] = IPC_GET_BYTE(data->TotalLenth, 0);
        payload[10] = IPC_GET_BYTE(data->number, 0);
        flexLength = data->PayloadLength * sizeof(data->Payload[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->PayloadLength; arrIndex++)
            {
                payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->Payload[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_IVI_MSGSUB_DIDWRITEREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message IoControlRequest */
int32_t IPC_M2S_DiagnoseIVIIoControlRequest_Transmit(IPC_M2S_DiagnoseIVIIoControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->StateAndMaskLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_ID;
        payload[3] = (uint8_t)(data->StateAndMaskLength >> 8);
        payload[4] = (uint8_t)(data->StateAndMaskLength);
        payload[5] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[6] = IPC_GET_BYTE(data->DataId, 1);
        payload[7] = IPC_GET_BYTE(data->DataId, 0);
        payload[8] = IPC_GET_BYTE(data->Parameter, 0);
        flexLength = data->StateAndMaskLength * sizeof(data->StateAndMask[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->StateAndMaskLength; arrIndex++)
            {
                payload[9 + arrIndex * 1] = IPC_GET_BYTE(data->StateAndMask[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_IVI_MSGSUB_IOCONTROLREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message RoutineControlRequest */
int32_t IPC_M2S_DiagnoseIVIRoutineControlRequest_Transmit(IPC_M2S_DiagnoseIVIRoutineControlRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->OptionLength <= IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_ID;
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
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLREQUEST_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message ReportEventResponse */
int32_t IPC_M2S_DiagnoseIVIReportEventResponse_Transmit(IPC_M2S_DiagnoseIVIReportEventResponse_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                payload[4 + arrIndex * 1] = IPC_GET_BYTE(data->DtcCode[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_IVI_MSGSUB_REPORTEVENTRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message DtcReinitRequest */
int32_t IPC_M2S_DiagnoseIVIDtcReinitRequest_Transmit(IPC_M2S_DiagnoseIVIDtcReinitRequest_t *data)
{
    uint8_t payload[IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DIAGNOSE_ID;
        payload[1] = IPC_M2S_DIAGNOSE_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_ID;
        payload[3] = IPC_GET_BYTE(data->ServiceId, 0);
        payload[4] = IPC_GET_BYTE(data->Type, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_DIAGNOSE_IVI_MSGSUB_DTCREINITREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* MCU to SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Diagnose */
/* Message Major: QNX */
/* Receive function of sub message SessionControlResponse */
void IPC_S2M_DiagnoseQNXSessionControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXSessionControlResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Type, 0) = receiveData[1];
    }

}

/* Receive function of sub message DidReadResponse */
void IPC_S2M_DiagnoseQNXDidReadResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXDidReadResponse_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH>= payloadLength) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN <= payloadLength))
    {
        data->DataLength = (receiveData[0] << 8) | receiveData[1];
        if(data->DataLength <= IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(payloadLength == flexLength + IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_LENGTH_MIN)
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
void IPC_S2M_DiagnoseQNXDidWriteResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXDidWriteResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Did, 1) = receiveData[1];
        IPC_GET_BYTE(data->Did, 0) = receiveData[2];
    }

}

/* Receive function of sub message IoControlResponse */
void IPC_S2M_DiagnoseQNXIoControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXIoControlResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->DataId, 1) = receiveData[1];
        IPC_GET_BYTE(data->DataId, 0) = receiveData[2];
        IPC_GET_BYTE(data->Parameter, 0) = receiveData[3];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->State[arrIndex], 0) = receiveData[4 + arrIndex * 1];
            }
        }
    }

}

/* Receive function of sub message RoutineControlResponse */
void IPC_S2M_DiagnoseQNXRoutineControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXRoutineControlResponse_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH>= payloadLength) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN <= payloadLength))
    {
        data->StateLength = (receiveData[0] << 8) | receiveData[1];
        if(data->StateLength <= IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateLength * sizeof(data->State[0]);
            if(payloadLength == flexLength + IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN)
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

/* Receive function of sub message ReportEventRequest */
void IPC_S2M_DiagnoseQNXReportEventRequest_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXReportEventRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                IPC_GET_BYTE(data->DtcCode[arrIndex], 0) = receiveData[1 + arrIndex * 1];
            }
        }
        IPC_GET_BYTE(data->Result, 0) = receiveData[4];
    }

}

/* Receive function of sub message DtcReinitResponse */
void IPC_S2M_DiagnoseQNXDtcReinitResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseQNXDtcReinitResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DTCREINITRESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Type, 0) = receiveData[1];
    }

}

/* Message Major: IVI */
/* Receive function of sub message SessionControlResponse */
void IPC_S2M_DiagnoseIVISessionControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVISessionControlResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Type, 0) = receiveData[1];
    }

}

/* Receive function of sub message DidReadResponse */
void IPC_S2M_DiagnoseIVIDidReadResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIDidReadResponse_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH>= payloadLength) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN <= payloadLength))
    {
        data->DataLength = (receiveData[0] << 8) | receiveData[1];
        if(data->DataLength <= IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(payloadLength == flexLength + IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = receiveData[2];
                IPC_GET_BYTE(data->Did, 1) = receiveData[3];
                IPC_GET_BYTE(data->Did, 0) = receiveData[4];
                IPC_GET_BYTE(data->TotalLength, 1) = receiveData[5];
                IPC_GET_BYTE(data->TotalLength, 0) = receiveData[6];
                IPC_GET_BYTE(data->Number, 0) = receiveData[7];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = receiveData[8 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

/* Receive function of sub message DidWriteResponse */
void IPC_S2M_DiagnoseIVIDidWriteResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIDidWriteResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Did, 1) = receiveData[1];
        IPC_GET_BYTE(data->Did, 0) = receiveData[2];
    }

}

/* Receive function of sub message IoControlResponse */
void IPC_S2M_DiagnoseIVIIoControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIIoControlResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_IOCONTROLRESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->DataId, 1) = receiveData[1];
        IPC_GET_BYTE(data->DataId, 0) = receiveData[2];
        IPC_GET_BYTE(data->Parameter, 0) = receiveData[3];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->State[arrIndex], 0) = receiveData[4 + arrIndex * 1];
            }
        }
    }

}

/* Receive function of sub message RoutineControlResponse */
void IPC_S2M_DiagnoseIVIRoutineControlResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIRoutineControlResponse_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH>= payloadLength) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN <= payloadLength))
    {
        data->StateLength = (receiveData[0] << 8) | receiveData[1];
        if(data->StateLength <= IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->StateLength * sizeof(data->State[0]);
            if(payloadLength == flexLength + IPC_S2M_DIAGNOSE_IVI_MSGSUB_ROUTINECONTROLRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ServiceId, 0) = receiveData[2];
                IPC_GET_BYTE(data->Type, 0) = receiveData[3];
                IPC_GET_BYTE(data->RoutineId, 1) = receiveData[4];
                IPC_GET_BYTE(data->RoutineId, 0) = receiveData[5];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->StateLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->State[arrIndex], 1) = receiveData[6 + arrIndex * 2];
                        IPC_GET_BYTE(data->State[arrIndex], 0) = receiveData[7 + arrIndex * 2];
                    }
                }
            }
        }
    }

}

/* Receive function of sub message ReportEventRequest */
void IPC_S2M_DiagnoseIVIReportEventRequest_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIReportEventRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 3; arrIndex++)
            {
                IPC_GET_BYTE(data->DtcCode[arrIndex], 0) = receiveData[1 + arrIndex * 1];
            }
        }
        IPC_GET_BYTE(data->Result, 0) = receiveData[4];
    }

}

/* Receive function of sub message DtcReinitResponse */
void IPC_S2M_DiagnoseIVIDtcReinitResponse_Receive(uint8_t *receiveData, IPC_S2M_DiagnoseIVIDtcReinitResponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DTCREINITRESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ServiceId, 0) = receiveData[0];
        IPC_GET_BYTE(data->Type, 0) = receiveData[1];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
