/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_Irq.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the MCU Driver Component.                                 */
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
* V1.0.0:  07-Sep-2015 : Initial Version                                       *
* V2.1.0:  05-Aug-2016 : ARDAABD-408 - MCU_INTCWEND_ISR declaration also       *
*                        included in the SEC_CODE_FAST memory section to be    *
*                        consistent with the definition                        *
* V2.2.0:  09-Sep-2016 : ARDAABD-398 - Acceptance points implemented:          *
*                        History comments made more relevant                   *
* V2.3.0:  14-Oct-2016 : ARDAABD-473 - AUTOSAR 3.2.2 is not supported anymore  *
*                           - MCU_AR_HIGHER_VERSION is changed to 4.2.2        *
*                           - MCU_AR_LOWER_VERSION is changed to 4.0.3         *
*                           - Removed code related to AUTOSAR 3.2.2            *
* V2.3.1:  28-Oct-2016 : ARDAABD-473 - History numbering changed according to  *
*                        projects requirements                                 *
* V2.4.0:  31-Jan-2017 : ARDAABD-989 - Included macro MCU_MEMMAP_FILE instead  *
*                        Memmap.h file                                         *
* V2.5.0:  29-Aug-2017 : ARDAABD-2150 -Added QAC/MISRA Warnings justification. *
*                        Corrected QAC/MISRA Warning.                          *
* V2.5.1:  20-Jun-2018 : 1.As part of #ARDAABD-3850, traceability              *
*                        inconsistencies are corrected and requirement         *
*                        mapping is done.                                      *
*                        2.Updated Copyright year.                            */
/******************************************************************************/
#ifndef MCU_IRQ_H
#define MCU_IRQ_H
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for interrupt category definitions */
#include "Os.h"
/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR specification version information */

#define MCU_IRQ_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_IRQ_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_IRQ_AR_RELEASE_REVISION_VERSION    \
                                               MCU_AR_RELEASE_REVISION_VERSION

/* File version information */
#define MCU_IRQ_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION
#define MCU_IRQ_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION


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

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_START_SEC_CODE_FAST
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_MCU_FEINT_CAT2_ISR) || defined (MCU_FEINT_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern FUNC(void, MCU_FAST_CODE) MCU_FEINT_ISR(void);
#endif


#if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && (MCU_INTCWEND_ISR_ENABLE == STD_ON))
#if defined  (Os_MCU_INTCWEND_CAT2_ISR) || defined (MCU_INTCWEND_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, MCU_FAST_CODE) MCU_INTCWEND_ISR(void);
#endif /* defined  (Os_MCU_INTCWEND_CAT2_ISR) ||
                                          defined (MCU_INTCWEND_CAT2_ISR) */
#endif /*((MCU_LOW_POWER_SEQUENCER == STD_ON) &&
             (MCU_INTCWEND_ISR_ENABLE == STD_ON))*/
/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_STOP_SEC_CODE_FAST
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* MCU_IRQ_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
