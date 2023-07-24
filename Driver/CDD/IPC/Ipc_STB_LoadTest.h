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
 * @file:      Ipc_STB_LoadTest.h
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

#ifndef _IPC_STB_LOADTEST_H_
#define _IPC_STB_LOADTEST_H_


//defbug info
//#define IPC_STB_DEBUG_OPEN
#ifdef IPC_STB_DEBUG_OPEN
#define IPC_STB_BUS_LOADING_MONITOR_CYCLE	(1000/10)//1000ms


#include "Platform_Types.h"

#define IPC_STB_TIME_OUT_DEF                (200000u)
#define IPC_STB_ROCAR_SIZE                  (0x20)  // user 2^n


typedef struct
{
    uint8 GId;
    uint8 MId;
    uint8 SId;
    uint16 len;
}IPC_STB_RocarData_t;

extern IPC_STB_RocarData_t RocarBuffer[IPC_STB_ROCAR_SIZE];
extern uint8 RocarCnt;



extern uint32 IPC_STB_DEBUG_Time;
extern uint16 IPC_STB_Debug_TimeoutCnt ;
extern uint32 IPC_STB_Debug_MaxTimeoutTime;
extern uint32 IPC_STB_Debug_RxDataSize;



void TST_IPC_STB_CheckRequestTransport(void);
void TST_IPC_STB_CheckSPITransportEnd(void);
void TST_IPC_STB_CheckSendData(const uint8 * data,uint16 len);
void TST_IPC_STB_CheckTransport(uint16 len);
void TST_IPC_STB_CheckReceiver(uint16 len);


void IPC_STB_BusMonitor_Mainfunction(void);

#else

#define TST_IPC_STB_CheckRequestTransport()
#define TST_IPC_STB_CheckSPITransportEnd()
#define TST_IPC_STB_CheckSendData(x,y)
#define TST_IPC_STB_CheckTransport(x)
#define TST_IPC_STB_CheckReceiver(x)


#endif


#endif /* ifndef _IPC_STB_LOADTEST_H_.2020-9-18 10:53:36 GW00188879 */

#endif
