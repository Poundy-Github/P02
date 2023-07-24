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
 *                 File:  IPC_Misc.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Misc source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Misc.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Misc */
/* Message Major: RTC */
/* Pack function of sub message ACK */
int32_t IPC_M2S_MiscRTCACK_Pack(IPC_M2S_MiscRTCACK_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_RTC_MSGSUB_ACK_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_RTC_ID;
        payload[4] = IPC_M2S_MISC_RTC_MSGSUB_ACK_ID;
        payload[5] = IPC_GET_BYTE(data->States, 0);
        totalLength = IPC_M2S_MISC_RTC_MSGSUB_ACK_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ACK */
int32_t IPC_M2S_MiscRTCACK_Parse(IPC_M2S_MiscRTCACK_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_RTC_MSGSUB_ACK_LENGTH == length))
    {
        IPC_GET_BYTE(data->States, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TIME */
int32_t IPC_M2S_MiscRTCTIME_Pack(IPC_M2S_MiscRTCTIME_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_RTC_MSGSUB_TIME_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_RTC_ID;
        payload[4] = IPC_M2S_MISC_RTC_MSGSUB_TIME_ID;
        payload[5] = IPC_GET_BYTE(data->UTC_Time, 7);
        payload[6] = IPC_GET_BYTE(data->UTC_Time, 6);
        payload[7] = IPC_GET_BYTE(data->UTC_Time, 5);
        payload[8] = IPC_GET_BYTE(data->UTC_Time, 4);
        payload[9] = IPC_GET_BYTE(data->UTC_Time, 3);
        payload[10] = IPC_GET_BYTE(data->UTC_Time, 2);
        payload[11] = IPC_GET_BYTE(data->UTC_Time, 1);
        payload[12] = IPC_GET_BYTE(data->UTC_Time, 0);
        totalLength = IPC_M2S_MISC_RTC_MSGSUB_TIME_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message TIME */
int32_t IPC_M2S_MiscRTCTIME_Parse(IPC_M2S_MiscRTCTIME_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_RTC_MSGSUB_TIME_LENGTH == length))
    {
        IPC_GET_BYTE(data->UTC_Time, 7) = payload[0];
        IPC_GET_BYTE(data->UTC_Time, 6) = payload[1];
        IPC_GET_BYTE(data->UTC_Time, 5) = payload[2];
        IPC_GET_BYTE(data->UTC_Time, 4) = payload[3];
        IPC_GET_BYTE(data->UTC_Time, 3) = payload[4];
        IPC_GET_BYTE(data->UTC_Time, 2) = payload[5];
        IPC_GET_BYTE(data->UTC_Time, 1) = payload[6];
        IPC_GET_BYTE(data->UTC_Time, 0) = payload[7];
        ret = 0;
    }
    return ret;
}
/* Message Major: Service */
/* Pack function of sub message Reply */
int32_t IPC_M2S_MiscServiceReply_Pack(IPC_M2S_MiscServiceReply_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_ID;
        payload[5] = IPC_GET_BYTE(data->u8Channel, 0);
        totalLength = IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Reply */
int32_t IPC_M2S_MiscServiceReply_Parse(IPC_M2S_MiscServiceReply_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_LENGTH == length))
    {
        IPC_GET_BYTE(data->u8Channel, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Vconfig */
int32_t IPC_M2S_MiscServiceVconfig_Pack(IPC_M2S_MiscServiceVconfig_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 200; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Vconfig_Buffer[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Vconfig */
int32_t IPC_M2S_MiscServiceVconfig_Parse(IPC_M2S_MiscServiceVconfig_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 200; arrIndex++)
            {
                IPC_GET_BYTE(data->Vconfig_Buffer[arrIndex], 0) = payload[0 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TriggerMsg */
int32_t IPC_M2S_MiscServiceTriggerMsg_Pack(IPC_M2S_MiscServiceTriggerMsg_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_ID;
        payload[5] = IPC_GET_BYTE(data->TriggerSource, 0);
        payload[6] = IPC_GET_BYTE(data->Value, 1);
        payload[7] = IPC_GET_BYTE(data->Value, 0);
        totalLength = IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message TriggerMsg */
int32_t IPC_M2S_MiscServiceTriggerMsg_Parse(IPC_M2S_MiscServiceTriggerMsg_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_LENGTH == length))
    {
        IPC_GET_BYTE(data->TriggerSource, 0) = payload[0];
        IPC_GET_BYTE(data->Value, 1) = payload[1];
        IPC_GET_BYTE(data->Value, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Vreply_Usb */
int32_t IPC_M2S_MiscServiceVreply_Usb_Pack(IPC_M2S_MiscServiceVreply_Usb_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_ID;
        payload[5] = IPC_GET_BYTE(data->u8Channel, 0);
        totalLength = IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Vreply_Usb */
int32_t IPC_M2S_MiscServiceVreply_Usb_Parse(IPC_M2S_MiscServiceVreply_Usb_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_LENGTH == length))
    {
        IPC_GET_BYTE(data->u8Channel, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Cconfig */
int32_t IPC_M2S_MiscServiceCconfig_Pack(IPC_M2S_MiscServiceCconfig_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 300; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Cconfig_Buffer[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Cconfig */
int32_t IPC_M2S_MiscServiceCconfig_Parse(IPC_M2S_MiscServiceCconfig_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 300; arrIndex++)
            {
                IPC_GET_BYTE(data->Cconfig_Buffer[arrIndex], 0) = payload[0 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Offset */
int32_t IPC_M2S_MiscServiceOffset_Pack(IPC_M2S_MiscServiceOffset_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Offset_Buffer[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Offset */
int32_t IPC_M2S_MiscServiceOffset_Parse(IPC_M2S_MiscServiceOffset_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                IPC_GET_BYTE(data->Offset_Buffer[arrIndex], 0) = payload[0 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Message Major: IVIInfo */
/* Pack function of sub message ReadDrvModeResp */
int32_t IPC_M2S_MiscIVIInfoReadDrvModeResp_Pack(IPC_M2S_MiscIVIInfoReadDrvModeResp_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_IVIINFO_ID;
        payload[4] = IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_ID;
        payload[5] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[6] = IPC_GET_BYTE(data->InfoID, 1);
        payload[7] = IPC_GET_BYTE(data->InfoID, 0);
        payload[8] = IPC_GET_BYTE(data->Switch, 0);
        totalLength = IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ReadDrvModeResp */
int32_t IPC_M2S_MiscIVIInfoReadDrvModeResp_Parse(IPC_M2S_MiscIVIInfoReadDrvModeResp_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_LENGTH == length))
    {
        IPC_GET_BYTE(data->ModuleID, 0) = payload[0];
        IPC_GET_BYTE(data->InfoID, 1) = payload[1];
        IPC_GET_BYTE(data->InfoID, 0) = payload[2];
        IPC_GET_BYTE(data->Switch, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message WriteDrvModeResp */
int32_t IPC_M2S_MiscIVIInfoWriteDrvModeResp_Pack(IPC_M2S_MiscIVIInfoWriteDrvModeResp_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_M2S_MISC_MSGMAJOR_IVIINFO_ID;
        payload[4] = IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_ID;
        payload[5] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[6] = IPC_GET_BYTE(data->InfoID, 1);
        payload[7] = IPC_GET_BYTE(data->InfoID, 0);
        payload[8] = IPC_GET_BYTE(data->Result, 0);
        totalLength = IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message WriteDrvModeResp */
int32_t IPC_M2S_MiscIVIInfoWriteDrvModeResp_Parse(IPC_M2S_MiscIVIInfoWriteDrvModeResp_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_LENGTH == length))
    {
        IPC_GET_BYTE(data->ModuleID, 0) = payload[0];
        IPC_GET_BYTE(data->InfoID, 1) = payload[1];
        IPC_GET_BYTE(data->InfoID, 0) = payload[2];
        IPC_GET_BYTE(data->Result, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Get_Time_Request */
int32_t IPC_S2M_MiscRTCGet_Time_Request_Pack(IPC_S2M_MiscRTCGet_Time_Request_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_RTC_MSGSUB_GET_TIME_REQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_RTC_ID;
        payload[4] = IPC_S2M_MISC_RTC_MSGSUB_GET_TIME_REQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->Reserve, 0);
        totalLength = IPC_S2M_MISC_RTC_MSGSUB_GET_TIME_REQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Get_Time_Request */
int32_t IPC_S2M_MiscRTCGet_Time_Request_Parse(IPC_S2M_MiscRTCGet_Time_Request_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_RTC_MSGSUB_GET_TIME_REQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->Reserve, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Set_Time_Request */
int32_t IPC_S2M_MiscRTCSet_Time_Request_Pack(IPC_S2M_MiscRTCSet_Time_Request_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_RTC_MSGSUB_SET_TIME_REQUEST_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_RTC_ID;
        payload[4] = IPC_S2M_MISC_RTC_MSGSUB_SET_TIME_REQUEST_ID;
        payload[5] = IPC_GET_BYTE(data->UTC_Time, 7);
        payload[6] = IPC_GET_BYTE(data->UTC_Time, 6);
        payload[7] = IPC_GET_BYTE(data->UTC_Time, 5);
        payload[8] = IPC_GET_BYTE(data->UTC_Time, 4);
        payload[9] = IPC_GET_BYTE(data->UTC_Time, 3);
        payload[10] = IPC_GET_BYTE(data->UTC_Time, 2);
        payload[11] = IPC_GET_BYTE(data->UTC_Time, 1);
        payload[12] = IPC_GET_BYTE(data->UTC_Time, 0);
        totalLength = IPC_S2M_MISC_RTC_MSGSUB_SET_TIME_REQUEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Set_Time_Request */
int32_t IPC_S2M_MiscRTCSet_Time_Request_Parse(IPC_S2M_MiscRTCSet_Time_Request_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_RTC_MSGSUB_SET_TIME_REQUEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->UTC_Time, 7) = payload[0];
        IPC_GET_BYTE(data->UTC_Time, 6) = payload[1];
        IPC_GET_BYTE(data->UTC_Time, 5) = payload[2];
        IPC_GET_BYTE(data->UTC_Time, 4) = payload[3];
        IPC_GET_BYTE(data->UTC_Time, 3) = payload[4];
        IPC_GET_BYTE(data->UTC_Time, 2) = payload[5];
        IPC_GET_BYTE(data->UTC_Time, 1) = payload[6];
        IPC_GET_BYTE(data->UTC_Time, 0) = payload[7];
        ret = 0;
    }
    return ret;
}
/* Message Major: Service */
/* Pack function of sub message WirtChannel */
int32_t IPC_S2M_MiscServiceWirtChannel_Pack(IPC_S2M_MiscServiceWirtChannel_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_SERVICE_MSGSUB_WIRTCHANNEL_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_S2M_MISC_SERVICE_MSGSUB_WIRTCHANNEL_ID;
        payload[5] = IPC_GET_BYTE(data->u8Channel, 0);
        payload[6] = IPC_GET_BYTE(data->u8Level, 0);
        totalLength = IPC_S2M_MISC_SERVICE_MSGSUB_WIRTCHANNEL_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message WirtChannel */
int32_t IPC_S2M_MiscServiceWirtChannel_Parse(IPC_S2M_MiscServiceWirtChannel_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_WIRTCHANNEL_LENGTH == length))
    {
        IPC_GET_BYTE(data->u8Channel, 0) = payload[0];
        IPC_GET_BYTE(data->u8Level, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Get_Vconfig */
int32_t IPC_S2M_MiscServiceGet_Vconfig_Pack(IPC_S2M_MiscServiceGet_Vconfig_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_SERVICE_MSGSUB_GET_VCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_S2M_MISC_SERVICE_MSGSUB_GET_VCONFIG_ID;
        payload[5] = IPC_GET_BYTE(data->request, 0);
        totalLength = IPC_S2M_MISC_SERVICE_MSGSUB_GET_VCONFIG_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Get_Vconfig */
int32_t IPC_S2M_MiscServiceGet_Vconfig_Parse(IPC_S2M_MiscServiceGet_Vconfig_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_GET_VCONFIG_LENGTH == length))
    {
        IPC_GET_BYTE(data->request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Vconfig_Reponse */
int32_t IPC_S2M_MiscServiceVconfig_Reponse_Pack(IPC_S2M_MiscServiceVconfig_Reponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_REPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_REPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->result, 0);
        totalLength = IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_REPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Vconfig_Reponse */
int32_t IPC_S2M_MiscServiceVconfig_Reponse_Parse(IPC_S2M_MiscServiceVconfig_Reponse_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_REPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->result, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message CheckTriggerMsg */
int32_t IPC_S2M_MiscServiceCheckTriggerMsg_Pack(IPC_S2M_MiscServiceCheckTriggerMsg_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_SERVICE_MSGSUB_CHECKTRIGGERMSG_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_S2M_MISC_SERVICE_MSGSUB_CHECKTRIGGERMSG_ID;
        payload[5] = IPC_GET_BYTE(data->TriggerSource, 0);
        totalLength = IPC_S2M_MISC_SERVICE_MSGSUB_CHECKTRIGGERMSG_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message CheckTriggerMsg */
int32_t IPC_S2M_MiscServiceCheckTriggerMsg_Parse(IPC_S2M_MiscServiceCheckTriggerMsg_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_CHECKTRIGGERMSG_LENGTH == length))
    {
        IPC_GET_BYTE(data->TriggerSource, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Cconfig_Response */
int32_t IPC_S2M_MiscServiceCconfig_Response_Pack(IPC_S2M_MiscServiceCconfig_Response_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_SERVICE_MSGSUB_CCONFIG_RESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_S2M_MISC_SERVICE_MSGSUB_CCONFIG_RESPONSE_ID;
        payload[5] = IPC_GET_BYTE(data->result, 0);
        totalLength = IPC_S2M_MISC_SERVICE_MSGSUB_CCONFIG_RESPONSE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Cconfig_Response */
int32_t IPC_S2M_MiscServiceCconfig_Response_Parse(IPC_S2M_MiscServiceCconfig_Response_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_CCONFIG_RESPONSE_LENGTH == length))
    {
        IPC_GET_BYTE(data->result, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Vconfig_Usb */
int32_t IPC_S2M_MiscServiceVconfig_Usb_Pack(IPC_S2M_MiscServiceVconfig_Usb_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_USB_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_USB_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 200; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Vconfig_Usb_Buffer[arrIndex], 0);
            }
        }
        totalLength = IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_USB_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Vconfig_Usb */
int32_t IPC_S2M_MiscServiceVconfig_Usb_Parse(IPC_S2M_MiscServiceVconfig_Usb_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_USB_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 200; arrIndex++)
            {
                IPC_GET_BYTE(data->Vconfig_Usb_Buffer[arrIndex], 0) = payload[0 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Get_Cconfig */
int32_t IPC_S2M_MiscServiceGet_Cconfig_Pack(IPC_S2M_MiscServiceGet_Cconfig_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_SERVICE_MSGSUB_GET_CCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_S2M_MISC_SERVICE_MSGSUB_GET_CCONFIG_ID;
        payload[5] = IPC_GET_BYTE(data->request, 0);
        totalLength = IPC_S2M_MISC_SERVICE_MSGSUB_GET_CCONFIG_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Get_Cconfig */
int32_t IPC_S2M_MiscServiceGet_Cconfig_Parse(IPC_S2M_MiscServiceGet_Cconfig_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_GET_CCONFIG_LENGTH == length))
    {
        IPC_GET_BYTE(data->request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Get_Offset */
int32_t IPC_S2M_MiscServiceGet_Offset_Pack(IPC_S2M_MiscServiceGet_Offset_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_SERVICE_MSGSUB_GET_OFFSET_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_SERVICE_ID;
        payload[4] = IPC_S2M_MISC_SERVICE_MSGSUB_GET_OFFSET_ID;
        payload[5] = IPC_GET_BYTE(data->request, 0);
        totalLength = IPC_S2M_MISC_SERVICE_MSGSUB_GET_OFFSET_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Get_Offset */
int32_t IPC_S2M_MiscServiceGet_Offset_Parse(IPC_S2M_MiscServiceGet_Offset_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_GET_OFFSET_LENGTH == length))
    {
        IPC_GET_BYTE(data->request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: IVIInfo */
/* Pack function of sub message ReadDrvModeReq */
int32_t IPC_S2M_MiscIVIInfoReadDrvModeReq_Pack(IPC_S2M_MiscIVIInfoReadDrvModeReq_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_IVIINFO_MSGSUB_READDRVMODEREQ_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_IVIINFO_ID;
        payload[4] = IPC_S2M_MISC_IVIINFO_MSGSUB_READDRVMODEREQ_ID;
        payload[5] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[6] = IPC_GET_BYTE(data->InfoID, 1);
        payload[7] = IPC_GET_BYTE(data->InfoID, 0);
        totalLength = IPC_S2M_MISC_IVIINFO_MSGSUB_READDRVMODEREQ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ReadDrvModeReq */
int32_t IPC_S2M_MiscIVIInfoReadDrvModeReq_Parse(IPC_S2M_MiscIVIInfoReadDrvModeReq_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_IVIINFO_MSGSUB_READDRVMODEREQ_LENGTH == length))
    {
        IPC_GET_BYTE(data->ModuleID, 0) = payload[0];
        IPC_GET_BYTE(data->InfoID, 1) = payload[1];
        IPC_GET_BYTE(data->InfoID, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message WriteDrvModeReq */
int32_t IPC_S2M_MiscIVIInfoWriteDrvModeReq_Pack(IPC_S2M_MiscIVIInfoWriteDrvModeReq_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_MISC_IVIINFO_MSGSUB_WRITEDRVMODEREQ_LENGTH))
    {
        payload[2] = IPC_GROUP_MISC_ID;
        payload[3] = IPC_S2M_MISC_MSGMAJOR_IVIINFO_ID;
        payload[4] = IPC_S2M_MISC_IVIINFO_MSGSUB_WRITEDRVMODEREQ_ID;
        payload[5] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[6] = IPC_GET_BYTE(data->InfoID, 1);
        payload[7] = IPC_GET_BYTE(data->InfoID, 0);
        payload[8] = IPC_GET_BYTE(data->Switch, 0);
        totalLength = IPC_S2M_MISC_IVIINFO_MSGSUB_WRITEDRVMODEREQ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message WriteDrvModeReq */
int32_t IPC_S2M_MiscIVIInfoWriteDrvModeReq_Parse(IPC_S2M_MiscIVIInfoWriteDrvModeReq_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_IVIINFO_MSGSUB_WRITEDRVMODEREQ_LENGTH == length))
    {
        IPC_GET_BYTE(data->ModuleID, 0) = payload[0];
        IPC_GET_BYTE(data->InfoID, 1) = payload[1];
        IPC_GET_BYTE(data->InfoID, 0) = payload[2];
        IPC_GET_BYTE(data->Switch, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
