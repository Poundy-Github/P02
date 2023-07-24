/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Version.c                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for modules included by       */
/* Core Test Driver.                                                          */
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
 * V1.0.0:  27-Nov-2013    : Initial Version
 *
 * V1.0.1:  09-Sep-2014    : As per CR 604 for Mantis issue #22252, following
 *                           changes are made:
 *                           1. The Copyright information is updated.
 *                           2. File is updated for including Autosar R3.2
 *                              version check and information details.
 * V2.0.0:  31-Aug-2016    : #ARDAABD-476
 *                           1. Updated to ASR 4.2.2
 * V2.0.1:  07-Sep-2016    : #ARDAABD-495
 *                           1.Updated copyright year and revision history
 * V2.0.2:  19-June-2018   : 1.Added justification for QAC Warning which cannot
 *                             be removed.
 *                           2.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           3.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 */
/******************************************************************************/

/*******************************************************************************
**                              QAC Warnings                                  **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0553) Translation unit contains no object or function   */
/*                 definitions with external linkage.                         */
/* Justification : Implementation of AUTOSAR SWS requirement to uniformize.   */
/* Verification  : Integration of the source code is not having any impact.   */
/* Reference     : Look for START Msg(2:0553)-1 and                           */
/*                 END Msg(2:0553)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*
 * Included for Core Test module version information and other modules version
 * information
 */
#include "CorTst_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define CORTST_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                           CORTST_AR_RELEASE_MAJOR_VERSION_VALUE
#define CORTST_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                           CORTST_AR_RELEASE_MINOR_VERSION_VALUE
#define CORTST_VERSION_C_AR_RELEASE_REVISION_VERSION \
                                        CORTST_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define CORTST_VERSION_C_SW_MAJOR_VERSION    CORTST_SW_MAJOR_VERSION_VALUE
#define CORTST_VERSION_C_SW_MINOR_VERSION    CORTST_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CORTST_VERSION_AR_RELEASE_MAJOR_VERSION != \
                                      CORTST_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "CorTst_Version.c : Mismatch in Release Major Version"
#endif
#if (CORTST_VERSION_AR_RELEASE_MINOR_VERSION != \
                                      CORTST_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "CorTst_Version.c : Mismatch in Release Minor Version"
#endif
#if (CORTST_VERSION_AR_RELEASE_REVISION_VERSION != \
                                   CORTST_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "CorTst_Version.c : Mismatch in Release Revision Version"
#endif

#if (CORTST_VERSION_SW_MAJOR_VERSION != CORTST_VERSION_C_SW_MAJOR_VERSION)
  #error "CorTst_Version.c : Mismatch in Software Major Version"
#endif
#if (CORTST_VERSION_SW_MINOR_VERSION != CORTST_VERSION_C_SW_MINOR_VERSION)
  #error "CorTst_Version.c : Mismatch in Software Minor Version"
#endif

/* Implements CORTST_ESDD_UD_020 */
#if (CORTST_VERSION_CHECK_EXT_MODULES == STD_ON)
/* Rte Module Version Check */
/* Implements EAAR_PN0077_FR_0007 */
#if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != CORTST_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != CORTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* End of CORTST_CRITICAL_SECTION_PROTECTION */

/* Dem Module Version Check */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != CORTST_AR_RELEASE_MAJOR_VERSION) \
 || (DEM_AR_RELEASE_MINOR_VERSION != CORTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

/* Det Module Version Check */
/* Implements CORTST_ESDD_UD_011 */
/* Implements CorTst017, CorTst020 */
#if (CORTST_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != CORTST_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != CORTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif /* #if (CORTST_DEV_ERROR_DETECT == STD_ON) */
#endif /* #if (CORTST_VERSION_CHECK_EXT_MODULES == STD_ON) */


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
