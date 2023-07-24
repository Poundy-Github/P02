/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Types.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Core Test driver specific types used within the module.       */
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
 *                           2. Global variable 'CorTst_GucTestRuns' is added in
 *                              'CorTst_GVariable' structure.
 * V1.0.2:  07-Jul-2014    : As per CR 542, 'CorTst_GVariable' structure is
 *                           updated for adding global variable
 *                           'CorTst_GblBgndTestError'.
 * V1.0.3:  09-Sep-2014    : As per CR 604 for Mantis issue #22252, following
 *                           changes are made:
 *                           1. File is updated for including Autosar R3.2
 *                              version information details and critical section
 *                              protection macros.
 *                           2. File is updated for providing justification for
 *                              QAC warning.
 * V1.0.4:  31-Dec-2014    : Updated as per mantis #24187:  Error in Critical
 *                           Section Macros during Static Analysis by PC-Lint
 *                           is fixed
 * V2.0.1:  22-Aug-2016    : #ARDAABD-573
 *                           1. Updated CorTst library to G3KH RC3 v1.20
 * V2.0.2:  30-Aug-2016    : #ARDAABD-476
 *                           1. Updated to ASR 4.2.2
 * V2.0.3:  07-Sep-2016    : #ARDAABD-495
 *                           1. Updated copyright year and revision history
 * V2.0.4:  22-Sep-2016    : #ARDAABD-476
 *                           1. Improved MemMap inclusion for 4.0.3 and 4.2.2
 * V2.0.5:  20-Oct-2016    : #ARDAABD-849
 *                           1. Added SchM switch according to SWS_Rte_07250
 *                           2. Added ASR versions macro
 * V2.0.6:  20-Oct-2016    : #ARDAABD-840
 *                           1. Added SWS_CorTst_01005 and support for CorTst138
 * V2.0.7:  21-Oct-2016    : #ARDAABD-896
 *                           1.Change the name of type CorTstSelect_ConfigType
 *                           to CorTst_ConfigType
 * V2.1.0:  24-Oct-2016    : #ARDAABD-574
 *                           1. Added definition of type
 *                              STag_CorTst_ForegroundIdRemap
 * V2.1.1:  26-Oct-2016    : #ARDAABD-928
 *                           1. Added traceability
 * V2.1.2:  18-Jan-2017    : #ARDAABD-818
 *                           1. Remove the precompile switch for
 *                              SchM_Enter_CorTst_59_Renesas
 * V2.1.3:  19-June-2018   : #ARDAABD-833
 *                           1.Removed redefined macros from section
 *                             "To support different AUTOSAR releases
 *                             in a single package"
 *                           2.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           3.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 *
 */
/******************************************************************************/
#ifndef CORTST_TYPES_H
#define CORTST_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for pre-compile options */
/* CORTST_TYPES_H_001:  CORTST_ESDD_UD_046                                    */
#include "CorTst_Cfg.h"
/* AUTOSAR standard types */
#include "Std_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Release version information */
#define CORTST_TYPES_AR_RELEASE_MAJOR_VERSION    CORTST_AR_RELEASE_MAJOR_VERSION
#define CORTST_TYPES_AR_RELEASE_MINOR_VERSION    CORTST_AR_RELEASE_MINOR_VERSION
#define CORTST_TYPES_AR_RELEASE_REVISION_VERSION \
                                              CORTST_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define CORTST_TYPES_SW_MAJOR_VERSION   CORTST_SW_MAJOR_VERSION
#define CORTST_TYPES_SW_MINOR_VERSION   CORTST_SW_MINOR_VERSION

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : An additional semi-colon is added to the critical section  */
/*                 macro to avoid static analysis warning.                    */
/* Verification  : However, part of the code is verified manually and         */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */
/******************************************************************************/


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* CORTST_TYPES_H_002:  CORTST_ESDD_UD_001                                    */
/* CORTST_TYPES_H_003:  EAAR_PN0034_FR_0052                                   */

/* Macros to avoid direct numbers */
#define CORTST_ZERO                               (uint32)0
#define CORTST_ONE                                (uint16)1

/* Macros for boolean variables  */
#define CORTST_FALSE                              (boolean)0
#define CORTST_TRUE                               (boolean)1

/*******************************************************************************
**               SchM Critical Section Protection Macros                      **
*******************************************************************************/
/* CORTST_TYPES_H_004: CORTST_ESDD_UD_022                                     */
#if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)

#define CORTST_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                SchM_Enter_CorTst_##Exclusive_Area()
#define CORTST_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                SchM_Exit_CorTst_##Exclusive_Area()

#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* CORTST_TYPES_H_005:  CORTST_ESDD_UD_042                                    */
/* CORTST_TYPES_H_006:  CorTst039, CorTst148                                  */
/* CORTST_TYPES_H_007:  SWS_CorTst_00039                                      */
/* CORTST_TYPES_H_008:  SWS_CorTst_00148                                      */
/* Enumeration for status of the Core Test module */
typedef enum ETag_CorTst_StateType
{
  CORTST_ABORT = 0,
  CORTST_INIT,
  CORTST_UNINIT,
  CORTST_RUNNING_BGND
} CorTst_StateType;


/* Enumeration for Result of the Last Completed Core Test */
/* Support for ASR 4.2.2 and ASR 4.0.3 */
/* CORTST_TYPES_H_009:  CORTST_ESDD_UD_063                                    */
#if (CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION)
/* CORTST_TYPES_H_010:  CORTST_ESDD_UD_044                                    */
/* CORTST_TYPES_H_011:  CorTst038, SWS_CorTst_00038, SWS_CorTst_01005         */
typedef enum ETag_CorTst_ResultType
{
   CORTST_E_NOT_OK = 0,
   CORTST_E_OKAY,
   CORTST_E_NOT_TESTED
} CorTst_ResultType;
/* CORTST_TYPES_H_012:  CORTST_ESDD_UD_063                                    */
#elif (CORTST_AR_VERSION == CORTST_AR_LOWER_VERSION)
/* CORTST_TYPES_H_013:  CORTST_ESDD_UD_069                                    */
/* CORTST_TYPES_H_014:  CorTst038, SWS_CorTst_00038, SWS_CorTst_01005         */
typedef enum ETag_CorTst_ResultType
{
  CORTST_E_NOT_TESTED = 0,
  CORTST_E_OKAY,
  CORTST_E_NOT_OK
} CorTst_ResultType;
#endif

/* CORTST_TYPES_H_015:  CORTST_ESDD_UD_045                                    */
/* Enumeration for status of the Last Completed Background Core Test */
typedef enum ETag_CorTst_BgndStatusType
{
  CORTST_BGND_COMPLETE = 0,
  CORTST_BGND_INPROGRESS
} CorTst_BgndStatusType;

/* CORTST_TYPES_H_016:  CORTST_ESDD_UD_043                                    */
/* CORTST_TYPES_H_017:  CorTst160, SWS_CorTst_00160                           */
/* Type which specifies Test Id of Core Test module in Foreground mode */
typedef uint32 CorTst_TestIdFgndType;

/* CORTST_TYPES_H_018:  CORTST_ESDD_UD_039                                    */
/* CORTST_TYPES_H_019:  CorTst037, SWS_CorTst_00037                           */
/* Type which specifies Test Signature of Core Test module in Foreground mode */
typedef uint32 CorTst_CsumSignatureType;

/* CORTST_TYPES_H_020:  CORTST_ESDD_UD_041                                    */
/* CORTST_TYPES_H_021:  CorTst038, CorTst138                                  */
/* CORTST_TYPES_H_022:  SWS_CorTst_01005, SWS_CorTst_00038, SWS_CorTst_00138  */
/* Data Structure for Test result status of Core Test module */
/* CORTST_TYPES_H_023: CorTst039, SWS_CorTst_00039   */
/* CORTST_TYPES_H_024: ECUC_CorTst_00143 */
typedef struct STag_CorTst_ErrOkType
{
  /* Variable to store the Test Interval Id */
  uint32 ulCorTstIntervalId;
  /* Variable to store the current Core Test result */
  CorTst_ResultType enCorTstResultBgnd;
} CorTst_ErrOkType;

/* CORTST_TYPES_H_025:  CORTST_ESDD_UD_040                                    */
/* CORTST_TYPES_H_026:  CorTst0176, SWS_CorTst_00176                          */
/* Data Structure for Test Signature of Core Test module */
/* CORTST_TYPES_H_027: CorTst176, SWS_CorTst_00176   */
typedef struct STag_CorTst_CsumSignatureBgndType
{
  /* Variable to store the Test Interval Id in Background */
  uint32 ulCorTstIntervalId;
  /* Variable to store the Core Test Signature value in Background */
  uint32 ulCorTstSignatureBgnd;
} CorTst_CsumSignatureBgndType;

/* CORTST_TYPES_H_028:  CORTST_ESDD_UD_036 */
/* CORTST_TYPES_H_029: EAAR_PN0077_FR_0013          */
/* Data Structure for variables used within Core Test module */
typedef struct STag_CorTst_GVariable
{
  /* Variable to store the Test Result of last test run in Background */
  CorTst_ResultType CorTst_GenTestResult;
  /* Variable to store the BGND Test status of last configuration run */
  CorTst_BgndStatusType CorTst_GenBGStatus;
  /* Variable to store the Test Interval Id */
  uint32 CorTst_GulIntervalId;
  /* Variable to store the Background Test Signature */
  uint32 CorTst_GulLastBgndSignature;
  /* Variable to store the Foreground Test Signature */
  uint32 CorTst_GulLastFgndSignature;
  /* Variable to store the BGND configuration set index */
  uint32 CorTst_GulCfgIndex;
  /* Variable to store the test number of all tests available */
  uint16 CorTst_GusTestId;
  /* Variable to store the atleast one test module is run in background mode  */
  uint8 CorTst_GucTestRuns;
  /* Variable to store about BGND signature availability */
  boolean CorTst_GblBgndSigAvailable;
  /* Variable to store about FGND signature availability */
  boolean CorTst_GblFgndSigAvailable;
  /* Variable to store about atleast one test module is failed in BGND mode */
  boolean CorTst_GblBgndTestError;
  /* Set the variable to store the status of new IntervalId */
  boolean CorTst_GblNewIntervalStarted;
} CorTst_GVariable;

/* Data Structure for Core Test Select configuration type */
/* CORTST_TYPES_H_030:  CORTST_ESDD_UD_028                                    */
/* CORTST_TYPES_H_031:  CorTst144, SWS_CorTst_00144, SWS_CorTst_00008         */
/* CORTST_TYPES_H_032:  SWS_CorTst_01003                                      */
/* CORTST_TYPES_H_033:  CORTST_ESDD_UD_070                                    */
/* CORTST_TYPES_H_034: CORTST_ESDD_UD_028, EAAR_PN0077_FR_0013                */
/* CORTST_TYPES_H_035: CORTST_ESDD_UD_026 */
/* CORTST_TYPES_H_036:  CorTst089_Conf */

typedef struct STag_CorTst_ConfigType
{
  /* Array variable contains all ST modules selection */
  boolean blCorTstModule[CORTST_NUM_TEST_AVAILABLE];
} CorTst_ConfigType;

/* CORTST_TYPES_H_037: CORTST_ESDD_UD_067 */
/* Data Structure for id remapping */
typedef struct STag_CorTst_ForegroundIdRemap
{
  CorTst_TestIdFgndType id;
  CorTst_ConfigType const *pGstFGModeSelConfig;
} CorTst_ForegroundIdRemap;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif  /* CORTST_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
