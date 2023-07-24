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
 * @file:      SRV_OSAL_RI.h
 * @author:    Nobo
 * @date:      2020-4-3
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-4-3
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _SRV_OSAL_RI_H_
#define _SRV_OSAL_RI_H_

#include "Platform_Types.h"
#include "Compiler.h"
#define cTicksPerMs                                         ((uint32)1)

// This macro is used to convert the counter value in system ticks to [ms]
#define RI_SystemTicksToMs(TimeInTicks)                     ((TimeInTicks) / cTicksPerMs)

// This macro is used to convert the time in [ms] to system ticks
#define RI_MsToSystemTicks(TimeInMs)                        ((TimeInMs) * cTicksPerMs)

extern void TM_Timer1msStartStamp(uint32 * StartStamp);
#define RI_GetSystemTimer(pSystemTimer)                    TM_Timer1msStartStamp(pSystemTimer) /* do{(*pSystemTimer) = 0;xTaskGetTickCount();}while(0)*/




#endif /* ifndef _SRV_OSAL_RI_H_.2020-4-3 16:25:41 GW00188879 */
