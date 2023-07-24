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
 *                 File:  IPC_SystemState.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group SystemState source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_SystemState.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: SystemState */
/* Message Major: SystemState */
/* Transmit function of sub message IVI_State */
int32_t IPC_M2S_SystemStateSystemStateIVI_State_Transmit(IPC_M2S_SystemStateSystemStateIVI_State_t *data)
{
    uint8_t payload[IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[1] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID;
        payload[2] = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_ID;
        payload[3] = IPC_GET_BYTE(data->IVI_State, 0);
        payload[4] = IPC_GET_BYTE(data->IVI_StateTransferRequest, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message HUDState */
int32_t IPC_M2S_SystemStateSystemStateHUDState_Transmit(IPC_M2S_SystemStateSystemStateHUDState_t *data)
{
    uint8_t payload[IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[1] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID;
        payload[2] = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_ID;
        payload[3] = IPC_GET_BYTE(data->HUD_State, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ConsoleState */
int32_t IPC_M2S_SystemStateSystemStateConsoleState_Transmit(IPC_M2S_SystemStateSystemStateConsoleState_t *data)
{
    uint8_t payload[IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[1] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID;
        payload[2] = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_ID;
        payload[3] = IPC_GET_BYTE(data->Console_State, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Message Major: MCU_Voltage */
/* Transmit function of sub message VoltategeValue */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltategeValue_Transmit(IPC_M2S_SystemStateMCU_VoltageVoltategeValue_t *data)
{
    uint8_t payload[IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[1] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_MCU_VOLTAGE_ID;
        payload[2] = IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_ID;
        payload[3] = IPC_GET_BYTE(data->VoltageValue, 3);
        payload[4] = IPC_GET_BYTE(data->VoltageValue, 2);
        payload[5] = IPC_GET_BYTE(data->VoltageValue, 1);
        payload[6] = IPC_GET_BYTE(data->VoltageValue, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message VoltageState */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltageState_Transmit(IPC_M2S_SystemStateMCU_VoltageVoltageState_t *data)
{
    uint8_t payload[IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[1] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_MCU_VOLTAGE_ID;
        payload[2] = IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_ID;
        payload[3] = IPC_GET_BYTE(data->VoltageState, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Message Major: MCU_Temperature */
/* Transmit function of sub message Temperature */
int32_t IPC_M2S_SystemStateMCU_TemperatureTemperature_Transmit(IPC_M2S_SystemStateMCU_TemperatureTemperature_t *data)
{
    uint8_t payload[IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[1] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_MCU_TEMPERATURE_ID;
        payload[2] = IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_ID;
        payload[3] = IPC_GET_BYTE(data->Temperature, 3);
        payload[4] = IPC_GET_BYTE(data->Temperature, 2);
        payload[5] = IPC_GET_BYTE(data->Temperature, 1);
        payload[6] = IPC_GET_BYTE(data->Temperature, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Message Major: KL15State */
/* Transmit function of sub message KL15State */
int32_t IPC_M2S_SystemStateKL15StateKL15State_Transmit(IPC_M2S_SystemStateKL15StateKL15State_t *data)
{
    uint8_t payload[IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[1] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_KL15STATE_ID;
        payload[2] = IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_ID;
        payload[3] = IPC_GET_BYTE(data->KL15State, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Receive function of sub message IVI_State */
void IPC_S2M_SystemStateSystemStateIVI_State_Receive(uint8_t *receiveData, IPC_S2M_SystemStateSystemStateIVI_State_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->TransferResponse, 0) = receiveData[0];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
