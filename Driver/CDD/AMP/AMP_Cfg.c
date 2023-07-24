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
 * @file:      AMP_cfg.c
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

#include "AMP_cfg.h"
#include "string.h"
#include "IIC.h"
#include "AMP_Common.h"
#include "Rte_AMP.h"
#include "VConfig_Cfg.h"
#include "logger.h"
#include "Logger_Cfg.h"
#include "AMPVCfg.h"
#include "AMP.h"


typedef struct
{
    uint8 reesrved;
    uint8 reserved;
    uint8 Length;
    uint8 Moduleid;
    uint8 Cmdid;
}s_AMPIICCmd_Type;


typedef struct
{
    s_AMPIICCmd_Type ChannelEnableCom;
    union{
        uint8 Data;
        struct{
            uint8 Ch1Disable    :1;
            uint8 Ch2Disable    :1;
            uint8 Ch3Disable    :1;
            uint8 Ch4Disable    :1;
            uint8 Ch5Disable    :1;
            uint8 rfa           :3;
        }Channel;
    }ChannelCfg;
}s_ChannelDisableCmd_Type;


typedef struct
{
    uint8 ChannelNr;
    uint8 Kvalue;
    uint8 CurrentLimit;
    uint8 PhaseStaggering;
    uint8 MaxModulationDepth;
    uint16 GainReduction;
    uint8 ClipDetectionThreshold;
    uint8 rfa;
    union{
        uint16 Data;
        struct{
            uint16 LineDriverCMVoltage      :12;
            uint16 LineDriverMode           :1;
            uint16 DCOffsetDetection        :1;
            uint16 rfa                      :2;
        }Cfg;
    }ChannelCfg;
}s_ChannelCfgChannelCmd_Type;

typedef struct
{
    s_AMPIICCmd_Type                        ChannelCfgCom;
    uint8                                   NrOfChannels;
    s_ChannelCfgChannelCmd_Type             ChannelCfg[4];
}s_ChannelCfgCmd_Type;

typedef struct
{
    s_AMPIICCmd_Type                        ChannelCfgCom;
    s_DeviceSts_Type                        DeviceSts;
    uint8                                   ResetStatus;
    uint8                                   DeviceState;
}s_GetDeviceStatus_Type;


typedef struct
{
    uint8 ChannelNr;
    uint8 Status;
    uint8 LineDriverMode                    :1;
    uint8 ParallelMode                      :1;
    uint8 ModulationScheme                  :3; 
    uint8 ModPinSetting                     :3;
    uint8 rfa1;
    u_ChannelErr_Type ChanelErr;
    uint8 rfa2;
}s_ChannelCfg_Type;


typedef struct
{
    s_AMPIICCmd_Type                        ChannelStCom;
    uint8                                   NrOfChannels;
    s_ChannelCfg_Type                       ChannelStsData[4];
}s_GetDeviceSts_Type;


#define AMP_START_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"

const uint8 AMPPIN_Table[DEVICE_NUM][PIN_8532_Number] = 
    {
        AMP1_8532_PIN_ID,
        AMP2_8532_PIN_ID
    };

#define AMP_STOP_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"


#define AMP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"

extern s_AMP_State_Type AMP_State_Data[DEVICE_NUM];

uint8 AMPDevVCfg = VCONFIG_ONLYAMP1;

static S_AmpGainSet_Type AmpGainSetData[DEVICE_NUM] = {
    {DEVICE_AMP1,{0xA5,0xC5,0xA5,0xC5,0xA5,0xC5,0xA5,0xC5}},
    {DEVICE_AMP2,{0xA5,0xC5,0xA5,0xC5,0xA5,0xC5,0xA5,0xC5}},
};

static u_AMPChannelCfg_t AMPCHCfg[DEVICE_NUM];
static uint8 AmpPwmData = 0x59u;
static uint8 LCCalibKNVMVValue[DEVICE_NUM][CHANNEL_NUM];
static uint8 AMPLCCalibStep[DEVICE_NUM];
static uint8 AMPHighProtect = AMP_HIGHPROTECTNONE;
static uint8 AMPClipThreshold = 0u;


#define AMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"

#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


/* Configuration commands */
static void AMPSet_AudioCfg(uint8 dev_id);
static void AMPSet_AudioRoutingCfg(uint8 dev_id);
static void AMPSet_HPFCfg(uint8 dev_id);
static void AMPSet_DeviceCfg(uint8 dev_id);
static void AMPSet_DeviceIOConfigData(uint8 dev_id);
static void AMPSet_MuteCfg(uint8 dev_id);
static void AMPSet_DiagPin(uint8 dev_id);
static void AMPSet_PWMData(uint8 dev_id);
static void AMPSet_ModSchemeCfg(uint8 dev_id);
static void AMPSet_ChannelCfg(uint8 dev_id);
static void AMPSet_LCFilterCfg(uint8 dev_id);
static void AMPSet_DCLoadCfg(uint8 dev_id);
static void AMPSet_ACLoadCfg(uint8 dev_id);
static void AMPSet_FilterDiag(uint8 dev_id);

/* Control commands */
static void AMPSet_ClockConnect(uint8 dev_id);
static void AMPSet_ChannelEnable(uint8 dev_id);
static void AMPSet_ChannelDisable(uint8 dev_id);
static void AMPSet_SetChannelMute(uint8 dev_id);
static void AMPSet_ChannelUnmute(uint8 dev_id);
static void AMPSet_StartupDiag(uint8 dev_id);

/* Read commands */
static void AMPGet_DeviceState(uint8 dev_id);
static void AMPGet_FaultState(uint8 dev_id);
static void AMPGet_DeviceStatus(uint8 dev_id);
static void AMPGet_SupplyVoltage(uint8 dev_id);
static void AMPGet_Tempeture(uint8 dev_id);
static void AMPGet_AudioStatus(uint8 dev_id);
static void AMPGet_StartupDiagResult(uint8 dev_id);
static void AMPGet_DCLoadCfg(uint8 dev_id);
static void AMPGet_ACLoadCfg(uint8 dev_id);
static void AMPGet_ChannelStatus(uint8 dev_id);
static void AMPGet_FilterDiagResult(uint8 dev_id);
static void AMPGet_AMPID(uint8 dev_id);


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"


const iic_cmd_length_t iic_cmd_length_cfg[AMPIICFlgNum]=
{
#define X_MACRO_IICDATA(a,b,c,d,e,f) {b,c,d,e,f},
        AMP_IICDataCfg
#undef  X_MACRO_IICDATA
};


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


/***********************************************************************
 * @brief       : SetAudioConfig_cmd 3.1.3
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_AudioCfg(uint8 dev_id)
{
    uint8 Set_AudioCfgData[11] = {0x02u,0x00u,0x08u,0x80u,0x1Cu,0x00u,0x01u,0x02u,0x04u,0x01u,0x01u};
    AMPSet_I2C_Req_Data(dev_id,Set_AudioCfgData,(uint8)sizeof(Set_AudioCfgData));
}

/***********************************************************************
 * @brief       : SetAudioRoutingConfig_cmd 3.1.4
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_AudioRoutingCfg(uint8 dev_id)
{
    uint8 Set_AudioRoutingCfg[13] = {0x02,0x00,0x0A,0x80,0x28,0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03};
    AMPSet_I2C_Req_Data(dev_id,Set_AudioRoutingCfg,(uint8)sizeof(Set_AudioRoutingCfg));
}

/***********************************************************************
 * @brief       : SetHPFConfig_cmd 3.1.5
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_HPFCfg(uint8 dev_id)
{
    uint8 Set_HPFCfg[7] = {0x02,0x00,0x04,0x80,0x44,0x00,0x00};
    AMPSet_I2C_Req_Data(dev_id,Set_HPFCfg,(uint8)sizeof(Set_HPFCfg));
}

/***********************************************************************
 * @brief       : SetDeviceConfig_cmd 3.1.6
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_DeviceCfg(uint8 dev_id)
{
    uint8 Set_DeviceCfg[12] = {0x02u,0x00u,0x09u,0x80u,0x12u,0x00u,0x02u,0x80u,0x01u,0x00u,0x01u,0x00u};
    AMPSet_I2C_Req_Data(dev_id,Set_DeviceCfg,(uint8)sizeof(Set_DeviceCfg));
}

/***********************************************************************
 * @brief       : SetDeviceIOConfig_cmd 3.1.7
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_DeviceIOConfigData(uint8 dev_id)
{
    uint8 SetDeviceIOConfig[13] = {0x02,0x00,0x0A,0x80,0x14,0x02,0x00,0x00,0x00,0x00,0x10,0x01,0x00};
    AMPSet_I2C_Req_Data(dev_id,SetDeviceIOConfig,(uint8)sizeof(SetDeviceIOConfig));
}

/***********************************************************************
 * @brief       : SetMuteConfig_cmd 3.1.8
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_MuteCfg(uint8 dev_id)
{
    uint8 Set_MuteConfig[9] = {0x02,0x00,0x06,0x80,0x18,0x00,0x01,0x00,0x00};
    AMPSet_I2C_Req_Data(dev_id,Set_MuteConfig,(uint8)sizeof(Set_MuteConfig));
}

/***********************************************************************
 * @brief       : SetDiagPin_cmd 3.1.9
                                                    DIAG1  DIAG2   DIAG3
            OverTemperatureProtectionActiveFlag     true
            OverTemperatureWarningActiveFlag        true
            ThermalFoldBackActiveFlag               true
            OverVoltageProtectionActiveFlag         true
            OverVoltageWarningActiveFlag            true
            UnderVoltageProtectionActiveFlag        true
            AutoMuteActiveFlag                      true
            ShortCircuitProtectionActiveFlag                true
            CurrentLimitingActiveFlag                       true
            Ch5ClipDetectActiveFlag     
            Ch4ClipDetectActiveFlag                                 true
            Ch3ClipDetectActiveFlag                                 true
            Ch2ClipDetectActiveFlag                                 true
            Ch1ClipDetectActiveFlag                                 true
            DCOffsetDetectActiveFlag                        true
            ChargePumpErrorFlag                     true
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_DiagPin(uint8 dev_id)
{
    uint8 Set_DiagPinData[21] = {0x02u,0x00u,0x12u,0x80u,0x10u,0x03u,0x00u,0xFEu,0x01u,0x00u,0x00u,0x01u,0x01u,0x82u,0x00u,0x00u,0x02u,0x00u,0x3Cu,0x00u,0x00u};
    AMPSet_I2C_Req_Data(dev_id,Set_DiagPinData,(uint8)sizeof(Set_DiagPinData));
}

/***********************************************************************
 * @brief       : SetPWMFreq_cmd 3.1.10
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_PWMData(uint8 dev_id)
{
    uint8 SetPWMFreq_cmd[8] = {0x02,0x00,0x05,0x80,0x16,0x59,0x01,0x00};
    SetPWMFreq_cmd[5] = AmpPwmData;
    AMPSet_I2C_Req_Data(dev_id,SetPWMFreq_cmd,(uint8)sizeof(SetPWMFreq_cmd));
}

/***********************************************************************
 * @brief       : SetModSchemeConfig_cmd 3.1.11
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_ModSchemeCfg(uint8 dev_id)
{
    uint8 Set_ModSchemeCfg[14] = {0x02,0x00,0x0B,0x80,0x20,0x04,0x01,0x01,0x02,0x01,0x03,0x01,0x04,0x01};
    AMPSet_I2C_Req_Data(dev_id,Set_ModSchemeCfg,(uint8)sizeof(Set_ModSchemeCfg));
}

/***********************************************************************
 * @brief       : SetChannelConfig_cmd 3.1.12
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_ChannelCfg(uint8 dev_id)
{
    uint8 ChannelID;
    uint8 SetChannelConfig_cmd[50] = {\
    0x02,0x00,0x2F,0x80,0x24,0x04,
    /*6   7    8    9   10    11   12   13   14   15   16, total 11*/
    0x01,0x40,0x01,0x00,0x02,0xA5,0xC5,0x00,0x00,0x24,0x00,
    0x02,0x40,0x01,0x02,0x02,0xA5,0xC5,0x00,0x00,0x24,0x00,
    0x03,0x40,0x01,0x04,0x02,0xA5,0xC5,0x00,0x00,0x24,0x00,
    0x04,0x40,0x01,0x06,0x02,0xA5,0xC5,0x00,0x00,0x24,0x00};
    for(ChannelID = 0u;ChannelID < 4u;ChannelID ++)
    {
        SetChannelConfig_cmd[9  + (11 * ChannelID)] = (dev_id * 8u) + (2u * ChannelID);
        SetChannelConfig_cmd[11 + (11 * ChannelID)] = AmpGainSetData[dev_id].GainReduction[ChannelID * 2];
        SetChannelConfig_cmd[12 + (11 * ChannelID)] = AmpGainSetData[dev_id].GainReduction[(ChannelID * 2) + 1];
        SetChannelConfig_cmd[7  + (11 * ChannelID)] = LCCalibKNVMVValue[dev_id][ChannelID];
        SetChannelConfig_cmd[13  + (11 * ChannelID)] = AMPClipThreshold;
    }
    AMPSet_I2C_Req_Data(dev_id,SetChannelConfig_cmd,(uint8)sizeof(SetChannelConfig_cmd));
}

/***********************************************************************
 * @brief       : SetLCFilterConfig_cmd 3.1.13
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_LCFilterCfg(uint8 dev_id)
{
    uint8 SetLCFilterCfg[52] = {0x02,0x00,0x31,0x80,0x2A,0x04,
                                0x01,0x04,0xDE,0x45,0x09,0xB8,0x61,0x04,0xDA,0x2C,0x01,
                                0x02,0x04,0xDE,0x45,0x09,0xB8,0x61,0x04,0xDA,0x2C,0x01,
                                0x03,0x04,0xDE,0x45,0x09,0xB8,0x61,0x04,0xDA,0x2C,0x01,
                                0x04,0x04,0xDE,0x45,0x09,0xB8,0x61,0x04,0xDA,0x2C,0x01,
                                0xC2,0x1C};
    AMPSet_I2C_Req_Data(dev_id,SetLCFilterCfg,(uint8)sizeof(SetLCFilterCfg));
}

/***********************************************************************
 * @brief       : SetDCLoadDetectionConfig_cmd 3.1.14
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_DCLoadCfg(uint8 dev_id)
{
    uint8 Set_DCLoadCfgData[22] = {0x02u,0x00u,0x13u,0x80u,0x22u,0x04u,
                                    0x01u,0x00u,0x04u,0xFAu,
                                    0x02u,0x00u,0x04u,0xFAu,
                                    0x03u,0x00u,0x04u,0xFAu,
                                    0x04u,0x00u,0x04u,0xFAu};
    AMPSet_I2C_Req_Data(dev_id,Set_DCLoadCfgData,(uint8)sizeof(Set_DCLoadCfgData));
}

/***********************************************************************
 * @brief       : SetACLoadDetectionConfig_cmd 3.1.15
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_ACLoadCfg(uint8 dev_id)
{
    uint8 Set_ACLoadCfgData[27] = {0x02u,0x00u,0x18u,0x80u,0x23u,0x04u,0x09u,
                                    0x01u,0x00u,0x00u,0x00u,0x5Fu,
                                    0x02u,0x00u,0x00u,0x00u,0x5Fu,
                                    0x03u,0x00u,0x00u,0x00u,0x5Fu,
                                    0x04u,0x00u,0x00u,0x00u,0x5Fu};
    AMPSet_I2C_Req_Data(dev_id,Set_ACLoadCfgData,(uint8)sizeof(Set_ACLoadCfgData));
}

/***********************************************************************
 * @brief       : SetFilterDiagnostic_cmd 3.1.17
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_FilterDiag(uint8 dev_id)
{
    if(AMPLCCalib_SetFilterDiag1 == AMPLCCalibStep[dev_id])
    {
        uint8 FilterDiagData[7] = {0x02u,0x00u,0x03u,0x80u,0x8Bu,0xFF,0x1A};
        AMPSet_I2C_Req_Data(dev_id,FilterDiagData,(uint8)sizeof(FilterDiagData));
    }
    else if(AMPLCCalib_SetFilterDiag2 == AMPLCCalibStep[dev_id])
    {
        uint8 FilterDiagData[7] = {0x02u,0x00u,0x03u,0x80u,0x8Bu,0x00,0x1A};
        AMPSet_I2C_Req_Data(dev_id,FilterDiagData,(uint8)sizeof(FilterDiagData));
    }
}

/***********************************************************************
 * @brief       : SetClockState_cmd 3.2.1
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_ClockConnect(uint8 dev_id)
{
    uint8 Set_ClockConnectValue[6] = {0x02u,0x00u,0x03u,0x80u,0x1Au,0x01u};
    AMPSet_I2C_Req_Data(dev_id,Set_ClockConnectValue,(uint8)sizeof(Set_ClockConnectValue));
}

/***********************************************************************
 * @brief       : SetChannelEnable_cmd 3.2.2
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_ChannelEnable(uint8 dev_id)
{
    uint8 Set_ChannelEnableData[6] = {0x02u,0x00u,0x03u,0x80u,0x26u,0x0Fu};
    AMPSet_I2C_Req_Data(dev_id,Set_ChannelEnableData,(uint8)sizeof(Set_ChannelEnableData));
}


/***********************************************************************
 * @brief       : SetChannelDisable_cmd 3.2.3
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_ChannelDisable(uint8 dev_id)
{
    if(AMP_STARTUP == AMP_State_Data[dev_id].DeviceState)
    {
        if( (Startup_Standby == AMP_State_Data[dev_id].Major_State) && 
            (Standby_Channel_EnableCfg == AMP_State_Data[dev_id].Sub_State) )
        {
            s_ChannelDisableCmd_Type ChannelDisableCfg = {{0x02u,0x00u,0x03u,0x80u,0x27u},0x0Fu};

			if( AMPCHCfg[dev_id].Channel.CH1 != 0u )
			{
				ChannelDisableCfg.ChannelCfg.Channel.Ch1Disable = 0u;
			}
			if( AMPCHCfg[dev_id].Channel.CH2 != 0u )
			{
				ChannelDisableCfg.ChannelCfg.Channel.Ch2Disable = 0u;
			}
			if( AMPCHCfg[dev_id].Channel.CH3 != 0u )
			{
				ChannelDisableCfg.ChannelCfg.Channel.Ch3Disable = 0u;
			}
			if( AMPCHCfg[dev_id].Channel.CH4 != 0u )
			{
				ChannelDisableCfg.ChannelCfg.Channel.Ch4Disable = 0u;
			}

            AMPSet_I2C_Req_Data(dev_id,(uint8 *)(void *)(&ChannelDisableCfg),(uint8)sizeof(ChannelDisableCfg));
        }
        else
        {
            uint8 Set_Channel_Disable_Default_Value[6] = {0x02u,0x00u,0x03u,0x80u,0x27u,0x0Fu};
            AMPSet_I2C_Req_Data(dev_id,Set_Channel_Disable_Default_Value,(uint8)sizeof(Set_Channel_Disable_Default_Value));
        }
    }
    else
    {
        if( (DEVICE_AMP2 == dev_id) && (AMP_HIGHPROTECTAPPEAR == AMPHighProtect) )
        {
            uint8 Set_Channel_Disable_Default_Value[6] = {0x02u,0x00u,0x03u,0x80u,0x27u,0x07u};
            AMPSet_I2C_Req_Data(dev_id,Set_Channel_Disable_Default_Value,(uint8)sizeof(Set_Channel_Disable_Default_Value));
        }
        else
        {
            uint8 Set_Channel_Disable_Default_Value[6] = {0x02u,0x00u,0x03u,0x80u,0x27u,0x0Fu};
            AMPSet_I2C_Req_Data(dev_id,Set_Channel_Disable_Default_Value,(uint8)sizeof(Set_Channel_Disable_Default_Value));
        }
    }
}

/***********************************************************************
 * @brief       : SetChannelMute_cmd 3.2.4
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_SetChannelMute(uint8 dev_id)
{
    uint8 SetChannelMuteData[6] = {0x02u,0x00u,0x03u,0x80u,0x42u,0x0Fu};
    AMPSet_I2C_Req_Data(dev_id,SetChannelMuteData,(uint8)sizeof(SetChannelMuteData));
}

/***********************************************************************
 * @brief       : SetChannelUnmute_cmd 3.2.5
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_ChannelUnmute(uint8 dev_id)
{
    uint8 Set_ChannelUnmute[6] = {0x02u,0x00u,0x03u,0x80u,0x43u,0x0Fu};
    AMPSet_I2C_Req_Data(dev_id,Set_ChannelUnmute,(uint8)sizeof(Set_ChannelUnmute));
}

/***********************************************************************
 * @brief       : SetStartupDiag_cmd 3.2.6
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSet_StartupDiag(uint8 dev_id)
{
    uint8 Set_StartupDiagValue[8] = {0x02u,0x00u,0x05u,0x80u,0x32u,0x03u,0x00u,0x0Fu};
    AMPSet_I2C_Req_Data(dev_id,Set_StartupDiagValue,(uint8)sizeof(Set_StartupDiagValue));
}

/***********************************************************************
 * @brief       : GetDeviceState_req 4.1
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_DeviceState(uint8 dev_id)
{
    uint8 GetDeviceStateData[5] = {0x02u,0x00u,0x02u,0x80u,0x80u};
    AMPSetRead_I2C_Req_Data(dev_id,GetDeviceStateData,(uint8)sizeof(GetDeviceStateData));
}

/***********************************************************************
 * @brief       : GetFaultStatus_req 4.5 Only available in N2/ROM7.3.0
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_FaultState(uint8 dev_id)
{
    uint8 GetFaultStateData[5] = {0x02u,0x00u,0x02u,0x80,0x81u};
    AMPSetRead_I2C_Req_Data(dev_id,GetFaultStateData,(uint8)sizeof(GetFaultStateData));
}

/***********************************************************************
 * @brief       : GetDeviceStatus_req 4.7 Only available in N3/ROM7.4.0
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_DeviceStatus(uint8 dev_id)
{
    uint8 Get_DeviceStatusData[5] = {0x02u,0x00u,0x02u,0x80u,0x8Cu};
    AMPSetRead_I2C_Req_Data(dev_id,Get_DeviceStatusData,(uint8)sizeof(Get_DeviceStatusData));
}

/***********************************************************************
 * @brief       : GetSupplyVoltage_req 4.9
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_SupplyVoltage(uint8 dev_id)
{
    uint8 GetVoltage[5] = {0x02u,0x00u,0x02u,0x80u,0x82u};
    AMPSetRead_I2C_Req_Data(dev_id,GetVoltage,(uint8)sizeof(GetVoltage));
}

/***********************************************************************
 * @brief       : GetTemperature_req 4.11
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_Tempeture(uint8 dev_id)
{
    uint8 GetTempData[5] = {0x02u,0x00u,0x02u,0x80u,0x84u};
    AMPSetRead_I2C_Req_Data(dev_id,GetTempData,(uint8)sizeof(GetTempData));
}

/***********************************************************************
 * @brief       : GetAudioStatus_req 4.13
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_AudioStatus(uint8 dev_id)
{
    uint8 GetAudioStatusData[5] = {0x02u,0x00u,0x02u,0x80u,0x90u};
    AMPSetRead_I2C_Req_Data(dev_id,GetAudioStatusData,(uint8)sizeof(GetAudioStatusData));
}

/***********************************************************************
 * @brief       : GetStartupDiagStatus_req 4.15
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_StartupDiagResult(uint8 dev_id)
{
    uint8 Get_StartupDiagResult[5] = {0x02u,0x00u,0x02u,0x80u,0x85u};
    AMPSetRead_I2C_Req_Data(dev_id,Get_StartupDiagResult,(uint8)sizeof(Get_StartupDiagResult));
}

/***********************************************************************
 * @brief       : GetDCLoadDetectionResult_req 4.17
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_DCLoadCfg(uint8 dev_id)
{
    uint8 Get_DCLoadResult[5] = {0x02u,0x00u,0x02u,0x80u,0x86u};
    AMPSetRead_I2C_Req_Data(dev_id,Get_DCLoadResult,(uint8)sizeof(Get_DCLoadResult));
}

/***********************************************************************
 * @brief       : GetACLoadDetectionResult_req 4.19
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_ACLoadCfg(uint8 dev_id)
{
    uint8 Get_ACLoadResult[5] = {0x02u,0x00u,0x02u,0x80u,0x87u};
    AMPSetRead_I2C_Req_Data(dev_id,Get_ACLoadResult,(uint8)sizeof(Get_ACLoadResult));
}

/***********************************************************************
 * @brief       : GetChannelStatus_req 4.21
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_ChannelStatus(uint8 dev_id)
{
    uint8 Get_ChannelStatusData[5] = {0x02u,0x00u,0x02u,0x80u,0x88u};
    AMPSetRead_I2C_Req_Data(dev_id,Get_ChannelStatusData,(uint8)sizeof(Get_ChannelStatusData));
}

/***********************************************************************
 * @brief       : GetFilterDiagnosticResult_req 4.23
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_FilterDiagResult(uint8 dev_id)
{
    uint8 Get_FilterDiagResultData[5] = {0x02u,0x00u,0x02u,0x80u,0x8Au};
    AMPSetRead_I2C_Req_Data(dev_id,Get_FilterDiagResultData,(uint8)sizeof(Get_FilterDiagResultData));
}

/***********************************************************************
 * @brief       : GetIdentification_req 4.27
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPGet_AMPID(uint8 dev_id)
{
    uint8 Get_AMPIDData[5] = {0x02u,0x00u,0x02u,0x80,0xE0u};
    AMPSetRead_I2C_Req_Data(dev_id,Get_AMPIDData,(uint8)sizeof(Get_AMPIDData));
}

/***********************************************************************
 * @brief       : 
        Not need read every cycle time, only read at init, as if vechile change, will reast HUT
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_CfgMain(void)
{
    s_AMPVCfg_t VCfg;

    AMP_VConfig(&VCfg);
    AMPCHCfg[DEVICE_AMP1].Data = VCfg.AMP1Cfg.AMPCfgSts;
    AMPCHCfg[DEVICE_AMP2].Data = VCfg.AMP2Cfg.AMPCfgSts;
	/*if vconfig change, will reset HUT, not need lock this par*/
    if((VCfg.AMP1Cfg.AMPCfgSts > 0u) && (VCfg.AMP2Cfg.AMPCfgSts > 0u))
    {
        AMPDevVCfg = VCONFIG_BOTHAMP;
    }
    else if(VCfg.AMP1Cfg.AMPCfgSts > 0u)
    {
        AMPDevVCfg = VCONFIG_ONLYAMP1;
    }
    else if(VCfg.AMP2Cfg.AMPCfgSts > 0u)
    {
        AMPDevVCfg = VCONFIG_ONLYAMP2;
    }
    else
    {
        AMPDevVCfg = VCONFIG_NONE;
    }
    
    (void)amp_warn("AMPDevVCfg = %d",AMPDevVCfg);
    (void)amp_warn("AMP1VCfg = 0x%x",AMPCHCfg[DEVICE_AMP1].Data);
    (void)amp_warn("AMP2VCfg = 0x%x",AMPCHCfg[DEVICE_AMP2].Data);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
u_AMPChannelCfg_t AMP_ChannelCfg(uint8 dev_id)
{
    return AMPCHCfg[dev_id];
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_ReadNVMKValue(uint8 dev_id, A_u8_20 Data) 
{
    (void)memcpy(LCCalibKNVMVValue[dev_id],Data,4);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPGetCurrentClipThreshold(uint8 *ptr)
{
    (void)memcpy(ptr,&AMPClipThreshold,sizeof(AMPClipThreshold));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPSetCurrentClipThreshold(uint8 Data)
{
    AMPClipThreshold = Data;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_TunerSetPwmValue(uint8 DrivingSetting)
{
    AmpPwmData = DrivingSetting;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_AudioSetGain(S_AmpGainSet_Type *ptr)
{
    if(DEVICE_AMP1 == ptr->DeviceId)
    {
        (void)memcpy(&AmpGainSetData[0],ptr,sizeof(S_AmpGainSet_Type));
    }
    else if(DEVICE_AMP2 == ptr->DeviceId)
    {
        (void)memcpy(&AmpGainSetData[1],ptr,sizeof(S_AmpGainSet_Type));
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPSet_LCCalibStep(uint8 dev_id,uint8 data)
{
    AMPLCCalibStep[dev_id] = data;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPSetAMPHighProtect(uint8 state)
{
    AMPHighProtect = state;
}


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"


