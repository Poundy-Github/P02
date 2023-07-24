/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverB_Debug.h                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2016 Renesas Electronics Corporation                     */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  03-Sep-2015    : Initial Version
 * V2.0.0:  26-Oct-2016    : Copyright information updated
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERB_DEBUG_H
#define WDG_59_DRIVERB_DEBUG_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/*
 * Since all the debug variables will be available in Wdg_59_DriverB_Ram.h it
 * is included.
 */
#include "Wdg_59_DriverB_Ram.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR release version information */
#define WDG_59_DRIVERB_DEBUG_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERB_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERB_DEBUG_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERB_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERB_DEBUG_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERB_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERB_DEBUG_SW_MAJOR_VERSION   WDG_59_DRIVERB_SW_MAJOR_VERSION
#define WDG_59_DRIVERB_DEBUG_SW_MINOR_VERSION   WDG_59_DRIVERB_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* WDG_59_DRIVERB_DEBUG_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
