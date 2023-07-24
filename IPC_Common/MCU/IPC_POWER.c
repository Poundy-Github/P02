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
 *                 File:  IPC_POWER.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group POWER source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_POWER.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: POWER */
/* Message Major: SocManager */
/* Transmit function of sub message HandshakeResponse */
int32_t IPC_M2S_POWERSocManagerHandshakeResponse_Transmit(IPC_M2S_POWERSocManagerHandshakeResponse_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SOCMANAGER_ID;
        payload[2] = IPC_M2S_POWER_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->u8Reserved[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message MCURequestQnxService */
int32_t IPC_M2S_POWERSocManagerMCURequestQnxService_Transmit(IPC_M2S_POWERSocManagerMCURequestQnxService_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SOCMANAGER_MSGSUB_MCUREQUESTQNXSERVICE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SOCMANAGER_ID;
        payload[2] = IPC_M2S_POWER_SOCMANAGER_MSGSUB_MCUREQUESTQNXSERVICE_ID;
        payload[3] = IPC_GET_BYTE(data->MCURequestQnxService, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SOCMANAGER_MSGSUB_MCUREQUESTQNXSERVICE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Version */
int32_t IPC_M2S_POWERSocManagerVersion_Transmit(IPC_M2S_POWERSocManagerVersion_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SOCMANAGER_MSGSUB_VERSION_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SOCMANAGER_ID;
        payload[2] = IPC_M2S_POWER_SOCMANAGER_MSGSUB_VERSION_ID;
        payload[3] = IPC_GET_BYTE(data->HwVersion, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SOCMANAGER_MSGSUB_VERSION_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message HeathResponse */
int32_t IPC_M2S_POWERSocManagerHeathResponse_Transmit(IPC_M2S_POWERSocManagerHeathResponse_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SOCMANAGER_MSGSUB_HEATHRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SOCMANAGER_ID;
        payload[2] = IPC_M2S_POWER_SOCMANAGER_MSGSUB_HEATHRESPONSE_ID;
        payload[3] = IPC_GET_BYTE(data->u8Reserved, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SOCMANAGER_MSGSUB_HEATHRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Message Major: SystemState */
/* Transmit function of sub message IVI_State */
int32_t IPC_M2S_POWERSystemStateIVI_State_Transmit(IPC_M2S_POWERSystemStateIVI_State_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SYSTEMSTATE_ID;
        payload[2] = IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_ID;
        payload[3] = IPC_GET_BYTE(data->IVI_State, 0);
        payload[4] = IPC_GET_BYTE(data->Force, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message HUDState */
int32_t IPC_M2S_POWERSystemStateHUDState_Transmit(IPC_M2S_POWERSystemStateHUDState_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SYSTEMSTATE_ID;
        payload[2] = IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_HUDSTATE_ID;
        payload[3] = IPC_GET_BYTE(data->HUD_State, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ConsoleState */
int32_t IPC_M2S_POWERSystemStateConsoleState_Transmit(IPC_M2S_POWERSystemStateConsoleState_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SYSTEMSTATE_ID;
        payload[2] = IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CONSOLESTATE_ID;
        payload[3] = IPC_GET_BYTE(data->Console_State, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ClusterState */
int32_t IPC_M2S_POWERSystemStateClusterState_Transmit(IPC_M2S_POWERSystemStateClusterState_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CLUSTERSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SYSTEMSTATE_ID;
        payload[2] = IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CLUSTERSTATE_ID;
        payload[3] = IPC_GET_BYTE(data->ClusterState, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CLUSTERSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message MCUState */
int32_t IPC_M2S_POWERSystemStateMCUState_Transmit(IPC_M2S_POWERSystemStateMCUState_t *data)
{
    uint8_t payload[IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_MCUSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_SYSTEMSTATE_ID;
        payload[2] = IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_MCUSTATE_ID;
        payload[3] = IPC_GET_BYTE(data->MCUState, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_MCUSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Message Major: PowerInfo */
/* Transmit function of sub message VoltategeInfo */
int32_t IPC_M2S_POWERPowerInfoVoltategeInfo_Transmit(IPC_M2S_POWERPowerInfoVoltategeInfo_t *data)
{
    uint8_t payload[IPC_M2S_POWER_POWERINFO_MSGSUB_VOLTATEGEINFO_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_POWERINFO_ID;
        payload[2] = IPC_M2S_POWER_POWERINFO_MSGSUB_VOLTATEGEINFO_ID;
        payload[3] = IPC_GET_BYTE(data->VoltageValue, 3);
        payload[4] = IPC_GET_BYTE(data->VoltageValue, 2);
        payload[5] = IPC_GET_BYTE(data->VoltageValue, 1);
        payload[6] = IPC_GET_BYTE(data->VoltageValue, 0);
        payload[7] = IPC_GET_BYTE(data->VoltageState, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_POWERINFO_MSGSUB_VOLTATEGEINFO_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Temperature */
int32_t IPC_M2S_POWERPowerInfoTemperature_Transmit(IPC_M2S_POWERPowerInfoTemperature_t *data)
{
    uint8_t payload[IPC_M2S_POWER_POWERINFO_MSGSUB_TEMPERATURE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_POWERINFO_ID;
        payload[2] = IPC_M2S_POWER_POWERINFO_MSGSUB_TEMPERATURE_ID;
        payload[3] = IPC_GET_BYTE(data->Temperature, 3);
        payload[4] = IPC_GET_BYTE(data->Temperature, 2);
        payload[5] = IPC_GET_BYTE(data->Temperature, 1);
        payload[6] = IPC_GET_BYTE(data->Temperature, 0);
        payload[7] = IPC_GET_BYTE(data->TemperatureState, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_POWERINFO_MSGSUB_TEMPERATURE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message KL15State */
int32_t IPC_M2S_POWERPowerInfoKL15State_Transmit(IPC_M2S_POWERPowerInfoKL15State_t *data)
{
    uint8_t payload[IPC_M2S_POWER_POWERINFO_MSGSUB_KL15STATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_POWERINFO_ID;
        payload[2] = IPC_M2S_POWER_POWERINFO_MSGSUB_KL15STATE_ID;
        payload[3] = IPC_GET_BYTE(data->KL15State, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_POWERINFO_MSGSUB_KL15STATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message MCUInfo */
int32_t IPC_M2S_POWERPowerInfoMCUInfo_Transmit(IPC_M2S_POWERPowerInfoMCUInfo_t *data)
{
    uint8_t payload[IPC_M2S_POWER_POWERINFO_MSGSUB_MCUINFO_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_POWERINFO_ID;
        payload[2] = IPC_M2S_POWER_POWERINFO_MSGSUB_MCUINFO_ID;
        payload[3] = IPC_GET_BYTE(data->ResetType, 0);
        payload[4] = IPC_GET_BYTE(data->WakeupSource, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_POWERINFO_MSGSUB_MCUINFO_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message FOTAACK */
int32_t IPC_M2S_POWERPowerInfoFOTAACK_Transmit(IPC_M2S_POWERPowerInfoFOTAACK_t *data)
{
    uint8_t payload[IPC_M2S_POWER_POWERINFO_MSGSUB_FOTAACK_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_POWERINFO_ID;
        payload[2] = IPC_M2S_POWER_POWERINFO_MSGSUB_FOTAACK_ID;
        payload[3] = IPC_GET_BYTE(data->StsACK, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_POWERINFO_MSGSUB_FOTAACK_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message APP_INFOMS */
int32_t IPC_M2S_POWERPowerInfoAPP_INFOMS_Transmit(IPC_M2S_POWERPowerInfoAPP_INFOMS_t *data)
{
    uint8_t payload[IPC_M2S_POWER_POWERINFO_MSGSUB_APP_INFOMS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_POWER_ID;
        payload[1] = IPC_M2S_POWER_MSGMAJOR_POWERINFO_ID;
        payload[2] = IPC_M2S_POWER_POWERINFO_MSGSUB_APP_INFOMS_ID;
        payload[3] = IPC_GET_BYTE(data->type, 0);
        payload[4] = IPC_GET_BYTE(data->value, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_POWER_POWERINFO_MSGSUB_APP_INFOMS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* MCU to SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: POWER */
/* Message Major: SocManager */
/* Receive function of sub message HandshakeRequest */
void IPC_S2M_POWERSocManagerHandshakeRequest_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerHandshakeRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH == payloadLength))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->u8Reserved[arrIndex], 0) = receiveData[0 + arrIndex * 1];
            }
        }
    }

}

/* Receive function of sub message Heath */
void IPC_S2M_POWERSocManagerHeath_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerHeath_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SOCMANAGER_MSGSUB_HEATH_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->u8Reserved, 0) = receiveData[0];
    }

}

/* Receive function of sub message Reset */
void IPC_S2M_POWERSocManagerReset_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerReset_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SOCMANAGER_MSGSUB_RESET_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->u8Parameter, 0) = receiveData[0];
        IPC_GET_BYTE(data->u8Describe, 0) = receiveData[1];
    }

}

/* Receive function of sub message QnxResponseMCURequest */
void IPC_S2M_POWERSocManagerQnxResponseMCURequest_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerQnxResponseMCURequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXRESPONSEMCUREQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->QnxResponseMCURequest, 0) = receiveData[0];
    }

}

/* Receive function of sub message QnxInfoMCUSystem */
void IPC_S2M_POWERSocManagerQnxInfoMCUSystem_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerQnxInfoMCUSystem_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXINFOMCUSYSTEM_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->u8Parameter, 0) = receiveData[0];
    }

}

/* Receive function of sub message QnxQueryVersion */
void IPC_S2M_POWERSocManagerQnxQueryVersion_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerQnxQueryVersion_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXQUERYVERSION_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->u8Reserved, 0) = receiveData[0];
    }

}

/* Receive function of sub message PowerOFFReady */
void IPC_S2M_POWERSocManagerPowerOFFReady_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerPowerOFFReady_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SOCMANAGER_MSGSUB_POWEROFFREADY_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->u8Reserved, 0) = receiveData[0];
    }

}

/* Receive function of sub message Healthset */
void IPC_S2M_POWERSocManagerHealthset_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerHealthset_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SOCMANAGER_MSGSUB_HEALTHSET_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->u8Reserved, 0) = receiveData[0];
    }

}

/* Message Major: SystemState */
/* Receive function of sub message IVI_State */
void IPC_S2M_POWERSystemStateIVI_State_Receive(uint8_t *receiveData, IPC_S2M_POWERSystemStateIVI_State_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->TransferResponse, 0) = receiveData[0];
    }

}

/* Receive function of sub message FOTASts */
void IPC_S2M_POWERSystemStateFOTASts_Receive(uint8_t *receiveData, IPC_S2M_POWERSystemStateFOTASts_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_FOTASTS_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->State, 0) = receiveData[0];
    }

}

/* Receive function of sub message GetSMSts */
void IPC_S2M_POWERSystemStateGetSMSts_Receive(uint8_t *receiveData, IPC_S2M_POWERSystemStateGetSMSts_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_GETSMSTS_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->State, 0) = receiveData[0];
    }

}

/* Receive function of sub message APP_INFOSM */
void IPC_S2M_POWERSystemStateAPP_INFOSM_Receive(uint8_t *receiveData, IPC_S2M_POWERSystemStateAPP_INFOSM_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_APP_INFOSM_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->type, 0) = receiveData[0];
        IPC_GET_BYTE(data->value, 0) = receiveData[1];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
