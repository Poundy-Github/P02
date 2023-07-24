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
 *  \addtogroup Os_Hal_Trap
 *  \{
 *
 *  \file       Os_Hal_Trap.asm
 *  \brief      Contains the implementation of the trap module.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */



/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* Os module dependencies */
#include "Os_Cfg.h"

/* Os HAL dependencies */
#include "Os_Hal_Compiler_ASM.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
# define OS_HAL_PSW_NP_MSK                           (0x00000080)


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


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ECCTST_G3KH_FEINT_ISR()
 **********************************************************************************************************************/
  /*!
   * \internal
   *  - #10 Load address of core handler into FEPC.
   *  - #20 Prepare PSW - Clear NP flag.
   * \endinternal
   */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(ECCTST_G3KH_FEINT_ISR)
 OS_HAL_ASM_LABEL(ECCTST_G3KH_FEINT_ISR)
 OS_HAL_ASM_EXTERN(_EccTst_FETINT_Notification)
 /* #10 Store interrupted context to stack. */
  OS_HAL_ASM_PUSHSP(r1,r2)
  OS_HAL_ASM_PUSHSP(r4,r19)
  OS_HAL_ASM_PUSHSP(r30,r31)
  stsr    2, r11, 0          /* store content of FEPC to r11 */
  stsr    3, r12, 0          /* store content of FEPSW to r12 */
  OS_HAL_ASM_PUSHSP(r11,r12)
  jarl    _EccTst_FETINT_Notification, lp
  OS_HAL_ASM_POPSP(r11,r12)
  ldsr    r11, 2, 0         /* load r11 to FEPC */
  ldsr    r12, 3, 0         /* load r11 to FEPSW */
  OS_HAL_ASM_POPSP(r30,r31)
  OS_HAL_ASM_POPSP(r4,r19)
  OS_HAL_ASM_POPSP(r1,r2)
  feret

 OS_HAL_ASM_END_OF_FILE()

/*!
 * \}
 */
 
/***********************************************************************************************************************
 *  ECCTST_G3KH_FEINT_ISR()
 **********************************************************************************************************************/
  /*!
   * \internal
   *  - #10 Load address of core handler into FEPC.
   *  - #20 Prepare PSW - Clear NP flag.
   * \endinternal
   */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(ECCTST_G3KH_SYSERR_ISR)
 OS_HAL_ASM_LABEL(ECCTST_G3KH_SYSERR_ISR)
 OS_HAL_ASM_EXTERN(_EccTst_SYSERR_Notification)
 /* #10 Store interrupted context to stack. */
  OS_HAL_ASM_PUSHSP(r1,r2)
  OS_HAL_ASM_PUSHSP(r4,r19)
  OS_HAL_ASM_PUSHSP(r30,r31)
  stsr    2, r11, 0          /* store content of FEPC to r11 */
  stsr    3, r12, 0          /* store content of FEPSW to r12 */
  OS_HAL_ASM_PUSHSP(r11,r12)
  jarl    _EccTst_SYSERR_Notification, lp
  OS_HAL_ASM_POPSP(r11,r12)
  ldsr    r11, 2, 0         /* load r11 to FEPC */
  ldsr    r12, 3, 0         /* load r11 to FEPSW */
  OS_HAL_ASM_POPSP(r30,r31)
  OS_HAL_ASM_POPSP(r4,r19)
  OS_HAL_ASM_POPSP(r1,r2)
  feret

 OS_HAL_ASM_END_OF_FILE()

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Trap.asm
 **********************************************************************************************************************/

