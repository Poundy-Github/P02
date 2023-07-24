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
 * @file:      Dma.h
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

#ifndef _DMA_H_
#define _DMA_H_

#include "Cdd_Common.h"
#include "Dma_Cfg.h"

typedef enum DMA_OPTION
{
    DMA_BYTE_8BIT = 0,
    DMA_BYTE_16BIT = BIT2,
    DMA_BYTE_32BIT = BIT3,
    DMA_BYTE_64BIT = BIT2 | BIT3,
    DMA_BYTE_128BIT = BIT4,

    DMA_SOURCE_ADDR_INC = 0,
    DMA_SOURCE_ADDR_DEC = BIT5,
    DMA_SOURCE_ADDR_FIX = BIT6,
    
    DMA_DEST_ADDR_INC = 0,
    DMA_DEST_ADDR_DEC = BIT7,
    DMA_DEST_ADDR_FIX = BIT8,
    
    DMA_COMPLETE_INT_DISABLE = 0,
    DMA_COMPLETE_INT_ENABLE = BIT14,

    DMA_TRANSFER_MOD_SINGLE = 0,
    DMA_TRANSFER_MOD_BLOCK1 = BIT0,
    DMA_TRANSFER_MOD_BLOCK2 = BIT1,

    DMA_RELOAD_DIS = 0,
    DMA_RELOAD_SOURCE = BIT9,
    DMA_RELOAD_DEST  = BIT10,

    DMA_CONTINUOUS_TRANSFER_DIS = 0,
    DMA_CONTINUOUS_TRANSFER_EN = BIT13,
}DMA_OPTION;


typedef struct Dma_typef
{
    uint32 *source_addr;
    uint32 *dest_addr;
    uint16  transfer_times; /*DMA transfer count*/
    DMA_CHANNEL channel; 
    DMA_OPTION option;
    uint8 trigger_source;

}Dma_typef;




#define DMA_CLEARL_ALL_REQ()                do{}while(0)


extern void Dma_Init(void);
extern void Dma_DeInit(void);
extern void Dma_software_start(DMA_CHANNEL channel);
extern void Dma_TrasferStop(DMA_CHANNEL channel);
extern void Dma_ChannelStop(DMA_DEVICE_ID user_id);
extern void Dma_ChannelConfiguration( DMA_DEVICE_ID user_id ,void *soure_address ,void *dest_address, uint16 times );
extern sint32 Dma_ChannelTransferCnt(uint8 user_id);
extern boolean Dma_ChannelTransferComplete(uint8 user_id);
extern void Dma_ChannelTransferCompleteClear(uint8 user_id);
#endif
