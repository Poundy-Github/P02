/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Ram.h                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Watchdog Driver are declared.          */
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
 *                           and ASR 3.2.2 was removed and 4.2.2 added
 * V2.0.1   26-Oct-2016    : 1. MemMap was changed according to #ARDAABD-474
 *                           2. FUSA req. implemented according to #ARDAABD-568
 * V2.0.2   14-Dec-2016    : Changed according to #ARDAABD-568
 * V2.0.3   22-Dec-2016    : #ARDAABD-601
 *                           1. Added MemMap switch arround
 *                              Wdg_59_DriverA_RamMirror
 * V2.0.4   16-Jan-2017    : MemMap section for Wdg_59_DriverA_RamMirror
 *                           was changed: WDG_59_DRIVERA_START_SEC_VAR_NOINIT_8
 * V2.0.5   17-Jan-2017    : Updated after #ARDAABD-408
 *                           VAR_NOINIT_16BIT was changed to VAR_NOINIT_16
 * V2.0.6   27-Jan-2017    : RAM Mirroring check was updated
 * V2.0.7   15-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.0.8   15-Jun-2017    : As part of ARDAABD-1897 Jira ticket, code was
 *                           updated after QAC analysis
 * V2.0.9   16-Nov-2017    : Following changes are made:
 *                           1. As part of ARDAABD-2266 Jira ticket,
 *                              a. Wdg_59_DriverA_GusTiggerCounter is renamed to
 *                                 Wdg_59_DriverA_GusTriggerCounter.
 *                           2. As part of ARDAABD-2734 Jira Ticket,
 *                              variable MEMMAP_FILE is changed to
 *                              WDG_MEMMAP_FILE.
 * V2.0.10   06-Jun-2018    : Following changes are made:
 *                           1. As part of merging activity, #ARDAABD-3474
 *                              Memory section naming modifications are done,
 *                              Ref:ARDAABD-908.
 *                           2. As per JIRA ARDAABD-3728,
 *                              Memory mapping of  Wdg_59_DriverA_GddCurrentMode
 *                              has been mapped to
 *                              WDG_59_DRIVERA_START/STOP_SEC_VAR_NO_INIT_8.
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_RAM_H
#define WDG_59_DRIVERA_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Wdg_59_DriverA_Cfg.h"
/* Included for RAM Mirroring and Write Verify */
#include "Wdg_59_DriverA_RegWrite.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_RAM_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_RAM_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_RAM_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERA_RAM_SW_MAJOR_VERSION    WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_RAM_SW_MINOR_VERSION    WDG_59_DRIVERA_SW_MINOR_VERSION
/*******************************************************************************
**                         Macro definition                                   **
*******************************************************************************/
/* WDG_59_DRIVERA_RAM_H_001: WDG_ESDD_UD_065                                  */
#if (WDG_59_DRIVERA_RAM_MIRROR == WDG_59_DRIVERA_MIRROR_ENABLE)

#define WDG_59_DRIVERA_WDTAReg_WDTE_IDX      (0x00u)

#define WDG_59_DRIVERA_WDTAReg_EVAC_IDX      (0x01u)

#define WDG_59_DRIVERA_WDTAReg_REF_IDX       (0x02u)

#define WDG_59_DRIVERA_WDTAReg_MD_IDX        (0x03u)

#define WDG_59_DRIVERA_NB_OF_MIRRORED_REGS   (0x04u)

#endif
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#if (WDG_59_DRIVERA_RAM_MIRROR == WDG_59_DRIVERA_MIRROR_ENABLE)
#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_8
#include WDG_MEMMAP_FILE

extern VAR(uint8, WDG_59_DRIVERA_NOINIT_DATA)
  Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_NB_OF_MIRRORED_REGS];
#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_8
#include WDG_MEMMAP_FILE
#endif

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_59_DRIVERA_START_SEC_VAR_INIT_8
#include WDG_MEMMAP_FILE

/* WDG_59_DRIVERA_RAM_H_002: WDG148                                           */
/* WDG_59_DRIVERA_RAM_H_003: WDG152                                           */
/* WDG_59_DRIVERA_RAM_H_004: SWS_Wdg_00152                                    */
/* Global variable to store the driver state */
extern VAR(Wdg_59_DriverA_StatusType, WDG_59_DRIVERA_INIT_DATA)
                                                 Wdg_59_DriverA_GddDriverState;
#define WDG_59_DRIVERA_STOP_SEC_VAR_INIT_8
#include WDG_MEMMAP_FILE

#endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include WDG_MEMMAP_FILE

/* Global variable to store pointer to Configuration */
extern P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC,
                        WDG_59_DRIVERA_CONFIG_CONST)Wdg_59_DriverA_GpConfigPtr;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include WDG_MEMMAP_FILE

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_8
#include WDG_MEMMAP_FILE

/* WDG_59_DRIVERA_RAM_H_005: WDG154                                           */
/* WDG_59_DRIVERA_RAM_H_006: SWS_Wdg_00154                                    */
/* Global variable to store the current watchdog state */
extern VAR(WdgIf_ModeType, WDG_59_DRIVERA_NOINIT_DATA)
                                                 Wdg_59_DriverA_GddCurrentMode;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_8
#include WDG_MEMMAP_FILE

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_16
#include WDG_MEMMAP_FILE

/* WDG_59_DRIVERA_RAM_H_007: WDG153                                           */
/* WDG_59_DRIVERA_RAM_H_008: SWS_Wdg_00153                                    */
/* Global variable to store the trigger counter value */
extern VAR(uint16, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GusTriggerCounter;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_16
#include WDG_MEMMAP_FILE

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* WDG_59_DRIVERA_RAM_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
