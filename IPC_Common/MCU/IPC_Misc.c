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
 *                 File:  IPC_Misc.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group Misc source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Misc.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Misc */
/* Message Major: RTC */
/* Transmit function of sub message ACK */
int32_t IPC_M2S_MiscRTCACK_Transmit(IPC_M2S_MiscRTCACK_t *data)
{
    uint8_t payload[IPC_M2S_MISC_RTC_MSGSUB_ACK_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_RTC_ID;
        payload[2] = IPC_M2S_MISC_RTC_MSGSUB_ACK_ID;
        payload[3] = IPC_GET_BYTE(data->States, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_RTC_MSGSUB_ACK_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message TIME */
int32_t IPC_M2S_MiscRTCTIME_Transmit(IPC_M2S_MiscRTCTIME_t *data)
{
    uint8_t payload[IPC_M2S_MISC_RTC_MSGSUB_TIME_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_RTC_ID;
        payload[2] = IPC_M2S_MISC_RTC_MSGSUB_TIME_ID;
        payload[3] = IPC_GET_BYTE(data->UTC_Time, 7);
        payload[4] = IPC_GET_BYTE(data->UTC_Time, 6);
        payload[5] = IPC_GET_BYTE(data->UTC_Time, 5);
        payload[6] = IPC_GET_BYTE(data->UTC_Time, 4);
        payload[7] = IPC_GET_BYTE(data->UTC_Time, 3);
        payload[8] = IPC_GET_BYTE(data->UTC_Time, 2);
        payload[9] = IPC_GET_BYTE(data->UTC_Time, 1);
        payload[10] = IPC_GET_BYTE(data->UTC_Time, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_RTC_MSGSUB_TIME_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: Service */
/* Transmit function of sub message Reply */
int32_t IPC_M2S_MiscServiceReply_Transmit(IPC_M2S_MiscServiceReply_t *data)
{
    uint8_t payload[IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[2] = IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_ID;
        payload[3] = IPC_GET_BYTE(data->u8Channel, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_SERVICE_MSGSUB_REPLY_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Vconfig */
int32_t IPC_M2S_MiscServiceVconfig_Transmit(IPC_M2S_MiscServiceVconfig_t *data)
{
    uint8_t payload[IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[2] = IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 200; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->Vconfig_Buffer[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_SERVICE_MSGSUB_VCONFIG_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message TriggerMsg */
int32_t IPC_M2S_MiscServiceTriggerMsg_Transmit(IPC_M2S_MiscServiceTriggerMsg_t *data)
{
    uint8_t payload[IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[2] = IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_ID;
        payload[3] = IPC_GET_BYTE(data->TriggerSource, 0);
        payload[4] = IPC_GET_BYTE(data->Value, 1);
        payload[5] = IPC_GET_BYTE(data->Value, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_SERVICE_MSGSUB_TRIGGERMSG_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Vreply_Usb */
int32_t IPC_M2S_MiscServiceVreply_Usb_Transmit(IPC_M2S_MiscServiceVreply_Usb_t *data)
{
    uint8_t payload[IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[2] = IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_ID;
        payload[3] = IPC_GET_BYTE(data->u8Channel, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_SERVICE_MSGSUB_VREPLY_USB_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Cconfig */
int32_t IPC_M2S_MiscServiceCconfig_Transmit(IPC_M2S_MiscServiceCconfig_t *data)
{
    uint8_t payload[IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[2] = IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 300; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->Cconfig_Buffer[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_SERVICE_MSGSUB_CCONFIG_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Offset */
int32_t IPC_M2S_MiscServiceOffset_Transmit(IPC_M2S_MiscServiceOffset_t *data)
{
    uint8_t payload[IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_SERVICE_ID;
        payload[2] = IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->Offset_Buffer[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_SERVICE_MSGSUB_OFFSET_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: IVIInfo */
/* Transmit function of sub message ReadDrvModeResp */
int32_t IPC_M2S_MiscIVIInfoReadDrvModeResp_Transmit(IPC_M2S_MiscIVIInfoReadDrvModeResp_t *data)
{
    uint8_t payload[IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_IVIINFO_ID;
        payload[2] = IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_ID;
        payload[3] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[4] = IPC_GET_BYTE(data->InfoID, 1);
        payload[5] = IPC_GET_BYTE(data->InfoID, 0);
        payload[6] = IPC_GET_BYTE(data->Switch, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_IVIINFO_MSGSUB_READDRVMODERESP_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message WriteDrvModeResp */
int32_t IPC_M2S_MiscIVIInfoWriteDrvModeResp_Transmit(IPC_M2S_MiscIVIInfoWriteDrvModeResp_t *data)
{
    uint8_t payload[IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_MISC_ID;
        payload[1] = IPC_M2S_MISC_MSGMAJOR_IVIINFO_ID;
        payload[2] = IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_ID;
        payload[3] = IPC_GET_BYTE(data->ModuleID, 0);
        payload[4] = IPC_GET_BYTE(data->InfoID, 1);
        payload[5] = IPC_GET_BYTE(data->InfoID, 0);
        payload[6] = IPC_GET_BYTE(data->Result, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_MISC_IVIINFO_MSGSUB_WRITEDRVMODERESP_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message Get_Time_Request */
void IPC_S2M_MiscRTCGet_Time_Request_Receive(uint8_t *receiveData, IPC_S2M_MiscRTCGet_Time_Request_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_RTC_MSGSUB_GET_TIME_REQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->Reserve, 0) = receiveData[0];
    }

}

/* Receive function of sub message Set_Time_Request */
void IPC_S2M_MiscRTCSet_Time_Request_Receive(uint8_t *receiveData, IPC_S2M_MiscRTCSet_Time_Request_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_RTC_MSGSUB_SET_TIME_REQUEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->UTC_Time, 7) = receiveData[0];
        IPC_GET_BYTE(data->UTC_Time, 6) = receiveData[1];
        IPC_GET_BYTE(data->UTC_Time, 5) = receiveData[2];
        IPC_GET_BYTE(data->UTC_Time, 4) = receiveData[3];
        IPC_GET_BYTE(data->UTC_Time, 3) = receiveData[4];
        IPC_GET_BYTE(data->UTC_Time, 2) = receiveData[5];
        IPC_GET_BYTE(data->UTC_Time, 1) = receiveData[6];
        IPC_GET_BYTE(data->UTC_Time, 0) = receiveData[7];
    }

}

/* Message Major: Service */
/* Receive function of sub message WirtChannel */
void IPC_S2M_MiscServiceWirtChannel_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceWirtChannel_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_WIRTCHANNEL_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->u8Channel, 0) = receiveData[0];
        IPC_GET_BYTE(data->u8Level, 0) = receiveData[1];
    }

}

/* Receive function of sub message Get_Vconfig */
void IPC_S2M_MiscServiceGet_Vconfig_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceGet_Vconfig_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_GET_VCONFIG_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->request, 0) = receiveData[0];
    }

}

/* Receive function of sub message Vconfig_Reponse */
void IPC_S2M_MiscServiceVconfig_Reponse_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceVconfig_Reponse_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_REPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->result, 0) = receiveData[0];
    }

}

/* Receive function of sub message CheckTriggerMsg */
void IPC_S2M_MiscServiceCheckTriggerMsg_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceCheckTriggerMsg_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_CHECKTRIGGERMSG_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->TriggerSource, 0) = receiveData[0];
    }

}

/* Receive function of sub message Cconfig_Response */
void IPC_S2M_MiscServiceCconfig_Response_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceCconfig_Response_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_CCONFIG_RESPONSE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->result, 0) = receiveData[0];
    }

}

/* Receive function of sub message Vconfig_Usb */
void IPC_S2M_MiscServiceVconfig_Usb_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceVconfig_Usb_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_USB_LENGTH == payloadLength))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 200; arrIndex++)
            {
                IPC_GET_BYTE(data->Vconfig_Usb_Buffer[arrIndex], 0) = receiveData[0 + arrIndex * 1];
            }
        }
    }

}

/* Receive function of sub message Get_Cconfig */
void IPC_S2M_MiscServiceGet_Cconfig_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceGet_Cconfig_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_GET_CCONFIG_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->request, 0) = receiveData[0];
    }

}

/* Receive function of sub message Get_Offset */
void IPC_S2M_MiscServiceGet_Offset_Receive(uint8_t *receiveData, IPC_S2M_MiscServiceGet_Offset_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_SERVICE_MSGSUB_GET_OFFSET_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->request, 0) = receiveData[0];
    }

}

/* Message Major: IVIInfo */
/* Receive function of sub message ReadDrvModeReq */
void IPC_S2M_MiscIVIInfoReadDrvModeReq_Receive(uint8_t *receiveData, IPC_S2M_MiscIVIInfoReadDrvModeReq_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_IVIINFO_MSGSUB_READDRVMODEREQ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ModuleID, 0) = receiveData[0];
        IPC_GET_BYTE(data->InfoID, 1) = receiveData[1];
        IPC_GET_BYTE(data->InfoID, 0) = receiveData[2];
    }

}

/* Receive function of sub message WriteDrvModeReq */
void IPC_S2M_MiscIVIInfoWriteDrvModeReq_Receive(uint8_t *receiveData, IPC_S2M_MiscIVIInfoWriteDrvModeReq_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_MISC_IVIINFO_MSGSUB_WRITEDRVMODEREQ_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ModuleID, 0) = receiveData[0];
        IPC_GET_BYTE(data->InfoID, 1) = receiveData[1];
        IPC_GET_BYTE(data->InfoID, 0) = receiveData[2];
        IPC_GET_BYTE(data->Switch, 0) = receiveData[3];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
