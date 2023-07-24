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
 *                 File:  IPC_Infra.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Infra source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Infra.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Infra */
/* Message Major: Misc */
/* Pack function of sub message RestoreFactorySettingResponse */
int32_t IPC_M2S_InfraMiscRestoreFactorySettingResponse_Pack(IPC_M2S_InfraMiscRestoreFactorySettingResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_M2S_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->Response, 0);
        totalLength = IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message RestoreFactorySettingResponse */
int32_t IPC_M2S_InfraMiscRestoreFactorySettingResponse_Parse(IPC_M2S_InfraMiscRestoreFactorySettingResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->Response, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ReadSerialNumberResponse */
int32_t IPC_M2S_InfraMiscReadSerialNumberResponse_Pack(IPC_M2S_InfraMiscReadSerialNumberResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_M2S_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_ID;
        if((data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[7 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message ReadSerialNumberResponse */
int32_t IPC_M2S_InfraMiscReadSerialNumberResponse_Parse(IPC_M2S_InfraMiscReadSerialNumberResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH >= length) &&
        (IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH_MIN)
            {
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[2 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message ReadVINNumberResponse */
int32_t IPC_M2S_InfraMiscReadVINNumberResponse_Pack(IPC_M2S_InfraMiscReadVINNumberResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_M2S_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_ID;
        if((data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[7 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message ReadVINNumberResponse */
int32_t IPC_M2S_InfraMiscReadVINNumberResponse_Parse(IPC_M2S_InfraMiscReadVINNumberResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH >= length) &&
        (IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH_MIN)
            {
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[2 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message ReadBeanIDResponse */
int32_t IPC_M2S_InfraMiscReadBeanIDResponse_Pack(IPC_M2S_InfraMiscReadBeanIDResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_M2S_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_ID;
        if((data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->Status, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[8 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message ReadBeanIDResponse */
int32_t IPC_M2S_InfraMiscReadBeanIDResponse_Parse(IPC_M2S_InfraMiscReadBeanIDResponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH >= length) &&
        (IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->Status, 0) = payload[2];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[3 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message RestoreFactorySettingRequset */
int32_t IPC_S2M_InfraMiscRestoreFactorySettingRequset_Pack(IPC_S2M_InfraMiscRestoreFactorySettingRequset_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGREQUSET_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_S2M_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_S2M_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGREQUSET_ID;
        payload[5] = IPC_GET_BYTE(data->Request, 0);
        totalLength = IPC_S2M_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGREQUSET_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message RestoreFactorySettingRequset */
int32_t IPC_S2M_InfraMiscRestoreFactorySettingRequset_Parse(IPC_S2M_InfraMiscRestoreFactorySettingRequset_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGREQUSET_LENGTH == length))
    {
        IPC_GET_BYTE(data->Request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ReadSerialNumberRequest */
int32_t IPC_S2M_InfraMiscReadSerialNumberRequest_Pack(IPC_S2M_InfraMiscReadSerialNumberRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_INFRA_MISC_MSGSUB_READSERIALNUMBERREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_S2M_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_S2M_INFRA_MISC_MSGSUB_READSERIALNUMBERREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->Request, 0);
        totalLength = IPC_S2M_INFRA_MISC_MSGSUB_READSERIALNUMBERREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ReadSerialNumberRequest */
int32_t IPC_S2M_InfraMiscReadSerialNumberRequest_Parse(IPC_S2M_InfraMiscReadSerialNumberRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_READSERIALNUMBERREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->Request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ReadVINNumberRequest */
int32_t IPC_S2M_InfraMiscReadVINNumberRequest_Pack(IPC_S2M_InfraMiscReadVINNumberRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_INFRA_MISC_MSGSUB_READVINNUMBERREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_S2M_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_S2M_INFRA_MISC_MSGSUB_READVINNUMBERREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->Request, 0);
        totalLength = IPC_S2M_INFRA_MISC_MSGSUB_READVINNUMBERREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ReadVINNumberRequest */
int32_t IPC_S2M_InfraMiscReadVINNumberRequest_Parse(IPC_S2M_InfraMiscReadVINNumberRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_READVINNUMBERREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->Request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ReadBeanIDRequest */
int32_t IPC_S2M_InfraMiscReadBeanIDRequest_Pack(IPC_S2M_InfraMiscReadBeanIDRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_INFRA_MISC_MSGSUB_READBEANIDREQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_S2M_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_S2M_INFRA_MISC_MSGSUB_READBEANIDREQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->Request, 0);
        totalLength = IPC_S2M_INFRA_MISC_MSGSUB_READBEANIDREQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ReadBeanIDRequest */
int32_t IPC_S2M_InfraMiscReadBeanIDRequest_Parse(IPC_S2M_InfraMiscReadBeanIDRequest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_READBEANIDREQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->Request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SetAVASSwitchStatus */
int32_t IPC_S2M_InfraMiscSetAVASSwitchStatus_Pack(IPC_S2M_InfraMiscSetAVASSwitchStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_INFRA_MISC_MSGSUB_SETAVASSWITCHSTATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_INFRA_ID;
        payload[3] = IPC_S2M_INFRA_MSGMAJOR_MISC_ID;
        payload[4] = IPC_S2M_INFRA_MISC_MSGSUB_SETAVASSWITCHSTATUS_ID;
        payload[5] = IPC_GET_BYTE(data->Switch, 0);
        totalLength = IPC_S2M_INFRA_MISC_MSGSUB_SETAVASSWITCHSTATUS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SetAVASSwitchStatus */
int32_t IPC_S2M_InfraMiscSetAVASSwitchStatus_Parse(IPC_S2M_InfraMiscSetAVASSwitchStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_SETAVASSWITCHSTATUS_LENGTH == length))
    {
        IPC_GET_BYTE(data->Switch, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
