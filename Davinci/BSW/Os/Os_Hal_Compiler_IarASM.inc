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
 *  \file       Os_Hal_Compiler_IarASM.inc
 *  \brief      Additional Iar assembler compiler abstraction.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_COMPILERIARASM_INC
# define OS_HAL_COMPILERIARASM_INC

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/*! \brief    Assembler macro used for exception vector table definition.
 */
OS_HAL_ASM_EXC_IAR MACRO  LABEL, EXCHANDLER
               ALIGN 4
               IMPORT EXCHANDLER
               LABEL:
               jr EXCHANDLER
               nop
               nop
               nop
               ENDM


/*! \brief    Assembler macro used for cat2 isr prologue.
 */
OS_HAL_ASM_CAT2ISR_IAR MACRO ISRNAME_LABEL, ISRNAME_FUNC
               PUBLIC ISRNAME_LABEL
               EXTERN ISRNAME_FUNC, _Os_Irq_Isr
               section .OS_CODE :CODE(2)
               code
               ALIGN 4
               ISRNAME_LABEL:
               pushsp r1-r2
               pushsp r4-r19
               mov    ISRNAME_FUNC, r6
               jr     _Os_Irq_Isr
               ENDM


/*! \brief    Assembler macro used for interrupt vector table definition.
 */
OS_HAL_ASM_WORD_IAR MACRO LABEL
                DC32 LABEL
                ENDM


/*! \brief    Assembler macro used for syscall table definition.
 */
OS_HAL_ASM_SYSCALL_WORD_IAR MACRO
                DC32 0x4
                jarl _Os_Hal_UnhandledSysCall, lp
                ENDM


/*! \brief    Assembler macro to use labels with mov directive correctly.
 */
OS_HAL_ASM_MOV_LABEL_IAR MACRO LABEL, REGISTER
                IMPORT LABEL
                mov LABEL, REGISTER
                ENDM

/*! \brief    Assembler macro to use labels with mov directive correctly.
 */
OS_HAL_ASM_MOV_LOCAL_LABEL_IAR MACRO LABEL, REGISTER
                mov LABEL, REGISTER
                ENDM

/*! \brief    Assembler macro to declare a public label.
 */
OS_HAL_ASM_GLOBAL_IAR MACRO LABEL
                PUBLIC LABEL
                ENDM


#endif /* OS_HAL_COMPILERIARASM_INC */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_IARASM.inc
 **********************************************************************************************************************/
