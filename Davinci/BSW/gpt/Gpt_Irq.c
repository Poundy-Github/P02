/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Irq.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISRs for all Timers of GPT Driver                       */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  17-Sep-2015    : Initial Version
 * V2.0.0:  28-Oct-2016    : As part of ARDAABC-875,interrupt handler for FE
 *                           level interrupts of OSTM channels 1-4 was
 *                           implemented FE interrupt have to use
 *                           G3K_FETRAP_ENTRY and G3K_FETRAP_LEAVE for context
 *                           switching
 * V2.1.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 * V2.2.0:  15-Oct-2016    : Add support for Predef Timer callback notification
 *                           function in case Prefef Timer function is
 *                           configured as part of ARDAABC-564
 * V2.2.1:  30-Nov-2016    : Use pragma ghs interrupt(FE) to inform
 *                           compiler that GPT_FEINT_ISR is a FE interrupt
 *                           routine instead of G3K_FETRAP_ENTRY/
 *                           G3K_FETRAP_LEAVE pair which was causing problems
 *                           with context switching.
 * V2.2.2:  06-Dec-2016    : Added compile switch GPT_PREDEF_TIMER_ENABLED to
 *                           exclude from compilation Predef Timer related code
 *                           when function is disabled.
 * V2.2.3:  08-Feb-2016    : Added comments for MISRA warnings
 * V2.2.4:  25-May-2017    : As part of JIRA ARDAABD-1883, ISRs for for TAUJ
 *                           units added, unsupported TAUD units removed
 *                           and copyright year updated.
 * V2.2.5:  25-Jul-2017    : MISRA references sections are updated.
 * V2.2.6:  18-Aug-2017    : As part of JIRA ARDAABD-2305, ISRs for for new OSTM
 *                           timer units are added.
 * V2.2.7:  18-Sep-2017    : As per ARDAABD-2425, QAC level 2 warning
 *                           Justification tags are added.
 * V2.2.8:  18-Jun-2018    : 1. Following changes were made as per merging
 *                             activity #ARDAABD-3489,
 *                             a. 'Iocommon_Defines.h' is added.
 *                               (Ref: ARDAABD-2461)
 *                             b. Copyright information updated.
 *                           2. As per merging activity #ARDAABD-3511,
 *                              ISR Macro name for OSTM5 updated.
 *                              (Ref: ARDAABD-3150)
 *                           3. As per ARDAABD-3841, traceability updated.
 * V2.2.9:  08-Oct-2019    :Following changes are made:
 *                           1. As part of JIRA ARDAABD-3970, macros
 *                              GPT_FEINT_WRITE_OR were changed to
 *                              GPT_FEINT_WRITE_ONLY when writing register
 *                              GPT_FEINT_FACTOR_CLEAR_REGISTER.
 *                           2. Corrected the format issue.
 */
/******************************************************************************/
/*Implements EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* Implements GPT261, GPT372 */
/* Implements SWS_Gpt_00261 */
/* Included for Gpt.h inclusion and macro definitions */
#include "Gpt.h"
/* Included for the Declarations of I/O Registers */
#include "Iocommon_Defines.h"
/* Included for declaration of the ISRs */
#include "Gpt_Irq.h"
/* Included for declaration of the Gpt_CbkNotification() function */
#include "Gpt_LLDriver.h"
/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0055 */
/* AUTOSAR release version information */
#define GPT_IRQ_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_IRQ_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_IRQ_C_AR_RELEASE_REVISION_VERSION \
    GPT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define GPT_IRQ_C_SW_MAJOR_VERSION    GPT_SW_MAJOR_VERSION_VALUE
#define GPT_IRQ_C_SW_MINOR_VERSION    GPT_SW_MINOR_VERSION_VALUE

/*******************************************************************************
 **                      Version Check                                        **
 ******************************************************************************/
#if (GPT_IRQ_AR_RELEASE_MAJOR_VERSION != GPT_IRQ_C_AR_RELEASE_MAJOR_VERSION)
#error "Gpt_Irq.c : Mismatch in Release Major Version"
#endif

#if (GPT_IRQ_AR_RELEASE_MINOR_VERSION != GPT_IRQ_C_AR_RELEASE_MINOR_VERSION)
#error "Gpt_Irq.c : Mismatch in Release Minor Version"
#endif

#if (GPT_IRQ_AR_RELEASE_REVISION_VERSION != \
    GPT_IRQ_C_AR_RELEASE_REVISION_VERSION)
#error "Gpt_Irq.c : Mismatch in Release Patch Version"
#endif

#if (GPT_IRQ_SW_MAJOR_VERSION != GPT_IRQ_C_SW_MAJOR_VERSION)
#error "Gpt_Irq.c : Mismatch in Major Version"
#endif

#if (GPT_IRQ_SW_MINOR_VERSION != GPT_IRQ_C_SW_MINOR_VERSION)
#error "Gpt_Irq.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
 **                         QAC Warning                                       **
 ******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : None                                                       */
/* Justification : These Macro substitution is required to optimize MemMap    */
/*                 inclusion.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/
/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/
/* Implements EAAR_PN0034_NR_0026 */
/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Needed for accessing memory mapped registers               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1   and                         */
/*                 END Msg(4:0303)-1   tags in the code.                      */
/*                                                                            */

/*******************************************************************************
 **                      Function Definitions                                 **
 ******************************************************************************/

/*******************************************************************************
 ** Function Name        : OSTMn_CHm_ISR
 **
 ** Service ID           : NA
 **
 ** Description          : These are Interrupt routines for the timer OSTMn
 **                        Channel m, where n represents the OSTM Units and
 **                        m represents channels associated for each Unit.
 **
 ** Sync/Async           : Synchronous
 **
 ** Re-entrancy          : Reentrant
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
 ** Function(s) invoked  : Gpt_CbkNotification
 **
 ** Registers Used       : None
 **
 ******************************************************************************/
/*Implements GPT_ESDD_UD_050 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_FAST_ASIL_B
#else
  #define GPT_START_SEC_CODE_FAST
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include GPT_MEMMAP_FILE
/* Implements EAAR_PN0080_FR_0015 */
#if (GPT_OSTM0_CH00_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_OSTM0_CH00_CAT2_ISR) || defined (OSTM0_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(OSTM0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) OSTM0_CH00_ISR(void)
#endif
{

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM0)
  /* call the notification function of Predef timers */
  Gpt_HW_PredefTimerCallbackNotification();
#else
  /* call the notification function of channel */
  Gpt_CbkNotification(GPT_OSTM0_CH00);
#endif/* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM0) */
#else
  /* call the notification function of channel */
  Gpt_CbkNotification(GPT_OSTM0_CH00);
#endif /* End of(GPT_PREDEF_TIMER_ENABLED == STD_ON) */

#else /* GPT_AR_HIGHER_VERSION != GPT_AR_VERSION  */
  /* call the notification function of channel */
  Gpt_CbkNotification(GPT_OSTM0_CH00);
#endif /*(GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */
}
#endif /*GPT_OSTM0_CH00_ISR_API == STD_ON */

#if (GPT_OSTM5_CH00_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_OSTM5_CH00_CAT2_ISR) || defined (OSTM5_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(OSTM5_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) OSTM5_CH00_ISR(void)
#endif
{
#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM5)
  /* call the notification function of Predef timers */
  Gpt_HW_PredefTimerCallbackNotification();
#else
  /* call the notification function of channel */
  Gpt_CbkNotification(GPT_OSTM5_CH00);
#endif/* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM5) */
#else
  /* call the notification function of channel */
   Gpt_CbkNotification(GPT_OSTM5_CH00);
#endif /* End of(GPT_PREDEF_TIMER_ENABLED == STD_ON) */

#else /* GPT_AR_HIGHER_VERSION != GPT_AR_VERSION  */
  /* call the notification function of channel */
  Gpt_CbkNotification(GPT_OSTM5_CH00);
#endif /*(GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */
}
#endif /*GPT_OSTM5_CH00_ISR_API == STD_ON */
/*******************************************************************************
 ** Function Name        : GPT_FEINT_ISR
 **
 ** Service ID           : NA
 **
 ** Description          : These is a common Interrupt routine used to handle
 **                        FE interrupts for the timers OSTM1-4.
 **
 ** Sync/Async           : Synchronous
 **
 ** Re-entrancy          : Reentrant
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
 ** Function(s) invoked  : Gpt_CbkNotification,
 **                        Gpt_HW_PredefTimerCallbackNotification
 **
 ** Registers Used       : FEINTF, FEINTFC
 **
 ******************************************************************************/
/* Defines the CAT2 interrupt mapping */
/*Implements GPT_ESDD_UD_050 */
#if defined  (Os_GPT_FEINT_CAT2_ISR) || defined (GPT_FEINT_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(GPT_FEINT_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
DEFINE_FE_INTERRUPT
/* Implements GPT_ESDD_UD_112 */
/* Implements EAAR_PN0080_FR_0015 */
FUNC(void, GPT_FAST_CODE) GPT_FEINT_ISR(void)
#endif /* defined  (Os_GPT_FEINT_CAT2_ISR) || defined (GPT_FEINT_CAT2_ISR) */
{
  /* MISRA Violation: START Msg(4:0303)-1 */
  if (GPT_OSTM1FEINT_MASK == (GPT_FEINT_FACTOR_REGISTER & GPT_OSTM1FEINT_MASK))
  {
  /* END Msg(4:0303)-1 */
#if (GPT_OSTM1_CH00_ISR_API == STD_ON)

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM1)
    /* call the notification function of Predef timers */
    Gpt_HW_PredefTimerCallbackNotification();
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM1_CH00);
#endif /* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM1) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM1_CH00);
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM1_CH00);
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /*(GPT_OSTM1_CH00_ISR_API == STD_ON) */

    /* clear pending interrupt flag */
    /* MISRA Violation: START Msg(4:0303)-1 */
    GPT_FEINT_WRITE_ONLY((&GPT_FEINT_FACTOR_CLEAR_REGISTER),
                         GPT_OSTM1FEINT_MASK);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:0303)-1 */
  if (GPT_OSTM2FEINT_MASK == (GPT_FEINT_FACTOR_REGISTER & GPT_OSTM2FEINT_MASK))
  /* END Msg(4:0303)-1 */
  {
#if (GPT_OSTM2_CH00_ISR_API == STD_ON)

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM2)
    /* call the notification function of Predef timers */
    Gpt_HW_PredefTimerCallbackNotification();
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM2_CH00);
#endif /* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM2) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM2_CH00);
#endif /* End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM2_CH00);
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /*(GPT_OSTM2_CH00_ISR_API == STD_ON) */
    /* Clear OSTM2 interrupt flag */
    /* MISRA Violation: START Msg(4:0303)-1 */
    GPT_FEINT_WRITE_ONLY((&GPT_FEINT_FACTOR_CLEAR_REGISTER),
                         GPT_OSTM2FEINT_MASK);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:0303)-1 */
  if (GPT_OSTM3FEINT_MASK == (GPT_FEINT_FACTOR_REGISTER & GPT_OSTM3FEINT_MASK))
  /* END Msg(4:0303)-1 */
  {
#if (GPT_OSTM3_CH00_ISR_API == STD_ON)
#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM3)
    /* call the notification function of Predef timers */
    Gpt_HW_PredefTimerCallbackNotification();
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM3_CH00);
#endif /* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM2) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM3_CH00);
#endif/* End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM3_CH00);
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /*(GPT_OSTM3_CH00_ISR_API == STD_ON) */
    /* Clear OSTM3 interrupt flag */
    /* MISRA Violation: START Msg(4:0303)-1 */
    GPT_FEINT_WRITE_ONLY((&GPT_FEINT_FACTOR_CLEAR_REGISTER),
                         GPT_OSTM3FEINT_MASK);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:0303)-1 */
  if (GPT_OSTM4FEINT_MASK == (GPT_FEINT_FACTOR_REGISTER & GPT_OSTM4FEINT_MASK))
  /* END Msg(4:0303)-1 */
  {
#if (GPT_OSTM4_CH00_ISR_API == STD_ON)

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM4)
    /* call the notification function of Predef timers */
    Gpt_HW_PredefTimerCallbackNotification();
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM4_CH00);
#endif/* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM4) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM4_CH00);
#endif /* End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM4_CH00);
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /*(GPT_OSTM4_CH00_ISR_API == STD_ON) */
    /* Clear OSTM4 interrupt flag */
    /* MISRA Violation: START Msg(4:0303)-1 */
    GPT_FEINT_WRITE_ONLY((&GPT_FEINT_FACTOR_CLEAR_REGISTER),
                         GPT_OSTM4FEINT_MASK);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:0303)-1 */
  if (GPT_OSTM6FEINT_MASK == (GPT_FEINT_FACTOR_REGISTER & GPT_OSTM6FEINT_MASK))
  /* END Msg(4:0303)-1 */
  {
#if (GPT_OSTM6_CH00_ISR_API == STD_ON)

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM6)
    /* call the notification function of Predef timers */
    Gpt_HW_PredefTimerCallbackNotification();
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM6_CH00);
#endif/* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM6) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM6_CH00);
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM6_CH00);
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /*(GPT_OSTM6_CH00_ISR_API == STD_ON) */
    /* Clear OSTM6 interrupt flag */
    /* MISRA Violation: START Msg(4:0303)-1 */
    GPT_FEINT_WRITE_ONLY((&GPT_FEINT_FACTOR_CLEAR_REGISTER),
                         GPT_OSTM6FEINT_MASK);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:0303)-1 */
  if (GPT_OSTM7FEINT_MASK == (GPT_FEINT_FACTOR_REGISTER & GPT_OSTM7FEINT_MASK))
  /* END Msg(4:0303)-1 */
  {
#if (GPT_OSTM7_CH00_ISR_API == STD_ON)

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM7)
    /* call the notification function of Predef timers */
    Gpt_HW_PredefTimerCallbackNotification();
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM7_CH00);
#endif/* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM7) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM7_CH00);
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM7_CH00);
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /*(GPT_OSTM7_CH00_ISR_API == STD_ON) */
    /* Clear OSTM7 interrupt flag */
    /* MISRA Violation: START Msg(4:0303)-1 */
    GPT_FEINT_WRITE_ONLY((&GPT_FEINT_FACTOR_CLEAR_REGISTER),
                         GPT_OSTM7FEINT_MASK);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:0303)-1 */
  if (GPT_OSTM8FEINT_MASK == (GPT_FEINT_FACTOR_REGISTER & GPT_OSTM8FEINT_MASK))
  /* END Msg(4:0303)-1 */
  {
#if (GPT_OSTM8_CH00_ISR_API == STD_ON)

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM8)
    /* call the notification function of Predef timers */
    Gpt_HW_PredefTimerCallbackNotification();
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM8_CH00);
#endif/* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM8) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM8_CH00);
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM8_CH00);
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /*(GPT_OSTM8_CH00_ISR_API == STD_ON) */
    /* Clear OSTM8 interrupt flag */
    /* MISRA Violation: START Msg(4:0303)-1 */
    GPT_FEINT_WRITE_ONLY((&GPT_FEINT_FACTOR_CLEAR_REGISTER),
                         GPT_OSTM8FEINT_MASK);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:0303)-1 */
  if (GPT_OSTM9FEINT_MASK == (GPT_FEINT_FACTOR_REGISTER & GPT_OSTM9FEINT_MASK))
  /* END Msg(4:0303)-1 */
  {
#if (GPT_OSTM9_CH00_ISR_API == STD_ON)

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX == GPT_PREDEF_TIMER_CHANNEL_OSTM9)
    /* call the notification function of Predef timers */
    Gpt_HW_PredefTimerCallbackNotification();
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM9_CH00);
#endif/* End of (GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX ==
                 GPT_PREDEF_TIMER_CHANNEL_OSTM9) */
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM9_CH00);
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#else
    /* call the notification function of channel */
    Gpt_CbkNotification(GPT_OSTM9_CH00);
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /*(GPT_OSTM9_CH00_ISR_API == STD_ON) */
    /* Clear OSTM9 interrupt flag */
    /* MISRA Violation: START Msg(4:0303)-1 */
    GPT_FEINT_WRITE_ONLY((&GPT_FEINT_FACTOR_CLEAR_REGISTER),
                         GPT_OSTM9FEINT_MASK);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }
}
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
 ** Re-entrancy          : Reentrant
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
 ** Function(s) invoked  : Gpt_CbkNotification
 **
 ** Registers Used       : None
 **
 ******************************************************************************/
/*Implements GPT_ESDD_UD_050 */
/* Implements EAAR_PN0080_FR_0015 */
#if (GPT_TAUD0_CH00_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH00_CAT2_ISR) || defined (TAUD0_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH00_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH00);
}
#endif /* End of GPT_TAUD0_CH00_ISR_API == STD_ON */

#if (GPT_TAUD0_CH01_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH01_CAT2_ISR) || defined (TAUD0_CH01_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH01_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH01);
}
#endif /* End of GPT_TAUD0_CH01_ISR_API == STD_ON */

#if (GPT_TAUD0_CH02_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH02_CAT2_ISR) || defined (TAUD0_CH02_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH02_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH02);
}
#endif /* End of GPT_TAUD0_CH02_ISR_API == STD_ON */

#if (GPT_TAUD0_CH03_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH03_CAT2_ISR) || defined (TAUD0_CH03_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH03_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH03);
}
#endif /* End of GPT_TAUD0_CH03_ISR_API == STD_ON */

#if (GPT_TAUD0_CH04_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH04_CAT2_ISR) || defined (TAUD0_CH04_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH04_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH04);
}

#endif /* End of GPT_TAUD0_CH04_ISR_API == STD_ON */

#if (GPT_TAUD0_CH05_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH05_CAT2_ISR) || defined (TAUD0_CH05_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH05_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH05);
}
#endif /* End of GPT_TAUD0_CH05_ISR_API == STD_ON */

#if (GPT_TAUD0_CH06_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH06_CAT2_ISR) || defined (TAUD0_CH06_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH06_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH06);
}
#endif /* End of GPT_TAUD0_CH06_ISR_API == STD_ON */

#if (GPT_TAUD0_CH07_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH07_CAT2_ISR) || defined (TAUD0_CH07_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH07_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH07);
}

#endif /* End of GPT_TAUD0_CH07_ISR_API == STD_ON */

#if (GPT_TAUD0_CH08_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH08_CAT2_ISR) || defined (TAUD0_CH08_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH08_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH08);
}

#endif /* End of GPT_TAUD0_CH08_ISR_API == STD_ON */

#if (GPT_TAUD0_CH09_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH09_CAT2_ISR) || defined (TAUD0_CH09_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH09_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH09);
}

#endif /* End of GPT_TAUD0_CH09_ISR_API == STD_ON */

#if (GPT_TAUD0_CH10_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH10_CAT2_ISR) || defined (TAUD0_CH10_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH10_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH10);
}

#endif /* End of GPT_TAUD0_CH10_ISR_API == STD_ON */

#if (GPT_TAUD0_CH11_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH11_CAT2_ISR) || defined (TAUD0_CH11_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH11_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH11);
}

#endif /* End of GPT_TAUD0_CH11_ISR_API == STD_ON */

#if (GPT_TAUD0_CH12_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH12_CAT2_ISR) || defined (TAUD0_CH12_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH12_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH12);
}

#endif /* End of GPT_TAUD0_CH12_ISR_API == STD_ON */

#if (GPT_TAUD0_CH13_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH13_CAT2_ISR) || defined (TAUD0_CH13_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH13_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH13);
}

#endif /* End of GPT_TAUD0_CH13_ISR_API == STD_ON */

#if (GPT_TAUD0_CH14_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH14_CAT2_ISR) || defined (TAUD0_CH14_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH14_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH14);
}

#endif /* End of GPT_TAUD0_CH14_ISR_API == STD_ON */

#if (GPT_TAUD0_CH15_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH15_CAT2_ISR) || defined (TAUD0_CH15_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUD0_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH15_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUD0_CH15);
}

#endif /* End of GPT_TAUD0_CH15_ISR_API == STD_ON */
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
 ** Re-entrancy          : Reentrant
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
 ** Function(s) invoked  : Gpt_CbkNotification
 **
 ** Registers Used       : None
 **
 ******************************************************************************/
/*Implements GPT_ESDD_UD_050 */
/* Implements EAAR_PN0080_FR_0015 */
#if (GPT_TAUB0_CH00_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH00_CAT2_ISR) || defined (TAUB0_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH00_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH00);
}

#endif /* End of GPT_TAUB0_CH00_ISR_API == STD_ON */

#if (GPT_TAUB0_CH01_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH01_CAT2_ISR) || defined (TAUB0_CH01_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH01_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH01);
}

#endif /* End of GPT_TAUB0_CH01_ISR_API == STD_ON */

#if (GPT_TAUB0_CH02_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH02_CAT2_ISR) || defined (TAUB0_CH02_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH02_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH02);
}

#endif /* End of GPT_TAUB0_CH02_ISR_API == STD_ON */

#if (GPT_TAUB0_CH03_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH03_CAT2_ISR) || defined (TAUB0_CH03_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH03_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH03);
}

#endif /* End of GPT_TAUB0_CH03_ISR_API == STD_ON */

#if (GPT_TAUB0_CH04_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH04_CAT2_ISR) || defined (TAUB0_CH04_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH04_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH04);
}

#endif /* End of GPT_TAUB0_CH04_ISR_API == STD_ON */

#if (GPT_TAUB0_CH05_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH05_CAT2_ISR) || defined (TAUB0_CH05_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH05_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH05);
}

#endif /* End of GPT_TAUB0_CH05_ISR_API == STD_ON */

#if (GPT_TAUB0_CH06_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH06_CAT2_ISR) || defined (TAUB0_CH06_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH06_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH06);
}

#endif /* End of GPT_TAUB0_CH06_ISR_API == STD_ON */

#if (GPT_TAUB0_CH07_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH07_CAT2_ISR) || defined (TAUB0_CH07_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH07_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH07);
}

#endif /* End of GPT_TAUB0_CH07_ISR_API == STD_ON */

#if (GPT_TAUB0_CH08_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH08_CAT2_ISR) || defined (TAUB0_CH08_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH08_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH08);
}

#endif /* End of GPT_TAUB0_CH08_ISR_API == STD_ON */

#if (GPT_TAUB0_CH09_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH09_CAT2_ISR) || defined (TAUB0_CH09_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH09_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH09);
}

#endif /* End of GPT_TAUB0_CH09_ISR_API == STD_ON */

#if (GPT_TAUB0_CH10_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH10_CAT2_ISR) || defined (TAUB0_CH10_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH10_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH10);
}

#endif /* End of GPT_TAUB0_CH10_ISR_API == STD_ON */

#if (GPT_TAUB0_CH11_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH11_CAT2_ISR) || defined (TAUB0_CH11_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH11_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH11);
}

#endif /* End of GPT_TAUB0_CH11_ISR_API == STD_ON */

#if (GPT_TAUB0_CH12_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH12_CAT2_ISR) || defined (TAUB0_CH12_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH12_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH12);
}

#endif /* End of GPT_TAUB0_CH12_ISR_API == STD_ON */

#if (GPT_TAUB0_CH13_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH13_CAT2_ISR) || defined (TAUB0_CH13_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH13_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH13);
}

#endif /* End of GPT_TAUB0_CH13_ISR_API == STD_ON */

#if (GPT_TAUB0_CH14_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH14_CAT2_ISR) || defined (TAUB0_CH14_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH14_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH14);
}

#endif /* End of GPT_TAUB0_CH14_ISR_API == STD_ON */

#if (GPT_TAUB0_CH15_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH15_CAT2_ISR) || defined (TAUB0_CH15_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB0_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH15_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB0_CH15);
}

#endif /* End of GPT_TAUB0_CH15_ISR_API == STD_ON */

#if (GPT_TAUB1_CH00_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH00_CAT2_ISR) || defined (TAUB1_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH00_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH00);
}

#endif /* End of GPT_TAUB1_CH00_ISR_API == STD_ON */

#if (GPT_TAUB1_CH01_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH01_CAT2_ISR) || defined (TAUB1_CH01_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH01_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH01);
}

#endif /* End of GPT_TAUB1_CH01_ISR_API == STD_ON */

#if (GPT_TAUB1_CH02_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH02_CAT2_ISR) || defined (TAUB1_CH02_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH02_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH02);
}

#endif /* End of GPT_TAUB1_CH02_ISR_API == STD_ON */

#if (GPT_TAUB1_CH03_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH03_CAT2_ISR) || defined (TAUB1_CH03_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH03_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH03);
}

#endif /* End of GPT_TAUB1_CH03_ISR_API == STD_ON */

#if (GPT_TAUB1_CH04_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH04_CAT2_ISR) || defined (TAUB1_CH04_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH04_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH04);
}

#endif /* End of GPT_TAUB1_CH04_ISR_API == STD_ON */

#if (GPT_TAUB1_CH05_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH05_CAT2_ISR) || defined (TAUB1_CH05_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH05_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH05);
}

#endif /* End of GPT_TAUB1_CH05_ISR_API == STD_ON */

#if (GPT_TAUB1_CH06_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH06_CAT2_ISR) || defined (TAUB1_CH06_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH06_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH06);
}

#endif /* End of GPT_TAUB1_CH06_ISR_API == STD_ON */

#if (GPT_TAUB1_CH07_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH07_CAT2_ISR) || defined (TAUB1_CH07_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH07_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH07);
}

#endif /* End of GPT_TAUB1_CH07_ISR_API == STD_ON */

#if (GPT_TAUB1_CH08_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH08_CAT2_ISR) || defined (TAUB1_CH08_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH08_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH08);
}

#endif /* End of GPT_TAUB1_CH08_ISR_API == STD_ON */

#if (GPT_TAUB1_CH09_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH09_CAT2_ISR) || defined (TAUB1_CH09_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH09_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH09);
}

#endif /* End of GPT_TAUB1_CH09_ISR_API == STD_ON */

#if (GPT_TAUB1_CH10_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH10_CAT2_ISR) || defined (TAUB1_CH10_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH10_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH10);
}

#endif /* End of GPT_TAUB1_CH10_ISR_API == STD_ON */

#if (GPT_TAUB1_CH11_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH11_CAT2_ISR) || defined (TAUB1_CH11_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH11_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH11);
}

#endif /* End of GPT_TAUB1_CH11_ISR_API == STD_ON */

#if (GPT_TAUB1_CH12_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH12_CAT2_ISR) || defined (TAUB1_CH12_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH12_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH12);
}

#endif /* End of GPT_TAUB1_CH12_ISR_API == STD_ON */

#if (GPT_TAUB1_CH13_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH13_CAT2_ISR) || defined (TAUB1_CH13_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH13_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH13);
}

#endif /* End of GPT_TAUB1_CH13_ISR_API == STD_ON */

#if (GPT_TAUB1_CH14_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH14_CAT2_ISR) || defined (TAUB1_CH14_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH14_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH14);
}

#endif /* End of GPT_TAUB1_CH14_ISR_API == STD_ON */

#if (GPT_TAUB1_CH15_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH15_CAT2_ISR) || defined (TAUB1_CH15_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUB1_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH15_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUB1_CH15);
}

#endif /* End of GPT_TAUB1_CH15_ISR_API == STD_ON */

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
 ** Re-entrancy          : Reentrant
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
 ** Function(s) invoked  : Gpt_CbkNotification
 **
 ** Registers Used       : None
 **
 ******************************************************************************/
/* Implements GPT_ESDD_UD_050 */
/* Implements EAAR_PN0080_FR_0015 */
#if (GPT_TAUJ0_CH00_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH00_CAT2_ISR) || defined (TAUJ0_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ0_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ0_CH00_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ0_CH00);
}

#endif /* End of GPT_TAUJ0_CH00_ISR_API == STD_ON */

#if (GPT_TAUJ0_CH01_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH01_CAT2_ISR) || defined (TAUJ0_CH01_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ0_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ0_CH01_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ0_CH01);
}

#endif /* End of GPT_TAUJ0_CH01_ISR_API == STD_ON */

#if (GPT_TAUJ0_CH02_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH02_CAT2_ISR) || defined (TAUJ0_CH02_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ0_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ0_CH02_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ0_CH02);
}

#endif /* End of GPT_TAUJ0_CH02_ISR_API == STD_ON */

#if (GPT_TAUJ0_CH03_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH03_CAT2_ISR) || defined (TAUJ0_CH03_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ0_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ0_CH03_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ0_CH03);
}

#endif /* End of GPT_TAUJ0_CH03_ISR_API == STD_ON */

#if (GPT_TAUJ1_CH00_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH00_CAT2_ISR) || defined (TAUJ1_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ1_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ1_CH00_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ1_CH00);
}
#endif /* End of GPT_TAUJ1_CH00_ISR_API == STD_ON */

#if (GPT_TAUJ1_CH01_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH01_CAT2_ISR) || defined (TAUJ1_CH01_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ1_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ1_CH01_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ1_CH01);
}
#endif /* End of GPT_TAUJ1_CH01_ISR_API == STD_ON */

#if (GPT_TAUJ1_CH02_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH02_CAT2_ISR) || defined (TAUJ1_CH02_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ1_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ1_CH02_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ1_CH02);
}
#endif /* End of GPT_TAUJ1_CH02_ISR_API == STD_ON */

#if (GPT_TAUJ1_CH03_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH03_CAT2_ISR) || defined (TAUJ1_CH03_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ1_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ1_CH03_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ1_CH03);
}
#endif /* End of GPT_TAUJ1_CH03_ISR_API == STD_ON */

#if (GPT_TAUJ2_CH00_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH00_CAT2_ISR) || defined (TAUJ2_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ2_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ2_CH00_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ2_CH00);
}
#endif /* End of GPT_TAUJ2_CH00_ISR_API == STD_ON */

#if (GPT_TAUJ2_CH01_ISR_API == STD_ON)

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH01_CAT2_ISR) || defined (TAUJ2_CH01_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ2_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ2_CH01_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ2_CH01);
}
#endif /* End of GPT_TAUJ2_CH01_ISR_API == STD_ON */

#if (GPT_TAUJ2_CH02_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH02_CAT2_ISR) || defined (TAUJ2_CH02_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ2_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ2_CH02_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ2_CH02);
}
#endif /* End of GPT_TAUJ2_CH02_ISR_API == STD_ON */

#if (GPT_TAUJ2_CH03_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH03_CAT2_ISR) || defined (TAUJ2_CH03_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ2_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ2_CH03_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ2_CH03);
}
#endif /* End of GPT_TAUJ2_CH03_ISR_API == STD_ON */

#if (GPT_TAUJ3_CH00_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH00_CAT2_ISR) || defined (TAUJ3_CH00_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ3_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ3_CH00_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ3_CH00);
}
#endif /* End of GPT_TAUJ3_CH00_ISR_API == STD_ON */

#if (GPT_TAUJ3_CH01_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH01_CAT2_ISR) || defined (TAUJ3_CH01_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ3_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ3_CH01_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ3_CH01);
}
#endif /* End of GPT_TAUJ3_CH01_ISR_API == STD_ON */

#if (GPT_TAUJ3_CH02_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH02_CAT2_ISR) || defined (TAUJ3_CH02_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ3_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ3_CH02_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ3_CH02);
}
#endif /* End of GPT_TAUJ3_CH02_ISR_API == STD_ON */

#if (GPT_TAUJ3_CH03_ISR_API == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH03_CAT2_ISR) || defined (TAUJ3_CH03_CAT2_ISR)
/* Implements GPT_ESDD_UD_113 */
ISR(TAUJ3_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements GPT_ESDD_UD_112 */
_INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ3_CH03_ISR(void)
#endif
{
  Gpt_CbkNotification(GPT_TAUJ3_CH03);
}
#endif /* End of GPT_TAUJ3_CH03_ISR_API == STD_ON */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define GPT_STOP_SEC_CODE_FAST
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 **                          End of File                                      **
 ******************************************************************************/
