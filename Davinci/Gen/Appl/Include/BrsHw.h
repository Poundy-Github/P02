
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
  \file  File:  BrsHw.h
      Project:  Vector Basic Runtime System
       Module:  BrsHw for platform Renesas RH850

  \brief Description:  This is the hardware specific header file for Vector Basic Runtime System (BRS).

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

#ifndef _BRSHW_H_
#define _BRSHW_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
/*
 * Description: The BrsCfg header is used to configure different types of
 *              tests and system setups. Therefore it must be included first
 *              in each BRS and test module.
 *              This file is part of the BRS.
 */
#include "vBrsCfg.h"

#if defined (BRS_ENABLE_PORT)
  #include "BrsHw_Ports.h"
#endif

/**********************************************************************************************************************
  MODULE VERSION
**********************************************************************************************************************/
/*
 * Description: This is the BrsHw main and bug fix version. The version numbers are BCD coded.
 *              E.g. a main version of 1.23 is coded with 0x0123, a bug fix version of 9 is coded 0x09.
 */

/* This is the BrsHw template main and bug fix version, the platform BrsHw is reviewed to */
#define BRSHW_SOURCECODE_TEMPLATE_VERSION        0x0100u
#define BRSHW_SOURCECODE_TEMPLATE_BUGFIX_VERSION 0x00u

/* This is the BrsHw main and bug fix version */
#define BRSHW_VERSION        0x0100u
#define BRSHW_BUGFIX_VERSION 0x00u

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/
/* The following parameters are necessary for this platform, to be generated by BRS-Cfg5-Generator into BrsCfg.h */
#if !defined (BRS_OSC_CLK)
  #error "BRS CHECK: The parameter BRS_OSC_CLK is missing! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_TIMEBASE_CLOCK)
  #error "BRS CHECK: The parameter BRS_TIMEBASE_CLOCK is missing! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_PERIPH_CLOCK)
  #error "BRS CHECK: The parameter BRS_PERIPH_CLOCK is missing! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_CPU_MAX_FREQUENCY)
  #error "BRS CHECK: The parameter BRS_CPU_MAX_FREQUENCY is missing! Please check your BRS Cfg5 configuration."
#endif

#if !(defined (BRS_CPU_CORE_G3M) || defined (BRS_CPU_CORE_G3MH) || defined (BRS_CPU_CORE_G3KH) || defined (BRS_CPU_CORE_G3K) || defined (BRS_CPU_CORE_G4MH))
  #error "BRS CHECK: The parameter BRS_CPU_CORE_x is missing or not supported! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_CPU_CORE_AMOUNT)
  #error "BRS CHECK: The parameter BRS_CPU_CORE_AMOUNT is missing! Please check your BRS Cfg5 configuration."
#endif

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/*
 * Description: Macro for access to IO addresses
 */
#define BRSHW_IOS(type, address) (*((volatile type *)(address)))

/* STATIC */
#define BRSHW_DERIVATIVE_CORE0_ID  0x00
#define BRSHW_DERIVATIVE_CORE1_ID  0x01
#define BRSHW_DERIVATIVE_CORE2_ID  0x02
#define BRSHW_DERIVATIVE_CORE3_ID  0x03

/* DERIVATIVE DEPENDENT STATIC */
#define BRSHW_INIT_CORE_ID         BRSHW_DERIVATIVE_CORE0_ID
#define BRSHW_G0MEV_BASE           0xFFFEEC00
#define BRSHW_CORE_START_PATTERN   0x0FEE0BEE
#define BRSHW_CORE_SYNC_REG        BRSHW_G0MEV_BASE

/**********************************************************************************************************************
  Compiler abstraction
**********************************************************************************************************************/
#if defined (BRS_COMP_GHS)
  #define ___asm(c)               __asm_(c)
  #define __asm_(c)               asm(" " #c);
  #define __as1(c, d)             __as1_(c, d)
  #define __as1_(c, d)            asm(" " #c " , " #d);
  #define __as2(c, d, e)          __as2_(c, d, e)
  #define __as2_(c, d, e)         asm(" " #c " , " #d " , " #e);
  #define BRS_ISR_BASE_ENTRY(x)   ___asm(jr x)
  #define BRS_ISR_ALIGNMENT       ___asm(nop)___asm(nop)___asm(nop)___asm(nop)___asm(nop)___asm(nop)
  #define BRS_ALIGN16()           asm(" .align 16");
  #define BRS_ISR_ENTRY(x)        ___asm(.word x)
  #define BRS_ISR_KEYWORD         __interrupt
  #define BRS_ISR_DEFINE(x)       _##x

  #define BRS_SECTION_CODE(c)     asm(" .section ." #c "," "ax" );
  #define BRS_GLOBAL(c)           asm(" .globl " #c);
  #define BRS_LABEL(c)            asm(#c ":");

  /* Unconditional branch to c */
  #define BRS_BRANCH(c)           ___asm(jr32 c) 

  /* Branch to e if c and d are equal */
  #define BRS_BRANCH_EQUAL(c,d,e) __as1(cmp   c, d) \
                                  ___asm(be   e)

  /* Branch to e if c and d are NOT equal */
  #define BRS_BRANCH_NOT_EQUAL(c,d,e)  __as1(cmp   c, d) \
                                       ___asm(bne   e)

/* Reads core id value (PEID) from HTCFG0 to register c. */
/* Register d is only a working register and can be reused afterwards */
# if defined (BRS_CPU_CORE_G4MH)
  #define BRS_READ_COREID(c)  __as2(stsr  0, c, 2)
# else
  #define BRS_READ_COREID(c)  __as2(stsr  0, c, 2) \
                              __as1(shr   17, c)
# endif

/* Reads architecture identifier value from PID to register c. */
/* Register d is only a working register and can be reused afterwards */
  #define BRS_READ_CORETYPE(c,d)  __as2(stsr  6, c, 1) \
                                  __as1(shr   24, c)   \
                                  __as1(mov   0xff, d) \
                                  __as1(and   d, c)

#else
  #error "Compiler not yet supported"
#endif

/**********************************************************************************************************************
  BrsHW configuration
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global variables
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global const variables
**********************************************************************************************************************/
/*
 * Description: These constants are used to propagate the Versions over module boundaries.
 *              The version numbers are BCD coded. E.g. a sub version of 23 is coded with 0x23, 
 *              a bug fix version of 9 is coded 0x09.
 */
extern uint8 const kBrsHwMainVersion;
extern uint8 const kBrsHwSubVersion;
extern uint8 const kBrsHwBugfixVersion;

/**********************************************************************************************************************
  Global function prototypes
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
#define BRSHW_PREINIT_AVAILABLE
void BrsHwPreInitPowerOn(void);

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
void BrsHwWatchdogInitPowerOn(void);
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
void BrsHwPllInitPowerOn(void);
#endif /*BRS_ENABLE_PLLCLOCKS*/

#if defined (BRS_ENABLE_PORT)
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
void BrsHwPort_SetLevel(brsHw_Port_PortType p, uint8 Level);

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
uint8 BrsHwPort_GetLevel(brsHw_Port_PortType p);
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif

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
void BrsHwPortInitPowerOn(void);
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
void BrsHwDisableInterruptAtPowerOn(void);

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
void BrsHwSoftwareResetECU(void);

typedef enum
{
  BRSHW_RESET_SW,
  BRSHW_RESET_OTHER
}brsHw_ResetReasonType;

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
brsHw_ResetReasonType BrsHwGetResetReason(void);

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
void BrsHwTime100NOP(void);

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
void BrsHw_EnableHwAccess(void);
#endif /*BRS_ENABLE_SAFECTXSUPPORT*/

#if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE
/*****************************************************************************/
/**
 * @brief      This function has to be used to enable self-programming. 
 *             This function is called from XXX
 *             (if BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE is set in BrsHw.h).
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from init@BrsMain
 */
/*****************************************************************************/
void BrsHwSetVfp(void);

/*****************************************************************************/
/**
 * @brief      This function has to be used to disable self-programming. 
 *             This function is called from XXX
 *             (if BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE is set in BrsHw.h).
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from init@BrsMain
 */
/*****************************************************************************/
void BrsHwResetVfp(void);
#endif /*BRS_ENABLE_FBL_SUPPORT*/

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
uint32 BrsHw_GetCore(void);

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
void BrsHw_EnableInterrupt(uint32, uint8);

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
void BrsHw_DisableInterrupt(uint32);

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
void BrsHw_TriggerSoftwareInterrupt(uint32);

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
void BrsHw_UnlockCores(uint32);
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

#endif /*_BRSHW_H_*/