/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Ram.c                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Watchdog Driver A                      */
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
 * V2.0.0   06-Sep-2016    : ASR 4.2.2 Release #ARDAABD-653
 * V2.1.0   26-Oct-2016    : Fusa added according to #ARDAABD-568
 * V2.1.1   14-Dec-2016    : Fusa added according to #ARDAABD-568 - fix
 * V2.1.2   16-Jan-2017    : MemMap section for Wdg_59_DriverA_RamMirror
 *                           was changed: WDG_59_DRIVERA_START_SEC_VAR_NOINIT_8
 * V2.1.3   17-Jan-2017    : Updated after #ARDAABD-408
 *                           VAR_NOINIT_16BIT was changed to VAR_NOINIT_16
 * V2.1.4   27-Jan-2017    : RAM Mirroring check was added.
 * V2.1.5   13-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.1.6   15-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.1.7   15-Jun-2017    : As part of ARDAABD-1897 Jira ticket, code was
 *                           updated after QAC analysis
 * V2.1.8   16-Nov-2017    : Following changes are made:
 *                           1. As part of ARDAABD-2266 Jira ticket,
 *                              a. Wdg_59_DriverA_GusTiggerCounter is renamed to
 *                                 Wdg_59_DriverA_GusTriggerCounter.
 *                           2. As part of ARDAABD-2734 Jira Ticket,
 *                              variable MEMMAP_FILE is changed to
 *                              WDG_MEMMAP_FILE.
 * V2.1.9   06-Jun-2018    : Following changes are made:
 *                           1. As part of merging activity, #ARDAABD-3474
 *                              Memory section naming modifications are done,
 *                              Ref:ARDAABD-908.
 *                           2. As per JIRA ARDAABD-3728,
 *                              Memory mapping of  Wdg_59_DriverA_GddCurrentMode
 *                              has been mapped to
 *                              WDG_59_DRIVERA_START/STOP_SEC_VAR_NO_INIT_8.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* Implements: WDG_ESDD_UD_072, WDG_ESDD_UD_032                               */
/* Implements: WDG061, WDG168, WDG147_Conf                                    */
/* Implements: SWS_Wdg_00061, SWS_Wdg_0016                                    */
/* Implements: BSW00345, BSW159, BSW00381, BSW00412, BSW00346, BSW158         */
/* Implements: BSW00370, BSW00435, BSW00436, BSW00301                         */
/* Implements: SRS_BSW_00345, SRS_BSW_00159, SRS_BSW_00381, SRS_BSW_0041      */
/* Implements: SRS_BSW_00346, SRS_BSW_00158, SRS_BSW_00301                    */

/* Included for module version information and other types declarations */
#include "Wdg_59_DriverA.h"
/* Header file inclusion */
#include "Wdg_59_DriverA_Ram.h"
/* Header file inclusion for macro definitions */
#include "Wdg_59_DriverA_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Implements: WDG087, SWS_Wdg_0086                                           */
/* Implements: BSW004, BSW167, SRS_BSW_00004                                  */
/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define WDG_59_DRIVERA_RAM_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Functionality related to R4.0 and R4.2 */
#if (WDG_59_DRIVERA_RAM_AR_RELEASE_MAJOR_VERSION != \
                                  WDG_59_DRIVERA_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_RAM_AR_RELEASE_MINOR_VERSION != \
                                  WDG_59_DRIVERA_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_RAM_AR_RELEASE_REVISION_VERSION != \
                               WDG_59_DRIVERA_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Revision Version"
#endif


#if (WDG_59_DRIVERA_RAM_SW_MAJOR_VERSION != \
                                          WDG_59_DRIVERA_RAM_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_RAM_SW_MINOR_VERSION != \
                                          WDG_59_DRIVERA_RAM_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Implements: WDG_ESDD_UD_001, WDG_ESDD_UD_002, WDG_ESDD_UD_004              */
#if (WDG_59_DRIVERA_RAM_MIRROR == WDG_59_DRIVERA_MIRROR_ENABLE)
#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_8
#include WDG_MEMMAP_FILE

/* Variable to store the registers values in RAM  */
VAR(uint8, WDG_59_DRIVERA_NOINIT_DATA)
               Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_NB_OF_MIRRORED_REGS];

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_8
#include WDG_MEMMAP_FILE
#endif


#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_59_DRIVERA_START_SEC_VAR_INIT_8
#include WDG_MEMMAP_FILE

/* Global variable to store the current watchdog driver state */
VAR(Wdg_59_DriverA_StatusType, WDG_59_DRIVERA_INIT_DATA)
                          Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_UNINIT;

#define WDG_59_DRIVERA_STOP_SEC_VAR_INIT_8
#include WDG_MEMMAP_FILE

#endif

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include WDG_MEMMAP_FILE

/* Global variable to store pointer to Configuration */
/* Implements: WDG_ESDD_UD_045                                                */
P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC,
                        WDG_59_DRIVERA_CONFIG_CONST)Wdg_59_DriverA_GpConfigPtr;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include WDG_MEMMAP_FILE

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_8
#include WDG_MEMMAP_FILE

/* Global variable to store the current watchdog driver mode */
VAR(WdgIf_ModeType, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GddCurrentMode;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_8
#include WDG_MEMMAP_FILE

/* Functionality related to R4.0 and R4.2 */
#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_16
#include WDG_MEMMAP_FILE

/* Global variable to store the trigger counter value */
VAR(uint16, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GusTriggerCounter;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_16
#include WDG_MEMMAP_FILE

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
