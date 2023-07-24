/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Ram.c                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Global variable definitions for Core Test Component.          */
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
 * V1.0.0: 27-Nov-2013    : Initial Version
 *
 * V1.0.1: 19-Jun-2014    : As per CR 525 for Mantis #21575, following changes
 *                          are made:
 *                          1. The Copyright information is updated.
 *                          2. Memory mapping section for declaration of
 *                             variable 'CorTst_GenExeStatus' is corrected.
 *
 * V1.0.2: 09-Sep-2014    : As per CR 604 for Mantis issue #22252, File is
 *                          updated for including Autosar R3.2 version check and
 *                          information details.
 * V2.0.0:  31-Aug-2016    : #ARDAABD-476
 *                           1. Updated to ASR 4.2.2
 * V2.0.1:  07-Sep-2016    : #ARDAABD-495
 *                           1. Updated copyright year and revision history
 * V2.0.2:  22-Sep-2016    : #ARDAABD-476
 *                           1. Improved MemMap inclusion for 4.0.3 and 4.2.2
 * V2.0.3:  14-Aug-2017    : Added justifications for QAC Warning which cannot
 *                           be removed.
 * V2.0.4:  19-June-2018    : The following changes are made:
 *                           1.As part of merging activity, #ARDAABD-3477
 *                             a.CORTST_START_SEC_VAR_UNSPECIFIED has been
 *                                changed as CORTST_START_SEC_VAR_INIT_8.
 *                             b.CORTST_STOP_SEC_VAR_UNSPECIFIED has been
 *                                changed as CORTST_STOP_SEC_VAR_INIT_8.
 *                             c.Updated copyright information.
 *                                Ref:ARDAABD-908.
 *                           2.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           3.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information and other types declarations */
#include "CorTst.h"
/* Included for RAM variable declarations */
#include "CorTst_Ram.h"

/*******************************************************************************
**                              QAC Warnings                                  **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:0862) This #include "MemMap.h" directive is redundant.  */
/* Justification : Each header has implemented safety for multiple inclusion. */
/*                 Header will not be included multiple times.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3211) The global identifier 'x' is defined here but is  */
/*                 not used in this translation unit.                         */
/* Justification : Implementation requirement as specified by AUTOSAR SW to   */
/*                 generate global variables and array for CorTst driver.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-3 and                           */
/*                 END Msg(2:3211)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:2022) A tentative definition is being used. It is       */
/*                 appropriate to include an explicit initializer?            */
/* Justification : Implementation requirement as specified by AUTOSAR SWS to  */
/*                 generate global variables and arrays for CorTst driver.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-4 and                           */
/*                 END Msg(2:2022)-4 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define CORTST_RAM_C_AR_RELEASE_MAJOR_VERSION \
                                           CORTST_AR_RELEASE_MAJOR_VERSION_VALUE
#define CORTST_RAM_C_AR_RELEASE_MINOR_VERSION \
                                           CORTST_AR_RELEASE_MINOR_VERSION_VALUE
#define CORTST_RAM_C_AR_RELEASE_REVISION_VERSION \
                                        CORTST_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define CORTST_RAM_C_SW_MAJOR_VERSION   CORTST_SW_MAJOR_VERSION_VALUE
#define CORTST_RAM_C_SW_MINOR_VERSION   CORTST_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CORTST_RAM_AR_RELEASE_MAJOR_VERSION != \
                     CORTST_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "CorTst_Ram.c : Mismatch in Release Major Version"
#endif
#if (CORTST_RAM_AR_RELEASE_MINOR_VERSION != \
                    CORTST_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "CorTst_Ram.c : Mismatch in Release Minor Version"
#endif
#if (CORTST_RAM_AR_RELEASE_REVISION_VERSION != \
                                      CORTST_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "CorTst_Ram.c : Mismatch in Release Revision Version"
#endif

#if (CORTST_RAM_SW_MAJOR_VERSION != CORTST_RAM_C_SW_MAJOR_VERSION)
  #error "CorTst_Ram.c : Mismatch in Software Major Version"
#endif
#if (CORTST_RAM_SW_MINOR_VERSION != CORTST_RAM_C_SW_MINOR_VERSION)
  #error "CorTst_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define CORTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* QAC Warning: START Msg(2:2022)-4 */
/* QAC Warning: START Msg(2:3211)-3 */
/* Pointer variable to hold base address of the BG mode selection configured */
P2CONST(boolean, CORTST_VAR, CORTST_CONFIG_CONST) CorTst_GpSTModule;
/* END Msg(2:3211)-3 */
/* END Msg(2:2022)-4 */

/* QAC Warning: START Msg(2:2022)-4 */
/* QAC Warning: START Msg(2:3211)-3 */
/*  Variable to store all global variables as a structure */
VAR(CorTst_GVariable, CORTST_NOINIT_DATA) CorTst_GVar;
/* END Msg(2:3211)-3 */
/* END Msg(2:2022)-4 */

#define CORTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define CORTST_START_SEC_VAR_INIT_8
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements   CORTST_ESDD_UD_060                                            */
/* Implements   EAAR_PN0077_FR_0013                                           */
/* Implements   CorTst144, SWS_CorTst_00144                                   */
/* Implements   SWS_CorTst_00008                                              */
/* QAC Warning: START Msg(2:3211)-3 */
/* Variable to store CORTST execution state */
VAR(CorTst_StateType, CORTST_INIT_DATA)CorTst_GenExeStatus = CORTST_UNINIT;
/* END Msg(2:3211)-3 */

#define CORTST_STOP_SEC_VAR_INIT_8
/* QAC Warning: START Msg(2:0862)-2 */
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
