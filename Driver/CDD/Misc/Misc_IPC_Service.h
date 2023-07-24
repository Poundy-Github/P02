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
 * @file:      Misc_IPC_Service.h
 * @author:    Nobo
 * @date:      2020-8-19
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-19
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _MISC_IPC_SERVICE_H_
#define _MISC_IPC_SERVICE_H_

#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void MISC_IPC_Service_Callback(uint8 sub_msg_id,uint8* param, uint16 param_len);
void MISC_IPC_Service_Task(void);

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ifndef _MISC_IPC_SERVICE_H_.2020-8-19 14:15:10 GW00188879 */
