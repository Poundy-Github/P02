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
 *                 File:  INFRA_Engineer.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Engineer source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "INFRA_Engineer.h"

/* MCU to SOC Pack interface */
/* Group: Engineer */
/* Message Major: HMI */
/* Pack function of sub message ReadInfoResponse */
int32_t INFRA_S2A_EngineerHMIReadInfoResponse_Pack(INFRA_S2A_EngineerHMIReadInfoResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_LENGTH))
    {
        payload[0] = INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_ID;
        if((data->DataLength <= INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[1] = (uint8_t)(data->DataLength >> 8);
            payload[2] = (uint8_t)(data->DataLength);
            payload[3] = IPC_GET_BYTE(data->ModuleId, 0);
            payload[4] = IPC_GET_BYTE(data->InfoId, 1);
            payload[5] = IPC_GET_BYTE(data->InfoId, 0);
            payload[6] = IPC_GET_BYTE(data->Result, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[7 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_LENGTH_MIN + flexLength + 1;
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}

/* Pack function of sub message SetParaResponse */
int32_t INFRA_S2A_EngineerHMISetParaResponse_Pack(INFRA_S2A_EngineerHMISetParaResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_S2A_ENGINEER_HMI_MSGSUB_SETPARARESPONSE_LENGTH))
    {
        payload[0] = INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_ID;
        payload[1] = IPC_GET_BYTE(data->ModuleId, 0);
        payload[2] = IPC_GET_BYTE(data->InfoId, 1);
        payload[3] = IPC_GET_BYTE(data->InfoId, 0);
        payload[4] = IPC_GET_BYTE(data->Result, 0);
        totalLength = INFRA_S2A_ENGINEER_HMI_MSGSUB_SETPARARESPONSE_LENGTH + 1;
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* MCU to SOC Parse interface */
/* Group: Engineer */
/* Message Major: HMI */
/* Parse function of sub message ReadInfoResponse */
int32_t INFRA_S2A_EngineerHMIReadInfoResponse_Parse(INFRA_S2A_EngineerHMIReadInfoResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_LENGTH >= length) &&
        (INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + INFRA_S2A_ENGINEER_HMI_MSGSUB_READINFORESPONSE_LENGTH_MIN)
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

/* Parse function of sub message SetParaResponse */
int32_t INFRA_S2A_EngineerHMISetParaResponse_Parse(INFRA_S2A_EngineerHMISetParaResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (INFRA_S2A_ENGINEER_HMI_MSGSUB_SETPARARESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->ModuleId, 0) = payload[0];
        IPC_GET_BYTE(data->InfoId, 1) = payload[1];
        IPC_GET_BYTE(data->InfoId, 0) = payload[2];
        IPC_GET_BYTE(data->Result, 0) = payload[3];
        ret = 0;
    }
    return ret;
}

/* SOC to MCU Pack interface */
/* Group: Engineer */
/* Message Major: HMI */
/* Pack function of sub message ReadInfoRequest */
int32_t INFRA_A2S_EngineerHMIReadInfoRequest_Pack(INFRA_A2S_EngineerHMIReadInfoRequest_t *data, uint8_t *payload, uint16_t length) 
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_A2S_ENGINEER_HMI_MSGSUB_READINFOREQUEST_LENGTH))
    {
        payload[0] = INFRA_A2S_ENGINEER_HMI_MSGSUB_READINFOREQUEST_ID;
        payload[1] = IPC_GET_BYTE(data->ModuleId, 0);
        payload[2] = IPC_GET_BYTE(data->InfoId, 1);
        payload[3] = IPC_GET_BYTE(data->InfoId, 0);
        totalLength = INFRA_A2S_ENGINEER_HMI_MSGSUB_READINFOREQUEST_LENGTH + 1;
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Pack function of sub message SetParaRequest */
int32_t INFRA_A2S_EngineerHMISetParaRequest_Pack(INFRA_A2S_EngineerHMISetParaRequest_t *data, uint8_t *payload, uint16_t length) 
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_LENGTH))
    {
        payload[0] = INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_ID;
        payload[1] = (uint8_t)(data->DataLength >> 8);
        payload[2] = (uint8_t)(data->DataLength);
        payload[3] = IPC_GET_BYTE(data->ModuleId, 0);
        payload[4] = IPC_GET_BYTE(data->InfoId, 1);
        payload[5] = IPC_GET_BYTE(data->InfoId, 0);

        totalLength = INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_LENGTH_MIN  + 1;
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* SOC to MCU Parse interface */
/* Group: Engineer */
/* Message Major: HMI */
/* Parse function of sub message ReadInfoRequest */
int32_t INFRA_A2S_EngineerHMIReadInfoRequest_Parse(INFRA_A2S_EngineerHMIReadInfoRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (INFRA_A2S_ENGINEER_HMI_MSGSUB_READINFOREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->ModuleId, 0) = payload[0];
        IPC_GET_BYTE(data->InfoId, 1) = payload[1];
        IPC_GET_BYTE(data->InfoId, 0) = payload[2];
        ret = 0;
    }
    return ret;
}

/* Parse function of sub message SetParaRequest */
int32_t INFRA_A2S_EngineerHMISetParaRequest_Parse(INFRA_A2S_EngineerHMISetParaRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_LENGTH >= length) &&
        (INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + INFRA_A2S_ENGINEER_HMI_MSGSUB_SETPARAREQUEST_LENGTH_MIN)
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

