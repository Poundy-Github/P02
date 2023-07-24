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
 *                 File:  IPC_SWUM.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group SWUM source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_SWUM.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: SWUM */
/* Message Major: SWUM_UDS */
/* Pack function of sub message SessionControlResponse */
int32_t IPC_M2S_SWUMSWUM_UDSSessionControlResponse_Pack(IPC_M2S_SWUMSWUM_UDSSessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_SWUM_ID;
        payload[3] = IPC_M2S_SWUM_MSGMAJOR_SWUM_UDS_ID;
        payload[4] = IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->Service, 0);
        payload[6] = IPC_GET_BYTE(data->SessionType, 0);
        totalLength = IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SessionControlResponse */
int32_t IPC_M2S_SWUMSWUM_UDSSessionControlResponse_Parse(IPC_M2S_SWUMSWUM_UDSSessionControlResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->Service, 0) = payload[0];
        IPC_GET_BYTE(data->SessionType, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Response */
int32_t IPC_M2S_SWUMSWUM_UDSResponse_Pack(IPC_M2S_SWUMSWUM_UDSResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_SWUM_ID;
        payload[3] = IPC_M2S_SWUM_MSGMAJOR_SWUM_UDS_ID;
        payload[4] = IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_ID;
        if((data->ResponseLength <= IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->ResponseLength >> 8);
            payload[6] = (uint8_t)(data->ResponseLength);
            payload[7] = IPC_GET_BYTE(data->SID, 0);
            flexLength = data->ResponseLength * sizeof(data->Response[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->ResponseLength; arrIndex++)
                {
                    payload[8 + arrIndex * 1] = IPC_GET_BYTE(data->Response[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message Response */
int32_t IPC_M2S_SWUMSWUM_UDSResponse_Parse(IPC_M2S_SWUMSWUM_UDSResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH >= length) &&
        (IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH_MIN <= length))
    {
        data->ResponseLength = (payload[0] << 8) | payload[1];
        if(data->ResponseLength <= IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->ResponseLength * sizeof(data->Response[0]);
            if(length == flexLength + IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->SID, 0) = payload[2];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->ResponseLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Response[arrIndex], 0) = payload[3 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message SessionControl */
int32_t IPC_S2M_SWUMSWUM_UDSSessionControl_Pack(IPC_S2M_SWUMSWUM_UDSSessionControl_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROL_LENGTH))
    {
        payload[2] = IPC_GROUP_SWUM_ID;
        payload[3] = IPC_S2M_SWUM_MSGMAJOR_SWUM_UDS_ID;
        payload[4] = IPC_S2M_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROL_ID;
        payload[5] = IPC_GET_BYTE(data->Service, 0);
        payload[6] = IPC_GET_BYTE(data->Type, 0);
        totalLength = IPC_S2M_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROL_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SessionControl */
int32_t IPC_S2M_SWUMSWUM_UDSSessionControl_Parse(IPC_S2M_SWUMSWUM_UDSSessionControl_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROL_LENGTH == length))
    {
        IPC_GET_BYTE(data->Service, 0) = payload[0];
        IPC_GET_BYTE(data->Type, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Request */
int32_t IPC_S2M_SWUMSWUM_UDSRequest_Pack(IPC_S2M_SWUMSWUM_UDSRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_SWUM_ID;
        payload[3] = IPC_S2M_SWUM_MSGMAJOR_SWUM_UDS_ID;
        payload[4] = IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_ID;
        if((data->RequestLength <= IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->RequestLength >> 8);
            payload[6] = (uint8_t)(data->RequestLength);
            payload[7] = IPC_GET_BYTE(data->SID, 0);
            flexLength = data->RequestLength * sizeof(data->Request[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->RequestLength; arrIndex++)
                {
                    payload[8 + arrIndex * 1] = IPC_GET_BYTE(data->Request[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message Request */
int32_t IPC_S2M_SWUMSWUM_UDSRequest_Parse(IPC_S2M_SWUMSWUM_UDSRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH >= length) &&
        (IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH_MIN <= length))
    {
        data->RequestLength = (payload[0] << 8) | payload[1];
        if(data->RequestLength <= IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->RequestLength * sizeof(data->Request[0]);
            if(length == flexLength + IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->SID, 0) = payload[2];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->RequestLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Request[arrIndex], 0) = payload[3 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
