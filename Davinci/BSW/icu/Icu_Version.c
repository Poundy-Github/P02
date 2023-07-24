/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Version.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporations                  */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains version check of modules included by ICU Driver         */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas.            */
/* Any warranty is expressly disclaimed and excluded by Renesas, either       */
/* expressed or implied, including but not limited to those for               */
/* non-infringement of intellectual property, merchantability                 */
/* and/or fitness for the particular purpose                                  */
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
 * V1.0.0:  16-Sep-2015  : Initial Version.
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  12-Apr-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3476
 *                            a. Handled QAC level 2 warnings.Ref:ARDAABD-2425
 *                            b. Copyright information is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*
 * Included for Icu module version information and other modules version
 * information
 */
#include "Icu_Version.h"

/*******************************************************************************
**                                QAC WARNING                                 **
*******************************************************************************/
/* 1. QAC WARNING:                                                            */
/* Message       : (2:0553) Translation unit contains no object or function   */
/*                 definitions with external linkage.                         */
/* Rule          : NA                                                         */
/* Justification : As per AUTOSAR, file should be required to include.        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:0553)-1 and              */
/*                 END Msg(2:0553)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*QAC Warning: START Msg(2:0553)-1*/
/* AUTOSAR release version information */
#define ICU_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                  ICU_AR_RELEASE_MAJOR_VERSION_VALUE
#define ICU_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                  ICU_AR_RELEASE_MINOR_VERSION_VALUE
#define ICU_VERSION_C_AR_RELEASE_REVISION_VERSION \
                               ICU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ICU_VERSION_C_SW_MAJOR_VERSION  ICU_SW_MAJOR_VERSION_VALUE
#define ICU_VERSION_C_SW_MINOR_VERSION  ICU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ICU_VERSION_AR_RELEASE_MAJOR_VERSION != \
                              ICU_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Icu_Version.c : Mismatch in Release Major Version"
#endif

#if (ICU_VERSION_AR_RELEASE_MINOR_VERSION != \
                              ICU_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Icu_Version.c : Mismatch in Release Minor Version"
#endif

#if (ICU_VERSION_AR_RELEASE_REVISION_VERSION != \
                           ICU_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Icu_Version.c : Mismatch in Release Revision Version"
#endif

#if (ICU_VERSION_SW_MAJOR_VERSION != ICU_VERSION_C_SW_MAJOR_VERSION)
  #error "Icu_Version.c : Mismatch in Software Major Version"
#endif

#if (ICU_VERSION_SW_MINOR_VERSION != ICU_VERSION_C_SW_MINOR_VERSION)
  #error "Icu_Version.c : Mismatch in Software Minor Version"
#endif

/* Implements:  ICU_ESDD_UD_053                                               */
#if (ICU_VERSION_CHECK_EXT_MODULES == STD_ON)
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)

/* EcuM Module Version Check */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) \
 || (ECUM_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of EcuM.h does not match the expected version"
#endif
#endif /* #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */

/* Det Module Version Check */
#if (ICU_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */

/* Os Module Version Check */
#if ((OS_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) \
 || (OS_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Os.h does not match the expected version"
#endif

/* Rte Module Version Check */
#if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
#endif /* #if (ICU_VERSION_CHECK_EXT_MODULES == STD_ON)   */
/*END Msg(2:0553)-1*/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
