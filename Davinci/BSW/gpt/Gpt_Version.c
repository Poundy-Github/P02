/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Version.c                                               */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  17-Sep-2015  : Initial Version
 *
 * V2.0.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 *
 * V2.0.1:  18-Sep-2017    : Following changes are made:
 *                           1. As per ARDAABD-2425, QAC level 2 warning
 *                              Justification tags are added.
 *                           2. Copyright year updated.
 *
 * V2.0.2:  18-Jun-2018    : Following changes are made:
 *                           1. As per ARDAABD-3841, traceability updated.
 *                           2. Copyright information updated.
 */
/******************************************************************************/
/*Implements EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */
/*******************************************************************************
**                       QAC Warning Justification                            **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       :  Msg(2:0553)  Translation unit contains no object or       */
/*                  function definitions with external linkage.               */
/* Rule          :  MISRA-C:2004 Rule 9.1                                     */
/* Justification :  As per AUTOSAR, file should be required to include.       */
/* Verification  :  However, part of the code is verified manually and it is  */
/*                  not having any impact.                                    */
/******************************************************************************/
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/

#include "Gpt_Version.h"

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_VERSION_C_AR_RELEASE_MAJOR_VERSION  \
    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_VERSION_C_AR_RELEASE_MINOR_VERSION  \
    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_VERSION_C_AR_RELEASE_REVISION_VERSION  \
    GPT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define GPT_VERSION_C_SW_MAJOR_VERSION    GPT_SW_MAJOR_VERSION_VALUE
#define GPT_VERSION_C_SW_MINOR_VERSION    GPT_SW_MINOR_VERSION_VALUE

/*******************************************************************************
 **                      Version Check                                        **
 ******************************************************************************/

#if (GPT_VERSION_AR_RELEASE_MAJOR_VERSION != \
    GPT_VERSION_C_AR_RELEASE_MAJOR_VERSION)
#error "Gpt_Version.c : Mismatch in Specification Major Version"
#endif

#if (GPT_VERSION_AR_RELEASE_MINOR_VERSION != \
    GPT_VERSION_C_AR_RELEASE_MINOR_VERSION)
#error "Gpt_Version.c : Mismatch in Specification Minor Version"
#endif

#if (GPT_VERSION_AR_RELEASE_REVISION_VERSION != \
    GPT_VERSION_C_AR_RELEASE_REVISION_VERSION)
#error "Gpt_Version.c : Mismatch in Specification Patch Version"
#endif

#if (GPT_VERSION_SW_MAJOR_VERSION != GPT_VERSION_C_SW_MAJOR_VERSION)
#error "Gpt_Version.c : Mismatch in Major Version"
#endif

#if (GPT_VERSION_SW_MINOR_VERSION != GPT_VERSION_C_SW_MINOR_VERSION)
#error "Gpt_Version.c : Mismatch in Minor Version"
#endif

/* Implements GPT_ESDD_UD_056 */
#if (GPT_VERSION_CHECK_EXT_MODULES == STD_ON)
/* Condition for GPT_VERSION_CHECK_EXT_MODULES */

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) \
    || (RTE_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* End of GPT_CRITICAL_SECTION_PROTECTION */

/* Dem Module Version Check */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) \
    || (DEM_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Dem.h does not match the expected version"
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) \
    || (DET_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif
#endif /* End of GPT_DEV_ERROR_DETECT */

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if ((ECUM_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) \
    || (ECUM_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION))
#error "The AR version of EcuM.h does not match the expected version"
#endif
#endif /* End of GPT_REPORT_WAKEUP_SOURCE */

#if ((OS_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) \
    || (OS_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Os.h does not match the expected version"
#endif

#endif /* End of GPT_VERSION_CHECK_EXT_MODULES */

/*******************************************************************************
 **                         Global Data                                       **
 ******************************************************************************/

/*******************************************************************************
 **                      Function Definitions                                 **
 ******************************************************************************/

/*******************************************************************************
 **                          End of File                                      **
 ******************************************************************************/
