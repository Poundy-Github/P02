/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Version.h                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2019 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros for version checking of modules included by Core */
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
/*
 * V1.0.0:  27-Nov-2013    : Initial Version
 *
 * V1.0.1:  09-Sep-2014    : As per CR 604 for Mantis issue #22252, following
 *                           changes are made:
 *                           1. Include section is updated for adding SchM.h
 *                              file.
 *                           2. Version information details are updated with
 *                              Autosar R3.2 specification version, DET, DEM
 *                              and SCHM version information.
 *                           3. The Copyright information is updated.
 * V2.0.0:  31-Aug-2016    : #ARDAABD-476
 *                           1. Updated to ASR 4.2.2
 * V2.0.1:  19-June-2018   : #ARDAABD-495
 *                           1.Updated copyright year and revision history
 *                           2.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           3.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 *          08-Oct-2019    : The problem with the historical version caused.
 *                           The version doesn't need to be upgraded.
 *                           1.The Copyright has been changed to "2013 - 2019".
 */
/******************************************************************************/
#ifndef CORTST_VERSION_H
#define CORTST_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for version information macros */
#include "CorTst.h"
/* CORTST_VERSION_H_001: CORTST_ESDD_UD_011                                   */
/* CORTST_VERSION_H_002: EAAR_PN0034_FR_0064, ECUC_CorTst_00082 */
#if (CORTST_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
/* DEM module version information*/
#include "Dem.h"
/* CORTST_VERSION_H_003: EAAR_PN0077_FR_0007 */
/* CORTST_VERSION_H_004: EAAR_PN0034_FR_0013 */
/* CORTST_VERSION_H_005: CORTST_ESDD_UD_022 */

#if (CORTST_CRITICAL_SECTION_PROTECTION == STD_ON)
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */
#include "Rte.h"
#endif


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define CORTST_VERSION_AR_RELEASE_MAJOR_VERSION  CORTST_AR_RELEASE_MAJOR_VERSION
#define CORTST_VERSION_AR_RELEASE_MINOR_VERSION  CORTST_AR_RELEASE_MINOR_VERSION
#define CORTST_VERSION_AR_RELEASE_REVISION_VERSION  \
                         CORTST_AR_RELEASE_REVISION_VERSION

/* File version information */
#define CORTST_VERSION_SW_MAJOR_VERSION    CORTST_SW_MAJOR_VERSION
#define CORTST_VERSION_SW_MINOR_VERSION    CORTST_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* CORTST_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
