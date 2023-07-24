/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA.h                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API and database declaration, Service Id and DET error Macros */
/* and Module version information Macros.                                     */
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
* V1.0.0:  03-Sep-2015    : Initial Version
*
* V1.0.1:  21-Dec-2015    : As per ARDAAGA-82 following changes has been done:
*                           1. Wdg_59_DriverA_GetVersionInfo macro is removed
*                              and extern declaration of
*                              Wdg_59_DriverA_GetVersionInfo API has been added.
*                           2. Inclusion of Det.h has been removed.
* V2.0.0   25-Aug-2016    : Changed according to #ARDAABD-653
*                           and ASR 3.2.2 was removed and 4.2.2 added
* V2.0.1   26-Sep-2016    : WDG_E_PARAM_POINTER defined for all ASR versions
* V2.1.0   26-Oct-2016    : 1. MemMap was changed according to #ARDAABD-474
*                           2. FUSA req. implemented according to #ARDAABD-568
* V2.1.1   14-Dec-2016    : Changed according to #ARDAABD-568
* V2.1.1   16-Jan-2017    : Changed after code review
*                           Wdg_59_DriverA_CheckHWConsistency was updated
* V2.1.2   27-Jan-2017    : RAM Mirroring check was updated
* V2.1.3   15-Mar-2017    : #ARDAABD-1207
*                           Traceability update
* V2.1.4   15-Jun-2017    : As part of ARDAABD-1897 Jira ticket, code was
*                           updated after QAC analysis
* V2.1.5   16-Nov-2017    : Following changes are made:
*                           1. As part of ARDAABD-2734 Jira Ticket,
*                              variable MEMMAP_FILE is changed to
*                              WDG_MEMMAP_FILE.
* V2.1.6   09-Jul-2018    : Following changes are made:
*                           1. As part of merging activity, #ARDAABD-3474
*                           a. Memory section naming modifications are done,
*                              Ref:ARDAABD-908.
*                           2. As part #ARDAABD-3905, traceability
*                              has been updated by mapping respective
*                              WDG_ESDD_UD IDs.
*/
/******************************************************************************/
#ifndef WDG_59_DRIVERA_H
#define WDG_59_DRIVERA_H

/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define WDG_59_DRIVERA_AR_FOUR_TWO_TWO         422
#define WDG_59_DRIVERA_AR_FOUR_ZERO_THREE      403

#define WDG_59_DRIVERA_AR_HIGHER_VERSION       WDG_59_DRIVERA_AR_FOUR_TWO_TWO
#define WDG_59_DRIVERA_AR_LOWER_VERSION        WDG_59_DRIVERA_AR_FOUR_ZERO_THREE

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Since Det_ReportError API is implemented as macro braces   */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-1 and                           */
/*                 END Msg(4:3458)-1 tags in the code.                        */

/******************************************************************************/
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* WDG_59_DRIVERA_H_001: WDG_ESDD_UD_044                                      */
/* WDG_59_DRIVERA_H_002: WDG149, WDG149_Conf                                  */
/* WDG_59_DRIVERA_H_003: ECUC_Wdg_00149                                       */
/* WDG_59_DRIVERA_H_004: WDG_ESDD_UD_042                                      */
/* WDG_59_DRIVERA_H_005: WDG150, WDG150_Conf, WDG151                          */
/* WDG_59_DRIVERA_H_006: ECUC_Wdg_00150                                       */
/* WDG_59_DRIVERA_H_007: AR_PN0064_FR_0034, AR_PN0064_FR_0035                 */
/* WDG_59_DRIVERA_H_008: AR_PN0064_FR_0050, EAAR_PN0034_FR_0067               */
/* WDG_59_DRIVERA_H_009: IMP_F1x_V3.03.06_WDG_RS_1                            */
/* WDG_59_DRIVERA_H_010: WDG_ESDD_UD_072                                      */
/* WDG_59_DRIVERA_H_011: WDG061, SWS_Wdg_00061                                */

/* To publish the type Wdg_59_DriverA_ConfigType */
#include "Wdg_59_DriverA_Types.h"
/* Inclusion for the tool generated macros */
#include "Wdg_59_DriverA_Cfg.h"
/* Included for RAM Mirroring and Write Verify */
#include "Wdg_59_DriverA_RegWrite.h"
/* Functionality related to R4.0 and R4.2 */
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* Only in case of DET enabled, Debug variables will be available externally */
#include "Wdg_59_DriverA_Debug.h"
#endif


/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
#define WDG_59_DRIVERA_VENDOR_ID    WDG_59_DRIVERA_VENDOR_ID_VALUE
#define WDG_59_DRIVERA_MODULE_ID    WDG_59_DRIVERA_MODULE_ID_VALUE
/* WDG_59_DRIVERA_H_019: WDG_ESDD_UD_018                                      */
#define WDG_59_DRIVERA_INSTANCE_ID  WDG_59_DRIVERA_INSTANCE_ID_VALUE

#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.2.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION    4
#define WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION    2
#define WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION 2

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION    4
#define WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION    0
#define WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION 3
#endif

/* Module Software version information */
#define WDG_59_DRIVERA_SW_MAJOR_VERSION   WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_SW_MINOR_VERSION   WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_SW_PATCH_VERSION   WDG_59_DRIVERA_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      DET ERROR CODES                                       **
*******************************************************************************/
/* WDG_59_DRIVERA_H_012: WDG_ESDD_UD_040, WDG_ESDD_UD_041                     */
/*
* Following error will be reported when API service is used in wrong context
* (For e.g. When Trigger / SetMode function is invoked without initialization).
*/
#define WDG_59_DRIVERA_E_DRIVER_STATE       (uint8)0x10

/*
* Following error will be reported when API Wdg_SetMode is called with wrong /
* inconsistent parameter(s).
*/
#define WDG_59_DRIVERA_E_PARAM_MODE         (uint8)0x11

/*
* Following error will be reported when API Wdg_Init  is called /
* with wrong inconsistent parameter(s).
*/
#define WDG_59_DRIVERA_E_PARAM_CONFIG       (uint8)0x12


#define WDG_59_DRIVERA_E_PARAM_POINTER      (uint8)0x14

#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
#define WDG_59_DRIVERA_E_INIT_FAILED        (uint8)0x15
#endif

/*
* Following error will be reported when API Wdg_SetTriggerCondition is called
* with timeout value greater than the maximum timeout value.
*/
#define WDG_59_DRIVERA_E_PARAM_TIMEOUT      (uint8)0x13

/*
* Following error will be reported when Watchdog driver database does not
* exist or exist in invalid location.
*/
#define WDG_59_DRIVERA_E_INVALID_DATABASE   (uint8)0xF1

/*******************************************************************************
**                      API Service Id Macros                                 **
*******************************************************************************/
/* Service ID of Watchdog Driver Initialization API. */
#define WDG_59_DRIVERA_INIT_SID                   (uint8)0x00

/*
* Service ID of SetMode API which switches current watchdog mode to the
* Watchdog mode defined by the parameter ModeSet.
*/
#define WDG_59_DRIVERA_SETMODE_SID                (uint8)0x01

/* Functionality related to R4.0 and R4.2 */
/* Service ID of Trigger condition API which triggers the Watchdog Hardware. */
#define WDG_59_DRIVERA_SETTRIGGERCONDITION_SID    (uint8)0x03

/* Service ID of Version Information API. */
#define WDG_59_DRIVERA_GETVERSIONINFO_SID         (uint8)0x04

/* Service ID of HW Check Consistency API */

#define WDG_59_DRIVERA_CHECK_HW_CONSISTENCY_SID   (uint8)0x05


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE

/* WDG_59_DRIVERA_H_013: WDG_ESDD_UD_015 , WDG_ESDD_UD_053                    */
#if (WDG_59_DRIVERA_VERSION_INFO_API == STD_ON)
extern FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_59_DRIVERA_APPL_DATA) versioninfo);
#endif
/* WDG_59_DRIVERA_H_014: WDG_ESDD_UD_051                                      */
/* External Declaration for Watchdog Initialization API. */
extern FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_Init
(P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
ConfigPtr);
/* WDG_59_DRIVERA_H_015: WDG_ESDD_UD_052                                      */
/* External Declaration for Watchdog SetMode API. */
extern FUNC(Std_ReturnType, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_SetMode
(WdgIf_ModeType Mode);
/* WDG_59_DRIVERA_H_016: WDG_ESDD_UD_056                                      */
/* Functionality related to R4.0 and R4.2 */
/* External Declaration for Watchdog Set Trigger Condition API. */
extern FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE)
Wdg_59_DriverA_SetTriggerCondition(uint16 timeout);
/* WDG_59_DRIVERA_H_017: WDG_ESDD_UD_055                                      */
/* Implementation of Wdg_59_DriverA_HWCheckConsistency API */
#if (WDG_59_DRIVERA_RAM_MIRROR == WDG_59_DRIVERA_MIRROR_ENABLE)
extern FUNC(Std_ReturnType, WDG_59_DRIVERA_PUBLIC_CODE)
Wdg_59_DriverA_CheckHWConsistency
          (Wdg_59_DriverA_HWConsistencyModeType HWConsistencyMode);
#endif

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* MISRA Violation: START Msg(4:3458)-1 */
#define WDG_59_DRIVERA_DET_REPORTERROR(ApiId, ErrorId)\
{\
(void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,\
ApiId, ErrorId);\
}
/* END Msg(4:3458)-1 */
#else
#define WDG_59_DRIVERA_DET_REPORTERROR(ApiId, ErrorId)
#endif

#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE


#define WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include WDG_MEMMAP_FILE

/* WDG_59_DRIVERA_H_018: WDG_ESDD_UD_026 */
/* External Declaration for Watchdog database configuration set. */
extern CONST(Wdg_59_DriverA_ConfigType, WDG_59_DRIVERA_CONFIG_CONST)
Wdg_59_DriverA_GstConfiguration;

#define WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include WDG_MEMMAP_FILE


#endif /* WDG_59_DRIVERA_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
