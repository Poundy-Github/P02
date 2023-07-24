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
 * @file:      logger_cfg.h
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
#ifndef __LOGGER_CFG_H
#define __LOGGER_CFG_H

/*
 *  %header file in this project/library%
 */


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
#include <stdint.h>
/*
 *  %type definition%
 */
#define LOGGER_DEV_ERROR_DETECT             STD_ON
 
#define LOGGER_ENTER_CRITICAL()             Rte_Enter_ExclusiveArea_Log()
#define LOGGER_EXIT_CRITICAL()              Rte_Exit_ExclusiveArea_Log()

#define LOGGER_RES_INIT()                 
#define LOGGER_RES_LOCK()                   Rte_Enter_ExclusiveArea_Log()
#define LOGGER_RES_UNLOCK()                 Rte_Exit_ExclusiveArea_Log()


/* Logger data flow control */
#define LOGGER_EN_STORE_PARA_POINTER    (0)/* Enable parameter data flow */

#if(LOGGER_EN_STORE_PARA_POINTER == 1)

#define LOGGER_UART_HEAD_SIZE               (2u)

#define LOGGER_MAX_PARA_NUM                 (6u)
#define LOGGER_TOTAL_PARA_NUM			    (LOGGER_MAX_PARA_NUM + 3u)// para + time + version


#define CONTROL_DATA_BYTES                  (LOGGER_UART_HEAD_SIZE + 4)//header + ml + len + sum
#define LOGGER_MAX_DATA_BYTES               (LOGGER_TOTAL_PARA_NUM * 4 + CONTROL_DATA_BYTES)

#define LOGGER_NONE_PARA                    (0x55aa1234u)

#define LOGGER_IPC_PARA_NUM                 (LOGGER_MAX_PARA_NUM + 1)//para + version  

#define LOGGER_MODE_NAME_MAX_LEN            (16)
#define LOGGER_DATA_SIZE                    (LOGGER_IPC_PARA_NUM * 4)

#else


#define LOGGER_IPC_BUFFER_FIT_DATA          (1)/* enable varaible IPC buffer size */

#define LOGGER_MODE_NAME_MAX_LEN            (16)
#define LOGGER_DATA_SIZE                    (100u)
#define LOGGER_UART_HEAD_SIZE               (30)

#endif




// TODO: < REPLACE START >
#include "RTC.h"
#define GetSystemTick                     RTC_GetTime 
// TODO: < REPLACE END >
 
#define sys_info(...)   Logger_String(LOGGER_MODULE_GENERAL, LOGGER_LEVEL_INFO, __VA_ARGS__ )

 
#define sys_warn(...)   Logger_String(LOGGER_MODULE_GENERAL, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define sys_err(...)    Logger_String(LOGGER_MODULE_GENERAL, LOGGER_LEVEL_ERR, __VA_ARGS__ )

#define can_info(...)   Logger_String(LOGGER_MODULE_CAN, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define can_warn(...)   Logger_String(LOGGER_MODULE_CAN, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define can_err(...)    Logger_String(LOGGER_MODULE_CAN, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define can_debug(...)   Logger_String(LOGGER_MODULE_CAN, LOGGER_LEVEL_DEBUG, __VA_ARGS__ )
#define can_verbose(...)   Logger_String(LOGGER_MODULE_CAN, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define spi_info(...)   Logger_String(LOGGER_MODULE_SPI, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define spi_warn(...)   Logger_String(LOGGER_MODULE_SPI, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define spi_err(...)    Logger_String(LOGGER_MODULE_SPI, LOGGER_LEVEL_ERR, __VA_ARGS__ )

#define rtc_info(...)   Logger_String(LOGGER_MODULE_RTC, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define rtc_warn(...)   Logger_String(LOGGER_MODULE_RTC, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define rtc_err(...)    Logger_String(LOGGER_MODULE_RTC, LOGGER_LEVEL_ERR, __VA_ARGS__ )

#define ipc_info(...)   Logger_String(LOGGER_MODULE_IPC, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define ipc_warn(...)   Logger_String(LOGGER_MODULE_IPC, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define ipc_err(...)    Logger_String(LOGGER_MODULE_IPC, LOGGER_LEVEL_ERR, __VA_ARGS__ )

#define amp_info(...)   Logger_String(LOGGER_MODULE_AMP, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define amp_warn(...)   Logger_String(LOGGER_MODULE_AMP, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define amp_err(...)    Logger_String(LOGGER_MODULE_AMP, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define amp_debug(...)  Logger_String(LOGGER_MODULE_AMP, LOGGER_LEVEL_DEBUG, __VA_ARGS__ )
#define amp_verbose(...)Logger_String(LOGGER_MODULE_AMP, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define adau1978_info(...)      Logger_String(LOGGER_MODULE_ADC, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define adau1978_warn(...)      Logger_String(LOGGER_MODULE_ADC, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define adau1978_err(...)       Logger_String(LOGGER_MODULE_ADC, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define adau1978_debug(...)     Logger_String(LOGGER_MODULE_ADC, LOGGER_LEVEL_DEBUG, __VA_ARGS__ )
#define adau1978_verbose(...)   Logger_String(LOGGER_MODULE_ADC, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define gyro_info(...)   Logger_String(LOGGER_MODULE_GYRO, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define gyro_warn(...)   Logger_String(LOGGER_MODULE_GYRO, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define gyro_err(...)    Logger_String(LOGGER_MODULE_GYRO, LOGGER_LEVEL_ERR, __VA_ARGS__ )

#define power_info(...)   Logger_String(LOGGER_MODULE_POWER, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define power_warn(...)   Logger_String(LOGGER_MODULE_POWER, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define power_err(...)    Logger_String(LOGGER_MODULE_POWER, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define power_debug(...)  Logger_String(LOGGER_MODULE_POWER, LOGGER_LEVEL_DEBUG, __VA_ARGS__ )
#define power_verbose(...)  Logger_String(LOGGER_MODULE_POWER,LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define misc_info(...)   Logger_String(LOGGER_MODULE_MISC, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define misc_warn(...)   Logger_String(LOGGER_MODULE_MISC, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define misc_err(...)    Logger_String(LOGGER_MODULE_MISC, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define misc_verbose(...)   Logger_String(LOGGER_MODULE_MISC, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define gnss_info(...)   Logger_String(LOGGER_MODULE_GNSS, LOGGER_LEVEL_INFO, __VA_ARGS__)
#define gnss_warn(...)   Logger_String(LOGGER_MODULE_GNSS, LOGGER_LEVEL_WARN, __VA_ARGS__)
#define gnss_err(...)    Logger_String(LOGGER_MODULE_GNSS, LOGGER_LEVEL_ERR, __VA_ARGS__)
#define gnss_verbose(...)   Logger_String(LOGGER_MODULE_GNSS, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define upgrade_info(...)   Logger_String(LOGGER_MODULE_UPGRADE, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define upgrade_warn(...)   Logger_String(LOGGER_MODULE_UPGRADE, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define upgrade_err(...)    Logger_String(LOGGER_MODULE_UPGRADE, LOGGER_LEVEL_ERR, __VA_ARGS__ )


#define dtc_err(...)      Logger_String(LOGGER_MODULE_DTC, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define dtc_Verbose(...)  Logger_String(LOGGER_MODULE_DTC, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define fuel_info(...)   Logger_String(LOGGER_MODULE_FUEL, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define fuel_warn(...)   Logger_String(LOGGER_MODULE_FUEL, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define fuel_err(...)    Logger_String(LOGGER_MODULE_FUEL, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define fuel_verbose(...)   Logger_String(LOGGER_MODULE_FUEL, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define tripcomputer_info(...)   Logger_String(LOGGER_MODULE_TC, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define tripcomputer_warn(...)   Logger_String(LOGGER_MODULE_TC, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define tripcomputer_err(...)    Logger_String(LOGGER_MODULE_TC, LOGGER_LEVEL_ERR, __VA_ARGS__ )

#define crypto_info(...)   Logger_String(LOGGER_MODULE_CRYPTO, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define crypto_warn(...)   Logger_String(LOGGER_MODULE_CRYPTO, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define crypto_err(...)    Logger_String(LOGGER_MODULE_CRYPTO, LOGGER_LEVEL_ERR, __VA_ARGS__ )

#define gw_info(...)   Logger_String(LOGGER_MODULE_GW, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define gw_debug(...)   Logger_String(LOGGER_MODULE_GW, LOGGER_LEVEL_DEBUG, __VA_ARGS__ )
#define gw_verbose(...)   Logger_String(LOGGER_MODULE_GW, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )
#define gw_warn(...)   Logger_String(LOGGER_MODULE_GW, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define gw_err(...)    Logger_String(LOGGER_MODULE_GW, LOGGER_LEVEL_ERR, __VA_ARGS__ )

#define vipodo_info(...)   Logger_String(LOGGER_MODULE_VIPODO, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define vipodo_warn(...)   Logger_String(LOGGER_MODULE_VIPODO, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define vipodo_err(...)    Logger_String(LOGGER_MODULE_VIPODO, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define vipodo_verbose(...)    Logger_String(LOGGER_MODULE_VIPODO, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )
#define vipodo_level(level,...)    Logger_String(LOGGER_MODULE_VIPODO, level, __VA_ARGS__ )

#define vipChime_info(...)   Logger_String(LOGGER_MODULE_VIPCHIME, LOGGER_LEVEL_INFO, __VA_ARGS__ )
#define vipChime_warn(...)   Logger_String(LOGGER_MODULE_VIPCHIME, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define vipChime_err(...)    Logger_String(LOGGER_MODULE_VIPCHIME, LOGGER_LEVEL_ERR, __VA_ARGS__ )
#define vipChime_verbose(...)    Logger_String(LOGGER_MODULE_VIPCHIME, LOGGER_LEVEL_VERBOSE, __VA_ARGS__ )

#define MenuSet_debug(...) 	 Logger_String(LOGGER_MODULE_MENUSET, LOGGER_LEVEL_WARN, __VA_ARGS__ )
#define Gear_warn(...)  (void)Logger_String(LOGGER_MODULE_GEAR, LOGGER_LEVEL_WARN, __VA_ARGS__)

// Before adding a module, confirm with the IVI
// @reference: http://10.52.245.125:8090/display/PROJV3X/Log+modules+in+system

typedef uint8_t Logger_Module_t;
#define LOGGER_MODULE_GENERAL               (0u)
#define LOGGER_MODULE_CAN                   (1u)
#define LOGGER_MODULE_SPI                   (2u)
#define LOGGER_MODULE_RTC                   (3u)
#define LOGGER_MODULE_IPC                   (4u)
#define LOGGER_MODULE_AMP                   (5u)
#define LOGGER_MODULE_GYRO                  (6u)
#define LOGGER_MODULE_POWER                 (7u)
#define LOGGER_MODULE_SOCM                  (8u)
#define LOGGER_MODULE_MISC                  (9u)
#define LOGGER_MODULE_DTC                   (10u)
#define LOGGER_MODULE_SAFETY                (11u)
#define LOGGER_MODULE_FUEL                  (12u)
#define LOGGER_MODULE_TC                    (13u)
#define LOGGER_MODULE_GW                    (14u)
#define LOGGER_MODULE_NUMBER                (15u)

#define LOGGER_MODULE_UPGRADE               (LOGGER_MODULE_MISC)
#define LOGGER_MODULE_ADC                   (LOGGER_MODULE_MISC)
#define LOGGER_MODULE_CRYPTO                (LOGGER_MODULE_MISC)
#define LOGGER_MODULE_GNSS                  (LOGGER_MODULE_MISC)
#define LOGGER_MODULE_VIPODO                (LOGGER_MODULE_TC)
#define LOGGER_MODULE_VIPCHIME              (LOGGER_MODULE_TC)
#define LOGGER_MODULE_MENUSET               (LOGGER_MODULE_TC)
#define LOGGER_MODULE_GEAR                  (LOGGER_MODULE_TC)


typedef uint8_t Logger_Level_t;
#define LOGGER_LEVEL_OFF                (0x00)
#define LOGGER_LEVEL_FATAL              (0x01)
#define LOGGER_LEVEL_ERR                (0x02)
#define LOGGER_LEVEL_WARN               (0x03)
#define LOGGER_LEVEL_INFO               (0x04)
#define LOGGER_LEVEL_DEBUG              (0x05)
#define LOGGER_LEVEL_VERBOSE            (0x06)
#define LOGGER_LEVEL_NUMBER             (0x07)


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
