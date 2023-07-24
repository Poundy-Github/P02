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
*                 File:  IPC_Audio.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_SOC.h.tem
*          Description:  IPC group Audio  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_AUDIO_H_
#define _IPC_AUDIO_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_AUDIO_ID                                                       (12u)

/* MCU to SOC Message major id */
#define IPC_M2S_AUDIO_MSGMAJOR_AMP_ID                                            (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_ID                       (0u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_ID                       (1u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_ID                        (2u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_ID                        (3u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_ID                               (4u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_ID                             (5u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_ID                            (6u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_ID                               (7u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_ID                               (8u)
/* MCU to SOC Message sub length */
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP1STARTUPDIAGRESULTS_LENGTH                   (9u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP2STARTUPDIAGRESULTS_LENGTH                   (9u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_LENGTH                    (6u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_LENGTH                    (6u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_MCU_TO_SOC_ACK_LENGTH                           (4u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP_DEVICESTATUS_LENGTH                         (9u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP_CHANNELSTATUS_LENGTH                        (31u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP1CLIPSTATUS_LENGTH                           (4u)
#define IPC_M2S_AUDIO_AMP_MSGSUB_AMP2CLIPSTATUS_LENGTH                           (4u)
/* SOC to MCU Message major id */
#define IPC_S2M_AUDIO_MSGMAJOR_AMP_ID                                            (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_ID                         (0u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_ID                             (1u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_ID                               (2u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_ID                            (3u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_ID                                   (4u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_ID                                       (5u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_ID                                     (6u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_ID                                      (7u)
/* SOC to MCU Message sub length */
#define IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_LENGTH                     (1u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_LENGTH                         (1u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_LENGTH                           (3u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_LENGTH                        (1u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_LENGTH                               (9u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_LENGTH                                   (1u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_LENGTH                                 (2u)
#define IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_LENGTH                                  (13u)
/* Group: : Audio */
/* Message Major: AMP */
/* Message Sub: Amp1StartupDiagResults */
typedef struct
{
    /*audio不回复ack*/
    uint8_t AMP1_Status;
    uint8_t CH1DCLoadCondition;
    uint8_t CH2DCLoadCondition;
    uint8_t CH3DCLoadCondition;
    uint8_t CH4DCLoadCondition;
    uint8_t CH1ACLoadCondition;
    uint8_t CH2ACLoadCondition;
    uint8_t CH3ACLoadCondition;
    uint8_t CH4ACLoadCondition;
}IPC_M2S_AudioAMPAmp1StartupDiagResults_t;

/* Pack function of sub message Amp1StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp1StartupDiagResults_Pack(IPC_M2S_AudioAMPAmp1StartupDiagResults_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Amp1StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp1StartupDiagResults_Parse(IPC_M2S_AudioAMPAmp1StartupDiagResults_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: Amp2StartupDiagResults */
typedef struct
{
    /*audio不回复ack*/
    uint8_t AMP2_Status;
    uint8_t CH1DCLoadCondition;
    uint8_t CH2DCLoadCondition;
    uint8_t CH3DCLoadCondition;
    uint8_t CH4DCLoadCondition;
    uint8_t CH1ACLoadCondition;
    uint8_t CH2ACLoadCondition;
    uint8_t CH3ACLoadCondition;
    uint8_t CH4ACLoadCondition;
}IPC_M2S_AudioAMPAmp2StartupDiagResults_t;

/* Pack function of sub message Amp2StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp2StartupDiagResults_Pack(IPC_M2S_AudioAMPAmp2StartupDiagResults_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Amp2StartupDiagResults */
int32_t IPC_M2S_AudioAMPAmp2StartupDiagResults_Parse(IPC_M2S_AudioAMPAmp2StartupDiagResults_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: Amp1PeriodDiagResults */
typedef struct
{
    /*audio回复ack,500ms*/
    uint8_t DeviceDiagResults_1;
    uint8_t DeviceDiagResults_2;
    uint8_t CH1DiagResults;
    uint8_t CH2DiagResults;
    uint8_t CH3DiagResults;
    uint8_t CH4DiagResults;
}IPC_M2S_AudioAMPAmp1PeriodDiagResults_t;

/* Pack function of sub message Amp1PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp1PeriodDiagResults_Pack(IPC_M2S_AudioAMPAmp1PeriodDiagResults_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Amp1PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp1PeriodDiagResults_Parse(IPC_M2S_AudioAMPAmp1PeriodDiagResults_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: Amp2PeriodDiagResults */
typedef struct
{
    uint8_t DeviceDiagResults_1;
    /*audio 回复ack,500ms*/
    uint8_t DeviceDiagResults_2;
    uint8_t CH1DiagResults;
    uint8_t CH2DiagResults;
    uint8_t CH3DiagResults;
    uint8_t CH4DiagResults;
}IPC_M2S_AudioAMPAmp2PeriodDiagResults_t;

/* Pack function of sub message Amp2PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp2PeriodDiagResults_Pack(IPC_M2S_AudioAMPAmp2PeriodDiagResults_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Amp2PeriodDiagResults */
int32_t IPC_M2S_AudioAMPAmp2PeriodDiagResults_Parse(IPC_M2S_AudioAMPAmp2PeriodDiagResults_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: MCU_To_SOC_ACK */
typedef struct
{
    uint8_t ACK;
    uint8_t major_msg_id;
    uint8_t sub_msg_id;
    uint8_t DeviceID;
}IPC_M2S_AudioAMPMCU_To_SOC_ACK_t;

/* Pack function of sub message MCU_To_SOC_ACK */
int32_t IPC_M2S_AudioAMPMCU_To_SOC_ACK_Pack(IPC_M2S_AudioAMPMCU_To_SOC_ACK_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message MCU_To_SOC_ACK */
int32_t IPC_M2S_AudioAMPMCU_To_SOC_ACK_Parse(IPC_M2S_AudioAMPMCU_To_SOC_ACK_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: AMP_DeviceStatus */
typedef struct
{
    uint8_t DeviceID;
    uint8_t DeviceStatus[8];
}IPC_M2S_AudioAMPAMP_DeviceStatus_t;

/* Pack function of sub message AMP_DeviceStatus */
int32_t IPC_M2S_AudioAMPAMP_DeviceStatus_Pack(IPC_M2S_AudioAMPAMP_DeviceStatus_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AMP_DeviceStatus */
int32_t IPC_M2S_AudioAMPAMP_DeviceStatus_Parse(IPC_M2S_AudioAMPAMP_DeviceStatus_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: AMP_ChannelStatus */
typedef struct
{
    uint8_t DeviceID;
    uint8_t ChannelStatus[30];
}IPC_M2S_AudioAMPAMP_ChannelStatus_t;

/* Pack function of sub message AMP_ChannelStatus */
int32_t IPC_M2S_AudioAMPAMP_ChannelStatus_Pack(IPC_M2S_AudioAMPAMP_ChannelStatus_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AMP_ChannelStatus */
int32_t IPC_M2S_AudioAMPAMP_ChannelStatus_Parse(IPC_M2S_AudioAMPAMP_ChannelStatus_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: AMP1ClipStatus */
typedef struct
{
    /*0:NoClip, 1:Clip*/
    uint8_t Channel1;
    /*0:NoClip, 1:Clip*/
    uint8_t Channel2;
    /*0:NoClip, 1:Clip*/
    uint8_t Channel3;
    /*0:NoClip, 1:Clip*/
    uint8_t Channel4;
}IPC_M2S_AudioAMPAMP1ClipStatus_t;

/* Pack function of sub message AMP1ClipStatus */
int32_t IPC_M2S_AudioAMPAMP1ClipStatus_Pack(IPC_M2S_AudioAMPAMP1ClipStatus_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AMP1ClipStatus */
int32_t IPC_M2S_AudioAMPAMP1ClipStatus_Parse(IPC_M2S_AudioAMPAMP1ClipStatus_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: AMP2ClipStatus */
typedef struct
{
    /*0:NoClip, 1:Clip*/
    uint8_t Channel1;
    /*0:NoClip, 1:Clip*/
    uint8_t Channel2;
    /*0:NoClip, 1:Clip*/
    uint8_t Channel3;
    /*0:NoClip, 1:Clip*/
    uint8_t Channel4;
}IPC_M2S_AudioAMPAMP2ClipStatus_t;

/* Pack function of sub message AMP2ClipStatus */
int32_t IPC_M2S_AudioAMPAMP2ClipStatus_Pack(IPC_M2S_AudioAMPAMP2ClipStatus_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AMP2ClipStatus */
int32_t IPC_M2S_AudioAMPAMP2ClipStatus_Parse(IPC_M2S_AudioAMPAMP2ClipStatus_t *data, uint8_t *payload, uint16_t length);

/* Group: : Audio */
/* Group: : Audio */
/* Message Major: AMP */
/* Message Sub: GetStartupDiagResult */
typedef struct
{
    /*audio发请求，amp回结果，如果通信异常，audio重发请求*/
    uint8_t GetStartupDiagResult;
}IPC_S2M_AudioAMPGetStartupDiagResult_t;

/* Pack function of sub message GetStartupDiagResult */
int32_t IPC_S2M_AudioAMPGetStartupDiagResult_Pack(IPC_S2M_AudioAMPGetStartupDiagResult_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message GetStartupDiagResult */
int32_t IPC_S2M_AudioAMPGetStartupDiagResult_Parse(IPC_S2M_AudioAMPGetStartupDiagResult_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: AudioDriverReady */
typedef struct
{
    /*收到消息回ack，200ms*/
    uint8_t AudioDriverReady;
}IPC_S2M_AudioAMPAudioDriverReady_t;

/* Pack function of sub message AudioDriverReady */
int32_t IPC_S2M_AudioAMPAudioDriverReady_Pack(IPC_S2M_AudioAMPAudioDriverReady_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AudioDriverReady */
int32_t IPC_S2M_AudioAMPAudioDriverReady_Parse(IPC_S2M_AudioAMPAudioDriverReady_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: SOC_to_MCU_ACK */
typedef struct
{
    /*不需要*/
    uint8_t ACK;
    uint8_t major_msg_id;
    uint8_t sub_msg_id;
}IPC_S2M_AudioAMPSOC_to_MCU_ACK_t;

/* Pack function of sub message SOC_to_MCU_ACK */
int32_t IPC_S2M_AudioAMPSOC_to_MCU_ACK_Pack(IPC_S2M_AudioAMPSOC_to_MCU_ACK_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SOC_to_MCU_ACK */
int32_t IPC_S2M_AudioAMPSOC_to_MCU_ACK_Parse(IPC_S2M_AudioAMPSOC_to_MCU_ACK_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: AmpFastMuteNotify */
typedef struct
{
    /*回复ack,200ms*/
    uint8_t MuteOnOff;
}IPC_S2M_AudioAMPAmpFastMuteNotify_t;

/* Pack function of sub message AmpFastMuteNotify */
int32_t IPC_S2M_AudioAMPAmpFastMuteNotify_Pack(IPC_S2M_AudioAMPAmpFastMuteNotify_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AmpFastMuteNotify */
int32_t IPC_S2M_AudioAMPAmpFastMuteNotify_Parse(IPC_S2M_AudioAMPAmpFastMuteNotify_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: AmpGainSet */
typedef struct
{
    /*0:AMP1;1:AMP2*/
    uint8_t DeviceId;
    uint8_t GainReduction[8];
}IPC_S2M_AudioAMPAmpGainSet_t;

/* Pack function of sub message AmpGainSet */
int32_t IPC_S2M_AudioAMPAmpGainSet_Pack(IPC_S2M_AudioAMPAmpGainSet_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AmpGainSet */
int32_t IPC_S2M_AudioAMPAmpGainSet_Parse(IPC_S2M_AudioAMPAmpGainSet_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: PWMSet */
typedef struct
{
    uint8_t DividerSetting;
}IPC_S2M_AudioAMPPWMSet_t;

/* Pack function of sub message PWMSet */
int32_t IPC_S2M_AudioAMPPWMSet_Pack(IPC_S2M_AudioAMPPWMSet_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message PWMSet */
int32_t IPC_S2M_AudioAMPPWMSet_Parse(IPC_S2M_AudioAMPPWMSet_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: AudioGet */
typedef struct
{
    /*0:AMP1;1:AMP2*/
    uint8_t DeviceID;
    /*1. AMPDeviceState
    2. AMPChannelState
    */
    uint8_t cmd;
}IPC_S2M_AudioAMPAudioGet_t;

/* Pack function of sub message AudioGet */
int32_t IPC_S2M_AudioAMPAudioGet_Pack(IPC_S2M_AudioAMPAudioGet_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AudioGet */
int32_t IPC_S2M_AudioAMPAudioGet_Parse(IPC_S2M_AudioAMPAudioGet_t *data, uint8_t *payload, uint16_t length);

/* Message Sub: GWMTest */
typedef struct
{
    /*0x0: 2%
    0x1: 5%
    0x2: 10%*/
    uint8_t clip_threshold;
    uint32_t clip_hold_time;
    uint32_t clip_release_time;
    uint32_t clip_polling_cycle;
}IPC_S2M_AudioAMPGWMTest_t;

/* Pack function of sub message GWMTest */
int32_t IPC_S2M_AudioAMPGWMTest_Pack(IPC_S2M_AudioAMPGWMTest_t *data, uint8_t *payload, uint16_t length);

/* Parse function of sub message GWMTest */
int32_t IPC_S2M_AudioAMPGWMTest_Parse(IPC_S2M_AudioAMPGWMTest_t *data, uint8_t *payload, uint16_t length);

/* Group: : Audio */
#ifdef __cplusplus
}
#endif

#endif
