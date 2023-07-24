/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_LTTypes.h                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2019 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR Core Test driver Link Time Parameters.                */
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
 * V1.0.0:  27-Nov-2013    : Initial Version
 *
 * V1.0.1:  15-May-2014    : As per CR 464, following changes are made:
 *                           1. The Copyright information is updated.
 *                           2. The file 'CorTst.h' is removed and 'Std_Types.h'
 *                              is added in include section.
 *
 * V1.0.2:  09-Sep-2014    : As per CR 604 for Mantis issue #22252, following
 *                           changes are made:
 *                           1. File is updated for including Autosar R3.2
 *                              version information details.
 *                           2. Misra warning with justification is provided.
 *
 * V2.0.0:  31-Aug-2016    : #ARDAABD-476
 *                           1. Updated to ASR 4.2.2
 *
 * V2.0.1:  06-Sep-2016    : #ARDAABD-495
 *                           1. Updated copyright year
 *
 * V2.0.2:  07-Sep-2016    : #ARDAABD-495
 *                           1. Updated copyright year and revision history
 * V2.0.3:  22-Sep-2016    : #ARDAABD-476
 *                           1. Improved MemMap inclusion for 4.0.3 and 4.2.2
 * V2.0.4:  23-Sep-2016    : #ARDAABD-495
 *                           1.Remove tabs from code
 * V2.0.5:  21-Oct-2016    : #ARDAABD-896
 *                           1.Change the name of type CorTstSelect_ConfigType
 *                           to CorTst_ConfigType
 * V2.1.0:  24-Oct-2016    : #ARDAABD-574
 *                           1. Added declaration of CorTst_GstRemapFngIds
 * V2.1.1:  19-June-2018   : 1.Added justification for QAC Warning which cannot
 *                             be removed.
 *                           2.As a part of ARDAABD-3845,
 *                                          Added UD IDs for requirement
 *                                          traceability.
 *                           3.As a part of ARDAABD-3845,
 *                                          Added Requirements for Requirement
 *                                          traceability.
 *          08-Oct-2019    : The problem with the historical version caused.
 *                           The version doesn't need to be upgraded.
 *                           1. Columns Width has been amended to less than 80.
 *                           2. TAB has been deleted at Line 89, 92.
 *                           3.The Copyright has been changed to "2013 - 2019".
 */
/******************************************************************************/
#ifndef CORTST_LTTYPES_H
#define CORTST_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* AUTOSAR standard types */
#include "Std_Types.h"

/* Include configuration */
/* CORTST_LLTYPES_H_001: CORTST_ESDD_UD_046 */
#include "CorTst_Cfg.h"

/* Included for call-back functions declarations */
/* CORTST_LLTYPES_H_002: CORTST_ESDD_UD_046 */
#include "CorTst_Cbk.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define CORTST_LTTYPES_AR_RELEASE_MAJOR_VERSION    \
                                CORTST_CFG_AR_RELEASE_MAJOR_VERSION
#define CORTST_LTTYPES_AR_RELEASE_MINOR_VERSION    \
                                CORTST_CFG_AR_RELEASE_MINOR_VERSION
#define CORTST_LTTYPES_AR_RELEASE_REVISION_VERSION \
                                CORTST_CFG_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define CORTST_LTTYPES_SW_MAJOR_VERSION   CORTST_SW_MAJOR_VERSION
#define CORTST_LTTYPES_SW_MINOR_VERSION   CORTST_SW_MINOR_VERSION

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                              QAC Warnings                                  **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* CORTST_LLTYPES_H_003:  CORTST_ESDD_UD_029                                  */
/* CORTST_LLTYPES_H_004:  CorTst144                                           */
/* CORTST_LLTYPES_H_005:  SWS_CorTst_00144, SWS_CorTst_00008                  */
/* Structure of function pointer for Callback notification function */
typedef struct STag_CorTst_NotifyFuncType
{
  /* Pointer to callback notification */
  P2FUNC (void, CORTST_APPL_CODE, pTestCompleteNotificationPointer)
                                                        (CorTst_ErrOkType);
} CorTst_NotifyFuncType;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/

#define CORTST_START_SEC_CONST_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Prototype for the test completed notification function */
extern CONST(CorTst_NotifyFuncType, CORTST_CONST)CorTst_GstTestNotifyFunc;

#define CORTST_STOP_SEC_CONST_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define CORTST_START_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for Back ground Core Test Configuration */
/* CORTST_LLTYPES_H_006:  CORTST_ESDD_UD_037                                  */

extern CONST (CorTst_ConfigType, CORTST_CONST)
                                                  CorTst_GstBGModeSelConfig[];
/* END Msg(4:3684)-1 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for Fore ground Core Test Configuration */
/* CORTST_LLTYPES_H_007:  CORTST_ESDD_UD_038                                  */
/* CORTST_LLTYPES_H_008:  CorTst159_Conf                                      */
extern CONST (CorTst_ConfigType, CORTST_CONST)
                                                  CorTst_GstFGModeSelConfig[];

/* Declaration for foreground id remapping array */
/* CORTST_LLTYPES_H_009:  CORTST_ESDD_UD_066                                  */
extern CONST(CorTst_ForegroundIdRemap, CORTST_CONST)
                                                  CorTst_GstRemapFngIds[];

/* END Msg(4:3684)-1 */

#define CORTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define CORTST_START_SEC_BUFFER_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* MISRA Violation: START Msg(4:3684)-1 */
/* Buffer to store result of each core test */
extern VAR(volatile long, AUTOMATIC)CorTst_GulResult[];
/* END Msg(4:3684)-1 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Buffer to store NOT result of each core test */
extern VAR(volatile long, AUTOMATIC)CorTst_GulNotResult[];
/* END Msg(4:3684)-1 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Buffer to store signature of each core test */
extern VAR(volatile long, AUTOMATIC)CorTst_GulSignature[];
/* END Msg(4:3684)-1 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Buffer to store NOT signature of each core test */
extern VAR(volatile long, AUTOMATIC)CorTst_GulNotSignature[];
/* END Msg(4:3684)-1 */

#define CORTST_STOP_SEC_BUFFER_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CORTST_LTTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
