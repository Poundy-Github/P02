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

#ifndef OS_HAL_DERIVATIVE_RH850P1LCINT_H
# define OS_HAL_DERIVATIVE_RH850P1LCINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  RH850P1LC
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
# define OS_HAL_INTC1_BASE   (0xFFFEEA00uL)
/*! INTC2 register base address */
# define OS_HAL_INTC2_BASE   (0xFFFFB000uL)
/*! EIBD1 register base address */
# define OS_HAL_EIBD1_BASE   (0x00000000uL)
/*! EIBD2 register base address */
# define OS_HAL_EIBD2_BASE   (0x00000000uL)
/*! IPIR register base address */
# define OS_HAL_IPIR_BASE   (0x00000000uL)

/* SELB_INTC1 register base address */
# define OS_HAL_SELB_INTC1_BASE        (0x00000000uL)
/* Defines whether SELB_INTC1 register is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_SELB_INTC1_AVAILABLE   (STD_OFF)

/* SELB_INTC2 register base address */
# define OS_HAL_SELB_INTC2_BASE        (0x00000000uL)
/* Defines whether SELB_INTC2 register is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_SELB_INTC2_AVAILABLE   (STD_OFF)

/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Support of STM timer units. */
# define OS_HAL_CFG_TIMER_STM    (STD_ON)
/*! Support of OSTM timer units. */
# define OS_HAL_CFG_TIMER_OSTM   (STD_OFF)
/*! Support of TAUJ timer units. */
# define OS_HAL_CFG_TIMER_TAUJ   (STD_OFF)

/*! STM0 timer unit base address */
# define OS_HAL_TIMER_STM0_BASE   (0xFFDD8000uL)

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
# define OS_HAL_MPU_REGION_COUNT_CORE0    (16uL)
   
/* Defines initial value to be set to memory region ID */
# define OS_HAL_MEM_REGION_ID_INIT_VAL    (0x3FFuL)

/**********************************************************************************************************************
 *  Interrupt Priority Mask
 *********************************************************************************************************************/
/*! Mask to disable all EI interrupt levels. */
# define OS_HAL_PMR_MASK     (0x0000FFFFuL)

/*! Defines the value for register MPM which is used to enable the MPU. */
# define OS_HAL_MPU_ENABLE   (0x00000003uL)

/*! Defines the value for register MPAT0 which is used to setup access rights of MPU region 0 . */
# define OS_HAL_MPU_MPAT0    (0x000000DBuL)




#endif /* OS_HAL_DERIVATIVE_RH850P1LCINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_RH850P1LCInt.h
 *********************************************************************************************************************/
