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
 * @file:      Ipc_LoadTest.c
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

#include "Ipc_LoadTest.h"
#include "Std_Types.h"
#include "Ipc_If.h"
#include "Ipc_Com.h"

#ifdef IPC_DEBUG_OPEN

#pragma ghs section bss = ".IPC_SHARE_NOINIT_DATA" 
#pragma ghs section data = ".IPC_SHARE_INIT_DATA" 

uint32 IPC_DEBUG_Time= 0;
uint16 IPC_Debug_TimeoutCnt = 0;
uint32 IPC_Debug_MaxTimeoutTime = 0;
//uint32 IPC_Debug_RxDataSize=0;
//uint32 IPC_Debug_TxDataSize=0;
uint32 IPC_TransportBufferMaxBuffer = 0;
uint32 IPC_ReceiverBufferMaxBuffer = 0;

uint32 IPC_Debug_PackCnt=0;

uint32 IPC_DataSwap_TotalTime = 0;


IPC_RocarData_t IPC_RocarBuffer[IPC_ROCAR_SIZE] = {0};
uint8 IPC_RocarCnt =0;

#pragma ghs section bss = default 
#pragma ghs section data = default 

extern void TM_TimerElapsed(uint32 * StartStamp, uint32 * TimeElapsed);
extern void  TM_TimerStartStamp(uint32 * StartStamp);

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_CheckRequestTransport(void)
{
    TM_TimerStartStamp(&IPC_DEBUG_Time);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_CheckSPITransportEnd(void)
{
    uint32 time=0;
    TM_TimerElapsed(&IPC_DEBUG_Time,&time);
	IPC_DataSwap_TotalTime += time;
    if ((time>IPC_TIME_OUT_DEF)&&(IPC_GetIPCStateType() == IPC_CONN_READY))
    {
        IPC_Debug_TimeoutCnt++;
        if (time > IPC_Debug_MaxTimeoutTime)
        {
            IPC_Debug_MaxTimeoutTime = time;
        }
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_CheckSendData(const uint8 * data,uint16 len)
{
	IPC_RocarCnt = IPC_RocarCnt%IPC_ROCAR_SIZE;
	//
    IPC_RocarBuffer[IPC_RocarCnt].GId = data[0];
    IPC_RocarBuffer[IPC_RocarCnt].MId = data[1];
    IPC_RocarBuffer[IPC_RocarCnt].SId = data[2];
    IPC_RocarBuffer[IPC_RocarCnt].len = len;
    IPC_RocarCnt++;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_CheckTransport(uint16 len)
{
    IPC_Debug_PackCnt++;
    if (IPC_TransportBufferMaxBuffer < len)
    {
        IPC_TransportBufferMaxBuffer = len; 
    }
    
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void TST_IPC_CheckReceiver(uint16 len)
{
    if (IPC_ReceiverBufferMaxBuffer < len)
    {
        IPC_ReceiverBufferMaxBuffer = len; 
    }

}
//
void IPC_BuffLoading_Monitor(void)
{
	static float32 f32IPCHighPriLoadFactor_Cur = 0.0f,f32IPCHighPriLoadFactor_Pre=0.0f,f32IPCHighPriLoadFactor_MAX=-0.1f;
	static float32 f32IPCLowPriLoadFactor_Cur = 0.0f,f32IPCLowPriLoadFactor_Pre=0.0f,f32IPCLowPriLoadFactor_MAX=-0.1f;
	float32 f32HighMonitorDiff = 0.1f,f32LowMonitorDiff = 0.2f;

	//
	f32IPCHighPriLoadFactor_Cur = (float32)ipc_TxDataHighPriLen/(float32)IPC_DATA_HIGH_PRI_LENGTH;
	f32IPCLowPriLoadFactor_Cur = (float32)ipc_TxDataLowPriLen/(float32)IPC_DATA_LOW_PRI_LENGTH;

	//
	if(((f32IPCHighPriLoadFactor_Cur - f32IPCHighPriLoadFactor_Pre) > f32HighMonitorDiff)
		|| ((f32IPCHighPriLoadFactor_Cur - f32IPCHighPriLoadFactor_Pre) < -f32HighMonitorDiff))
	{
		if(f32IPCHighPriLoadFactor_Cur >= f32IPCHighPriLoadFactor_MAX)
		{
			ipc_info("[IPC-I]:high pri buff loading pre = %.3f,cur = %.3f,max = %.3f,cur len = %d",f32IPCHighPriLoadFactor_Pre,f32IPCHighPriLoadFactor_Cur,f32IPCHighPriLoadFactor_MAX,ipc_TxDataHighPriLen);
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
			ipc_info("[IPC-I]:low pri buff loading pre = %.3f,cur = %.3f,max = %.3f,cur len = %d",f32IPCLowPriLoadFactor_Pre,f32IPCLowPriLoadFactor_Cur,f32IPCLowPriLoadFactor_MAX,ipc_TxDataLowPriLen);
			f32IPCLowPriLoadFactor_MAX = f32IPCLowPriLoadFactor_Cur;
		}
		f32IPCLowPriLoadFactor_Pre = f32IPCLowPriLoadFactor_Cur;
	}
}
//
void IPC_BusLoading_Monitor(void)
{
	static boolean bSysRunningStart = FALSE;
	static uint32 ipcRunningTime = 0 , ipcRunningElapsedTime = 0;
	static uint16 cnt = 0 ;
	static float32 f32IpcLoadingPer = 0.0f ,f32IpcLoadingCur = 0.0f,f32IpcLoadingMax = 0.0f;
	float32 f32IpcLoadingMonitorDiff = 0.1f;
	//
	if(IPC_GetIPCStateType() == IPC_CONN_READY)
	{
		if(FALSE == bSysRunningStart)
		{
			bSysRunningStart = TRUE;
			cnt = 0;
			//
			IPC_DataSwap_TotalTime = 0 ;
			TM_TimerStartStamp(&ipcRunningTime);
		}
		else
		{	
			if(cnt++ >= IPC_BUS_LOADING_MONITOR_CYCLE)
			{
				cnt = 0;
				bSysRunningStart = FALSE;
				//
				TM_TimerElapsed(&ipcRunningTime,&ipcRunningElapsedTime);
				f32IpcLoadingCur = 0 ;
				f32IpcLoadingCur = IPC_DataSwap_TotalTime;
				f32IpcLoadingCur /= ipcRunningElapsedTime;
				//ipc_info("[IPC-I]:Data SwapTime = %d , Sys RunTime = %d , IPC Loading = %f",IPC_DataSwap_TotalTime,ipcRunningElapsedTime,f32IpcLoadingCur);

				//
				if(((f32IpcLoadingCur - f32IpcLoadingPer) > f32IpcLoadingMonitorDiff) ||
					((f32IpcLoadingCur - f32IpcLoadingPer) < -f32IpcLoadingMonitorDiff))
				{
					if(f32IpcLoadingMax < f32IpcLoadingCur)
					{
						ipc_info("[IPC-I]:IPC Bus Loading Was Pre = %.3f, Cur = %.3f, Max = %.3f",f32IpcLoadingPer,f32IpcLoadingCur,f32IpcLoadingMax);
						f32IpcLoadingMax = f32IpcLoadingCur;
					}
					f32IpcLoadingPer = f32IpcLoadingCur;
				}
			}
		}
	}
}

void IPC_BusMonitor_Mainfunction(void)
{
	IPC_BuffLoading_Monitor();
	IPC_BusLoading_Monitor();
}

#endif
