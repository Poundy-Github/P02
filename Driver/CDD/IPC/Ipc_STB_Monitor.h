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
 * @file:      Ipc_STB_Monitor.h
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

/*
 *  %header file in this project/library%
 */

#ifndef IPC_STB_MONITOR_H
#define	IPC_STB_MONITOR_H

#include "Platform_Types.h"
#include "IPC_STB_Com.h"



#define IPC_STB_BUFFER_FULL_PRITF_EN		(STD_ON)

extern void IPC_STB_Monitor_Init(void);
extern void IPC_STB_Monitor_DeInit(void);
extern void IPC_STB_Monitor_MainFunction(void);
extern void IPC_STB_RePrepareSendData(void);
extern void IPC_STB_PrepareAckData(uint8 ack);
extern void IPC_STB_ClearRollCounter(void);

#if(STD_ON == IPC_STB_COM_NACK_CHECK_EN)
extern boolean IPC_STB_NackCheck(void);
#endif


#endif

#endif
