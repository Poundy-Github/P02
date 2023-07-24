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
 * @file:      hal_spi.h
 * @author:    Nobo
 * @date:      2020-3-16
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-3-16
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _HAL_SPI_H_
#define _HAL_SPI_H_
#include "VariantCfg.h"
#include "Cdd_Common.h"

typedef enum HAL_SPI_USED_NUM
{
	HAL_SPI_IPC=0,
#ifdef PLATFORM_OF_STB_IPC_USED
	HAL_SPI_IPC_STB,
#endif
	HAL_SPI_DEVICE_MAX
}HAL_SPI_USED_NUM;


typedef enum Hal_Spi_State
{
	HAL_SPI_STATE_CLOSE,
	HAL_SPI_STATE_IDLE,
	HAL_SPI_STATE_BUSY
}Hal_Spi_State;

/* SPI BUS STATE */
typedef struct Hal_Spi_Cfg
{
    uint8  			SWChannel;
	uint8  			HWChannel;
}Hal_Spi_Cfg;


extern void Hal_Spi_Init(void);
extern void Hal_Spi_DeInit(void);
extern uint8 Hal_Spi_Open(HAL_SPI_USED_NUM device_id);
extern uint8 Hal_Spi_Close(HAL_SPI_USED_NUM device_id);
extern uint8 Hal_Spi_Transmit(HAL_SPI_USED_NUM device_id,uint8 *write_buffer, uint16 write_buffer_size);

#endif
