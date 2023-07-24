/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = RamTst.h                                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, RamTst type definitions, structure data types   */
/* and API function prototypes of RamTst Driver                               */
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
 * V1.0.0:  06-Nov-2013  : Initial Version
 *
 * V1.0.1:  06-Feb-2014  : As per CR 392, following changes are made:
 *                         1. Updated as per coding guidelines.
 *                         2. The Copyright information is updated.
 *                         3. DET error "RAMTST_E_PARAM_POINTER" is removed.
 *
 * V1.0.2:  15-Apr-2014  : As per CR 463, following changes are made:
 *                         1. Updated as per coding guidelines.
 *                         2. Added Critical section Macro's.
 *
 * V1.0.3:  07-May-2014  : As per CR 505, for mantis #21215:
 *                         Updated to type cast Macros from
 *                         RAMTST_ABRAHAM_TESTRUN to RAMTST_ALG_INVALID.
 *
 * V1.1.0:  23-Jun-2014  : As per CR 531, for mantis #21269:
 *                         1. Register read-back is implemented in API's
 *                            "RamTst_Init".
 *
 * V1.1.1:  15-Jul-2014  : As per CR 557, following changes are made:
 *                         1. Scheduler Protocol is updated.
 *                         2. Updated as per coding guidelines..
 *
 * V1.1.2:  18-Sep-2014  : As per CR 09, following change is made:
 *                         1. File is updated to remove unwanted QAC Warning.
 *                         2. File is updated for avoiding the QAC misra
 *                            warning and for providing justifications.
 *                         3. File is Updated as per coding guidelines.
 *
 * V1.1.3:  13-Feb-2015 :  As part of merging activity (mantis #26024),
 *                         following changes are made:
 *                         1. P1X file is adapted from P1X branch.
 *                         2. Copyright information is updated.
 *
 * V1.1.4:  28-May-2015 :  As per Mantis #20338, following changes are made:
 *                         1. DET error "RAMTST_E_PARAM_POINTER" is added.
 *                         2. NULL pointer checking and DET error reporting is
 *                            implemented in RamTst_GetVersionInfo API.
 *
 * V1.2.0:  30-Sep-2016 :  WriteVerify and HWConsistencyCheck related
 *                         functionality added (ARDAABC-722, ARDAABC-724,
 *                         ARDAABC-726)
 *
 * V1.3.0:  19-Oct-2016 :  Read verify ECC registers reset values added
 *                         (ARDAABC-901)
 *
 * V1.3.1:  24-Oct-2016 :  RamTst_GetVersionInfo corrected after static
 *                         analysis (ARDAABC-917)
 *
 * V1.3.2:  28-Oct-2016 :  Traceability tag format changed, missing tags added
 *                         (ARDAABC-900)
 *
 * V2.0.0:  07-Nov-2016 :  As part of ARDAABC-939, following changes are made:
 *                         1. RAMTST_AR_RELEASE_*_VERSION macros define the
 *                            currently supported AR version
 *                         2. MemMap.h replaced by macro RAMTST_MEMMAP_FILE
 *                         3. RamTst_Init has a ConfigPtr parameter when
 *                            compiled for AR422
 *                         4. Updated memory section names
 *
 * V2.1.0:  11-Nov-2016 :  As part of ARDAABC-938,
 *                         RAMTST_CHECK_HW_CONSISTENCY_SVCID added.
 *
 * V2.1.1:  16-Nov-2016 :  As part of the review activity the following changes
 *                         are made (ARDAABC-726):
 *                         1. RamTst_OverallTestResult, RamTst_ExecutionStatus,
 *                            RamTst_TestResultBuffer and RamTst_Algorithm moved
 *                            into section VAR_POWER_ON_INIT_UNSPECIFIED
 * V2.1.2:  03-Dec-2016 :  As part of ARDAABC-571 the following changes made
 *                         1. Traceability tags updated according to AR4.2.2
 *                            format
 * V2.1.3:  07-Dec-2016 :  As part of ARDAABC-588 the following changes made
 *                         1. New SWS_BSW_nnnnn and SWS_RamTst_nnnnn
 *                            traceability tags added.
 * V2.2.0:  13-Feb-2017 :  Following changes are made:
 *                         1. As part of ARDAABC-978, critical section names
 *                            updated
 * V2.2.1:   16-Jun-2017 :  As part of F1KM support implementation, read verify
 *                          ECC registers reset values added for Global RAM.
 * V2.2.2:   02-Aug-2017 :  Added justifications for QAC Warning which cannot be
 *                          removed from the implementation.
 * V2.2.3:   26-Sep-2017 :  As part of ARDAABD-2252, inclusion of
 *                          RamTst_RegWrite.h and the vendor specific function
 *                          RamTst_HWConsistencyCheckType are removed.
 *                          As part of ARDAABD-1413, the macro
 *                          RamTst_GetVersionInfo is implemented as a function.
 * V2.2.4    06-Jul-2018 :  Following changes are made:
 *                          1. As part of merging activity ARDAABD-3470
 *                            a. RAMTST_<START/STOP>_SEC_VAR_NO_INIT_ASIL_B_16
 *                               and RAMTST_<START/STOP>_SEC_VAR_NO_INIT_16
 *                               are changed to
 *                               RAMTST_<START/STOP>_SEC_VAR_INIT_ASIL_B_16
 *                               and RAMTST_<START/STOP>_SEC_VAR_INIT_16
 *                               respectively.
 *                            b. RAMTST_<START/STOP>_SEC_VAR_NO_INIT_ASIL_B_32
 *                               and RAMTST_<START/STOP>_SEC_VAR_NO_INIT_32
 *                               are changed to
 *                               RAMTST_<START/STOP>_SEC_VAR_INIT_ASIL_B_32 and
 *                               RAMTST_<START/STOP>_SEC_VAR_INIT_32
 *                               respectively.
 *                            c. RAMTST_<START/STOP>_SEC_VAR_NO_INIT_ASIL_B_
 *                               UNSPECIFIED and
 *                               RAMTST_<START/STOP>_SEC_VAR_NO_INIT_UNSPECIFIED
 *                               are changed to
 *                               RAMTST_<START/STOP>_SEC_VAR_INIT_ASIL_B_
 *                               UNSPECIFIED and RAMTST_<START/STOP>_SEC_VAR_
 *                               INIT_UNSPECIFIED respectively.
 *                               Ref: ARDAABD-908
 *                           2. Updated Copyright(c) information.
 *                           3. As part of ARDAABD-2101, added traceability tags
 *                              for Reqtify coverage improvement.
 */
/******************************************************************************/
/* RAMTST_H_032: EAAR_PN0034_FR_0001 */
/* RAMTST_H_052: EAAR_PN0034_FR_0047 */
/* RAMTST_H_053: EAAR_PN0034_FR_0052 */
/* RAMTST_H_054: EAAR_PN0034_FR_0018 */
/* RAMTST_H_055: EAAR_PN0034_FR_0021 */
/* RAMTST_H_056: EAAR_PN0034_FR_0025 */
/* RAMTST_H_058: EAAR_PN0034_FR_0064 */
/* RAMTST_H_059: EAAR_PN0034_FR_0065 */
/* RAMTST_TYPES_H_041: EAAR_PN0034_NR_0001 */
/* RAMTST_H_063: EAAR_PN0034_NR_0007 */
/* RAMTST_H_064: EAAR_PN0034_NR_0056 */
/* RAMTST_H_065: EAAR_PN0034_NR_0012 */
/* RAMTST_H_066: EAAR_PN0034_NR_0018 */
/* RAMTST_H_067: EAAR_PN0034_NR_0020 */
/* RAMTST_H_068: EAAR_PN0034_NR_0069 */
/* RAMTST_H_069: AR_PN0040_FR_0017 */
/* RAMTST_H_071: AR_PN0040_FR_0036 */
/* RAMTST_H_072: AR_PN0040_FR_0038 */
/* RAMTST_H_073: AR_PN0040_NR_0006 */
/* RAMTST_H_074: RamTst087 */
#ifndef RAMTST_H
#define RAMTST_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* RAMTST_H_001: RamTst003, SWS_RamTst_00003 */
/* RAMTST_H_075: RamTst208 */
/* RAMTST_H_076: RamTst155 */
/* RAMTST_H_077: RamTst098 */
/* Included for Pre-compile options */
#include "RamTst_Cfg.h"
/* RAMTST_H_002: SWS_BSW_00024 */
/* Included AUTOSAR standard types */
#include "Std_Types.h"
/* Included for Type declarations */
#include "RamTst_Types.h"
/* Included for Notification declarations */
#include "RamTst_Cbk.h"
 #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
 /* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif

/*******************************************************************************
**                   Critical Section Protection Macros                       **
*******************************************************************************/
/* RAMTST_H_003: EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0013 */
/* RAMTST_H_033: EAAR_PN0034_FR_0061 */
#define RAMTST_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                 SchM_Enter_RamTst_##Exclusive_Area()
#define RAMTST_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                  SchM_Exit_RamTst_##Exclusive_Area()

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* RAMTST_H_004: SWS_BSW_00059, SWS_BSW_00161 */
/* RAMTST_H_054: EAAR_PN0034_FR_0055 */
/* RAMTST_H_070: AR_PN0040_FR_0020 */
/* RAMTST_H_079: RamTst117 */
#define RAMTST_VENDOR_ID    RAMTST_VENDOR_ID_VALUE
#define RAMTST_MODULE_ID    RAMTST_MODULE_ID_VALUE
#define RAMTST_INSTANCE_ID  RAMTST_INSTANCE_ID_VALUE

/* RAMTST_H_005: RamTst080, SWS_BSW_00036 */
/* AUTOSAR release version information */
#define  RAMTST_AR_RELEASE_MAJOR_VERSION     \
  RAMTST_AR_RELEASE_MAJOR_VERSION_VALUE
#define  RAMTST_AR_RELEASE_MINOR_VERSION     \
  RAMTST_AR_RELEASE_MINOR_VERSION_VALUE
#define  RAMTST_AR_RELEASE_REVISION_VERSION  \
  RAMTST_AR_RELEASE_REVISION_VERSION_VALUE

/* Module Software version information */
#define  RAMTST_SW_MAJOR_VERSION   RAMTST_SW_MAJOR_VERSION_VALUE
#define  RAMTST_SW_MINOR_VERSION   RAMTST_SW_MINOR_VERSION_VALUE
#define  RAMTST_SW_PATCH_VERSION   RAMTST_SW_PATCH_VERSION_VALUE

/* RAMTST_H_061: EAAR_PN0034_NR_0002 */
/* RAMTST_H_062: EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* RAMTST_H_006: SWS_BSW_00115 */

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Coding Requirement to optimize the function.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-1 and                           */
/*                 END Msg(4:3453)-1 tags in the code.                        */

/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-2 and                           */
/*                 END Msg(4:3684)-2 tags in the code.                        */

/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-3 and                           */
/*                 END Msg(4:3458)-3 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
*                          QAC Warnings                                       **
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
**                      API Service Id Macros                                 **
*******************************************************************************/
/* RAMTST_H_007: SWS_BSW_00110 */
/* RamTst_Init service ID */
#define RAMTST_INIT_SVCID (uint8)(0x00)
/* RamTst_Init service ID */
#define RAMTST_MAIN_FUNCTION_SVCID  (uint8)(0x01)
/* RamTst_Stop service ID */
#define RAMTST_STOP_SVCID (uint8)(0x02)
/* RamTst_Allow service ID */
#define RAMTST_ALLOW_SVCID  (uint8)(0x03)
/* RamTst_GetExecutionStatus service ID */
#define RAMTST_GET_EXECUTION_STATUS_SVCID (uint8)(0x04)
/* RamTst_GetTestResult service ID */
#define RAMTST_GET_TEST_RESULT_SVCID  (uint8)(0x05)
/* RamTst_GetTestResultPerBlock service ID */
#define RAMTST_GET_TEST_RESULT_PER_BLOCK_SVCID  (uint8)(0x06)
/* RamTst_GetTestAlgorithm service ID */
#define RAMTST_GET_TEST_ALGORITHM_SVCID (uint8)(0x07)
/* RamTst_ChangeNumberOfTestedCells service ID */
#define RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_SVCID  (uint8)(0x08)
/* RamTst_GetNumberOfTestedCells service ID */
#define RAMTST_GET_NUMBER_OF_TESTED_CELLS_SVCID (uint8)(0x09)
/* RamTst_GetVersionInfo service ID */
#define RAMTST_GET_VERSIONINFO_SVCID  (uint8)(0x0A)
/* RamTst_SelectAlgParams service ID */
#define RAMTST_SELECT_ALGORITHM_PARAMS_SVCID  (uint8)(0x0B)
/* RamTst_DeInit service ID */
#define RAMTST_DEINIT_SVCID (uint8)(0x0C)
/* RamTst_Suspend service ID */
#define RAMTST_SUSPEND_SVCID  (uint8)(0x0D)
/* RamTst_Resume service ID */
#define RAMTST_RESUME_SVCID (uint8)(0x0E)
/* RamTst_RunFullTest service ID */
#define RAMTST_RUN_FULL_TEST_SVCID  (uint8)(0x10)
/* RamTst_RunPartialTest service ID */
#define RAMTST_RUN_PARTIAL_TEST_SVCID (uint8)(0x11)
/* RamTst_GetAlgParams service ID */
#define RAMTST_GET_ALGORITHM_PARAMS_SVCID (uint8)(0x12)
/* RamTst_CheckHWConsistency service ID */
#define RAMTST_CHECK_HW_CONSISTENCY_SVCID (uint8)(0x20)

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* RAMTST_H_008: RamTst067, SWS_RamTst_00067, RamTst074 */
/* RAMTST_H_009: SWS_BSW_00201, SWS_BSW_00110 */
/* API called with irrelevant execution status */
#define RAMTST_E_STATUS_FAILURE (uint8)0x01
/* API called with parameter out of specified range */
#define RAMTST_E_OUT_OF_RANGE (uint8)0x02
/* API called without module initialization */
#define RAMTST_E_UNINIT (uint8)0x03
/* API called with null pointer */
#define RAMTST_E_PARAM_POINTER  (uint8)0x04

/*******************************************************************************
**                      Internal Defines                                      **
*******************************************************************************/
/* MISRA Violation: START Msg(4:3453)-1 */
/* Macro for finding the Mask */
#define RAMTST_MASK_BITX(X) ((0x0001UL) << (X))
/* Macro for inverting a particular bit */
#define RAMTST_INVERT_BITX(VAR, X, TYPE) \
                                     ((VAR) = (VAR) ^ (TYPE)RAMTST_MASK_BITX(X))
/* END Msg(4:3453)-1 */

/*  Number of test runs */
#define RAMTST_ABRAHAM_TESTRUN (uint8)0x09
/*  First test run in Abraham test */
#define RAMTST_RW1_ASCEND  (uint8)0x00
/* Second test run in Abraham test */
#define RAMTST_RW0_ASCEND  (uint8)0x01
/* Third test run in Abraham test */
#define RAMTST_RW1_DESCEND  (uint8)0x02
/* Fourth test run in Abraham test */
#define RAMTST_RW0_DESCEND  (uint8)0x03
/* Fifth test run in Abraham test */
#define RAMTST_RWW_ASCEND  (uint8)0x04
/* Sixth test run in Abraham test */
#define RAMTST_WRW_DESCEND  (uint8)0x05
/* Seventh test run in Abraham test */
#define RAMTST_W_ASCEND  (uint8)0x06
/* Eighth test run in Abraham test */
#define RAMTST_WRW_ASCEND  (uint8)0x07
/* Ninth test run in Abraham test */
#define RAMTST_RWW_DESCEND  (uint8)0x08
/* Tenth test run in Abraham test */
#define RAMTST_ALG_INVALID  (uint8)0xFF

#if (RAMTST_ECC_CHECK == STD_ON)
  /* Reset value of Local RAM Test Control Register */
  #define RAMTST_LRTST_CNTL_RESET_VALUE     (uint32)0x0000u
  /* Reset value of Local RAM ECC Control Register */
  #define RAMTST_LRECC_CNTL_RESET_VALUE     (uint32)0x0000u
  /* Reset value of Local RAM Error Information Control Register */
  #define RAMTST_LRERRINT_CNTL_RESET_VALUE  (uint32)0x0003u

  #if (RAMTST_GLOBAL_RAM == STD_ON)
    /* Reset value of Global RAM Test Control Register */
    #define RAMTST_GRTST_CNTL_RESET_VALUE     (uint32)0x0000u
    /* Reset value of Global RAM ECC Control Register */
    #define RAMTST_GRECC_CNTL_RESET_VALUE     (uint32)0x0000u
    /* Reset value of Global RAM Error Information Control Register */
    #define RAMTST_GRERRINT_CNTL_RESET_VALUE     (uint32)0x0001u
  #endif

#endif

/* RAMTST_H_010: RamTst068, SWS_BSW_00202 */
/* MISRA Violation:  START Msg(4:3458)-3 */
#if (RAMTST_DEV_ERROR_DETECT == STD_ON)
 #define RAMTST_DET_REPORTERROR(ApiId, ErrorId)\
 {\
  (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID, ApiId, ErrorId);\
 }
#else
  #define RAMTST_DET_REPORTERROR(ApiId, ErrorId)
#endif
/* END Msg(4:3458)-3 */

/* RAMTST Version Information Check */
/* RAMTST_H_011: EAAR_PN0081_FR_0005, RamTst078, SWS_BSW_00052, RamTst079 */
/* RAMTST_H_012: SWS_BSW_00051, RamTst222, SWS_RamTst_00222, SWS_BSW_00110 */
/* RAMTST_H_013: SWS_BSW_00051, SWS_BSW_00164, SWS_RamTst_00109 */
/* MISRA Violation:  START Msg(4:3458)-3 */

/* END Msg(4:3458)-3 */

/*******************************************************************************
*                             Global Variables                                 *
*******************************************************************************/
/* RAMTST_H_016: SWS_BSW_00110 */
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_INIT_ASIL_B_16
#else
#define RAMTST_START_SEC_VAR_INIT_16
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_017: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Variable for getting number of blocks */
/* RAMTST_H_046: RAMTST_ESDD_UD_123  */
/* RAMTST_H_035: RAMTST_ESDD_UD_109 */
/* RAMTST_H_036: RAMTST_ESDD_UD_110 */
extern VAR(RamTst_NumberOfBlocksType, RAMTST_VAR) RamTst_NumBlock;
extern VAR(RamTst_NumberOfBlocksType, RAMTST_VAR) RamTst_Block;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_INIT_ASIL_B_16
#else
#define RAMTST_STOP_SEC_VAR_INIT_16
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_018: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_INIT_ASIL_B_32
#else
#define RAMTST_START_SEC_VAR_INIT_32
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_019: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Variable for Number of tested cells */
/* RAMTST_H_045: RAMTST_ESDD_UD_122 */
extern VAR(RamTst_NumberOfTestedCellsType, RAMTST_VAR_FAST)RamTst_NumTestedCell;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_INIT_ASIL_B_32
#else
#define RAMTST_STOP_SEC_VAR_INIT_32
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_020: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_021: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* RAMTST_H_037: RAMTST_ESDD_UD_112 */
extern P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST)RamTst_CellAddress;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_022: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_ASIL_B_8
#else
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_8
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_023: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* RAMTST_H_040: RAMTST_ESDD_UD_116 */
/* RAMTST_H_043: RAMTST_ESDD_UD_120 */
extern VAR(RamTst_AlgParamsIdType, RAMTST_VAR) RamTst_AlgParamsId;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_ASIL_B_8
#else
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_8
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_024: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_025: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* RAMTST_H_038: RAMTST_ESDD_UD_113 */
/* RAMTST_H_042: RAMTST_ESDD_UD_119 */
extern VAR(RamTst_TestResultType, RAMTST_VAR_FAST)RamTst_OverallTestResult;
/* RAMTST_H_041: RAMTST_ESDD_UD_118 */
extern VAR(RamTst_ExecutionStatusType, RAMTST_VAR_FAST)RamTst_ExecutionStatus;
/* RAMTST_H_039: RAMTST_ESDD_UD_115 */
/* RAMTST_H_042: RAMTST_ESDD_UD_119 */
extern VAR(RamTst_TestResultType, RAMTST_VAR_FAST)
                                      RamTst_TestResultBuffer[RAMTST_MAX_BLOCK];
/* Variable for getting Algorithm */
/* RAMTST_H_044: RAMTST_ESDD_UD_121 */
extern VAR(RamTst_AlgorithmType, AUTOMATIC) RamTst_Algorithm;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_026: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
*                             API FUNCTION PROTOTYPES                          *
*******************************************************************************/
/* RAMTST_H_027: SWS_BSW_00110, SWS_BSW_00048 */
/* Start of RamTst Section Code   */
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_CODE_ASIL_B
#else
#define RAMTST_START_SEC_CODE
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_028: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* RAMTST_H_057: EAAR_PN0034_FR_0063 */
#if (RAMTST_AR_VERSION == RAMTST_AR_LOWER_VERSION)
extern FUNC(void, RAMTST_CODE) RamTst_Init(void);
#else
extern FUNC(void, RAMTST_CODE) RamTst_Init(
  P2CONST(RamTst_ConfigType, AUTOMATIC, RAMTST_CONFIG_CONST) ConfigPtr);
#endif

extern FUNC(void, RAMTST_CODE) RamTst_DeInit(void);

/* RAMTST_H_092: RamTst127_Conf */
#if (RAMTST_STOP_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_Stop(void);
#endif

/* RAMTST_H_080: RamTst120_Conf */
#if (RAMTST_ALLOW_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_Allow(void);
#endif

/* RAMTST_H_093: RamTst156_Conf */
#if (RAMTST_SUSPEND_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_Suspend(void);
#endif

/* RAMTST_H_088: RamTst155_Conf */
#if (RAMTST_RESUME_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_Resume(void);
#endif

/* RAMTST_H_049: RAMTST_ESDD_UD_130 */
/* RAMTST_H_083: RamTst122_Conf */
#if (RAMTST_GET_EXECUTION_STATUS_API == STD_ON)
extern FUNC(RamTst_ExecutionStatusType, RAMTST_CODE)
                                                RamTst_GetExecutionStatus(void);
#endif

/* RAMTST_H_085: RamTst125_Conf */
#if (RAMTST_GET_TEST_RESULT_API == STD_ON)
extern FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResult(void);
#endif

/* RAMTST_H_086: RamTst126_Conf */
#if (RAMTST_GET_TEST_RESULT_PER_BLOCK_API == STD_ON)
extern FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResultPerBlock
                          (VAR(RamTst_NumberOfBlocksType, AUTOMATIC) BlockID);
#endif

/* RAMTST_H_048: RAMTST_ESDD_UD_129 */
/* RAMTST_H_082: RamTst183_Conf */
#if (RAMTST_GET_ALG_PARAMS_API == STD_ON)
extern FUNC(RamTst_AlgParamsIdType, RAMTST_CODE) RamTst_GetAlgParams(void);
#endif

/* RAMTST_H_084: RamTst124_Conf */
#if (RAMTST_GET_TEST_ALGORITHM_API == STD_ON)
extern FUNC(RamTst_AlgorithmType, RAMTST_CODE) RamTst_GetTestAlgorithm(void);
#endif

/* RAMTST_H_050: RAMTST_ESDD_UD_131 */
/* RAMTST_H_084: RamTst123_Conf */
#if (RAMTST_GET_NUMBER_OF_TESTED_CELLS_API == STD_ON)
extern FUNC(RamTst_NumberOfTestedCellsType, RAMTST_CODE)
                                         RamTst_GetNumberOfTestedCells(void);
#endif

/* RAMTST_H_091: RamTst182_Conf */
#if (RAMTST_SELECT_ALG_PARAMS_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_SelectAlgParams
(VAR(RamTst_AlgParamsIdType, AUTOMATIC)NewAlgParamsId);
#endif

/* RAMTST_H_081: RamTst118_Conf */
#if (RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_ChangeNumberOfTestedCells
(VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) NewNumberOfTestedCells);
#endif

/* RAMTST_H_089: RamTst184_Conf */
#if (RAMTST_RUN_FULL_TEST_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_RunFullTest(void);
#endif

/* RAMTST_H_090: RamTst185_Conf */
#if (RAMTST_RUN_PARTIAL_TEST_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_RunPartialTest
(VAR(RamTst_NumberOfBlocksType, AUTOMATIC)BlockId);
#endif

extern FUNC(void, RAMTST_CODE) RamTst_MainFunction(void);

/* RAMTST_H_078: RamTst109 */
/* RAMTST_H_087: RamTst128_Conf */
#if (RAMTST_GET_VERSION_INFO_API == STD_ON)
extern FUNC(void, RAMTST_CODE) RamTst_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, RAMTST_APPL_DATA) VersionInfo);
#endif

/** End of RamTst Section Code  */
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_CODE_ASIL_B
#else
#define RAMTST_STOP_SEC_CODE
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_029: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
*                             External variables                               *
*******************************************************************************/
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
#define RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_030: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:3684)-2 */
/* RamTst Configuration array */
/* RAMTST_H_034: RAMTST_ESDD_UD_108 */
extern CONST(RamTst_ConfigType, RAMTST_CONST) RamTst_59_93_Config[];
/* END Msg(4:3684)-2 */
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
#define RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* RAMTST_H_031: SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* RAMTST_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
