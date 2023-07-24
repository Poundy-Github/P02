/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Types.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
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
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  16-Mar-2017  : #ARDAABD-1206
 *                         1. Added traceability
 * V2.0.2:  22-Jun-2018  : Following changes are made:
 *                         1. Storage specifier for configuration data
 *                            variables is changed from AUTOMATIC to TYPEDEF,
 *                            since it is allocated in ROM. Ref:ARDAABD-894
 *                         2. Copyright information is updated.
 *                         3. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 */
/******************************************************************************/
#ifndef ICU_TYPES_H
#define ICU_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* ICU_TYPES_H_013: ICU247, SWS_Icu_00247   */
/* ICU_TYPES_H_014: ICU245, SWS_Icu_00245   */
/* Included for pre-compile options */
#include "Icu_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define ICU_TYPES_AR_RELEASE_MAJOR_VERSION       ICU_AR_RELEASE_MAJOR_VERSION
#define ICU_TYPES_AR_RELEASE_MINOR_VERSION       ICU_AR_RELEASE_MINOR_VERSION
#define ICU_TYPES_AR_RELEASE_REVISION_VERSION    ICU_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define ICU_TYPES_SW_MAJOR_VERSION   ICU_SW_MAJOR_VERSION
#define ICU_TYPES_SW_MINOR_VERSION   ICU_SW_MINOR_VERSION

/******************************************************************************/

/* ICU_TYPES_H_001: ICU_ESDD_UD_185                                           */
/* ICU_TYPES_H_002: ICU280, SWS_Icu_00280, ICU281, SWS_Icu_00281              */
/* ICU_TYPES_H_003: ICU039, SWS_Icu_00039, ICU283, SWS_Icu_00283              */
/* ICU_TYPES_H_004: ICU084, SWS_Icu_00084, ICU285, SWS_Icu_00285              */
/* ICU_TYPES_H_005: ICU378, SWS_Icu_00378, ICU286, SWS_Icu_00286              */
/* ICU_TYPES_H_006: ICU287, SWS_Icu_00287, ICU288, SWS_Icu_00288              */
/* ICU_TYPES_H_010: ICU_ESDD_UD_054                                           */
/* Data Structure for ICU for Initializing the ICU Module */
typedef struct STag_Icu_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  /* Pointer to ICU driver channel configuration */
  P2CONST(void, TYPEDEF, ICU_CONFIG_CONST) pChannelConfig;
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) || \
  (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer to ICU driver Timer channel configuration */
  P2CONST(void, TYPEDEF, ICU_CONFIG_CONST) pTimerChannelConfig;
  /* Pointer to ICU hardware unit configuration */
  P2CONST(void, TYPEDEF, ICU_CONFIG_CONST) pHWUnitConfig;
  #endif

  /* ICU_TYPES_H_012: ICU_ESDD_UD_037 */
  #if (ICU_PREVIOUS_INPUT_USED == STD_ON)
  /* Pointer to Previous input configuration */
  P2CONST(void, TYPEDEF, ICU_CONFIG_CONST) pPrevInputConfig;
  #endif
  #if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
  /* Pointer to the address of WUF register */
  P2CONST(void, TYPEDEF, ICU_CONFIG_DATA) pWakeUpFactorRamAddress;
  #endif
  /* Pointer to the address of internal RAM data */
  P2VAR (void, TYPEDEF, ICU_CONFIG_DATA) pRamAddress;
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) || \
  (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer to the address of Signal Measure RAM data */
  P2VAR (void, TYPEDEF, ICU_CONFIG_DATA) pSignalMeasureAddress;
  /* Pointer to the address of TimeStamp RAM data */
  P2VAR (void, TYPEDEF, ICU_CONFIG_DATA) pTimeStampAddress;
  /* Pointer to the address of Edge Count RAM data */
  P2VAR (void, TYPEDEF, ICU_CONFIG_DATA) pEdgeCountRamAddress;
  #endif
} Icu_ConfigType;


/* ICU_TYPES_H_007: ICU_ESDD_UD_084                                           */
/* ICU_TYPES_H_008: ICU258, SWS_Icu_00258, ICU277, SWS_Icu_00277              */
/* ICU_TYPES_H_011: ICU_ESDD_UD_197                                           */
/* Operation Mode of the ICU Module */
typedef enum ETag_Icu_ModeType
{
  ICU_MODE_NORMAL,
  ICU_MODE_SLEEP
} Icu_ModeType;


/* Type definition for Icu_HWConsistencyModeType */
/* ICU_TYPES_H_009: ICU_ESDD_UD_221 */
typedef enum ETag_Icu_HWConsistencyModeType
{
  ICU_STATIC = 0,
  ICU_DYNAMIC
}Icu_HWConsistencyModeType;

#endif /* ICU_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
