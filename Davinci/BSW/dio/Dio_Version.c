/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Version.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for the modules included by   */
/* Dio Driver                                                                 */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  02-Sep-2015  : Initial Version
 * V2.0.0:  27-Oct-2016  : As part of ARDAABC-626 and ARDAABC-882 Jira Ticket,
 *                         the following changes are made:
 *                         1) Removed AR 3.2.2 related functionality and
 *                            added AR 4.2.2 where applicable.
 * V2.0.1   04-Jan-2017  : As part of ARDAABC-595 Jira ticket,
 *                         the following changes made:
 *                         1) Updated the traceability tags to the required
 *                            format.
 * V2.0.2   06-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Updated copyright dates
 * V2.0.3   24-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Header comment updated due to acceptance team
 *                            comment
 * V2.0.4   13-Feb-2017  : Following changes are made:
 *                         1) As part of ARDAABC-630, code was updated after QAC
 *                            analysis
 * V2.0.5   08-Mar-2017  : Following changes are made:
 *                         1) As part of ARDAABC-522, added check version for
 *                            DEM module
 * V2.0.6:  20-Oct-2017  : Following changes are made:
 *                         1) As part of ARDAABD-2198, Style_Format
 *                           corrected for comments and condition.
 *                         2) Removed reference of MISRA justification.
 * V2.0.7:  20-June-2018 : Following changes are made:
 *                         1) As part of ARDAABD-3851 to improve traceability,
 *                            a.Removed all the redundant and obsolete
 *                              requirements.
 *                            b.Added missing requirements from requirement
 *                              documents.
 *                          2) Updated copyright year.
 */
/******************************************************************************/

/*******************************************************************************
 **                     Include Section                                       **
 ******************************************************************************/
/* Header file inclusion */
#include "Dio_Version.h"

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:0553) Translation unit contains no object or function   */
/*                 definitions with external linkage.                         */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0553           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/

/* AUTOSAR release version information */
#define DIO_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                  DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                  DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_VERSION_C_AR_RELEASE_REVISION_VERSION \
                               DIO_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define DIO_VERSION_C_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION_VALUE
#define DIO_VERSION_C_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION_VALUE

/*******************************************************************************
 **                      Version Check                                        **
 ******************************************************************************/

#if (DIO_VERSION_AR_RELEASE_MAJOR_VERSION != \
                              DIO_VERSION_C_AR_RELEASE_MAJOR_VERSION)
#error "Dio_Version.c : Mismatch in Release Major Version"
#endif

#if (DIO_VERSION_AR_RELEASE_MINOR_VERSION != \
                              DIO_VERSION_C_AR_RELEASE_MINOR_VERSION)
#error "Dio_Version.c : Mismatch in Release Minor Version"
#endif

#if (DIO_VERSION_AR_RELEASE_REVISION_VERSION != \
                           DIO_VERSION_C_AR_RELEASE_REVISION_VERSION)
#error "Dio_Version.c : Mismatch in Release Revision Version"
#endif

/* Implements DIO106 */
#if (DIO_VERSION_SW_MAJOR_VERSION != DIO_VERSION_C_SW_MAJOR_VERSION)
#error "Dio_Version.c : Mismatch in Software Major Version"
#endif

/* Implements DIO106 */
#if (DIO_VERSION_SW_MINOR_VERSION != DIO_VERSION_C_SW_MINOR_VERSION)
#error "Dio_Version.c : Mismatch in Software Minor Version"
#endif

/* Implements DIO_ESDD_UD_016 */
#if (DIO_VERSION_CHECK_EXT_MODULES == STD_ON)
/* Implements DIO_ESDD_UD_017 */
#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) \
              || (RTE_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Rte.h does not match the expected version"
#endif
#endif /*(DIO_CRITICAL_SECTION_PROTECTION == STD_ON) */

/* START of Dem Module Version Check */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) \
    || (DEM_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Dem.h does not match the expected version"
#endif

/* START of DIO_DEV_ERROR_DETECT */
#if (DIO_DEV_ERROR_DETECT == STD_ON)

#if ((DET_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif
#endif
#endif
/*(DIO_VERSION_CHECK_EXT_MODULES == STD_ON) */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
