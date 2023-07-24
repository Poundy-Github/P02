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
 * @file:      Dma_cfg.c
 * @author:    Nobo
 * @date:      2020-4-3
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-4-3
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "VariantCfg.h"

#include "Dma.h"
#include "Dma_Cfg.h"


const app_dma_config DMA_CONFIG_TABLE[DMA_USED_NUMB]=
{
    {
        DMA_IPC_TX,
        DMA_CHANNLE_0,
        DMA_BYTE_8BIT|DMA_DEST_ADDR_FIX|DMA_COMPLETE_INT_DISABLE,
        DMA_TRIGGER_INTCSIH1IC,
    },
    {
        DMA_IPC_RX,
        DMA_CHANNLE_1,
        DMA_BYTE_8BIT|DMA_SOURCE_ADDR_FIX|DMA_COMPLETE_INT_DISABLE,
        DMA_TRIGGER_INTCSIH1IR,
    },
#ifdef PLATFORM_OF_STB_IPC_USED
    {
        DMA_IPC_STB_TX,
        DMA_CHANNLE_2,
        DMA_BYTE_8BIT|DMA_DEST_ADDR_FIX|DMA_COMPLETE_INT_DISABLE,
        DMA_TRIGGER_INTCSIH2IC,
    },
    {
        DMA_IPC_STB_RX,
        DMA_CHANNLE_3,
        DMA_BYTE_8BIT|DMA_SOURCE_ADDR_FIX|DMA_COMPLETE_INT_DISABLE,
        DMA_TRIGGER_INTCSIH2IR,
    },
#endif
    {
        DMA_GPS_RX,
        DMA_CHANNLE_4,
        DMA_BYTE_8BIT|DMA_SOURCE_ADDR_FIX|DMA_COMPLETE_INT_DISABLE|DMA_RELOAD_DEST|DMA_CONTINUOUS_TRANSFER_EN,
        DMA_TRIGGER_INTRLIN34UR1,
    },
    {
        DMA_LOG_RX,
        DMA_CHANNLE_5,
        DMA_BYTE_8BIT|DMA_SOURCE_ADDR_FIX|DMA_COMPLETE_INT_DISABLE|DMA_RELOAD_DEST|DMA_CONTINUOUS_TRANSFER_EN,
        DMA_TRIGGER_INTRLIN35UR1,
    },    
	/* added new dma config to here */
};
