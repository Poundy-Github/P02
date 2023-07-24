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
 * @file:      RamTst_Monitor.c
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

#include "RamTst.h"
#include "logger.h"
#include "SysSafety.h"
#include "RamTst_Monitor.h"

#define SysSafety_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static RamTst_TestResultType RamTst_TestResult;

#define SysSafety_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define SysSafety_START_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void RamTst_MonitorHandle(void)
{
    if(RamTst_TestResult == RAMTST_RESULT_NOT_OK)
    {
        /*Ram Test Error Todo*/        
        #ifdef SYSSAFETY_DEBUG_ENABLE
            sys_info("FUSA Ram Test Failed");
        #endif  

    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void RamTst_CompletedNotification(void)
{
	RamTst_TestResult = RamTst_GetTestResult();
}
#define SysSafety_STOP_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

