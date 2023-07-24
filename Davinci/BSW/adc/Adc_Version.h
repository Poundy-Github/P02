/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Version.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by ADC Driver                                                     */
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

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V2.0.0:  28-Oct-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.0.1:  27-Jun-2018     : Following change is made:
 *                            1.As part of merging activity ticket ARDAABD-3452,
 *                              a.Heading for MISRA rule violations is
 *                                corrected.
 *                              b.Copyright updated.
 *                            2.As part of traceability improvement activity
 *                              ticket ARDAABD-2101, requirements and UD Ids
 *                              are added.
 */
/******************************************************************************/
/* Implements EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (6:0857)Number of macro definitions exceeds 1024 - program */
/*                 does not conform strictly to ISO:C99.                      */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(6:0857)-1 and                           */
/*                 END Msg(6:0857)-1 tags in the code.                        */
/******************************************************************************/
/* ADC_VERSION_H_003: EAAR_PN0034_FR_0001 */
#ifndef ADC_VERSION_H
#define ADC_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* ADC_VERSION_H_005: ADC267, ADC239, SWS_Adc_00267, ADC235 */
/* Adc module version information is required for inter module version check */
#include "Adc.h"
#include "Dem.h"
/* ADC_VERSION_H_001 ADC_ESDD_UD_003 */
/* ADC_VERSION_H_002 EAAR_PN0034_FR_0064 */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
/* DEM module version information is required */
/* ADC_VERSION_H_001 ADC_ESDD_UD_034 */
#if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
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
/* AUTOSAR release version information */
#define ADC_VERSION_AR_RELEASE_MAJOR_VERSION    ADC_AR_RELEASE_MAJOR_VERSION
#define ADC_VERSION_AR_RELEASE_MINOR_VERSION    ADC_AR_RELEASE_MINOR_VERSION
#define ADC_VERSION_AR_RELEASE_REVISION_VERSION ADC_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define ADC_VERSION_SW_MAJOR_VERSION  ADC_SW_MAJOR_VERSION
#define ADC_VERSION_SW_MINOR_VERSION  ADC_SW_MINOR_VERSION

#endif /* ADC_VERSION_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
