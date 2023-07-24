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
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Log source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Log.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Log */
/* Message Major: Default */
/* Pack function of sub message Log */
int32_t IPC_M2S_LogDefaultLog_Pack(IPC_M2S_LogDefaultLog_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH))
    {
        payload[2] = IPC_GROUP_LOG_ID;
        payload[3] = IPC_M2S_LOG_MSGMAJOR_DEFAULT_ID;
        payload[4] = IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_ID;
        if((data->payloadLength <= IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->payloadLength >> 8);
            payload[6] = (uint8_t)(data->payloadLength);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < 16; arrIndex++)
                {
                    payload[7 + arrIndex * 1] = IPC_GET_BYTE(data->Id[arrIndex], 0);
                }
            }
            payload[23] = IPC_GET_BYTE(data->level, 0);
            payload[24] = IPC_GET_BYTE(data->timestamp, 7);
            payload[25] = IPC_GET_BYTE(data->timestamp, 6);
            payload[26] = IPC_GET_BYTE(data->timestamp, 5);
            payload[27] = IPC_GET_BYTE(data->timestamp, 4);
            payload[28] = IPC_GET_BYTE(data->timestamp, 3);
            payload[29] = IPC_GET_BYTE(data->timestamp, 2);
            payload[30] = IPC_GET_BYTE(data->timestamp, 1);
            payload[31] = IPC_GET_BYTE(data->timestamp, 0);
            flexLength = data->payloadLength * sizeof(data->payload[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->payloadLength; arrIndex++)
                {
                    payload[32 + arrIndex * 1] = IPC_GET_BYTE(data->payload[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message Log */
int32_t IPC_M2S_LogDefaultLog_Parse(IPC_M2S_LogDefaultLog_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH >= length) &&
        (IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH_MIN <= length))
    {
        data->payloadLength = (payload[0] << 8) | payload[1];
        if(data->payloadLength <= IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_FLEX_NUMBER)
        {
            uint16_t flexLength = data->payloadLength * sizeof(data->payload[0]);
            if(length == flexLength + IPC_M2S_LOG_DEFAULT_MSGSUB_LOG_LENGTH_MIN)
            {
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < 16; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Id[arrIndex], 0) = payload[2 + arrIndex * 1];
                    }
                }
                IPC_GET_BYTE(data->level, 0) = payload[18];
                IPC_GET_BYTE(data->timestamp, 7) = payload[19];
                IPC_GET_BYTE(data->timestamp, 6) = payload[20];
                IPC_GET_BYTE(data->timestamp, 5) = payload[21];
                IPC_GET_BYTE(data->timestamp, 4) = payload[22];
                IPC_GET_BYTE(data->timestamp, 3) = payload[23];
                IPC_GET_BYTE(data->timestamp, 2) = payload[24];
                IPC_GET_BYTE(data->timestamp, 1) = payload[25];
                IPC_GET_BYTE(data->timestamp, 0) = payload[26];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->payloadLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->payload[arrIndex], 0) = payload[27 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message SetLogLevel */
int32_t IPC_S2M_LogDefaultSetLogLevel_Pack(IPC_S2M_LogDefaultSetLogLevel_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_LOG_DEFAULT_MSGSUB_SETLOGLEVEL_LENGTH))
    {
        payload[2] = IPC_GROUP_LOG_ID;
        payload[3] = IPC_S2M_LOG_MSGMAJOR_DEFAULT_ID;
        payload[4] = IPC_S2M_LOG_DEFAULT_MSGSUB_SETLOGLEVEL_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 16; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Id[arrIndex], 0);
            }
        }
        payload[21] = IPC_GET_BYTE(data->level, 0);
        totalLength = IPC_S2M_LOG_DEFAULT_MSGSUB_SETLOGLEVEL_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SetLogLevel */
int32_t IPC_S2M_LogDefaultSetLogLevel_Parse(IPC_S2M_LogDefaultSetLogLevel_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_LOG_DEFAULT_MSGSUB_SETLOGLEVEL_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 16; arrIndex++)
            {
                IPC_GET_BYTE(data->Id[arrIndex], 0) = payload[0 + arrIndex * 1];
            }
        }
        IPC_GET_BYTE(data->level, 0) = payload[16];
        ret = 0;
    }
    return ret;
}
