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
*                 File:  IPC_SystemState.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_SOC.h.tem
*          Description:  IPC group SystemState  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_SYSTEMSTATE_H_
#define _IPC_SYSTEMSTATE_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_SYSTEMSTATE_ID                                                 (17u)

/* MCU to SOC Message major id */
#define IPC_M2S_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID                              (0u)
#define IPC_M2S_SYSTEMSTATE_MSGMAJOR_MCU_VOLTAGE_ID                              (1u)
#define IPC_M2S_SYSTEMSTATE_MSGMAJOR_MCU_TEMPERATURE_ID                          (2u)
#define IPC_M2S_SYSTEMSTATE_MSGMAJOR_KL15STATE_ID                                (3u)
/* MCU to SOC Message sub id */
#define IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_ID                      (0u)
#define IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_ID                       (1u)
#define IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_ID                   (2u)
#define IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_ID                 (0u)
#define IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_ID                   (1u)
#define IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_ID                (2u)
#define IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_ID                        (0u)
/* MCU to SOC Message sub length */
#define IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH                  (2u)
#define IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH                   (1u)
#define IPC_M2S_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH               (1u)
#define IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTATEGEVALUE_LENGTH             (4u)
#define IPC_M2S_SYSTEMSTATE_MCU_VOLTAGE_MSGSUB_VOLTAGESTATE_LENGTH               (1u)
#define IPC_M2S_SYSTEMSTATE_MCU_TEMPERATURE_MSGSUB_TEMPERATURE_LENGTH            (4u)
#define IPC_M2S_SYSTEMSTATE_KL15STATE_MSGSUB_KL15STATE_LENGTH                    (1u)
/* SOC to MCU Message major id */
#define IPC_S2M_SYSTEMSTATE_MSGMAJOR_SYSTEMSTATE_ID                              (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_ID                      (0u)
/* SOC to MCU Message sub length */
#define IPC_S2M_SYSTEMSTATE_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH                  (1u)
/* Group: : SystemState */
/* Message Major: SystemState */
/* Message Sub: IVI_State */
typedef struct
{
    /*0x0:IVI_OFF;0x1:IVI_Standby;0x2:IVI_ON;0x3:IVI_Startup;0x4:IVI_Shutdown;0x5:IVI_Normal;0x6:IVI_Power_Err;0x7:IVI_PowerSave1;0x8:IVI_PowerSave2;0x9:IVI_Local
    当IVI_OFF切换到IVI_Startup是，通过 IVI_StateTransferRequest 发送standby，等待IVI 反馈，收到Done后，切换到standby，镜像，当standby切到shutdown时，发送请求，等到IVI反馈*/
    uint8_t IVI_State;
    /*0x1:Standby;0x2:OFF*/
    uint8_t IVI_StateTransferRequest;
}IPC_M2S_SystemStateSystemStateIVI_State_t;

/* Pack function of sub message IVI_State */
int32_t IPC_M2S_SystemStateSystemStateIVI_State_Pack(IPC_M2S_SystemStateSystemStateIVI_State_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IVI_State */
int32_t IPC_M2S_SystemStateSystemStateIVI_State_Parse(IPC_M2S_SystemStateSystemStateIVI_State_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: HUDState */
typedef struct
{
    uint8_t HUD_State;
}IPC_M2S_SystemStateSystemStateHUDState_t;

/* Pack function of sub message HUDState */
int32_t IPC_M2S_SystemStateSystemStateHUDState_Pack(IPC_M2S_SystemStateSystemStateHUDState_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message HUDState */
int32_t IPC_M2S_SystemStateSystemStateHUDState_Parse(IPC_M2S_SystemStateSystemStateHUDState_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: ConsoleState */
typedef struct
{
    /*0x0:console off;0x1:console standby;0x2:console on*/
    uint8_t Console_State;
}IPC_M2S_SystemStateSystemStateConsoleState_t;

/* Pack function of sub message ConsoleState */
int32_t IPC_M2S_SystemStateSystemStateConsoleState_Pack(IPC_M2S_SystemStateSystemStateConsoleState_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ConsoleState */
int32_t IPC_M2S_SystemStateSystemStateConsoleState_Parse(IPC_M2S_SystemStateSystemStateConsoleState_t *data, uint8_t *payload, uint16_t length);

/* Group: : SystemState */
/* Message Major: MCU_Voltage */
/* Message Sub: VoltategeValue */
typedef struct
{
    float VoltageValue;
}IPC_M2S_SystemStateMCU_VoltageVoltategeValue_t;

/* Pack function of sub message VoltategeValue */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltategeValue_Pack(IPC_M2S_SystemStateMCU_VoltageVoltategeValue_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message VoltategeValue */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltategeValue_Parse(IPC_M2S_SystemStateMCU_VoltageVoltategeValue_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: VoltageState */
typedef struct
{
    /*0x0:low_sleep;0x1:normal;0x2: high_alarm;0x3:high_sleep*/
    uint8_t VoltageState;
}IPC_M2S_SystemStateMCU_VoltageVoltageState_t;

/* Pack function of sub message VoltageState */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltageState_Pack(IPC_M2S_SystemStateMCU_VoltageVoltageState_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message VoltageState */
int32_t IPC_M2S_SystemStateMCU_VoltageVoltageState_Parse(IPC_M2S_SystemStateMCU_VoltageVoltageState_t *data, uint8_t *payload, uint16_t length);

/* Group: : SystemState */
/* Message Major: MCU_Temperature */
/* Message Sub: Temperature */
typedef struct
{
    float Temperature;
}IPC_M2S_SystemStateMCU_TemperatureTemperature_t;

/* Pack function of sub message Temperature */
int32_t IPC_M2S_SystemStateMCU_TemperatureTemperature_Pack(IPC_M2S_SystemStateMCU_TemperatureTemperature_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Temperature */
int32_t IPC_M2S_SystemStateMCU_TemperatureTemperature_Parse(IPC_M2S_SystemStateMCU_TemperatureTemperature_t *data, uint8_t *payload, uint16_t length);

/* Group: : SystemState */
/* Message Major: KL15State */
/* Message Sub: KL15State */
typedef struct
{
    /*0x0:KL15 OFF ; 0x1:KL15 ON*/
    uint8_t KL15State;
}IPC_M2S_SystemStateKL15StateKL15State_t;

/* Pack function of sub message KL15State */
int32_t IPC_M2S_SystemStateKL15StateKL15State_Pack(IPC_M2S_SystemStateKL15StateKL15State_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message KL15State */
int32_t IPC_M2S_SystemStateKL15StateKL15State_Parse(IPC_M2S_SystemStateKL15StateKL15State_t *data, uint8_t *payload, uint16_t length);

/* Group: : SystemState */
/* Group: : SystemState */
/* Message Major: SystemState */
/* Message Sub: IVI_State */
typedef struct
{
    /*0x0:pending；0x1:done*/
    uint8_t TransferResponse;
}IPC_S2M_SystemStateSystemStateIVI_State_t;

/* Pack function of sub message IVI_State */
int32_t IPC_S2M_SystemStateSystemStateIVI_State_Pack(IPC_S2M_SystemStateSystemStateIVI_State_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IVI_State */
int32_t IPC_S2M_SystemStateSystemStateIVI_State_Parse(IPC_S2M_SystemStateSystemStateIVI_State_t *data, uint8_t *payload, uint16_t length);

/* Group: : SystemState */
#ifdef __cplusplus
}
#endif

#endif
