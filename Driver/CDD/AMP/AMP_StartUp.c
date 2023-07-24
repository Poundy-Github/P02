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
 * @file:      AMP_StartUp.c
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
#include "AMP_StartUp.h"
#include "String.h"
#include "logger.h"
#include "Logger_Cfg.h"
#include "AMP_Common.h"
#include "AMP_DTC.h"
#include "AMP.h"
#include "AMP_ShutDown.h"



#define AMP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"

extern s_AMP_State_Type AMP_State_Data[DEVICE_NUM];
static uint8 AMPShutdown2Startup_Retry[DEVICE_NUM];
static uint8 AMPStartup_Retry[DEVICE_NUM];
static uint8 AMP_ID_INFOR[DEVICE_NUM][6];
extern I2C_AMPReq_t I2C_Req_AMPData[DEVICE_NUM];
static uint8 AMP_DiagRetryCunt[DEVICE_NUM];
static uint8 AMPDeviceState[DEVICE_NUM];
static uint8 AMPDCcheckfail[DEVICE_NUM];
static uint8 AMPIsNotInPlaying[DEVICE_NUM];


#define AMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


static void AMP_BootEnableLogic(uint8 dev_id);
static Std_ReturnType Boot_Get_IDCallback(uint8 dev_id);
static Std_ReturnType SetDiag_Callback(uint8 dev_id);
static Std_ReturnType AMPUmute_Callback(uint8 dev_id);
static void AMP_Startup_Idle_Mgr(uint8 dev_id);
static void AMP_Startup_SCLK_Wait_Mgr(uint8 dev_id);
static void AMP_Startup_Standby_mgr(uint8 dev_id);
static void AMP_Startup_StateTransfer(uint8 ID, uint8 Major, uint8 Sub);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_StartUpInit(uint8 dev_id)
{
	AMPIsNotInPlaying[dev_id] = 0u;
	AMPDCcheckfail[dev_id] = 0x0u;
	AMPShutdown2Startup_Retry[dev_id] = 0x0u;
    AMPStartup_Retry[dev_id] = 0x0u;
    AMP_DiagRetryCunt[dev_id] = 0x0u;
	(void)memset(AMP_ID_INFOR[dev_id], 0, 6);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_StartupMainLogic(uint8 dev_id)
{
    switch( (Startup_StateMachine_t)AMP_State_Data[dev_id].Major_State )
    {
        case Startup_Idle:
            AMP_Startup_Idle_Mgr(dev_id);
            break;
        
        case Startup_SCLK_Wait:
            AMP_Startup_SCLK_Wait_Mgr(dev_id);
            break;

        case Startup_Standby:
            AMP_Startup_Standby_mgr(dev_id);
            break;
        
        case Startup_Done:
            AMP_State_Data[dev_id].NextState = AMP_NORMAL;
            break;
		
        case Startup_Err:
			if( AMPShutdown2Startup_Retry[dev_id] < (AMP8532_START_RETRY_COUNTER-1u) )
			{
				AMPShutdown2Startup_Retry[dev_id]++;
				AMP_EmergencyShutdownOneDevice(dev_id);
				AMP_Startup_StateTransfer(dev_id, (uint8)Startup_Idle, (uint8)Boot_Enable);
				AMPDCcheckfail[dev_id] = 0u;
				AMPIsNotInPlaying[dev_id] = 0u;
				(void)amp_warn("AMP%d startup fail retry %d",dev_id+1,AMPShutdown2Startup_Retry[dev_id]);
			}
			else
			{
				if( AMPIsNotInPlaying[dev_id] != 0u )
				{
					AMPShutdown2Startup_Retry[dev_id]++;
					AMP_State_Data[dev_id].Major_State = (uint8)Startup_Standby;
					AMP_State_Data[dev_id].Sub_State = (uint8)Standby_Playing_Check;
				}
			}
            break;

        default:
        	/* do nothing */
            break;
    }
}

/***********************************************************************
 * @brief       : get AMP Rom ID
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType Boot_Get_IDCallback(uint8 dev_id)
{
    (void)memcpy(&AMP_ID_INFOR[dev_id][0], &I2C_Req_AMPData[dev_id].Data[5], 6);

    (void)amp_warn("AMP%d HwVer:N%d SwVer:%d.%d.%d", dev_id+1,AMP_ID_INFOR[dev_id][1], 
		AMP_ID_INFOR[dev_id][3], AMP_ID_INFOR[dev_id][4], AMP_ID_INFOR[dev_id][5]);
	
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean Get_AMP_Infor(uint8 amp_id, AMP_ID_INFOR_t * ptr)
{
    boolean ret = FALSE;
    if (amp_id < DEVICE_NUM)
    {
        (void)memcpy(ptr, &AMP_ID_INFOR[amp_id][0], 6);
        ret = TRUE;
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 Get_AMP_HWVer(uint8 dev_id)
{
    uint8 ret = AMP853X_HWVERSIONMajor_N3;

    if( dev_id < DEVICE_NUM )
    {
        ret = AMP_ID_INFOR[dev_id][1];
    }

    return( ret );
}

/***********************************************************************
 * @brief       : CheckIdleState
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Idle_Get_StateCallback(uint8 dev_id)
{
    if (I2C_Req_Success == I2C_Req_AMPData[dev_id].Sts)
    {
        if((uint8)Idle_Standby_Check == AMP_State_Data[dev_id].Sub_State)
        {
            AMPDeviceState[dev_id] = I2C_Req_AMPData[dev_id].Data[5];
            if ((AMP_IDLE == AMPDeviceState[dev_id]) ||(AMP_STANDBY == AMPDeviceState[dev_id]) ||(AMP_PLAYING == AMPDeviceState[dev_id]))
            {
                AMP_State_Data[dev_id].Sub_State = (uint8)Idle_Done;
            }
            else
            {
                AMP_State_Data[dev_id].Sub_State = (uint8)Idle_Set_Diag_Pin;
				(void)amp_info("AMP%d DeviceState is %d",dev_id + 1,AMPDeviceState[dev_id]);
            }
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
        }
    }
    else if(I2C_Req_Err == I2C_Req_AMPData[dev_id].Sts)
    {
        AMP_State_Data[dev_id].Sub_State = (uint8)Idle_Err;
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SCLK_Get_StateCallback(uint8 dev_id)
{
    if( I2C_Req_Success == I2C_Req_AMPData[dev_id].Sts )
    {
        if((uint8)SCLK_Wait_Check == AMP_State_Data[dev_id].Sub_State)
        {
            AMPDeviceState[dev_id] = I2C_Req_AMPData[dev_id].Data[5];
            if ((AMP_STANDBY == AMPDeviceState[dev_id]) || (AMP_PLAYING == AMPDeviceState[dev_id]))
            {
                AMP_State_Data[dev_id].Sub_State = (uint8)SCLK_Wait_Done;
                //amp_info("[AMP%d] State is Playing",dev_id + 1);
            }
            else
            {
                AMP_State_Data[dev_id].Sub_State = (uint8)SCLK_Wait_Connect_Clock;
            }
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
        }
    }
    else if(I2C_Req_Err == I2C_Req_AMPData[dev_id].Sts)
    {
        AMP_State_Data[dev_id].Sub_State = (uint8)Idle_Err;
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Standby_Get_StateCallback(uint8 dev_id)
{
    if(I2C_Req_Success == I2C_Req_AMPData[dev_id].Sts)
    {
        AMPDeviceState[dev_id] = I2C_Req_AMPData[dev_id].Data[5];
		
        if (AMP_PLAYING == AMPDeviceState[dev_id])
        {
            AMP_State_Data[dev_id].Sub_State = (uint8)Standby_Done;
			AMPIsNotInPlaying[dev_id] = 0u;
        }
        else
        {
        	AMPIsNotInPlaying[dev_id] = 1u;
        	if( (AMPDCcheckfail[dev_id] != 0u) && (AMPStartup_Retry[dev_id] < AMP8532_START_RETRY_COUNTER) )
			{
				AMP_State_Data[dev_id].Sub_State = (uint8)Standby_DCLoad_Cfg;
				AMPStartup_Retry[dev_id]++;
			}
			else if( AMPShutdown2Startup_Retry[dev_id] < AMP8532_START_RETRY_COUNTER )
			{
				AMP_State_Data[dev_id].Major_State = (uint8)Startup_Err;
				(void)amp_info("AMP%d DeviceState is %d",dev_id + 1,AMPDeviceState[dev_id]);
				if( AMPDeviceState[dev_id] == AMP_CLOCKFAIL )
				{
					(void)amp_warn("AMP%d Startup Standby failed lost clock",dev_id+1);
				}
				else if( AMPDeviceState[dev_id] == AMP_PROTECTED )
				{
					(void)amp_warn("AMP%d Startup Standby failed alarm happen",dev_id+1);
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				AMP_State_Data[dev_id].Sub_State = (uint8)Standby_Playing_Check;
			}
        }
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
    }
    else if(I2C_Req_Err == I2C_Req_AMPData[dev_id].Sts)
    {
        AMP_State_Data[dev_id].Sub_State = (uint8)Standby_Err;
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_Startup_Idle_Mgr(uint8 dev_id)
{
    switch( (Startup_Idle_t)AMP_State_Data[dev_id].Sub_State )
    {
        case Boot_Enable:
            AMP_BootEnableLogic(dev_id);
            break;
        case Boot_Get_ID:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_AMP_ID);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Idle_Set_Diag_Pin,(uint8)Idle_Err,Boot_Get_IDCallback);    
            break;
        case Idle_Set_Diag_Pin:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_DIAG_PIN);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Idle_Set_Device_Cfg,(uint8)Idle_Err,NULL);
            break;       
        case Idle_Set_Device_Cfg:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_DEVICECONFIG);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Idle_Set_Disable_Channels,(uint8)Idle_Err,NULL);
            break;
        case Idle_Set_Disable_Channels:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_DISABLE);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Idle_Set_Audio_Cfg,(uint8)Idle_Err,NULL); 
            break;
        case Idle_Set_Audio_Cfg:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_AUDIO_CONFIG);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Idle_Set_Audiorounting_Cfg,(uint8)Idle_Err,NULL);
            break;
        case Idle_Set_Audiorounting_Cfg:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_AUDIO_ROUTING_CFG);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Idle_Standby_Check,(uint8)Idle_Err,NULL);
            break;
        case Idle_Standby_Check:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_DEVICESTATE);
            Idle_Get_StateCallback(dev_id);          
            break;
        case Idle_Done:
            AMP_Startup_StateTransfer(dev_id, (uint8)Startup_SCLK_Wait, 0u);
			(void)amp_warn("AMP%d Startup Idle Finished",dev_id+1);
            break;
        case Idle_Err:
            AMPStartup_Retry[dev_id]++;
            if (AMP8532_START_RETRY_COUNTER <= AMPStartup_Retry[dev_id])
            {
                AMP_State_Data[dev_id].Major_State = (uint8)Startup_Err;
				(void)amp_warn("AMP%d Startup Idle failed",dev_id+1);
            }
            else
            {
                AMP_State_Data[dev_id].Sub_State = (uint8)Boot_Enable;
            }
            break;
        default:
			/* do nothing */
            break;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_Startup_SCLK_Wait_Mgr(uint8 dev_id)
{
    switch( (Startup_SCLK_Wait_t)AMP_State_Data[dev_id].Sub_State )
    {
        case SCLK_Wait_Connect_Clock:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CLOCKSTATE);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)SCLK_Wait_Check,(uint8)SCLK_Wait_Err,NULL);  
            break;
        case SCLK_Wait_Check:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_DEVICESTATE);
            SCLK_Get_StateCallback(dev_id); 
            break;
        case SCLK_Wait_Done:
            AMP_Startup_StateTransfer(dev_id, (uint8)Startup_Standby, 0u);
			(void)amp_warn("AMP%d Startup SCLK Finished",dev_id+1);
            break;
        case SCLK_Wait_Err:
			AMPStartup_Retry[dev_id]++;
            if (AMP8532_START_RETRY_COUNTER <= AMPStartup_Retry[dev_id])
            {
                AMP_State_Data[dev_id].Major_State = (uint8)Startup_Err;
				(void)amp_warn("AMP%d Startup SCLK failed",dev_id+1);
            }
            else 
            {
                AMP_State_Data[dev_id].Sub_State = (uint8)SCLK_Wait_Connect_Clock;
            }
            break;
        default:
			/* do nothing */
            break;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Standby_Diag_CheckCallback(uint8 dev_id)
{
    if (I2C_Req_Success == I2C_Req_AMPData[dev_id].Sts)
    {
        uint8 DCLoadDetectionStatus = I2C_Req_AMPData[dev_id].Data[5];
        uint8 ACLoadDetectionStatus = I2C_Req_AMPData[dev_id].Data[6];
        uint8 StartupDiagnosticStatus = I2C_Req_AMPData[dev_id].Data[7];
        if ((0x2u == DCLoadDetectionStatus) && (0x2u == ACLoadDetectionStatus) && (0x2u == StartupDiagnosticStatus))
        {
            AMP_State_Data[dev_id].Sub_State = (uint8)Standby_DC_Results;
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
            AMP_DiagRetryCunt[dev_id] = 0u;
            //amp_debug("AMP%d Diag Status is DC%d AC%d Startup%d", dev_id + 1, DCLoadDetectionStatus, ACLoadDetectionStatus, StartupDiagnosticStatus);
        }
        else 
        {
            AMP_DiagRetryCunt[dev_id] ++;
            if(AMP_DiagRetryCunt[dev_id] < 3u)
            {
                AMP_State_Data[dev_id].Sub_State = (uint8)Standby_DCLoad_Cfg;
            }
            else
            {
            	if( AMPStartup_Retry[dev_id] >= (AMP8532_START_RETRY_COUNTER-1u) )
            	{
					AMP_State_Data[dev_id].Sub_State = (uint8)Standby_DC_Results;
					(void)amp_warn("AMP%d DCcheck fail read state",dev_id+1);
				}
				else
				{
					AMP_State_Data[dev_id].Sub_State = (uint8)Standby_Channel_Cfg;
					(void)amp_warn("AMP%d DCcheck timeout",dev_id+1);
				}
				AMPDCcheckfail[dev_id] = 1u;
            }
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
        }
    }
    else if(I2C_Req_Err == I2C_Req_AMPData[dev_id].Sts)
    {
        AMP_State_Data[dev_id].Sub_State = (uint8)Standby_Err;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType DC_Results_StateCallback(uint8 dev_id)
{
    (void)AMP8532_SelfCheckResult(dev_id, AMPSELFCHECKTYPE_DCLOAD,&I2C_Req_AMPData[dev_id]);
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType ChannelEnable_Callback(uint8 dev_id)
{
    Std_ReturnType ret = E_NOT_OK;
    if(TRUE == AMP_TimerIsStarted(dev_id))
    {
        if(TRUE == AMP_TimerIsElasped(dev_id,AMPTIMER_CHANNELENABLE_WAIT))
        {
            AMP_TimerEnd(dev_id);
            ret = E_OK;
        }
    }
    else
    {
        AMP_TimerStart(dev_id);
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPUmute_Callback(uint8 dev_id)
{
    AMP8532_Set_Pin(dev_id, AMPPIN_MUTE_N, STD_HIGH);
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType SetDiag_Callback(uint8 dev_id)
{
    Std_ReturnType ret = E_NOT_OK;
    if(TRUE == AMP_TimerIsStarted(dev_id))
    {
        if(TRUE == AMP_TimerIsElasped(dev_id,AMPTIMER_SETDIAGWAIT))
        {
            AMP_TimerEnd(dev_id);
            ret = E_OK;
        }
    }
    else
    {
        AMP_TimerStart(dev_id);
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_Startup_Standby_mgr(uint8 dev_id)
{
    switch( (Startup_Standby_t)AMP_State_Data[dev_id].Sub_State )
    {
        case Standby_DCLoad_Cfg:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_DCLOADDETECTION_CONFIG);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Standby_start_diag,(uint8)Standby_Err,NULL);
            break;
        case Standby_start_diag:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_STARTUPDIAG);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Standby_GET_Diag_Sts,(uint8)Standby_Err,SetDiag_Callback);
            break;
        case Standby_GET_Diag_Sts:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_STARTUPDIAGSTATUS);
            Standby_Diag_CheckCallback(dev_id);
            break;
        case Standby_DC_Results:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_DCLOADDETECTIONRESULT);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Standby_Channel_Cfg,(uint8)Standby_Err,DC_Results_StateCallback);      
            break;
        case Standby_Channel_Cfg:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_CFG);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Standby_Channel_Enable,(uint8)Standby_Err,NULL);
            break;
        case Standby_Channel_Enable:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_ENABLE);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Standby_Channel_EnableCfg,(uint8)Standby_Err,ChannelEnable_Callback);
            break;          
        case Standby_Channel_EnableCfg:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_DISABLE);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Standby_UnMute,(uint8)Standby_Err,ChannelEnable_Callback);
            break;
        case Standby_UnMute:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_UNMUTE);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Sub_State,dev_id,(uint8)Standby_Playing_Check,(uint8)Standby_Err,AMPUmute_Callback);
			break;
        case Standby_Playing_Check:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_DEVICESTATE);
            Standby_Get_StateCallback(dev_id);
            break;
        case Standby_Done:
            (void)AMP8532_SelfCheckStsSet(dev_id,AMPSELFCHECKSTS_DONE);
            AMP_Startup_StateTransfer(dev_id, (uint8)Startup_Done, 0u);
			(void)amp_warn("AMP%d Startup Standby Finished",dev_id+1);
			(void)amp_warn("AMP%d Init Success!",dev_id+1);
            break;        
        case Standby_Err:
            AMPStartup_Retry[dev_id]++;
            if (AMP8532_START_RETRY_COUNTER <= AMPStartup_Retry[dev_id])
            {
                AMP_State_Data[dev_id].Major_State = (uint8)Startup_Err;
				(void)amp_warn("AMP%d Startup Standby failed",dev_id+1);
            }
            else
            {
                AMP_State_Data[dev_id].Sub_State = (uint8)Standby_DCLoad_Cfg;
            }
            break;
        default:
			/* do nothing */
            break;
    }
}

/***********************************************************************
 * @brief       : Wait 150ms before put on eanble pin.
 				  after LC power on, wait LC's IIC ready for 20ms
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_BootEnableLogic(uint8 dev_id)
{
	if( STD_LOW == AMP8532_Get_Pin(dev_id, AMPPIN_ENABLE) )
	{
	    if(TRUE == AMP_TimerIsStarted(dev_id))
	    {
	        if(TRUE == AMP_TimerIsElasped(dev_id,AMPTIMER_PINENABLEWAIT))
	        {
	            AMP_TimerEnd(dev_id);
	            AMP8532_Set_Pin(dev_id, AMPPIN_ENABLE, STD_HIGH);
	        }
	    }
	    else
	    {
	        AMP_TimerStart(dev_id);
	    }
	}
	else
	{
		if(TRUE == AMP_TimerIsStarted(dev_id))
		{
			if(TRUE == AMP_TimerIsElasped(dev_id,AMPTIMER_BOOTENABLEWAIT))
			{
				AMP_TimerEnd(dev_id);
				AMP_State_Data[dev_id].Sub_State = (uint8)Boot_Get_ID;
			}
		}
		else
		{
			AMP_TimerStart(dev_id);
		}
	}
}

/***********************************************************************
 * @brief       : AMP starup state sync, two amp all enter next state, start next state
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_Startup_StateTransfer(uint8 ID, uint8 Major, uint8 Sub)
{
    AMP_State_Data[ID].Major_State = Major;
    AMP_State_Data[ID].Sub_State = Sub;
    AMPStartup_Retry[ID] = 0u;
}

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

