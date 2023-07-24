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
 *                 File:  IPC_Audio.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group Audio source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Audio.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Audio */
/* Message Major: AMP */
/* Pack function of sub message Amp1StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp1StartupDiagResults_Pack(IPC_M2S_AudioAMPAmp1StartupDiagResults_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_ID;
        payload[5] = IPC_GET_BYTE(data->AMP1_Status, 0);
        payload[6] = IPC_GET_BYTE(data->CH1DCLoadCondition, 0);
        payload[7] = IPC_GET_BYTE(data->CH2DCLoadCondition, 0);
        payload[8] = IPC_GET_BYTE(data->CH3DCLoadCondition, 0);
        payload[9] = IPC_GET_BYTE(data->CH4DCLoadCondition, 0);
        payload[10] = IPC_GET_BYTE(data->CH1ACLoadCondition, 0);
        payload[11] = IPC_GET_BYTE(data->CH2ACLoadCondition, 0);
        payload[12] = IPC_GET_BYTE(data->CH3ACLoadCondition, 0);
        payload[13] = IPC_GET_BYTE(data->CH4ACLoadCondition, 0);
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Amp1StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp1StartupDiagResults_Parse(IPC_M2S_AudioAMPAmp1StartupDiagResults_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_LENGTH == length))
    {
        IPC_GET_BYTE(data->AMP1_Status, 0) = payload[0];
        IPC_GET_BYTE(data->CH1DCLoadCondition, 0) = payload[1];
        IPC_GET_BYTE(data->CH2DCLoadCondition, 0) = payload[2];
        IPC_GET_BYTE(data->CH3DCLoadCondition, 0) = payload[3];
        IPC_GET_BYTE(data->CH4DCLoadCondition, 0) = payload[4];
        IPC_GET_BYTE(data->CH1ACLoadCondition, 0) = payload[5];
        IPC_GET_BYTE(data->CH2ACLoadCondition, 0) = payload[6];
        IPC_GET_BYTE(data->CH3ACLoadCondition, 0) = payload[7];
        IPC_GET_BYTE(data->CH4ACLoadCondition, 0) = payload[8];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Amp2StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp2StartupDiagResults_Pack(IPC_M2S_AudioAMPAmp2StartupDiagResults_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_ID;
        payload[5] = IPC_GET_BYTE(data->AMP2_Status, 0);
        payload[6] = IPC_GET_BYTE(data->CH1DCLoadCondition, 0);
        payload[7] = IPC_GET_BYTE(data->CH2DCLoadCondition, 0);
        payload[8] = IPC_GET_BYTE(data->CH3DCLoadCondition, 0);
        payload[9] = IPC_GET_BYTE(data->CH4DCLoadCondition, 0);
        payload[10] = IPC_GET_BYTE(data->CH1ACLoadCondition, 0);
        payload[11] = IPC_GET_BYTE(data->CH2ACLoadCondition, 0);
        payload[12] = IPC_GET_BYTE(data->CH3ACLoadCondition, 0);
        payload[13] = IPC_GET_BYTE(data->CH4ACLoadCondition, 0);
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Amp2StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp2StartupDiagResults_Parse(IPC_M2S_AudioAMPAmp2StartupDiagResults_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_LENGTH == length))
    {
        IPC_GET_BYTE(data->AMP2_Status, 0) = payload[0];
        IPC_GET_BYTE(data->CH1DCLoadCondition, 0) = payload[1];
        IPC_GET_BYTE(data->CH2DCLoadCondition, 0) = payload[2];
        IPC_GET_BYTE(data->CH3DCLoadCondition, 0) = payload[3];
        IPC_GET_BYTE(data->CH4DCLoadCondition, 0) = payload[4];
        IPC_GET_BYTE(data->CH1ACLoadCondition, 0) = payload[5];
        IPC_GET_BYTE(data->CH2ACLoadCondition, 0) = payload[6];
        IPC_GET_BYTE(data->CH3ACLoadCondition, 0) = payload[7];
        IPC_GET_BYTE(data->CH4ACLoadCondition, 0) = payload[8];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Amp1PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp1PeriodDiagResults_Pack(IPC_M2S_AudioAMPAmp1PeriodDiagResults_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_ID;
        payload[5] = IPC_GET_BYTE(data->DeviceDiagResults_1, 0);
        payload[6] = IPC_GET_BYTE(data->DeviceDiagResults_2, 0);
        payload[7] = IPC_GET_BYTE(data->CH1DiagResults, 0);
        payload[8] = IPC_GET_BYTE(data->CH2DiagResults, 0);
        payload[9] = IPC_GET_BYTE(data->CH3DiagResults, 0);
        payload[10] = IPC_GET_BYTE(data->CH4DiagResults, 0);
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Amp1PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp1PeriodDiagResults_Parse(IPC_M2S_AudioAMPAmp1PeriodDiagResults_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_LENGTH == length))
    {
        IPC_GET_BYTE(data->DeviceDiagResults_1, 0) = payload[0];
        IPC_GET_BYTE(data->DeviceDiagResults_2, 0) = payload[1];
        IPC_GET_BYTE(data->CH1DiagResults, 0) = payload[2];
        IPC_GET_BYTE(data->CH2DiagResults, 0) = payload[3];
        IPC_GET_BYTE(data->CH3DiagResults, 0) = payload[4];
        IPC_GET_BYTE(data->CH4DiagResults, 0) = payload[5];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Amp2PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp2PeriodDiagResults_Pack(IPC_M2S_AudioAMPAmp2PeriodDiagResults_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_ID;
        payload[5] = IPC_GET_BYTE(data->DeviceDiagResults_1, 0);
        payload[6] = IPC_GET_BYTE(data->DeviceDiagResults_2, 0);
        payload[7] = IPC_GET_BYTE(data->CH1DiagResults, 0);
        payload[8] = IPC_GET_BYTE(data->CH2DiagResults, 0);
        payload[9] = IPC_GET_BYTE(data->CH3DiagResults, 0);
        payload[10] = IPC_GET_BYTE(data->CH4DiagResults, 0);
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Amp2PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp2PeriodDiagResults_Parse(IPC_M2S_AudioAMPAmp2PeriodDiagResults_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_LENGTH == length))
    {
        IPC_GET_BYTE(data->DeviceDiagResults_1, 0) = payload[0];
        IPC_GET_BYTE(data->DeviceDiagResults_2, 0) = payload[1];
        IPC_GET_BYTE(data->CH1DiagResults, 0) = payload[2];
        IPC_GET_BYTE(data->CH2DiagResults, 0) = payload[3];
        IPC_GET_BYTE(data->CH3DiagResults, 0) = payload[4];
        IPC_GET_BYTE(data->CH4DiagResults, 0) = payload[5];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message MCU_To_SOC_ACK */
int32_t IPC_M2S_AudioAMPMCU_To_SOC_ACK_Pack(IPC_M2S_AudioAMPMCU_To_SOC_ACK_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_ID;
        payload[5] = IPC_GET_BYTE(data->ACK, 0);
        payload[6] = IPC_GET_BYTE(data->major_msg_id, 0);
        payload[7] = IPC_GET_BYTE(data->sub_msg_id, 0);
        payload[8] = IPC_GET_BYTE(data->DeviceID, 0);
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message MCU_To_SOC_ACK */
int32_t IPC_M2S_AudioAMPMCU_To_SOC_ACK_Parse(IPC_M2S_AudioAMPMCU_To_SOC_ACK_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_LENGTH == length))
    {
        IPC_GET_BYTE(data->ACK, 0) = payload[0];
        IPC_GET_BYTE(data->major_msg_id, 0) = payload[1];
        IPC_GET_BYTE(data->sub_msg_id, 0) = payload[2];
        IPC_GET_BYTE(data->DeviceID, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AMP_DeviceStatus */
int32_t IPC_M2S_AudioAMPAMP_DeviceStatus_Pack(IPC_M2S_AudioAMPAMP_DeviceStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_ID;
        payload[5] = IPC_GET_BYTE(data->DeviceID, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->DeviceStatus[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message AMP_DeviceStatus */
int32_t IPC_M2S_AudioAMPAMP_DeviceStatus_Parse(IPC_M2S_AudioAMPAMP_DeviceStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_LENGTH == length))
    {
        IPC_GET_BYTE(data->DeviceID, 0) = payload[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                IPC_GET_BYTE(data->DeviceStatus[arrIndex], 0) = payload[1 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AMP_ChannelStatus */
int32_t IPC_M2S_AudioAMPAMP_ChannelStatus_Pack(IPC_M2S_AudioAMPAMP_ChannelStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_ID;
        payload[5] = IPC_GET_BYTE(data->DeviceID, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 30; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->ChannelStatus[arrIndex], 0);
            }
        }
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message AMP_ChannelStatus */
int32_t IPC_M2S_AudioAMPAMP_ChannelStatus_Parse(IPC_M2S_AudioAMPAMP_ChannelStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_LENGTH == length))
    {
        IPC_GET_BYTE(data->DeviceID, 0) = payload[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 30; arrIndex++)
            {
                IPC_GET_BYTE(data->ChannelStatus[arrIndex], 0) = payload[1 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AMP1ClipStatus */
int32_t IPC_M2S_AudioAMPAMP1ClipStatus_Pack(IPC_M2S_AudioAMPAMP1ClipStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_ID;
        payload[5] = IPC_GET_BYTE(data->Channel1, 0);
        payload[6] = IPC_GET_BYTE(data->Channel2, 0);
        payload[7] = IPC_GET_BYTE(data->Channel3, 0);
        payload[8] = IPC_GET_BYTE(data->Channel4, 0);
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message AMP1ClipStatus */
int32_t IPC_M2S_AudioAMPAMP1ClipStatus_Parse(IPC_M2S_AudioAMPAMP1ClipStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_LENGTH == length))
    {
        IPC_GET_BYTE(data->Channel1, 0) = payload[0];
        IPC_GET_BYTE(data->Channel2, 0) = payload[1];
        IPC_GET_BYTE(data->Channel3, 0) = payload[2];
        IPC_GET_BYTE(data->Channel4, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AMP2ClipStatus */
int32_t IPC_M2S_AudioAMPAMP2ClipStatus_Pack(IPC_M2S_AudioAMPAMP2ClipStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_ID;
        payload[5] = IPC_GET_BYTE(data->Channel1, 0);
        payload[6] = IPC_GET_BYTE(data->Channel2, 0);
        payload[7] = IPC_GET_BYTE(data->Channel3, 0);
        payload[8] = IPC_GET_BYTE(data->Channel4, 0);
        totalLength = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message AMP2ClipStatus */
int32_t IPC_M2S_AudioAMPAMP2ClipStatus_Parse(IPC_M2S_AudioAMPAMP2ClipStatus_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_LENGTH == length))
    {
        IPC_GET_BYTE(data->Channel1, 0) = payload[0];
        IPC_GET_BYTE(data->Channel2, 0) = payload[1];
        IPC_GET_BYTE(data->Channel3, 0) = payload[2];
        IPC_GET_BYTE(data->Channel4, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message GetStartupDiagResult */
int32_t IPC_S2M_AudioAMPGetStartupDiagResult_Pack(IPC_S2M_AudioAMPGetStartupDiagResult_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_ID;
        payload[5] = IPC_GET_BYTE(data->GetStartupDiagResult, 0);
        totalLength = IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message GetStartupDiagResult */
int32_t IPC_S2M_AudioAMPGetStartupDiagResult_Parse(IPC_S2M_AudioAMPGetStartupDiagResult_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_LENGTH == length))
    {
        IPC_GET_BYTE(data->GetStartupDiagResult, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AudioDriverReady */
int32_t IPC_S2M_AudioAMPAudioDriverReady_Pack(IPC_S2M_AudioAMPAudioDriverReady_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_ID;
        payload[5] = IPC_GET_BYTE(data->AudioDriverReady, 0);
        totalLength = IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message AudioDriverReady */
int32_t IPC_S2M_AudioAMPAudioDriverReady_Parse(IPC_S2M_AudioAMPAudioDriverReady_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_LENGTH == length))
    {
        IPC_GET_BYTE(data->AudioDriverReady, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SOC_to_MCU_ACK */
int32_t IPC_S2M_AudioAMPSOC_to_MCU_ACK_Pack(IPC_S2M_AudioAMPSOC_to_MCU_ACK_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_ID;
        payload[5] = IPC_GET_BYTE(data->ACK, 0);
        payload[6] = IPC_GET_BYTE(data->major_msg_id, 0);
        payload[7] = IPC_GET_BYTE(data->sub_msg_id, 0);
        totalLength = IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SOC_to_MCU_ACK */
int32_t IPC_S2M_AudioAMPSOC_to_MCU_ACK_Parse(IPC_S2M_AudioAMPSOC_to_MCU_ACK_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_LENGTH == length))
    {
        IPC_GET_BYTE(data->ACK, 0) = payload[0];
        IPC_GET_BYTE(data->major_msg_id, 0) = payload[1];
        IPC_GET_BYTE(data->sub_msg_id, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AmpFastMuteNotify */
int32_t IPC_S2M_AudioAMPAmpFastMuteNotify_Pack(IPC_S2M_AudioAMPAmpFastMuteNotify_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_ID;
        payload[5] = IPC_GET_BYTE(data->MuteOnOff, 0);
        totalLength = IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message AmpFastMuteNotify */
int32_t IPC_S2M_AudioAMPAmpFastMuteNotify_Parse(IPC_S2M_AudioAMPAmpFastMuteNotify_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_LENGTH == length))
    {
        IPC_GET_BYTE(data->MuteOnOff, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AmpGainSet */
int32_t IPC_S2M_AudioAMPAmpGainSet_Pack(IPC_S2M_AudioAMPAmpGainSet_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_ID;
        payload[5] = IPC_GET_BYTE(data->DeviceId, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                payload[6 + arrIndex * 1] = IPC_GET_BYTE(data->GainReduction[arrIndex], 0);
            }
        }
        totalLength = IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message AmpGainSet */
int32_t IPC_S2M_AudioAMPAmpGainSet_Parse(IPC_S2M_AudioAMPAmpGainSet_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_LENGTH == length))
    {
        IPC_GET_BYTE(data->DeviceId, 0) = payload[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                IPC_GET_BYTE(data->GainReduction[arrIndex], 0) = payload[1 + arrIndex * 1];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message PWMSet */
int32_t IPC_S2M_AudioAMPPWMSet_Pack(IPC_S2M_AudioAMPPWMSet_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_ID;
        payload[5] = IPC_GET_BYTE(data->DividerSetting, 0);
        totalLength = IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message PWMSet */
int32_t IPC_S2M_AudioAMPPWMSet_Parse(IPC_S2M_AudioAMPPWMSet_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_LENGTH == length))
    {
        IPC_GET_BYTE(data->DividerSetting, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AudioGet */
int32_t IPC_S2M_AudioAMPAudioGet_Pack(IPC_S2M_AudioAMPAudioGet_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_ID;
        payload[5] = IPC_GET_BYTE(data->DeviceID, 0);
        payload[6] = IPC_GET_BYTE(data->cmd, 0);
        totalLength = IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message AudioGet */
int32_t IPC_S2M_AudioAMPAudioGet_Parse(IPC_S2M_AudioAMPAudioGet_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_LENGTH == length))
    {
        IPC_GET_BYTE(data->DeviceID, 0) = payload[0];
        IPC_GET_BYTE(data->cmd, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message GWMTest */
int32_t IPC_S2M_AudioAMPGWMTest_Pack(IPC_S2M_AudioAMPGWMTest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_LENGTH))
    {
        payload[2] = IPC_GROUP_AUDIO_ID;
        payload[3] = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
        payload[4] = IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_ID;
        payload[5] = IPC_GET_BYTE(data->clip_threshold, 0);
        payload[6] = IPC_GET_BYTE(data->clip_hold_time, 3);
        payload[7] = IPC_GET_BYTE(data->clip_hold_time, 2);
        payload[8] = IPC_GET_BYTE(data->clip_hold_time, 1);
        payload[9] = IPC_GET_BYTE(data->clip_hold_time, 0);
        payload[10] = IPC_GET_BYTE(data->clip_release_time, 3);
        payload[11] = IPC_GET_BYTE(data->clip_release_time, 2);
        payload[12] = IPC_GET_BYTE(data->clip_release_time, 1);
        payload[13] = IPC_GET_BYTE(data->clip_release_time, 0);
        payload[14] = IPC_GET_BYTE(data->clip_polling_cycle, 3);
        payload[15] = IPC_GET_BYTE(data->clip_polling_cycle, 2);
        payload[16] = IPC_GET_BYTE(data->clip_polling_cycle, 1);
        payload[17] = IPC_GET_BYTE(data->clip_polling_cycle, 0);
        totalLength = IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_LENGTH + 5;
        payload[0] = (uint8_t)(totalLength >> 8);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message GWMTest */
int32_t IPC_S2M_AudioAMPGWMTest_Parse(IPC_S2M_AudioAMPGWMTest_t *data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_LENGTH == length))
    {
        IPC_GET_BYTE(data->clip_threshold, 0) = payload[0];
        IPC_GET_BYTE(data->clip_hold_time, 3) = payload[1];
        IPC_GET_BYTE(data->clip_hold_time, 2) = payload[2];
        IPC_GET_BYTE(data->clip_hold_time, 1) = payload[3];
        IPC_GET_BYTE(data->clip_hold_time, 0) = payload[4];
        IPC_GET_BYTE(data->clip_release_time, 3) = payload[5];
        IPC_GET_BYTE(data->clip_release_time, 2) = payload[6];
        IPC_GET_BYTE(data->clip_release_time, 1) = payload[7];
        IPC_GET_BYTE(data->clip_release_time, 0) = payload[8];
        IPC_GET_BYTE(data->clip_polling_cycle, 3) = payload[9];
        IPC_GET_BYTE(data->clip_polling_cycle, 2) = payload[10];
        IPC_GET_BYTE(data->clip_polling_cycle, 1) = payload[11];
        IPC_GET_BYTE(data->clip_polling_cycle, 0) = payload[12];
        ret = 0;
    }
    return ret;
}
