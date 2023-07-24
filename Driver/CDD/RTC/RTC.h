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
 * @file:      RTC.h
 * @author:    Nobo
 * @date:      2020-4-24
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-4-24
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _RTC_H_
#define _RTC_H_

/* include file */
#include <time.h>
#include "Platform_Types.h"
#include "Compiler.h"

/* DEFINE RTC RESULT */
typedef signed char RTC_Result_t;

#define eRTC_Result_Seccess                 (0)
#define eRTC_Result_Error                   (1)

/* DEFINE RETURN TYPE */
typedef signed char RTC_Return_t;

#define eRTC_Return_Seccess                 (0)
#define eRTC_Return_E_Error                 (-1)
#define eRTC_Return_E_Uninit                (-2)
#define eRTC_Return_E_BUSY                  (-3)

typedef unsigned char RTC_RequestUnit_t;



typedef struct
{
    uint16  u16Year;
    uint8   u8Day;
    uint8   u8Hour;
    uint8   u8Minutes;
    uint8   u8Month;
    uint8   u8Second;
    uint8   u8WeekDay;
}DataTime_t;


#define RTC_ENTER_CRITICAL_SECTION        Rte_Enter_ExclusiveArea_RTC
#define RTC_EXIT_CRITICAL_SECTION         Rte_Exit_ExclusiveArea_RTC

void RTC_MainFunction(void);
void RTC_CycleTask(void);

extern void RTC_PreInit(void);
extern RTC_Return_t RTC_GetTime(sint64 * time);
extern RTC_Return_t RTC_SetTime(const sint64 time);
typedef void(*RTC_Callback_t) (RTC_Result_t tResult, sint64 time);
void MISC_IPC_RTC_Callback(uint8 sub_msg_id,uint8* param, uint16 param_len);
void Rtc_SleepDateTimeRecord(void);
void RTC_ColdResetCallout(void);
RTC_Return_t RTC_GetBinTime(sint64 * time);
#ifdef RTC_TST
extern void RTC_Test(void);
#endif


#endif /* ifndef _RTC_H_.2020-4-24 17:04:20 GW00188879 */
