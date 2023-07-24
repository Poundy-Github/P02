/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vBRS
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: .\vBrsCfg.h
 *   Generation Time: 2021-01-20 17:06:28
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef _VBRSCFG_H_
#define _VBRSCFG_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#if !defined (BRS_INCLUDED_BY_ASM_FILE)
# include "Std_Types.h"
#endif

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define BASIC_RUNTIME_SYSTEM_TYPE_MSR4

#define BRS_GENERATED_HW_CONFIG_VERSION 341U

/*******************************************************************************
 Standard BRS configuration
*******************************************************************************/
/* Testsuite support is disabled (#define BRS_ENABLE_TESTSUITE_SUPPORT) */

/* TCC support is disabled (#define BRS_ENABLE_TCC_COMIF_SUPPORT / #define BRS_ENABLE_TCC_TCM_SUPPORT) */

/* LED support is disabled (#define BRS_ENABLE_SUPPORT_LEDS) */

/* Toggle custom pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN) */

/* Toggle watchdog pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) */


/*******************************************************************************
 Additional BRS support features
*******************************************************************************/
/* Switch to enable support of SafeContext OS */
#define BRS_ENABLE_SAFECTXSUPPORT

/* Switch to enable support of MultiCore OS */
/* MultiCore OS support is disabled (#define BRS_ENABLE_OS_MULTICORESUPPORT) */

/* Switches to enable support of FlashBootLoader and to define the FBL Type */
/* FlashBootLoader support is disabled (#define BRS_ENABLE_FBL_SUPPORT) */

/* Switch to enable support of Hardware Security Module (HSM) */
/* HSM support is disabled (#define BRS_ENABLE_HSM_SUPPORT) */

/*******************************************************************************
 BRS hardware configuration constants
*******************************************************************************/
/* Main Oscillator Clock (MHz) */
#define BRS_OSC_CLK 24

/* Timebase Clock (MHz) */
#define BRS_TIMEBASE_CLOCK 240

/* Peripheral Clock (MHz) */
#define BRS_PERIPH_CLOCK 40

/* CAN Clock (MHz) */
#define BRS_CAN_CLOCK 40

/* LIN Clock (MHz) */
#define BRS_LIN_CLOCK 40


/*******************************************************************************
 BRS communication interface configuration
*******************************************************************************/
#define BRS_ENABLE_CAN_SUPPORT
#define BRS_ENABLE_LIN_SUPPORT



/*******************************************************************************
 Tested Derivative: Renesas RH850 F1KM_S4 Family R7F7016514ABG-C
*******************************************************************************/
#define BRS_DERIVATIVE_RH850_1651

/*******************************************************************************
 CPU Core
*******************************************************************************/
#define BRS_CPU_CORE_G3KH

/*******************************************************************************
 CPU Max Frequency (MHz)
*******************************************************************************/
#define BRS_CPU_MAX_FREQUENCY 240

/*******************************************************************************
 CPU Core Amount (number of cores)
*******************************************************************************/
#define BRS_CPU_CORE_AMOUNT 1

/*******************************************************************************
 Derivative Group
*******************************************************************************/
#define BRS_DERIVATIVE_GROUP_F1KM_S4

/*******************************************************************************
 Clock Group
*******************************************************************************/
#define BRS_CLOCK_GROUP_A2

/*******************************************************************************
 Pll Group
*******************************************************************************/
#define BRS_PLL_GROUP_A4

/*******************************************************************************
 Port Group
*******************************************************************************/
#define BRS_PORT_GROUP_A

/*******************************************************************************
 Protection Group
*******************************************************************************/
#define BRS_PROTECTION_GROUP_A

/*******************************************************************************
 Reset Group
*******************************************************************************/
#define BRS_RESET_GROUP_A

/*******************************************************************************
 Init Patterns
*******************************************************************************/
#define BRS_INIT_PATTERN_BLOCKS (0x0UL)
#define BRS_INIT_PATTERN_HARDRESET_BLOCKS (0x0UL)
#define BRS_INIT_PATTERN_AREAS (0x0UL)
#define BRS_INIT_PATTERN_HARDRESET_AREAS (0x0UL)

/*******************************************************************************
 DrvCan Handling
*******************************************************************************/
#define BRS_DRVCAN_HEADER_FILENAME "Can.h"
#define BRS_DRVCAN_EXCLUSIVE_AREA_INFIX(a, b) void SchM_##a##_Can_CAN_##b(void)
#define BRS_DRVCAN_ControllerInterrupts_INFIX(a) Can_##a##ControllerInterrupts

#endif /*_VBRSCFG_H_*/

