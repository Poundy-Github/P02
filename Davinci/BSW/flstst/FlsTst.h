/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst.h                                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, FLSTST type definitions, enumerations,          */
/* data types and API function prototypes of FLSTST Driver.                   */
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
 * V1.0.0:  20-Nov-2013    : Initial Version
 *
 * V1.0.1:  03-Feb-2014    : As per CR78 and merge activity and mantis #17998
 *                           following changes are made:
 *                           1. Copyright information is updated.
 *                           2. Macros are updated with a typecasting at the
 *                              declaration.
 *                           3. FLSTST_E_PARAM_POINTER macro is removed since
 *                              it is unused because FlsTst_GetVersionInfo is
 *                              implemented in macro.
 *
 * V1.0.2:  08-May-2014    : As per CR506  header file Std_Types.h included
 *                           instead of FlsTst_PBTypes.h file.
 *
 * V1.0.3:  06-Jun-2014    : As per CR524, The changes made in the previous
 *                           revision is reverted ie.header file
 *                           FlsTst_PBTypes.h included again.
 *
 * V1.0.4:  17-Sep-2014    : As per CR12, following changes are made:
 *                           1. MISRA C Rule Violations section is added.
 *                           2. MISRA rules violation messages are added.
 *                           3. As per Renesas coding guidelines,
 *                              Markers are added for Tracing.
 *
 * V1.0.5:  09-Jun-2015    : As part of F1L V4.01.07, following changes were
 *                           made:
 *                           1. Added macros FLSTST_E_PARAM_POINTER and
 *                           FLSTST_DET_REPORTERROR as part of fixing mantis
 *                           ticket #20338.
 *                           2. Copyright information was updated
 * V2.0.0:  28-Oct-2016    : Changed memmap file handling (ASR4.2.2 compliant)
 *                           Added CheckHWConsistency() function
 * V2.0.1:  02-Nov-2016    : Fix MISRA violation
 * V2.0.2:  16-Mar-2017    : FlsTst_CheckHWConsistency interface corrected
 *                           Replaced FLSTST_MIRROR_ENABLE with FLSTST_ENABLE
 *                           Added traceability information as part of JIRA
 *                           ARDAABD-1211.
 * V2.0.3:  21-Aug-2017    : Justification added for QAC warning which cannot
 *                           be removed.
 * V2.0.4:  21-Jun-2018    : 1. As part of #ARDAABD-3842, Removed duplicate
 *                              Requirement id's and mapped the required
 *                              Requirements for traceability
 *                           2. Updated copy-rights information
 */
/******************************************************************************/
/* FLSTST_H_015: EAAR_PN0034_FR_0001                                          */
#ifndef FLSTST_H
#define FLSTST_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for FlsTst type declarations */
#include "FlsTst_PBTypes.h"
#include "FlsTst_RegWrite.h"

#if (FLSTST_DEV_ERROR_DETECT == STD_ON)
/* Only in case of DET enabled, Debug variables will be available externally */
#include "FlsTst_Debug.h"
#include "Det.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define FLSTST_VENDOR_ID         FLSTST_VENDOR_ID_VALUE
#define FLSTST_MODULE_ID         FLSTST_MODULE_ID_VALUE
/* FLSTST_H_018: FLSTST_ESDD_UD_002, ECUC_FlsTst_00104, ECUC_FlsTst_00120     */
/* FLSTST_H_031: ECUC_FlsTst_00086, ECUC_FlsTst_00135, ECUC_FlsTst_00082      */
/* FLSTST_H_032: ECUC_FlsTst_00161, ECUC_FlsTst_00084, ECUC_FlsTst_00158      */
/* FLSTST_H_033: ECUC_FlsTst_00160, ECUC_FlsTst_00085                         */
#define FLSTST_INSTANCE_ID       FLSTST_INSTANCE_ID_VALUE

/* AUTOSAR release version information */
#define FLSTST_AR_RELEASE_MAJOR_VERSION    FLSTST_CFG_AR_RELEASE_MAJOR_VERSION
#define FLSTST_AR_RELEASE_MINOR_VERSION    FLSTST_CFG_AR_RELEASE_MINOR_VERSION
#define FLSTST_AR_RELEASE_REVISION_VERSION \
                                          FLSTST_CFG_AR_RELEASE_REVISION_VERSION

/* FLSTST_H_016: EAAR_PN0034_FR_0055                                          */
/* Module Software version information */
#define FLSTST_SW_MAJOR_VERSION    FLSTST_SW_MAJOR_VERSION_VALUE
#define FLSTST_SW_MINOR_VERSION    FLSTST_SW_MINOR_VERSION_VALUE
#define FLSTST_SW_PATCH_VERSION    FLSTST_SW_PATCH_VERSION_VALUE

/* FLSTST_H_017: EAAR_PN0034_NR_0026                                          */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-1 and                           */
/*                 END Msg(4:3458)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-2 and                           */
/*                 END Msg(4:3684)-2 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                             QAC Warnings                                   **
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
/* Service Id of FlsTst_Init */
#define FLSTST_INIT_SID                               (uint8)0x00
/* Service Id of FlsTst_DeInit */
#define FLSTST_DEINIT_SID                             (uint8)0x01
/* Service Id of FlsTst_StartFgnd */
#define FLSTST_START_FGND_SID                         (uint8)0x02
/* Service Id of FlsTst_Abort */
#define FLSTST_ABORT_SID                              (uint8)0x03
/* Service Id of FlsTst_Suspend */
#define FLSTST_SUSPEND_SID                            (uint8)0x04
/* Service Id of FlsTst_Resume */
#define FLSTST_RESUME_SID                             (uint8)0x05
/* Service Id of FlsTst_GetCurrentState */
#define FLSTST_GET_CURRENT_STATE_SID                  (uint8)0x06
/* Service Id of FlsTst_GetTestResultBgnd */
#define FLSTST_GET_TEST_RESULT_BGND_SID               (uint8)0x07
/* Service Id of FlsTst_GetVersionInfo */
#define FLSTST_GET_VERSION_INFO_SID                   (uint8)0x08
/* Service Id of FlsTst_GetTestSignatureBgnd */
#define FLSTST_GET_TEST_SIGNATURE_BGND_SID            (uint8)0x09
/* Service Id of FlsTst_GetTestSignaturefgnd */
#define FLSTST_GET_TEST_SIGNATURE_FGND_SID            (uint8)0x0A
/* Service Id of FlsTst_GetErrorDetails */
#define FLSTST_GET_ERROR_DETAILS_SID                  (uint8)0x0B
/* Service Id of FlsTst_TestEcc */
#define FLSTST_TEST_ECC_SID                           (uint8)0x0C
/* Service Id of FlsTst_MainFunction */
#define FLSTST_MAIN_FUNCTION_SID                      (uint8)0x0D
/* Service Id of FlsTst_TestCompletedNotification */
#define FLSTST_TEST_COMPLETED_NOTIFICATION_SID        (uint8)0x0E
/* Service Id of FlsTst_GetTestResultFgnd */
#define FLSTST_GET_TEST_RESULT_FGND_SID               (uint8)0x0F
/* Service Id of FlsTst_CheckHWConsistency */
#define FLSTST_CHECK_HW_CONSISTENCY_SID               (uint8)0x10

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* TRACE [R4, FlsTst006] */
/*
 * API service Flsttst_Resume is called and if the current execution state of
 * the Flash Test module is not FLSTST_SUSPENDED is reported using following
 * error code
 */
/* FLSTST_H_001: FLSTST_ESDD_UD_061                                           */
/* FLSTST_H_002: FlsTst006, FlsTst007, FlsTst008, FlsTst009, FlsTst011        */
/* FLSTST_H_003: FlsTst014, FlsTst012, FlsTst023, FlsTst025, FlsTst033        */
/* FLSTST_H_004: FlsTst039, FlsTst072, FlsTst133, FlsTst073, FlsTst161        */
/* FLSTST_H_005: SWS_FlsTst_00007, SWS_FlsTst_00168                           */
/* FLSTST_H_006: SWS_FlsTst_00011                                             */
/* FLSTST_H_007: SWS_FlsTst_00025                                             */
/* FLSTST_H_008: SWS_FlsTst_00033, SWS_FlsTst_00039, SWS_FlsTst_00072         */
/* FLSTST_H_009: SWS_FlsTst_00073, SWS_FlsTst_00161                           */
#define FLSTST_E_STATE_FAILURE                 (uint8)0x01

/*
 * API service  called with parameters out of specified range is reported using
 * following error code
 */
#define FLSTST_E_PARAM_INVALID                 (uint8)0x02
/*
 * API service called without module initialization is reported using following
 * error code
 */
#define FLSTST_E_UNINIT                        (uint8)0x03

/*
 * API service FlsTst_Init called while FLSTST is already initialized
 * is reported using following error code
 */
#define FLSTST_E_ALREADY_INITIALIZED           (uint8)0x04

/*
 * API service FlsTst_Init for variant PB called with configuration pointer
 * as NULL_PTR is reported using following error code
 */
#define FLSTST_E_PARAM_CONFIG                  (uint8)0x05

/*
 * API service FlsTst_GetVersionInfo called with NULL_PTR passed
 * is reported using following error code
 */
#define FLSTST_E_PARAM_POINTER                 (uint8)0x06

/* When valid Database is not available */
#define FLSTST_E_INVALID_DATABASE              (uint8)0xEF

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

extern FUNC(void, FLSTST_PUBLIC_CODE) FlsTst_Init
(P2CONST(FlsTst_ConfigType, AUTOMATIC, FLSTST_APPL_CONST) ConfigPtr);

extern FUNC(void, FLSTST_PUBLIC_CODE) FlsTst_DeInit(void);

/* FLSTST_H_019: FLSTST_ESDD_UD_094, FlsTst086_Conf                           */
#if (FLSTST_START_FGND_API == STD_ON)
extern FUNC(Std_ReturnType, FLSTST_PUBLIC_CODE)
FlsTst_StartFgnd(FlsTst_BlockIdFgndType FgndBlockId);
#endif /*(FLSTST_START_FGND_API == STD_ON) */

extern FUNC(void, FLSTST_PUBLIC_CODE)FlsTst_Abort(void);

/* FLSTST_H_020: FLSTST_ESDD_UD_095, FlsTst087_Conf                           */
#if (FLSTST_SUSPEND_RESUME_API == STD_ON)
extern FUNC(void, FLSTST_PUBLIC_CODE)FlsTst_Suspend(void);

/* FLSTST_H_029: FLSTST_ESDD_UD_091                                           */
extern FUNC(void, FLSTST_PUBLIC_CODE)FlsTst_Resume(void);
#endif /* (FLSTST_SUSPEND_RESUME_API == STD_ON)*/

#if (FLSTST_GET_CURRENT_STATE_API == STD_ON)
extern FUNC(FlsTst_StateType, FLSTST_PUBLIC_CODE)FlsTst_GetCurrentState(void);
#endif /*(FLSTST_GET_CURRENT_STATE_API == STD_ON) */

/* FLSTST_H_021:  FLSTST_ESDD_UD_096                                          */
#if (FLSTST_GET_TEST_RESULT_BGND_API == STD_ON)
extern FUNC(FlsTst_TestResultBgndType, FLSTST_PUBLIC_CODE)
FlsTst_GetTestResultBgnd(void);
#endif /* (FLSTST_GET_TEST_RESULT_BGND_API == STD_ON)*/

/* FLSTST_H_022:  FLSTST_ESDD_UD_097                                          */
#if (FLSTST_GET_TEST_RESULT_FGND_API == STD_ON)
extern FUNC(FlsTst_TestResultFgndType, FLSTST_PUBLIC_CODE)
FlsTst_GetTestResultFgnd(void);
#endif /*(FLSTST_GET_TEST_RESULT_FGND_API == STD_ON) */

/* FLSTST_H_023:  FLSTST_ESDD_UD_098                                          */
#if (FLSTST_GET_TEST_SIGNATURE_BGND_API == STD_ON)
extern FUNC(FlsTst_TestSignatureBgndType, FLSTST_PUBLIC_CODE)
FlsTst_GetTestSignatureBgnd(void);
#endif /* (FLSTST_GET_TEST_SIGNATURE_BGND_API == STD_ON) */

/* FLSTST_H_024:  FLSTST_ESDD_UD_099                                          */
#if (FLSTST_GET_TEST_SIGNATURE_FGND_API == STD_ON)
extern FUNC(FlsTst_TestSignatureFgndType, FLSTST_PUBLIC_CODE)
FlsTst_GetTestSignatureFgnd(void);
#endif /*(FLSTST_GET_TEST_SIGNATURE_FGND_API == STD_ON) */

/* FLSTST_H_025:  FLSTST_ESDD_UD_100                                          */
#if (FLSTST_GET_ERROR_DETAILS_API == STD_ON)
extern FUNC(FlsTst_ErrorDetailsType, FLSTST_PUBLIC_CODE)
FlsTst_GetErrorDetails(void);
#endif /*(FLSTST_GET_ERROR_DETAILS_API == STD_ON)*/

#if (FLSTST_TEST_ECC_API == STD_ON)
extern FUNC(Std_ReturnType, FLSTST_PUBLIC_CODE)
FlsTst_TestEcc(void);
#endif /*(FLSTST_TEST_ECC_API ==STD_ON)*/

extern FUNC(void, FLSTST_PUBLIC_CODE)FlsTst_MainFunction(void);

#if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)
extern FUNC(Std_ReturnType, FLSTST_PUBLIC_CODE) FlsTst_CheckHWConsistency
                           (FlsTst_HWConsistencyModeType HWConsistencyMode);
#endif /* (FLSTST_RAM_MIRROR == FLSTST_ENABLE) */

/* MISRA Violation: START Msg(4:3458)-1 */
/* Macro for DET error reporting */
/* FLSTST_H_026: FLSTST_ESDD_UD_003                                           */
#if (FLSTST_DEV_ERROR_DETECT == STD_ON)
  #define FLSTST_DET_REPORTERROR(ApiId, ErrorId)\
  {\
   (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID, ApiId, ErrorId);\
  }
#else
  #define FLSTST_DET_REPORTERROR(ApiId, ErrorId)
#endif
/* END Msg(4:3458)-1 */

/* API to get the version information */
#if (FLSTST_VERSION_INFO_API == STD_ON)
/* TRACE [R4, FlsTst045] */
/* TRACE [R4, FlsTst047] */
/* MISRA Violation: START Msg(4:3458)-1 */
/* FLSTST_H_027: FLSTST_ESDD_UD_093, FLSTST_ESDD_UD_040                       */
/* FLSTST_H_011: FlsTst014, FlsTst044, FlsTst045, FlsTst133, FlsTst046        */
/* FLSTST_H_012: FlsTst047, EAAR_PN0034_FR_0092, FlsTst095_Conf               */
/* FLSTST_H_013: SWS_FlsTst_00044                                             */
/* FLSTST_H_028: EAAR_PN0034_FR_0051                                          */
#define FlsTst_GetVersionInfo(VersioninfoPtr)\
{ \
  if(NULL_PTR == (VersioninfoPtr)) \
  { \
   FLSTST_DET_REPORTERROR(FLSTST_GET_VERSION_INFO_SID, FLSTST_E_PARAM_POINTER) \
  } \
  else \
  { \
    (VersioninfoPtr)->vendorID = (uint16)FLSTST_VENDOR_ID; \
    (VersioninfoPtr)->moduleID = (uint16)FLSTST_MODULE_ID; \
    (VersioninfoPtr)->sw_major_version = FLSTST_SW_MAJOR_VERSION; \
    (VersioninfoPtr)->sw_minor_version = FLSTST_SW_MINOR_VERSION; \
    (VersioninfoPtr)->sw_patch_version = FLSTST_SW_PATCH_VERSION; \
  } \
}
/* END Msg(4:3458)-1 */
#endif /*(FLSTST_VERSION_INFO_API == STD_ON)*/

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Configured parameter for FLSTST  */
/* MISRA Violation: START Msg(4:3684)-2 */
/* FLSTST_H_030: FLSTST_ESDD_UD_071                                           */
extern CONST(FlsTst_ConfigType, FLSTST_CONFIG_CONST) FlsTst_GstConfiguration[];
/* END Msg (4:3684)-2 */
#define FLSTST_STOP_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* FLSTST_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
