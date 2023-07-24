/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Hal_Compiler
 * \{
 *
 * \file       Os_Hal_Compiler_Greenhills_ASMInt.h
 * \brief      Compiler abstraction for assembler macros compiler Greenhills
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_COMPILER_GREENHILLS_ASM
# define OS_HAL_COMPILER_GREENHILLS_ASM
                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! PSW Mask for EP flag - Disable EI interrupt handling. */
#define OS_HAL_PSW_EP_MSK                           (0x00000040)

/* Compiler abstraction of assembler directive .section (text) */
#define OS_HAL_ASM_SECTION_TEXT(SEC_NAME)            .##section SEC_NAME, ax

/* Compiler abstraction of assembler directive to declare .OS_CONST section */
#define OS_HAL_ASM_SECTION_OS_CONST()                .##section .##OS_CONST, a

/* Compiler abstraction of assembler directive to declare .OS_CODE section */
#define OS_HAL_ASM_SECTION_OS_CODE()                 .##section .##OS_CODE, ax

/* Compiler abstraction of assembler directive .align for specific alignment values */
#define OS_HAL_ASM_ALIGN2()                          .##align 2

#define OS_HAL_ASM_ALIGN4()                          .##align 4

#define OS_HAL_ASM_ALIGN8()                          .##align 8

#define OS_HAL_ASM_ALIGN16()                         .##align 16

#define OS_HAL_ASM_ALIGN32()                         .##align 32

#define OS_HAL_ASM_ALIGN64()                         .##align 64

#define OS_HAL_ASM_ALIGN128()                        .##align 128

#define OS_HAL_ASM_ALIGN256()                        .##align 256

#define OS_HAL_ASM_ALIGN512()                        .##align 512

#define OS_HAL_ASM_ALIGN1024()                       .##align 1024

/* Compiler abstraction of assembler directive to signal end of file */
#define OS_HAL_ASM_END_OF_FILE()

/* Compiler abstraction of assembler directive .align */
#define OS_HAL_ASM_ALIGN(ALIGN_VAL)                  .##align ALIGN_VAL

/* Compiler abstraction of assembler directive to declare global label */
#define OS_HAL_ASM_GLOBAL(LABEL)                     .##globl _##LABEL

/* Compiler abstraction of assembler directive to define label */
#define OS_HAL_ASM_LABEL(LABEL)                      _##LABEL:

/* Compiler abstraction of assembler directive to allocate memory area */
#define OS_HAL_ASM_WORD(LABEL)                       .##word _##LABEL

/* Compiler abstraction of assembler directive pushsp */
#define OS_HAL_ASM_PUSHSP(R1,R2)                     pushsp R1-R2

/* Compiler abstraction of assembler directive popsp */
#define OS_HAL_ASM_POPSP(R1,R2)                      popsp R1-R2

/* Compiler abstraction of assembler directive to declare extern label */
#define OS_HAL_ASM_EXTERN(LABEL)

/* Compiler abstraction to declare exception vector table */
#define OS_HAL_ASM_EXC(LABEL,FUNC)                   OS_HAL_ASM_EXC_GHS LABEL,FUNC

/* Compiler abstraction of assembler directive to declare CAT2 Isr */
#define OS_HAL_ASM_CAT2ISR(ISRNAME)                  OS_HAL_ASM_CAT2ISR_GHS ISRNAME

/* Compiler abstraction of assembler directive to declare syscall table */
#define OS_HAL_ASM_SYSCALL_WORD(LABEL_A,LABEL_B)     .##word(LABEL_A - LABEL_B)

/* Compiler abstraction of assembler directive mov, using labels */
#define OS_HAL_ASM_MOV_LABEL(LABEL,REGISTER)         mov _##LABEL, REGISTER

/* Compiler abstraction of assembler directive mov, using local label */
#define OS_HAL_ASM_MOV_LOCAL_LABEL(LABEL,REGISTER)   mov _##LABEL, REGISTER

#if defined (OS_HAL_ASM_CORE_G4X)

/* Compiler abstraction of assembler directive to access MPIDX register - G4X core MPU handling */
# define OS_HAL_ASM_SET_MPIDX_0                      ldsr r0, 16, 5

/* Compiler abstraction of assembler directive to access MPU area 0 lower address register */
# define OS_HAL_ASM_SET_MPLA0(REG)                   ldsr REG, 20, 5

/* Compiler abstraction of assembler directive to read MPU area 0 lower address register */
# define OS_HAL_ASM_GET_MPLA0(REG)                   stsr 20, REG, 5

/* Compiler abstraction of assembler directive to access MPU area 0 upper address register */
# define OS_HAL_ASM_SET_MPUA0(REG)                   ldsr REG, 21, 5

/* Compiler abstraction of assembler directive to read MPU area 0 upper address register */
# define OS_HAL_ASM_GET_MPUA0(REG)                   stsr 21, REG, 5

/* Compiler abstraction of assembler directive to access MPU area 0 protection attribute register */
# define OS_HAL_ASM_SET_MPAT0(REG)                   ldsr REG, 22, 5

/* Compiler abstraction of assembler directive to access address space ID register */
# define OS_HAL_ASM_SET_ADDRESS_ID_REG(REG)          ldsr REG, 0, 1

/* Compiler abstraction of assembler directive to read address space ID register */
# define OS_HAL_ASM_GET_ASID_REG(REG)                stsr 0, REG, 1

/* Compiler abstraction of assembler directive to access PMR register */
# define OS_HAL_ASM_GET_PMR(REG)                     stsr   14, REG, 2

/* Compiler abstraction of assembler directive to access PMR register */
# define OS_HAL_ASM_SET_PMR(REG)                     ldsr REG, 14, 2

/* Compiler abstraction of assembler directive to process core ID register - G3X cores */
#define OS_HAL_COREID_PROCESS(REG)

#else

/* Compiler abstraction of assembler directive to access MPIDX register - G4X core MPU handling */
# define OS_HAL_ASM_SET_MPIDX_0

/* Compiler abstraction of assembler directive to access MPU area 0 lower address register */
# define OS_HAL_ASM_SET_MPLA0(REG)                   ldsr REG, 0, 6

/* Compiler abstraction of assembler directive to read MPU area 0 lower address register */
# define OS_HAL_ASM_GET_MPLA0(REG)                   stsr 0, REG, 6

/* Compiler abstraction of assembler directive to access MPU area 0 upper address register */
# define OS_HAL_ASM_SET_MPUA0(REG)                   ldsr REG, 1, 6

/* Compiler abstraction of assembler directive to read MPU area 0 lower address register */
# define OS_HAL_ASM_GET_MPUA0(REG)                   stsr 1, REG, 6

/* Compiler abstraction of assembler directive to access MPU area 0 protection attribute register */
# define OS_HAL_ASM_SET_MPAT0(REG)                   ldsr REG, 2, 6

/* Compiler abstraction of assembler directive to access address space ID register */
# define OS_HAL_ASM_SET_ADDRESS_ID_REG(REG)          ldsr REG, 7, 2

/* Compiler abstraction of assembler directive to read address space ID register */
# define OS_HAL_ASM_GET_ASID_REG(REG)                stsr 7, REG, 2

/* Compiler abstraction of assembler directive to access PMR register */
# define OS_HAL_ASM_GET_PMR(REG)                     stsr   11, REG, 2

/* Compiler abstraction of assembler directive to access PMR register */
# define OS_HAL_ASM_SET_PMR(REG)                     ldsr REG, 11, 2

/* Compiler abstraction of assembler directive to process core ID register - G3X cores */
#define OS_HAL_COREID_PROCESS(REG)                   shr 17, REG

#endif

#pragma asm

/* Macro to create the entries of the exception table */
.macro OS_HAL_ASM_EXC_GHS LABEL,FUNC
  .align 16
  .globl _><LABEL
  _><LABEL:
  /* #10 Jump to the passed exception handler symbol. */
  jr32 _><FUNC
  nop
  nop
  nop
.endm

/* Macro to declare CAT2 ISR */
.macro OS_HAL_ASM_CAT2ISR_GHS ISRNAME
  .section ".OS_CODE", "ax"
  .align 4
  _Os_Hal_Irq_><ISRNAME:
  /* #10 Store temporary registers on the stack. */
  pushsp r1-r2
  pushsp r4-r19
  /* #20 Store the pointer to ISR configuration in function parameter 1. */
  mov   _OsCfg_Isr_><ISRNAME, r6
  /* #30 Jump to function Os_Irq_Isr */
  jr    _Os_Irq_Isr

.endm

#pragma endasm

#endif /* OS_HAL_COMPILER_GREENHILLS_ASM */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_Greenhills_ASMInt.h
 **********************************************************************************************************************/
