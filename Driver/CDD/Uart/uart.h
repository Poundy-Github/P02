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
 * @file:      uart.h
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
#ifndef __UART_H
#define __UART_H

/*
 *  %header file in this project/library%
 */
#include "Uart_Cfg.h"
#include "Interrupt.h"



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
#define UART_CHN_NUM            (6u)
#define UART_HW_BUF_SIZE        (8u)

typedef sint8 Uart_Return_t;
#define UART_SUCCESS            (0)
#define UART_ERROR              (-1)
#define UART_E_PARAM            (-2)
#define UART_E_STATE            (-3)
#define UART_E_OCCUPY           (-4)

typedef uint8 Uart_State_t;
#define UART_STATE_NOT_INIT     (0u)
#define UART_STATE_CLOSE        (1u)
#define UART_STATE_OPEN         (2u)
#define UART_STATE_NUMBER       (3u)

typedef uint32 Uart_Baudrate_t;
#define UART_BAUDRATE_9600      (9600u)
#define UART_BAUDRATE_19200     (19200u)
#define UART_BAUDRATE_38400     (38400u)
#define UART_BAUDRATE_57600     (57600u)
#define UART_BAUDRATE_115200    (115200u)

typedef uint8 Uart_PinAlt_t;
#define UART_PIN_ALT_1          (0u)
#define UART_PIN_ALT_2          (1u)
#define UART_PIN_ALT_3          (2u)
#define UART_PIN_ALT_4          (3u)
#define UART_PIN_ALT_NUMBER     (4u)


typedef uint8 Uart_Err_t;
#define UART_ERR_NONE           (0u)
#define UART_ERR_OTHER          (1u)
#define UART_ERR_NUMBER         (2u)

typedef void (* Uart_Callback_t)(Uart_Id_t);
typedef void (* Uart_CallbackRx_t)(Uart_Id_t, uint8);
typedef void (* Uart_CallbackTx_t)(Uart_Id_t, uint8 *, uint8 *);
typedef void (* Uart_CallbackErr_t)(Uart_Id_t, uint8);

typedef struct Uart_Cfg
{
    uint8 chn;                          /* channel of uart */
    uint8 pinAlt;                       /* pinAlt profile id */
    uint8 intPriority;                  /* interrupt priority */
    Uart_Baudrate_t baudrate;           /* baudrate */
    CriticalType_t critical;            /* critical type */
    Uart_Callback_t initCbk;            /* initialize callback */
    Uart_Callback_t deinitCbk;          /* deinitialize callback */
    Uart_Callback_t openCbk;            /* open callback */
    Uart_Callback_t closeCbk;           /* close callback */
    Uart_CallbackTx_t txCbk;            /* transmit get data callback */
    Uart_CallbackTx_t txFinCbk;         /* transmit get data callback */
    Uart_CallbackRx_t rxCbk;            /* receive data callback */
    Uart_CallbackErr_t errCbk;          /* error callback */
}Uart_Cfg_t;

typedef struct Uart_Data
{
    Uart_State_t state;                 /* state of uart driver */
}Uart_Data_t;

extern struct Uart_Data uart_datas[UART_ID_NUMBER];
extern const struct Uart_Cfg uart_cfgs[UART_ID_NUMBER];

/*
 *  %function declaration%
 */
Uart_Return_t Uart_Init(Uart_Id_t id);
Uart_Return_t Uart_Deinit(uint8 id);
Uart_Return_t Uart_Open(Uart_Id_t id);
Uart_Return_t Uart_Close(Uart_Id_t chn);
Uart_Return_t Uart_TriggerTransmit(uint8 id);

__interrupt void Uart_IntRx0(void);
__interrupt void Uart_IntRx1(void);
__interrupt void Uart_IntRx2(void);
__interrupt void Uart_IntRx3(void);
__interrupt void Uart_IntTx0(void);
__interrupt void Uart_IntTx1(void);
__interrupt void Uart_IntTx2(void);
__interrupt void Uart_IntTx3(void);
__interrupt void Uart_IntErr0(void);
__interrupt void Uart_IntErr1(void);
__interrupt void Uart_IntErr2(void);
__interrupt void Uart_IntErr3(void);

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
