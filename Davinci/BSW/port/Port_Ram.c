/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Ram.c                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Port Driver                            */
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

/* Implements EAAR_PN0034_NR_0045 */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Sep-2015  : Initial Version
 * V2.0.0:  20-Oct-2016  : As part of ARDAABC-621 Jira ticket, the following
 *                         changes are made:
 *                         1. Changed AUTOSAR lower version to 4.0.3 and
 *                            higher version to 4.2.2.
 *                         2. Removed Autosar 3.2.2 specific parts
 *                            from implementation.
 * V2.1.0:  14-Nov-2016  : As part of ARDAABC-542 Jira ticket the following
 *                         changes are made:
 *                         1. Include MemMap header file from "Port_Cfg.h".
 *                         2. Use precompile switches to select different
 *                            memory section names in AR4.0.3 and AR4.2.2.
 * V2.1.1:  24-Nov-2016  : As part of ARDAABC-757 Jira Ticket, the following
 *                         changes are made:
 *                         1. Removed RAM mirroring for analog port groups.
 *                         2. Updated precompile switches.
 * V2.1.2:  03-Oct-2017  : 1. As part of JIRA ARDAABD-2549, The global variable
 *                         Port_GblDriverStatus is declared as volatile.
 *                         2. Copyright information is updated.
 * V2.1.3:  21-Jun-2018  : As part of ARDAABD-3844 Jira Ticket, the following
 *                         changes are made:
 *                         1. Requirements and Design ID's are mapped to the
 *                         implementation in order to improve coverage.
 * V2.1.4:  05-JuL-2019  : As part of ARDAABD-4140, following changes are made:
 *                         1. Change
 *                            PORT_START_SEC_VAR_ASIL_B_NO_INIT_UNSPECIFIED to
 *                            PORT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED.
 *                         2. Copyright was updated.
 */
/******************************************************************************/
/* Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements PORT080, SWS_Port_00080 */
/* Included for Port.h inclusion and macro definitions */
#include "Port.h"
/* Header file inclusion */
#include "Port_Ram.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PORT_RAM_C_AR_RELEASE_MAJOR_VERSION \
                                             PORT_AR_RELEASE_MAJOR_VERSION_VALUE
#define PORT_RAM_C_AR_RELEASE_MINOR_VERSION \
                                             PORT_AR_RELEASE_MINOR_VERSION_VALUE
#define PORT_RAM_C_AR_RELEASE_REVISION_VERSION \
                                          PORT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define PORT_RAM_C_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION_VALUE
#define PORT_RAM_C_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PORT_RAM_AR_RELEASE_MAJOR_VERSION != \
                                            PORT_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port_Ram.c : Mismatch in Release Major Version"
#endif
#if (PORT_RAM_AR_RELEASE_MINOR_VERSION != \
                                            PORT_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Port_Ram.c : Mismatch in Release Minor Version"
#endif
#if (PORT_RAM_AR_RELEASE_REVISION_VERSION != \
                                         PORT_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Port_Ram.c : Mismatch in Release Revision Version"
#endif

#if (PORT_RAM_SW_MAJOR_VERSION != PORT_RAM_C_SW_MAJOR_VERSION)
   #error "Port_Ram.c : Mismatch in Software Major Version"
#endif
#if (PORT_RAM_SW_MINOR_VERSION != PORT_RAM_C_SW_MINOR_VERSION)
   #error "Port_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-1 and                           */
/*                 END Msg(4:0857)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (PORT_DEV_ERROR_DETECT == STD_ON)

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define PORT_START_SEC_VAR_INIT_BOOLEAN
#endif

#include PORT_MEMMAP_FILE

/* Global variable to store Initialization status of Port Driver Component */
/* Implements PORT200 */
VAR (volatile boolean, PORT_INIT_DATA) Port_GblDriverStatus =
                                                            PORT_UNINITIALIZED;

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

/* Global variable to store pointer to Configuration */
P2CONST(Port_ConfigType, PORT_VAR, PORT_CONFIG_CONST)Port_GpConfigPtr;

/* Implements PORT_ESDD_UD_142 */
/* Global variables for RAM mirror */
#if (PORT_RAM_MIRROR == PORT_RAM_MIRROR_ENABLE)
/* Indicates the Port Registers Ram Mirror for Hardware Consistency Check */
/* Implements PORT_ESDD_UD_018 */
#if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
VAR(Port_NumRegRamMirror, PORT_NOINIT_DATA)
                    Port_GstRamMirrorPortReg[PORT_NUM_PORT_INSTANCES];
#endif /* (PORT_NUM_PORT_GROUPS_AVAILABLE) */
/* Implements PORT_ESDD_UD_020 */
#if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
VAR(Port_JTAGRegRamMirror, PORT_NOINIT_DATA)
                    Port_GstRamMirrorJPortReg;
#endif /* (PORT_JTAG_PORT_GROUPS_AVAILABLE) */
#endif /* (PORT_RAM_MIRROR == PORT_RAM_MIRROR_ENABLE) */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  /* MISRA Violation: START Msg(4:0857)-1 */
  #define PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  /* END Msg(4:0857)-1 */
#endif
#include PORT_MEMMAP_FILE
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
