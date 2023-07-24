/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = RamTst.c                                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the implementations AUTOSAR specified APIs for RamTst   */
/* handler.                                                                   */
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
 *
 * V1.0.2:  12-Apr-2014  : As per CR 463, following changes are made:
 *                         1. Updated as per coding guidelines.
 *                         2. Enter and Exit of Critical section is updated.
 *                         3. Det Error ID is correct for API "RamTst_DeInit".
 *
 * V1.1.0:  23-Jun-2014  : As per CR 531, for mantis #21172, #21269 and #21175
 *                         following changes are made:
 *                         1. Updated as per coding guidelines.
 *                         2. "RAMTST_C_SW_MINOR_VERSION" is updated.
 *                         3. Autosar Specification for DET errors are
 *                            satisfied.
 *                         4. Register read-back is implemented in API's
 *                            "RamTst_Init".
 *
 * V1.1.1:  15-Jul-2014  : As per CR 557, following change is made:
 *                         1. Scheduler Protocol is updated.
 *
 * V1.1.2:  18-Sep-2014  : As per CR 09, following change is made:
 *                         1. File is updated for removal and addition of QAC
 *                            warning message.
 *                         2. File is Updated as per coding guidelines.
 *                         3. RamTst_GusLRECCMirror, RamTst_GusLRECCMask
 *                            are included in RAMTST_START_SEC_VAR_NOINIT_16
 *                            Memory section.
 *
 * V1.1.3:  02-Dec-2014  : As per CR 83, for mantis #14715 and #25451, following
 *                         change is made:
 *                         1. File is updated with RAMTST_VAR for P2CONST the
 *                            memory class.
 *                         2. Previous Revision Control History is updated.
 *                         3. File is updated for removal of unwanted QAC
 *                            warning message.
 *
 * V1.1.4:  13-Feb-2015 :  As part of merging activity (mantis #26024),
 *                         following changes are made:
 *                         1. P1X file is adapted from P1X branch.
 *                         2. Copyright information is updated.
 *
 * V1.1.5:  20-May-2015 :  As per mantis #26199, critical section name
 *                         'RAM_DATA_PROTECTION' is changed to
 *                         'RAMTST_RAM_DATA_PROTECTION'.
 *                         As per mantis #25588, function headers are updated.
 *
 * V1.2.0:  30-Sep-2016 :  WriteVerify and HWConsistencyCheck related
 *                         functionality added (ARDAABC-722, ARDAABC-724,
 *                         ARDAABC-726)
 *
 * V1.3.0:  19-Oct-2016 :  Read verify ECC configuration registers
 *                         implementation added (ARDAABC-901)
 *
 * V1.3.1:  19-Oct-2016 :  As part of ARDAABC-917, MISRA related issues solved.
 *                         RamTst_RunPartialTest implementation changed as
 *                         follows: BlockIdFound variable is introduces to
 *                         eliminate break statement in the for loop.
 *
 * V1.3.2:  28-Oct-2016 :  Traceability tag format changed, missing tags added
 *                         (ARDAABC-900)
 *
 * V1.3.3:  02-Nov-2016 :  As part of ARDAABC-917, implementation of
 *                         RamTst_RunPartialTest corrected after MISRA related
 *                         issues solved: condition "if (index < RamTstAlgPtr->
 *                         RamTstNumberOfBlocks)" replaced by "if (TRUE ==
 *                         BlockIdFound)"
 *
 * V2.0.0:  07-Nov-2016 :  As part of ARDAABC-939, following changes are made:
 *                         1. RAMTST_C_SW_MAJOR/MINOR_VERSION macros updated
 *                         2. Expected AR version of external modules changed
 *                         3. MemMap.h replaced by macro RAMTST_MEMMAP_FILE
 *                         4. RamTst_Init has a ConfigPtr parameter when
 *                            compiled for AR422
 *                         5. New AR422 DEM errors added
 *                         6. Updated memory section names
 *
 * V2.1.0:  11-Nov-2016 :  As part of ARDAABC-938, following changes are made:
 *                         1. Made definiton of RamTst_CRC AUTOSAR compliant
 *                         2. Added mask parameter for all instances of
 *                            RAMTST_CHECK_WRITE_VERIFY_INIT
 *                         3. Replaced ApiID parameter to RAMTST_INIT_SVCID for
 *                            all instances of RAMTST_CHECK_WRITE_VERIFY_INIT
 *                         4. Added Det error check in RamTst_CheckHWConsistency
 *
 * V2.1.1:  16-Nov-2016 :  As part of the review activity the following changes
 *                         are made (ARDAABC-726):
 *                         1. RamTst_RunPartialTest changes adde to file history
 *                            for revisions 1.3.1 and 1.3.3
 *                         2. RamTst_OverallTestResult, RamTst_ExecutionStatus,
 *                            RamTst_TestResultBuffer and RamTst_Algorithm moved
 *                            into section VAR_POWER_ON_INIT_UNSPECIFIED
 *                         3. Inclusion of RamTst_RegWrite.h removed
 *                         4. Trailing spaces removed.
 * V2.1.2:  03-Dec-2016 :  As part of ARDAABC-571 the following changes made
 *                         1. Traceability tags updated according to AR4.2.2
 *                            format
 * V2.1.3:  07-Dec-2016 :  As part of ARDAABC-588 the following changes made
 *                         1. New SWS_BSW_nnnnn and SWS_RamTst_nnnnn
 *                            traceability tags added.
 * V2.1.4:  19-Dec-2016 :  Too long lines wrapped.
 * V2.1.5:  11-Feb-2017 :  As part of ARDAABC-900 the following changes were
 *                         made:
 *                         1)Traceability tags RAM_ESDD_UD_xxx were added
 * V2.1.6:  16-Jun-2017 :  As part of F1KM support, verification and
 *                         configuration of the Global RAM control registers
 *                         is implemented.
 * V2.1.7:  01-Aug-2017 :  Updated code to remove QAC warnings.
 *                         Justification added for warnings which cannot be
 *                         corrected as specified in ARDAARBD-2147.
 * V2.2.0:  26-Sep-2017 :  The following changes are made:
 *                         1. As part of ARDAABD-1741, a verification mechanism
 *                         is implemented for DET off state.
 *                         2. As part of ARDAABD-1625, RamTst_RunPartialTest is
 *                         changed to report multiple DET errors. Changed the
 *                         condition for BlockID verification to compare with
 *                         RamTstNumberOfBlocks field of RamTstAlgConfig.
 *                         3. As part of ARDAABD-1653, in RamTst_ChangeNumberOf
 *                         TestedCells embedded RamTst_ExtNumTestedCell in DET
 *                         precompile switches.
 *                         4. As part of ARDAABD-1624, internal function
 *                         RamTst_ReadAscend is embedded also with
 *                         RAMTST_MARCH_Y_TEST_SELECTED precompile switches.
 *                         5. As part of ARDAABD-1414, for functions
 *                         RamTst_SelectAlgParams,
 *                         RamTst_ChangeNumberOfTestedCells,
 *                         RamTst_RunPartialTest ,RamTst_GetTestResultPerBlock
 *                         has been implementation to report multiple DETs.
 *                         6. As part of ARDAABD-2319, local buffer was removed
 *                         from internal test algorithm functions and
 *                         RAMTST_NON_DESTRUCTIVE_POLICY has been added.
 *                         7. As part of ARDAABD-2252, Write-Verify mechanism
 *                         for ECC registers and vendor specific function
 *                         RamTst_HWConsistencyCheckType are removed.
 *                         8. As part of ARDAABD-1413, removed the macro
 *                         implementation of RamTst_GetVersionInfo and
 *                         implemented as a C function.
 *                         9. Removed MISRA rule violation (4:3200) related to
 *                         DET function.
 *                         10. Changed the specifier for constant variables
 *                         within functions and initialized the local variables
 *                         as a distinct statement from declaration statement.
 * V2.2.1:  14-Jul-2018 :  Following changes are made:
 *                         1. As part of merging activity ARDAABD-3470
 *                            a. RAMTST_<START/STOP>_SEC_VAR_NO_INIT_ASIL_B_16
 *                               and RAMTST_<START/STOP>_SEC_VAR_NO_INIT_16
 *                               are changed to
 *                               RAMTST_<START/STOP>_SEC_VAR_INIT_ASIL_B_16 and
 *                               RAMTST_<START/STOP>_SEC_VAR_INIT_16
 *                               respectively.
 *                            b. RAMTST_<START/STOP>_SEC_VAR_NO_INIT_ASIL_B_32
 *                               and RAMTST_<START/STOP>_SEC_VAR_NO_INIT_32 are
 *                               changed to
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
 *                         2. Updated copyright information.
 *                         3. As part of ARDAABD-3555, included reference tags.
 *                         4. As part of ARDAABD-2101, added traceability tags
 *                            for Reqtify coverage improvement.
 * V2.2.2:  24-Dec-2018 :  Following changes are made:
 *                            As per ARDAABL-4080, in
 *                            RamTst_ChangeBlock_BackGrndTest and
 *                            RamTst_ChangeBlock_ForeGrndTest, removed a
 *                            condition from for loop and added the same in a
 *                            if loop and an else part is added to avoid QAC
 *                            warning.
 */
/******************************************************************************/
/* Implements RamTst003 */
/* Implements SWS_RamTst_00003 */
/* Implements EAAR_PN0034_FR_0047, EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0065, AR_PN0040_FR_0017 */
/* Implements AR_PN0040_FR_0038 */
/* Implements AR_PN0040_NR_0006 */
/* Implements EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0007, EAAR_PN0034_NR_0056 */
/* Implements EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0020 */
/* Implements EAAR_PN0034_NR_0069 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* RamTest Header file */
/* Implements RamTst208 */
/* Implements RamTst155 */
#include "RamTst.h"
/* Implements RamTst121_Conf */
#if (RAMTST_DEV_ERROR_DETECT == STD_ON)
/* Det public header file*/
#include "Det.h"
#endif
/* Implements SWS_BSW_00007 */
/* SchM RamTest header file  */
#include "SchM_RamTst.h"
/* Implements RamTst072 */
/* Implements SWS_BSW_00008 */
/* Dem public header file*/
/* Implements RamTst073 */
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* RAMTST_H_054: EAAR_PN0034_FR_0055 */
/* Implements AR_PN0040_FR_0020 */
/* Implements RamTst117 */
/* Implements RAMTST_ESDD_UD_135 */
/* RAMTST SW Major Version */
#define RAMTST_C_SW_MAJOR_VERSION   2
/* RAMTST SW Minor Version       */
#define RAMTST_C_SW_MINOR_VERSION   1


/* RAMTST AR Major Version       */
#define RAMTST_C_AR_RELEASE_MAJOR_VERSION   RAMTST_CFG_AR_RELEASE_MAJOR_VERSION
/* RAMTST AR Minor Version       */
#define RAMTST_C_AR_RELEASE_MINOR_VERSION   RAMTST_CFG_AR_RELEASE_MINOR_VERSION
/* RAMTST AR Patch Version       */
#define RAMTST_C_AR_RELEASE_REVISION_VERSION \
                                          RAMTST_CFG_AR_RELEASE_REVISION_VERSION

/* Det AR Major Version       */
#define DET_C_AR_MAJOR_VERSION        RAMTST_C_AR_RELEASE_MAJOR_VERSION
/* Det AR Minor Version       */
#define DET_C_AR_MINOR_VERSION        RAMTST_C_AR_RELEASE_MINOR_VERSION

/* Dem AR Major Version       */
#define DEM_C_AR_MAJOR_VERSION        RAMTST_C_AR_RELEASE_MAJOR_VERSION
/* Dem AR Minor Version       */
#define DEM_C_AR_MINOR_VERSION        RAMTST_C_AR_RELEASE_MINOR_VERSION

/* STD_TYPES AR Major Version */
#define STD_TYPES_C_AR_MAJOR_VERSION  RAMTST_C_AR_RELEASE_MAJOR_VERSION
/* STD_TYPES AR Minor Version */
#define STD_TYPES_C_AR_MINOR_VERSION  RAMTST_C_AR_RELEASE_MINOR_VERSION

/* MEMMAP AR Major Version */
#define MEMMAP_C_AR_MAJOR_VERSION     RAMTST_C_AR_RELEASE_MAJOR_VERSION
/* MEMMAP AR Minor Version */
#define MEMMAP_C_AR_MINOR_VERSION     RAMTST_C_AR_RELEASE_MINOR_VERSION

/* Version checking for RAMTST Module's internal c and h files */
/* Implements RamTst117 */
#if (RAMTST_C_SW_MAJOR_VERSION != RAMTST_SW_MAJOR_VERSION)
  #error "Incompatible RAMTST Driver SW major version"
#endif

#if (RAMTST_C_SW_MINOR_VERSION != RAMTST_SW_MINOR_VERSION)
  #error "Incompatible RAMTST Driver SW minor version"
#endif

/*******************************************************************************
**                          DET Section                                       **
*******************************************************************************/
#if (STD_ON == RAMTST_VERSION_CHECK_EXT_MODULES)
/* Implements RamTst121_Conf */
#if (STD_ON == RAMTST_DEV_ERROR_DETECT)
#if (DET_C_AR_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
#error "DET Module's header file Major Version mismatch"
#endif
#if (DET_C_AR_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)
#error "DET Module's header file Minor Version mismatch"
#endif
#endif

/*******************************************************************************
**                          DEM Section                                       **
*******************************************************************************/
/* DEM Driver AR Major version checking before compilation */
#if (DEM_C_AR_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION)
#error "DEM Module's header file Major Version mismatch"
#endif
/* DEM Driver AR Minor version checking before compilation */
#if (DEM_C_AR_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION)
#error "DEM Module's header file Minor Version mismatch"
#endif

/*******************************************************************************
**                          Std_Types                                         **
*******************************************************************************/
#if (STD_TYPES_AR_RELEASE_MAJOR_VERSION != STD_TYPES_C_AR_MAJOR_VERSION)
#error "STD_TYPES Module's header file Major Version mismatch"
#endif

#if (STD_TYPES_AR_RELEASE_MINOR_VERSION != STD_TYPES_C_AR_MINOR_VERSION)
#error "STD_TYPES Module's header file Minor Version mismatch"
#endif

/*******************************************************************************
**                          RamTst                                            **
*******************************************************************************/
#if (RAMTST_AR_RELEASE_MAJOR_VERSION != RAMTST_C_AR_RELEASE_MAJOR_VERSION)
    #error Incompatible RAMTST AR Major Version
#endif

#if (RAMTST_AR_RELEASE_MINOR_VERSION != RAMTST_C_AR_RELEASE_MINOR_VERSION)
    #error Incompatible RAMTST AR Minor Version
#endif

/*******************************************************************************
**                          MemMap                                            **
*******************************************************************************/
#if (MEMMAP_C_AR_MAJOR_VERSION != MEMMAP_AR_RELEASE_MAJOR_VERSION)
    #error "MEMMAP Module's header file Major Version mismatch"
#endif
/* MEMMAP AR Minor version checking before compilation */
#if (MEMMAP_C_AR_MINOR_VERSION != MEMMAP_AR_RELEASE_MINOR_VERSION)
    #error "MEMMAP Module's header file Minor Version mismatch"
#endif
#endif

/* Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026 */
/*******************************************************************************
* Following are the MISRA C Violations in the RAMTST Driver code.             **
*******************************************************************************/
/* Implements SWS_BSW_00115 */

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Macro argument is empty.                          */
/*                                                                            */
/* Rule          : MISRA-C:2004 Rule 19.8                                     */
/*                 REFERENCE - ISO-6.3.3.2 Semantics                          */
/* Justification : This is done as per the AUTOSAR Compiler abstraction       */
/*                 requirement(AUTOSAR_SWS_Compiler_Abstraction.pdf).         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-1 and                           */
/*                 END Msg(4:0491)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/*                                                                            */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                                                                            */
/* Justification : Implementation requirement.                                */
/*                                                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-2 and                           */
/*                 END Msg(4:0488)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3218) File scope static, variable is only accessed      */
/*                 in one function.                                           */
/*                                                                            */
/* Rule          : MISRA-C:2004 Rule 8.7                                      */
/*                                                                            */
/* Justification : Implementation requirement.                                */
/*                                                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3218)-3 and                           */
/*                 END Msg(4:3218)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                 type.                                                      */
/*                                                                            */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                                                                            */
/* Justification : Implementation requirement.                                */
/*                                                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-4 and                           */
/*                 END Msg(4:0306)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/*                                                                            */
/* Rule          : MISRA-C:2004 Rule 8.5                                      */
/*                                                                            */
/* Justification : The variables required for Debugging by test environment.  */
/*                                                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-5 and                           */
/*                 END Msg(4:0303)-5 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
* Following are the QAC Warnings in the RAMTST Driver code.                   **
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
/* Message       : (2:0862) This #include "MemMap.h/Dem.h/Det.h"  directive   */
/*                 is redundant.                                              */
/* Justification : Each header has implemented safety for multiple inclusion. */
/*                 Header will not be included multiple times.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/*                                                                            */
/* Justification : Pointer is generated by configurator tool, which ensures   */
/*                 that is not a NULL pointer                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-3 and                           */
/*                 END Msg(2:2814)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/*                                                                            */
/* Justification : Pointer is generated by configurator tool, which ensures   */
/*                 that is not a NULL pointer                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-4 and                           */
/*                 END Msg(2:2824)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:3227) The parameter is never modified and so it could   */
/*                 be declared with the 'const' qualifier.                    */
/*                                                                            */
/* Justification : Parameter is not declared with the 'const' qualifier in    */
/*                 order to respect AUTOSAR SWS and module requirements.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-5 and                           */
/*                 END Msg(2:3227)-5 tags in the code.                        */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : (0:2755) Analysis time of function 'RamTst_CallAlgorithm'  */
/*                 has exceeded the configured maximum:'60000ms'.             */
/*                                                                            */
/* Justification : Execution of the function is dependant of the configured   */
/*                 block by the implementer.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(0:2755)-6 and                           */
/*                 END Msg(0:2755)-6 tags in the code.                        */
/******************************************************************************/

/* 7. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/*                                                                            */
/* Justification : The default statement is required by the MISRA standard.   */
/*                                                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-7 and                           */
/*                 END Msg(2:2016)-7 tags in the code.                        */
/******************************************************************************/

/* 8. QAC Warning:                                                            */
/* Message       : (2:3206) The parameter 'ConfigPtr' is not used in          */
/*                 this function.                                             */
/* Justification : Implicit requirement as specified by AUTOSAR SWS for AR422.*/
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-8 and                           */
/*                 END Msg(2:3206)-8 tags in the code.                        */
/******************************************************************************/

/* 9. QAC Warning:                                                            */
/* Message       : (2:3204) The variable 'BackGroundVariable' is only set once*/
/*                 and so it could be declared with the 'const' qualifier.    */
/* Justification : Internal coding guidelines specify the removal of local    */
/*                 const variable.                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3204)-9 and                           */
/*                 END Msg(2:3204)-9 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                         Global Variables                                   **
*******************************************************************************/
/* Implements SWS_BSW_00129 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_INIT_ASIL_B_16
#else
#define RAMTST_START_SEC_VAR_INIT_16
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Variable for RamTst blocks */
/* Implements RAMTST_ESDD_UD_110, RAMTST_ESDD_UD_123  */
VAR(RamTst_NumberOfBlocksType, RAMTST_VAR) RamTst_Block = RAMTST_ZERO;
/* Implements RAMTST_ESDD_UD_109 */
VAR(RamTst_NumberOfBlocksType, RAMTST_VAR) RamTst_NumBlock = RAMTST_ZERO;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_INIT_ASIL_B_16
#else
#define RAMTST_STOP_SEC_VAR_INIT_16
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_INIT_ASIL_B_32
#else
#define RAMTST_START_SEC_VAR_INIT_32
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements  RAMTST_ESDD_UD_122 */
/* Variable for number of tested cell */
VAR(RamTst_NumberOfTestedCellsType, RAMTST_VAR) RamTst_NumTestedCell
                                                                  = RAMTST_ZERO;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_INIT_ASIL_B_32
#else
#define RAMTST_STOP_SEC_VAR_INIT_32
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_ASIL_B_8
#else
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_8
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements RamTst163 */
/* Implements SWS_RamTst_00163 */
/* Implements RamTst188 */
/* Implements SWS_RamTst_00188 */
/* Implements RAMTST_ESDD_UD_120 */
VAR(RamTst_AlgParamsIdType, RAMTST_VAR) RamTst_AlgParamsId = RAMTST_ZERO;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_ASIL_B_8
#else
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_8
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements RamTst161 */
/* Implements SWS_RamTst_00161 */
/* Implements RAMTST_ESDD_UD_119 */
VAR(RamTst_TestResultType, RAMTST_VAR_POWER_ON_INIT)RamTst_OverallTestResult
                                                 = RAMTST_RESULT_NOT_TESTED;
/* Implements RAMTST_ESDD_UD_118 */
VAR(RamTst_ExecutionStatusType, RAMTST_VAR_POWER_ON_INIT)RamTst_ExecutionStatus
                                                 = RAMTST_EXECUTION_UNINIT;
/* Implements RAMTST_ESDD_UD_121 */
VAR(RamTst_AlgorithmType, RAMTST_VAR) RamTst_Algorithm =
                                                     RAMTST_ALGORITHM_UNDEFINED;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements RAMTST_ESDD_UD_156 */
P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) RamTst_CellAddress
                                                                     = NULL_PTR;
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                         Static Variables                                   **
*******************************************************************************/
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_INIT_ASIL_B_32
#else
#define RAMTST_START_SEC_VAR_INIT_32
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements RamTst121_Conf */
#if (RAMTST_DEV_ERROR_DETECT == STD_ON)
/* Implements  RAMTST_ESDD_UD_122 */
/* Static variable for Maximum Number tested cells */
STATIC VAR(RamTst_NumberOfTestedCellsType, RAMTST_VAR) RamTst_MaxNumTestedCell
                                                                  = RAMTST_ZERO;
/* Static variable for Ext Number tested cells */
STATIC VAR(RamTst_NumberOfTestedCellsType, RAMTST_VAR) RamTst_ExtNumTestedCell
                                                                  = RAMTST_ZERO;
/* Static variable for Minimum  Number tested cells */
STATIC VAR(RamTst_NumberOfTestedCellsType, RAMTST_VAR)
                                   RamTst_MinNumberOf_TestedCells = RAMTST_ZERO;
#endif
/* Static variable for Fillpattern */
STATIC VAR(uint32, RAMTST_VAR)RamTst_FillPattern = RAMTST_ZERO;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_INIT_ASIL_B_32
#else
#define RAMTST_STOP_SEC_VAR_INIT_32
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements RamTst121_Conf */
#if (RAMTST_DEV_ERROR_DETECT == STD_ON)
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_INIT_ASIL_B_8
#else
#define RAMTST_START_SEC_VAR_INIT_8
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements RAMTST_ESDD_UD_120 */
STATIC VAR(RamTst_AlgParamsIdType, RAMTST_VAR)
                                     RamTst_NumberOf_AlgParamSets = RAMTST_ZERO;

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_INIT_ASIL_B_8
#else
#define RAMTST_STOP_SEC_VAR_INIT_8
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif

/* Implements EAAR_PN0034_FR_0021 */
#if (STD_ON == RAMTST_TRANSP_GALPAT_TEST_SELECTED)

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_CONST_ASIL_B_16
#else
#define RAMTST_START_SEC_CONST_16
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Fast CRC lookup table, standard hashing table for Polynomial 0xA001 */
/* MISRA Violation: START Msg(4:3218)-3 */
/* Implements SWS_RamTst_00221 */
STATIC CONST(uint16, RAMTST_CONST) RamTst_CRC[RAMTST_CRC_TABLE_LENGTH] =
/* END Msg(4:3218)-3 */
{
  0x0000u, 0xC0C1u, 0xC181u, 0x0140u, 0xC301u, 0x03C0u, 0x0280u, 0xC241u,
  0xC601u, 0x06C0u, 0x0780u, 0xC741u, 0x0500u, 0xC5C1u, 0xC481u, 0x0440u,
  0xCC01u, 0x0CC0u, 0x0D80u, 0xCD41u, 0x0F00u, 0xCFC1u, 0xCE81u, 0x0E40u,
  0x0A00u, 0xCAC1u, 0xCB81u, 0x0B40u, 0xC901u, 0x09C0u, 0x0880u, 0xC841u,
  0xD801u, 0x18C0u, 0x1980u, 0xD941u, 0x1B00u, 0xDBC1u, 0xDA81u, 0x1A40u,
  0x1E00u, 0xDEC1u, 0xDF81u, 0x1F40u, 0xDD01u, 0x1DC0u, 0x1C80u, 0xDC41u,
  0x1400u, 0xD4C1u, 0xD581u, 0x1540u, 0xD701u, 0x17C0u, 0x1680u, 0xD641u,
  0xD201u, 0x12C0u, 0x1380u, 0xD341u, 0x1100u, 0xD1C1u, 0xD081u, 0x1040u,
  0xF001u, 0x30C0u, 0x3180u, 0xF141u, 0x3300u, 0xF3C1u, 0xF281u, 0x3240u,
  0x3600u, 0xF6C1u, 0xF781u, 0x3740u, 0xF501u, 0x35C0u, 0x3480u, 0xF441u,
  0x3C00u, 0xFCC1u, 0xFD81u, 0x3D40u, 0xFF01u, 0x3FC0u, 0x3E80u, 0xFE41u,
  0xFA01u, 0x3AC0u, 0x3B80u, 0xFB41u, 0x3900u, 0xF9C1u, 0xF881u, 0x3840u,
  0x2800u, 0xE8C1u, 0xE981u, 0x2940u, 0xEB01u, 0x2BC0u, 0x2A80u, 0xEA41u,
  0xEE01u, 0x2EC0u, 0x2F80u, 0xEF41u, 0x2D00u, 0xEDC1u, 0xEC81u, 0x2C40u,
  0xE401u, 0x24C0u, 0x2580u, 0xE541u, 0x2700u, 0xE7C1u, 0xE681u, 0x2640u,
  0x2200u, 0xE2C1u, 0xE381u, 0x2340u, 0xE101u, 0x21C0u, 0x2080u, 0xE041u,
  0xA001u, 0x60C0u, 0x6180u, 0xA141u, 0x6300u, 0xA3C1u, 0xA281u, 0x6240u,
  0x6600u, 0xA6C1u, 0xA781u, 0x6740u, 0xA501u, 0x65C0u, 0x6480u, 0xA441u,
  0x6C00u, 0xACC1u, 0xAD81u, 0x6D40u, 0xAF01u, 0x6FC0u, 0x6E80u, 0xAE41u,
  0xAA01u, 0x6AC0u, 0x6B80u, 0xAB41u, 0x6900u, 0xA9C1u, 0xA881u, 0x6840u,
  0x7800u, 0xB8C1u, 0xB981u, 0x7940u, 0xBB01u, 0x7BC0u, 0x7A80u, 0xBA41u,
  0xBE01u, 0x7EC0u, 0x7F80u, 0xBF41u, 0x7D00u, 0xBDC1u, 0xBC81u, 0x7C40u,
  0xB401u, 0x74C0u, 0x7580u, 0xB541u, 0x7700u, 0xB7C1u, 0xB681u, 0x7640u,
  0x7200u, 0xB2C1u, 0xB381u, 0x7340u, 0xB101u, 0x71C0u, 0x7080u, 0xB041u,
  0x5000u, 0x90C1u, 0x9181u, 0x5140u, 0x9301u, 0x53C0u, 0x5280u, 0x9241u,
  0x9601u, 0x56C0u, 0x5780u, 0x9741u, 0x5500u, 0x95C1u, 0x9481u, 0x5440u,
  0x9C01u, 0x5CC0u, 0x5D80u, 0x9D41u, 0x5F00u, 0x9FC1u, 0x9E81u, 0x5E40u,
  0x5A00u, 0x9AC1u, 0x9B81u, 0x5B40u, 0x9901u, 0x59C0u, 0x5880u, 0x9841u,
  0x8801u, 0x48C0u, 0x4980u, 0x8941u, 0x4B00u, 0x8BC1u, 0x8A81u, 0x4A40u,
  0x4E00u, 0x8EC1u, 0x8F81u, 0x4F40u, 0x8D01u, 0x4DC0u, 0x4C80u, 0x8C41u,
  0x4400u, 0x84C1u, 0x8581u, 0x4540u, 0x8701u, 0x47C0u, 0x4680u, 0x8641u,
  0x8201u, 0x42C0u, 0x4380u, 0x8341u, 0x4100u, 0x81C1u, 0x8081u, 0x4040u
};
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_CONST_ASIL_B_16
#else
#define RAMTST_STOP_SEC_CONST_16
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif

/*******************************************************************************
**                         Internal Functions                                 **
*******************************************************************************/
/* Start of RAMTST Section Code */
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_CODE_ASIL_B
#else
#define RAMTST_START_SEC_CODE
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements RAMTST_ESDD_UD_145 */
/* Implements RamTst130_Conf */
/* Implements ECUC_RamTst_00130 */
#if (STD_ON == RAMTST_CHECKERBOARD_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_Checker_Algorithm
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber
);
#endif

/* Implements RamTst132_Conf */
/* Implements ECUC_RamTst_00132 */
#if (STD_ON == RAMTST_GALPAT_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_Galpat_Algorithm
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber
);
#endif
/* Implements RAMTST_ESDD_UD_148 */
/* Implements RamTst135_Conf */
/* Implements ECUC_RamTst_00135 */
#if (STD_ON == RAMTST_WALK_PATH_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_WalkPath_Algorithm
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber
);
#endif

/* Implements RamTst133_Conf */
/* Implements ECUC_RamTst_00133 */
#if (STD_ON == RAMTST_MARCH_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_March_Algorithm
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber
);
#endif

/* Implements EAAR_PN0034_FR_0020 */
#if (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_MarchY_Algorithm
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber
);
#endif
/* Implements RAMTST_ESDD_UD_147 */
/* Implements RamTst134_Conf */
/* Implements ECUC_RamTst_00134 */
#if (STD_ON == RAMTST_TRANSP_GALPAT_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_Transp_Galpat_Algorithm
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber
);
#endif
/* Implements RamTst129_Conf */
/* Implements RAMTST_ESDD_UD_143 */
/* Implements ECUC_RamTst_00129 */
#if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_Abraham_Algorithm
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber
);
STATIC FUNC(Std_ReturnType, RAMTST_CODE)RamTst_Abraham_TestSteps
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
#endif

STATIC FUNC(void, RAMTST_CODE) RamTst_ChangeBlock_BackGrndTest
(
  void
);
/* Implements RamTst184_Conf */
/* Implements RAMTST_ESDD_UD_137 */
#if (RAMTST_RUN_FULL_TEST_API == STD_ON)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_ChangeBlock_ForeGrndTest
(
  void
);
#endif
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_CallAlgorithm
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells
);

/* Implements EAAR_PN0034_FR_0020 */
#if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
STATIC FUNC(void, RAMTST_CODE) RamTst_SaveData
(
  /* Implements RAMTST_ESDD_UD_122 */
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_CODE) Buffer,
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells
);

STATIC FUNC(void, RAMTST_CODE) RamTst_RestoreData
(
  /* Implements RAMTST_ESDD_UD_122 */
  P2CONST(RamTst_TestDataType, AUTOMATIC, RAMTST_CODE) Buffer,
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
#endif

STATIC FUNC(void, RAMTST_CODE) RamTst_FillData
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(uint32, RAMTST_VAR)RamTstFillPattern,
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);

/* Implements ECUC_RamTst_00129 */
#if ((STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) || \
(STD_ON == RAMTST_MARCH_TEST_SELECTED) || \
(STD_ON == RAMTST_MARCH_Y_TEST_SELECTED) || \
(STD_ON == RAMTST_GALPAT_TEST_SELECTED) || \
(STD_ON == RAMTST_WALK_PATH_TEST_SELECTED))
STATIC FUNC(void, RAMTST_CODE) RamTst_InitializeCell
(
  /* Implements RAMTST_ESDD_UD_122 */
  VAR(RamTst_TestDataType, AUTOMATIC) Init_CellVariable,
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
#endif

/* Implements ECUC_RamTst_00133 */
#if ((STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) || \
(STD_ON == RAMTST_MARCH_TEST_SELECTED))
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWAscend
(
  VAR(uint8, AUTOMATIC) CheckVariable,
  VAR(uint32, AUTOMATIC) Totalbits,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);

STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWDescend
(
  VAR(uint8, AUTOMATIC) CheckVariable,
  VAR(uint32, AUTOMATIC) Totalbits,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
#endif

#if (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWRAscend
(
  VAR(RamTst_TestDataType, AUTOMATIC) CheckVariable,
  VAR(uint32, AUTOMATIC) Totalbits,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);

STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWRDescend
(
  VAR(RamTst_TestDataType, AUTOMATIC) CheckVariable,
  VAR(uint32, AUTOMATIC) Totalbits,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
#endif

#if ((STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) || \
  (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED))
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_ReadAscend
(
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable,
  P2CONST(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
#endif
#if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_ReadDescend
(
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable,
  P2CONST(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
#endif

#if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWWDescend
(
  VAR(uint8, AUTOMATIC) CheckVariable,
  VAR(uint32, AUTOMATIC) Totalbits,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);

STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWWAscend
(
  VAR(uint8, AUTOMATIC) CheckVariable,
  VAR(uint32, AUTOMATIC) Totalbits,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_WRWAscend
(
  VAR(uint8, AUTOMATIC) CheckVariable,
  VAR(uint32, AUTOMATIC) Totalbits,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_WRWDescend
(
  VAR(uint8, AUTOMATIC) CheckVariable,
  VAR(uint32, AUTOMATIC) Totalbits,
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress
);

#endif

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_CODE_ASIL_B
#else
#define RAMTST_STOP_SEC_CODE
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/* Start of RAMTST Section Code */
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_CODE_ASIL_B
#else
#define RAMTST_START_SEC_CODE
#endif
/* Implements SWS_BSW_00006 */
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : RamTst_Init
**
** Service ID            : 0x00
**
** Description           : This API is for initialization and change the state
**                         of Ram Test module.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : ConfigPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : RamTst_MinNumberOf_TestedCells,
**                         RamTst_NumTestedCell,
**                         RamTst_Algorithm,
**                         RamTst_NumBlock,
**                         RamTst_MaxNumTestedCell,
**                         RamTst_ExtNumTestedCell,
**                         RamTst_CellAddress,
**                         RamTst_FillPattern,
**                         RamTst_TestResultBuffer[],
**                         RamTst_ExecutionStatus,
**                         RamTst_OverallTestResult
**
** Function(s) invoked   : Det_ReportError
**                         Dem_ReportErrorStatus
**
** Registers Used        : LRTSTCTL_PE1, LRECCCTL_PE1, LRERRINT_PE1
**                         GRTSTCTL_BKA, GRECCCTL_BKA, GRERRINT_BKA
**                         GRTSTCTL_BKB, GRECCCTL_BKB, GRERRINT_BKB
*******************************************************************************/
/* Implements RamTst099 */
/* Implements SWS_RamTst_00099 */
/* Implements SWS_RamTst_00099 */
/* Implements RamTst093 */
/* Implements SWS_RamTst_00093 */
/* Implements SWS_BSW_00148 */
/* Implements SWS_BSW_00186 */
/* Implements SWS_BSW_00229 */
/* Implements SWS_BSW_00185 */
/* Implements SWS_RamTst_01012 */
/* Implements RAMTST_ESDD_UD_105 */
/* Implements EAAR_PN0081_FR_0005, EAAR_PN0081_FR_0011 */
/* Implements EAAR_PN0081_FR_0006, EAAR_PN0081_FR_0012 */
/* Implements RAMTST_ESDD_UD_053, EAAR_PN0081_FR_0010 */
/* Implements EAAR_PN0034_FR_0025 */
#if (RAMTST_AR_VERSION == RAMTST_AR_LOWER_VERSION)
FUNC(void, RAMTST_CODE) RamTst_Init (void)
#else
/* QAC Warning: START Msg(2:3206)-8 */
FUNC(void, RAMTST_CODE) RamTst_Init
  (P2CONST(RamTst_ConfigType, AUTOMATIC, RAMTST_CONFIG_CONST) ConfigPtr)
/* END Msg(2:3206)-8 */
#endif
{
  /* Pointer to the Algorithm Configuration Structure for the RAM Test */
  /* Implements   RAMTST_ESDD_UD_106 */
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Index to the RamTst_TestResultBuffer */
  /* Implements  RAMTST_ESDD_UD_123 */
  VAR(RamTst_NumberOfBlocksType, AUTOMATIC) Index;
  /* Implements RamTst116 */
  /* Implements SWS_BSW_00045 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RAMTST_ESDD_UD_114 */
  /* Implements RamTst096, SWS_RamTst_00112 */
  /* Implements SWS_RamTst_00096 */
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT != RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    /* Implements RAMTST_ESDD_UD_153 */
    /* Implements RAMTST_ESDD_UD_127 */
    /* Implements ECUC_RamTst_00121 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                   RAMTST_INIT_SVCID, RAMTST_E_STATUS_FAILURE);
  }
  else
  #else
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  #endif
  {
    /* Implements RamTst007 */
    /* Implements SWS_RamTst_00007 */
    /* Implements   RAMTST_ESDD_UD_106, RAMTST_ESDD_UD_116 */
    /* Initialize all RAM Test relevant global variables. */
    RamTst_AlgParamsId =
         RamTst_59_93_Config[RAMTST_ZERO].RamTstDefaultAlgParamsId;
    /* Implements RamTst121_Conf */
    #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
    /* Load minimum tested cell value to RamTst_MinNumberOf_TestedCells */
    /* Implements   RAMTST_ESDD_UD_106 */
    RamTst_MinNumberOf_TestedCells =
                  RamTst_59_93_Config[RAMTST_ZERO].RamTstMinNumberOfTestedCells;
    #endif
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(2:2814)-3 */
    /* Implements RAMTST_ESDD_UD_111 */
    RamTst_NumTestedCell = RamTstAlgPtr->RamTstNumberOfTestedCells;
    /* END Msg(2:2814)-3 */
    /* Implements RamTst121_Conf */
    #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
    /* Load Number of algorithm parameter to RamTst_NumberOf_AlgParamSets */
    RamTst_NumberOf_AlgParamSets =
                  RamTst_59_93_Config[RAMTST_ZERO].RamTstNumberOfAlgParamSets;
    #endif
    RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
    RamTst_Block = RAMTST_ZERO;
    /* Implements RAMTST_ESDD_UD_107, RAMTST_ESDD_UD_109 */
    RamTst_NumBlock = RamTstAlgPtr->RamTstNumberOfBlocks;
    /* Implements RamTst121_Conf */
    #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
    /* Load maximum tested cell value to RamTst_MaxNumTestedCell */
    /* Implements RAMTST_ESDD_UD_107 */
    RamTst_MaxNumTestedCell = RamTstAlgPtr->RamTstMaxNumberOfTestedCells;
    /* Load Ext tested cell value to RamTst_ExtNumTestedCell */
    RamTst_ExtNumTestedCell = RamTstAlgPtr->RamTstExtNumberOfTestedCells;
    #endif
    /* MISRA Violation: START Msg(4:0306)-4 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_CellAddress = (RamTst_TestDataType*)
          (RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstStartAddress);
    /* END Msg(4:0491)-1 */
    /* END Msg(4:0306)-4 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_FillPattern =
       (uint32)RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstFillPattern;
    /* END Msg(4:0491)-1 */
    /* Initialize the test results of configured blocks of the RAM Test */
    for (Index = RAMTST_ZERO;Index <
                            (RamTst_NumberOfBlocksType)RAMTST_MAX_BLOCK;Index++)
    {
      /* Implements RamTst207 */
      /* Implements SWS_RamTst_00207 */
      /* Implements RAMTST_ESDD_UD_115 */
      RamTst_TestResultBuffer[Index] = RAMTST_RESULT_NOT_TESTED;
    }
    /* Implements EAAR_PN0081_FSR_0003 */
    /* Implements RAMTST_ESDD_UD_142 */
    /* Implements SWS_RamTst_00221 */
    #if (RAMTST_ECC_CHECK == STD_ON)
    /* Read verify reset values of ECC configuration registers */
    /* Implements EAAR_PN0081_FSR_0002 */
    /* MISRA Violation: START Msg(4:0303)-5 */
    if ((RAMTST_LRTST_CNTL_RESET_VALUE != RAMTST_LRTST_CNTL) ||
      (RAMTST_LRECC_CNTL_RESET_VALUE != RAMTST_LRECC_CNTL) ||
      (RAMTST_LRERRINT_CNTL_RESET_VALUE != RAMTST_LRERRINT_CNTL)
    /* Implements EAAR_PN0081_FR_0021 */
    #if (RAMTST_GLOBAL_RAM == STD_ON)
      || (RAMTST_GRTST_CNTL_RESET_VALUE != RAMTST_GRTST_BKA_CNTL)
      || (RAMTST_GRECC_CNTL_RESET_VALUE != RAMTST_GRECC_BKA_CNTL)
      || (RAMTST_GRERRINT_CNTL_RESET_VALUE != RAMTST_GRERRINT_BKA_CNTL)
      || (RAMTST_GRTST_CNTL_RESET_VALUE != RAMTST_GRTST_BKB_CNTL)
      || (RAMTST_GRECC_CNTL_RESET_VALUE != RAMTST_GRECC_BKB_CNTL)
      || (RAMTST_GRERRINT_CNTL_RESET_VALUE != RAMTST_GRERRINT_BKB_CNTL)
    #endif
       )
    /* END Msg(4:0303)-5 */
    {
      /* Implements SWS_BSW_00205 */
      /* Implements SWS_BSW_00046 */
      /* Implements SWS_BSW_00066 */
      /* Implements SWS_RamTst_00111 */
      /* Implements RamTst111 */
      /* Implements RamTst188_Conf */
      /* Implements ECUC_RamTst_00150 */
      /* Implements ECUC_RamTst_00188 */
      /* The reset value of ECC configuration registers are not correct */
      Dem_ReportErrorStatus (RAMTST_E_ECC_FAILED, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* The reset value of ECC configuration registers are correct */
    }
    #endif /* (RAMTST_ECC_CHECK == STD_ON) */
    /* Implements RamTst007 */
    /* Implements SWS_RamTst_00007 */
    /* Implements SWS_BSW_00071 */
    /* Implements RAMTST_ESDD_UD_113, RAMTST_ESDD_UD_114 */
    RamTst_ExecutionStatus = RAMTST_EXECUTION_STOPPED;
    /* Initialize the over all test result */
    /* Implements RamTst202 */
    /* Implements SWS_RamTst_00202 */
    RamTst_OverallTestResult = RAMTST_RESULT_NOT_TESTED;
  }
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_OFF)
  else
  {
    /* Do nothing */
  }
  #endif
  /* Implements EAAR_PN0034_FR_0049 */
} /* End of RamTst_Init () */

/*******************************************************************************
** Function Name         : RamTst_DeInit
**
** Service ID            : 0x0c
**
** Description           : This API performs Deinitialization of RamTst Driver.
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
** Preconditions         : The function RamTst_Init shall be called
**                         first before calling this function.
**
** Global Variables Used : RamTst_AlgParamsId,
**                         RamTst_NumTestedCell,
**                         RamTst_CellAddress,
**                         RamTst_ExecutionStatus,
**                         RamTst_NumberOf_AlgParamSets
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst146 */
/* Implements SWS_RamTst_00146 */
/* Implements EAAR_PN0081_FR_0004 */
/* Implements RAMTST_ESDD_UD_054 */
/* Implements SWS_BSW_00148 */
/* Implements EAAR_PN0081_FR_0005, EAAR_PN0034_FR_0058 */
/* Implements EAAR_PN0081_FR_0006 */
FUNC(void, RAMTST_CODE) RamTst_DeInit (void)
{
  /* Implements RamTst116, SWS_RamTst_00112 */
  /* Implements SWS_BSW_00045 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    /* Implements RAMTST_ESDD_UD_155 */
    /* Implements RAMTST_ESDD_UD_127 */
    /* Implements ECUC_RamTst_00121 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                         RAMTST_DEINIT_SVCID, RAMTST_E_UNINIT);
  }
  else
  #else
  if (RAMTST_EXECUTION_UNINIT != RamTst_ExecutionStatus)
  #endif
  {
    /* DeInitialize all RAM Test relevant global variables. */
    /* Implements RamTst147 */
    /* Implements SWS_RamTst_00147 */
    /* Implements SWS_BSW_00072 */
    /* Change execution status */
    /* Implements RAMTST_ESDD_UD_114 */
    RamTst_ExecutionStatus = RAMTST_EXECUTION_UNINIT;
    RamTst_AlgParamsId = RAMTST_ZERO;
    RamTst_NumTestedCell = RAMTST_ZERO;
    RamTst_CellAddress = NULL_PTR;
    RamTst_FillPattern = RAMTST_ZERO;
    /* Implements RamTst121_Conf */
    #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
    RamTst_NumberOf_AlgParamSets = RAMTST_ZERO;
    #endif
  }
  #if (RAMTST_DEV_ERROR_DETECT == STD_OFF)
  else
  {
    /* Do nothing */
  }
  #endif
  /* Implements EAAR_PN0034_FR_0049 */
}/* End of RamTst_DeInit() */

/* Implements RAMTST_ESDD_UD_140 */
#if (RAMTST_STOP_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_Stop
**
** Service ID            : 0x02
**
** Description           : The Service for stopping the RAM Test.
**
** Sync/Async            : Asynchronous
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
** Preconditions         : The function RamTst_Init shall be called
**                         first before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst100 */
/* Implements SWS_RamTst_00100 */
/* Implements SWS_BSW_00148 */
/* Implements EAAR_PN0081_FR_0004 */
/* Implements RAMTST_ESDD_UD_055 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst127_Conf */
/* Implements ECUC_RamTst_00127 */
FUNC(void, RAMTST_CODE) RamTst_Stop (void)
{
  /* Implements RamTst116 */
  /* Implements SWS_BSW_00045 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements RamTst114 */
  /* Implements SWS_RamTst_00089, SWS_RamTst_00112 */
  /* Check if RAM Test Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    /* Implements RAMTST_ESDD_UD_155 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                           RAMTST_STOP_SVCID, RAMTST_E_UNINIT);
  }
  /* Implements RamTst033 */
  /* Implements SWS_RamTst_00033 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the "RamTst_ExecutionStatus" is relevant */
  else if (RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    /* Implements RAMTST_ESDD_UD_153 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                   RAMTST_STOP_SVCID, RAMTST_E_STATUS_FAILURE);
  }
  else
  #else
  if ((RAMTST_EXECUTION_RUNNING == RamTst_ExecutionStatus) ||
    (RAMTST_EXECUTION_SUSPENDED == RamTst_ExecutionStatus))
  #endif
  {
    /* Implements RamTst014 */
    /* Implements SWS_RamTst_00014 */
    /* Change execution status */
    RamTst_ExecutionStatus = RAMTST_EXECUTION_STOPPED;
  }
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_OFF)
  else
  {
    /* Do nothing */
  }
  #endif
  /* Implements EAAR_PN0034_FR_0049 */
} /* End of RamTst_Stop () */
/* Implements RAMTST_ESDD_UD_140 */
#endif /* End of RAMTST_STOP_API == STD_ON */

#if (RAMTST_ALLOW_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_Allow
**
** Service ID            : 0x03
**
** Description           : This Service for continuing the RAM Test after
**                         calling RamTst_Stop.
**
** Sync/Async            : Asynchronous
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
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst149 */
/* Implements SWS_RamTst_00149 */
/* Implements SWS_BSW_00148 */
/* Implements EAAR_PN0081_FR_0004 */
/* Implements RAMTST_ESDD_UD_056 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RAMTST_ESDD_UD_125 */
/* Implements RamTst120_Conf */
/* Implements ECUC_RamTst_00120 */
FUNC(void, RAMTST_CODE) RamTst_Allow (void)
{
  /* Implements RamTst116 */
  /* Implements SWS_BSW_00045 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if RAM Test Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                          RAMTST_ALLOW_SVCID, RAMTST_E_UNINIT);
  }
  /* Implements RamTst170 */
  /* Implements SWS_RamTst_00170 */
  else if (RAMTST_EXECUTION_STOPPED != RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                  RAMTST_ALLOW_SVCID, RAMTST_E_STATUS_FAILURE);
  }
  else
  #else
  if (RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
  #endif
  {
    /* Implements RamTst169 */
    /* Implements SWS_RamTst_00169 */
    RamTst_ExecutionStatus = RAMTST_EXECUTION_RUNNING;
  }
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_OFF)
  else
  {
    /* Do nothing */
  }
  #endif
}
#endif /* End of RAMTST_ALLOW_API == STD_ON */

#if (RAMTST_SUSPEND_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_Suspend
**
** Service ID            : 0x0d
**
** Description           : The Service for suspending current operation of
**                         background RAM Test, until RESUME is called.
**
** Sync/Async            : Asynchronous
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
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst150 */
/* Implements SWS_RamTst_00150 */
/* Implements SWS_BSW_00148 */
/* Implements SWS_RamTst_00203 */
/* Implements EAAR_PN0081_FR_0004 */
/* Implements RAMTST_ESDD_UD_057 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst156_Conf */
/* Implements ECUC_RamTst_00156 */
/* Implements RAMTST_ESDD_UD_141 */
FUNC(void, RAMTST_CODE) RamTst_Suspend (void)
{
  /* Implements RamTst116 */
  /* Implements SWS_BSW_00045 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if RAM Test Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                        RAMTST_SUSPEND_SVCID, RAMTST_E_UNINIT);
  }
  /* Implements RamTst172 */
  /* Implements SWS_RamTst_00172 */
  /* Implements RAMTST_ESDD_UD_114 */
  else if (RAMTST_EXECUTION_RUNNING != RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                RAMTST_SUSPEND_SVCID, RAMTST_E_STATUS_FAILURE);
  }
  else
  #else
  if (RAMTST_EXECUTION_RUNNING == RamTst_ExecutionStatus)
  #endif
  {
    /* Implements RamTst171 */
    /* Implements SWS_RamTst_00171 */
    RamTst_ExecutionStatus = RAMTST_EXECUTION_SUSPENDED;
  }
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_OFF)
  else
  {
    /* Do nothing */
  }
  #endif
}
#endif /* End of RAMTST_SUSPEND_API == STD_ON */

/* Implements RAMTST_ESDD_UD_136 */
#if (RAMTST_RESUME_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_Resume
**
** Service ID            : 0x0e
**
** Description           : The Service for allowing to continue the background
**                         RAM Test at the point is was suspended.
**
** Sync/Async            : Asynchronous
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
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst101 */
/* Implements SWS_RamTst_00101 */
/* Implements SWS_BSW_00148 */
/* Implements EAAR_PN0081_FR_0004 */
/* Implements RAMTST_ESDD_UD_058 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst155_Conf */
/* Implements ECUC_RamTst_00155 */
FUNC(void, RAMTST_CODE) RamTst_Resume (void)

{
  /* Implements RamTst116 */
  /* Implements SWS_BSW_00045 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if RAM Test Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                         RAMTST_RESUME_SVCID, RAMTST_E_UNINIT);
  }
  /* Implements RamTst037 */
  /* Implements SWS_RamTst_00037 */
  else if (RAMTST_EXECUTION_SUSPENDED != RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                 RAMTST_RESUME_SVCID, RAMTST_E_STATUS_FAILURE);
  }
  else
  #else
  if (RAMTST_EXECUTION_SUSPENDED == RamTst_ExecutionStatus)
  #endif
  {
    RamTst_ExecutionStatus = RAMTST_EXECUTION_RUNNING;
  }
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_OFF)
  else
  {
    /* Do nothing */
  }
  #endif
}
/* Implements RAMTST_ESDD_UD_136 */
#endif /* End of RAMTST_RESUME_API == STD_ON */

#if (RAMTST_GET_EXECUTION_STATUS_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_GetExecutionStatus
**
** Service ID            : 0x04
**
** Description           : This API return current Ram Test execution status
**                         for RamTst Driver.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : RamTst_ExecutionStatusType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst018 */
/* Implements SWS_RamTst_00018 */
/* Implements RamTst102 */
/* Implements SWS_RamTst_00102 */
/* Implements SWS_BSW_00148 */
/* Implements RAMTST_ESDD_UD_059 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RAMTST_ESDD_UD_130 */
/* Implements RamTst122_Conf */
/* Implements ECUC_RamTst_00122 */
FUNC(RamTst_ExecutionStatusType, RAMTST_CODE) RamTst_GetExecutionStatus (void)
{
  /* Implements RamTst116 */
  /* Implements SWS_BSW_00045 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                           RAMTST_GET_EXECUTION_STATUS_SVCID, RAMTST_E_UNINIT);
  }
  else
  #endif
  {
    /* do nothing */
  }
  /* Implements RamTst019 */
  /* Implements SWS_RamTst_00019 */
  return RamTst_ExecutionStatus;
} /* End of RamTst_GetExecutionStatus() */
#endif /* End of RAMTST_GET_EXECUTION_STATUS_API == STD_ON */

#if (RAMTST_GET_TEST_RESULT_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_GetTestResult
**
** Service ID            : 0x05
**
** Description           : This API is to change the state of Core Test module
**                         to Abort.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : RamTst_TestResultType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
*                          RamTst_OverallTestResult
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst103 */
/* Implements SWS_RamTst_00103 */
/* Implements SWS_BSW_00148 */
/* Implements RAMTST_ESDD_UD_060 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst125_Conf */
/* Implements RAMTST_ESDD_UD_133 */
/* Implements ECUC_RamTst_00125 */
FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResult (void)
{
  /* Variable for return current Ram Test result */
  VAR(RamTst_TestResultType, AUTOMATIC) TestResult;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  TestResult = RAMTST_RESULT_NOT_TESTED;
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                RAMTST_GET_TEST_RESULT_SVCID, RAMTST_E_UNINIT);
  }
  else
  #endif
  {
    TestResult = RamTst_OverallTestResult;
  }
  /* Implements RamTst024 */
  /* Implements SWS_RamTst_00024 */
  return TestResult;
} /* End of RamTst_GetTestResult () */
#endif /* End of RAMTST_GET_TEST_RESULT_API == STD_ON */

#if (RAMTST_GET_TEST_RESULT_PER_BLOCK_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_GetTestResultPerBlock
**
** Service ID            : 0x06
**
** Description           : This API return Current test result for the
**                         specified block for RamTst Driver.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : BlockID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : RamTst_TestResultType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
**                         RamTst_TestResultBuffer
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst104 */
/* Implements SWS_RamTst_00104 */
/* Implements SWS_BSW_00148 */
/* Implements RAMTST_ESDD_UD_061 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst126_Conf */
/* QAC Warning: START Msg(2:3227)-5 */
/* Implements RAMTST_ESDD_UD_134 */
/* Implements ECUC_RamTst_00126 */
FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResultPerBlock
                             (VAR(RamTst_NumberOfBlocksType, AUTOMATIC) BlockID)
/* END Msg(2:3227)-5 */
{
  VAR(RamTst_TestResultType, AUTOMATIC) TestResult;
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Variable used to control execution */
  VAR(Std_ReturnType, AUTOMATIC) LblStatusValue;
  LblStatusValue = E_OK;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Initialize the Value */
  TestResult = RAMTST_RESULT_NOT_TESTED;
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                      RAMTST_GET_TEST_RESULT_PER_BLOCK_SVCID, RAMTST_E_UNINIT);

    LblStatusValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }
  /* Implements RamTst039 */
  /* Implements SWS_RamTst_00039 */
  /* Implements SWS_BSW_00049 */
  /* Check if the parameter "BlockID" is out of range */
  if ((BlockID > ((RamTst_NumberOfBlocksType)RAMTST_MAX_BLOCK))
                                                    || (RAMTST_ZERO == BlockID))
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    /* Implements RAMTST_ESDD_UD_154 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                RAMTST_GET_TEST_RESULT_PER_BLOCK_SVCID, RAMTST_E_OUT_OF_RANGE);

    TestResult = RAMTST_RESULT_UNDEFINED;
    LblStatusValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }

  if (E_OK == LblStatusValue)
  #endif
  {
    TestResult = (RamTst_TestResultBuffer[BlockID - RAMTST_ONE]);
  }
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do nothing */
  }
  #endif
  /* Implements RamTst038 */
  /* Implements SWS_RamTst_00038 */
  return(TestResult);
} /* End of RamTst_GetTestResultPerBlock () */
#endif /* End of RAMTST_GET_TEST_RESULT_PER_BLOCK_API == STD_ON */

#if (RAMTST_GET_ALG_PARAMS_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_GetAlgParams
**
** Service ID            : 0x12
**
** Description           : This API return the ID of the current RAM Test
**                         algorithm parameter set for RamTst Driver.
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
** Return parameter      : RamTst_AlgParamsIdType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst193 */
/* Implements SWS_RamTst_00193 */
/* Implements SWS_BSW_00148 */
/* Implements RAMTST_ESDD_UD_063 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RAMTST_ESDD_UD_129 */
/* Implements RamTst183_Conf */
/* Implements ECUC_RamTst_00183 */
FUNC(RamTst_AlgParamsIdType, RAMTST_CODE) RamTst_GetAlgParams (void)
{
  /* Variable for algorithm parameter id */
  VAR(RamTst_AlgParamsIdType, AUTOMATIC) AlgParamsId;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the value */
  AlgParamsId = RAMTST_ZERO;
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
            RAMTST_GET_ALGORITHM_PARAMS_SVCID, RAMTST_E_UNINIT);
  }
  else
  #endif
  {
    AlgParamsId =  RamTst_AlgParamsId;
  }
  /* Implements RamTst194 */
  /* Implements SWS_RamTst_00194 */
  return AlgParamsId;
} /* End of RamTst_GetAlgParams() */
#endif /* End of RAMTST_GET_ALG_PARAMS_API == STD_ON */

#if (RAMTST_GET_TEST_ALGORITHM_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_GetTestAlgorithm
**
** Service ID            : 0x07
**
** Description           : This API return the current RAM Test algorithm.
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
** Return parameter      : RamTst_AlgorithmType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
**                         RamTst_Algorithm
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst106 */
/* Implements SWS_RamTst_00106 */
/* Implements SWS_BSW_00148 */
/* Implements RAMTST_ESDD_UD_064 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst124_Conf */
/* Implements RAMTST_ESDD_UD_132 */
/* Implements ECUC_RamTst_00124 */
FUNC(RamTst_AlgorithmType, RAMTST_CODE) RamTst_GetTestAlgorithm (void)
{
  /* Variable for return the current RAM Test algorithm */
  VAR(RamTst_AlgorithmType, AUTOMATIC) Algorithm;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the value */
  Algorithm = RAMTST_ALGORITHM_UNDEFINED;
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                             RAMTST_GET_TEST_ALGORITHM_SVCID, RAMTST_E_UNINIT);
  }
  else
  #endif
  {
    Algorithm = RamTst_Algorithm;
  }
  /* Implements RamTst021 */
  /* Implements SWS_RamTst_00021 */
  return Algorithm;
} /* End of RamTst_GetTestAlgorithm() */
#endif /* End of RAMTST_GET_TEST_ALGORITHM_API == STD_ON */

#if (RAMTST_GET_NUMBER_OF_TESTED_CELLS_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_GetNumberOfTestedCells
**
** Service ID            : 0x09
**
** Description           : This API return the current number of tested cells
**                         per main-function cycle.
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
** Return parameter      : RamTst_NumberOfTestedCellsType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
**                         RamTst_NumTestedCell
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst108 */
/* Implements SWS_RamTst_00108 */
/* Implements SWS_BSW_00148 */
/* Implements RAMTST_ESDD_UD_065 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RAMTST_ESDD_UD_131 */
/* Implements RamTst123_Conf */
/* Implements ECUC_RamTst_00123 */
FUNC(RamTst_NumberOfTestedCellsType, RAMTST_CODE) RamTst_GetNumberOfTestedCells
                                                                          (void)
{
  /* Variable for return the current number of tested cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the Value */
  TestedCells = RAMTST_ZERO;
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                     RAMTST_GET_NUMBER_OF_TESTED_CELLS_SVCID, RAMTST_E_UNINIT);
  }
  else
  #endif
  {
    /* Implements RamTst034 */
    /* Implements SWS_RamTst_00034 */
    TestedCells = RamTst_NumTestedCell;
  }
  return TestedCells;
} /* End of RamTst_GetNumberOfTestedCells() */
#endif /* End of RAMTST_GET_NUMBER_OF_TESTED_CELLS_API == STD_ON */

#if (RAMTST_SELECT_ALG_PARAMS_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_SelectAlgParams
**
** Service ID            : 0x0b
**
** Description           : This API used to set the test algorithm and
**                         its parameter set.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : NewAlgParamsId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
**                         RamTst_NumberOf_AlgParamSets,
**                         RamTst_MaxNumTestedCell,
**                         RamTst_Algorithm,
**                         RamTst_NumBlock,
**                         RamTst_Block,
**                         RamTst_TestResultBuffer,
**                         RamTst_OverallTestResult
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst105 */
/* Implements SWS_RamTst_00105 */
/* Implements SWS_BSW_00148 */
/* Implements RAMTST_ESDD_UD_066 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst182_Conf */
/* Implements RAMTST_ESDD_UD_139 */
/* Implements ECUC_RamTst_00182 */
/* QAC Warning: START Msg(2:3227)-5 */
FUNC(void, RAMTST_CODE) RamTst_SelectAlgParams
                          (VAR(RamTst_AlgParamsIdType, AUTOMATIC)NewAlgParamsId)
/* END Msg(2:3227)-5 */
{
  /* Pointer to the Algorithm Configuration Structure for the RAM Test */
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Index to the RamTst_TestResultBuffer */
  VAR(RamTst_NumberOfBlocksType, AUTOMATIC) Index;
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  VAR(Std_ReturnType, AUTOMATIC) LblStatusValue;
  LblStatusValue = E_OK;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized */
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                        RAMTST_SELECT_ALGORITHM_PARAMS_SVCID, RAMTST_E_UNINIT);

    LblStatusValue = E_NOT_OK;
  }
  /* Implements RamTst097 */
  /* Implements SWS_RamTst_00097 */
  else if (RAMTST_EXECUTION_STOPPED != RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                RAMTST_SELECT_ALGORITHM_PARAMS_SVCID, RAMTST_E_STATUS_FAILURE);

    LblStatusValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }
  /* Implements RamTst084 */
  /* Implements SWS_RamTst_00084 */
  /* Implements SWS_BSW_00049 */
  if ((RAMTST_ZERO == NewAlgParamsId) ||
                               (NewAlgParamsId > RamTst_NumberOf_AlgParamSets ))
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    /* Implements RAMTST_ESDD_UD_154 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                  RAMTST_SELECT_ALGORITHM_PARAMS_SVCID, RAMTST_E_OUT_OF_RANGE);

    LblStatusValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }

  if (E_OK == LblStatusValue)
  #else
  if (RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
  #endif
  {
    /* Implements RamTst085 */
    /* Implements SWS_RamTst_00085 */
    RamTst_AlgParamsId = NewAlgParamsId;
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
    /* END Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2814)-3 */
    RamTst_NumTestedCell = RamTstAlgPtr->RamTstNumberOfTestedCells;
    /* END Msg(2:2814)-3 */
    /* Implements RamTst121_Conf */
    #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
    /* Load Max tested cell value to RamTst_MaxNumTestedCells */
    RamTst_MaxNumTestedCell = RamTstAlgPtr->RamTstMaxNumberOfTestedCells;
    /* Load Ext tested cell value to RamTst_ExtNumTestedCells */
    RamTst_ExtNumTestedCell = RamTstAlgPtr->RamTstExtNumberOfTestedCells;
    #endif
    /* Implements RamTst083 */
    /* Implements SWS_RamTst_00083 */
    RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
    RamTst_NumBlock = RamTstAlgPtr->RamTstNumberOfBlocks;
    RamTst_Block = RAMTST_ZERO;
    /* MISRA Violation: START Msg(4:0306)-4 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_CellAddress = (RamTst_TestDataType *)
      (RamTstAlgPtr->RamTst_BlockConfig[ RamTst_Block].RamTstStartAddress);
    /* END Msg(4:0491)-1 */
    /* END Msg(4:0306)-4 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_FillPattern =
      (uint32)RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstFillPattern;
    /* END Msg(4:0491)-1 */
    /* Implements RamTst094 */
    /* Implements SWS_RamTst_00094 */
    /* Initialize the test results of configured blocks of the RAM Test*/
    for (Index = RAMTST_ZERO;Index <
                            (RamTst_NumberOfBlocksType)RAMTST_MAX_BLOCK;Index++)
    {
      /* Implements RamTst207 */
      /* Implements SWS_RamTst_00207 */
      /* Implements RAMTST_ESDD_UD_115 */
      RamTst_TestResultBuffer[Index] = RAMTST_RESULT_NOT_TESTED;
    }
    /* Initialize the over all test result  */
    /* Implements RamTst202 */
    /* Implements SWS_RamTst_00202 */
    RamTst_OverallTestResult = RAMTST_RESULT_NOT_TESTED;
  }
  else
  {
    /* Do nothing */
  }
} /* End of RamTst_SelectAlgParams  () */
#endif /* End of RAMTST_SELECT_ALG_PARAMS_API == STD_ON */

#if (RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_ChangeNumberOfTestedCells
**
** Service ID            : 0x08
**
** Description           : This API used to changes the current number
**                         of tested cells.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : NewNumberOfTestedCells
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
**                         RamTst_MaxNumTestedCell,
**                         RamTst_ExtNumTestedCell,
**                         RamTst_MinNumberOf_TestedCells,
**                         RamTst_NumTestedCell,
**                         RamTst_ExecutionStatus
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst036 */
/* Implements SWS_RamTst_00036 */
/* Implements RamTst107 */
/* Implements SWS_RamTst_00107 */
/* Implements SWS_BSW_00148 */
/* Implements RAMTST_ESDD_UD_067 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst118_Conf */
/* Implements RAMTST_ESDD_UD_126 */
/* Implements ECUC_RamTst_00118 */
/* QAC Warning: START Msg(2:3227)-5 */
FUNC(void, RAMTST_CODE) RamTst_ChangeNumberOfTestedCells
          (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC)NewNumberOfTestedCells)
/* END Msg(2:3227)-5 */
{
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Variable used to control execution */
  VAR(Std_ReturnType, AUTOMATIC) LblStatusValue;
  LblStatusValue = E_OK;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized*/
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                  RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_SVCID, RAMTST_E_UNINIT);

    LblStatusValue = E_NOT_OK;
  }
  /* Implements RamTst095 */
  /* Implements SWS_RamTst_00095 */
  /* Check if the "RamTst_ExecutionStatus" is relevant*/
  else if (RAMTST_EXECUTION_STOPPED != RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
          RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_SVCID, RAMTST_E_STATUS_FAILURE);

    LblStatusValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }
  /* Implements RamTst040 */
  /* Implements SWS_RamTst_00040 */
  /* Implements SWS_BSW_00049 */
  /* Check if the parameter "NewNumberOfTestedCells" is out of range */
  if ((NewNumberOfTestedCells > RamTst_MaxNumTestedCell) ||
      (NewNumberOfTestedCells > RamTst_ExtNumTestedCell) ||
      (NewNumberOfTestedCells < RamTst_MinNumberOf_TestedCells))
  {
    /* Report DET Error */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
            RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_SVCID, RAMTST_E_OUT_OF_RANGE);

    LblStatusValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }

  if (E_OK == LblStatusValue)
  #else
  if (RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
  #endif
  {
    RamTst_NumTestedCell = NewNumberOfTestedCells;
  }
  else
  {
    /* Do nothing */
  }
} /* End of RamTst_ChangeNumberOfTestedCells  () */
#endif /* End of RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API == STD_ON */

#if (RAMTST_RUN_FULL_TEST_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_RunFullTest
**
** Service ID            : 0x10
**
** Description           : This API used for executing the full RAM Test in the
**                         foreground.
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
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
**                         RamTst_Algorithm,
**                         RamTst_NumberOfTestedCellsType,
**                         RamTst_CellAddress,
**                         RamTst_TestResultBuffer
**
** Function(s) invoked   : Det_ReportError, Dem_ReportError
**                         RamTst_ChangeBlock_ForeGrndTest
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst195, SWS_RamTst_01005, SWS_RamTst_01006 */
/* Implements SWS_RamTst_00195, SWS_RamTst_01007 */
/* Implements RamTst002 */
/* Implements SWS_RamTst_00002 */
/* Implements SWS_RamTst_00203 */
/* Implements RamTst206 */
/* Implements SWS_RamTst_00206 */
/* Implements SWS_BSW_00148 */
/* Implements EAAR_PN0081_FR_0004 */
/* Implements RAMTST_ESDD_UD_068 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst184_Conf */
/* Implements RAMTST_ESDD_UD_137 */
/* Implements ECUC_RamTst_00184 */
FUNC(void, RAMTST_CODE) RamTst_RunFullTest (void)
{
  /* Pointer to the Algorithm Configuration Structure for the RAM Test */
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Variable to store the Result of RAM Test in each cycle*/
  VAR(Std_ReturnType, AUTOMATIC) Result;
  /* Number of tested RAM cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) NumTestCell;
  VAR(Std_ReturnType, AUTOMATIC) Ret;

  Ret = E_NOT_OK;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized*/
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                  RAMTST_RUN_FULL_TEST_SVCID, RAMTST_E_UNINIT);
  }
  /* Implements RamTst210 */
  /* Implements SWS_RamTst_00210 */
  /* Check if the "RamTst_ExecutionStatus" is relevant*/
  else if (RAMTST_EXECUTION_STOPPED != RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                          RAMTST_RUN_FULL_TEST_SVCID, RAMTST_E_STATUS_FAILURE);
  }
  else
  #else
  if (RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
  #endif
  /* Implements RamTst211 */
  /* Implements SWS_RamTst_00211 */
  /* Implements RamTst196 */
  /* Implements SWS_RamTst_00196 */
  {
    RamTst_ExecutionStatus = RAMTST_EXECUTION_RUNNING;

    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
    /* END Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2814)-3 */
    RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
    /* END Msg(2:2814)-3 */
    /* Implements RamTst212 */
    /* Implements SWS_RamTst_00212 */
    while (E_NOT_OK == Ret)
    {
      /* QAC Warning: START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0306)-4 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      NumTestCell = (RamTst_NumberOfTestedCellsType)
        (((RamTst_TestDataType *)RamTstAlgPtr->RamTst_BlockConfig
        [RamTst_Block].RamTstEndAddress) - RamTst_CellAddress) +
        (RamTst_NumberOfTestedCellsType)RAMTST_ONE;
      /* END Msg(4:0491)-1 */
      /* END Msg(4:0306)-4 */
      /* END Msg(4:0488)-2 */
      /* END Msg(2:2824)-4 */
      /* Set the Test Status of the Block */
      /* MISRA Violation: START Msg(4:0491)-1 */
      RamTst_TestResultBuffer
        [(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstBlockId)
                                        - RAMTST_ONE] = RAMTST_RESULT_UNDEFINED;
      /* END Msg(4:0491)-1 */
      /* Implements RamTst202 */
      /* Implements SWS_RamTst_00202 */
      RamTst_OverallTestResult = RAMTST_RESULT_UNDEFINED;
      /*Function for Calling Different Algorithm */
      Result = RamTst_CallAlgorithm(NumTestCell);
      if (E_NOT_OK == Result)
      {
        /* Implements SWS_RamTst_01006 */
        /* Set the Test Status of the Block */
        /* MISRA Violation: START Msg(4:0491)-1 */
        RamTst_TestResultBuffer
        [(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstBlockId)
                                           - RAMTST_ONE] = RAMTST_RESULT_NOT_OK;
        /* END Msg(4:0491)-1 */
        #if (RAMTST_AR_VERSION == RAMTST_AR_LOWER_VERSION)
        /* Implements RamTst011 */
        /* Implements SWS_RamTst_00011 */
        /* Implements RamTst071 */
        /* Implements SWS_RamTst_00071 */
        /* Implements RamTst213 */
        /* Implements SWS_RamTst_00213 */
        /* Implements SWS_BSW_00046 */
        /* Implements SWS_BSW_00066 */
        /* Implements SWS_RamTst_00111 */
        /* Implements RamTst111 */
        /* Implements RamTst188_Conf */
        /* Implements ECUC_RamTst_00150 */
        /* Implements ECUC_RamTst_00188 */
        /* Implements ECUC_RamTst_00189 */
        /* Report production error RAMTST_E_RAM_FAILURE */
        Dem_ReportErrorStatus (RAMTST_E_RAM_FAILURE, DEM_EVENT_STATUS_FAILED);
        #else
        /* Implements SWS_RamTst_01005 */
        /* Implements SWS_BSW_00205 */
        /* Implements SWS_BSW_00046 */
        /* Implements SWS_BSW_00066 */
        /* Report production error RAMTST_RUNFL_RAM_FAILURE */
        Dem_ReportErrorStatus (RAMTST_RUNFL_RAM_FAILURE,
          DEM_EVENT_STATUS_FAILED);
        #endif
        /* MISRA Violation: START Msg(4:0306)-4 */
        /* MISRA Violation: START Msg(4:0491)-1 */
        RamTst_CellAddress = (RamTst_TestDataType *)
          (RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstEndAddress +
          (uint32)RAMTST_ONE);
        /* END Msg(4:0491)-1 */
        /* END Msg(4:0306)-4 */
      }
      else
      {
        /* MISRA Violation: START Msg(4:0488)-2 */
        RamTst_CellAddress = RamTst_CellAddress + NumTestCell;
        /* END Msg(4:0488)-2 */

        /* Set TestResult Status for the Tested Block  */
        /* MISRA Violation: START Msg(4:0306)-4 */
        /* MISRA Violation: START Msg(4:0491)-1 */
        if (((uint32)RamTst_CellAddress) >
             RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstEndAddress)
        {
          /* Set the Test Status of the Block */
          RamTst_TestResultBuffer
            [(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstBlockId)
                                              - RAMTST_ONE] = RAMTST_RESULT_OK;
          /* END Msg(4:0491)-1 */
          /* END Msg(4:0306)-4 */
        }
        else
        {
          /* do nothing */
        }
      }
      /* MISRA Violation: START Msg(4:0306)-4 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      if (((uint32)RamTst_CellAddress) >
               RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstEndAddress)
      /* END Msg(4:0491)-1 */
      /* END Msg(4:0306)-4 */
      {
        Ret = RamTst_ChangeBlock_ForeGrndTest();
      }
      else
      {
        /* do nothing */
      }
    }
    RamTst_ExecutionStatus = RAMTST_EXECUTION_STOPPED;
  }
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_OFF)
  else
  {
    /* Do nothing */
  }
  #endif
} /* End of RamTst_RunFullTest() */
#endif /* End of RAMTST_RUN_FULL_TEST_API == STD_ON */

#if (RAMTST_RUN_PARTIAL_TEST_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_RunPartialTest
**
** Service ID            : 0x11
**
** Description           : This API used for testing one RAM block
**                         in the foreground.
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
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
**                         RamTst_CellAddress,
**                         RamTst_NumberOfTestedCellsType,
**                         RamTst_TestResultBuffer,
**                         RamTst_OverallTestResult
**
** Function(s) invoked   : Det_ReportError, Dem_ReportError
**                         RamTst_CallAlgorithm
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst197, SWS_RamTst_01008 */
/* Implements SWS_RamTst_00197, SWS_RamTst_01009 */
/* Implements RamTst002, SWS_RamTst_01010 */
/* Implements SWS_RamTst_00002 */
/* Implements RamTst206 */
/* Implements SWS_RamTst_00206 */
/* Implements SWS_BSW_00148 */
/* Implements EAAR_PN0081_FR_0004 */
/* Implements RAMTST_ESDD_UD_069 */
/* Implements EAAR_PN0081_FR_0005 */
/* Implements EAAR_PN0081_FR_0006 */
/* Implements RamTst185_Conf */
/* Implements RAMTST_ESDD_UD_138 */
/* Implements ECUC_RamTst_00185 */
FUNC(void, RAMTST_CODE) RamTst_RunPartialTest
                              (VAR(RamTst_NumberOfBlocksType, AUTOMATIC)BlockId)
{
  /* Temporary variable to hold state of execution status */
  VAR(RamTst_ExecutionStatusType, AUTOMATIC)RamTst_TempExecutionStatus;
  /* Pointer to the Algorithm Configuration Structure for the RAM Test */
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Number of tested RAM cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) NumTestCell;
  /* Variable to store the Result of RAM Test in each cycle*/
  VAR(Std_ReturnType, AUTOMATIC) Result;
  /* Index used for finding block ID */
  VAR(uint16, AUTOMATIC) Index;
  /* Indicate that block ID is found */
  VAR(boolean, AUTOMATIC) BlockIdFound;
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Variable used to control execution */
  VAR(Std_ReturnType, AUTOMATIC) LblStatusValue;
  LblStatusValue = E_OK;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized*/
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                               RAMTST_RUN_PARTIAL_TEST_SVCID, RAMTST_E_UNINIT);

    LblStatusValue = E_NOT_OK;
  }
  /* Implements RamTst198 */
  /* Implements SWS_RamTst_00198 */
  /* Implements RamTst214 */
  /* Implements SWS_RamTst_00214 */
  else if (RAMTST_EXECUTION_RUNNING == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                       RAMTST_RUN_PARTIAL_TEST_SVCID, RAMTST_E_STATUS_FAILURE);

    LblStatusValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }
  #endif
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                    [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst223 */
  /* Implements SWS_RamTst_00223 */
  /* Implements SWS_BSW_00049 */
  /* Check if the parameter "BlockId" is out of range */
  /* QAC Warning: START Msg(2:2814)-3 */
  if ((BlockId > RamTstAlgPtr->RamTstNumberOfBlocks) ||
                                                       (RAMTST_ZERO == BlockId))
  /* END Msg(2:2814)-3 */
  {
    /* Report DET Error */
    /* Implements RamTst112 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                         RAMTST_RUN_PARTIAL_TEST_SVCID, RAMTST_E_OUT_OF_RANGE);

    LblStatusValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }

  if (E_OK == LblStatusValue)
  #else
  if ((RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus) ||
    (RAMTST_EXECUTION_SUSPENDED == RamTst_ExecutionStatus))
  #endif
  {
    /* Implements RamTst215 */
    /* Implements SWS_RamTst_00215 */
    RamTst_TempExecutionStatus = RamTst_ExecutionStatus;
    RamTst_ExecutionStatus = RAMTST_EXECUTION_RUNNING;
    BlockIdFound = FALSE;
    /* QAC Warning: START Msg(2:2814)-3 */
    for (Index = RAMTST_ZERO;
      (Index < RamTstAlgPtr->RamTstNumberOfBlocks) && (BlockIdFound == FALSE);
      Index++)
    /* END Msg(2:2814)-3 */
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      if (RamTstAlgPtr->RamTst_BlockConfig[Index].RamTstBlockId == BlockId)
      /* END Msg(4:0491)-1 */
      {
        BlockId = Index;
        RamTst_Block = BlockId;
        /* MISRA Violation: START Msg(4:0491)-1 */
        RamTst_FillPattern =
        (uint32)RamTstAlgPtr->RamTst_BlockConfig[BlockId].RamTstFillPattern;
        /* END Msg(4:0491)-1 */
        BlockIdFound = TRUE;
      }
      else
      {
        /* do nothing */
      }
    }
    if (TRUE == BlockIdFound)
    {
      /* MISRA Violation: START Msg(4:0306)-4 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      RamTst_CellAddress = (RamTst_TestDataType*)
            (RamTstAlgPtr->RamTst_BlockConfig[BlockId].RamTstStartAddress);
      /* END Msg(4:0491)-1 */
      /* END Msg(4:0306)-4 */

      RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;

      /* QAC Warning: START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0306)-4 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:0491)-1 */
        NumTestCell = (RamTst_NumberOfTestedCellsType)(((RamTst_TestDataType *)
          RamTstAlgPtr->RamTst_BlockConfig[BlockId].RamTstEndAddress) -
          RamTst_CellAddress) + (RamTst_NumberOfTestedCellsType)RAMTST_ONE;
      /* END Msg(4:0491)-1 */
      /* END Msg(4:0488)-2 */
      /* END Msg(4:0306)-4 */
      /* END Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      RamTst_TestResultBuffer
        [(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstBlockId)
                                        - RAMTST_ONE] = RAMTST_RESULT_UNDEFINED;
      /* END Msg(4:0491)-1 */
      /* Implements RamTst202 */
      /* Implements SWS_RamTst_00202 */
      RamTst_OverallTestResult = RAMTST_RESULT_UNDEFINED;
      Result = RamTst_CallAlgorithm(NumTestCell);
      /* Implements RamTst217 */
      /* Implements SWS_RamTst_00217 */
      if (E_NOT_OK == Result)
      {
        /* Implements SWS_RamTst_01009 */
        /* Set the Test Status of the Block */
        /* MISRA Violation: START Msg(4:0491)-1 */
        RamTst_TestResultBuffer
        [(RamTstAlgPtr->RamTst_BlockConfig[BlockId].RamTstBlockId) - RAMTST_ONE]
                                                         = RAMTST_RESULT_NOT_OK;
        /* END Msg(4:0491)-1 */
        /* Implements RamTst202 */
        /* Implements SWS_RamTst_00202 */
        RamTst_OverallTestResult = RAMTST_RESULT_NOT_OK;
        #if (RAMTST_AR_VERSION == RAMTST_AR_LOWER_VERSION)
        /* Implements RamTst071, SWS_RamTst_00069 */
        /* Implements SWS_RamTst_00071 */
        /* Implements RamTst216 */
        /* Implements SWS_RamTst_00216 */
        /* Implements SWS_BSW_00046 */
        /* Implements SWS_BSW_00066 */
        /* Implements RamTst111 */
        /* Implements RamTst188_Conf */
        /* Implements ECUC_RamTst_00189 */
        /* Report production error RAMTST_E_RAM_FAILURE */
        Dem_ReportErrorStatus (RAMTST_E_RAM_FAILURE, DEM_EVENT_STATUS_FAILED);
        #else
        /* Implements SWS_RamTst_01008, SWS_RamTst_00069 */
        /* Implements SWS_BSW_00205 */
        /* Implements SWS_BSW_00046 */
        /* Implements SWS_BSW_00066 */
        /* Report production error RAMTST_PART_RAM_FAILURE */
        Dem_ReportErrorStatus (RAMTST_PART_RAM_FAILURE,
          DEM_EVENT_STATUS_FAILED);
        #endif
        /* MISRA Violation: START Msg(4:0306)-4 */
        /* MISRA Violation: START Msg(4:0491)-1 */
        RamTst_CellAddress = (RamTst_TestDataType *)
          (RamTstAlgPtr->RamTst_BlockConfig[BlockId].RamTstEndAddress +
          (uint32)RAMTST_ONE);
        /* END Msg(4:0491)-1 */
        /* END Msg(4:0306)-4 */
      }
      else
      {
        /* MISRA Violation: START Msg(4:0488)-2 */
        RamTst_CellAddress = RamTst_CellAddress + NumTestCell;
        /* END Msg(4:0488)-2 */

        /* Set TestResult Status for the Tested Block  */
        /* MISRA Violation: START Msg(4:0306)-4 */
        /* MISRA Violation: START Msg(4:0491)-1 */
        if (((uint32)RamTst_CellAddress) >
                   RamTstAlgPtr->RamTst_BlockConfig[BlockId].RamTstEndAddress)
        /* END Msg(4:0491)-1 */
        /* END Msg(4:0306)-4 */
        {
          /* Set the Test Status of the Block */
          /* MISRA Violation: START Msg(4:0491)-1 */
          RamTst_TestResultBuffer
          [(RamTstAlgPtr->RamTst_BlockConfig[BlockId].RamTstBlockId)
                                               - RAMTST_ONE] = RAMTST_RESULT_OK;
          /* END Msg(4:0491)-1 */
          /* Implements SWS_RamTst_01010 */
          RamTst_OverallTestResult = RAMTST_RESULT_OK;
        }
        else
        {
          /* do nothing */
        }
      }
      /* Implements RamTst215 */
      /* Implements SWS_RamTst_00215 */
      RamTst_ExecutionStatus = RamTst_TempExecutionStatus;
    }
    else
    {
      /* do nothing */
    }
  }
  else
  {
    /* Do nothing */
  }
} /* End of RamTst_RunPartialTest() */
#endif /* End of RAMTST_RUN_PARTIAL_TEST_API == STD_ON */
/*******************************************************************************
** Function Name         : RamTst_MainFunction
**
** Service ID            : 0x01
**
** Description           : Scheduled function for executing the RAM Test
**                         in the background.
**
** Sync/Async            : -
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
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_ExecutionStatus,
**                         RamTst_AlgParamsId,
**                         RamTst_Algorithm,
**                         RamTst_NumberOfTestedCellsType,
**                         RamTst_CellAddress,
**                         RamTst_NumTestedCell,
**                         RamTst_TestResultBuffer
**
** Function(s) invoked   : Det_ReportError, Dem_ReportError
**                         RamTst_ChangeBlock_BackGrndTest
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst110 */
/* Implements SWS_RamTst_00110 */
/* Implements RamTst002 */
/* Implements SWS_RamTst_00002 */
/* Implements RamTst005 */
/* Implements SWS_RamTst_00005 */
/* Implements RAMTST_ESDD_UD_070 */
/* Implements SWS_BSW_00148 */
/* Implements SWS_BSW_00153 */
/* Implements SWS_BSW_00154 */
/* Implements SWS_BSW_00156 */
FUNC(void, RAMTST_CODE) RamTst_MainFunction (void)
{
  /* Pointer to the Algorithm Configuration Structure for the RAM Test */
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Variable to store the Result of RAM Test in each cycle */
  VAR(Std_ReturnType, AUTOMATIC) Result;
  /* Number of tested RAM cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) NumTestCell;
  /* Implements RamTst068 */
  /* Implements SWS_BSW_00202 */
  /* Implements RamTst115 */
  /* Implements SWS_BSW_00203 */
  /* Implements SWS_BSW_00042 */
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* Implements RamTst089 */
  /* Implements SWS_RamTst_00089 */
  /* Implements RAMTST_ESDD_UD_114 */
  /* Check if the Module is initialized*/
  if (RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
  {
    /* Report DET Error */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                                  RAMTST_MAIN_FUNCTION_SVCID, RAMTST_E_UNINIT);
  }
  else
  {
    /* do nothing */
  }
  #endif
  /* Implements RamTst009 */
  /* Implements SWS_RamTst_00009 */
  /* Implements RamTst148 */
  /* Implements SWS_RamTst_00148 */
  /* Implements RamTst175 */
  /* Implements SWS_RamTst_00175 */
  /* Implements RamTst008 */
  /* Implements SWS_RamTst_00008 */
  if (RAMTST_EXECUTION_RUNNING == RamTst_ExecutionStatus)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                            [RamTst_AlgParamsId - RAMTST_ONE]);
    /* END Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2814)-3 */
    RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
    /* END Msg(2:2814)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0306)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Implements RamTst059 */
    /* Implements SWS_RamTst_00059 */
    if (((RamTst_NumberOfTestedCellsType)(((RamTst_TestDataType *)
          (RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstEndAddress)) -
                                   RamTst_CellAddress)) < RamTst_NumTestedCell)
    {
      NumTestCell = (RamTst_NumberOfTestedCellsType)((RamTst_TestDataType *)
        (RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstEndAddress) -
        RamTst_CellAddress) + (RamTst_NumberOfTestedCellsType)RAMTST_ONE;
    }
    /* END Msg(4:0491)-1 */
    /* END Msg(4:0488)-2 */
    /* END Msg(4:0306)-4 */
    /* END Msg(2:2824)-4 */
    else
    {
      NumTestCell = RamTst_NumTestedCell;
    }
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_TestResultBuffer
        [(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstBlockId)
                                        - RAMTST_ONE] = RAMTST_RESULT_UNDEFINED;
    /* END Msg(4:0491)-1 */
    /* Implements RamTst202 */
    /* Implements SWS_RamTst_00202 */
    RamTst_OverallTestResult = RAMTST_RESULT_UNDEFINED;
    Result = RamTst_CallAlgorithm(NumTestCell);
    if (E_NOT_OK == Result)
    {
      /* Implements SWS_RamTst_01003 */
      /* Set the Test Status of the Block */
      /* MISRA Violation: START Msg(4:0491)-1 */
      RamTst_TestResultBuffer[(RamTstAlgPtr->RamTst_BlockConfig
            [RamTst_Block].RamTstBlockId) - RAMTST_ONE] = RAMTST_RESULT_NOT_OK;
      /* END Msg(4:0491)-1 */
      #if (RAMTST_AR_VERSION == RAMTST_AR_LOWER_VERSION)
      /* Implements RamTst071 */
      /* Implements SWS_RamTst_00071, SWS_RamTst_00069 */
      /* Implements SWS_BSW_00046 */
      /* Implements SWS_BSW_00066 */
      /* Implements RamTst111 */
      /* Implements RamTst188_Conf */
      /* Report production error RAMTST_E_RAM_FAILURE */
      Dem_ReportErrorStatus (RAMTST_E_RAM_FAILURE, DEM_EVENT_STATUS_FAILED);
      #else
      /* Implements SWS_RamTst_01002, SWS_RamTst_00069 */
      /* Implements SWS_BSW_00205 */
      /* Implements SWS_BSW_00046 */
      /* Implements SWS_BSW_00066 */
      /* Implements RamTst111 */
      /* Implements RamTst188_Conf */
      /* Report production error RAMTST_MAIN_RAM_FAILURE */
      Dem_ReportErrorStatus (RAMTST_MAIN_RAM_FAILURE, DEM_EVENT_STATUS_FAILED);
      #endif
      /* Implements RamTst044, SWS_RamTst_00114 */
      /* Implements SWS_RamTst_00044, ECUC_RamTst_00139 */
      if (NULL_PTR != RamTst_59_93_Config[RAMTST_ZERO].RamTstErrorNotification)
      {
        /* Implements RamTst043, SWS_RamTst_00114 */
        /* Implements SWS_RamTst_00043, ECUC_RamTst_00139 */
        RamTst_59_93_Config[RAMTST_ZERO].RamTstErrorNotification();
      }
      else
      {
        /* do nothing */
      }
      /* MISRA Violation: START Msg(4:0306)-4 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      RamTst_CellAddress = (RamTst_TestDataType *)
          (RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstEndAddress +
          (uint32)RAMTST_ONE);
      /* END Msg(4:0491)-1 */
      /* END Msg(4:0306)-4 */
    }
    else
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      RamTst_CellAddress = RamTst_CellAddress + NumTestCell;
      /* END Msg(4:0488)-2 */

      /* MISRA Violation: START Msg(4:0306)-4 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Implements RamTst010 */
      /* Implements SWS_RamTst_00010 */
      /* Set TestResult Status for the Tested Block  */
      if (((uint32)RamTst_CellAddress) >
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstEndAddress)
      /* END Msg(4:0491)-1 */
      /* END Msg(4:0306)-4 */
      {
        /* MISRA Violation: START Msg(4:0491)-1 */
        /* Set the Test Status of the Block */
        RamTst_TestResultBuffer
          [(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstBlockId) -
                                                RAMTST_ONE] = RAMTST_RESULT_OK;
        /* END Msg(4:0491)-1 */
      }
      else
      {
        /* do nothing */
      }
    }
    /* MISRA Violation: START Msg(4:0306)-4 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (((uint32)RamTst_CellAddress) >
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstEndAddress)
    /* END Msg(4:0491)-1 */
    /* END Msg(4:0306)-4 */
    {
      RamTst_ChangeBlock_BackGrndTest();
    }
    else
    {
      /* Do nothing */
    }
  }
  else
  {
    /* Do nothing */
  }
} /* End of RamTst_MainFunction () */

#if (STD_ON == RAMTST_CHECKERBOARD_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_Checker_Algorithm
**
** Service ID            : NA
**
** Description           : Function for RAM testing using the CheckerBoard
**                         Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType  TestedCellNumber
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_Algorithm,
**                         RamTst_CellAddress
**
** Function(s) invoked   : RamTst_SaveData,
**                         RamTst_FillData
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst050 */
/* Implements RAMTST_ESDD_UD_071 */
/* Implements SWS_RamTst_00050, SWS_RamTst_00062 */
/* Implements SWS_RamTst_00224 */
/* Implements RAMTST_ESDD_UD_144 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_Checker_Algorithm
               (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber)
/* END Msg(2:3227)-5 */
{
  /* Value to check the cell*/
  VAR(RamTst_TestDataType, AUTOMATIC) value;
  /* Variable for check the Index */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Index;
  /* Testrun needed for the algorithm */
  VAR(uint8, AUTOMATIC) TestRun;
  /* Return value */
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress;
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Initialize the Return value */
  ReturnVal = E_OK;
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */
  /* Load RamTst_CellAddress to CellAddress */
  CellAddress = RamTst_CellAddress;
  /* Load RAMTST_CHECKERVALUE to value */
  value = (RamTst_TestDataType)RAMTST_CHECKERVALUE;

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_ENTER_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif
  /* Implements RamTst060, SWS_RamTst_00061 */
  /* Implements SWS_RamTst_00060, SWS_RamTst_00002 */
  /* Implements RAMTST_ESDD_UD_124 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  if (RAMTST_NON_DESTRUCTIVE ==
              RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_SaveData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber);
    /* END Msg(4:0491)-1 */
  }
  else
  {
    /* do nothing */
  }
  #endif

  /* write 0 and 1 in consecutive locations */
  for (TestRun = RAMTST_ZERO;(TestRun < RAMTST_TWO) && (E_OK == ReturnVal);
                                                                      TestRun++)
  {
    /* write 0 and 1 in consecutive locations */
    for (Index = RAMTST_ZERO;Index < TestedCellNumber;Index++)
    {
      /* QAC Warning: START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      *(CellAddress + Index) = value;
      /* END Msg(4:0488)-2 */
      /* END Msg(2:2824)-4 */
      value = ~value;
    }
    /* Check whether the number of tested cell is odd or even */
    if (RAMTST_ZERO != (((uint8)(TestedCellNumber)) & (uint8)RAMTST_ONE))
    {
      value = ~value;
    }
    else
    {
      /* do nothing */
    }
    /* Read 0 and 1 in consecutive locations */
    for (Index = RAMTST_ZERO;(Index < TestedCellNumber) && (E_OK == ReturnVal);
                                                                        Index++)
    {
      /* Check whether the data are correct */
      /* MISRA Violation: START Msg(4:0488)-2 */
      if (*(CellAddress + Index) != value)
      /* END Msg(4:0488)-2 */
      {
        /* Returning E_NOT_OK */
        ReturnVal = E_NOT_OK;
      }
      else
      {
        /* do nothing */
      }
      value = ~value;
    }
    value = (RamTst_TestDataType)~RAMTST_CHECKERVALUE;
  }
  /* Implements RamTst060 */
  /* Implements SWS_RamTst_00060 */
  /* Implements RamTst200 */
  /* Implements SWS_RamTst_00200 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
               RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_RestoreData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber, CellAddress);
    /* END Msg(4:0491)-1 */

  }
  /* Implements RamTst201 */
  /* Implements SWS_RamTst_00201 */
  else
  {
    RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  }
  #else
  RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  #endif

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_EXIT_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif

  return ReturnVal;
} /* End of RamTst_Checker_Algorithm () */
#endif /* End of STD_ON == RAMTST_CHECKERBOARD_TEST_SELECTED */

#if (STD_ON == RAMTST_GALPAT_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_Galpat_Algorithm
**
** Service ID            : NA
**
** Description           : Function for RAM testing using the Galpat Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCellNumber
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_AlgParamsId,
**                         RamTst_Algorithm,
**                         RamTst_CellAddress
**
** Function(s) invoked   : SchM_Enter_RamTst_Area, SchM_Exit_RamTst_Area
**                         RamTst_SaveData, RamTst_InitializeCell,
**                         RamTst_FillData
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst053, SWS_RamTst_00062 */
/* Implements RAMTST_ESDD_UD_072 */
/* Implements SWS_RamTst_00053 */
/* Implements SWS_RamTst_00226 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_Galpat_Algorithm
               (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells*/
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* Cell to be tested*/
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) BaseCell;
  /* Testrun needed for the algorithm*/
  VAR(uint8, AUTOMATIC) TestRun;
  /* Bit to be tested in the cell*/
  VAR(uint8, AUTOMATIC) BaseBit;
  /* Total number of bits */
  VAR(uint32, AUTOMATIC) Totalbits;
  /* Bit numbering*/
  VAR(uint32, AUTOMATIC) Index;
  /* BackGroundVariable */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress;
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Initialize the Return value */
  ReturnVal = E_OK;
  /* Initialize the BackGroundVariable */
  BackGroundVariable = RAMTST_ZERO;
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */
  CellAddress = RamTst_CellAddress;

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_ENTER_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif
  /* Implements RamTst060, SWS_RamTst_00061 */
  /* Implements SWS_RamTst_00060, SWS_RamTst_00002 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_SaveData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber);
    /* END Msg(4:0491)-1 */
  }
  else
  {
    /* do nothing */
  }
  #endif
  /* Load Total number of bits */
  Totalbits = (uint32)TestedCellNumber << RAMTST_CELL_DIVIDER;
  for (TestRun = RAMTST_ZERO; (TestRun < RAMTST_TWO) && (E_OK == ReturnVal);
                                                                      TestRun++)
  {
    /* Initialize the tested cells with BackGroundVariable  */
    RamTst_InitializeCell(BackGroundVariable, TestedCellNumber, CellAddress);

    /* Select the base bit to be tested in the ascending order. (LSB to MSB) */
    for (Index = RAMTST_ZERO;(Index < Totalbits) && (E_OK == ReturnVal);Index++)
    {
      /* Loading BaseCell Value */
      BaseCell = (RamTst_NumberOfTestedCellsType)(Index >> RAMTST_CELL_DIVIDER);
      /* Loading BaseBit Value */
      BaseBit = (uint8)(Index & (RAM_TEST_DATA_TYPE - RAMTST_ONE));

      /* QAC Warning: START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Invert the base bit */
      RAMTST_INVERT_BITX(*(CellAddress + BaseCell), BaseBit ,
                                                           RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
      /* END Msg(2:2824)-4 */

      /* Read and check all other bits in the tested cells (LSB to MSB) */
      for (Cellnumber = RAMTST_ZERO;(Cellnumber < TestedCellNumber) &&
                                              (E_OK == ReturnVal);Cellnumber++)
      {
        /* Read and Check the content of all other bits in each of tested cells,
         * followed by verification of the base bit each time
         */
        /* MISRA Violation: START Msg(4:0488)-2 */
        if ((Cellnumber != BaseCell) &&
                            (*(CellAddress + Cellnumber) != BackGroundVariable))
        /* END Msg(4:0488)-2 */
        {
          ReturnVal = E_NOT_OK;
        }
        else
        {
          /* do nothing */
        }
        /* MISRA Violation: START Msg(4:0488)-2 */
        if (*(CellAddress + BaseCell)  !=
                     (BackGroundVariable ^ (((uint32)(RAMTST_ONE)) << BaseBit)))
        /* END Msg(4:0488)-2 */
        {
          ReturnVal = E_NOT_OK;
        }
        else
        {
          /* do nothing */
        }
      }
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Re-invert the base bit */
      RAMTST_INVERT_BITX(*(CellAddress + BaseCell), BaseBit ,
                                                          RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
    }
    BackGroundVariable = ~BackGroundVariable;
  }
  /* Implements RamTst060 */
  /* Implements SWS_RamTst_00060 */
  /* Implements RamTst200 */
  /* Implements SWS_RamTst_00200 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_RestoreData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber, CellAddress);
    /* END Msg(4:0491)-1 */

  }
  /* Implements RamTst201 */
  /* Implements SWS_RamTst_00201 */
  else
  {
    RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  }
  #else
  RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  #endif

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_EXIT_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif

  return ReturnVal;
} /* End of Galpat_Algorithm */
#endif /*End of  STD_ON == RAMTST_GALPAT_TEST_SELECTED */

#if (STD_ON == RAMTST_WALK_PATH_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_WalkPath_Algorithm
**
** Service ID            : NA
**
** Description           : Function for RAM testing using the WalkPath
**                         Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCellNumber
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_Algorithm,
**                         RamTst_CellAddress
**
** Function(s) invoked   : SchM_Enter_RamTst_Area, SchM_Exit_RamTst_Area
**                         RamTst_SaveData, RamTst_InitializeCell,
**                         RamTst_FillData, RamTst_RestoreData
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst052 */
/* Implements RAMTST_ESDD_UD_073 */
/* Implements SWS_RamTst_00052 */
/* Implements SWS_RamTst_00225 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_WalkPath_Algorithm
               (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* Cell to be tested */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) BaseCell;
  /* Testrun needed for the algorithm */
  VAR(uint8, AUTOMATIC) TestRun;
  /* Bit to be tested in the cell */
  VAR(uint8, AUTOMATIC) BaseBit;
  /* Total number of bits */
  VAR(uint32, AUTOMATIC) Totalbits;
  /* Bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  /* Initialize the tested cells with value 0 or 1 */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress;
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Initialize the Return value */
  ReturnVal = E_OK;
  /* Initialize the BackGroundVariable */
  BackGroundVariable = RAMTST_ZERO;
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */
  CellAddress = RamTst_CellAddress;

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_ENTER_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif
  /* Implements RamTst060, SWS_RamTst_00061 */
  /* Implements SWS_RamTst_00060, SWS_RamTst_00002 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
               RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_SaveData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber);
    /* END Msg(4:0491)-1 */
  }
  else
  {
    /* do nothing */
  }
  #endif

  Totalbits = (uint32)TestedCellNumber << RAMTST_CELL_DIVIDER;
  for (TestRun = RAMTST_ZERO; (TestRun < RAMTST_TWO) && (E_OK == ReturnVal);
                                                                      TestRun++)
  {
    /* Initialize the tested cells with BackGroundVariable */
    RamTst_InitializeCell(BackGroundVariable, TestedCellNumber, CellAddress);
    /* Select the base bit to be tested in the ascending order. (LSB to MSB) */
    for (Index = RAMTST_ZERO;(Index < Totalbits) && (E_OK == ReturnVal);Index++)
    {
      BaseCell = (RamTst_NumberOfTestedCellsType)(Index >> RAMTST_CELL_DIVIDER);
      BaseBit = (uint8)(Index & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
      /* QAC Warning: START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Invert the base bit */
      RAMTST_INVERT_BITX(*(CellAddress + BaseCell),
                                                BaseBit, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
      /* END Msg(2:2824)-4 */
      /* Read and check all other bits in the tested cells (LSB to MSB) */
      for (Cellnumber = RAMTST_ZERO;(Cellnumber < TestedCellNumber) &&
                                          (E_OK == ReturnVal); Cellnumber++)
      {
        /* Check for the base cell */
        if (Cellnumber == BaseCell)
        {
          /* MISRA Violation: START Msg(4:0488)-2 */

          if (*(CellAddress + BaseCell)  !=
                     (BackGroundVariable ^ (((uint32)(RAMTST_ONE)) << BaseBit)))

          /* END Msg(4:0488)-2 */
          {
            ReturnVal = E_NOT_OK;
          }
          else
          {
            /* do nothing */
          }
        }
        /* Check the content of all other cells excluding the base cell */
        /* MISRA Violation: START Msg(4:0488)-2 */
        else if (*(CellAddress + Cellnumber) != BackGroundVariable)
        /* END Msg(4:0488)-2 */
        {
          ReturnVal = E_NOT_OK;
        }
        else
        {
          /* do nothing */
        }
      }
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Re-invert the base cell */
      RAMTST_INVERT_BITX(*(CellAddress + BaseCell), BaseBit ,
                                                          RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
    }
    BackGroundVariable = ~BackGroundVariable;
  }
  /* Implements RamTst060 */
  /* Implements SWS_RamTst_00060 */
  /* Implements RamTst200 */
  /* Implements SWS_RamTst_00200 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_RestoreData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber, CellAddress);
    /* END Msg(4:0491)-1 */

  }
  /* Implements RamTst201 */
  /* Implements SWS_RamTst_00201 */
  else
  {
    RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  }
  #else
  RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  #endif

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_EXIT_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif

  return ReturnVal;
} /* End of RamTst_WalkPath_Algorithm */
#endif /* End of STD_ON == RAMTST_WALK_PATH_TEST_SELECTED */

#if (STD_ON == RAMTST_MARCH_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_March_Algorithm
**
** Service ID            : NA
**
** Description           : Function for RAM testing using the March Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCellNumber
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_CellAddress
**
** Function(s) invoked   : SchM_Enter_RamTst_Area, SchM_Exit_RamTst_Area
**                         RamTst_SaveData, RamTst_InitializeCell,
**                         RamTst_RWAscend, RamTst_RWDescend,
**                         RamTst_FillData, RamTst_RestoreData
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst051 */
/* Implements RAMTST_ESDD_UD_074 */
/* Implements SWS_RamTst_00051 */
/* Implements SWS_RamTst_00224 */
/* Implements RAMTST_ESDD_UD_146 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_March_Algorithm
               (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber)
/* END Msg(2:3227)-5 */
{
  /* Testrun needed for the algorithm*/
  VAR(uint8, AUTOMATIC) TestRun;
  /* Total number of bits */
  VAR(uint32, AUTOMATIC) Totalbits;
  /* check for the bit*/
  VAR(uint8, AUTOMATIC) MarchCheckVariable;
  /* Initialize the tested cells with value 0 or 1 */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress;
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr ;
  /* Initialize the Return value */
  ReturnVal = E_OK;
  /* Initialize the BackGroundVariable */
  BackGroundVariable = RAMTST_ZERO;
  /* Initialize the MarchCheckVariable */
  MarchCheckVariable = RAMTST_ZERO;
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */
  CellAddress = RamTst_CellAddress;

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_ENTER_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif
  /* Implements RamTst060, SWS_RamTst_00061 */
  /* Implements SWS_RamTst_00060, SWS_RamTst_00002 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
              RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_SaveData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber);
    /* END Msg(4:0491)-1 */
  }
  else
  {
    /* do nothing */
  }
  #endif

  Totalbits = (uint32)TestedCellNumber << RAMTST_CELL_DIVIDER;
  for (TestRun = RAMTST_ZERO; (TestRun < RAMTST_TWO) && (E_OK == ReturnVal);
                                                                      TestRun++)
  {
    /* Initialize the tested cells with BackGroundVariable */
    RamTst_InitializeCell(BackGroundVariable, TestedCellNumber, CellAddress);

    /* Read, check and invert each bit in ascending order (LSB to MSB) */
    ReturnVal = RamTst_RWAscend(MarchCheckVariable, Totalbits, CellAddress);

    if (E_OK == ReturnVal)
    {
      MarchCheckVariable = MarchCheckVariable ^ RAMTST_ONE;

      /* Read, check and invert each bit in descending order (MSB to LSB) */
      ReturnVal = RamTst_RWDescend(MarchCheckVariable, Totalbits, CellAddress);
    }
    else
    {
      /* do nothing */
    }

    /* Change the Initializing value */
    BackGroundVariable = ~BackGroundVariable;
  }
  /* Implements RamTst060 */
  /* Implements SWS_RamTst_00060 */
  /* Implements RamTst200 */
  /* Implements SWS_RamTst_00200 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_RestoreData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber, CellAddress);
    /* END Msg(4:0491)-1 */

  }
  /* Implements RamTst201 */
  /* Implements SWS_RamTst_00201 */
  else
  {
    RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  }
  #else
  RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  #endif

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_EXIT_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif

  return ReturnVal;
}/* End of RamTst_March_Algorithm */
#endif /* End of STD_ON == RAMTST_MARCH_TEST_SELECTED */

/* Implements RamTst205 */
/* Implements SWS_RamTst_00205 */
/* Implements EAAR_PN0034_FR_0020, EAAR_PN0034_FR_0021 */
#if (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_MarchY_Algorithm
**
** Service ID            : NA
**
** Description           : Function for RAM testing using the March Y
**                         Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCellNumber
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : SchM_Enter_RamTst_Area, SchM_Exit_RamTst_Area
**                         RamTst_InitializeCell, RamTst_RWAscend,
**                         RamTst_RWDescend, RamTst_FillData,
**                         RamTst_ReadAscend,
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst204 */
/* Implements SWS_RamTst_00204 */
/* Implements SWS_RamTst_00224 */
/* Implements RAMTST_ESDD_UD_075 */
/* Implements EAAR_PN0081_FR_0003 */
/* Implements EAAR_PN0081_FSR_0001 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_MarchY_Algorithm
               (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber)
/* END Msg(2:3227)-5 */
{
  /* Total number of bits */
  VAR(uint32, AUTOMATIC) Totalbits;
  /* check for the bit*/
  VAR(RamTst_TestDataType, AUTOMATIC) MarchCheckVariable;
  /* Initialize the tested cells with value 0 */
  /* QAC Warning: START Msg(2:3204)-9 */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  /* END Msg(2:3204)-9 */
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress;
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Initialize the BackGroundVariable */
  BackGroundVariable = RAMTST_ZERO;
  /* Initialize the MarchCheckVariable */
  MarchCheckVariable = RAMTST_ZERO;
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */
  CellAddress = RamTst_CellAddress;

  /* Implements EAAR_PN0034_FR_0066 */
  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_ENTER_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif

  Totalbits = (uint32)TestedCellNumber << RAMTST_CELL_DIVIDER;

  /* Initialize the tested cells with zero */
  RamTst_InitializeCell(BackGroundVariable, TestedCellNumber, CellAddress);

  /* Read, check and invert each bit in ascending order (LSB to MSB) */
  ReturnVal = RamTst_RWRAscend(MarchCheckVariable, Totalbits, CellAddress);

  if (E_OK == ReturnVal)
  {
    MarchCheckVariable = RAMTST_ONE;

    /* Read, check and invert each bit in descending order (MSB to LSB) */
    ReturnVal = RamTst_RWRDescend(MarchCheckVariable, Totalbits, CellAddress);
  }
  else
  {
    /* do nothing */
  }
  if (E_OK == ReturnVal)
  {
    MarchCheckVariable = RAMTST_ZERO;
    /* Read each bit in ascending order (LSB to MSB) */
    ReturnVal =
          RamTst_ReadAscend(TestedCellNumber,
                          (RamTst_TestDataType)MarchCheckVariable, CellAddress);
  }
  else
  {
    /* do nothing */
  }

  RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);

  /* Implements EAAR_PN0034_FR_0066 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_EXIT_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif

  return ReturnVal;
}/* End of RamTst_MarchY_Algorithm */
#endif /* End of STD_ON == RAMTST_MARCH_Y_TEST_SELECTED */

#if (STD_ON == RAMTST_TRANSP_GALPAT_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_Transp_Galpat_Algorithm
**
** Service ID            : NA
**
** Description           : Function for RAM testing using the
**                         Transparent_Galpat Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCellNumber
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_Algorithm
**
** Function(s) invoked   : SchM_Enter_RamTst_Area, SchM_Exit_RamTst_Area
**                         RamTst_SaveData, RamTst_RestoreData,
**                         RamTst_FillData,
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst054 */
/* Implements SWS_RamTst_00054 */
/* Implements SWS_RamTst_00226 */
/* Implements EAAR_PN0081_FR_0004 */
/* Implements RAMTST_ESDD_UD_076 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_Transp_Galpat_Algorithm
               (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber)
/* END Msg(2:3227)-5 */

{
  /* Testrun needed for the algorithm*/
  VAR(uint8, AUTOMATIC) TestRun;
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) BaseCell;
  /* Cell Count */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Count;
  /* Bit to be tested in the cell */
  VAR(uint8, AUTOMATIC) BaseBit;
  /* Total number of bits */
  VAR(uint32, AUTOMATIC) Totalbits;
  /* Bit Index */
  VAR(uint32, AUTOMATIC) Index;
  /* CRC for the tested cells */
  VAR(uint16, AUTOMATIC) Signature[RAMTST_THREE] =
    {RAMTST_CRC_INIT_VALUE, RAMTST_CRC_INIT_VALUE, RAMTST_CRC_INIT_VALUE};
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the tested cells with value 0 or 1 */
  VAR(RamTst_TestDataType, AUTOMATIC) BufferCell;
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress;
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr ;
  /* Initialize the Return value */
  ReturnVal = E_OK;
  /* Initialize the BufferCell */
  BufferCell = RAMTST_ZERO;
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */
  CellAddress = RamTst_CellAddress;

  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_ENTER_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif
  /* Implements RamTst060, SWS_RamTst_00061 */
  /* Implements SWS_RamTst_00060, SWS_RamTst_00002 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_SaveData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber);
    /* END Msg(4:0491)-1 */
  }
  else
  {
    /* do nothing */
  }
  #endif

  Totalbits = (uint32)TestedCellNumber << RAMTST_CELL_DIVIDER;
  /* Select the base bit to be tested in the ascending order. (LSB to MSB)*/
  for (Index = RAMTST_ZERO;Index < Totalbits;Index++)
  {
    BaseCell = (RamTst_NumberOfTestedCellsType)(Index >> RAMTST_CELL_DIVIDER);
    BaseBit = (uint8)(Index & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    for (TestRun = RAMTST_ZERO; ((TestRun < RAMTST_THREE) &&
                                                (E_OK == ReturnVal)); TestRun++)
    {
      /* Calculate the Signature*/
      for (Count = RAMTST_ZERO; Count < TestedCellNumber; Count++)
      {
        /* Uses Fast Table based method */
        if (Count == BaseCell)
        {
          /* QAC Warning: START Msg(2:2824)-4 */
          /* MISRA Violation: START Msg(4:0488)-2 */
          BufferCell = *(CellAddress + BaseCell);
          *(CellAddress + BaseCell) = ((*(CellAddress + BaseCell)) &
                           (~(((RamTst_TestDataType)(RAMTST_ONE)) << BaseBit)));
          /* END Msg(4:0488)-2 */
          /* END Msg(2:2824)-4 */
        }
        else
        {
          /* do nothing */
        }

        /* MISRA Violation: START Msg(4:0488)-2 */
        /* Calculate the CRC using CRC lookup Table */
        Signature[TestRun] = (uint16)((Signature[TestRun] >> RAMTST_EIGHT) ^
                                      RamTst_CRC[(uint8)(Signature[TestRun]) ^
                                              (uint8)(*(CellAddress + Count))]);
        /* END Msg(4:0488)-2 */
      }
      /* MISRA Violation: START Msg(4:0488)-2 */
      *(CellAddress + BaseCell) = BufferCell;
      /* Invert the base bit*/
      RAMTST_INVERT_BITX(*(CellAddress + BaseCell), BaseBit,
                                                           RamTst_TestDataType);
      /* END Msg(4:0488)-2 */

      if ((TestRun > RAMTST_ZERO) && (Signature[RAMTST_ZERO] !=
                                                            Signature[TestRun]))
      {
        ReturnVal = E_NOT_OK;
      }
      else
      {
        /* do nothing */
      }
    }
    /* MISRA Violation: START Msg(4:0488)-2 */
    RAMTST_INVERT_BITX(*(CellAddress + BaseCell), BaseBit, RamTst_TestDataType);
    /* END Msg(4:0488)-2 */
  }
  /* Implements RamTst060 */
  /* Implements SWS_RamTst_00060 */
  /* Implements RamTst200 */
  /* Implements SWS_RamTst_00200 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_RestoreData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber, CellAddress);
    /* END Msg(4:0491)-1 */

  }
  /* Implements RamTst201 */
  /* Implements SWS_RamTst_00201 */
  else
  {
    RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  }
  #else
  RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  #endif

  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_EXIT_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif

  return ReturnVal;
} /* End of RamTst_Transp_Galpat_Algorithm */
#endif /* End of STD_ON == RAMTST_TRANSP_GALPAT_TEST_SELECTED */

#if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_Abraham_Algorithm
**
** Service ID            : NA
**
** Description           : Function for RAM testing using the Abraham
**                         Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCellNumber
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_Algorithm, RamTst_AlgParamsId
**
** Function(s) invoked   : SchM_Enter_RamTst_Area, SchM_Exit_RamTst_Area,
**                         RamTst_SaveData, RamTst_Abraham_TestSteps,
**                         RamTst_RestoreData, RamTst_FillData,
**
** Registers Used        : None
*******************************************************************************/
/* Implements RamTst055 */
/* Implements RAMTST_ESDD_UD_077 */
/* Implements SWS_RamTst_00055 */
/* Implements SWS_RamTst_00226 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE)RamTst_Abraham_Algorithm
               (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber)
/* END Msg(2:3227)-5 */
{
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress;
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;

  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                            [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */
  CellAddress = RamTst_CellAddress;

  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_ENTER_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif
  /* Implements RamTst060, SWS_RamTst_00061 */
  /* Implements SWS_RamTst_00060, SWS_RamTst_00002 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  if (RAMTST_NON_DESTRUCTIVE ==
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* Implements RAMTST_ESDD_UD_124 */
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_SaveData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber);
    /* END Msg(4:0491)-1 */
  }
  else
  {
    /* do nothing */
  }
  #endif

  ReturnVal = RamTst_Abraham_TestSteps(TestedCellNumber, CellAddress);
  /* Implements RamTst200 */
  /* Implements SWS_RamTst_00200 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  #if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
  /* Implements RAMTST_ESDD_UD_124 */
  if (RAMTST_NON_DESTRUCTIVE ==
                RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].RamTstTestPolicy)
  /* END Msg(4:0491)-1 */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    RamTst_RestoreData(RamTstAlgPtr->RamTst_BlockConfig[RamTst_Block].
      RamTstTestBuffer, TestedCellNumber, CellAddress);
    /* END Msg(4:0491)-1 */

  }
  /* Implements RamTst201 */
  /* Implements SWS_RamTst_00201 */
  else
  {
    RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  }
  #else
  RamTst_FillData(RamTst_FillPattern, TestedCellNumber, CellAddress);
  #endif

  /* Implements RAMTST_ESDD_UD_128 */
  #if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  RAMTST_EXIT_CRITICAL_SECTION(RAMTST_RAM_DATA_PROTECTION);
  #endif

  return ReturnVal;
} /* End of RamTst_Abraham_Algorithm */
#endif /* End of STD_ON == RAMTST_ABRAHAM_TEST_SELECTED */

#if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_Abraham_TestSteps
**
** Service ID            : NA
**
** Description           : Function for RAM testing using the Abraham
**                         Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCellNumber,
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : RamTst_InitializeCell, RamTst_RWAscend,
**                         RamTst_ReadDescend, RamTst_RWDescend,
**                         RamTst_ReadAscend, RamTst_RWWAscend,
**                         RamTst_WRWDescend, RamTst_InitializeCell,
**                         RamTst_WRWAscend, RamTst_RWWDescend
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_078 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE)RamTst_Abraham_TestSteps
     (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCellNumber,
             P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Testrun needed for the algorithm */
  VAR(uint8, AUTOMATIC) TestRun;
  /* Total number of tested bits */
  VAR(uint32, AUTOMATIC) Totalbits;
  /* Check for the bit */
  VAR(uint8, AUTOMATIC) CheckVariable;
  /* Initialize the tested cells with value 0 or 1 */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the Return value */
  ReturnVal = E_OK;
  /* Initialize the BackGroundVariable */
  BackGroundVariable = RAMTST_ZERO;
  /* Initialize the CheckVariable */
  CheckVariable = RAMTST_ZERO;
  Totalbits = (uint32)TestedCellNumber << RAMTST_CELL_DIVIDER;
  /* Initialize the tested cells with BackGroundVariable */
  RamTst_InitializeCell(BackGroundVariable, TestedCellNumber, CellAddress);
  for (TestRun = RAMTST_ZERO; (TestRun < RAMTST_ABRAHAM_TESTRUN) &&
                                                 (ReturnVal == E_OK); TestRun++)
  {
    if ((RAMTST_RW1_ASCEND == TestRun) || (RAMTST_RW0_ASCEND == TestRun))
    {
      ReturnVal = RamTst_RWAscend(CheckVariable, Totalbits, CellAddress);
      if (E_OK == ReturnVal)
      {
        CheckVariable = CheckVariable ^ RAMTST_ONE;
        BackGroundVariable = ~BackGroundVariable;
        ReturnVal = RamTst_ReadDescend(TestedCellNumber,
                                               BackGroundVariable, CellAddress);
      }
      else
      {
        /* do nothing */
      }
    }
    else if ((RAMTST_RW1_DESCEND == TestRun) || (RAMTST_RW0_DESCEND == TestRun))
    {
      ReturnVal = RamTst_RWDescend(CheckVariable, Totalbits, CellAddress);
      if (E_OK == ReturnVal)
      {
        CheckVariable = CheckVariable ^ RAMTST_ONE;
        BackGroundVariable = ~BackGroundVariable;
        ReturnVal = RamTst_ReadAscend(TestedCellNumber,
                                              BackGroundVariable, CellAddress);
      }
      else
      {
        /* do nothing */
      }
    }
    else if (RAMTST_RWW_ASCEND == TestRun)
    {
      ReturnVal = RamTst_RWWAscend(CheckVariable, Totalbits, CellAddress);
    }
    else if (RAMTST_WRW_DESCEND == TestRun)
    {
      ReturnVal = RamTst_WRWDescend(CheckVariable, Totalbits, CellAddress);
    }
    else if (RAMTST_W_ASCEND == TestRun)
    {
      BackGroundVariable = ~BackGroundVariable;
      CheckVariable = CheckVariable ^ RAMTST_ONE;
      RamTst_InitializeCell(BackGroundVariable, TestedCellNumber, CellAddress);
    }
    else if (RAMTST_WRW_ASCEND == TestRun)
    {
      ReturnVal = RamTst_WRWAscend(CheckVariable, Totalbits, CellAddress);
    }
    else
    {
      ReturnVal = RamTst_RWWDescend(CheckVariable, Totalbits, CellAddress);
    }
  }
  return ReturnVal;
} /* End of RamTst_Abraham_Algorithm */
#endif /* End of STD_ON == RAMTST_ABRAHAM_TEST_SELECTED */
/*******************************************************************************
** Function Name         : RamTst_ChangeBlock_BackGrndTest
**
** Service ID            : NA
**
** Description           : Function for Changing the Block.
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
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_AlgParamsId, RamTst_Algorithm,
**                         RamTst_NumBlock, RamTst_OverallTestResult,
**                         RamTst_FillPattern, RamTst_CellAddress
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements RAMTST_ESDD_UD_079 */
STATIC FUNC(void, RAMTST_CODE) RamTst_ChangeBlock_BackGrndTest (void)
{
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Index of the RamTst_TestResultBuffer for each block  */
  VAR(RamTst_NumberOfBlocksType, AUTOMATIC) Index;
  /* Temporary variable to store the test result to be assigned
   * to the overall test result
   */
  VAR(RamTst_TestResultType, AUTOMATIC)Result;

  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                            [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */

  if (RamTst_Block >= (RamTst_NumBlock - RAMTST_ONE))
  {
    /* Implements SWS_RamTst_01004 */
    Result = RAMTST_RESULT_OK;
    for (Index = RAMTST_ZERO; Index < RamTst_NumBlock; Index++)
    {
        if(RamTst_TestResultBuffer[(RamTstAlgPtr->RamTst_BlockConfig[Index].RamTstBlockId) - RAMTST_ONE]
            == RAMTST_RESULT_NOT_OK)
        {
            Result = RAMTST_RESULT_NOT_OK;
        }
        else
        {
            /* no action required */
        }
    }
    RamTst_OverallTestResult = Result;
    /* Implements RamTst044 */
    /* Implements SWS_RamTst_00044, SWS_RamTst_00113, ECUC_RamTst_00138 */
    if (NULL_PTR !=
                  RamTst_59_93_Config[RAMTST_ZERO].RamTstCompletedNotification)
    {
      /* Implements RamTst043 */
      /* Implements SWS_RamTst_00043, ECUC_RamTst_00138 */
      RamTst_59_93_Config[RAMTST_ZERO].RamTstCompletedNotification();
    }
    else
    {
      /* do nothing */
    }
    /* Implements RamTst047 */
    /* Implements SWS_RamTst_00047 */
    RamTst_Block = RAMTST_ZERO;
  }
  else
  {
    RamTst_Block++;
  }
  /* MISRA Violation: START Msg(4:0306)-4 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTst_CellAddress =
      (RamTst_TestDataType *)RamTstAlgPtr->RamTst_BlockConfig
                                              [RamTst_Block].RamTstStartAddress;
  /* END Msg(4:0491)-1 */
  /* END Msg(4:0306)-4 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTst_FillPattern = (uint32)RamTstAlgPtr->RamTst_BlockConfig
                                               [RamTst_Block].RamTstFillPattern;
  /* END Msg(4:0491)-1 */
} /* End of RamTst_ChangeBlock_BackGrndTest */

#if (RAMTST_RUN_FULL_TEST_API == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_ChangeBlock_ForeGrndTest
**
** Service ID            : NA
**
** Description           : Function for Changing the Block.
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
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : RamTst_AlgParamsId, RamTst_Algorithm,
**                         RamTst_NumBlock, RamTst_OverallTestResult,
**                         RamTst_FillPattern, RamTst_CellAddress
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements RAMTST_ESDD_UD_095 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_ChangeBlock_ForeGrndTest (void)
{
  P2CONST(RamTst_AlgConfigType, AUTOMATIC, RAMTST_VAR) RamTstAlgPtr;
  /* Index of the RamTst_TestResultBuffer for each block */
  VAR(RamTst_NumberOfBlocksType, AUTOMATIC) Index;
  /* Temporary variable to store the test result to be assigned
   * to the overall test result
   */
  VAR(RamTst_TestResultType, AUTOMATIC)Result;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the Return value */
  ReturnVal = E_OK;
  /* MISRA Violation: START Msg(4:0491)-1 */

  RamTstAlgPtr = &(RamTst_59_93_Config[RAMTST_ZERO].RamTstAlgConfig
                                             [RamTst_AlgParamsId - RAMTST_ONE]);
  /* END Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2814)-3 */
  RamTst_Algorithm = RamTstAlgPtr->RamTstAlgorithm;
  /* END Msg(2:2814)-3 */

  if (RamTst_Block >= (RamTst_NumBlock - RAMTST_ONE))
  {
    /* Implements SWS_RamTst_01007 */
    Result = RAMTST_RESULT_OK;
    for (Index = RAMTST_ZERO; Index < RamTst_NumBlock; Index++)
    {
        if(RamTst_TestResultBuffer[(RamTstAlgPtr->RamTst_BlockConfig[Index].RamTstBlockId) - RAMTST_ONE]
            == RAMTST_RESULT_NOT_OK)
        {
            Result = RAMTST_RESULT_NOT_OK;
        }
        else
        {
            /* no action required */
        }
    }
    RamTst_OverallTestResult = Result;
    RamTst_Block = RAMTST_ZERO;
  }
  else
  {
    RamTst_Block++;
    ReturnVal = E_NOT_OK;
  }
  /* MISRA Violation: START Msg(4:0306)-4 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTst_CellAddress =
      (RamTst_TestDataType *)RamTstAlgPtr->RamTst_BlockConfig
                                              [RamTst_Block].RamTstStartAddress;
  /* END Msg(4:0491)-1 */
  /* END Msg(4:0306)-4 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  RamTst_FillPattern = (uint32)RamTstAlgPtr->RamTst_BlockConfig
                                               [RamTst_Block].RamTstFillPattern;
  /* END Msg(4:0491)-1 */
  return ReturnVal;
} /* End of RamTst_ChangeBlock_ForeGrndTest */
#endif /* End of RAMTST_RUN_FULL_TEST_API == STD_ON */
/*******************************************************************************
** Function Name         : RamTst_CallAlgorithm
**
** Service ID            : NA
**
** Description           : Function for Calling Different Algorithm.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCells
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : RamTst_Checker_Algorithm, RamTst_March_Algorithm,
**                         RamTst_MarchY_Algorithm, RamTst_WalkPath_Algorithm,
**                         RamTst_Galpat_Algorithm,
**                         RamTst_Transp_Galpat_Algorithm,
**                         RamTst_Abraham_Algorithm
**
** Registers Used        : None
*******************************************************************************/
/* Implements RAMTST_ESDD_UD_080 */
/* Implements EAAR_PN0034_FR_0023 */
/* QAC Warning: START Msg(0:2755)-6 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_CallAlgorithm
                    (VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells)
/* END Msg(2:3227)-5 */
/* END Msg(0:2755)-6 */
{
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the Return value */
  ReturnVal = E_OK;
  switch (RamTst_Algorithm)
  {
  /* Implements ECUC_RamTst_00130 */
  #if (STD_ON == RAMTST_CHECKERBOARD_TEST_SELECTED)
  case RAMTST_CHECKERBOARD_TEST:
    /* Start the RAM Test by Checker Board Test Algorithm */
    ReturnVal = RamTst_Checker_Algorithm(TestedCells);
    break;
  #endif
  #if (STD_ON == RAMTST_MARCH_TEST_SELECTED)
  case RAMTST_MARCH_TEST:
    /* Start the RAM Test by March Test Algorithm */
    ReturnVal = RamTst_March_Algorithm(TestedCells);
    break;
  #endif
   #if (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED)
  case RAMTST_MARCH_Y_TEST:
    /* Start the RAM Test by March Y Test Algorithm */
    ReturnVal = RamTst_MarchY_Algorithm(TestedCells);
    break;
  #endif
  #if (STD_ON == RAMTST_WALK_PATH_TEST_SELECTED)
  case RAMTST_WALK_PATH_TEST:
    /* Start the RAM Test by WalkPath Test Algorithm */
    ReturnVal = RamTst_WalkPath_Algorithm(TestedCells);
    break;
  #endif
  #if (STD_ON == RAMTST_GALPAT_TEST_SELECTED)
  case RAMTST_GALPAT_TEST:
    /* Start the RAM Test by Galpat Test Algorithm */
    ReturnVal = RamTst_Galpat_Algorithm(TestedCells);
    break;
  #endif
  #if (STD_ON == RAMTST_TRANSP_GALPAT_TEST_SELECTED)
  case RAMTST_TRANSP_GALPAT_TEST:
    /* Start the RAM Test by Transparent Galpat Test Algorithm */
    ReturnVal = RamTst_Transp_Galpat_Algorithm(TestedCells);
    break;
  #endif
  #if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
  case RAMTST_ABRAHAM_TEST:
    /* Start the RAM Test by Abraham Test Algorithm */
    ReturnVal = RamTst_Abraham_Algorithm(TestedCells);
    break;
  #endif
  /* QAC Warning: START Msg(2:2016)-7 */
  default:
     /* Do Nothing */
    break;
  }
  /* END Msg(2:2016)-7 */
  return ReturnVal;
}/* End of RamTst_CallAlgorithm */
#if (RAMTST_NON_DESTRUCTIVE_POLICY == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_SaveData
**
** Service ID            : NA
**
** Description           : Function for storing the RAM content before
**                         starting the RAM Test.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_TestDataType Buffer,
**                         RamTst_NumberOfTestedCellsType TestedCells
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_094 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(void, RAMTST_CODE) RamTst_SaveData
              (P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_CODE) Buffer,
                     VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells)
/* END Msg(2:3227)-5 */
{
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Index;
  for (Index = RAMTST_ZERO; Index < TestedCells; Index++)
  {
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    *(Buffer + Index) = *(RamTst_CellAddress + Index);
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
  }
}/* End of RamTst_SaveData */
/*******************************************************************************
** Function Name         : RamTst_RestoreData
**
** Service ID            : NA
**
** Description           : Function for re-storing the RAM content after
**                         finishing the RAM Test.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_TestDataType Buffer
**                         RamTst_NumberOfTestedCellsType TestedCells
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00186 */
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_081 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(void, RAMTST_CODE) RamTst_RestoreData
(P2CONST(RamTst_TestDataType, AUTOMATIC, RAMTST_CODE) Buffer,
        VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
             P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Index;
  for (Index = RAMTST_ZERO;Index < TestedCells; Index++)
  {
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    *(CellAddress + Index) = *(Buffer + Index);
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
  }
}/* End of RamTst_RestoreData */
#endif
/*******************************************************************************
** Function Name         : RamTst_FillData
**
** Service ID            : NA
**
** Description           : Function for initializing the RAM content after
**                         finishing the destructive RAM Test.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : uint32 RamTstFillPattern,
**                         RamTst_NumberOfTestedCellsType TestedCells,
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_082 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(void, RAMTST_CODE) RamTst_FillData
(VAR(uint32, RAMTST_VAR)RamTstFillPattern,
      VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
             P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Index;
  for (Index = RAMTST_ZERO; Index < TestedCells; Index++)
  {
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    *(CellAddress + Index) = RamTstFillPattern;
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
  }
}/* End of RamTst_FillData */
/*******************************************************************************
** Function Name         : RamTst_InitializeCell
**
** Service ID            : NA
**
** Description           : Function for Initializing  RAM content either
**                         with zero or one.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_TestDataType Init_CellVariable,
**                         RamTst_NumberOfTestedCellsType TestedCells,
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
#if ((STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) || \
(STD_ON == RAMTST_MARCH_TEST_SELECTED) ||  \
(STD_ON == RAMTST_MARCH_Y_TEST_SELECTED) ||  \
(STD_ON == RAMTST_GALPAT_TEST_SELECTED) || \
(STD_ON == RAMTST_WALK_PATH_TEST_SELECTED))
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_083 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(void, RAMTST_CODE) RamTst_InitializeCell
(VAR(RamTst_TestDataType, AUTOMATIC) Init_CellVariable,
   VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
     P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Index;
  for (Index = RAMTST_ZERO; Index < TestedCells; Index++)
  {
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    *(CellAddress + Index) = Init_CellVariable;
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
  }
}/* End of RamTst_InitializeCell */
#endif /* End of STD_ON == (test algorithms selected) */

#if ((STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) || \
(STD_ON == RAMTST_MARCH_TEST_SELECTED))
/*******************************************************************************
** Function Name         : RamTst_RWAscend
**
** Service ID            : NA
**
** Description           : Function for read, check and invert each bit in
**                         ascending order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : uint8 CheckVariable,
**                         uint32 Totalbits,
**                         RamTst_TestDataType Cellnumber
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_084*/
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWAscend
(
  VAR(uint8, AUTOMATIC) CheckVariable,
         VAR(uint32, AUTOMATIC) Totalbits,
            P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* Bit to be tested in the cell */
  VAR(uint8, AUTOMATIC) Bitnumber;
  /* Bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  /* Return variable */
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Read, check and invert each bit in ascending order (LSB to MSB) */
  for (Index = RAMTST_ZERO; (Index < Totalbits) && (E_OK == ReturnVal); Index++)
  {
    /* loading Value for Cellnumber */
    Cellnumber = (RamTst_NumberOfTestedCellsType)(Index >> RAMTST_CELL_DIVIDER);
    /* Loading Bitnumber value */
    Bitnumber = (uint8)(Index & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    if ((*(CellAddress + Cellnumber) & ((uint32)(RAMTST_ONE) << Bitnumber)) ==
                          (((RamTst_TestDataType)(CheckVariable)) << Bitnumber))
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber) ,
                                              Bitnumber, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
    }
    else
    {
      ReturnVal = E_NOT_OK;
    }
  }
  return ReturnVal;
}/* End of RamTst_RWAscend */
#endif
  /* End of (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
   * || (STD_ON == RAMTST_MARCH_TEST_SELECTED)
   */

#if (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_RWRAscend
**
** Service ID            : NA
**
** Description           : Function for read, check and write, check
**                         each bit in ascending order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_TestDataType CheckVariable,
**                         uint32 Totalbits,
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_085 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWRAscend
  (VAR(RamTst_TestDataType, AUTOMATIC) CheckVariable,
    VAR(uint32, AUTOMATIC) Totalbits,
      P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* Bit to be tested in the cell */
  VAR(uint8, AUTOMATIC) Bitnumber;
  /* Bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Read, check and invert each bit in ascending order (LSB to MSB) */
  for (Index = RAMTST_ZERO; (Index < Totalbits) && (E_OK == ReturnVal); Index++)
  {
    Cellnumber = (RamTst_NumberOfTestedCellsType)(Index >> RAMTST_CELL_DIVIDER);
    Bitnumber = (uint8)(Index & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    if (((*(CellAddress + Cellnumber)) & ((uint32)(RAMTST_ONE) << Bitnumber)) ==
                         ((RamTst_TestDataType)(CheckVariable) << Bitnumber))
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                               Bitnumber, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      if ((*(CellAddress + Cellnumber) & ((uint32)(RAMTST_ONE) << Bitnumber)) ==
        (RamTst_TestDataType)((CheckVariable ^ (RamTst_TestDataType)RAMTST_ONE)
        << Bitnumber))
      /* END Msg(4:0488)-2 */
      {
        /* No action Required  */
      }
      else
      {
        ReturnVal = E_NOT_OK;
      }
    }
    else
    {
      ReturnVal = E_NOT_OK;
    }
  }
  return ReturnVal;
}/* End of RamTst_RWAscend */
#endif
      /* End of (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
       * || (STD_ON == RAMTST_MARCH_TEST_SELECTED)
       */
#if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_ReadDescend
**
** Service ID            : NA
**
** Description           : Function for read and check cells in descending
**                         order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCells,
**                         RamTst_TestDataType BackGroundVariable,
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00186 */
/* Implements RAMTST_ESDD_UD_086 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_ReadDescend
(VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable,
    P2CONST(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells*/
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Read and check in descending order */
  for (Cellnumber = (TestedCells);
    ((Cellnumber > (RamTst_NumberOfTestedCellsType)RAMTST_ZERO) &&
    (E_OK == ReturnVal)); Cellnumber--)
  {
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    if (*(CellAddress + (Cellnumber -
      (RamTst_NumberOfTestedCellsType)RAMTST_ONE)) != BackGroundVariable)
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
    {
      ReturnVal = E_NOT_OK;
    }
    else
    {
      /* do nothing */
    }
  }
  return ReturnVal;
}/* End of RamTst_ReadDescend */
#endif/* End of (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) */

#if ((STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) || \
 (STD_ON == RAMTST_MARCH_TEST_SELECTED))
/*******************************************************************************
** Function Name         : RamTst_RWDescend
**
** Service ID            : NA
**
** Description           : Function for read, check and invert each bit in
**                         descending order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : uint8 CheckVariable,
**                         uint32 Totalbits,
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_087 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWDescend
(VAR(uint8, AUTOMATIC) CheckVariable, VAR(uint32, AUTOMATIC) Totalbits,
     P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* Bit to be tested in the cell */
  VAR(uint8, AUTOMATIC) Bitnumber;
  /* Bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Read, check and invert each bit in descending order (LSB to MSB) */
  for (Index = (Totalbits);(Index > (uint32)RAMTST_ZERO) && (E_OK == ReturnVal);
    Index--)
  {
    Cellnumber = (RamTst_NumberOfTestedCellsType)
      ((Index - (uint32)RAMTST_ONE) >> RAMTST_CELL_DIVIDER);
    Bitnumber = (uint8)
      ((Index - (uint32)RAMTST_ONE) & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    if (((*(CellAddress + Cellnumber)) & ((uint32)(RAMTST_ONE) << Bitnumber))
                        == ((RamTst_TestDataType)(CheckVariable) << Bitnumber))
     /* END Msg(4:0488)-2 */
     /* END Msg(2:2824)-4 */
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                                Bitnumber, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
    }
    else
    {
      ReturnVal = E_NOT_OK;
    }
  }
  return ReturnVal;
}/* End of RamTst_RWDescend */
#endif
      /* End of (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) ||
       * (STD_ON == RAMTST_MARCH_TEST_SELECTED)
       */

#if (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_RWRDescend
**
** Service ID            : NA
**
** Description           : Function for read, check and write check
**                         each bit in descending order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : uint8 CheckVariable,
**                         uint32 Totalbits,
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_088 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWRDescend
(VAR(RamTst_TestDataType, AUTOMATIC) CheckVariable,
      VAR(uint32, AUTOMATIC) Totalbits,
             P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* Bit to be tested in the cell */
  VAR(uint8, AUTOMATIC) Bitnumber;
  /* Bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Read, check and invert each bit in descending order (LSB to MSB) */
  for (Index = (Totalbits); (Index > (uint32)RAMTST_ZERO) &&
                                                   (E_OK == ReturnVal); Index--)
  {
    Cellnumber = (RamTst_NumberOfTestedCellsType)
      ((Index - (uint32)RAMTST_ONE) >> RAMTST_CELL_DIVIDER);
    Bitnumber = (uint8)
      ((Index - (uint32)RAMTST_ONE) & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */

    if (((*(CellAddress + Cellnumber)) & ((uint32)(RAMTST_ONE) << Bitnumber))
             == ((RamTst_TestDataType)(CheckVariable) << Bitnumber))

    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                              Bitnumber, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:0488)-2 */

      if (((*(CellAddress + Cellnumber)) & ((uint32)(RAMTST_ONE) << Bitnumber))
        == ((CheckVariable ^ (uint32)RAMTST_ONE) << Bitnumber))
      /* END Msg(4:0488)-2 */
      {
        /* do nothing */
      }
      else
      {
        ReturnVal = E_NOT_OK;
      }
    }
    else
    {
      ReturnVal = E_NOT_OK;
    }
  }
  return ReturnVal;
}/* End of RamTst_RWDescend */
#endif/* End of (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED) */

#if ((STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) || \
  (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED))
/*******************************************************************************
** Function Name         : RamTst_ReadAscend
**
** Service ID            : NA
**
** Description           : Function for read and check cells in ascending
**                         order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : RamTst_NumberOfTestedCellsType TestedCells
**                         RamTst_TestDataType BackGroundVariable
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00186 */
/* Implements RAMTST_ESDD_UD_089 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_ReadAscend
(VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells,
   VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable,
     P2CONST(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Read and check in descending order */
  for (Cellnumber = RAMTST_ZERO;(Cellnumber < TestedCells) &&
                                               (E_OK == ReturnVal);Cellnumber++)
  {
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    if (*(CellAddress + Cellnumber) != BackGroundVariable)
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
    {
      ReturnVal = E_NOT_OK;
    }
    else
    {
      /* do nothing */
    }
  }
  return ReturnVal;
}/* End of RamTst_ReadAscend */
#endif/* End of ((STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) || \
        (STD_ON == RAMTST_MARCH_Y_TEST_SELECTED)) */

#if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
/*******************************************************************************
** Function Name         : RamTst_RWWDescend
**
** Service ID            : NA
**
** Description           : Function for read, invert and re-invert each bit in
**                         descending order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : uint8 CheckVariable
**                         uint32 Totalbits
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_090 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWWDescend
(VAR(uint8, AUTOMATIC) CheckVariable, VAR(uint32, AUTOMATIC) Totalbits,
             P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  VAR(uint32, AUTOMATIC) Bitnumber;
  /* Bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells;
  /* Initialize the tested cells with value ~0 */
  /* QAC Warning: START Msg(2:3204)-9 */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  /* END Msg(2:3204)-9 */
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Initialize the value to BackGroundVariable */
  BackGroundVariable = ~(RamTst_TestDataType)(RAMTST_ZERO);
  /* Read, check and invert each bit in descending order (LSB to MSB) */
  for (Index = Totalbits;(Index > (uint32)RAMTST_ZERO) && (E_OK == ReturnVal);
    Index--)
  {
    Cellnumber = (RamTst_NumberOfTestedCellsType)
      ((Index - (uint32)RAMTST_ONE) >> RAMTST_CELL_DIVIDER);
    Bitnumber = (uint32)
      ((Index - (uint32)RAMTST_ONE) & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    if (((*(CellAddress + Cellnumber)) & ((uint32)(RAMTST_ONE) << Bitnumber))
                      == ((RamTst_TestDataType)(CheckVariable) << Bitnumber))
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */

    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                                Bitnumber, RamTst_TestDataType);
      /* re-Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                                Bitnumber, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
    }
    else
    {
      ReturnVal = E_NOT_OK;
    }
  }
  if (E_OK == ReturnVal)
  {
    TestedCells = (RamTst_NumberOfTestedCellsType)(Totalbits >>
                                                          RAMTST_CELL_DIVIDER);
    ReturnVal = RamTst_ReadAscend(TestedCells, BackGroundVariable, CellAddress);
  }
  else
  {
    /* do nothing */
  }
  return ReturnVal;
}/* End of RamTst_RWWDescend */
/*******************************************************************************
** Function Name         : RamTst_RWWAscend
**
** Service ID            : NA
**
** Description           : Function for read, invert and re-invert each bit in
**                         ascending order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : uint8 CheckVariable
**                         uint32 Totalbits
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : RamTst_ReadDescend
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_091 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_RWWAscend
(VAR(uint8, AUTOMATIC) CheckVariable, VAR(uint32, AUTOMATIC) Totalbits,
             P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* Bit to be tested in the cell */
  VAR(uint32, AUTOMATIC) Bitnumber;
  /* Bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells;
  /* Initialize the tested cells with value 0 */
  /* QAC Warning: START Msg(2:3204)-9 */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  /* END Msg(2:3204)-9 */
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Initialize the value to BackGroundVariable */
  BackGroundVariable = RAMTST_ZERO;
  /* Read, check and invert each bit in ascending order (LSB to MSB) */
  for (Index = RAMTST_ZERO;(Index < Totalbits) && (E_OK == ReturnVal);Index++)
  {
    Cellnumber = (RamTst_NumberOfTestedCellsType)(Index >> RAMTST_CELL_DIVIDER);
    Bitnumber = (uint32)(Index & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */

    if (((*(CellAddress + Cellnumber)) & ((uint32)(RAMTST_ONE) << Bitnumber))
                      == ((RamTst_TestDataType)(CheckVariable) << Bitnumber))
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */

    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                                Bitnumber, RamTst_TestDataType);
      /* re-Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                                Bitnumber, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
    }
    else
    {
      ReturnVal = E_NOT_OK;
    }
  }
  if (E_OK == ReturnVal)
  {
    TestedCells = (RamTst_NumberOfTestedCellsType)
                                             (Totalbits >> RAMTST_CELL_DIVIDER);
    ReturnVal = RamTst_ReadDescend(TestedCells,
                                              BackGroundVariable, CellAddress);
  }
  else
  {
    /* do nothing */
  }

  return ReturnVal;
}/* End of RamTst_RWWAscend */
/*******************************************************************************
** Function Name         : RamTst_WRWAscend
**
** Service ID            : NA
**
** Description           : Function for invert, read and re-invert each bit in
**                         ascending order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : uint8 CheckVariable
**                         uint32 Totalbits
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : RamTst_ReadDescend
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_096 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_WRWAscend
(VAR(uint8, AUTOMATIC) CheckVariable, VAR(uint32, AUTOMATIC) Totalbits,
     P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* bit to be tested in the cell */
  VAR(uint32, AUTOMATIC) Bitnumber;
  /* bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells;
  /* Initialize the tested cells with value ~0 */
  /* QAC Warning: START Msg(2:3204)-9 */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  /* END Msg(2:3204)-9 */
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Initialize the value to BackGroundVariable */
  BackGroundVariable = ~(RamTst_TestDataType)(RAMTST_ZERO);
  CheckVariable = CheckVariable ^ RAMTST_ONE;
  /* Read, check and invert each bit in ascending order (LSB to MSB) */
  for (Index = RAMTST_ZERO; (Index < Totalbits) && (E_OK == ReturnVal); Index++)
  {
    Cellnumber = (RamTst_NumberOfTestedCellsType)(Index >> RAMTST_CELL_DIVIDER);
    Bitnumber = (uint32)(Index & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* Invert the Testbit  */
    RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
           Bitnumber, RamTst_TestDataType);
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    if (((*(CellAddress + Cellnumber)) & ((uint32)(RAMTST_ONE) << Bitnumber))
                      == ((RamTst_TestDataType)(CheckVariable) << Bitnumber))
    /* END Msg(4:0488)-2 */

    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* re-Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                               Bitnumber, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
    }
    else
    {
      ReturnVal = E_NOT_OK;
    }
  }
  if (E_OK == ReturnVal)
  {
    TestedCells = (RamTst_NumberOfTestedCellsType)
                                            (Totalbits >> RAMTST_CELL_DIVIDER);
    ReturnVal = RamTst_ReadDescend(TestedCells,
                                              BackGroundVariable, CellAddress);
  }
  else
  {
    /* do nothing */
  }

  return ReturnVal;
}/* End of RamTst_WRWAscend */
/*******************************************************************************
** Function Name         : RamTst_WRWDescend
**
** Service ID            : NA
**
** Description           : Function for invert, read and re-invert each bit in
**                         descending order.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : uint8 CheckVariable
**                         uint32 Totalbits
**                         RamTst_TestDataType CellAddress
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : The function RamTst_Init shall be called first
**                         before calling this function.
**
** Global Variables Used : None
**
** Function(s) invoked   : RamTst_ReadAscend
**
** Registers Used        : None
*******************************************************************************/
/* Implements SWS_BSW_00187 */
/* Implements RAMTST_ESDD_UD_093 */
/* QAC Warning: START Msg(2:3227)-5 */
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_WRWDescend
(VAR(uint8, AUTOMATIC) CheckVariable, VAR(uint32, AUTOMATIC) Totalbits,
     P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_VAR_FAST) CellAddress)
/* END Msg(2:3227)-5 */
{
  /* Index of the 0cells */
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) Cellnumber;
  /* Bit to be tested in the cell */
  VAR(uint32, AUTOMATIC) Bitnumber;
  /* Bit numbering */
  VAR(uint32, AUTOMATIC) Index;
  VAR(Std_ReturnType, AUTOMATIC) ReturnVal;
  VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC) TestedCells;
  /* Initialize the tested cells with value 0 */
  /* QAC Warning: START Msg(2:3204)-9 */
  VAR(RamTst_TestDataType, AUTOMATIC) BackGroundVariable;
  /* END Msg(2:3204)-9 */
  /* Initialize the value to ReturnVal */
  ReturnVal = E_OK;
  /* Initialize the value to BackGroundVariable */
  BackGroundVariable = RAMTST_ZERO;
  CheckVariable = CheckVariable ^ RAMTST_ONE;
  /* Read, check and invert each bit in ascending order (LSB to MSB) */
  for (Index = Totalbits; (Index > (uint32)RAMTST_ZERO) && (E_OK == ReturnVal);
    Index--)
  {
    Cellnumber = (RamTst_NumberOfTestedCellsType)
      ((Index - (uint32)RAMTST_ONE) >> RAMTST_CELL_DIVIDER);
    Bitnumber = (uint32)
      ((Index - (uint32)RAMTST_ONE) & (RAM_TEST_DATA_TYPE - RAMTST_ONE));
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* Invert the Testbit  */
    RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                                Bitnumber, RamTst_TestDataType);
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    if (((*(CellAddress + Cellnumber)) & ((uint32)(RAMTST_ONE) << Bitnumber))
                      == ((RamTst_TestDataType)(CheckVariable) << Bitnumber))
    /* END Msg(4:0488)-2 */

    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* re-Invert the Testbit  */
      RAMTST_INVERT_BITX(*(CellAddress + Cellnumber),
                                                Bitnumber, RamTst_TestDataType);
      /* END Msg(4:0488)-2 */
    }
    else
    {
      ReturnVal = E_NOT_OK;
    }
  }
  if (E_OK == ReturnVal)
  {
    TestedCells = (RamTst_NumberOfTestedCellsType)
                                            (Totalbits >> RAMTST_CELL_DIVIDER);
    ReturnVal = RamTst_ReadAscend(TestedCells, BackGroundVariable, CellAddress);
  }
  else
  {
    /* do nothing */
  }

  return ReturnVal;
}/* End of RamTst_WRWDescend */
#endif/* End of (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED) */

#if (RAMTST_GET_VERSION_INFO_API  == STD_ON)
/*******************************************************************************
** Function Name         : RamTst_GetVersionInfo
**
** Service ID            : 0x0A
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
** Output Parameters     : VersionInfo
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

/* RAMTST Version Information Check */
/* RAMTST_H_011: EAAR_PN0081_FR_0005, RamTst078, SWS_BSW_00052, RamTst079 */
/* RAMTST_H_012: SWS_BSW_00051, RamTst222, SWS_RamTst_00222, SWS_BSW_00110 */
/* RAMTST_H_013: SWS_BSW_00051, SWS_BSW_00164, SWS_RamTst_00109 */
/* Implements: EAAR_PN0034_FR_0051, EAAR_PN0034_FR_0092 */
/* Implements RAMTST_ESDD_UD_062 */
/* Implements RamTst109 */
/* Implements RamTst128_Conf */
/* Implements ECUC_RamTst_00128 */
/* QAC Warning: START Msg(2:3227)-5 */
FUNC(void, RAMTST_CODE) RamTst_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, RAMTST_APPL_DATA) VersionInfo)
/* END Msg(2:3227)-5 */
{
  /* Implements RamTst121_Conf */
  #if (RAMTST_DEV_ERROR_DETECT == STD_ON)
  /* RAMTST_H_014: SWS_BSW_00212, SWS_BSW_00215, SWS_BSW_00168 */
  /* RAMTST_H_015: SWS_BSW_00064, SWS_BSW_00052, EAAR_PN0034_FR_0092 */
  /* Report to DET, if VersionInfo pointer is equal to Null */
  if (NULL_PTR == VersionInfo)
  {
    /* Report to DET  */
    /* Implements RAMTST_ESDD_UD_156 */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
                         RAMTST_GET_VERSIONINFO_SVCID, RAMTST_E_PARAM_POINTER);
  }
  else
  #endif /*#if (RAMTST_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(2:2814)-3 */
    /* Copy the vendor Id */
    (VersionInfo)->vendorID = (uint16)RAMTST_VENDOR_ID;
    /* Copy the module Id */
    (VersionInfo)->moduleID = (uint16)RAMTST_MODULE_ID;
    /* Copy Software Major Version */
    (VersionInfo)->sw_major_version = RAMTST_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    (VersionInfo)->sw_minor_version = RAMTST_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    (VersionInfo)->sw_patch_version = RAMTST_SW_PATCH_VERSION;
    /* END Msg(2:2814)-3 */
  }
}
#endif
/* End of RamTst Section Code */
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_CODE_ASIL_B
#else
#define RAMTST_STOP_SEC_CODE
#endif
/* QAC Warning: START Msg(2:0862)-2 */
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
