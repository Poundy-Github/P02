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
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group SystemState source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_SystemState.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: SystemState */
/* Message Major: SystemState */
/* Pack function of sub message IVI_State */
int32_t IPC_M2S_SystemStateSystemStateIVI_State_Pack(IPC_M2S_SystemStateSystemStateIVI_State_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH))
    {
        payload[2] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[3] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID;
        payload[4] = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_ID;
        payload[5] = IPC_GET_BYTE(data->IVI_State, 0);
        payload[6] = IPC_GET_BYTE(data->IVI_StateTransferRequest, 0);
        totalLength = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message IVI_State */
int32_t IPC_M2S_SystemStateSystemStateIVI_State_Parse(IPC_M2S_SystemStateSystemStateIVI_State_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->IVI_State, 0) = payload[0];
        IPC_GET_BYTE(data->IVI_StateTransferRequest, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message HUDState */
int32_t IPC_M2S_SystemStateSystemStateHUDState_Pack(IPC_M2S_SystemStateSystemStateHUDState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH))
    {
        payload[2] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[3] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID;
        payload[4] = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_ID;
        payload[5] = IPC_GET_BYTE(data->HUD_State, 0);
        totalLength = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message HUDState */
int32_t IPC_M2S_SystemStateSystemStateHUDState_Parse(IPC_M2S_SystemStateSystemStateHUDState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->HUD_State, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ConsoleState */
int32_t IPC_M2S_SystemStateSystemStateConsoleState_Pack(IPC_M2S_SystemStateSystemStateConsoleState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH))
    {
        payload[2] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[3] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID;
        payload[4] = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_ID;
        payload[5] = IPC_GET_BYTE(data->Console_State, 0);
        totalLength = IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ConsoleState */
int32_t IPC_M2S_SystemStateSystemStateConsoleState_Parse(IPC_M2S_SystemStateSystemStateConsoleState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->Console_State, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: MCU_Voltage */
/* Pack function of sub message VoltategeValue */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltategeValue_Pack(IPC_M2S_SystemStateMCU_VoltageVoltategeValue_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_LENGTH))
    {
        payload[2] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[3] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_MCU_VOLTAGE_ID;
        payload[4] = IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_ID;
        payload[5] = IPC_GET_BYTE(data->VoltageValue, 3);
        payload[6] = IPC_GET_BYTE(data->VoltageValue, 2);
        payload[7] = IPC_GET_BYTE(data->VoltageValue, 1);
        payload[8] = IPC_GET_BYTE(data->VoltageValue, 0);
        totalLength = IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message VoltategeValue */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltategeValue_Parse(IPC_M2S_SystemStateMCU_VoltageVoltategeValue_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_LENGTH == length))
    {
        IPC_GET_BYTE(data->VoltageValue, 3) = payload[0];
        IPC_GET_BYTE(data->VoltageValue, 2) = payload[1];
        IPC_GET_BYTE(data->VoltageValue, 1) = payload[2];
        IPC_GET_BYTE(data->VoltageValue, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message VoltageState */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltageState_Pack(IPC_M2S_SystemStateMCU_VoltageVoltageState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_LENGTH))
    {
        payload[2] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[3] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_MCU_VOLTAGE_ID;
        payload[4] = IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_ID;
        payload[5] = IPC_GET_BYTE(data->VoltageState, 0);
        totalLength = IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message VoltageState */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltageState_Parse(IPC_M2S_SystemStateMCU_VoltageVoltageState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->VoltageState, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: MCU_Temperature */
/* Pack function of sub message Temperature */
int32_t IPC_M2S_SystemStateMCU_TemperatureTemperature_Pack(IPC_M2S_SystemStateMCU_TemperatureTemperature_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_LENGTH))
    {
        payload[2] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[3] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_MCU_TEMPERATURE_ID;
        payload[4] = IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_ID;
        payload[5] = IPC_GET_BYTE(data->Temperature, 3);
        payload[6] = IPC_GET_BYTE(data->Temperature, 2);
        payload[7] = IPC_GET_BYTE(data->Temperature, 1);
        payload[8] = IPC_GET_BYTE(data->Temperature, 0);
        totalLength = IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Temperature */
int32_t IPC_M2S_SystemStateMCU_TemperatureTemperature_Parse(IPC_M2S_SystemStateMCU_TemperatureTemperature_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_LENGTH == length))
    {
        IPC_GET_BYTE(data->Temperature, 3) = payload[0];
        IPC_GET_BYTE(data->Temperature, 2) = payload[1];
        IPC_GET_BYTE(data->Temperature, 1) = payload[2];
        IPC_GET_BYTE(data->Temperature, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Message Major: KL15State */
/* Pack function of sub message KL15State */
int32_t IPC_M2S_SystemStateKL15StateKL15State_Pack(IPC_M2S_SystemStateKL15StateKL15State_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_LENGTH))
    {
        payload[2] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[3] = IPC_M2S_SYSTEMSTATE_MSGMAJOR_KL15STATE_ID;
        payload[4] = IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_ID;
        payload[5] = IPC_GET_BYTE(data->KL15State, 0);
        totalLength = IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message KL15State */
int32_t IPC_M2S_SystemStateKL15StateKL15State_Parse(IPC_M2S_SystemStateKL15StateKL15State_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->KL15State, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message IVI_State */
int32_t IPC_S2M_SystemStateSystemStateIVI_State_Pack(IPC_S2M_SystemStateSystemStateIVI_State_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH))
    {
        payload[2] = IPC_GROUP_SYSTEMSTATE_ID;
        payload[3] = IPC_S2M_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID;
        payload[4] = IPC_S2M_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_ID;
        payload[5] = IPC_GET_BYTE(data->TransferResponse, 0);
        totalLength = IPC_S2M_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message IVI_State */
int32_t IPC_S2M_SystemStateSystemStateIVI_State_Parse(IPC_S2M_SystemStateSystemStateIVI_State_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->TransferResponse, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
