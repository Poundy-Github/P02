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
 * @file:      SOCManager_IPC_Service.h
 * @author:    Nobo
 * @date:      2020-10-22
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-10-22
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _SOCMANAGER_IPC_SERVICE_H_
#define _SOCMANAGER_IPC_SERVICE_H_
#include "VariantCfg.h"

#include "SOCManager_Type.h"
#include "SOCManager_Alg.h"

#define SOC_INFO_HANDSHAKE_TIMEOUT_RESET_OFF	(0u)
#define SOC_INFO_HANDSHAKE_TIMEOUT_RESET_ON		(1u)

void SOCManager_ScanIPCMsg(sSOCManagerIO_t *io);
void SOCManager_IPC_Service_Init(void);
void SOCManager_IPCResponse(sSOCManagerIO_t *io);
#ifdef PLATFORM_OF_STB_IPC_USED
void SOCManager_STBIPCResponse(sSOCManagerIO_t *io);
void IPC_STB_Deticated_SocManager(uint8 sub_msg_id, uint8 * param, uint16 param_len);
#endif

#endif /* ifndef _SOCMANAGER_IPC_SERVICE_H_.2020-10-22 14:32:30 GW00188879 */
