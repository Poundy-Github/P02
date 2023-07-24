/*********************************************************************************************************************
 * File Name     : $Source: target.h $
 * Mod. Revision : $Revision: 1.3 $
 * Mod. Date     : $Date: 2016/06/07 09:58:03JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Target specific defines
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only  intended for use with Renesas products.
 * No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS
 * AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
 * REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2015-2016 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
#include "dr7f701651.dvf.h"

#define R_NULL ((void*)0)
#define R_TRUE 1
#define R_FALSE 0

/************************************************************************************************************
Macro definitions
************************************************************************************************************/
#define protected_write(preg,pstatus,reg,value)             \
do                                                          \
{                                                           \
    (preg) = 0xa5u;                                         \
    (reg) = (value);                                        \
    (reg) = ~(value);                                       \
    (reg) = (value);                                        \
} while ((pstatus) == 1u)

#define R_FCL_INIT_CPU_AND_FPERIPHERAL_CLK                                                          \
    CLKCTL.MOSCC = 0x06;                    /* Set MainOSC gain for 16MHz */                        \
    CLKCTL.MOSCST = 0x00003E80;             /* Set MainOSC stabilization time to 2ms */            \
    protected_write(WPROTR.PROTCMD0,WPROTR.PROTS0,CLKCTL.MOSCE,0x01);   /* Trigger MainOsc start */ \
    while ((CLKCTL.MOSCS & 0x04) != 0x4);   /* Wait for active MainOSC */                           \
                                                                                                    \
    /* Prepare PLL0 */                                                                               \
    CLKCTL.PLL0C = 0x6340483B;               /* 16 MHz MainOSC -> 480MHz VCOUT */                  \
                                             /* 5% @ 100kHz SSCG */                                 \
    protected_write(WPROTR.PROTCMD0,WPROTR.PROTS0,CLKCTL.PLL0ST,0x1B80);   /* Set stabilization time to recommended value */  \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.PLL0E,0x01);   /* enable PLL0 */             \
    while ((CLKCTL.PLL0S & 0x04) != 0x04);   /* Wait for active PLL0 */                               \
   												     \
    /* Prepare PLL1 */                                                                               \
    CLKCTL.PLL1C = 0x10B3B;               /* 16 MHz MainOSC -> 480MHz VCOUT, 80MHz PPLLOUT */        \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.PLL1E,0x01);   /* enable PLL1 */             \
    while ((CLKCTL.PLL1S & 0x04) != 0x04);   /* Wait for active PLL1 */                               \
                                                                                                    \
    /* CPLLOUT = VCOOUT 1/2 = 240 MHz */                                                          \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKD_CTL,0x29);                    \
    while (CLKCTL.CKSC_CPUCLKD_ACT != 0x29);                                                        \
                                                                                                    \
    /* CPLLOUT -> CPU Clock */                                                                      \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKS_CTL,0x00);                    \
    while (CLKCTL.CKSC_CPUCLKS_ACT != 0x00);                                                        \
                                                                                                    \
    /* PPLLOUT -> PPLLCLK = 80MHz */                                                                \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_PPLLCLKS_CTL,0x03);                   \
    while (CLKCTL.CKSC_PPLLCLKS_ACT != 0x03);                                                       \
                                                                                                    \
     /* TAUJ Clock = PPLLCLK/2=40MHz */                                                                   \
    protected_write(WPROTRPROTCMD0, WPROTRPROTS0, CLKCTLCKSC_ATAUJS_CTL, 0x04);                     \
    while(CLKCTLCKSC_ATAUJS_CTL != 0x04);                                                           \



#define FLMD0_PROTECTION_OFF    (0x01u)
#define FLMD0_PROTECTION_ON     (0x00u)

#define FCL_INIT_FLASHACCESS                                        \
            uint32_t i;                                             \
                                                                    \
            /* enable FLMD0 */                                      \
            FLMDPCMD = 0xa5;                                        \
            FLMDCNT  = FLMD0_PROTECTION_OFF;                        \
            FLMDCNT  = ~FLMD0_PROTECTION_OFF;                       \
            FLMDCNT  = FLMD0_PROTECTION_OFF;                        \
            for (i = 0; i < 10000; i++)                             \
            {                                                       \
                /* do nothing ... delay time may depend on */       \
                /* external FLMD0 pin connection */                 \
            }

#define FCL_DISABLE_FLASHACCESS                                     \
            uint32_t i;                                             \
                                                                    \
            /* enable FLMD0 */                                      \
            FLMDPCMD = 0xa5;                                        \
            FLMDCNT  = FLMD0_PROTECTION_ON;                         \
            FLMDCNT  = ~FLMD0_PROTECTION_ON;                        \
            FLMDCNT  = FLMD0_PROTECTION_ON;                         \
            for (i = 0; i < 10000; i++)                             \
            {                                                       \
                /* do nothing ... delay time may depend on */       \
                /* external FLMD0 pin connection */                 \
            }

/************************************************************************************************************
Typedef definitions
************************************************************************************************************/


/************************************************************************************************************
Exported global variables
************************************************************************************************************/


/************************************************************************************************************
Exported global functions (to be accessed by other files) 
************************************************************************************************************/

