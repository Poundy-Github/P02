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
 * @file:      Ipc_Cfg.h
 * @author:    Nobo
 * @date:      2020-5-22
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-22
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _IPC_CFG_H_
#define _IPC_CFG_H_

#include "dio.h"
#include "icu.h"
#include "csih_spi.h"
#include "VariantCfg.h"


#define IPC_VIP_SOC_REQ                     DioConf_DioChannel_VIP_SOC_CSIH1_REQ1
#define IPC_GET_SOC_VIP_CS()                Icu_GetInputLevel(IcuConf_IcuChannel_SOC_VIP_CSIH1_CS)
#define IPC_GET_SOC_VIP_REQ()               Dio_ReadChannel(DioConf_DioChannel_SOC_VIP_CSIH1_REQ2)

#define IPC_STB_VIP_SOC_REQ                 DioConf_DioChannel_VIP_SOC_CSIH2_REQ1
#define IPC_STB_GET_SOC_VIP_CS()            Icu_GetInputLevel(IcuConf_IcuChannel_SOC_VIP_CSIH2_CS)
#define IPC_STB_GET_SOC_VIP_REQ()           Dio_ReadChannel(DioConf_DioChannel_SOC_VIP_CSIH2_REQ2)

#define IPC_USER_RX_ADDR                    (CSIH1_RX_ADDR)
#define IPC_USER_TX_ADDR                    (CSIH1_TX_ADDR)

#ifdef PLATFORM_OF_STB_IPC_USED
#define IPC_STB_USER_RX_ADDR                (CSIH2_RX_ADDR)
#define IPC_STB_USER_TX_ADDR                (CSIH2_TX_ADDR)
#endif

#endif /* ifndef _IPC_CFG_H_.2020-5-22 9:38:39 GW00188879 */
