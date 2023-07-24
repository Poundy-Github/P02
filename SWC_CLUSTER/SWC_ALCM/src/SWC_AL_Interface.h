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

#ifndef __SWC_AL_INTERFACE_H
#define	__SWC_AL_INTERFACE_H

#include "Platform_Types.h"
#include "SWC_AL_Core.h"
#include "logger.h"

#define Common_GateWay_START_SEC_CODE
#include  "Common_Gateway_MemMap.h"

extern void ALCM_API_vColdInit(void);

extern void ALCM_API_vTimeTask(void);

extern AL_EventRunningObject_t* ALCM_RunObjectGet(void);

extern void ALCM_OutputValueInit(CanSignalValue_t* canSignal);

extern void ALCM_AssertProcess(void);

extern void ALCM_EventSet(uint8 eventId);

extern void ALCM_RestartEventTime(uint8 eventId);

extern void ALCM_EventClr(uint8 eventId);

extern void ALCM_CanSignalOutput(CanSignalValue_t *signalVal);

extern void ALCM_GetConfigProcess(AL_EventRunningObject_t *runObject);

#define Common_GateWay_STOP_SEC_CODE
#include  "Common_Gateway_MemMap.h"

#if ALCM_DEBUG_EN
#define vipAl_info(...)   //Logger_String(LOGGER_MODULE_VIPAL, LOGGER_LEVEL_INFO, __VA_ARGS__)
#define vipAl_warn(...)   //Logger_String(LOGGER_MODULE_VIPAL, LOGGER_LEVEL_WARN, __VA_ARGS__)
#define vipAl_err(...)    //Logger_String(LOGGER_MODULE_VIPAL, LOGGER_LEVEL_ERR, __VA_ARGS__)
#else
#define vipAl_info(...)
#define vipAl_warn(...)
#define vipAl_err(...)
#endif

#if ALCM_DEBUG_EN
#define	ASSERT_ALCM(x)	\
{						\
	do{	if(!(x))AL_AssertProcess() }while(0);\
}
#else
#define	ASSERT_ALCM(x)
#endif

#endif

