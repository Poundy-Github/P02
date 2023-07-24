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
 * @file:      RTC_cfg.c
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

#include "Os.h"
#include "Rte_RTC.h"
#include "RTC.h"
#include "RTC_cfg.h"







void RTC_TraceMainFunction(void)
{
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_RTC_RTC_MainFunction);
}


