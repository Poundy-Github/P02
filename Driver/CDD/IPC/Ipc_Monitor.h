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
 * @file:      Ipc_Monitor.h
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

/*
 *  %header file in this project/library%
 */

#ifndef IPC_MONITOR_H
#define	IPC_MONITOR_H

#include "Platform_Types.h"
#include "Ipc_Com.h"



extern uint8 ipc_TxFrameBuffer[IPC_DATA_FRAME_LENGTH]; /*IPC DMA send data buffer.*/
extern uint8 ipc_RxFrameBuffer[IPC_DATA_FRAME_LENGTH];   /*DMA receive data buffer.*/
extern uint8 ipc_TxAckBuffer[IPC_ACK_FRAME_LENGTH];   /*Ack data buffer.*/
extern uint8 ipc_RxRollCnt;


extern void IPC_Monitor_Init(void);
extern void IPC_Monitor_DeInit(void);
extern void IPC_Monitor_MainFunction(void);
extern void IPC_RePrepareSendData(void);
extern void IPC_PrepareAckData(uint8 ack);
extern void IPC_ClearRollCounter(void);
#if(STD_ON == IPC_COM_NACK_CHECK_EN)
extern boolean IPC_NackCheck(void);
#endif


#endif
