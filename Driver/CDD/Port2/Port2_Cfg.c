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
 * @file:      Port2_Cfg.c
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
#include "Port2_cfg.h"
#include "Port2.h"

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

/*
 *  %global definition%
 */
const struct Port_Cfg port_cfgs[PORT_ID_NUMBER] =
{
    {PORT_DIR_OUT, PORT_PORT_10, PORT_PIN_3, PORT_FUNC_GPIO, TRUE},
    {PORT_DIR_OUT, PORT_PORT_8, PORT_PIN_5, PORT_FUNC_GPIO, TRUE},
    PORT_CAN3_RX_SLEEP_2,
    PORT_CAN3_TX_SLEEP_2,
    PORT_CAN3_RX_OPEN_2,
    PORT_CAN3_TX_OPEN_2,
    {PORT_DIR_OUT, PORT_PORT_1, PORT_PIN_4, PORT_FUNC_GPIO, TRUE},
    PORT_UART0_RX_CLOSE_1,
    PORT_UART0_TX_CLOSE_1,
    PORT_UART0_RX_OPEN_1,
    PORT_UART0_TX_OPEN_1,
};


/*
 *  %function definition%
 */



/*
* @brief   :
* @param   :
* @retval  :
*/


