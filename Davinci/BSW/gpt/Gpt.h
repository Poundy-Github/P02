/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API information.                                              */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  17-Sep-2015    : Initial Version
 *
 * V1.0.1:  11-Nov-2015    : As per ARDAAGA-76 following changes has been done:
 *                           1. Gpt_GetVersionInfo macro is removed since
 *                              Gpt_GetVersionInfo is implemented as function
 *
 * V2.0.0:  27-Sep-2016    : Several changes for solving tickets
 *                           1. ARDAABC-751 Remove Gpt_ReadBackTest macro.
 *                           Old implementation is replaced by a new approach
 *                           where this macro is not required any more.
 *                           2. ARDAABC-518 Moved enumeration type Gpt_ModeType
 *                           to Gpt_Types.h
 *                           3. ARDAABC-769 Added Gpt_HWCheckConsistency API
 *                           declaration and Service Id
 *
 * V2.1.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 *
 * V2.2.0:  15-Oct-2016    : Add one new public API Gpt_GetPredefTimerValue
 *                           and the corresponding SID and update DET error
 *                           codes as part of ARDAABC-564
 *
 * V2.2.1:  18-Sep-2017    : Following changes are made:
 *                           1. As per ARDAABD-2425, QAC level 2 warning
 *                              Justification tags are added.
 *                           2. As per ARDAABD-2570, typo errors corrected.
 *                           3. Copyright year updated.
 *
 * V2.2.2:  18-Jun-2018    : Following changes are made:
 *                           1. As per ARDAABD-3841, traceability updated.
 *                           2. Copyright information updated.
 */
/******************************************************************************/
#ifndef GPT_H
#define GPT_H
/* GPT_H_033: GPT365, EAAR_PN0034_FR_0001 */
/*******************************************************************************
 **      To support different AUTOSAR releases in a single package            **
 ******************************************************************************/
#define GPT_AR_FOUR_ZERO_THREE    403
#define GPT_AR_FOUR_TWO_TWO       422
/* GPT_H_001: GPT_ESDD_UD_059*/
#define GPT_AR_HIGHER_VERSION     GPT_AR_FOUR_TWO_TWO
/* GPT_H_002: GPT_ESDD_UD_058*/
#define GPT_AR_LOWER_VERSION      GPT_AR_FOUR_ZERO_THREE

/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* Included for Type definitions */
#include "Std_Types.h"
#include "Gpt_Cbk.h"
/* GPT_H_003: GPT259 */
/* GPT_H_004: SWS_Gpt_00259 */
/* Included for Gpt_Cfg.h inclusion and To publish the type Gpt_ConfigType */
#include "Gpt_Types.h"
/* GPT_H_005: GPT271 */
/* GPT_H_006: SWS_Gpt_00271 */
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
/* Included for the declaration of EcuM_SetWakeupEvent() */
#include "EcuM_Cbk.h"
#endif
/* GPT_H_007: GPT_ESDD_UD_114*/
#include "Gpt_PBTypes.h"
#if (GPT_DEV_ERROR_DETECT == STD_ON)
/*
 * Only in case of DET enabled, Debug variables will be available externally.
 */
#include "Gpt_Debug.h"
#endif
/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* Version identification */
/* GPT_H_032: GPT380, SWS_Gpt_00380, EAAR_PN0034_FR_0055 */
#define GPT_VENDOR_ID              GPT_VENDOR_ID_VALUE
#define GPT_MODULE_ID              GPT_MODULE_ID_VALUE
/* GPT_H_008: GPT_ESDD_UD_025*/
#define GPT_INSTANCE_ID            GPT_INSTANCE_ID_VALUE

/* AUTOSAR specification version information */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
/* Functionality related to R4.2.2 */
#define GPT_AR_RELEASE_MAJOR_VERSION       4
#define GPT_AR_RELEASE_MINOR_VERSION       2
#define GPT_AR_RELEASE_REVISION_VERSION    2
#else
/* Functionality related to R4.0.3 */
#define GPT_AR_RELEASE_MAJOR_VERSION       4
#define GPT_AR_RELEASE_MINOR_VERSION       0
#define GPT_AR_RELEASE_REVISION_VERSION    3
#endif

/* File version information */
#define GPT_SW_MAJOR_VERSION     GPT_SW_MAJOR_VERSION_VALUE
#define GPT_SW_MINOR_VERSION     GPT_SW_MINOR_VERSION_VALUE
#define GPT_SW_PATCH_VERSION     GPT_SW_PATCH_VERSION_VALUE

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/
/*******************************************************************************
 **                         QAC Warning                                       **
 ******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : None                                                       */
/* Justification : These Macro substitution is required to optimize MemMap    */
/*                 inclusion.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/
/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
 **                        Service IDs                                        **
 ******************************************************************************/

/* Service Id of Gpt_GetVersionInfo */
#define GPT_GET_VERSION_INFO_SID   (uint8)0x00

/* Service Id of Gpt_Init */
#define GPT_INIT_SID               (uint8)0x01

/* Service Id of Gpt_DeInit */
#define GPT_DEINIT_SID             (uint8)0x02

/* Service Id of Gpt_GetTimeElapsed */
#define GPT_GET_TIME_ELAPSED_SID   (uint8)0x03

/* Service Id of Gpt_GetTimeRemaining */
#define GPT_GET_TIME_REMAINING_SID (uint8)0x04

/* Service Id of Gpt_StartTimer */
#define GPT_START_TIMER_SID        (uint8)0x05

/* Service Id of Gpt_StopTimer */
#define GPT_STOP_TIMER_SID         (uint8)0x06

/* Service Id of Gpt_EnableNotification */
#define GPT_ENABLE_NOTIFY_SID      (uint8)0x07

/* Service Id of Gpt_DisableNotification */
#define GPT_DISABLE_NOTIFY_SID     (uint8)0x08

/* Service Id of Gpt_SetMode */
#define GPT_SET_MODE_SID           (uint8)0x09

/* Service Id of Gpt_DisableWakeup */
#define GPT_DISABLE_WAKEUP_SID     (uint8)0x0A

/* Service Id of Gpt_EnableWakeup */
#define GPT_ENABLE_WAKEUP_SID      (uint8)0x0B

/* Service Id of  Gpt_CheckWakeup */
#define GPT_CHECK_WAKEUP_SID       (uint8)0x0C

/* Service Id of  Gpt_HWCheckConsistency */
#define GPT_HW_CHECK_CONSISTENCY_SID (uint8)0x0E

/* Service Id of  Gpt_GetPredefTimerValue */
#define GPT_GET_PREDEF_TIMER_VALUE_SID (uint8)0x0D

/*******************************************************************************
 **                      DET Error Codes                                      **
 ******************************************************************************/
/* GPT_H_009: GPT174, GPT345 */
/* GPT_H_010: SWS_Gpt_00174, SWS_Gpt_00345, EAAR_PN0034_FR_0064 */
/* DET code to report uninitialized state */
#define GPT_E_UNINIT               (uint8)0x0A

/* GPT_H_011: GPT346 */
/* GPT_H_012: SWS_Gpt_00346 */
/* DET code to report Timer is already running */
#define GPT_E_BUSY                 (uint8)0x0B


/* GPT_H_013: SWS_Gpt_00387 */
/* DET code to report that driver is in wrong mode  */
#define GPT_E_MODE                 (uint8)0x0C

/* GPT_H_014: GPT347 */
/* GPT_H_015: SWS_Gpt_00347 */
/* DET code to report Timer already Initialized */
#define GPT_E_ALREADY_INITIALIZED  (uint8)0x0D

/* GPT_H_016: SWS_Gpt_00404 */
/* DET code to report that Init function failed  */
#define GPT_E_INIT_FAILED          (uint8)0x0E

/* GPT_H_017: GPT348 */
/* GPT_H_018: SWS_Gpt_00348 */
/* DET code to report invalid Channel Identifier */
#define GPT_E_PARAM_CHANNEL        (uint8)0x14
/* GPT_H_019: GPT349 */
/* GPT_H_020: SWS_Gpt_00349 */
/* DET code to report invalid timer value */
#define GPT_E_PARAM_VALUE          (uint8)0x15
/* GPT_H_021: GPT350 */
/* GPT_H_022: SWS_Gpt_00350 */
/* DET code to report the use of an invalid pointer */
#define GPT_E_PARAM_POINTER        (uint8)0x16

/* GPT_H_023: SWS_Gpt_00388 */
/* DET code to report that an invalid Predef Timer is used */
#define GPT_E_PARAM_PREDEF_TIMER    (uint8)0x17
/* GPT_H_024: GPT351 */
/* GPT_H_025: SWS_Gpt_00351 */
/* DET code to report invalid mode parameter */
#define GPT_E_PARAM_MODE           (uint8)0x1F

/* GPT_H_034: GPT004 */
/* DET code to report invalid database */
#define GPT_E_INVALID_DATABASE     (uint8)0xEF

/* DET code to report that Gpt API service Gpt_DisableNotification
 * is invoked for the channel for which the notification is already disabled
 */
#define GPT_E_ALREADY_DISABLED     (uint8)0xF1

/* DET code to report that Gpt API service Gpt_EnableNotification
 * is invoked for the channel for which the notification is already enabled
 */
#define GPT_E_ALREADY_ENABLED      (uint8)0xF2

/*******************************************************************************
 **                      Global Data Types                                    **
 ******************************************************************************/
/* GPT_H_026: GPT359 */
/* GPT_H_027: SWS_Gpt_00359 */
/* Type describing the time out value */
typedef uint32 Gpt_ValueType;
/* GPT_H_028: GPT358 */
/* GPT_H_029: SWS_Gpt_00358 */
/* Type describing the channel ID */
typedef uint8 Gpt_ChannelType;

/*******************************************************************************
 **                          Macros                                           **
 ******************************************************************************/

/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* GPT_H_030: GPT182 */
/* GPT_H_031: SWS_Gpt_00182, EAAR_PN0034_NR_0088 */
#if (GPT_VERSION_INFO_API == STD_ON)
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_GetVersionInfo
    (P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) versioninfo);
#endif

extern FUNC(void, GPT_PUBLIC_CODE) Gpt_Init
    (P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr);

#if (GPT_DE_INIT_API == STD_ON)
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_DeInit (void);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
extern FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeElapsed
    (Gpt_ChannelType channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)

extern FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeRemaining
    (Gpt_ChannelType channel);

#endif

extern FUNC(void, GPT_PUBLIC_CODE) Gpt_StartTimer
    (Gpt_ChannelType channel, Gpt_ValueType value);

extern FUNC(void, GPT_PUBLIC_CODE) Gpt_StopTimer
    (Gpt_ChannelType channel);


#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON )
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableNotification
    (Gpt_ChannelType channel);
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableNotification
    (Gpt_ChannelType channel);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_SetMode
    (Gpt_ModeType mode);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableWakeup
    (Gpt_ChannelType channel);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableWakeup
    (Gpt_ChannelType channel);
#endif

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)

FUNC(Std_ReturnType, GPT_PUBLIC_CODE) Gpt_GetPredefTimerValue(
    Gpt_PredefTimerType PredefTimer,
    uint32* TimeValuePtr );
#endif /* #if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */


#if ( (GPT_OSTM_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
    (GPT_TAUDB_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
    (GPT_TAUJ_RAM_MIRROR == GPT_MIRROR_ENABLE ))
FUNC(Std_ReturnType, GPT_PUBLIC_CODE) Gpt_HWCheckConsistency
    (Gpt_HWConsistencyModeType HWConsistencyMode);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

extern FUNC(void, GPT_PUBLIC_CODE)Gpt_CheckWakeup
    (EcuM_WakeupSourceType wakeupSource);


#endif
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Gpt_ConfigType, GPT_CONST) Gpt_GstConfiguration[];
/* END Msg(4:3684)-1 */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE
#endif  /* GPT_H */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
