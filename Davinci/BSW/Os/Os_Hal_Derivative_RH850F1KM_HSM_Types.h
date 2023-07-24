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
 * \addtogroup  Os_Hal_Derivative_Types
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

#ifndef OS_HAL_DERIVATIVE_RH850F1KM_HSM_TYPES_H
# define OS_HAL_DERIVATIVE_RH850F1KM_HSM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Stack
 *********************************************************************************************************************/
 
/*! Defines the stack gap size. */
# define OS_HAL_STACK_GAP_SIZE                        (0uL)


/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/

/*! \brief    Highest possible compare register value for the Free Running Timer (FRT).
 *  \details  The define is used for calculation purpose in case the hardware timer bit width differs from 32bit.
 */
# define OS_HAL_TIMERFRTTICKTYPE_MAX                  (0xFFFFFFFFuL)

/*! Bit width of the timer hardware register. */
# define OS_HAL_TIMERFRTBITWITDH                      (32uL)

/*! Extended high resolution timer's counter data type. */
typedef uint32 Os_Hal_TimerFrtTickType;

#endif /* OS_HAL_DERIVATIVE_RH850F1KM_HSM_TYPES_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_RH850F1KM_HSM_Types.h
 *********************************************************************************************************************/

