/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Version.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by GPT Driver                                                     */
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
 */
/******************************************************************************/
#ifndef GPT_VERSION_H
#define GPT_VERSION_H
/* GPT_VERSION_H_001: EAAR_PN0034_FR_0001 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* Included for Gpt.h inclusion and macro definitions */
#include "Gpt.h"

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */
/* OS module version information is required */
#include "Rte.h"
#endif /*END of GPT_CRITICAL_SECTION_PROTECTION*/

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
/*
 * EcuM module version information is required only when wakeup source is
 * enabled
 */
#include "EcuM.h"
#endif
/* OS module version information is required */
#include "Os.h"
/* GPT_VERSION_H_002: GPT172 */
#include "Dem.h"

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* GPT_VERSION_H_003: EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_VERSION_AR_RELEASE_MAJOR_VERSION  \
    GPT_AR_RELEASE_MAJOR_VERSION
#define GPT_VERSION_AR_RELEASE_MINOR_VERSION  \
    GPT_AR_RELEASE_MINOR_VERSION
#define GPT_VERSION_AR_RELEASE_REVISION_VERSION  \
    GPT_AR_RELEASE_REVISION_VERSION

/* File version information */
#define GPT_VERSION_SW_MAJOR_VERSION    GPT_SW_MAJOR_VERSION
#define GPT_VERSION_SW_MINOR_VERSION    GPT_SW_MINOR_VERSION

/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/

/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-1 and                           */
/*                 END Msg(4:0857)-1 tags in the code.                        */
/******************************************************************************/

#endif /* GPT_VERSION_H */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
