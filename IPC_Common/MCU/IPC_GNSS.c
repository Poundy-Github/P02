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
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group GNSS source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "VariantCfg.h"
#ifdef PLATFOEM_OF_GNSS_USED

#include "IPC_GNSS.h"

#ifdef PLATFORM_OF_STB_IPC_USED
#include "Ipc_STB_If.h"
#else
#pragma weak IPC_STB_DataSend
e_IPC_STB_ErrorType_t IPC_STB_DataSend(uint8 *p_msg, uint16 len, uint8 priority)
{}
#endif


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: GNSS */
/* Message Major: SeriaNet */
/* Transmit function of sub message Data */
int32_t IPC_M2S_GNSSSeriaNetData_Transmit(IPC_M2S_GNSSSeriaNetData_t *data)
{
    uint8_t payload[IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->BufferLength <= IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_GNSS_ID;
        payload[1] = IPC_M2S_GNSS_MSGMAJOR_SERIANET_ID;
        payload[2] = IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_ID;
        payload[3] = (uint8_t)(data->BufferLength >> 8);
        payload[4] = (uint8_t)(data->BufferLength);
        flexLength = data->BufferLength * sizeof(data->Buffer[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->BufferLength; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Buffer[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_STB_DataSend(payload, IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: NMEA */
/* Transmit function of sub message Data */
int32_t IPC_M2S_GNSSNMEAData_Transmit(IPC_M2S_GNSSNMEAData_t *data)
{
    uint8_t payload[IPC_M2S_GNSS_NMEA_MSGSUB_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_GNSS_ID;
        payload[1] = IPC_M2S_GNSS_MSGMAJOR_NMEA_ID;
        payload[2] = IPC_M2S_GNSS_NMEA_MSGSUB_DATA_ID;
        payload[3] = IPC_GET_BYTE(data->NmeaVersion, 0);
        /* Send IPC */
        ret = IPC_STB_DataSend(payload, IPC_M2S_GNSS_NMEA_MSGSUB_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: NAV */
/* Transmit function of sub message Data */
int32_t IPC_M2S_GNSSNAVData_Transmit(IPC_M2S_GNSSNAVData_t *data)
{
    uint8_t payload[IPC_M2S_GNSS_NAV_MSGSUB_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_GNSS_ID;
        payload[1] = IPC_M2S_GNSS_MSGMAJOR_NAV_ID;
        payload[2] = IPC_M2S_GNSS_NAV_MSGSUB_DATA_ID;
        payload[3] = IPC_GET_BYTE(data->NAVData, 0);
        /* Send IPC */
        ret = IPC_STB_DataSend(payload, IPC_M2S_GNSS_NAV_MSGSUB_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: FrameLoss */
/* Transmit function of sub message Data */
int32_t IPC_M2S_GNSSFrameLossData_Transmit(IPC_M2S_GNSSFrameLossData_t *data)
{
    uint8_t payload[IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_GNSS_ID;
        payload[1] = IPC_M2S_GNSS_MSGMAJOR_FRAMELOSS_ID;
        payload[2] = IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_ID;
        payload[3] = IPC_GET_BYTE(data->FrameLossNum, 1);
        payload[4] = IPC_GET_BYTE(data->FrameLossNum, 0);
        /* Send IPC */
        ret = IPC_STB_DataSend(payload, IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: Config */
/* Transmit function of sub message NMEA_Data */
int32_t IPC_M2S_GNSSConfigNMEA_Data_Transmit(IPC_M2S_GNSSConfigNMEA_Data_t *data)
{
    uint8_t payload[IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_GNSS_ID;
        payload[1] = IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID;
        payload[2] = IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_ID;
        payload[3] = IPC_GET_BYTE(data->NmeaVersion, 0);
        /* Send IPC */
        ret = IPC_STB_DataSend(payload, IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message NAV_Data */
int32_t IPC_M2S_GNSSConfigNAV_Data_Transmit(IPC_M2S_GNSSConfigNAV_Data_t *data)
{
    uint8_t payload[IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_GNSS_ID;
        payload[1] = IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID;
        payload[2] = IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_ID;
        payload[3] = IPC_GET_BYTE(data->NAVData, 0);
        /* Send IPC */
        ret = IPC_STB_DataSend(payload, IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message FrameLoss_Data */
int32_t IPC_M2S_GNSSConfigFrameLoss_Data_Transmit(IPC_M2S_GNSSConfigFrameLoss_Data_t *data)
{
    uint8_t payload[IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_GNSS_ID;
        payload[1] = IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID;
        payload[2] = IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_ID;
        payload[3] = IPC_GET_BYTE(data->FrameLossNum, 1);
        payload[4] = IPC_GET_BYTE(data->FrameLossNum, 0);
        /* Send IPC */
        ret = IPC_STB_DataSend(payload, IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message PDTINFO_Data */
int32_t IPC_M2S_GNSSConfigPDTINFO_Data_Transmit(IPC_M2S_GNSSConfigPDTINFO_Data_t *data)
{
    uint8_t payload[IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->PDTINFODataLength <= IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_GNSS_ID;
        payload[1] = IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID;
        payload[2] = IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_ID;
        payload[3] = (uint8_t)(data->PDTINFODataLength >> 8);
        payload[4] = (uint8_t)(data->PDTINFODataLength);
        flexLength = data->PDTINFODataLength * sizeof(data->PDTINFOData[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->PDTINFODataLength; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->PDTINFOData[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_STB_DataSend(payload, IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message reserved */
void IPC_S2M_GNSSReservedreserved_Receive(uint8_t *receiveData, IPC_S2M_GNSSReservedreserved_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_RESERVED_MSGSUB_RESERVED_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->reserved, 0) = receiveData[0];
    }

}

/* Message Major: NMEA */
/* Receive function of sub message Read */
void IPC_S2M_GNSSNMEARead_Receive(uint8_t *receiveData, IPC_S2M_GNSSNMEARead_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_NMEA_MSGSUB_READ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = receiveData[0];
    }

}

/* Receive function of sub message Write */
void IPC_S2M_GNSSNMEAWrite_Receive(uint8_t *receiveData, IPC_S2M_GNSSNMEAWrite_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = receiveData[0];
    }

}

/* Message Major: NAV */
/* Receive function of sub message Read */
void IPC_S2M_GNSSNAVRead_Receive(uint8_t *receiveData, IPC_S2M_GNSSNAVRead_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_NAV_MSGSUB_READ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->NAVData, 0) = receiveData[0];
    }

}

/* Receive function of sub message Write */
void IPC_S2M_GNSSNAVWrite_Receive(uint8_t *receiveData, IPC_S2M_GNSSNAVWrite_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_NAV_MSGSUB_WRITE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->NAVData, 0) = receiveData[0];
    }

}

/* Message Major: FrameLoss */
/* Receive function of sub message Read */
void IPC_S2M_GNSSFrameLossRead_Receive(uint8_t *receiveData, IPC_S2M_GNSSFrameLossRead_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = receiveData[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = receiveData[1];
    }

}

/* Receive function of sub message Write */
void IPC_S2M_GNSSFrameLossWrite_Receive(uint8_t *receiveData, IPC_S2M_GNSSFrameLossWrite_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_FRAMELOSS_MSGSUB_WRITE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = receiveData[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = receiveData[1];
    }

}

/* Message Major: Config */
/* Receive function of sub message NMEA_Read */
void IPC_S2M_GNSSConfigNMEA_Read_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigNMEA_Read_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = receiveData[0];
    }

}

/* Receive function of sub message NMEA_Write */
void IPC_S2M_GNSSConfigNMEA_Write_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigNMEA_Write_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->NmeaVersion, 0) = receiveData[0];
    }

}

/* Receive function of sub message NAV_Read */
void IPC_S2M_GNSSConfigNAV_Read_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigNAV_Read_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->NAVData, 0) = receiveData[0];
    }

}

/* Receive function of sub message NAV_Write */
void IPC_S2M_GNSSConfigNAV_Write_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigNAV_Write_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->NAVData, 0) = receiveData[0];
    }

}

/* Receive function of sub message FrameLoss_Read */
void IPC_S2M_GNSSConfigFrameLoss_Read_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigFrameLoss_Read_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = receiveData[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = receiveData[1];
    }

}

/* Receive function of sub message FrameLoss_Write */
void IPC_S2M_GNSSConfigFrameLoss_Write_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigFrameLoss_Write_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->FrameLossNum, 1) = receiveData[0];
        IPC_GET_BYTE(data->FrameLossNum, 0) = receiveData[1];
    }

}

/* Receive function of sub message PDTINFO_Read */
void IPC_S2M_GNSSConfigPDTINFO_Read_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigPDTINFO_Read_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->PDTINFORead, 0) = receiveData[0];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"

#endif
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
