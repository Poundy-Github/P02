/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Version.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for modules included by PORT  */
/* Driver                                                                     */
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

/* Implements EAAR_PN0034_NR_0045 */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Sep-2015  : Initial Version
 * V2.0.0:  20-Oct-2016  : As part of ARDAABC-621 Jira ticket, the following
 *                         changes are made:
 *                         1. Changed AUTOSAR lower version to 4.0.3 and
 *                         higher version to 4.2.2. Versioning for both
 *                         AR4.0.3 and AR4.2.2 comes from Port_Cfg.h now.
 *                         2. Removed Autosar 3.2.2 code from implementation.
 * V2.0.1:  21-Jun-2018  : As part of ARDAABD-3844 Jira Ticket, the following
 *                         changes are made:
 *                         1. Requirements and Design ID's are mapped to the
 *                         implementation in order to improve coverage.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Header file inclusion */
#include "Port_Version.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PORT_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                             PORT_AR_RELEASE_MAJOR_VERSION_VALUE
#define PORT_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                             PORT_AR_RELEASE_MINOR_VERSION_VALUE
#define PORT_VERSION_C_AR_RELEASE_REVISION_VERSION \
                                          PORT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define PORT_VERSION_C_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION_VALUE
#define PORT_VERSION_C_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION_VALUE
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PORT_VERSION_AR_RELEASE_MAJOR_VERSION != \
                                        PORT_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port_Version.c : Mismatch in Release Major Version"
#endif
#if (PORT_VERSION_AR_RELEASE_MINOR_VERSION != \
                                        PORT_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Port_Version.c : Mismatch in Release Minor Version"
#endif
#if (PORT_VERSION_AR_RELEASE_REVISION_VERSION != \
                                     PORT_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Port_Version.c : Mismatch in Release Revision Version"
#endif

#if (PORT_VERSION_SW_MAJOR_VERSION != PORT_VERSION_C_SW_MAJOR_VERSION)
  #error "Port_Version.c : Mismatch in Software Major Version"
#endif
#if (PORT_VERSION_SW_MINOR_VERSION != PORT_VERSION_C_SW_MINOR_VERSION)
  #error "Port_Version.c : Mismatch in Software Minor Version"
#endif
/* Implements PORT_ESDD_UD_053 */
#if (PORT_VERSION_CHECK_EXT_MODULES == STD_ON)

/* Rte Module Version Check */
/* Implements EAAR_PN0034_FR_0030 */
/* Implements PORT_ESDD_UD_023 */
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* (PORT_CRITICAL_SECTION_PROTECTION == STD_ON) */

/* Dem Module Version Check */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) \
 || (DEM_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

/* Det Module Version Check */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
#endif /* #if (PORT_VERSION_CHECK_EXT_MODULES == STD_ON) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
