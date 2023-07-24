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
 * @file:      RingBuffer_Cfg.c
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
#include "RingBuffer_Cfg.h"
#include "RingBuffer.h"
#include "Std_Types.h"
#include "logger.h"


/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */


#if(LOGGER_IPC_BUFFER_FIT_DATA == 1)

#define RB_LOGGER_IPC_ELEMENT_SIZE      (1)

#define RB_LOGGER_IPC_ELEMENT_NUMBER    (33000)//300*110

#define RB_LOGGER_IPC_BUFFER_SIZE      	((RB_LOGGER_IPC_ELEMENT_NUMBER) * (RB_LOGGER_IPC_ELEMENT_SIZE))


#else

#define RB_LOGGER_IPC_ELEMENT_NUMBER    (180u)

#define RB_LOGGER_IPC_ELEMENT_SIZE      sizeof(Ipc_Data_t)

#define RB_LOGGER_IPC_BUFFER_SIZE       ((RB_LOGGER_IPC_ELEMENT_NUMBER) * (RB_LOGGER_IPC_ELEMENT_SIZE))


#endif







/*
 *  %forward declaration%
 */

#pragma ghs section bss = ".IPC_SHARE_NOINIT_DATA" 
#pragma ghs section data = ".IPC_SHARE_INIT_DATA" 
/*
 *  %global definition%
 */
uint8_t rb_testBuffer[RB_TEST_BUFFER_SIZE] = {0};
uint8_t rb_loggerUartBuffer[RB_LOGGER_UART_BUFFER_SIZE] = {0};
uint8_t rb_iicQueue0Buffer[RB_I2C_QUEUE0_BUFFER_SIZE] = {0};
uint8_t rb_iicQueue1Buffer[RB_I2C_QUEUE1_BUFFER_SIZE] = {0};
uint8_t rb_CmdInputBuffer[RB_CMD_INPUT_BUFFER_SIZE] = {0};
uint8_t rb_GPSUartTxBuffer[RB_GPS_UART_TX_BUFFER_SIZE] = {0};
uint8_t rb_GPSUartRxBuffer[RB_GPS_UART_RX_BUFFER_SIZE] = {0};
uint8_t rb_GyroIpcBuffer[RB_GYRO_IPC_BUFFER_SIZE] = {0};
uint8_t rb_AMP1QueueBuffer[RB_AMP1_QUEUE_BUFFER_SIZE] = {0};
uint8_t rb_AMP2QueueBuffer[RB_AMP2_QUEUE_BUFFER_SIZE] = {0};

#pragma ghs section bss=default
#pragma ghs section data=default


#pragma ghs startdata
#pragma ghs section bss=".LogContext"
uint8_t rb_loggerIpcBuffer[RB_LOGGER_IPC_BUFFER_SIZE];
RB_BackupStorage_t rb_loggerIpcBackupBuffer;
#pragma ghs section bss=default
#pragma ghs enddata

#pragma ghs section bss = ".IPC_SHARE_NOINIT_DATA" 
#pragma ghs section data = ".IPC_SHARE_INIT_DATA" 

struct RB_Data rb_datas[RB_ID_NUMBER] = {0};

#pragma ghs section bss=default
#pragma ghs section data=default

const struct RB_Cfg rb_cfgs[RB_ID_NUMBER] =
{
    {rb_testBuffer, rb_testBuffer + RB_TEST_BUFFER_SIZE, NULL_PTR, RB_TEST_ELEMENT_SIZE, RB_TEST_ELEMENT_NUMBER, FALSE, FALSE, FALSE},
    {rb_loggerUartBuffer, rb_loggerUartBuffer + RB_LOGGER_UART_BUFFER_SIZE, NULL_PTR, RB_LOGGER_UART_ELEMENT_SIZE, RB_LOGGER_UART_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
    {rb_loggerIpcBuffer, rb_loggerIpcBuffer + RB_LOGGER_IPC_BUFFER_SIZE, &rb_loggerIpcBackupBuffer, RB_LOGGER_IPC_ELEMENT_SIZE, RB_LOGGER_IPC_ELEMENT_NUMBER, TRUE, FALSE, TRUE},
    {rb_iicQueue0Buffer, rb_iicQueue0Buffer + RB_I2C_QUEUE0_BUFFER_SIZE, NULL_PTR, RB_I2C_QUEUE0_ELEMENT_SIZE, RB_I2C_QUEUE0_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
    {rb_iicQueue1Buffer, rb_iicQueue1Buffer + RB_I2C_QUEUE1_BUFFER_SIZE, NULL_PTR, RB_I2C_QUEUE1_ELEMENT_SIZE, RB_I2C_QUEUE1_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
    {rb_CmdInputBuffer, rb_CmdInputBuffer + RB_CMD_INPUT_BUFFER_SIZE, NULL_PTR, RB_CMD_INPUT_ELEMENT_SIZE, RB_CMD_INPUT_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
    {rb_GPSUartTxBuffer, rb_GPSUartTxBuffer + RB_GPS_UART_TX_BUFFER_SIZE, NULL_PTR, RB_GPS_UART_TX_ELEMENT_SIZE, RB_GPS_UART_TX_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
    {rb_GPSUartRxBuffer, rb_GPSUartRxBuffer + RB_GPS_UART_RX_BUFFER_SIZE, NULL_PTR, RB_GPS_UART_RX_ELEMENT_SIZE, RB_GPS_UART_RX_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
    {rb_GyroIpcBuffer, rb_GyroIpcBuffer + RB_GYRO_IPC_BUFFER_SIZE, NULL_PTR, RB_GYRO_IPC_BUFFER_ELEMENT_SIZE, RB_GYRO_IPC_BUFFER_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
    {rb_AMP1QueueBuffer, rb_AMP1QueueBuffer + RB_AMP1_QUEUE_BUFFER_SIZE, NULL_PTR, RB_AMP1_QUEUE_ELEMENT_SIZE, RB_AMP1_QUEUE_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
    {rb_AMP2QueueBuffer, rb_AMP2QueueBuffer + RB_AMP2_QUEUE_BUFFER_SIZE, NULL_PTR, RB_AMP2_QUEUE_ELEMENT_SIZE, RB_AMP2_QUEUE_ELEMENT_NUMBER, TRUE, FALSE, FALSE},
};


/*
 *  %function definition%
 */


