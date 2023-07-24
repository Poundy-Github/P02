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
 * @file:      AMP_ShutDown.c
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

#include "AMP_ShutDown.h"
#include "AMP_Common.h"
#include "string.h"
#include "AMP_Cfg.h"
#include "logger.h"
#include "Logger_Cfg.h"
#include "AMP.h"


extern s_AMP_State_Type AMP_State_Data[DEVICE_NUM];
static uint8 AMPShutDownRetryCunt[DEVICE_NUM];

#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

static Std_ReturnType AMPShutDown_WaitCallback(uint8 dev_id);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_ShutDownInit(void)
{
    (void)memset(AMPShutDownRetryCunt,0,sizeof(AMPShutDownRetryCunt));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType AMPShutDown_WaitCallback(uint8 dev_id)
{
    Std_ReturnType ret = E_NOT_OK;

    if(TRUE == AMP_TimerIsStarted(dev_id))
    {
        if(TRUE == AMP_TimerIsElasped(dev_id,AMPTIMER_CHANNELDIASBLE))
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
void AMP_Emergency_Shutdown(void)
{
    if(VCONFIG_BOTHAMP == AMPDevVCfg)
    {
        AMP_EmergencyShutdownOneDevice(DEVICE_AMP1);
        AMP_EmergencyShutdownOneDevice(DEVICE_AMP2);
    }
    else if(VCONFIG_BOTHAMP > AMPDevVCfg)
    {
        AMP_EmergencyShutdownOneDevice(AMPDevVCfg);
    }
	else
	{
		/* do nothing */
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_EmergencyShutdownOneDevice(uint8 dev_id)
{
    AMP8532_Set_Pin(dev_id, AMPPIN_MUTE_N, STD_LOW);
    AMP8532_Set_Pin(dev_id, AMPPIN_ENABLE, STD_LOW);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void PowerCtrl_AMPShutDown(void)
{
    if(VCONFIG_BOTHAMP == AMPDevVCfg)
    {
        AMPSet_NextDeviceState(DEVICE_AMP1 ,AMP_SHUTDOWN);
        AMPSet_NextDeviceState(DEVICE_AMP2 ,AMP_SHUTDOWN);
    } 
    else if(VCONFIG_BOTHAMP > AMPDevVCfg)
    {
        AMPSet_NextDeviceState(AMPDevVCfg, AMP_SHUTDOWN);
    }
	else
	{
		/* do nothing */
	}

    (void)amp_info("Power Request AMP ShutDown");
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Std_ReturnType AMP_ShutDownMainLogic(uint8 dev_id)
{
    switch( (Shutdown_State_t)AMP_State_Data[dev_id].Major_State )
    {
        case Shutdown_SW_Mute:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_MUTE);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Major_State,dev_id,(uint8)Shutdown_Channel_Disable,(uint8)Shutdown_Err,NULL);
            break;
        case Shutdown_Channel_Disable:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_DISABLE);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Major_State,dev_id,(uint8)Shutdown_DisalbeClock,(uint8)Shutdown_Err,AMPShutDown_WaitCallback);
            break;
        case Shutdown_DisalbeClock:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CLOCKSTATE);
            AMP_StateIICCallback(&AMP_State_Data[dev_id].Major_State,dev_id,(uint8)Shutdown_Done,(uint8)Shutdown_Err,AMPShutDown_WaitCallback);
            break;
        case Shutdown_Done:
        	AMP8532_Set_Pin(dev_id, AMPPIN_ENABLE, STD_LOW);
        	AMPSet_NextDeviceState(dev_id, AMP_OFF);
			(void)amp_info("AMP%d ShutDown Success",dev_id+1);
            break;
        case Shutdown_Err:
            AMPShutDownRetryCunt[dev_id]++;
            if (AMPSHUTDOWN_RETRYMAX <= AMPShutDownRetryCunt[dev_id])
            {
                AMP8532_Set_Pin(dev_id, AMPPIN_MUTE_N, STD_LOW);
                AMP8532_Set_Pin(dev_id, AMPPIN_ENABLE, STD_LOW);
				AMPSet_NextDeviceState(dev_id, AMP_OFF);
				(void)amp_info("AMP%d ShutDown failed",dev_id+1);
            }
            else 
            {
                AMP_State_Data[dev_id].Major_State = (uint8)Shutdown_SW_Mute;
            }
            break;
        default:
			/* do nothing */
            break;
    }
    return E_OK;
}


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

