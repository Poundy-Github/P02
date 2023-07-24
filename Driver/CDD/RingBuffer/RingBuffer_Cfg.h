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
 * @file:      RingBuffer_Cfg.h
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
#ifndef _RB_CFG_H
#define _RB_CFG_H

/*
 *  %header file in this project/library%
 */
//#include "Resource.h"


/*
 *  %third-party header file%
 */
//#include "FreeRTOS.h" 
//#include "task.h" 
#include <stdint.h>

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
typedef uint8_t RB_Id_t;

#define RB_DEV_ERROR_DETECT             STD_ON

#define RB_ID_TEST                      (0u)
#define RB_ID_LOGGER_UART               (1u)
#define RB_ID_LOGGER_IPC                (2u)
#define RB_ID_I2C_QUEUE0                (3u)
#define RB_ID_I2C_QUEUE1                (4u)
#define RB_ID_CMD_INPUT                 (5u)
#define RB_ID_GPS_UART_TX               (6u)
#define RB_ID_GPS_UART_RX               (7u)
#define RB_ID_GYRO_IPC                  (8u)
#define RB_ID_AMP1_QUEUE                (9u)
#define RB_ID_AMP2_QUEUE                (10u)
#define RB_ID_NUMBER                    (11u)

#define RB_TEST_BUFFER_SIZE             (100u)
#define RB_TEST_ELEMENT_SIZE            (5u)
#define RB_TEST_ELEMENT_NUMBER          (20u)

#define RB_LOGGER_UART_BUFFER_SIZE      (6144u)
#define RB_LOGGER_UART_ELEMENT_SIZE     (1u)
#define RB_LOGGER_UART_ELEMENT_NUMBER   (6144u)



#define RB_I2C_QUEUE0_BUFFER_SIZE         (100u)
#define RB_I2C_QUEUE0_ELEMENT_SIZE        (1u)
#define RB_I2C_QUEUE0_ELEMENT_NUMBER      (100u)

#define RB_I2C_QUEUE1_BUFFER_SIZE         (100u)
#define RB_I2C_QUEUE1_ELEMENT_SIZE        (1u)
#define RB_I2C_QUEUE1_ELEMENT_NUMBER      (100u)

#define RB_CMD_INPUT_BUFFER_SIZE         (100u)
#define RB_CMD_INPUT_ELEMENT_SIZE        (1u)
#define RB_CMD_INPUT_ELEMENT_NUMBER      (100u)

#define RB_GPS_UART_TX_BUFFER_SIZE         (100u)
#define RB_GPS_UART_TX_ELEMENT_SIZE        (1u)
#define RB_GPS_UART_TX_ELEMENT_NUMBER      (100u)

#define RB_GPS_UART_RX_BUFFER_SIZE         (4000u)
#define RB_GPS_UART_RX_ELEMENT_SIZE        (1u)
#define RB_GPS_UART_RX_ELEMENT_NUMBER      (4000u)

#define RB_GYRO_IPC_BUFFER_SIZE                 (100u)
#define RB_GYRO_IPC_BUFFER_ELEMENT_SIZE         (1u)
#define RB_GYRO_IPC_BUFFER_ELEMENT_NUMBER       (100u)

#define RB_AMP1_QUEUE_BUFFER_SIZE                (50u)
#define RB_AMP1_QUEUE_ELEMENT_SIZE               (1u)
#define RB_AMP1_QUEUE_ELEMENT_NUMBER             (50u)

#define RB_AMP2_QUEUE_BUFFER_SIZE                (50u)
#define RB_AMP2_QUEUE_ELEMENT_SIZE               (1u)
#define RB_AMP2_QUEUE_ELEMENT_NUMBER             (50u)

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
