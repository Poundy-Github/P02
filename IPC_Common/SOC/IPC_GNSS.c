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
 *                 File:  IPC_GNSS.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group GNSS source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_GNSS.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: GNSS */
/* Message Major: SeriaNet */
/* Pack function of sub message Data */
int32_t IPC_M2S_GNSSSeriaNetData_Pack(IPC_M2S_GNSSSeriaNetData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_M2S_GNSS_MSGMAJOR_SERIANET_ID;
        payload[4] = IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_ID;
        if((data->BufferLength <= IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->BufferLength >> 8);
            payload[6] = (uint8_t)(data->BufferLength);
            flexLength = data->BufferLength * sizeof(data->Buffer[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->BufferLength; arrIndex++)
                {
                    payload[7 + arrIndex * 1] = IPC_GET_BYTE(data->Buffer[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message Data */
int32_t IPC_M2S_GNSSSeriaNetData_Parse(IPC_M2S_GNSSSeriaNetData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH >= length) &&
        (IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH_MIN <= length))
    {
        data->BufferLength = (payload[0] << 8) | payload[1];
        if(data->BufferLength <= IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_FLEX_NUMBER)
        {
            uint16_t flexLength = data->BufferLength * sizeof(data->Buffer[0]);
            if(length == flexLength + IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH_MIN)
            {
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->BufferLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Buffer[arrIndex], 0) = payload[2 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Message Major: NMEA */
/* Pack function of sub message Data */
int32_t IPC_M2S_GNSSNMEAData_Pack(IPC_M2S_GNSSNMEAData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_GNSS_NMEA_MSGSUB_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_M2S_GNSS_MSGMAJOR_NMEA_ID;
        payload[4] = IPC_M2S_GNSS_NMEA_MSGSUB_DATA_ID;
        payload[5] = IPC_GET_BYTE(data->NmeaVersion, 0);
        totalLength = IPC_M2S_GNSS_NMEA_MSGSUB_DATA_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Data */
int32_t IPC_M2S_GNSSNMEAData_Parse(IPC_M2S_GNSSNMEAData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_GNSS_NMEA_MSGSUB_DATA_LENGTH == length))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: NAV */
/* Pack function of sub message Data */
int32_t IPC_M2S_GNSSNAVData_Pack(IPC_M2S_GNSSNAVData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_GNSS_NAV_MSGSUB_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_M2S_GNSS_MSGMAJOR_NAV_ID;
        payload[4] = IPC_M2S_GNSS_NAV_MSGSUB_DATA_ID;
        payload[5] = IPC_GET_BYTE(data->NAVData, 0);
        totalLength = IPC_M2S_GNSS_NAV_MSGSUB_DATA_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Data */
int32_t IPC_M2S_GNSSNAVData_Parse(IPC_M2S_GNSSNAVData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_GNSS_NAV_MSGSUB_DATA_LENGTH == length))
    {
        IPC_GET_BYTE(data->NAVData, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: FrameLoss */
/* Pack function of sub message Data */
int32_t IPC_M2S_GNSSFrameLossData_Pack(IPC_M2S_GNSSFrameLossData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_M2S_GNSS_MSGMAJOR_FRAMELOSS_ID;
        payload[4] = IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_ID;
        payload[5] = IPC_GET_BYTE(data->FrameLossNum, 1);
        payload[6] = IPC_GET_BYTE(data->FrameLossNum, 0);
        totalLength = IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Data */
int32_t IPC_M2S_GNSSFrameLossData_Parse(IPC_M2S_GNSSFrameLossData_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = payload[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Message Major: Config */
/* Pack function of sub message NMEA_Data */
int32_t IPC_M2S_GNSSConfigNMEA_Data_Pack(IPC_M2S_GNSSConfigNMEA_Data_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_ID;
        payload[5] = IPC_GET_BYTE(data->NmeaVersion, 0);
        totalLength = IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message NMEA_Data */
int32_t IPC_M2S_GNSSConfigNMEA_Data_Parse(IPC_M2S_GNSSConfigNMEA_Data_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_LENGTH == length))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message NAV_Data */
int32_t IPC_M2S_GNSSConfigNAV_Data_Pack(IPC_M2S_GNSSConfigNAV_Data_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_ID;
        payload[5] = IPC_GET_BYTE(data->NAVData, 0);
        totalLength = IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message NAV_Data */
int32_t IPC_M2S_GNSSConfigNAV_Data_Parse(IPC_M2S_GNSSConfigNAV_Data_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_LENGTH == length))
    {
        IPC_GET_BYTE(data->NAVData, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message FrameLoss_Data */
int32_t IPC_M2S_GNSSConfigFrameLoss_Data_Pack(IPC_M2S_GNSSConfigFrameLoss_Data_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_ID;
        payload[5] = IPC_GET_BYTE(data->FrameLossNum, 1);
        payload[6] = IPC_GET_BYTE(data->FrameLossNum, 0);
        totalLength = IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message FrameLoss_Data */
int32_t IPC_M2S_GNSSConfigFrameLoss_Data_Parse(IPC_M2S_GNSSConfigFrameLoss_Data_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = payload[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message PDTINFO_Data */
int32_t IPC_M2S_GNSSConfigPDTINFO_Data_Pack(IPC_M2S_GNSSConfigPDTINFO_Data_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_ID;
        if((data->PDTINFODataLength <= IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->PDTINFODataLength >> 8);
            payload[6] = (uint8_t)(data->PDTINFODataLength);
            flexLength = data->PDTINFODataLength * sizeof(data->PDTINFOData[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->PDTINFODataLength; arrIndex++)
                {
                    payload[7 + arrIndex * 1] = IPC_GET_BYTE(data->PDTINFOData[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message PDTINFO_Data */
int32_t IPC_M2S_GNSSConfigPDTINFO_Data_Parse(IPC_M2S_GNSSConfigPDTINFO_Data_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH >= length) &&
        (IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH_MIN <= length))
    {
        data->PDTINFODataLength = (payload[0] << 8) | payload[1];
        if(data->PDTINFODataLength <= IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_FLEX_NUMBER)
        {
            uint16_t flexLength = data->PDTINFODataLength * sizeof(data->PDTINFOData[0]);
            if(length == flexLength + IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH_MIN)
            {
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->PDTINFODataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->PDTINFOData[arrIndex], 0) = payload[2 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message reserved */
int32_t IPC_S2M_GNSSReservedreserved_Pack(IPC_S2M_GNSSReservedreserved_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_RESERVED_MSGSUB_RESERVED_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_RESERVED_ID;
        payload[4] = IPC_S2M_GNSS_RESERVED_MSGSUB_RESERVED_ID;
        payload[5] = IPC_GET_BYTE(data->reserved, 0);
        totalLength = IPC_S2M_GNSS_RESERVED_MSGSUB_RESERVED_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message reserved */
int32_t IPC_S2M_GNSSReservedreserved_Parse(IPC_S2M_GNSSReservedreserved_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_RESERVED_MSGSUB_RESERVED_LENGTH == length))
    {
        IPC_GET_BYTE(data->reserved, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: NMEA */
/* Pack function of sub message Read */
int32_t IPC_S2M_GNSSNMEARead_Pack(IPC_S2M_GNSSNMEARead_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_NMEA_MSGSUB_READ_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_NMEA_ID;
        payload[4] = IPC_S2M_GNSS_NMEA_MSGSUB_READ_ID;
        payload[5] = IPC_GET_BYTE(data->NmeaVersion, 0);
        totalLength = IPC_S2M_GNSS_NMEA_MSGSUB_READ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Read */
int32_t IPC_S2M_GNSSNMEARead_Parse(IPC_S2M_GNSSNMEARead_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_NMEA_MSGSUB_READ_LENGTH == length))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Write */
int32_t IPC_S2M_GNSSNMEAWrite_Pack(IPC_S2M_GNSSNMEAWrite_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_NMEA_ID;
        payload[4] = IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_ID;
        payload[5] = IPC_GET_BYTE(data->NmeaVersion, 0);
        totalLength = IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Write */
int32_t IPC_S2M_GNSSNMEAWrite_Parse(IPC_S2M_GNSSNMEAWrite_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_LENGTH == length))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: NAV */
/* Pack function of sub message Read */
int32_t IPC_S2M_GNSSNAVRead_Pack(IPC_S2M_GNSSNAVRead_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_NAV_MSGSUB_READ_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_NAV_ID;
        payload[4] = IPC_S2M_GNSS_NAV_MSGSUB_READ_ID;
        payload[5] = IPC_GET_BYTE(data->NAVData, 0);
        totalLength = IPC_S2M_GNSS_NAV_MSGSUB_READ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Read */
int32_t IPC_S2M_GNSSNAVRead_Parse(IPC_S2M_GNSSNAVRead_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_NAV_MSGSUB_READ_LENGTH == length))
    {
        IPC_GET_BYTE(data->NAVData, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Write */
int32_t IPC_S2M_GNSSNAVWrite_Pack(IPC_S2M_GNSSNAVWrite_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_NAV_MSGSUB_WRITE_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_NAV_ID;
        payload[4] = IPC_S2M_GNSS_NAV_MSGSUB_WRITE_ID;
        payload[5] = IPC_GET_BYTE(data->NAVData, 0);
        totalLength = IPC_S2M_GNSS_NAV_MSGSUB_WRITE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Write */
int32_t IPC_S2M_GNSSNAVWrite_Parse(IPC_S2M_GNSSNAVWrite_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_NAV_MSGSUB_WRITE_LENGTH == length))
    {
        IPC_GET_BYTE(data->NAVData, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: FrameLoss */
/* Pack function of sub message Read */
int32_t IPC_S2M_GNSSFrameLossRead_Pack(IPC_S2M_GNSSFrameLossRead_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_FRAMELOSS_ID;
        payload[4] = IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_ID;
        payload[5] = IPC_GET_BYTE(data->FrameLossNum, 1);
        payload[6] = IPC_GET_BYTE(data->FrameLossNum, 0);
        totalLength = IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Read */
int32_t IPC_S2M_GNSSFrameLossRead_Parse(IPC_S2M_GNSSFrameLossRead_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = payload[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Write */
int32_t IPC_S2M_GNSSFrameLossWrite_Pack(IPC_S2M_GNSSFrameLossWrite_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_FRAMELOSS_MSGSUB_WRITE_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_FRAMELOSS_ID;
        payload[4] = IPC_S2M_GNSS_FRAMELOSS_MSGSUB_WRITE_ID;
        payload[5] = IPC_GET_BYTE(data->FrameLossNum, 1);
        payload[6] = IPC_GET_BYTE(data->FrameLossNum, 0);
        totalLength = IPC_S2M_GNSS_FRAMELOSS_MSGSUB_WRITE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Write */
int32_t IPC_S2M_GNSSFrameLossWrite_Parse(IPC_S2M_GNSSFrameLossWrite_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_FRAMELOSS_MSGSUB_WRITE_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = payload[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Message Major: Config */
/* Pack function of sub message NMEA_Read */
int32_t IPC_S2M_GNSSConfigNMEA_Read_Pack(IPC_S2M_GNSSConfigNMEA_Read_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_ID;
        payload[5] = IPC_GET_BYTE(data->NmeaVersion, 0);
        totalLength = IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message NMEA_Read */
int32_t IPC_S2M_GNSSConfigNMEA_Read_Parse(IPC_S2M_GNSSConfigNMEA_Read_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_LENGTH == length))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message NMEA_Write */
int32_t IPC_S2M_GNSSConfigNMEA_Write_Pack(IPC_S2M_GNSSConfigNMEA_Write_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_ID;
        payload[5] = IPC_GET_BYTE(data->NmeaVersion, 0);
        totalLength = IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message NMEA_Write */
int32_t IPC_S2M_GNSSConfigNMEA_Write_Parse(IPC_S2M_GNSSConfigNMEA_Write_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_LENGTH == length))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message NAV_Read */
int32_t IPC_S2M_GNSSConfigNAV_Read_Pack(IPC_S2M_GNSSConfigNAV_Read_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_ID;
        payload[5] = IPC_GET_BYTE(data->NAVData, 0);
        totalLength = IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message NAV_Read */
int32_t IPC_S2M_GNSSConfigNAV_Read_Parse(IPC_S2M_GNSSConfigNAV_Read_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_LENGTH == length))
    {
        IPC_GET_BYTE(data->NAVData, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message NAV_Write */
int32_t IPC_S2M_GNSSConfigNAV_Write_Pack(IPC_S2M_GNSSConfigNAV_Write_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_ID;
        payload[5] = IPC_GET_BYTE(data->NAVData, 0);
        totalLength = IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message NAV_Write */
int32_t IPC_S2M_GNSSConfigNAV_Write_Parse(IPC_S2M_GNSSConfigNAV_Write_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_LENGTH == length))
    {
        IPC_GET_BYTE(data->NAVData, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message FrameLoss_Read */
int32_t IPC_S2M_GNSSConfigFrameLoss_Read_Pack(IPC_S2M_GNSSConfigFrameLoss_Read_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_ID;
        payload[5] = IPC_GET_BYTE(data->FrameLossNum, 1);
        payload[6] = IPC_GET_BYTE(data->FrameLossNum, 0);
        totalLength = IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message FrameLoss_Read */
int32_t IPC_S2M_GNSSConfigFrameLoss_Read_Parse(IPC_S2M_GNSSConfigFrameLoss_Read_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = payload[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message FrameLoss_Write */
int32_t IPC_S2M_GNSSConfigFrameLoss_Write_Pack(IPC_S2M_GNSSConfigFrameLoss_Write_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_ID;
        payload[5] = IPC_GET_BYTE(data->FrameLossNum, 1);
        payload[6] = IPC_GET_BYTE(data->FrameLossNum, 0);
        totalLength = IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message FrameLoss_Write */
int32_t IPC_S2M_GNSSConfigFrameLoss_Write_Parse(IPC_S2M_GNSSConfigFrameLoss_Write_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_LENGTH == length))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = payload[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message PDTINFO_Read */
int32_t IPC_S2M_GNSSConfigPDTINFO_Read_Pack(IPC_S2M_GNSSConfigPDTINFO_Read_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_LENGTH))
    {
        payload[2] = IPC_GROUP_GNSS_ID;
        payload[3] = IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID;
        payload[4] = IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_ID;
        payload[5] = IPC_GET_BYTE(data->PDTINFORead, 0);
        totalLength = IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message PDTINFO_Read */
int32_t IPC_S2M_GNSSConfigPDTINFO_Read_Parse(IPC_S2M_GNSSConfigPDTINFO_Read_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_LENGTH == length))
    {
        IPC_GET_BYTE(data->PDTINFORead, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
