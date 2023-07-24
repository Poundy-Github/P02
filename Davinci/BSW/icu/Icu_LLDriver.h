/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_LLDriver.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low level driver function prototypes of the ICU         */
/* Driver                                                                     */
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
 * V1.0.1:  10-Aug-2016  : JIRA #ARDAABD-583
 *                         1. Removed LpChannelConfig from function parameters
 *                            (Icu_HW_EdgeCountingInit, Icu_HW_TimestampInit)
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  26-Nov-2016  : #ARDAABD-841
 *                         1. Removed Icu_HW_Clr_Pnd_Intr declaration because
 *                            ASR3.2.2 was removed, function is not needed
 * V2.0.2:  19-Jun-2018  : Following changes are made:
 *                         1. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 *                         2. Copyright information is updated.
 */
/******************************************************************************/
#ifndef ICU_LLDRIVER_H
#define ICU_LLDRIVER_H

/******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : Number of macro definitions exceeds 1024 - program does not*/
/*                 conform strictly to ISO:C99.                               */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-1 and                           */
/*                 END Msg(4:0857)-1 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Icu.h inclusion and macro definitions */
#include "Icu_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ICU_LLDRIVER_AR_RELEASE_MAJOR_VERSION  ICU_AR_RELEASE_MAJOR_VERSION
#define ICU_LLDRIVER_AR_RELEASE_MINOR_VERSION  ICU_AR_RELEASE_MINOR_VERSION
#define ICU_LLDRIVER_AR_RELEASE_REVISION_VERSION \
                                               ICU_AR_RELEASE_REVISION_VERSION

/* MISRA Violation: START Msg(4:0857)-1 */
/* Module Software version information */
#define ICU_LLDRIVER_SW_MAJOR_VERSION  ICU_SW_MAJOR_VERSION
#define ICU_LLDRIVER_SW_MINOR_VERSION  ICU_SW_MINOR_VERSION
/* END Msg(4:0857)-1 */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include ICU_MEMMAP_FILE

/* ICU_LLDRIVER_H_001: ICU_ESDD_UD_114 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_EdgeCountingInit
(P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig);

/* ICU_LLDRIVER_H_002: ICU_ESDD_UD_115 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_TimestampInit
(P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig);

/* ICU_LLDRIVER_H_003: ICU_ESDD_UD_116 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SignalMeasurementInit
(P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig);

/* ICU_LLDRIVER_H_004: ICU_ESDD_UD_112 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_Init(void);

/* ICU_LLDRIVER_H_005: ICU_ESDD_UD_117 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SetActivation
(Icu_ChannelType Channel, Icu_ActivationType ActiveEdge, uint8 LucSid);

#if (ICU_DE_INIT_API == STD_ON)
/* ICU_LLDRIVER_H_006: ICU_ESDD_UD_113 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_DeInit(void);
#endif

#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)
/* ICU_LLDRIVER_H_007: ICU_ESDD_UD_152 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SynchronousInit (void);
/* ICU_LLDRIVER_H_008: ICU_ESDD_UD_146 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SynchronousStart (void);
/* ICU_LLDRIVER_H_009: ICU_ESDD_UD_147 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SynchronousStop (void);
/* ICU_LLDRIVER_H_010: ICU_ESDD_UD_153 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SynchronousDeInit (void);
#endif

#if (ICU_SET_MODE_API == STD_ON)
/* ICU_LLDRIVER_H_011: ICU_ESDD_UD_118 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SetMode(Icu_ModeType Mode);
#endif

#if (ICU_EDGE_COUNT_API == STD_ON)
#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
/* ICU_LLDRIVER_H_012: ICU_ESDD_UD_122 */
extern FUNC(void, ICU_PRIVATE_CODE)
Icu_HW_ResetEdgeCount(Icu_ChannelType Channel);
#endif
#endif

/* ICU_LLDRIVER_H_013: ICU_ESDD_UD_119 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_StartCountMeasurement
(Icu_ChannelType Channel, uint8 LucSid);

/* ICU_LLDRIVER_H_014: ICU_ESDD_UD_120 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_StopCountMeasurement
(Icu_ChannelType Channel, uint8 LucSid);

/* ICU_LLDRIVER_H_015: ICU_ESDD_UD_121 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_GetEdgeNumbers
(Icu_ChannelType Channel);

/* ICU_LLDRIVER_H_016: ICU_ESDD_UD_123 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_EnableEdgeDetection
(Icu_ChannelType Channel);

/* ICU_LLDRIVER_H_017: ICU_ESDD_UD_132 */
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HW_DisableEdgeDetection
(Icu_ChannelType Channel);


#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/* ICU_LLDRIVER_H_018: ICU_ESDD_UD_137 */
extern FUNC(Icu_LevelType, ICU_PRIVATE_CODE) Icu_HW_GetInputLevel
(Icu_ChannelType Channel);
#endif

#if (ICU_GET_TAU_COUNT_VALUE_API == STD_ON)
/* ICU_LLDRIVER_H_019: ICU_ESDD_UD_142 */
extern FUNC(Icu_CounterValueType, ICU_PRIVATE_CODE) Icu_HW_GetTAUInCountValue
(Icu_ChannelType Channel);
#endif

#if ( (ICU_TAUDB_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
      (ICU_TAUJ_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
      (ICU_FCLA_RAM_MIRROR == ICU_MIRROR_ENABLE ))

/* ICU_LLDRIVER_H_020: ICU_ESDD_UD_167 */
extern FUNC(Std_ReturnType, ICU_PRIVATE_CODE) Icu_HWCheckConsistency
(Icu_HWConsistencyModeType HWConsistencyMode);
#endif

#define ICU_STOP_SEC_PRIVATE_CODE
#include ICU_MEMMAP_FILE

#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* ICU_LLDRIVER_H_021: ICU_ESDD_UD_125 */
extern FUNC(void, ICU_FAST_CODE)Icu_ServiceSignalMeasurement
(Icu_ChannelType Channel);

/* ICU_LLDRIVER_H_022: ICU_ESDD_UD_126 */
extern FUNC(void, ICU_FAST_CODE)Icu_ServiceTimestamp
(Icu_ChannelType Channel, uint32 LulCapturedTimestampVal);

/* ICU_LLDRIVER_H_023: ICU_ESDD_UD_124 */
extern FUNC(void, ICU_FAST_CODE) Icu_TimerIsr(Icu_ChannelType Channel);

/* ICU_LLDRIVER_H_024: ICU_ESDD_UD_127 */
extern FUNC(void, ICU_FAST_CODE) Icu_ExternalInterruptIsr
(Icu_ChannelType Channel);

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

#endif /* ICU_LLDRIVER_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
