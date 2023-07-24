/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c)  2015-2018 Renesas Electronics Corporation                    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, ADC type definitions, enumerations,             */
/* data types and API function prototypes of ADC Driver.                      */
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
/* Implements EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V1.0.1:  12-Jan-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAAGA-72,
 *                              Macros ADC_CUS_SET_SAMPLING_CLK_SID,
 *                              ADC_GET_PWS_REG16_SID and ADC_GET_PWS_REG32_SID
 *                              are added for service Ids of APIs
 *                              Adc_CusSetSamplingClock,
 *                              Adc_CusGetPWSAnPVCRx_y_16bit and
 *                              Adc_CusGetPWSAnPVCRx_y_32bit respectively.
 *                           2. As a part of JIRA ticket ARDAAGA-72,
 *                              ADC_E_PARAM_SAMPLE_CLK DET error is added.
 *                           3. As a part of JIRA ticket ARDAAGA-72,
 *                              Definitions of macros Adc_GetVersionInfo and
 *                              ADC_DET_REPORTERROR are removed.
 *                           4. As a part of JIRA ticket ARDAAGA-72,
 *                              Declaration for APIs Adc_GetVersionInfo,
 *                              Adc_CusSetSamplingClock,
 *                              Adc_CusGetPWSAnPVCRx_y_16bit and
 *                              Adc_CusGetPWSAnPVCRx_y_32bit are added.
 *                           5. Include section updated.
 *                           6. Unwanted MISRA justification and global data
 *                              types removed.
 * V2.0.0:  19-Aug-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Adc_CheckHWConsistency() API is added.
 * V2.1.0:  28-Oct-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.1.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE
 * V2.1.2:  19-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              added ADC_CHECK_HW_CONSISTENCY_SID
 * V2.2.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage and includes
 * V2.2.1:  27-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Input variable renamed for function
 *                              Adc_CheckHWConsistency().
 * V2.2.2:  27-Jan-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-912,
 *                              Removed unused macro ADC_E_WRONG_CONV_MODE.
 * V2.2.3:  15-Mar-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              Added DET error ADC_E_PARAM_VALUE.
 * V2.2.4:  27-Jun-2018    : Following change made:
 *                            As part of traceability improvement activity
 *                            ticket ARDAABD-2101, requirements and UD Ids are
 *                            added.
 */
/******************************************************************************/
/* ADC_H_022: EAAR_PN0034_FR_0001 */
#ifndef ADC_H
#define ADC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* ADC_H_024: ADC267, SWS_Adc_00267 */
/* Included for Adc type declarations */
#include "Adc_Types.h"
#include "Adc_PBTypes.h"
/* Included to get the pre-compile macros */
#include "Adc_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* ADC_H_019: ADC_ESDD_UD_014 */
#define ADC_VENDOR_ID         ADC_VENDOR_ID_VALUE
#define ADC_MODULE_ID         ADC_MODULE_ID_VALUE
#define ADC_INSTANCE_ID       ADC_INSTANCE_ID_VALUE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
/* AUTOSAR release version information */
#define ADC_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_AR_RELEASE_MINOR_VERSION    2U
#define ADC_AR_RELEASE_REVISION_VERSION 2U
#elif (ADC_AR_VERSION  == ADC_AR_LOWER_VERSION)
/* AUTOSAR specification version information */
#define ADC_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_AR_RELEASE_MINOR_VERSION    0U
#define ADC_AR_RELEASE_REVISION_VERSION 3U
#endif

/* Module Software version information */
#define ADC_SW_MAJOR_VERSION    ADC_SW_MAJOR_VERSION_VALUE
#define ADC_SW_MINOR_VERSION    ADC_SW_MINOR_VERSION_VALUE
#define ADC_SW_PATCH_VERSION    ADC_SW_PATCH_VERSION_VALUE

/* Implements EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
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
**                      API Service Id Macros                                 **
*******************************************************************************/
/* Service Id of Adc_Init */
#define ADC_INIT_SID                        (uint8)0x00
/* Service Id of Adc_DeInit */
#define ADC_DEINIT_SID                      (uint8)0x01
/* Service Id of Adc_StartGroupConversion */
#define ADC_START_GROUP_CONVERSION_SID      (uint8)0x02
/* Service Id of Adc_StopGroupConversion */
#define ADC_STOP_GROUP_CONVERSION_SID       (uint8)0x03
/* Service Id of Adc_ReadGroup */
#define ADC_READ_GROUP_SID                  (uint8)0x04
/* Service Id of Adc_EnableHardwareTrigger */
#define ADC_ENABLE_HARDWARE_TRIGGER_SID     (uint8)0x05
/* Service Id of Adc_DisableHardwareTrigger */
#define ADC_DISABLE_HARDWARE_TRIGGER_SID    (uint8)0x06
/* Service Id of Adc_EnableGroupNotification */
#define ADC_ENABLE_GROUP_NOTIFICATION_SID   (uint8)0x07
/* Service Id of Adc_DisableGroupNotification */
#define ADC_DISABLE_GROUP_NOTIFICATION_SID  (uint8)0x08
/* Service Id of Adc_GetGroupStatus */
#define ADC_GET_GROUP_STATUS_SID            (uint8)0x09
/* Service Id of Adc_GetVersionInfo */
#define ADC_GET_VERSION_INFO_SID            (uint8)0x0A
/* Service Id of Adc_GetStreamLastPointer */
#define ADC_GET_STREAM_LAST_POINTER_SID     (uint8)0x0B
/* Service Id of Adc_SetupResultBuffer */
#define ADC_SETUP_RESULT_BUFFER_SID         (uint8)0x0C
/* Service Id of Adc_EnableHwTrigger */
#define ADC_ENABLE_HW_TRIGGER_SID           (uint8)0x0D
/* Service Id of Adc_DisableHwTrigger */
#define ADC_DISABLE_HW_TRIGGER_SID          (uint8)0x0E
/* Service Id of Adc_HwResultReadGroup */
#define ADC_HW_RESULT_READ_GROUP_SID        (uint8)0x0F
/* Service Id of Adc_DisableChannel */
#define ADC_DISABLE_CHANNEL_SID             (uint8)0x10
/* Service Id of Adc_EnableChannel */
#define ADC_ENABLE_CHANNEL_SID              (uint8)0x11
/* Service Id of Adc_SetThresholds */
#define ADC_SET_THRESHOLD_SID               (uint8)0x12
/* Service Id of Adc_SetChannelThreshold */
#define ADC_SET_CHANNEL_THRESHOLD_SID       (uint8)0x13
/* Service Id of Adc_CusGetADCAnDRmAddr */
#define ADC_CUS_GET_ADCADRADDR_SID          (uint8)0x14
/* Service Id of Adc_EnableIntAdcErr */
#define ADC_ENABLE_ERR_INT_SID              (uint8)0x15
/* Service Id of Adc_DisableIntAdcErr */
#define ADC_DISABLE_ERR_INT_SID             (uint8)0x16
/* Service Id of Adc_CusSetSamplingClock */
#define ADC_CUS_SET_SAMPLING_CLK_SID        (uint8)0x17
/* Service Id of PWSAnPVCRx_y_16bit  */
#define ADC_GET_PWS_REG16_SID               (uint8)0x18
/* Service Id of PWSAnPVCRx_y_32bit */
#define ADC_GET_PWS_REG32_SID               (uint8)0x19
/* Service Id of Adc_CheckHWConsistency */
#define ADC_CHECK_HW_CONSISTENCY_SID        (uint8)0x20
/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* ADC_H_001: ADC229 */
/* ADC_H_002: ADC_ESDD_UD_099 */
/*
 * API service called without module initialization is reported using following
 * error code
 */
#define ADC_E_UNINIT                            (uint8)0x0A

/* ADC_H_004: ADC_ESDD_UD_100 */
/*
 * API services Adc_StartGroupConversion, Adc_EnableHardwareTrigger,
 * Adc_SetupResultBuffer and Adc_DeInit called when the timer
 * is already running is reported using following error code
 */
#define ADC_E_BUSY                              (uint8)0x0B

/* ADC_H_005: ADC_ESDD_UD_101 */
/*
 * API service Adc_StopGroupConversion called while no conversion was running
 * is reported using following error code
 */
#define ADC_E_IDLE                              (uint8)0x0C

/* ADC_H_006: ADC_ESDD_UD_102 */
/*
 * API service Adc_Init called while ADC is already initialized
 * is reported using following error code
 */
#define ADC_E_ALREADY_INITIALIZED               (uint8)0x0D

/* ADC_H_007: ADC_ESDD_UD_103 */
/*
 * API service Adc_Init called with incorrect configuration
 * is reported using following error code
 */
#define ADC_E_PARAM_CONFIG                      (uint8)0x0E

/* ADC_H_008: ADC_ESDD_UD_167 */
/*
 * API service Adc_SetupResultBuffer called with invalid
 * data buffer pointer, NULL_PTR passed
 */
#define ADC_E_PARAM_POINTER                     (uint8)0x14

/* ADC_H_009: ADC_ESDD_UD_106 */
/*
 * API service called with invalid Group ID is reported using following error
 * code
 */
#define ADC_E_PARAM_GROUP                       (uint8)0x15

/* ADC_H_010: ADC_ESDD_UD_107 */
/*
 * API services Adc_EnableHardwareTrigger or Adc_DisableHardwareTrigger called
 * on a group with trigger source configured as software is reported using
 * following error code
 */
#define ADC_E_WRONG_TRIGG_SRC                   (uint8)0x17

/* ADC_H_011: ADC_ESDD_UD_168 */
/*
 * API services Adc_EnableGroupNotification or Adc_DisableGroupNotification
 * called on a group whose configuration set has no notification available is
 * reported using following error code
 */
#define ADC_E_NOTIF_CAPABILITY                  (uint8)0x18

/* ADC_H_012: ADC_ESDD_UD_108 */
/*
 * API services Adc_StartGroupConversion or Adc_EnableHardwareTrigger
 * called on a group whose result buffer pointer not initialized is
 * reported using following error code
 */
#define ADC_E_BUFFER_UNINIT                     (uint8)0x19

/* ADC_H_013: ADC_ESDD_UD_109 */
/*
 * API service Adc_Init called without/with a wrong database is reported using
 * following error code
 */
#define ADC_E_INVALID_DATABASE                  (uint8)0xEF

/* ADC_H_014: ADC_ESDD_UD_113 */
/*
 * API service Adc_DisableChannel and Adc_EnableChannel called with invalid
 * channel is reported using following error code
 */
#define ADC_E_PARAM_CHANNEL                     (uint8)0xEE

/* ADC_H_015: ADC_ESDD_UD_115 */
/*
 * API service Adc_DisableHwTrigger when called with not latest enabled trigger
 * source or invalid trigger source.
 */
#define ADC_E_PARAM_TRIGGSRC                    (uint8)0xED

/* ADC_H_016: ADC_ESDD_UD_116 */
/*
 * API service Adc_EnableHwTrigger and Adc_DisableHwTrigger when called with
 * invalid duty cycle
 */
#define ADC_E_INVALID_DUTY_CYCLE                (uint8)0xF0

/*
 * API service Adc_EnableHwTrigger and Adc_DisableHwTrigger when called with
 * invalid Trigger source
 */
#define ADC_E_INVALID_TRIGG_SOURCE              (uint8)0xF1

/* ADC_H_017: ADC_ESDD_UD_118 */
/*
 * API service Adc_SetThresholds when called with invalid Index.
 */
#define ADC_E_PARAM_INDEX                       (uint8)0xF2
/*
 * API service Adc_SetThresholds when called with invalid ADC Limits.
 */
#define ADC_E_PARAM_LIMIT                       (uint8)0xF3
/*
 * API service Adc_SetThreshold  when called with invalid Thresholds.
 */
#define ADC_E_PARAM_THRESHOLD                   (uint8)0xF4

/* ADC_H_018: ADC_ESDD_UD_119 */
/*
 * API service Adc_EnableIntAdcErr  when called with invalid HW unit.
 */
#define ADC_E_PARAM_HWUNIT                      (uint8)0xF5

/* ADC_H_020: ADC_ESDD_UD_120 */
/*
 * API service Adc_CusSetSamplingClock  when called with invalid Sampling
 * Clock.
 */
#define ADC_E_PARAM_SAMPLE_CLK                  (uint8)0xF6

/* ADC_H_021: ADC_ESDD_UD_121 */
/*
 * API service Adc_CheckHWConsistency when called with invalid Check Type.
 */
#define ADC_E_PARAM_VALUE                       (uint8)0xF7

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/* Declaration of API "Adc_Init". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_Init
(P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) ConfigPtr);

#if (ADC_DEINIT_API == STD_ON)
/* Declaration of API "Adc_DeInit". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_DeInit(void);
#endif

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/* Declaration of API "Adc_StartGroupConversion". */
extern FUNC(void, ADC_PUBLIC_CODE)
Adc_StartGroupConversion(Adc_GroupType Group);

/* Declaration of API "Adc_StopGroupConversion". */
extern FUNC(void, ADC_PUBLIC_CODE)
Adc_StopGroupConversion(Adc_GroupType Group);
#endif


#if (ADC_READ_GROUP_API == STD_ON)
/* Declaration of API "Adc_ReadGroup". */
extern FUNC(Std_ReturnType, ADC_PUBLIC_CODE)
Adc_ReadGroup (Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) DataBufferPtr);
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
/* Declaration of API "Adc_EnableHardwareTrigger". */
extern FUNC(void, ADC_PUBLIC_CODE)
Adc_EnableHardwareTrigger(Adc_GroupType Group);

/* Declaration of API "Adc_DisableHardwareTrigger". */
extern FUNC(void, ADC_PUBLIC_CODE)
Adc_DisableHardwareTrigger(Adc_GroupType Group);
#endif

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/* Declaration of API "Adc_EnableGroupNotification". */
extern FUNC(void, ADC_PUBLIC_CODE)
Adc_EnableGroupNotification(Adc_GroupType Group);

/* Declaration of API "Adc_DisableGroupNotification". */
extern FUNC(void, ADC_PUBLIC_CODE)
Adc_DisableGroupNotification(Adc_GroupType Group);
#endif


/* Declaration of API "Adc_GetGroupStatus". */
extern FUNC(Adc_StatusType, ADC_PUBLIC_CODE)
Adc_GetGroupStatus(Adc_GroupType Group);

/* Declaration of API "Adc_CusGetADCAnDRmAddr". */
extern FUNC(Adc_AddressType, ADC_PUBLIC_CODE) Adc_CusGetADCAnDRmAddr
                                                        (Adc_GroupType Group);
#if (ADC_GETSTREAMLASTPOINTER_API == STD_ON)
/* Declaration of API "Adc_GetStreamLastPointer". */
extern FUNC(Adc_StreamNumSampleType, ADC_PUBLIC_CODE) Adc_GetStreamLastPointer
(Adc_GroupType Group, P2VAR(P2VAR(Adc_ValueGroupType,
AUTOMATIC, ADC_CONFIG_DATA), AUTOMATIC, ADC_CONFIG_DATA) PtrToSamplePtr);
#endif

#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* Declaration of API "Adc_EnableHwTrigger". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_EnableHwTrigger
(Adc_GroupType Group, Adc_HwTriggerTimerType TriggerSource);

/* Declaration of API "Adc_DisableHwTrigger". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_DisableHwTrigger
(Adc_GroupType Group, Adc_HwTriggerTimerType TriggerSource);

/* Declaration of API "Adc_HwResultReadGroup". */
extern FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_HwResultReadGroup
(Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) pDataBuffer);

/*Declaration for the API Adc_CusGetPWSAnPVCRx_y_16bit*/
extern FUNC(uint16, ADC_PUBLIC_CODE) Adc_CusGetPWSAnPVCRx_y_16bit (uint8
                                                              PwmDiagChannelID);
/*Declaration for the API Adc_CusGetPWSAnPVCRx_y_32bit*/
extern FUNC(uint32, ADC_PUBLIC_CODE) Adc_CusGetPWSAnPVCRx_y_32bit (uint8
                                                              PwmDiagChannelID);
#endif

#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
/* Declaration of API "Adc_DisableChannel". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_DisableChannel (Adc_GroupType Group,
Adc_ChannelType ChannelId);

/* Declaration of API "Adc_EnableChannel". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_EnableChannel (Adc_GroupType Group,
Adc_ChannelType ChannelId);
#endif

#if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && (ADC_FLEXIBLE_THRESHOLD == STD_ON))
/* Declaration of API "Adc_SetThreshold". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_SetThreshold (Adc_GroupType Group,
uint8 LucADCAnULLMTBRx, uint16 UpperLimit, uint16 LowerLimit);

/* Declaration of API "Adc_SelectChannelThreshold". */
extern FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_SelectChannelThreshold (
Adc_GroupType Group, Adc_ChannelType AdcChannelId, Adc_ThresholdType Threshold);
#endif


#if (ADC_ERROR_SUPPORT == STD_ON)
/* Declaration of API "Adc_EnableIntAdcErr". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_EnableIntAdcErr (uint8 LucHwunit);
/* Declaration of API "Adc_DisableIntAdcErr". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_DisableIntAdcErr (uint8 LucHwunit);
#endif

/* Declaration of API "Adc_CusSetSamplingClock". */
extern FUNC(void, ADC_PUBLIC_CODE) Adc_CusSetSamplingClock(Adc_HardwareIndexType
                                  HwIndex, Adc_SamplingClockType SamplingClock);

#if (ADC_ENABLE_BUFFER_ALLOCATION == STD_OFF)
/* Declaration of API "Adc_SetupResultBuffer". */
extern FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_SetupResultBuffer
(Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) DataBufferPtr);
#endif

#if (ADC_VERSION_INFO_API == STD_ON)
extern FUNC(void,ADC_PUBLIC_CODE) Adc_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, ADC_APPL_CONST) versioninfo);
#endif

#if ((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))
extern FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_CheckHWConsistency
                                   (Adc_HWConsistencyCheckType LddCheckType);
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

/* Declaration for ADC Database */
/* ADC_H_003: ADC_ESDD_UD_030 */
/* MISRA Violation: START Msg(4:3684)-1  */
extern CONST(Adc_ConfigType, ADC_CONST) Adc_GstConfiguration[];
/* END Msg(4:3684)-1 */

/* ADC_H_023: EAAR_PN0034_NR_0088 */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

#endif /* ADC_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
