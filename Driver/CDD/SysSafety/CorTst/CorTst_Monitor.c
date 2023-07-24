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
 * @file:      CoreTst_Monitor.c
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

#include "Cortst.h"
#include "logger.h"
#include "SysSafety.h"
#include "CorTst_Monitor.h"

#define SysSafety_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static Std_ReturnType CorTst_TestResult;

#define SysSafety_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define SysSafety_START_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void CorTst_SelfTest(void)
{
    CorTst_Init( NULL_PTR );
    CorTst_TestResult = CorTst_Start(0);
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void CoreTst_MonitorHandle(void)
{
    if(CorTst_TestResult == E_NOT_OK)
    {
        /*Todo Core Selftest Error */
        #ifdef SYSSAFETY_DEBUG_ENABLE
            (void)sys_info("FUSA Core Test Failed");
        #endif  
    }
}

void CorTst_EITRAP0_Notification(void)
{
}

void CorTst_EITRAP1_Notification(void)
{
}

void CorTst_FETRAP_Notification(void)
{
}

void CorTst_MAE_Notification(void)
{
}

#define SysSafety_STOP_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

