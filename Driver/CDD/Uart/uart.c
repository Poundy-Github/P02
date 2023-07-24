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
 * @file:      uart.c
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
#include "Os.h"
#include "Rte_Log.h"
#include "Uart.h"
#include "Std_Types.h"
#include "rtm.h"


/*
 *  %third-party header file%
 */

/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */

/* UART mode register (RLN3n.LMD)*/
/* UART Reception Data Noise Filtering Disable (LRDNFS) */
#define UART_NOISE_FILTER_ENABLED               (BIT(0u, 0)) /* The noise filter is enabled */
#define UART_NOISE_FILTER_DISABLED              (BIT(1u, 5)) /* The noise filter is disabled */
/* LIN OR UART Mode Select (LMD[1:0]) */
#define UART_MODE_SELECT                        (BIT(1u, 0)) /* UART mode */
#define LIN_MODE_SELECT                         (BIT(0u, 0)) /* UART mode */

/* UART configuration register (RLN3n.LBFC)*/
/* UART Output Polarity Switch (UTPS) */
#define UART_TRANSMISSION_NORMAL                (BIT(0u, 0)) /* Transmit data normal output */
#define UART_TRANSMITSSION_INVERTED             (BIT(1u, 6)) /* Transmit data with inversion output */
/* UART Input Polarity Switch (URPS) */
#define UART_RECEPTION_NORMAL                   (BIT(0u, 0)) /* Reception data normal output */
#define UART_RECEPTION_INVERTED                 (BIT(1u, 5)) /* Reception data with inversion output */
/* UART Parity Select (UPS[1:0]) */
#define UART_PARITY_PROHIBITED                  (BIT(0u, 0)) /* Parity prohibited */
#define UART_PARITY_EVEN                        (BIT(1u, 3)) /* Even Parity */
#define UART_PARITY_ZERO                        (BIT(2u, 3)) /* 0 Parity */
#define UART_PARITY_ODD                         (BIT(3u, 3)) /* Odd parity */
/* UART Stop Bit length Select (USBLS) */
#define UART_STOP_BIT_1                         (BIT(0u, 0)) /* Stop bit:1 bit */
#define UART_STOP_BIT_2                         (BIT(1u, 2)) /* Stop bit: 2 bits */
/* UART Transfer Format Order Select (UBOS) */
#define UART_LSB                                (BIT(0u, 0)) /* LSB First */
#define UART_MSB                                (BIT(1u, 1)) /* MSB First */
/* UART Character Length Select (UBLS) */
#define UART_LENGTH_8                           (BIT(0u, 0)) /* UART 8 bits communication */
#define UART_LENGTH_7                           (BIT(1u, 0)) /* UART 7 bits communication */

/* UART error detection enable register (RLN3n.LEDE)*/
/* Framing Error Detection Enable (FERE) */
#define UART_FRAMING_ERROR_DETECTED             (BIT(1u, 3)) /* Enables framing error detection */
/* Overrun Error Detection Enable (OERE) */
#define UART_OVERRUN_ERROR_DETECTED             (BIT(1u, 2)) /* Enables overrun error detection */
/* Bit Error Detection Enable (BERE) */
#define UART_BIT_ERROR_DETECTED                 (BIT(1u, 0)) /* Enables bit error detection */

/* UART transmission control register (RLN3n.LTRC)*/
/* UART Buffer Transmission Start (RTS) */
#define UART_BUFFER_TRANSMISSION_IS_STOPPED     (BIT(0u, 1)) /* UART Buffer transmission is stopped */
#define UART_BUFFER_TRANSMISSION_IS_STARTED     (BIT(1u, 1)) /* UART Buffer transmission is started */

/* UART status register (RLN3n.LST)*/
/* Reception Status Flag (URS) */
#define UART_RECEPTION_ISNOT_OPERATED           (BIT(0u, 0)) /* Reception is not operated */
#define UART_RECEPTION_OPERATED                 (BIT(1u, 5)) /* Reception is operated */
/* Transmission Status Flag (UTS) */
#define UART_TRANSMISSION_ISNOT_OPERATED        (BIT(0u, 0)) /* Transmission is not operated */
#define UART_TRANSMISSION_OPERATED              (BIT(1u, 4)) /* Transmission is operated */
/* Error Detection Flag (ERR) */
#define UART_REC_NO_ERROR_DETECTED              (BIT(0u, 0)) /* No error has been detected */
#define UART_RECEPTION_ERROR_DETECTED           (BIT(1u, 3)) /* Error has been detected */
/* Successful UART Buffer Reception Flag (FRC) */
#define UART_BUFFER_RECEIVE_NOT_COMPLETED       (BIT(0u, 1)) /* UART buffer reception has not been completed */
#define UART_RECEPTION_COMPLETED                (BIT(1u, 1)) /* UART buffer reception has been completed */
/* Successful UART Buffer Transmission Flag (FTC) */
#define UART_BUFFER_TRANSMIT_NOT_COMPLETED      (BIT(0u, 0)) /* UART buffer transmission has not been completed */
#define UART_TRANSMISSION_COMPLETED             (BIT(1u, 0)) /* UART buffer transmission has been completed */

/* UART error status register (RLN3n.LEST)*/
/* Parity Error Flag (UPER) */
#define UART_PARITY_ERROR_NOT_DETECTED          (BIT(0u, 0)) /* Parity error has not been detected */
#define UART_PARITY_ERROR_FLAG                  (BIT(1u, 6)) /* Parity error has been detected */
/* Framing Error Flag (FER) */
#define UART_FRAMING_ERROR_NOT_DETECTED         (BIT(0u, 0)) /* Framing error has not been detected */
#define UART_FRAMING_ERROR_FLAG                 (BIT(1u, 3)) /* Framing error has been detected */
/* Overrun Error Flag (OER) */
#define UART_OVERRUN_ERROR_NOT_DETECTED         (BIT(0u, 0)) /* Overrun error has not been detected */
#define UART_OVERRUN_ERROR_FLAG                 (BIT(1u, 2)) /* Overrun error has been detected */
/* Bit Error Flag (BER) */
#define UART_BIT_ERROR_NOT_DETECTED             (BIT(0u, 0)) /* Bit error has not been detected */
#define UART_BIT_ERROR_FLAG                     (BIT(1u, 0)) /* Bit error has been detected */

/* UART operation enable register (RLN3n.LUOER)*/
/* Reception Enable (UROE) */
#define UART_RECEPTION_DISABLED                 (BIT(0u, 0)) /* Disables reception */
#define UART_RECEPTION_ENABLED                  (BIT(1u, 1)) /* Enables reception */
/* Transmission Enable (UTOE) */
#define UART_TRANSMISSION_DISABLED              (BIT(0u, 0)) /* Disables transmission */
#define UART_TRANSMISSION_ENABLED               (BIT(1u, 0)) /* Enables transmission */

/* UART option register 1 (RLN3n.LUOR1)*/
/* Transmission Interrupt Generation Timing Select (UTIGTS) */
#define UART_INT_TRANSMISSION_START            (BIT(0u, 0)) /* INT is generated at the start of transmission */
#define UART_INT_TRANSMISSION_END              (BIT(1u, 3)) /* INT is generated at the completion of transmission */

/* UART control register (RLN3n.LCUC)*/
/* LIN Reset (OM0) */
#define UART_LIN_RESET_MODE_CAUSED              (BIT(0u, 0)) /* LIN reset mode is caused */
#define UART_LIN_RESET_MODE_CANCELED            (BIT(1u, 0)) /* LIN reset mode is canceled. */

/* LIN wake-up baud Rate select register (RLN3n.LWBR)*/
/* Bit Sampling Count Select (NSPB[3:0]) */
#define UART_6_SAMPLING                         (BIT(5u, 4)) /* 6 sampling */
#define UART_7_SAMPLING                         (BIT(6u, 4)) /* 7 sampling */
#define UART_8_SAMPLING                         (BIT(7u, 4)) /* 8 sampling */
#define UART_9_SAMPLING                         (BIT(8u, 4)) /* 9 sampling */
#define UART_10_SAMPLING                        (BIT(9u, 4)) /* 10 sampling */
#define UART_11_SAMPLING                        (BIT(10u, 4)) /* 11 sampling */
#define UART_12_SAMPLING                        (BIT(11u, 4)) /* 12 sampling */
#define UART_13_SAMPLING                        (BIT(12u, 4)) /* 13 sampling */
#define UART_14_SAMPLING                        (BIT(13u, 4)) /* 14 sampling */
#define UART_15_SAMPLING                        (BIT(14u, 4)) /* 15 sampling */
#define UART_16_SAMPLING                        (BIT(15u, 4)) /* 16 sampling */
/* Prescaler clock select (LPRS[2:0]) */
#define UART_PRESCALER_CLOCK_SELECT_1           (BIT(0u, 0)) /* Prescaler clock select 1/1 */
#define UART_PRESCALER_CLOCK_SELECT_2           (BIT(1u, 1)) /* Prescaler clock select 1/2 */
#define UART_PRESCALER_CLOCK_SELECT_4           (BIT(2u, 1)) /* Prescaler clock select 1/4 */
#define UART_PRESCALER_CLOCK_SELECT_8           (BIT(3u, 1)) /* Prescaler clock select 1/8 */
#define UART_PRESCALER_CLOCK_SELECT_16          (BIT(4u, 1)) /* Prescaler clock select 1/16 */
#define UART_PRESCALER_CLOCK_SELECT_32          (BIT(5u, 1)) /* Prescaler clock select 1/32 */
#define UART_PRESCALER_CLOCK_SELECT_64          (BIT(6u, 1)) /* Prescaler clock select 1/64 */
#define UART_PRESCALER_CLOCK_SELECT_128         (BIT(7u, 1)) /* Prescaler clock select 1/128 */

#define UART_ERROR_FLAG                         (BIT(1u, 0) | BIT(1u, 2) | BIT(1u, 3) |  \
                                                 BIT(1u, 4) | BIT(1u, 5) | BIT(1u, 6))

/* UART data field configuration register (RLN3n.LDFC)*/
/* UART buffer data length select (MDL[2:0]) */
#define UART_BUFFER_LENGTH(n)                   (BIT((n), 0))/* UART Buffer transmission is stopped */
/* UART transfer start wait (UTSW) */
#define UART_TRANSFER_START_WAIT                (BIT(1u, 5))


#define LIN_NSPB                                (BIT(0u, 4))
#define LIN_LPRS(n)                             (BIT((n), 1))
#define LIN_LWBR0                               (BIT(1u, 0))
#define LIN_BDT(n)                              (BIT((n), 4))
#define LIN_BLT(n)                              (BIT((n), 0))
#define LIN_IBS(n)                              (BIT((n), 4))
#define LIN_IBHS(n)                             (BIT((n), 0))
#define LIN_WUTL(n)                             (BIT((n), 4))
#define LIN_FRCIE                               (BIT(1u, 1))
#define LIN_FTCIE                               (BIT(1u, 0))
#define LIN_FERE                                (BIT(1u, 3))
#define LIN_FTERE                               (BIT(1u, 2))
#define LIN_PBERE                               (BIT(1u, 1))
#define LIN_BERE                                (BIT(1u, 0))
#define LIN_LSS                                 (BIT(1u, 7))
#define LIN_FSM                                 (BIT(1u, 6))
#define LIN_CSM                                 (BIT(1u, 5))
#define LIN_RFDL(n)                             (BIT((n), 0))
#define LIN_OM0                                 (BIT(1u, 0))
#define LIN_OM1                                 (BIT(1u, 1))
#define LIN_FRC                                 (BIT(1u, 1))
#define LIN_RFT                                 (BIT(1u, 4))
#define LIN_RFDL(n)                             (BIT((n), 0))
#define LIN_RTS                                 (BIT(1u, 1))
#define LIN_FTS                                 (BIT(1u, 0))
#define LIN_LCKS(n)                             (BIT((n), 2))


/* urat reg structure */
typedef struct Uart_CfgReg
{
    uint8  dummy0[1];                                   /* Reserved         */
    __IO uint8  LWBR;                                   /* LWBR             */
    __IO uint16 LBRP;                                   /* LBRP           */
    __IO uint8  LSTC;                                   /* LSTC             */
    uint8  dummy1[3];                                   /* Reserved         */
}Uart_CfgReg_t;

typedef struct Uart_CtrlReg
{
    __IO uint8  LMD;                                    /* LMD              */
    __IO uint8  LBFC;                                   /* LBFC             */
    __IO uint8  LSC;                                    /* LSC              */
    __IO uint8  LWUP;                                   /* LWUP             */
    __IO uint8  LIE;                                    /* LIE              */
    __IO uint8  LEDE;                                   /* LEDE             */
    __IO uint8  LCUC;                                   /* LCUC             */
    uint8  dummy2[1];                                   /* Reserved         */
    __IO uint8  LTRC;                                   /* LTRC             */
    __IO uint8  LMST;                                   /* LMST             */
    __IO uint8  LST;                                    /* LST              */
    __IO uint8  LEST;                                   /* LEST             */
    __IO uint8  LDFC;                                   /* LDFC             */
    __IO uint8  LIDB;                                   /* LIDB             */
    __IO uint8  LCBR;                                   /* LCBR             */
    __IO uint8  LUDB0;                                  /* LUDB0            */
    __IO uint8  LDBR[8];                                /* LDBR             */
}Uart_CtrlReg_t;

typedef struct Uart_StsReg
{
    __IO uint8  LUOER;                                  /* LUOER            */
    __IO uint8  LUOR1;                                  /* LUOR1            */
    __IO uint8  dummy3[2];                              /* Reserved         */
    __IO uint16 LUTDR;                                  /* LUTDR            */
    __IO uint16 LURDR;                                  /* LURDR            */
    __IO uint16 LUWTDR;                                 /* LUWTDR           */
}Uart_StsReg_t;

typedef struct UartReg
{
    struct Uart_CfgReg *reg_cfg;
    struct Uart_CtrlReg *reg_ctrl;
    struct Uart_StsReg *reg_sts;
}UartReg_t;

/* interrupt reg */
typedef struct Uart_IntReg
{
    volatile uint16 *base;
    volatile uint16 *r0;
    volatile uint16 *r1;
    volatile uint16 *r2;
}Uart_IntReg;

/* base reg of RLN3x and RLIN240x */
#define RLN240_CFG_REG  (*(struct Uart_CfgReg *)0xFFCE0000)    /* RLN240 */
#define RLN2400_CTRL_REG (*(struct Uart_CtrlReg *)0xFFCE0008)  /* RLN2400 */
#define RLN2401_CTRL_REG (*(struct Uart_CtrlReg *)0xFFCE0028)  /* RLN2401 */
#define RLN2402_CTRL_REG (*(struct Uart_CtrlReg *)0xFFCE0048)  /* RLN2402 */
#define RLN30_CFG_REG   (*(struct Uart_CfgReg *)0xFFCE2000)    /* RLN30 */
#define RLN30_CTRL_REG   (*(struct Uart_CtrlReg *)0xFFCE2008)
#define RLN30_STS_REG   (*(struct Uart_StsReg *)0xFFCE2020)
#define RLN31_CFG_REG   (*(struct Uart_CfgReg *)0xFFCE2040)    /* RLN31 */
#define RLN31_CTRL_REG   (*(struct Uart_CtrlReg *)0xFFCE2048)
#define RLN31_STS_REG   (*(struct Uart_StsReg *)0xFFCE2060)
#define RLN32_CFG_REG   (*(struct Uart_CfgReg *)0xFFCE2080)    /* RLN32 */
#define RLN32_CTRL_REG   (*(struct Uart_CtrlReg *)0xFFCE2088)
#define RLN32_STS_REG   (*(struct Uart_StsReg *)0xFFCE20A0)
#define RLN33_CFG_REG   (*(struct Uart_CfgReg *)0xFFCE20C0)    /* RLN33 */
#define RLN33_CTRL_REG   (*(struct Uart_CtrlReg *)0xFFCE20C8)
#define RLN33_STS_REG   (*(struct Uart_StsReg *)0xFFCE20E0)
#define RLN34_CFG_REG   (*(struct Uart_CfgReg *)0xFFCE2100)    /* RLN34 */
#define RLN34_CTRL_REG   (*(struct Uart_CtrlReg *)0xFFCE2108)
#define RLN34_STS_REG   (*(struct Uart_StsReg *)0xFFCE2120)
#define RLN35_CFG_REG   (*(struct Uart_CfgReg *)0xFFCE2140)    /* RLN34 */
#define RLN35_CTRL_REG   (*(struct Uart_CtrlReg *)0xFFCE2148)
#define RLN35_STS_REG   (*(struct Uart_StsReg *)0xFFCE2160)

/* uart device config of MCU R7F701581 */
struct Uart_DevCfg
{
    const struct UartReg *reg;              /*register*/
    const struct Uart_IntReg *reg_int;      /*register of interrupt*/
};

/*
 *  %forward declaration%
 */
static Uart_Return_t Uart_IntRx(uint8 chn);
static Uart_Return_t Uart_IntTx(uint8 chn);
static Uart_Return_t Uart_IntErr(uint8 chn);

/*
 *  %global definition%
 */
/* register of uart 0 */
static const struct UartReg regUart0 =
{
    &RLN30_CFG_REG, &RLN30_CTRL_REG, &RLN30_STS_REG
};

/* interrput register of uart 0 */
static const struct Uart_IntReg intRegUart0 =
{
    &INT_CTRL2.CRLIN30, &INT_CTRL2.CRLIN30UR0, &INT_CTRL2.CRLIN30UR1, &INT_CTRL2.CRLIN30UR2
};

/* register of uart 1 */
static const struct UartReg regUart1 =
{
    &RLN31_CFG_REG, &RLN31_CTRL_REG, &RLN31_STS_REG
};

/* interrput register of uart 1 */
static const struct Uart_IntReg intRegUart1 =
{
    &INT_CTRL2.CRLIN31, &INT_CTRL2.CRLIN31UR0, &INT_CTRL2.CRLIN31UR1, &INT_CTRL2.CRLIN31UR2
};

/* register of uart 2 */
static const struct UartReg regUart2 =
{
    &RLN32_CFG_REG, &RLN32_CTRL_REG, &RLN32_STS_REG
};

/* interrput register of uart 2 */
static const struct Uart_IntReg intRegUart2 =
{
    &INT_CTRL2.CRLIN32, &INT_CTRL2.CRLIN32UR0, &INT_CTRL2.CRLIN32UR1, &INT_CTRL2.CRLIN32UR2
};

/*register of uart 3*/
static const struct UartReg regUart3 =
{
    &RLN33_CFG_REG, &RLN33_CTRL_REG, &RLN33_STS_REG
};

/* interrput register of uart 3 */
static const struct Uart_IntReg intRegUart3 =
{
    &INT_CTRL2.CRLIN33, &INT_CTRL2.CRLIN33UR0, &INT_CTRL2.CRLIN33UR1, &INT_CTRL2.CRLIN33UR2
};
/*register of uart 4*/
static const struct UartReg regUart4 =
{
    &RLN34_CFG_REG, &RLN34_CTRL_REG, &RLN34_STS_REG
};
/* interrput register of uart 4 */

static const struct Uart_IntReg intRegUart4 =
{
    &INT_CTRL2.CRLIN34, &INT_CTRL2.CRLIN34UR0, &INT_CTRL2.CRLIN34UR1, &INT_CTRL2.CRLIN34UR2
};
/*register of uart 5*/
static const struct UartReg regUart5 =
{
    &RLN35_CFG_REG, &RLN35_CTRL_REG, &RLN35_STS_REG
};
/* interrput register of uart 5 */
static const struct Uart_IntReg intRegUart5 =
{
    &INT_CTRL2.CRLIN35, &INT_CTRL2.CRLIN35UR0, &INT_CTRL2.CRLIN35UR1, &INT_CTRL2.CRLIN35UR2
};


/* all uart device config */
static const struct Uart_DevCfg uartDevCfgs[UART_CHN_NUM] =
{
    {&regUart0, &intRegUart0},
    {&regUart1, &intRegUart1},
    {&regUart2, &intRegUart2},
    {&regUart3, &intRegUart3},
    {&regUart4, &intRegUart4},
    {&regUart5, &intRegUart5},
};

static Uart_Id_t uart_chnToId[UART_CHN_NUM] = {UART_ID_NUMBER};

/*
 *  %function definition%
 */

/*
* @brief   :   init uart
* @param   :   chn: channel id represent one uart channel
* @retval  :   UART_SUCCESS: init success
* @retval  :   UART_E_PARAM: parameter error
* @retval  :   UART_E_INIT: init error
*/
Uart_Return_t Uart_Init(Uart_Id_t id)
{
    Uart_Return_t ret = UART_ERROR;

#if(UART_DEV_ERROR_DETECT == STD_ON)
    if(id >= UART_ID_NUMBER)
    {
        ret = UART_E_PARAM;
    }
    else if(UART_STATE_NOT_INIT != uart_datas[id].state)
    {
        ret = UART_E_STATE;
    }
    else if((uart_cfgs[id].intPriority > INT_PRIORITY_LOWEST) ||
        (uart_cfgs[id].critical >= CRITICAL_TYPE_NUMBER))
    {
        ret = UART_E_PARAM;
    }
    else
#endif
    {
        uint8 chn = uart_cfgs[id].chn;
        UART_ENTER_CRITICAL();
        if(uart_cfgs[id].critical != CRITICAL_TYPE_ISR_I)
        {
            UART_RES_INIT(id);
        }

        if(NULL_PTR != uart_cfgs[id].initCbk)
        {
            uart_cfgs[id].initCbk(id);
        }

        /* Set LIN reset mode */
        uartDevCfgs[chn].reg->reg_ctrl->LCUC = UART_LIN_RESET_MODE_CAUSED;

        /* Disable ICRLIN3xUR0 operation and clear request */
        /* Set ICRLIN3xUR0 table method and priority*/
        *uartDevCfgs[chn].reg_int->r0 = (INT_TR_TABLE | INT_MASK_DISABLE | INT_PRIORITY(INT_PRIORITY_LOWEST));
        /* Disable ICRLIN3xUR1 operation and clear request */
        /* Set ICRLIN3xUR1 table method and priority */
        *uartDevCfgs[chn].reg_int->r1 = (INT_TR_TABLE | INT_MASK_DISABLE | INT_PRIORITY(INT_PRIORITY_LOWEST));
        /* Disable ICRLIN3xUR2 operation and clear request */
        /* Set ICRLIN3xUR2 table method and priority*/
        *uartDevCfgs[chn].reg_int->r2 = (INT_TR_TABLE | INT_MASK_DISABLE | INT_PRIORITY(INT_PRIORITY_LOWEST));

        /* Set UARTx setting */
        uartDevCfgs[chn].reg->reg_cfg->LWBR = UART_6_SAMPLING | UART_PRESCALER_CLOCK_SELECT_2;

        switch(uart_cfgs[id].baudrate)
        {
            case UART_BAUDRATE_9600:
            {
                uartDevCfgs[chn].reg->reg_cfg->LBRP = 346u;
            }
            break;

            case UART_BAUDRATE_19200:
            {
                uartDevCfgs[chn].reg->reg_cfg->LBRP = 173u;
            }
            break;

            case UART_BAUDRATE_38400:
            {
                uartDevCfgs[chn].reg->reg_cfg->LBRP = 86u;
            }
            break;

            case UART_BAUDRATE_57600:
            {
                uartDevCfgs[chn].reg->reg_cfg->LBRP = 57u;
            }
            break;

            case UART_BAUDRATE_115200:
            default:
            {
                uartDevCfgs[chn].reg->reg_cfg->LBRP = 28u;
            }
            break;
        }

        /* Set UARTx transmission interrupt timing*/
        uartDevCfgs[chn].reg->reg_sts->LUOR1 |= UART_INT_TRANSMISSION_END;

        /* Set UARTx LMD*/
        uartDevCfgs[chn].reg->reg_ctrl->LMD = UART_NOISE_FILTER_ENABLED |
            UART_MODE_SELECT;
    
        /* Set UARTx LEDE*/
        uartDevCfgs[chn].reg->reg_ctrl->LEDE = UART_FRAMING_ERROR_DETECTED |
            UART_OVERRUN_ERROR_DETECTED;

        /* Set UARTx LBFC*/
        uartDevCfgs[chn].reg->reg_ctrl->LBFC = UART_TRANSMISSION_NORMAL |
            UART_RECEPTION_NORMAL | UART_PARITY_PROHIBITED |
            UART_STOP_BIT_1 | UART_LSB | UART_LENGTH_8;

        /* Synchronization processing */
        EXECUTE_SYNCP();

        /* store mapping */
        uart_chnToId[chn] = id;     
        uart_datas[id].state = UART_STATE_CLOSE;

        UART_EXIT_CRITICAL();
        ret = UART_SUCCESS;
    }
    return ret;
}

/*
* @brief   :   deinit uart
* @param   :   config: pointer to uart config
* @retval  :   UART_SUCCESS: deinit success
* @retval  :   UART_E_PARAM: parameter error
* @retval  :   UART_E_INIT: init error
* @retval  :   UART_E_STATE: state error
*/
Uart_Return_t Uart_Deinit(Uart_Id_t id)
{
    Uart_Return_t ret = UART_ERROR;

#if(UART_DEV_ERROR_DETECT == STD_ON)
    if(id >= UART_ID_NUMBER)
    {
        ret = UART_E_PARAM;
    }
    else if(UART_STATE_CLOSE != uart_datas[id].state)
    {
        ret = UART_E_STATE;
    }
    else if(uart_cfgs[id].intPriority > INT_PRIORITY_LOWEST)
    {
      ret = UART_E_PARAM;
    }
    else
#endif
    {
        uint8 chn = uart_cfgs[id].chn;
        if(uart_cfgs[id].critical == CRITICAL_TYPE_ISR_I)
        {
            UART_ENTER_CRITICAL();
        }
        else
        {
            UART_RES_LOCK(id);
        }

        if(NULL_PTR != uart_cfgs[id].deinitCbk)
        {
            uart_cfgs[id].deinitCbk(id);
        }

        /* Set LIN reset mode */
        uartDevCfgs[chn].reg->reg_ctrl->LCUC = UART_LIN_RESET_MODE_CAUSED;

        /* Disable ICRLIN3xUR0 operation and clear request */
        *uartDevCfgs[chn].reg_int->r0 |= INT_MASK_DISABLE;
        *uartDevCfgs[chn].reg_int->r0 &= (uint16)(~INT_REQUEST_NO_ACK);
        /* Disable ICRLIN3xUR1 operation and clear request */
        *uartDevCfgs[chn].reg_int->r1 |= INT_MASK_DISABLE;
        *uartDevCfgs[chn].reg_int->r1 &= (uint16)(~INT_REQUEST_NO_ACK);
        /* Disable ICRLIN3xUR2 operation and clear request */
        *uartDevCfgs[chn].reg_int->r2 |= INT_MASK_DISABLE;
        *uartDevCfgs[chn].reg_int->r2 &= (uint16)(~INT_REQUEST_NO_ACK);

        /* Synchronization processing */
        EXECUTE_SYNCP();

        /* delete mapping */
        uart_chnToId[chn] = UART_ID_NUMBER;
        uart_datas[id].state = UART_STATE_NOT_INIT;
        
        if(uart_cfgs[id].critical == CRITICAL_TYPE_ISR_I)
        {
            UART_EXIT_CRITICAL();
        }
        else
        {
            UART_RES_UNLOCK(id);
        }
        ret = UART_SUCCESS;
    }
    return ret;
}


/*
* @brief   :   open uart
* @param   :   channel: channel of uart to operate
* @retval  :   UART_SUCCESS: open success
* @retval  :   UART_E_PARAM: parameter error
* @retval  :   UART_E_INIT: init error
* @retval  :   UART_E_STATE: channel is already opened
*/
Uart_Return_t Uart_Open(Uart_Id_t id)
{
    Uart_Return_t ret = UART_ERROR;

#if(UART_DEV_ERROR_DETECT == STD_ON)
    if(id >= UART_ID_NUMBER)
    {
        ret = UART_E_PARAM;
    }
    else if(UART_STATE_CLOSE != uart_datas[id].state)
    {
        ret = UART_E_STATE;
    }
    else
#endif
    {
        uint8 chn = uart_cfgs[id].chn;
        if(uart_cfgs[id].critical == CRITICAL_TYPE_ISR_I)
        {
            UART_ENTER_CRITICAL();
        }
        else
        {
            UART_RES_LOCK(id);
        }

        if(NULL_PTR != uart_cfgs[id].openCbk)
        {
            uart_cfgs[id].openCbk(id);
        }
        
        /* Clear ICRLIN30UR0 interrupt request and enable operation */
        *uartDevCfgs[chn].reg_int->r0 &= (~INT_MASK_DISABLE);
        *uartDevCfgs[chn].reg_int->r0 &= (uint16)(~INT_REQUEST_NO_ACK);
        /* Clear ICRLIN30UR1 interrupt request and enable operation */
		if(NULL_PTR != uart_cfgs[id].rxCbk)
		{
	        *uartDevCfgs[chn].reg_int->r1 &= (~INT_MASK_DISABLE);
	        *uartDevCfgs[chn].reg_int->r1 &= (uint16)(~INT_REQUEST_NO_ACK);
		}
        /* Clear ICRLIN30UR2 interrupt request and enable operation */
        *uartDevCfgs[chn].reg_int->r2 &= (~INT_MASK_DISABLE);
        *uartDevCfgs[chn].reg_int->r2 &= (uint16)(~INT_REQUEST_NO_ACK);

        /* Set UARTx LCUC*/
        uartDevCfgs[chn].reg->reg_ctrl->LCUC = UART_LIN_RESET_MODE_CANCELED;
        /* Enable UART0 operation */
        uartDevCfgs[chn].reg->reg_sts->LUOER |= UART_RECEPTION_ENABLED |
            UART_TRANSMISSION_ENABLED;

        EXECUTE_SYNCP();

        uart_datas[id].state = UART_STATE_OPEN;

        if(uart_cfgs[id].critical == CRITICAL_TYPE_ISR_I)
        {
            UART_EXIT_CRITICAL();
        }
        else
        {
            UART_RES_UNLOCK(id);
        }
        ret = UART_SUCCESS;
    }
    return ret;
}

/*
* @brief   :   close uart
* @param   :   channel: channel of uart to operate
* @retval  :   UART_SUCCESS: close success
* @retval  :   UART_E_PARAM: parameter error
* @retval  :   UART_E_INIT: init error
* @retval  :   UART_E_STATE: channel is already closed
*/
Uart_Return_t Uart_Close(Uart_Id_t id)
{
    Uart_Return_t ret = UART_ERROR;

#if(UART_DEV_ERROR_DETECT == STD_ON)
    if(id >= UART_ID_NUMBER)
    {
        ret = UART_E_PARAM;
    }
    else if(UART_STATE_OPEN != uart_datas[id].state)
    {
        ret = UART_E_STATE;
    }
    else
#endif
    {
        uint8 chn = uart_cfgs[id].chn;
        if(uart_cfgs[id].critical == CRITICAL_TYPE_ISR_I)
        {
            UART_ENTER_CRITICAL();
        }
        else
        {
            UART_RES_LOCK(id);
        }

        /* Disable UART0 operation */
        uartDevCfgs[chn].reg->reg_sts->LUOER &= (uint8) ~(UART_RECEPTION_ENABLED |
            UART_TRANSMISSION_ENABLED);
        /* Set UARTx LCUC*/
        uartDevCfgs[chn].reg->reg_ctrl->LCUC = UART_LIN_RESET_MODE_CANCELED;

        /* Disable ICRLIN3xUR0 operation and clear request */
        *uartDevCfgs[chn].reg_int->r0 |= INT_MASK_DISABLE;
        *uartDevCfgs[chn].reg_int->r0 &= (uint16)(~INT_REQUEST_NO_ACK);
        /* Disable ICRLIN3xUR1 operation and clear request */
        *uartDevCfgs[chn].reg_int->r1 |= INT_MASK_DISABLE;
        *uartDevCfgs[chn].reg_int->r1 &= (uint16)(~INT_REQUEST_NO_ACK);
        /* Disable ICRLIN3xUR2 operation and clear request */
        *uartDevCfgs[chn].reg_int->r2 |= INT_MASK_DISABLE;
        *uartDevCfgs[chn].reg_int->r2 &= (uint16)(~INT_REQUEST_NO_ACK);

        /* Synchronization processing */
        EXECUTE_SYNCP();

        if(uart_cfgs[id].closeCbk)
        {
             uart_cfgs[id].closeCbk(id);
        }                                                   

        uart_datas[id].state = UART_STATE_CLOSE;
        ret = UART_SUCCESS;

        if(uart_cfgs[id].critical == CRITICAL_TYPE_ISR_I)
        {
            UART_EXIT_CRITICAL();
        }
        else
        {
            UART_RES_UNLOCK(id);
        }                                                                                                                                    
    }
    return ret;
}

/*
* @brief   :   transmit data by uart
* @param   :   chn: channel of uart to transmit data
* @param   :   buf: data to be transmitted
* @param   :   len: length of data to be transmitted
* @param   :   ret_len: length of data transmitted actually
* @retval  :   UART_SUCCESS: close success
* @retval  :   UART_E_PARAM: parameter error
* @retval  :   UART_E_INIT: init error
* @retval  :   UART_E_INTERFACE: interface is not uart
* @retval  :   UART_E_STATE: state is not open
* @retval  :   UART_E_FULL: transmit queue is full
*/
Uart_Return_t Uart_TriggerTransmit(Uart_Id_t id)
{
    Uart_Return_t ret = UART_ERROR;

#if(UART_DEV_ERROR_DETECT == STD_ON)
    if(id >= UART_ID_NUMBER)
    {
        ret = UART_E_PARAM;
    }
    else if(UART_STATE_OPEN != uart_datas[id].state)
    {
        ret = UART_E_STATE;
    }
    else
#endif
    {
        uint8 chn = uart_cfgs[id].chn;

        if((0 != (uartDevCfgs[chn].reg->reg_ctrl->LST & UART_TRANSMISSION_OPERATED)) ||
            (0 != (uartDevCfgs[chn].reg->reg_ctrl->LTRC & UART_BUFFER_TRANSMISSION_IS_STARTED)))
        {
            /* opertion is going on*/
            ret = UART_E_OCCUPY;
        }
        else
        {
            uint8 i;
            uint8 length = UART_HW_BUF_SIZE;
            uint8 data[UART_HW_BUF_SIZE];

            if(uart_cfgs[id].critical == CRITICAL_TYPE_ISR_I)
            {
                UART_ENTER_CRITICAL();
            }
            else
            {
                UART_RES_LOCK(id);
            }

            if(NULL_PTR != uart_cfgs[id].txCbk)
            {
                uart_cfgs[id].txCbk(id, data, &length);
            }

            if(length <= UART_HW_BUF_SIZE)
            {
                i = length;
            }
            else
            {
                i = UART_HW_BUF_SIZE;
            }
            uartDevCfgs[chn].reg->reg_ctrl->LDFC = UART_BUFFER_LENGTH(i);
            for( ; i > 0u; i--)
            {
                uartDevCfgs[chn].reg->reg_ctrl->LDBR[i - 1u] = data[i - 1u];
            }
            uartDevCfgs[chn].reg->reg_ctrl->LTRC = UART_BUFFER_TRANSMISSION_IS_STARTED;

            if(uart_cfgs[id].critical == CRITICAL_TYPE_ISR_I)
            {
                UART_EXIT_CRITICAL();
            }
            else
            {
                UART_RES_UNLOCK(id);
            }
        }
        ret = UART_SUCCESS;
    }
    return ret;
}



/*
* @brief   :   uart receive interrupt routine handler
* @param   :   chn: channel of uart
* @retval  :   none
*/
static Uart_Return_t Uart_IntRx(uint8 chn)
{
    Uart_Return_t ret = UART_ERROR;
	
	Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);

#if(UART_DEV_ERROR_DETECT == STD_ON)
    if(chn >= UART_CHN_NUM)
    {
        ret = UART_E_PARAM;
    }
    else if(uart_chnToId[chn] >= UART_ID_NUMBER)
    {
        ret = UART_E_PARAM;
    }
    else if(UART_STATE_OPEN != uart_datas[uart_chnToId[chn]].state)
    {
        ret = UART_E_STATE;
    }
    else
#endif
    {
        Uart_Id_t id = uart_chnToId[chn];
        if(NULL_PTR != uart_cfgs[id].rxCbk)
        {
            uart_cfgs[id].rxCbk(id, uartDevCfgs[chn].reg->reg_sts->LURDR);
        }
        ret = UART_SUCCESS;
    }
	Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);

    return ret;
}

#ifdef __CCRH__
#pragma interrupt Uart_IntRx0(enable=false, channel=35, fpu=true, callt=false)
#endif
ISR(Uart_IntRx0)
{
    Uart_IntRx(0u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntRx1(enable=false, channel=122, fpu=true, callt=false)
#endif
ISR(Uart_IntRx1)
{
    Uart_IntRx(1u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntRx2(enable=false, channel=166, fpu=true, callt=false)
#endif
ISR(Uart_IntRx2)
{
    Uart_IntRx(2u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntRx3(enable=false, channel=230, fpu=true, callt=false)
#endif
ISR(Uart_IntRx3)
{
    Uart_IntRx(3u);
}
#ifdef __CCRH__
#pragma interrupt Uart_IntRx4(enable=false, channel=234, fpu=true, callt=false)
#endif
ISR(Uart_IntRx4)
{
    Uart_IntRx(4u);
}
#ifdef __CCRH__
#pragma interrupt Uart_IntRx5(enable=false, channel=238, fpu=true, callt=false)
#endif
ISR(Uart_IntRx5)
{
    Uart_IntRx(5u);
}

/*
* @brief   :   uart transmit finish interrupt routine handler
* @param   :   chn: channel of uart
* @retval  :   none
*/
static Uart_Return_t Uart_IntTx(uint8 chn)
{
    Uart_Return_t ret = UART_ERROR;
	Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);

#if(UART_DEV_ERROR_DETECT == STD_ON)
    if(chn >= UART_CHN_NUM)
    {
        ret = UART_E_PARAM;
    }
    else if(uart_chnToId[chn] >= UART_ID_NUMBER)
    {
        ret = UART_E_PARAM;
    }
    else if(UART_STATE_OPEN != uart_datas[uart_chnToId[chn]].state)
    {
        ret = UART_E_STATE;
    }
    else
#endif
    {
        Uart_Id_t id = uart_chnToId[chn];
        uint8 length = UART_HW_BUF_SIZE;
        uint8 data[UART_HW_BUF_SIZE];

        if(NULL_PTR != uart_cfgs[id].txFinCbk)
        {
            uart_cfgs[id].txFinCbk(id, data, &length);
        }
        
        if(length > 0u)
        {
            uartDevCfgs[chn].reg->reg_ctrl->LDFC = UART_BUFFER_LENGTH(length);
            for( ; length > 0u; length--)
            {
                uartDevCfgs[chn].reg->reg_ctrl->LDBR[length - 1u] = data[length - 1u];
            }
            uartDevCfgs[chn].reg->reg_ctrl->LTRC = UART_BUFFER_TRANSMISSION_IS_STARTED;
        }
        ret = UART_SUCCESS;
    }
   Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
	return ret;
}

#ifdef __CCRH__
#pragma interrupt Uart_IntTx0(enable=false, channel=34, fpu=true, callt=false)
#endif
ISR(Uart_IntTx0)
{
    Uart_IntTx(0u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntTx1(enable=false, channel=121, fpu=true, callt=false)
#endif
ISR(Uart_IntTx1)
{
    Uart_IntTx(1u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntTx2(enable=false, channel=165, fpu=true, callt=false)
#endif
ISR(Uart_IntTx2)
{
    Uart_IntTx(2u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntTx3(enable=false, channel=229, fpu=true, callt=false)
#endif
ISR(Uart_IntTx3)
{
    Uart_IntTx(3u);
}
#ifdef __CCRH__
#pragma interrupt Uart_IntTx4(enable=false, channel=233, fpu=true, callt=false)
#endif
ISR(Uart_IntTx4)
{
    Uart_IntTx(4u);
}
#ifdef __CCRH__
#pragma interrupt Uart_IntTx5(enable=false, channel=237, fpu=true, callt=false)
#endif
ISR(Uart_IntTx5)
{
    Uart_IntTx(5u);
}



/*
* @brief   :   uart error interrupt routine handler
* @param   :   chn: channel of uart
* @retval  :   none
*/
static Uart_Return_t Uart_IntErr(uint8 chn)
{
    Uart_Return_t ret = UART_ERROR;
	Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);

#if(UART_DEV_ERROR_DETECT == STD_ON)
    if(chn >= UART_CHN_NUM)
    {
        ret = UART_E_PARAM;
    }
    else if(uart_chnToId[chn] >= UART_ID_NUMBER)
    {
        ret = UART_E_PARAM;
    }
    else if(UART_STATE_OPEN != uart_datas[uart_chnToId[chn]].state)
    {
        ret = UART_E_STATE;
    }
    else
#endif
    {
        Uart_Id_t id = uart_chnToId[chn];
        uint8 data = uartDevCfgs[chn].reg->reg_sts->LURDR;
        uint8 err = uartDevCfgs[chn].reg->reg_ctrl->LEST;

        uartDevCfgs[chn].reg->reg_ctrl->LEST &= (~UART_ERROR_FLAG);

        if(NULL_PTR != uart_cfgs[id].errCbk)
        {
            uart_cfgs[id].errCbk(id, err);
        }
        ret = UART_SUCCESS;
    }
    Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
	return ret;
}

#ifdef __CCRH__
#pragma interrupt Uart_IntErr0(enable=false, channel=36, fpu=true, callt=false)
#endif
ISR(Uart_IntErr0)
{
    Uart_IntErr(0u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntErr1(enable=false, channel=123, fpu=true, callt=false)
#endif
ISR(Uart_IntErr1)
{
    Uart_IntErr(1u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntErr2(enable=false, channel=167, fpu=true, callt=false)
#endif
ISR(Uart_IntErr2)
{
    Uart_IntErr(2u);
}

#ifdef __CCRH__
#pragma interrupt Uart_IntErr3(enable=false, channel=231, fpu=true, callt=false)
#endif
ISR(Uart_IntErr3)
{
    Uart_IntErr(3u);
}
#ifdef __CCRH__
#pragma interrupt Uart_IntErr4(enable=false, channel=235, fpu=true, callt=false)
#endif
ISR(Uart_IntErr4)
{
    Uart_IntErr(4u);
}
#ifdef __CCRH__
#pragma interrupt Uart_IntErr5(enable=false, channel=239, fpu=true, callt=false)
#endif
ISR(Uart_IntErr5)
{
    Uart_IntErr(5u);
}


