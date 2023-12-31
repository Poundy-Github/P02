/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup  Os_Hal_Derivative
 * \{
 *
 * \file
 * \brief  This file contains derivative specific information.
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 *********************************************************************************************************************/

#ifndef OS_HAL_DERIVATIVE_RH850F1LINT_H
# define OS_HAL_DERIVATIVE_RH850F1LINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  RH850F1L
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Core Type
 *********************************************************************************************************************/
/* Defines whether G3X core is supported (STD_ON) or not (STD_OFF) */
# define OS_HAL_CORE_G3X    STD_ON
/* Defines whether G4X core is supported (STD_ON) or not (STD_OFF) */
# define OS_HAL_CORE_G4X    STD_OFF

/**********************************************************************************************************************
 *  Interrupt Controller
 *********************************************************************************************************************/
/* Defines whether G3X interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_G3X    STD_ON
/* Defines whether G4X interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_G4X    STD_OFF

/*! INTC1 register base address */
# define OS_HAL_INTC1_BASE   (0xFFFF9000uL)
/*! INTC2 register base address */
# define OS_HAL_INTC2_BASE   (0xFFFFA000uL)
/*! EIBD1 register base address */
# define OS_HAL_EIBD1_BASE   (0x00000000uL)
/*! EIBD2 register base address */
# define OS_HAL_EIBD2_BASE   (0x00000000uL)
/*! IPIR register base address */
# define OS_HAL_IPIR_BASE   (0x00000000uL)

/* SELB_INTC1 register base address */
# define OS_HAL_SELB_INTC1_BASE        (0xFFBC0300uL)
/* Defines whether SELB_INTC1 register is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_SELB_INTC1_AVAILABLE   (STD_ON)

/* SELB_INTC2 register base address */
# define OS_HAL_SELB_INTC2_BASE        (0xFFBC0304uL)
/* Defines whether SELB_INTC2 register is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_SELB_INTC2_AVAILABLE   (STD_ON)

/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Support of STM timer units. */
# define OS_HAL_CFG_TIMER_STM    (STD_OFF)
/*! Support of OSTM timer units. */
# define OS_HAL_CFG_TIMER_OSTM   (STD_ON)
/*! Support of TAUJ timer units. */
# define OS_HAL_CFG_TIMER_TAUJ   (STD_ON)

/*! OSTM0 timer unit base address */
# define OS_HAL_TIMER_OSTM0_BASE   (0xFFEC0000uL)
/*! TAUJ0 timer unit base address */
# define OS_HAL_TIMER_TAUJ0_BASE   (0xFFE50000uL)
/*! TAUJ1 timer unit base address */
# define OS_HAL_TIMER_TAUJ1_BASE   (0xFFE51000uL)

/*! Bit mask to enable OSTM interrupt. */
# define OS_HAL_TIMER_OSTM_INT_ENABLE_MASK    (0x00u)

/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/* Defines whether G3X interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MPU_G3X    STD_ON
/* Defines whether G4X interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MPU_G4X    STD_OFF 

/*! Number of supported MPU regions (Core0). */
# define OS_HAL_MPU_REGION_COUNT_CORE0    (4uL)
   
/* Defines initial value to be set to memory region ID */
# define OS_HAL_MEM_REGION_ID_INIT_VAL    (0x3FFuL)

/**********************************************************************************************************************
 *  Interrupt Priority Mask
 *********************************************************************************************************************/
/*! Mask to disable all EI interrupt levels. */
# define OS_HAL_PMR_MASK     (0x000000FFuL)

/*! Defines the value for register MPM which is used to enable the MPU. */
# define OS_HAL_MPU_ENABLE   (0x00000001uL)

/*! Defines the value for register MPAT0 which is used to setup access rights of MPU region 0 . */
# define OS_HAL_MPU_MPAT0    (0x000000C3uL)




#endif /* OS_HAL_DERIVATIVE_RH850F1LINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_RH850F1LInt.h
 *********************************************************************************************************************/
