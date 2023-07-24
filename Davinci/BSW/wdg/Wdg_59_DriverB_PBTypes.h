/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverB_PBTypes.h                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post Build time Parameters      */
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
 * V2.0.0   25-Aug-2016    : Changed according to #ARDAABD-653
 *                           1. ASR 3.2.2 was removed and 4.2.2 added
 * V2.0.1   26-Oct-2016    : Version Fix
 * V2.0.2   14-Dec-2016    : Changed according to #ARDAABD-851
 * V2.0.3   16-Jan-2017    : Changed after code review
 *                           WDG_59_DRIVERB_INIT_VAL added
 * V2.0.4   23-Feb-2017    : #ARDAABD-568
 *                           1. Removed WDG_59_DRIVERB_DEM_TYPE and
 *                           WDG_59_DRIVERB_DEM_TYPE macro definition.
 *                           Macro usage was related to Autosar 3.2.2.
 * V2.0.5   01-Mar-2017    : #ARDAABD-832
 *                           1. Removed definition of WDG_59_DRIVERB_INIT_VAL
 * V2.0.6   15-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.0.7   15-Jun-2017    : As part of ARDAABD-1897 Jira ticket, code was
 *                           updated after QAC analysis
 * V2.0.8   06-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1523 Jira ticket, Macros
 *                              function WDG_59_DRIVERB_EXCLUDE_CRITICAL_SECTION
 *                              and WDG_59_DRIVERB_INCLUDE_CRITICAL_SECTION are
 *                              added to include and exclude critical section
 *                              from APIs.
 *                           2. As part of JIRA ticket ARDAABD-1832, macros
 *                             'WDG_59_DRIVERB_ONE','WDG_59_DRIVERB_THREE' and
 *                             'WDTAMD_WIE_MASK' are added to compare with
 *                              values one, three and WIE bit mask values.
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERB_PBTYPES_H
#define WDG_59_DRIVERB_PBTYPES_H

/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information */
#include "Wdg_59_DriverB.h"
#include "Wdg_59_DriverB_Hardware.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* WDG_59_DRIVERB_PBTYPES_H_001: WDG_ESDD_UD_042                              */
/* WDG_59_DRIVERB_PBTYPES_H_002: WDG159                                       */
/* WDG_59_DRIVERB_PBTYPES_H_003: SWS_Wdg_00159                                */
/* WDG_59_DRIVERB_PBTYPES_H_004: AR_PN0064_FR_0034, AR_PN0064_FR_0035         */
/* WDG_59_DRIVERB_PBTYPES_H_005: AR_PN0064_FR_0050, AR_PN0034_FR_0067         */
/* WDG_59_DRIVERB_PBTYPES_H_006: IMP_F1x_V3.03.06_WDG_RS_1                    */

/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERB_PBTYPES_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERB_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERB_PBTYPES_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERB_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERB_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERB_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERB_PBTYPES_SW_MAJOR_VERSION  WDG_59_DRIVERB_SW_MAJOR_VERSION
#define WDG_59_DRIVERB_PBTYPES_SW_MINOR_VERSION  WDG_59_DRIVERB_SW_MINOR_VERSION

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Type definition for trigger mode */
#define WDG_59_DRIVERB_WINDOW          1

/* Macros for watchdog driver execution area */
#define WDG_59_DRIVERB_RAM             0
#define WDG_59_DRIVERB_ROM             1

/* General defines */
#define WDG_59_DRIVERB_DBTOC_VALUE \
                                ((((uint32) WDG_59_DRIVERB_VENDOR_ID) << 22) | \
                                 (((uint32)WDG_59_DRIVERB_MODULE_ID) << 14) | \
                             ((uint32)(WDG_59_DRIVERB_SW_MAJOR_VERSION) << 8) |\
                             (((uint32)WDG_59_DRIVERB_SW_MINOR_VERSION) << 3))

/*
 * Value to be written to WDTAWDTE / WDTAEVAC register to clear and restart
 * the timer.
 */
#define WDG_59_DRIVERB_RESTART         (uint8)0xAC

/* Macro for compare with zero,one,three */
#define WDG_59_DRIVERB_ZERO            (uint8)0x00
#define WDG_59_DRIVERB_ONE             (uint8)0x01
#define WDG_59_DRIVERB_THREE           (uint8)0x03
/* WIE bit mask value */
#define WDTAMD_WIE_MASK                (uint8)0x08

/* 75% interrupt mask values */
#define WDG_59_DRIVERB_75INTERRUPT_MASK      (uint8)0x08

/* Macros to exclude and include critical section */
#define WDG_59_DRIVERB_EXCLUDE_CRITICAL_SECTION    (boolean)0x00
#define WDG_59_DRIVERB_INCLUDE_CRITICAL_SECTION    (boolean)0x01

/* Watchdog error type macro */
#define WDG_59_DRIVERB_RESET_MODE      0
#define WDG_59_DRIVERB_NMI_MODE        1

/* MISRA Violation: START Msg(4:3412)-1 */
#if (WDG_59_DRIVERB_CRITICAL_SECTION_PROTECTION == STD_ON)

#define WDG_59_DRIVERB_ENTER_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Enter_Wdg_59_DriverB_##Exclusive_Area()

#define WDG_59_DRIVERB_EXIT_CRITICAL_SECTION(Exclusive_Area) \
SchM_Exit_Wdg_59_DriverB_##Exclusive_Area()

/* END Msg(4:3412)-1 */
#endif

#endif /* WDG_59_DRIVERB_PBTYPES_H */
/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
