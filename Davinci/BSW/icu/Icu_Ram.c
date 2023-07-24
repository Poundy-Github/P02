/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Global variable definitions of ICU Driver               */
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
 *                         1. Modified EcuM_WakeupSourceType to
 *                            Icu_GulWakeupSource
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  06-Dec-2016  : #ARDAABD-583
 *                         1. Minor corrections
 * V2.0.2:  16-Mar-2017  : #ARDAABD-1206
 *                         1. Added Traceability
 * V2.0.3:  25-Sep-2017  : As part of Jira #ARDAABD-2425, QAC WARNING has
 *                         been added.
 * V2.0.4:  11-Jul-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3476
 *                            a. Mapping of memory section for global or static
 *                            variables are updated as per the AUTOSAR memory
 *                            mapping requirement MEMMAP022.Ref:ARDAABD-908.
 *                            b. Copyright information is updated.
 *                         2. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information and other types declarations */
#include "Icu.h"
/* Included for macro definitions */
#include "Icu_PBTypes.h"
/* Included for RAM variable declarations */
#include "Icu_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ICU_RAM_C_AR_RELEASE_MAJOR_VERSION    ICU_AR_RELEASE_MAJOR_VERSION_VALUE
#define ICU_RAM_C_AR_RELEASE_MINOR_VERSION    ICU_AR_RELEASE_MINOR_VERSION_VALUE
#define ICU_RAM_C_AR_RELEASE_REVISION_VERSION \
                                           ICU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ICU_RAM_C_SW_MAJOR_VERSION    ICU_SW_MAJOR_VERSION_VALUE
#define ICU_RAM_C_SW_MINOR_VERSION    ICU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ICU_RAM_AR_RELEASE_MAJOR_VERSION != ICU_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Icu_Ram.c : Mismatch in Release Major Version"
#endif

#if (ICU_RAM_AR_RELEASE_MINOR_VERSION != ICU_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Icu_Ram.c : Mismatch in Release Minor Version"
#endif

#if (ICU_RAM_AR_RELEASE_REVISION_VERSION != \
                                          ICU_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Icu_Ram.c : Mismatch in Release Revision Version"
#endif

#if (ICU_RAM_SW_MAJOR_VERSION != ICU_RAM_C_SW_MAJOR_VERSION)
  #error "Icu_Ram.c : Mismatch in Software Major Version"
#endif

#if (ICU_RAM_SW_MINOR_VERSION != ICU_RAM_C_SW_MINOR_VERSION)
  #error "Icu_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include                    */
/*                 preprocessing directive.                                   */
/* Rule          : MISRA-C:2004 Message 0832                                  */
/* Justification : Required for inclusion of ASR version specific,MemMap file */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */

/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message      : (2:2022) This is a tentative definition and according to    */
/*                the ISO:C Standard, the object will automatically be        */
/*                initialized to zero.                                        */
/* Rule         : MISRA-C:2004 Rule 1.1                                       */
/* Justification: The object's initialisation to zero will not affect the     */
/*                functionality.                                              */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:2022)-2 and                            */
/*                END Msg(2:2022)-2 tags in the code.                         */

/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message      : (2:3211) The global identifier is defined                   */
/*                here but is not used in this translation unit.              */
/* Rule         : MISRA-C:2004 Message 3211                                   */
/* Justification: As per AUTOSAR,all global variables with extern declaration */
/*                shall be given in Adc_Ram.h                                 */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:3211)-3 and                            */
/*                END Msg(2:3211)-3 tags in the code.                         */

/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0862)-4 and               */
/*                 END Msg(2:0862)-4 tags in the code.                        */

/******************************************************************************/
/* 5. QAC Warning:                                                            */
/* Message       : (2:0890) This #include #ifdef refers to a macro that has   */
/*                 been #undef'd in a previous #if block.                     */
/* Rule          : NA                                                         */
/* Justification : This is done for proper memory mapping of code and data    */
/*                 for PWM.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:0890)-5 and              */
/*                 END Msg(2:0890)-5 tags in the code.                        */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:0890)-5 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0890)-5 */
/* END Msg(2:0832)-1 */

/* Implements: ICU_ESDD_UD_168                                                */
/* Implements: EAAR_PN0034_FR_0019                                            */
/* Global pointer variable for channel configuration */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
P2CONST(Icu_ChannelConfigType, ICU_VAR, ICU_CONFIG_CONST) Icu_GpChannelConfig;

/* Implements: ICU_ESDD_UD_169                                                */
/* Global pointer variable for Timer channel configuration */
P2CONST(Icu_TimerChannelConfigType, ICU_VAR, ICU_CONFIG_CONST)
                                                       Icu_GpTimerChannelConfig;
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */

#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) || \
    (ICU_TAUB_UNIT_USED == STD_ON))
/* Implements: ICU_ESDD_UD_170                                                */
/* Global pointer variable for ICU hardware unit configuration */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
P2CONST(Icu_TAUUnitConfigType, ICU_VAR, ICU_CONFIG_CONST) Icu_GpTAUUnitConfig;
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */

#endif

/* Implements: ICU_ESDD_UD_037 */
#if (ICU_PREVIOUS_INPUT_USED == STD_ON)
/* Implements: ICU_ESDD_UD_171                                                */
/* Global pointer variable for Previous input configuration */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
P2CONST(Icu_PreviousInputUseType, ICU_VAR, ICU_CONFIG_CONST)
                                                     Icu_GpPreviousInputConfig;
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */
#endif

#if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
/* Implements: ICU_ESDD_UD_180                                                */
/* Global pointer variable for Wakeup Factor configuration */
P2CONST(Icu_WakeupFactorType, ICU_VAR, ICU_CONFIG_DATA)
                                                  Icu_GpWakeUpFactorRamAddress;
#endif

/* Implements: ICU_ESDD_UD_172                                                */
/* Global pointer variable for channel RAM data */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
P2VAR(Icu_ChannelRamDataType, ICU_NOINIT_DATA, ICU_CONFIG_DATA)
                                                          Icu_GpChannelRamData;

/* Implements: ICU_ESDD_UD_173                                                */
/* Global pointer to the address of Edge Count RAM data */
P2VAR(Icu_EdgeCountChannelRamDataType, ICU_NOINIT_DATA, ICU_CONFIG_DATA)
                                                           Icu_GpEdgeCountData;

/* Implements: ICU_ESDD_UD_174                                                */
/* Global pointer variable for Timestamp channel data */
P2VAR(Icu_TimeStampChannelRamDataType, ICU_NOINIT_DATA, ICU_CONFIG_DATA)
                                                           Icu_GpTimeStampData;

/* Implements: ICU_ESDD_UD_175                                                */
/* Global pointer to the address of Signal Measure RAM data */
P2VAR(Icu_SignalMeasureChannelRamDataType, ICU_NOINIT_DATA, ICU_CONFIG_DATA)
                                                   Icu_GpSignalMeasurementData;

/* Implements: ICU_ESDD_UD_176                                                */
/* Holds the status of ICU Driver Component */
VAR(Icu_ModeType, ICU_NOINIT_DATA) Icu_GenModuleMode;
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */

#if ( ((ICU_TAUD_UNIT_USED  == STD_ON) || (ICU_TAUB_UNIT_USED  == STD_ON)) && \
       (ICU_MIRROR_ENABLE == ICU_TAUDB_RAM_MIRROR ) )
/* Global array to store TAUDBChannelRegMirror data */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(Icu_TAUDBChannelRegMirror, ICU_NOINIT_DATA)
                             Icu_GaaTAUDBChannelRegMirror[ICU_MAX_CHANNEL];
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */
#endif
#if ((ICU_TAUJ_UNIT_USED  == STD_ON) && \
       (ICU_MIRROR_ENABLE == ICU_TAUJ_RAM_MIRROR ) )
/* Global array to store TAUJChannelRegMirror data */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(Icu_TAUJChannelRegMirror, ICU_NOINIT_DATA)
Icu_GaaTAUJChannelRegMirror[ICU_MAX_CHANNEL];
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */
#endif

#if ( (ICU_EDGE_DETECT_API == STD_ON) && \
      (ICU_MIRROR_ENABLE == ICU_FCLA_RAM_MIRROR) )
/* Global array to store FclaRegMirror data */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(Icu_FclaRegsMirror, ICU_NOINIT_DATA) Icu_GaaFclaRegsMirror[ICU_MAX_CHANNEL];
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */
#endif /* End of #if ( (ICU_EDGE_DETECT_API == STD_ON) && \
        *              (ICU_MIRROR_ENABLE) == ICU_FCLA_RAM_MIRROR )
        */
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */


#define ICU_START_SEC_VAR_NO_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:0890)-5 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0890)-5 */
/* END Msg(2:0832)-1 */

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
/* Implements: ICU_ESDD_UD_179                                                */
/* Holds the wake up source information */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(EcuM_WakeupSourceType, ICU_NOINIT_DATA) Icu_GulWakeupSource;
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */

#endif

#define ICU_STOP_SEC_VAR_NO_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-1 */


#define ICU_START_SEC_VAR_INIT_BOOLEAN
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:0890)-5 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0890)-5 */
/* END Msg(2:0832)-1 */

#if (ICU_DEV_ERROR_DETECT == STD_ON)
/* Implements:  ICU_ESDD_UD_177                                               */
/* Holds the status of Initialization */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(boolean, ICU_INIT_DATA) Icu_GblDriverStatus = ICU_UNINITIALIZED;
/* END Msg(2:3211)-3 */

#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)
/* Implements:  ICU_ESDD_UD_178                                               */
/* Status of ICU synchronous initialization */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(boolean, ICU_INIT_DATA) Icu_GblSyncInitStatus = ICU_UNINITIALIZED;
/* Implements:  ICU_ESDD_UD_181                                               */
/* Status of ICU synchronous start */
VAR(boolean, ICU_INIT_DATA) Icu_GblSyncStartStatus = ICU_SYNC_NOTSTARTED;
/* END Msg(2:3211)-3 */
#endif
#endif /* ICU_DEV_ERROR_DETECT == STD_ON */

#define ICU_STOP_SEC_VAR_INIT_BOOLEAN
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:0862)-4 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0862)-4 */
/* END Msg(2:0832)-1 */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
