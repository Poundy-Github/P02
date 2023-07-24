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
 * @file:      logger_cfg.c
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
#include "Rte_Log.h"
#include "Logger_Cfg.h"
#include "Logger.h"
#include "Uart_Cfg.h"


/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */
#define LOGGER_THRESHOLD    (50u)


/*
 *  %forward declaration%
 */


/*
 *  %global definition%
 */
#pragma ghs startdata
#pragma ghs section bss=".LogContext"
static uint8_t loggerLevelStorage[LOGGER_MODULE_NUMBER];
#pragma ghs section bss=default
#pragma ghs enddata

static char *loggerModuleNames[LOGGER_MODULE_NUMBER] = {"SYS", "CAN","SPI","RTC","IPC","AMP","GYRO","POWER","SOCM","MISC","DTC","SAFETY","FUEL","TC","IPC_GATEWAY"};

static char *logger_level_names[LOGGER_LEVEL_NUMBER] = {"OFF","FATAL","ERROR","WARN","INFO","DEBUG","VERBOSE"};

const struct Logger_Cfg logger_cfg =
{
    UART_ID_LOGGER, RB_ID_LOGGER_UART, FALSE, RB_ID_LOGGER_IPC,
    LOGGER_MODULE_NUMBER, loggerModuleNames, loggerLevelStorage,
    LOGGER_LEVEL_NUMBER, logger_level_names
};

/*
 *  %function definition%
 */




