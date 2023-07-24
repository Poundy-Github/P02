/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Irq.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISRs for all Timers of PWM Driver                       */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
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
 * V1.0.0:  10-Sep-2015  : Initial Version
 * V2.0.0:  19-Oct-2016  : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                            ASR 4.0.3.
 * V2.0.1:  17-Mar-2017  : Update for ARDAABD-827 Traceability ticket
 * V2.0.2:  17-May-2017  : 1. As part of JIRA ARDAABD-1726 added ISRs for TAUJ3
 *                         2. Updated Copyright(c).
 *                         3. Re-entrancy of ISRs are changed to Non Reentrant
 * V2.1.0:  11-Jul-2017  : As part of JIRA ARDAABD-1726, following changes are
 *                         made:
 *                         1. Added ISRs PWM_INTPWGAG0m_ISR (where m=0,1,2) for
 *                            PWM Diag channel groups.
 *                         2. Handled QAC warnings.
 * V2.1.1:  21-Sep-2017  : Following changes are made:
 *                         1. As part of ARDAABD-2476,
 *                            a. Array names are corrected based on the data
 *                              type names as per requirement MCAL052.
 *                         2. As part of ARDAABD-2425,
 *                            a. Handled QAC level 2 warnings.
 * V2.1.2:  18-Jun-2018  : As part of jira ticket ARDAABD-3839, following
 *                         changes are made:
 *                         1. Updated traceability tags.
 *                         2. Updated Copyright(c) information.
 */
/******************************************************************************/
/* Implements:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0018 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Pwm.h inclusion and macro definitions */
/* Implements:  PWM075g                                                       */
/* Implements:  SWS_Pwm_70075                                                 */
#include "Pwm.h"
/* Included for declaration of the ISRs */
#include "Pwm_Irq.h"
/* Included for declaration of the Pwm_HW_Callback() function */
#include "Pwm_LLDriver.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_IRQ_C_AR_RELEASE_MAJOR_VERSION    PWM_AR_RELEASE_MAJOR_VERSION_VALUE
#define PWM_IRQ_C_AR_RELEASE_MINOR_VERSION    PWM_AR_RELEASE_MINOR_VERSION_VALUE
#define PWM_IRQ_C_AR_RELEASE_REVISION_VERSION \
                                           PWM_AR_RELEASE_REVISION_VERSION_VALUE

#elif (PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_IRQ_C_AR_RELEASE_MAJOR_VERSION    PWM_AR_RELEASE_MAJOR_VERSION_VALUE
#define PWM_IRQ_C_AR_RELEASE_MINOR_VERSION    PWM_AR_RELEASE_MINOR_VERSION_VALUE
#define PWM_IRQ_C_AR_RELEASE_REVISION_VERSION \
                                           PWM_AR_RELEASE_REVISION_VERSION_VALUE
#endif

/* Module software version information */
#define PWM_IRQ_C_SW_MAJOR_VERSION    PWM_SW_MAJOR_VERSION_VALUE
#define PWM_IRQ_C_SW_MINOR_VERSION    PWM_SW_MINOR_VERSION_VALUE

/* Implements:  EAAR_PN0034_FR_0055                                           */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_IRQ_AR_RELEASE_MAJOR_VERSION != PWM_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Pwm_Irq.c : Mismatch in Release Major Version"
#endif

#if (PWM_IRQ_AR_RELEASE_MINOR_VERSION != PWM_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Pwm_Irq.c : Mismatch in Release Minor Version"
#endif

#if (PWM_IRQ_AR_RELEASE_REVISION_VERSION != \
                                          PWM_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Pwm_Irq.c : Mismatch in Release Patch Version"
#endif

#if (PWM_IRQ_SW_MAJOR_VERSION != PWM_IRQ_C_SW_MAJOR_VERSION)
  #error "Pwm_Irq.c : Mismatch in Software Major Version"
#endif

#if (PWM_IRQ_SW_MINOR_VERSION != PWM_IRQ_C_SW_MINOR_VERSION)
  #error "Pwm_Irq.c : Mismatch in Software Minor Version"
#endif

/* Implements:  EAAR_PN0034_NR_0026                                           */
/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:0890) This #include #ifdef refers to a macro that has   */
/*                 been #undef'd in a previous #if block.                     */
/* Rule          : NA                                                         */
/* Justification : This is done for proper memory mapping of code and data    */
/*                 for PWM.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:0890)-1 and              */
/*                 END Msg(2:0890)-1 tags in the code.                        */
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
/* 3. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type.                                           */
/* Rule          : NA                                                         */
/* Justification : The result of this cast is implicitly converted            */
/*                 to another type.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:3892)-3 and              */
/*                 END Msg(2:3892)-3 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_014, PWM_ESDD_UD_066                              */
/* Implements:  PWM_ESDD_UD_065                                               */
/* Implements:  PWM_ESDD_UD_121                                               */
/* Implements:  PWM_ESDD_UD_122                                               */
/* Implements:  PWM_ESDD_UD_157                                               */
/* Implements:  EAAR_PN0066_FR_0012                                           */

/* Below ISRs will be checked only if PWM_TAU_UNIT_USED is STD_ON */
#if (PWM_TAU_UNIT_USED == STD_ON)
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
** Re-entrancy          : Non Reentrant
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
** Function(s) invoked  : Pwm_HW_Callback
**
** Registers Used       : None
**
*******************************************************************************/
#if (PWM_TAUD0_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0890)-1 */
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"
/* END Msg(2:0890)-1 */

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH00_CAT2_ISR) || defined (TAUD0_CH00_CAT2_ISR)
ISR(TAUD0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH00_ISR_API == STD_ON */

#if (PWM_TAUD0_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH01_CAT2_ISR) || defined (TAUD0_CH01_CAT2_ISR)
ISR(TAUD0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH01_ISR_API == STD_ON */

#if (PWM_TAUD0_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH02_CAT2_ISR) || defined (TAUD0_CH02_CAT2_ISR)
ISR(TAUD0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH02_ISR_API == STD_ON */

#if (PWM_TAUD0_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH03_CAT2_ISR) || defined (TAUD0_CH03_CAT2_ISR)
ISR(TAUD0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH03_ISR_API == STD_ON */

#if (PWM_TAUD0_CH04_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH04_CAT2_ISR) || defined (TAUD0_CH04_CAT2_ISR)
ISR(TAUD0_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH04_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH04);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH04_ISR_API == STD_ON */

#if (PWM_TAUD0_CH05_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH05_CAT2_ISR) || defined (TAUD0_CH05_CAT2_ISR)
ISR(TAUD0_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH05_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH05);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH05_ISR_API == STD_ON */

#if (PWM_TAUD0_CH06_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH06_CAT2_ISR) || defined (TAUD0_CH06_CAT2_ISR)
ISR(TAUD0_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH06_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH06);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH06_ISR_API == STD_ON */

#if (PWM_TAUD0_CH07_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH07_CAT2_ISR) || defined (TAUD0_CH07_CAT2_ISR)
ISR(TAUD0_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH07_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH07);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH07_ISR_API == STD_ON */

#if (PWM_TAUD0_CH08_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH08_CAT2_ISR) || defined (TAUD0_CH08_CAT2_ISR)
ISR(TAUD0_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH08_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH08);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH08_ISR_API == STD_ON */

#if (PWM_TAUD0_CH09_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH09_CAT2_ISR) || defined (TAUD0_CH09_CAT2_ISR)
ISR(TAUD0_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH09_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH09);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH09_ISR_API == STD_ON */

#if (PWM_TAUD0_CH10_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH10_CAT2_ISR) || defined (TAUD0_CH10_CAT2_ISR)
ISR(TAUD0_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH10_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH10);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH10_ISR_API == STD_ON */

#if (PWM_TAUD0_CH11_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH11_CAT2_ISR) || defined (TAUD0_CH11_CAT2_ISR)
ISR(TAUD0_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH11_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH11);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH11_ISR_API == STD_ON */

#if (PWM_TAUD0_CH12_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0890)-1 */
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"
/* END Msg(2:0890)-1 */

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH12_CAT2_ISR) || defined (TAUD0_CH12_CAT2_ISR)
ISR(TAUD0_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH12_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH12);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH12_ISR_API == STD_ON */

#if (PWM_TAUD0_CH13_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH13_CAT2_ISR) || defined (TAUD0_CH13_CAT2_ISR)
ISR(TAUD0_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH13_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH13);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH13_ISR_API == STD_ON */

#if (PWM_TAUD0_CH14_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH14_CAT2_ISR) || defined (TAUD0_CH14_CAT2_ISR)
ISR(TAUD0_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH14_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH14);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH14_ISR_API == STD_ON */

#if (PWM_TAUD0_CH15_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH15_CAT2_ISR) || defined (TAUD0_CH15_CAT2_ISR)
ISR(TAUD0_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH15_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD0_CH15);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD0_CH15_ISR_API == STD_ON */

#if (PWM_TAUD1_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH00_CAT2_ISR) || defined (TAUD1_CH00_CAT2_ISR)
ISR(TAUD1_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH00_ISR_API == STD_ON */

#if (PWM_TAUD1_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH01_CAT2_ISR) || defined (TAUD1_CH01_CAT2_ISR)
ISR(TAUD1_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH01_ISR_API == STD_ON */

#if (PWM_TAUD1_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH02_CAT2_ISR) || defined (TAUD1_CH02_CAT2_ISR)
ISR(TAUD1_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH02_ISR_API == STD_ON */

#if (PWM_TAUD1_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH03_CAT2_ISR) || defined (TAUD1_CH03_CAT2_ISR)
ISR(TAUD1_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH03_ISR_API == STD_ON */

#if (PWM_TAUD1_CH04_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH04_CAT2_ISR) || defined (TAUD1_CH04_CAT2_ISR)
ISR(TAUD1_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH04_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH04);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH04_ISR_API == STD_ON */

#if (PWM_TAUD1_CH05_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH05_CAT2_ISR) || defined (TAUD1_CH05_CAT2_ISR)
ISR(TAUD1_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH05_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH05);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH05_ISR_API == STD_ON */

#if (PWM_TAUD1_CH06_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH06_CAT2_ISR) || defined (TAUD1_CH06_CAT2_ISR)
ISR(TAUD1_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH06_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH06);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH06_ISR_API == STD_ON */

#if (PWM_TAUD1_CH07_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH07_CAT2_ISR) || defined (TAUD1_CH07_CAT2_ISR)
ISR(TAUD1_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH07_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH07);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH07_ISR_API == STD_ON */

#if (PWM_TAUD1_CH08_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH08_CAT2_ISR) || defined (TAUD1_CH08_CAT2_ISR)
ISR(TAUD1_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH08_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH08);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH08_ISR_API == STD_ON */

#if (PWM_TAUD1_CH09_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH09_CAT2_ISR) || defined (TAUD1_CH09_CAT2_ISR)
ISR(TAUD1_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH09_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH09);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH09_ISR_API == STD_ON */

#if (PWM_TAUD1_CH10_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH10_CAT2_ISR) || defined (TAUD1_CH10_CAT2_ISR)
ISR(TAUD1_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH10_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH10);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH10_ISR_API == STD_ON */

#if (PWM_TAUD1_CH11_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH11_CAT2_ISR) || defined (TAUD1_CH11_CAT2_ISR)
ISR(TAUD1_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH11_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH11);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH11_ISR_API == STD_ON */

#if (PWM_TAUD1_CH12_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH12_CAT2_ISR) || defined (TAUD1_CH12_CAT2_ISR)
ISR(TAUD1_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH12_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH12);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH12_ISR_API == STD_ON */

#if (PWM_TAUD1_CH13_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH13_CAT2_ISR) || defined (TAUD1_CH13_CAT2_ISR)
ISR(TAUD1_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH13_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH13);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH13_ISR_API == STD_ON */

#if (PWM_TAUD1_CH14_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH14_CAT2_ISR) || defined (TAUD1_CH14_CAT2_ISR)
ISR(TAUD1_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH14_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH14);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH14_ISR_API == STD_ON */

#if (PWM_TAUD1_CH15_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH15_CAT2_ISR) || defined (TAUD1_CH15_CAT2_ISR)
ISR(TAUD1_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH15_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD1_CH15);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD1_CH15_ISR_API == STD_ON */

#if (PWM_TAUD2_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH00_CAT2_ISR) || defined (TAUD2_CH00_CAT2_ISR)
ISR(TAUD2_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH00_ISR_API == STD_ON */

#if (PWM_TAUD2_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH01_CAT2_ISR) || defined (TAUD2_CH01_CAT2_ISR)
ISR(TAUD2_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH01_ISR_API == STD_ON */

#if (PWM_TAUD2_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH02_CAT2_ISR) || defined (TAUD2_CH02_CAT2_ISR)
ISR(TAUD2_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH02_ISR_API == STD_ON */

#if (PWM_TAUD2_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH03_CAT2_ISR) || defined (TAUD2_CH03_CAT2_ISR)
ISR(TAUD2_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH03_ISR_API == STD_ON */

#if (PWM_TAUD2_CH04_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH04_CAT2_ISR) || defined (TAUD2_CH04_CAT2_ISR)
ISR(TAUD2_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH04_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH04);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH04_ISR_API == STD_ON */

#if (PWM_TAUD2_CH05_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH05_CAT2_ISR) || defined (TAUD2_CH05_CAT2_ISR)
ISR(TAUD2_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH05_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH05);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH05_ISR_API == STD_ON */

#if (PWM_TAUD2_CH06_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH06_CAT2_ISR) || defined (TAUD2_CH06_CAT2_ISR)
ISR(TAUD2_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH06_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH06);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH06_ISR_API == STD_ON */

#if (PWM_TAUD2_CH07_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH07_CAT2_ISR) || defined (TAUD2_CH07_CAT2_ISR)
ISR(TAUD2_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH07_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH07);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH07_ISR_API == STD_ON */

#if (PWM_TAUD2_CH08_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH08_CAT2_ISR) || defined (TAUD2_CH08_CAT2_ISR)
ISR(TAUD2_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH08_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH08);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH08_ISR_API == STD_ON */

#if (PWM_TAUD2_CH09_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH09_CAT2_ISR) || defined (TAUD2_CH09_CAT2_ISR)
ISR(TAUD2_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH09_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH09);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH09_ISR_API == STD_ON */

#if (PWM_TAUD2_CH10_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH10_CAT2_ISR) || defined (TAUD2_CH10_CAT2_ISR)
ISR(TAUD2_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH10_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH10);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH10_ISR_API == STD_ON */

#if (PWM_TAUD2_CH11_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH11_CAT2_ISR) || defined (TAUD2_CH11_CAT2_ISR)
ISR(TAUD2_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH11_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH11);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH11_ISR_API == STD_ON */

#if (PWM_TAUD2_CH12_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH12_CAT2_ISR) || defined (TAUD2_CH12_CAT2_ISR)
ISR(TAUD2_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH12_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH12);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH12_ISR_API == STD_ON */

#if (PWM_TAUD2_CH13_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH13_CAT2_ISR) || defined (TAUD2_CH13_CAT2_ISR)
ISR(TAUD2_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH13_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH13);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH13_ISR_API == STD_ON */

#if (PWM_TAUD2_CH14_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH14_CAT2_ISR) || defined (TAUD2_CH14_CAT2_ISR)
ISR(TAUD2_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH14_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH14);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH14_ISR_API == STD_ON */

#if (PWM_TAUD2_CH15_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH15_CAT2_ISR) || defined (TAUD2_CH15_CAT2_ISR)
ISR(TAUD2_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH15_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUD2_CH15);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUD2_CH15_ISR_API == STD_ON */
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
** Re-entrancy          : Non Reentrant
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
** Function(s) invoked  : Pwm_HW_Callback
**
** Registers Used       : None
**
*******************************************************************************/
#if (PWM_TAUB0_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* QAC Warning: START Msg(2:0890)-1 */
/* Functionality related to R4.0 */
#include "MemMap.h"
/* END Msg(2:0890)-1 */
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH00_CAT2_ISR) || defined (TAUB0_CH00_CAT2_ISR)
ISR(TAUB0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH00_ISR_API == STD_ON */

#if (PWM_TAUB0_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH01_CAT2_ISR) || defined (TAUB0_CH01_CAT2_ISR)
ISR(TAUB0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH01_ISR_API == STD_ON */

#if (PWM_TAUB0_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH02_CAT2_ISR) || defined (TAUB0_CH02_CAT2_ISR)
ISR(TAUB0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH02_ISR_API == STD_ON */

#if (PWM_TAUB0_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH03_CAT2_ISR) || defined (TAUB0_CH03_CAT2_ISR)
ISR(TAUB0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH03_ISR_API == STD_ON */

#if (PWM_TAUB0_CH04_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH04_CAT2_ISR) || defined (TAUB0_CH04_CAT2_ISR)
ISR(TAUB0_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH04_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH04);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH04_ISR_API == STD_ON */

#if (PWM_TAUB0_CH05_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH05_CAT2_ISR) || defined (TAUB0_CH05_CAT2_ISR)
ISR(TAUB0_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH05_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH05);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH05_ISR_API == STD_ON */

#if (PWM_TAUB0_CH06_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH06_CAT2_ISR) || defined (TAUB0_CH06_CAT2_ISR)
ISR(TAUB0_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH06_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH06);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH06_ISR_API == STD_ON */

#if (PWM_TAUB0_CH07_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH07_CAT2_ISR) || defined (TAUB0_CH07_CAT2_ISR)
ISR(TAUB0_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH07_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH07);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH07_ISR_API == STD_ON */

#if (PWM_TAUB0_CH08_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH08_CAT2_ISR) || defined (TAUB0_CH08_CAT2_ISR)
ISR(TAUB0_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH08_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH08);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH08_ISR_API == STD_ON */

#if (PWM_TAUB0_CH09_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH09_CAT2_ISR) || defined (TAUB0_CH09_CAT2_ISR)
ISR(TAUB0_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH09_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH09);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH09_ISR_API == STD_ON */

#if (PWM_TAUB0_CH10_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH10_CAT2_ISR) || defined (TAUB0_CH10_CAT2_ISR)
ISR(TAUB0_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH10_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH10);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH10_ISR_API == STD_ON */

#if (PWM_TAUB0_CH11_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH11_CAT2_ISR) || defined (TAUB0_CH11_CAT2_ISR)
ISR(TAUB0_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH11_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH11);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH11_ISR_API == STD_ON */

#if (PWM_TAUB0_CH12_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH12_CAT2_ISR) || defined (TAUB0_CH12_CAT2_ISR)
ISR(TAUB0_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH12_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH12);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH12_ISR_API == STD_ON */

#if (PWM_TAUB0_CH13_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH13_CAT2_ISR) || defined (TAUB0_CH13_CAT2_ISR)
ISR(TAUB0_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH13_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH13);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH13_ISR_API == STD_ON */

#if (PWM_TAUB0_CH14_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH14_CAT2_ISR) || defined (TAUB0_CH14_CAT2_ISR)
ISR(TAUB0_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH14_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH14);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH14_ISR_API == STD_ON */

#if (PWM_TAUB0_CH15_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH15_CAT2_ISR) || defined (TAUB0_CH15_CAT2_ISR)
ISR(TAUB0_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH15_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB0_CH15);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB0_CH15_ISR_API == STD_ON */

#if (PWM_TAUB1_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH00_CAT2_ISR) || defined (TAUB1_CH00_CAT2_ISR)
ISR(TAUB1_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH00_ISR_API == STD_ON */

#if (PWM_TAUB1_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH01_CAT2_ISR) || defined (TAUB1_CH01_CAT2_ISR)
ISR(TAUB1_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH01_ISR_API == STD_ON */

#if (PWM_TAUB1_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH02_CAT2_ISR) || defined (TAUB1_CH02_CAT2_ISR)
ISR(TAUB1_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH02_ISR_API == STD_ON */

#if (PWM_TAUB1_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH03_CAT2_ISR) || defined (TAUB1_CH03_CAT2_ISR)
ISR(TAUB1_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH03_ISR_API == STD_ON */

#if (PWM_TAUB1_CH04_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH04_CAT2_ISR) || defined (TAUB1_CH04_CAT2_ISR)
ISR(TAUB1_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH04_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH04);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH04_ISR_API == STD_ON */

#if (PWM_TAUB1_CH05_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH05_CAT2_ISR) || defined (TAUB1_CH05_CAT2_ISR)
ISR(TAUB1_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH05_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH05);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH05_ISR_API == STD_ON */

#if (PWM_TAUB1_CH06_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH06_CAT2_ISR) || defined (TAUB1_CH06_CAT2_ISR)
ISR(TAUB1_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH06_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH06);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH06_ISR_API == STD_ON */

#if (PWM_TAUB1_CH07_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH07_CAT2_ISR) || defined (TAUB1_CH07_CAT2_ISR)
ISR(TAUB1_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH07_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH07);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH07_ISR_API == STD_ON */

#if (PWM_TAUB1_CH08_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH08_CAT2_ISR) || defined (TAUB1_CH08_CAT2_ISR)
ISR(TAUB1_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH08_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH08);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH08_ISR_API == STD_ON */

#if (PWM_TAUB1_CH09_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH09_CAT2_ISR) || defined (TAUB1_CH09_CAT2_ISR)
ISR(TAUB1_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH09_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH09);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH09_ISR_API == STD_ON */

#if (PWM_TAUB1_CH10_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH10_CAT2_ISR) || defined (TAUB1_CH10_CAT2_ISR)
ISR(TAUB1_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH10_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH10);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH10_ISR_API == STD_ON */

#if (PWM_TAUB1_CH11_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH11_CAT2_ISR) || defined (TAUB1_CH11_CAT2_ISR)
ISR(TAUB1_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH11_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH11);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH11_ISR_API == STD_ON */

#if (PWM_TAUB1_CH12_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH12_CAT2_ISR) || defined (TAUB1_CH12_CAT2_ISR)
ISR(TAUB1_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH12_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH12);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH12_ISR_API == STD_ON */

#if (PWM_TAUB1_CH13_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH13_CAT2_ISR) || defined (TAUB1_CH13_CAT2_ISR)
ISR(TAUB1_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH13_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH13);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH13_ISR_API == STD_ON */

#if (PWM_TAUB1_CH14_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH14_CAT2_ISR) || defined (TAUB1_CH14_CAT2_ISR)
ISR(TAUB1_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH14_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH14);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH14_ISR_API == STD_ON */

#if (PWM_TAUB1_CH15_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH15_CAT2_ISR) || defined (TAUB1_CH15_CAT2_ISR)
ISR(TAUB1_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH15_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUB1_CH15);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUB1_CH15_ISR_API == STD_ON */

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
** Re-entrancy          : Non Reentrant
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
** Function(s) invoked  : Pwm_HW_Callback
**
** Registers Used       : None
**
*******************************************************************************/
#if (PWM_TAUJ0_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0890)-1 */
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"
/* END Msg(2:0890)-1 */

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH00_CAT2_ISR) || defined (TAUJ0_CH00_CAT2_ISR)
ISR(TAUJ0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ0_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ0_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ0_CH00_ISR_API == STD_ON */

#if (PWM_TAUJ0_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH01_CAT2_ISR) || defined (TAUJ0_CH01_CAT2_ISR)
ISR(TAUJ0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ0_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ0_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ0_CH01_ISR_API == STD_ON */

#if (PWM_TAUJ0_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH02_CAT2_ISR) || defined (TAUJ0_CH02_CAT2_ISR)
ISR(TAUJ0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ0_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ0_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ0_CH02_ISR_API == STD_ON */

#if (PWM_TAUJ0_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH03_CAT2_ISR) || defined (TAUJ0_CH03_CAT2_ISR)
ISR(TAUJ0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ0_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ0_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ0_CH03_ISR_API == STD_ON */

#if (PWM_TAUJ1_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH00_CAT2_ISR) || defined (TAUJ1_CH00_CAT2_ISR)
ISR(TAUJ1_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ1_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ1_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ1_CH00_ISR_API == STD_ON */

#if (PWM_TAUJ1_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH01_CAT2_ISR) || defined (TAUJ1_CH01_CAT2_ISR)
ISR(TAUJ1_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ1_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ1_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ1_CH01_ISR_API == STD_ON */

#if (PWM_TAUJ1_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH02_CAT2_ISR) || defined (TAUJ1_CH02_CAT2_ISR)
ISR(TAUJ1_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ1_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ1_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ1_CH02_ISR_API == STD_ON */

#if (PWM_TAUJ1_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH03_CAT2_ISR) || defined (TAUJ1_CH03_CAT2_ISR)
ISR(TAUJ1_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ1_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ1_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ1_CH03_ISR_API == STD_ON */

#if (PWM_TAUJ2_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH00_CAT2_ISR) || defined (TAUJ2_CH00_CAT2_ISR)
ISR(TAUJ2_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ2_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ2_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ2_CH00_ISR_API == STD_ON */

#if (PWM_TAUJ2_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH01_CAT2_ISR) || defined (TAUJ2_CH01_CAT2_ISR)
ISR(TAUJ2_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ2_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ2_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ2_CH01_ISR_API == STD_ON */

#if (PWM_TAUJ2_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH02_CAT2_ISR) || defined (TAUJ2_CH02_CAT2_ISR)
ISR(TAUJ2_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ2_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ2_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ2_CH02_ISR_API == STD_ON */

#if (PWM_TAUJ2_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH03_CAT2_ISR) || defined (TAUJ2_CH03_CAT2_ISR)
ISR(TAUJ2_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ2_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ2_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ2_CH03_ISR_API == STD_ON */

#if (PWM_TAUJ3_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH00_CAT2_ISR) || defined (TAUJ3_CH00_CAT2_ISR)
ISR(TAUJ3_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ3_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ3_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ3_CH00_ISR_API == STD_ON */

#if (PWM_TAUJ3_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH01_CAT2_ISR) || defined (TAUJ3_CH01_CAT2_ISR)
ISR(TAUJ3_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ3_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ3_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ3_CH01_ISR_API == STD_ON */

#if (PWM_TAUJ3_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH02_CAT2_ISR) || defined (TAUJ3_CH02_CAT2_ISR)
ISR(TAUJ3_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ3_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ3_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ3_CH02_ISR_API == STD_ON */

#if (PWM_TAUJ3_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH03_CAT2_ISR) || defined (TAUJ3_CH03_CAT2_ISR)
ISR(TAUJ3_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ3_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_118                                             */
  Pwm_HW_Callback(PWM_TAUJ3_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_TAUJ3_CH03_ISR_API == STD_ON */

#endif /* End of PWM_NOTIFICATION_SUPPORTED == STD_ON */

/* Implements:  PWM_ESDD_UD_133, PWM_ESDD_UD_159, PWM_ESDD_UD_227             */
/* Below ISRs will be checked only if PWM_DIAG_UNIT_USED is STD_ON */
#if (PWM_DIAG_UNIT_USED == STD_ON)
#if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_OFF)
/*******************************************************************************
** Function Name        : PWGA_CHm_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the PWM PWGA
**                        Channel m, where m represents channels.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non Reentrant
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
** Function(s) invoked  : None
**
** Registers Used       : None
**
*******************************************************************************/
#if (PWM_PWGA_CH00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0890)-1 */
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"
/* END Msg(2:0890)-1 */

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH00_CAT2_ISR) || defined (PWGA_CH00_CAT2_ISR)
ISR(PWGA_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH00_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH00);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH00_ISR_API == STD_ON */

#if (PWM_PWGA_CH01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH01_CAT2_ISR) || defined (PWGA_CH01_CAT2_ISR)
ISR(PWGA_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH01_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH01);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH01_ISR_API == STD_ON */

#if (PWM_PWGA_CH02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH02_CAT2_ISR) || defined (PWGA_CH02_CAT2_ISR)
ISR(PWGA_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH02_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH02);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH02_ISR_API == STD_ON */

#if (PWM_PWGA_CH03_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH03_CAT2_ISR) || defined (PWGA_CH03_CAT2_ISR)
ISR(PWGA_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH03_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH03);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH03_ISR_API == STD_ON */

#if (PWM_PWGA_CH04_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH04_CAT2_ISR) || defined (PWGA_CH04_CAT2_ISR)
ISR(PWGA_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH04_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH04);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH04_ISR_API == STD_ON */

#if (PWM_PWGA_CH05_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH05_CAT2_ISR) || defined (PWGA_CH05_CAT2_ISR)
ISR(PWGA_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH05_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH05);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH05_ISR_API == STD_ON */

#if (PWM_PWGA_CH06_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH06_CAT2_ISR) || defined (PWGA_CH06_CAT2_ISR)
ISR(PWGA_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH06_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH06);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH06_ISR_API == STD_ON */

#if (PWM_PWGA_CH07_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH07_CAT2_ISR) || defined (PWGA_CH07_CAT2_ISR)
ISR(PWGA_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH07_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH07);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH07_ISR_API == STD_ON */

#if (PWM_PWGA_CH08_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH08_CAT2_ISR) || defined (PWGA_CH08_CAT2_ISR)
ISR(PWGA_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH08_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH08);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH08_ISR_API == STD_ON */

#if (PWM_PWGA_CH09_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH09_CAT2_ISR) || defined (PWGA_CH09_CAT2_ISR)
ISR(PWGA_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH09_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH09);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH09_ISR_API == STD_ON */

#if (PWM_PWGA_CH10_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH10_CAT2_ISR) || defined (PWGA_CH10_CAT2_ISR)
ISR(PWGA_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH10_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH10);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH10_ISR_API == STD_ON */

#if (PWM_PWGA_CH11_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH11_CAT2_ISR) || defined (PWGA_CH11_CAT2_ISR)
ISR(PWGA_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH11_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH11);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH11_ISR_API == STD_ON */

#if (PWM_PWGA_CH12_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH12_CAT2_ISR) || defined (PWGA_CH12_CAT2_ISR)
ISR(PWGA_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH12_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH12);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH12_ISR_API == STD_ON */

#if (PWM_PWGA_CH13_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH13_CAT2_ISR) || defined (PWGA_CH13_CAT2_ISR)
ISR(PWGA_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH13_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH13);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH13_ISR_API == STD_ON */

#if (PWM_PWGA_CH14_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH14_CAT2_ISR) || defined (PWGA_CH14_CAT2_ISR)
ISR(PWGA_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH14_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH14);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH14_ISR_API == STD_ON */

#if (PWM_PWGA_CH15_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH15_CAT2_ISR) || defined (PWGA_CH15_CAT2_ISR)
ISR(PWGA_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH15_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH15);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH15_ISR_API == STD_ON */

#if (PWM_PWGA_CH16_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH16_CAT2_ISR) || defined (PWGA_CH16_CAT2_ISR)
ISR(PWGA_CH16_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH16_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH16);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH16_ISR_API == STD_ON */

#if (PWM_PWGA_CH17_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH17_CAT2_ISR) || defined (PWGA_CH17_CAT2_ISR)
ISR(PWGA_CH17_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH17_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH17);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH17_ISR_API == STD_ON */

#if (PWM_PWGA_CH18_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH18_CAT2_ISR) || defined (PWGA_CH18_CAT2_ISR)
ISR(PWGA_CH18_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH18_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH18);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH18_ISR_API == STD_ON */

#if (PWM_PWGA_CH19_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH19_CAT2_ISR) || defined (PWGA_CH19_CAT2_ISR)
ISR(PWGA_CH19_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH19_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH19);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH19_ISR_API == STD_ON */

#if (PWM_PWGA_CH20_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH20_CAT2_ISR) || defined (PWGA_CH20_CAT2_ISR)
ISR(PWGA_CH20_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH20_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH20);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH20_ISR_API == STD_ON */

#if (PWM_PWGA_CH21_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH21_CAT2_ISR) || defined (PWGA_CH21_CAT2_ISR)
ISR(PWGA_CH21_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH21_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH21);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH21_ISR_API == STD_ON */

#if (PWM_PWGA_CH22_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH22_CAT2_ISR) || defined (PWGA_CH22_CAT2_ISR)
ISR(PWGA_CH22_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH22_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH22);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH22_ISR_API == STD_ON */

#if (PWM_PWGA_CH23_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH23_CAT2_ISR) || defined (PWGA_CH23_CAT2_ISR)
ISR(PWGA_CH23_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH23_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH23);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH23_ISR_API == STD_ON */

#if (PWM_PWGA_CH24_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH24_CAT2_ISR) || defined (PWGA_CH24_CAT2_ISR)
ISR(PWGA_CH24_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH24_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH24);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH24_ISR_API == STD_ON */

#if (PWM_PWGA_CH25_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH25_CAT2_ISR) || defined (PWGA_CH25_CAT2_ISR)
ISR(PWGA_CH25_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH25_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH25);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH25_ISR_API == STD_ON */

#if (PWM_PWGA_CH26_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH26_CAT2_ISR) || defined (PWGA_CH26_CAT2_ISR)
ISR(PWGA_CH26_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH26_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH26);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH26_ISR_API == STD_ON */

#if (PWM_PWGA_CH27_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH27_CAT2_ISR) || defined (PWGA_CH27_CAT2_ISR)
ISR(PWGA_CH27_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH27_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH27);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH27_ISR_API == STD_ON */

#if (PWM_PWGA_CH28_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH28_CAT2_ISR) || defined (PWGA_CH28_CAT2_ISR)
ISR(PWGA_CH28_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH28_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH28);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH28_ISR_API == STD_ON */

#if (PWM_PWGA_CH29_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH29_CAT2_ISR) || defined (PWGA_CH29_CAT2_ISR)
ISR(PWGA_CH29_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH29_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH29);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH29_ISR_API == STD_ON */

#if (PWM_PWGA_CH30_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH30_CAT2_ISR) || defined (PWGA_CH30_CAT2_ISR)
ISR(PWGA_CH30_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH30_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH30);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH30_ISR_API == STD_ON */

#if (PWM_PWGA_CH31_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH31_CAT2_ISR) || defined (PWGA_CH31_CAT2_ISR)
ISR(PWGA_CH31_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH31_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH31);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH31_ISR_API == STD_ON */

#if (PWM_PWGA_CH32_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH32_CAT2_ISR) || defined (PWGA_CH32_CAT2_ISR)
ISR(PWGA_CH32_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH32_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH32);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH32_ISR_API == STD_ON */

#if (PWM_PWGA_CH33_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH33_CAT2_ISR) || defined (PWGA_CH33_CAT2_ISR)
ISR(PWGA_CH33_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH33_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH33);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH33_ISR_API == STD_ON */

#if (PWM_PWGA_CH34_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH34_CAT2_ISR) || defined (PWGA_CH34_CAT2_ISR)
ISR(PWGA_CH34_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH34_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH34);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH34_ISR_API == STD_ON */

#if (PWM_PWGA_CH35_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH35_CAT2_ISR) || defined (PWGA_CH35_CAT2_ISR)
ISR(PWGA_CH35_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH35_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH35);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH35_ISR_API == STD_ON */

#if (PWM_PWGA_CH36_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH36_CAT2_ISR) || defined (PWGA_CH36_CAT2_ISR)
ISR(PWGA_CH36_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH36_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH36);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH36_ISR_API == STD_ON */

#if (PWM_PWGA_CH37_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH37_CAT2_ISR) || defined (PWGA_CH37_CAT2_ISR)
ISR(PWGA_CH37_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH37_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH37);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH37_ISR_API == STD_ON */

#if (PWM_PWGA_CH38_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH38_CAT2_ISR) || defined (PWGA_CH38_CAT2_ISR)
ISR(PWGA_CH38_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH38_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH38);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH38_ISR_API == STD_ON */

#if (PWM_PWGA_CH39_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH39_CAT2_ISR) || defined (PWGA_CH39_CAT2_ISR)
ISR(PWGA_CH39_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH39_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH39);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH39_ISR_API == STD_ON */

#if (PWM_PWGA_CH40_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH40_CAT2_ISR) || defined (PWGA_CH40_CAT2_ISR)
ISR(PWGA_CH40_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH40_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH40);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH40_ISR_API == STD_ON */

#if (PWM_PWGA_CH41_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH41_CAT2_ISR) || defined (PWGA_CH41_CAT2_ISR)
ISR(PWGA_CH41_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH41_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH41);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH41_ISR_API == STD_ON */

#if (PWM_PWGA_CH42_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH42_CAT2_ISR) || defined (PWGA_CH42_CAT2_ISR)
ISR(PWGA_CH42_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH42_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH42);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH42_ISR_API == STD_ON */

#if (PWM_PWGA_CH43_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH43_CAT2_ISR) || defined (PWGA_CH43_CAT2_ISR)
ISR(PWGA_CH43_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH43_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH43);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH43_ISR_API == STD_ON */

#if (PWM_PWGA_CH44_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH44_CAT2_ISR) || defined (PWGA_CH44_CAT2_ISR)
ISR(PWGA_CH44_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH44_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH44);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH44_ISR_API == STD_ON */

#if (PWM_PWGA_CH45_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH45_CAT2_ISR) || defined (PWGA_CH45_CAT2_ISR)
ISR(PWGA_CH45_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH45_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH45);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH45_ISR_API == STD_ON */

#if (PWM_PWGA_CH46_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH46_CAT2_ISR) || defined (PWGA_CH46_CAT2_ISR)
ISR(PWGA_CH46_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH46_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH46);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH46_ISR_API == STD_ON */

#if (PWM_PWGA_CH47_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH47_CAT2_ISR) || defined (PWGA_CH47_CAT2_ISR)
ISR(PWGA_CH47_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH47_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH47);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH47_ISR_API == STD_ON */

#if (PWM_PWGA_CH48_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH48_CAT2_ISR) || defined (PWGA_CH48_CAT2_ISR)
ISR(PWGA_CH48_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH48_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH48);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH48_ISR_API == STD_ON */

#if (PWM_PWGA_CH49_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH49_CAT2_ISR) || defined (PWGA_CH49_CAT2_ISR)
ISR(PWGA_CH49_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH49_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH49);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH49_ISR_API == STD_ON */

#if (PWM_PWGA_CH50_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH50_CAT2_ISR) || defined (PWGA_CH50_CAT2_ISR)
ISR(PWGA_CH50_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH50_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH50);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH50_ISR_API == STD_ON */

#if (PWM_PWGA_CH51_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH51_CAT2_ISR) || defined (PWGA_CH51_CAT2_ISR)
ISR(PWGA_CH51_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH51_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH51);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH51_ISR_API == STD_ON */

#if (PWM_PWGA_CH52_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH52_CAT2_ISR) || defined (PWGA_CH52_CAT2_ISR)
ISR(PWGA_CH52_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH52_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH52);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH52_ISR_API == STD_ON */

#if (PWM_PWGA_CH53_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH53_CAT2_ISR) || defined (PWGA_CH53_CAT2_ISR)
ISR(PWGA_CH53_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH53_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH53);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH53_ISR_API == STD_ON */

#if (PWM_PWGA_CH54_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH54_CAT2_ISR) || defined (PWGA_CH54_CAT2_ISR)
ISR(PWGA_CH54_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH54_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH54);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH54_ISR_API == STD_ON */

#if (PWM_PWGA_CH55_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH55_CAT2_ISR) || defined (PWGA_CH55_CAT2_ISR)
ISR(PWGA_CH55_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH55_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH55);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH55_ISR_API == STD_ON */

#if (PWM_PWGA_CH56_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH56_CAT2_ISR) || defined (PWGA_CH56_CAT2_ISR)
ISR(PWGA_CH56_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH56_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH56);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH56_ISR_API == STD_ON */

#if (PWM_PWGA_CH57_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH57_CAT2_ISR) || defined (PWGA_CH57_CAT2_ISR)
ISR(PWGA_CH57_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH57_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH57);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH57_ISR_API == STD_ON */

#if (PWM_PWGA_CH58_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH58_CAT2_ISR) || defined (PWGA_CH58_CAT2_ISR)
ISR(PWGA_CH58_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH58_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH58);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH58_ISR_API == STD_ON */

#if (PWM_PWGA_CH59_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH59_CAT2_ISR) || defined (PWGA_CH59_CAT2_ISR)
ISR(PWGA_CH59_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH59_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH59);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH59_ISR_API == STD_ON */

#if (PWM_PWGA_CH60_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH60_CAT2_ISR) || defined (PWGA_CH60_CAT2_ISR)
ISR(PWGA_CH60_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH60_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH60);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH60_ISR_API == STD_ON */

#if (PWM_PWGA_CH61_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH61_CAT2_ISR) || defined (PWGA_CH61_CAT2_ISR)
ISR(PWGA_CH61_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH61_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH61);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH61_ISR_API == STD_ON */

#if (PWM_PWGA_CH62_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH62_CAT2_ISR) || defined (PWGA_CH62_CAT2_ISR)
ISR(PWGA_CH62_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH62_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH62);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH62_ISR_API == STD_ON */

#if (PWM_PWGA_CH63_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH63_CAT2_ISR) || defined (PWGA_CH63_CAT2_ISR)
ISR(PWGA_CH63_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH63_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH63);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH63_ISR_API == STD_ON */

#if (PWM_PWGA_CH64_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH64_CAT2_ISR) || defined (PWGA_CH64_CAT2_ISR)
ISR(PWGA_CH64_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH64_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH64);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH64_ISR_API == STD_ON */

#if (PWM_PWGA_CH65_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH65_CAT2_ISR) || defined (PWGA_CH65_CAT2_ISR)
ISR(PWGA_CH65_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH65_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH65);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH65_ISR_API == STD_ON */

#if (PWM_PWGA_CH66_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH66_CAT2_ISR) || defined (PWGA_CH66_CAT2_ISR)
ISR(PWGA_CH66_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH66_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH66);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH66_ISR_API == STD_ON */

#if (PWM_PWGA_CH67_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH67_CAT2_ISR) || defined (PWGA_CH67_CAT2_ISR)
ISR(PWGA_CH67_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH67_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH67);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH67_ISR_API == STD_ON */

#if (PWM_PWGA_CH68_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH68_CAT2_ISR) || defined (PWGA_CH68_CAT2_ISR)
ISR(PWGA_CH68_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH68_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH68);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH68_ISR_API == STD_ON */

#if (PWM_PWGA_CH69_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH69_CAT2_ISR) || defined (PWGA_CH69_CAT2_ISR)
ISR(PWGA_CH69_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH69_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH69);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH69_ISR_API == STD_ON */

#if (PWM_PWGA_CH70_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH70_CAT2_ISR) || defined (PWGA_CH70_CAT2_ISR)
ISR(PWGA_CH70_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH70_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH70);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH70_ISR_API == STD_ON */

#if (PWM_PWGA_CH71_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH71_CAT2_ISR) || defined (PWGA_CH71_CAT2_ISR)
ISR(PWGA_CH71_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH71_ISR(void)
#endif
{
  /* Implements:  PWM_ESDD_UD_172                                             */
  Pwm_PWGA_Callback(PWM_PWGA_CH71);
}

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CH71_ISR_API == STD_ON */
#endif /* End of PWM_DIAG_CHANNELGROUP_SUPPORT == STD_OFF */

/* Implements:  PWM_ESDD_UD_226, PWM_ESDD_UD_227                              */
#if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
/*******************************************************************************
** Function Name        : PWM_INTPWGAGm_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the PWM PWGA
**                        Channel groups m, where m represents channel groups
**                        00, 01 and 02.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non Reentrant
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
** Global Variable(s)   : Pwm_GaaDiagChannelMap
**
** Function(s) invoked  : Pwm_PWGA_Callback
**
** Registers Used       : ulPWGAINTMSK, ulPWGAINTF, ulPWGAINTFC
**
*******************************************************************************/
#if (PWM_PWGA_CHGRP00_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CHGRP00_CAT2_ISR) || defined (PWGA_CHGRP00_CAT2_ISR)
ISR(PWGA_CHGRP00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWM_INTPWGAG00_ISR(void)
#endif
{
  uint8 LucCount;
  for (LucCount = PWM_ZERO; LucCount < PWM_DIAG_GROUP1; LucCount++)
  {
    /* Check if interrupt occured*/
    /* QAC Warning: START Msg(2:3892)-3 */
    if(((((Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK) >> LucCount)
    & PWM_ONE) == PWM_ZERO) &&
    ((((Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTF) >> LucCount) &
    PWM_ONE) == PWM_ONE))
    /* END Msg(2:3892)-3 */
    {
      /* Implements:  PWM_ESDD_UD_172                                         */
      /*Call callback function of channel interrupt*/
      Pwm_PWGA_Callback(Pwm_GaaDiagChannelMap[LucCount]);

      /* QAC Warning: START Msg(2:3892)-3 */
      /*clear the corresponding channel interrupt by writing to PWGAINTFC00
      register.*/
      Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTFC |=
                                                   (uint32)PWM_ONE << LucCount;
      /* END Msg(2:3892)-3 */
    }
    else
    {
        /* do nothing */
    }
  }
}
#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CHGRP00_ISR_API == STD_ON */

#if (PWM_PWGA_CHGRP01_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CHGRP01_CAT2_ISR) || defined (PWGA_CHGRP01_CAT2_ISR)
ISR(PWGA_CHGRP01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWM_INTPWGAG01_ISR(void)
#endif
{
  uint8 LucCount;
  for (LucCount = PWM_ZERO; LucCount < PWM_DIAG_GROUP1; LucCount++)
  {
    /* QAC Warning: START Msg(2:3892)-3 */
    /* Check if interrupt occured*/
    if(((((Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK) >> LucCount) &
    PWM_ONE) == PWM_ZERO) && \
   ((((Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTF)>> LucCount) & \
    PWM_ONE) == PWM_ONE))
    /* END Msg(2:3892)-3 */
    {
      /* Implements:  PWM_ESDD_UD_172                                         */
      /*Call callback function of channel interrupt*/
      Pwm_PWGA_Callback(Pwm_GaaDiagChannelMap[PWM_DIAG_GROUP1 + LucCount]);

      /* QAC Warning: START Msg(2:3892)-3 */
      /*clear the corresponding channel interrupt by writing to PWGAINTFC01
      register.*/
      Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTFC |=
                                                   (uint32)PWM_ONE << LucCount;
      /* END Msg(2:3892)-3 */
    }
    else
    {
        /* do nothing */
    }
  }
}
#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif /* End of PWM_PWGA_CHGRP01_ISR_API == STD_ON */

#if (PWM_PWGA_CHGRP02_ISR_API == STD_ON)
#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CHGRP02_CAT2_ISR) || defined (PWGA_CHGRP02_CAT2_ISR)
ISR(PWGA_CHGRP02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWM_INTPWGAG02_ISR(void)
#endif
 {
  uint8 LucCount;
  for (LucCount = PWM_ZERO; LucCount < PWM_DIAG_GROUP1; LucCount++)
  {
    /* QAC Warning: START Msg(2:3892)-3 */
    /* Check if interrupt occured*/
    if(((((Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK) >> LucCount) &
    PWM_ONE) == PWM_ZERO) && \
    ((((Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTF)>> LucCount) & \
    PWM_ONE) == PWM_ONE))
    /* END Msg(2:3892)-3 */
    {
      /* Implements:  PWM_ESDD_UD_172                                         */
      /*Call callback function of channel interrupt*/
      Pwm_PWGA_Callback(Pwm_GaaDiagChannelMap[PWM_DIAG_GROUP2 + LucCount]);

      /* QAC Warning: START Msg(2:3892)-3 */
      /*clear the corresponding channel interrupt by writing to PWGAINTFC02
      register.*/
      Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTFC |=
                                                   (uint32)PWM_ONE << LucCount;
      /* END Msg(2:3892)-3 */
    }
    else
    {
        /* do nothing */
    }
  }
 }
#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* QAC Warning: START Msg(2:0862)-2 */
/* Functionality related to R4.0 */
#include "MemMap.h"
/* END Msg(2:0862)-2 */
#endif
#endif /* End of PWM_PWGA_CHGRP02_ISR_API == STD_ON */
#endif /* End of PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON */

#endif /* End of PWM_DIAG_UNIT_USED == STD_ON */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
