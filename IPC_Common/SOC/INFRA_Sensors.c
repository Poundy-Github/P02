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
 *                 File:  INFRA_Sensors.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Sensor source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "INFRA_Sensors.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Sensor */
/* Message Major: IPC */
/* Pack function of sub message SensorData */
int32_t INFRA_S2A_SensorIPCSensorData_Pack(INFRA_S2A_SensorIPCSensorData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH))
    {
        payload[0] = INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORDATA_ID;
        payload[1] = IPC_GET_BYTE(data->handle, 0);
        payload[2] = IPC_GET_BYTE(data->x, 3);
        payload[3] = IPC_GET_BYTE(data->x, 2);
        payload[4] = IPC_GET_BYTE(data->x, 1);
        payload[5] = IPC_GET_BYTE(data->x, 0);
        payload[6] = IPC_GET_BYTE(data->y, 3);
        payload[7] = IPC_GET_BYTE(data->y, 2);
        payload[8] = IPC_GET_BYTE(data->y, 1);
        payload[9] = IPC_GET_BYTE(data->y, 0);
        payload[10] = IPC_GET_BYTE(data->z, 3);
        payload[11] = IPC_GET_BYTE(data->z, 2);
        payload[12] = IPC_GET_BYTE(data->z, 1);
        payload[13] = IPC_GET_BYTE(data->z, 0);
        payload[14] = IPC_GET_BYTE(data->timestamp, 7);
        payload[15] = IPC_GET_BYTE(data->timestamp, 6);
        payload[16] = IPC_GET_BYTE(data->timestamp, 5);
        payload[17] = IPC_GET_BYTE(data->timestamp, 4);
        payload[18] = IPC_GET_BYTE(data->timestamp, 3);
        payload[19] = IPC_GET_BYTE(data->timestamp, 2);
        payload[20] = IPC_GET_BYTE(data->timestamp, 1);
        payload[21] = IPC_GET_BYTE(data->timestamp, 0);
        payload[22] = IPC_GET_BYTE(data->temp, 3);
        payload[23] = IPC_GET_BYTE(data->temp, 2);
        payload[24] = IPC_GET_BYTE(data->temp, 1);
        payload[25] = IPC_GET_BYTE(data->temp, 0);
        totalLength = INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH + 1;
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SensorData */
int32_t INFRA_S2A_SensorIPCSensorData_Parse(INFRA_S2A_SensorIPCSensorData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH == length))
    {
        IPC_GET_BYTE(data->handle, 0) = payload[0];
        IPC_GET_BYTE(data->x, 3) = payload[1];
        IPC_GET_BYTE(data->x, 2) = payload[2];
        IPC_GET_BYTE(data->x, 1) = payload[3];
        IPC_GET_BYTE(data->x, 0) = payload[4];
        IPC_GET_BYTE(data->y, 3) = payload[5];
        IPC_GET_BYTE(data->y, 2) = payload[6];
        IPC_GET_BYTE(data->y, 1) = payload[7];
        IPC_GET_BYTE(data->y, 0) = payload[8];
        IPC_GET_BYTE(data->z, 3) = payload[9];
        IPC_GET_BYTE(data->z, 2) = payload[10];
        IPC_GET_BYTE(data->z, 1) = payload[11];
        IPC_GET_BYTE(data->z, 0) = payload[12];
        IPC_GET_BYTE(data->timestamp, 7) = payload[13];
        IPC_GET_BYTE(data->timestamp, 6) = payload[14];
        IPC_GET_BYTE(data->timestamp, 5) = payload[15];
        IPC_GET_BYTE(data->timestamp, 4) = payload[16];
        IPC_GET_BYTE(data->timestamp, 3) = payload[17];
        IPC_GET_BYTE(data->timestamp, 2) = payload[18];
        IPC_GET_BYTE(data->timestamp, 1) = payload[19];
        IPC_GET_BYTE(data->timestamp, 0) = payload[20];
        IPC_GET_BYTE(data->temp, 3) = payload[21];
        IPC_GET_BYTE(data->temp, 2) = payload[22];
        IPC_GET_BYTE(data->temp, 1) = payload[23];
        IPC_GET_BYTE(data->temp, 0) = payload[24];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SensorState */
int32_t INFRA_S2A_SensorIPCSensorState_Pack(INFRA_S2A_SensorIPCSensorState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH))
    {
        payload[0] = INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORSTATE_ID;
        payload[1] = IPC_GET_BYTE(data->handle, 0);
        payload[2] = IPC_GET_BYTE(data->state, 0);
        totalLength = INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH + 1;
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SensorState */
int32_t INFRA_S2A_SensorIPCSensorState_Parse(INFRA_S2A_SensorIPCSensorState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->handle, 0) = payload[0];
        IPC_GET_BYTE(data->state, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SensorReply */
int32_t INFRA_S2A_SensorIPCSensorReply_Pack(INFRA_S2A_SensorIPCSensorReply_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH))
    {
        payload[0] = INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORREPLY_ID;
        payload[1] = IPC_GET_BYTE(data->id, 0);
        payload[2] = IPC_GET_BYTE(data->handle, 0);
        payload[3] = IPC_GET_BYTE(data->state, 0);
        totalLength = INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH + 1;
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SensorReply */
int32_t INFRA_S2A_SensorIPCSensorReply_Parse(INFRA_S2A_SensorIPCSensorReply_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (INFRA_S2A_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH == length))
    {
        IPC_GET_BYTE(data->id, 0) = payload[0];
        IPC_GET_BYTE(data->handle, 0) = payload[1];
        IPC_GET_BYTE(data->state, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Activate */
int32_t INFRA_A2S_SensorIPCActivate_Pack(INFRA_A2S_SensorIPCActivate_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_A2S_SENSOR_IPC_MSGSUB_ACTIVATE_LENGTH))
    {
        payload[0] = INFRA_A2S_SENSOR_IPC_MSGSUB_ACTIVATE_ID;
        payload[1] = IPC_GET_BYTE(data->handle, 0);
        payload[2] = IPC_GET_BYTE(data->enable, 0);
        totalLength = INFRA_A2S_SENSOR_IPC_MSGSUB_ACTIVATE_LENGTH + 1;
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Activate */
int32_t INFRA_A2S_SensorIPCActivate_Parse(INFRA_A2S_SensorIPCActivate_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (INFRA_A2S_SENSOR_IPC_MSGSUB_ACTIVATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->handle, 0) = payload[0];
        IPC_GET_BYTE(data->enable, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Batch */
int32_t INFRA_A2S_SensorIPCBatch_Pack(INFRA_A2S_SensorIPCBatch_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= INFRA_A2S_SENSOR_IPC_MSGSUB_BATCH_LENGTH))
    {
        payload[0] = INFRA_A2S_SENSOR_IPC_MSGSUB_BATCH_ID;
        payload[1] = IPC_GET_BYTE(data->handle, 0);
        payload[2] = IPC_GET_BYTE(data->period_ns, 7);
        payload[3] = IPC_GET_BYTE(data->period_ns, 6);
        payload[4] = IPC_GET_BYTE(data->period_ns, 5);
        payload[5] = IPC_GET_BYTE(data->period_ns, 4);
        payload[6] = IPC_GET_BYTE(data->period_ns, 3);
        payload[7] = IPC_GET_BYTE(data->period_ns, 2);
        payload[8] = IPC_GET_BYTE(data->period_ns, 1);
        payload[9] = IPC_GET_BYTE(data->period_ns, 0);
        totalLength = INFRA_A2S_SENSOR_IPC_MSGSUB_BATCH_LENGTH + 1;
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Batch */
int32_t INFRA_A2S_SensorIPCBatch_Parse(INFRA_A2S_SensorIPCBatch_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (INFRA_A2S_SENSOR_IPC_MSGSUB_BATCH_LENGTH == length))
    {
        IPC_GET_BYTE(data->handle, 0) = payload[0];
        IPC_GET_BYTE(data->period_ns, 7) = payload[1];
        IPC_GET_BYTE(data->period_ns, 6) = payload[2];
        IPC_GET_BYTE(data->period_ns, 5) = payload[3];
        IPC_GET_BYTE(data->period_ns, 4) = payload[4];
        IPC_GET_BYTE(data->period_ns, 3) = payload[5];
        IPC_GET_BYTE(data->period_ns, 2) = payload[6];
        IPC_GET_BYTE(data->period_ns, 1) = payload[7];
        IPC_GET_BYTE(data->period_ns, 0) = payload[8];
        ret = 0;
    }
    return ret;
}
