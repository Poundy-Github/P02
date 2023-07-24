/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_LLDriver.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of prototypes for internal functions.                            */
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
 * V1.0.0:  10-Sep-2015  : Initial Version
 * V1.0.1:  11-Jan-2016  : As part of F1K V4.00.01 development activity,
 *                         following changes are made,
 *                        1. As part of the AR_PN0066_FR_0092 and JIRA
 *                           #ARDAAGA-187 Pwm_HW_SetDuty_FixedPeriodShifted is
 *                           renamed to Pwm_HW_SetDuty_PeriodShifted.
 * V1.0.2:  18-Aug-2016  : As part of F1K V42.00.00 development activity,
 *                         following changes are made,
 *                         1. As part of JIRA #ARDAABD-441,
 *                            Pwm_GaaChannelIdleStatus was removed. Idle state
 *                            is determined based on Channel Output Register.
 *                            Pwm_HW_GetDiagChannelStatus function added.
 * V2.0.0:  19-Oct-2016  : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                            ASR 4.0.3.
 * V3.0.0:  23-Nov-2016  : 1. JIRA #ARDAABD-565 - Implement FuSa requirements
 *                            for ASIL-B.
 * V3.1.0:  10-Jul-2017  : As per JIRA ticket #ARDAABD-1726, following changes
 *                         are made:
 *                         1. Extern declaration for Pwm_HW_ControlTriggerOutput
 *                            API is added.
 *                         2. Copyright information is updated.
 *                         3. Added global array 'Pwm_GaaDiagChannelMap'
 *                            declaration.
 *                         4. Handled QAC warnings.
 * V3.1.1:  18-Jun-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3454
 *                            a. Memory section
 *                               PWM_<START/STOP>_SEC_VAR_NO_INIT_8 is added for
 *                               Pwm_GaaDiagChannelMap global array.
 *                               Ref: ARDAABD-908.
 *                            b. Updated Copyright information.
 *                         2. As part of jira ticket ARDAABD-3839, added
 *                            traceability tags PWM_LLDRIVER_H_001 to
 *                            PWM_LLDRIVER_H_004.
 * V3.1.2: 12-Apr-2019  : As part of ticket #ARDAABD-4077,
 *                        Following changes are made:
 *                        1. Pwm_HW_CalDiagResetTriggerPoint() API is
 *                         modified. Variable 'LusDiagPeriod' is added.
 *                        2. Declaration for Pwm_HW_GetDiagChannelPeriod 
 *                         API is added.
 *                        3. Copyright information is updated.

 */
/******************************************************************************/
/* PWM_LLDRIVER_H_003: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045               */
/* PWM_LLDRIVER_H_002:  EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0018              */
#ifndef PWM_LLDRIVER_H
#define PWM_LLDRIVER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Pwm.h inclusion and macro definitions */
#include "Pwm_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_LLDRIVER_AR_RELEASE_MAJOR_VERSION PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_LLDRIVER_AR_RELEASE_MINOR_VERSION PWM_AR_RELEASE_MINOR_VERSION
#define PWM_LLDRIVER_AR_RELEASE_REVISION_VERSION \
                                           PWM_AR_RELEASE_REVISION_VERSION

#elif (PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_LLDRIVER_AR_RELEASE_MAJOR_VERSION PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_LLDRIVER_AR_RELEASE_MINOR_VERSION PWM_AR_RELEASE_MINOR_VERSION
#define PWM_LLDRIVER_AR_RELEASE_REVISION_VERSION \
                                           PWM_AR_RELEASE_REVISION_VERSION
#endif

/*  Module software version information */
#define PWM_LLDRIVER_SW_MAJOR_VERSION   PWM_SW_MAJOR_VERSION
#define PWM_LLDRIVER_SW_MINOR_VERSION   PWM_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Array Declarations                             **
*******************************************************************************/
#define PWM_START_SEC_VAR_NO_INIT_8
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
/* PWM_LLDRIVER_H_001: PWM_ESDD_UD_136, EAAR_PN0034_NR_0088                   */
/* Global array to store PwmDiagChannelId data */
extern VAR(uint8, Pwm_NOINIT_DATA)
                          Pwm_GaaDiagChannelMap[PWM_MAX_DIAG_CHANNELS];
#endif /* End of #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON) */

#define PWM_STOP_SEC_VAR_NO_INIT_8
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_Init (void);

#if (PWM_DE_INIT_API == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_DeInit (void);
#endif

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
extern FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetOutputToIdle
(Pwm_ChannelType LddChannelId);
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
extern FUNC (Pwm_OutputStateType, PWM_PRIVATE_CODE) Pwm_HW_GetOutputState
(Pwm_ChannelType LddChannelId);
#endif

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
extern FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetDutyCycle
(Pwm_ChannelType LddChannelId, uint16 LusDutyCycle);

extern FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetDuty_PeriodShifted
(Pwm_ChannelType LddChannelId, uint16 LusDutyCycle);
#endif

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
extern FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetPeriodAndDuty
(Pwm_ChannelType LddChannelId, Pwm_PeriodType  LddPeriod, uint16 LusDutyCycle);
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
extern FUNC (void, PWM_PRIVATE_CODE)Pwm_HW_EnableNotification
(Pwm_ChannelType LddChannelId);

extern FUNC (void, PWM_PRIVATE_CODE)Pwm_HW_DisableNotification
(Pwm_ChannelType LddChannelId);
#endif

#if (PWM_TAU_UNIT_USED == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_Callback
(Pwm_ChannelType LddChannelId);
#endif

#if (PWM_DIAG_UNIT_USED == STD_ON)
extern FUNC (uint16, PWM_PRIVATE_CODE) Pwm_HW_CalDiagResetTriggerPoint
(Pwm_DiagPeriodType LusDutyCycle, uint16 LusOffset, uint16 LusDiagPeriod);
#endif

#if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
extern FUNC (uint16, PWM_PRIVATE_CODE) Pwm_HW_GetDiagChannelPeriod
(uint8 LucPwmShift);
#endif

#if (PWM_TAU_UNIT_USED == STD_ON)
extern FUNC(Pwm_PeriodType, PWM_PRIVATE_CODE) Pwm_HW_CalculateDuty
(Pwm_PeriodType LddAbsolutePeriod, Pwm_PeriodType LddRelativeDuty,
 uint8 LucTAUType);
#endif

#if (PWM_SELECT_CHANNEL_CLK_API == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SelectChannelClk
(Pwm_ChannelType LddChannelId, Pwm_ClockSourceType LddClockSource);
#endif

#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetTriggerDelay
(Pwm_ChannelType LddChannelId, uint16 LusTriggerDelay);
#endif

#if (PWM_DIAG_UNIT_USED == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_StartDiagChannel
(uint8 LucDiagChannel, Dem_EventStatusType LucSid);
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_StopDiagChannel
(uint8 LucDiagChannel, Dem_EventStatusType LucSid);
extern FUNC(uint8, PWM_PRIVATE_CODE) Pwm_HW_GetDiagChannelStatus
(Pwm_ChannelType LddChannelId);
#endif

#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetChannelOutput
(Pwm_ChannelType LddChannelId, Pwm_OutputStateType LddState);
#endif

#if (PWM_DIAG_UNIT_USED == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE)
Pwm_PWGA_Callback(Pwm_ChannelType LddChannelId);
#endif

#if (PWM_SYNC_START_SUPPORT == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SynchronousInit (void);
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SynchronousStart (void);
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SynchronousStop (void);
#endif

#if (PWM_DIAG_UNIT_USED == STD_ON)
extern FUNC(uint16, PWM_PRIVATE_CODE) Pwm_HW_GetPrescalerValue
                                           (Pwm_ClockSourceType LddClockSource);
#endif

#if ( (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
      (PWM_TAUJ_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
      (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE ))
/* PWM_LLDRIVER_H_004: PWM094, SWS_Pwm_00094                                  */
extern FUNC(Std_ReturnType, PWM_PRIVATE_CODE) Pwm_HW_CheckHWConsistency
                                  (Pwm_HWConsistencyModeType HWConsistencyMode);
#endif

#if ((PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON) &&  \
                                        (PWM_DIAG_UNIT_USED == STD_ON))
extern FUNC(Std_ReturnType, PWM_PRIVATE_CODE) Pwm_HW_ControlTriggerOutput
                 (Pwm_ChannelType LddChannelId, Pwm_TriggerControlType LddCtl);
#endif

#define PWM_STOP_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif /* PWM_LLDRIVER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
