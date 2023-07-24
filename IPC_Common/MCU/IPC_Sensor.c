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
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group Sensor source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Sensor.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Sensor */
/* Message Major: IPC */
/* Transmit function of sub message SensorData */
int32_t IPC_M2S_SensorIPCSensorData_Transmit(IPC_M2S_SensorIPCSensorData_t *data)
{
    uint8_t payload[IPC_M2S_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SENSOR_ID;
        payload[1] = IPC_M2S_SENSOR_MSGMAJOR_IPC_ID;
        payload[2] = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORDATA_ID;
        payload[3] = IPC_GET_BYTE(data->handle, 0);
        payload[4] = IPC_GET_BYTE(data->x, 3);
        payload[5] = IPC_GET_BYTE(data->x, 2);
        payload[6] = IPC_GET_BYTE(data->x, 1);
        payload[7] = IPC_GET_BYTE(data->x, 0);
        payload[8] = IPC_GET_BYTE(data->y, 3);
        payload[9] = IPC_GET_BYTE(data->y, 2);
        payload[10] = IPC_GET_BYTE(data->y, 1);
        payload[11] = IPC_GET_BYTE(data->y, 0);
        payload[12] = IPC_GET_BYTE(data->z, 3);
        payload[13] = IPC_GET_BYTE(data->z, 2);
        payload[14] = IPC_GET_BYTE(data->z, 1);
        payload[15] = IPC_GET_BYTE(data->z, 0);
        payload[16] = IPC_GET_BYTE(data->timestamp, 7);
        payload[17] = IPC_GET_BYTE(data->timestamp, 6);
        payload[18] = IPC_GET_BYTE(data->timestamp, 5);
        payload[19] = IPC_GET_BYTE(data->timestamp, 4);
        payload[20] = IPC_GET_BYTE(data->timestamp, 3);
        payload[21] = IPC_GET_BYTE(data->timestamp, 2);
        payload[22] = IPC_GET_BYTE(data->timestamp, 1);
        payload[23] = IPC_GET_BYTE(data->timestamp, 0);
        payload[24] = IPC_GET_BYTE(data->temp, 3);
        payload[25] = IPC_GET_BYTE(data->temp, 2);
        payload[26] = IPC_GET_BYTE(data->temp, 1);
        payload[27] = IPC_GET_BYTE(data->temp, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SENSOR_IPC_MSGSUB_SENSORDATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message SensorState */
int32_t IPC_M2S_SensorIPCSensorState_Transmit(IPC_M2S_SensorIPCSensorState_t *data)
{
    uint8_t payload[IPC_M2S_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SENSOR_ID;
        payload[1] = IPC_M2S_SENSOR_MSGMAJOR_IPC_ID;
        payload[2] = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORSTATE_ID;
        payload[3] = IPC_GET_BYTE(data->handle, 0);
        payload[4] = IPC_GET_BYTE(data->state, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SENSOR_IPC_MSGSUB_SENSORSTATE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message SensorReply */
int32_t IPC_M2S_SensorIPCSensorReply_Transmit(IPC_M2S_SensorIPCSensorReply_t *data)
{
    uint8_t payload[IPC_M2S_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SENSOR_ID;
        payload[1] = IPC_M2S_SENSOR_MSGMAJOR_IPC_ID;
        payload[2] = IPC_M2S_SENSOR_IPC_MSGSUB_SENSORREPLY_ID;
        payload[3] = IPC_GET_BYTE(data->id, 0);
        payload[4] = IPC_GET_BYTE(data->handle, 0);
        payload[5] = IPC_GET_BYTE(data->state, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SENSOR_IPC_MSGSUB_SENSORREPLY_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message Activate */
void IPC_S2M_SensorIPCActivate_Receive(uint8_t *receiveData, IPC_S2M_SensorIPCActivate_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_SENSOR_IPC_MSGSUB_ACTIVATE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->handle, 0) = receiveData[0];
        IPC_GET_BYTE(data->enable, 0) = receiveData[1];
    }

}

/* Receive function of sub message Batch */
void IPC_S2M_SensorIPCBatch_Receive(uint8_t *receiveData, IPC_S2M_SensorIPCBatch_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_SENSOR_IPC_MSGSUB_BATCH_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->handle, 0) = receiveData[0];
        IPC_GET_BYTE(data->period_ns, 7) = receiveData[1];
        IPC_GET_BYTE(data->period_ns, 6) = receiveData[2];
        IPC_GET_BYTE(data->period_ns, 5) = receiveData[3];
        IPC_GET_BYTE(data->period_ns, 4) = receiveData[4];
        IPC_GET_BYTE(data->period_ns, 3) = receiveData[5];
        IPC_GET_BYTE(data->period_ns, 2) = receiveData[6];
        IPC_GET_BYTE(data->period_ns, 1) = receiveData[7];
        IPC_GET_BYTE(data->period_ns, 0) = receiveData[8];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
