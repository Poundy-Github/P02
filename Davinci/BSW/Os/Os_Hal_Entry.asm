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
 *  \addtogroup Os_Hal_Entry
 *  \{
 *
 *  \file       Os_Hal_Entry.asm
 *  \brief      This component handles hardware exceptions and interrupts.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

#define OS_HAL_ENTRY_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Os module dependencies */
#include "Os_Cfg.h"

/* Os Hal dependencies */
#include "Os_Hal_Entry_Cfg.h"
#include "Os_Hal_Compiler_ASM.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/*! \brief Syscall table
 *  \details The syscall table contains only the unhandledSysCall handler because syscalls are not used within the OS.
 */
 OS_HAL_ASM_SECTION_OS_CONST()
 OS_HAL_ASM_ALIGN32()
 OS_HAL_ASM_GLOBAL(OS_SYSCALL_TABLE)
 OS_HAL_ASM_LABEL(OS_SYSCALL_TABLE)
 OS_HAL_ASM_SYSCALL_WORD(_Os_Hal_UnhandledSysCall,_OS_SYSCALL_TABLE)


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Irq_Isr()
 **********************************************************************************************************************/
/*! \brief      This handler is triggered, if a configured category 2 interrupt occurs.
 *  \details    This handler shall save a minimal set of registers, to be able to call a C-Function and restore
 *              the previous state afterwards. The rest is performed by the kernel's Os_IsrRun() function.
 *
 *              This handler typically has to save the following information:
 *              - Scratch Registers
 *              - Previous Program Counter
 *              - Previous Link Register
 *              - Previous Interrupt Level
 *
 *              The kernel expects Os_IsrRun() to be called on the interrupted stack.
 *              All handlers of this type shall have the following naming convention: Os_Irq_Isr_<Specific-Suffix>.
 *              The <Specific-Suffix> can be either the interrupt vector number or the interrupt source name.
 *              The kernel expects that Os_IsrRun() is executed on the interrupt priority level of the associated ISR2.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 **********************************************************************************************************************/
/*!
 * \internal
 *  - #10 Store interrupted context to stack.
 *  - #20 Enter Os Isr handler
 *  - #30 Restore interrupted context.
 *  - #40 Return to interrupted context.
 * \endinternal
 */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(Os_Irq_Isr)
 OS_HAL_ASM_EXTERN(Os_IsrRun)
 OS_HAL_ASM_LABEL(Os_Irq_Isr)
/* #10 Store interrupted context to stack. */
  OS_HAL_ASM_PUSHSP(r30,r31)
  stsr    0, r11, 0          /* store content of EIPC to r11 */
  stsr    1, r12, 0          /* store content of EIPSW to r12 */
  OS_HAL_ASM_PUSHSP(r11,r12)
#if defined (OS_HAL_ASM_FPU_USAGE)
  stsr    6, r11, 0          /* store content of FPSR to r11 */
  stsr    7, r12, 0          /* store content of FPEPC to r12 */
  OS_HAL_ASM_PUSHSP(r11,r12)
#endif /* defined (OS_HAL_ASM_FPU_USAGE) */
/* #20 Enter Os Isr handler. */
  jarl    _Os_IsrRun, lp
/* #30 Restore interrupted context. */
#if defined (OS_HAL_ASM_FPU_USAGE)
  OS_HAL_ASM_POPSP(r11,r12)
  ldsr    r11, 6, 0         /* load r11 to FPSR */
  ldsr    r12, 7, 0         /* load r12 to  FPEPC */
#endif /* defined (OS_HAL_ASM_FPU_USAGE) */
  OS_HAL_ASM_POPSP(r11,r12)
  ldsr    r11, 0, 0         /* load r11 to EIPC */
  ldsr    r12, 1, 0         /* load r11 to EIPSW */
  OS_HAL_ASM_POPSP(r30,r31)
  OS_HAL_ASM_POPSP(r4,r19)
  OS_HAL_ASM_POPSP(r1,r2)
/* #40 Retrun to interrupted context. */
  eiret


/***********************************************************************************************************************
 *  Os_Hal_SaveExceptionContextUnhandledExc()
 **********************************************************************************************************************/
/*! \brief      This handler saves context by exception entrance.
 *  \details    This handler takes a snapshot of the current context and stores it in a global variable.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 **********************************************************************************************************************/
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(Os_Hal_SaveExceptionContextUnhandledExc)
 OS_HAL_ASM_LABEL(Os_Hal_SaveExceptionContextUnhandledExc)
  ldsr    r6, 16 ,0                              /* Store r6 in CTPC to free r6 */
  ldsr    r7, 29, 0                              /* Store r7 in FEWR to free r7 */
  stsr    0, r6, 2                               /* r6 = CoreId */
  OS_HAL_COREID_PROCESS(r6)
  shl     2, r6
  OS_HAL_ASM_MOV_LABEL(OsCfg_Hal_Context_ExceptionContextRef, r7)
  add     r6, r7
  ld.w    0x00[r7], r6                           /* r6 = Address of exception context variable */
  st.w    r2,  0x00[r6]                          /* Save register r2 */
  st.w    r8,  0x0C[r6]                          /* Save register r8 */
  st.w    r9,  0x10[r6]                          /* Save register r9 */
  st.w    r10, 0x14[r6]                          /* Save register r10 */
  st.w    r11, 0x18[r6]                          /* Save register r11 */
  st.w    r12, 0x1C[r6]                          /* Save register r12 */
  st.w    r13, 0x20[r6]                          /* Save register r13 */
  st.w    r14, 0x24[r6]                          /* Save register r14 */
  st.w    r15, 0x28[r6]                          /* Save register r15 */
  st.w    r16, 0x2C[r6]                          /* Save register r16 */
  st.w    r17, 0x30[r6]                          /* Save register r17 */
  st.w    r18, 0x34[r6]                          /* Save register r18 */
  st.w    r19, 0x38[r6]                          /* Save register r19 */
  st.w    r20, 0x3C[r6]                          /* Save register r20 */
  st.w    r21, 0x40[r6]                          /* Save register r21 */
  st.w    r22, 0x44[r6]                          /* Save register r22 */
  st.w    r23, 0x48[r6]                          /* Save register r23 */
  st.w    r24, 0x4C[r6]                          /* Save register r24 */
  st.w    r25, 0x50[r6]                          /* Save register r25 */
  st.w    r26, 0x54[r6]                          /* Save register r26 */
  st.w    r27, 0x58[r6]                          /* Save register r27 */
  st.w    r28, 0x5C[r6]                          /* Save register r28 */
  st.w    r29, 0x60[r6]                          /* Save register r29 */
  mov     r6, r10                                /* r10 = Address of exception context variable */
  addi    0x64, r6, r6                           /* r6 += 0x64 */
  st.w    r3,  0x00[r6]                          /* Save stack pointer in Sp */
  stsr    14, r11, 0                             /* Store FEIC to r11 */
  st.w    r11, 0x04[r6]                          /* Save FEIC in Feic */
  OS_HAL_ASM_GET_ASID_REG(r11)                   /* Store ASID in r11 */
  st.w    r11, 0x08[r6]                          /* Save ASID in Pid */
  stsr    2, r11, 0                              /* Store FEPC to r11 */
  st.w    r11, 0x0C[r6]                          /* Save FEPC in Fepc */
  stsr    3, r11, 0                              /* Store FEPSW to r11 */
  st.w    r11, 0x10[r6]                          /* Save FEPSW in Fepsw */
  st.w    r31, 0x14[r6]                          /* Store LR to Lr */
  OS_HAL_ASM_SET_MPIDX_0                         /* Set MPIDX to 0 to read out stack region */
  OS_HAL_ASM_GET_MPLA0(r11)                      /* Store stack region start address to r11 */
  st.w    r11, 0x18[r6]                          /* Save stack region start address */
  OS_HAL_ASM_GET_MPUA0(r11)                      /* Store stack region end address to r11 */
  st.w    r11, 0x1C[r6]                          /* Save stack region end address */
  OS_HAL_ASM_GET_PMR(r11)                        /* Store PMR/PLMR to r11 */
  st.w    r11, 0x20[r6]                          /* Save PMR/PLMR to Pmr */
  stsr    16, r6, 0                              /* Restore r6 from CTPC */
  st.w    r6, 0x04[r10]                          /* Save register r6 */
  stsr    29, r7, 0                              /* Restore r7 from FEWR */
  st.w    r7, 0x08[r10]                          /* Save register r7 */
  jr _Os_Hal_UnhandledExcRet


/***********************************************************************************************************************
 *  Os_Hal_SaveExceptionContextMemFaultExc()
 **********************************************************************************************************************/
/*! \brief      This handler saves context by exception entrance.
 *  \details    This handler takes a snapshot of the current context and stores it in a global variable.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 **********************************************************************************************************************/
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(Os_Hal_SaveExceptionContextMemFaultExc)
 OS_HAL_ASM_LABEL(Os_Hal_SaveExceptionContextMemFaultExc)
  ldsr    r6, 16 ,0                              /* Store r6 in CTPC to free r6 */
  ldsr    r7, 29, 0                              /* Store r7 in FEWR to free r7 */
  stsr    0, r6, 2                               /* r6 = CoreId */
  OS_HAL_COREID_PROCESS(r6)
  shl     2, r6
  OS_HAL_ASM_MOV_LABEL(OsCfg_Hal_Context_ExceptionContextRef, r7)
  add     r6, r7
  ld.w    0x00[r7], r6                           /* r6 = Address of exception context variable */
  st.w    r2,  0x00[r6]                          /* Save register r2 */
  st.w    r8,  0x0C[r6]                          /* Save register r8 */
  st.w    r9,  0x10[r6]                          /* Save register r9 */
  st.w    r10, 0x14[r6]                          /* Save register r10 */
  st.w    r11, 0x18[r6]                          /* Save register r11 */
  st.w    r12, 0x1C[r6]                          /* Save register r12 */
  st.w    r13, 0x20[r6]                          /* Save register r13 */
  st.w    r14, 0x24[r6]                          /* Save register r14 */
  st.w    r15, 0x28[r6]                          /* Save register r15 */
  st.w    r16, 0x2C[r6]                          /* Save register r16 */
  st.w    r17, 0x30[r6]                          /* Save register r17 */
  st.w    r18, 0x34[r6]                          /* Save register r18 */
  st.w    r19, 0x38[r6]                          /* Save register r19 */
  st.w    r20, 0x3C[r6]                          /* Save register r20 */
  st.w    r21, 0x40[r6]                          /* Save register r21 */
  st.w    r22, 0x44[r6]                          /* Save register r22 */
  st.w    r23, 0x48[r6]                          /* Save register r23 */
  st.w    r24, 0x4C[r6]                          /* Save register r24 */
  st.w    r25, 0x50[r6]                          /* Save register r25 */
  st.w    r26, 0x54[r6]                          /* Save register r26 */
  st.w    r27, 0x58[r6]                          /* Save register r27 */
  st.w    r28, 0x5C[r6]                          /* Save register r28 */
  st.w    r29, 0x60[r6]                          /* Save register r29 */
  mov     r6, r10                                /* r10 = Address of exception context variable */
  addi    0x64, r6, r6                           /* r6 += 0x64 */
  st.w    r3,  0x00[r6]                          /* Save stack pointer in Sp */
  stsr    14, r11, 0                             /* Store FEIC to r11 */
  st.w    r11, 0x04[r6]                          /* Save FEIC in Feic */
  OS_HAL_ASM_GET_ASID_REG(r11)                   /* Store ASID in r11 */
  st.w    r11, 0x08[r6]                          /* Save ASID in Pid */
  stsr    2, r11, 0                              /* Store FEPC to r11 */
  st.w    r11, 0x0C[r6]                          /* Save FEPC in Fepc */
  stsr    3, r11, 0                              /* Store FEPSW to r11 */
  st.w    r11, 0x10[r6]                          /* Save FEPSW in Fepsw */
  st.w    r31, 0x14[r6]                          /* Store LR to Lr */
  OS_HAL_ASM_SET_MPIDX_0                         /* Set MPIDX to 0 to read out stack region */
  OS_HAL_ASM_GET_MPLA0(r11)                      /* Store stack region start address to r11 */
  st.w    r11, 0x18[r6]                          /* Save stack region start address */
  OS_HAL_ASM_GET_MPUA0(r11)                      /* Store stack region end address to r11 */
  st.w    r11, 0x1C[r6]                          /* Save stack region end address */
  OS_HAL_ASM_GET_PMR(r11)                        /* Store PMR/PLMR to r11 */
  st.w    r11, 0x20[r6]                          /* Save PMR/PLMR to Pmr */
  stsr    16, r6, 0                              /* Restore r6 from CTPC */
  st.w    r6, 0x04[r10]                          /* Save register r6 */
  stsr    29, r7, 0                              /* Restore r7 from FEWR */
  st.w    r7, 0x08[r10]                          /* Save register r7 */
  jr _Os_Hal_MemFaultExcRet


/***********************************************************************************************************************
 *  Os_Hal_RestoreExceptionContextFE()
 **********************************************************************************************************************/
/*! \brief      This handler restores context from FE level exceptions.
 *  \details    This handler restores context from a global variable.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 **********************************************************************************************************************/
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_LABEL(Os_Hal_RestoreExceptionContextFE)
  ldsr    r6, 16 ,0                              /* Store r6 in CTPC to free r6 */
  ldsr    r7, 29, 0                              /* Store r7 in FEWR to free r7 */
  stsr    0, r6, 2                               /* r6 = CoreId */
  OS_HAL_COREID_PROCESS(r6)
  shl     2, r6
  OS_HAL_ASM_MOV_LABEL(OsCfg_Hal_Context_ExceptionContextRef, r7)
  add     r6, r7
  ld.w    0x00[r7], r6                           /* r6 = Address of exception context variable */
  OS_HAL_ASM_SET_MPIDX_0                         /* Set MPIDX to 0 to read out stack region */
  ld.w    0x7C[r6], r11                          /* Get stack region start address */
  OS_HAL_ASM_SET_MPLA0(r11)                      /* Restore stack region start address from r11 */
  ld.w    0x80[r6], r11                          /* Get stack region end address */
  OS_HAL_ASM_SET_MPUA0(r11)                      /* Restore stack region end address to r11 */
  ld.w    0x84[r6], r11                          /* Get PMR/PLMR from Pmr */
  OS_HAL_ASM_SET_PMR(r11)                        /* Restore PMR/PLMR from r11 */
  ld.w    0x6C[r6], r11                          /* Get ASID from Pid */
  OS_HAL_ASM_SET_ADDRESS_ID_REG(r11)             /* Restore ASID from r11 */
  ld.w    0x68[r6], r11                          /* Get FEIC from Feic */
  ldsr    r11, 14, 0                             /* Restore FEIC from r11 */
  ld.w    0x70[r6], r11                          /* Get FEPC from Fepc */
  ldsr    r11, 2, 0                              /* Restore FEPC from r11 */
  ld.w    0x74[r6], r11                          /* Get FEPSW from Fepsw */
  ldsr    r11, 3, 0                              /* Restore FEPSW from r11 */
  ld.w    0x00[r6], r2                           /* Restore register r2 */
  ld.w    0x0C[r6], r8                           /* Restore register r8 */
  ld.w    0x10[r6], r9                           /* Restore register r9 */
  ld.w    0x14[r6], r10                          /* Restore register r10 */
  ld.w    0x18[r6], r11                          /* Restore register r11 */
  ld.w    0x1C[r6], r12                          /* Restore register r12 */
  ld.w    0x20[r6], r13                          /* Restore register r13 */
  ld.w    0x24[r6], r14                          /* Restore register r14 */
  ld.w    0x28[r6], r15                          /* Restore register r15 */
  ld.w    0x2C[r6], r16                          /* Restore register r16 */
  ld.w    0x30[r6], r17                          /* Restore register r17 */
  ld.w    0x34[r6], r18                          /* Restore register r18 */
  ld.w    0x38[r6], r19                          /* Restore register r19 */
  ld.w    0x3C[r6], r20                          /* Restore register r20 */
  ld.w    0x40[r6], r21                          /* Restore register r21 */
  ld.w    0x44[r6], r22                          /* Restore register r22 */
  ld.w    0x48[r6], r23                          /* Restore register r23 */
  ld.w    0x4C[r6], r24                          /* Restore register r24 */
  ld.w    0x50[r6], r25                          /* Restore register r25 */
  ld.w    0x54[r6], r26                          /* Restore register r26 */
  ld.w    0x58[r6], r27                          /* Restore register r27 */
  ld.w    0x5C[r6], r28                          /* Restore register r28 */
  ld.w    0x60[r6], r29                          /* Restore register r29 */
  ld.w    0x78[r6], r31                          /* Restore LR from Lr */
  ld.w    0x64[r6], r3                           /* Restore stack pointer from Sp */
  ld.w    0x08[r6], r6                           /* Restore register r6  */
  feret


/***********************************************************************************************************************
 *  Os_Hal_UnhandledIrq()
 **********************************************************************************************************************/
/*! \brief    This handler is triggered, if an interrupt occurs, which is not configured.
 *  \details  It shall call the kernel's Os_UnhandledIrq() function. Os_UnhandledIrq() expects the exception
 *            source number and the address of the interrupted instruction to be passed.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *
 *  \trace        CREQ-24
 **********************************************************************************************************************/
/*!
 * \internal
 *  - #10 Synchronize pipeline on exception entry.
 *  - #20 Disable FE level interrupts.
 *  - #30 Get the core ID.
 *  - #40 Switch to kernel stack and reprogram stack window.
 *  - #50 Store the exception index in first parameter of next function call.
 *  - #60 Store the exception address in second parameter of next function call.
 *  - #70 Store the privileged mode in third parameter of next function call.
 *  - #80 Call Os_UnhandledIrq in privileged mode with interrupts disabled.
 * \endinternal
 */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(Os_Hal_UnhandledIrq)
 OS_HAL_ASM_LABEL(Os_Hal_UnhandledIrq)
/* #10 Synchronize pipeline on exception entry. */
  syncp
/* #20 Disable FE level interrupts. */
  mov     0x000180A0, r11
  ldsr    r11, 5, 0         /* load r11 to PSW */
/* #30 Get the core ID. */
  stsr    0, r11, 2         /* store HTCFG0 to r11 */
  OS_HAL_COREID_PROCESS(r11)
  shl     2, r11
/* #40 Switch to kernel stack and reprogram stack window. */
  OS_HAL_ASM_MOV_LABEL(OsCfg_Stack_KernelStacks, r12)
  add     r11, r12
  ld.w    0[r12], r12
  ld.w    0[r12], r11
  OS_HAL_ASM_SET_MPIDX_0
  OS_HAL_ASM_SET_MPLA0(r11) /* load r11 to MPLA0 */
  ld.w    4[r12], r3        /* get SP (r3) */
  OS_HAL_ASM_SET_MPUA0(r3)  /* load SP (r3) to MPUA0 */
/* #50 Store the exception index in first parameter of next function call. */
  stsr    13, r6, 0         /* store EIIC to r6 */
  andi    0x01FF, r6, r6
/* #60 Store the exception address in second parameter of next function call. */
  stsr    0, r7, 0          /* store EIPC to r7 */
  ldsr    r7, 16, 0         /* load r7 to CTPC */
/* #70 Store the privileged mode in third parameter of next function call. */
  stsr    1, r8, 0          /* store EIPSW to r8 */
  ldsr    r8, 17, 0         /* store r8 to CTPSW */
  not     r8, r8
  shl     1, r8
  shr     31, r8
/* #80 Call Os_UnhandledIrq in privileged mode with interrupts disabled. */
  OS_HAL_ASM_MOV_LABEL(Os_UnhandledIrq, r11)
  ldsr    r11, 0, 0         /* load r11 to EIPC */
  mov     0x000180A0, r11
  ldsr    r11, 1, 0         /* load r11 to EIPSW */
  eiret


/***********************************************************************************************************************
 *  Os_Hal_UnhandledSysCall()
 **********************************************************************************************************************/
/*! \brief    This handler is called, if a system call is triggered, which is not handled by the OS.
 *  \details  It shall call the kernel's Os_UnhandledSysCall() function. Os_UnhandledSysCall() expects the
 *            address of the instruction that caused the exception to be passed.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 **********************************************************************************************************************/
/*!
 * \internal
 *  - #10 Synchronize pipeline on exception entry.
 *  - #20 Disable FE level interrupts.
 *  - #30 Get the core ID.
 *  - #40 Switch to kernel stack and reprogram stack window.
 *  - #50 Store the syscall address in first parameter of next function call.
 *  - #60 Store the privileged mode in second parameter of next function call.
 *  - #70 Call Os_UnhandledSysCall in privileged mode with interrupts disabled.
 * \endinternal
 */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(Os_Hal_UnhandledSysCall)
 OS_HAL_ASM_LABEL(Os_Hal_UnhandledSysCall)
/* #10 Synchronize pipeline on exception entry. */
  syncp
/* #20 Disable FE level interrupts. */
  mov     0x00018A0, r11
  ldsr    r11, 5, 0         /* load r11 to PSW */
/* #30 Get the core ID. */
  stsr    0, r11, 2         /* store HTCFG0 to r11 */
  OS_HAL_COREID_PROCESS(r11)
  shl     2, r11
/* #40 Switch to kernel stack an reprogram stack window. */
  OS_HAL_ASM_MOV_LABEL(OsCfg_Stack_KernelStacks, r12)
  add     r11, r12
  ld.w    0[r12], r12
  ld.w    0[r12], r11
  OS_HAL_ASM_SET_MPIDX_0
  OS_HAL_ASM_SET_MPLA0(r11) /* load r11 to MPLA0 */
  ld.w    4[r12], r3        /* r3 = SP */
  OS_HAL_ASM_SET_MPUA0(r3)  /* load SP (r3) to MPUA0 */
/* #50 Store the syscalll address in the first parameter of next function call. */
  stsr    0, r6, 0          /* store EIPC to r6 */
  ldsr    r6, 16 ,0         /* load r6 to CTPC */
/* #60 Store the privileged mode in second parameter of next function call. */
  stsr    1, r7, 0          /* store EIPSW  to r7 */
  ldsr    r7, 17, 0         /* load r7 to CTPSW */
  not     r7, r7
  shl     1, r7
  shr     31, r7
/* #70 Call Os_UnhandledSysCall in privileged mode with interrupts disabled. */
  OS_HAL_ASM_MOV_LABEL(Os_UnhandledSysCall, r11)
  ldsr    r11, 0, 0         /* load r11 to EIPC */
  mov     0x000180A0, r11
  ldsr    r11, 1, 0         /* load r11 to EIPSW */
  eiret


/***********************************************************************************************************************
 *  Os_Hal_MemFaultExc()
 **********************************************************************************************************************/
/*! \brief      This handler is triggered, if a memory fault is detected.
 *  \details    In this handler it is not safe to use the current stack pointer any longer, because the memory fault
 *              may be a result of an invalid stack pointer. For this reason the handler has to switch to the kernel
 *              stack before using any stack. Scratch registers are allowed to be destroyed here, because this function
 *              never returns.
 *
 *              The handler shall call the kernel's Os_MemFault() function with the address of the instruction that
 *              caused the exception as argument.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 **********************************************************************************************************************/
/*!
 * \internal
 *  - #10 Synchronize pipeline on exception entry.
 *  - #20 Save context.
 *  - #30 Get the core ID.
 *  - #40 Switch to kernel stack and reprogram stack window.
 *  - #50 Store the exception address in first parameter of next function call.
 *  - #60 Store the privileged mode in second parameter of next function call.
 *  - #70 Call Os_MemFault in privileged mode with interrupts disabled.
 * \endinternal
 */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_EXTERN(Os_MemFault)
 OS_HAL_ASM_GLOBAL(Os_Hal_MemFaultExc)
 OS_HAL_ASM_LABEL(Os_Hal_MemFaultExc)
/* #10 Synchronize pipeline on exception entry. */
  syncp
/* #20 Save context. */
  jr _Os_Hal_SaveExceptionContextMemFaultExc
  OS_HAL_ASM_LABEL(Os_Hal_MemFaultExcRet)
/* #30 Get the core ID. */
  stsr    0, r11, 2         /* store HTCFG0 to r11 */
  OS_HAL_COREID_PROCESS(r11)
  shl     2, r11
/* #40 Switch to kernel stack and reprogram stack window.*/
  OS_HAL_ASM_MOV_LABEL(OsCfg_Stack_KernelStacks, r12)
  add     r11, r12
  ld.w    0[r12], r12
  ld.w    0[r12], r11
  OS_HAL_ASM_SET_MPIDX_0
  OS_HAL_ASM_SET_MPLA0(r11) /* load r11 to MPLA0 */
  ld.w    4[r12], r3        /* r3 = SP */
  OS_HAL_ASM_SET_MPUA0(r3)  /* load SP (r3) to MPUA0 */
/* #50 Store the exception address in first parameter of next function call.*/
  stsr    2, r6, 0          /* store FEPC to r6 */
  ldsr    r6, 16 ,0         /* load r6 to CTPC */
/* #60 Store the privileged mode in second parameter of next function call.*/
  stsr    3, r7, 0          /* store FEPSW to r7 */
  ldsr    r7, 17, 0         /* load r7 to CTPSW */
  not     r7, r7
  shl     1, r7
  shr     31, r7
/* #70 Call Os_MemFault in privileged mode with interrupts disabled.*/
  OS_HAL_ASM_MOV_LABEL(Os_MemFault, r11)
  OS_HAL_ASM_MOV_LOCAL_LABEL(Os_Hal_RestoreExceptionContextFE, r31)
  ldsr    r11, 2, 0         /* load r11 to FEPC */
  mov     0x00018A0, r11
  ldsr    r11, 3, 0         /* load r11 to FEPSW */
  feret


/***********************************************************************************************************************
 *  Os_Hal_UnhandledExc()
 **********************************************************************************************************************/
/*! \brief    This handler is called, if an exception is triggered, which is not handled by the OS.
 *  \details  In this handler it is not safe to use the current stack pointer any longer, because the exception
 *            may be a result of an invalid stack pointer. For this reason the handler has to switch to the kernel
 *            stack before using any stack.
 *
 *            This handler shall call the kernel's Os_UnhandledExc() function.
 *            Os_UnhandledExc() expects the following parameters:
 *              <EXC-SOURCE>           The source number of the exception.
 *              <INSTRUCTION-ADDRESS>  The address of the causing instruction.
 *              <CAUSER-PRIVILEGED>    The privilege state before the exception:
 *                                       !0 Before the exception, the core was privileged.
 *                                       0  Before the exception, the core was not privileged.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 **********************************************************************************************************************/
  /*!
   * \internal
   *  - #10 Synchronize pipeline on exception entry.
   *  - #20 Save context.
   *  - #30 Get the core ID.
   *  - #40 Switch to kernel stack and reprogram stack window.
   *  - #50 Store the exception index in first parameter of next function call.
   *  - #60 Store the exception address in second parameter of next function call.
   *  - #70 Store the privileged mode in third parameter of next function call.
   *  - #80 Call Os_UnhandledExc in privileged mode with interrupts disabled.
   * \endinternal
   */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(Os_Hal_UnhandledExc)
 OS_HAL_ASM_LABEL(Os_Hal_UnhandledExc)
 OS_HAL_ASM_EXTERN(Os_UnhandledExc)
/* #10 Synchronize pipeline on exception entry. */
  syncp
/* #20 Save context. */
  jr _Os_Hal_SaveExceptionContextUnhandledExc
  OS_HAL_ASM_LABEL(Os_Hal_UnhandledExcRet)
/* #30 Get the core ID. */
  stsr    0, r11, 2         /* store HTCFG0 to r11 */
  OS_HAL_COREID_PROCESS(r11)
  shl     2, r11
/* #40 Switch to kernel stack and reprogram stack window. */
  OS_HAL_ASM_MOV_LABEL(OsCfg_Stack_KernelStacks, r12)
  add     r11, r12
  ld.w    0[r12], r12
  ld.w    0[r12], r11
  OS_HAL_ASM_SET_MPIDX_0
  OS_HAL_ASM_SET_MPLA0(r11) /* load r11 to MPLA0 */
  ld.w    4[r12], r3        /* r3 = SP */
  OS_HAL_ASM_SET_MPUA0(r3)  /* load SP to MPUA0 */
/* #50 Store the exception index in first parameter of next function call. */
  stsr    14, r6, 0         /* store FEIC to r6 */
  shr     4, r6
/* #60 Store the exception address in second parameter of next function call. */
  stsr    2, r7, 0          /* store FEPC to r7 */
  ldsr    r7, 16, 0         /* load r7 to CTPC */
/* #70 Store the privileged mode in third parameter of next function call. */
  stsr    3, r8, 0          /* store FEPSW to r8 */
  ldsr    r8, 17, 0         /* load r8 to CTPSW */
  not     r8, r8
  shl     1, r8
  shr     31, r8
/* #80 Call Os_UnhandledExc in privileged mode with interrupts disabled. */
  OS_HAL_ASM_MOV_LABEL(Os_UnhandledExc, r11)
  OS_HAL_ASM_MOV_LOCAL_LABEL(Os_Hal_RestoreExceptionContextFE, r31)
  ldsr    r11, 2, 0         /* load r11 to FEPC */
  mov     0x000180A0, r11
  ldsr    r11, 3, 0         /* load r11 to PEPSW */
  feret

 OS_HAL_ASM_END_OF_FILE()

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry.asm
 **********************************************************************************************************************/

