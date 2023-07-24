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
 * @file:      Ipc_STB_LoadTest.c
 * @author:    Nobo
 * @date:      2020-9-18
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-18
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "VariantCfg.h"
#ifdef PLATFORM_OF_STB_IPC_USED

/**
 ********************************************************************************************************************
 * @file:      IPC_STB_LoadTest.c
 * @Folder:    
 * @author:    Nobo
 * @date:      2020-9-18 
 * @brief:   
 ********************************************************************************************************************
 * @attention: 
 *    1. date    : 2020-9-18
 *       author  : Nobo
 *       reviser : create
 ********************************************************************************************************************
 *  @copyright
 *  COPYRIGHT
 *  -----------------------------------------------------------------------------------------------------------------
 * 
 *  This software is copyright protected and proprietary to Noch Automotive Technology(Shanghai) Co. , Ltd.
 *  Noch Automotive Technology(Shanghai) Co. , Ltd. grants to you only those rights as set out in the license 
 *  conditions.All other rights remain with Noch Automotive Technology(Shanghai) Co. , Ltd.
 * 
 ********************************************************************************************************************
 */

#include "IPC_STB_LoadTest.h"

#ifdef IPC_STB_DEBUG_OPEN

#include "IPC_STB_If.h"

uint32 IPC_STB_DEBUG_Time= 0;
uint16 IPC_STB_Debug_TimeoutCnt = 0;
uint32 IPC_STB_Debug_MaxTimeoutTime = 0;
uint32 IPC_STB_Debug_RxDataSize=0;
uint32 IPC_STB_Debug_TxDataSize=0;
uint32 IPC_STB_TransportBufferMaxBuffer = 0;
uint32 IPC_STB_ReceiverBufferMaxBuffer = 0;

uint32 IPC_STB_Debug_PackCnt=0;
uint32 IPC_STB_DataSwap_TotalTime = 0;


IPC_STB_RocarData_t IPC_STB_RocarBuffer[IPC_STB_ROCAR_SIZE] = {0};
uint8 IPC_STB_RocarCnt =0;

extern void TM_TimerElapsed(uint32 * StartStamp, uint32 * TimeElapsed);
extern void  TM_TimerStartStamp(uint32 * StartStamp);

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_STB_CheckRequestTransport(void)
{
    TM_TimerStartStamp(&IPC_STB_DEBUG_Time);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_STB_CheckSPITransportEnd(void)
{
    uint32 time=0;
    TM_TimerElapsed(&IPC_STB_DEBUG_Time,&time);
    if ((time>IPC_STB_TIME_OUT_DEF)&&(IPC_STB_GetIPC_STBStateType() == IPC_STB_CONN_READY))
    {
        IPC_STB_Debug_TimeoutCnt++;
		IPC_STB_DataSwap_TotalTime += time;
        if (time > IPC_STB_Debug_MaxTimeoutTime)
        {
            IPC_STB_Debug_MaxTimeoutTime = time;
        }
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_STB_CheckSendData(const uint8 * data,uint16 len)
{
	IPC_STB_RocarCnt = IPC_STB_RocarCnt%IPC_STB_ROCAR_SIZE;
	//
    IPC_STB_RocarBuffer[IPC_STB_RocarCnt].GId = data[0];
    IPC_STB_RocarBuffer[IPC_STB_RocarCnt].MId = data[1];
    IPC_STB_RocarBuffer[IPC_STB_RocarCnt].SId = data[2];
    IPC_STB_RocarBuffer[IPC_STB_RocarCnt].len = len;
    IPC_STB_RocarCnt++;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_STB_CheckTransport(uint16 len)
{
    IPC_STB_Debug_PackCnt++;
    if (IPC_STB_TransportBufferMaxBuffer < len)
    {
        IPC_STB_TransportBufferMaxBuffer = len; 
    }
    
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_STB_CheckReceiver(uint16 len)
{
    if (IPC_STB_ReceiverBufferMaxBuffer < len)
    {
        IPC_STB_ReceiverBufferMaxBuffer = len; 
    }

}


void IPC_STB_BuffLoading_Monitor(void)
{
	static float32 f32IPCHighPriLoadFactor_Cur = 0.0f,f32IPCHighPriLoadFactor_Pre=0.0f,f32IPCHighPriLoadFactor_MAX=-0.1f;
	static float32 f32IPCLowPriLoadFactor_Cur = 0.0f,f32IPCLowPriLoadFactor_Pre=0.0f,f32IPCLowPriLoadFactor_MAX=-0.1f;
	float32 f32HighMonitorDiff = 0.1f,f32LowMonitorDiff = 0.2f;

	//
	f32IPCHighPriLoadFactor_Cur = (float32)IPC_STB_TxDataHighPriLen/(float32)IPC_STB_DATA_HIGH_PRI_LENGTH;
	f32IPCLowPriLoadFactor_Cur = (float32)IPC_STB_TxDataLowPriLen/(float32)IPC_STB_DATA_LOW_PRI_LENGTH;

	//
	if(((f32IPCHighPriLoadFactor_Cur - f32IPCHighPriLoadFactor_Pre) > f32HighMonitorDiff)
		|| ((f32IPCHighPriLoadFactor_Cur - f32IPCHighPriLoadFactor_Pre) < -f32HighMonitorDiff))
	{
		if(f32IPCHighPriLoadFactor_Cur >= f32IPCHighPriLoadFactor_MAX)
		{
			ipc_info("[IPC-STB-I]:high pri buff loading pre = %.3f,cur = %.3f,max = %.3f,cur len = %d",f32IPCHighPriLoadFactor_Pre,f32IPCHighPriLoadFactor_Cur,f32IPCHighPriLoadFactor_MAX,IPC_STB_TxDataHighPriLen);
			f32IPCHighPriLoadFactor_MAX = f32IPCHighPriLoadFactor_Cur;
		}
		f32IPCHighPriLoadFactor_Pre = f32IPCHighPriLoadFactor_Cur;
	}

	//
	if(((f32IPCLowPriLoadFactor_Cur - f32IPCLowPriLoadFactor_Pre) > f32LowMonitorDiff)
		|| ((f32IPCLowPriLoadFactor_Cur - f32IPCLowPriLoadFactor_Pre) < -f32LowMonitorDiff))
	{
		if(f32IPCLowPriLoadFactor_Cur >= f32IPCLowPriLoadFactor_MAX)
		{
			ipc_info("[IPC-STB-I]:low pri buff loading pre = %.3f,cur = %.3f,max = %.3f,cur len = %d",f32IPCLowPriLoadFactor_Pre,f32IPCLowPriLoadFactor_Cur,f32IPCLowPriLoadFactor_MAX,IPC_STB_TxDataLowPriLen);
			f32IPCLowPriLoadFactor_MAX = f32IPCLowPriLoadFactor_Cur;
		}
		f32IPCLowPriLoadFactor_Pre = f32IPCLowPriLoadFactor_Cur;
	}
}
//
void IPC_STB_BusLoading_Monitor(void)
{
	static boolean bSysRunningStart = FALSE;
	static uint32 ipcRunningTime = 0 , ipcRunningElapsedTime = 0;
	static uint16 cnt = 0 ;
	static float32 f32IpcLoadingPer = 0.0f ,f32IpcLoadingCur = 0.0f,f32IpcLoadingMax = 0.0f;
	float32 f32IpcLoadingMonitorDiff = 0.1f;
	//
	if(IPC_STB_GetIPC_STBStateType() == IPC_STB_CONN_READY)
	{
		if(FALSE == bSysRunningStart)
		{
			bSysRunningStart = TRUE;
			cnt = 0;
			//
			IPC_STB_DataSwap_TotalTime = 0 ;
			TM_TimerStartStamp(&ipcRunningTime);
		}
		else
		{	
			if(cnt++ >= IPC_STB_BUS_LOADING_MONITOR_CYCLE)
			{
				cnt = 0;
				bSysRunningStart = FALSE;
				//
				TM_TimerElapsed(&ipcRunningTime,&ipcRunningElapsedTime);
				f32IpcLoadingCur = 0 ;
				f32IpcLoadingCur = IPC_STB_DataSwap_TotalTime;
				f32IpcLoadingCur /= ipcRunningElapsedTime;
				//ipc_info("[IPC-I]:Data SwapTime = %d , Sys RunTime = %d , IPC Loading = %f",IPC_DataSwap_TotalTime,ipcRunningElapsedTime,f32IpcLoadingCur);

				//
				if(((f32IpcLoadingCur - f32IpcLoadingPer) > f32IpcLoadingMonitorDiff) ||
					((f32IpcLoadingCur - f32IpcLoadingPer) < -f32IpcLoadingMonitorDiff))
				{
					if(f32IpcLoadingMax < f32IpcLoadingCur)
					{
						ipc_info("[IPC-STB-I]:STB IPC Bus Loading Was Pre = %.3f, Cur = %.3f, Max = %.3f",f32IpcLoadingPer,f32IpcLoadingCur,f32IpcLoadingMax);
						f32IpcLoadingMax = f32IpcLoadingCur;
					}
					f32IpcLoadingPer = f32IpcLoadingCur;
				}
			}
		}
	}
}


void IPC_STB_BusMonitor_Mainfunction(void)
{
	IPC_STB_BuffLoading_Monitor();
	IPC_STB_BusLoading_Monitor();
}


#endif

#endif
