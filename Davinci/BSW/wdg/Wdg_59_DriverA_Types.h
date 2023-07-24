/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Types.h                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
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
 * V1.0.0:  03-Sep-2015    : Initial Version
 * V2.0.0   25-Aug-2016    : Changed according to #ARDAABD-653
 *                           1. ASR 3.2.2 was removed and 4.2.2 added
 * V2.0.1   26-Oct-2016    : Version Fix
 * V2.0.2   16-Jan-2016    : Wdg_59_DriverA_HWConsistencyModeType was added
 * V2.0.3   27-Jan-2017    : RAM Mirroring check was updated
 * V2.0.4   31-Jan-2017    : Inclusion of Wdg_59_DriverA.h was removed.
 * V2.0.5   09-Jul-2018    : 1. #ARDAABD-1207
 *                           Traceability update
 *                           2. As part #ARDAABD-3905, traceability
 *                            has been updated by mapping respective
 *                            WDG_ESDD_UD IDs.
 *                           3. As part of JIRA ARDAABD-3881, following changes
 *                              are made:
 *                           a. Copyright information updated.
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_TYPES_H
#define WDG_59_DRIVERA_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for declaration of type WdgIf_ModeType */
#include "WdgIf_Types.h"
/* Included for pre-compile options */
#include "Wdg_59_DriverA_Cfg.h"
/* Included for RAM Mirroring and Write Verify */
#include "Wdg_59_DriverA_RegWrite.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_TYPES_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_TYPES_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_TYPES_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERA_TYPES_SW_MAJOR_VERSION   WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_TYPES_SW_MINOR_VERSION   WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Structure declarations                                **
*******************************************************************************/
/* WDG_59_DRIVERA_TYPES_H_001: WDG171, SWS_Wdg_00171                          */
/* WDG_59_DRIVERA_TYPES_H_002: BSW00414                                       */
/* WDG_59_DRIVERA_TYPES_H_003: SRS_BSW_00414                                  */
/* WDG_59_DRIVERA_TYPES_H_004: WDG_ESDD_UD_039                                */

typedef struct STag_Wdg_59_DriverA_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  /* Functionality related to R4.0 and R4.2 */
  /* Value of Timer Counter for Default mode */
  uint16 usInitTimerCountValue;
  /* Value of 75% interrupt time for SLOW mode in msec */
  uint16 usSlowTimeValue;
  /* Value of 75% interrupt time for FAST mode in msec */
  uint16 usFastTimeValue;
  /* Value of WDTAMD register for SLOW mode */
  uint8 ucWdtamdSlowValue;
  /* Value of WDTAMD register for FAST mode */
  uint8 ucWdtamdFastValue;
  /* Value of WDTAMD register for Default mode */
  uint8 ucWdtamdDefaultValue;
  /* Configured Default mode */
  WdgIf_ModeType ddWdtamdDefaultMode;
}Wdg_59_DriverA_ConfigType;


#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

/* Type definition for the current state of Watchdog Driver */
typedef enum ETag_Wdg_59_DriverA_StatusType
{
  WDG_59_DRIVERA_UNINIT,
  WDG_59_DRIVERA_IDLE,
  WDG_59_DRIVERA_BUSY
}Wdg_59_DriverA_StatusType;

#endif

#if (WDG_59_DRIVERA_RAM_MIRROR == WDG_59_DRIVERA_MIRROR_ENABLE)

/* Type definition for Wdg_59_DriverA_HWConsistencyModeType */
typedef enum ETag_Wdg_59_DriverA_HWConsistencyModeType
{
  WDG_59_DRIVERA_STATIC = 0,
  WDG_59_DRIVERA_DYNAMIC
}Wdg_59_DriverA_HWConsistencyModeType;

#endif

#endif /* WDG_59_DRIVERA_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
