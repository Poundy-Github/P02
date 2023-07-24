/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Version.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Version information                                           */
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
 * V1.0.0:  10-Sep-2015 : Initial Version.
 * V2.0.0:  19-Oct-2015 : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                           ASR 4.0.3
 * V2.0.1:  25-Sep-2017 : Following changes are made:
 *                        1. As part of ARDAABD-2425,
 *                           a.Handled QAC level 2 warnings.
 * V2.0.2:  18-Jun-2018 : As part of jira ticket ARDAABD-3839, following changes
 *                        are made:
 *                        1. Added traceability tags.
 *                        2. Updated Copyright(c) information.
 */
/******************************************************************************/
/* Implements:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0018 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*
 * Included for Pwm module version information and other modules version
 * information
 */
#include "Pwm_Version.h"

/* Implements:  EAAR_PN0034_NR_0026                                           */
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
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_VERSION_C_AR_RELEASE_MAJOR_VERSION  \
                                           PWM_AR_RELEASE_MAJOR_VERSION_VALUE
#define PWM_VERSION_C_AR_RELEASE_MINOR_VERSION  \
                                           PWM_AR_RELEASE_MINOR_VERSION_VALUE
#define PWM_VERSION_C_AR_RELEASE_REVISION_VERSION  \
                                         PWM_AR_RELEASE_REVISION_VERSION_VALUE
#elif (PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_VERSION_C_AR_RELEASE_MAJOR_VERSION  \
                                           PWM_AR_RELEASE_MAJOR_VERSION_VALUE
#define PWM_VERSION_C_AR_RELEASE_MINOR_VERSION  \
                                           PWM_AR_RELEASE_MINOR_VERSION_VALUE
#define PWM_VERSION_C_AR_RELEASE_REVISION_VERSION  \
                                         PWM_AR_RELEASE_REVISION_VERSION_VALUE
#endif /* End of PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION */

/* Module software version information */
#define PWM_VERSION_C_SW_MAJOR_VERSION  PWM_SW_MAJOR_VERSION_VALUE
#define PWM_VERSION_C_SW_MINOR_VERSION  PWM_SW_MINOR_VERSION_VALUE

/* Implements:  EAAR_PN0034_FR_0055                                           */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_VERSION_AR_RELEASE_MAJOR_VERSION != \
                            PWM_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Pwm_Version.c : Mismatch in Release Major Version"
#endif

#if (PWM_VERSION_AR_RELEASE_MINOR_VERSION != \
                            PWM_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Pwm_Version.c : Mismatch in Release Minor Version"
#endif

#if (PWM_VERSION_AR_RELEASE_REVISION_VERSION != \
                       PWM_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Pwm_Version.c : Mismatch in Release Patch Version"
#endif

#if (PWM_VERSION_SW_MAJOR_VERSION != PWM_VERSION_C_SW_MAJOR_VERSION)
  #error "Pwm_Version.c : Mismatch in Software Major Version"
#endif

#if (PWM_VERSION_SW_MINOR_VERSION != PWM_VERSION_C_SW_MINOR_VERSION)
  #error "Pwm_Version.c : Mismatch in Software Minor Version"
#endif

/* Implements:  PWM_ESDD_UD_068                                               */
#if (PWM_VERSION_CHECK_EXT_MODULES == STD_ON)
/* Condition for PWM_VERSION_CHECK_EXT_MODULES */

/* Implements:  PWM_ESDD_UD_043                                               */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif/* End of PWM_DEV_ERROR_DETECT */

#if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* End of PWM_CRITICAL_SECTION_PROTECTION */

#if ((OS_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (OS_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Os.h does not match the expected version"
#endif /* End of OS */
#endif /* End of PWM_VERSION_CHECK_EXT_MODULES */

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
/*END Msg(2:0553)-1*/
