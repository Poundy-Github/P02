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
 * @file:      csih_spi.h
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

#ifndef _CSIH_H_
#define _CSIH_H_

#include "Platform_Types.h"

#define CSIH0_RX_ADDR       (0xFFD80000+0x1014)
#define CSIH0_TX_ADDR       (0xFFD80000+0x100C)

#define CSIH1_RX_ADDR       (0xFFD82000+0x1014)
#define CSIH1_TX_ADDR       (0xFFD82000+0x100C)

#define CSIH2_RX_ADDR       (0xFFD84000+0x1014)
#define CSIH2_TX_ADDR       (0xFFD84000+0x100C)

#define CSIH3_RX_ADDR       (0xFFD86000+0x1014)
#define CSIH3_TX_ADDR       (0xFFD86000+0x100C)


#define SPI_BUS_CSIH0	0
#define SPI_BUS_CSIH1	1
#define SPI_BUS_CSIH2	2
#define SPI_BUS_CSIH3	3
#define SPI_BUS_MAX     4


extern void csih_init_to_slave(uint8 csih_numb);
extern void csih_slave_send_data(uint8 csih_numb,uint8 tx_buf);
extern void csih_close(uint8 csih_numb);

#endif
