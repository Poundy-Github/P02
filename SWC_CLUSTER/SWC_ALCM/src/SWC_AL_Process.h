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

#ifndef __SWC_AL_PROCESS_H
#define	__SWC_AL_PROCESS_H

#include "Platform_Types.h"

#define Common_GateWay_START_SEC_CODE
#include  "Common_GateWay_MemMap.h"

#define	CAN_SIGNAL_VALUE_SET(signalIndex, eventIndex)	\
{														\
	canSignalValue.freq[signalIndex] = eventAttribute[eventIndex].freq;\
	canSignalValue.color[signalIndex] = eventAttribute[eventIndex].color;\
	canSignalValue.lightLevel[signalIndex] = eventAttribute[eventIndex].lightLevel;\
}

#define	CAN_SIGNAL_VALUE_KEEP(signalIndex)	\
{														\
	canSignalValue.freq[signalIndex] = eventRunningObject->runningSignalValue.freq[signalIndex];\
	canSignalValue.color[signalIndex] = eventRunningObject->runningSignalValue.color[signalIndex];\
	canSignalValue.lightLevel[signalIndex] = eventRunningObject->runningSignalValue.lightLevel[signalIndex];\
}

#define AL_SINGLE_AIRCONDITION		((uint8)1)
#define AL_DOUBLE_AIRCONDITION		((uint8)2)

#define AL_PM25_POLLUTION_LOW		((uint8)1)
#define AL_PM25_POLLUTION_MID		((uint8)2)
#define AL_PM25_POLLUTION_HIGH		((uint8)3)
#define AL_PM25_POLLUTION_SERIOUS	((uint8)4)
#define AL_PM25_POLLUTION_CLEAR		((uint8)0xFF)

typedef struct{
    uint8 CurrentSigValue;
    uint8 CurrentSigStat;
    uint8 PreSigValue;
}AL_U8SigAttribute_t;

typedef struct{
    uint16 CurrentSigValue;
    uint8 CurrentSigStat;
    uint16 PreSigValue;
}AL_U16SigAttribute_t;
typedef struct{
    AL_U8SigAttribute_t     ALCM_AEB_VehTrig;
    AL_U8SigAttribute_t     ALCM_AEB_PedTrig;
    AL_U8SigAttribute_t     ALCM_AEB_JA_Warn;
    AL_U8SigAttribute_t     ALCM_AEB_JABrkTrig;
    AL_U8SigAttribute_t     ALCM_FCW_Warn;
    AL_U8SigAttribute_t     ALCM_FCTBTrig;
    AL_U8SigAttribute_t     ALCM_FCTA_Warn;
    AL_U8SigAttribute_t     ALCM_LCA_WarnR;
    AL_U8SigAttribute_t     ALCM_LCA_WarnL;
    AL_U8SigAttribute_t     ALCM_DOW_WarnR;
    AL_U8SigAttribute_t     ALCM_DOW_WarnL;
    AL_U8SigAttribute_t     ALCM_DrvDoorSts;
    AL_U8SigAttribute_t     ALCM_PassengerDoorSts;
    AL_U8SigAttribute_t     ALCM_LRDoorSts;
    AL_U8SigAttribute_t     ALCM_RRDoorSts;
    AL_U8SigAttribute_t     ALCM_ACDrvTemp;
    AL_U8SigAttribute_t     ALCM_ACFrntPasstTemp;
    AL_U16SigAttribute_t    ALCM_PM25InDens;
}AL_SignalList_t;


void AL_InputProcess_AEB(uint8 *runObject);
void AL_InputProcess_FCW(uint8 *runObject);
void AL_InputProcess_FCT(uint8 *runObject);
void AL_InputProcess_LCA(uint8 *runObject);
void AL_InputProcess_DOW(uint8 *runObject);
void AL_InputProcess_DOOR(uint8 *runObject);
void AL_InputProcess_TBD(uint8 *runObject);
void AL_InputProcess_ACTEMP(uint8 *runObject);
void AL_InputProcess_PM25(uint8 *runObject);


void AL_OutputValueGet_NONE(uint8 *runObject);
void AL_OutputValueGet_AEB(uint8 *runObject);
void AL_OutputValueGet_FCW(uint8 *runObject);
void AL_OutputValueGet_FCT(uint8 *runObject);
void AL_OutputValueGet_LCA(uint8 *runObject);
void AL_OutputValueGet_DOW(uint8 *runObject);
void AL_OutputValueGet_DOOR(uint8 *runObject);
void AL_OutputValueGet_TBD(uint8 *runObject);
void AL_OutputValueGet_ACTEMP(uint8 *runObject);
void AL_OutputValueGet_PM25(uint8 *runObject);

void AL_TransExitNormal(const AL_EventRunningObject_t * const runObject);
void AL_TransIntoNormal(const AL_EventRunningObject_t * const runObject);

void ALCM_AppCommonProcess(const AL_EventRunningObject_t * const runObject);

#define Common_GateWay_STOP_SEC_CODE
#include  "Common_GateWay_MemMap.h"

#endif

