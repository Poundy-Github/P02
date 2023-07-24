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
 * @file:      CPULoadMeasure.h
 * @author:    Nobo
 * @date:      2020-7-31
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-7-31
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern void Misc_CPULoad_MainFunction(void);
extern void MISC_OS_Task_Execution_Init(void);
extern void MISC_OS_PreTask_Execution(void);
extern void MISC_OS_PostTask_Execution(void);
extern void MISC_OS_PreIsr_Execution(void);
extern void MISC_OS_PostIsr_Execution(void);

void cpu_load_dbg_setting_cb(boolean val);

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define PANIC_ERROR		0xaa55
#define PANIC_MPU_ERROR	0x55aa
