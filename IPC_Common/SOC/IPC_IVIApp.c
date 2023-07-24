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
 *                 File:  IPC_IVIApp.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group IVIApp source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_IVIApp.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: IVIApp */
/* Message Major: Info */
/* Pack function of sub message ReadSettingSignalResp */
int32_t IPC_M2S_IVIAppInfoReadSettingSignalResp_Pack(IPC_M2S_IVIAppInfoReadSettingSignalResp_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH))
    {
        payload[2] = IPC_GROUP_IVIAPP_ID;
        payload[3] = IPC_M2S_IVIAPP_MSGMAJOR_INFO_ID;
        payload[4] = IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_ID;
        if((data->DataLength <= IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->ClientID, 3);
            payload[8] = IPC_GET_BYTE(data->ClientID, 2);
            payload[9] = IPC_GET_BYTE(data->ClientID, 1);
            payload[10] = IPC_GET_BYTE(data->ClientID, 0);
            payload[11] = IPC_GET_BYTE(data->ModuleID, 0);
            payload[12] = IPC_GET_BYTE(data->InfoID, 3);
            payload[13] = IPC_GET_BYTE(data->InfoID, 2);
            payload[14] = IPC_GET_BYTE(data->InfoID, 1);
            payload[15] = IPC_GET_BYTE(data->InfoID, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[16 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message ReadSettingSignalResp */
int32_t IPC_M2S_IVIAppInfoReadSettingSignalResp_Parse(IPC_M2S_IVIAppInfoReadSettingSignalResp_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH >= length) &&
        (IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ClientID, 3) = payload[2];
                IPC_GET_BYTE(data->ClientID, 2) = payload[3];
                IPC_GET_BYTE(data->ClientID, 1) = payload[4];
                IPC_GET_BYTE(data->ClientID, 0) = payload[5];
                IPC_GET_BYTE(data->ModuleID, 0) = payload[6];
                IPC_GET_BYTE(data->InfoID, 3) = payload[7];
                IPC_GET_BYTE(data->InfoID, 2) = payload[8];
                IPC_GET_BYTE(data->InfoID, 1) = payload[9];
                IPC_GET_BYTE(data->InfoID, 0) = payload[10];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[11 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message SetSettingSignalResp */
int32_t IPC_M2S_IVIAppInfoSetSettingSignalResp_Pack(IPC_M2S_IVIAppInfoSetSettingSignalResp_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH))
    {
        payload[2] = IPC_GROUP_IVIAPP_ID;
        payload[3] = IPC_M2S_IVIAPP_MSGMAJOR_INFO_ID;
        payload[4] = IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_ID;
        if((data->DataLength <= IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->ClientID, 3);
            payload[8] = IPC_GET_BYTE(data->ClientID, 2);
            payload[9] = IPC_GET_BYTE(data->ClientID, 1);
            payload[10] = IPC_GET_BYTE(data->ClientID, 0);
            payload[11] = IPC_GET_BYTE(data->ModuleID, 0);
            payload[12] = IPC_GET_BYTE(data->InfoID, 3);
            payload[13] = IPC_GET_BYTE(data->InfoID, 2);
            payload[14] = IPC_GET_BYTE(data->InfoID, 1);
            payload[15] = IPC_GET_BYTE(data->InfoID, 0);
            payload[16] = IPC_GET_BYTE(data->Result, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[17 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message SetSettingSignalResp */
int32_t IPC_M2S_IVIAppInfoSetSettingSignalResp_Parse(IPC_M2S_IVIAppInfoSetSettingSignalResp_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH >= length) &&
        (IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ClientID, 3) = payload[2];
                IPC_GET_BYTE(data->ClientID, 2) = payload[3];
                IPC_GET_BYTE(data->ClientID, 1) = payload[4];
                IPC_GET_BYTE(data->ClientID, 0) = payload[5];
                IPC_GET_BYTE(data->ModuleID, 0) = payload[6];
                IPC_GET_BYTE(data->InfoID, 3) = payload[7];
                IPC_GET_BYTE(data->InfoID, 2) = payload[8];
                IPC_GET_BYTE(data->InfoID, 1) = payload[9];
                IPC_GET_BYTE(data->InfoID, 0) = payload[10];
                IPC_GET_BYTE(data->Result, 0) = payload[11];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[12 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message ReadSettingSignalReq */
int32_t IPC_S2M_IVIAppInfoReadSettingSignalReq_Pack(IPC_S2M_IVIAppInfoReadSettingSignalReq_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALREQ_LENGTH))
    {
        payload[2] = IPC_GROUP_IVIAPP_ID;
        payload[3] = IPC_S2M_IVIAPP_MSGMAJOR_INFO_ID;
        payload[4] = IPC_S2M_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALREQ_ID;
        payload[5] = IPC_GET_BYTE(data->ClientID, 3);
        payload[6] = IPC_GET_BYTE(data->ClientID, 2);
        payload[7] = IPC_GET_BYTE(data->ClientID, 1);
        payload[8] = IPC_GET_BYTE(data->ClientID, 0);
        payload[9] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[10] = IPC_GET_BYTE(data->InfoID, 3);
        payload[11] = IPC_GET_BYTE(data->InfoID, 2);
        payload[12] = IPC_GET_BYTE(data->InfoID, 1);
        payload[13] = IPC_GET_BYTE(data->InfoID, 0);
        totalLength = IPC_S2M_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALREQ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ReadSettingSignalReq */
int32_t IPC_S2M_IVIAppInfoReadSettingSignalReq_Parse(IPC_S2M_IVIAppInfoReadSettingSignalReq_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALREQ_LENGTH == length))
    {
        IPC_GET_BYTE(data->ClientID, 3) = payload[0];
        IPC_GET_BYTE(data->ClientID, 2) = payload[1];
        IPC_GET_BYTE(data->ClientID, 1) = payload[2];
        IPC_GET_BYTE(data->ClientID, 0) = payload[3];
        IPC_GET_BYTE(data->ModuleID, 0) = payload[4];
        IPC_GET_BYTE(data->InfoID, 3) = payload[5];
        IPC_GET_BYTE(data->InfoID, 2) = payload[6];
        IPC_GET_BYTE(data->InfoID, 1) = payload[7];
        IPC_GET_BYTE(data->InfoID, 0) = payload[8];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SetSettingSignalReq */
int32_t IPC_S2M_IVIAppInfoSetSettingSignalReq_Pack(IPC_S2M_IVIAppInfoSetSettingSignalReq_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH))
    {
        payload[2] = IPC_GROUP_IVIAPP_ID;
        payload[3] = IPC_S2M_IVIAPP_MSGMAJOR_INFO_ID;
        payload[4] = IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_ID;
        if((data->DataLength <= IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->DataLength >> 8);
            payload[6] = (uint8_t)(data->DataLength);
            payload[7] = IPC_GET_BYTE(data->ClientID, 3);
            payload[8] = IPC_GET_BYTE(data->ClientID, 2);
            payload[9] = IPC_GET_BYTE(data->ClientID, 1);
            payload[10] = IPC_GET_BYTE(data->ClientID, 0);
            payload[11] = IPC_GET_BYTE(data->ModuleID, 0);
            payload[12] = IPC_GET_BYTE(data->InfoID, 3);
            payload[13] = IPC_GET_BYTE(data->InfoID, 2);
            payload[14] = IPC_GET_BYTE(data->InfoID, 1);
            payload[15] = IPC_GET_BYTE(data->InfoID, 0);
            flexLength = data->DataLength * sizeof(data->Data[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                {
                    payload[16 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message SetSettingSignalReq */
int32_t IPC_S2M_IVIAppInfoSetSettingSignalReq_Parse(IPC_S2M_IVIAppInfoSetSettingSignalReq_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH >= length) &&
        (IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH_MIN <= length))
    {
        data->DataLength = (payload[0] << 8) | payload[1];
        if(data->DataLength <= IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(length == flexLength + IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ClientID, 3) = payload[2];
                IPC_GET_BYTE(data->ClientID, 2) = payload[3];
                IPC_GET_BYTE(data->ClientID, 1) = payload[4];
                IPC_GET_BYTE(data->ClientID, 0) = payload[5];
                IPC_GET_BYTE(data->ModuleID, 0) = payload[6];
                IPC_GET_BYTE(data->InfoID, 3) = payload[7];
                IPC_GET_BYTE(data->InfoID, 2) = payload[8];
                IPC_GET_BYTE(data->InfoID, 1) = payload[9];
                IPC_GET_BYTE(data->InfoID, 0) = payload[10];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = payload[11 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
