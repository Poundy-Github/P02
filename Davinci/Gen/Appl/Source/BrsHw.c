
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  BrsHw.c
      Project:  Vector Basic Runtime System
       Module:  BrsHw for platform Renesas RH850
     Template:  This file is reviewed according to Brs_Template@Implementation[1.00.00]

  \brief Description:  This is the hardware specific code file for Vector Basic Runtime System (BRS).

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Benjamin Walter               visbwa        Vector Informatik GmbH
  Lukas Rohrwild                virrlu        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2020-05-26  visbwa  New branch for vBaseEnv 2.0, based on zBrs_Rh850 BrsHw.c 3.11.05
                        virrlu  Review according to Brs_Template@Implementation[1.00.00]
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

#define _BRSHW_C_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "BrsHw.h"

#include "Os.h"

#include "BrsMain.h"

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
#if (BRSHW_VERSION != 0x0100u)
  #error "Header and source file are inconsistent!"
#endif
#if (BRSHW_BUGFIX_VERSION != 0x00u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/
#if defined (BRS_COMP_GHS)     

#else
  #error "Unknown compiler specified!"
#endif

/**********************************************************************************************************************
  DEFINITION + MACROS
**********************************************************************************************************************/
  #define BRSHWNOP10() ___asm(nop);___asm(nop);___asm(nop);___asm(nop);___asm(nop);___asm(nop);___asm(nop);___asm(nop);___asm(nop);___asm(nop)

#if defined (BRS_PROTECTION_GROUP_A)
  #define PROTCMD0    BRSHW_IOS(uint32 , 0xFFF80000)  /* Protection command register 0 */
  #define PROTCMD1    BRSHW_IOS(uint32 , 0xFFF88000)  /* Protection command register 1 */
  #define PROTCMDD1   BRSHW_IOS(uint32 , 0xFFF87000)  /* Protection command register 2*/
  #define PROTCMDMRST BRSHW_IOS(uint32 , 0xFFF8F480)  /* MRSTC protection command register*/

#elif defined (BRS_PROTECTION_GROUP_B)
  #define PROTCMD1    BRSHW_IOS(uint32 , 0xFFF8B000)  /* PROTCMD1=PROT1PHCMD Protect 1 command register */

#elif defined (BRS_PROTECTION_GROUP_NONE)

#else
  #error "Unknown BRS_PROTECTION_GROUP configured. Check the Cfg5 BRS PreConfig for your Derivative."
#endif

/*** MACROS ***/
/* Protected write macro to access protected registers */
#define PROT_WRITEX(reg,val) (reg)=(uint32)(val);     /* write value */          \
                             (reg)=(uint32)(~(val));  /* write inversed value */ \
                             (reg)=(uint32)(val);     /* write value */

/* PROTCMD0 -> PLLEk, CKSC_0n */
#define PROT_WRITE0(reg,val) PROTCMD0=0xa5;  /* write to protected register */   \
                             PROT_WRITEX(reg,val)

/* PROTCMD1 -> CKSC_1 */
#define PROT_WRITE1(reg,val) PROTCMD1=0xa5;  /* write to protected register */   \
                             PROT_WRITEX(reg,val)

/* PROTCMD2 -> MOSCE, SOSCE, ROSCE, CKSC_An, PSC0-2, SWRESA */
#define PROT_WRITE2(reg,val) PROTCMD2=0xa5;  /* write to protected register */   \
                             PROT_WRITEX(reg,val)

/* PROTCMDD1 -> e.g. PLL2, CLKJIT, CLKFIX, PLLFIXCLK, C_ISO_XCCLK, RSCANPCLK,
                C_ISO_RSCAN, C_ISO_RSCANXIN, C_ISO_TAUB01, C_ISO_TAUJ, C_ISO_OSTM,
                C_ISO_RLIN, PLL0PIXCLK, PLL2INCLK, PLL2CLK */
#define PROT_WRITE3(reg,val) PROTCMDD1=0xa5;  /* write to protected register */ \
                             PROT_WRITEX(reg,val)

/* PROTCMDMRST1 -> MRSTC protection command register */
#define PROT_WRITE4(reg,val) PROTCMDMRST=0xa5;  /* write to protected register */ \
                             PROT_WRITEX(reg,val)

#if defined (BRS_ENABLE_FBL_SUPPORT)
  #define FLMDPCMD BRSHW_IOS(uint32 , 0xFFA00004)
  #define FLMDPS   BRSHW_IOS(uint32 , 0XFFA00008)
  #define FLMDCNT  BRSHW_IOS(uint32 , 0xFFA00000)

  #define PROT_WRITE_VFP(reg,val) FLMDPCMD=0xa5; /* write to protected register */ \
                                PROT_WRITEX(reg,val)
#endif /*BRS_ENABLE_FBL_SUPPORT*/

/* MSR/CBD abstraction for DrvCan interrupt handling */
#if defined (BRS_ENABLE_CAN_SUPPORT)
# if defined (VGEN_ENABLE_IF_ASRIFCAN)
#  if (CAN_INTLOCK == CAN_APPL)
#   define C_INT_BY_APPL
#  endif
# else
#  if defined (C_ENABLE_OSEK_CAN_INTCTRL)
#   define C_INT_BY_APPL
#  endif
# endif
#endif

/**********************************************************************************************************************
  GLOBAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL CONST VARIABLES
**********************************************************************************************************************/
/*
 * Description: These constants are used to propagate the Versions over
 *              module boundaries.The version numbers are BCD coded. E.g. a sub
 *              version of 23 is coded with 0x23, a bug fix version of 9 is
 *              coded 0x09.
 */
uint8 const kBrsHwMainVersion   = (uint8)(BRSHW_VERSION >> 8);
uint8 const kBrsHwSubVersion    = (uint8)(BRSHW_VERSION & 0xFF);
uint8 const kBrsHwBugfixVersion = (uint8)(BRSHW_BUGFIX_VERSION);

/**********************************************************************************************************************
  LOCAL VARIABLES AND LOCAL HW REGISTERS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONTROLLER CONFIGURATION REGISTERS
**********************************************************************************************************************/

/*******************************************************************************
  PLL registers
********************************************************************************/
#if defined (BRS_ENABLE_PLLCLOCKS)
# if defined (BRS_PLL_GROUP_A) || defined (BRS_PLL_GROUP_A1) || defined (BRS_PLL_GROUP_A2) || \
     defined (BRS_PLL_GROUP_A3)|| defined (BRS_PLL_GROUP_A4)
  #define PLL_BASE_ADDRESS   0xFFF89000

  #define PLLE0      BRSHW_IOS(uint32,   PLL_BASE_ADDRESS         ) /* PLL0E / PLLE enable register */
  #define PLLS0      BRSHW_IOS(uint32,   PLL_BASE_ADDRESS + 0x04  ) /* PLL0S / PLLS status register */
  #define PLLC0      BRSHW_IOS(uint32,   PLL_BASE_ADDRESS + 0x08  ) /* PLL0C / PLLC control register */

#  if defined (BRS_PLL_GROUP_A1) || defined (BRS_PLL_GROUP_A2) || defined (BRS_PLL_GROUP_A4)
  #define PLLE1    BRSHW_IOS(uint32,   PLL_BASE_ADDRESS + 0x100  ) /* PLL1E enable register */
  #define PLLS1    BRSHW_IOS(uint32,   PLL_BASE_ADDRESS + 0x104  ) /* PLL1S status register */
  #define PLLC1    BRSHW_IOS(uint32,   PLL_BASE_ADDRESS + 0x108  ) /* PLL1C control register */
#  endif /*BRS_PLL_GROUP_A1 || BRS_PLL_GROUP_A2*/
#  if defined (BRS_PLL_GROUP_A2)
  #define PLL1CLK   480
  #define PLLFIXCLK PLL1CLK
#  endif /*BRS_PLL_GROUP_A2*/

# elif defined (BRS_PLL_GROUP_B) || \
       defined (BRS_PLL_GROUP_B1)
#  if !(BRS_TIMEBASE_CLOCK==160)
  #error "The selected CPU frequency is not supported for your derivative (please choose 160 MHz)."
#  endif
#  if !(BRS_OSC_CLK==16)
  #error "The selected clock frequency of main oscillator is not support (supported: 16 MHz only)."
#  endif

  /** Clock frequencies **/
  #define CLK_HSB 80  /* RS-CAN, FlexRay, CSIH, CSIG, RLIN3, RSENT, PSI5, SCI3, WDTA, TAUD, TAUJ, TSG3, TPBA, TAPA, ENCA, OSTM, ECM, DCRA, PIC (BRS_TIMEBASE_CLOCK/2) */

# elif defined (BRS_PLL_GROUP_C)
#  if !((BRS_TIMEBASE_CLOCK == BRS_CPU_MAX_FREQUENCY) || (BRS_TIMEBASE_CLOCK == BRS_CPU_MAX_FREQUENCY/2) || (BRS_TIMEBASE_CLOCK == BRS_CPU_MAX_FREQUENCY/4))
  #error "The selected CPU frequency is not supported for your derivative (please choose BRS_CPU_MAX_FREQUENCY devided by 1, 2 or 4 )."
#  endif
#  if !(BRS_OSC_CLK == 20)
  #error "The selected clock frequency of main oscillator is not support (supported: 20 MHz only)."
#  endif

  /** Clock frequencies **/
  #define CLKC_LSB 40  /* Unmodulated low speed peripheral clock (CAN, LIN, ATU-IV, APA, WDTA, OSTM, SCI, AD) */
  #define CLKC_HSB 80  /* Unmodulated high speed peripheral clock (TAUD, TAUJ, TSG3, TAPA, TPBA, PIC1A, PIC2B, ENCA, EMU2) */

  #define PLL0CLKS   BRSHW_IOS(uint32, 0xFFF88004) /* PLL0 status register    */
  #define PLL0CLKC1  BRSHW_IOS(uint32, 0xFFF88200) /* PLL0 control register 1 */

# elif defined (BRS_PLL_GROUP_D)
  /* reading the register from chip */
  /* reading of this register was not possible with v1 version of this chip */
  #define OPBT1     BRSHW_IOS(uint32, 0xFFCD0034) /* Option Byte 1 */

  /* Check for incompatible settings with v1 Chip */
#  if (BRS_TIMEBASE_CLOCK!=240) || ((BRS_OSC_CLK!=16)&&(BRS_OSC_CLK!=24))
  #error "BrsHw was verified successful with Oscillator=16MHz|24MHz and Cpu-Frequency=240MHz only. Renesas verified, that other frequencies cause errors on v1 versions of this chip."
#  endif

/* Configuration of System Clock Divider */
#  if (BRS_TIMEBASE_CLOCK==240)
  #define BRSHW_CLKD0DIV 0x01  /* CLK_CPU=240MHz, CLK_HSB=80MHz (STM Timer), CLK_LSB=40MHz */
  #define BRSHW_CLKD1DIV 0x01  /* CLKP_C=160MHz, CLKP_H1=80MHz, CLKP_H2=80MHz (MCAN), CLKP_L=40MHz (LIN) */
#  elif (BRS_TIMEBASE_CLOCK==160)
  #define BRSHW_CLKD0DIV 0x02  /* CLK_CPU=160MHz, CLK_HSB=80MHz (STM Timer), CLK_LSB=40MHz */
  #define BRSHW_CLKD1DIV 0x02  /* CLKP_C=80MHz,  CLKP_H1=80MHz, CLKP_H2=80MHz (MCAN), CLKP_L=40MHz (LIN) */
#  elif (BRS_TIMEBASE_CLOCK==80)
  #define BRSHW_CLKD0DIV 0x04  /* CLK_CPU=80MHz,  CLK_HSB=40MHz (STM Timer), CLK_LSB=40MHz */
  #define BRSHW_CLKD1DIV 0x04  /* CLKP_C=40MHz,  CLKP_H1=40MHz, CLKP_H2=40MHz (MCAN), CLKP_L=40MHz (LIN) */
#  else
  #error "The selected CPU clock is not yet supported by this BrsHw implemention. For assumed OPBT1.PLL0FREQ=2, 240,160 or 80 MHz are supported."
#  endif

# elif defined (BRS_PLL_GROUP_E)
  #define PLLE    BRSHW_IOS(uint32, 0xFF980000) /* PLL enable register */
  #define PLLS    BRSHW_IOS(uint32, 0xFF980004) /* PLL status register */

# elif defined (BRS_PLL_GROUP_F)
  /* reading the register from chip */
  #define OPBT1     BRSHW_IOS(uint32, 0xFFCD0034) /* Option Byte 1 */
  #define OPBT0     BRSHW_IOS(uint32, 0xFFCD0030) /* Option Byte 1 */
  /* Check for incompatible settings with v1 Chip */
#   if (BRS_TIMEBASE_CLOCK!=120) || ((BRS_OSC_CLK!=16) && (BRS_OSC_CLK!=20) && (BRS_OSC_CLK!=24))
  #error "The supported Oscillator-Frequency=16||20||24MHz and Cpu-Frequency=120MHz only."
#   endif

/* Configuration of System Clock Divider */
#   if (BRS_TIMEBASE_CLOCK==120)
  #define BRSHW_CLKD0DIV 0x01  /* CLK_CPU=120MHz, CLK_HSB=40MHz (STM Timer), CLK_LSB=40MHz */
  #define BRSHW_CLKD1DIV 0x01  /* CLKP_C=80MHz, CLKP_H1=80MHz, CLKP_H2=40MHz (MCAN), CLKP_L=40MHz (LIN), CLKP_T=40MHz */
#   else
  #error "The selected CPU clock is not yet supported by this BrsHw implemention. For assumed OPBT1.PLL0FREQ=2, 240,160 or 80 MHz are supported."
#   endif

# else
  #error "Unknown BRS_PLL_GROUP configured. Check the Cfg5 BRS PreConfig for your Derivative."
# endif /*BRS_PLL_GROUP_x*/

/*******************************************************************************
  Clock generator registers
********************************************************************************/
# if defined (BRS_CLOCK_GROUP_A) || defined (BRS_CLOCK_GROUP_A1) || defined (BRS_CLOCK_GROUP_A2)
  #define CLOCK_BASE_ADDRESS    0xFFF81000

  #define MOSCE      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x100)  /* MainOSC enable register */
  #define MOSCS      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x104)  /* MainOSC status register */
  #define MOSCC      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x108)  /* MainOSC control register */
  #define MOSCST     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x10C)  /* MainOSC stabilization time register */

  #define SOSCE      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x200)  /* SubOSC enable register */
  #define SOSCS      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x204)  /* SubOSC status register */
  #define SOSCST     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x20C)  /* SubOSC stabilization time register */

  #define ROSCE      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS        )  /* HS IntOSC enable register */
  #define ROSCS      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x04 )  /* HS IntOSC status register */

  /* Clock selector control register */
  #define CKSC_CPUCLKS_CTL   BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9000)  /* C_ISO_CPUCLK source clock selection register */
  #define CKSC_CPUCLKS_ACT   BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9008)  /* C_ISO_CPUCLK source clock active register */
  #define CKSC_CPUCLKD_CTL   BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9100)  /* C_ISO_CPUCLK clock divider register */
  #define CKSC_CPUCLKD_ACT   BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9108)  /* C_ISO_CPUCLK clock divider active register */

# if defined (BRS_CLOCK_GROUP_A2)
  #define CKSC_PPLLCLKS_CTL  BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9010) /* PPLLCLK source clock selection register */
  #define CKSC_PPLLCLKS_ACT  BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9018) /* PPLLCLK source clock active register */
# endif

# if defined (BRS_CLOCK_GROUP_A1)
  #define CKSC_IPPL0S_CTL      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x8200) /* PLL0CLK clock control register */
  #define CKSC_IPPL0S_ACT      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x8208) /* PLL0CLK clock active register */
  #define CKSC_IPPL1S_CTL      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x8300) /* PLL1CLK clock control register */
  #define CKSC_IPPL1S_ACT      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x8308) /* PLL1CLK clock active register */
  #define CKDV_ICLKJITD_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x43C0) /* CLKJIT clock divider register */
  #define CKDV_ICLKJITD_STAT   BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x43C4) /* CLKJIT clock divider status register */
  #define CKSC_ICLKJITS_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4400) /* CLKJIT source clock selection register */
  #define CKSC_ICLKJITS_ACT    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4408) /* CLKJIT source clock active register */
  #define CKDV_ICLKFIXD_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4700) /* CLKFIX clock divider register */
  #define CKDV_ICLKFIXD_STAT   BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4704) /* CLKFIX clock divider status register */
  #define CKSC_ICLKFIXS_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4740) /* CLKFIX source clock selection register */
  #define CKSC_ICLKFIXS_ACT    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4748) /* CLKFIX source clock active register */
  #define CKSC_IRSCAND_CTL     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4780) /* C_ISO_RSCAN source clock divider register */
  #define CKSC_IRSCAND_ACT     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4788) /* C_ISO_RSCAN source clock active register */
  #define CKSC_IRSCANXINS_CTL  BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4800) /* C_ISO_RSCANXIN clock selection register */
  #define CKSC_IRSCANXINS_ACT  BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4808) /* C_ISO_RSCANXIN source clock active register */
  #define CKSC_IRLINS_CTL      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4500) /* C_ISO_RLIN source clock selection register */
  #define CKSC_IRLINS_ACT      BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4508) /* C_ISO_RLIN source clock active register */
  #define CKSC_IPCRSCANS_CTL   BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4140) /* RSCANPCLK clock control register */
  #define CKSC_IPCRSCANS_ACT   BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4148) /* RSCANPCLK clock active register */
  #define CKSC_ICLKFIXS_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4740) /* CLKFIX source clock selection register */
  #define CKSC_ICLKFIXS_ACT    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4748) /* CLKFIX source clock active register */
  #define CKSC_ITAUB01S_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4740) /* C_ISO_TAUB01 source clock selection register */
  #define CKSC_ITAUB01S_ACT    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4748) /* C_ISO_TAUB01 clock active register */
  #define CKSC_IXCCLKS_CTL     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4180) /* ETNBXCCLK clock control register */
  #define CKSC_IXCCLKS_ACT     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4188) /* ETNBXCCLK clock active register */
  #define CKSC_IXCETNBS_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x41C0) /* ETNBXCCLK clock control register */
  #define CKSC_IXCETNBS_ACT    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x41C8) /* ETNBXCCLK clock active register */
  #define CKSC_IPCETNBS_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4280) /* ETNBPCLK clock control register */
  #define CKSC_IPCETNBS_ACT    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x4288) /* ETNBPCLK clock active register */

  /* Module reset control register */
  #define MRSTC                BRSHW_IOS(uint32, 0xFFF8F400) /* Module reset control register*/

# else
  #define CKSC_ICANOSCD_CTL    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9A00) /* C_ISO_CANOSC clock divider register */
  #define CKSC_ICANOSCD_ACT    BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9A08) /* C_ISO_CANOSC clock divider active register */
  #define CKSC_ICANS_CTL       BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9900) /* C_ISO_CAN source clock selection register */
  #define CKSC_ICANS_ACT       BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9908) /* C_ISO_CAN source clock active register */
  #define CKSC_ILIND_CTL       BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9800) /* C_ISO_LIN clock divider register */
  #define CKSC_ILIND_ACT       BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9808) /* C_ISO_LIN clock divider active register */
  #define CKSC_ILINS_CTL       BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9400) /* C_ISO_LIN source clock selection register */
  #define CKSC_ILINS_ACT       BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9408) /* C_ISO_LIN source clock active register */
  #define CKSC_IPERI1S_CTL     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9200) /* C_ISO_PERI1 Source Clock Selection Register */
  #define CKSC_IPERI1S_ACT     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9208) /* C_ISO_PERI1 Source Clock Active Register */
  #define CKSC_IPERI2S_CTL     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9300) /* C_ISO_PERI2 Source Clock Selection Register */
  #define CKSC_IPERI2S_ACT     BRSHW_IOS(uint32, CLOCK_BASE_ADDRESS + 0x9308) /* C_ISO_PERI2 Source Clock Active Register */
# endif /*else BRS_CLOCK_GROUP_A1*/

# elif defined (BRS_CLOCK_GROUP_B)
  /* Nothing to do, everything is static */

# elif defined (BRS_CLOCK_GROUP_C)
  #define CKSC0CTL            BRSHW_IOS(uint32, 0xFFF89000 )    /* Clock 0 selection control register */
  #define CKSC0ACT            BRSHW_IOS(uint32, 0xFFF89008 )    /* Clock 0 selection active register */
  #define CLKD0DIV            BRSHW_IOS(uint32, 0xFFF88800 )    /* Clock 0 division register */
  #define CLKD0STAT           BRSHW_IOS(uint32, 0xFFF88804 )    /* Clock 0 division status register */
  #define CKSC1CTL            BRSHW_IOS(uint32, 0xFFF89040 )    /* Clock 1 selection control register */
  #define CKSC1ACT            BRSHW_IOS(uint32, 0xFFF89048 )    /* Clock 1 selection active register */

# elif defined (BRS_CLOCK_GROUP_D)
  #define CLKD0DIV   BRSHW_IOS(uint32, 0xFFF88800)  /*Clock divider 0 divisor register*/
  #define CLKD0STAT  BRSHW_IOS(uint32, 0xFFF88804)  /*Clock divider 0 status register*/
  #define CLKD1DIV   BRSHW_IOS(uint32, 0xFFF88808)  /*Clock divider 1 divisor register*/
  #define CLKD1STAT  BRSHW_IOS(uint32, 0xFFF8880C)  /*Clock divider 1 status register*/
  #define CKSC0C     BRSHW_IOS(uint32, 0xFFF89000)  /*Clock selector 0 control register*/
  #define CKSC0S     BRSHW_IOS(uint32, 0xFFF89008)  /*Clock selector 0 status register*/

# elif defined (BRS_CLOCK_GROUP_E)
  #define MOSCE         BRSHW_IOS(uint32, 0xFF988000) /* MainOSC enable register */
  #define MOSCS         BRSHW_IOS(uint32, 0xFF988004) /* MainOSC status register */
  #define CKSC_CPUC     BRSHW_IOS(uint32, 0xFF980100) /* CLK_CPU selector control register */
  #define CKSC_CPUS     BRSHW_IOS(uint32, 0xFF980108) /* CLK_CPU selector status register */
  #define CLKD_PLLC     BRSHW_IOS(uint32, 0xFF980120) /* CLK_PLLO divider control register */
  #define CLKD_PLLS     BRSHW_IOS(uint32, 0xFF980128) /* CLK_PLLO divider status register */
  #define CLKKCPROT1    BRSHW_IOS(uint32, 0xFF980700) /* Clock Controller Register Key Code Protection Register 1 */
  #define CKSC_RCANC    BRSHW_IOS(uint32, 0xFF980150) /* CLK_RCANOSC Selector Control Register */
  #define CKSC_RCANS    BRSHW_IOS(uint32, 0xFF980158) /* CLK_RCANOSC Selector Status Register */
  #define CKSC_RLINC    BRSHW_IOS(uint32, 0xFF980140) /* CLK_RLIN Selector Control Register */
  #define CKSC_RLINS    BRSHW_IOS(uint32, 0xFF980148) /* CLK_RLIN Selector Status Register */

  #define MSRKCPROT     BRSHW_IOS(uint32, 0xFF981710)  /* Module Standby Register Key Code Protection Register */
  #define MSR_OSTM      BRSHW_IOS(uint32, 0xFF981180)  /* Module Standby Register for OSTM */
  #define MSR_TAUJ_ISO  BRSHW_IOS(uint32, 0xFF981140)  /* Module Standby Register for TAUJ0/TAUJ1 (ISO area) */
  #define MSR_TAUJ_AWO  BRSHW_IOS(uint32, 0xFF988E20)  /* Module Standby Register for TAUJ2/TAUJ3 (AWO area) */
  #define MSR_RLIN3     BRSHW_IOS(uint32, 0xFF981060)  /* Module Standby Register for RLIN3 */

  #define PBGKCPROT     BRSHW_IOS(uint32, 0xFFC7B018)  /* P-Bus Guard Key Code Protection Register */

  /* P-Bus Guard Control Registers */
  #define PBGPROT50_7   BRSHW_IOS(uint32, 0xFFC7A338)  /* Group 50, Channel 7: OSTM0 */
  #define PBGPROT50_8   BRSHW_IOS(uint32, 0xFFC7A340)  /* Group 50, Channel 8: OSTM1 */
  #define PBGPROT50_9   BRSHW_IOS(uint32, 0xFFC7A348)  /* Group 50, Channel 9: OSTM2 */
  #define PBGPROT50_10  BRSHW_IOS(uint32, 0xFFC7A350)  /* Group 50, Channel 10: OSTM3 */
  #define PBGPROT50_11  BRSHW_IOS(uint32, 0xFFC7A358)  /* Group 50, Channel 11: OSTM4 */
  #define PBGPROT50_12  BRSHW_IOS(uint32, 0xFFC7A360)  /* Group 50, Channel 12: OSTM5 */
  #define PBGPROT50_13  BRSHW_IOS(uint32, 0xFFC7A368)  /* Group 50, Channel 13: OSTM6 */
  #define PBGPROT50_14  BRSHW_IOS(uint32, 0xFFC7A370)  /* Group 50, Channel 14: OSTM7 */
  #define PBGPROT50_15  BRSHW_IOS(uint32, 0xFFC7A378)  /* Group 50, Channel 15: OSTM8 */
  #define PBGPROT51_0   BRSHW_IOS(uint32, 0xFFC7A400)  /* Group 51, Channel 0: OSTM9 */
  #define PBGPROT51_4   BRSHW_IOS(uint32, 0xFFC7A420)  /* Group 51, Channel 4: TAUJ0 */
  #define PBGPROT51_5   BRSHW_IOS(uint32, 0xFFC7A428)  /* Group 51, Channel 5: TAUJ1 */

# else
  #error "Unknown BRS_CLOCK_GROUP configured. Check the Cfg5 BRS PreConfig for your Derivative."
# endif /*BRS_CLOCK_GROUP_x*/
#endif /*BRS_ENABLE_PLLCLOCKS*/

/*******************************************************************************
  Port registers
********************************************************************************/
#if defined (BRS_ENABLE_PORT)
# if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_A1)
  #define PORT_BASE_ADDRESS  0xFFC10000

  #define P(n)        BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0000 + (0x4*n))  /* Port register -Pn */
  #define PSR(n)      BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0100 + (0x4*n))
  #define PPR(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0200 + (0x4*n))
  #define PM(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0300 + (0x4*n))  /* Port mode register - PMn */
  #define PMC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0400 + (0x4*n))  /* Port mode control register - PMCn */
  #define PFC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0500 + (0x4*n))  /* Port function control register - PFCn */
  #define PFCE(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0600 + (0x4*n))  /* Port  function control enhancing register - PFCEn */
  #define PNOT(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0700 + (0x4*n))
  #define PMSR(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0800 + (0x4*n))
  #define PMCSR(n)    BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0900 + (0x4*n))
  #define PFCAE(n)    BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0A00 + (0x4*n))
  #define PIBC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4000 + (0x4*n))  /* Port IP control register - PIPCn */
  #define PBDC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4100 + (0x4*n))  /* Port bidirection control register */
  #define PU(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4300 + (0x4*n))
  #define PIPC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4200 + (0x4*n))
  #define PODC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4500 + (0x4*n))
  #define PDSC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4600 + (0x4*n))
  #define PIS(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4700 + (0x4*n))
  #define PPROTS(n)   BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4B00 + (0x4*n))
  #define PPCMD(n)    BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4C00 + (0x4*n))

  /* Filter control register for external interrupts - used for wakeup */
  #define FCLA0CTL(n) BRSHW_IOS(uint8,  0xFFC34020 + (0x4*n))

# elif defined (BRS_PORT_GROUP_B) || defined (BRS_PORT_GROUP_B1) || defined (BRS_PORT_GROUP_B2)
  #define PORT_BASE_ADDRESS  0xFFC10000

  #define P(n)        BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0000 + (0x40*n))  /* Port register -Pn */
  #define PSR(n)      BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0004 + (0x40*n))
  #define PNOT(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0008 + (0x40*n))
  #define PPR(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x000C + (0x40*n))
  #define PM(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0010 + (0x40*n))  /* Port mode register - PMn */
  #define PMC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0014 + (0x40*n))  /* Port mode control register - PMCn */
  #define PFC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0018 + (0x40*n))  /* Port function control register - PFCn */
  #define PFCE(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x001C + (0x40*n))  /* Port  function control enhancing register - PFCEn */
  #define PMSR(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0020 + (0x40*n))
  #define PMCSR(n)    BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0024 + (0x40*n))
  #define PFCAE(n)    BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0028 + (0x40*n))
  #define PIBC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4000 + (0x40*n))  /* Port IP control register - PIPCn */
  #define PBDC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4004 + (0x40*n))  /* Port bidirection control register */
  #define PU(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x400C + (0x40*n))
  #define PODC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4014 + (0x40*n))
  #define PISA(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x402C + (0x40*n))
  #define PPROTS(n)   BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4034 + (0x40*n))
  #define PPCMD(n)    BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4030 + (0x40*n))
  #define PDSC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4018 + (0x40*n))  /* Port Drive Strength Control Register */
  #define PIPC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4008 + (0x40*n))  /* Port IP Control Register */
  #define PD(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4010 + (0x40*n))  /* Port Pull-down option Register */

#  if defined (BRS_PORT_GROUP_B)
  /*Digital Noise Elimination for external interrupts - used for wakeup */
  #define DNFAnEN(n)  BRSHW_IOS(uint8,  0xFFC30004 + (0x100*n)) /* Enable Register */
  #define FCLA1CTL(n) BRSHW_IOS(uint8,  0xFFC34020 + (0x4*n))   /* Filter control register */
#  endif

#  if defined (BRS_PORT_GROUP_B1)
  /* Filter control register for external interrupts - used for wakeup */
  #define EXINTCTL  BRSHW_IOS(uint16,  0xFFC00010)
#  endif

#  if defined (BRS_PORT_GROUP_B2)
  /* Filter control register for external interrupts - used for wakeup */
  #define FCLA0CTL(n) BRSHW_IOS(uint8,  0xFFC34000 + (0x4*n))  /* INTP0 - INTP6 */
#   endif /*BRS_PORT_GROUP_B2*/

# elif defined (BRS_PORT_GROUP_C)
  #define PORTU0_BASE_ADDRESS  0xFF618000    /* Port group number n == 0 */
  #define PORTUn_BASE_ADDRESS  0xFF610000    /* Port group number n > 0 */
  #define PORTU0_PROT_BASE_ADDRESS  0xFFC18000  /* Port group number n == 0 */
  #define PORTUn_PROT_BASE_ADDRESS  0xFFC10000  /* Port group number n > 0 */

  #define PORT_BASE_ADDRESS(n)      (n == 0 ? PORTU0_BASE_ADDRESS : PORTUn_BASE_ADDRESS)   /* if n==0 use PORTU0_BASE_ADDRESS else use PORTUn_BASE_ADDRESS*/
  #define PORT_PROT_BASE_ADDRESS(n) (n == 0 ? PORTU0_PROT_BASE_ADDRESS : PORTUn_PROT_BASE_ADDRESS)

  #define P(n)        BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x0000 + (0x40*n))  /* Port register -Pn */
  #define PSR(n)      BRSHW_IOS(uint32, PORT_BASE_ADDRESS(n) + 0x0004 + (0x40*n))
  #define PNOT(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x0008 + (0x40*n))
  #define PPR(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x000C + (0x40*n))
  #define PM(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x0010 + (0x40*n))  /* Port mode register - PMn */
  #define PMC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x0014 + (0x40*n))  /* Port mode control register - PMCn */
  #define PFC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x0018 + (0x40*n))  /* Port function control register - PFCn */
  #define PFCE(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x001C + (0x40*n))  /* Port  function control enhancing register - PFCEn */
  #define PMSR(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS(n) + 0x0020 + (0x40*n))
  #define PMCSR(n)    BRSHW_IOS(uint32, PORT_BASE_ADDRESS(n) + 0x0024 + (0x40*n))
  #define PFCAE(n)    BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x0028 + (0x40*n))
  #define PIBC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x4000 + (0x40*n))
  #define PBDC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x4004 + (0x40*n))  /* Port bidirection control register */
  #define PIPC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x4008 + (0x40*n))  /* Port IP control register - PIPCn */
  #define PU(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x400C + (0x40*n))
  #define PODC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS(n) + 0x4014 + (0x40*n))
  #define PDSC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS(n) + 0x4018 + (0x40*n))
  #define PISA(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS(n) + 0x4024 + (0x40*n))
  #define PPCMD(n)    BRSHW_IOS(uint8,  PORT_PROT_BASE_ADDRESS(n) + 0x402C + (0x40 * n))
  #define PPROTS(n)   BRSHW_IOS(uint8,  PORT_PROT_BASE_ADDRESS(n) + 0x4034 + (0x40 * n))  

  /* Filter control register for external interrupts - used for wakeup */
  #define FCLA0CTL(n) BRSHW_IOS(uint8,  0xFFC34000 + (0x4*n))  /* INTP0 - INTP6 */
  #define FCLA1CTL(n) BRSHW_IOS(uint8,  0xFFC34100 + (0x4*n))  /* INTP7 - INTP10 */

# elif defined (BRS_PORT_GROUP_D)
  #define PORT_BASE1_ADDRESS  0xFF610000
  #define PORT_BASE2_ADDRESS  0xFFC10000

  #define P(n)        BRSHW_IOS(uint16, PORT_BASE1_ADDRESS + 0x0000 + (0x40 * n))
  #define PSR(n)      BRSHW_IOS(uint32, PORT_BASE1_ADDRESS + 0x0004 + (0x40 * n))
  #define PNOT(n)     BRSHW_IOS(uint16, PORT_BASE1_ADDRESS + 0x0008 + (0x40 * n))
  #define PPR(n)      BRSHW_IOS(uint16, PORT_BASE1_ADDRESS + 0x000C + (0x40 * n))
  #define PM(n)       BRSHW_IOS(uint16, PORT_BASE1_ADDRESS + 0x0010 + (0x40 * n))
  #define PMC(n)      BRSHW_IOS(uint16, PORT_BASE1_ADDRESS + 0x0014 + (0x40 * n))
  #define PFC(n)      BRSHW_IOS(uint16, PORT_BASE1_ADDRESS + 0x0018 + (0x40 * n))
  #define PFCE(n)     BRSHW_IOS(uint16, PORT_BASE1_ADDRESS + 0x001C + (0x40 * n))
  #define PMSR(n)     BRSHW_IOS(uint32, PORT_BASE1_ADDRESS + 0x0020 + (0x40 * n))
  #define PMCSR(n)    BRSHW_IOS(uint32, PORT_BASE1_ADDRESS + 0x0024 + (0x40 * n))
  #define PFCAE(n)    BRSHW_IOS(uint16, PORT_BASE1_ADDRESS + 0x0028 + (0x40 * n))
  #define PINV(n)     BRSHW_IOS(uint32, PORT_BASE1_ADDRESS + 0x0030 + (0x40 * n))
  #define PIBC(n)     BRSHW_IOS(uint16, PORT_BASE2_ADDRESS + 0x4000 + (0x40 * n))
  #define PBDC(n)     BRSHW_IOS(uint16, PORT_BASE2_ADDRESS + 0x4004 + (0x40 * n))  /* Port bidirection control register */
  #define PIPC(n)     BRSHW_IOS(uint16, PORT_BASE2_ADDRESS + 0x4008 + (0x40 * n))
  #define PU(n)       BRSHW_IOS(uint16, PORT_BASE2_ADDRESS + 0x400C + (0x40 * n))
  #define PD(n)       BRSHW_IOS(uint16, PORT_BASE2_ADDRESS + 0x4010 + (0x40 * n))
  #define PDSC(n)     BRSHW_IOS(uint32, PORT_BASE2_ADDRESS + 0x4018 + (0x40 * n))
  #define PUCC(n)     BRSHW_IOS(uint32, PORT_BASE2_ADDRESS + 0x4028 + (0x40 * n))
  #define PPCMD(n)    BRSHW_IOS(uint8,  PORT_BASE2_ADDRESS + 0x402C + (0x40 * n))
  #define PPROTS(n)   BRSHW_IOS(uint8,  PORT_BASE2_ADDRESS + 0x4034 + (0x40 * n))
  #define PCR(n,m)    BRSHW_IOS(uint32, PORT_BASE1_ADDRESS + 0x2000 + (0x40 * n) + (0x04 * m))

  /* External Interrupt Control Register (EXINTCTL) - used for wakeup */
  #define EXINTCTL         BRSHW_IOS(uint16, 0xFFC00010)

# elif defined (BRS_PORT_GROUP_E)
  #define PORT_BASE_ADDRESS  0xFFD90000

  #define P(n)        BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0000 + (0x40*n))  /* Port register -Pn */
  #define PSR(n)      BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0004 + (0x40*n))
  #define PNOT(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0008 + (0x40*n))
  #define PPR(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x000C + (0x40*n))
  #define PM(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0010 + (0x40*n))  /* Port mode register - PMn */
  #define PMC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0014 + (0x40*n))  /* Port mode control register - PMCn */
  #define PFC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0018 + (0x40*n))  /* Port function control register - PFCn */
  #define PFCE(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x001C + (0x40*n))  /* Port  function control enhancing register - PFCEn */
  #define PMSR(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0020 + (0x40*n))
  #define PMCSR(n)    BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0024 + (0x40*n))
  #define PFCAE(n)    BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0028 + (0x40*n))
  #define PINV(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0030 + (0x40*n))
  #define PIBC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4000 + (0x40*n))
  #define PBDC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4004 + (0x40*n))  /* Port bidirection control register */
  #define PIPC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4008 + (0x40*n))  /* Port IP Control Register */
  #define PU(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x400C + (0x40*n))
  #define PD(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4010 + (0x40*n))  /* Port Pull-down option Register */
  #define PODC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4014 + (0x40*n))
  #define PDSC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4018 + (0x40*n))  /* Port Drive Strength Control Register */
  #define PIS(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x401C + (0x40*n))
  #define PISA(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4024 + (0x40*n))
  #define PUCC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4028 + (0x40*n))
  #define PODCE(n)    BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4038 + (0x40*n))
  #define PCR(n, m)   BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x2000 + (0x40*n)) + (0x04 * m))

  #define PKCPROT    BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x2F40)
  #define PWE        BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x2F44)

# elif defined (BRS_PORT_GROUP_F)
  #define PORT_BASE_ADDRESS  0xFFC10000

  #define P(n)        BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0000 + (0x40*n))  /* Port register -Pn */
  #define PSR(n)      BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0004 + (0x40*n))
  #define PNOT(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0008 + (0x40*n))
  #define PPR(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x000C + (0x40*n))
  #define PM(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0010 + (0x40*n))  /* Port mode register - PMn */
  #define PMC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0014 + (0x40*n))  /* Port mode control register - PMCn */
  #define PFC(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0018 + (0x40*n))  /* Port function control register - PFCn */
  #define PFCE(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x001C + (0x40*n))  /* Port  function control enhancing register - PFCEn */
  #define PMSR(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0020 + (0x40*n))
  #define PMCSR(n)    BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x0024 + (0x40*n))
  #define PINV(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x0030 + (0x40*n))
  #define PIBC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4000 + (0x40*n))  /* Port IP control register - PIPCn */
  #define PBDC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4004 + (0x40*n))
  #define PIPC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4008 + (0x40*n))  /* Port IP Control Register */
  #define PU(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x400C + (0x40*n))
  #define PD(n)       BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4010 + (0x40*n))  /* Port Pull-down option Register */
  #define PODC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4014 + (0x40*n))
  #define PDSC(n)     BRSHW_IOS(uint32, PORT_BASE_ADDRESS + 0x4018 + (0x40*n))  /* Port Drive Strength Control Register */
  #define PIS(n)      BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x401C + (0x40*n))
  #define PUCC(n)     BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4028 + (0x40*n))
  #define PODCE(n)    BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x4038 + (0x40*n))
  #define PCR(n,m)    BRSHW_IOS(uint16, PORT_BASE_ADDRESS + 0x2000 + (0x40*n) + (0x4*m))

  /* Filter control register for external interrupts - used for wakeup */
  #define FCLA0CTL(n) BRSHW_IOS(uint8,  0xFFC34000 + (0x4*n))  /* INTP0 - INTP6 */
  #define FCLA1CTL(n) BRSHW_IOS(uint8,  0xFFC34100 + (0x4*n))  /* INTP7 - INTP10 */

# else
  #error "Unknown BRS_PORT_GROUP configed. Check the Cfg5 BRS PreConfig for your Derivative."
# endif /*BRS_PORT_GROUP_x*/
#endif /*BRS_ENABLE_PORT*/

/*******************************************************************************
  Power Down Modes Register
********************************************************************************/
#if defined (BRSHW_POWER_DOWN_MODES)
  #define MSR_LM2  0xFFF86210 /*ICUMC*/
  #define MSR_LM3  0xFFF81710 /*MCAN/MTTCAN*/
  #define MSR_LM4  0xFFF81810 /*FlexRay*/
  #define MSR_LM5  0xFFF81910 /*GTM*/
  #define MSR_LM6  0xFFF81A10 /*Ethernet*/
  #define MSR_LM7  0xFFF81B10 /*SENT*/
  #define MSR_LM8  0xFFF81C10 /*HS-USRT*/
  #define MSR_LM10 0xFFF81E10 /*CSIH*/
  #define MSR_LM11 0xFFF81F10 /*RLIN3*/
  #define MSR_LM12 0xFFF82010 /*ADCTL*/
#endif /*BRSHW_POWER_DOWN_MODES*/

/*******************************************************************************
  Exclusive Control Register
********************************************************************************/
#define BRSHW_G0MEV(n)   BRSHW_IOS(uint32, BRSHW_G0MEV_BASE + (0x4 * n))

/*******************************************************************************
  Software Reset Register
********************************************************************************/
#if defined (BRS_RESET_GROUP_A)
  #define SWRESA   BRSHW_IOS(uint32,0xFFF80A04)
  #define RESF     BRSHW_IOS(uint32,0xFFF80760)    /* Reset factor register */
  #define BRSHW_SWRESET_TRIGGERT_MASK  0x00000001  /* Software (SWRES) reset flag */

#elif defined (BRS_RESET_GROUP_B)
  #define SWRESA   BRSHW_IOS(uint32,0xFFF8AC18)
  #define RESF     BRSHW_IOS(uint32,0xFFF82800)    /* Reset factor register */
  #define BRSHW_SWRESET_TRIGGERT_MASK  0x00000001  /* Software (SWRES) reset flag */

#elif defined (BRS_RESET_GROUP_C)
  #define SWSRESA0 BRSHW_IOS(uint32,0xFFF81100)

# if defined (BRS_DERIVATIVE_GROUP_P1H) || defined (BRS_DERIVATIVE_GROUP_P1L) || defined (BRS_DERIVATIVE_GROUP_P1M_E)
  #define RESF     BRSHW_IOS(uint32,0xFFF81000)    /* Reset factor register */
  #define BRSHW_SWRESET_TRIGGERT_MASK  0x00000008  /* Software reset flag (SRESF3) */
# else  
  #define RESF     BRSHW_IOS(uint32,0xFFF82800)    /* Reset factor register */
  #define BRSHW_SWRESET_TRIGGERT_MASK  0x00000001  /* Software (SWRES) reset flag */
#endif

#elif defined (BRS_RESET_GROUP_E)
  #define SWSRESA  BRSHW_IOS(uint32,0xFF98840C)
  #define RESF     BRSHW_IOS(uint32,0xFF988500)    /* Reset factor register */
  #define BRSHW_SWRESET_TRIGGERT_MASK  0x00000010  /* Software reset flag (SRES2F0) */

#else
  #error "Unknown BRS_RESET_GROUP configed. Check the Cfg5 BRS PreConfig for your Derivative."
#endif /*BRS_RESET_GROUP_x*/

#if defined (BRS_DERIVATIVE_GROUP_F1H)
  /* PE GUARD Registers */
  #define CPU_PEGSP      *((volatile uint16*)0xFFFEE60CUL)
  #define CPU_PEGG0MK    *((volatile uint32*)0xFFFEE680UL)
  #define CPU_PEGG0BA    *((volatile uint32*)0xFFFEE684UL)
  #define CPU_PEGG1MK    *((volatile uint32*)0xFFFEE690UL)
  #define CPU_PEGG1BA    *((volatile uint32*)0xFFFEE694UL)
  #define CPU_PEGG2MK    *((volatile uint32*)0xFFFEE6A0UL)
  #define CPU_PEGG2BA    *((volatile uint32*)0xFFFEE6A4UL)
  #define CPU_PEGG3MK    *((volatile uint32*)0xFFFEE6B0UL)
  #define CPU_PEGG3BA    *((volatile uint32*)0xFFFEE6B4UL)

  extern uint8 _Local_RAM_Core1_Section_StartAddr[];
  extern uint8 _Local_RAM_Core0_Section_StartAddr[];
#endif /*BRS_DERIVATIVE_GROUP_F1H*/

#if defined (BRS_DERIVATIVE_GROUP_E1FCC)
  /* PE GUARD Registers */
  #define CPU_PEGSP      *((volatile uint16*)0xFFFEE60CUL)
  #define CPU_PEGG0MK    *((volatile uint32*)0xFFFEE680UL)
  #define CPU_PEGG0BA    *((volatile uint32*)0xFFFEE684UL)
  #define CPU_PEGG0SP    *((volatile uint32*)0xFFFEE688UL)
  #define CPU_PEGG0PE    *((volatile uint32*)0xFFFEE68CUL)
  #define CPU_PEGG1MK    *((volatile uint32*)0xFFFEE690UL)
  #define CPU_PEGG1BA    *((volatile uint32*)0xFFFEE694UL)
  #define CPU_PEGG1SP    *((volatile uint32*)0xFFFEE698UL)
  #define CPU_PEGG1PE    *((volatile uint32*)0xFFFEE69CUL)

  extern uint8 _Local_RAM_Core1_Section_StartAddr[];
  extern uint8 _Local_RAM_Core0_Section_StartAddr[];

#endif /* BRS_DERIVATIVE_GROUP_E1FCC */

#if defined (BRS_DERIVATIVE_GROUP_D1L) || defined (BRS_DERIVATIVE_GROUP_D1M)
  /* PBG0B protection register to access INTC2 registers */
  #define FSGD0BPROT0 0xFFC4C000
#endif

/*******************************************************************************
  Interrupt Controller Register
********************************************************************************/
/* INTC1, INTC2 base address. */
#if defined (BRS_DERIVATIVE_GROUP_F1L) || defined (BRS_DERIVATIVE_GROUP_R1L)
  #define ICR_BASE0  0xFFFF9000UL
  #define ICR_BASE1  0xFFFFA000UL
#else
  #define ICR_BASE0  0xFFFEEA00UL
  #define ICR_BASE1  0xFFFFB000UL
#endif

/* Macro to access the correct EICx/ICx register depending on the source number. */
#define BRSHW_ICRADDR(x)   (((x)<32)?((ICR_BASE0)+((x)*2)):((ICR_BASE1)+((x)*2)))
/* Macro to access the lower byte of the EICx/ICx Register. */
#define BRSHW_ICRXLOW(x)   BRSHW_IOS(uint8, BRSHW_ICRADDR(x))
/* Macro to access the upper byte of the EICx/ICx Register. */
#define BRSHW_ICRXHIGH(x)  BRSHW_IOS(uint8, BRSHW_ICRADDR(x)+1)
/* ICRX Table Mode set value. */
#define ICRX_TBX_SET        0x40U  
/* ICRX Interrupt request mask bit. */
#define ICRX_MKX_SET        0x80U

/**********************************************************************************************************************
  LOCAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL CONST VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  PROTOTYPES OF LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/

/*****************************************************************************/
/**
 * @brief      This function can be used to initialize controller specific
*              stuff that is not related to one of the other InitPowerOn
*              functions (e.g. code that is always mandatory, also if MCAL
*              and/or OS is used). This function is called from BrsMain
*              immediately after BrsHwDisableInterruptAtPowerOn() during
*              initialization (if BRSHW_PREINIT_AVAILABLE is set in BrsHw.h).
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 */
/*****************************************************************************/
void BrsHwPreInitPowerOn(void)
{
#if defined (BRSHW_POWER_DOWN_MODES)
# if defined (BRS_ENABLE_CAN_SUPPORT)
  BRSHW_IOS(uint32, MSR_LM3) = 0x00;  /*MCAN/MTTCAN Register*/
# endif

# if defined (BRS_ENABLE_ETHERNET_SUPPORT)
  BRSHW_IOS(uint32, MSR_LM6) = 0x00;  /*Ethernet Register*/
# endif

# if defined (BRS_ENABLE_LIN_SUPPORT)
  BRSHW_IOS(uint32, MSR_LM11) = 0x00;  /*RLIN3 Register*/
# endif

# if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
  BRSHW_IOS(uint32, MSR_LM4) = 0x00;  /*FlexRay Register*/
# endif

  #warning "If you need addiditional peripherals, you can deactivate their power-down modes here." */
  /* BRSHW_IOS(uint32, MSR_LM2)  = 0x00;  ICUMC Register*/
  /* BRSHW_IOS(uint32, MSR_LM5)  = 0x00;  GTM Register*/
  /* BRSHW_IOS(uint32, MSR_LM7)  = 0x00;  SENT Register*/
  /* BRSHW_IOS(uint32, MSR_LM8)  = 0x00;  HS-USRT Register*/
  /* BRSHW_IOS(uint32, MSR_LM10) = 0x00;  CSIH Register*/
  /* BRSHW_IOS(uint32, MSR_LM12) = 0x00;  ADCTL Register*/
#endif /*BRSHW_POWER_DOWN_MODES*/

#if defined (BRS_DERIVATIVE_GROUP_F1H)
  /* Initializes PEGuards for cross core local ram read/write access */
  CPU_PEGSP   = (uint16)0x0001;     /* enable access via SPID */
  CPU_PEGG0MK = (uint32)0x0003F000; /* first write to mask register because this clears PEGG0BA.GnEN; Support local memory up to 256k */
  CPU_PEGG0BA = (((uint32)(_Local_RAM_Core1_Section_StartAddr) & 0xFFFF0000) | 0x4077); /* allow core 0 R/W and external master to access local RAM 1 */
  CPU_PEGG1MK = (uint32)0x0003F000; /* first write to mask register because this clears PEGG1BA.GnEN; Support local memory up to 256k */
  CPU_PEGG1BA = (((uint32)(_Local_RAM_Core0_Section_StartAddr) & 0xFFFF0000) | 0x4077); /* allow core 1 R/W and external master to access local RAM 0 */
#endif /*BRS_DERIVATIVE_GROUP_F1H*/

#if defined (BRS_DERIVATIVE_GROUP_E1FCC)
  /* Initializes PEGuards for cross core local ram read/write access */
  CPU_PEGSP   = (uint16)0x0001;     /* enable access via SPID */
  CPU_PEGG0MK = (uint32)0x00010000; /* first write to mask register because this clears PEGG0BA.GnEN; Support local memory up to 64k */
  CPU_PEGG0BA = (((uint32)(_Local_RAM_Core1_Section_StartAddr) & 0xFFFFF000) | 0x0007); /* allow core 0 R/W and external master to access local RAM 1 */
  CPU_PEGG0SP = (uint32)0x0000000F;
  CPU_PEGG0PE = (uint32)0x000000FF;
  CPU_PEGG1MK = (uint32)0x00010000; /* first write to mask register because this clears PEGG0BA.GnEN; Support local memory up to 64k */
  CPU_PEGG1BA = (((uint32)(_Local_RAM_Core0_Section_StartAddr) & 0xFFFFF000) | 0x0007); /* allow core 1 R/W and external master to access local RAM 0 */
  CPU_PEGG1SP = (uint32)0x0000000F;
  CPU_PEGG1PE = (uint32)0x000000FF;
#endif /* BRS_DERIVATIVE_GROUP_E1FCC */

#if defined (BRS_DERIVATIVE_GROUP_D1L) || defined (BRS_DERIVATIVE_GROUP_D1M)
  /* The INTC2 registers are not accessible per default as they are protected by the PBUS Guard PBG0B.
     Before accessing any of these registers, the PBG0B protection register FSGD0BPROT0 has to be set to 0x07FFFFFF */
  BRSHW_IOS(uint32, FSGD0BPROT0) = 0x07FFFFFF;
#endif
}

#if defined (BRS_ENABLE_WATCHDOG)
/*****************************************************************************/
/**
 * @brief      This function must be used to initialize the Watchdog.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 */
/*****************************************************************************/
void BrsHwWatchdogInitPowerOn(void)
{
  /* Nothing to be done here, internal Watchdog already switched off via OptionBytes */
}
#endif /*BRS_ENABLE_WATCHDOG*/

#if defined (BRS_ENABLE_PLLCLOCKS)
/*****************************************************************************/
/**
 * @brief      This function must be used to initialize the PLL.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 */
/*****************************************************************************/
void BrsHwPllInitPowerOn(void)
{
#if (BRS_TIMEBASE_CLOCK > BRS_CPU_MAX_FREQUENCY)
  #error "The selected derivative does not support frequencies above BRS_CPU_MAX_FREQUENCY (please find the defined value inside the Cfg5 BRS PreConfig for your Derivative)."
#endif

#if defined (BRS_PLL_GROUP_A) || defined (BRS_PLL_GROUP_A1) || defined (BRS_PLL_GROUP_A2) || \
    defined (BRS_PLL_GROUP_A3)|| defined (BRS_PLL_GROUP_A4)

# if defined (BRS_PLL_GROUP_A4)
#  if !((BRS_OSC_CLK==8) || (BRS_OSC_CLK==16) || (BRS_OSC_CLK==20) || (BRS_OSC_CLK==24))
  #error "The selected clock frequency of main oscillator is not supported (PLL_GROUP_A4 supports: 8, 16, 20 and 24 MHz)."
#  endif

# elif defined (BRS_PLL_GROUP_A3)
#  if !((BRS_OSC_CLK==16) || (BRS_OSC_CLK==20) || (BRS_OSC_CLK==24))
  /* Only F1KM-S1 supports OSC_CLK=8MHz when using Main OSC as source clock */
  #error "The selected clock frequency of main oscillator is not supported (PLL_GROUP_A3 supports: 16, 20 and 24 MHz)."
#  endif

# elif defined (BRS_PLL_GROUP_A2)
#  if !((BRS_OSC_CLK==8) || (BRS_OSC_CLK==12) || (BRS_OSC_CLK==16))
  #error "The selected clock frequency of main oscillator is not supported (PLL_GROUP_A2 supports: 8, 12 and 16 MHz)."
#  endif

# else /*BRS_PLL_GROUP_Ax*/
#  if !((BRS_OSC_CLK==8) || (BRS_OSC_CLK==12) || (BRS_OSC_CLK==16) || (BRS_OSC_CLK==20) || (BRS_OSC_CLK==24))
  #error "The selected clock frequency of main oscillator is not supported (supported: 8, 12, 16, 20 and 24 MHz)."
#  endif
# endif /*else BRS_PLL_GROUP_Ax*/

  PROT_WRITE0(MOSCE, 0x02);       /* stop MainOsc */
  while((MOSCS & 0x04) == 0x04);  /* wait for main osc to shutdown */

# if defined (BRS_PLL_GROUP_A3) || defined (BRS_PLL_GROUP_A4)
#  if (BRS_OSC_CLK == 8)
  MOSCC = 0x03; /* Set MainOsc gain (MOSC frequency = 8MHz) */
#  endif
#  if (BRS_OSC_CLK == 16)
  MOSCC = 0x02; /* Set MainOsc gain (MOSC frequency = 16MHz) */
#  elif (BRS_OSC_CLK == 20)
  MOSCC = 0x01; /* Set MainOsc gain (MOSC frequency = 20MHz) */
#  elif (BRS_OSC_CLK == 24)
  MOSCC = 0x00; /* Set MainOsc gain (MOSC frequency = 24MHz) */
#  endif

# elif defined (BRS_PLL_GROUP_A2)
#  if (BRS_OSC_CLK == 8)
  MOSCC = 0x05; /* Set MainOsc gain (8MHz) (and set mandatory Bit2 to '1') */
#  elif (BRS_OSC_CLK == 12) || (BRS_OSC_CLK == 16)
  MOSCC = 0x04; /* Set MainOsc gain (8MHz < MOSC frequency <= 16MHz) (and set mandatory Bit2 to '1') */
#  endif

# else /*BRS_PLL_GROUP_Ax*/
#  if (BRS_OSC_CLK == 8)
  MOSCC = 0x03; /* Set MainOsc gain (8MHz) */
#  elif (BRS_OSC_CLK == 12) || (BRS_OSC_CLK == 16)
  MOSCC = 0x02; /* Set MainOsc gain (8MHz < MOSC frequency <= 16MHz) */
#  elif (BRS_OSC_CLK == 20)
  MOSCC = 0x01; /* Set MainOsc gain (16MHz < MOSC frequency <= 20MHz) */
#  elif (BRS_OSC_CLK == 24)
  MOSCC = 0x00; /* Set MainOsc gain (24MHz < MOSC frequency <= 24MHz) */
#  endif
# endif /*else BRS_PLL_GROUP_Ax*/

# if defined (BRS_PLL_GROUP_A2) || defined (BRS_PLL_GROUP_A3) || defined (BRS_PLL_GROUP_A4)
  MOSCST = 0x1FFFF; /* Set MainOsc stabilization time to max value */
# else
  MOSCST = 0xFFFF; /* Set MainOsc stabilization time to max value */
# endif

  PROT_WRITE0(MOSCE, 0x01); /* start MainOsc */
  while((MOSCS & 0x04) != 0x04); /* Wait for stable MainOsc*/

  PROT_WRITE1(PLLE0, 0x02); /* stop PLL */
  while((PLLS0 & 0x04) == 0x04); /* wait for PLL to shutdown */

# if defined (BRS_PLL_GROUP_A4)
#  if (BRS_CPU_MAX_FREQUENCY == 120 || BRS_CPU_MAX_FREQUENCY == 160 || BRS_CPU_MAX_FREQUENCY == 240)
#   if (BRS_TIMEBASE_CLOCK == 120 || BRS_TIMEBASE_CLOCK == 160 || BRS_TIMEBASE_CLOCK == 240)
#    if (BRS_OSC_CLK == 8)
  #define M_DIVIDER  0 /* Mr Value =  1 */
  #define NR_VALUE  59 /* Nr Value = 60 */
#    elif (BRS_OSC_CLK == 16)
  #define M_DIVIDER  1 /* Mr Value =  2 */
  #define NR_VALUE  59 /* Nr Value = 60 */
#    elif (BRS_OSC_CLK == 20)
  #define M_DIVIDER  1 /* Mr Value =  2 */
  #define NR_VALUE  47 /* Nr Value = 48 */
#    elif (BRS_OSC_CLK == 24)
  #define M_DIVIDER  1 /* Mr Value =  2 */
  #define NR_VALUE  39 /* Nr Value = 40 */
#    endif

#   else
  /* CPU frequency of 80 MHz is not possible when using MainOSC as clock source of PLL0*/
  #error "The selected CPU frequency is not supported (please choose 120 MHz, 160 MHz or 240 MHz)."
#   endif

#  else /*BRS_CPU_MAX_FREQUENCY == 120/160/240*/
  #error "The max CPU frequency of the selected derivative is not verified."
#  endif

# elif defined (BRS_PLL_GROUP_A3)
#  if (BRS_CPU_MAX_FREQUENCY == 80 || BRS_CPU_MAX_FREQUENCY == 96 || BRS_CPU_MAX_FREQUENCY == 120)
#   if (BRS_TIMEBASE_CLOCK == 80 || BRS_TIMEBASE_CLOCK == 96 || BRS_TIMEBASE_CLOCK == 120)
#    if (BRS_OSC_CLK == 16)
  #define M_DIVIDER  1 /* Mr Value =  2 */
  #define NR_VALUE  59 /* Nr Value = 60 */
#    elif (BRS_OSC_CLK == 20)
  #define M_DIVIDER  1 /* Mr Value =  2 */
  #define NR_VALUE  47 /* Nr Value = 48 */
#    elif (BRS_OSC_CLK == 24)
  #define M_DIVIDER  1 /* Mr Value =  2 */
  #define NR_VALUE  39 /* Nr Value = 40 */
#    endif

#   else
  /* Other CPU frequencies are possible only for F1K */
  #error "The selected CPU frequency is not yet supported (please choose 80 MHz, 96 MHz or 120 MHz)."
#   endif

#  else /*BRS_CPU_MAX_FREQUENCY == 80/96/120*/
  #error "The max CPU frequency of the selected derivative is not yet verified."
#  endif

# else /*BRS_PLL_GROUP_Ax*/
#  if ((BRS_OSC_CLK == 8) || (BRS_OSC_CLK == 12))
  #define M_DIVIDER 0x0 /* Mr Value = 1 */
#  elif ((BRS_OSC_CLK == 16) || (BRS_OSC_CLK == 20))
  #define M_DIVIDER 0x1 /* Mr Value = 2 */
#  elif (BRS_OSC_CLK == 24)
  #define M_DIVIDER 0x2 /* Mr Value = 3 */
#  endif

#  if ((BRS_CPU_MAX_FREQUENCY == 80) || (BRS_CPU_MAX_FREQUENCY == 96))
#   if ((BRS_TIMEBASE_CLOCK >= 60) && (BRS_TIMEBASE_CLOCK <= 80))
  #define P_DIVIDER 0x2                          /* Par Value = 4*/

#    if ((BRS_OSC_CLK == 8) || (BRS_OSC_CLK == 16) || (BRS_OSC_CLK == 24))
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK/2) - 1)  /* Division ratio Nr */
#    elif (BRS_OSC_CLK == 12)
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK/4) +6)  /* Division ratio Nr */
#    elif (BRS_OSC_CLK == 20)
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK*2/5) -1) /* Division ratio Nr */
#    endif
#   elif ((BRS_TIMEBASE_CLOCK >= 30) && (BRS_TIMEBASE_CLOCK <= 60))
  #define P_DIVIDER 0x4                          /* Par Value = 8*/
#    if ((BRS_OSC_CLK == 8) || (BRS_OSC_CLK == 12) || (BRS_OSC_CLK == 16))
  #define NR_VALUE (BRS_TIMEBASE_CLOCK - 1)      /* Division ratio Nr */
#    elif (BRS_OSC_CLK == 20)
  #define NR_VALUE (BRS_TIMEBASE_CLOCK*4/5)      /* Division ratio Nr */

#    else
  #error "The selected clock frequency of main oscillator is not yet supported for your derivative"
#    endif

#   else
  #error "The selected CPU frequency is not yet supported (please choose min >30..80 MHz)."
#   endif

#  elif (BRS_CPU_MAX_FREQUENCY == 120)
#   if ((BRS_TIMEBASE_CLOCK >= 80) && (BRS_TIMEBASE_CLOCK <= 120))
  #define P_DIVIDER 0x2                          /* Par Value = 4*/
#    if ((BRS_OSC_CLK == 8) || (BRS_OSC_CLK == 16))
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK/2) - 1)  /* Division ratio Nr */
#    elif (BRS_OSC_CLK == 20)
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK*2/5) -1) /* Division ratio Nr */
#    endif

#   elif ((BRS_TIMEBASE_CLOCK >= 40) && (BRS_TIMEBASE_CLOCK < 80))
  #define P_DIVIDER 0x3                          /* Par Value = 8*/
#    if ((BRS_OSC_CLK == 8) || (BRS_OSC_CLK == 16))
  #define NR_VALUE (BRS_TIMEBASE_CLOCK - 1)      /* Division ratio Nr */
#    elif (BRS_OSC_CLK == 20)
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK*4/5) -1) /* Division ratio Nr */

#    else
  #error "The selected clock frequency of main oscillator is not yet supported for your derivative"
#    endif

#   else
  #error "The selected CPU frequency is not yet supported (please choose min 40..120 MHz)."
#   endif

#  elif ((BRS_CPU_MAX_FREQUENCY == 240) || (BRS_CPU_MAX_FREQUENCY == 200) || (BRS_CPU_MAX_FREQUENCY == 160))
#   if ((BRS_TIMEBASE_CLOCK > 160) && (BRS_TIMEBASE_CLOCK <= 320))
  #define P_DIVIDER 0x1                          /* Par Value = 2*/
#    if ((BRS_OSC_CLK == 8) || (BRS_OSC_CLK == 16))
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK/4) - 1)  /* Division ratio Nr */
#    elif (BRS_OSC_CLK == 20)
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK/5) - 1)  /* Division ratio Nr */

#    else
  #error "The selected clock frequency of main oscillator is not yet supported for your derivative"
#    endif
#   elif ((BRS_TIMEBASE_CLOCK > 80) && (BRS_TIMEBASE_CLOCK <= 160))
  #define P_DIVIDER 0x2                          /* Par Value = 4*/
#    if ((BRS_OSC_CLK == 8) || (BRS_OSC_CLK == 16))
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK/2) -1)   /* Division ratio Nr */
#    elif (BRS_OSC_CLK == 20)
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK*2/5) -1) /* Division ratio Nr */

#    else
  #error "The selected clock frequency of main oscillator is not yet supported for your derivative"
#    endif
#   elif ((BRS_TIMEBASE_CLOCK > 40) && (BRS_TIMEBASE_CLOCK <= 80))
  #define P_DIVIDER 0x3                          /* Par Value = 8*/
#    if ((BRS_OSC_CLK == 8) || (BRS_OSC_CLK == 16))
  #define NR_VALUE (BRS_TIMEBASE_CLOCK -1)       /* Division ratio Nr */
#    elif (BRS_OSC_CLK == 20)
  #define NR_VALUE ((BRS_TIMEBASE_CLOCK*4/5) -1) /* Division ratio Nr */

#    else
  #error "The selected clock frequency of main oscillator is not yet supported for your derivative"
#    endif

#   else
  #error "The selected CPU frequency is not yet supported (please choose min >40 .. 240 MHz)."
#   endif

#  else
  #error "The max CPU frequency of the selected derivative is not yet verified."
#  endif
# endif /*else BRS_PLL_GROUP_A3*/

  /**********************************************************************************
   *                              PLL config                                        *
   **********************************************************************************/
# if defined (BRS_PLL_GROUP_A4)
  /* PLL1 is used as source clock of PPLLCLK, and PLL0 drives CPUCLK*/
  /* VCO output range: 440 MHz to 480MHz */
  /* Modulation fequency: (40KHz for Osc_clk=8MHz/16MHz), (50KHz for Osc_clk=20MHz) and (60KHz for Osc_clk=24MHz) */
  /* SSCG mode is enabled to reduce EMI, and Frequency Modulation Range is 1% */

  /* By default, MainOSC is the source clock of PLL0 */
  PLLC0 =
    (0x6                  << 24U) |
    (0x1                  << 14U) |
    (((M_DIVIDER) & 0x03) << 11U) |
    ((NR_VALUE) & 0x7F);

  PROT_WRITE1(PLLE0, 0x01); /* Enable PLL0 */
  while((PLLS0 & 0x04) != 0x04); /* Wait for stabilized PLL0 */

  /* By default, MainOSC is the source clock of PLL1 */
  /* PPLLOUT frequency = 80 MHz */
  PROT_WRITE1(PLLE1, 0x02);  /* Disable PLL1 */
  while((PLLS1 & 0x04) == 0x04);  /* Wait for stabilized PLL1 */

  PLLC1 =
    (0x1                  << 16U) |
    (((M_DIVIDER) & 0x03) << 11U) |
    (0x3                  <<  8U) |
    ((NR_VALUE) & 0x3F);

  PROT_WRITE1(PLLE1, 0x01);  /* Enable PLL1 */
  while((PLLS1 & 0x04) != 0x04);  /* Wait for stabilized PLL1 */

# elif defined (BRS_PLL_GROUP_A3)
  /* VCO = 480MHz */
  /* 480MHz = XOsc * "Division ratio Nr" / (Mr-Value * Pr-Value) */
  /* for CPPL: Pr is derived from CKSC_CPUCLKD_CTL.CPUCLKDPLL[1:0] -> {4, 5, 6}, default: 6 */
  /* for PPPL: Pr is 6 */

  PLLC0 =
    (0x1                  << 16U) |
    (((M_DIVIDER) & 0x03) << 11U) |
    (0x3                  <<  8U) |
    ((NR_VALUE) & 0x3F);

  PROT_WRITE1(PLLE0, 0x01);  /* start PLL */
  while((PLLS0 & 0x04) != 0x04);  /* Wait for stabilized PLL */

# elif defined (BRS_PLL_GROUP_A2)
  /* Freq_VCO = PLLclk * Pr-Value */
  /* FVV is to set the PLL0 VCO output frequency range:
       000b 320 MHz < fPLL0VCOOUT <= 360 MHz
       001b 360 MHz < fPLL0VCOOUT <= 400 MHz
       010b 400 MHz < fPLL0VCOOUT <= 440 MHz
       011b 440 MHz < fPLL0VCOOUT <= 480 MHz
       100b 480 MHz < fPLL0VCOOUT <= 520 MHz
       101b 520 MHz < fPLL0VCOOUT <= 560 MHz
       110b 560 MHz < fPLL0VCOOUT <= 600 MHz
       111b 600 MHz < fPLL0VCOOUT <= 640 MHz */
#  if ((BRS_TIMEBASE_CLOCK > 180) && (BRS_TIMEBASE_CLOCK <= 200))
  #define FVV_VCOOUT_RANGE 0x1  /* Pr-Value = 2, VCO = 361-400MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 160) && (BRS_TIMEBASE_CLOCK <= 180))
  #define FVV_VCOOUT_RANGE 0x0  /* Pr-Value = 2, VCO = 321-360MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 150) && (BRS_TIMEBASE_CLOCK <= 160))
  #define FVV_VCOOUT_RANGE 0x7  /* Pr-Value = 4, VCO = 601-640MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 140) && (BRS_TIMEBASE_CLOCK <= 150))
  #define FVV_VCOOUT_RANGE 0x6  /* Pr-Value = 4, VCO = 561-600MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 130) && (BRS_TIMEBASE_CLOCK <= 140))
  #define FVV_VCOOUT_RANGE 0x5  /* Pr-Value = 4, VCO = 521-560MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 120) && (BRS_TIMEBASE_CLOCK <= 130))
  #define FVV_VCOOUT_RANGE 0x4  /* Pr-Value = 4, VCO = 481-520MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 110) && (BRS_TIMEBASE_CLOCK <= 120))
  #define FVV_VCOOUT_RANGE 0x3  /* Pr-Value = 4, VCO = 441-480MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 100) && (BRS_TIMEBASE_CLOCK <= 110))
  #define FVV_VCOOUT_RANGE 0x2  /* Pr-Value = 4, VCO = 401-440MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 90) && (BRS_TIMEBASE_CLOCK <= 100))
  #define FVV_VCOOUT_RANGE 0x1  /* Pr-Value = 4, VCO = 361-400MHz */
#  elif ((BRS_TIMEBASE_CLOCK > 80) && (BRS_TIMEBASE_CLOCK <= 90))
  #define FVV_VCOOUT_RANGE 0x0  /* Pr-Value = 4, VCO = 321-360MHz */

#  else
  #error "The selected CPU frequency is not yet supported (please choose min >80 .. 200 MHz)."
#  endif

  PLLC0 =
    (FVV_VCOOUT_RANGE <<29U) | /* Bit 29-31 */
    (M_DIVIDER <<11U) |        /* Bit 11-12 */
    (P_DIVIDER << 8U) |        /* Bit 8-10  */
    (NR_VALUE);                /* Bit 0-5   */

  PROT_WRITE1(PLLE0, 0x01);  /* start PLL */
  while((PLLS0 & 0x04) != 0x04); /* Wait for stabilized PLL */

  /* PLL1CLK = 480 MHz fix */
  /* 480MHz = XOsc * "Division ratio Nr" / (Mr-Value * Pr-Value) */
#  if (BRS_CPU_MAX_FREQUENCY == 240) /* D1M2 Derivatives */
  #define P_DIVIDER_PLL1 0x1                  /* Pr-Value = 2, PLL1clk = 266-533MHz */
  #define FVV_VCOOUT_RANGE_PLL1 0x3           /* Freq_VCO = PLLclk * Pr-Value ==> 480*2=960MHz */
  #define NR_VALUE_PLL1 ((960/BRS_OSC_CLK)-1) /* Nr-Value = (960MHz/Osc-clock)-1 (to cut Osc-clock from PLL equation) */
#  else
  #define P_DIVIDER_PLL1 0x0                  /* Pr-Value = 1, PLL1clk = 240-480MHz */
  #define FVV_VCOOUT_RANGE_PLL1 0x0           /* no FVV, write initioal value */
  #define NR_VALUE_PLL1 ((480/BRS_OSC_CLK)-1) /* Nr-Value = (480MHz/Osc-clock)-1 (to cut Osc-clock from PLL equation) */
#  endif

  PROT_WRITE1(PLLE1, 0x02);  /* stop PLL */
  while((PLLS1 & 0x04) == 0x04);  /* wait for PLL to shutdown */

  PLLC1 =
    (FVV_VCOOUT_RANGE_PLL1 << 29U) |  /* FVV; PLL1 VCO output frequency fPLL1VCOOUT=960 MHz*/
    (0x0 << 11U) |                    /* Mr Divider set to 1 */
    (P_DIVIDER_PLL1 << 8U) |          /* Bit 8-10  */
    (NR_VALUE_PLL1);                  /* Bit 0-5   */

  PROT_WRITE1(PLLE1, 0x01);  /* start PLL */
  while((PLLS1 & 0x04) != 0x04); /* Wait for stabilized PLL */

# else /*BRS_PLL_GROUP_Ax*/
  /** PLL0CLK = BRS_TIMEBASE_CLOCK **/
  PLLC0 =
    (M_DIVIDER <<11U) |  /* Bit 11-12 */
    (P_DIVIDER << 8U) |  /* Bit 8-10  */
    (NR_VALUE);          /* Bit 0-5   */

  PROT_WRITE1(PLLE0, 0x01);  /* start PLL */
  while((PLLS0 & 0x04) != 0x04); /* Wait for stabilized PLL */

  /** PLL1 **/
#  if defined (BRS_PLL_GROUP_A1)
  /* PLL1CLK = BRS_TIMEBASE_CLOCK */
  PROT_WRITE1(PLLE1, 0x02);  /* stop PLL */

  PLLC1 =
    (M_DIVIDER <<11U) |  /* Bit 11-12 */
    (P_DIVIDER << 8U) |  /* Bit 8-10  */
    (NR_VALUE);          /* Bit 0-5   */

  PROT_WRITE1(PLLE1, 0x01);  /* start PLL */
  while((PLLS1 & 0x04) != 0x04); /* Wait for stabilized PLL */
#  endif /*BRS_PLL_GROUP_A1*/
# endif /*else BRS_PLL_GROUP_Ax*/

  /**********************************************************************************
   *                         Clock selection config                                 *
   **********************************************************************************/
# if defined (BRS_CLOCK_GROUP_A2)
  /* Peripherals use PPLCLK by default on F1K, F1KM-S1 and F1KM-S4 */
  /* Config PPLLCLK -> PPLLOUT */
  PROT_WRITE1(CKSC_PPLLCLKS_CTL, 0x03);
  while(CKSC_PPLLCLKS_ACT!=0x03);

#  if defined (BRS_PLL_GROUP_A4)
  /* Set CPU clock divider to 1 and set CPLLDIV */
#   if (BRS_TIMEBASE_CLOCK == 240)
  PROT_WRITE1(CKSC_CPUCLKD_CTL, 0x29);
  while(CKSC_CPUCLKD_ACT!=0x29);
#   elif (BRS_TIMEBASE_CLOCK == 160)
  PROT_WRITE1(CKSC_CPUCLKD_CTL, 0x31);
  while(CKSC_CPUCLKD_ACT!=0x31);
#   elif (BRS_TIMEBASE_CLOCK == 120)
  PROT_WRITE1(CKSC_CPUCLKD_CTL, 0x11);
  while(CKSC_CPUCLKD_ACT!=0x11);
#   endif

  /* Maximum clock frequency of CPLL0OUT is 240 MHz, while 120 MHz for CPLL1OUT */
  /* Set CPU clock -> CPLL0OUT */
  PROT_WRITE1(CKSC_CPUCLKS_CTL, 0x0);
  while(CKSC_CPUCLKS_ACT!=0x0);

#  elif defined (BRS_PLL_GROUP_A3)
  /* Set CPU clock divider to 1 and set CPLLDIV */
#   if (BRS_TIMEBASE_CLOCK == 120)
  PROT_WRITE1(CKSC_CPUCLKD_CTL, 0x11);
  while(CKSC_CPUCLKD_ACT!=0x11);
#   elif (BRS_TIMEBASE_CLOCK == 96)
  PROT_WRITE1(CKSC_CPUCLKD_CTL, 0x09);
  while(CKSC_CPUCLKD_ACT!=0x09);
#   elif (BRS_TIMEBASE_CLOCK == 80)
  PROT_WRITE1(CKSC_CPUCLKD_CTL, 0x01);
  while(CKSC_CPUCLKD_ACT!=0x01);
#   endif

  /* Config CPU clock -> CPLLOUT (F1K) / CPLL1OUT (F1KM-S1) */
  PROT_WRITE1(CKSC_CPUCLKS_CTL, 0x03);
  while(CKSC_CPUCLKS_ACT!=0x03);

#  else
  #error "CPU clock domain has not been configured yet."
#  endif

  /** CAN clock selection  **/
#  if defined (BRS_ENABLE_CAN_SUPPORT)
  /* Set pclk for RCFDCn -> PPLLCLK (Default), Max freq: 80 MHz */
  PROT_WRITE1(CKSC_ICANS_CTL, 0x03);
  while(CKSC_ICANS_ACT!=0x03);

  /* Either clkc or clk_xincan is selected via DCS bit in RCFDCnCFDGCFG register */
  /* Set clk_xincan for RCFDCn -> MainOSC/1, Max freq: 24 MHz */
  PROT_WRITE1(CKSC_ICANOSCD_CTL, 0x01);
  while(CKSC_ICANOSCD_ACT!=0x01);
  /* Set clkc for RCFDCn ->PPLLCLK2 (Default), Max freq: 40 MHz */
  PROT_WRITE1(CKSC_IPERI2S_CTL, 0x01);
  while(CKSC_IPERI2S_ACT!=0x01);
#  endif /*BRS_ENABLE_CAN_SUPPORT*/

  /** LIN clock selection  **/
#  if defined (BRS_ENABLE_LIN_SUPPORT)
  /* Set C_ISO_LIN -> PPLLCLK2 (Default), Max freq: 40 MHz */
  PROT_WRITE1(CKSC_ILINS_CTL, 0x01);
  while(CKSC_ILINS_ACT!=0x01);
#   if defined (LIN_ENABLE_HARDWARE_INTERFACE_RLIN30_0)
  /* Set clock divider to 1 (Default) for C_ISO_LIN */
  /* Only applicable to RLIN30, Other settings are prohibited */
  PROT_WRITE1(CKSC_ILIND_CTL, 0x01);
  while(CKSC_ILIND_ACT!=0x01);
#   endif /*LIN_ENABLE_HARDWARE_INTERFACE_RLIN30_x*/
#  endif /*BRS_ENABLE_LIN_SUPPORT*/

  /** ETH clock selection for BRS_PLL_GROUP_A4
    * CPUCLK_L is supplied to ETNB, and is generated in the clock generation circuit automatically
    * By default OPTB0 = 0xFA27FFCF, thus Ethernet AVB is enabled and CKDIVMD=1 (clock divider mode for CPUCLK_L = CPUCLK/4) */
# endif /*BRS_CLOCK_GROUP_A2*/

  /** PLL activation / CLKJIT, CLKFIX configuration **/
# if defined (BRS_CLOCK_GROUP_A1)
  /* Activate PLL0CLK */
  PROT_WRITE1(CKSC_IPPL0S_CTL, 0x01);
  while(CKSC_IPPL0S_ACT!=0x01);

  /* Activate PLL1CLK */
  PROT_WRITE1(CKSC_IPPL1S_CTL, 0x01);
  while(CKSC_IPPL1S_ACT!=0x01);

  /* Configure CLKJIT */
  PROT_WRITE3(CKSC_ICLKJITS_CTL, 0x01);  /* Select CKDV_ICLKJITD_CTL as source clock for CLKJIT */
  while(CKSC_ICLKJITS_ACT!=0x01);

  /* Configure CLKFIX */
  PROT_WRITE3(CKSC_ICLKFIXS_CTL, 0x01);  /* Select CKDV_ICLKFIXD_CTL as source clock for CLKFIX */
  while(CKSC_ICLKFIXS_ACT!=0x01);
# endif /*BRS_CLOCK_GROUP_A1*/

# if defined (BRS_CLOCK_GROUP_A) || defined (BRS_CLOCK_GROUP_A1)
  /** CPU clock selection **/
  /* Set CPU clock divider to 1 */
  PROT_WRITE1(CKSC_CPUCLKD_CTL, 0x01);
  while(CKSC_CPUCLKD_ACT!=0x01);

  /* PLL -> CPU clock */
  PROT_WRITE1(CKSC_CPUCLKS_CTL, 0x03);
  while(CKSC_CPUCLKS_ACT!=0x03);

  /** CAN clock selection  **/
#  if defined (BRS_ENABLE_CAN_SUPPORT)
#   if defined (BRS_CLOCK_GROUP_A1)
  /* PLLFIXCLK /30 -> RSCANPCLK */
  PROT_WRITE3(CKSC_IRSCAND_CTL, 0x01);
  while(CKSC_IRSCAND_ACT!=0x01);

  /* Activate RSCANPCLK clock */
  PROT_WRITE3(CKSC_IPCRSCANS_CTL, 0x01);
  while(CKSC_IPCRSCANS_ACT!=0x01);

  /* MainOsc -> RSCANXIN */
  PROT_WRITE3(CKSC_IRSCANXINS_CTL, 0x01);
  while(CKSC_IRSCANXINS_ACT!=0x01);
#   else
  /* Set CAN oscillator clock divider to 1 */
  PROT_WRITE1(CKSC_ICANOSCD_CTL, 0x01);
  while(CKSC_ICANOSCD_ACT!=0x01);

  /* F1L: CPU clock    -> CAN clock*/
  /* F1H: CPU clock /2 -> CAN clock*/
  /* F1M: CPU clock /2 -> CAN clock*/
  PROT_WRITE1(CKSC_ICANS_CTL, 0x03);
  while(CKSC_ICANS_ACT!=0x03);
#   endif
#  endif /*BRS_ENABLE_CAN_SUPPORT*/

  /** LIN clock selection  **/
#  if defined (BRS_ENABLE_LIN_SUPPORT)
#   if defined (BRS_CLOCK_GROUP_A1)
  /* PLLFIXCLK /10 -> RLIN */
  PROT_WRITE3(CKSC_IRLINS_CTL, 0x01);
  while( CKSC_IRLINS_ACT!=0x01);
#   else
  /* Set LIN clock divider to 1 */
  PROT_WRITE1(CKSC_ILIND_CTL, 0x01);
  while(CKSC_ILIND_ACT!=0x01);

  /* CPU clock /2 -> LIN clock*/
  PROT_WRITE1(CKSC_ILINS_CTL, 0x01);
  while(CKSC_ILINS_ACT!=0x01);
#   endif
#  endif /*BRS_ENABLE_LIN_SUPPORT*/

  /** ETH clock selection  **/
#  if defined (BRS_ENABLE_ETHERNET_SUPPORT)
#   if defined (BRS_CLOCK_GROUP_A1)
   /* Manual:
     Before activating C_ISO_XCCLK by XCCLKSSTP = 1,
     the XC0 cross-connect software reset must be released (MRSTC.XC0RES = 1)
     and
     the Ethernet AVB MAC (ETNB0) software reset must be released (MRSTC.ETNB0RES = 1)
     and
     the Ethernet AVB MAC (ETNB0) PBUS clock ETNBPCLK must be activated by CKSC_IPCETNBS_CTL.IPCETNBSSTP = 1. */
  PROT_WRITE4(MRSTC, 0x4); /* Release ETNB0 reset */

  /* Activate ETNBPCLK clock */
  PROT_WRITE3(CKSC_IPCETNBS_CTL, 0x01);
  while(CKSC_IPCETNBS_ACT!=0x01);

  PROT_WRITE4(MRSTC, 0x2004); /* Release XC0 reset */
  /* Activate C_ISO_XCCLK clock */
  PROT_WRITE3(CKSC_IXCCLKS_CTL, 0x01);
  while(CKSC_IXCCLKS_ACT  !=0x01);

  /* Activate ETNBXCCLK clock */
  PROT_WRITE3(CKSC_IXCETNBS_CTL, 0x01);
  while(CKSC_IXCETNBS_ACT !=0x01);
#   endif /*BRS_CLOCK_GROUP_A1*/
#  endif /*BRS_ENABLE_ETHERNET_SUPPORT*/
# endif /*BRS_CLOCK_GROUP_A*/
#endif /*BRS_PLL_GROUP_A*/

#if defined (BRS_PLL_GROUP_C)
  /*PLL0 divider 0A*/
  while(PLL0CLKS!=0x07);        /* PLL0 stable and operating */

  PROT_WRITE1(CKSC0CTL, 0x23);  /* Selects the PLL0 clock. */

# if (BRS_CPU_MAX_FREQUENCY==320)
  /*Wait at least 140 cycles, until the clock gets stable*/
  BrsHwTime100NOP();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
# elif (BRS_CPU_MAX_FREQUENCY==240)
  /*Wait at least 105 cycles, until the clock gets stable*/
  BrsHwTime100NOP();
  BRSHWNOP10();
# elif (BRS_CPU_MAX_FREQUENCY==160)
  /*Wait at least 70 cycles, until the clock gets stable*/
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();

# else
  #error "this specific maximun frequencies is not yet support"
# endif

  while(CKSC0ACT!=0x23);        /* PLL0 clock is selected (PLL0: CLK_CPU, CLK_HSB, CLK_LSB)*/

  /* Change of Divider 0A */
# if (BRS_TIMEBASE_CLOCK == BRS_CPU_MAX_FREQUENCY/4)
  PROT_WRITE1(CLKD0DIV, 0x04);  /* This register specifies a frequency division ratio of divider 0A (1/4) */
# elif (BRS_TIMEBASE_CLOCK == BRS_CPU_MAX_FREQUENCY/2)
  PROT_WRITE1(CLKD0DIV, 0x02);  /* This register specifies a frequency division ratio of divider 0A (1/2) */
# elif (BRS_TIMEBASE_CLOCK == BRS_CPU_MAX_FREQUENCY)
  PROT_WRITE1(CLKD0DIV, 0x01);  /* This register specifies a frequency division ratio of divider 0A (1/1) */

# else
  #error "Other Cpu-Frequency as PLL0 with division 1/1, 1/2, 1/4 are not possible for this derivative"
# endif

  PROT_WRITE1(CKSC1CTL, 0x24);  /* Selects 1/1 clock of PLL1 */

# if (BRS_CPU_MAX_FREQUENCY==320)
  /*Wait at least 140 cycles, until the clock gets stable*/
  BrsHwTime100NOP();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
# elif (BRS_CPU_MAX_FREQUENCY==240)
  /*Wait at least 105 cycles, until the clock gets stable*/
  BrsHwTime100NOP();
  BRSHWNOP10();
# elif (BRS_CPU_MAX_FREQUENCY==160)
  /*Wait at least 70 cycles, until the clock gets stable*/
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();

# else
  #error "this specific maximun frequencies is not yet support"
# endif

  while(CLKD0STAT!=0x1);  /* Divider 0A is running at the division ratio specified in CLKD0DIV */

  while(CKSC1ACT!=0x24);  /* PLL1/1 is selected (PLL1: CLKC_HSB, CLKC_LSB) */

#endif /*BRS_PLL_GROUP_C*/

#if defined (BRS_PLL_GROUP_D)
# if !( (BRS_OSC_CLK==16) || (BRS_OSC_CLK==20) || (BRS_OSC_CLK==24))
  #error "The selected clock frequency of main oscillator is not supported (supported: 16, 20 and 24 MHz)."
# endif

  /* reading the base_address register OPBT1 from chip */
  /* reading of this register is not possible with v1 version of this chip */
  uint32 OptionByte1 = OPBT1;
  /* Bitmask PLL0FREQ  */
  uint32 PLL0FREQ = OptionByte1 & 0xC0000000;
  /* Bitmask PLL0NDIV */
  uint32 PLL0NDIV = OptionByte1 & 0x000007F8;
  /* Bitmask PLL0MDIV */
  uint32 PLL0MDIV = OptionByte1 & 0x00003800;
  /* CLKOUT = ((BRS_OSC_CLK * PLL0NDIV) / PLL0MDIV) */
  uint32 CLKOUT;
  /* estimated value for CLKOUT, depending on CPU_CLK */
  uint32 estimatedCLKOUT;

  /* Bit shifting */
  PLL0FREQ =  PLL0FREQ >> 30;
  PLL0NDIV = (PLL0NDIV >> 3)  + 0x1;
  PLL0MDIV = (PLL0MDIV >> 11) + 0x1;

# if (BRS_TIMEBASE_CLOCK == 240)
  estimatedCLKOUT = 480;
  if (PLL0FREQ != 0x2)
# elif (BRS_TIMEBASE_CLOCK == 160)
  estimatedCLKOUT = 320;
  if (PLL0FREQ != 0x1)
# elif (BRS_TIMEBASE_CLOCK == 120)
  estimatedCLKOUT = 480;
  if (PLL0FREQ != 0x0)
# else
  #error "The selected CPU frequency is not yet supported"
# endif
  {
    while(1)
    {
      /* OPBT1 (Optionbyte1) of your chip does not fit to your Makefile.config.generated settings. Please check and/or reprogram Optionbyte1. */
    }
  }

# if (BRS_OSC_CLK == 16)
  CLKOUT = ((BRS_OSC_CLK * PLL0NDIV) / PLL0MDIV);

# elif (BRS_OSC_CLK == 20)
  CLKOUT = ((BRS_OSC_CLK * PLL0NDIV) / PLL0MDIV);
# elif (BRS_OSC_CLK == 24)
  CLKOUT = ((BRS_OSC_CLK * PLL0NDIV) / PLL0MDIV);

# else
  #error "The selected clock frequency of main oscillator is not yet supported"
# endif

  if(CLKOUT != estimatedCLKOUT)
  {
    while(1)
    {
      /* OPBT1 (Optionbyte1) of your chip does not fit to your Makefile.config.generated settings. Please check and/or reprogram Optionbyte1. */
    }
  }

  CKSC0C = 0x01;       /* Configure PLL as source clock for system and peripheral clock */
  while(CKSC0S!=0x01); /* PLL clock is selected */

  /* Configuration of System Clock Divider */
  CLKD0DIV=BRSHW_CLKD0DIV; /* CLK_CPU, CLK_HSB (STM Timer), CLK_LSB */
  while(CLKD0STAT!=0x03);  /* Clock divider 0 is running at the division ratio specified in CLKD0DIV (SYNC and ACTIVE) */

  /* Configuration of Peripheral Clock Divider */
  CLKD1DIV=BRSHW_CLKD1DIV; /* CLKP_C, CLKP_H1, CLKP_H2 (MCAN), CLKP_L (LIN) */
  while(CLKD1STAT!=0x03);  /* Clock divider 0 is running at the division ratio specified in CLKD1DIV (SYNC and ACTIVE) */
#endif /*BRS_PLL_GROUP_D*/

#if defined (BRS_PLL_GROUP_E)
  /* Sanity checks */
# if !((BRS_OSC_CLK==16) || (BRS_OSC_CLK==20) || (BRS_OSC_CLK==24) || (BRS_OSC_CLK==40))
  #error "The selected clock frequency of main oscillator is not supported (supported: 16, 20, 24 and 40 MHz)."
# endif

  /* PLL frequency is set by Option Byte CKDIVMD (400/320/240) */
# if (BRS_TIMEBASE_CLOCK == 400 || BRS_TIMEBASE_CLOCK == 320 || BRS_TIMEBASE_CLOCK == 240)
  #define PLL_DIVIDER_1
# elif (BRS_TIMEBASE_CLOCK == 200 || BRS_TIMEBASE_CLOCK == 160 || BRS_TIMEBASE_CLOCK == 120)
  /* no divider */
# else
  #error "The selected CPU frequency is not supported (supported: 120, 160, 200, 240, 320 and 400 MHz)."
# endif

  CLKKCPROT1 = 0xA5A5A501;    /* enable writing to protected registers */

  /* MOSC config */
  MOSCE = 0x01;
  while (MOSCS != 0x03);      /* Enabled by default, wait for Main OSC to stabilize */
  BrsHwTime100NOP();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();

  /* PLL & CPU clock config */
  PLLE = 0x01;
  while (PLLS != 0x03);       /* Enabled by default if Option Byte STARTUPPLL is set, wait for PLL to stabilize */
  /* Wait 1.4us (140 cycles on 100 MHz) until the clock gets stable (clarification needed, HSIOSC = 200 MHz) */
  BrsHwTime100NOP();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();

  /* Clock gear up procedure, datasheet chapter 13.6.5 */
  CLKD_PLLC = 0x02;           /* Change PLL division ratio to 1/2 */
  while (CLKD_PLLS != 0x03);  /* Verify divider synchronization */
  CKSC_CPUC = 0x00;           /* Change system clock source to CLK_PLLO */
  while (CKSC_CPUS != 0x00);  /* Verify change */
# if defined (PLL_DIVIDER_1)
  CLKD_PLLC = 0x01;           /* Change PLL division ratio to 1/1 */
  while (CLKD_PLLS != 0x03);  /* Verify divider synchronization */
# endif

  /* Clock selection config */
  /* No modification needed for peripheral clocks */

  CLKKCPROT1 = 0xA5A5A500;    /* disable writing to protected registers */

  /* Standby controller configuration to enable peripheral clocks */
  MSRKCPROT = 0xA5A5A501;     /* Enable writing to protected registers of standby controller */
  MSR_OSTM     = 0x0;         /* Enable clocks for OSTMn */
  MSR_TAUJ_ISO = 0x0;         /* Enable clocks for TAUJ0/1 */
  MSR_TAUJ_AWO = 0x0;         /* Enable clocks for TAUJ2/3 */
# if defined (BRS_ENABLE_LIN_SUPPORT)
  MSR_RLIN3    = 0x0;         /* Enable clocks for RLIN3 */
# endif
  MSRKCPROT = 0xA5A5A500;     /* Disable writing to protected registers of standby controller */

  /* Peripheral guard configuration to enable write access for all timers */
  PBGKCPROT = 0xA5A5A501;
  PBGPROT50_7 |= 0x2;
  PBGPROT50_8 |= 0x2;
  PBGPROT50_9 |= 0x2;
  PBGPROT50_10 |= 0x2;
  PBGPROT50_11 |= 0x2;
  PBGPROT50_12 |= 0x2;
  PBGPROT50_13 |= 0x2;
  PBGPROT50_14 |= 0x2;
  PBGPROT50_15 |= 0x2;
  PBGPROT51_0 |= 0x2;
  PBGPROT51_4 |= 0x2;
  PBGPROT51_5 |= 0x2;
  PBGKCPROT = 0xA5A5A500;
#endif /*BRS_PLL_GROUP_E*/

#if defined (BRS_PLL_GROUP_F)
# if !( (BRS_OSC_CLK==16) || (BRS_OSC_CLK==20) || (BRS_OSC_CLK==24))
  #error "The selected clock frequency of main oscillator is not supported (supported: 16, 20 and 24 MHz)."
# endif
  /* reading the base_address register OPBT1 from chip */
  uint32 OptionByte1 = OPBT1;

  /* Bitmask PLL0FREQ  */
  uint32 PLL0FREQ = OptionByte1 & 0xC0000000;
  /* Bitmask PLL0NDIV */
  uint32 PLL0NDIV = OptionByte1 & 0x000007F8;
  /* Bitmask PLL0MDIV */
  uint32 PLL0MDIV = OptionByte1 & 0x00003800;
  /* Bitmask PLL0PDIV */
  uint32 PLL0PDIV = OptionByte1 & 0x00000007;
  /* CLKOUT = ((BRS_OSC_CLK * PLL0NDIV) / PLL0MDIV) */
  uint32 CLKOUT;
  /* estimated value for CLKOUT, depending on CPU_CLK */
  uint32 estimatedCLKOUT;

  /* Bit shifting */
  PLL0FREQ =  PLL0FREQ >> 30;
  PLL0NDIV = (PLL0NDIV >> 3)  + 0x1;
  PLL0MDIV = (PLL0MDIV >> 11) + 0x1;
  PLL0PDIV = PLL0PDIV + 0x1;

# if (BRS_TIMEBASE_CLOCK == 120)
  estimatedCLKOUT = 240;
  if (PLL0FREQ != 0x3)
# else
  #error "The selected CPU frequency is not yet supported"
# endif
  {
    while(1)
    {
      /* OPBT1 (Optionbyte1) of your chip does not fit to your makefile.config settings. Please check and/or reprogram Optionbyte1. */
    }
  }

# if (BRS_OSC_CLK == 16)
  CLKOUT = (((BRS_OSC_CLK * PLL0NDIV) / PLL0MDIV) / PLL0PDIV);
# elif (BRS_OSC_CLK == 20)
  CLKOUT = (((BRS_OSC_CLK * PLL0NDIV) / PLL0MDIV) / PLL0PDIV);
# elif (BRS_OSC_CLK == 24)
  CLKOUT = (((BRS_OSC_CLK * PLL0NDIV) / PLL0MDIV) / PLL0PDIV);

# else
  #error "The selected clock frequency of main oscillator is not yet supported"
# endif

  if(CLKOUT != estimatedCLKOUT)
  {
    while(1)
    {
      /* OPBT1 (Optionbyte1) of your chip does not fit to your makefile.config settings. Please check and/or reprogram Optionbyte1. */
    }
  }

  CKSC0C = 0x01;       /* Configure PLL as source clock for system and peripheral clock */
  while(CKSC0S!=0x01); /* PLL clock is selected */

  /* Configuration of System Clock Divider */
  CLKD0DIV=BRSHW_CLKD0DIV; /* CLK_CPU, CLK_HSB (STM Timer), CLK_LSB */
  while(CLKD0STAT!=0x03);  /* Clock divider 0 is running at the division ratio specified in CLKD0DIV (SYNC and ACTIVE) */

  /* Configuration of Peripheral Clock Divider */
  CLKD1DIV=BRSHW_CLKD1DIV; /* CLKP_C, CLKP_H1, CLKP_H2 (MCAN), CLKP_L (LIN) */
  while(CLKD1STAT!=0x03);  /* Clock divider 0 is running at the division ratio specified in CLKD1DIV (SYNC and ACTIVE) */
#endif /*BRS_PLL_GROUP_F*/
}
#endif /*BRS_ENABLE_PLLCLOCKS*/

#if defined (BRS_ENABLE_PORT)
/*******************************************************************************
  Port Pin initialization helper functions for usage of BrsHw_Ports.h
********************************************************************************/
/*****************************************************************************/
/**
 * @brief      This function sets port alternative mode registers.
 * @pre        Port pin configurations available within BrsHw_Ports.h and
 *             no DrvPort used for port pin initialization.
 * @param[in]  p - brsHw_Port_PortType, to be initialized.
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwInitPortInput() and
 *             BrsHwInitPortOutput() locally.
 */
/*****************************************************************************/
void BrsHwInitPortAlternative(brsHw_Port_PortType p)
{
#if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_A1)
  /* workaround for disabling the protected open drain on P0_0 (at least for some F1x derivatives) */
  if ((p.portGroup == BRSHW_PORT_PORTGROUP_0) && (p.portNumber == BRSHW_PORT_PORTNUMBER_0))
  {
    /* procedure to write to protected register */
    PPCMD(p.portGroup) = 0xA5;
    /* procedure: write, write inverse, write */
    BRSHWNOP10();
    PODC(p.portGroup) &= ~(1 << p.portNumber);
    BRSHWNOP10();
    PODC(p.portGroup) ^= ~(1 << p.portNumber);
    BRSHWNOP10();
    PODC(p.portGroup) &= ~(1 << p.portNumber);
    if (PPROTS(p.portGroup) == 1)
      while(1); /* An error occured during access on protected register. Pleasee check the pin configuration */  /* write to protected register */
  }
#endif /*BRS_PORT_GROUP_A || defined (BRS_PORT_GROUP_A1)*/

  if (p.portAlternative == BRSHW_PORT_ALT_0)
  {
    PMC(p.portGroup) &= ~(1 << p.portNumber); /* Enable port mode function */
  }
  else
  {
    /* Disables the input buffer */
    PIBC(p.portGroup) &=  ~(1 << p.portNumber);
    /* clear port alternative bits */

#if !defined(BRS_PORT_GROUP_F) /* Port Group F only supports ALT_1 -> ALT_4 --> PFCAE is not available */
    PFCAE(p.portGroup) &= ~(1 << p.portNumber);
#endif
    PFCE(p.portGroup) &= ~(1 << p.portNumber);
    PFC(p.portGroup) &= ~(1 << p.portNumber);
    /* portAlternative value can be translated to a (PFCAE, PFCE, PFC) binary
       composition by substraction with 1:
            PFCAE | PFCE | PFC
    ALT_1 ->  0       0     0  ; 000b = 1-1
    ALT_2 ->  0       0     1  ; 001b = 2-1
    ALT_3 ->  0       1     0  ; 010b = 3-1
    ALT_4 ->  0       1     1  ; 011b = 4-1
    ALT_5 ->  1       0     0  ; 100b = 5-1
    ALT_6 ->  1       0     1  ; 101b = 6-1
    ALT_7 ->  1       1     0  ; 110b = 7-1 */

#if !defined(BRS_PORT_GROUP_F) /* Port Group F only supports ALT_1 -> ALT_4 --> PFCAE is not available */
    /* set PFCAE - substract by 1 and look at alternative BIT2 */
    if (((p.portAlternative - 1) & 0x4) == 0x4)
    {
      PFCAE(p.portGroup) |= (1 << p.portNumber);
    }
#endif
    /* set PFCE  - substract by 1 and look at alternative BIT1 */
    if (((p.portAlternative - 1) & 0x2) == 0x2)
    {
      PFCE(p.portGroup) |= (1 << p.portNumber);
    }
    /* set PFC   - substract by 1 and look at alternative BIT0 */
    if (((p.portAlternative - 1) & 0x1) == 0x1)
    {
      PFC(p.portGroup) |= (1 << p.portNumber);
    }
    PMC(p.portGroup) |= (1 << p.portNumber); /* Enable alternative port function */
  }
}

/*****************************************************************************/
/**
 * @brief      This function configures a port pin as input pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h and
 *             no DrvPort used for port pin initialization.
 * @param[in]  p - brsHw_Port_PortType, to be initialized.
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() locally.
 */
/*****************************************************************************/
void BrsHwInitPortInput(brsHw_Port_PortType p)
{
  PM(p.portGroup)    |=  (1 << p.portNumber); /* Set Pin as input */
  BrsHwInitPortAlternative(p);

  /* RH850/E1M-S2 HW UserManual Rev1.00 - 2.1.4.2 Configuration of Pin Function - (6) PIBCn - Port Input Buffer Control Register:
     However, when the pin is used as an input pin in S/W I/O control alternative mode (PMCn.PMCn_m = 1 and PIPCn.PIPCn_m = 0) or
     direct I/O control alternative mode (PMCn.PMCn_m = 1 and PIPCn.PIPCn_m = 1), set PIBCn.PIBCn_m = 0. */
  /* Setting to '0' already done within BrsHwInitPortAlternative(). So, setting to '1' is prevented here. */
  /* Value of PIBC in general not used for pins in alternative mode,
     setting only useful for pins in port mode (see 2.1.2.3 Pin Data Input/Output) */
  if (p.portAlternative == BRSHW_PORT_ALT_0)
    PIBC(p.portGroup)  |=  (1 << p.portNumber); /* Enables the input buffer */
}

/*****************************************************************************/
/**
 * @brief      This function configures a port pin as output pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h and
 *             no DrvPort used for port pin initialization.
 * @param[in]  p - brsHw_Port_PortType, to be initialized.
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() locally.
 */
/*****************************************************************************/
void BrsHwInitPortOutput(brsHw_Port_PortType p)
{
  PM(p.portGroup) &= ~(1 << p.portNumber); /* Clear pin as output */
  BrsHwInitPortAlternative(p);
}

/*****************************************************************************/
/**
 * @brief      This function configures a port pin as input and output pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h and
 *             no DrvPort used for port pin initialization.
 * @param[in]  p - brsHw_Port_PortType, to be initialized.
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() locally.
 */
/*****************************************************************************/
void BrsHwInitPortInputOutput(brsHw_Port_PortType p)
{
  PBDC(p.portGroup) |= (1 << p.portNumber); /* Bidirectional mode enabled. */
  BrsHwInitPortAlternative(p);
}

/*****************************************************************************/
/**
 * @brief      This function configures the port pin configuration registers
 *             (pull-up, drive strength, open drain, protection)
 * @pre        Port pin configurations available within BrsHw_Ports.h and
 *             no DrvPort used for port pin initialization.
 * @param[in]  p - brsHw_Port_PortType, to be initialized,
 *             n - brsHw_Port_ConfType, for port pin configuration
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() and
 *             BrsHwEvaBoardInitPowerOn() locally.
 */
/*****************************************************************************/
void BrsHwInitPortConfig(brsHw_Port_PortType p, brsHw_Port_ConfType n)
{
  if (n.PortPullUp == PORT_PULL_UP_ENABLED)
  {
    PU(p.portGroup) |= (1 << p.portNumber);
  }
  else
  {
    PU(p.portGroup) &= ~(1 << p.portNumber);
  }

  if (n.PortIPControl == PORT_IP_CONTROL_ENABLED)
  {
    PIPC(p.portGroup)  |= (1 << p.portNumber);
  }
  else
  {
    PIPC(p.portGroup)  &= ~(1 << p.portNumber);
  }

  if (n.PortDriveStrength == PORT_DRIVE_STRENGTH_CONTROL_ENABLED)
  {
    if (n.PortProtectionCMD == PORT_PROTECTION_COMMAND_ENABLED)
    {
#if (!defined (BRS_PORT_GROUP_E)) && (!defined(BRS_PORT_GROUP_F))
      PPCMD(p.portGroup) = 0xA5;
      BRSHWNOP10();
#endif
      PDSC(p.portGroup) |= (1 << p.portNumber);
      BRSHWNOP10();
      PDSC(p.portGroup) ^= ~(1 << p.portNumber);
      BRSHWNOP10();
      PDSC(p.portGroup) |= (1 << p.portNumber);
#if !defined (BRS_PORT_GROUP_E) && !defined(BRS_PORT_GROUP_F)
      if (PPROTS(p.portGroup) == 1)
        while(1); /* An error occured during access on protected register. Pleasee check the pin configuration */
#endif
    }
    else
    {
      PDSC(p.portGroup) |= (1 << p.portNumber);
    }
  }
  else
  {
    if (n.PortProtectionCMD == PORT_PROTECTION_COMMAND_ENABLED)
    {
#if (!defined (BRS_PORT_GROUP_E)) && (!defined(BRS_PORT_GROUP_F))
      PPCMD(p.portGroup) = 0xA5;
      BRSHWNOP10();
#endif
      PDSC(p.portGroup) &= ~(1 << p.portNumber);
      BRSHWNOP10();
      PDSC(p.portGroup) ^= ~(1 << p.portNumber);
      BRSHWNOP10();
      PDSC(p.portGroup) &= ~(1 << p.portNumber);
#if !defined (BRS_PORT_GROUP_E) && !defined(BRS_PORT_GROUP_F)
      if (PPROTS(p.portGroup) == 1)
        while(1); /* An error occured during access on protected register. Pleasee check the pin configuration */
#endif
    }
    else
    {
      PDSC(p.portGroup) &= ~(1 << p.portNumber);
    }
  }

  if (n.PortBidirectionalMode == PORT_BIDIRECTIONAL_MODE_ENABLED)
  {
    PBDC(p.portGroup) |= (1 << p.portNumber);
  }
  else
  {
    PBDC(p.portGroup) &= ~(1 << p.portNumber);
  }
}

# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
/*****************************************************************************/
/**
 * @brief      This function sets the output level of a port pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h,
 *             no DrvPort used for port pin initialization and
 *             transferred port pin has to be initialized as output pin with
 *             GPIO functionality.
 * @param[in]  p     - brsHw_Port_PortType, to be set,
 *             Level - level, port pin has to be set to
 *                     (BRSHW_PORT_LOGIC_LOW or BRSHW_PORT_LOGIC_HIGH).
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() and
 *             provided to external modules (e.g. BrsMainTogglePin()).
 */
/*****************************************************************************/
void BrsHwPort_SetLevel(brsHw_Port_PortType p, uint8 Level)
{
  if (Level != BRSHW_PORT_LOGIC_LOW)
  {
    P(p.portGroup) |= (1 << p.portNumber); /* set port-pin-level to high */
  }
  else
  {
    P(p.portGroup) &= ~(1 << p.portNumber); /* set port-pin-level to low */
  }
}
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif

/*****************************************************************************/
/**
 * @brief      This function reads the input level of a port pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h,
 *             no DrvPort used for port pin initialization and
 *             transferred port pin has to be initialized as input pin with
 *             GPIO functionality.
 * @param[in]  p - brsHw_Port_PortType, to be read.
 * @param[out] -
 * @return     Level, read from port pin
 *             (BRSHW_PORT_LOGIC_LOW or BRSHW_PORT_LOGIC_HIGH).
 * @context    Function is provided to external modules.
 */
/*****************************************************************************/
uint8 BrsHwPort_GetLevel(brsHw_Port_PortType p)
{
  uint32 temp;
  temp = PPR(p.portGroup);
  temp &= (1 << p.portNumber);

  if(temp != 0x00000000)
  {
    return BRSHW_PORT_LOGIC_HIGH;
  }
  else
  {
    return BRSHW_PORT_LOGIC_LOW;
  }
}

/*****************************************************************************/
/**
 * @brief      This function must be used to initialize the used ports.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 */
/*****************************************************************************/
void BrsHwPortInitPowerOn(void)
{
#if defined (BRS_PORT_GROUP_E)
  /* Disable port protection completely */
  PKCPROT = 0xA5A5A501;   /* Enable modification of PWE register */
  PWE = 0xFFFFFFE;        /* Enable write to all port registers */
#endif

#if defined (BRS_ENABLE_SUPPORT_LEDS)
  BrsHwInitPortOutput(BRSHW_PORT_LED);

  /* Set LED on EVB demo board to show the system is alive */
  BrsMainTogglePin(BRSMAIN_TOGGLEPIN_LED);
#endif

#if defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN)
  BrsHwInitPortOutput(BRSHW_PORT_TOGGLE_WD);
#endif

#if defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
  BrsHwInitPortOutput(BRSHW_PORT_TOGGLE_CUSTOM);
#endif

#if defined (BRS_PORT_GROUP_B2)
  /* Flexray && LIN - incompatible configuration check */
# if defined (BRS_ENABLE_FLEXRAY_SUPPORT) && defined (BRS_ENABLE_LIN_SUPPORT)
#  if ((defined (BRS_ENABLE_LIN_CHANNEL_2) || defined (LIN_ENABLE_HARDWARE_INTERFACE_RLIN32_0) || defined (SIO_ENABLE_RLIN3_2)) && defined (BRS_ENABLE_FLEXRAY_SUPPORT))
#   if (FR_CHANNEL_A_USED == STD_ON)
  #error "No possibility to configure LIN on Port 7.5 (RLIN32TX) and Flexray on Port 7.5 (FLX1TXDA) simultaneously"
#   endif /*FR_CHANNEL_A_USED*/
#  endif
# endif

  /* Flexray && Ethernet - incompatible configuration check */
# if defined (BRS_ENABLE_FLEXRAY_SUPPORT) && defined (BRS_ENABLE_ETHERNET_SUPPORT)
  #error "No possibility to configure FlexRay Modul 2 and Ethernet Modul 2 simultaneously"
  #error "No possibility to configure FlexRay Modul 1 and Ethernet Modul 1 simultaneously"
# endif
#endif /*BRS_PORT_GROUP_B2*/

/*******************************************************************************
  CAN driver
********************************************************************************/
#if defined (BRS_ENABLE_CAN_SUPPORT)
# if defined (BRS_ENABLE_CAN_CHANNEL_0)
  BrsHwInitPortOutput(BRSHW_PORT_CAN0_TX);
  BrsHwInitPortInput(BRSHW_PORT_CAN0_RX);
#  if defined(_BRSHW_PORT_CAN0_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN0_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN0_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#  endif
#  if defined (_BRSHW_PORT_CAN0_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN0_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN0_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#  endif

#  if defined (BRSHW_ENABLE_CAN_WAKEUP_FILTER)
#   if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_A1)
  FCLA0CTL(0) = 0x02; /* configure filter control register for external wakeup / INTP0 / falling edge */
#   endif
#   if defined (BRS_PORT_GROUP_B)
  FCLA1CTL(5) = 0x02; /* configure filter control register for external wakeup / INTP5 / falling edge */
  DNFAnEN(2) |= (1 << 1); /* enable filter control register for external wakeup / INTP5 */
#   endif
#   if defined (BRS_PORT_GROUP_B1)
  EXINTCTL |= (1 << 5); /* configure External Interrupt control register for external wakeup */
  /* 5 correspond to INTP2 with falling edge detection*/
  /* INTP2 / Port 0_5 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN0_WAKEUP);
#   endif
#  if defined (BRS_PORT_GROUP_B2)
  FCLA0CTL(2) |= (1 << 1); /*INTP1, falling edge detection*/
  /* INTP1 / Port 4.12 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN0_WAKEUP);
#   endif
#   if defined (BRS_PORT_GROUP_C)
  FCLA0CTL(7) = 0x02; /* configure filter control register for external wakeup / INTP6 / falling edge */
#   endif
#   if defined (BRS_PORT_GROUP_D)
  EXINTCTL |= (1 << 1); /* configure External Interrupt control register for external wakeup */
  /* IRQ0 / Port 2_0 */
  BrsHwInitPortInput(BRSHW_PORT_CAN0_WAKEUP);
#   endif
#    if defined (BRS_PORT_GROUP_F)
  FCLA0CTL(6) |= (1 << 1); /*INTP5, falling edge detection*/
  /* INTP5 / Port 2.7 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN0_WAKEUP);
#    endif /*BRS_PORT_GROUP_F*/  
#  endif /*BRSHW_ENABLE_CAN_WAKEUP_FILTER*/
# endif /*BRS_ENABLE_CAN_CHANNEL_0*/

# if defined (BRS_ENABLE_CAN_CHANNEL_1)
  BrsHwInitPortOutput(BRSHW_PORT_CAN1_TX);
  BrsHwInitPortInput(BRSHW_PORT_CAN1_RX);
#  if defined(_BRSHW_PORT_CAN1_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN1_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN1_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#  endif
#  if defined (_BRSHW_PORT_CAN1_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN1_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN1_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#  endif

#  if defined (BRSHW_ENABLE_CAN_WAKEUP_FILTER)
#   if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_A1)
  FCLA0CTL(1) = 0x02; /* configure filter control register for external wakeup / INTP1 / falling edge */
#   endif
#   if defined (BRS_PORT_GROUP_B)
  FCLA1CTL(6) = 0x02; /* configure filter control register for external wakeup / INTP6 / falling edge */
  DNFAnEN(2) |= (1 << 2); /* enable filter control register for external wakeup / INTP6 */
#   endif
#   if defined (BRS_PORT_GROUP_B1)
  EXINTCTL |= (1 << 7); /* configure External Interrupt control register for external wakeup */
  /* 7 correspond to INTP3 with falling edge detection*/
  /* INTP3 / Port 0_6 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN1_WAKEUP);
#   endif
#   if defined (BRS_PORT_GROUP_B2)
  FCLA0CTL(3) |= (1 << 1); /*INTP2, falling edge detection*/
  /* INTP2 / Port 5.13 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN1_WAKEUP);
#   endif
#   if defined (BRS_PORT_GROUP_C)
  FCLA1CTL(1) = 0x02; /* configure filter control register for external wakeup / INTP8 / falling edge */
#   endif
#   if defined (BRS_PORT_GROUP_D)
  EXINTCTL |= (1 << 3); /* configure External Interrupt control register for external wakeup */
  /* IRQ1 / Port 2_1 */
  BrsHwInitPortInput(BRSHW_PORT_CAN1_WAKEUP);
#   endif
#   if defined (BRS_PORT_GROUP_F)
  FCLA1CTL(0) |= (1 << 1); /*INTP, falling edge detection*/
  /* INTP7 / Port 3.8 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN1_WAKEUP);
#   endif /*BRS_PORT_GROUP_F*/
#  endif /*BRSHW_ENABLE_CAN_WAKEUP_FILTER*/
# endif /*BRS_ENABLE_CAN_CHANNEL_1*/

# if defined (BRS_ENABLE_CAN_CHANNEL_2)
  BrsHwInitPortOutput(BRSHW_PORT_CAN2_TX);
  BrsHwInitPortInput(BRSHW_PORT_CAN2_RX);
#  if defined(_BRSHW_PORT_CAN2_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN2_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN2_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#  endif
#  if defined (_BRSHW_PORT_CAN2_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN2_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN2_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#  endif

#  if defined (BRSHW_ENABLE_CAN_WAKEUP_FILTER)
#   if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_A1)
  FCLA0CTL(2) = 0x02; /* configure filter control register for external wakeup / INTP2 / falling edge */
#   endif
#   if defined (BRS_PORT_GROUP_B1)
  EXINTCTL |= (1 << 9); /* configure External Interrupt control register for external wakeup */
  /* 9 correspond to INTP4 with falling edge detection*/
  /* INTP4 / Port 0_7 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN2_WAKEUP);
#   endif
#   if defined (BRS_PORT_GROUP_B2)
  FCLA0CTL(4) |= (1 << 1); /*INTP3, falling edge detection*/
  /* INTP3 / Port 0.5 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN2_WAKEUP);
#   endif
#   if defined (BRS_PORT_GROUP_C)
  FCLA1CTL(3) = 0x02; /* configure filter control register for external wakeup / INTP3 / falling edge */
#   endif
#   if defined (BRS_PORT_GROUP_D)
  EXINTCTL |= (1 << 5); /* configure External Interrupt control register for external wakeup */
  /* IRQ2 / Port 2_2 */
  BrsHwInitPortInput(BRSHW_PORT_CAN2_WAKEUP);
#   endif
#  endif /*BRSHW_ENABLE_CAN_WAKEUP_FILTER*/
# endif /*BRS_ENABLE_CAN_CHANNEL_2*/

# if defined (BRS_ENABLE_CAN_CHANNEL_3)
  BrsHwInitPortOutput(BRSHW_PORT_CAN3_TX);
  BrsHwInitPortInput(BRSHW_PORT_CAN3_RX);
#  if defined(_BRSHW_PORT_CAN3_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN3_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN3_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#  endif
#  if defined (_BRSHW_PORT_CAN3_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN3_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN3_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#  endif

#  if defined (BRSHW_ENABLE_CAN_WAKEUP_FILTER)
#   if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_A1)
  FCLA0CTL(3) = 0x02; /* configure filter control register for external wakeup / INTP3 / falling edge */
#   endif
#   if defined (BRS_PORT_GROUP_B1)
  EXINTCTL |= (1 << 11); /* configure External Interrupt control register for external wakeup */
  /* 11 correspond to INTP5 with falling edge detection*/
  /* INTP5 / Port 0_8 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN3_WAKEUP);
#   endif
#   if defined (BRS_PORT_GROUP_B2)
  FCLA0CTL(5) |= (1 << 1); /*INTP4, falling edge detection*/
  /* INTP4 / Port 1.1 / falling edge */
  BrsHwInitPortInput(BRSHW_PORT_CAN3_WAKEUP);
#   endif
#   if defined (BRS_PORT_GROUP_D)
  EXINTCTL |= (1 << 7);  /* configure External Interrupt control register for external wakeup */
  /* IRQ3 / Port 2_3 */
  BrsHwInitPortInput(BRSHW_PORT_CAN3_WAKEUP);
#   endif
#  endif /*BRSHW_ENABLE_CAN_WAKEUP_FILTER*/
# endif /*BRS_ENABLE_CAN_CHANNEL_3*/

# if defined (BRS_ENABLE_CAN_CHANNEL_4)
  BrsHwInitPortOutput(BRSHW_PORT_CAN4_TX);
  BrsHwInitPortInput(BRSHW_PORT_CAN4_RX);
#  if defined(_BRSHW_PORT_CAN4_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN4_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN4_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#  endif
#  if defined (_BRSHW_PORT_CAN4_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN4_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN4_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#  endif

#  if defined (BRSHW_ENABLE_CAN_WAKEUP_FILTER)
#   if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_A1)
  FCLA0CTL(4) = 0x02; /* configure filter control register for external wakeup / INTP4 / falling edge */
#   endif
#  endif /*BRSHW_ENABLE_CAN_WAKEUP_FILTER*/
# endif /*BRS_ENABLE_CAN_CHANNEL_4*/

# if defined (BRS_ENABLE_CAN_CHANNEL_5)
  BrsHwInitPortOutput(BRSHW_PORT_CAN5_TX);
  BrsHwInitPortInput(BRSHW_PORT_CAN5_RX);
#  if defined(_BRSHW_PORT_CAN5_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN5_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN5_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#  endif
#  if defined (_BRSHW_PORT_CAN5_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN5_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN5_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#  endif

#  if defined (BRSHW_ENABLE_CAN_WAKEUP_FILTER)
#   if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_A1)
  FCLA0CTL(5) = 0x02; /* configure filter control register for external wakeup / INTP5 / falling edge */
#   endif
#  endif /*BRSHW_ENABLE_CAN_WAKEUP_FILTER*/
# endif /*BRS_ENABLE_CAN_CHANNEL_5*/
#endif /*BRS_ENABLE_CAN_SUPPORT*/

/*******************************************************************************
  LIN driver
********************************************************************************/
#if defined (BRS_ENABLE_LIN_SUPPORT)
# if defined (BRS_PORT_GROUP_A) || defined (BRS_PORT_GROUP_B1) || defined (BRS_PORT_GROUP_D)
/* All derivatives, which have RLIN2 and RLIN3, or only RLIN2 */
#  if defined (BRS_ENABLE_LIN_CHANNEL_0)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_0_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_0_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_0_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_0_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_1)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_1_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_1_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_1_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_1_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_2)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_2_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_2_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_2_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_2_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_3)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_3_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_3_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_3_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_3_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_4)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_4_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_4_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_4_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_4_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_5)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_5_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_5_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_5_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_5_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_6)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_6_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_6_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_6_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_6_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_7)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_7_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_7_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_7_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_7_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_8)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_8_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_8_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_8_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_8_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_9)
   BrsHwInitPortOutput(BRSHW_PORT_LIN2_9_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN2_9_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_9_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN2_9_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_10)
  BrsHwInitPortOutput(BRSHW_PORT_LIN3_0_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN3_0_RX);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_0_TX, BRSHW_PORT_CONF_LIN);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_0_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_11)
  BrsHwInitPortOutput(BRSHW_PORT_LIN3_1_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN3_1_RX);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_1_TX, BRSHW_PORT_CONF_LIN);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_1_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_12)
  BrsHwInitPortOutput(BRSHW_PORT_LIN3_2_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN3_2_RX);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_2_TX, BRSHW_PORT_CONF_LIN);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_2_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_13)
  BrsHwInitPortOutput(BRSHW_PORT_LIN3_3_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN3_3_RX);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_3_TX, BRSHW_PORT_CONF_LIN);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_3_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_14)
  BrsHwInitPortOutput(BRSHW_PORT_LIN3_4_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN3_4_RX);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_4_TX, BRSHW_PORT_CONF_LIN);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_4_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_15)
  BrsHwInitPortOutput(BRSHW_PORT_LIN3_5_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN3_5_RX);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_5_TX, BRSHW_PORT_CONF_LIN);
  BrsHwInitPortConfig(BRSHW_PORT_LIN3_5_RX, BRSHW_PORT_CONF_LIN);
#  endif

# else
  /* All derivatives, which have only RLIN3 */
#  if defined (BRS_ENABLE_LIN_CHANNEL_0)
   BrsHwInitPortOutput(BRSHW_PORT_LIN3_0_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN3_0_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_0_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_0_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_1)
   BrsHwInitPortOutput(BRSHW_PORT_LIN3_1_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN3_1_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_1_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_1_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_2)
   BrsHwInitPortOutput(BRSHW_PORT_LIN3_2_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN3_2_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_2_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_2_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_3)
   BrsHwInitPortOutput(BRSHW_PORT_LIN3_3_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN3_3_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_3_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_3_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_4)
   BrsHwInitPortOutput(BRSHW_PORT_LIN3_4_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN3_4_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_4_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_4_RX, BRSHW_PORT_CONF_LIN);
#  endif

#  if defined (BRS_ENABLE_LIN_CHANNEL_5)
   BrsHwInitPortOutput(BRSHW_PORT_LIN3_5_TX);
   BrsHwInitPortInput(BRSHW_PORT_LIN3_5_RX);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_5_TX, BRSHW_PORT_CONF_LIN);
   BrsHwInitPortConfig(BRSHW_PORT_LIN3_5_RX, BRSHW_PORT_CONF_LIN);
#  endif
# endif /*BRS_PORT_GROUP_x*/
#endif /*BRS_ENABLE_LIN_SUPPORT*/

/*******************************************************************************
  FLEXRAY driver
********************************************************************************/
#if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
# if defined (BRS_ENABLE_FLEXRAY_CHANNEL_0_A)
  BrsHwInitPortOutput(BRSHW_PORT_FLX0_A_TX);
  BrsHwInitPortOutput(BRSHW_PORT_FLX0_A_EN);
  BrsHwInitPortInput(BRSHW_PORT_FLX0_A_RX);
# endif
# if defined (BRS_ENABLE_FLEXRAY_CHANNEL_0_B)
  BrsHwInitPortOutput(BRSHW_PORT_FLX0_B_TX);
  BrsHwInitPortOutput(BRSHW_PORT_FLX0_B_EN);
  BrsHwInitPortInput(BRSHW_PORT_FLX0_B_RX);
# endif
#endif /*BRS_ENABLE_FLEXRAY_SUPPORT*/

/*******************************************************************************
  ETHERNET driver
********************************************************************************/
#if defined (BRS_ENABLE_ETHERNET_SUPPORT)
  /* -- Transmitter signals -- */
  BrsHwInitPortInput(BRSHW_PORT_ETH0TXCLK);
  BrsHwInitPortOutput(BRSHW_PORT_ETH0TXD0);
  BrsHwInitPortOutput(BRSHW_PORT_ETH0TXD1);
# if defined (_BRSHW_PORT_ETH0_TXD2)
  /* Transmit signal 2 is obsolete within RMII */
  BrsHwInitPortOutput(BRSHW_PORT_ETH0TXD2);
# endif
# if defined (_BRSHW_PORT_ETH0_TXD3)
  /* Transmit signal 3 is obsolete within RMII */
  BrsHwInitPortOutput(BRSHW_PORT_ETH0TXD3);
# endif
  BrsHwInitPortOutput(BRSHW_PORT_ETH0TXEN);
# if defined (_BRSHW_PORT_ETH0_TXERR)
  /* Transmit Error signal is only optional within MII and obsolete within RMII */
  BrsHwInitPortOutput(BRSHW_PORT_ETH0TXERR);
# endif

  BrsHwInitPortConfig(BRSHW_PORT_ETH0TXD0, BRSHW_PORT_CONF_ETH0TXD);
  BrsHwInitPortConfig(BRSHW_PORT_ETH0TXD1, BRSHW_PORT_CONF_ETH0TXD);
# if defined (_BRSHW_PORT_ETH0_TXD2)
  BrsHwInitPortConfig(BRSHW_PORT_ETH0TXD2, BRSHW_PORT_CONF_ETH0TXD);
# endif
# if defined (_BRSHW_PORT_ETH0_TXD3)
  BrsHwInitPortConfig(BRSHW_PORT_ETH0TXD3, BRSHW_PORT_CONF_ETH0TXD);
# endif
  BrsHwInitPortConfig(BRSHW_PORT_ETH0TXEN, BRSHW_PORT_CONF_ETH0TXEN);
# if defined (_BRSHW_PORT_ETH0_TXERR)
  BrsHwInitPortConfig(BRSHW_PORT_ETH0TXERR, BRSHW_PORT_CONF_ETH0TXERR);
#endif

  /* -- Receiver signals -- */
# if defined (_BRSHW_PORT_ETH0_RXCLK)
  /* Receive clock signal is obsolete within RMII */
  BrsHwInitPortInput(BRSHW_PORT_ETH0RXCLK);
# endif
  BrsHwInitPortInput(BRSHW_PORT_ETH0RXD0);
  BrsHwInitPortInput(BRSHW_PORT_ETH0RXD1);
# if defined (_BRSHW_PORT_ETH0_RXD2)
  /* Receive signal 2 is obsolete within RMII */
  BrsHwInitPortInput(BRSHW_PORT_ETH0RXD2);
# endif
# if defined (_BRSHW_PORT_ETH0_RXD3)
  /* Receive signal 3 is obsolete within RMII */
  BrsHwInitPortInput(BRSHW_PORT_ETH0RXD3);
# endif
  BrsHwInitPortInput(BRSHW_PORT_ETH0RXDV);
  BrsHwInitPortInput(BRSHW_PORT_ETH0RXERR);
  BrsHwInitPortInput(BRSHW_PORT_ETH0CRS);
  BrsHwInitPortInput(BRSHW_PORT_ETH0COL);

  /* -- Management signals -- */
  BrsHwInitPortInputOutput(BRSHW_PORT_ETH0MDIO);
# if defined (_BRSHW_PORT_ETH0_MDC)
  /* Management data clock not always needed */
  BrsHwInitPortOutput(BRSHW_PORT_ETH0MDC);
#endif
  BrsHwInitPortConfig(BRSHW_PORT_ETH0MDIO, BRSHW_PORT_CONF_ETH0MDIO);
#if defined (_BRSHW_PORT_ETH0_MDC)
  BrsHwInitPortConfig(BRSHW_PORT_ETH0MDC, BRSHW_PORT_CONF_ETH0MDC);
#endif

#  if defined (BRSHW_PORT_ETH0_RESET)
  BrsHwInitPortOutput(BRSHW_PORT_ETH0RESET);
  /* wait for configuration of pin has been performed */
  BRSHWNOP10();
  /* Write a one to disable reset */
  BrsHwPort_SetLevel(BRSHW_PORT_ETH0RESET, BRSHW_PORT_LOGIC_HIGH);
#  endif

# if defined (_BRSHW_PORT_ETH0_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_ETH0_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_ETH0_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
# endif
#endif /*BRS_ENABLE_ETHERNET_SUPPORT*/
}
#endif /*BRS_ENABLE_PORT*/

/*****************************************************************************/
/**
 * @brief      Disable the global system interrupt.
 * @pre        Must be the first function call in main@BrsMain
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 */
/*****************************************************************************/
void BrsHwDisableInterruptAtPowerOn(void)
{
  ___asm(di);
}

/*****************************************************************************/
/**
 * @brief      restart ECU (issue a software reset or jump to startup code)
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. ECU state handling
 */
/*****************************************************************************/
void BrsHwSoftwareResetECU(void)
{
  DisableAllInterrupts();

#if defined (BRS_RESET_GROUP_A)
  PROT_WRITE0(SWRESA,0x1);

#elif defined (BRS_RESET_GROUP_B)
  PROT_WRITE1(SWRESA,0x1);

#elif defined (BRS_RESET_GROUP_C)
  SWSRESA0 = 0x1;

#elif defined (BRS_RESET_GROUP_E)
  SWSRESA = 0x1;
#endif

  while (1)
  {
    /* Wait until reset/watchdog reset occurs */
  }
}

/*****************************************************************************/
/**
 * @brief      Get reset reason
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Reset reason 
 * @context    Function is called from BrsMainStartup to determine if reset
 *             was triggered through software call (BrsHwSoftwareResetECU()).
 */
/*****************************************************************************/
brsHw_ResetReasonType BrsHwGetResetReason(void)
{
  if ((RESF) & (BRSHW_SWRESET_TRIGGERT_MASK))
  {
    return BRSHW_RESET_SW;
  }
  else
  {
    return BRSHW_RESET_OTHER;
  }
}

/*****************************************************************************/
/**
 * @brief      This API is used for the BRS time measurement support to get a
 *             default time value for all measurements with this platform to
 *             be able to compare time measurements on different dates based
 *             on this time result.
 * @pre        Should be called with interrupts global disabled
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. component testsuits for calibration
 */
/*****************************************************************************/
void BrsHwTime100NOP(void)
{
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
}

#if defined (BRS_ENABLE_SAFECTXSUPPORT)
/*****************************************************************************/
/**
 * @brief      This API is used to enable hardware access in untrusted mode
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function must be called after all depending peripheral modules
 *             are supplied by proper clocks AND before the OS is started.
 */
/*****************************************************************************/
void BrsHw_EnableHwAccess(void)
{
  /* Nothing to do for Rh850 yet */
}
#endif /*BRS_ENABLE_SAFECTXSUPPORT*/

#if defined (BRS_COMP_GHS)
# if defined (BRS_DERIVATIVE_GROUP_U2A)
asm uint32 BrsHw_GetCoreAsm(void)
{
  stsr PEID, r10  -- get current PEID value
}

# else
asm uint32 BrsHw_GetCoreAsm(void)
{
  stsr HTCFG0, r10  -- get current HTCFG0 value
  shr  17, r10      -- right shift
}
# endif

#else
uint32 BrsHw_GetCoreAsm (void)
{
  __as2(stsr 0, r10, 2);
  __as1(shr  17, r10);
}
#endif /*BRS_COMP_x*/

/*****************************************************************************/
/**
 * @brief      This API is used to read the core ID of the actual running core
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Core ID of the actual running core
 * @context    Function is e.g. called from main@BrsMain, to only call HW-init
 *             code once, on the boot core.
 *             In MultiCore setups, additional BRSHW_INIT_CORE_ID must be
 *             declared inside BrsHw.h, to configure the proper core ID value
 *             of that boot core.
 */
/*****************************************************************************/
uint32 BrsHw_GetCore(void)
{
  uint32 coreId;
  coreId=BrsHw_GetCoreAsm();
  return coreId;
}

#if defined (BRS_ENABLE_FBL_SUPPORT)
/*****************************************************************************/
/**
 * @brief      This API is used to enable self-programming
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from XXX
 */
/*****************************************************************************/
void BrsHwSetVfp(void)
{
  do
  {
    /*selected pull up for FLMD0 pin, self-programming is enabled*/
    PROT_WRITE_VFP(FLMDCNT, 0x01);
  } while((FLMDPS & 0x01) == 0x01);
}

/*****************************************************************************/
/**
 * @brief      This API is used to disable self-programming
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from XXX
 */
/*****************************************************************************/
void BrsHwResetVfp(void)
{
  do
  {
    /*selected pull down for FLMD0 pin, self-programming is disabled*/
    PROT_WRITE_VFP(FLMDCNT, 0x00);
  } while((FLMDPS & 0x01) == 0x01);
}
#endif /*BRS_ENABLE_FBL_SUPPORT*/

/*****************************************************************************/
/**
 * @brief      This API is used to enable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be enabled.
 * @param[in]  Priority level to be set.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 */
/*****************************************************************************/
void BrsHw_EnableInterrupt(uint32 Source, uint8 Priority)
{
  /* Clear pending interrupt */
  BRSHW_ICRXHIGH(Source) = 0x00;
  ___asm(syncm);

  /* Enable ISR with priority and table mode */
  BRSHW_ICRXLOW(Source) = (uint8)(ICRX_TBX_SET | Priority );
  ___asm(syncm);
}

/*****************************************************************************/
/**
 * @brief      This API is used to disable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be disabled.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 */
/*****************************************************************************/
void BrsHw_DisableInterrupt(uint32 Source)
{
  /* Set interrupt request mask bit. */
  BRSHW_ICRXLOW(Source) |= (uint8)(ICRX_MKX_SET);
  ___asm(syncm);
}

/*****************************************************************************/
/**
 * @brief      This API is used to trigger the given software interrupt source.
 * @pre        
 * @param[in]  Source to be triggered.
 *             Some derivatives only support few software triggerable sources,
 *             check for their validity.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 */
/*****************************************************************************/
void BrsHw_TriggerSoftwareInterrupt(uint32 Source)
{
  BRSHW_ICRXHIGH(Source) = 0x10;
  ___asm(syncm);
}

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
/*****************************************************************************/
/**
 * @brief      This API is used as sync barrier. It is used to unlock cores
 *             that are locked in the Startup code. The implementation is only
 *             needed on platforms, where all cores are started automatically
 *             after a power-on reset. All additional cores are looped, until
 *             the boot core reaches this function.
 * @pre        
 * @param[in]  uint32 coreId
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainStartup on the boot core.
 */
/*****************************************************************************/
void BrsHw_UnlockCores(uint32 coreId)
{
  BRSHW_G0MEV(0) = BRSHW_CORE_START_PATTERN;
}
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/
