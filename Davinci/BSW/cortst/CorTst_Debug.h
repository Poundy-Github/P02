/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Debug.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2016 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Global Variables for debugging purpose.                       */
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
 * V1.0.0:  27-Nov-2013    : Initial Version
 *
 * V2.0.0:  09-Sep-2014    : As per CR 604 for Mantis issue #22252, following
 *                           changes are made:
 *                           1. The Copyright information is updated.
 *                           2. File is updated for including Autosar R3.2
 *                              version information details.
 * V2.0.1:  07-Aug-2016    : #ARDAABD-476
 *                           1. Updated to ASR 4.2.2
 */
/******************************************************************************/
#ifndef CORTST_DEBUG_H
#define CORTST_DEBUG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for macro definitions and structure declarations */
/* CORTST_DEBUG_H_001: CorTst146, CorTst0174, CorTst0175, CorTst147, CorTst148*/
#include "CorTst_Types.h"

/*
 * Since all the debug variables will be available in CorTst_Ram.h it is
 * included.
 */
#include "CorTst_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define CORTST_DEBUG_AR_RELEASE_MAJOR_VERSION   CORTST_AR_RELEASE_MAJOR_VERSION
#define CORTST_DEBUG_AR_RELEASE_MINOR_VERSION   CORTST_AR_RELEASE_MINOR_VERSION
#define CORTST_DEBUG_AR_RELEASE_REVISION_VERSION  \
                                              CORTST_AR_RELEASE_REVISION_VERSION

/* File version information */
#define CORTST_DEBUG_SW_MAJOR_VERSION    CORTST_SW_MAJOR_VERSION
#define CORTST_DEBUG_SW_MINOR_VERSION    CORTST_SW_MINOR_VERSION


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CORTST_DEBUG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
