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
 *                 File:  IPC_Engineer.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group Engineer source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Engineer.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Engineer */
/* Message Major: IVI */
/* Transmit function of sub message ReadInfoResponse */
int32_t IPC_M2S_EngineerIVIReadInfoResponse_Transmit(IPC_M2S_EngineerIVIReadInfoResponse_t *data)
{
    uint8_t payload[IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataLength <= IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_ENGINEER_ID;
        payload[1] = IPC_M2S_ENGINEER_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_ID;
        payload[3] = (uint8_t)(data->DataLength >> 8);
        payload[4] = (uint8_t)(data->DataLength);
        payload[5] = IPC_GET_BYTE(data->ModuleId, 0);
        payload[6] = IPC_GET_BYTE(data->InfoId, 1);
        payload[7] = IPC_GET_BYTE(data->InfoId, 0);
        payload[8] = IPC_GET_BYTE(data->Result, 0);
        flexLength = data->DataLength * sizeof(data->Data[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
            {
                payload[9 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_ENGINEER_IVI_MSGSUB_READINFORESPONSE_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message SetParaResponse */
int32_t IPC_M2S_EngineerIVISetParaResponse_Transmit(IPC_M2S_EngineerIVISetParaResponse_t *data)
{
    uint8_t payload[IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_ENGINEER_ID;
        payload[1] = IPC_M2S_ENGINEER_MSGMAJOR_IVI_ID;
        payload[2] = IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_ID;
        payload[3] = IPC_GET_BYTE(data->ModuleId, 0);
        payload[4] = IPC_GET_BYTE(data->InfoId, 1);
        payload[5] = IPC_GET_BYTE(data->InfoId, 0);
        payload[6] = IPC_GET_BYTE(data->Result, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_ENGINEER_IVI_MSGSUB_SETPARARESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message ReadInfoRequest */
void IPC_S2M_EngineerIVIReadInfoRequest_Receive(uint8_t *receiveData, IPC_S2M_EngineerIVIReadInfoRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_ENGINEER_IVI_MSGSUB_READINFOREQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ModuleId, 0) = receiveData[0];
        IPC_GET_BYTE(data->InfoId, 1) = receiveData[1];
        IPC_GET_BYTE(data->InfoId, 0) = receiveData[2];
    }

}

/* Receive function of sub message SetParaRequest */
void IPC_S2M_EngineerIVISetParaRequest_Receive(uint8_t *receiveData, IPC_S2M_EngineerIVISetParaRequest_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH>= payloadLength) &&
        (IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH_MIN <= payloadLength))
    {
        data->DataLength = (receiveData[0] << 8) | receiveData[1];
        if(data->DataLength <= IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(payloadLength == flexLength + IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ModuleId, 0) = receiveData[2];
                IPC_GET_BYTE(data->InfoId, 1) = receiveData[3];
                IPC_GET_BYTE(data->InfoId, 0) = receiveData[4];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = receiveData[5 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
