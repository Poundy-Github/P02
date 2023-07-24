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
 *                 File:  IPC_SWUM.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group SWUM source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_SWUM.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: SWUM */
/* Message Major: SWUM_UDS */
/* Transmit function of sub message SessionControlResponse */
int32_t IPC_M2S_SWUMSWUM_UDSSessionControlResponse_Transmit(IPC_M2S_SWUMSWUM_UDSSessionControlResponse_t *data)
{
    uint8_t payload[IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SWUM_ID;
        payload[1] = IPC_M2S_SWUM_MSGMAJOR_SWUM_UDS_ID;
        payload[2] = IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_ID;
        payload[3] = IPC_GET_BYTE(data->Service, 0);
        payload[4] = IPC_GET_BYTE(data->SessionType, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROLRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Response */
int32_t IPC_M2S_SWUMSWUM_UDSResponse_Transmit(IPC_M2S_SWUMSWUM_UDSResponse_t *data)
{
    uint8_t payload[IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->ResponseLength <= IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_SWUM_ID;
        payload[1] = IPC_M2S_SWUM_MSGMAJOR_SWUM_UDS_ID;
        payload[2] = IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_ID;
        payload[3] = (uint8_t)(data->ResponseLength >> 8);
        payload[4] = (uint8_t)(data->ResponseLength);
        payload[5] = IPC_GET_BYTE(data->SID, 0);
        flexLength = data->ResponseLength * sizeof(data->Response[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->ResponseLength; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->Response[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SWUM_SWUM_UDS_MSGSUB_RESPONSE_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message SessionControl */
void IPC_S2M_SWUMSWUM_UDSSessionControl_Receive(uint8_t *receiveData, IPC_S2M_SWUMSWUM_UDSSessionControl_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROL_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->Service, 0) = receiveData[0];
        IPC_GET_BYTE(data->Type, 0) = receiveData[1];
    }

}

/* Receive function of sub message Request */
void IPC_S2M_SWUMSWUM_UDSRequest_Receive(uint8_t *receiveData, IPC_S2M_SWUMSWUM_UDSRequest_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH>= payloadLength) &&
        (IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH_MIN <= payloadLength))
    {
        data->RequestLength = (receiveData[0] << 8) | receiveData[1];
        if(data->RequestLength <= IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_FLEX_NUMBER)
        {
            uint16_t flexLength = data->RequestLength * sizeof(data->Request[0]);
            if(payloadLength == flexLength + IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->SID, 0) = receiveData[2];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->RequestLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Request[arrIndex], 0) = receiveData[3 + arrIndex * 1];
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
