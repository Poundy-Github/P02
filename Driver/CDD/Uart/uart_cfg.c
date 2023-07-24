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
 * @file:      uart_cfg.c
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

/*
 *  %header file in this project/library%
 */
#include "HwConfig.h"
#include "Compiler.h"
#include "Uart_Cfg.h"
#include "Uart.h"
#include "Logger.h"
#include "Port2.h"
#include "CDD_Test.h"
#include "GPS_Test.h"
/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */



/*
 *  %forward declaration%
 */
static void UartInitCallback(Uart_Id_t id);
static void UartOpenCallback(Uart_Id_t id);


/*
 *  %global definition%
 */
struct Uart_Data uart_datas[UART_ID_NUMBER] = {0};

const struct Uart_Cfg uart_cfgs[UART_ID_NUMBER] =
{
    {5u, UART_PIN_ALT_1, INT_PRIORITY_LEVEL7, UART_BAUDRATE_115200, CRITICAL_TYPE_ISR_I,
    UartInitCallback, NULL_PTR, UartOpenCallback, NULL_PTR,
    Logger_UartTransmitCallback, Logger_UartTransmitFinishCallback, NULL_PTR, NULL_PTR},

    {4u, UART_PIN_ALT_4, INT_PRIORITY_LEVEL7, UART_BAUDRATE_115200, CRITICAL_TYPE_ISR_I,
    NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR,
    GPS_UartTransmitCallback, GPS_UartTransmitFinishCallback, NULL_PTR, NULL_PTR},

};

static void UartInitCallback(Uart_Id_t id)
{
    switch(id)
    {
        case UART_ID_LOGGER:
//        Port2_Init(PORT_ID_UART0_RX_CLOSE);
//        Port2_Init(PORT_ID_UART0_TX_CLOSE);
        break;

        default:
        /*Do Nothing*/
        break;
    }
}

static void UartOpenCallback(Uart_Id_t id)
{
    switch(id)
    {
        case UART_ID_LOGGER:
        /* Port initialization is handled by MCAL */
//        Port2_Init(PORT_ID_UART0_RX_OPEN);
//        Port2_Init(PORT_ID_UART0_TX_OPEN);
        break;

        default:
        /*Do Nothing*/
        break;
    }
}

/*
 *  %function definition%
 */

