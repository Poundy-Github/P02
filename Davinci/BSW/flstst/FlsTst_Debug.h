/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst_Debug.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 Renesas Electronics Corporation                          */
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
 * V1.0.0:  20-Nov-2013    : Initial Version
 */
/******************************************************************************/
/* FLSTST_DEBUG_H_001: EAAR_PN0034_FR_0001                                    */
#ifndef FLSTST_DEBUG_H
#define FLSTST_DEBUG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for FlsTst.h inclusion and macro definitions */
#include "FlsTst_PBTypes.h"
/*
 * Since all the debug variables will be available in FlsTst_Ram.h it is
 * included.
 */
#include "FlsTst_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define FLSTST_DEBUG_AR_RELEASE_MAJOR_VERSION    FLSTST_AR_RELEASE_MAJOR_VERSION
#define FLSTST_DEBUG_AR_RELEASE_MINOR_VERSION    FLSTST_AR_RELEASE_MINOR_VERSION
#define FLSTST_DEBUG_AR_RELEASE_REVISION_VERSION \
                                              FLSTST_AR_RELEASE_REVISION_VERSION

/* FLSTST_DEBUG_H_002: EAAR_PN0034_FR_0055                                    */
/* Module Software version information */
#define FLSTST_DEBUG_SW_MAJOR_VERSION   FLSTST_SW_MAJOR_VERSION
#define FLSTST_DEBUG_SW_MINOR_VERSION   FLSTST_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* FLSTST_DEBUG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
