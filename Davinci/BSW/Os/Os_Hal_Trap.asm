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

#define OS_HAL_TRAP_SOURCE

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
 *  Os_Hal_SystemTrap()
 **********************************************************************************************************************/
/*!
 * \internal
 *  - #10 Trigger trap Os_Hal_TrapHandler.
 * \endinternal
 */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(Os_Hal_SystemTrap)
 OS_HAL_ASM_LABEL(Os_Hal_SystemTrap)
  trap    1


/***********************************************************************************************************************
 *  Os_Hal_TrapHandler()
 **********************************************************************************************************************/
  /*!
   * \internal
   *  - #10 Load address of core handler into EIPC.
   *  - #20 Prepare PSW - Clear EP flag.
   * \endinternal
   */
 OS_HAL_ASM_SECTION_OS_CODE()
 OS_HAL_ASM_ALIGN4()
 OS_HAL_ASM_GLOBAL(Os_Hal_TrapHandler)
 OS_HAL_ASM_LABEL(Os_Hal_TrapHandler)
 OS_HAL_ASM_EXTERN(_Os_TrapHandler)
; #10 Load address of core handler into EIPC.
  OS_HAL_ASM_MOV_LABEL(Os_TrapHandler, r11)
  ldsr    r11, 0, 0          /* load r11 to EIPC */
; #20 Prepare PSW - Clear EP flag.
  stsr    5, r11, 0          /* store PSW to r11 */
  mov     OS_HAL_PSW_EP_MSK, r12
  not     r12, r12
  and     r12, r11
  ldsr    r11, 1, 0          /* load r11 to EIPSW */
  eiret

 OS_HAL_ASM_END_OF_FILE()

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Trap.asm
 **********************************************************************************************************************/

