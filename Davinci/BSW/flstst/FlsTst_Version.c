/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst_Version.c                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for modules included by       */
/* FLSTST Component                                                           */
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
 * V1.0.0:  11-Oct-2013    : Initial Version
 *
 * V1.0.1:  03-Feb-2014    : As per CR78 and merge activity and mantis #17998
 *                           following changes are made:
 *                           1. Copyright information is updated.
 *                           2. Pre-compiler FLSTST_VERSION_CHECK_EXT_MODULES
 *                              check added.
 * V2.0.0: 28-Oct-2016    : As per CR12, As per Renesas coding guidelines,
 *                          Markers are added for Tracing.
 * V2.0.1: 21-Aug-2017    : Added justifications for MISRA Violations and QAC
 *                          Warnings which cannot be removed. Removed tags and
 *                          justification for MISRA Violation message (4:3138).
 * V2.0.2: 21-Jun-2018    : 1. As part of #ARDAABD-3842, Removed duplicate
 *                             Requirement id's and mapped the required
 *                             Requirements for traceability
 *                          2. Updated copy-rights information
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included macros for version checking of modules included by FLSTST  */
#include "FlsTst_Version.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define FLSTST_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                           FLSTST_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLSTST_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                           FLSTST_AR_RELEASE_MINOR_VERSION_VALUE
#define FLSTST_VERSION_C_AR_RELEASE_REVISION_VERSION \
                                        FLSTST_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define FLSTST_VERSION_C_SW_MAJOR_VERSION    FLSTST_SW_MAJOR_VERSION_VALUE
#define FLSTST_VERSION_C_SW_MINOR_VERSION    FLSTST_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (FLSTST_VERSION_AR_RELEASE_MAJOR_VERSION != \
                                      FLSTST_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "FLSTST_Version.c : Mismatch in Release Major Version"
#endif
#if (FLSTST_VERSION_AR_RELEASE_MINOR_VERSION != \
                                      FLSTST_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "FLSTST_Version.c : Mismatch in Release Minor Version"
#endif
#if (FLSTST_VERSION_AR_RELEASE_REVISION_VERSION != \
                                   FLSTST_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "FLSTST_Version.c : Mismatch in Release Revision Version"
#endif

#if (FLSTST_VERSION_SW_MAJOR_VERSION != FLSTST_VERSION_C_SW_MAJOR_VERSION)
  #error "FLSTST_Version.c : Mismatch in Software Major Version"
#endif
#if (FLSTST_VERSION_SW_MINOR_VERSION != FLSTST_VERSION_C_SW_MINOR_VERSION)
  #error "FLSTST_Version.c : Mismatch in Software Minor Version"
#endif

#if (FLSTST_VERSION_CHECK_EXT_MODULES == STD_ON)
/* Rte Module Version Check */
/* Implements: FLSTST_ESDD_UD_059                                             */
#if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != FLSTST_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != FLSTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* End of FLSTST_CRITICAL_SECTION_PROTECTION */

/* Dem Module Version Check */
/* Implements: FLSTST_ESDD_UD_003                                             */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != FLSTST_AR_RELEASE_MAJOR_VERSION) \
 || (DEM_AR_RELEASE_MINOR_VERSION != FLSTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

/* Det Module Version Check */
#if (FLSTST_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != FLSTST_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != FLSTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
#endif /* #if (FLSTST_VERSION_CHECK_EXT_MODULES == STD_ON) */


/*******************************************************************************
**                              Global Data                                   **
*******************************************************************************/

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
**                      Function Definitions                                  **
*******************************************************************************/
/* QAC Warning: START Msg(2:0553)-1 */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
/* END Msg(2:0553)-1 */
