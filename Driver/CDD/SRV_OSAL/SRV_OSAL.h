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
 * @file:      SRV_OSAL.h
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

#ifndef _SRV_OSAL_H_
#define _SRV_OSAL_H_

#include <stdio.h>
#include "Platform_Types.h"

typedef uint32 TickType;


extern uint32       SRV_OSAL_Timer32_GetSystemTimer( void );
extern void         SRV_OSAL_Timer32_Start( uint32 * const pu32TimerP );
extern void         SRV_OSAL_Timer32_Stop( uint32 * const pu32TimerP );
extern boolean      SRV_OSAL_Timer32_IsStarted( const uint32 u32TimerP );
extern boolean      SRV_OSAL_Timer32_IsElapsed( const uint32 u32TimerP, const uint32 u32TimeoutP );
extern uint32       SRV_OSAL_Timer32_GetElapsedTime( const uint32 u32TimerP );


extern uint16       SRV_OSAL_Timer16_GetSystemTimer( void );
extern void         SRV_OSAL_Timer16_Start( uint16 * const pu16TimerP );
extern void         SRV_OSAL_Timer16_Stop( uint16 * const pu16TimerP );
extern boolean      SRV_OSAL_Timer16_IsStarted( const uint16 u16TimerP );
extern boolean      SRV_OSAL_Timer16_IsElapsed( const uint16 u16TimerP, const uint16 u16TimeoutP );
extern uint16       SRV_OSAL_Timer16_GetElapsedTime( const uint16 u16TimerP );



#ifdef USER_ASSERT_SRV_OSAL
#include "logger.h"
#define ASSERT_SRV_OSAL(X)           X?0:sys_err("Line:%d:",__LINE__)
#else
#define ASSERT_SRV_OSAL(X)
#endif

#endif /* ifndef _SRV_OSAL_H_.2020-4-3 16:13:01 GW00188879 */
