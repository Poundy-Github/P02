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
 * @file:      Ipc_LoadTest.h
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

#ifndef _IPC_LOADTEST_H_
#define _IPC_LOADTEST_H_
#include "Std_Types.h"
#include "Platform_Types.h"


//defbug info
//#define IPC_DEBUG_OPEN
#ifdef IPC_DEBUG_OPEN

#define IPC_BUS_LOADING_MONITOR_CYCLE	(1000/10)//1000ms


#define IPC_TIME_OUT_DEF                (200000u)
#define IPC_ROCAR_SIZE                  (0x20)  // user 2^n


typedef struct
{
    uint8 GId;
    uint8 MId;
    uint8 SId;
    uint16 len;
}IPC_RocarData_t;

extern IPC_RocarData_t IPC_RocarBuffer[IPC_ROCAR_SIZE];
extern uint8 IPC_RocarCnt;



extern uint32 IPC_DEBUG_Time;
extern uint16 IPC_Debug_TimeoutCnt ;
extern uint32 IPC_Debug_MaxTimeoutTime;
extern uint32 IPC_Debug_RxDataSize;



void TST_IPC_CheckRequestTransport(void);
void TST_IPC_CheckSPITransportEnd(void);
void TST_IPC_CheckSendData(const uint8 * data,uint16 len);
void TST_IPC_CheckTransport(uint16 len);
void TST_IPC_CheckReceiver(uint16 len);
void IPC_BusMonitor_Mainfunction(void);

#else

#define TST_IPC_CheckRequestTransport()
#define TST_IPC_CheckSPITransportEnd()
#define TST_IPC_CheckSendData(x,y)
#define TST_IPC_CheckTransport(x)
#define TST_IPC_CheckReceiver(x)


#endif


#endif /* ifndef _IPC_LOADTEST_H_.2020-9-18 10:53:36 GW00188879 */
