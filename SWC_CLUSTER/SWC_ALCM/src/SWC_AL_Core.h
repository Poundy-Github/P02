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

#ifndef __SWC_AL_CORE_H
#define	__SWC_AL_CORE_H

#include "Platform_Types.h"
#include "SWC_AL_Config.h"

typedef struct
{
	uint8 freq[LINKAGE_AREA_NUMBER];
	uint8 color[LINKAGE_AREA_NUMBER];
	uint8 lightLevel[LINKAGE_AREA_NUMBER];
}CanSignalValue_t;

typedef void (*CanSignalValueGet_t)(uint8 *);
typedef void (*InputProcess_t)(uint8 *);

typedef struct
{
	uint8 Cfg_NvmInitflag;
	uint8 Cfg_MLPConfig;
	uint8 Cfg_LeftDriverDoor;
	uint8 Cfg_AEBVehicleEnable;
	uint8 Cfg_AEBPedestrianEnable;
	uint8 Cfg_AEBJABrkEnable;
	uint8 Cfg_FCWEnable;
	uint8 Cfg_FCTEnable;
	uint8 Cfg_LCAEnable;
	uint8 Cfg_DOWEnable;
	uint8 Cfg_AirCondition;
	uint8 Cfg_PM25Enable;
}AL_ConfigList_t;

typedef struct
{
	uint8 eventSlotNumber;
	//uint8 funcEventNumber;
	InputProcess_t funcInputProcess;
	CanSignalValueGet_t funcCanSignalGet;
}AL_FuncAttribute_t;

typedef struct
{
	uint8 priority;
	uint8 eventIndex;
	//uint8 eventValue;
	uint8 eventClearOption;
	uint16 timeout;

	uint8 freq;
	uint8 color;
	uint8 lightLevel;
}AL_EventAttribute_t;

typedef struct
{
	// 当前仲裁的事件表
	uint8 eventTable[LINKAGE_FUNCTION_NUMBER][EVENT_IN_FUN_SLOT_NUMBER];
	//uint8 eventBitMask[(LINKAGE_EVENT_NUMBER+7)/8];

	// 即将运行的功能
	uint8 aboutToRunFunc;
	uint8 aboutToRunEventId[EVENT_IN_FUN_SLOT_NUMBER];

	// 当前正在运行氛围灯情况
	uint8 runningFunc;
	uint8 runningEventId[EVENT_IN_FUN_SLOT_NUMBER];
	uint16 runningEventTimeRemain[EVENT_IN_FUN_SLOT_NUMBER];

	// 当前配置各个event对应的联动区域
	//uint8 linkageArea[LINKAGE_EVENT_NUMBER];

	CanSignalValue_t runningSignalValue;
	AL_ConfigList_t AlcmConfig;

	uint32 powerModeStatus;
	uint8 MasterSwt;
	uint8 PartitionSwt;
	uint8 MLPConfig;

	const AL_FuncAttribute_t *funcAttributePtr;
	const AL_EventAttribute_t *eventAttributePtr;
}AL_EventRunningObject_t;

#define Common_GateWay_START_SEC_VAR_NOINIT_UNSPECIFIED
#include  "Common_Gateway_MemMap.h"


extern AL_EventRunningObject_t eventRunningObj;

#define Common_GateWay_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include  "Common_Gateway_MemMap.h"


#endif

