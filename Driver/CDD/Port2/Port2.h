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
 * @file:      Port2.h
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
 *  %head of header file guard%
 */
#ifndef __PORT2_H
#define __PORT2_H

/*
 *  %header file in this project/library%
 */
#include "Interrupt.h"
#include "Port2_Cfg.h"


/*
 *  %third-party header file%
 */

//#include "semphr.h"


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
typedef sint8 Port_Return_t;
#define PORT_SUCCESS              (0)
#define PORT_ERROR                (-1)
#define PORT_E_PARAM              (-2)

/* gpio port type */
typedef uint8 Port_Port_t;
#define PORT_PORT_0               (0u)
#define PORT_PORT_1               (1u)
#define PORT_PORT_2               (2u)
#define PORT_PORT_8               (3u)
#define PORT_PORT_9               (4u)
#define PORT_PORT_10              (5u)
#define PORT_PORT_11              (6u)
#define PORT_PORT_12              (7u)
#define PORT_PORT_18              (8u)
#define PORT_PORT_20              (9u)
#define PORT_PORT_A0              (10u)
#define PORT_PORT_A1              (11u)
#define PORT_PORT_NUM             (12u)

/* gpio pin type */
typedef uint16 Port_Pin_t;
#define PORT_PIN_0                BIT(1u, 0)
#define PORT_PIN_1                BIT(1u, 1)
#define PORT_PIN_2                BIT(1u, 2)
#define PORT_PIN_3                BIT(1u, 3)
#define PORT_PIN_4                BIT(1u, 4)
#define PORT_PIN_5                BIT(1u, 5)
#define PORT_PIN_6                BIT(1u, 6)
#define PORT_PIN_7                BIT(1u, 7)
#define PORT_PIN_8                BIT(1u, 8)
#define PORT_PIN_9                BIT(1u, 9)
#define PORT_PIN_10               BIT(1u, 10)
#define PORT_PIN_11               BIT(1u, 11)
#define PORT_PIN_12               BIT(1u, 12)
#define PORT_PIN_13               BIT(1u, 13)
#define PORT_PIN_14               BIT(1u, 14)
#define PORT_PIN_15               BIT(1u, 15)

/* gpio multi function list */
typedef uint8 Port_Func_t;
#define PORT_FUNC_GPIO            (0u)
#define PORT_FUNC_ALT_1           (1u)
#define PORT_FUNC_ALT_2           (2u)
#define PORT_FUNC_ALT_3           (3u)
#define PORT_FUNC_ALT_4           (4u)
#define PORT_FUNC_ALT_5           (5u)
#define PORT_FUNC_ALT_6           (6u)
#define PORT_FUNC_ALT_7           (7u)
#define PORT_FUNC_NUM             (8u)

/* gpio direction list */
typedef uint8 Port_Dir_t;
#define PORT_DIR_IN               (0u)
#define PORT_DIR_OUT              (1u)
#define PORT_DIR_BI               (2u)
#define PORT_DIR_PIPC             (3u)
#define PORT_DIR_NUM              (4u)

/* gpio pin config */
struct Port_Cfg
{
    Port_Dir_t dir;               /* direction */
    Port_Port_t port;             /* port */
    Port_Pin_t pin;               /* pin */
    Port_Func_t func;             /* alternative function */
    boolean initLevel;            /* level after init */
};

/* can0 io alt 1 */
#define PORT_CAN0_RX_SLEEP_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_1, PORT_FUNC_ALT_2, FALSE}
#define PORT_CAN0_TX_SLEEP_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_0, PORT_FUNC_GPIO, FALSE}

#define PORT_CAN0_RX_OPEN_1       {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_1, PORT_FUNC_ALT_2, FALSE}
#define PORT_CAN0_TX_OPEN_1       {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_0, PORT_FUNC_ALT_2, FALSE}

/* can0 io alt 2 */
#define PORT_CAN0_RX_SLEEP_2      {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_0, PORT_FUNC_ALT_2, FALSE}
#define PORT_CAN0_TX_SLEEP_2      {PORT_DIR_OUT, PORT_PORT_10, PORT_PIN_1, PORT_FUNC_GPIO, FALSE}

#define PORT_CAN0_RX_OPEN_2       {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_0, PORT_FUNC_ALT_2, FALSE}
#define PORT_CAN0_TX_OPEN_2       {PORT_DIR_OUT, PORT_PORT_10, PORT_PIN_1, PORT_FUNC_ALT_2, FALSE}

/* can1 io alt 1 */
#define PORT_CAN1_RX_SLEEP_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_2, PORT_FUNC_ALT_2, FALSE}
#define PORT_CAN1_TX_SLEEP_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_3, PORT_FUNC_GPIO, FALSE}

#define PORT_CAN1_RX_OPEN_1       {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_2, PORT_FUNC_ALT_2, FALSE}
#define PORT_CAN1_TX_OPEN_1       {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_3, PORT_FUNC_ALT_2, FALSE}

/* can1 io alt 2 */
#define PORT_CAN1_RX_SLEEP_2      {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_6, PORT_FUNC_ALT_4, FALSE}
#define PORT_CAN1_TX_SLEEP_2      {PORT_DIR_OUT, PORT_PORT_10, PORT_PIN_7, PORT_FUNC_GPIO, FALSE}

#define PORT_CAN1_RX_OPEN_2       {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_6, PORT_FUNC_ALT_4, FALSE}
#define PORT_CAN1_TX_OPEN_2       {PORT_DIR_OUT, PORT_PORT_10, PORT_PIN_7, PORT_FUNC_ALT_4, FALSE}

/* can2 io alt 1 */
#define PORT_CAN2_RX_SLEEP_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_5, PORT_FUNC_ALT_1, FALSE}
#define PORT_CAN2_TX_SLEEP_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_4, PORT_FUNC_GPIO, FALSE}

#define PORT_CAN2_RX_OPEN_1       {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_5, PORT_FUNC_ALT_1, FALSE}
#define PORT_CAN2_TX_OPEN_1       {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_4, PORT_FUNC_ALT_1, FALSE}

/* can3 io alt 1 */
#define PORT_CAN3_RX_SLEEP_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_7, PORT_FUNC_ALT_5, FALSE}
#define PORT_CAN3_TX_SLEEP_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_8, PORT_FUNC_GPIO, FALSE}

#define PORT_CAN3_RX_OPEN_1       {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_7, PORT_FUNC_ALT_5, FALSE}
#define PORT_CAN3_TX_OPEN_1       {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_8, PORT_FUNC_ALT_5, FALSE}

/* can3 io alt 2 */
#define PORT_CAN3_RX_SLEEP_2      {PORT_DIR_IN, PORT_PORT_1, PORT_PIN_2, PORT_FUNC_ALT_1, FALSE}
#define PORT_CAN3_TX_SLEEP_2      {PORT_DIR_OUT, PORT_PORT_1, PORT_PIN_3, PORT_FUNC_GPIO, FALSE}

#define PORT_CAN3_RX_OPEN_2       {PORT_DIR_IN, PORT_PORT_1, PORT_PIN_2, PORT_FUNC_ALT_1, FALSE}
#define PORT_CAN3_TX_OPEN_2       {PORT_DIR_OUT, PORT_PORT_1, PORT_PIN_3, PORT_FUNC_ALT_1, FALSE}

/* can4 io alt 1 */
#define PORT_CAN4_RX_SLEEP_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_9, PORT_FUNC_ALT_5, FALSE}
#define PORT_CAN4_TX_SLEEP_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_10, PORT_FUNC_ALT_5, FALSE}

#define PORT_CAN4_RX_OPEN_1       {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_9, PORT_FUNC_ALT_5, FALSE}
#define PORT_CAN4_TX_OPEN_1       {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_10, PORT_FUNC_ALT_5, FALSE}

/* can5 io alt 1 */
#define PORT_CAN5_RX_SLEEP_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_13, PORT_FUNC_ALT_5, FALSE}
#define PORT_CAN5_TX_SLEEP_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_14, PORT_FUNC_ALT_5, FALSE}

#define PORT_CAN5_RX_OPEN_1       {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_13, PORT_FUNC_ALT_5, FALSE}
#define PORT_CAN5_TX_OPEN_1       {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_14, PORT_FUNC_ALT_5, FALSE}

/* LIN30 io alt 1 */
#define PORT_UART0_RX_CLOSE_1     {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_3, PORT_FUNC_GPIO, FALSE}
#define PORT_UART0_TX_CLOSE_1     {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_2, PORT_FUNC_GPIO, FALSE}

#define PORT_UART0_RX_OPEN_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_3, PORT_FUNC_ALT_2, FALSE}
#define PORT_UART0_TX_OPEN_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_2, PORT_FUNC_ALT_2, TRUE}

/* LIN30 io alt 2 */
#define PORT_UART0_RX_CLOSE_2     {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_9, PORT_FUNC_GPIO, FALSE}
#define PORT_UART0_TX_CLOSE_2     {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_10, PORT_FUNC_GPIO, FALSE}

#define PORT_UART0_RX_OPEN_2      {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_9, PORT_FUNC_ALT_2, FALSE}
#define PORT_UART0_TX_OPEN_2      {PORT_DIR_OUT, PORT_PORT_10, PORT_PIN_10, PORT_FUNC_ALT_2, TRUE}

/* LIN31 io alt 1 */
#define PORT_UART1_RX_CLOSE_1     {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_4, PORT_FUNC_GPIO, FALSE
#define PORT_UART1_TX_CLOSE_1     {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_5, PORT_FUNC_GPIO, FALSE}

#define PORT_UART1_RX_OPEN_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_4, PORT_FUNC_ALT_1, FALSE}
#define PORT_UART1_TX_OPEN_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_5, PORT_FUNC_ALT_1, TRUE}

/* LIN31 io alt 2 */
#define PORT_UART1_RX_CLOSE_2     {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_11, PORT_FUNC_GPIO, FALSE}
#define PORT_UART1_TX_CLOSE_2     {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_12, PORT_FUNC_GPIO, FALSE}

#define PORT_UART1_RX_OPEN_2      {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_11, PORT_FUNC_ALT_2, FALSE}
#define PORT_UART1_TX_OPEN_2      {PORT_DIR_OUT, PORT_PORT_10, PORT_PIN_12, PORT_FUNC_ALT_2, TRUE}

/* LIN32 io alt 1 */
#define PORT_UART2_RX_CLOSE_1     {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_13, PORT_FUNC_GPIO, FALSE
#define PORT_UART2_TX_CLOSE_1     {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_14, PORT_FUNC_GPIO, FALSE}

#define PORT_UART2_RX_OPEN_1      {PORT_DIR_IN, PORT_PORT_0, PORT_PIN_13, PORT_FUNC_ALT_1, FALSE}
#define PORT_UART2_TX_OPEN_1      {PORT_DIR_OUT, PORT_PORT_0, PORT_PIN_14, PORT_FUNC_ALT_1, TRUE}

/* LIN32 io alt 2 */
#define PORT_UART2_RX_CLOSE_2     {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_13, PORT_FUNC_GPIO, FALSE}
#define PORT_UART2_TX_CLOSE_2     {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_14, PORT_FUNC_GPIO, FALSE}

#define PORT_UART2_RX_OPEN_2      {PORT_DIR_IN, PORT_PORT_10, PORT_PIN_13, PORT_FUNC_ALT_2, FALSE}
#define PORT_UART2_TX_OPEN_2      {PORT_DIR_OUT, PORT_PORT_10, PORT_PIN_14, PORT_FUNC_ALT_2, TRUE}

/* LIN33 io alt 1 */
#define PORT_UART3_RX_CLOSE_1     {PORT_DIR_IN, PORT_PORT_1, PORT_PIN_0, PORT_FUNC_GPIO, FALSE
#define PORT_UART3_TX_CLOSE_1     {PORT_DIR_IN, PORT_PORT_1, PORT_PIN_1, PORT_FUNC_GPIO, FALSE}

#define PORT_UART3_RX_OPEN_1      {PORT_DIR_IN, PORT_PORT_1, PORT_PIN_0, PORT_FUNC_ALT_1, FALSE}
#define PORT_UART3_TX_OPEN_1      {PORT_DIR_OUT, PORT_PORT_1, PORT_PIN_1, PORT_FUNC_ALT_1, TRUE}

/* LIN33 io alt 2 */
#define PORT_UART3_RX_CLOSE_2     {PORT_DIR_IN, PORT_PORT_11, PORT_PIN_6, PORT_FUNC_GPIO, FALSE}
#define PORT_UART3_TX_CLOSE_2     {PORT_DIR_IN, PORT_PORT_11, PORT_PIN_5, PORT_FUNC_GPIO, FALSE}

#define PORT_UART3_RX_OPEN_2      {PORT_DIR_IN, PORT_PORT_11, PORT_PIN_6, PORT_FUNC_ALT_1, FALSE}
#define PORT_UART3_TX_OPEN_2      {PORT_DIR_OUT, PORT_PORT_11, PORT_PIN_5, PORT_FUNC_ALT_1, TRUE}

extern const struct Port_Cfg port_cfgs[PORT_ID_NUMBER];

/*
 *  %function declaration%
 */
Port_Return_t Port2_Init(Port_Id_t id);
Port_Return_t Port2_Deinit(Port_Id_t id);
Port_Return_t Port2_Get(Port_Id_t id, boolean *result);
Port_Return_t Port2_Set(Port_Id_t id, boolean level);
Port_Return_t Port2_Toggle(Port_Id_t id);
Port_Return_t Port2_OpenDrainSet(Port_Id_t id, boolean state);
Port_Return_t Port2_PushPullSet(Port_Id_t id, boolean state);
Port_Return_t Port2_StrengthSet(Port_Id_t id, boolean state);

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

