/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = RamTst_Version.c                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2017 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for modules included by RAM   */
/* Test Driver.                                                               */
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
/* Implements EAAR_PN0034_NR_0045 */
/*
 * V1.0.0:  27-Sep-2017    : Initial Version
 * V1.0.1:  14-Jul-2018    : Following changes are made:
 *                           1. As part of merging activity ARDAABD-3470
 *                              a. As part of QAC analysis, QAC warning tag is
 *                                 added for Message(2:0553).
 *                           2. Updated Copyright(c) information.
 *                           3. As part of ARDAABD-2101, added traceability tags
 *                              for Reqtify coverage improvement.
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
 * Included for RAM Test module version information and other modules version
 * information
 */
#include "RamTst_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*QAC Warning: START Msg(2:0553)-1*/

/* AUTOSAR release version information */
#define RAMTST_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                           RAMTST_AR_RELEASE_MAJOR_VERSION_VALUE
#define RAMTST_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                           RAMTST_AR_RELEASE_MINOR_VERSION_VALUE
#define RAMTST_VERSION_C_AR_RELEASE_REVISION_VERSION \
                                        RAMTST_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define RAMTST_VERSION_C_SW_MAJOR_VERSION    RAMTST_SW_MAJOR_VERSION_VALUE
#define RAMTST_VERSION_C_SW_MINOR_VERSION    RAMTST_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (RAMTST_VERSION_AR_RELEASE_MAJOR_VERSION != \
                                      RAMTST_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "RamTst_Version.c : Mismatch in Release Major Version"
#endif
#if (RAMTST_VERSION_AR_RELEASE_MINOR_VERSION != \
                                      RAMTST_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "RamTst_Version.c : Mismatch in Release Minor Version"
#endif
#if (RAMTST_VERSION_AR_RELEASE_REVISION_VERSION != \
                                   RAMTST_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "RamTst_Version.c : Mismatch in Release Revision Version"
#endif

#if (RAMTST_VERSION_SW_MAJOR_VERSION != RAMTST_VERSION_C_SW_MAJOR_VERSION)
  #error "RamTst_Version.c : Mismatch in Software Major Version"
#endif
#if (RAMTST_VERSION_SW_MINOR_VERSION != RAMTST_VERSION_C_SW_MINOR_VERSION)
  #error "RamTst_Version.c : Mismatch in Software Minor Version"
#endif

#if (RAMTST_VERSION_CHECK_EXT_MODULES == STD_ON)
/* Rte Module Version Check */
#if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != RAMTST_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != RAMTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* End of RAMTST_CRITICAL_SECTION_PROTECTION */

/* Implements RamTst073 */
/* Implements SWS_RamTst_00098 */
/* Dem Module Version Check */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != RAMTST_AR_RELEASE_MAJOR_VERSION) \
 || (DEM_AR_RELEASE_MINOR_VERSION != RAMTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

/* Det Module Version Check */
/* Implements EAAR_PN0034_FR_0064 */
#if (RAMTST_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != RAMTST_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != RAMTST_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif /* #if (RAMTST_DEV_ERROR_DETECT == STD_ON) */
#endif /* #if (RAMTST_VERSION_CHECK_EXT_MODULES == STD_ON) */

/*Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026*/
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
/*END Msg(2:0553)-1*/