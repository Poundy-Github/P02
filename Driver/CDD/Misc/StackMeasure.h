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
 * @file:      StackMeasure.h
 * @author:    Nobo
 * @date:      2020-7-23
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-7-23
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern void MISC_OS_Stack_Usage(void);
extern void OS_Stack_Usage_Init(void);
extern void OS_Stack_Usage_setting_cb(boolean val, uint32 time);
#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
