/**********************************************************************************************************************
 *  Copyright (C) 2020 GWM Automotive Inc.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *  The code contains GWM Confidential Proprietary Information.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *                 File:  IPC_HUD.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group HUD source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_HUD.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: HUD */
/* Message Major: Common */
/* Pack function of sub message NvmConfigResponse */
int32_t IPC_M2S_HUDCommonNvmConfigResponse_Pack(IPC_M2S_HUDCommonNvmConfigResponse_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_LENGTH))
    {
        payload[2] = IPC_GROUP_HUD_ID;
        payload[3] = IPC_M2S_HUD_MSGMAJOR_COMMON_ID;
        payload[4] = IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_ID;
        payload[5] = IPC_GET_BYTE(in_data->WHUDSwitch, 0);
        payload[6] = IPC_GET_BYTE(in_data->DriverDisplaySwitch, 0);
        payload[7] = IPC_GET_BYTE(in_data->NaviDisplaySwitch, 0);
        payload[8] = IPC_GET_BYTE(in_data->PhoneDisplaySwitch, 0);
        payload[9] = IPC_GET_BYTE(in_data->DisplayRotationLevel, 0);
        payload[10] = IPC_GET_BYTE(in_data->DisplayHeightLevel, 0);
        payload[11] = IPC_GET_BYTE(in_data->DisplayBacklightSwitch, 0);
        payload[12] = IPC_GET_BYTE(in_data->DisplayBacklightLevel, 0);
        payload[13] = IPC_GET_BYTE(in_data->DisplayTheme, 0);
        payload[14] = IPC_GET_BYTE(in_data->DisplayFramework, 0);
        payload[15] = IPC_GET_BYTE(in_data->DisplayMode, 0);
        payload[16] = IPC_GET_BYTE(in_data->DriveMode, 0);
        totalLength = IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message NvmConfigResponse */
int32_t IPC_M2S_HUDCommonNvmConfigResponse_Parse(IPC_M2S_HUDCommonNvmConfigResponse_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_LENGTH)
        {
            length = IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->WHUDSwitch, 0) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->DriverDisplaySwitch, 0) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->NaviDisplaySwitch, 0) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->PhoneDisplaySwitch, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->DisplayRotationLevel, 0) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->DisplayHeightLevel, 0) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->DisplayBacklightSwitch, 0) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->DisplayBacklightLevel, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->DisplayTheme, 0) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->DisplayFramework, 0) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->DisplayMode, 0) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->DriveMode, 0) = receiveBuffer[11];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AliveMonitorMsgUploaded */
int32_t IPC_M2S_HUDCommonAliveMonitorMsgUploaded_Pack(IPC_M2S_HUDCommonAliveMonitorMsgUploaded_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_LENGTH))
    {
        payload[2] = IPC_GROUP_HUD_ID;
        payload[3] = IPC_M2S_HUD_MSGMAJOR_COMMON_ID;
        payload[4] = IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_ID;
        payload[5] = IPC_GET_BYTE(in_data->Status, 0);
        totalLength = IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message AliveMonitorMsgUploaded */
int32_t IPC_M2S_HUDCommonAliveMonitorMsgUploaded_Parse(IPC_M2S_HUDCommonAliveMonitorMsgUploaded_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_LENGTH)
        {
            length = IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Status, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message NvmConfigRequset */
int32_t IPC_S2M_HUDCommonNvmConfigRequset_Pack(IPC_S2M_HUDCommonNvmConfigRequset_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_LENGTH))
    {
        payload[2] = IPC_GROUP_HUD_ID;
        payload[3] = IPC_S2M_HUD_MSGMAJOR_COMMON_ID;
        payload[4] = IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_ID;
        payload[5] = IPC_GET_BYTE(in_data->Request, 0);
        totalLength = IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message NvmConfigRequset */
int32_t IPC_S2M_HUDCommonNvmConfigRequset_Parse(IPC_S2M_HUDCommonNvmConfigRequset_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->Request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SetNvmConfig */
int32_t IPC_S2M_HUDCommonSetNvmConfig_Pack(IPC_S2M_HUDCommonSetNvmConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_HUD_ID;
        payload[3] = IPC_S2M_HUD_MSGMAJOR_COMMON_ID;
        payload[4] = IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_ID;
        payload[5] = IPC_GET_BYTE(in_data->WHUDSwitch, 0);
        payload[6] = IPC_GET_BYTE(in_data->DriverDisplaySwitch, 0);
        payload[7] = IPC_GET_BYTE(in_data->NaviDisplaySwitch, 0);
        payload[8] = IPC_GET_BYTE(in_data->PhoneDisplaySwitch, 0);
        payload[9] = IPC_GET_BYTE(in_data->DisplayRotationLevel, 0);
        payload[10] = IPC_GET_BYTE(in_data->DisplayHeightLevel, 0);
        payload[11] = IPC_GET_BYTE(in_data->DisplayBacklightSwitch, 0);
        payload[12] = IPC_GET_BYTE(in_data->DisplayBacklightLevel, 0);
        payload[13] = IPC_GET_BYTE(in_data->DisplayTheme, 0);
        payload[14] = IPC_GET_BYTE(in_data->DisplayFramework, 0);
        payload[15] = IPC_GET_BYTE(in_data->DisplayMode, 0);
        totalLength = IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SetNvmConfig */
int32_t IPC_S2M_HUDCommonSetNvmConfig_Parse(IPC_S2M_HUDCommonSetNvmConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->WHUDSwitch, 0) = payload[0];
        IPC_GET_BYTE(in_data->DriverDisplaySwitch, 0) = payload[1];
        IPC_GET_BYTE(in_data->NaviDisplaySwitch, 0) = payload[2];
        IPC_GET_BYTE(in_data->PhoneDisplaySwitch, 0) = payload[3];
        IPC_GET_BYTE(in_data->DisplayRotationLevel, 0) = payload[4];
        IPC_GET_BYTE(in_data->DisplayHeightLevel, 0) = payload[5];
        IPC_GET_BYTE(in_data->DisplayBacklightSwitch, 0) = payload[6];
        IPC_GET_BYTE(in_data->DisplayBacklightLevel, 0) = payload[7];
        IPC_GET_BYTE(in_data->DisplayTheme, 0) = payload[8];
        IPC_GET_BYTE(in_data->DisplayFramework, 0) = payload[9];
        IPC_GET_BYTE(in_data->DisplayMode, 0) = payload[10];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AliveMsg */
int32_t IPC_S2M_HUDCommonAliveMsg_Pack(IPC_S2M_HUDCommonAliveMsg_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_LENGTH))
    {
        payload[2] = IPC_GROUP_HUD_ID;
        payload[3] = IPC_S2M_HUD_MSGMAJOR_COMMON_ID;
        payload[4] = IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_ID;
        payload[5] = IPC_GET_BYTE(in_data->Tick, 0);
        totalLength = IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message AliveMsg */
int32_t IPC_S2M_HUDCommonAliveMsg_Parse(IPC_S2M_HUDCommonAliveMsg_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->Tick, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message WhudNvmSet */
int32_t IPC_S2M_HUDCommonWhudNvmSet_Pack(IPC_S2M_HUDCommonWhudNvmSet_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_LENGTH))
    {
        payload[2] = IPC_GROUP_HUD_ID;
        payload[3] = IPC_S2M_HUD_MSGMAJOR_COMMON_ID;
        payload[4] = IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_ID;
        payload[5] = IPC_GET_BYTE(in_data->Id, 0);
        payload[6] = IPC_GET_BYTE(in_data->Value, 0);
        totalLength = IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message WhudNvmSet */
int32_t IPC_S2M_HUDCommonWhudNvmSet_Parse(IPC_S2M_HUDCommonWhudNvmSet_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->Id, 0) = payload[0];
        IPC_GET_BYTE(in_data->Value, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
