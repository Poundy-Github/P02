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
 *                 File:  IPC_Engineer.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Engineer source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Engineer.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Engineer */
/* Message Major: IVI */
/* Pack function of sub message ReadInfoResponse */
int32_t IPC_M2S_EngineerIVIReadInfoResponse_Pack(IPC_M2S_EngineerIVIReadInfoResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_ENGINEER_ID;
        payload[3] = IPC_M2S_ENGINEER_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_ID;
        if((data->DataLength <= IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->ModuleId, 0);
            payload[8] = IPC_GET_BYTE(data->InfoId, 1);
            payload[9] = IPC_GET_BYTE(data->InfoId, 0);
            payload[10] = IPC_GET_BYTE(data->Result, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[11 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message ReadInfoResponse */
int32_t IPC_M2S_EngineerIVIReadInfoResponse_Parse(IPC_M2S_EngineerIVIReadInfoResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH >= length) &&
        (IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ModuleId, 0) = payload[2];
                IPC_GET_BYTE(data->InfoId, 1) = payload[3];
                IPC_GET_BYTE(data->InfoId, 0) = payload[4];
                IPC_GET_BYTE(data->Result, 0) = payload[5];
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
/* Pack function of sub message SetParaResponse */
int32_t IPC_M2S_EngineerIVISetParaResponse_Pack(IPC_M2S_EngineerIVISetParaResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_ENGINEER_ID;
        payload[3] = IPC_M2S_ENGINEER_MSGMAJOR_IVI_ID;
        payload[4] = IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->ModuleId, 0);
        payload[6] = IPC_GET_BYTE(data->InfoId, 1);
        payload[7] = IPC_GET_BYTE(data->InfoId, 0);
        payload[8] = IPC_GET_BYTE(data->Result, 0);
        totalLength = IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SetParaResponse */
int32_t IPC_M2S_EngineerIVISetParaResponse_Parse(IPC_M2S_EngineerIVISetParaResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ModuleId, 0) = payload[0];
        IPC_GET_BYTE(data->InfoId, 1) = payload[1];
        IPC_GET_BYTE(data->InfoId, 0) = payload[2];
        IPC_GET_BYTE(data->Result, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ReadInfoRequest */
int32_t IPC_S2M_EngineerIVIReadInfoRequest_Pack(IPC_S2M_EngineerIVIReadInfoRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_ENGINEER_IVI_MSGSUB_READINFOREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_ENGINEER_ID;
        payload[3] = IPC_S2M_ENGINEER_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_ENGINEER_IVI_MSGSUB_READINFOREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->ModuleId, 0);
        payload[6] = IPC_GET_BYTE(data->InfoId, 1);
        payload[7] = IPC_GET_BYTE(data->InfoId, 0);
        totalLength = IPC_S2M_ENGINEER_IVI_MSGSUB_READINFOREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ReadInfoRequest */
int32_t IPC_S2M_EngineerIVIReadInfoRequest_Parse(IPC_S2M_EngineerIVIReadInfoRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_ENGINEER_IVI_MSGSUB_READINFOREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ModuleId, 0) = payload[0];
        IPC_GET_BYTE(data->InfoId, 1) = payload[1];
        IPC_GET_BYTE(data->InfoId, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SetParaRequest */
int32_t IPC_S2M_EngineerIVISetParaRequest_Pack(IPC_S2M_EngineerIVISetParaRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_ENGINEER_ID;
        payload[3] = IPC_S2M_ENGINEER_MSGMAJOR_IVI_ID;
        payload[4] = IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_ID;
        if((data->DataLength <= IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->ModuleId, 0);
            payload[8] = IPC_GET_BYTE(data->InfoId, 1);
            payload[9] = IPC_GET_BYTE(data->InfoId, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[10 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message SetParaRequest */
int32_t IPC_S2M_EngineerIVISetParaRequest_Parse(IPC_S2M_EngineerIVISetParaRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH >= length) &&
        (IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ModuleId, 0) = payload[2];
                IPC_GET_BYTE(data->InfoId, 1) = payload[3];
                IPC_GET_BYTE(data->InfoId, 0) = payload[4];
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
