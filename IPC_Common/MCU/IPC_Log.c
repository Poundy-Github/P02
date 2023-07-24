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
 *                 File:  IPC_Log.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group Log source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Log.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Log */
/* Message Major: Default */
/* Transmit function of sub message Log */
int32_t IPC_M2S_LogDefaultLog_Transmit(IPC_M2S_LogDefaultLog_t *data)
{
    uint8_t payload[IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->payloadLength <= IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_LOG_ID;
        payload[1] = IPC_M2S_LOG_MSGMAJOR_DEFAULT_ID;
        payload[2] = IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_ID;
        payload[3] = (uint8_t)(data->payloadLength >> 8);
        payload[4] = (uint8_t)(data->payloadLength);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 16; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Id[arrIndex], 0);
            }
        }
        payload[21] = IPC_GET_BYTE(data->level, 0);
        payload[22] = IPC_GET_BYTE(data->timestamp, 7);
        payload[23] = IPC_GET_BYTE(data->timestamp, 6);
        payload[24] = IPC_GET_BYTE(data->timestamp, 5);
        payload[25] = IPC_GET_BYTE(data->timestamp, 4);
        payload[26] = IPC_GET_BYTE(data->timestamp, 3);
        payload[27] = IPC_GET_BYTE(data->timestamp, 2);
        payload[28] = IPC_GET_BYTE(data->timestamp, 1);
        payload[29] = IPC_GET_BYTE(data->timestamp, 0);
        flexLength = data->payloadLength * sizeof(data->payload[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->payloadLength; arrIndex++)
            {
                payload[30 + arrIndex * 1] = IPC_GET_BYTE(data->payload[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message SetLogLevel */
void IPC_S2M_LogDefaultSetLogLevel_Receive(uint8_t *receiveData, IPC_S2M_LogDefaultSetLogLevel_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_LOG_DEFAULT_MSGSUB_SETLOGLEVEL_LENGTH == payloadLength))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 16; arrIndex++)
            {
                IPC_GET_BYTE(data->Id[arrIndex], 0) = receiveData[0 + arrIndex * 1];
            }
        }
        IPC_GET_BYTE(data->level, 0) = receiveData[16];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
