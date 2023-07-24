/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Global variable declarations of ICU Driver              */
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
 * V1.0.1:  02-Jun-2016  : #ARDAABD-426
 *                         1. Modified wakeup sources to EcuM_WakeupSourceType
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  24-Nov-2016  : #ARDAABD-617
 *                         1. Expanded INTP Ram Mirror array for all channels
 * V2.0.2:  06-Dec-2016  : #ARDAABD-583
 *                         1. Minor corrections
 * V2.0.3:  12-Apr-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3476
 *                            a. Mapping of memory section for global or static
 *                               variables are updated as per the AUTOSAR memory
 *                               mapping requirement MEMMAP022.Ref:ARDAABD-908
 *                            b. Copyright information is updated.
 *
 */
/******************************************************************************/
#ifndef ICU_RAM_H
#define ICU_RAM_H

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
#include "Icu.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ICU_RAM_AR_RELEASE_MAJOR_VERSION     ICU_AR_RELEASE_MAJOR_VERSION
#define ICU_RAM_AR_RELEASE_MINOR_VERSION     ICU_AR_RELEASE_MINOR_VERSION
#define ICU_RAM_AR_RELEASE_REVISION_VERSION  ICU_AR_RELEASE_REVISION_VERSION

/* MISRA Violation: START Msg(4:0857)-1 */
/* Module Software version information */
#define ICU_RAM_SW_MAJOR_VERSION    ICU_SW_MAJOR_VERSION
#define ICU_RAM_SW_MINOR_VERSION    ICU_SW_MINOR_VERSION
/* END Msg(4:0857)-1 */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include ICU_MEMMAP_FILE

/* Global pointer variable for channel configuration */
extern P2CONST(Icu_ChannelConfigType, ICU_VAR, ICU_CONFIG_CONST)
                                                        Icu_GpChannelConfig;

/* Global pointer variable for Timer channel configuration */
extern P2CONST(Icu_TimerChannelConfigType, ICU_VAR, ICU_CONFIG_CONST)
                                                   Icu_GpTimerChannelConfig;

#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) || \
    (ICU_TAUB_UNIT_USED == STD_ON))
/* Global pointer variable for ICU hardware unit configuration */
extern P2CONST(Icu_TAUUnitConfigType, ICU_VAR, ICU_CONFIG_CONST)
                                                        Icu_GpTAUUnitConfig;
#endif

/* ICU_RAM_H_001: ICU_ESDD_UD_037 */
#if (ICU_PREVIOUS_INPUT_USED == STD_ON)
/* Global pointer variable for Previous input configuration */
extern P2CONST(Icu_PreviousInputUseType, ICU_VAR, ICU_CONFIG_CONST)
                                                  Icu_GpPreviousInputConfig;
#endif

#if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
/* Global pointer variable for Wakeup Factor configuration */
extern P2CONST(Icu_WakeupFactorType, ICU_VAR, ICU_CONFIG_DATA)
                                                  Icu_GpWakeUpFactorRamAddress;
#endif

/* Global pointer variable for channel RAM data */
extern P2VAR(Icu_ChannelRamDataType, ICU_NOINIT_DATA, ICU_CONFIG_DATA)
                                                       Icu_GpChannelRamData;

/* Global pointer to the address of Edge Count RAM data */
extern P2VAR(Icu_EdgeCountChannelRamDataType, ICU_NOINIT_DATA,
                                       ICU_CONFIG_DATA) Icu_GpEdgeCountData;

/* Global pointer variable for Timestamp channel RAM data */
extern P2VAR(Icu_TimeStampChannelRamDataType, ICU_NOINIT_DATA,
                                       ICU_CONFIG_DATA) Icu_GpTimeStampData;

/* Global pointer to the address of Signal Measure RAM data */
extern P2VAR(Icu_SignalMeasureChannelRamDataType, ICU_NOINIT_DATA,
                               ICU_CONFIG_DATA) Icu_GpSignalMeasurementData;

#if ( ((ICU_TAUD_UNIT_USED  == STD_ON) || (ICU_TAUB_UNIT_USED  == STD_ON)) && \
       (ICU_MIRROR_ENABLE == ICU_TAUDB_RAM_MIRROR ) )
/* Global array to store TAUDBChannelRegMirror data */
extern VAR(Icu_TAUDBChannelRegMirror, ICU_NOINIT_DATA)
                                Icu_GaaTAUDBChannelRegMirror[ICU_MAX_CHANNEL];
#endif

#if ((ICU_TAUJ_UNIT_USED  == STD_ON) && \
       (ICU_MIRROR_ENABLE == ICU_TAUJ_RAM_MIRROR ) )
/* Global array to store TAUJChannelRegMirror data */
extern VAR(Icu_TAUJChannelRegMirror, ICU_NOINIT_DATA)
                                Icu_GaaTAUJChannelRegMirror[ICU_MAX_CHANNEL];
#endif

#if ( (ICU_EDGE_DETECT_API == STD_ON) && \
      (ICU_MIRROR_ENABLE == ICU_FCLA_RAM_MIRROR) )
/* Global array to store FclaRegMirror data */
extern VAR(Icu_FclaRegsMirror, ICU_NOINIT_DATA)
                                Icu_GaaFclaRegsMirror[ICU_MAX_CHANNEL];
#endif /* End of #if ( (ICU_EDGE_DETECT_API == STD_ON) && \
        *              (ICU_MIRROR_ENABLE == ICU_FCLA_RAM_MIRROR) )
        */


/* Holds the status of ICU Driver Component */
extern VAR(Icu_ModeType, ICU_NOINIT_DATA) Icu_GenModuleMode;

#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include ICU_MEMMAP_FILE

#define ICU_START_SEC_VAR_NO_INIT_32
#include ICU_MEMMAP_FILE
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
/* Holds the wake up source information */
extern VAR(EcuM_WakeupSourceType, ICU_NOINIT_DATA) Icu_GulWakeupSource;
#endif
#define ICU_STOP_SEC_VAR_NO_INIT_32
#include ICU_MEMMAP_FILE

#define ICU_START_SEC_VAR_INIT_BOOLEAN
#include ICU_MEMMAP_FILE
#if (ICU_DEV_ERROR_DETECT == STD_ON)
/* Holds the status of Initialization */
extern VAR(boolean, ICU_INIT_DATA) Icu_GblDriverStatus;
#endif

#if ((ICU_SYNC_START_STOP_SUPPORT == STD_ON) \
         && (ICU_DEV_ERROR_DETECT == STD_ON))
/* Status of ICU synchronous initialization */
extern VAR(boolean, ICU_INIT_DATA) Icu_GblSyncInitStatus;
#endif

#if ((ICU_SYNC_START_STOP_SUPPORT == STD_ON) \
         && (ICU_DEV_ERROR_DETECT == STD_ON))
/* Status of ICU synchronous start */
extern VAR(boolean, ICU_INIT_DATA) Icu_GblSyncStartStatus;
#endif
#define ICU_STOP_SEC_VAR_INIT_BOOLEAN
#include ICU_MEMMAP_FILE

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ICU_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
