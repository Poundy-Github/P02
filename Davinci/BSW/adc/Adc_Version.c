/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Version.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for modules included by ADC   */
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
/* Implements EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */
/* Implements AR_PN0076_FR_0027 */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V2.0.0:  28-Oct-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.0.1:  27-Jun-2018    : Following change made:
 *                            As part of traceability improvement activity
 *                            ticket ARDAABD-2101, requirements and UD Ids are
 *                            added.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements: ADC267, SWS_Adc_00267 */
/*
 * Included for Adc module version information and other modules version
 * information
 */
#include "Adc_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ADC_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                  ADC_AR_RELEASE_MAJOR_VERSION_VALUE
#define ADC_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                  ADC_AR_RELEASE_MINOR_VERSION_VALUE
#define ADC_VERSION_C_AR_RELEASE_REVISION_VERSION \
                               ADC_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ADC_VERSION_C_SW_MAJOR_VERSION    ADC_SW_MAJOR_VERSION_VALUE
#define ADC_VERSION_C_SW_MINOR_VERSION    ADC_SW_MINOR_VERSION_VALUE

/* Implements EAAR_PN0034_FR_0055 */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ADC_VERSION_AR_RELEASE_MAJOR_VERSION != \
                              ADC_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Adc_Version.c : Mismatch in Release Major Version"
#endif

#if (ADC_VERSION_AR_RELEASE_MINOR_VERSION != \
                              ADC_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Adc_Version.c : Mismatch in Release Minor Version"
#endif

#if (ADC_VERSION_AR_RELEASE_REVISION_VERSION != \
                           ADC_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Adc_Version.c : Mismatch in Release Revision Version"
#endif

#if (ADC_VERSION_SW_MAJOR_VERSION != ADC_VERSION_C_SW_MAJOR_VERSION)
  #error "Adc_Version.c : Mismatch in Software Major Version"
#endif
#if (ADC_VERSION_SW_MINOR_VERSION != ADC_VERSION_C_SW_MINOR_VERSION)
  #error "Adc_Version.c : Mismatch in Software Minor Version"
#endif

/* Implements ADC_ESDD_UD_037, ADC124 */
#if (ADC_VERSION_CHECK_EXT_MODULES == STD_ON)
#if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (RTE_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif /* End of RTE */
#endif /* End of ADC_CRITICAL_SECTION_PROTECTION */

/* Implements ADC_ESDD_UD_003 */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (DET_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif /* End of DET */
#endif /* End of ADC_DEV_ERROR_DETECT */

#if ((DEM_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif /* End of DET */

#if ((OS_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (OS_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Os.h does not match the expected version"
#endif /* End of OS */

#endif /* End of ADC_VERSION_CHECK_EXT_MODULES */

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
