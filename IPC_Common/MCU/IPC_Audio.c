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
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group Audio source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_Audio.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Audio */
/* Message Major: AMP */
/* Transmit function of sub message Amp1StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp1StartupDiagResults_Transmit(IPC_M2S_AudioAMPAmp1StartupDiagResults_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_ID;
        payload[3] = IPC_GET_BYTE(data->AMP1_Status, 0);
        payload[4] = IPC_GET_BYTE(data->CH1DCLoadCondition, 0);
        payload[5] = IPC_GET_BYTE(data->CH2DCLoadCondition, 0);
        payload[6] = IPC_GET_BYTE(data->CH3DCLoadCondition, 0);
        payload[7] = IPC_GET_BYTE(data->CH4DCLoadCondition, 0);
        payload[8] = IPC_GET_BYTE(data->CH1ACLoadCondition, 0);
        payload[9] = IPC_GET_BYTE(data->CH2ACLoadCondition, 0);
        payload[10] = IPC_GET_BYTE(data->CH3ACLoadCondition, 0);
        payload[11] = IPC_GET_BYTE(data->CH4ACLoadCondition, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Amp2StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp2StartupDiagResults_Transmit(IPC_M2S_AudioAMPAmp2StartupDiagResults_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_ID;
        payload[3] = IPC_GET_BYTE(data->AMP2_Status, 0);
        payload[4] = IPC_GET_BYTE(data->CH1DCLoadCondition, 0);
        payload[5] = IPC_GET_BYTE(data->CH2DCLoadCondition, 0);
        payload[6] = IPC_GET_BYTE(data->CH3DCLoadCondition, 0);
        payload[7] = IPC_GET_BYTE(data->CH4DCLoadCondition, 0);
        payload[8] = IPC_GET_BYTE(data->CH1ACLoadCondition, 0);
        payload[9] = IPC_GET_BYTE(data->CH2ACLoadCondition, 0);
        payload[10] = IPC_GET_BYTE(data->CH3ACLoadCondition, 0);
        payload[11] = IPC_GET_BYTE(data->CH4ACLoadCondition, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Amp1PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp1PeriodDiagResults_Transmit(IPC_M2S_AudioAMPAmp1PeriodDiagResults_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_ID;
        payload[3] = IPC_GET_BYTE(data->DeviceDiagResults_1, 0);
        payload[4] = IPC_GET_BYTE(data->DeviceDiagResults_2, 0);
        payload[5] = IPC_GET_BYTE(data->CH1DiagResults, 0);
        payload[6] = IPC_GET_BYTE(data->CH2DiagResults, 0);
        payload[7] = IPC_GET_BYTE(data->CH3DiagResults, 0);
        payload[8] = IPC_GET_BYTE(data->CH4DiagResults, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Amp2PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp2PeriodDiagResults_Transmit(IPC_M2S_AudioAMPAmp2PeriodDiagResults_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_ID;
        payload[3] = IPC_GET_BYTE(data->DeviceDiagResults_1, 0);
        payload[4] = IPC_GET_BYTE(data->DeviceDiagResults_2, 0);
        payload[5] = IPC_GET_BYTE(data->CH1DiagResults, 0);
        payload[6] = IPC_GET_BYTE(data->CH2DiagResults, 0);
        payload[7] = IPC_GET_BYTE(data->CH3DiagResults, 0);
        payload[8] = IPC_GET_BYTE(data->CH4DiagResults, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message MCU_To_SOC_ACK */
int32_t IPC_M2S_AudioAMPMCU_To_SOC_ACK_Transmit(IPC_M2S_AudioAMPMCU_To_SOC_ACK_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_ID;
        payload[3] = IPC_GET_BYTE(data->ACK, 0);
        payload[4] = IPC_GET_BYTE(data->major_msg_id, 0);
        payload[5] = IPC_GET_BYTE(data->sub_msg_id, 0);
        payload[6] = IPC_GET_BYTE(data->DeviceID, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message AMP_DeviceStatus */
int32_t IPC_M2S_AudioAMPAMP_DeviceStatus_Transmit(IPC_M2S_AudioAMPAMP_DeviceStatus_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_ID;
        payload[3] = IPC_GET_BYTE(data->DeviceID, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                payload[4 + arrIndex * 1] = IPC_GET_BYTE(data->DeviceStatus[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message AMP_ChannelStatus */
int32_t IPC_M2S_AudioAMPAMP_ChannelStatus_Transmit(IPC_M2S_AudioAMPAMP_ChannelStatus_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_ID;
        payload[3] = IPC_GET_BYTE(data->DeviceID, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 30; arrIndex++)
            {
                payload[4 + arrIndex * 1] = IPC_GET_BYTE(data->ChannelStatus[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message AMP1ClipStatus */
int32_t IPC_M2S_AudioAMPAMP1ClipStatus_Transmit(IPC_M2S_AudioAMPAMP1ClipStatus_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_ID;
        payload[3] = IPC_GET_BYTE(data->Channel1, 0);
        payload[4] = IPC_GET_BYTE(data->Channel2, 0);
        payload[5] = IPC_GET_BYTE(data->Channel3, 0);
        payload[6] = IPC_GET_BYTE(data->Channel4, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message AMP2ClipStatus */
int32_t IPC_M2S_AudioAMPAMP2ClipStatus_Transmit(IPC_M2S_AudioAMPAMP2ClipStatus_t *data)
{
    uint8_t payload[IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_AUDIO_ID;
        payload[1] = IPC_M2S_AUDIO_MSGMAJOR_AMP_ID;
        payload[2] = IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_ID;
        payload[3] = IPC_GET_BYTE(data->Channel1, 0);
        payload[4] = IPC_GET_BYTE(data->Channel2, 0);
        payload[5] = IPC_GET_BYTE(data->Channel3, 0);
        payload[6] = IPC_GET_BYTE(data->Channel4, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Receive function of sub message GetStartupDiagResult */
void IPC_S2M_AudioAMPGetStartupDiagResult_Receive(uint8_t *receiveData, IPC_S2M_AudioAMPGetStartupDiagResult_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->GetStartupDiagResult, 0) = receiveData[0];
    }

}

/* Receive function of sub message AudioDriverReady */
void IPC_S2M_AudioAMPAudioDriverReady_Receive(uint8_t *receiveData, IPC_S2M_AudioAMPAudioDriverReady_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->AudioDriverReady, 0) = receiveData[0];
    }

}

/* Receive function of sub message SOC_to_MCU_ACK */
void IPC_S2M_AudioAMPSOC_to_MCU_ACK_Receive(uint8_t *receiveData, IPC_S2M_AudioAMPSOC_to_MCU_ACK_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->ACK, 0) = receiveData[0];
        IPC_GET_BYTE(data->major_msg_id, 0) = receiveData[1];
        IPC_GET_BYTE(data->sub_msg_id, 0) = receiveData[2];
    }

}

/* Receive function of sub message AmpFastMuteNotify */
void IPC_S2M_AudioAMPAmpFastMuteNotify_Receive(uint8_t *receiveData, IPC_S2M_AudioAMPAmpFastMuteNotify_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->MuteOnOff, 0) = receiveData[0];
    }

}

/* Receive function of sub message AmpGainSet */
void IPC_S2M_AudioAMPAmpGainSet_Receive(uint8_t *receiveData, IPC_S2M_AudioAMPAmpGainSet_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->DeviceId, 0) = receiveData[0];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 8; arrIndex++)
            {
                IPC_GET_BYTE(data->GainReduction[arrIndex], 0) = receiveData[1 + arrIndex * 1];
            }
        }
    }

}

/* Receive function of sub message PWMSet */
void IPC_S2M_AudioAMPPWMSet_Receive(uint8_t *receiveData, IPC_S2M_AudioAMPPWMSet_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->DividerSetting, 0) = receiveData[0];
    }

}

/* Receive function of sub message AudioGet */
void IPC_S2M_AudioAMPAudioGet_Receive(uint8_t *receiveData, IPC_S2M_AudioAMPAudioGet_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->DeviceID, 0) = receiveData[0];
        IPC_GET_BYTE(data->cmd, 0) = receiveData[1];
    }

}

/* Receive function of sub message GWMTest */
void IPC_S2M_AudioAMPGWMTest_Receive(uint8_t *receiveData, IPC_S2M_AudioAMPGWMTest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->clip_threshold, 0) = receiveData[0];
        IPC_GET_BYTE(data->clip_hold_time, 3) = receiveData[1];
        IPC_GET_BYTE(data->clip_hold_time, 2) = receiveData[2];
        IPC_GET_BYTE(data->clip_hold_time, 1) = receiveData[3];
        IPC_GET_BYTE(data->clip_hold_time, 0) = receiveData[4];
        IPC_GET_BYTE(data->clip_release_time, 3) = receiveData[5];
        IPC_GET_BYTE(data->clip_release_time, 2) = receiveData[6];
        IPC_GET_BYTE(data->clip_release_time, 1) = receiveData[7];
        IPC_GET_BYTE(data->clip_release_time, 0) = receiveData[8];
        IPC_GET_BYTE(data->clip_polling_cycle, 3) = receiveData[9];
        IPC_GET_BYTE(data->clip_polling_cycle, 2) = receiveData[10];
        IPC_GET_BYTE(data->clip_polling_cycle, 1) = receiveData[11];
        IPC_GET_BYTE(data->clip_polling_cycle, 0) = receiveData[12];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
