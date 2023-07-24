/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Version.c                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for the modules included by   */
/* Watchdog Driver A                                                          */
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
 * V2.0.1   26-Oct-2016    : Version fix
 * V2.0.2   13-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.0.3   19-Jul-2018    : 1.#ARDAABD-1207
 *                             Traceability update
 *                           2.As part #ARDAABD-3905, traceability
 *                             has been updated by mapping respective
 *                             WDG_ESDD_UD IDs.
 *                           3.Copyright information is updated.
 */
/******************************************************************************/


/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Implements: WDG099 */
/* Implements: WDG_ESDD_UD_053 */
/* Header file inclusion */
#include "Wdg_59_DriverA_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Implements: WDG_ESDD_UD_008, WDG_ESDD_UD_053, WDG_ESDD_UD_072              */
/* Implements: WDG174, WDG109                                                 */
/* Implements: SWS_Wdg_00174, SWS_Wdg_00109                                   */


/* Functionality related to R4.0 and R4.2 */
/* Implements: WDG_ESDD_UD_015, WDG_ESDD_UD_053, WDG_ESDD_UD_004              */
/* Implements: EAAR_PN0034_FR_0017                                            */
/* Implements: WDG068, WDG109, WDG067, WDG099, WDG087                         */
/* Implements: ECUC_Wdg_00119, SWS_Wdg_00109                                  */
/* Implements: WDG087, SWS_Wdg_0086                                           */
/* Implements: BSW004, BSW167, SRS_BSW_00004                                  */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define WDG_59_DRIVERA_VERSION_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_MAJOR_VERSION != \
                              WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_MINOR_VERSION != \
                              WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_REVISION_VERSION != \
                           WDG_59_DRIVERA_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Revision Version"
#endif


#if (WDG_59_DRIVERA_VERSION_SW_MINOR_VERSION !=  \
                                      WDG_59_DRIVERA_VERSION_C_SW_MINOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Software Minor Version"
#endif

/* Implements: WDG_ESDD_UD_020,                                               */
#if (WDG_59_DRIVERA_VER_CHECK_EXT == STD_ON)

/* Implements: WDG_ESDD_UD_013                                                */
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#if ((DET_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

#if ((DEM_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (DEM_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif
/* Implements: WDG_ESDD_UD_025                                                */
#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif

#if ((OS_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (OS_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Os.h does not match the expected version"
#endif


#endif /* #if (WDG_59_DRIVERA_VER_CHECK_EXT == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
