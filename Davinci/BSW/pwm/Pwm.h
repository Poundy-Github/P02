/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm.h                                                       */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0: 10-Sep-2015  : Initial Version
 * V1.0.1: 02-Dec-2015  : As part of F1K V4.00.01 development activity,
 *                        following changes are made,
 *                        1. As part of the JIRA #ARDAAGA-70, removed
 *                           definitions of macros Pwm_GetVersionInfo and added
 *                           an external call for that as a function.
 * V2.0.0: 19-Oct-2016  : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                           ASR 4.0.3.
 *                        2. JIRA #ARDAABD-877 - Wrong inclusion of Det.h in
 *                           header file Msn.h.
 * V3.0.0: 16-Nov-2016  : 1. JIRA #ARDAABD-565 - Implement FuSa requirements
 *                           for ASIL-B.
 * V3.0.1:  08-Dec-2016 : JIRA ARDAABD-479 - DET error code PWM_E_INIT_FAILED
 *                        added for AR4.2.2
 * V3.0.2:  19-Dec-2016 : JIRA ARDAABD-804 - SID for Pwm_CheckHWConsistency
 *                        changed accordingly to BSWMDT
 *                        Ensure acceptance point regarding Coding Requirements
 * V3.0.3: 17-Mar-2017  : 1. Update for ARDAABD-827 Traceability ticket
 *                        2. Remove unused PWM_E_CHECK_HW_CONSISTENCY DET code
 * V3.0.4: 17-Jun-2017  : MISRA violations are handled
 * V3.1.0: 10-Jul-2017  : As per JIRA ticket #ARDAABD-1726, following changes
 *                        are made:
 *                        1. Extern declaration for Pwm_ControlTriggerOutput
 *                           API is added.
 *                        2. Service Id for PWM_CONTROL_TRIGGER_OUTPUT_SID is
 *                           added.
 * V3.1.1: 18-Jun-2018  : Following changes are made:
 *                        1. As part of merging activity, #ARDAABD-3454
 *                           a. Memory section
 *                              PWM_<START/STOP>_SEC_DBTOC_DATA_UNSPECIFIED is
 *                              removed and mapped the structure
 *                              Pwm_GstConfiguration into
 *                              PWM_<START/STOP>_SEC_CONFIG_DATA_UNSPECIFIED.
 *                              Ref: ARDAABD-908.
 *                           b. Updated Copyright information.
 *                        2. As part of #ARDAABD-3839, traceability tags are
 *                           updated.
 */
/******************************************************************************/
/* PWM_H_029:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0018  */
/* PWM_H_027:  EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0026                       */
#ifndef PWM_H
#define PWM_H
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
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-2 and                           */
/*                 END Msg(4:3458)-2 tags in the code.                        */
/******************************************************************************/
/******************************************************************************/
/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define PWM_AR_FOUR_ZERO_THREE    403
#define PWM_AR_FOUR_TWO_TWO       422

#define PWM_AR_HIGHER_VERSION     PWM_AR_FOUR_TWO_TWO
#define PWM_AR_LOWER_VERSION      PWM_AR_FOUR_ZERO_THREE

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for Type definitions */
/* PWM_H_002:  PWM075a, PWM075b, PWM075c, PWM147                              */
/* PWM_H_003:  SWS_Pwm_10075                                                  */
#include "Std_Types.h"
/* Included for Pwm_Cfg.h inclusion and To publish the type Pwm_ConfigType */
#include "Pwm_Types.h"
#include "Pwm_RegWrite.h"

/* PWM_H_023:  PWM_ESDD_UD_043                                                */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
/*
 * Only in case of DET enabled, Debug variables will be available externally
 */
/* Functionality related to R4.0 and R4.2 */
#include "Pwm_Debug.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Version identification */
/* PWM_H_004:  PWM_ESDD_UD_041                                                */
/* PWM_H_005:  PWM139_Conf, PWM152                                            */
/* PWM_H_006:  ECUC_Pwm_00139                                                 */
#define PWM_VENDOR_ID              PWM_VENDOR_ID_VALUE
#define PWM_MODULE_ID              PWM_MODULE_ID_VALUE
#define PWM_INSTANCE_ID            PWM_INSTANCE_ID_VALUE

/* PWM_H_026:  PWM_ESDD_UD_128, EAAR_PN0066_FR_0045                           */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_AR_RELEASE_MAJOR_VERSION       4
#define PWM_AR_RELEASE_MINOR_VERSION       2
#define PWM_AR_RELEASE_REVISION_VERSION    2

/* PWM_H_001:  PWM_ESDD_UD_129, EAAR_PN0066_FR_0045, PWM029                   */
#elif (PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_AR_RELEASE_MAJOR_VERSION       4
#define PWM_AR_RELEASE_MINOR_VERSION       0
#define PWM_AR_RELEASE_REVISION_VERSION    3
#endif

/* Software module version information */
#define PWM_SW_MAJOR_VERSION       PWM_SW_MAJOR_VERSION_VALUE
#define PWM_SW_MINOR_VERSION       PWM_SW_MINOR_VERSION_VALUE
#define PWM_SW_PATCH_VERSION       PWM_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                     Service Ids                                            **
*******************************************************************************/
/* Service Id of Pwm_Init */
#define PWM_INIT_SID                    (uint8)0x00U

/* Service Id of Pwm_DeInit */
#define PWM_DEINIT_SID                  (uint8)0x01U

/* Service Id of Pwm_SetDutyCycle */
#define PWM_SET_DUTYCYCLE_SID           (uint8)0x02U

/* Service Id of Pwm_SetPeriodAndDuty */
#define PWM_SET_PERIODANDDUTY_SID       (uint8)0x03U

/* Service Id of Pwm_SetOutputToIdle */
#define PWM_SET_OUTPUTTOIDLE_SID        (uint8)0x04U

/* Service Id of Pwm_GetOutputState */
#define PWM_GET_OUTPUTSTATE_SID         (uint8)0x05U

/* Service Id of Pwm_DisableNotification */
#define PWM_DISABLENOTIFICATION_SID     (uint8)0x06U

/* Service Id of Pwm_EnableNotification */
#define PWM_ENABLENOTIFICATION_SID      (uint8)0x07U

/* Service Id of Pwm_GetVersionInfo */
#define PWM_GET_VERSION_INFO_SID        (uint8)0x08U

/* Service Id of Pwm_SelectChannelClk */
#define PWM_SELECT_CHANNEL_CLK_SID      (uint8)0x09U

/* Service Id of Pwm_SetTriggerDelay */
#define PWM_SET_TRIGGER_DELAY_SID       (uint8)0x0AU

/* Service Id of Pwm_SetChannelOutput */
#define PWM_SET_CHANNEL_OUTPUT_SID      (uint8)0x0BU

/* Service Id of Pwm_SynchronousInit */
#define PWM_SYNCHRONOUS_INIT_SID        (uint8)0x0CU

/* Service Id of Pwm_SynchronousStart */
#define PWM_SYNCHRONOUS_START_SID       (uint8)0x0DU

/* Service Id of Pwm_SynchronousStop */
#define PWM_SYNCHRONOUS_STOP_SID        (uint8)0x0EU

/* Service Id of Pwm_CheckHWConsistency */
#define PWM_CHECK_HW_CONSISTENCY_SID    (uint8)0x0FU

/* Service Id of Pwm TAU ISR */
#define PWM_TAU_ISR_SID                 (uint8)0x1EU

/* Service Id of Pwm PWGA ISR */
#define PWM_PWGA_ISR_SID                (uint8)0x1FU

/* Service Id of Pwm_ControlTriggerOutput */
#define PWM_CONTROL_TRIGGER_OUTPUT_SID  (uint8)0x10U

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* PWM_H_007:  PWM_ESDD_UD_084                                                */
/* PWM_H_008:  PWM_ESDD_UD_201                                                */
/* PWM_H_009:  PWM_ESDD_UD_208, PWM_ESDD_UD_188                               */
/* PWM_H_010:  PWM_ESDD_UD_209, PWM_ESDD_UD_184, PWM_ESDD_UD_186              */
/* PWM_H_011:  PWM002a, PWM002b, PWM002c, PWM002d, PWM002e, PWM117, PWM118,   */
/* PWM_H_012:  PWM045, PWM047, PWM151                                         */
/* PWM_H_013:  SWS_Pwm_00201, SWS_Pwm_20002, SWS_Pwm_30002, SWS_Pwm_40002     */
/* PWM_H_014:  SWS_Pwm_50002, SWS_Pwm_00117, SWS_Pwm_00045, SWS_Pwm_00047     */
/* PWM_H_015:  SWS_Pwm_00118                                                  */
/* Pwm_Init API called with wrong parameter */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
#define PWM_E_INIT_FAILED               (uint8)0x10
#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
#define PWM_E_PARAM_CONFIG              (uint8)0x10
#endif

/* When PWM APIs are invoked before PWM Module Initialization */
#define PWM_E_UNINIT                    (uint8)0x11

/* When PWM APIs are invoked with invalid channel identifier */
#define PWM_E_PARAM_CHANNEL             (uint8)0x12

/* Invoking the PWM APIs on PWM channel configured as Fixed period */
#define PWM_E_PERIOD_UNCHANGEABLE       (uint8)0x13

/* Pwm_Init API called when PWM module is already initialized */
#define PWM_E_ALREADY_INITIALIZED       (uint8)0x14

/* When API Pwm_GetVersionInfo service is called with a NULL parameter */
#define PWM_E_PARAM_POINTER             (uint8)0x15

/* PWM_H_016:  PWM_ESDD_UD_085                                                */
/* PWM_H_017:  PWM_ESDD_UD_086                                                */
/* PWM_H_018:  PWM_ESDD_UD_087                                                */
/* PWM_H_019:  PWM_ESDD_UD_088                                                */
/* PWM_H_020:  PWM_ESDD_UD_089                                                */
/* PWM_H_021:  PWM_ESDD_UD_191                                                */
/* PWM_H_022:  EAAR_PN0066_FR_0020, PWM006a, PWM006b                          */
/* Invoking Pwm_EnableNotification API for a channel whose notification is
   already enabled */
#define PWM_E_ALREADY_ENABLED           (uint8)0xEE

/* Invoking Pwm_DisableNotification API for the configured
   channel whose notification is already disabled */
#define PWM_E_ALREADY_DISABLED          (uint8)0xEF

/* When valid Database is not available */
#define PWM_E_INVALID_DATABASE          (uint8)0xF0

/* When PWM APIs are invoked with invalid parameter values */
#define PWM_E_PARAM_VALUE               (uint8)0xF2

/* When Pwm_DisableNotification or Pwm_EnableNotification API are invoked for
   channel with no notification configured */
#define PWM_E_NOTIFY_NOTCONFIG          (uint8)0xF4

/* When Pwm_SynchronousStart API is invoked and PWM module is already
   synchronously started */
#define PWM_E_ALREADY_STARTED           (uint8)0x1A

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* PWM_H_028: EAAR_PN0034_NR_0088, EAAR_PN0034_NR_0087                        */
#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

extern FUNC(void, PWM_PUBLIC_CODE) Pwm_Init
(P2CONST(Pwm_ConfigType, PWM_VAR, PWM_APPL_CONST)ConfigPtr);

#if (PWM_DE_INIT_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_DeInit (void);
#endif

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SetDutyCycle
(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
#endif

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SetPeriodAndDuty
(Pwm_ChannelType ChannelNumber, Pwm_PeriodType  Period, uint16 DutyCycle);
#endif

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SetOutputToIdle
(Pwm_ChannelType ChannelNumber);
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
extern FUNC(Pwm_OutputStateType, PWM_PUBLIC_CODE) Pwm_GetOutputState
(Pwm_ChannelType ChannelNumber);
#endif

/* PWM_H_024:  PWM_ESDD_UD_044                                                */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_EnableNotification
(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);

extern FUNC(void, PWM_PUBLIC_CODE) Pwm_DisableNotification
(Pwm_ChannelType ChannelNumber);
#endif

#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SetTriggerDelay
(Pwm_ChannelType ChannelNumber, uint16 TriggerDelay);
#endif

#if (PWM_SELECT_CHANNEL_CLK_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SelectChannelClk
(Pwm_ChannelType ChannelNumber, Pwm_ClockSourceType ClockSource);
#endif

#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SetChannelOutput
(Pwm_ChannelType ChannelNumber, Pwm_OutputStateType State);
#endif

#if (PWM_SYNC_START_SUPPORT == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SynchronousInit (void);
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SynchronousStart (void);
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SynchronousStop (void);
#endif

#if (PWM_VERSION_INFO_API == STD_ON)
extern FUNC(void,PWM_PUBLIC_CODE) Pwm_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, PWM_APPL_CONST) versioninfo);
#endif

#if ( (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
      (PWM_TAUJ_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
      (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE ))
/* PWM_H_030: PWM094, SWS_Pwm_00094                                           */
extern FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_CheckHWConsistency
                                  (Pwm_HWConsistencyModeType HWConsistencyMode);
#endif

#if ((PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON) &&  \
                                        (PWM_DIAG_UNIT_USED == STD_ON))
extern FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_ControlTriggerOutput
                (Pwm_ChannelType ChannelNumber, Pwm_TriggerControlType Control);
#endif

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* PWM_H_025:  PWM_ESDD_UD_064, PWM140_Conf, ECUC_Pwm_00140                   */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Pwm_ConfigType, PWM_CONST) Pwm_GstConfiguration[];
/* END Msg(4:3684)-1 */

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif  /* PWM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
