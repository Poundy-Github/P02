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
 * @file:      RTC_RI.h
 * @author:    Nobo
 * @date:      2020-5-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _RTC_RI_H_
#define _RTC_RI_H_

#include "IIC.h"





/* RTC CONFIG */

/* DEFINE RTC DEBUG CONFIG */
//#define RTC_TST


#define SYNC_TIMEOUT                        (1000*60*60)
#define RTC_SEND_TPC_TIMEOUT                (1000u)


#define RTC_IPC_ACK_OK                      (0u)
#define RTC_IPC_ACK_NOK                     (1u)




#define RI_QueueTxReq                       IIC_QueueTxReq
#define RI_QueueRxReq                       IIC_QueueRxReq

#define RI_GetSystemTimer                   RTC_GetSystemTick
#define RI_GetElapsedValue                  RTC_GetElapsedValue


#define RI_Write_UtcTime                    Rte_Write_Sd_RTC_UtcTime
#define RI_Write_SleepDateTime              Rte_Write_Sd_RTC_SleepDateTime



/* DEFINE RTC DEBUG */
#ifdef RTC_TST
#undef  SYNC_TIMEOUT
#define SYNC_TIMEOUT                        (500)

#include "logger.h"
#define RTC_ACCERT(expr)                    do{(expr)?(void)0 : (void)rtc_err("\nLINE:%d;\n",__LINE__);}while(0)
#define RTC_DEBUG(...)                      rtc_info(__VA_ARGS__);
#define RTC_WARN(...)                       rtc_warn(__VA_ARGS__);
#ifdef STATIC
#undef STATIC
#endif
#define STATIC

#else

#include "logger.h"
#define STATIC                              static
#define RTC_ACCERT(expr)                    
#define RTC_DEBUG(...)                      
#define STATIC                              static

#endif


#endif /* ifndef _RTC_RI_H_.2020-5-6 13:15:08 GW00188879 */
