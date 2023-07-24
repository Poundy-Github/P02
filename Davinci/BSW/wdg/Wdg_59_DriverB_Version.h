/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverB_Version.h                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking release versions of        */
/* modules included by Watchdog Driver.                                       */
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
 * V2.0.2   15-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERB_VERSION_H
#define WDG_59_DRIVERB_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information */
#include "Wdg_59_DriverB.h"

#if (WDG_59_DRIVERB_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
/* WDG_59_DRIVERB_VERSION_H_001: WDG_ESDD_UD_042                              */
/* WDG_59_DRIVERB_VERSION_H_002: WDG080                                       */
/* WDG_59_DRIVERB_VERSION_H_003: AR_PN0064_FR_0034, AR_PN0064_FR_0035         */
/* WDG_59_DRIVERB_VERSION_H_004: AR_PN0064_FR_0050, AR_PN0034_FR_0067         */
/* WDG_59_DRIVERB_VERSION_H_005: IMP_F1x_V3.03.06_WDG_RS_1                    */

/* DEM module version information is required */
#include "Dem.h"

#if (WDG_59_DRIVERB_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Functionality related to R4.0 and R4.2 */
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */
#include "Rte.h"

#endif

/* OS module version information is required */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERB_VERSION_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERB_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERB_VERSION_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERB_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERB_VERSION_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERB_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERB_VERSION_SW_MAJOR_VERSION  WDG_59_DRIVERB_SW_MAJOR_VERSION
#define WDG_59_DRIVERB_VERSION_SW_MINOR_VERSION  WDG_59_DRIVERB_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#endif /* WDG_59_DRIVERB_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
