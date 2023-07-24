/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = RamTst_Version.h                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2017-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros for version checking of modules included by RAM  */
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
 * V1.0.0:  27-Sep-2017    : Initial Version
 * V1.0.1:  06-Jul-2018    : As part of ARDAABD-2101 following changes are made:
 *                           1. Added traceability tags for Reqtify coverage
 *                              improvement.
 *                           2. Updated copyright information
 */
/******************************************************************************/
#ifndef RAMTST_VERSION_H
#define RAMTST_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for version information macros */
/* RAMTST_VERSION_H_002: RamTst155 */
#include "RamTst.h"
#if (RAMTST_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
/* DEM module version information*/
/* RAMTST_VERSION_H_001: RamTst073 */
/* RAMTST_VERSION_H_003: RamTst121_Conf */
#include "Dem.h"
#if (RAMTST_CRITICAL_SECTION_PROTECTION == STD_ON)
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
/* RAMTST_VERSION_H_004: ECUC_RamTst_00186 */
#define RAMTST_VERSION_AR_RELEASE_MAJOR_VERSION  RAMTST_AR_RELEASE_MAJOR_VERSION
#define RAMTST_VERSION_AR_RELEASE_MINOR_VERSION  RAMTST_AR_RELEASE_MINOR_VERSION
#define RAMTST_VERSION_AR_RELEASE_REVISION_VERSION  \
                         RAMTST_AR_RELEASE_REVISION_VERSION

/* File version information */
#define RAMTST_VERSION_SW_MAJOR_VERSION    RAMTST_SW_MAJOR_VERSION
#define RAMTST_VERSION_SW_MINOR_VERSION    RAMTST_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* RAMTST_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
