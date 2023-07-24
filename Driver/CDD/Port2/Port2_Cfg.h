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
 * @file:      Port2_Cfg.h
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
 *             %head of header file guard%
 */
#ifndef __PORT2_CFG_H
#define __PORT2_CFG_H

/*
 *  %header file in this project/library%
 */
#include "Platform_Types.h"


/*
 *  %third-party header file%
 */

/*
 *  %system/C-run-time header file%
 */



/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */
typedef uint8 Port_Id_t;
#define PORT_ID_LED1                      (0u)
#define PORT_ID_LED2                      (1u)
#define PORT_ID_CAN3_RX_SLEEP             (2u)
#define PORT_ID_CAN3_TX_SLEEP             (3u)
#define PORT_ID_CAN3_RX_OPEN              (4u)
#define PORT_ID_CAN3_TX_OPEN              (5u)
#define PORT_ID_CAN3_STBY                 (6u)
#define PORT_ID_UART0_RX_CLOSE            (7u)
#define PORT_ID_UART0_TX_CLOSE            (8u)
#define PORT_ID_UART0_RX_OPEN             (9u)
#define PORT_ID_UART0_TX_OPEN             (10u)
#define PORT_ID_NUMBER                    (11u)

#define PORT2_DEV_ERROR_DETECT            STD_ON

/*
 *  %function declaration%
 */



/*
 *  %bottom of extern "C" declaration%
 */
#ifdef __cplusplus
}
#endif

/*
 *  %bottom of header file guard%
 */
#endif
