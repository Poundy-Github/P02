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
 *                 File:  IPC_IVIApp.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group IVIApp source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_IVIApp.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: IVIApp */
/* Message Major: Info */
/* Transmit function of sub message ReadSettingSignalResp */
int32_t IPC_M2S_IVIAppInfoReadSettingSignalResp_Transmit(IPC_M2S_IVIAppInfoReadSettingSignalResp_t *data)
{
    uint8_t payload[IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataLength <= IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_IVIAPP_ID;
        payload[1] = IPC_M2S_IVIAPP_MSGMAJOR_INFO_ID;
        payload[2] = IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_ID;
        payload[3] = (uint8_t)(data->DataLength >> 8);
        payload[4] = (uint8_t)(data->DataLength);
        payload[5] = IPC_GET_BYTE(data->ClientID, 3);
        payload[6] = IPC_GET_BYTE(data->ClientID, 2);
        payload[7] = IPC_GET_BYTE(data->ClientID, 1);
        payload[8] = IPC_GET_BYTE(data->ClientID, 0);
        payload[9] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[10] = IPC_GET_BYTE(data->InfoID, 3);
        payload[11] = IPC_GET_BYTE(data->InfoID, 2);
        payload[12] = IPC_GET_BYTE(data->InfoID, 1);
        payload[13] = IPC_GET_BYTE(data->InfoID, 0);
        flexLength = data->DataLength * sizeof(data->Data[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
            {
                payload[14 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALRESP_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message SetSettingSignalResp */
int32_t IPC_M2S_IVIAppInfoSetSettingSignalResp_Transmit(IPC_M2S_IVIAppInfoSetSettingSignalResp_t *data)
{
    uint8_t payload[IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->DataLength <= IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_IVIAPP_ID;
        payload[1] = IPC_M2S_IVIAPP_MSGMAJOR_INFO_ID;
        payload[2] = IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_ID;
        payload[3] = (uint8_t)(data->DataLength >> 8);
        payload[4] = (uint8_t)(data->DataLength);
        payload[5] = IPC_GET_BYTE(data->ClientID, 3);
        payload[6] = IPC_GET_BYTE(data->ClientID, 2);
        payload[7] = IPC_GET_BYTE(data->ClientID, 1);
        payload[8] = IPC_GET_BYTE(data->ClientID, 0);
        payload[9] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[10] = IPC_GET_BYTE(data->InfoID, 3);
        payload[11] = IPC_GET_BYTE(data->InfoID, 2);
        payload[12] = IPC_GET_BYTE(data->InfoID, 1);
        payload[13] = IPC_GET_BYTE(data->InfoID, 0);
        payload[14] = IPC_GET_BYTE(data->Result, 0);
        flexLength = data->DataLength * sizeof(data->Data[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
            {
                payload[15 + arrIndex * 1] = IPC_GET_BYTE(data->Data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALRESP_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message ReadSettingSignalReq */
void IPC_S2M_IVIAppInfoReadSettingSignalReq_Receive(uint8_t *receiveData, IPC_S2M_IVIAppInfoReadSettingSignalReq_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALREQ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ClientID, 3) = receiveData[0];
        IPC_GET_BYTE(data->ClientID, 2) = receiveData[1];
        IPC_GET_BYTE(data->ClientID, 1) = receiveData[2];
        IPC_GET_BYTE(data->ClientID, 0) = receiveData[3];
        IPC_GET_BYTE(data->ModuleID, 0) = receiveData[4];
        IPC_GET_BYTE(data->InfoID, 3) = receiveData[5];
        IPC_GET_BYTE(data->InfoID, 2) = receiveData[6];
        IPC_GET_BYTE(data->InfoID, 1) = receiveData[7];
        IPC_GET_BYTE(data->InfoID, 0) = receiveData[8];
    }

}

/* Receive function of sub message SetSettingSignalReq */
void IPC_S2M_IVIAppInfoSetSettingSignalReq_Receive(uint8_t *receiveData, IPC_S2M_IVIAppInfoSetSettingSignalReq_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH>= payloadLength) &&
        (IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH_MIN <= payloadLength))
    {
        data->DataLength = (receiveData[0] << 8) | receiveData[1];
        if(data->DataLength <= IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_FLEX_NUMBER)
        {
            uint16_t flexLength = data->DataLength * sizeof(data->Data[0]);
            if(payloadLength == flexLength + IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_LENGTH_MIN)
            {
                IPC_GET_BYTE(data->ClientID, 3) = receiveData[2];
                IPC_GET_BYTE(data->ClientID, 2) = receiveData[3];
                IPC_GET_BYTE(data->ClientID, 1) = receiveData[4];
                IPC_GET_BYTE(data->ClientID, 0) = receiveData[5];
                IPC_GET_BYTE(data->ModuleID, 0) = receiveData[6];
                IPC_GET_BYTE(data->InfoID, 3) = receiveData[7];
                IPC_GET_BYTE(data->InfoID, 2) = receiveData[8];
                IPC_GET_BYTE(data->InfoID, 1) = receiveData[9];
                IPC_GET_BYTE(data->InfoID, 0) = receiveData[10];
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->DataLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->Data[arrIndex], 0) = receiveData[11 + arrIndex * 1];
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
