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

/**********************************************************************************************************
*File Name   : SWC_AL_Core.c                                                                              *
*                                                                                                         *
*Description : Ambient Light core logic process                                          				  *
*                                                                                                         *
*Author      :                                                                                    	  	  *
*                                                                                                         *
*Platform    : MICROSAR OS                                                    						      *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/


#include "Compiler.h"
#include "Platform_Types.h"
#include "stddef.h" /* NULL */
#include <string.h> /* memset */
#include "Rte_Common_Gateway.h"

#include "SWC_AL_Config.h"
#include "SWC_AL_Core.h"
#include "SWC_AL_Process.h"
#include "SWC_AL_Interface.h"
#include "SWC_AL_Adapt.h"

#define Common_GateWay_START_SEC_CONST_UNSPECIFIED
#include  "Common_Gateway_MemMap.h"

static const AL_FuncAttribute_t funcAttributeTalbe[LINKAGE_FUNCTION_NUMBER] = DEFINE_FUNC_ATTRIBUTE;
static const AL_EventAttribute_t eventAttributeTalbe[LINKAGE_EVENT_NUMBER] = DEFINE_EVENT_ATTRIBUTE;

#define Common_GateWay_STOP_SEC_CONST_UNSPECIFIED
#include  "Common_Gateway_MemMap.h"

#define Common_GateWay_START_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_GateWay_MemMap.h"

static uint32 ALCM_WakeupWaitFlg = 0;

#define Common_GateWay_STOP_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_GateWay_MemMap.h"

#define Common_GateWay_START_SEC_VAR_NOINIT_UNSPECIFIED
#include  "Common_Gateway_MemMap.h"

AL_EventRunningObject_t eventRunningObj;

#define Common_GateWay_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include  "Common_Gateway_MemMap.h"


#define Common_GateWay_START_SEC_CODE
#include  "Common_Gateway_MemMap.h"

static boolean ALCM_WaitWakeupFunc(void)
{
	boolean ret = FALSE;
	if(ALCM_WAKEUPWAIT_TIME < ALCM_WakeupWaitFlg)
	{
		ret = TRUE;
	}
	else
	{
		ALCM_WakeupWaitFlg++;
	}
	return ret;
}

static void ALCM_RemoveInterruptedEvent(AL_EventRunningObject_t *runObject)
{
	const AL_EventAttribute_t * const eventAttribute = runObject->eventAttributePtr;
	const AL_FuncAttribute_t * const funcAttribute = runObject->funcAttributePtr;
	uint8 index = 0;
	uint8 eventId = 0;
	uint8 eventSlotNumber = 0;

	if ((runObject->aboutToRunFunc < runObject->runningFunc)
		&& (runObject->runningFunc != LINKAGE_FUNCTION_ID_INVALID))
	{
		eventSlotNumber = funcAttribute[runObject->runningFunc].eventSlotNumber;

		for (index = 0; index < eventSlotNumber; index++)
		{
			eventId = runObject->runningEventId[index];
			if (eventId != LINKAGE_EVENT_ID_INVALID)
			{
				if((eventAttribute[eventId].eventClearOption & EVENT_CLERA_BY_INTERRUPT) == EVENT_CLERA_BY_INTERRUPT)
				{
					ALCM_EventClr(eventId);
				}
			}
		}
	}
}

static void ALCM_RemoveNotRunningEvent(AL_EventRunningObject_t *runObject)
{
	const AL_EventAttribute_t * const eventAttribute = runObject->eventAttributePtr;
	uint8 index = 0;

	for (index = 0; index < LINKAGE_EVENT_NUMBER; index++)
	{
		if ((eventAttribute[index].priority > runObject->aboutToRunFunc)
			&& ((eventAttribute[index].eventClearOption & EVENT_CLERA_BY_NOTEXECUTE) == EVENT_CLERA_BY_NOTEXECUTE))
		{
			ALCM_EventClr(index);
		}
	}
}

static void ALCM_RemoveTimeoutEvent(AL_EventRunningObject_t *runObject)
{
	const AL_EventAttribute_t * const eventAttribute = runObject->eventAttributePtr;
	const AL_FuncAttribute_t * const funcAttribute = runObject->funcAttributePtr;
	uint8 index = 0;
	uint8 eventSlotNumber = 0;
	uint8 eventId = 0;

	if (runObject->runningFunc != LINKAGE_FUNCTION_ID_INVALID)
	{
		eventSlotNumber = funcAttribute[runObject->runningFunc].eventSlotNumber;

		for (index = 0; index < eventSlotNumber; index++)
		{
			eventId = runObject->runningEventId[index];

			if (eventId != LINKAGE_EVENT_ID_INVALID)
			{
				if ((eventAttribute[eventId].eventClearOption & EVENT_CLERA_BY_TIMEOUT) == EVENT_CLERA_BY_TIMEOUT)
				{
					if (runObject->runningEventTimeRemain[index] != 0)
					{
						runObject->runningEventTimeRemain[index]--;
					}

					if (runObject->runningEventTimeRemain[index] == 0)
					{
						ALCM_EventClr(runObject->runningEventId[index]);
					}
				}
			}
		}
	}
}

static void ALCM_GetAboutToRunFunc(AL_EventRunningObject_t *runObject)
{
	const AL_EventAttribute_t * const eventAttribute = runObject->eventAttributePtr;
	uint8 index = 0;
	uint8 slotIndex = 0;

	runObject->aboutToRunFunc = LINKAGE_FUNCTION_ID_INVALID;
	for (index = 0; index < EVENT_IN_FUN_SLOT_NUMBER; index++)
	{
		runObject->aboutToRunEventId[index] = LINKAGE_EVENT_ID_INVALID;
	}

	for (index = 0; index < LINKAGE_EVENT_NUMBER; index++)
	{
		if (runObject->eventTable[eventAttribute[index].priority][eventAttribute[index].eventIndex] != LINKAGE_FUNCTION_ID_INVALID)
		{
			runObject->aboutToRunFunc = eventAttribute[index].priority;
			for (slotIndex = 0; slotIndex <EVENT_IN_FUN_SLOT_NUMBER; slotIndex++)
			{
				runObject->aboutToRunEventId[slotIndex] = runObject->eventTable[runObject->aboutToRunFunc][slotIndex];
			}
			break;
		}
	}
}

static void ALCM_RunningObjectInit(AL_EventRunningObject_t *runObject)
{
	uint8 index = 0;
	(void)memset(runObject, 0, sizeof(AL_EventRunningObject_t));
	(void)memset(&runObject->eventTable[0][0], (sint32)LINKAGE_EVENT_ID_INVALID, sizeof(runObject->eventTable));

	runObject->funcAttributePtr = &funcAttributeTalbe[0];
	runObject->eventAttributePtr = &eventAttributeTalbe[0];

	runObject->aboutToRunFunc = LINKAGE_FUNCTION_ID_INVALID;
	runObject->runningFunc = LINKAGE_FUNCTION_ID_INVALID;

	runObject->PartitionSwt = SWITCH_OFF;	// 初始化清除该标志，后续重新获取
	runObject->MasterSwt = SWITCH_OFF;		// 初始化清除该标志，后续重新获取
	runObject->MLPConfig = 0;				// 初始化清除该标志，后续重新获取

	/* 初始化CAN外发信号列表 */
	ALCM_OutputValueInit(&runObject->runningSignalValue);
	/* 获取配置字 */
	ALCM_GetConfigProcess(runObject);

	for (index = 0; index < EVENT_IN_FUN_SLOT_NUMBER; index++)
	{
		runObject->aboutToRunEventId[index] = LINKAGE_EVENT_ID_INVALID;
		runObject->runningEventId[index] = LINKAGE_EVENT_ID_INVALID;
	}
}


static void ALCM_EventArbitration(AL_EventRunningObject_t *runObject)
{
	ALCM_RemoveTimeoutEvent(runObject);
	ALCM_GetAboutToRunFunc(runObject);
	ALCM_RemoveInterruptedEvent(runObject);
	ALCM_RemoveNotRunningEvent(runObject);
}

static void ALCM_SetRunningFuncAndEvent(AL_EventRunningObject_t *runObject)
{
	uint8 index = 0;

	runObject->runningFunc = runObject->aboutToRunFunc;
	runObject->aboutToRunFunc = LINKAGE_FUNCTION_ID_INVALID;

	for (index = 0; index < EVENT_IN_FUN_SLOT_NUMBER; index++)
	{
		runObject->runningEventId[index] = runObject->aboutToRunEventId[index];
		runObject->aboutToRunEventId[index] = LINKAGE_EVENT_ID_INVALID;
	}
}

static void ALCM_CanSignalSet(AL_EventRunningObject_t *runObject)
{
	const AL_FuncAttribute_t * const funcAttribute = runObject->funcAttributePtr;

	sint32 ret = 0;

	if (runObject->aboutToRunFunc != runObject->runningFunc)
	{
		if (runObject->aboutToRunFunc == LINKAGE_FUNCTION_ID_INVALID)
		{
			AL_OutputValueGet_NONE((uint8*)runObject);
		}
		else
		{
			funcAttribute[runObject->aboutToRunFunc].funcCanSignalGet((uint8*)runObject);
		}
		ALCM_SetRunningFuncAndEvent(runObject);
	}
	else
	{
		if (runObject->aboutToRunFunc != LINKAGE_FUNCTION_ID_INVALID)
		{
			ret = memcmp(&runObject->aboutToRunEventId[0], &runObject->runningEventId[0], EVENT_IN_FUN_SLOT_NUMBER);

			if (ret != 0)
			{
				funcAttribute[runObject->aboutToRunFunc].funcCanSignalGet((uint8*)runObject);
				ALCM_SetRunningFuncAndEvent(runObject);
			}
		}
	}
}


static void ALCM_InputProcess(AL_EventRunningObject_t *runObject)
{
	const AL_FuncAttribute_t * const funcAttribute = runObject->funcAttributePtr;
	uint8 index = 0;

	ALCM_AppCommonProcess(runObject);

	for (index = 0; index < LINKAGE_FUNCTION_NUMBER; index++)
	{
		funcAttribute[index].funcInputProcess((uint8*)runObject);
	}
}

static void ALCM_TransExitNormal(AL_EventRunningObject_t *runObject)
{
	AL_TransExitNormal(runObject);
	ALCM_RunningObjectInit(runObject);
}

static void ALCM_TransIntoNormal(AL_EventRunningObject_t *runObject)
{
	AL_TransIntoNormal(runObject);
	ALCM_RunningObjectInit(runObject);
}

static boolean ALCM_IsFunctionEnable(AL_EventRunningObject_t *runObject)
{
	boolean ret = FALSE;

	if ((runObject->powerModeStatus == ALCM_POWER_MODE_RUN)
		&& (runObject->MasterSwt == SWITCH_ON)
		&& (runObject->PartitionSwt == SWITCH_ON)
		&& (runObject->MLPConfig == (uint8)1)
		&& (runObject->AlcmConfig.Cfg_NvmInitflag != (uint8)0))
	{
		ret = TRUE;
	}

	return ret;
}

static void ALCM_SwitchCheck(AL_EventRunningObject_t *runObject)
{
	uint8 PartitionSwt = SWITCH_OFF;
	uint8 MasterSwt = SWITCH_OFF;
	uint8 MLPConfig = 0;

	MLPConfig = runObject->AlcmConfig.Cfg_MLPConfig;

	if ((uint32)ALCM_POWER_MODE_RUN == runObject->powerModeStatus)
	{
		FALCM_Adapt_GetTxSig_PartitionSwt(&PartitionSwt);
		FALCM_Adapt_GetTxSig_MasterSwt(&MasterSwt);
#if ALCM_DEBUG_EN
		PartitionSwt = SWITCH_ON;
		MasterSwt = SWITCH_ON;
		MLPConfig = 1;
#endif
		if((uint8)1 == MLPConfig)
		{
			if ((MasterSwt == SWITCH_ON) && (PartitionSwt == SWITCH_ON))
			{
				if ((SWITCH_OFF == runObject->MasterSwt) \
					|| (SWITCH_OFF == runObject->PartitionSwt))
				{
					ALCM_TransIntoNormal(runObject);
				}
			}
			else
			{
				if ((SWITCH_ON == runObject->MasterSwt) \
					&& (SWITCH_ON == runObject->PartitionSwt))
				{
					ALCM_TransExitNormal(runObject);
				}
			}
		}
		else
		{
			if((uint8)1 == runObject->MLPConfig)
			{
				ALCM_TransExitNormal(runObject);
			}
		}

		if ((MasterSwt != runObject->MasterSwt) \
			|| (PartitionSwt != runObject->PartitionSwt))
		{
			(void)SWC_IPC_PRINT_DEBUG("ALCM: [MSW %d->%d, PSW %d->%d]", \
				runObject->MasterSwt, MasterSwt, \
				runObject->PartitionSwt, PartitionSwt);
		}

		runObject->PartitionSwt = PartitionSwt;
		runObject->MasterSwt = MasterSwt;
		runObject->MLPConfig = MLPConfig;
	}
	else
	{
		/* do nothing */
	}
}

static void ALCM_PowerModeCheck(AL_EventRunningObject_t *runObject)
{
    uint32 u32PowerModeStatus = 0;
	uint32 u32LastPowerModeStatus = runObject->powerModeStatus;
	SystemState_RecordType *stSystemState = NULL;

	stSystemState = Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut();

	if((stSystemState->s_PowerVoltage.state == VOLTAGE_OUT_NORMAL) || (stSystemState->s_PowerVoltage.state == VOLTAGE_OUT_LOWALARM))
	{
		if(stSystemState->ClusterState == SYSTEMSTATE_Cluster_STANDBY)
		{
			u32PowerModeStatus = (uint32)ALCM_POWER_MODE_OFF;
		}
		else if(stSystemState->ClusterState == SYSTEMSTATE_Cluster_ON)
		{
			u32PowerModeStatus = (uint32)ALCM_POWER_MODE_RUN;
		}
		else if((stSystemState->ClusterState == SYSTEMSTATE_Cluster_OFF)\
			|| (stSystemState->ClusterState == SYSTEMSTATE_Cluster_SHUTDOWN))
		{
			u32PowerModeStatus = (uint32)ALCM_POWER_MODE_SLEEP;
		}
		else
		{
			/*Do nothing but avoid QAC*/
		}
	}
	else
	{
		u32PowerModeStatus = (uint32)ALCM_POWER_MODE_ABNORMAL_VOLTAGE;
	}

	if((u32PowerModeStatus == ALCM_POWER_MODE_ABNORMAL_VOLTAGE) && (u32LastPowerModeStatus != ALCM_POWER_MODE_ABNORMAL_VOLTAGE))
	{
		//ALCM_TransExitNormal(runObject);
	}
	else
	{
		if((u32PowerModeStatus == ALCM_POWER_MODE_RUN) && (u32LastPowerModeStatus != ALCM_POWER_MODE_RUN))
		{
			//ALCM_TransIntoNormal(runObject);
		}
		else if(((u32PowerModeStatus == ALCM_POWER_MODE_OFF) && (u32LastPowerModeStatus != ALCM_POWER_MODE_OFF)))
		{
			ALCM_TransExitNormal(runObject);
		}
		else
		{
			/*Do nothing but avoid QAC*/
		}
	}

	runObject->powerModeStatus = u32PowerModeStatus;

}

void ALCM_API_vColdInit(void)
{
	ALCM_WakeupWaitFlg = 0;
	ALCM_RunningObjectInit(&eventRunningObj);
}

void ALCM_API_vTimeTask(void)
{
	AL_EventRunningObject_t *runObject = &eventRunningObj;
	boolean WkUpFlag = FALSE;

	ALCM_PowerModeCheck(runObject);
	ALCM_SwitchCheck(runObject);
	WkUpFlag = ALCM_WaitWakeupFunc();

	if (ALCM_IsFunctionEnable(runObject) && (TRUE == WkUpFlag))
	{
		ALCM_InputProcess(runObject);

		ALCM_EventArbitration(runObject);

		ALCM_CanSignalSet(runObject);
	}
}


#define Common_GateWay_STOP_SEC_CODE
#include  "Common_Gateway_MemMap.h"


