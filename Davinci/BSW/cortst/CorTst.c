/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst.c                                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2019 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API implementations of Core Test Driver Component.      */
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
 * V1.0.1:  15-May-2014    : As per CR 464, following changes are made:
 *                           1. The Copyright information is updated.
 *                           2. The DET report 'CORTST_E_BGNDTEST_RUNNING' is
 *                              included in 'CorTst_Start' function call.
 *                           3. File is updated as per coding guidelines.
 *                           4. The functions 'CorTst_Init', 'CorTst_DeInit' and
 *                              'CorTst_MainFunction' are modified to include
 *                              global variable 'CorTst_GVar.CorTst_GucTestRuns'
 *                              holds atleast one test module is tested.
 * V1.0.2:  19-Jun-2014    : As per CR 525, File is updated as per coding
 *                           guidelines.
 * V1.0.3:  07-Jul-2014    : As per CR 542, following changes are made:
 *                           1. CorTst_MainFunction is updated to support the
 *                              restart after completion of test again and to
 *                              provide the critical section protection.
 *                           2. CorTst_MainFunction and CorTst_Start functions
 *                              are updated for DEM report only after each test
 *                              module and CorTst_Start function is updated with
 *                              providing critical section protection functions
 *                              at required lines of code.
 *                           3. The functions 'CorTst_Init', 'CorTst_DeInit' and
 *                              'CorTst_MainFunction' are modified to include
 *                              'CorTst_GVar.CorTst_GblBgndTestError' variable
 *                              holds atleast one test module is failed.
 * V1.0.4:  09-Sep-2014    : As per CR 604 for Mantis issue #22252, following
 *                           changes are made:
 *                           1. File is updated for including Autosar R3.2
 *                              version check and information details.
 *                           2. File is updated for avoiding the QAC misra
 *                              warning and for providing justifications.
 *                           3. File is updated as per Renesas coding
 *                              guidelines.
 *                           4. CorTst_Internal.h file is included to get the
 *                              swg3k library function prototype.
 * V1.0.5:  31-Dec-2014    : As per Mantis issue #24187, following
 *                           changes are made:
 *                           1. semicolon added.
 *                           2. MISRA warning message (4:3138) is added.
 * V1.0.6:  18-May-2015    : As per mantis #26209, File is updated for
 *                           critical section names of enter and exit
 *                           functions.
 * V2.0.0:  22-Aug-2016    : #ARDAABD-573
 *                           1. Updated CorTst library to G3KH RC3 v1.20
 * V2.0.1:  02-Sep-2016    : #ARDAABD-476
 *                           1. Updated to ASR 4.2.2
 * V2.0.2:  06-Sep-2016    : #ARDAABD-495
 *                           1. Updated copyright year
 * V2.0.3:  07-Sep-2016    : #ARDAABD-476
 *                           1. Updated Revision History and copyright year
 * V2.0.4:  22-Sep-2016    : #ARDAABD-476
 *                           1. Improved MemMap inclusion for 4.0.3 and 4.2.2
 * V2.0.5:  23-Sep-2016    : #ARDAABD-495
 *                           1. Initialization of variables was updated,
 *                           all variables are declared and initialized in
 *                           2 separate statements
 * V2.0.6:  23-Sep-2016    : #ARDAABD-495
 *                           1. Remove tabs from code
 * V2.0.7:  25-Sep-2016    : #ARDAABD-722
 *                           1. CORTST_C_SW_MINOR_VERSION, changed from 0 to 1
 * V2.0.8:  26-Sep-2016    : #ARDAABD-580
 *                           1. Removed 'else' from CorTst_MainFunction(),
 *                              surrounding callback NULL_PTR check
 * V2.0.9:  20-Oct-2016    : #ARDAABD-899
 *                           1. Removed unwanted macros and replace
 *                              conditinos for ASR 4.2.2 with
 *                              CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION
 * V2.0.10: 21-Oct-2016    : #ARDAABD-896
 *                           1. Change the name of type CorTstSelect_ConfigType
 *                              to CorTst_ConfigType
 * V2.1.0:  21-Oct-2016    : #ARDAABD-574
 *                           1. Added private function CorTst_SearchVal
 *                           2. Modified CorTst_Start, added call to
 *                              CorTst_SearchVal which searches for input id in
 *                              CorTst_GstRemapFngIds and returns the index
 *                           3. CorTst_Start can accept any id from
 *                              configuration (does not have to be sequential)
 * V2.1.1:  24-Oct-2016    : #ARDAABD-897
 *                           1. CorTst_Init prototype shall have an input
 *                              parameter ConfigPtr
 * V2.1.2:  25-Oct-2016    : #ARDAABD-574
 *                           1. Updated function CorTst_SearchVal
 * V2.1.3:  25-Oct-2016    : #ARDAABD-574
 *                           1. Updated function CorTst_SearchVal according to
 *                              coding guidelines
 *                           2. Updated function CorTst_SearchVal declaration
 *                           3. Moved variable initialization after DET block
 *                              in CorTst_GetFgndSignature
 *                           4. Corrected index return value in CorTst_SearchVal
 * V2.1.4:  26-Oct-2016    : #ARDAABD-897
 *                           1. Remove part of code with (void)ConfigPtr;
 * V2.1.5:  26-Oct-2016    : #ARDAABD-833
 *                           1. Suppressed dataflow errors 2980 2814 2824 2877
 *                              0492 2984
 * V2.1.6:  26-Oct-2016    : #ARDAABD-928
 *                           1. Added traceability
 * V2.1.7:  26-Oct-2016    : #ARDAABD-574
 *                           1. Updated CorTst_Start() to correct DET error
 *                              CORTST_E_INVALID_PARAM generation
 *                           2. Updated CorTst_SearchVal() to return value
 *                              in case index is not found
 *                           3. Updated function CorTst_SearchVal() prototype
 * V2.1.8:  28-Oct-2016    : #ARDAABD-574
 *                           1. Updated CorTst_SearchVal() prototype and var
 *                              namings
 * V2.1.9:  08-Nov-2016    : #ARDAABD-939
 *                           1. Update section Version information
 * V2.2.0:  14-Nov-2016    : #ARDAABD-833
 *                           1. Corrected QAC warnings
 *                           2. Added fdg_idx check in CorTst_Start() in case
 *                              DET is disabled, then the test is ignored,
 *                              prevent out of bounds access
 * V2.2.1:  12-Dec-2016    : #ARDAABD-818
 *                           1. Surrounded CorTst_SearchVal with precompile
 *                              switches
 * V2.2.2:  18-Jan-2017    : #ARDAABD-818
 *                           1. Change the name of variable "fdg_idx" to
 *                              "LulFgndId"
 * V2.2.3:  19-Jan-2017    : #ARDAABD-580
 *                           1. Removed PRQA tags. QAC justifications are
 *                              are provided in report
 * V2.2.4:  14-Aug-2017    : Added justifications for MISRA Violations and QAC
 *                           Warnings which cannot be removed. Removed tags and
 *                           justification for MISRA Violation message (4:3138).
 * V2.2.5:  19-Jun-2018    : The following changes are made:
 *                           1.As part of ARDAABD-3013,
 *                             Updated CorTst_Start function.
 *                           2.As part of ARDAABD-3729,
 *                             Updated CorTst_DeInit function.
 *                           3.As part of ARDAABD-3499, added CORTST_UT_001.
 *                           4.Updated copyright information.
 *                           5.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           6.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 * V2.2.6:  14-Oct-2019    : The following changes are made:
 *                           1.As part of ARDAABD-4639,
 *                             Handled QAC warnings.
 */
/******************************************************************************/

/*******************************************************************************
**                      General Traceability Section                          **
*******************************************************************************/
/* Implements   CORTST_ESDD_UD_009                                            */
/* Implements   CorTst003, CorTst006, CorTst007, CorTst023                    */
/* Implements   SWS_CorTst_00002, SWS_CorTst_00023, SWS_CorTst_00009          */
/* Implements   SWS_CorTst_00010, SWS_CorTst_00011, SWS_CorTst_00012          */
/* Implements   SWS_CorTst_00013, SWS_CorTst_00014, SWS_CorTst_00016          */

/* Implements  CORTST_ESDD_UD_002, CORTST_ESDD_UD_003, CORTST_ESDD_UD_004     */
/* Implements  EAAR_PN0034_NR_0087                                            */
/* Implements  EAAR_PN0034_NR_0088                                            */
/* Implements  CORTST_ESDD_UD_061, CORTST_ESDD_UD_062                         */

/* Implements  EAAR_PN0077_FR_0012                                            */
/* Implements  EAAR_PN0034_NR_0007, EAAR_PN0034_FR_0052  */
/* Implements  EAAR_PN0034_NR_0042, EAAR_PN0034_NR_0046  */
/* Implements  EAAR_PN0034_FR_0063  */
/* Implements  EAAR_PN0034_NR_0001  */
/* Implements  EAAR_PN0034_NR_0020  */
/* Implements  EAAR_PN0034_FR_0066  */
/* Implements  EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0020, EAAR_PN0034_FR_0026  */
/* Implements  EAAR_PN0034_NR_0012  */
/* Implements  EAAR_PN0034_FR_0065  */
/* Implements  EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0018  */
/* Implements  EAAR_PN0034_NR_0063, EAAR_PN0034_FR_0060, EAAR_PN0034_NR_0045  */
/* Implements  EAAR_PN0034_NR_0018  */
/* Implements  EAAR_PN0034_NR_0002, EAAR_PN0034_FR_0056  */
/* Implements  EAAR_PN0034_NR_0069  */
/* Implements  EAAR_PN0034_FR_0055  */
/* Implements  EAAR_PN0034_NR_0008  */
/* Implements  EAAR_PN0034_NR_0056  */
/* Implements  EAAR_PN0034_FR_0001, EAAR_PN0034_FR_0019  */
/* Implements  EAAR_PN0034_FR_0024, EAAR_PN0034_NR_0039  */
/* Implements  EAAR_PN0034_NR_0026  */
/* Implements  EAAR_PN0034_NR_0064  */
/* Implements  EAAR_PN0034_FR_0068, EAAR_PN0034_FR_0067                       */

/* Implements  EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002                     */
/* Implements  EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004                     */
/* Implements  EAAR_PN0034_FSR_0005, EAAR_PN0034_FSR_0006                     */
/* Implements  EAAR_PN0034_FSR_0007  */
/* Implements  EAAR_PN0034_FSR_0009, EAAR_PN0034_FSR_0010                     */
/* Implements  EAAR_PN0034_FSR_0011, EAAR_PN0034_FSR_0012                     */
/* Implements  EAAR_PN0034_FSR_0013                                           */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for macro definitions and type definitions */
/* Implements EAAR_PN0034_FR_0021 */
#include "CorTst.h"
/* Included for prototypes for low level library functions */
#include "CorTst_Internal.h"
/* Included for RAM variable declarations */
#include "CorTst_Ram.h"
/* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
/*Implements CorTst017, CorTst018 */
/*Implements CorTst018, CorTst082_Conf */
/* Implements ECUC_CorTst_00082 */
#if (CORTST_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif

/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/*Implements EAAR_PN0077_FR_0007, EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030 */
/*Implements EAAR_PN0034_FR_0061 */
/*Implements CORTST_ESDD_UD_022 */

#if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_CorTst.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*Implements CorTst022*/
/* AUTOSAR release version information */
#define CORTST_C_AR_RELEASE_MAJOR_VERSION  CORTST_AR_RELEASE_MAJOR_VERSION_VALUE
#define CORTST_C_AR_RELEASE_MINOR_VERSION  CORTST_AR_RELEASE_MINOR_VERSION_VALUE
#define CORTST_C_AR_RELEASE_REVISION_VERSION \
                                        CORTST_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define CORTST_C_SW_MAJOR_VERSION      CORTST_SW_MAJOR_VERSION_VALUE
#define CORTST_C_SW_MINOR_VERSION      CORTST_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/*Implements CorTst022*/
#if (CORTST_AR_RELEASE_MAJOR_VERSION != CORTST_C_AR_RELEASE_MAJOR_VERSION)
  #error "CorTst.c : Mismatch in Release Major Version"
#endif

#if (CORTST_AR_RELEASE_MINOR_VERSION != CORTST_C_AR_RELEASE_MINOR_VERSION)
  #error "CorTst.c : Mismatch in Release Minor Version"
#endif

#if (CORTST_AR_RELEASE_REVISION_VERSION != CORTST_C_AR_RELEASE_REVISION_VERSION)
  #error "CorTst.c : Mismatch in Release Revision Version"
#endif

#if (CORTST_SW_MAJOR_VERSION != CORTST_C_SW_MAJOR_VERSION)
  #error "CorTst.c : Mismatch in Software Major Version"
#endif

#if (CORTST_SW_MINOR_VERSION != CORTST_C_SW_MINOR_VERSION)
  #error "CorTst.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Implements CORTST_ESDD_UD_018*/
/* Implements ECUC_CorTst_00093 */
#if (CORTST_START_API == STD_ON)
#define CORTST_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

FUNC(STATIC CorTst_TestIdFgndType, CORTST_PRIVATE_CODE) CorTst_SearchVal
        ( VAR(CorTst_TestIdFgndType AUTOMATIC, CORTST_APPL_DATA) LenSearchId );

#define CORTST_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* #if (CORTST_START_API == STD_ON) */

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : Pointer to the configuration array is used and verified    */
/*                 when accessing the boolean parameter value.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-1 and                           */
/*                 END Msg(4:0491)-1 tags in the code.                        */

/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4470) A non-constant expression of 'essentially signed' */
/*                 type (signed short) is being passed to a function          */
/*                 parameter of wider signed type, 'int'.                     */
/* Rule          : MISRA-C:2004 Rule 10.1                                     */
/* Justification : The variable which is used of unsigned type and it can not */
/*                 be signed type for module implementation.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4470)-2 and                           */
/*                 END Msg(4:4470)-2 tags in the code.                        */

/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2991) The value of this 'if' controlling expression     */
/*                 is always 'true'.                                          */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Caused by activation of DET mechanism, the 'if' controlling*/
/*                 expression implements functional requirement.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-4 and                           */
/*                 END Msg(4:2991)-4 tags in the code.                        */

/******************************************************************************/
/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Caused by activation of DET mechanism, the 'if' controlling*/
/*                 expression implements functional requirement.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-5 and                           */
/*                 END Msg(4:2995)-5 tags in the code.                        */

/******************************************************************************/
/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0715) Nesting of control structures (statements)        */
/*                 exceeds 15 - program does not conform strictly to ISO:C90. */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : Caused by activation of DET mechanism, the 'if-else' block */
/*                 control implements functional requirement.                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0715)-6 and                           */
/*                 END Msg(4:0715)-6 tags in the code.                        */

/******************************************************************************/
/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2877) This loop will never be executed more than once.  */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Values for CORTST_FGND_TEST_NUMBER are configurable        */
/*                 message is reported for value 1.                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2877)-7 and                           */
/*                 END Msg(4:2877)-7 tags in the code.                        */

/******************************************************************************/
/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation is redundant. The value of the     */
/*                 result is always '1'.                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Values for CORTST_FGND_TEST_NUMBER are configurable        */
/*                 message is reported for value 1.                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-8 and                           */
/*                 END Msg(4:2984)-8 tags in the code.                        */

/******************************************************************************/
/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:1257) An integer constant suffixed with L or LL is      */
/*                 being converted to a type of lower rank on assignment      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Value for RUN MODE is configurable with 0                  */
/*                 Message is reported for value OUL.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:1257)-9 and                           */
/*                 END Msg(4:1257)-9 tags in the code.                        */

/******************************************************************************/
/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:1291)  An integer constant of 'essentially unsigned'    */
/*                 type is being converted to signed type on assignment.      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Value for RUN MODE is configurable with 0                  */
/*                 Message is reported for value OUL.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:1291)-10 and                          */
/*                 END Msg(4:1291)-10 tags in the code.                       */

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

/* 2. QAC Warning:                                                            */
/* Message       : (2:0862) This #include "MemMap.h" directive is redundant.  */
/* Justification : Each header has implemented safety for multiple inclusion. */
/*                 Header will not be included multiple times.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3227) The parameter is never modified and so it could   */
/*                 be declared with the 'const' qualifier.                    */
/* Justification : Parameter is not declared with the 'const' qualifier in    */
/*                 order to respect AUTOSAR SWS and module requirements.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-3 and                           */
/*                 END Msg(2:3227)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Justification : Pointer is generated by configurator tool, which ensures   */
/*                 that is not a NULL pointer                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-4 and                           */
/*                 END Msg(2:2814)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Justification : Pointer is generated by configurator tool, which ensures   */
/*                 that is not a NULL pointer                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-5 and                           */
/*                 END Msg(2:2824)-5 tags in the code.                        */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : (2:3204) The variable 'LpRemapArr' is only set once and so */
/*                 it could be declared with the 'const' qualifier.           */
/* Justification : Variable 'LpRemapArr' is declare with const qualifier,     */
/*                 thus the QAC message is invalid.                           */
/* Verification  : Part of the code is verified manually and it is            */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3204)-6 and                           */
/*                 END Msg(2:3204)-6 tags in the code.                        */
/******************************************************************************/

/* 7. QAC Warning:                                                            */
/* Message       : (2:3206) The parameter 'ConfigPtr' is not used in          */
/*                 this function.                                             */
/* Justification : Implicit requirement as specified by AUTOSAR SWS for AR422.*/
/* Verification  : Part of the code is verified manually and it is            */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-7 and                           */
/*                 END Msg(2:3206)-7 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/


/*******************************************************************************
** Function Name         : CorTst_Init
**
** Service ID            : 0x00
**
** Description           : This API is for initialization and change the state
**                         of Core Test module.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : For ASR 4.0.3: None
**                         For ASR 4.2.2: ConfigPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : CorTst_GVar.CorTst_GulIntervalId,
**                         CorTst_GVar.CorTst_GulLastBgndSignature,
**                         CorTst_GVar.CorTst_GulLastFgndSignature,
**                         CorTst_GVar.CorTst_GenTestResult,
**                         CorTst_GenExeStatus,
**                         CorTst_GVar.CorTst_GenBGStatus,
**                         CorTst_GVar.CorTst_GulCfgIndex,
**                         CorTst_GVar.CorTst_GusTestId,
**                         CorTst_GVar.CorTst_GblBgndSigAvailable,
**                         CorTst_GVar.CorTst_GblFgndSigAvailable,
**                         CorTst_GstBGModeSelConfig, CorTst_GpSTModule,
**                         CorTst_GVar.CorTst_GucTestRuns,
**                         CorTst_GVar.CorTst_GblBgndTestError,
**                         CorTst_GblNewIntervalStarted
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements  CORTST_ESDD_UD_048, CORTST_ESDD_UD_082                         */
/* Implements  CorTst040, CorTst041, CorTst0179, CorTst042, CorTst0178        */
/* Implements  CorTst183, CorTst153, SWS_CorTst_00040                         */
/* Implements  SWS_CorTst_01004, SWS_CorTst_00041, SWS_CorTst_00179           */
/* Implements  SWS_CorTst_00042, SWS_CorTst_00178, SWS_CorTst_00044           */
/* Implements  SWS_CorTst_00183                                               */
/* Implements  CORTST_ESDD_UD_062, CORTST_ESDD_UD_023, EAAR_PN0077_FR_0008    */
/* Implements  EAAR_PN0077_NR_0002, EAAR_PN0077_NR_0003, EAAR_PN0077_FR_0013  */
/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0034_FR_0049, EAAR_PN0077_FR_0006  */
/* Implements  CORTST_ESDD_UD_063                                             */

#if (CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:3206)-7 */
/* Implements  CORTST_ESDD_UD_074*/
FUNC(void, CORTST_PUBLIC_CODE) CorTst_Init
          ( P2CONST(CorTst_ConfigType, AUTOMATIC, CORTST_APPL_DATA) ConfigPtr )
/* END Msg(2:3206)-7 */
/* Implements  CORTST_ESDD_UD_063                                             */
#elif (CORTST_AR_VERSION == CORTST_AR_LOWER_VERSION)
FUNC(void, CORTST_PUBLIC_CODE) CorTst_Init(void)
#endif
{
  /* Implements CORTST_ESDD_UD_027 */
  /* Implements CorTst087_Conf */
  /* Implements ECUC_CorTst_00087 */
  #if (CORTST_BGND_TEST_CFG_AVAILABLE == STD_ON)
  /* Pointer to the CorTst BGND mode selection Configuration type structure */
  P2CONST(CorTst_ConfigType, CORTST_VAR, CORTST_CONFIG_CONST)
                                                        LpCorTstBGModeConfig;
  #endif
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements CORTST_ESDD_UD_021 */
  #if (CORTST_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Check if the module execution state is initialized */
  if (CORTST_UNINIT != CorTst_GenExeStatus)
  {
    /* Report error to DET if CORTST module is already initialized */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                                CORTST_INIT_SID, CORTST_E_ALREADY_INITIALIZED);
  }
  else
  #endif /* #if (CORTST_ALREADY_INIT_DET_CHECK == STD_ON) */
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
  /* Implements CORTST_ESDD_UD_027 */
  /* Implements ECUC_CorTst_00087 */
    #if (CORTST_BGND_TEST_CFG_AVAILABLE == STD_ON)
    /* Get the pointer to CorTst BGND mode selection Configuration array */
  /* Implements CORTST_ESDD_UD_037 */
    LpCorTstBGModeConfig = &CorTst_GstBGModeSelConfig[CORTST_ZERO];
    /*
     * Get the pointer to CorTst Configuration array contains ST modules
     * selection values.
     */
    CorTst_GpSTModule = &LpCorTstBGModeConfig->blCorTstModule[CORTST_ZERO];
    #endif
    /* Initialize the global variable Test Interval Id to zero */
    CorTst_GVar.CorTst_GulIntervalId = CORTST_ZERO;
    /* Initialize the global variable Background Test signature to zero */
    CorTst_GVar.CorTst_GulLastBgndSignature = CORTST_ZERO;
    /* Initialize the global variable Foreground Test signature to zero */
    CorTst_GVar.CorTst_GulLastFgndSignature = CORTST_ZERO;
    /* Set the global variable Test result to Test not performed */
  /* Implements CorTst086_Conf */
    CorTst_GVar.CorTst_GenTestResult = CORTST_E_NOT_TESTED;
    /* Set the execution state to Initialized */
    CorTst_GenExeStatus = CORTST_INIT;
    /* Set the Background test status of last configuration to complete */
    CorTst_GVar.CorTst_GenBGStatus = CORTST_BGND_COMPLETE;
    /* Set the Background configuration set index variable to zero */
    CorTst_GVar.CorTst_GulCfgIndex = CORTST_ZERO;
    /* Set the Test Id of number of tests available in Background to one */
    CorTst_GVar.CorTst_GusTestId = CORTST_ONE;
    /* Set the variable to indicate Background signature not available */
    CorTst_GVar.CorTst_GblBgndSigAvailable = CORTST_FALSE;
    /* Set the variable to indicate Foreground signature not available */
    CorTst_GVar.CorTst_GblFgndSigAvailable = CORTST_FALSE;
    /* Set the variable to store atleast one test module is tested to zero */
    CorTst_GVar.CorTst_GucTestRuns = (uint8)CORTST_ZERO;
    /* Set the variable to store atleast one test module is failed to false */
    CorTst_GVar.CorTst_GblBgndTestError = CORTST_FALSE;
    /* Set the variable to store the status of new IntervalId */
    CorTst_GVar.CorTst_GblNewIntervalStarted = CORTST_FALSE;
  }
} /* End of API CorTst_Init */

#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : CorTst_DeInit
**
** Service ID            : 0x01
**
** Description           : This API is to change the State of the Core Test
**                         module to Uninitialized.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
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
** Global Variables Used : CorTst_GVar.CorTst_GulIntervalId,
**                         CorTst_GVar.CorTst_GulLastBgndSignature,
**                         CorTst_GVar.CorTst_GulLastFgndSignature,
**                         CorTst_GVar.CorTst_GenTestResult,
**                         CorTst_GenExeStatus,
**                         CorTst_GVar.CorTst_GenBGStatus,
**                         CorTst_GVar.CorTst_GulCfgIndex,
**                         CorTst_GVar.CorTst_GusTestId,
**                         CorTst_GVar.CorTst_GblBgndSigAvailable,
**                         CorTst_GVar.CorTst_GblFgndSigAvailable,
**                         CorTst_GVar.CorTst_GucTestRuns,
**                         CorTst_GVar.CorTst_GblBgndTestError,
**                         CorTst_GblNewIntervalStarted
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements  CORTST_ESDD_UD_049, CORTST_ESDD_UD_083                         */
/* Implements  CorTst045, CorTst046, CorTst04, CorTst136, CorTst149           */
/* Implements  CorTst183, CorTst153                                           */
/* Implements  SWS_CorTst_00045, SWS_CorTst_00046, SWS_CorTst_00047           */
/* Implements  SWS_CorTst_000136, SWS_CorTst_00149                            */
/* Implements  SWS_CorTst_00136                                               */

/* Implements  EAAR_PN0077_FR_0012                                            */
/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006                       */
/* Implements  EAAR_PN0034_NR_0087                                            */
/* Implements  EAAR_PN0034_NR_0088                                            */
/* Implements  CORTST_ESDD_UD_002, CORTST_ESDD_UD_003, CORTST_ESDD_UD_004     */
/* Implements  CORTST_ESDD_UD_061, CORTST_ESDD_UD_062                         */
/* Implements  EAAR_PN0034_FR_0049, EAAR_PN0077_NR_0002, EAAR_PN0077_NR_0003  */
FUNC(void, CORTST_PUBLIC_CODE) CorTst_DeInit(void)
{
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Check if the module is not initialized */
  if (CORTST_UNINIT == CorTst_GenExeStatus)
  {
    /* Report error to DET if module is not initialized */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                                         CORTST_DEINIT_SID, CORTST_E_UNINIT);
  }
  else
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check is the module is in initialized or abort state */
  /* Implements CorTst046, CorTst047, CorTst136 */
    if ((CORTST_INIT == CorTst_GenExeStatus) ||
                       (CORTST_ABORT == CorTst_GenExeStatus))
    {
      /* Set the global variable State to uninitialized */
      CorTst_GenExeStatus = CORTST_UNINIT;
      /* Initialize the global variable Test Id to zero */
      CorTst_GVar.CorTst_GulIntervalId = CORTST_ZERO;
      /* Initialize the global variable Background Test signature to zero */
      CorTst_GVar.CorTst_GulLastBgndSignature = CORTST_ZERO;
      /* Initialize the global variable Foreground Test signature to zero */
      CorTst_GVar.CorTst_GulLastFgndSignature = CORTST_ZERO;
      /* Set the global variable Test result to Test not performed */
      CorTst_GVar.CorTst_GenTestResult = CORTST_E_NOT_TESTED;
      /* Set the Background test status of last configuration to complete */
      CorTst_GVar.CorTst_GenBGStatus = CORTST_BGND_COMPLETE;
      /* Set the Background configuration set index to zero */
      CorTst_GVar.CorTst_GulCfgIndex = CORTST_ZERO;
      /* Set the Test Id of number of tests available in Background to one */
      CorTst_GVar.CorTst_GusTestId = (uint16)CORTST_ZERO;
      /* Set the variable to indicate Background signature not available */
      CorTst_GVar.CorTst_GblBgndSigAvailable = CORTST_FALSE;
      /* Set the variable to indicate Foreground signature not available */
      CorTst_GVar.CorTst_GblFgndSigAvailable = CORTST_FALSE;
      /* Set the variable to store atleast one test module is tested to zero */
      CorTst_GVar.CorTst_GucTestRuns = (uint8)CORTST_ZERO;
      /* Set the variable to store atleast one test module is failed to false */
      CorTst_GVar.CorTst_GblBgndTestError = CORTST_FALSE;
      /* Set the variable to store the status of new IntervalId */
      CorTst_GVar.CorTst_GblNewIntervalStarted = CORTST_FALSE;
    }
    /* Check is the module is in running back ground state */
    else
    {
    /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
    /* Implements CorTst018, CorTst017, CorTst020 */
    /* Implements CorTst082_Conf */
    /* Implements ECUC_CorTst_00082 */
      #if (CORTST_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET if CORTST module is running in BGND mode */
      (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                               CORTST_DEINIT_SID, CORTST_E_STATUS_FAILURE);
      #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
    }
  }
} /* End of API CorTst_DeInit */

#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements CORTST_ESDD_UD_013 */
/* Implements ECUC_CorTst_00094 */
#if (CORTST_ABORT_API == STD_ON)
/*******************************************************************************
** Function Name         : CorTst_Abort
**
** Service ID            : 0x02
**
** Description           : This API is to change the state of Core Test module
**                         to Abort.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Component must be initialized using CorTst_Init().
**
** Global Variables Used : CorTst_GenExeStatus,
**                         CorTst_GVar.CorTst_GenTestResult
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements  EAAR_PN0034_NR_0087                                            */
/* Implements  EAAR_PN0034_NR_0088                                            */
/* Implements  EAAR_PN0077_FR_0012                                            */
/* Implements  CORTST_ESDD_UD_002, CORTST_ESDD_UD_003, CORTST_ESDD_UD_004     */
/* Implements  CORTST_ESDD_UD_061, CORTST_ESDD_UD_062                         */
/* Implements  EAAR_PN0077_NR_0002, EAAR_PN0077_NR_0003, EAAR_PN0034_FR_0049  */

/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006                       */
/* Implements  CORTST_ESDD_UD_050                                             */
/* Implements  CorTst048, CorTst049, CorTst105, CorTst050, CorTst051          */
/* Implements  CorTst044, CorTst094_Conf, CorTst152, CorTst183, CorTst153     */
/* Implements  SWS_CorTst_00048, SWS_CorTst_00049, SWS_CorTst_00105           */
/* Implements  SWS_CorTst_00050, SWS_CorTst_00051, SWS_CorTst_00052           */
/* Implements  SWS_CorTst_00152                                               */
FUNC(void, CORTST_PUBLIC_CODE) CorTst_Abort(void)
{
  /* Implements CorTst082_Conf */
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Set the DET return value to E_OK */
  LenReturnValue = E_OK;
  /* Check if the module is initialized */
  if (CORTST_UNINIT == CorTst_GenExeStatus)
  {
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                                         CORTST_ABORT_SID, CORTST_E_UNINIT);
    /* Set the DET return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * Check is the module status is in initialized or in running BGND mode
     * state.
     */
    if ((CORTST_INIT == CorTst_GenExeStatus) ||
                       (CORTST_RUNNING_BGND == CorTst_GenExeStatus))
    {
      /* Set the global variable execution state to abort */
      CorTst_GenExeStatus = CORTST_ABORT;
      /* Set the global variable Test result to Test not performed */
      CorTst_GVar.CorTst_GenTestResult = CORTST_E_NOT_TESTED;
    }
    else
    {
      /* No action required */
    }
  }
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064*/
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif  /* CORTST_DEV_ERROR_DETECT == STD_ON */
} /* End of API CorTst_Abort */

#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (CORTST_ABORT_API == STD_ON) */

/* Implements CORTST_ESDD_UD_017*/
/* Implements ECUC_CorTst_00096*/
#if (CORTST_GET_STATE_API == STD_ON)
/*******************************************************************************
** Function Name         : CorTst_GetState
**
** Service ID            : 0x03
**
** Description           : This API Returns the Core Test module current state.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : CorTst_StateType
**
** Preconditions         : None
**
** Global Variables Used : CorTst_GenExeStatus
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements  CorTst140                                                      */
/* Implements  CORTST_ESDD_UD_051                                             */
/* Implements  CorTst053, CorTst054, CorTst096_Conf                           */
/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006, EAAR_PN0034_FR_0049  */
/* Implements  SWS_CorTst_00053, SWS_CorTst_00054                             */
FUNC(CorTst_StateType, CORTST_PUBLIC_CODE) CorTst_GetState(void)
{
  /* Local variable to store the module state */
  CorTst_StateType LenCorTstState;
  /* Read the current state of the driver */
  LenCorTstState = CorTst_GenExeStatus;
  /* return the current state of the driver */
  return(LenCorTstState);
} /* End of API CorTst_GetState */

#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (CORTST_GET_STATE_API == STD_ON) */
/* Implements CORTST_ESDD_UD_014 */
/* Implements CorTst104_Conf */
/* Implements ECUC_CorTst_00104 */
#if (CORTST_GET_CURRENT_STATUS_API == STD_ON)
/*******************************************************************************
** Function Name         : CorTst_GetCurrentStatus
**
** Service ID            : 0x04
**
** Description           : This API Returns the result of the last completed
**                         Core Test run and Test Interval Id of the last
**                         background test.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : ErrOk
**
** Return parameter      : None
**
** Preconditions         : Component must be initialized using CorTst_Init().
**
** Global Variables Used : CorTst_GenExeStatus,
**                         CorTst_GVar.CorTst_GulIntervalId,
**                         CorTst_GVar.CorTst_GenTestResult
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements  SWS_CorTst_00055 */
/* Implements  SWS_CorTst_00056 */
/* Implements  CorTst055 */
/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006, EAAR_PN0034_FR_0049  */
/* Implements  CORTST_ESDD_UD_051                                             */
/* Implements  CORTST_ESDD_UD_084                         */
/* Implements  CorTst053, CorTst054, CorTst096_Conf                           */
/* Implements  SWS_CorTst_00053, SWS_CorTst_00054                             */
/* Implements  EAAR_PN0077_FR_0011 */
/* Implements  CORTST_ESDD_UD_052 */
/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, CORTST_PUBLIC_CODE) CorTst_GetCurrentStatus
(P2VAR(CorTst_ErrOkType, AUTOMATIC, CORTST_APPL_DATA) ErrOk)
/* END Msg(2:3227)-3 */
{
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Set the DET return value to E_OK */
  LenReturnValue = E_OK;
  /* Check if the module is initialized */
  if (CORTST_UNINIT == CorTst_GenExeStatus)
  {
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                              CORTST_GET_CURRENT_STATUS_SID, CORTST_E_UNINIT);
    /* Set the DET return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  if (NULL_PTR == ErrOk)
  {
    /* Report error to DET when parameter passed is null pointer */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                        CORTST_GET_CURRENT_STATUS_SID, CORTST_E_PARAM_POINTER);
    /* Set the DET return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check for the back ground mode test is not performed */
  /* Implements CorTst086_Conf */
    if (CORTST_E_NOT_TESTED == CorTst_GVar.CorTst_GenTestResult)
    {
      /* Set the default values */
      /* QAC Warning: START Msg(2:2814)-4 */
    /* Implements CorTst056 */
    /* Implements CorTst120 */
    /* Implements SWS_CorTst_00120 */
      ErrOk->ulCorTstIntervalId = CORTST_ZERO;
      ErrOk->enCorTstResultBgnd = CORTST_E_NOT_TESTED;
      /* END Msg(2:2814)-4 */
    }
    else
    {
      /* Read the Test Result status */
      ErrOk->ulCorTstIntervalId =
                                (CorTst_GVar.CorTst_GulIntervalId);
      ErrOk->enCorTstResultBgnd = CorTst_GVar.CorTst_GenTestResult;
    }
  }
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
} /* End of API CorTst_GetCurrentStatus */

#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (CORTST_GET_CURRENT_STATUS_API == STD_ON) */

/* Implements CORTST_ESDD_UD_016 */
/* Implements ECUC_CorTst_00097 */
#if (CORTST_GET_SIGNATURE_API == STD_ON)
/*******************************************************************************
** Function Name         : CorTst_GetSignature
**
** Service ID            : 0x05
**
** Description           : This API Returns currently pending Core Test result
**                         signature and Test Interval Id of the last completed
**                         test.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : CorTst_CsumSignatureBgndType
**
** Preconditions         : Component must be initialized using CorTst_Init().
**
** Global Variables Used : CorTst_GVar.CorTst_GulLastBgndSignature,
**                         CorTst_GVar.CorTst_GulIntervalId,
**                         CorTst_GenExeStatus,
**                         CorTst_GVar.CorTst_GblBgndSigAvailable
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements  EAAR_PN0077_FR_0012                                            */
/* Implements  CORTST_ESDD_UD_085                         */
/* Implements  EAAR_PN0034_NR_0087                                            */
/* Implements  EAAR_PN0034_NR_0088                                            */
/* Implements  CORTST_ESDD_UD_002, CORTST_ESDD_UD_003, CORTST_ESDD_UD_004     */
/* Implements  CORTST_ESDD_UD_061, CORTST_ESDD_UD_062                         */
/* Implements  EAAR_PN0077_NR_0002, EAAR_PN0077_NR_0003                       */

/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006, EAAR_PN0034_FR_0049  */
/* Implements  CORTST_ESDD_UD_053                                             */
/* Implements  CorTst057, CorTst058, CorTst121, CorTst044, CorTst097_Conf     */
/* Implements  CorTst183                                                      */
/* Implements  SWS_CorTst_00057, SWS_CorTst_00058, SWS_CorTst_00121           */
FUNC(CorTst_CsumSignatureBgndType, CORTST_PUBLIC_CODE) CorTst_GetSignature(void)
{
  /*
   * Structure variable that contains the signature of last executed BGND
   * core test
   */
  /* Implements  EAAR_PN0077_FR_0011 */
  VAR(CorTst_CsumSignatureBgndType, CORTST_NOINIT_DATA) LddCorTstSignature;
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  /* Set the default values */
  LddCorTstSignature.ulCorTstIntervalId = CORTST_ZERO;
  LddCorTstSignature.ulCorTstSignatureBgnd = CORTST_ZERO;
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Set the DET return value to E_OK */
  LenReturnValue = E_OK;
  /* Check if the module is initialized */
  if (CORTST_UNINIT == CorTst_GenExeStatus)
  {
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                                   CORTST_GET_SIGNATURE_SID, CORTST_E_UNINIT);
    /* Set the DET return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check for background mode test signature is available */
    if (CORTST_TRUE == CorTst_GVar.CorTst_GblBgndSigAvailable)
    {
      /* Read the Test Signature status */
      LddCorTstSignature.ulCorTstIntervalId =
                               (CorTst_GVar.CorTst_GulIntervalId);
      LddCorTstSignature.ulCorTstSignatureBgnd =
                                   CorTst_GVar.CorTst_GulLastBgndSignature;
    }
    else
    {
      /* No action required */
    }
  }
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  /* Return the test interval id and signature of the last BGND test */
  return(LddCorTstSignature);
} /* End of API CorTst_GetSignature */

#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (CORTST_GET_SIGNATURE_API == STD_ON) */

/* Implements CORTST_ESDD_UD_015 */
/* Implements ECUC_CorTst_00103 */
#if (CORTST_GET_FGND_SIGNATURE_API == STD_ON)
/*******************************************************************************
** Function Name         : CorTst_GetFgndSignature
**
** Service ID            : 0x06
**
** Description           : This API Returns Core Test result signature of the
**                         last completed Test run in foreground mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : CorTst_CsumSignatureType
**
** Preconditions         : Component must be initialized using CorTst_Init().
**
** Global Variables Used : CorTst_GenExeStatus,
**                         CorTst_GVar.CorTst_GulLastFgndSignature,
**                         CorTst_GVar.CorTst_GblFgndSigAvailable
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements  EAAR_PN0034_NR_0087                                            */
/* Implements  EAAR_PN0034_NR_0088                                            */
/* Implements  EAAR_PN0077_FR_0012                                            */
/* Implements  CORTST_ESDD_UD_002, CORTST_ESDD_UD_003, CORTST_ESDD_UD_004     */
/* Implements  CORTST_ESDD_UD_061, CORTST_ESDD_UD_062                         */
/* Implements  EAAR_PN0077_NR_0002, EAAR_PN0077_NR_0003                       */

/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006, EAAR_PN0034_FR_0049  */
/* Implements  CORTST_ESDD_UD_054                                             */
/* Implements  CorTst060, CorTst061, CorTst122, CorTst044, CorTst103_Conf     */
/* Implements  CorTst183                                                      */
/* Implements  SWS_CorTst_00060, SWS_CorTst_00061, SWS_CorTst_00122           */
FUNC(CorTst_CsumSignatureType, CORTST_PUBLIC_CODE) CorTst_GetFgndSignature(void)
{
  /* Local variable to store the Test signature */
    CorTst_CsumSignatureType LulFgndTestSignature;
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  #endif  /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */

  /* Initialize the local variable */
  LulFgndTestSignature = CORTST_ZERO;

  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Set the DET return value to E_OK */
  LenReturnValue = E_OK;
  /* Check if the module is initialized */
  if (CORTST_UNINIT == CorTst_GenExeStatus)
  {
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                               CORTST_GET_FGND_SIGNATURE_SID, CORTST_E_UNINIT);
    /* Set the DET return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
  #endif  /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check for foreground mode test signature is available */
    if (CORTST_TRUE == CorTst_GVar.CorTst_GblFgndSigAvailable)
    {
      /* Read the Test Signature status */
      LulFgndTestSignature = CorTst_GVar.CorTst_GulLastFgndSignature;
    }
    else
    {
      /* No action required */
    }
  }
  /* Implements  CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements  CorTst018, CorTst017, CorTst020 */
  /* Implements  CorTst082_Conf */
  /* Implements  ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  /* Return the signature of the last FGND test performed */
  return(LulFgndTestSignature);
} /* End of API CorTst_GetFgndSignature */

#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (CORTST_GET_FGND_SIGNATURE_API == STD_ON) */

/* Implements CORTST_ESDD_UD_018 */
/* Implements ECUC_CorTst_00093 */
#if (CORTST_START_API == STD_ON)
/*******************************************************************************
** Function Name         : CorTst_Start
**
** Service ID            : 0x07
**
** Description           : This API Returns whether the Core Test run in
**                         foreground mode is processed or not.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : TestId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : Component must be initialized using CorTst_Init().
**
** Global Variables Used : CorTst_GenExeStatus,
**                         CorTst_GVar.CorTst_GenTestResult,
**                         CorTst_GVar.CorTst_GulLastFgndSignature,
**                         CorTst_GVar.CorTst_GblFgndSigAvailable,
**                         CorTst_GstFGModeSelConfig
**
** Function(s) invoked   : Det_ReportError, Dem_ReportErrorStatus, sw_g3k,
**                         CorTst_SearchVal,
**                         CORTST_ENTER_CRITICAL_SECTION,
**                         CORTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements  EAAR_PN0034_NR_0087                                            */
/* Implements  EAAR_PN0034_NR_0088                                            */
/* Implements  EAAR_PN0077_FR_0012                                            */
/* Implements  CORTST_ESDD_UD_002, CORTST_ESDD_UD_003, CORTST_ESDD_UD_004     */
/* Implements  CORTST_ESDD_UD_061, CORTST_ESDD_UD_062                         */
/* Implements  EAAR_PN0077_NR_0002, EAAR_PN0077_NR_0003, EAAR_PN0034_FR_0049  */

/* Implements   EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006                      */
/* Implements   CORTST_ESDD_UD_055                                            */
/* Implements   CorTst064, CorTst065, CorTst109, CorTst154, CorTst161,        */
/* Implements   CorTst044, CorTst144, CorTst093_Conf, CorTst183               */
/* Implements   SWS_CorTst_00064, SWS_CorTst_00065, SWS_CorTst_00109          */
/* Implements   SWS_CorTst_00154, SWS_CorTst_01001, SWS_CorTst_00161          */
/* Implements   SWS_CorTst_00021, SWS_CorTst_00026                            */

/* Implements   CORTST_ESDD_UD_064, CORTST_ESDD_UD_065                        */
/* Implements   BSW00339, CorTst017, CorTst019, CorTst021, CorTst027          */
/* Implements   CorTst173, CorTst157_Conf, ECUC_CorTst_00157                  */
/* Implements   SWS_CorTst_01000, SWS_BSW_00066, SWS_CorTst_00027             */
/* Implements   SWS_CorTst_00154, SWS_CorTst_00155                            */
/* Implements   CorTst158_Conf                                                */
/* QAC Warning: START Msg(2:3227)-3 */
FUNC(Std_ReturnType, CORTST_PUBLIC_CODE) CorTst_Start(CorTst_TestIdFgndType
                                                                 TestId)
/* END Msg(2:3227)-3 */
{
  /* Foreground id found in remapping array */
    uint32 LulFgndId;
  /* Pointer to CorTst FGND mode selection configuration type of structure */
  /* Implements CorTst088_Conf */
  P2CONST(CorTst_ConfigType, CORTST_VAR, CORTST_CONFIG_CONST)
                                                         LpCorTstFGModeConfig;
  P2CONST(boolean, CORTST_VAR, CORTST_CONFIG_CONST)LpCorTstModule;
  /* Declare the variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Declare the variable to hold the Core Test number ID value */
  uint16 LusCorTstId;
  /* Set the variable Core Test number ID value as default to one */
  LusCorTstId = CORTST_ONE;
  /* Set the DET return value to E_OK */
  LenReturnValue = E_OK;
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Check if the module is initialized */
  if (CORTST_UNINIT == CorTst_GenExeStatus)
  {
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                                         CORTST_START_SID, CORTST_E_UNINIT);
    /* Set the DET return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
  #endif  /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * Check for the module execution status is not running in background mode
     */
    if (CORTST_RUNNING_BGND != CorTst_GenExeStatus)
    {
      /* Check for the module execution status is in initialized state */
      if (CORTST_INIT == CorTst_GenExeStatus)
      {
          LulFgndId = CorTst_SearchVal(TestId);
    /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
    /* Implements CorTst018, CorTst017, CorTst020 */
    /* Implements CorTst082_Conf */
    /* Implements ECUC_CorTst_00082 */
        #if (CORTST_DEV_ERROR_DETECT == STD_ON)
        /* Check whether the Test Id is in configured range */
          if (LulFgndId >= CORTST_FGND_TEST_NUMBER)
        {
          /* Report error to DET that Test ID is out of range */
          (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                                    CORTST_START_SID, CORTST_E_PARAM_INVALID);
          /* Set the DET return value to E_NOT_OK */
          LenReturnValue = E_NOT_OK;
        }
        else
        #endif  /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
        {
          /* MISRA Violation: START Msg(4:2995)-5 */
          /* MISRA Violation: START Msg(4:2991)-4 */
            if (LulFgndId < CORTST_FGND_TEST_NUMBER)
          /* END Msg(4:2991)-4 */
          /* END Msg(4:2995)-5 */
          {
            /* Get pointer to CorTst FGND mode selection Configuration array */
            LpCorTstFGModeConfig =
                CorTst_GstRemapFngIds[LulFgndId].pGstFGModeSelConfig;

            /* QAC Warning: START Msg(2:2814)-4 */
            LpCorTstModule = &LpCorTstFGModeConfig->blCorTstModule[CORTST_ZERO];
            /* END Msg(2:2814)-4 */
            /* Check for the test module Id is within nr of tests available */
            /* Implements CORTST_ESDD_UD_026 */
      while (CORTST_NUM_TEST_AVAILABLE >= LusCorTstId)
            {
              /* MISRA Violation: START Msg(4:0491)-1 */
              /* Check whether particular test module is selected */
              if (CORTST_TRUE ==
                            (boolean)LpCorTstModule[LusCorTstId - CORTST_ONE])
                /* END Msg(4:0491)-1 */
              {
        /* Implements EAAR_PN0077_FR_0007, EAAR_PN0034_FR_0013  */
        /* Implements CORTST_ESDD_UD_022 */
        /* Implements CorTst018, CorTst017, CorTst020 */
                #if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
                CORTST_ENTER_CRITICAL_SECTION(
                                            CORTST_TESTMODULE_DATA_PROTECTION);
                #endif
/* MISRA Violation: START Msg(4:4470)-2 */
/* MISRA Violation: START Msg(4:1257)-9 */
/* MISRA Violation: START Msg(4:1291)-10 */
/* Call all the test modules */
/* Implements CorTst130_Conf, CorTst129_Conf, CorTst133_Conf */
/* Implements CorTst128_Conf, CorTst131_Conf */
/* Implements CorTst132_Conf, CorTst127_Conf */
/* Implements EAAR_PN0077_NR_0001 */
                #if (CORE_G3K == CORTST_SWCST)
                sw_cst((sint16)LusCorTstId, RUN_MODE,
                  CorTst_GulResult, CorTst_GulNotResult,
                  CorTst_GulSignature, CorTst_GulNotSignature);
                #else
                sw_cst((sint16)LusCorTstId, RUN_MODE,
                  CorTst_GulResult, CorTst_GulSignature);
                #endif
/* END Msg(4:4470)-2 */
/* END Msg(4:1257)-9 */
/* END Msg(4:1291)-10 */
/* Check for the test module result is success */
                if ((sint32)PASSED ==
                                  CorTst_GulResult[LusCorTstId - CORTST_ONE])
/* MISRA Violation: START Msg(4:0715)-6 */
                {
 /* Set the global variable Test result to Test okay */
                  CorTst_GVar.CorTst_GenTestResult = CORTST_E_OKAY;
/* Get the last foreground test signature value */
                  CorTst_GVar.CorTst_GulLastFgndSignature =
                    (uint32)CorTst_GulSignature[LusCorTstId - CORTST_ONE];
/* Set the variable to indicate FGND signature is available */
                  CorTst_GVar.CorTst_GblFgndSigAvailable = CORTST_TRUE;
/* Implements  CORTST_ESDD_UD_063                           */
                  #if (CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION)
/* Implements  SWS_CorTst_01001, SWS_CORTST_01000 */
/* Report error to DEM the extended production error        */
/* since the core test module has passed                    */
/* Implements CORTST_ESDD_UD_035 */
/* Implements SWS_CorTst_00177 */
          Dem_ReportErrorStatus(CORTST_E_CORE_FAILURE,
                    DEM_EVENT_STATUS_PREPASSED);

                  #endif

                }
/* END Msg(4:0715)-6 */
                else
/* MISRA Violation: START Msg(4:0715)-6 */
                {
/* Set the global variable Test result to Test not okay */
                  CorTst_GVar.CorTst_GenTestResult = CORTST_E_NOT_OK;
/* Set the DET return value to E_NOT_OK */
                  LenReturnValue = E_NOT_OK;
/* Implements  CORTST_ESDD_UD_063                       */
                  #if (CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION)
/* Implements SWS_CORTST_00154, SWS_CORTST_01000, SWS_CORTST_00021 */
/* Report error to DEM since the test module has failed */
/* Implements CORTST_ESDD_UD_035 */
/* Implements CorTst156_Conf */
/* Implements SWS_CorTst_00177 */
                  Dem_ReportErrorStatus(CORTST_E_CORE_FAILURE,
                    DEM_EVENT_STATUS_PREFAILED);
                  #else
/* Report error to DEM since the test module has failed */
/* Implements CORTST_ESDD_UD_035 */
/* Implements SWS_CorTst_00177 */
                  Dem_ReportErrorStatus(CORTST_E_CORE_FAILURE,
                    DEM_EVENT_STATUS_FAILED);
                  #endif
                }
                /* END Msg(4:0715)-6 */
/* Implements EAAR_PN0077_FR_0007 */
/* Implements CORTST_ESDD_UD_022 */
                #if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
                CORTST_EXIT_CRITICAL_SECTION(CORTST_TESTMODULE_DATA_PROTECTION);
                #endif
              }
              else
              {
                /* No action required */
              }
              /* Increment the Test Id value */
              LusCorTstId++;
            }
/* Implements EAAR_PN0077_FR_0007 */
/* Implements CORTST_ESDD_UD_022 */
            #if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
            CORTST_ENTER_CRITICAL_SECTION(CORTST_TESTMODULE_DATA_PROTECTION);
            #endif
/* Check for test failure condition of all test modules */
            if (E_NOT_OK == LenReturnValue)
            {
              /* Set the global variable Test result to Test not okay */
              CorTst_GVar.CorTst_GenTestResult = CORTST_E_NOT_OK;
            }
            else
            {
              /* Set the global variable Test result to Test okay */
              CorTst_GVar.CorTst_GenTestResult = CORTST_E_OKAY;
            }
/* Implements EAAR_PN0077_FR_0007  */
/* Implements CORTST_ESDD_UD_011 */
/* Implements CORTST_ESDD_UD_022 */
            #if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
            CORTST_EXIT_CRITICAL_SECTION(CORTST_TESTMODULE_DATA_PROTECTION);
            #endif
          }
          /* Start CORTST_UT_001 */
          else
          {
            /* Ignore test, prevent out of bounds */
          } /* End of if (LulFgndId < CORTST_FGND_TEST_NUMBER) */
          /* End CORTST_UT_001 */
        }

      }
      else
      {
        /* No action required */
      }
    }
    else
    {
    /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
    /* Implements CorTst018, CorTst017, CorTst020 */
    /* Implements CorTst082_Conf */
    /* Implements ECUC_CorTst_00082 */
      #if (CORTST_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that test is running in background mode */
    /* Implements EAAR_PN0077_FR_0010 */
      (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                                  CORTST_START_SID, CORTST_E_BGNDTEST_RUNNING);
      #endif  /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
      /*Return E_OK if the CORTST status is in CORTST_RUNNING_BGND mode*/
      LenReturnValue = E_OK;
    }
  }
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif  /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  /* Return the value */
  return(LenReturnValue);
} /* End of API CorTst_Start */

#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (CORTST_START_API == STD_ON) */

/*******************************************************************************
** Function Name         : CorTst_MainFunction
**
** Service ID            : 0x0B
**
** Description           : This API performs processing of the core test module
**                         in background mode and shall change the state of the
**                         module from CORTST_INIT to CORTST_RUNNING_BGND.
**
** Sync/Async            : NA
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Component must be initialized using CorTst_Init().
**
** Global Variables Used : CorTst_GenExeStatus,
**                         CorTst_GVar.CorTst_GulCfgIndex,
**                         CorTst_GVar.CorTst_GenBGStatus,
**                         CorTst_GVar.CorTst_GusTestId,
**                         CorTst_GVar.CorTst_GenTestResult,
**                         CorTst_GVar.CorTst_GulLastBgndSignature,
**                         CorTst_GVar.CorTst_GulIntervalId,
**                         CorTst_GVar.CorTst_GblBgndSigAvailable,
**                         CorTst_GstBGModeSelConfig, CorTst_GpSTModule,
**                         CorTst_GVar.CorTst_GucTestRuns,
**                         CorTst_GVar.CorTst_GblBgndTestError,
**                         CorTst_GblNewIntervalStarted
**
** Function(s) invoked   : Det_ReportError, Dem_ReportErrorStatus, sw_g3k,
**                         CorTst_GstTestNotifyFunc.TestCompleteNotification,
**                         CORTST_ENTER_CRITICAL_SECTION,
**                         CORTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements  CORTST_ESDD_UD_047 */
/* Implements  EAAR_PN0034_NR_0087                                            */
/* Implements  EAAR_PN0034_NR_0088                                            */
/* Implements  EAAR_PN0077_FR_0012                                            */
/* Implements  CORTST_ESDD_UD_002, CORTST_ESDD_UD_003, CORTST_ESDD_UD_004     */
/* Implements  CORTST_ESDD_UD_061, CORTST_ESDD_UD_062                         */
/* Implements  EAAR_PN0077_NR_0002, EAAR_PN0077_NR_0003                       */

/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006, EAAR_PN0034_FR_0049  */
/* Implements  CORTST_ESDD_UD_057                                             */
/* Implements  CorTst067, CorTst068, CorTst069, CorTst070, CorTst071          */
/* Implements  CorTst072, CorTst073, CorTst074, CorTst139, CorTst155          */
/* Implements  CorTst044, CorTst144, CorTst183, CorTst153, CorTst145          */
/* Implements  CorTst137                                                      */
/* Implements  SWS_CorTst_00067, SWS_CorTst_00068, SWS_CorTst_00069           */
/* Implements  SWS_CorTst_00070, SWS_CorTst_00071, SWS_CorTst_00072           */
/* Implements  SWS_CorTst_00073, SWS_CorTst_00074, SWS_CorTst_00139           */
/* Implements  SWS_CorTst_00021, SWS_CorTst_00026, SWS_CorTst_00137           */
/* Implements  SWS_CorTst_00145, SWS_CorTst_00153, SWS_CorTst_01002           */
FUNC(void, CORTST_PUBLIC_CODE)CorTst_MainFunction(void)
{
  /* Implements CORTST_ESDD_UD_027 */
  /* Implements ECUC_CorTst_00087 */
  #if (CORTST_BGND_TEST_CFG_AVAILABLE == STD_ON)
  /* Implements CORTST_ESDD_UD_012 */
  /* Implements ECUC_CorTst_00083 */
  #if (CORTST_NOTIFICATION_SUPPORTED == STD_ON)
  /*
   * Structure variable that contains the result of last executed background
   * core test
   */
  CorTst_ErrOkType LddCorTstResultBgnd;
  #endif
  /* Pointer to the CorTst BGND mode selection configuration type structure */
  P2CONST(CorTst_ConfigType, CORTST_VAR, CORTST_CONFIG_CONST)
                                                        LpCorTstBGModeConfig;
  /* Declare the variable to hold status of BGND core test run */
  uint8 LucCorTstRuns;
  /* Variable to hold the value of BGND core test run */
  LucCorTstRuns = (uint8)CORTST_ZERO;
  #endif /* #if (CORTST_BGND_TEST_CFG_AVAILABLE == STD_ON) */
  /* Check if the module is uninitialized */
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  if (CORTST_UNINIT == CorTst_GenExeStatus)
  {
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                               CORTST_MAIN_FUNCTION_SID, CORTST_E_UNINIT);
  }
  else
   #endif  /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
  /* Implements EAAR_PN0077_FR_0007  */
  /* Implements CORTST_ESDD_UD_027 */
  /* Implements CORTST_ESDD_UD_022 */
  /* Implements ECUC_CorTst_00087 */
    #if (CORTST_BGND_TEST_CFG_AVAILABLE == STD_ON)
    #if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    CORTST_ENTER_CRITICAL_SECTION(CORTST_TESTMODULE_DATA_PROTECTION);
    #endif
    /* Check if the module is initialized */
    if (CORTST_INIT == CorTst_GenExeStatus)
    {
      /* Set the execution status to running background mode */
      CorTst_GenExeStatus = CORTST_RUNNING_BGND;
    }
    else
    {
      /* No action required */
    }
    /* Check if the module is in running background mode */
    if (CORTST_RUNNING_BGND == CorTst_GenExeStatus)
    {
      /* Check for status of the Last Completed Background Core Test */
      if (CORTST_BGND_COMPLETE == CorTst_GVar.CorTst_GenBGStatus)
      {
        /* Get pointer to CorTst BGND mode selection Configuration array */
        /* Implements CORTST_ESDD_UD_037 */
    LpCorTstBGModeConfig =
                  &CorTst_GstBGModeSelConfig[CorTst_GVar.CorTst_GulCfgIndex];
        /*
         * Get the pointer to CorTst Configuration array contains ST modules
         * selection values
         */
        CorTst_GpSTModule = &LpCorTstBGModeConfig->blCorTstModule[CORTST_ZERO];
        CorTst_GVar.CorTst_GenBGStatus = CORTST_BGND_INPROGRESS;
        /* To check the status of new IntervalId */
        if(CORTST_TRUE == CorTst_GVar.CorTst_GblNewIntervalStarted)
        {
/* Check for Test Interval Id is reached the end value */
/* Implements CORTST_ESDD_UD_024, EAAR_PN0077_FR_0008 */
/* Implements CorTst143_Conf */
/* Implements ECUC_CorTst_00143 */
          if (CORTST_TEST_INTERVAL_ID_END_VALUE ==
                                          CorTst_GVar.CorTst_GulIntervalId)
          {
            /* Initialize test interval Id value with zero */
            CorTst_GVar.CorTst_GulIntervalId = CORTST_ZERO;
          }
          else
          {
            /* Increment the test interval Id */
            CorTst_GVar.CorTst_GulIntervalId++;
          }
         /* Set the variable to store the status of new IntervalId */
         CorTst_GVar.CorTst_GblNewIntervalStarted = CORTST_FALSE;
        }
        else
        {
            /*No action required*/
        }
      }
      else
      {
        /* Check for the test module Id is within number of tests available */
        /* Implements CORTST_ESDD_UD_026 */
    while ((CORTST_NUM_TEST_AVAILABLE >= CorTst_GVar.CorTst_GusTestId) &&
                                              (CORTST_ZERO == LucCorTstRuns))
        {
          /* QAC Warning: START Msg(2:2824)-5 */
          /* MISRA Violation: START Msg(4:0491)-1 */
          /* Check whether particular test module is selected */
          if (CORTST_TRUE ==
                CorTst_GpSTModule[CorTst_GVar.CorTst_GusTestId - CORTST_ONE])
          /* END Msg(4:0491)-1 */
          /* END Msg(2:2824)-5 */
          {
            /* MISRA Violation: START Msg(4:4470)-2 */
            /* MISRA Violation: START Msg(4:1257)-9 */
            /* MISRA Violation: START Msg(4:1291)-10 */
            /* Call all the test modules. */
              #if (CORE_G3K == CORTST_SWCST)
              sw_cst((sint16)CorTst_GVar.CorTst_GusTestId, RUN_MODE,
                         CorTst_GulResult, CorTst_GulNotResult,
                             CorTst_GulSignature, CorTst_GulNotSignature);
              #else
              sw_cst((sint16)CorTst_GVar.CorTst_GusTestId, RUN_MODE,
                         CorTst_GulResult, CorTst_GulSignature);
              #endif
             /* END Msg(4:4470)-2 */
             /* END Msg(4:1257)-9 */
             /* END Msg(4:1291)-10 */
            /* Check for the test module result is success */
            if ((sint32)PASSED ==
                 CorTst_GulResult[CorTst_GVar.CorTst_GusTestId - CORTST_ONE])
            {
              /* Set the global variable Test result to Test okay */
              CorTst_GVar.CorTst_GenTestResult = CORTST_E_OKAY;
              /* Get the last background test signature value */
              CorTst_GVar.CorTst_GulLastBgndSignature = (uint32)
              CorTst_GulSignature[CorTst_GVar.CorTst_GusTestId - CORTST_ONE];
              /* Set variable to indicate Background signature is available */
              CorTst_GVar.CorTst_GblBgndSigAvailable = CORTST_TRUE;
/* Implements  CORTST_ESDD_UD_063                            */
              #if (CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION)
/* SWS_CorTst_01002, SWS_CORTST_01000 */
/* Report error to DEM the extended production error         */
/* since the core test module has passed                     */
/* Implements CORTST_ESDD_UD_035 */
/* Implements SWS_CorTst_00177 */
        Dem_ReportErrorStatus(CORTST_E_CORE_FAILURE,
                                                    DEM_EVENT_STATUS_PREPASSED);

              #endif
            }
            else
            {
              /* Set the global variable Test result to Test not okay */
              CorTst_GVar.CorTst_GenTestResult = CORTST_E_NOT_OK;
              /* Set the variable to store at least one test module is failed
               * to true.
               */
              CorTst_GVar.CorTst_GblBgndTestError = CORTST_TRUE;
/* Implements  CORTST_ESDD_UD_063                       */
              #if (CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION)
/* SWS_CorTst_00155, SWS_CorTst_01000, SWS_CorTst_00021 */
/* Report error to DEM since the core test module has failed */
/* Implements CORTST_ESDD_UD_035 */
/* Implements SWS_CorTst_00177 */
        Dem_ReportErrorStatus(CORTST_E_CORE_FAILURE,
                                                    DEM_EVENT_STATUS_PREFAILED);
              #else
  /* Report error to DEM since the core test module has failed */
  /* Implements CORTST_ESDD_UD_035 */
  /* Implements SWS_CorTst_00177 */
        Dem_ReportErrorStatus(CORTST_E_CORE_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
              #endif
            }
            /* Set variable to hold the value of BGND core test run to one */
            LucCorTstRuns = (uint8)CORTST_ONE;
            /* Set the variable with at least one test module is tested */
            CorTst_GVar.CorTst_GucTestRuns = LucCorTstRuns;
          }
          else
          {
            /* No action required */
          }
          /* Increment the Test Id value */
          CorTst_GVar.CorTst_GusTestId++;
        }
/*
* Check for all test modules testing completed for one configuration
*/
/* Implements CORTST_ESDD_UD_026 */
        if (CorTst_GVar.CorTst_GusTestId > CORTST_NUM_TEST_AVAILABLE)
        {
          /* Check for atleast one test module testing is failed in BGND mode */
          if (CORTST_TRUE == CorTst_GVar.CorTst_GblBgndTestError)
          {
            /* Set the global variable Test result to Test not okay */
            CorTst_GVar.CorTst_GenTestResult = CORTST_E_NOT_OK;
          }
          else
          {
            /* Set the global variable Test result to Test okay */
            CorTst_GVar.CorTst_GenTestResult = CORTST_E_OKAY;
          }
/* Implements CORTST_ESDD_UD_012 */
/* Implements ECUC_CorTst_00083 */
          #if (CORTST_NOTIFICATION_SUPPORTED == STD_ON)
          /* Read the Test Result status */
          LddCorTstResultBgnd.ulCorTstIntervalId =
                                           CorTst_GVar.CorTst_GulIntervalId;
          LddCorTstResultBgnd.enCorTstResultBgnd =
                                           CorTst_GVar.CorTst_GenTestResult;
          #endif
          /* Increment the global variable Core Test configuration ID value */
          CorTst_GVar.CorTst_GulCfgIndex++;
          /* Check for the configuration set id is within total configured
           * number.
           */
/* Implements CORTST_ESDD_UD_025 */
          if (CORTST_BGND_TEST_NUMBER == CorTst_GVar.CorTst_GulCfgIndex)
          {
            /* Set the Background configuration set index variable to zero */
            CorTst_GVar.CorTst_GulCfgIndex = CORTST_ZERO;
          }
          else
          {
            /* No action required */
          }
          /* Set the execution status to initialized */
          CorTst_GenExeStatus = CORTST_INIT;
          /* Check for at least one core test run confirmation */
          if (CORTST_ONE == (uint16)CorTst_GVar.CorTst_GucTestRuns)
          {
      /* Implements CORTST_ESDD_UD_012 */
      /* Implements CorTst083_Conf */
      /* Implements ECUC_CorTst_00083 */
            #if (CORTST_NOTIFICATION_SUPPORTED == STD_ON)
            /* Check for notification pointer is configured as null */
            if (NULL_PTR !=
                     CorTst_GstTestNotifyFunc.pTestCompleteNotificationPointer)
            {
              /* Test complete notification to the upper layer */
              /* Implements CorTst076 */
        CorTst_GstTestNotifyFunc.pTestCompleteNotificationPointer
                                                      (LddCorTstResultBgnd);
            }
            else
            {
              /* Ignore test */
            }
            #endif /* #if (CORTST_NOTIFICATION_SUPPORTED == STD_ON) */
          }
          else
          {
            /* Set the global variable Test result to Test Not performed */
            CorTst_GVar.CorTst_GenTestResult = CORTST_E_NOT_TESTED;
            /* Set the global variable last background signature to zero */
            CorTst_GVar.CorTst_GulLastBgndSignature = CORTST_ZERO;
          }
          /* Initialize global variable Core Test ID value as default */
          CorTst_GVar.CorTst_GusTestId = CORTST_ONE;
          /* Set Background test status of last configuration to complete */
          CorTst_GVar.CorTst_GenBGStatus = CORTST_BGND_COMPLETE;
          /* Set variable to hold the value of BGND core test run to zero */
          CorTst_GVar.CorTst_GucTestRuns = (uint8)CORTST_ZERO;
          /* Set variable to store atleast one test module is failed to false */
          CorTst_GVar.CorTst_GblBgndTestError = CORTST_FALSE;
          /* Set the variable to store the status of new IntervalId */
          CorTst_GVar.CorTst_GblNewIntervalStarted = CORTST_TRUE;
        }
        else
        {
          /* No action required */
        }
      }
    }
    else
    {
      /* No action required */
    }
  /* Implements EAAR_PN0077_FR_0007 */
  /* Implements CORTST_ESDD_UD_022 */
    #if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    CORTST_EXIT_CRITICAL_SECTION(CORTST_TESTMODULE_DATA_PROTECTION);
    #endif
    #endif  /* #if (CORTST_BGND_TEST_CFG_AVAILABLE == STD_ON) */
  }
}
#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : CorTst_GetVersionInfo
**
** Service ID            : 0x08
**
** Description           : This service returns the version information of this
**                         module.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : versioninfo
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements  CORTST_ESDD_UD_019                                            */
/* Implements CorTst098_Conf */
/* Implements ECUC_CorTst_00098 */
#if (CORTST_VERSION_INFO_API == STD_ON)
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements  EAAR_PN0034_NR_0087                                            */
/* Implements  EAAR_PN0034_NR_0088                                            */
/* Implements  EAAR_PN0077_FR_0012                                            */
/* Implements   CORTST_ESDD_UD_002, CORTST_ESDD_UD_003, CORTST_ESDD_UD_004    */
/* Implements   CORTST_ESDD_UD_061, CORTST_ESDD_UD_062                        */
/* Implements   EAAR_PN0077_NR_0002, EAAR_PN0077_NR_0003                      */

/* Implements  SWS_CorTst_00112, SWS_CorTst_00118 */
/* Implements  EAAR_PN0077_FR_0001, EAAR_PN0077_FR_0006                       */
/* Implements  CORTST_ESDD_UD_006                                             */
/* Implements  EAAR_PN0034_FR_0051, EAAR_PN0034_FR_0092                       */
/* QAC Warning: START Msg(2:3227)-3 */
/* Implements CorTst112, CorTst113 */
/* Implements  CORTST_ESDD_UD_056                                             */
FUNC(void, CORTST_PUBLIC_CODE) CorTst_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, CORTST_APPL_DATA) versioninfo)
/* END Msg(2:3227)-3 */
{
  /* Implements CORTST_ESDD_UD_011, EAAR_PN0034_FR_0064 */
  /* Implements CorTst018, CorTst017, CorTst020 */
  /* Implements CorTst082_Conf */
  /* Implements ECUC_CorTst_00082 */
  #if (CORTST_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if versioninfo pointer is equal to Null */
  if(NULL_PTR == versioninfo)
  {
    /* Report to DET  */
  /* Implements CorTst118 */
    (void)Det_ReportError(CORTST_MODULE_ID, CORTST_INSTANCE_ID,
                         CORTST_GET_VERSION_INFO_SID, CORTST_E_PARAM_POINTER);
  }
  else
  #endif /*#if(CORTST_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    /* QAC Warning: START Msg(2:2814)-4 */
    (versioninfo)->vendorID = (uint16)CORTST_VENDOR_ID;
    /* END Msg(2:2814)-4 */
    /* Copy the module Id */
    (versioninfo)->moduleID = (uint16)CORTST_MODULE_ID;
    /* Copy Software Major Version */
    (versioninfo)->sw_major_version = CORTST_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    (versioninfo)->sw_minor_version = CORTST_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    (versioninfo)->sw_patch_version = CORTST_SW_PATCH_VERSION;
  }
}
#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif  /*(CORTST_VERSION_INFO_API == STD_ON)*/

/* Implements CORTST_ESDD_UD_018 */
/* Implements ECUC_CorTst_00093 */
#if (CORTST_START_API == STD_ON)
/*******************************************************************************
** Function Name         : CorTst_SearchVal
**
** Service ID            : NA
**
** Description           : This service returns the index of the foreground id
**                         found in the remapping array.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : LenSearchId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : CorTst_TestIdFgndType
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
#define CORTST_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:3227)-3 */
FUNC(STATIC CorTst_TestIdFgndType, CORTST_PRIVATE_CODE) CorTst_SearchVal
        ( VAR(CorTst_TestIdFgndType AUTOMATIC, CORTST_APPL_DATA) LenSearchId )
/* END Msg(2:3227)-3 */
{
  /* Assume out of bounds case so when CorTst_Start() is called and an
   * index is not found a DET is generated.
   * If the id is found, then LenIdIndex will take the correct value.
   */
  /* QAC Warning: START Msg(2:3204)-6 */
  CorTst_ForegroundIdRemap const *LpRemapArr;
  /* END Msg(2:3204)-6 */
  CorTst_TestIdFgndType LenIdIndex;

  LpRemapArr = CorTst_GstRemapFngIds;
  LenIdIndex = CORTST_ZERO;

  /* MISRA Violation: START Msg(4:0491)-1 */
  /* MISRA Violation: START Msg(4:2877)-7 */
  while ( (LenIdIndex < CORTST_FGND_TEST_NUMBER) &&
          (LpRemapArr[LenIdIndex].id != LenSearchId) )
  /* END Msg(4:2877)-7 */
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:2984)-8 */
    LenIdIndex++;
    /* END Msg(4:2984)-8 */
  }

  /* MISRA Violation: START Msg(4:0491)-1 */
  if (LpRemapArr[LenIdIndex].id == LenSearchId)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LenIdIndex = LpRemapArr[LenIdIndex].id;
    /* END Msg(4:0491)-1 */
  }
  else
  {
    /* intentional force overflow to report DET at CORTST_Start() */
    LenIdIndex = CORTST_FGND_TEST_NUMBER;
  }

  return LenIdIndex;
}
#define CORTST_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0862)-2 */
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */
#endif /* #if (CORTST_START_API == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
