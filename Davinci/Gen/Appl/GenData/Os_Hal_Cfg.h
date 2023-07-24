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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Cfg.h
 *   Generation Time: 2021-04-23 13:22:54
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CFG_H
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2u)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (30u)

/* ISR core and level definitions */
# define OS_ISR_ADC0_SG1_CAT2_ISR_CORE      (0)
# define OS_ISR_ADC0_SG1_CAT2_ISR_LEVEL     (6)
# define OS_ISR_ADC1_SG1_CAT2_ISR_CORE      (0)
# define OS_ISR_ADC1_SG1_CAT2_ISR_LEVEL     (6)
# define OS_ISR_CORTST_G3KH_EITRAP1_CAT1_ISR_CORE      (0)
# define OS_ISR_CORTST_G3KH_EITRAP1_CAT1_ISR_LEVEL     (0)
# define OS_ISR_CORTST_G3KH_FETRAP_CAT1_ISR_CORE      (0)
# define OS_ISR_CORTST_G3KH_FETRAP_CAT1_ISR_LEVEL     (0)
# define OS_ISR_CORTST_G3KH_MAE_CAT1_ISR_CORE      (0)
# define OS_ISR_CORTST_G3KH_MAE_CAT1_ISR_LEVEL     (0)
# define OS_ISR_CANISRGLOBALSTATUS_CORE      (0)
# define OS_ISR_CANISRGLOBALSTATUS_LEVEL     (7)
# define OS_ISR_CANISRSTATUS_0_CORE      (0)
# define OS_ISR_CANISRSTATUS_0_LEVEL     (1)
# define OS_ISR_CANISRSTATUS_1_CORE      (0)
# define OS_ISR_CANISRSTATUS_1_LEVEL     (1)
# define OS_ISR_CANISRSTATUS_3_CORE      (0)
# define OS_ISR_CANISRSTATUS_3_LEVEL     (1)
# define OS_ISR_CANISRWAKEUP_0_CORE      (0)
# define OS_ISR_CANISRWAKEUP_0_LEVEL     (1)
# define OS_ISR_CANISRWAKEUP_1_CORE      (0)
# define OS_ISR_CANISRWAKEUP_1_LEVEL     (1)
# define OS_ISR_CANISRWAKEUP_3_CORE      (0)
# define OS_ISR_CANISRWAKEUP_3_LEVEL     (1)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE      (0)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_LEVEL     (12)
# define OS_ISR_ECCTST_G3KH_FEINT_CAT1_ISR_CORE      (0)
# define OS_ISR_ECCTST_G3KH_FEINT_CAT1_ISR_LEVEL     (0)
# define OS_ISR_ECCTST_G3KH_SYSERR_CAT1_ISR_CORE      (0)
# define OS_ISR_ECCTST_G3KH_SYSERR_CAT1_ISR_LEVEL     (0)
# define OS_ISR_EXT_INTP_CH00_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH00_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH01_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH01_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH03_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH03_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH04_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH04_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH05_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH05_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH09_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH09_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH11_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH11_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH12_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH12_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH13_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH13_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH18_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH18_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH19_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH19_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH20_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH20_CAT2_ISR_LEVEL     (6)
# define OS_ISR_EXT_INTP_CH21_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH21_CAT2_ISR_LEVEL     (6)
# define OS_ISR_INTFICUIF0DFRQPE_CORE      (0)
# define OS_ISR_INTFICUIF0DFRQPE_LEVEL     (15)
# define OS_ISR_INTRIIC0EE_INTERRUPT_CORE      (0)
# define OS_ISR_INTRIIC0EE_INTERRUPT_LEVEL     (6)
# define OS_ISR_INTRIIC0RI_INTERRUPT_CORE      (0)
# define OS_ISR_INTRIIC0RI_INTERRUPT_LEVEL     (6)
# define OS_ISR_INTRIIC0TEI_INTERRUPT_CORE      (0)
# define OS_ISR_INTRIIC0TEI_INTERRUPT_LEVEL     (6)
# define OS_ISR_INTRIIC0TI_INTERRUPT_CORE      (0)
# define OS_ISR_INTRIIC0TI_INTERRUPT_LEVEL     (6)
# define OS_ISR_INTRIIC1EE_INTERRUPT_CORE      (0)
# define OS_ISR_INTRIIC1EE_INTERRUPT_LEVEL     (6)
# define OS_ISR_INTRIIC1RI_INTERRUPT_CORE      (0)
# define OS_ISR_INTRIIC1RI_INTERRUPT_LEVEL     (6)
# define OS_ISR_INTRIIC1TEI_INTERRUPT_CORE      (0)
# define OS_ISR_INTRIIC1TEI_INTERRUPT_LEVEL     (6)
# define OS_ISR_INTRIIC1TI_INTERRUPT_CORE      (0)
# define OS_ISR_INTRIIC1TI_INTERRUPT_LEVEL     (6)
# define OS_ISR_LIN_RLIN_31_INTRLIN31_CORE      (0)
# define OS_ISR_LIN_RLIN_31_INTRLIN31_LEVEL     (10)
# define OS_ISR_LIN_RLIN_32_INTRLIN32_CORE      (0)
# define OS_ISR_LIN_RLIN_32_INTRLIN32_LEVEL     (10)
# define OS_ISR_SPI_CSIH3_TIR_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIH3_TIR_CAT2_ISR_LEVEL     (6)
# define OS_ISR_SYSTEM1MSTICK_CORE      (0)
# define OS_ISR_SYSTEM1MSTICK_LEVEL     (0)
# define OS_ISR_TAUD0_CH13_CAT2_ISR_CORE      (0)
# define OS_ISR_TAUD0_CH13_CAT2_ISR_LEVEL     (6)
# define OS_ISR_TAUD0_CH15_CAT2_ISR_CORE      (0)
# define OS_ISR_TAUD0_CH15_CAT2_ISR_LEVEL     (6)
# define OS_ISR_UART_INTERR4_CORE      (0)
# define OS_ISR_UART_INTERR4_LEVEL     (6)
# define OS_ISR_UART_INTERR5_CORE      (0)
# define OS_ISR_UART_INTERR5_LEVEL     (6)
# define OS_ISR_UART_INTRX4_CORE      (0)
# define OS_ISR_UART_INTRX4_LEVEL     (6)
# define OS_ISR_UART_INTRX5_CORE      (0)
# define OS_ISR_UART_INTRX5_LEVEL     (6)
# define OS_ISR_UART_INTTX4_CORE      (0)
# define OS_ISR_UART_INTTX4_LEVEL     (6)
# define OS_ISR_UART_INTTX5_CORE      (0)
# define OS_ISR_UART_INTTX5_LEVEL     (6)
# define OS_ISR_VHSMRESPONSEISR_CORE      (0)
# define OS_ISR_VHSMRESPONSEISR_LEVEL     (8)

/* Hardware counter timing macros */

/* Counter timing macros and constants: SystemTimer */
# define OSMAXALLOWEDVALUE_SystemTimer     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer            (1uL)
# define OSTICKSPERBASE_SystemTimer        (40000uL)
# define OSTICKDURATION_SystemTimer        (1000000uL)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_SystemTimer)
# define OSMINCYCLE            (OSMINCYCLE_SystemTimer)
# define OSTICKSPERBASE        (OSTICKSPERBASE_SystemTimer)
# define OSTICKDURATION        (OSTICKDURATION_SystemTimer)

/*! Macro OS_NS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */




/* Bit mask to be set to SELB_INTC1 register for interrupt routing. */
# define OS_HAL_SELB_INTC1_MASK   (uint16)(0x00000000uL)

/* Bit mask to be set to SELB_INTC2 register for interrupt routing. */
# define OS_HAL_SELB_INTC2_MASK   (uint16)(0x00000000uL)

/* Defines wether G3X or G4X core is supported. */
# define OS_HAL_ASM_CORE_G3X



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
