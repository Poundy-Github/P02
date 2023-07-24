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
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group SAFETY source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_SAFETY.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: SAFETY */
/* Message Major: APP */
/* Pack function of sub message TT_Safety */
int32_t IPC_M2S_SAFETYAPPTT_Safety_Pack(IPC_M2S_SAFETYAPPTT_Safety_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 14; arrIndex++)
            {
                payload[5 + arrIndex * 1] = IPC_GET_BYTE(data->u_TT_Safetyu32Telltales_status_t.u32Telltales_status[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message TT_Safety */
int32_t IPC_M2S_SAFETYAPPTT_Safety_Parse(IPC_M2S_SAFETYAPPTT_Safety_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 14; arrIndex++)
            {
                IPC_GET_BYTE(data->u_TT_Safetyu32Telltales_status_t.u32Telltales_status[arrIndex], 0) = payload[0 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Gear */
int32_t IPC_M2S_SAFETYAPPGear_Pack(IPC_M2S_SAFETYAPPGear_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SAFETY_APP_MSGSUB_GEAR_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_SAFETY_APP_MSGSUB_GEAR_ID;
        payload[5] = IPC_GET_BYTE(data->gear_vlaue, 0);
        payload[6] = IPC_GET_BYTE(data->gear_status, 0);
        payload[7] = IPC_GET_BYTE(data->gear_shift_value, 0);
        totalLength = IPC_M2S_SAFETY_APP_MSGSUB_GEAR_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Gear */
int32_t IPC_M2S_SAFETYAPPGear_Parse(IPC_M2S_SAFETYAPPGear_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SAFETY_APP_MSGSUB_GEAR_LENGTH == length))
    {
        IPC_GET_BYTE(data->gear_vlaue, 0) = payload[0];
        IPC_GET_BYTE(data->gear_status, 0) = payload[1];
        IPC_GET_BYTE(data->gear_shift_value, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SafetyTelltaleCheck */
int32_t IPC_M2S_SAFETYAPPSafetyTelltaleCheck_Pack(IPC_M2S_SAFETYAPPSafetyTelltaleCheck_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_ID;
        if((data->TT_ACKLength <= IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->TT_ACKLength >> 8);
            payload[6] = (uint8_t)(data->TT_ACKLength);
            flexLength = data->TT_ACKLength * sizeof(data->TT_ACK[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->TT_ACKLength; arrIndex++)
                {
                    payload[7 + arrIndex * 1] = IPC_GET_BYTE(data->TT_ACK[arrIndex], 0);
                }
            }
            totalLength = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message SafetyTelltaleCheck */
int32_t IPC_M2S_SAFETYAPPSafetyTelltaleCheck_Parse(IPC_M2S_SAFETYAPPSafetyTelltaleCheck_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH >= length) &&
        (IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH_MIN <= length))
    {
        data->TT_ACKLength = (payload[0] << 8) | payload[1];
        if(data->TT_ACKLength <= IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_FLEX_NUMBER)
        {
            uint16_t flexLength = data->TT_ACKLength * sizeof(data->TT_ACK[0]);
            if(length == flexLength + IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH_MIN)
            {
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->TT_ACKLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->TT_ACK[arrIndex], 0) = payload[2 + arrIndex * 1];
                    }
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/* Pack function of sub message SafetyGearCheck */
int32_t IPC_M2S_SAFETYAPPSafetyGearCheck_Pack(IPC_M2S_SAFETYAPPSafetyGearCheck_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_ID;
        payload[5] = IPC_GET_BYTE(data->u_SafetyGearCheckGear_ACK_t.Gear_ACK, 0);
        totalLength = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SafetyGearCheck */
int32_t IPC_M2S_SAFETYAPPSafetyGearCheck_Parse(IPC_M2S_SAFETYAPPSafetyGearCheck_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_LENGTH == length))
    {
        IPC_GET_BYTE(data->u_SafetyGearCheckGear_ACK_t.Gear_ACK, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SafetyAppMsgUploaded */
int32_t IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_Pack(IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_M2S_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_ID;
        payload[5] = IPC_GET_BYTE(data->Status, 0);
        totalLength = IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SafetyAppMsgUploaded */
int32_t IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_Parse(IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_LENGTH == length))
    {
        IPC_GET_BYTE(data->Status, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: MANAGEMENT */
/* Pack function of sub message SafetyAlive */
int32_t IPC_M2S_SAFETYMANAGEMENTSafetyAlive_Pack(IPC_M2S_SAFETYMANAGEMENTSafetyAlive_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_M2S_SAFETY_MSGMAJOR_MANAGEMENT_ID;
        payload[4] = IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_ID;
        payload[5] = IPC_GET_BYTE(data->RollingCounter, 0);
        totalLength = IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SafetyAlive */
int32_t IPC_M2S_SAFETYMANAGEMENTSafetyAlive_Parse(IPC_M2S_SAFETYMANAGEMENTSafetyAlive_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_LENGTH == length))
    {
        IPC_GET_BYTE(data->RollingCounter, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SafetyAppAlive */
int32_t IPC_S2M_SAFETYAPPSafetyAppAlive_Pack(IPC_S2M_SAFETYAPPSafetyAppAlive_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SAFETY_APP_MSGSUB_SAFETYAPPALIVE_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_S2M_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_S2M_SAFETY_APP_MSGSUB_SAFETYAPPALIVE_ID;
        payload[5] = IPC_GET_BYTE(data->AliveTick, 0);
        totalLength = IPC_S2M_SAFETY_APP_MSGSUB_SAFETYAPPALIVE_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SafetyAppAlive */
int32_t IPC_S2M_SAFETYAPPSafetyAppAlive_Parse(IPC_S2M_SAFETYAPPSafetyAppAlive_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_SAFETY_APP_MSGSUB_SAFETYAPPALIVE_LENGTH == length))
    {
        IPC_GET_BYTE(data->AliveTick, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SafetyTTCRC */
int32_t IPC_S2M_SAFETYAPPSafetyTTCRC_Pack(IPC_S2M_SAFETYAPPSafetyTTCRC_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_S2M_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_ID;
        if((data->TT_CRCLength <= IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_FLEX_NUMBER))
        {
            uint16_t flexLength;

            payload[5] = (uint8_t)(data->TT_CRCLength >> 8);
            payload[6] = (uint8_t)(data->TT_CRCLength);
            flexLength = data->TT_CRCLength * sizeof(data->TT_CRC[0]);
            {
                uint16_t arrIndex;
                for(arrIndex = 0; arrIndex < data->TT_CRCLength; arrIndex++)
                {
                    payload[7 + arrIndex * 1] = IPC_GET_BYTE(data->TT_CRC[arrIndex], 0);
                }
            }
            totalLength = IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH_MIN + flexLength + 5;
            payload[0] = (uint8_t)(totalLength >> 8);
            payload[1] = (uint8_t)(totalLength);
            ret = (int32_t)totalLength;
        }
    }
    return ret;
}
/* Parse function of sub message SafetyTTCRC */
int32_t IPC_S2M_SAFETYAPPSafetyTTCRC_Parse(IPC_S2M_SAFETYAPPSafetyTTCRC_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((data != NULL) && (IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH >= length) &&
        (IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH_MIN <= length))
    {
        data->TT_CRCLength = (payload[0] << 8) | payload[1];
        if(data->TT_CRCLength <= IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_FLEX_NUMBER)
        {
            uint16_t flexLength = data->TT_CRCLength * sizeof(data->TT_CRC[0]);
            if(length == flexLength + IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH_MIN)
            {
                {
                    uint16_t arrIndex;
                    for(arrIndex = 0; arrIndex < data->TT_CRCLength; arrIndex++)
                    {
                        IPC_GET_BYTE(data->TT_CRC[arrIndex], 0) = payload[2 + arrIndex * 1];
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SafetyGearCRC */
int32_t IPC_S2M_SAFETYAPPSafetyGearCRC_Pack(IPC_S2M_SAFETYAPPSafetyGearCRC_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SAFETY_APP_MSGSUB_SAFETYGEARCRC_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_S2M_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_S2M_SAFETY_APP_MSGSUB_SAFETYGEARCRC_ID;
        payload[5] = IPC_GET_BYTE(data->CRC_Value, 3);
        payload[6] = IPC_GET_BYTE(data->CRC_Value, 2);
        payload[7] = IPC_GET_BYTE(data->CRC_Value, 1);
        payload[8] = IPC_GET_BYTE(data->CRC_Value, 0);
        payload[9] = IPC_GET_BYTE(data->Gear_ID, 0);
        totalLength = IPC_S2M_SAFETY_APP_MSGSUB_SAFETYGEARCRC_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SafetyGearCRC */
int32_t IPC_S2M_SAFETYAPPSafetyGearCRC_Parse(IPC_S2M_SAFETYAPPSafetyGearCRC_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_SAFETY_APP_MSGSUB_SAFETYGEARCRC_LENGTH == length))
    {
        IPC_GET_BYTE(data->CRC_Value, 3) = payload[0];
        IPC_GET_BYTE(data->CRC_Value, 2) = payload[1];
        IPC_GET_BYTE(data->CRC_Value, 1) = payload[2];
        IPC_GET_BYTE(data->CRC_Value, 0) = payload[3];
        IPC_GET_BYTE(data->Gear_ID, 0) = payload[4];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TTSelfCheck */
int32_t IPC_S2M_SAFETYAPPTTSelfCheck_Pack(IPC_S2M_SAFETYAPPTTSelfCheck_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_SAFETY_APP_MSGSUB_TTSELFCHECK_LENGTH))
    {
        payload[2] = IPC_GROUP_SAFETY_ID;
        payload[3] = IPC_S2M_SAFETY_MSGMAJOR_APP_ID;
        payload[4] = IPC_S2M_SAFETY_APP_MSGSUB_TTSELFCHECK_ID;
        payload[5] = IPC_GET_BYTE(data->TT_SelfCheck_Sts, 0);
        totalLength = IPC_S2M_SAFETY_APP_MSGSUB_TTSELFCHECK_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message TTSelfCheck */
int32_t IPC_S2M_SAFETYAPPTTSelfCheck_Parse(IPC_S2M_SAFETYAPPTTSelfCheck_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_SAFETY_APP_MSGSUB_TTSELFCHECK_LENGTH == length))
    {
        IPC_GET_BYTE(data->TT_SelfCheck_Sts, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
