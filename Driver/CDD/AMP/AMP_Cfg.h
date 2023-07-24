/**
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.
* All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are NOT permitted except as agreed by
* Nobo Automotive Technologies Co.,Ltd.
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
/**
 **********************************************************************************************************************
 * @file:      AMP_cfg.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/
 
#ifndef AMP_CFG_H
#define AMP_CFG_H


#include "Dio.h"
#include "AMPVCfg.h"

#define DEVICE_AMP1                                     (0u)
#define DEVICE_AMP2                                     (1u)
#define DEVICE_NUM                                      (2U)
#define AMP_HWUNMUTE                                    (0u)
#define AMP_HWMUTE                                      (1u)
#define AMP_HIGHPROTECTNONE                             (0U)
#define AMP_HIGHPROTECTAPPEAR                           (1u)
#define AMP_HIGHPROTECTDISAPPEAR                        (2u)
#define AMP_HWMUTE_EVENT                                (8u)
#define AMP_STARTDIAGRESULT_EVENT                       (9u)
#define AMP_SOC_MCU_EVENT                               (10u)
#define AMP_BOOT                                        (0u)
#define AMP_IDLE                                        (1u)
#define AMP_STANDBY                                     (2u)
#define AMP_PLAYING                                     (4u)
#define AMP_PROTECTED                                   (5u)
#define AMP_SHUTDWON                                    (6u)
#define AMP_CLOCKFAIL                                   (7u)
#define AMP_OFF                                         (0u)
#define AMP_STARTUP                                     (1u)
#define AMP_NORMAL                                      (2u)
#define AMP_SHUTDOWN                                    (3U)
#define AMP_LCCALIB                                     (4u)
#define ipc_ack_counter                                 (40)/*200ms*/
#define ACK_OK                                          (1u)
#define AMP_IPC_AMPGAINSET                              (3u)
#define AMP_IPC_AUDIODRIVERREADY                        (4u)
#define AMP_IICFDATAMAXLENGTH                           (60u)
#define VCONFIG_ONLYAMP1                                (0u)
#define VCONFIG_ONLYAMP2                                (1u)
#define VCONFIG_BOTHAMP                                 (2u)
#define VCONFIG_NONE                                    (3u)
#define AMPIIC_READ                                     (0u)
#define AMPIIC_WRITE                                    (1u)


typedef enum
{
    AMPPIN_DIAG1 = 0u,
    AMPPIN_DIAG2,
    AMPPIN_DIAG3,
    AMPPIN_ENABLE,
    AMPPIN_MUTE_N,
    PIN_8532_Number,
}AMP_8532_PIN_ID_t;


#define AMP_DIAGPINNUM              (3u)

#define AMP1_8532_PIN_ID    {\
    DioConf_DioChannel_VIP_AMP8532_DIAG1,\
    DioConf_DioChannel_VIP_AMP8532_DIAG2,\
    DioConf_DioChannel_VIP_AMP8532_DIAG3,\
    DioConf_DioChannel_VIP_AMP8532_EN,\
    DioConf_DioChannel_VIP_AMP8532_MUTE,\
}

#define AMP2_8532_PIN_ID    {\
    DioConf_DioChannel_VIP_AMP8531_DIAG1,\
    DioConf_DioChannel_VIP_AMP8531_DIAG2,\
    DioConf_DioChannel_VIP_8532_DIAG3,\
    DioConf_DioChannel_VIP_AMP8531_EN,\
    DioConf_DioChannel_VIP_AMP8531_MUTE,\
}

typedef enum
{
    Startup_Idle = 0u,
    Startup_SCLK_Wait,
    Startup_Standby,
    Startup_Done,
    Startup_Err,
}Startup_StateMachine_t;

typedef struct
{
    const uint8 ExeTime;
    const uint8 OperType;
    const uint8 Length;
    void(*p_fun) (uint8 dev_id);
    const char * LogName;
}iic_cmd_length_t;




typedef enum
{
    I2C_Req_Idle = 0u,
    I2C_Req_Success,
    I2C_Req_Err,
    I2C_Req_PushSucess,
    I2C_Req_Trigger,
    I2C_Req_Wait,
    I2C_Req_RXResponseTrigger,
    I2C_Req_RXResponseWait,
    I2C_Req_RXDataTrigger,
    I2C_Req_RXDataWait,
}I2C_Req_Sts_t;

typedef struct
{
    I2C_Req_Sts_t Sts;
    uint8 Flg;
    uint8 Counter;
    uint8 Data[AMP_IICFDATAMAXLENGTH];
    uint8 Rx_Request[5];
    uint8 Rx_Response[5];
}I2C_AMPReq_t;


typedef union{
    uint8 Data;
    struct{
        uint8 CH4    :2;
        uint8 CH3    :2;
        uint8 CH2    :2;
        uint8 CH1    :2;
    }Channel;
}u_AMPChannelCfg_t;

typedef enum
{
    Standby_DCLoad_Cfg = 0u,
    Standby_start_diag,
    Standby_GET_Diag_Sts,
    Standby_DC_Results,
    Standby_Channel_Cfg,
    Standby_Channel_Enable,
    Standby_Channel_EnableCfg,
    Standby_Playing_Check,
    Standby_Err,
    Standby_UnMute,
    Standby_Done,
}Startup_Standby_t;


typedef enum
{
    Boot_Enable = 0u,
    Boot_Get_ID,
    Idle_Set_Diag_Pin,
    Idle_Set_Device_Cfg,
    Idle_Set_Disable_Channels,
    Idle_Set_Audio_Cfg,
    Idle_Set_Audiorounting_Cfg,
    Idle_Set_Clock_State,
    Idle_Standby_Check,
    Idle_Err,
    Idle_Done,
}Startup_Idle_t;



typedef struct
{
    /*0:AMP1;1:AMP2*/
    uint8 DeviceId;
    uint8 GainReduction[8];
}S_AmpGainSet_Type;

    
#define AMP_IICDataCfg\
    /*00*/X_MACRO_IICDATA(GET_STARTUPDIAGSTATUS,          0u,     AMPIIC_READ,  8,    AMPGet_StartupDiagResult,   "Get_StartupDiagResult")\
    /*01*/X_MACRO_IICDATA(GET_DCLOADDETECTIONRESULT,      0u,     AMPIIC_READ,  34,   AMPGet_DCLoadCfg,           "Get_DCLoadCfg")\
    /*02*/X_MACRO_IICDATA(GET_ACLOADDETECTIONRESULT,      0u,     AMPIIC_READ,  38,   AMPGet_ACLoadCfg,           "Get_ACLoadCfg")\
    /*03*/X_MACRO_IICDATA(GET_DEVICESTATUS,               0u,     AMPIIC_READ,  9,    AMPGet_DeviceStatus,        "Get_DeviceStatus")\
    /*04*/X_MACRO_IICDATA(GET_CHANNELSTATUS,              0u,     AMPIIC_READ,  30,   AMPGet_ChannelStatus,       "Get_ChannelStatus")\
    /*05*/X_MACRO_IICDATA(GET_DEVICESTATE,                0u,     AMPIIC_READ,  6,    AMPGet_DeviceState,         "Get_DeviceState")\
    /*06*/X_MACRO_IICDATA(GET_AMP_ID,                     0u,     AMPIIC_READ,  11,   AMPGet_AMPID,               "Get_AMPID")\
    /*07*/X_MACRO_IICDATA(GET_FAULTSTATE,                 0u,     AMPIIC_READ,  9,    AMPGet_FaultState,          "Get_FaultState")\
    /*08*/X_MACRO_IICDATA(GET_TEMPETURE,                  0u,     AMPIIC_READ,  7,    AMPGet_Tempeture,           "Get_Tempeture")\
    /*09*/X_MACRO_IICDATA(GET_SUPPLYVOLTAGE,              0u,     AMPIIC_READ,  7,    AMPGet_SupplyVoltage,       "Get_SupplyVoltage")\
    /*10*/X_MACRO_IICDATA(GET_FILTERDIAGRESULT,           0u,     AMPIIC_READ,  5,    AMPGet_FilterDiagResult,    "Get_FilterDiagResult")\
    /*11*/X_MACRO_IICDATA(SET_DIAG_PIN,                   10u,    AMPIIC_WRITE, 21,   AMPSet_DiagPin,             "Set_DiagPin")\
    /*12*/X_MACRO_IICDATA(SET_DEVICECONFIG,               10u,    AMPIIC_WRITE, 12,   AMPSet_DeviceCfg,           "Set_DeviceCfg")\
    /*13*/X_MACRO_IICDATA(SET_CHANNEL_DISABLE,            10u,    AMPIIC_WRITE, 6,    AMPSet_ChannelDisable,      "Set_ChannelDisable")\
    /*14*/X_MACRO_IICDATA(SET_CHANNEL_ENABLE,             10u,    AMPIIC_WRITE, 6,    AMPSet_ChannelEnable,       "Set_ChannelEnable")\
    /*15*/X_MACRO_IICDATA(SET_CLOCKSTATE,                 10u,    AMPIIC_WRITE, 6,    AMPSet_ClockConnect,        "Set_ClockConnect")\
    /*16*/X_MACRO_IICDATA(SET_CHANNEL_MUTE,               10u,    AMPIIC_WRITE, 6,    AMPSet_SetChannelMute,      "Set_SetChannelMute")\
    /*17*/X_MACRO_IICDATA(SET_CHANNEL_UNMUTE,             10u,    AMPIIC_WRITE, 6,    AMPSet_ChannelUnmute,       "Set_ChannelUnmute")\
    /*18*/X_MACRO_IICDATA(SET_DCLOADDETECTION_CONFIG,     33u,    AMPIIC_WRITE, 22,   AMPSet_DCLoadCfg,           "Set_DCLoadCfg")\
    /*19*/X_MACRO_IICDATA(SET_ACLOADDETECTION_CONFIG,     33u,    AMPIIC_WRITE, 27,   AMPSet_ACLoadCfg,           "Set_ACLoadCfg")\
    /*20*/X_MACRO_IICDATA(SET_STARTUPDIAG,                10u,    AMPIIC_WRITE, 8,    AMPSet_StartupDiag,         "Set_StartupDiag")\
    /*21*/X_MACRO_IICDATA(SET_AUDIO_CONFIG,               33u,    AMPIIC_WRITE, 11,   AMPSet_AudioCfg,            "Set_AudioCfg")\
    /*22*/X_MACRO_IICDATA(SET_CHANNEL_CFG,                33u,    AMPIIC_WRITE, 50,   AMPSet_ChannelCfg,          "Set_ChannelCfg")\
    /*23*/X_MACRO_IICDATA(SET_DEVICE_IO_CFG,              10u,    AMPIIC_WRITE, 11,   AMPSet_DeviceIOConfigData,  "Set_DeviceIOConfigData")\
    /*24*/X_MACRO_IICDATA(SET_AUDIO_ROUTING_CFG,          10u,    AMPIIC_WRITE, 13,   AMPSet_AudioRoutingCfg,     "Set_AudioRoutingCfg")\
    /*25*/X_MACRO_IICDATA(SET_PWMFreq_CMD,                10u,    AMPIIC_WRITE, 8,    AMPSet_PWMData,             "Set_PWMData")\
    /*26*/X_MACRO_IICDATA(SET_MODSCHEME_CFG,              10u,    AMPIIC_WRITE, 14,   AMPSet_ModSchemeCfg,        "Set_ModSchemeCfg")\
    /*27*/X_MACRO_IICDATA(Set_HPF_CFG,                    10u,    AMPIIC_WRITE, 7,    AMPSet_HPFCfg,              "Set_HPFCfg")\
    /*28*/X_MACRO_IICDATA(Set_MUTE_CFG,                   10u,    AMPIIC_WRITE, 9,    AMPSet_MuteCfg,             "Set_MuteCfg")\
    /*29*/X_MACRO_IICDATA(Set_FILTERDAIG,                 33u,    AMPIIC_WRITE, 6,    AMPSet_FilterDiag,          "Set_FilterDiag")\
    /*30*/X_MACRO_IICDATA(Set_LCFilterCfg,                33u,    AMPIIC_WRITE, 52,   AMPSet_LCFilterCfg,         "Set_LCFilterCfg")\
	/*31*/X_MACRO_IICDATA(GET_AUDIOSTATUS,				  0u,	  AMPIIC_READ,  6,    AMPGet_AudioStatus,		  "Get_AudioStatus")\





typedef enum
{
#define X_MACRO_IICDATA(a,b,c,d,e,f) a,
    AMP_IICDataCfg
#undef X_MACRO_IICDATA
    AMPIICFlgNum
}e_AMPIICFlgEnum_t;


typedef enum
{
    AMPLCCalib_ChannelMute,
    AMPLCCalib_SetLCFilterCfg,
    AMPLCCalib_SetFilterDiag1,
    AMPLCCalib_GetTemp,
    AMPLCCalib_GetVoltage,
    AMPLCCalib_GetDeviceState,
    AMPLCCalib_GetFaultStatus,
    AMPLCCalib_GetChannleStatus,
    AMPLCCalib_GetFilterDiagResult,
    AMPLCCalib_EveironmentCheck,
    AMPLCCalib_Kvalue,
    AMPLCCalib_SetFilterDiag2,
    AMPLCCalib_Done,
    AMPLCCalib_WaitHW,
    AMPLCCalib_Err,
    AMPLCCalibNum,
}e_LCCalibEnum_t;


#define AMPNormalCfg\
    /*00*/X_MACRO_NORMAL(NORMALAMP_CHANGEPWM,                       AMPNormal_Tuner_PWM                 ,"TunerChangAMPPwm")\
    /*01*/X_MACRO_NORMAL(NORMALAMPGET_DEVICESTATUS,                 AMPNormal_GetDeviceStatus           ,"GetAMPDeviceSts")\
    /*02*/X_MACRO_NORMAL(NORMALAMPGET_CHANNELSTATE,                 AMPNormal_GetChannelState           ,"GetAMPChannelSts")\
    /*03*/X_MACRO_NORMAL(NORMALAMPSET_GAIN,                         AMPNormal_Set_Gain                  ,"SetAMPGain")\
    /*04*/X_MACRO_NORMAL(NORMALSET_HGIHPROTECTAPPEAR,               AMPNormal_HighProtectAppear         ,"Trigger High Protect")\
    /*05*/X_MACRO_NORMAL(NORMALSET_HGIHPROTECTDISAPPEAR,            AMPNormal_HighProtectDisappear      ,"Cancel High Protect")\
    /*06*/X_MACRO_NORMAL(DEBUGAMPGET_DEVICESTATE,                   AMPDebug_GetDeviceState             ,"DebugAMPDeviceSts")\
    /*07*/X_MACRO_NORMAL(DEBUGAMPGET_CHANNELSTATE,                  AMPDebug_GetChannelState            ,"DebugAMPChannelSts")\
    /*08*/X_MACRO_NORMAL(TESTAMPSET_CHANNELCFG,                     AMPTest_SetChannelCfg               ,"AMPTest_SetChannelCfg")\
    /*09*/X_MACRO_NORMAL(CLIPAMPGET_CHANNELSTATE,                   AMPClip_GetChannelState             ,"GetClipAMPChannelSts")\
	/*10*/X_MACRO_NORMAL(NORMALAMPGET_DEVICESTATE,					AMPNormal_GetDeviceState 			,"GetDeviceState")\
	/*11*/X_MACRO_NORMAL(NORMALAMPGET_FAULTSTATUS,					AMPNormal_GetFaultStatus 		   	,"GetFaultStatus")\
	/*12*/X_MACRO_NORMAL(NORMALAMPGET_AUDIOSTATUS,					AMPNormal_GetAudioStatus 			,"GetAudioStatus")\


typedef enum
{
#define X_MACRO_NORMAL(a,b,c) a,
    AMPNormalCfg
#undef X_MACRO_NORMAL
    AMPNormalNum
}e_AMPNormalEnum_t;


typedef union
{
    uint8 Data;
    struct
    {
        uint8 CalibrationErrorDetected                          :1;
        uint8 OutputDCOffsetDetected                            :1;
        uint8 OutputClipping                                    :1;
        uint8 CurrentLimitingActive                             :1;
        uint8 ShortToGroundDetected                             :1;
        uint8 ShortToExternalVoltageDetected                    :1;
        uint8 ShortToSupplyDetected                             :1;
        uint8 ShortAcrossLoadDetected                           :1;
    }Channel;
}u_ChannelErr_Type;

typedef struct
{
    union{
        uint8 Data;
        struct{
            uint8 AutoMuteActive                                :1;
            uint8 VDDAUnderVoltageLockoutActive                 :1;
            uint8 VDDPUnderVoltageProtectionActive              :1;
            uint8 OverVoltageWarningActive                      :1;
            uint8 OverVoltageProtectionActive                   :1;
            uint8 ThermalFoldbackModeActive                     :1;
            uint8 OverTemperatureWarningActive                  :1;
            uint8 OverTemperatureProtectionActive               :1;
        }DevSts1Bit;
    }DevSts1;
    union{
        uint8 Data;
        struct{
            uint8 NonVolatileMemoryWriteStatus                  :1;
            uint8 NonVolatileMemoryReadErrorCorrected           :1;
            uint8 NonVolatileMemoryReadErrorNotCorrected        :1;
            uint8 FrameErrorDetected                            :1;
            uint8 MissingFSEdgeDetected                         :1;
            uint8 MissingSCLKEdgeDetected                       :1;
            uint8 SlaveWaitingForSync                           :1;
            uint8 ChargePumpError                               :1;
        }DevSts2Bit;
    }DevSts2;
}s_DeviceSts_Type;

typedef struct
{   
    uint8 Status;
    u_ChannelErr_Type ChannelErr;
}s_ChannelData_Type;



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

extern uint8 AMPDevVCfg;
extern const uint8 AMPPIN_Table[DEVICE_NUM][PIN_8532_Number];
extern const iic_cmd_length_t iic_cmd_length_cfg[AMPIICFlgNum];

extern void AMP_CfgMain(void);
extern u_AMPChannelCfg_t AMP_ChannelCfg(uint8 dev_id);
extern void AMP_ReadNVMKValue(uint8 dev_id, A_u8_20 Data);
extern void AMPGetCurrentClipThreshold(uint8 *ptr);
extern void AMPSetCurrentClipThreshold(uint8 Data);
extern void AMP_TunerSetPwmValue(uint8 DrivingSetting);
extern void AMP_AudioSetGain(S_AmpGainSet_Type *ptr);
extern void AMPSet_LCCalibStep(uint8 dev_id,uint8 data);
extern void AMPSetAMPHighProtect(uint8 state);


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"


#endif
