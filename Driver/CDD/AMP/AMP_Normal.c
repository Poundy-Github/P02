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
 * @file:      AMP_Normal.c
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

#include "Rte_AMP.h"
#include "AMP_Normal.h"
#include "logger.h"
#include "Logger_Cfg.h"
#include "AMP_Common.h"
#include "AMP_DTC.h"
#include "string.h"
#include "RingBuffer.h"
#include "IPC_Audio.h"
#include "AMP_LCCalib.h"
#include "Misc_Board.h"
#include "Icu.h"
#include "AMP_StartUp.h"

#define AMPCLIPTIME                                                         (200)

typedef struct
{
    e_AMPNormalEnum_t CmdID;
    Std_ReturnType(*p_fun) (uint8 dev_id);
    char *LogName;
}s_AMPNormal_Type;

typedef struct
{
    uint8 PinSts;
    boolean ClipRead;
    boolean IPCSendFlg;
    uint32 TDown;
    uint32 TUp;
    uint32 TM_Current;
}s_AMPClip_Data_Type;

#define AMP_START_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"

static const uint8 AMPPIN_TimerTable[DEVICE_NUM][AMP_DIAGPINNUM] = 
{
    {TIMER_AMP1DIAG1,TIMER_AMP1DIAG2,TIMER_AMP1DIAG3},
    {TIMER_AMP2DIAG1,TIMER_AMP2DIAG2,TIMER_AMP2DIAG3},
};

static const IPC_S2M_AudioAMPGWMTest_t AMPClipCfgInit = 
{
    2u,5u,500u,100u
};

#define AMP_STOP_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"


#define AMP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"

extern I2C_AMPReq_t I2C_Req_AMPData[DEVICE_NUM];

s_AMPClipResult_Type AMPClipResult[DEVICE_NUM];

static uint8 AMPClrDiagResult[DEVICE_NUM];
static uint8 TempState_Backup;
static boolean AMPNormalRun[DEVICE_NUM];
static uint8 AMPNormalCunt[DEVICE_NUM];
static IPC_M2S_AudioAMPAMP_DeviceStatus_t AMPDeviceSts[DEVICE_NUM];
static IPC_M2S_AudioAMPAMP_ChannelStatus_t AMPChannelSts[DEVICE_NUM];
static IPC_S2M_AudioAMPGWMTest_t AMPClipCfgPar;
static IPC_S2M_AudioAMPGWMTest_t AMPClipCfgParBackup;
static s_AMPClipResult_Type AMPClipResultBackup[DEVICE_NUM];
static uint8 HW_Vision;
static s_AMPClip_Data_Type AMPClipData[DEVICE_NUM];

extern FUNC(void, TM_CODE) TM_TimerStartStamp(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp);
static uint32 AMPTimerFlg;


#define AMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


static void AMPNormal_DiagPin_Check(uint8 dev_id,uint8 PinID,Dio_LevelType PinIMacro,uint8 NormalReqID);
static void AMPNormalN2_DiagPin_Check(uint8 dev_id,uint8 PinID,Dio_LevelType PinIMacro);
static Std_ReturnType AMPNormal_Set_Gain(uint8 dev_id);
static Std_ReturnType AMPNormal_GetChannelState(uint8 dev_id);
static Std_ReturnType AMPNormal_GetDeviceStatus(uint8 dev_id);
static Std_ReturnType AMPNormal_HighProtectDisappear(uint8 dev_id);
static Std_ReturnType AMPNormal_HighProtectAppear(uint8 dev_id);
static Std_ReturnType AMPNormal_Tuner_PWM(uint8 dev_id);
static Std_ReturnType AMPDebug_GetDeviceState(uint8 dev_id);
static Std_ReturnType AMPDebug_GetChannelState(uint8 dev_id);
static Std_ReturnType AMPTest_SetChannelCfg(uint8 dev_id);
static Std_ReturnType AMPClip_GetChannelState(uint8 dev_id);
static Std_ReturnType AMPNormal_GetDeviceState(uint8 dev_id);
static Std_ReturnType AMPNormal_GetFaultStatus(uint8 dev_id);
static Std_ReturnType AMPNormal_GetAudioStatus(uint8 dev_id);


static void AMPClipTaskLogic(uint8 dev_id);
static void AMPNormal_RemoveCmd(uint8 dev_id, uint8 CmdID);
static void AMPNormal_ReadChannelCycle100(uint8 dev_id);
static void AMPIPCUpdate(uint8 dev_id);
static void AMPI2CClipSend(uint8 dev_id);
static void AMPClipIQEdgeLogic(uint8 dev_id);
static Std_ReturnType AMP_EventMonitorMain(uint8 dev_id);
static Std_ReturnType AMP_EventLogicMain(uint8 dev_id);


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"


#define AMP_START_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"

static const s_AMPNormal_Type AMPNormalOper[AMPNormalNum]=
{
#define X_MACRO_NORMAL(a,b,c) {a,b,c},
        AMPNormalCfg
#undef  X_MACRO_NORMAL
};

#define AMP_STOP_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

/***********************************************************************
 * @brief       : AMP Normal Init
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_NormalInit(uint8 dev_id)
{
    if(dev_id == DEVICE_AMP2)
    {
        TempState_Backup = TEMP_NORMAL;
        (void)RB_Init(RB_ID_AMP2_QUEUE);
    }
    if(dev_id == DEVICE_AMP1)
    {
        (void)RB_Init(RB_ID_AMP1_QUEUE);
    }
    AMPClipCfgPar = AMPClipCfgInit;
    (void)memcpy(&AMPClipCfgParBackup,&AMPClipCfgPar,sizeof(AMPClipCfgPar));
    (void)memset(&AMPClipData[dev_id],0,sizeof(s_AMPClip_Data_Type));
    (void)memset(&AMPClipResultBackup[dev_id],0,sizeof(s_AMPClipResult_Type));
    (void)memset(&AMPClipResult[dev_id],0,sizeof(s_AMPClipResult_Type));
    AMPNormalCunt[dev_id] = 0u;
    AMPNormalRun[dev_id] = FALSE;
    AMPClipData[dev_id].PinSts = STD_HIGH;
	AMPClrDiagResult[dev_id] = 0u;
}

/***********************************************************************
 * @brief       :
				 According to the status of diagnostic PIN port
				If there are errors, every 100ms communication detection.
				If there are no errors, no communication is required. Clear the error status
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPNormal_DiagPin_Check(uint8 dev_id,uint8 PinID,Dio_LevelType PinIMacro,uint8 NormalReqID)
{
    Dio_LevelType PinState = Dio_ReadChannel(PinIMacro);

    if(FALSE == AMP_TimerIsStarted(AMPPIN_TimerTable[dev_id][PinID]))
    {
        if(STD_LOW == PinState)
        {
            (void)AMPNormalBuf_Insert(dev_id, NormalReqID);
            AMP_TimerStart(AMPPIN_TimerTable[dev_id][PinID]);
			AMPClrDiagResult[dev_id] = 3u;
        }
        else
        {
            if(NORMALAMPGET_CHANNELSTATE == NormalReqID)
            {
                AMPClearDiag2Result(dev_id);
            }
            else
            {
				if( AMPClrDiagResult[dev_id] > 0u )
				{
					AMPClrDiagResult[dev_id]--;
					(void)AMPNormalBuf_Insert(dev_id, NormalReqID);
				}
            }
        }
    }
    else
    {
        if(AMP_TimerIsElasped(AMPPIN_TimerTable[dev_id][PinID],9950))//100ms
        {
            AMP_TimerEnd(AMPPIN_TimerTable[dev_id][PinID]);
        }
    }
}

/***********************************************************************
 * @brief       :
				 According to the status of diagnostic PIN port
				If there are errors, every 100ms communication detection.
				If there are no errors, no communication is required. Clear the error status
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPNormalN2_DiagPin_Check(uint8 dev_id,uint8 PinID,Dio_LevelType PinIMacro)
{
    Dio_LevelType PinState = Dio_ReadChannel(PinIMacro);
	static uint8 MonitorReqID[DEVICE_NUM] = {AMPMONITOR_NONE};

    if(FALSE == AMP_TimerIsStarted(AMPPIN_TimerTable[dev_id][PinID]))
    {
        if(STD_LOW == PinState)
        {
            MonitorReqID[dev_id] = AMPMONITORN2_DEVICE;
            AMP_TimerStart(AMPPIN_TimerTable[dev_id][PinID]);
			AMPClrDiagResult[dev_id] = 1u;
        }
		else
		{
			if( AMPClrDiagResult[dev_id] != 0u )
			{
				AMPClrDiagResult[dev_id] = 0u;
				MonitorReqID[dev_id] = AMPMONITORN2_DEVICE;
			}
		}
    }
    else
    {
        if(AMP_TimerIsElasped(AMPPIN_TimerTable[dev_id][PinID],9950))//100ms
        {
            AMP_TimerEnd(AMPPIN_TimerTable[dev_id][PinID]);
        }
    }

	if( MonitorReqID[dev_id] > AMPMONITOR_NONE )
	{
		if( MonitorReqID[dev_id] == AMPMONITORN2_DEVICE )
		{
			MonitorReqID[dev_id] = AMPMONITOR_FAULT;
			(void)AMPNormalBuf_Insert(dev_id, (uint8)NORMALAMPGET_DEVICESTATE);
		}
		else if( MonitorReqID[dev_id] == AMPMONITOR_FAULT )
		{
			MonitorReqID[dev_id] = AMPMONITOR_AUDIO;
			(void)AMPNormalBuf_Insert(dev_id, (uint8)NORMALAMPGET_FAULTSTATUS);
		}
		else if( MonitorReqID[dev_id] == AMPMONITOR_AUDIO )
		{
			MonitorReqID[dev_id] = AMPMONITOR_NONE;
			(void)AMPNormalBuf_Insert(dev_id, (uint8)NORMALAMPGET_AUDIOSTATUS);
		}
	}
}

/***********************************************************************
 * @brief       : High temperature protection, When the temperature is too high, turn off AMP2
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_HighProtect(void)
{
    u_AMPChannelCfg_t channelCfg = AMP_ChannelCfg(DEVICE_AMP2);

    if( (channelCfg.Channel.CH1 > 0u) || (channelCfg.Channel.CH2 > 0u) || (channelCfg.Channel.CH3 > 0u) )
    {
        SystemState_RecordType PowerOut;
        (void)Rte_Read_rpSR_Power_Out_SystemStateOut(&PowerOut);
        if((TEMP_HIGH_PROTECT == PowerOut.s_TempVoltage.state) && (TEMP_NORMAL == TempState_Backup))
        {
            (void)AMPNormalBuf_Insert(DEVICE_AMP2, (uint8)NORMALSET_HGIHPROTECTAPPEAR);
        }
        else if((TEMP_HIGH_PROTECT == TempState_Backup) && (TEMP_NORMAL == PowerOut.s_TempVoltage.state))
        {
            (void)AMPNormalBuf_Insert(DEVICE_AMP2, (uint8)NORMALSET_HGIHPROTECTDISAPPEAR);
        }
        TempState_Backup = PowerOut.s_TempVoltage.state;
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_HighProtectAppear(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;

	/* only AMP2 has high protect function */
	dev_id = DEVICE_AMP2;

    AMPSetAMPHighProtect(AMP_HIGHPROTECTAPPEAR);
    AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_DISABLE);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALSET_HGIHPROTECTAPPEAR);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALSET_HGIHPROTECTAPPEAR);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_HighProtectDisappear(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;

	/* only AMP2 has high protect function */
	dev_id = DEVICE_AMP2;

    AMPSetAMPHighProtect(AMP_HIGHPROTECTDISAPPEAR);
    AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_ENABLE);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALSET_HGIHPROTECTDISAPPEAR);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALSET_HGIHPROTECTDISAPPEAR);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_GetDeviceStatus(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;

    AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_DEVICESTATUS);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        (void)AMP8532_MonitorResult(dev_id,AMPMONITOR_DEVICE,&I2C_Req_AMPData[dev_id]);
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_DEVICESTATUS);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_DEVICESTATUS);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_GetDeviceState(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;
    AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_DEVICESTATE);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        (void)AMP8532N2_MonitorResult(dev_id,AMPMONITOR_DEVICE,&I2C_Req_AMPData[dev_id]);
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_DEVICESTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_DEVICESTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_GetFaultStatus(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;

    AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_FAULTSTATE);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        (void)AMP8532N2_MonitorResult(dev_id,AMPMONITOR_FAULT,&I2C_Req_AMPData[dev_id]);
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_FAULTSTATUS);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_FAULTSTATUS);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }

    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_GetAudioStatus(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;

    AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_AUDIOSTATUS);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        (void)AMP8532N2_MonitorResult(dev_id,AMPMONITOR_AUDIO,&I2C_Req_AMPData[dev_id]);
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_AUDIOSTATUS);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_AUDIOSTATUS);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }

    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_GetChannelState(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;
    AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_CHANNELSTATUS);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        (void)AMP8532_MonitorResult(dev_id,AMPMONITOR_CHANNEL,&I2C_Req_AMPData[dev_id]);
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_CHANNELSTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPGET_CHANNELSTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPDebug_GetDeviceState(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;
    AMP_I2C_Req_State_Oper(dev_id,(uint8)DEBUGAMPGET_DEVICESTATE);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        AMPDeviceSts[dev_id].DeviceID = dev_id;
        (void)memcpy(&AMPDeviceSts[dev_id].DeviceStatus[0],&I2C_Req_AMPData[dev_id].Data[1],8);
        (void)IPC_M2S_AudioAMPAMP_DeviceStatus_Transmit(&AMPDeviceSts[dev_id]);
        AMPNormal_RemoveCmd(dev_id, (uint8)DEBUGAMPGET_DEVICESTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)DEBUGAMPGET_DEVICESTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPDebug_GetChannelState(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;
    AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_CHANNELSTATUS);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        AMPChannelSts[dev_id].DeviceID = dev_id;
        (void)memcpy(&AMPChannelSts[dev_id].ChannelStatus[0],&I2C_Req_AMPData[dev_id].Data[0],30);
        (void)IPC_M2S_AudioAMPAMP_ChannelStatus_Transmit(&AMPChannelSts[dev_id]);
        AMPNormal_RemoveCmd(dev_id, (uint8)DEBUGAMPGET_CHANNELSTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)DEBUGAMPGET_CHANNELSTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_Set_Gain(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;
    AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_CFG);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPSET_GAIN);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMPSET_GAIN);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPNormal_Tuner_PWM(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;
    AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_PWMFreq_CMD);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMP_CHANGEPWM);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)NORMALAMP_CHANGEPWM);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
			 Different detection methods are used according to different hardware versions
			1. Direct communication detection every 100ms
			2. According to the status of diagnostic PIN port, communication detection every 100ms
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMP_EventMonitorMain(uint8 dev_id)
{
	uint8 LCHWVer = Get_AMP_HWVer(dev_id);

    if(DEVICE_AMP1 == dev_id) 
    {
        if(HW_Vision >= eMiscBoard_Version_B1)
        {
            AMPClipTaskLogic(DEVICE_AMP1);
            AMPNormal_DiagPin_Check(DEVICE_AMP1,(uint8)AMPPIN_DIAG2,DioConf_DioChannel_VIP_AMP8532_DIAG2,(uint8)NORMALAMPGET_CHANNELSTATE);
        }

		if( LCHWVer == AMP853X_HWVERSIONMajor_N3 )
		{
        	AMPNormal_DiagPin_Check(DEVICE_AMP1,(uint8)AMPPIN_DIAG1,DioConf_DioChannel_VIP_AMP8532_DIAG1,(uint8)NORMALAMPGET_DEVICESTATUS);
		}
		else if( LCHWVer == AMP853X_HWVERSIONMajor_N2 )
		{
			AMPNormalN2_DiagPin_Check(DEVICE_AMP1,(uint8)AMPPIN_DIAG1,DioConf_DioChannel_VIP_AMP8532_DIAG1);
		}
		else
		{
			/* do nothing */
		}

		/* High temperature protection, When the temperature is too high, turn off AMP2 */
		if(VCONFIG_BOTHAMP == AMPDevVCfg)
        {
            (void)AMPNormal_HighProtect();
        }
    }

    if(DEVICE_AMP2 == dev_id)
    {
        if(HW_Vision >= eMiscBoard_Version_B1)
        {
            AMPClipTaskLogic(DEVICE_AMP2);
            AMPNormal_DiagPin_Check(DEVICE_AMP2,(uint8)AMPPIN_DIAG2,DioConf_DioChannel_VIP_AMP8531_DIAG2,(uint8)NORMALAMPGET_CHANNELSTATE);
        }

		if( LCHWVer == AMP853X_HWVERSIONMajor_N3 )
		{
			AMPNormal_DiagPin_Check(DEVICE_AMP2,(uint8)AMPPIN_DIAG1,DioConf_DioChannel_VIP_AMP8531_DIAG1,(uint8)NORMALAMPGET_DEVICESTATUS);
		}
		else if( LCHWVer == AMP853X_HWVERSIONMajor_N2 )
		{
			AMPNormalN2_DiagPin_Check(DEVICE_AMP2,(uint8)AMPPIN_DIAG1,DioConf_DioChannel_VIP_AMP8531_DIAG1);
		}
		else
		{
			/* do nothing */
		}		
    }

    if(HW_Vision < eMiscBoard_Version_B1)
    {
        AMPNormal_ReadChannelCycle100(dev_id);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMP_EventLogicMain(uint8 dev_id)
{
    uint8 CurrentCmd = 0u;
    RB_Return_t rbRet = RB_E_EMPTY;
    if(DEVICE_AMP1 == dev_id)
    {
        rbRet = RB_Peek(RB_ID_AMP1_QUEUE,&CurrentCmd, 1);
    }
    else if(DEVICE_AMP2 == dev_id)
    {
        rbRet = RB_Peek(RB_ID_AMP2_QUEUE,&CurrentCmd, 1);
    }
    if(RB_E_EMPTY != rbRet)
    {
        (void)AMPNormalOper[CurrentCmd].p_fun(dev_id);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Std_ReturnType AMP_NormalMain(uint8 dev_id)
{
    (void)AMP_EventMonitorMain(dev_id);
    (void)AMP_EventLogicMain(dev_id);
    AMPDTC_MainFunc(dev_id);
    DIDDataReport();
    AMPIPCUpdate(dev_id);
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_NormalMainLogic(uint8 dev_id)
{
    if(FALSE == AMPNormalRun[dev_id])
    {
        (void)Misc_Board_GetHwVersion(&HW_Vision);
        if(HW_Vision >= eMiscBoard_Version_B1)
        {
            Icu_EnableNotification(IcuConf_IcuChannel_VIP_8532_DIAG3);
            Icu_EnableEdgeDetection(IcuConf_IcuChannel_VIP_8532_DIAG3);
            Icu_EnableNotification(IcuConf_IcuChannel_VIP_AMP8532_DIAG3);
            Icu_EnableEdgeDetection(IcuConf_IcuChannel_VIP_AMP8532_DIAG3);
        }
    }
    AMPNormalRun[dev_id] = TRUE;
	(void)AMP_NormalMain(dev_id);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Std_ReturnType AMPNormalBuf_Insert(uint8 dev_id, uint8 data)
{
    if(dev_id == DEVICE_AMP1)
    {
        (void)RB_Push(RB_ID_AMP1_QUEUE,&data,sizeof(uint8));
    }
    else if(dev_id == DEVICE_AMP2)
    {
        (void)RB_Push(RB_ID_AMP2_QUEUE,&data,sizeof(uint8));
    }

    switch((e_AMPNormalEnum_t)data)
    {
        case NORMALAMPGET_CHANNELSTATE:
        case NORMALAMPGET_DEVICESTATUS:
        case CLIPAMPGET_CHANNELSTATE:
		case NORMALAMPGET_DEVICESTATE:
		case NORMALAMPGET_FAULTSTATUS:
		case NORMALAMPGET_AUDIOSTATUS:
            break;
        default:
            (void)amp_info("Normal Insert %s",AMPNormalOper[data].LogName);
			break;
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPNormal_RemoveCmd(uint8 dev_id, uint8 CmdID)
{
    uint8 data=0u;
    if(DEVICE_AMP1 == dev_id) 
    {
        (void)RB_Pop(RB_ID_AMP1_QUEUE, &data, 1);
    }
    else if(DEVICE_AMP2 == dev_id)
    {
        (void)RB_Pop(RB_ID_AMP2_QUEUE, &data, 1);
    }
    switch((e_AMPNormalEnum_t)data)
    {
        case NORMALAMPGET_CHANNELSTATE:
        case NORMALAMPGET_DEVICESTATUS:
        case CLIPAMPGET_CHANNELSTATE:
		case NORMALAMPGET_DEVICESTATE:
		case NORMALAMPGET_FAULTSTATUS:
		case NORMALAMPGET_AUDIOSTATUS:
            break;
        default:
        (void)amp_info("Normal Remove %s\n",AMPNormalOper[CmdID].LogName);
			break;
    }
}

/***********************************************************************
 * @brief       : Monitor AMP each channel status every 100ms, for each DTC item
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPNormal_ReadChannelCycle100(uint8 dev_id)
{
    if(TRUE == AMPNormalRun[dev_id])
    {
        AMPNormalCunt[dev_id] ++;
        if(AMPNormalCunt[dev_id] >= 20u)
        {
            AMPNormalCunt[dev_id] = 0u;
            (void)AMPNormalBuf_Insert(dev_id, (uint8)NORMALAMPGET_CHANNELSTATE);
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPClipParSet(IPC_S2M_AudioAMPGWMTest_t *par)
{
    AMPClipCfgPar.clip_hold_time = par->clip_hold_time;
    AMPClipCfgPar.clip_polling_cycle = par ->clip_polling_cycle;
    AMPClipCfgPar.clip_release_time = par ->clip_release_time;
    AMPClipCfgPar.clip_threshold = par->clip_threshold;
    AMPGetCurrentClipThreshold(&AMPClipCfgParBackup.clip_threshold);
    if(AMPClipCfgPar.clip_threshold != AMPClipCfgParBackup.clip_threshold)
    {
        AMPSetCurrentClipThreshold(AMPClipCfgPar.clip_threshold);
        (void)AMPNormalBuf_Insert(DEVICE_AMP1, (uint8)TESTAMPSET_CHANNELCFG);
        (void)AMPNormalBuf_Insert(DEVICE_AMP2, (uint8)TESTAMPSET_CHANNELCFG);
        (void)amp_info("AMP Clip threshold change from %d to %d",AMPClipCfgParBackup.clip_threshold,AMPClipCfgPar.clip_threshold);
    }
    if((AMPClipCfgPar.clip_hold_time != AMPClipCfgParBackup.clip_hold_time) ||\
        (AMPClipCfgPar.clip_release_time != AMPClipCfgParBackup.clip_release_time) ||\
        (AMPClipCfgPar.clip_polling_cycle != AMPClipCfgParBackup.clip_polling_cycle))
    {
        (void)memset(&AMPClipData,0,sizeof(AMPClipData));
        AMPClipData[DEVICE_AMP1].PinSts = STD_HIGH;
        AMPClipData[DEVICE_AMP2].PinSts = STD_HIGH;
    }
    if(AMPClipCfgPar.clip_hold_time != AMPClipCfgParBackup.clip_hold_time)
    {
        (void)amp_info("AMP clip_hold_time change from %d to %d",AMPClipCfgParBackup.clip_hold_time,AMPClipCfgPar.clip_hold_time);
    }
    if(AMPClipCfgPar.clip_release_time != AMPClipCfgParBackup.clip_release_time)
    {
        (void)amp_info("AMP clip_release_time change from %d to %d",AMPClipCfgParBackup.clip_release_time,AMPClipCfgPar.clip_release_time);
    }
    if(AMPClipCfgPar.clip_polling_cycle != AMPClipCfgParBackup.clip_polling_cycle)
    {
        (void)amp_info("AMP clip_polling_cycle change from %d to %d",AMPClipCfgParBackup.clip_polling_cycle,AMPClipCfgPar.clip_polling_cycle);
    }
    (void)memcpy(&AMPClipCfgParBackup,&AMPClipCfgPar,sizeof(AMPClipCfgPar));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPTest_SetChannelCfg(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;
    AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_CFG);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)TESTAMPSET_CHANNELCFG);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)TESTAMPSET_CHANNELCFG);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPClip_GetChannelState(uint8 dev_id)
{
    I2C_Req_Sts_t I2CReqRet;
    AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_CHANNELSTATUS);
    I2CReqRet = AMPGet_I2C_Req_DataSts(dev_id);
    if (I2C_Req_Success == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)CLIPAMPGET_CHANNELSTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
        if(TRUE == AMPClipData[dev_id].IPCSendFlg)
        {
            AMPClipResult[dev_id].IPCSend = TRUE;
            AMPI2CClipSend(dev_id);
        }
    }
    else if(I2C_Req_Err == I2CReqRet)
    {
        AMPNormal_RemoveCmd(dev_id, (uint8)CLIPAMPGET_CHANNELSTATE);
        AMPSet_I2C_Req_DataSts(dev_id,I2C_Req_Idle);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       :  AMP1 IR Func
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_IsrVIP_AMP8532_DIAG3(void)
{
    AMPClipIQEdgeLogic(DEVICE_AMP1);
}

/***********************************************************************
 * @brief       :  AMP2 IR Func
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_IsrVIP_8532_DIAG3(void)
{
    AMPClipIQEdgeLogic(DEVICE_AMP2);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPClipIQEdgeLogic(uint8 dev_id)
{
    TM_TimerStartStamp(&AMPClipData[dev_id].TM_Current);
    if(DEVICE_AMP1 == dev_id)
    {
        AMPClipData[dev_id].PinSts = (uint8)Icu_GetInputState(IcuConf_IcuChannel_VIP_AMP8532_DIAG3);
    }
    else if(DEVICE_AMP2 == dev_id)
    {
        AMPClipData[dev_id].PinSts = (uint8)Icu_GetInputState(IcuConf_IcuChannel_VIP_8532_DIAG3);
    }
	else
	{}

    if(STD_LOW == AMPClipData[dev_id].PinSts)
    {
        AMPClipData[dev_id].TDown = AMPClipData[dev_id].TM_Current;
        if(TRUE == AMPClipData[dev_id].IPCSendFlg)
        {
            if((AMPClipData[dev_id].TUp - AMPClipData[dev_id].TM_Current) >= (AMPClipCfgPar.clip_release_time * 20000u))
            {
                AMPClipData[dev_id].IPCSendFlg = FALSE;
                AMPClipData[dev_id].ClipRead = FALSE;
                AMPClipResult[dev_id].IPCSend = TRUE;
                AMPClipResult[dev_id].ChannelClip[0] = 0u;
                AMPClipResult[dev_id].ChannelClip[1] = 0u;
                AMPClipResult[dev_id].ChannelClip[2] = 0u;
                AMPClipResult[dev_id].ChannelClip[3] = 0u;
                (void)GetCounterValue(SystemTimer,&AMPTimerFlg);
                (void)amp_debug("%ld MS AMP%d clip Release",AMPTimerFlg,dev_id + 1);
            }
        }
        AMPClipData[dev_id].ClipRead = TRUE;
        if(FALSE == AMP_TimerIsStarted(TIMER_AMP1DIAG3 + (dev_id * 3u)))
        {
            (void)GetCounterValue(SystemTimer,&AMPTimerFlg);
            AMP_TimerStart(TIMER_AMP1DIAG3 + (dev_id * 3u));
            (void)AMPNormalBuf_Insert(dev_id, (uint8)CLIPAMPGET_CHANNELSTATE);
            (void)amp_verbose("%ldMS AMP Read IIC1",AMPTimerFlg);
        }
    }
    else if(STD_HIGH == AMPClipData[dev_id].PinSts)
    {
        AMPClipData[dev_id].TUp = AMPClipData[dev_id].TM_Current;
        if(FALSE == AMPClipData[dev_id].IPCSendFlg)
        {
            if((AMPClipData[dev_id].TDown - AMPClipData[dev_id].TM_Current) >= (AMPClipCfgPar.clip_hold_time * 20000u / AMPCLIPTIME) )
            {
                AMPClipData[dev_id].IPCSendFlg = TRUE;
            }
        }
    }
	else
	{}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPIPCFlgUpdate(uint8 dev_id)
{
    if(DEVICE_AMP1 == dev_id)
    {
        AMPClipData[dev_id].PinSts = (uint8)Icu_GetInputState(IcuConf_IcuChannel_VIP_AMP8532_DIAG3);
    }
    else if(DEVICE_AMP2 == dev_id)
    {
        AMPClipData[dev_id].PinSts = (uint8)Icu_GetInputState(IcuConf_IcuChannel_VIP_8532_DIAG3);
    }

    SuspendOSInterrupts();
    TM_TimerStartStamp(&AMPClipData[dev_id].TM_Current);
    if(STD_HIGH == AMPClipData[dev_id].PinSts)
    {
        if(TRUE == AMPClipData[dev_id].IPCSendFlg)
        {
            if((AMPClipData[dev_id].TUp - AMPClipData[dev_id].TM_Current) >= (AMPClipCfgPar.clip_release_time * 20000u))
            {
                AMPClipData[dev_id].IPCSendFlg = FALSE;
                AMPClipData[dev_id].ClipRead = FALSE;
                AMPClipResult[dev_id].IPCSend = TRUE;
                AMPClipResult[dev_id].ChannelClip[0] = 0u;
                AMPClipResult[dev_id].ChannelClip[1] = 0u;
                AMPClipResult[dev_id].ChannelClip[2] = 0u;
                AMPClipResult[dev_id].ChannelClip[3] = 0u;
                (void)GetCounterValue(SystemTimer,&AMPTimerFlg);
                (void)amp_debug("%ld MS AMP%d clip Release",AMPTimerFlg,dev_id + 1);
            }
        }
    }
    else if(STD_LOW == AMPClipData[dev_id].PinSts)
    {
        if(FALSE == AMPClipData[dev_id].IPCSendFlg)
        {
            if((AMPClipData[dev_id].TDown - AMPClipData[dev_id].TM_Current) >= (AMPClipCfgPar.clip_hold_time * 20000u / AMPCLIPTIME) )
            {
                AMPClipData[dev_id].IPCSendFlg = TRUE;
            }
        }
        AMPClipData[dev_id].ClipRead = TRUE;
    }
    ResumeOSInterrupts();
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : if rising edge trigger
 ***********************************************************************/
static void AMPClipTaskLogic(uint8 dev_id)
{
    AMPIPCFlgUpdate(dev_id);
    if(TRUE == AMP_TimerIsStarted(TIMER_AMP1DIAG3 + (dev_id * 3u)))
    {
        if(AMP_TimerIsElasped(TIMER_AMP1DIAG3 + (dev_id * 3u),AMPClipCfgPar.clip_polling_cycle * 10u))
        {
            AMP_TimerEnd(TIMER_AMP1DIAG3 + (dev_id * 3u));
            if(TRUE == AMPClipData[dev_id].ClipRead)
            {
                (void)GetCounterValue(SystemTimer,&AMPTimerFlg);
                AMP_TimerStart(TIMER_AMP1DIAG3 + (dev_id * 3u));
                (void)AMPNormalBuf_Insert(dev_id, (uint8)CLIPAMPGET_CHANNELSTATE);
                (void)amp_verbose("%ldMS AMP %d Read IIC as polling timer elasped",AMPTimerFlg,dev_id + 1);
                AMPClipData[dev_id].ClipRead = FALSE;
            }
        }
    }
    else 
    {
        if(TRUE == AMPClipData[dev_id].ClipRead)
        {
            (void)GetCounterValue(SystemTimer,&AMPTimerFlg);
            (void)amp_verbose("%ldMS AMP Read IIC 3",AMPTimerFlg);
            AMP_TimerStart(TIMER_AMP1DIAG3 + (dev_id * 3u));
            (void)AMPNormalBuf_Insert(dev_id, (uint8)CLIPAMPGET_CHANNELSTATE);
            (void)GetCounterValue(SystemTimer,&AMPTimerFlg);
            (void)amp_debug("%ldMS AMP %d Read IIC",AMPTimerFlg,dev_id + 1);
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPI2CClipSend(uint8 dev_id)
{
    uint8 CHIndex;
    s_ChannelData_Type ClipChannelData[CHANNEL_NUM];
    for(CHIndex = 0u; CHIndex < AMP8532_CHANNEL_NUM; CHIndex ++)
    {
        ClipChannelData[CHIndex].ChannelErr.Data = I2C_Req_AMPData[dev_id].Data[10 + (CHIndex * 6)];
        AMPClipResult[dev_id].ChannelClip[CHIndex] = ClipChannelData[CHIndex].ChannelErr.Channel.OutputClipping;
    }
}

/***********************************************************************
 * @brief       : Clip IPC Send Update Logic 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPIPCUpdate(uint8 dev_id)
{
    if(TRUE == AMPClipResult[dev_id].IPCSend)
    {
        if((0u != memcmp(&AMPClipResult[dev_id].ChannelClip[0],&AMPClipResultBackup[dev_id].ChannelClip[0],4))/* &&\
            (TRUE == AMP_TimerIsStarted(TIMER_AMP1DIAG3))*/)
        {
            int32_t ret = -1;
            if(DEVICE_AMP1 == dev_id)
            {
                ret = IPC_M2S_AudioAMPAMP1ClipStatus_Transmit((IPC_M2S_AudioAMPAMP1ClipStatus_t *)(void *)(&AMPClipResult[dev_id].ChannelClip[0]));
            }
            if(DEVICE_AMP2 == dev_id) 
            {
                ret = IPC_M2S_AudioAMPAMP2ClipStatus_Transmit((IPC_M2S_AudioAMPAMP2ClipStatus_t *)(void *)(&AMPClipResult[dev_id].ChannelClip[0]));
            }
            if(0u == ret)
            {
                (void)memcpy(&AMPClipResultBackup[dev_id].ChannelClip[0],&AMPClipResult[dev_id].ChannelClip[0],4);
                AMPClipResult[dev_id].IPCSend = FALSE;
                (void)GetCounterValue(SystemTimer,&AMPTimerFlg);
                (void)amp_debug("%d AMP%d Clip report %d %d %d %d",AMPTimerFlg, dev_id + 1, AMPClipResult[dev_id].ChannelClip[0],AMPClipResult[dev_id].ChannelClip[1],AMPClipResult[dev_id].ChannelClip[2],AMPClipResult[dev_id].ChannelClip[3]);
            }
        }
        else
        {
            AMPClipResult[dev_id].IPCSend = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : Clip IPC Send Update Logic 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPGetClipResult(s_AMPClipResult_Type *Data, uint8 dev_id)
{
    (void)memcpy(Data,&AMPClipResult[dev_id],sizeof(s_AMPClipResult_Type));
}


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

