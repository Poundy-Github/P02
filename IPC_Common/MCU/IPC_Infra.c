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
 *                 File:  IPC_Infra.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group Infra source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Infra.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Infra */
/* Message Major: Misc */
/* Transmit function of sub message RestoreFactorySettingResponse */
int32_t IPC_M2S_InfraMiscRestoreFactorySettingResponse_Transmit(IPC_M2S_InfraMiscRestoreFactorySettingResponse_t *data)
{
    uint8_t payload[IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_INFRA_ID;
        payload[1] = IPC_M2S_INFRA_MSGMAJOR_MISC_ID;
        payload[2] = IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_ID;
        payload[3] = IPC_GET_BYTE(data->Response, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message ReadSerialNumberResponse */
int32_t IPC_M2S_InfraMiscReadSerialNumberResponse_Transmit(IPC_M2S_InfraMiscReadSerialNumberResponse_t *data)
{
    uint8_t payload[IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_INFRA_ID;
        payload[1] = IPC_M2S_INFRA_MSGMAJOR_MISC_ID;
        payload[2] = IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_ID;
        payload[3] = (uint8_t)(data->DataLength >> 8);
        payload[4] = (uint8_t)(data->DataLength);
        flexLength = data->DataLength * sizeof(data->Data[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message ReadVINNumberResponse */
int32_t IPC_M2S_InfraMiscReadVINNumberResponse_Transmit(IPC_M2S_InfraMiscReadVINNumberResponse_t *data)
{
    uint8_t payload[IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_INFRA_ID;
        payload[1] = IPC_M2S_INFRA_MSGMAJOR_MISC_ID;
        payload[2] = IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_ID;
        payload[3] = (uint8_t)(data->DataLength >> 8);
        payload[4] = (uint8_t)(data->DataLength);
        flexLength = data->DataLength * sizeof(data->Data[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message ReadBeanIDResponse */
int32_t IPC_M2S_InfraMiscReadBeanIDResponse_Transmit(IPC_M2S_InfraMiscReadBeanIDResponse_t *data)
{
    uint8_t payload[IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataLength <= IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_INFRA_ID;
        payload[1] = IPC_M2S_INFRA_MSGMAJOR_MISC_ID;
        payload[2] = IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_ID;
        payload[3] = (uint8_t)(data->DataLength >> 8);
        payload[4] = (uint8_t)(data->DataLength);
        payload[5] = IPC_GET_BYTE(data->Status, 0);
        flexLength = data->DataLength * sizeof(data->Data[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message RestoreFactorySettingRequset */
void IPC_S2M_InfraMiscRestoreFactorySettingRequset_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscRestoreFactorySettingRequset_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGREQUSET_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->Request, 0) = receiveData[0];
    }

}

/* Receive function of sub message ReadSerialNumberRequest */
void IPC_S2M_InfraMiscReadSerialNumberRequest_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscReadSerialNumberRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_READSERIALNUMBERREQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->Request, 0) = receiveData[0];
    }

}

/* Receive function of sub message ReadVINNumberRequest */
void IPC_S2M_InfraMiscReadVINNumberRequest_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscReadVINNumberRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_READVINNUMBERREQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->Request, 0) = receiveData[0];
    }

}

/* Receive function of sub message ReadBeanIDRequest */
void IPC_S2M_InfraMiscReadBeanIDRequest_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscReadBeanIDRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_READBEANIDREQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->Request, 0) = receiveData[0];
    }

}

/* Receive function of sub message SetAVASSwitchStatus */
void IPC_S2M_InfraMiscSetAVASSwitchStatus_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscSetAVASSwitchStatus_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_INFRA_MISC_MSGSUB_SETAVASSWITCHSTATUS_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->Switch, 0) = receiveData[0];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
