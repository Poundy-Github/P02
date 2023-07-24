
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
  \file  File:  BrsHwStartup.c
      Project:  Vector Basic Runtime System
       Module:  BrsHw for platform Renesas RH850
     Template:  This file is reviewed according to Brs_Template@Implementation[1.00.00]

  \brief Description:  This file contains the assembler part of the BRS StartUpCode.

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Benjamin Walter               visbwa        Vector Informatik GmbH
  Lukas Rohrwild                virrlu        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2020-06-03  visbwa  New branch for vBaseEnv 2.0, based on zBrs_Rh850 BrsHwStartup.c 1.05.05
                        virrlu  Updated vLinkGen define and struct names to new vLinkGen 2.0 naming schema
  01.00.01  2020-06-08  virrlu  Fixed error in accessing of vLinkGen structs
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "BrsHw.h"
#include "BrsMain.h"
#include "BrsMainStartup.h"
#include "vLinkGen_Lcfg.h"

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/
#if defined (BRS_COMP_GHS) 

#else
  #error "Unknown compiler specified!"
#endif

#if (VLINKGEN_CFG_MAJOR_VERSION != 2u)
  #error "This StartUpCode is dependent to the vLinkGen version! vLinkGen major version does not fit!"
#else
# if (VLINKGEN_CFG_MINOR_VERSION < 0u)
  #error "This StartUpCode is dependent to the vLinkGen version! Your vLinkGen minor version is too old!"
# endif
#endif

/* =========================================================================== */
/*                                                                             */
/* Description: Definition of external functions                               */
/*                                                                             */
/* =========================================================================== */

/* =========================================================================== */
/*                                                                             */
/* Description: Entry point for all cores                                      */
/*                                                                             */
/* =========================================================================== */
BRS_SECTION_CODE(brsStartup)
 BRS_GLOBAL(brsStartupEntry)
BRS_LABEL(brsStartupEntry)

#if (BRS_CPU_CORE_AMOUNT>1) && !defined (BRS_CPU_CORE_G4MH)
  /* This is a multicore derivative != U2A */
  /* If the current core is the INIT core, branch to the the next step */
  BRS_READ_COREID(r11)
  BRS_BRANCH_EQUAL(BRSHW_INIT_CORE_ID,r11,brsPreAsmStartupHook)

  /* Loop all other cores */
  __as1(mov BRSHW_CORE_START_PATTERN, r6)
  __as1(mov BRSHW_CORE_SYNC_REG, r7)
  BRS_LABEL(coreWaitLoop)
  __as1(ld.w  0[r7],r8)/* Load sync register */
  __as1(cmp   r6, r8) /* If sync pattern is not present, loop again */
  ___asm(bne   coreWaitLoop)
#elif defined (BRS_DERIVATIVE_GROUP_E1L)
  /* Keep PCU core in an endless loop. */
  BRS_READ_COREID(r11)
  BRS_LABEL(PCUWaitLabel)
  BRS_BRANCH_NOT_EQUAL(BRSHW_INIT_CORE_ID, r11, PCUWaitLabel)
# endif /*BRS_CPU_CORE_AMOUNT>1 && !BRS_CPU_CORE_G4MH*/

 BRS_BRANCH(brsPreAsmStartupHook)

/* =========================================================================== */
/*                                                                             */
/* Description: Optional hook for platform specific tasks                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(brsPreAsmStartupHook)
BRS_LABEL(brsPreAsmStartupHook)
/* Nothing to do here */

 BRS_BRANCH(coreRegisterInit)

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize core ID independent core registers                  */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit)
BRS_LABEL(coreRegisterInit)
/* For RH850, we don't have to distinguish between Core Types (yet) */
/* General Purpose Registers */
__as1(mov r0, r1)
__as1(mov r0, r2)
__as1(mov r0, r3)
__as1(mov r0, r4)
__as1(mov r0, r5)
__as1(mov r0, r6)
__as1(mov r0, r7)
__as1(mov r0, r8)
__as1(mov r0, r9)
__as1(mov r0, r10)
__as1(mov r0, r11)
__as1(mov r0, r12)
__as1(mov r0, r13)
__as1(mov r0, r14)
__as1(mov r0, r15)
__as1(mov r0, r16)
__as1(mov r0, r17)
__as1(mov r0, r18)
__as1(mov r0, r19)
__as1(mov r0, r20)
__as1(mov r0, r21)
__as1(mov r0, r22)
__as1(mov r0, r23)
__as1(mov r0, r24)
__as1(mov r0, r25)
__as1(mov r0, r26)
__as1(mov r0, r27)
__as1(mov r0, r28)
__as1(mov r0, r29)
__as1(mov r0, r30)
__as1(mov r0, r31)

/* Basic System Registers */
__as2(ldsr r0, 0, 0)  /* EIPC */
__as2(ldsr r0, 2, 0)  /* FEPC */
__as2(ldsr r0, 16, 0) /* CTPC */
__as2(ldsr r0, 20, 0) /* CTBP */
__as2(ldsr r0, 28, 0) /* EIWR */
__as2(ldsr r0, 29, 0) /* FEWR */
__as2(ldsr r0, 3, 1)  /* EBASE */
__as2(ldsr r0, 4, 1)  /* INTBP */
__as2(ldsr r0, 11, 1) /* SCCFG */
__as2(ldsr r0, 12, 1) /* SCBP */
__as2(ldsr r0, 6, 2)  /* MEA */
__as2(ldsr r0, 7, 2)  /* ASID */
__as2(ldsr r0, 8, 2)  /* MEI */

#if (defined(__NoFloat__) || defined(__SoftwareFloat__))
  /* No hardware floating point support according to GHS compiler options. */
  /* Skip FPU function register initialization. */
#else
  /* FPU Function Registers */
  __as1(stsr PSW, r1) /* Enable access to FPU co processor */
  __as1(mov  0x10000, r2)
  __as1(or   r2, r1)
  __as1(ldsr r1, PSW)
  __as2(ldsr r6, 6, 0)  /* FPSR - Initial value after reset FPSR.FS=1 */
  __as2(ldsr r0, 7, 0)  /* FPEPC */
  __as2(ldsr r0, 8, 0)  /* FPST */
  __as2(ldsr r0, 9, 0)  /* FPCC */
  __as2(ldsr r0, 10, 0) /* FPCFG */
  __as2(ldsr r0, 11, 0) /* FPEC */
#endif

/* MPU Function registers */
__as2(ldsr r0, 8, 5)    /* MCA */
__as2(ldsr r0, 9, 5)    /* MCS */
__as2(ldsr r0, 11, 5)   /* MCR */
__as2(ldsr r0, 0, 6)    /* MPLA0 */
__as2(ldsr r0, 1, 6)    /* MPUA0 */
__as2(ldsr r0, 2, 6)    /* MPAT0 */
__as2(ldsr r0, 4, 6)    /* MPLA1 */
__as2(ldsr r0, 5, 6)    /* MPUA1 */
__as2(ldsr r0, 6, 6)    /* MPAT1 */
__as2(ldsr r0, 8, 6)    /* MPLA2 */
__as2(ldsr r0, 9, 6)    /* MPUA2 */
__as2(ldsr r0, 10, 6)   /* MPAT2 */
__as2(ldsr r0, 12, 6)   /* MPLA3 */
__as2(ldsr r0, 13, 6)   /* MPUA3 */
__as2(ldsr r0, 14, 6)   /* MPAT3 */
__as2(ldsr r0, 16, 6)   /* MPLA4 */
__as2(ldsr r0, 17, 6)   /* MPUA4 */
__as2(ldsr r0, 18, 6)   /* MPAT4 */
__as2(ldsr r0, 20, 6)   /* MPLA5 */
__as2(ldsr r0, 21, 6)   /* MPUA5 */
__as2(ldsr r0, 22, 6)   /* MPAT5 */
__as2(ldsr r0, 24, 6)   /* MPLA6 */
__as2(ldsr r0, 25, 6)   /* MPUA6 */
__as2(ldsr r0, 26, 6)   /* MPAT6 */
__as2(ldsr r0, 28, 6)   /* MPLA7 */
__as2(ldsr r0, 29, 6)   /* MPUA7 */
__as2(ldsr r0, 30, 6)   /* MPAT7 */
__as2(ldsr r0, 0, 7)    /* MPLA8 */
__as2(ldsr r0, 1, 7)    /* MPUA8 */
__as2(ldsr r0, 2, 7)    /* MPAT8 */
__as2(ldsr r0, 4, 7)    /* MPLA9 */
__as2(ldsr r0, 5, 7)    /* MPUA9 */
__as2(ldsr r0, 6, 7)    /* MPAT9 */
__as2(ldsr r0, 8, 7)    /* MPLA10 */
__as2(ldsr r0, 9, 7)    /* MPUA10 */
__as2(ldsr r0, 10, 7)   /* MPAT10 */
__as2(ldsr r0, 12, 7)   /* MPLA11 */
__as2(ldsr r0, 13, 7)   /* MPUA11 */
__as2(ldsr r0, 14, 7)   /* MPAT11 */

/* Initialization of the global pointer */
__as1(mov   __gp, gp)

/* Initialization of the text pointer */
__as1(mov   __tp, tp)

/* Core Type dependent part */
#if defined (BRS_CPU_CORE_G3M) || defined (BRS_CPU_CORE_G3MH)
  /* Hardware Thread Function Registers */
  __as2(ldsr r0, 10, 1) /* TCSEL */

  /* Virtualization Support Function Registers */
  __as2(ldsr r0, 13, 1) /* HVCCFG */
  __as2(ldsr r0, 14, 1) /* HVCBP */
  __as2(ldsr r0, 15, 1) /* VCSEL */

  /* Cache Operation Function Registers */
  __as2(ldsr r0, 16, 4) /* ICTAGL */
  __as2(ldsr r0, 17, 4) /* ICTAGH */
  __as2(ldsr r0, 18, 4) /* ICDATL */
  __as2(ldsr r0, 19, 4) /* ICDATH */
  __as2(ldsr r0, 28, 4) /* ICERR */
#endif /*BRS_CPU_CORE_G3M||BRS_CPU_CORE_G3MH*/

 BRS_BRANCH(coreRegisterInit2)

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core ID dependent core registers                */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit2)
BRS_LABEL(coreRegisterInit2)

/* Branch to the core ID specific init routines coreRegisterInit2_cx */
BRS_READ_COREID(r11)
BRS_BRANCH_EQUAL(BRSHW_DERIVATIVE_CORE0_ID,r11,coreRegisterInit2_c0)

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
# if (BRS_CPU_CORE_AMOUNT>1)
  /* For multicore, branch to the correct init routine for the core id */
  BRS_BRANCH_EQUAL(BRSHW_DERIVATIVE_CORE1_ID,r11,coreRegisterInit2_c1)
# endif
# if (BRS_CPU_CORE_AMOUNT>2)
  BRS_BRANCH_EQUAL(BRSHW_DERIVATIVE_CORE2_ID,r11,coreRegisterInit2_c2)
# endif
# if (BRS_CPU_CORE_AMOUNT>3)
  BRS_BRANCH_EQUAL(BRSHW_DERIVATIVE_CORE3_ID,r11,coreRegisterInit2_c3)
# endif
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

/* Still here? ID is not supported yet -> BrsMainExceptionStartup */
 BRS_BRANCH(_BrsMainExceptionStartup)

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 0). Also used for singlecore derivatives                 */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit2_c0)
BRS_LABEL(coreRegisterInit2_c0)

/*  Setup initial core exception table */
/* Set OS section label here */
__as1(mov   _OS_EXCVEC_CORE0_CODE_START, r11)
__as2(ldsr   r11, 3, 1)   /* EBASE */
__as1(mov 0x00008020, r6) /* Disable interrupts and PSW.EBV bit to 1. */
__as1(ldsr r6, PSW)

/* Setup initial interrupt handler table */
__as1(mov   _OS_INTVEC_CORE0_CODE_START, r6) /* interrupt handler base address */
__as2(ldsr r6, 4, 1)      /* INTBP*/

/* Initialization of the stack pointer */
__as1(mov __section_stack_c0_end, sp)

 BRS_BRANCH(brsStartupZeroInitLoop)

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
# if (BRS_CPU_CORE_AMOUNT>1)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 1)                                                       */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit2_c1)
BRS_LABEL(coreRegisterInit2_c1)

/*  Setup initial core exception table */
/* Set OS section label here */
__as1(mov   _OS_EXCVEC_CORE1_CODE_START, r11)
__as2(ldsr   r11, 3, 1)   /* EBASE */

__as1(mov 0x00008020, r6) /* Disable interrupts and PSW.EBV bit to 1. */
__as1(ldsr r6, PSW)

/* Setup initial interrupt handler table */
__as1(mov   _OS_INTVEC_CORE1_CODE_START, r6) /* interrupt handler base address */
__as2(ldsr r6, 4, 1)      /* INTBP*/

/* Initialization of the stack pointer */
__as1(mov __section_stack_c1_end, sp)

 BRS_BRANCH(brsStartupZeroInitLoop)
# endif /*BRS_CPU_CORE_AMOUNT>1*/

# if (BRS_CPU_CORE_AMOUNT>2)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 2)                                                       */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit2_c2)
BRS_LABEL(coreRegisterInit2_c2)

/*  Setup initial core exception table */
/* Set OS section label here */
__as1(mov   _OS_EXCVEC_CORE2_CODE_START, r11)
__as2(ldsr   r11, 3, 1)   /* EBASE */

__as1(mov 0x00008020, r6) /* Disable interrupts and PSW.EBV bit to 1. */
__as1(ldsr r6, PSW)

/* Setup initial interrupt handler table */
__as1(mov   _OS_INTVEC_CORE2_CODE_START, r6) /* interrupt handler base address */
__as2(ldsr r6, 4, 1)      /* INTBP*/

/* Initialization of the stack pointer */
__as1(mov __section_stack_c2_end, sp)

 BRS_BRANCH(brsStartupZeroInitLoop)
# endif /*BRS_CPU_CORE_AMOUNT>2*/

# if (BRS_CPU_CORE_AMOUNT>3)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 3)                                                       */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit2_c3)
BRS_LABEL(coreRegisterInit2_c3)

/*  Setup initial core exception table */
/* Set OS section label here */
__as1(mov   _OS_EXCVEC_CORE3_CODE_START, r11)
__as2(ldsr   r11, 3, 1)   /* EBASE */

__as1(mov 0x00008020, r6) /* Disable interrupts and PSW.EBV bit to 1. */
__as1(ldsr r6, PSW)
 
/* Setup initial interrupt handler table */
__as1(mov   _OS_INTVEC_CORE3_CODE_START, r6) /* interrupt handler base address */
__as2(ldsr r6, 4, 1)      /* INTBP*/

/* Initialization of the stack pointer */
__as1(mov __section_stack_c3_end, sp)

 BRS_BRANCH(brsStartupZeroInitLoop)
# endif /*BRS_CPU_CORE_AMOUNT>3*/
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize memory blocks and areas with zero                   */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(brsStartupZeroInitLoop)
BRS_LABEL(brsStartupZeroInitLoop)

/* read ID of actual running Core into Register 16 */
BRS_READ_COREID(r16)

/* Initialize memory sections with zeros */
#if defined (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS)
# if (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS>1uL)
  __as1(mov    _vLinkGen_ZeroInit_Early_Blocks, r11)
BRS_LABEL(_startup_block_zero_init_start)
  __as1(mov    r11, r12)
  __as2(addi   16, r11, r11)
  __as1(ld.w   0[r12], r13)               /* get start address */
  __as1(ld.w   4[r12], r14)               /* get end address */
  __as1(ld.w   8[r12], r15)               /* get core ID */
  __as1(cmp    r13, r14)                  /* check end of table */
  ___asm(be     _startup_block_zero_init_end)

  __as1(cmp    r15, r16)                  /* compare core ID */
  ___asm(bne    _startup_block_zero_init_start)
BRS_LABEL(_startup_block_zero_init_loop_start)
  __as1(st.w   r0, 0[r13])
  __as2(addi   4, r13, r13)
  __as1(cmp    r13, r14)                  /* compare to end address */
  ___asm(bh     _startup_block_zero_init_loop_start)
  ___asm(jr     _startup_block_zero_init_start)
BRS_LABEL(_startup_block_zero_init_end)
# endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS>1uL*/

#else
  #error "Mandatory define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS missing within vLinkGen configuration!"
#endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS*/

#if defined (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS)
# if (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS>1uL)
  __as1(mov    _vLinkGen_ZeroInit_Early_Groups, r11)
BRS_LABEL(_startup_area_zero_init_start)
  __as1(mov    r11, r12)
  __as2(addi   16, r11, r11)
  __as1(ld.w   0[r12], r13)               /* get start address */
  __as1(ld.w   4[r12], r14)               /* get end address */
  __as1(ld.w   8[r12], r15)               /* get core ID */
  __as1(cmp    r13, r14)                  /* check end of table */
  ___asm(be     _startup_area_zero_init_end)

  __as1(cmp    r15, r16)                  /* compare core ID */
  ___asm(bne    _startup_area_zero_init_start)
BRS_LABEL(_startup_area_zero_init_loop_start)
  __as1(st.w   r0, 0[r13])
  __as2(addi   4, r13, r13)
  __as1(cmp    r13, r14)                  /* compare to end address */
  ___asm(bh     _startup_area_zero_init_loop_start)
  ___asm(jr     _startup_area_zero_init_start)
BRS_LABEL(_startup_area_zero_init_end)
# endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS>1uL*/

#else
  #error "Mandatory define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS missing within vLinkGen configuration!"
#endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS*/

/* =========================================================================== */
/*                                                                             */
/* Description: Jump to Brs_PreMainStartup() (BrsMainStartup.c)                */
/*                                                                             */
/* =========================================================================== */
 BRS_BRANCH(_Brs_PreMainStartup)

/* =========================================================================== */
/*                                                                             */
/* Description: Jump to BrsMainExceptionStartup() in case of an unexpected     */
/*              return from PreMain/main                                       */
/*                                                                             */
/* =========================================================================== */
 BRS_BRANCH(_BrsMainExceptionStartup)

/* =========================================================================== */
/* Minimal reset vector at entry address (e. g. 0x0)                           */
/* =========================================================================== */
__as1(.section ".bcode0", "ax")
BRS_ALIGN16()
BRS_BRANCH(brsStartupEntry)
___asm(nop)
___asm(nop)
___asm(nop)
BRS_ALIGN16()
 BRS_BRANCH(_BrsMainExceptionStartup)
___asm(nop)
___asm(nop)
___asm(nop)

#if (BRS_CPU_CORE_AMOUNT>1)
/* =========================================================================== */
/* Minimal reset vector at entry address (e. g. 0x0)                           */
/* =========================================================================== */
__as1(.section ".bcode1", "ax")
BRS_ALIGN16()
BRS_BRANCH(brsStartupEntry)
___asm(nop)
___asm(nop)
___asm(nop)
BRS_ALIGN16()
 BRS_BRANCH(_BrsMainExceptionStartup)
___asm(nop)
___asm(nop)
___asm(nop)
#endif /*BRS_CPU_CORE_AMOUNT>1*/

#if (BRS_CPU_CORE_AMOUNT>2)
/* =========================================================================== */
/* Minimal reset vector at entry address (e. g. 0x0)                           */
/* =========================================================================== */
__as1(.section ".bcode2", "ax")
BRS_ALIGN16()
BRS_BRANCH(brsStartupEntry)
___asm(nop)
___asm(nop)
___asm(nop)
BRS_ALIGN16()
 BRS_BRANCH(_BrsMainExceptionStartup)
___asm(nop)
___asm(nop)
___asm(nop)
#endif /*BRS_CPU_CORE_AMOUNT>2*/

#if (BRS_CPU_CORE_AMOUNT>3)
/* =========================================================================== */
/* Minimal reset vector at entry address (e. g. 0x0)                           */
/* =========================================================================== */
__as1(.section ".bcode3", "ax")
BRS_ALIGN16()
BRS_BRANCH(brsStartupEntry)
___asm(nop)
___asm(nop)
___asm(nop)
BRS_ALIGN16()
 BRS_BRANCH(_BrsMainExceptionStartup)
___asm(nop)
___asm(nop)
___asm(nop)
#endif /*BRS_CPU_CORE_AMOUNT>3*/
