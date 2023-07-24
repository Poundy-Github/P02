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
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group HUD source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_HUD.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: HUD */
/* Message Major: Common */
/* Transmit function of sub message NvmConfigResponse */
int32_t IPC_M2S_HUDCommonNvmConfigResponse_Transmit(IPC_M2S_HUDCommonNvmConfigResponse_t *data)
{
    uint8_t payload[IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_HUD_ID;
        payload[1] = IPC_M2S_HUD_MSGMAJOR_COMMON_ID;
        payload[2] = IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_ID;
        payload[3] = IPC_GET_BYTE(data->WHUDSwitch, 0);
        payload[4] = IPC_GET_BYTE(data->DriverDisplaySwitch, 0);
        payload[5] = IPC_GET_BYTE(data->NaviDisplaySwitch, 0);
        payload[6] = IPC_GET_BYTE(data->PhoneDisplaySwitch, 0);
        payload[7] = IPC_GET_BYTE(data->DisplayRotationLevel, 0);
        payload[8] = IPC_GET_BYTE(data->DisplayHeightLevel, 0);
        payload[9] = IPC_GET_BYTE(data->DisplayBacklightSwitch, 0);
        payload[10] = IPC_GET_BYTE(data->DisplayBacklightLevel, 0);
        payload[11] = IPC_GET_BYTE(data->DisplayTheme, 0);
        payload[12] = IPC_GET_BYTE(data->DisplayFramework, 0);
        payload[13] = IPC_GET_BYTE(data->DisplayMode, 0);
        payload[14] = IPC_GET_BYTE(data->DriveMode, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message AliveMonitorMsgUploaded */
int32_t IPC_M2S_HUDCommonAliveMonitorMsgUploaded_Transmit(IPC_M2S_HUDCommonAliveMonitorMsgUploaded_t *data)
{
    uint8_t payload[IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_HUD_ID;
        payload[1] = IPC_M2S_HUD_MSGMAJOR_COMMON_ID;
        payload[2] = IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_ID;
        payload[3] = IPC_GET_BYTE(data->Status, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message NvmConfigRequset */
void IPC_S2M_HUDCommonNvmConfigRequset_Receive(uint8_t *receiveData, IPC_S2M_HUDCommonNvmConfigRequset_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_LENGTH)
        {
            payloadLength = IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->Request, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message SetNvmConfig */
void IPC_S2M_HUDCommonSetNvmConfig_Receive(uint8_t *receiveData, IPC_S2M_HUDCommonSetNvmConfig_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_LENGTH)
        {
            payloadLength = IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->WHUDSwitch, 0) = receiveBuffer[0];
        IPC_GET_BYTE(data->DriverDisplaySwitch, 0) = receiveBuffer[1];
        IPC_GET_BYTE(data->NaviDisplaySwitch, 0) = receiveBuffer[2];
        IPC_GET_BYTE(data->PhoneDisplaySwitch, 0) = receiveBuffer[3];
        IPC_GET_BYTE(data->DisplayRotationLevel, 0) = receiveBuffer[4];
        IPC_GET_BYTE(data->DisplayHeightLevel, 0) = receiveBuffer[5];
        IPC_GET_BYTE(data->DisplayBacklightSwitch, 0) = receiveBuffer[6];
        IPC_GET_BYTE(data->DisplayBacklightLevel, 0) = receiveBuffer[7];
        IPC_GET_BYTE(data->DisplayTheme, 0) = receiveBuffer[8];
        IPC_GET_BYTE(data->DisplayFramework, 0) = receiveBuffer[9];
        IPC_GET_BYTE(data->DisplayMode, 0) = receiveBuffer[10];
    }

}

/* Receive function of sub message AliveMsg */
void IPC_S2M_HUDCommonAliveMsg_Receive(uint8_t *receiveData, IPC_S2M_HUDCommonAliveMsg_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_LENGTH)
        {
            payloadLength = IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->Tick, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message WhudNvmSet */
void IPC_S2M_HUDCommonWhudNvmSet_Receive(uint8_t *receiveData, IPC_S2M_HUDCommonWhudNvmSet_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_LENGTH)
        {
            payloadLength = IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->Id, 0) = receiveBuffer[0];
        IPC_GET_BYTE(data->Value, 0) = receiveBuffer[1];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
