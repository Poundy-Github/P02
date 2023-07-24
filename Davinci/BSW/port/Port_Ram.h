/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Ram.h                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of PORT */
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

/* PORT_RAM_H_005: EAAR_PN0034_NR_0045 */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Sep-2015  : Initial Version
 *
 * V2.0.0:  08-Sep-2016  : As part of ARDAABC-757 Jira Ticket, the following
 *                         changes are made:
 *                         1. Added arrays for RAM Mirroring
 *                         2. Added custom types for RAM Mirroring in order to
 *                            reduce RAM usage.
 * V2.1.0:  20-Oct-2016  : As part of ARDAABC-621 Jira ticket, the following
 *                         changes are made:
 *                         1. Changed AUTOSAR lower version to 4.0.3 and
 *                            higher version to 4.2.2. Removed Autosar 3.2.2
 *                            from implementation.
 * V2.2.0:  14-Nov-2016  : As part of ARDAABC-542 Jira ticket the following
 *                         changes are made:
 *                         1. Include MemMap header file from "Port_Cfg.h".
 *                         2. Use precompile switches to select different
 *                            memory section names in AR4.0.3 and AR4.2.2.
 * V2.3.0:  18-Nov-2016  : As part of ARDAABC-757 Jira Ticket, the following
 *                         changes are made:
 *                         1. RAM Mirroring types were moved to Port_Types.h.
 * V2.3.1:  24-Nov-2016  : As part of ARDAABC-757 Jira Ticket, the following
 *                         changes are made:
 *                         1. RAM Mirroring array for analog port groups was
 *                         removed.
 * V2.3.2:  03-Oct-2017  : As part of JIRA ARDAABD-2549, The global variable
 *                         Port_GblDriverStatus is declared as volatile.
 * V2.3.3:  21-Jun-2018  : As part of ARDAABD-3844 Jira Ticket, the following
 *                         changes are made:
 *                         1. Requirements and Design ID's are mapped to the
 *                         implementation in order to improve coverage.
 * V2.3.4:  05-JuL-2019  : As part of ARDAABD-4140, following changes are made:
 *                         1. Change
 *                            PORT_START_SEC_VAR_ASIL_B_NO_INIT_UNSPECIFIED to
 *                            PORT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED.
 *                         2. Copyright was updated.
 */
/******************************************************************************/
/* PORT_RAM_H_001: EAAR_PN0034_FR_0001 */
#ifndef PORT_RAM_H
#define PORT_RAM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PORT_RAM_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_RAM_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION
#define PORT_RAM_AR_RELEASE_REVISION_VERSION \
                                          PORT_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define PORT_RAM_SW_MAJOR_VERSION  PORT_SW_MAJOR_VERSION
#define PORT_RAM_SW_MINOR_VERSION  PORT_SW_MINOR_VERSION
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* PORT_RAM_H_006: EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0828) [L] More than 8 levels of nested conditional      */
/*                 inclusion - program does not conform strictly to ISO:C90.  */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : This is due to the counting of nested condition on the     */
/*                 common files which share other modules                     */
/* Verification  : However, part of the code is verified manually and         */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0828)-1 and                           */
/*                 END Msg(4:0828)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (PORT_DEV_ERROR_DETECT == STD_ON)

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define PORT_START_SEC_VAR_INIT_BOOLEAN
#endif

#include PORT_MEMMAP_FILE
/* PORT_RAM_H_002: PORT_ESDD_UD_070 */
/* Global variable to store Initialization status of Port Driver Component */
extern VAR (volatile boolean, PORT_INIT_DATA) Port_GblDriverStatus;

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define PORT_STOP_SEC_VAR_INIT_BOOLEAN
#endif

#include PORT_MEMMAP_FILE

#endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE
/* PORT_RAM_H_003: PORT_ESDD_UD_070 */
/* Global variable to store pointer to Configuration */
extern P2CONST(Port_ConfigType, PORT_VAR, PORT_CONFIG_CONST)
                                             Port_GpConfigPtr;
/* PORT_RAM_H_004: PORT_ESDD_UD_142 */
#if (PORT_RAM_MIRROR == PORT_RAM_MIRROR_ENABLE)
/* Indicates the Port Registers Ram Mirror for Hardware Consistency Check */
#if (PORT_NUM_PORT_GROUPS_AVAILABLE)
extern VAR(Port_NumRegRamMirror, PORT_NOINIT_DATA)
                    Port_GstRamMirrorPortReg[PORT_NUM_PORT_INSTANCES];
#endif /* (PORT_NUM_PORT_GROUPS_AVAILABLE) */
#if (PORT_JTAG_PORT_GROUPS_AVAILABLE)
extern VAR(Port_JTAGRegRamMirror, PORT_NOINIT_DATA)
                    Port_GstRamMirrorJPortReg;
#endif /* (PORT_JTAG_PORT_GROUPS_AVAILABLE) */
#endif

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
