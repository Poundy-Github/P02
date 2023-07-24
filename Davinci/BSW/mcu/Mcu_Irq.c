/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_Irq.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the MCU Driver Component                                  */
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
/*              Devices:        F1x                                           */
/*============================================================================*/

/* Implements: EAAR_PN0034_NR_0045                                            */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*                                                                             *
* V1.0.0: 10-Sep-2015 : Initial Version                                        *
* V1.0.1: 08-Jan-2016 : As part of the JIRA #ARDAAGA-156,                      *
*                       the register macro MCU_WUFC0 is replaced with          *
*                       WufReg_BaseAddress->ulWUFC0 in MCU_INTCWEND_ISR,       *
*                       MCU_FEINTF replaced with FEINTF and  MCU_FEINTFC       *
*                       replaced with FEINTFC in MCU_FEINT_ISR                 *
*                       (as per IOCommon.h file).                              *
* V2.0.0: 10-Jun-2016 : As part of the JIRA ARDAABD-398, Mask name changed from*
*                       MCU_LVIFEIF_MASK to MCU_LVILFEIFMSK_MASK               *
* V2.0.1: 14-Jun-2016 : As part of the JIRA ARDAABD-398,Review points from     *
*                       V2.0.0 Implemented : add history entry for charges made*
* V2.1.0: 09-Sep-2016 : As part of the JIRA ARDAABD-398,History entry for      *
*                       V2.0.0 rephrased for a better understanding            *
* V2.2.0: 14-Oct-2016 : As part of the JIRA ARDAABD-473,                       *
*                       - AUTOSAR 3.2.2 is not supported anymore               *
*                       - MCU_AR_HIGHER_VERSION is changed to 4.2.2            *
*                       - MCU_AR_LOWER_VERSION is changed to 4.0.3             *
*                       - Removed code related to AUTOSAR 3.2.2                *
* V2.2.1: 28-Oct-2016 : As part of the JIRA ARDAABD-473, History numbering     *
*                       changed according to projects requirements             *
* V2.3.0: 11-Nov-2016 : As part of the JIRA ARDAABD-947 - Revision history     *
*                       updated with acceptance points                         *
* V2.3.1: 29-Nov-2016 : As part of the JIRA ARDAABD-969 - Revision history     *
*                       updated after review                                   *
* V2.4.0: 17-Jan-2017 : As part of the JIRA ARDAABD-569 - Write verify         *
*                       procedure for WUFC0 added                              *
* V2.5.0: 31-Jan-2017 : As part of JIRA ARDAABD-989 - Included macro           *
*                       MCU_MEMMAP_FILE instead Memmap.h file                  *
* V2.6.0: 22-Feb-2017 : As part of JIRA ARDAABD-831 - Added else branch to if  *
* V2.7.0: 10-Mar-2017 : As part of JIRA ARDAABD-1210 - Traceability            *
*                       was added                                              *
* V2.8.0: 29-Aug-2017 : As part of JIRA ARDAABD-2150 -Added QAC/MISRA          *
*                       warnings justification.Corrected QAC/MISRA Warning.    *
* V2.9.0: 19-Sep-2017 : As part of JIRA ARDAABD-2346 - Use specific macros for *
*                       registers                                              *
* V2.10.0:10-Oct-2017 : As part of JIRA ARDAABD-2160 - Add include for         *
*                       Iocommon_Defines.h                                     *
* V2.11.0:12-Oct-2017 : As part of JIRA ARDAABD-2594 - Changes after QAC       *
* V2.11.1:11-Jul-2018 : 1. As part of JIRA ARDAABD-1358, Check added for       *
*                       servicing of INTLVIH interrupt.                        *
*                       2. As part of JIRA ARDAABD-3831, MCU_INTCWEND_ISR is   *
*                       updated clear WUF register for INTCWEND after checking *
*                       of McuINTCWENDEnable and indentations of code is       *
*                       corrected.                                             *
*                       3. As part of #ARDAABD-3850, traceability              *
*                       inconsistencies are corrected and requirement          *
*                       mapping is done.                                      */
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Iocommon_Defines.h"
/*Implements:  MCU130, SWS_Mcu_00130 */
/* Included for global variable initialization values */
#include "Mcu_PBTypes.h"

/* Implements: MCU213                                                         */
/* Included for module version information definitions required for Mcu_Irq.c */
#include "Mcu.h"

/* Included for ISR functions declaration */
#include "Mcu_Irq.h"

/*Implements:  MCU109, MCU111 */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
 /* Included for the declaration of the critical section protection functions */
    #include "SchM_Mcu.h"
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/

/* AUTOSAR release version information */
#define MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_IRQ_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_IRQ_C_AR_RELEASE_REVISION_VERSION \
                                           MCU_AR_RELEASE_REVISION_VERSION_VALUE


/* File version information */
#define MCU_IRQ_C_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION_VALUE
#define MCU_IRQ_C_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-1 and               */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/
/* 2.MISRA C RULE VIOLATION:                                                  */
/*Message        : (4:3138)Null statement is located close to other code or   */
/*                  comments                                                  */
/*Rule           : MISRA-C:2004 Rule 14.3                                     */
/*Justification  : An additional semi-colon is added to the critical section  */
/*                   macro to avoid static analysis warning.                  */
/*Verification   : However, part of the code is verified manually and it is   */
/*                   not having any impact.                                   */
/*Reference      : Look for START Msg(4:3138)-2 and END Msg(4:3138)-2 tags    */
/*                 in the code.                                               */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-3 and                           */
/*                 END Msg(4:0303)-3 tags in the code.                        */
/******************************************************************************/
/* 4.QAC Warning:                                                             */
/* Message       : (2:3141) Null statement does not occur on a line by itself.*/
/* Rule          : NA                                                         */
/* Justification : Function is exported from compiler.h                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3141)-4 and                           */
/*                 END Msg(2:3141)-4 tags in the code.                        */
/******************************************************************************/
/* 5.QAC Warning:                                                             */
/* Message       : (2:3109) Null statement follows other code on the same line*/
/* Rule          : NA                                                         */
/* Justification : Intended empty for function                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3109)-5 and                           */
/*                 END Msg(2:3109)-5 tags in the code.                        */
/******************************************************************************/
/* 6. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2814)-6 and              */
/*                 END Msg(2:2814)-6 tags in the code.                        */
/******************************************************************************/
/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0850)[C99] Macro argument is empty                      */
/* Rule          : MISRA-C:2004 Rule 1.1, 19.8                                */
/*                 REFERENCE - ISO-6.8.3 Macro Replacement - Semantics        */
/* Justification : Parameter of macro is void                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0850)-7 and                           */
/*                 END Msg(4:0850)-7 tags in the code.                        */
/******************************************************************************/


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (MCU_IRQ_AR_RELEASE_MAJOR_VERSION != MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Major Version"
#endif /* (MCU_IRQ_AR_RELEASE_MAJOR_VERSION !=
                                 MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION) */

#if (MCU_IRQ_AR_RELEASE_MINOR_VERSION != MCU_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Minor Version"
#endif

#if (MCU_IRQ_AR_RELEASE_REVISION_VERSION != \
                                   MCU_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Revision Version"
#endif /* (MCU_IRQ_AR_RELEASE_REVISION_VERSION != \
                                   MCU_IRQ_C_AR_RELEASE_REVISION_VERSION) */


#if (MCU_IRQ_SW_MAJOR_VERSION != MCU_IRQ_C_SW_MAJOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Software Major Version"
#endif /* (MCU_IRQ_SW_MAJOR_VERSION != MCU_IRQ_C_SW_MAJOR_VERSION) */

#if (MCU_IRQ_SW_MINOR_VERSION != MCU_IRQ_C_SW_MINOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Software Minor Version"
#endif /* (MCU_IRQ_SW_MINOR_VERSION != MCU_IRQ_C_SW_MINOR_VERSION) */

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : MCU_FEINT_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine for Low voltage indication
**
** Sync/Async            : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : None.
**
** Functions Invoked     : Dem_ReportErrorStatus
**
** Registers Used        : None
**
*******************************************************************************/
#if (MCU_LVI0_ISR == STD_ON)
/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_START_SEC_CODE_FAST
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements: EAAR_PN0075_FR_0029                                            */
/* Implements: EAAR_PN0034_FR_0024, EAAR_PN0034_NR_0073                       */
/* Implements: MCU_ESDD_UD_097, MCU_ESDD_UD_027                               */
/* Implements: EAAR_PN0075_FR_0029                                            */
/* Implements: EAAR_PN0034_FR_0024, EAAR_PN0034_NR_0073                       */
/* Implements: MCU_ESDD_UD_070                                                */
/* Defines the CAT2 interrupt mapping */
/* MISRA Violation: START Msg(4:3138)-2 */
/* MISRA Violation: START Msg(4:0303)-3 */
#if defined  (Os_MCU_FEINT_CAT2_ISR) || defined (MCU_FEINT_CAT2_ISR)
ISR(MCU_FEINT_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements: MCU_ESDD_UD_096                                                */
FUNC(void, MCU_FAST_CODE) MCU_FEINT_ISR(void)
#endif /* defined  (Os_MCU_FEINT_CAT2_ISR) || defined (MCU_FEINT_CAT2_ISR) */
{
    /* MISRA Violation: START Msg(2:3141)-4 */
    /* MISRA Violation: START Msg(4:0850)-7 */
    #ifndef Os_MCU_FEINT_CAT2_ISR
    #ifndef MCU_FEINT_CAT2_ISR
    G3K_FETRAP_ENTRY();
    #endif
    #endif
    /*END Msg(4:0850)-7 */
    /*END Msg(2:3141)-4 */
    if (MCU_LVILFEIFMSK_MASK  == (FEINTF & MCU_LVILFEIFMSK_MASK))
    {
        /* Report Error to DEM */
        Dem_ReportErrorStatus(MCU_E_LVI_FAILURE, DEM_EVENT_STATUS_FAILED);
        /* clear the Low-voltage indicator interrupt flag */
        FEINTFC = MCU_LVILFEIFMSK_MASK;
    }
    else if (MCU_LVIHFEIFMSK_MASK == (FEINTF & MCU_LVIHFEIFMSK_MASK))
    {
        /* clear the Low-voltage indicator interrupt flag */
        FEINTFC = MCU_LVIHFEIFMSK_MASK;
    }
    else
    {
        /*no action*/
    }
    /* MISRA Violation: START Msg(2:3141)-4 */
    /* MISRA Violation: START Msg(4:0850)-7 */
    #ifndef Os_MCU_FEINT_CAT2_ISR
    #ifndef MCU_FEINT_CAT2_ISR
    G3K_FETRAP_LEAVE();
    #endif
    #endif
    /*END Msg(4:0850)-7 */
    /*END Msg(2:3141)-4 */
}
/*END Msg(4:3138)-2 */
/*END Msg(4:0303)-3 */
/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_STOP_SEC_CODE_FAST
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* (MCU_LVI0_ISR == STD_ON) */

/*******************************************************************************
** Function Name         : MCU_INTCWEND_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine which indicates port
**                         Polling end interrupt for sequencer
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : MCU_WUFC0
**
*******************************************************************************/
/* Implements: MCU_ESDD_UD_105                                                */
#if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && (MCU_INTCWEND_ISR_ENABLE == STD_ON))
/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_START_SEC_CODE_FAST
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements: EAAR_PN0034_FR_0024, EAAR_PN0034_NR_0073                       */
/* Implements: MCU_ESDD_UD_156                                                */
/* Implements: EAAR_PN0034_FR_0024, EAAR_PN0034_NR_0073                       */
/* Defines the CAT2 interrupt mapping */
#if defined  (Os_MCU_INTCWEND_CAT2_ISR) || defined (MCU_INTCWEND_CAT2_ISR)
ISR(MCU_INTCWEND_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements: MCU_ESDD_UD_155                                                */
_INTERRUPT_ FUNC(void, MCU_FAST_CODE) MCU_INTCWEND_ISR(void)
#endif /* defined  (Os_MCU_INTCWEND_CAT2_ISR) || defined (MCU_INTCWEND_CAT2_ISR)
              */
{

    if ( Mcu_GpConfigPtr->ucINTCWEND == MCU_TRUE )
    {
        /* MISRA Violation: START Msg(4:3138)-2 */
        #if (MCU_WUF_CLEARISR == STD_ON)
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* QAC Warning: START Msg(2:3109)-5 */
        MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
        /*END Msg(2:3109)-5 */
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        /* QAC Warning: START Msg(2:2814)-6 */
        /* Clearing wakeup factor register for ICCWEND */
        MCU_WRITE_REG_ONLY(&WufReg_BaseAddress->ulWUFC0,
                        (MCU_ICCWEND_WAKEUP_FACTOR_CLR))
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufReg_BaseAddress->ulWUF0,
                                        MCU_WUF0_RESET_VALUE,
                                    MCU_ICCWEND_WAKEUP_FACTOR_CLR,
                                    MCU_INTCWEND_ISR_API_ID)
        /*END Msg(4:3138)-2 */
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        #endif /* MCU_WUF_CLEARISR == STD_ON */
        /*END Msg(2:2814)-6 */
    }
    else
    {
        /*no action*/
    }
}

/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_STOP_SEC_CODE_FAST
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /*((MCU_LOW_POWER_SEQUENCER == STD_ON) &&
          (MCU_INTCWEND_ISR_ENABLE == STD_ON))*/
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
