/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Version.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by PWM Driver                                                     */
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
 * V1.0.0:  10-Sep-2015  : Initial Version.
 * V2.0.0:  19-Oct-2016  : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                            ASR 4.0.3.
 * V2.0.1:  18-Jun-2018  : As part of JIRA #ARDAABD-3839, following changes are
 *                         made:
 *                         1. Added PWM_VERSION_H_001 to PWM_VERSION_H_008 for
 *                            traceability improvement.
 *                         2. Updated Copyright(c) information.
 */
/******************************************************************************/
/* PWM_VERSION_H_008:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045               */
/* PWM_VERSION_H_007:  EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0018               */
#ifndef PWM_VERSION_H
#define PWM_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for version information macros */
#include "Pwm.h"

/* PWM_VERSION_H_004:  PWM_ESDD_UD_043, EAAR_PN0034_FR_0064, PWM131_Conf      */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif

/* PWM_VERSION_H_001:  PWM_ESDD_UD_042, EAAR_PN0066_FR_0043                   */
#if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */
#include "Rte.h"
#endif /*END of PWM_CRITICAL_SECTION_PROTECTION*/

/* OS module version information is required */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* PWM_VERSION_H_005:  PWM_ESDD_UD_128, EAAR_PN0066_FR_0045                   */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_VERSION_AR_RELEASE_MAJOR_VERSION  PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_VERSION_AR_RELEASE_MINOR_VERSION  PWM_AR_RELEASE_MINOR_VERSION
#define PWM_VERSION_AR_RELEASE_REVISION_VERSION  PWM_AR_RELEASE_REVISION_VERSION

/* PWM_VERSION_H_006:  PWM_ESDD_UD_129, EAAR_PN0066_FR_0045                   */
#elif (PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_VERSION_AR_RELEASE_MAJOR_VERSION  PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_VERSION_AR_RELEASE_MINOR_VERSION  PWM_AR_RELEASE_MINOR_VERSION
#define PWM_VERSION_AR_RELEASE_REVISION_VERSION  PWM_AR_RELEASE_REVISION_VERSION

/* Included files AUTOSAR specification version */
#define PWM_OS_AR_MAJOR_VERSION    3
#define PWM_OS_AR_MINOR_VERSION    2

/* PWM_VERSION_H_003:  PWM_ESDD_UD_043                                        */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
#define PWM_DET_AR_MAJOR_VERSION      2
#define PWM_DET_AR_MINOR_VERSION      2
#endif

/* PWM_VERSION_H_002:  PWM_ESDD_UD_042, EAAR_PN0066_FR_0043                   */
#if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
#define PWM_SCHM_AR_MAJOR_VERSION     1
#define PWM_SCHM_AR_MINOR_VERSION     2
#endif

#endif /* End of PWM_AR_VERSION */

/* Software module version information */
#define PWM_VERSION_SW_MAJOR_VERSION    PWM_SW_MAJOR_VERSION
#define PWM_VERSION_SW_MINOR_VERSION    PWM_SW_MINOR_VERSION

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PWM_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
