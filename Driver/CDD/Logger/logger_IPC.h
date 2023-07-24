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
 * @file:      logger_IPC.h
 * @author:    Nobo
 * @date:      2020-8-4
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-4
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _LOGGER_IPC_H_
#define _LOGGER_IPC_H_

void Logger_IPC_Init(void);
void Logger_IPC_Task(void);
void IPC_Log_Callback(uint8 major_msg_id, uint8 sub_msg_id, uint8 * param, uint16 param_len);

#endif /* ifndef _LOGGER_IPC_H_.2020-8-4 10:43:53 GW00188879 */
