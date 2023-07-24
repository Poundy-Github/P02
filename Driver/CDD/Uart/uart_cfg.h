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
 * @file:      uart_cfg.h
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
#ifndef __UART_CFG_H
#define __UART_CFG_H

/*
 *  %header file in this project/library%
 */
#include "Platform_Types.h"


/*
 *  %third-party header file%
 */
//#include "FreeRTOS.h"
//#include "task.h"



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
#define UART_DEV_ERROR_DETECT           STD_ON

#define UART_ENTER_CRITICAL()           Rte_Enter_ExclusiveArea_Log()
#define UART_EXIT_CRITICAL()            Rte_Exit_ExclusiveArea_Log()

#define UART_RES_INIT(id)
#define UART_RES_LOCK(id)               //Rte_Enter_ExclusiveArea_Log()
#define UART_RES_UNLOCK(id)             //Rte_Exit_ExclusiveArea_Log()

typedef uint8 Uart_Id_t;
#define UART_ID_LOGGER                  (0u)
#define UART_ID_GPS                     (1u)
#define UART_ID_NUMBER                  (2u)

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
