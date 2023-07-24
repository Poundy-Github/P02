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
 * @file:      Dma_cfg.h
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


#ifndef _DMA_CFG_H_
#define _DMA_CFG_H_


#include "Std_Types.h"
#include "VariantCfg.h"


#define DMA_USED_NUMB               (NUMBER_OF_DMA_DEVICES)

/*DMA trigger factor, please refer MCU spec 7.1.4 DMA Trigger Factors*/
typedef enum DMA_TRIGGER_SOURCE
{
    DMA_TRIGGER_SOFTWARE    = 0xF0u,
    
    DMA_TRIGGER_INTCSIH1IC  = 28u,
    DMA_TRIGGER_INTCSIH1IR  = 29u,
    DMA_TRIGGER_INTCSIH2IC  = 89u,
    DMA_TRIGGER_INTCSIH2IR  = 90u,
    DMA_TRIGGER_INTCSIH3IC  = 41u,
    DMA_TRIGGER_INTCSIH3IR  = 42u,
    DMA_TRIGGER_INTRLIN34UR1 = 51u,
    DMA_TRIGGER_INTRLIN35UR1 = 122u,
}DMA_TRIGGER_SOURCE;


typedef enum DMA_DEVICE_ID
{
    DMA_IPC_RX = 0,
    DMA_IPC_TX,
#ifdef PLATFORM_OF_STB_IPC_USED
    DMA_IPC_STB_RX,
    DMA_IPC_STB_TX,
#endif
    DMA_GPS_RX,
    DMA_LOG_RX,
    NUMBER_OF_DMA_DEVICES
}DMA_DEVICE_ID;

typedef enum DMA_CHANNEL
{
    DMA_CHANNLE_0 = 0,
    DMA_CHANNLE_1,
    DMA_CHANNLE_2, 
    DMA_CHANNLE_3, 
    DMA_CHANNLE_4,
    DMA_CHANNLE_5,
    DMA_CHANNLE_6,
    DMA_CHANNLE_7,
    DMA_CHANNLE_8,
    DMA_CHANNLE_9,
    DMA_CHANNLE_10,
    DMA_CHANNLE_11,
    DMA_CHANNLE_12,
    DMA_CHANNLE_13,
    DMA_CHANNLE_14,
    DMA_CHANNLE_15,
    
    DMA_CHANNLE_NUM
}DMA_CHANNEL;

/*dma*/
typedef struct app_dma_config
{
    DMA_DEVICE_ID     user_id;
    DMA_CHANNEL	hw_channel;
    uint32    option;
    uint8     trigger;
}app_dma_config;

extern const app_dma_config DMA_CONFIG_TABLE[DMA_USED_NUMB];

#endif
