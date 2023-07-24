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
 * @file:      logger.h
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
#ifndef __LOGGER_H
#define __LOGGER_H

/*
 *  %header file in this project/library%
 */
#include <stdint.h>
#include "Logger_Cfg.h"
#include "RingBuffer.h"
#include "Uart.h"


/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */
#include <stdarg.h>


/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
    extern "C" {
#endif

/*
 *  %type definition%
 */
/* logger return type */
typedef int8_t Logger_Return_t;
/* operation success */
#define LOGGER_SUCCESS              (0)
/* this flag is initialized error and should not be returned
   if this flag returned, there should be software design error */
#define LOGGER_ERROR                (-1)
/* parameter error */
#define LOGGER_E_PARAM              (-2)
/* logger state error */
#define LOGGER_E_STATE              (-3)

/*string without end 0x00*/
typedef struct StrNoEnd
{
    char *str;
    uint32_t len;
}StrNoEnd_t;

/*logger_data config*/
typedef struct Logger_Cfg
{
    uint8_t chnUart;            /* uart channel */
    RB_Id_t rbUart;             /* uart ring buffer */
    boolean needIpc;               /* if transfer to ipc */
    RB_Id_t rbIpc;              /* ipc ring buffer */
    uint32_t subNumber;         /* submodule number */
    char **subNames;            /* submodule names */
    uint8_t *subLevelStorage;   /* submodule state storage */
    uint32_t levelNumber;       /* level number */
    char **levelNames;          /* level names */
}Logger_Cfg_t;

typedef struct Ipc_Data
{
    #if (LOGGER_IPC_BUFFER_FIT_DATA == 1)
    uint8 header0;
    uint8 header1;
	uint8 length;
    #endif
    uint8 mdlID;
    uint8 level;

	uint8 timestamp[8]; 
    uint8 buffer[LOGGER_DATA_SIZE];
}Ipc_Data_t;

#if (LOGGER_IPC_BUFFER_FIT_DATA == 1)

#define IPC_DATA_TYPE_SIZE          (1u)

#else

#define IPC_DATA_TYPE_SIZE          sizeof(Ipc_Data_t)

#endif



/* state of looger during operation */
typedef uint8_t Logger_State_t;
/* logger module is not initialized */
#define LOGGER_STATE_NOT_INIT       (0u)
/* logger module is initializ and close state */
#define LOGGER_STATE_CLOSE          (1u)
/* logger module is open state */
#define LOGGER_STATE_OPEN           (2u)
/* logger module state number */
#define LOGGER_STATE_NUMBER         (3u)

/* output format type */
typedef uint8_t Logger_Format_t;
/* level, sub module name and tick display */
#define LOGGER_FORMAT_ALL           (0u)
/* level and tick display */
#define LOGGER_FORMAT_TICK          (1u)
/* level and sub module name display */
#define LOGGER_FORMAT_SUB           (2u)
/* only level display */
#define LOGGER_FORMAT_NONE          (3u)
/* logger format number */
#define LOGGER_FORMAT_NUMBER        (4u)

typedef uint16 Logger_Len_t;
extern const struct Logger_Cfg logger_cfg;

/*
 *  %function declaration%
 */

void Logger_Init(void);
Logger_Return_t Logger_Open(void);
Logger_Return_t Logger_String(Logger_Module_t module, Logger_Level_t level,const char *fmt, ...);
Logger_Return_t Logger_LevelSet(Logger_Module_t module, Logger_Level_t level);
void Logger_UartTransmitCallback(Uart_Id_t id, uint8_t *data, uint8_t *length);
void Logger_UartTransmitFinishCallback(Uart_Id_t id, uint8_t *data, uint8_t *length);
Logger_Return_t Logger_StringFromCLI(const char*fmt, ...);

Logger_Return_t Logger_LevelSetAll(Logger_Level_t level);
Logger_Return_t  Logger_GetModeId(uint8 * name, uint8 * id);
void Log_ColdResetCallout(void);

char* Hex2Str(uint8 *hex, int hexLen);

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
