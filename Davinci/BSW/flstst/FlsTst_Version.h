/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst_Version.h                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros for version checking of modules included by      */
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
 * V1.0.0:  20-Nov-2013    : Initial Version
 * V1.0.1:  12-Jul-2018    : 1. As part of #ARDAABD-3842, Removed duplicate
 *                              Requirement id's and mapped the required
 *                              Requirements for traceability
 *                           2. Updated copy-rights information
 */
/******************************************************************************/
/* FLSTST_VERSION_H_001:  EAAR_PN0034_FR_0001                                 */
#ifndef FLSTST_VERSION_H
#define FLSTST_VERSION_H

/* FLSTST_VERSION_H_003:  FLSTST_ESDD_UD_003                                  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for version information macros */
#include "FlsTst.h"
#if (FLSTST_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
/* DEM module version information*/
#include "Dem.h"
/* FLSTST_VERSION_H_004:  FLSTST_ESDD_UD_059                                  */
#if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
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
#define FLSTST_VERSION_AR_RELEASE_MAJOR_VERSION  FLSTST_AR_RELEASE_MAJOR_VERSION
#define FLSTST_VERSION_AR_RELEASE_MINOR_VERSION  FLSTST_AR_RELEASE_MINOR_VERSION
#define FLSTST_VERSION_AR_RELEASE_REVISION_VERSION  \
                         FLSTST_AR_RELEASE_REVISION_VERSION

/* FLSTST_VERSION_H_002:  EAAR_PN0034_FR_0055                                 */
/* File version information */
#define FLSTST_VERSION_SW_MAJOR_VERSION    FLSTST_SW_MAJOR_VERSION
#define FLSTST_VERSION_SW_MINOR_VERSION    FLSTST_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* FLSTST_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
