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

#include "Compiler.h"
#include "Platform_Types.h"
#include <string.h> /* memset */

#include "SWC_AL_Config.h"
#include "SWC_AL_Core.h"
#include "SWC_AL_Interface.h"
#include "SWC_AL_Adapt.h"


#define Common_GateWay_START_SEC_CONST_UNSPECIFIED
#include  "Common_GateWay_MemMap.h"

static const uint16 ALCM_TxCanSigAdapt[21] = ALCM_TXCANSIG_ADAPT_LIST;

#define Common_GateWay_STOP_SEC_CONST_UNSPECIFIED
#include  "Common_GateWay_MemMap.h"


#define Common_GateWay_START_SEC_CODE
#include  "Common_Gateway_MemMap.h"

AL_EventRunningObject_t* ALCM_RunObjectGet(void)
{
	return &eventRunningObj;
}

void ALCM_RestartEventTime(uint8 eventId)
{
	AL_EventRunningObject_t *runObject = ALCM_RunObjectGet();
	uint8 priority = runObject->eventAttributePtr[eventId].priority;
	uint8 eventIndex = runObject->eventAttributePtr[eventId].eventIndex;

	if ((runObject->runningEventId[eventIndex] != LINKAGE_EVENT_ID_INVALID) && (runObject->runningFunc == priority)
		&& ((runObject->eventAttributePtr[eventId].eventClearOption & EVENT_CLERA_BY_TIMEOUT) == EVENT_CLERA_BY_TIMEOUT))
	{
		runObject->runningEventTimeRemain[eventIndex] = runObject->eventAttributePtr[eventId].timeout;
	}
}

void ALCM_EventSet(uint8 eventId)
{
	AL_EventRunningObject_t *runObject = ALCM_RunObjectGet();

	uint8 priority = runObject->eventAttributePtr[eventId].priority;
	uint8 eventIndex = runObject->eventAttributePtr[eventId].eventIndex;

	runObject->eventTable[priority][eventIndex] = eventId;

	ALCM_RestartEventTime(eventId);
}

void ALCM_EventClr(uint8 eventId)
{
	AL_EventRunningObject_t *runObject = ALCM_RunObjectGet();

	uint8 priority = runObject->eventAttributePtr[eventId].priority;
	uint8 eventIndex = runObject->eventAttributePtr[eventId].eventIndex;

	runObject->eventTable[priority][eventIndex] = LINKAGE_EVENT_ID_INVALID;
}

void ALCM_OutputValueInit(CanSignalValue_t* canSignal)
{
	uint8 index = 0;

	for (index = 0; index < LINKAGE_AREA_NUMBER; index++)
	{
		canSignal->freq[index] = LINKAGE_SIGNAL_FREQ_OFF;
		canSignal->color[index] = LINKAGE_SIGNAL_COLOR_NOACTION;
		canSignal->lightLevel[index] = LINKAGE_SIGNAL_LIGHTLVL_NOACTION;
	}
}

void ALCM_AssertProcess(void)
{
	vipAl_info("AL Process Error!\n");
}

#if 1
void ALCM_CanSignalOutput(CanSignalValue_t *signalVal)
{
	uint8 index = 0;
	EventSignalInfo_Type TxSigSent = {0};
	AL_EventRunningObject_t *runObject = ALCM_RunObjectGet();

	if (0 != memcmp(signalVal, &runObject->runningSignalValue, sizeof(CanSignalValue_t)))
	{
		TxSigSent.event_signal_length = 0;
		if (0 != memcmp(&signalVal->freq[0], &runObject->runningSignalValue.freq[0], sizeof(runObject->runningSignalValue.freq)))
		{
			for (index = 0; index < 21; index++)
			{
				TxSigSent.event_signal_list[index].event_id = ALCM_TxCanSigAdapt[index];
			}

			for (index = 0; index < LINKAGE_AREA_NUMBER; index++)
			{
				TxSigSent.event_signal_list[index].request_value = (uint32)signalVal->freq[index];
				TxSigSent.event_signal_list[index+7].request_value = (uint32)signalVal->color[index];
				TxSigSent.event_signal_list[index+14].request_value = (uint32)signalVal->lightLevel[index];
			}
			TxSigSent.event_signal_length = TxSigSent.event_signal_length + 21u;
		}
		else
		{
			if (0 != memcmp(&signalVal->color[0], &runObject->runningSignalValue.color[0], sizeof(runObject->runningSignalValue.color)))
			{
				for (index = 0; index < LINKAGE_AREA_NUMBER; index++)
				{
					TxSigSent.event_signal_list[index+(TxSigSent.event_signal_length)].event_id = ALCM_TxCanSigAdapt[index+7];
				}

				for (index = 0; index < LINKAGE_AREA_NUMBER; index++)
				{
					TxSigSent.event_signal_list[index+(TxSigSent.event_signal_length)].request_value = (uint32)signalVal->color[index];
				}
				TxSigSent.event_signal_length = TxSigSent.event_signal_length + 7u;
			}

			if (0 != memcmp(&signalVal->lightLevel[0], &runObject->runningSignalValue.lightLevel[0], sizeof(runObject->runningSignalValue.lightLevel)))
			{
				for (index = 0; index < LINKAGE_AREA_NUMBER; index++)
				{
					TxSigSent.event_signal_list[index+(TxSigSent.event_signal_length)].event_id = ALCM_TxCanSigAdapt[index+7];
				}

				for (index = 0; index < LINKAGE_AREA_NUMBER; index++)
				{
					TxSigSent.event_signal_list[index+(TxSigSent.event_signal_length)].request_value = (uint32)signalVal->lightLevel[index];
				}
				TxSigSent.event_signal_length = TxSigSent.event_signal_length + 7u;
			}
		}

		Rte_Call_CNA_SignalGroupSet_Operation(&TxSigSent);

		(void)memcpy(&runObject->runningSignalValue, signalVal, sizeof(CanSignalValue_t));

		(void)SWC_IPC_PRINT_DEBUG("ALCM freq = %02x %02x %02x %02x %02x %02x %02x",
					runObject->runningSignalValue.freq[0],
					runObject->runningSignalValue.freq[1],
					runObject->runningSignalValue.freq[2],
					runObject->runningSignalValue.freq[3],
					runObject->runningSignalValue.freq[4],
					runObject->runningSignalValue.freq[5],
					runObject->runningSignalValue.freq[6]);

		(void)SWC_IPC_PRINT_DEBUG("ALCM color = %02x %02x %02x %02x %02x %02x %02x",
					runObject->runningSignalValue.color[0],
					runObject->runningSignalValue.color[1],
					runObject->runningSignalValue.color[2],
					runObject->runningSignalValue.color[3],
					runObject->runningSignalValue.color[4],
					runObject->runningSignalValue.color[5],
					runObject->runningSignalValue.color[6]);

		(void)SWC_IPC_PRINT_DEBUG("ALCM lightLevel = %02x %02x %02x %02x %02x %02x %02x",
					runObject->runningSignalValue.lightLevel[0],
					runObject->runningSignalValue.lightLevel[1],
					runObject->runningSignalValue.lightLevel[2],
					runObject->runningSignalValue.lightLevel[3],
					runObject->runningSignalValue.lightLevel[4],
					runObject->runningSignalValue.lightLevel[5],
					runObject->runningSignalValue.lightLevel[6]);
	}
}
#else
void ALCM_CanSignalOutput(CanSignalValue_t *signalVal)
{
	AL_EventRunningObject_t *runObject = ALCM_RunObjectGet();

	if (0 != memcmp(signalVal, &runObject->runningSignalValue, sizeof(CanSignalValue_t)))
	{
		if (0 != memcmp(&signalVal->freq[0], &runObject->runningSignalValue.freq[0], sizeof(runObject->runningSignalValue.freq)))
		{
			/*	1. Save Signal Value into buffer
				2. Send last Signal value and trigger this event message	*/
			FALCM_Adapt_SetSigBuffer_DrvDoorALCMFlashFreq(signalVal->freq[0]);
			FALCM_Adapt_SetSigBuffer_PassDoorALCMFlashFreq(signalVal->freq[1]);
			FALCM_Adapt_SetSigBuffer_LeftPanelALCMFlashFreq(signalVal->freq[2]);
			FALCM_Adapt_SetSigBuffer_RightPanelALCMFlashFreq(signalVal->freq[3]);
			FALCM_Adapt_SetSigBuffer_LRDoorALCMFlashFreq(signalVal->freq[4]);
			FALCM_Adapt_SetSigBuffer_RRDoorALCMFlashFreq(signalVal->freq[5]);
			FALCM_Adapt_SetSigBuffer_FootALCMFlashFreq(signalVal->freq[6]);

			FALCM_Adapt_SetSigBuffer_DrvDoorALCMClrSet(signalVal->color[0]);
			FALCM_Adapt_SetSigBuffer_PassDoorALCMClrSet(signalVal->color[1]);
			FALCM_Adapt_SetSigBuffer_LeftPanelALCMClrSet(signalVal->color[2]);
			FALCM_Adapt_SetSigBuffer_RightPanelALCMClrSet(signalVal->color[3]);
			FALCM_Adapt_SetSigBuffer_LRDoorALCMClrSet(signalVal->color[4]);
			FALCM_Adapt_SetSigBuffer_RRDoorALCMClrSet(signalVal->color[5]);
			FALCM_Adapt_SetSigBuffer_FootALCMClrSet(signalVal->color[6]);

			FALCM_Adapt_SetSigBuffer_DrvDoorALCMLightLvlSet(signalVal->lightLevel[0]);
			FALCM_Adapt_SetSigBuffer_PassDoorALCMLightLvlSet(signalVal->lightLevel[1]);
			FALCM_Adapt_SetSigBuffer_LeftPanelALCMLightLvlSet(signalVal->lightLevel[2]);
			FALCM_Adapt_SetSigBuffer_RightPanelALCMLightLvlSet(signalVal->lightLevel[3]);
			FALCM_Adapt_SetSigBuffer_LRDoorALCMLightLvlSet(signalVal->lightLevel[4]);
			FALCM_Adapt_SetSigBuffer_RRDoorALCMLightLvlSet(signalVal->lightLevel[5]);
			FALCM_Adapt_SetSigBuffer_FootALCMLightLvlSet(signalVal->lightLevel[6]);

			FALCM_Adapt_SetSig_DrvDoorALCMFlashFreq(signalVal->freq[0]);
			FALCM_Adapt_SetSig_DrvDoorALCMClrSet(signalVal->color[0]);
			FALCM_Adapt_SetSig_DrvDoorALCMLightLvlSet(signalVal->lightLevel[0]);
		}
		else
		{
			if (0 != memcmp(&signalVal->color[0], &runObject->runningSignalValue.color[0], sizeof(runObject->runningSignalValue.color)))
			{
				FALCM_Adapt_SetSigBuffer_DrvDoorALCMClrSet(signalVal->color[0]);
				FALCM_Adapt_SetSigBuffer_PassDoorALCMClrSet(signalVal->color[1]);
				FALCM_Adapt_SetSigBuffer_LeftPanelALCMClrSet(signalVal->color[2]);
				FALCM_Adapt_SetSigBuffer_RightPanelALCMClrSet(signalVal->color[3]);
				FALCM_Adapt_SetSigBuffer_LRDoorALCMClrSet(signalVal->color[4]);
				FALCM_Adapt_SetSigBuffer_RRDoorALCMClrSet(signalVal->color[5]);
				FALCM_Adapt_SetSigBuffer_FootALCMClrSet(signalVal->color[6]);

				FALCM_Adapt_SetSig_DrvDoorALCMClrSet(signalVal->color[0]);
				FALCM_Adapt_SetSig_LeftPanelALCMClrSet(signalVal->color[2]);
			}

			if (0 != memcmp(&signalVal->lightLevel[0], &runObject->runningSignalValue.lightLevel[0], sizeof(runObject->runningSignalValue.lightLevel)))
			{
				FALCM_Adapt_SetSigBuffer_DrvDoorALCMLightLvlSet(signalVal->lightLevel[0]);
				FALCM_Adapt_SetSigBuffer_PassDoorALCMLightLvlSet(signalVal->lightLevel[1]);
				FALCM_Adapt_SetSigBuffer_LeftPanelALCMLightLvlSet(signalVal->lightLevel[2]);
				FALCM_Adapt_SetSigBuffer_RightPanelALCMLightLvlSet(signalVal->lightLevel[3]);
				FALCM_Adapt_SetSigBuffer_LRDoorALCMLightLvlSet(signalVal->lightLevel[4]);
				FALCM_Adapt_SetSigBuffer_RRDoorALCMLightLvlSet(signalVal->lightLevel[5]);
				FALCM_Adapt_SetSigBuffer_FootALCMLightLvlSet(signalVal->lightLevel[6]);

				FALCM_Adapt_SetSig_DrvDoorALCMLightLvlSet(signalVal->lightLevel[0]);
			}
		}

		(void)memcpy(&runObject->runningSignalValue, signalVal, sizeof(CanSignalValue_t));

		(void)SWC_IPC_PRINT_DEBUG("ALCM freq = %02x %02x %02x %02x %02x %02x %02x",
					runObject->runningSignalValue.freq[0],
					runObject->runningSignalValue.freq[1],
					runObject->runningSignalValue.freq[2],
					runObject->runningSignalValue.freq[3],
					runObject->runningSignalValue.freq[4],
					runObject->runningSignalValue.freq[5],
					runObject->runningSignalValue.freq[6]);

		(void)SWC_IPC_PRINT_DEBUG("ALCM color = %02x %02x %02x %02x %02x %02x %02x",
					runObject->runningSignalValue.color[0],
					runObject->runningSignalValue.color[1],
					runObject->runningSignalValue.color[2],
					runObject->runningSignalValue.color[3],
					runObject->runningSignalValue.color[4],
					runObject->runningSignalValue.color[5],
					runObject->runningSignalValue.color[6]);

		(void)SWC_IPC_PRINT_DEBUG("ALCM lightLevel = %02x %02x %02x %02x %02x %02x %02x",
					runObject->runningSignalValue.lightLevel[0],
					runObject->runningSignalValue.lightLevel[1],
					runObject->runningSignalValue.lightLevel[2],
					runObject->runningSignalValue.lightLevel[3],
					runObject->runningSignalValue.lightLevel[4],
					runObject->runningSignalValue.lightLevel[5],
					runObject->runningSignalValue.lightLevel[6]);
	}
}
#endif

#define Common_GateWay_STOP_SEC_CODE
#include  "Common_Gateway_MemMap.h"

