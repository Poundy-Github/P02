/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, ICU type definitions, structure data types and  */
/* API function prototypes of ICU Driver                                      */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas.            */
/* Any warranty is expressly disclaimed and excluded by Renesas, either       */
/* expressed or implied, including but not limited to those for               */
/* non-infringement of intellectual property, merchantability                 */
/* and/or fitness for the particular purpose                                  */
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
 * V1.0.0:  16-Sep-2015  : Initial Version.
 * V1.0.1:  04-Nov-2015  : As part of JIRA #ARDAAGA-78,following changes are
 *                         made,
 *                         a. Icu_GetVersionInfo macro is removed since
 *                            Icu_GetVersionInfo is implemented as function.
 *                         b. Added Misra justification for message 4:3458.
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  05-Oct-2016  : #ARDAABD-841
 *                         1. Removed DET codes ICU_E_PARAM_BUFFER_PTR and
 *                            ICU_E_PARAM_CONFIG as per ASR4.2.2
 *                         2. Added DET code ICU_E_PARAM_POINTER
 *                            for null pointer check as per ASR4.2.2
 *                         3. Added DET code ICU_E_INIT_FAILED
 *                            for init failed as per ASR4.2.2
 * V2.0.2:  24-Nov-2016  : #ARDAABD-617
 *                         1. Added ASR4.2.2 and ASR4.0.3 support
 * V2.0.3:  06-Dec-2016  : #ARDAABD-583
 *                         1. Removed DET_REPORTERROR
 * V2.0.4:  12-Dec-2016  : #ARDAABD-583
 *                         1. Changed DET_ICU_E_PARAM_VALUE to ICU_E_PARAM_VALUE
 *                         2. ICU_E_PARAM_VALUE has 0xF4 like in F1L
 * V2.0.5:  16-Mar-2017  : #ARDAABD-1206
 *                         1. Added traceability
 * V2.0.6:  22-Jun-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3476
 *                            a. Mapping of memory section for global or static
 *                               variables are updated as per the AUTOSAR memory
 *                               mapping requirement MEMMAP022.Ref:ARDAABD-908
 *                            b. Copyright information is updated.
 *                         2. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 */
/******************************************************************************/
#ifndef ICU_H
#define ICU_H

/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define ICU_AR_FOUR_ZERO_THREE    403
#define ICU_AR_FOUR_TWO_TWO       422

#define ICU_AR_HIGHER_VERSION     ICU_AR_FOUR_TWO_TWO
#define ICU_AR_LOWER_VERSION      ICU_AR_FOUR_ZERO_THREE

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* ICU_H_067:   ICU219_Conf,    ECUC_Icu_00219 */
/* Included for AUTOSAR standard Type definitions */
#include "Std_Types.h"
/* ICU_H_068:   ICU245, SWS_Icu_00245,  ICU247, SWS_Icu_00247   */
/* Included for Icu_Cfg.h inclusion and To publish the type Icu_ConfigType */
#include "Icu_Types.h"
#include "Icu_RegWrite.h"

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
/* ICU_H_069:   ICU256, SWS_Icu_00256   */
/* ICU_H_070:   ICU190, SWS_Icu_00190   */
/* ICU_H_071:   ICU276, SWS_Icu_00276   */
/* Included for the declaration of EcuM_SetWakeupEvent() */
#include "EcuM_Cbk.h"
#endif
/* ICU_H_076:   ICU274, ICU273, ICU112, ICU002 */
#if (ICU_DEV_ERROR_DETECT == STD_ON)
/* Only in case of DET enabled, Debug variables will be available externally */
#include "Icu_Debug.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* ICU_H_072:   ICU346, SWS_Icu_00346,  ICU182, ICU212, SWS_Icu_00212   */
/* ICU_H_073:   ICU_ESDD_UD_018, ICU_ESDD_UD_201 */
/* ICU_H_075:   ICU221_Conf, ECUC_Icu_00221 */
/*Icu_GetVersionInfo is Implemented as an macro */
/* Vendor and Module IDs */
#define ICU_VENDOR_ID    ICU_VENDOR_ID_VALUE
#define ICU_MODULE_ID    ICU_MODULE_ID_VALUE
#define ICU_INSTANCE_ID  ICU_INSTANCE_ID_VALUE

#if (ICU_AR_VERSION  == ICU_AR_HIGHER_VERSION)
/* AUTOSAR release version information */
#define ICU_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_AR_RELEASE_MINOR_VERSION    2U
#define ICU_AR_RELEASE_REVISION_VERSION 2U
#elif (ICU_AR_VERSION  == ICU_AR_LOWER_VERSION)
/* AUTOSAR specification version information */
#define ICU_AR_RELEASE_MAJOR_VERSION  4U
#define ICU_AR_RELEASE_MINOR_VERSION  0U
#define ICU_AR_RELEASE_REVISION_VERSION  3U
#endif

/* Module Software version information */
#define ICU_SW_MAJOR_VERSION    ICU_SW_MAJOR_VERSION_VALUE
#define ICU_SW_MINOR_VERSION    ICU_SW_MINOR_VERSION_VALUE
#define ICU_SW_PATCH_VERSION    ICU_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

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
/**                      API Service Id Macros                                **
*******************************************************************************/
/* Service ID of Icu_Init */
#define ICU_INIT_SID                        (uint8)0x00
/* Service ID of Icu_DeInit */
#define ICU_DEINIT_SID                      (uint8)0x01
/* Service ID of Icu_SetMode */
#define ICU_SET_MODE_SID                    (uint8)0x02
/* Service ID of Icu_DisableWakeup */
#define ICU_DISABLE_WAKEUP_SID              (uint8)0x03
/* Service ID of Icu_EnableWakeup */
#define ICU_ENABLE_WAKEUP_SID               (uint8)0x04
/* Service ID of Icu_SetActivationCondition */
#define ICU_SET_ACTIVATION_CONDITION_SID    (uint8)0x05
/* Service ID of Icu_DisableNotification */
#define ICU_DISABLE_NOTIFICATION_SID        (uint8)0x06
/* Service ID of Icu_EnableNotification */
#define ICU_ENABLE_NOTIFICATION_SID         (uint8)0x07
/* Service ID of Icu_GetInputState */
#define ICU_GET_INPUT_STATE_SID             (uint8)0x08
/* Service ID of Icu_StartTimestamp */
#define ICU_START_TIMESTAMP_SID             (uint8)0x09
/* Service ID of Icu_StopTimestamp */
#define ICU_STOP_TIMESTAMP_SID              (uint8)0x0A
/* Service ID of Icu_GetTimestampIndex */
#define ICU_GET_TIMESTAMP_INDEX_SID         (uint8)0x0B
/* Service ID of Icu_ResetEdgeCount */
#define ICU_RESET_EDGE_COUNT_SID            (uint8)0x0C
/* Service ID of Icu_EnableEdgeCount */
#define ICU_ENABLE_EDGE_COUNT_SID           (uint8)0x0D
/* Service ID of Icu_DisableEdgeCount */
#define ICU_DISABLE_EDGE_COUNT_SID          (uint8)0x0E
/* Service ID of Icu_GetEdgeNumbers */
#define ICU_GET_EDGE_NUMBERS_SID            (uint8)0x0F
/* Service ID of Icu_GetTimeElapsed */
#define ICU_GET_TIME_ELAPSED_SID            (uint8)0x10
/* Service ID of Icu_GetDutyCycleValues */
#define ICU_GET_DUTY_CYCLE_VALUES_SID       (uint8)0x11
/* Service ID of Icu_GetVersionInfo */
#define ICU_GET_VERSION_INFO_SID            (uint8)0x12
/* Service ID of Icu_StartSignalMeasurement */
#define ICU_START_SIGNAL_MEASUREMENT_SID    (uint8)0x13
/* Service ID of Icu_StopSignalMeasurement */
#define ICU_STOP_SIGNAL_MEASUREMENT_SID     (uint8)0x14
/* Service ID of Icu_CheckWakeup */
#define ICU_CHECK_WAKEUP_SID                (uint8)0x15
/* Service ID of Icu_EnableEdgeDetection */
#define ICU_ENABLE_EDGE_DETECTION_SID       (uint8)0x16
/* Service ID of Icu_DisableEdgeDetection */
#define ICU_DISABLE_EDGE_DETECTION_SID      (uint8)0x17
/* Service ID of Icu_GetInputLevel */
#define ICU_GET_INPUT_LEVEL_SID             (uint8)0x18
/* Service ID of Icu_GetTAUCountValue */
#define ICU_GET_COUNT_VALUE_SID             (uint8)0x19
/* Service Id of Icu_SynchronousInit */
#define ICU_SYNCHRONOUS_INIT_SID            (uint8)0x1A
/* Service Id of Icu_SynchronousStart */
#define ICU_SYNCHRONOUS_START_SID           (uint8)0x1B
/* Service ID of Icu_SynchronousStop */
#define ICU_SYNCHRONOUS_STOP_SID            (uint8)0x1C
/* Service Id of Icu_SynchronousDeInit */
#define ICU_SYNCHRONOUS_DEINIT_SID          (uint8)0x1D
/* Service Id of Icu_CheckHWConsistency */
#define ICU_CHECK_HW_CONSISTENCY_SID        (uint8)0x1E

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
#if (ICU_AR_VERSION == ICU_AR_HIGHER_VERSION)
/* ICU_H_008: ICU_ESDD_UD_202                                                 */
/* ICU_H_009: ICU118, SWS_BSW_00201, ICU001, ICU265, SWS_Icu_00382            */
/* DET code to report a wrong parameter passed to Icu_Init API. */
#define ICU_E_PARAM_POINTER                 (uint8)0x0A
#elif (ICU_AR_VERSION == ICU_AR_LOWER_VERSION)
/* ICU_H_006: ICU_ESDD_UD_070                                                 */
/* ICU_H_007: ICU118, SWS_BSW_00201, ICU001, ICU265, SWS_Icu_00382            */
/* DET code to report a wrong parameter passed to Icu_Init API. */
#define ICU_E_PARAM_CONFIG                  (uint8)0x0A
#endif


/* ICU_H_034: ICU_ESDD_UD_071                                                 */
/* ICU_H_035: ICU118, SWS_BSW_00201, ICU272, SWS_Icu_00382                    */
/*
 * DET code to report that API service used with an invalid Channel Identifier
 * or Channel is not configured for the functionality of the calling API.
 */
#define ICU_E_PARAM_CHANNEL                 (uint8)0x0B

/* ICU_H_036: ICU_ESDD_UD_072                                                 */
/* ICU_H_037: ICU118, SWS_BSW_00201, ICU264, SWS_Icu_00382                    */
/*
 * DET code to report that API service used with an invalid
 * or not feasible activation.
 */
#define ICU_E_PARAM_ACTIVATION              (uint8)0x0C

#if (ICU_AR_VERSION == ICU_AR_HIGHER_VERSION)
/* ICU_H_003: ICU_ESDD_UD_203                                                 */
/* ICU_H_004: ICU118, SWS_BSW_00201, ICU001, ICU265, SWS_Icu_00382            */
  #define ICU_E_INIT_FAILED                 (uint8)0x0D
#elif (ICU_AR_VERSION == ICU_AR_LOWER_VERSION)
/* ICU_H_005: ICU_ESDD_UD_073                                                 */
/* ICU_H_066: ICU118, SWS_BSW_00201, ICU001, ICU265, SWS_Icu_00382            */
  /*
   * DET code to report that API service used with an invalid
   * application-buffer pointer.
   */
  #define ICU_E_PARAM_BUFFER_PTR            (uint8)0x0D
#endif

/* ICU_H_038: ICU_ESDD_UD_074                                                 */
/* DET code to report that API service used with an invalid buffer size. */
#define ICU_E_PARAM_BUFFER_SIZE             (uint8)0x0E

/* ICU_H_039: ICU_ESDD_UD_075                                                 */
/*
 * DET code to report that API service Icu_SetMode used
 * with an invalid operation mode.
 */
#define ICU_E_PARAM_MODE                    (uint8)0x0F

/* ICU_H_040: ICU_ESDD_UD_076                                                 */
/* DET code to report that API service used without module initialization. */
#define ICU_E_UNINIT                        (uint8)0x14

/* ICU_H_041: ICU_ESDD_UD_077                                                 */
/*
 * DET code to report that the API Icu_StopTimestamp used
 * on a channel which was not started or already stopped.
 */
#define ICU_E_NOT_STARTED                   (uint8)0x15

/* ICU_H_042: ICU_ESDD_UD_078                                                 */
/*
 * DET code to report that the API Icu_SetMode used
 * during a running operation.
 */
#define ICU_E_BUSY_OPERATION                (uint8)0x16

/* ICU_H_001: ICU_ESDD_UD_079                                                 */
/* ICU_H_010: ICU118, SWS_BSW_00201, ICU271, SWS_Icu_00382                    */
/*
 * DET code to report that ICU is already initialized
 * when Icu_Init() is called.
 */
#define ICU_E_ALREADY_INITIALIZED           (uint8)0x17

/* ICU_H_043: ICU_ESDD_UD_083                                                 */
/*
 * DET code to report that the API Icu_StartTimeStamp invoked with
 * NotifyInterval < 1.
 */
#define ICU_E_PARAM_NOTIFY_INTERVAL         (uint8)0x18

/* ICU_H_044: ICU_ESDD_UD_155                                                 */
/*
 * Icu_GetVersionInfo invoked with a NULL POINTER is reported using following
 * error code.
 */
#define  ICU_E_PARAM_VINFO                  (uint8)0x19

/* ICU_H_002: ICU_ESDD_UD_080                                                 */
/*
 * API service Icu_Init called without a database is reported using following
 * error code.
 */
#define ICU_E_INVALID_DATABASE              (uint8)0xEF

/* ICU_H_045: ICU_ESDD_UD_081                                                 */
/*
 * DET code to report that Icu API service Icu_DisableNotification
 * is invoked for the channel for which the notification is already disabled.
 */
#define ICU_E_ALREADY_DISABLED              (uint8)0xF1

/* ICU_H_046: ICU_ESDD_UD_082                                                 */
/*
 * DET code to report that Icu API service Icu_EnableNotification
 * is invoked for the channel for which the notification is already enabled.
 */
#define ICU_E_ALREADY_ENABLED               (uint8)0xF2

/* ICU_H_047: ICU_ESDD_UD_163                                                 */
/*
 * DET code to report that ICU Synchronous Init is already initialized
 * when Icu_SynchronousInit() is called.
 */
#define ICU_E_SYNC_ALREADY_STARTED          (uint8)0xF3

/* ICU_H_065: ICU_ESDD_UD_200                                                 */
/* DET code reported when Icu_CheckHWConsistency is called with
* invalid arguments
*/
#define  ICU_E_PARAM_VALUE                  (uint8)0xF4




/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* ICU_H_011: ICU_ESDD_UD_085                                                 */
/* ICU_H_012: ICU278, SWS_Icu_00278                                           */
/* Numeric identifier of an ICU Channel */
typedef uint8 Icu_ChannelType;

/* ICU_H_013: ICU_ESDD_UD_086                                                 */
/* ICU_H_074: ICU279, SWS_Icu_00279                                           */
/* Input state of an ICU channel */
typedef enum ETag_Icu_InputStateType
{
  ICU_ACTIVE,
  ICU_IDLE
} Icu_InputStateType;

/* ICU_H_014: ICU_ESDD_UD_204                                                 */
/* ICU_H_015: EAAR_PN0067_FR_0051                                             */
/* Input level of an ICU channel */
typedef enum ETag_Icu_LevelType
{
  ICU_LOW = 0,
  ICU_HIGH
} Icu_LevelType;

/* ICU_H_016: ICU_ESDD_UD_186                                                 */
/* ICU_H_017: ICU289, SWS_Icu_00289, ICU088, SWS_Icu_00088                    */
/* Definition of the type of activation of an ICU Channel */
typedef enum ETag_Icu_ActivationType
{
  ICU_FALLING_EDGE,
  ICU_RISING_EDGE,
  ICU_BOTH_EDGES
} Icu_ActivationType;

/* ICU_H_018: ICU_ESDD_UD_187                                                 */
/* ICU_H_019: ICU290, SWS_Icu_00290                                           */
/* Width of the buffer for storing time in terms of timer ticks  */
typedef uint32 Icu_ValueType;

/* ICU_H_020: ICU_ESDD_UD_188                                                 */
/* ICU_H_021: ICU291, SWS_Icu_00291                                           */
/* Type which contains the values needed for calculating duty cycles */
typedef struct STag_Icu_DutyCycleType
{
  Icu_ValueType ActiveTime;
  Icu_ValueType PeriodTime;
} Icu_DutyCycleType;

/* ICU_H_022: ICU_ESDD_UD_189                                                 */
/* ICU_H_023: ICU292, SWS_Icu_00292                                           */
/* Type to abstract the return value of the service Icu_GetTimestampIndex() */
typedef uint16 Icu_IndexType;

/* ICU_H_024: ICU_ESDD_UD_190                                                 */
/* ICU_H_025: ICU293, SWS_Icu_00293                                           */
/* Type to abstract the return value of the service Icu_GetEdgeNumbers() */
typedef uint16 Icu_EdgeNumberType;

/* ICU_H_026: ICU_ESDD_UD_194                                                 */
/* ICU_H_027: EAAR_PN0067_FR_0062                                             */
/* Type to abstract the return value of the service Icu_GetTAUCountValue() */
typedef uint32 Icu_CounterValueType;

/* ICU_H_028: ICU_ESDD_UD_191                                                 */
/* ICU_H_029: ICU294, SWS_Icu_00294                                           */
/* Definition of the measurement mode type */
typedef enum ETag_Icu_MeasurementModeType
{
  ICU_MODE_SIGNAL_EDGE_DETECT,
  ICU_MODE_SIGNAL_MEASUREMENT,
  ICU_MODE_TIMESTAMP,
  ICU_MODE_EDGE_COUNTER
} Icu_MeasurementModeType;

/* ICU_H_030: ICU_ESDD_UD_192                                                 */
/* ICU_H_031: ICU295, SWS_Icu_00295, ICU284, SWS_Icu_00284                    */
/* Definition of the signal measurement property type */
typedef enum ETag_Icu_SignalMeasurementPropertyType
{
  ICU_LOW_TIME,
  ICU_HIGH_TIME,
  ICU_PERIOD_TIME,
  ICU_DUTY_CYCLE
} Icu_SignalMeasurementPropertyType;

/* ICU_H_032: ICU_ESDD_UD_193                                                 */
/* ICU_H_033: ICU296, SWS_Icu_00296                                           */
/* Definition of the timestamp measurement property type */
typedef enum ETag_Icu_TimestampBufferType
{
  ICU_LINEAR_BUFFER,
  ICU_CIRCULAR_BUFFER
} Icu_TimestampBufferType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include ICU_MEMMAP_FILE

extern FUNC(void, ICU_PUBLIC_CODE) Icu_Init
(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr);

#if (ICU_DE_INIT_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_DeInit(void);
#endif

#if (ICU_SET_MODE_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_SetMode(Icu_ModeType Mode);
#endif

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_DisableWakeup(Icu_ChannelType Channel);
#endif

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_EnableWakeup(Icu_ChannelType Channel);
#endif

#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && \
                                        (ICU_REPORT_WAKEUP_SOURCE == STD_ON))
extern FUNC(void, ICU_PUBLIC_CODE) Icu_CheckWakeup
(EcuM_WakeupSourceType WakeupSource);
#endif

extern FUNC(void, ICU_PUBLIC_CODE) Icu_SetActivationCondition
(Icu_ChannelType Channel, Icu_ActivationType Activation);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_DisableNotification
(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_EnableNotification
(Icu_ChannelType Channel);

/* ICU_H_060: ICU_ESDD_UD_026, ICU_ESDD_UD_097 */
/* ICU_H_061: ICU238_Conf */
#if (ICU_GET_INPUT_STATE_API == STD_ON)
extern FUNC(Icu_InputStateType, ICU_PUBLIC_CODE) Icu_GetInputState
(Icu_ChannelType Channel);
#endif

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
extern FUNC(Icu_LevelType, ICU_PUBLIC_CODE) Icu_GetInputLevel
(Icu_ChannelType Channel);
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_StartTimestamp(Icu_ChannelType Channel,
P2VAR (Icu_ValueType, AUTOMATIC, ICU_APPL_DATA)BufferPtr,
uint16 BufferSize, uint16 NotifyInterval);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_StopTimestamp (Icu_ChannelType Channel);

extern FUNC(Icu_IndexType, ICU_PUBLIC_CODE) Icu_GetTimestampIndex
(Icu_ChannelType Channel);
#endif

#if (ICU_EDGE_COUNT_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_ResetEdgeCount(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_EnableEdgeCount(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_DisableEdgeCount
(Icu_ChannelType Channel);

extern FUNC(Icu_EdgeNumberType, ICU_PUBLIC_CODE) Icu_GetEdgeNumbers
(Icu_ChannelType Channel);
#endif

#if (ICU_EDGE_DETECT_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_EnableEdgeDetection
(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_DisableEdgeDetection
(Icu_ChannelType Channel);
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_StartSignalMeasurement
(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_StopSignalMeasurement
(Icu_ChannelType Channel);
#endif

#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
extern FUNC(Icu_ValueType, ICU_PUBLIC_CODE) Icu_GetTimeElapsed
(Icu_ChannelType Channel);
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE)
Icu_GetDutyCycleValues(Icu_ChannelType Channel,
P2VAR(Icu_DutyCycleType,  AUTOMATIC, ICU_APPL_DATA) DutyCycleValues);
#endif

#if (ICU_GET_TAU_COUNT_VALUE_API == STD_ON)
extern FUNC(Icu_CounterValueType, ICU_PUBLIC_CODE) Icu_GetTAUInCountValue
(Icu_ChannelType Channel);
#endif

#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_SynchronousInit (void);
extern FUNC(void, ICU_PUBLIC_CODE) Icu_SynchronousStart (void);
extern FUNC(void, ICU_PUBLIC_CODE) Icu_SynchronousStop (void);
extern FUNC(void, ICU_PUBLIC_CODE) Icu_SynchronousDeInit (void);
#endif

#if ( (ICU_TAUDB_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
      (ICU_TAUJ_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
      (ICU_FCLA_RAM_MIRROR == ICU_MIRROR_ENABLE ))
extern FUNC(Std_ReturnType, ICU_PUBLIC_CODE) Icu_CheckHWConsistency
                                  (Icu_HWConsistencyModeType HWConsistencyMode);
#endif

#if (ICU_GET_VERSION_INFO_API == STD_ON)
extern FUNC(void,ICU_PUBLIC_CODE) Icu_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_CONST) versioninfo);
#endif

#define ICU_STOP_SEC_PUBLIC_CODE
#include ICU_MEMMAP_FILE

/******************************************************************************/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include ICU_MEMMAP_FILE
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for ICU Database */
extern CONST(Icu_ConfigType, ICU_CONST) Icu_GstConfiguration[];
/* END Msg(4:3684)-1 */

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include ICU_MEMMAP_FILE

#endif /* ICU_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
