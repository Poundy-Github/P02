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
 * @file:      CoreTst_Monitor.h
 * @author:    Nobo
 * @date:      2021-1-13
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-1-13
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _CORTST_MONITOR_H_
#define _CORTST_MONITOR_H_

#define SysSafety_START_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void CorTst_SelfTest(void);
void CoreTst_MonitorHandle(void);
void CorTst_EITRAP0_Notification(void);
void CorTst_EITRAP1_Notification(void);
void CorTst_FETRAP_Notification(void);
void CorTst_MAE_Notification(void);

#define SysSafety_STOP_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ifndef _CORTST_MONITOR_H_.2021-1-20 16:53:38 GW00191223 */
