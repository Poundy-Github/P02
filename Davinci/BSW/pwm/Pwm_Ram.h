/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global variable declarations.                                              */
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
 * V1.0.1:  09-Aug-2016  : As part of F1K V42.00.00 development activity,
 *                         the following changes are made:
 *                         1. As part of JIRA #ARDAABD-441,
 *                            Pwm_GaaChannelIdleStatus was removed. Idle state
 *                            is determined based on Channel Output Register.
 * V2.0.0:  19-Oct-2016  : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                            ASR 4.0.3.
 * V3.0.0: 23-Nov-2016   : 1. JIRA #ARDAABD-565 - Implement FuSa requirements
 *                            for ASIL-B.
 * V3.1.0: 10-Jul-2017   : As per JIRA ticket #ARDAABD-1726, following changes
 *                         are made:
 *                         1. Extern declaration for variables Pwm_GulGroup0,
 *                            Pwm_GulGroup1 and Pwm_GulGroup2 are added.
 *                         2. Copyright information is updated.
 *                         3. Added global structure 'Pwm_GstPwgaINTFMaskMirror'
 * V3.1.1: 22-Aug-2017   : As per JIRA ticket #ARDAABD-1726, following changes
 *                         are made:
 *                         1. Added PWM_START_SEC_VAR_NOINIT_32 and
 *                            PWM_STOP_SEC_VAR_NOINIT_32 sections.
 * V3.1.2: 18-Jun-2018   : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3454
 *                            a. Following memory sections are renamed,
 *                               PWM_<START/STOP>_SEC_VAR_NOINIT_UNSPECIFIED to
 *                               PWM_<START/STOP>_SEC_VAR_NO_INIT_UNSPECIFIED,
 *                               PWM_<START/STOP>_SEC_VAR_NOINIT_32 to
 *                               PWM_<START/STOP>_SEC_VAR_NO_INIT_32,
 *                               PWM_<START/STOP>_SEC_VAR_NOINIT_16 to
 *                               PWM_<START/STOP>_SEC_VAR_NO_INIT_16,
 *                               PWM_<START/STOP>_SEC_VAR_NOINIT_8 to
 *                               PWM_<START/STOP>_SEC_VAR_NO_INIT_8 and
 *                               PWM_<START/STOP>_SEC_VAR_BOOLEAN to
 *                               PWM_<START/STOP>_SEC_VAR_INIT_BOOLEAN.
 *                               Ref: ARDAABD-908.
 *                            b. Updated Copyright information.
 *                         2. As per JIRA ticket ARDAABD-1627, pre-compile
 *                            switch PWM_SELB_INTC2_SUPPORT is added for
 *                            Pwm_GusIntSelRegMask variable.
 *                         3. As per JIRA ticket ARDAABD-3839, added
 *                            PWM_RAM_H_001 to PWM_RAM_H_003.
 */
/******************************************************************************/
/* PWM_RAM_H_002:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045                   */
/* PWM_RAM_H_001:  EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0018                   */
#ifndef PWM_RAM_H
#define PWM_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_RAM_AR_RELEASE_MAJOR_VERSION      PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_RAM_AR_RELEASE_MINOR_VERSION      PWM_AR_RELEASE_MINOR_VERSION
#define PWM_RAM_AR_RELEASE_REVISION_VERSION   PWM_AR_RELEASE_REVISION_VERSION

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_RAM_AR_RELEASE_MAJOR_VERSION      PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_RAM_AR_RELEASE_MINOR_VERSION      PWM_AR_RELEASE_MINOR_VERSION
#define PWM_RAM_AR_RELEASE_REVISION_VERSION   PWM_AR_RELEASE_REVISION_VERSION
#endif /* End of PWM_AR_VERSION */

/* Software module version information */
#define PWM_RAM_SW_MAJOR_VERSION    PWM_SW_MAJOR_VERSION
#define PWM_RAM_SW_MINOR_VERSION    PWM_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Variables                                      **
*******************************************************************************/
/* PWM_RAM_H_003:  PWM145                                                     */
#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#if ((PWM_TAUD_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON))
/* Global pointer variable for TAUD/TAUB Unit configuration */
extern P2CONST(Pwm_TAUDBUnitConfigType, PWM_VAR, PWM_CONFIG_CONST)
Pwm_GpTAUDBUnitConfig;

#if (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE)
/* Global array to store TAUDBChannelRegMirror data */
extern VAR(Pwm_TAUDBChannelRegMirrorType, Pwm_NOINIT_DATA)
                  Pwm_GaaTAUDBChannelRegMirror[PWM_TOTAL_TAUDB_CHANNELS_CONFIG];
/* Global array to store TAUDBUserRegMirror data */
extern VAR(Pwm_TAUDBUserRegMirrorType, Pwm_NOINIT_DATA)
                  Pwm_GaaTAUDBUserRegMirror[PWM_TOTAL_TAUDB_UNITS_CONFIG];
#endif /* #if (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE) */

#endif

#if (PWM_TAUJ_UNIT_USED == STD_ON)
/* Global pointer variable for TAUJ Unit configuration */
extern P2CONST(Pwm_TAUJUnitConfigType, PWM_VAR, PWM_CONFIG_CONST)
Pwm_GpTAUJUnitConfig;

#if (PWM_TAUJ_RAM_MIRROR == PWM_MIRROR_ENABLE)
/* Global array to store TAUJChannelRegMirror data */
extern VAR(Pwm_TAUJChannelRegMirrorType, PWM_NOINIT_DATA)
                    Pwm_GaaTAUJChannelRegMirror[PWM_TOTAL_TAUJ_CHANNELS_CONFIG];
/* Global array to store TAUJUserRegMirror data */
extern VAR(Pwm_TAUJUserRegMirrorType, PWM_NOINIT_DATA)
                    Pwm_GaaTAUJUserRegMirror[PWM_TOTAL_TAUJ_UNITS_CONFIG];
#endif /* #if (PWM_TAUJ_RAM_MIRROR == PWM_MIRROR_ENABLE) */

#endif

#if (PWM_TAU_UNIT_USED == STD_ON)
/* Global pointer variable for channel configuration */
extern P2CONST(Pwm_ChannelConfigType, PWM_VAR, PWM_CONFIG_CONST)
Pwm_GpChannelConfig;
#endif

#if (PWM_DIAG_UNIT_USED  == STD_ON)
/* Global pointer variable for PWGA Unit configuration */
extern P2CONST(Pwm_DiagUnitConfigType, PWM_VAR, PWM_CONFIG_CONST)
Pwm_GpDiagUnitConfig;

/* Global pointer variable for PWGA channel configuration */
extern P2CONST(Pwm_DiagChannelConfigType, PWM_VAR, PWM_CONFIG_CONST)
Pwm_GpDiagChannelConfig;

#if (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE)
/* Global array to store PwgaRegMirror data */
extern VAR(Pwm_PwgaRegsMirrorType, Pwm_NOINIT_DATA)
                          Pwm_GaaPwgaRegsMirror[PWM_TOTAL_DIAG_CHANNELS_CONFIG];

 #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
 /* Global structure to store PwgaINTFMaskMirror data */
 extern VAR(Pwm_PwgaINTFMaskMirrorType, Pwm_NOINIT_DATA)
                          Pwm_GstPwgaINTFMaskMirror;
 #endif
#endif /* End of #if (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE) */
#endif

#if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))
/* Global array to store Idle state status of configured channels */
extern VAR(Pwm_OutputStateType, PWM_NOINIT_DATA)
Pwm_GaaChannelConstantState[PWM_TOTAL_DIAG_CHANNELS_CONFIG];
#endif

#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#define PWM_START_SEC_VAR_NO_INIT_32
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#if ((PWM_DIAG_UNIT_USED == STD_ON) &&(PWM_PERIOD_SELECTION_SUPPORT == STD_ON))
extern VAR(uint32, PWM_NOINIT_DATA) Pwm_GulGroup0;
extern VAR(uint32, PWM_NOINIT_DATA) Pwm_GulGroup1;
extern VAR(uint32, PWM_NOINIT_DATA) Pwm_GulGroup2;
#endif

#define PWM_STOP_SEC_VAR_NO_INIT_32
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#define PWM_START_SEC_VAR_NO_INIT_16
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#if (PWM_DIAG_UNIT_USED == STD_ON)
/* Global array to store CRDR restore value of configured PWGA channels */
extern VAR(uint16, PWM_NOINIT_DATA)
Pwm_GaaChannelCRDRRestoreVal[PWM_TOTAL_DIAG_CHANNELS_CONFIG];
/* Global array to store CSDR restore value of configured PWGA channels */
extern VAR(uint16, PWM_NOINIT_DATA)
Pwm_GaaChannelCSDRRestoreVal[PWM_TOTAL_DIAG_CHANNELS_CONFIG];
#endif

#if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_SELECT_CHANNEL_CLK_API == STD_ON))
/* Global array to store current duty cycle of configured PWGA channels */
extern VAR(uint16, PWM_NOINIT_DATA)
Pwm_GaaChannelCurrDutyCycle[PWM_TOTAL_DIAG_CHANNELS_CONFIG];
#endif

#if (PWM_DIAG_UNIT_USED == STD_ON)
extern VAR(uint16, PWM_NOINIT_DATA)
Pwm_GaaDCBoundaryFlag[PWM_TOTAL_DIAG_CHANNELS_CONFIG];
/* Global variable to store CSDR value for PWGA channel when duty cycle is set
   to 0% or 100% */
extern VAR(uint16, PWM_NOINIT_DATA) Pwm_GaaPWGACSDR
                                    [PWM_TOTAL_DIAG_CHANNELS_CONFIG];
/* Global variable to store CRDR value for PWGA channel when duty cycle is set
   to 0% or 100% */
extern VAR(uint16, PWM_NOINIT_DATA) Pwm_GaaPWGACRDR
                                    [PWM_TOTAL_DIAG_CHANNELS_CONFIG];
#endif /* End of #if (PWM_DIAG_UNIT_USED == STD_ON) */

#if (PWM_DIAG_UNIT_USED == STD_ON)
#if (PWM_SELB_INTC2_SUPPORT == STD_ON)
extern VAR(uint16, PWM_NOINIT_DATA) Pwm_GusIntSelRegMask;
#endif
#endif

#define PWM_STOP_SEC_VAR_NO_INIT_16
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#define PWM_START_SEC_VAR_NO_INIT_8
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/* Global array to store Idle state status of configured channels */
extern VAR(uint8, PWM_NOINIT_DATA)
Pwm_GaaChannelConstantStatus [PWM_TOTAL_PWM_CHANNELS_CONFIG];
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/* Array for Notification status of timers configured */
extern VAR(uint8, PWM_NOINIT_DATA)
Pwm_GaaNotifStatus[PWM_TOTAL_PWM_CHANNELS_CONFIG];
#endif

#define PWM_STOP_SEC_VAR_NO_INIT_8
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#define PWM_START_SEC_VAR_INIT_BOOLEAN
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
/* Status of PWM Driver initialization */
extern VAR(boolean, PWM_INIT_DATA) Pwm_GblDriverStatus;
#endif

#if ((PWM_SYNC_START_SUPPORT == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
/* Status of PWM synchronous initialization */
extern VAR(boolean, PWM_INIT_DATA) Pwm_GblSyncInitStatus;
#endif
/* Status of PWM synchronous start status */
#if (PWM_SYNC_START_SUPPORT == STD_ON)
extern VAR(boolean, PWM_INIT_DATA) Pwm_GblSyncStartStatus;
#endif

#define PWM_STOP_SEC_VAR_INIT_BOOLEAN
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

#endif  /* PWM_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
