/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Version.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by DIO Driver.                                                    */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  02-Sep-2015  : Initial Version
 *
 * V2.0.0:  27-Oct-2016  : As part of ARDAABC-626 and ARDAABC-882 Jira Ticket,
 *                         the following changes are made:
 *                         1) Removed AR 3.2.2 related functionality and
 *                            added AR 4.2.2 where applicable.
 * V2.0.1   06-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Updated copyright dates
 * V2.0.2   24-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Header comment updated due to acceptance team
 *                            comment
 * V2.0.3   20-June-2018 : Following changes are made:
 *                         1) As part of ARDAABD-3851 to improve traceability,
 *                            a.Removed all the redundant and obsolete
 *                              requirements.
 *                            b.Added missing requirements from requirement
 *                              documents.
 *                          2) Updated copyright year.
 */
/******************************************************************************/
/* DIO_VERSION_H_001: EAAR_PN0034_FR_0001 */
#ifndef DIO_VERSION_H
#define DIO_VERSION_H

/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* Included for module version information */
#include "Dio.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)

/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif

/* DIO_LTTYPES_H_002: DIO_ESDD_UD_017 */
#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */
#include "Rte.h"
#endif
/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/

/* AUTOSAR release version information */
#define DIO_VERSION_AR_RELEASE_MAJOR_VERSION    DIO_AR_RELEASE_MAJOR_VERSION
#define DIO_VERSION_AR_RELEASE_MINOR_VERSION    DIO_AR_RELEASE_MINOR_VERSION
#define DIO_VERSION_AR_RELEASE_REVISION_VERSION DIO_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define DIO_VERSION_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION
#define DIO_VERSION_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/

#endif
/* DIO_VERSION_H */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
