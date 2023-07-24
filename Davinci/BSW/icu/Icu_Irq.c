/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Irq.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISRs for all Timers of ICU Driver                       */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas.            */
/* Any warranty is expressly disclaimed and excluded by Renesas, either       */
/* expressed or implied, including but not limited to those for               */
/* non-infringement of intellectual property, merchantability                 */
/* and/or fitness for the particular purpose                                  */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  16-Sep-2015  : Initial Version.
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  06-Jun-2017  : As part of Jira #ARDAABD-1373, Additional timer
 *                         interrupts and external interrupts are added and
 *                         TAUD1 and TAUD2 interrupts have been removed for
 *                         F1KM support.
 * V2.0.2:  25-Sept-2017   As part of Jira #ARDAABD-2425, QAC WARNING has
 *                         been added.
 * V2.0.3:  26-Jun-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3476
 *                            a. QAC warning is added and violations are
 *                               justified.
 *                            b. Copyright information is updated.
 *                         2. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 * V2.0.4:  26-Sep-2018  : Following changes are made:
 *                         1. Add traceability tags in the corresponding place 
 *                            for reqtify improvement.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements:  ICU246, SWS_Icu_00246   */
/* Included for module version information and other types declarations */
#include "Icu.h"
/* Included for declaration of the ISRs */
#include "Icu_Irq.h"
/* Included for declaration of the Icu_CbkNotification() function */
#include "Icu_LLDriver.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ICU_IRQ_C_AR_RELEASE_MAJOR_VERSION    ICU_AR_RELEASE_MAJOR_VERSION_VALUE
#define ICU_IRQ_C_AR_RELEASE_MINOR_VERSION    ICU_AR_RELEASE_MINOR_VERSION_VALUE
#define ICU_IRQ_C_AR_RELEASE_REVISION_VERSION \
                                           ICU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ICU_IRQ_C_SW_MAJOR_VERSION    ICU_SW_MAJOR_VERSION_VALUE
#define ICU_IRQ_C_SW_MINOR_VERSION    ICU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ICU_IRQ_AR_RELEASE_MAJOR_VERSION != ICU_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Icu_Irq.c : Mismatch in Release Major Version"
#endif

#if (ICU_IRQ_AR_RELEASE_MINOR_VERSION != ICU_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Icu_Irq.c : Mismatch in Release Minor Version"
#endif

#if (ICU_IRQ_AR_RELEASE_REVISION_VERSION != \
                                          ICU_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Icu_Irq.c : Mismatch in Release Patch Version"
#endif

#if (ICU_IRQ_SW_MAJOR_VERSION != ICU_IRQ_C_SW_MAJOR_VERSION)
  #error "Icu_Irq.c : Mismatch in Software Major Version"
#endif

#if (ICU_IRQ_SW_MINOR_VERSION != ICU_IRQ_C_SW_MINOR_VERSION)
  #error "Icu_Irq.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include                    */
/*                 preprocessing directive.                                   */
/* Rule          : MISRA-C:2004 Message 0832                                  */
/* Justification : Required for inclusion of ASR version specific,MemMap file */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0862)-2 and               */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : EXTERNAL_INTERRUPT_CHm_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt Service routines for the External
**                        Interrupts where m represents instances of external
**                        interrupts (0 to 23).
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variable(s)   : None
**
** Function(s) invoked  : Icu_ExternalInterruptIsr
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  ICU252, ICU_ESDD_UD_051, SWS_Icu_00252                       */
#if (ICU_EXT_INTP_CH00_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129, ICU_ESDD_UD_049, ICU_ESDD_UD_013            */
#if defined (Os_EXT_INTP_CH00_CAT2_ISR) || defined (EXT_INTP_CH00_CAT2_ISR)
ISR(EXT_INTP_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU252, ICU_ESDD_UD_051, SWS_Icu_00252                       */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH00_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH00);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_EXT_INTP_CH00_ISR_API == STD_ON */

/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
#if (ICU_EXT_INTP_CH01_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH01_CAT2_ISR) || defined (EXT_INTP_CH01_CAT2_ISR)
ISR(EXT_INTP_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH01_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH01);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH01_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH02_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH02_CAT2_ISR) || defined (EXT_INTP_CH02_CAT2_ISR)
ISR(EXT_INTP_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH02_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH02);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH02_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH03_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH03_CAT2_ISR) || defined (EXT_INTP_CH03_CAT2_ISR)
ISR(EXT_INTP_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH03_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH03);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH03_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH04_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH04_CAT2_ISR) || defined (EXT_INTP_CH04_CAT2_ISR)
ISR(EXT_INTP_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH04_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH04);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_EXT_INTP_CH04_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH05_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH05_CAT2_ISR) || defined (EXT_INTP_CH05_CAT2_ISR)
ISR(EXT_INTP_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH05_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH05);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH05_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH06_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH06_CAT2_ISR) || defined (EXT_INTP_CH06_CAT2_ISR)
ISR(EXT_INTP_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH06_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH06);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH06_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH07_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH07_CAT2_ISR) || defined (EXT_INTP_CH07_CAT2_ISR)
ISR(EXT_INTP_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH07_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH07);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH07_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH08_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH08_CAT2_ISR) || defined (EXT_INTP_CH08_CAT2_ISR)
ISR(EXT_INTP_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH08_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH08);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH08_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH09_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH09_CAT2_ISR) || defined (EXT_INTP_CH09_CAT2_ISR)
ISR(EXT_INTP_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH09_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH09);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH09_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH10_CAT2_ISR) || defined (EXT_INTP_CH10_CAT2_ISR)
ISR(EXT_INTP_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH10_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH10);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH10_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH11_CAT2_ISR) || defined (EXT_INTP_CH11_CAT2_ISR)
ISR(EXT_INTP_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH11_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH11);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH11_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH12_CAT2_ISR) || defined (EXT_INTP_CH12_CAT2_ISR)
ISR(EXT_INTP_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH12_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH12);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH12_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH13_CAT2_ISR) || defined (EXT_INTP_CH13_CAT2_ISR)
ISR(EXT_INTP_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH13_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH13);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH13_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH14_CAT2_ISR) || defined (EXT_INTP_CH14_CAT2_ISR)
ISR(EXT_INTP_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH14_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH14);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH14_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH15_CAT2_ISR) || defined (EXT_INTP_CH15_CAT2_ISR)
ISR(EXT_INTP_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH15_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH15);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH15_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH16_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH16_CAT2_ISR) || defined (EXT_INTP_CH16_CAT2_ISR)
ISR(EXT_INTP_CH16_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH16_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH16);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH16_ISR_API == STD_ON */

/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
#if (ICU_EXT_INTP_CH17_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH17_CAT2_ISR) || defined (EXT_INTP_CH17_CAT2_ISR)
ISR(EXT_INTP_CH17_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH17_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH17);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH17_ISR_API == STD_ON */

/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
#if (ICU_EXT_INTP_CH18_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH18_CAT2_ISR) || defined (EXT_INTP_CH18_CAT2_ISR)
ISR(EXT_INTP_CH18_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH18_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH18);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH18_ISR_API == STD_ON */

/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
#if (ICU_EXT_INTP_CH19_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH19_CAT2_ISR) || defined (EXT_INTP_CH19_CAT2_ISR)
ISR(EXT_INTP_CH19_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH19_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH19);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH19_ISR_API == STD_ON */

/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
#if (ICU_EXT_INTP_CH20_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH20_CAT2_ISR) || defined (EXT_INTP_CH20_CAT2_ISR)
ISR(EXT_INTP_CH20_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH20_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH20);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH20_ISR_API == STD_ON */

/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
#if (ICU_EXT_INTP_CH21_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH21_CAT2_ISR) || defined (EXT_INTP_CH21_CAT2_ISR)
ISR(EXT_INTP_CH21_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH21_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH21);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH21_ISR_API == STD_ON */

/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
#if (ICU_EXT_INTP_CH22_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH22_CAT2_ISR) || defined (EXT_INTP_CH22_CAT2_ISR)
ISR(EXT_INTP_CH22_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH22_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH22);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH22_ISR_API == STD_ON */

#if (ICU_EXT_INTP_CH23_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_EXT_INTP_CH23_CAT2_ISR) || defined (EXT_INTP_CH23_CAT2_ISR)
ISR(EXT_INTP_CH23_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_128, ICU_ESDD_UD_049                             */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH23_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXT_INTP_CH23);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_EXT_INTP_CH23_ISR_API == STD_ON */

/*******************************************************************************
** Function Name        : TAUDn_CHm_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the timer TAUDn
**                        Channel m, where n represents the TAUD Units and
**                        m represents channels associated for each Unit.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variable(s)   : None
**
** Function(s) invoked  : Icu_TimerIsr
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
#if (ICU_TAUD0_CH00_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
/* Implements:  ICU_ESDD_UD_129 */
#if defined (Os_TAUD0_CH00_CAT2_ISR) || defined (TAUD0_CH00_CAT2_ISR)
ISR(TAUD0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH00_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH00);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUD0_CH00_ISR_API == STD_ON */

#if (ICU_TAUD0_CH01_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH01_CAT2_ISR) || defined (TAUD0_CH01_CAT2_ISR)
ISR(TAUD0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH01_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH01);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUD0_CH01_ISR_API == STD_ON */

#if (ICU_TAUD0_CH02_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH02_CAT2_ISR) || defined (TAUD0_CH02_CAT2_ISR)
ISR(TAUD0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH02_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH02);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUD0_CH02_ISR_API == STD_ON */

#if (ICU_TAUD0_CH03_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH03_CAT2_ISR) || defined (TAUD0_CH03_CAT2_ISR)
ISR(TAUD0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH03_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH03);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUD0_CH03_ISR_API == STD_ON */

#if (ICU_TAUD0_CH04_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH04_CAT2_ISR) || defined (TAUD0_CH04_CAT2_ISR)
ISR(TAUD0_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH04_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH04);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH04_ISR_API == STD_ON */

#if (ICU_TAUD0_CH05_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH05_CAT2_ISR) || defined (TAUD0_CH05_CAT2_ISR)
ISR(TAUD0_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH05_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH05);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH05_ISR_API == STD_ON */

#if (ICU_TAUD0_CH06_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH06_CAT2_ISR) || defined (TAUD0_CH06_CAT2_ISR)
ISR(TAUD0_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH06_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH06);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH06_ISR_API == STD_ON */

#if (ICU_TAUD0_CH07_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH07_CAT2_ISR) || defined (TAUD0_CH07_CAT2_ISR)
ISR(TAUD0_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH07_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH07);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH07_ISR_API == STD_ON */

#if (ICU_TAUD0_CH08_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH08_CAT2_ISR) || defined (TAUD0_CH08_CAT2_ISR)
ISR(TAUD0_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH08_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH08);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH08_ISR_API == STD_ON */

#if (ICU_TAUD0_CH09_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH09_CAT2_ISR) || defined (TAUD0_CH09_CAT2_ISR)
ISR(TAUD0_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH09_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH09);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH09_ISR_API == STD_ON */

#if (ICU_TAUD0_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH10_CAT2_ISR) || defined (TAUD0_CH10_CAT2_ISR)
ISR(TAUD0_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH10);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH10_ISR_API == STD_ON */

#if (ICU_TAUD0_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH11_CAT2_ISR) || defined (TAUD0_CH11_CAT2_ISR)
ISR(TAUD0_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH11);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH11_ISR_API == STD_ON */

#if (ICU_TAUD0_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH12_CAT2_ISR) || defined (TAUD0_CH12_CAT2_ISR)
ISR(TAUD0_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH12);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH12_ISR_API == STD_ON */

#if (ICU_TAUD0_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH13_CAT2_ISR) || defined (TAUD0_CH13_CAT2_ISR)
ISR(TAUD0_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH13);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUD0_CH13_ISR_API == STD_ON */

#if (ICU_TAUD0_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH14_CAT2_ISR) || defined (TAUD0_CH14_CAT2_ISR)
ISR(TAUD0_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH14);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUD0_CH14_ISR_API == STD_ON */

#if (ICU_TAUD0_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH15_CAT2_ISR) || defined (TAUD0_CH15_CAT2_ISR)
ISR(TAUD0_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUD0_CH15);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUD0_CH15_ISR_API == STD_ON */

/*******************************************************************************
** Function Name        : TAUBn_CHm_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the timer TAUBn
**                        Channel m, where n represents the TAUB Units and
**                        m represents channels associated for each Unit.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variable(s)   : None
**
** Function(s) invoked  : Icu_TimerIsr
**
** Registers Used       : None
**
*******************************************************************************/

#if (ICU_TAUB0_CH00_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH00_CAT2_ISR) || defined (TAUB0_CH00_CAT2_ISR)
ISR(TAUB0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH00_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH00);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUB0_CH00_ISR_API == STD_ON */

#if (ICU_TAUB0_CH01_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH01_CAT2_ISR) || defined (TAUB0_CH01_CAT2_ISR)
ISR(TAUB0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH01_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH01);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH01_ISR_API == STD_ON */

#if (ICU_TAUB0_CH02_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH02_CAT2_ISR) || defined (TAUB0_CH02_CAT2_ISR)
ISR(TAUB0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH02_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH02);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUB0_CH02_ISR_API == STD_ON */

#if (ICU_TAUB0_CH03_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH03_CAT2_ISR) || defined (TAUB0_CH03_CAT2_ISR)
ISR(TAUB0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH03_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH03);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH03_ISR_API == STD_ON */

#if (ICU_TAUB0_CH04_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH04_CAT2_ISR) || defined (TAUB0_CH04_CAT2_ISR)
ISR(TAUB0_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH04_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH04);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH04_ISR_API == STD_ON */

#if (ICU_TAUB0_CH05_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH05_CAT2_ISR) || defined (TAUB0_CH05_CAT2_ISR)
ISR(TAUB0_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH05_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH05);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH05_ISR_API == STD_ON */

#if (ICU_TAUB0_CH06_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH06_CAT2_ISR) || defined (TAUB0_CH06_CAT2_ISR)
ISR(TAUB0_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH06_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH06);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH06_ISR_API == STD_ON */

#if (ICU_TAUB0_CH07_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH07_CAT2_ISR) || defined (TAUB0_CH07_CAT2_ISR)
ISR(TAUB0_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH07_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH07);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH07_ISR_API == STD_ON */

#if (ICU_TAUB0_CH08_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH08_CAT2_ISR) || defined (TAUB0_CH08_CAT2_ISR)
ISR(TAUB0_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH08_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH08);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH08_ISR_API == STD_ON */

#if (ICU_TAUB0_CH09_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH09_CAT2_ISR) || defined (TAUB0_CH09_CAT2_ISR)
ISR(TAUB0_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH09_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH09);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH09_ISR_API == STD_ON */

#if (ICU_TAUB0_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH10_CAT2_ISR) || defined (TAUB0_CH10_CAT2_ISR)
ISR(TAUB0_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH10);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH10_ISR_API == STD_ON */

#if (ICU_TAUB0_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH11_CAT2_ISR) || defined (TAUB0_CH11_CAT2_ISR)
ISR(TAUB0_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH11);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH11_ISR_API == STD_ON */

#if (ICU_TAUB0_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH12_CAT2_ISR) || defined (TAUB0_CH12_CAT2_ISR)
ISR(TAUB0_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH12);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH12_ISR_API == STD_ON */

#if (ICU_TAUB0_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH13_CAT2_ISR) || defined (TAUB0_CH13_CAT2_ISR)
ISR(TAUB0_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH13);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH13_ISR_API == STD_ON */

#if (ICU_TAUB0_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH14_CAT2_ISR) || defined (TAUB0_CH14_CAT2_ISR)
ISR(TAUB0_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH14);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH14_ISR_API == STD_ON */

#if (ICU_TAUB0_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH15_CAT2_ISR) || defined (TAUB0_CH15_CAT2_ISR)
ISR(TAUB0_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB0_CH15);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB0_CH15_ISR_API == STD_ON */

#if (ICU_TAUB1_CH00_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH00_CAT2_ISR) || defined (TAUB1_CH00_CAT2_ISR)
ISR(TAUB1_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH00_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH00);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH00_ISR_API == STD_ON */

#if (ICU_TAUB1_CH01_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH01_CAT2_ISR) || defined (TAUB1_CH01_CAT2_ISR)
ISR(TAUB1_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH01_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH01);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH01_ISR_API == STD_ON */

#if (ICU_TAUB1_CH02_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH02_CAT2_ISR) || defined (TAUB1_CH02_CAT2_ISR)
ISR(TAUB1_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH02_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH02);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH02_ISR_API == STD_ON */

#if (ICU_TAUB1_CH03_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH03_CAT2_ISR) || defined (TAUB1_CH03_CAT2_ISR)
ISR(TAUB1_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH03_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH03);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH03_ISR_API == STD_ON */

#if (ICU_TAUB1_CH04_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH04_CAT2_ISR) || defined (TAUB1_CH04_CAT2_ISR)
ISR(TAUB1_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH04_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH04);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH04_ISR_API == STD_ON */

#if (ICU_TAUB1_CH05_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH05_CAT2_ISR) || defined (TAUB1_CH05_CAT2_ISR)
ISR(TAUB1_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH05_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH05);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH05_ISR_API == STD_ON */

#if (ICU_TAUB1_CH06_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH06_CAT2_ISR) || defined (TAUB1_CH06_CAT2_ISR)
ISR(TAUB1_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH06_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH06);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH06_ISR_API == STD_ON */

#if (ICU_TAUB1_CH07_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH07_CAT2_ISR) || defined (TAUB1_CH07_CAT2_ISR)
ISR(TAUB1_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH07_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH07);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH07_ISR_API == STD_ON */

#if (ICU_TAUB1_CH08_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH08_CAT2_ISR) || defined (TAUB1_CH08_CAT2_ISR)
ISR(TAUB1_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH08_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH08);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH08_ISR_API == STD_ON */

#if (ICU_TAUB1_CH09_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH09_CAT2_ISR) || defined (TAUB1_CH09_CAT2_ISR)
ISR(TAUB1_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH09_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH09);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH09_ISR_API == STD_ON */

#if (ICU_TAUB1_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH10_CAT2_ISR) || defined (TAUB1_CH10_CAT2_ISR)
ISR(TAUB1_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH10);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH10_ISR_API == STD_ON */

#if (ICU_TAUB1_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH11_CAT2_ISR) || defined (TAUB1_CH11_CAT2_ISR)
ISR(TAUB1_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH11);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH11_ISR_API == STD_ON */

#if (ICU_TAUB1_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH12_CAT2_ISR) || defined (TAUB1_CH12_CAT2_ISR)
ISR(TAUB1_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH12);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH12_ISR_API == STD_ON */

#if (ICU_TAUB1_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH13_CAT2_ISR) || defined (TAUB1_CH13_CAT2_ISR)
ISR(TAUB1_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH13);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH13_ISR_API == STD_ON */

#if (ICU_TAUB1_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH14_CAT2_ISR) || defined (TAUB1_CH14_CAT2_ISR)
ISR(TAUB1_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH14);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH14_ISR_API == STD_ON */

#if (ICU_TAUB1_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH15_CAT2_ISR) || defined (TAUB1_CH15_CAT2_ISR)
ISR(TAUB1_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH15);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUB1_CH15_ISR_API == STD_ON */

/*******************************************************************************
** Function Name        : TAUJn_CHm_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the timer TAUJn
**                        Channel m, where n represents the TAUJ Units and
**                        m represents channels associated for each Unit.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variable(s)   : None
**
** Function(s) invoked  : Icu_TimerIsr
**
** Registers Used       : None
**
*******************************************************************************/

#if (ICU_TAUJ0_CH00_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH00_CAT2_ISR) || defined (TAUJ0_CH00_CAT2_ISR)
ISR(TAUJ0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ0_CH00_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ0_CH00);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUJ0_CH00_ISR_API == STD_ON */

#if (ICU_TAUJ0_CH01_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH01_CAT2_ISR) || defined (TAUJ0_CH01_CAT2_ISR)
ISR(TAUJ0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ0_CH01_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ0_CH01);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUJ0_CH01_ISR_API == STD_ON */

#if (ICU_TAUJ0_CH02_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH02_CAT2_ISR) || defined (TAUJ0_CH02_CAT2_ISR)
ISR(TAUJ0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ0_CH02_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ0_CH02);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ0_CH02_ISR_API == STD_ON */

#if (ICU_TAUJ0_CH03_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH03_CAT2_ISR) || defined (TAUJ0_CH03_CAT2_ISR)
ISR(TAUJ0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ0_CH03_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ0_CH03);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUJ0_CH03_ISR_API == STD_ON */

#if (ICU_TAUJ1_CH00_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH00_CAT2_ISR) || defined (TAUJ1_CH00_CAT2_ISR)
ISR(TAUJ1_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ1_CH00_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ1_CH00);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ1_CH00_ISR_API == STD_ON */

#if (ICU_TAUJ1_CH01_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH01_CAT2_ISR) || defined (TAUJ1_CH01_CAT2_ISR)
ISR(TAUJ1_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ1_CH01_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ1_CH01);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUJ1_CH01_ISR_API == STD_ON */

#if (ICU_TAUJ1_CH02_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH02_CAT2_ISR) || defined (TAUJ1_CH02_CAT2_ISR)
ISR(TAUJ1_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ1_CH02_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ1_CH02);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUJ1_CH02_ISR_API == STD_ON */

#if (ICU_TAUJ1_CH03_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH03_CAT2_ISR) || defined (TAUJ1_CH03_CAT2_ISR)
ISR(TAUJ1_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ1_CH03_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ1_CH03);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* End of ICU_TAUJ1_CH03_ISR_API == STD_ON */

#if (ICU_TAUJ2_CH00_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH00_CAT2_ISR) || defined (TAUJ2_CH00_CAT2_ISR)
ISR(TAUJ2_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ2_CH00_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ2_CH00);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ2_CH00_ISR_API == STD_ON */

#if (ICU_TAUJ2_CH01_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH01_CAT2_ISR) || defined (TAUJ2_CH01_CAT2_ISR)
ISR(TAUJ2_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ2_CH01_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ2_CH01);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ2_CH01_ISR_API == STD_ON */

#if (ICU_TAUJ2_CH02_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH02_CAT2_ISR) || defined (TAUJ2_CH02_CAT2_ISR)
ISR(TAUJ2_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ2_CH02_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ2_CH02);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ2_CH02_ISR_API == STD_ON */

#if (ICU_TAUJ2_CH03_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH03_CAT2_ISR) || defined (TAUJ2_CH03_CAT2_ISR)
ISR(TAUJ2_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ2_CH03_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ2_CH03);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ2_CH03_ISR_API == STD_ON */

#if (ICU_TAUJ3_CH00_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH00_CAT2_ISR) || defined (TAUJ3_CH00_CAT2_ISR)
ISR(TAUJ3_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ3_CH00_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ3_CH00);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ3_CH00_ISR_API == STD_ON */

#if (ICU_TAUJ3_CH01_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH01_CAT2_ISR) || defined (TAUJ3_CH01_CAT2_ISR)
ISR(TAUJ3_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ3_CH01_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ3_CH01);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ3_CH01_ISR_API == STD_ON */

#if (ICU_TAUJ3_CH02_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH02_CAT2_ISR) || defined (TAUJ3_CH02_CAT2_ISR)
ISR(TAUJ3_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ3_CH02_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ3_CH02);
}

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif /* End of ICU_TAUJ3_CH02_ISR_API == STD_ON */

#if (ICU_TAUJ3_CH03_ISR_API == STD_ON)
#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH03_CAT2_ISR) || defined (TAUJ3_CH03_CAT2_ISR)
ISR(TAUJ3_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements:  ICU_ESDD_UD_050, ICU_ESDD_UD_048                              */
_INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ3_CH03_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ3_CH03);
}

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0862)-2 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0862)-2 */
#endif /* End of ICU_TAUJ3_CH03_ISR_API == STD_ON */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
