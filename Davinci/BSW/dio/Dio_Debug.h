/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Debug.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of global variables for debugging purpose.                       */
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
 * V1.0.0:  02-Sep-2015  : Initial Version
 *
 * V2.0.0:  27-Oct-2016  : As part of ARDAABC-626 and ARDAABC-882 Jira Ticket,
 *                         the following changes are made:
 *                         1) Removed AR 3.2.2 related functionality and
 *                            added AR 4.2.2 where applicable.
 * V2.0.1   06-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Updated copyright dates
 * V2.0.2   24-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Header comment updated due to acceptance team
 *                            comment
 * V2.0.3   13-Jul-2017  : Following changes are made:
 *                         1) As part of ARDAABD-1751, precompile switches
 *                            added for inclusion of Dio_PBTypes.h and
 *                            Dio_LTTypes.h.
 * V2.0.4   18-Jul-2018 :Following changes are made:
 *                        1) As part of ARDAABD-3851 to improve traceability,
 *                           added missing requirements from requirement
 *                           documents.
 *                        2) Updated copyright year.
 */
/******************************************************************************/
/* DIO_DEBUG_H_001: EAAR_PN0034_FR_0001, DIO160, DIO162, DIO163 */
#ifndef DIO_DEBUG_H
#define DIO_DEBUG_H

/*******************************************************************************
 **                     Include Section                                       **
 ******************************************************************************/
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Included for macro definitions and structure declarations */
#include "Dio_PBTypes.h"
#else
/* Included for macro definitions and structure declarations */
#include "Dio_LTTypes.h"
#endif
/*
 * Since all the debug variables will be available in Dio_Ram.h it is
 * included.
 */
#include "Dio_Ram.h"

/*******************************************************************************
 **                        Version Information                                **
 ******************************************************************************/
/* AUTOSAR release version information */
#define DIO_DEBUG_AR_RELEASE_MAJOR_VERSION      DIO_AR_RELEASE_MAJOR_VERSION
#define DIO_DEBUG_AR_RELEASE_MINOR_VERSION      DIO_AR_RELEASE_MINOR_VERSION
#define DIO_DEBUG_AR_RELEASE_REVISION_VERSION   DIO_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define DIO_DEBUG_SW_MAJOR_VERSION   DIO_SW_MAJOR_VERSION
#define DIO_DEBUG_SW_MINOR_VERSION   DIO_SW_MINOR_VERSION

/*******************************************************************************
 **                      Global Data Types                                    **
 ******************************************************************************/

/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/

#endif
/* DIO_DEBUG_H */

/*******************************************************************************
 **                          End Of File                                      **
 ******************************************************************************/
