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
 *                 File:  IPC_Sensor.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Sensor source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Sensor.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Sensor */
/* Message Major: IPC */
/* Pack function of sub message SensorData */
int32_t IPC_M2S_SensorIPCSensorData_Pack(IPC_M2S_SensorIPCSensorData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH))
    {
        payload[2] = IPC_GROUP_SENSOR_ID;
        payload[3] = IPC_M2S_SENSOR_MSGMAJOR_IPC_ID;
        payload[4] = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORDATA_ID;
        payload[5] = IPC_GET_BYTE(data->handle, 0);
        payload[6] = IPC_GET_BYTE(data->x, 3);
        payload[7] = IPC_GET_BYTE(data->x, 2);
        payload[8] = IPC_GET_BYTE(data->x, 1);
        payload[9] = IPC_GET_BYTE(data->x, 0);
        payload[10] = IPC_GET_BYTE(data->y, 3);
        payload[11] = IPC_GET_BYTE(data->y, 2);
        payload[12] = IPC_GET_BYTE(data->y, 1);
        payload[13] = IPC_GET_BYTE(data->y, 0);
        payload[14] = IPC_GET_BYTE(data->z, 3);
        payload[15] = IPC_GET_BYTE(data->z, 2);
        payload[16] = IPC_GET_BYTE(data->z, 1);
        payload[17] = IPC_GET_BYTE(data->z, 0);
        payload[18] = IPC_GET_BYTE(data->timestamp, 7);
        payload[19] = IPC_GET_BYTE(data->timestamp, 6);
        payload[20] = IPC_GET_BYTE(data->timestamp, 5);
        payload[21] = IPC_GET_BYTE(data->timestamp, 4);
        payload[22] = IPC_GET_BYTE(data->timestamp, 3);
        payload[23] = IPC_GET_BYTE(data->timestamp, 2);
        payload[24] = IPC_GET_BYTE(data->timestamp, 1);
        payload[25] = IPC_GET_BYTE(data->timestamp, 0);
        payload[26] = IPC_GET_BYTE(data->temp, 3);
        payload[27] = IPC_GET_BYTE(data->temp, 2);
        payload[28] = IPC_GET_BYTE(data->temp, 1);
        payload[29] = IPC_GET_BYTE(data->temp, 0);
        totalLength = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SensorData */
int32_t IPC_M2S_SensorIPCSensorData_Parse(IPC_M2S_SensorIPCSensorData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH == length))
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
int32_t IPC_M2S_SensorIPCSensorState_Pack(IPC_M2S_SensorIPCSensorState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH))
    {
        payload[2] = IPC_GROUP_SENSOR_ID;
        payload[3] = IPC_M2S_SENSOR_MSGMAJOR_IPC_ID;
        payload[4] = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORSTATE_ID;
        payload[5] = IPC_GET_BYTE(data->handle, 0);
        payload[6] = IPC_GET_BYTE(data->state, 0);
        totalLength = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SensorState */
int32_t IPC_M2S_SensorIPCSensorState_Parse(IPC_M2S_SensorIPCSensorState_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->handle, 0) = payload[0];
        IPC_GET_BYTE(data->state, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SensorReply */
int32_t IPC_M2S_SensorIPCSensorReply_Pack(IPC_M2S_SensorIPCSensorReply_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH))
    {
        payload[2] = IPC_GROUP_SENSOR_ID;
        payload[3] = IPC_M2S_SENSOR_MSGMAJOR_IPC_ID;
        payload[4] = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORREPLY_ID;
        payload[5] = IPC_GET_BYTE(data->id, 0);
        payload[6] = IPC_GET_BYTE(data->handle, 0);
        payload[7] = IPC_GET_BYTE(data->state, 0);
        totalLength = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SensorReply */
int32_t IPC_M2S_SensorIPCSensorReply_Parse(IPC_M2S_SensorIPCSensorReply_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH == length))
    {
        IPC_GET_BYTE(data->id, 0) = payload[0];
        IPC_GET_BYTE(data->handle, 0) = payload[1];
        IPC_GET_BYTE(data->state, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Activate */
int32_t IPC_S2M_SensorIPCActivate_Pack(IPC_S2M_SensorIPCActivate_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SENSOR_IPC_MSGSUB_ACTIVATE_LENGTH))
    {
        payload[2] = IPC_GROUP_SENSOR_ID;
        payload[3] = IPC_S2M_SENSOR_MSGMAJOR_IPC_ID;
        payload[4] = IPC_S2M_SENSOR_IPC_MSGSUB_ACTIVATE_ID;
        payload[5] = IPC_GET_BYTE(data->handle, 0);
        payload[6] = IPC_GET_BYTE(data->enable, 0);
        totalLength = IPC_S2M_SENSOR_IPC_MSGSUB_ACTIVATE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Activate */
int32_t IPC_S2M_SensorIPCActivate_Parse(IPC_S2M_SensorIPCActivate_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_SENSOR_IPC_MSGSUB_ACTIVATE_LENGTH == length))
    {
        IPC_GET_BYTE(data->handle, 0) = payload[0];
        IPC_GET_BYTE(data->enable, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Batch */
int32_t IPC_S2M_SensorIPCBatch_Pack(IPC_S2M_SensorIPCBatch_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SENSOR_IPC_MSGSUB_BATCH_LENGTH))
    {
        payload[2] = IPC_GROUP_SENSOR_ID;
        payload[3] = IPC_S2M_SENSOR_MSGMAJOR_IPC_ID;
        payload[4] = IPC_S2M_SENSOR_IPC_MSGSUB_BATCH_ID;
        payload[5] = IPC_GET_BYTE(data->handle, 0);
        payload[6] = IPC_GET_BYTE(data->period_ns, 7);
        payload[7] = IPC_GET_BYTE(data->period_ns, 6);
        payload[8] = IPC_GET_BYTE(data->period_ns, 5);
        payload[9] = IPC_GET_BYTE(data->period_ns, 4);
        payload[10] = IPC_GET_BYTE(data->period_ns, 3);
        payload[11] = IPC_GET_BYTE(data->period_ns, 2);
        payload[12] = IPC_GET_BYTE(data->period_ns, 1);
        payload[13] = IPC_GET_BYTE(data->period_ns, 0);
        totalLength = IPC_S2M_SENSOR_IPC_MSGSUB_BATCH_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Batch */
int32_t IPC_S2M_SensorIPCBatch_Parse(IPC_S2M_SensorIPCBatch_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_SENSOR_IPC_MSGSUB_BATCH_LENGTH == length))
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
