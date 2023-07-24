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
*                 File:  INFRA_Sensors.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_SOC.h.tem
*          Description:  IPC group Sensor  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _INFRA_SENSOR_H_
#define _INFRA_SENSOR_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_SENSOR_ID                                                      (9u)

/* MCU to SOC Message major id */
#define INFRA_S2A_SENSOR_MSGMAJOR_IPC_ID                                           (0u)
/* MCU to SOC Message sub id */
#define INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORDATA_ID                                  (0u)
#define INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORSTATE_ID                                 (1u)
#define INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORREPLY_ID                                 (2u)
/* MCU to SOC Message sub length */
#define INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH                              (25u)
#define INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH                             (2u)
#define INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH                             (3u)
/* SOC to MCU Message major id */
#define INFRA_A2S_SENSOR_MSGMAJOR_IPC_ID                                           (0u)
/* SOC to MCU Message sub id */
#define INFRA_A2S_SENSOR_IPC_MSGSUB_ACTIVATE_ID                                    (0u)
#define INFRA_A2S_SENSOR_IPC_MSGSUB_BATCH_ID                                       (1u)
/* SOC to MCU Message sub length */
#define INFRA_A2S_SENSOR_IPC_MSGSUB_ACTIVATE_LENGTH                                (2u)
#define INFRA_A2S_SENSOR_IPC_MSGSUB_BATCH_LENGTH                                   (9u)
/* Group: : Sensor */
/* Message Major: IPC */
/* Message Sub: SensorData */
typedef struct
{
    /*handle*/
    uint8_t handle;
    /* x axis*/
    float x;
    /* y axis*/
    float y;
    /* z axis*/
    float z;
    /*timestamp*/
    int64_t timestamp;
    /*temp*/
    float temp;
}INFRA_S2A_SensorIPCSensorData_t;

/* Pack function of sub message SensorData */
int32_t INFRA_S2A_SensorIPCSensorData_Pack(INFRA_S2A_SensorIPCSensorData_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SensorData */
int32_t INFRA_S2A_SensorIPCSensorData_Parse(INFRA_S2A_SensorIPCSensorData_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: SensorState */
typedef struct
{
    uint8_t handle;
    uint8_t state;
}INFRA_S2A_SensorIPCSensorState_t;

/* Pack function of sub message SensorState */
int32_t INFRA_S2A_SensorIPCSensorState_Pack(INFRA_S2A_SensorIPCSensorState_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SensorState */
int32_t INFRA_S2A_SensorIPCSensorState_Parse(INFRA_S2A_SensorIPCSensorState_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: SensorReply */
typedef struct
{
    uint8_t id;
    uint8_t handle;
    uint8_t state;
}INFRA_S2A_SensorIPCSensorReply_t;

/* Pack function of sub message SensorReply */
int32_t INFRA_S2A_SensorIPCSensorReply_Pack(INFRA_S2A_SensorIPCSensorReply_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SensorReply */
int32_t INFRA_S2A_SensorIPCSensorReply_Parse(INFRA_S2A_SensorIPCSensorReply_t *data, uint8_t *payload, uint16_t length);

/* Group: : Sensor */
/* Group: : Sensor */
/* Message Major: IPC */
/* Message Sub: Activate */
typedef struct
{
    /*sensor handle*/
    uint8_t handle;
    /*enable/disable*/
    uint8_t enable;
}INFRA_A2S_SensorIPCActivate_t;

/* Pack function of sub message Activate */
int32_t INFRA_A2S_SensorIPCActivate_Pack(INFRA_A2S_SensorIPCActivate_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Activate */
int32_t INFRA_A2S_SensorIPCActivate_Parse(INFRA_A2S_SensorIPCActivate_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: Batch */
typedef struct
{
    uint8_t handle;
    uint64_t period_ns;
}INFRA_A2S_SensorIPCBatch_t;

/* Pack function of sub message Batch */
int32_t INFRA_A2S_SensorIPCBatch_Pack(INFRA_A2S_SensorIPCBatch_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Batch */
int32_t INFRA_A2S_SensorIPCBatch_Parse(INFRA_A2S_SensorIPCBatch_t *data, uint8_t *payload, uint16_t length);

/* Group: : Sensor */
#ifdef __cplusplus
}
#endif

#endif
