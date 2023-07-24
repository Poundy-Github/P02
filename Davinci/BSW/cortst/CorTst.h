/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst.h                                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros and API function prototypes of Core Test Driver. */
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
 *                           2. The DET error code 'CORTST_E_BGNDTEST_RUNNING'
 *                              macro is added.
 *
 * V1.0.2:  09-Sep-2014    : As per CR 604 for Mantis issue #22252, following
 *                           changes are made:
 *                           1. File is updated for including Autosar R3.2
 *                              version information details and get version
 *                              information macro.
 *                           2. Autosar release specific macros are added.
 *                           3. Function prototype for swg3k API is removed for
 *                              not to publish to the upper layer.
 *                           4. Misra warning with justification is provided.
 *
 * V1.0.3:  28-May-2015   : As per Mantis #20338, following changes are made:
 *                          1. The Copyright information is updated.
 *                          2. NULL pointer checking and DET error reporting is
 *                             implemented in CorTst_GetVersionInfo API.
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
 * V2.0.5:  24-Oct-2016    : #ARDAABD-897
 *                           1.CorTst_Init prototype shall have an input
 *                           parameter ConfigPtr
 * V2.0.5:  27-Oct-2016    : #ARDAABD-897
 *                           1.CorTst_Init prototype was changed
 * V2.0.6:  8-Nov-2016     : #ARDAABD-939
 *                           1. Update section " Version information"
 * V2.0.7:  19-June-2018   : 1.Added justification for QAC Warning which cannot
 *                             be removed.
 *                           2.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           3.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 */
/******************************************************************************/
#ifndef CORTST_H
#define CORTST_H

/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define CORTST_AR_FOUR_ZERO_THREE    403
#define CORTST_AR_FOUR_TWO_TWO       422

#define CORTST_AR_HIGHER_VERSION     CORTST_AR_FOUR_TWO_TWO
#define CORTST_AR_LOWER_VERSION      CORTST_AR_FOUR_ZERO_THREE

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/* Included to get the pre-compile macros */
/* CORTST_H_001: CORTST_ESDD_UD_046, CorTst182 */
#include "CorTst_Cfg.h"
/* Included for CorTst type declarations */
#include "CorTst_Types.h"
/* Included for CorTst type external declarations for Callback functions */
#include "CorTst_LTTypes.h"

#if (CORE_G3K == CORTST_SWCST)
#include "st_glob.h"
/* CORTST_H_002: CorTst092_Conf, CorTst081_Conf, CorTst125_Conf */
#include "config.h"
#else
#include "CST_if.h"
#endif

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
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define CORTST_VENDOR_ID         CORTST_VENDOR_ID_VALUE
#define CORTST_MODULE_ID         CORTST_MODULE_ID_VALUE
/* CORTST_H_002:  CORTST_ESDD_UD_010                                          */
/* CORTST_H_003:  BSW00347, CorTst125_Conf                                    */
/* CORTST_H_004:  ECUC_CorTst_00125                                           */
#define CORTST_INSTANCE_ID       CORTST_INSTANCE_ID_VALUE

/* CORTST_H_005: CORTST_ESDD_UD_063                                           */
#if (CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION)
/* AUTOSAR release version information */
#define CORTST_AR_RELEASE_MAJOR_VERSION    4U
#define CORTST_AR_RELEASE_MINOR_VERSION    2U
#define CORTST_AR_RELEASE_REVISION_VERSION 2U
/* CORTST_H_006: CORTST_ESDD_UD_063                                           */
#elif (CORTST_AR_VERSION == CORTST_AR_LOWER_VERSION)
/* AUTOSAR release version information */
#define CORTST_AR_RELEASE_MAJOR_VERSION    4U
#define CORTST_AR_RELEASE_MINOR_VERSION    0U
#define CORTST_AR_RELEASE_REVISION_VERSION 3U
#endif

/* Module Software version information */
#define CORTST_SW_MAJOR_VERSION    1U
#define CORTST_SW_MINOR_VERSION    1U
#define CORTST_SW_PATCH_VERSION    0U

/*******************************************************************************
**                      API Service Id Macros                                 **
*******************************************************************************/
/* Service Id of CorTst_Init */
#define CORTST_INIT_SID                               (uint8)0x00
/* Service Id of CorTst_DeInit */
#define CORTST_DEINIT_SID                             (uint8)0x01
/* Service Id of CorTst_Abort */
#define CORTST_ABORT_SID                              (uint8)0x02
/* Service Id of CorTst_GetState */
#define CORTST_GET_STATE_SID                          (uint8)0x03
/* Service Id of CorTst_GetCurrentStatus */
#define CORTST_GET_CURRENT_STATUS_SID                 (uint8)0x04
/* Service Id of CorTst_GetTestSignatureBgnd */
#define CORTST_GET_SIGNATURE_SID                      (uint8)0x05
/* Service Id of CorTst_GetFgndSignature */
#define CORTST_GET_FGND_SIGNATURE_SID                 (uint8)0x06
/* Service Id of CorTst_Start */
#define CORTST_START_SID                              (uint8)0x07
/* Service Id of CorTst_GetVersionInfo */
#define CORTST_GET_VERSION_INFO_SID                   (uint8)0x08
/* Service Id of CorTst_MainFunction */
#define CORTST_MAIN_FUNCTION_SID                      (uint8)0x0B

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* CORTST_H_007:  CORTST_ESDD_UD_034                                          */
/* CORTST_H_008:  BSW00337, CorTst015, CorTst016, CorTst169, CorTst170        */
/* CORTST_H_009:  CorTst_00180, CorTst_00181                                  */
/* CORTST_H_010:  SWS_BSW_00201, SWS_CorTst_00016, SWS_CorTst_00169           */
/* CORTST_H_011:  SWS_CorTst_00170, SWS_CorTst_00180, SWS_CorTst_00181        */
/*
 * When API service is called in an unexpected state is reported using following
 * error code
 */
#define CORTST_E_STATUS_FAILURE                 (uint8)0x01

/* CORTST_H_012:  CORTST_ESDD_UD_030                                          */
/* CORTST_H_013:  BSW00337, CorTst015, CorTst016, CorTst169, CorTst170        */
/* CORTST_H_014:  CorTst_00180, CorTst_00181                                  */
/* CORTST_H_015:  SWS_BSW_00201, SWS_CorTst_00016, SWS_CorTst_00169           */
/* CORTST_H_016:  SWS_CorTst_00170, SWS_CorTst_00180, SWS_CorTst_00181        */
/*
 * When API service is called with wrong parameter range is reported using
 * following error code
 */
#define CORTST_E_PARAM_INVALID                  (uint8)0x011

/* CORTST_H_017:  CORTST_ESDD_UD_031                                          */
/* CORTST_H_018:  BSW00337, CorTst015, CorTst016, CorTst169, CorTst170        */
/* CORTST_H_019:  CorTst_00180, CorTst_00181                                  */
/* CORTST_H_020:  SWS_BSW_00201, SWS_CorTst_00016, SWS_CorTst_00169           */
/* CORTST_H_021:  SWS_CorTst_00170, SWS_CorTst_00180, SWS_CorTst_00181        */
/*
 * When API service called without module initialization is reported using
 * following error code
 */
#define CORTST_E_UNINIT                         (uint8)0x020

/* CORTST_H_022:  CORTST_ESDD_UD_032                                          */
/* CORTST_H_023:  BSW00337, CorTst015, CorTst016, CorTst169, CorTst170        */
/* CORTST_H_024:  CorTst_00180, CorTst_00181                                  */
/* CORTST_H_025:  SWS_BSW_00201, SWS_CorTst_00016, SWS_CorTst_00169           */
/* CORTST_H_026:  SWS_CorTst_00170, SWS_CorTst_00180, SWS_CorTst_00181        */
/*
 * When API service CorTst_Init called while CORTST is already initialized is
 * reported using following error code
 */
#define CORTST_E_ALREADY_INITIALIZED            (uint8)0x023

/* CORTST_H_027:  CORTST_ESDD_UD_033                                          */
/* CORTST_H_028:  BSW00337, CorTst015, CorTst016, CorTst169, CorTst170        */
/* CORTST_H_029:  CorTst_00180, CorTst_00181                                  */
/* CORTST_H_030:  SWS_BSW_00201, SWS_CorTst_00016, SWS_CorTst_00169           */
/* CORTST_H_031:  SWS_CorTst_00170, SWS_CorTst_00180, SWS_CorTst_00181        */
/*
 * When API service CorTst_GetVersionInfo / CorTst_GetCurrentStatus is called
 * with NULL pointer is reported using following error code
 */
#define CORTST_E_PARAM_POINTER                  (uint8)0x024

/* CORTST_H_032:  CORTST_ESDD_UD_059                                          */
/* CORTST_H_033:  BSW00337, CorTst015, CorTst016, CorTst169, CorTst170        */
/* CORTST_H_034:  CorTst_00180, CorTst_00181                                  */
/* CORTST_H_035:  SWS_BSW_00201, SWS_CorTst_00016, SWS_CorTst_00169           */
/* CORTST_H_036:  SWS_CorTst_00170, SWS_CorTst_00180, SWS_CorTst_00181        */
/*
 * When API service CorTst_Start is called while background test is running is
 * reported using following error code
 */
#define CORTST_E_BGNDTEST_RUNNING               (uint8)0x025

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CORTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* CORTST_H_037: CORTST_ESDD_UD_063                                           */
#if (CORTST_AR_VERSION == CORTST_AR_HIGHER_VERSION)
/* CORTST_H_038: SWS_CORTST_1004 */
FUNC(void, CORTST_PUBLIC_CODE) CorTst_Init
         ( P2CONST(CorTst_ConfigType, AUTOMATIC, CORTST_APPL_DATA) ConfigPtr );
/* CORTST_H_039: CORTST_ESDD_UD_063                                           */
#elif (CORTST_AR_VERSION == CORTST_AR_LOWER_VERSION)
FUNC(void, CORTST_PUBLIC_CODE) CorTst_Init(void);
#endif

extern FUNC(void, CORTST_PUBLIC_CODE) CorTst_DeInit(void);

/* CORTST_H_040: CORTST_ESDD_UD_013 */
/* Implements ECUC_CorTst_00094 */
#if (CORTST_ABORT_API == STD_ON)
extern FUNC(void, CORTST_PUBLIC_CODE)CorTst_Abort(void);
#endif /* End of #if (CORTST_ABORT_API == STD_ON) */

/* CORTST_H_041: CORTST_ESDD_UD_017, ECUC_CorTst_00096 */
#if (CORTST_GET_STATE_API == STD_ON)
extern FUNC(CorTst_StateType, CORTST_PUBLIC_CODE)CorTst_GetState(void);
#endif /* End of #if (CORTST_GET_STATE_API == STD_ON) */

/* CORTST_H_042: CORTST_ESDD_UD_014 */
/* CORTST_H_043: CORTST_ESDD_UD_052 */
/* CORTST_H_044: CORTST_ESDD_UD_084, ECUC_CorTst_00104 */
#if (CORTST_GET_CURRENT_STATUS_API == STD_ON)
extern FUNC(void, CORTST_PUBLIC_CODE)CorTst_GetCurrentStatus
(P2VAR(CorTst_ErrOkType, AUTOMATIC, CORTST_APPL_DATA) ErrOk);
#endif /* End of #if (CORTST_GET_CURRENT_STATUS_API == STD_ON) */

/* CORTST_H_045: CORTST_ESDD_UD_016 */
/* CORTST_H_046: CORTST_ESDD_UD_085, ECUC_CorTst_00097 */
#if (CORTST_GET_SIGNATURE_API == STD_ON)
extern FUNC(CorTst_CsumSignatureBgndType, CORTST_PUBLIC_CODE)
CorTst_GetSignature(void);
#endif /* End of #if (CORTST_GET_SIGNATURE_API == STD_ON) */

/* CORTST_H_047: CORTST_ESDD_UD_015, ECUC_CorTst_00103 */
#if (CORTST_GET_FGND_SIGNATURE_API == STD_ON)
extern FUNC(CorTst_CsumSignatureType, CORTST_PUBLIC_CODE)
CorTst_GetFgndSignature(void);
#endif /* End of #if (CORTST_GET_FGND_SIGNATURE_API == STD_ON) */

/* CORTST_H_048: CORTST_ESDD_UD_018 */
/* Implements ECUC_CorTst_00093 */
#if (CORTST_START_API == STD_ON)
extern FUNC(Std_ReturnType, CORTST_PUBLIC_CODE)
CorTst_Start(CorTst_TestIdFgndType TestId);
#endif /* End of #if (CORTST_START_API == STD_ON) */

extern FUNC(void, CORTST_PUBLIC_CODE)CorTst_MainFunction(void);

/* CORTST_H_049: CORTST_ESDD_UD_019, ECUC_CorTst_00098 */
#if (CORTST_VERSION_INFO_API == STD_ON)
/* CORTST_H_050: CORTST_ESDD_UD_056 */
extern FUNC(void, CORTST_PUBLIC_CODE) CorTst_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, CORTST_APPL_DATA) versioninfo);
#endif


#define CORTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* CORTST_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
