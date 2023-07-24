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
 *                 File:  IPC_SAFETY.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group SAFETY source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_SAFETY.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: SAFETY */
/* Message Major: APP */
/* Transmit function of sub message TT_Safety */
int32_t IPC_M2S_SAFETYAPPTT_Safety_Transmit(IPC_M2S_SAFETYAPPTT_Safety_t *data)
{
    uint8_t payload[IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SAFETY_ID;
        payload[1] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 14; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->u_TT_Safetyu32Telltales_status_t.u32Telltales_status[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Gear */
int32_t IPC_M2S_SAFETYAPPGear_Transmit(IPC_M2S_SAFETYAPPGear_t *data)
{
    uint8_t payload[IPC_M2S_SAFETY_APP_MSGSUB_GEAR_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SAFETY_ID;
        payload[1] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_SAFETY_APP_MSGSUB_GEAR_ID;
        payload[3] = IPC_GET_BYTE(data->gear_vlaue, 0);
        payload[4] = IPC_GET_BYTE(data->gear_status, 0);
        payload[5] = IPC_GET_BYTE(data->gear_shift_value, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SAFETY_APP_MSGSUB_GEAR_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message SafetyTelltaleCheck */
int32_t IPC_M2S_SAFETYAPPSafetyTelltaleCheck_Transmit(IPC_M2S_SAFETYAPPSafetyTelltaleCheck_t *data)
{
    uint8_t payload[IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if((data != NULL) && (data->TT_ACKLength <= IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_FLEX_NUMBER))
    {
        uint16_t flexLength;
        payload[0] = IPC_GROUP_SAFETY_ID;
        payload[1] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_ID;
        payload[3] = (uint8_t)(data->TT_ACKLength >> 8);
        payload[4] = (uint8_t)(data->TT_ACKLength);
        flexLength = data->TT_ACKLength * sizeof(data->TT_ACK[0]);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < data->TT_ACKLength; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->TT_ACK[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH_MIN + IPC_TRANSPORT_OVERHEAD+ flexLength, IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message SafetyGearCheck */
int32_t IPC_M2S_SAFETYAPPSafetyGearCheck_Transmit(IPC_M2S_SAFETYAPPSafetyGearCheck_t *data)
{
    uint8_t payload[IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SAFETY_ID;
        payload[1] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_ID;
        payload[3] = IPC_GET_BYTE(data->u_SafetyGearCheckGear_ACK_t.Gear_ACK, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message SafetyAppMsgUploaded */
int32_t IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_Transmit(IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_t *data)
{
    uint8_t payload[IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SAFETY_ID;
        payload[1] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_ID;
        payload[3] = IPC_GET_BYTE(data->Status, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: MANAGEMENT */
/* Transmit function of sub message SafetyAlive */
int32_t IPC_M2S_SAFETYMANAGEMENTSafetyAlive_Transmit(IPC_M2S_SAFETYMANAGEMENTSafetyAlive_t *data)
{
    uint8_t payload[IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_SAFETY_ID;
        payload[1] = IPC_M2S_SAFETY_MSGMAJOR_MANAGEMENT_ID;
        payload[2] = IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_ID;
        payload[3] = IPC_GET_BYTE(data->RollingCounter, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Receive function of sub message SafetyAppAlive */
void IPC_S2M_SAFETYAPPSafetyAppAlive_Receive(uint8_t *receiveData, IPC_S2M_SAFETYAPPSafetyAppAlive_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_SAFETY_APP_MSGSUB_SAFETYAPPALIVE_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->AliveTick, 0) = receiveData[0];
    }

}

/* Receive function of sub message SafetyTTCRC */
void IPC_S2M_SAFETYAPPSafetyTTCRC_Receive(uint8_t *receiveData, IPC_S2M_SAFETYAPPSafetyTTCRC_t *data, uint32_t payloadLength)
{
    if((data != NULL) && (IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH>= payloadLength) &&
        (IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH_MIN <= payloadLength))
    {
        data->TT_CRCLength = (receiveData[0] << 8) | receiveData[1];
        if(data->TT_CRCLength <= IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_FLEX_NUMBER)
        {
            uint16_t flexLength = data->TT_CRCLength * sizeof(data->TT_CRC[0]);
            if(payloadLength == flexLength + IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH_MIN)
            {
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->TT_CRCLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->TT_CRC[arrIndex], 0) = receiveData[2 + arrIndex * 1];
                    }
                }
            }
        }
    }

}

/* Receive function of sub message SafetyGearCRC */
void IPC_S2M_SAFETYAPPSafetyGearCRC_Receive(uint8_t *receiveData, IPC_S2M_SAFETYAPPSafetyGearCRC_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_SAFETY_APP_MSGSUB_SAFETYGEARCRC_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->CRC_Value, 3) = receiveData[0];
        IPC_GET_BYTE(data->CRC_Value, 2) = receiveData[1];
        IPC_GET_BYTE(data->CRC_Value, 1) = receiveData[2];
        IPC_GET_BYTE(data->CRC_Value, 0) = receiveData[3];
        IPC_GET_BYTE(data->Gear_ID, 0) = receiveData[4];
    }

}

/* Receive function of sub message TTSelfCheck */
void IPC_S2M_SAFETYAPPTTSelfCheck_Receive(uint8_t *receiveData, IPC_S2M_SAFETYAPPTTSelfCheck_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_SAFETY_APP_MSGSUB_TTSELFCHECK_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->TT_SelfCheck_Sts, 0) = receiveData[0];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
