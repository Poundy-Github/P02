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
 * @file:      AMP_IPCReceive.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef AMP_IPCRECEIVE_H
#define AMP_IPCRECEIVE_H

#include "IPC_Audio.h"
#include "Std_Types.h"


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

extern void AMP_ReceiveIPCData(uint8 Major_msg_id, uint8 Sub_msg_id, uint8 * param, uint16_t param_len);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

#endif
