/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_Compiler
 *  \{
 *
 *  \file       Os_Hal_Compiler_DiabASM.inc
 *  \brief      Additional Diab assembler compiler abstraction.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_COMPILERDIABASM_INC
# define OS_HAL_COMPILERDIABASM_INC

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/*! \brief    Assembler macro used for exception vector table definition.
 */
OS_HAL_ASM_EXC_DIAB: .macro  LABEL, EXCHANDLER
               .align 4
               LABEL:
               jr EXCHANDLER
               nop
               nop
               nop
               .endm


/*! \brief    Assembler macro used for cat2 isr prologue.
 */
OS_HAL_ASM_CAT2ISR_DIAB: .macro LABEL, FUNCTION
               .section ".OS_CODE"
               .align 4
               LABEL:
               pushsp r1-r2
               pushsp r4-r19
               mov    FUNCTION, r6
               jr     _Os_Irq_Isr
               .endm


/*! \brief    Assembler macro used for syscall table definition.
 */
OS_HAL_ASM_SYSCALL_WORD_DIAB: .macro
               .word 4
               jarl _Os_Hal_UnhandledSysCall, lp
               .endm


#endif /* OS_HAL_COMPILERDIABASM_INC */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_DiabASM.inc
 **********************************************************************************************************************/
