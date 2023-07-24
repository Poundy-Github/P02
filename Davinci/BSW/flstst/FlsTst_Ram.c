/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst_Ram.c                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Global variable definitions for FlashTest Component.          */
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
 * V1.0.0: 20-Nov-2013    : Initial Version
 *
 * V1.0.1: 03-Feb-2014    : As per CR78 and mantis #17998
 *                           following changes are made:
 *                           1. Copyright information is updated.
 *                           2. Global variable FlsTst_GenExeState is changed to
 *                              volatile.
 *
 * V1.0.2: 18-Jun-2014    : As per CR524 and mantis #21575, memory mapping
 *                          sections of variables are updated.
 *
 * V1.0.3: 18-Sep-2014    : As per CR12, As per Renesas coding guidelines,
 *                          Markers are added for Tracing.
 * V2.0.0: 28-Oct-2016    : Changed memmap file handling (ASR4.2.2 compliant).
 *                          Replaced FLSTST_MIRROR_ENABLE with FLSTST_ENABLE
 *                          Removed FLSTST_DCRACOUT_RESET_VAL and
 *                          FLSTST_DCRACOUT_RESET_VAL from FlsTst_RamMirror
 *                          Added compiler switch for FlsTst_RamMirror
 *                          optional registers
 * V2.0.1: 16-Mar-2017    : 1. As part of JIRA ARDAABD-496: Updated
 *                          FlsTst_RamMirror regarding the number
 *                          of mirrored registers
 *                          2. As part of JIRA ARDAABD-408: Updated memclass and
 *                          memory selector for FlsTst_RamMirror,
 *                          FlsTst_GenLastFgndResult and
 *                          FlsTst_GenOverallBgndResult
 *                          3. As part of JIRA ARDAABD-1211: Added traceability
 *                          information
 *                          4. FlsTst_GblTestComplete added
 * V2.0.2: 28-Aug-2017    : Added justifications for MISRA Violations and QAC
 *                          Warnings which cannot be removed. Removed tags and
 *                          justification for MISRA Violation message (4:3138).
 * V2.0.3: 12-Jan-2018    : As part of ARDAABD-908, following changes are made:
 *                          1. The memory sections,
 *                          FLSTST_<START/STOP>_SEC_VAR_32 and
 *                          FLSTST_<START/STOP>_SEC_VAR_UNSPECIFIED removed and
 *                          replaced with FLSTST_<START/STOP>_SEC_VAR_INIT_32,
 *                          and FLSTST_<START/STOP>_SEC_VAR_INIT_UNSPECIFIED
 *                          respectively. Added new memory section
 *                          FLSTST_<START/STOP>_SEC_VAR_NO_INIT_BOOLEAN for
 *                          FlsTst_GblTestComplete variable.
 *                          2. Added justifications for QAC warnings.
 *                          3. Copyright information is updated.
 * V2.0.4: 21-Jun-2018    : As part of #ARDAABD-3842, Removed duplicate
 *                          Requirement id's and mapped the required
 *                          Requirements for traceability
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information and other types declarations */
#include "FlsTst.h"
/* Included for RAM variable declarations */
#include "FlsTst_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define FLSTST_RAM_C_AR_RELEASE_MAJOR_VERSION \
                                           FLSTST_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLSTST_RAM_C_AR_RELEASE_MINOR_VERSION \
                                           FLSTST_AR_RELEASE_MINOR_VERSION_VALUE
#define FLSTST_RAM_C_AR_RELEASE_REVISION_VERSION \
                                        FLSTST_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define FLSTST_RAM_C_SW_MAJOR_VERSION   FLSTST_SW_MAJOR_VERSION_VALUE
#define FLSTST_RAM_C_SW_MINOR_VERSION   FLSTST_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* TRACE [R4, FlsTst134] */
#if (FLSTST_RAM_AR_RELEASE_MAJOR_VERSION != \
                     FLSTST_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "FlsTst_Ram.c : Mismatch in Release Major Version"
#endif
#if (FLSTST_RAM_AR_RELEASE_MINOR_VERSION != \
                    FLSTST_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "FlsTst_Ram.c : Mismatch in Release Minor Version"
#endif
#if (FLSTST_RAM_AR_RELEASE_REVISION_VERSION != \
                                      FLSTST_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "FlsTst_Ram.c : Mismatch in Release Revision Version"
#endif

#if (FLSTST_RAM_SW_MAJOR_VERSION != FLSTST_RAM_C_SW_MAJOR_VERSION)
  #error "FlsTst_Ram.c : Mismatch in Software Major Version"
#endif
#if (FLSTST_RAM_SW_MINOR_VERSION != FLSTST_RAM_C_SW_MINOR_VERSION)
  #error "FlsTst_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
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
/* Message       : (2:2022) A tentative definition is being used. Is it       */
/*                 appropriate to include an explicit initializer ?           */
/* Justification : If there are no definitions in the same translation unit   */
/*                 then the tentative definition acts as an actual definition */
/*                 Has no functional impact.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-2 and                           */
/*                 END Msg(2:2022)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3211) The global identifier '%s' is defined here but    */
/*                 is not used in this translation unit.                      */
/* Justification : If there are no definitions in the same translation unit   */
/*                 in other translation file                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-3 and                           */
/*                 END Msg(2:3211)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type.                                           */
/* Justification : Direct register access by cast of register address to      */
/*                 volatile register type.                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-4 and                           */
/*                 END Msg(2:3892)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:0862) This #include "MemMap.h" directive is redundant.  */
/* Justification : Each header has implemented safety for multiple inclusion. */
/*                 Header will not be included multiple times.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-5 and                           */
/*                 END Msg(2:0862)-5 tags in the code.                        */
/******************************************************************************/
/******************************************************************************/
/* Implements: FLSTST_ESDD_UD_008                                             */
/* Implements: EAAR_PN0034_NR_0088                                            */

#define FLSTST_START_SEC_VAR_NO_INIT_BOOLEAN
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
/* Variable to store the test execution status*/
VAR(uint8, FLSTST_NOINIT_DATA)FlsTst_GblTestComplete;
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */

#define FLSTST_STOP_SEC_VAR_NO_INIT_BOOLEAN
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_VAR_NO_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Variable to store the interval id for bgnd test*/
/* Implements: FLSTST_ESDD_UD_070                                             */
/* Implements:  FlsTst144                                                     */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(uint32, FLSTST_NOINIT_DATA) FlsTst_GulTestIntervalId;
/* Variable to store the last signature for fgnd test */
/* Implements: FLSTST_ESDD_UD_066                                             */
/* Implements:  FlsTst144                                                     */
VAR(uint32, FLSTST_NOINIT_DATA) FlsTst_GulLastFgndSignature;
/* Variable to store the last signature for Bgnd test */
/* Implements: FLSTST_ESDD_UD_067                                             */
/* Implements:  FlsTst144                                                     */
VAR(uint32, FLSTST_NOINIT_DATA) FlsTst_GulLastBgndSignature;
/* Variable to store the Ecc test failed address  */
VAR(uint32, FLSTST_NOINIT_DATA)FlsTst_GulEccErrorAddress;
/* Variable to store the test execution status*/
VAR(uint8, FLSTST_NOINIT_DATA)FlsTst_GblTestComplete;
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */
#define FLSTST_STOP_SEC_VAR_NO_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_VAR_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* QAC Warning: START Msg(2:3211)-3 */
#if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)
/* Variable to store the registers values in RAM  */
/* END Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(uint32, FLSTST_INIT_DATA)FlsTst_RamMirror[FLSTS_NB_OF_MIRRORED_REGS] =
/* END Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:3892)-4 */
{
  FLSTST_LONG_WORD_ZERO,
  FLSTST_LONG_WORD_ZERO,
#if(FLSTST_TEST_ECC_API == STD_ON)
  CFECCCTL_VCI_DEFAULT,
  CFERRINT_VCI_DEFAULT
#endif
};
/* END Msg(2:3892)-4 */

#endif

#define FLSTST_STOP_SEC_VAR_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Variable to store the Ecc test result  */
/* QAC Warning: START Msg(2:2022)-2 */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(FlsTst_ErrorDetailsType, FLSTST_NOINIT_DATA)FlsTst_GddEccErrorDetail;
/*  Variable to store all global variables as a structure */
VAR(FlsTst_GVarProperties, FLSTST_NOINIT_DATA) FlsTst_GVar;
/* Global variable to store the config pointer */
P2CONST(FlsTst_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST) FlsTst_GpConfigPtr;
/* pointer Variable to load the base address of the Fgnd test block configured*/
P2CONST(FlsTstBlock_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST)
                                                      FlsTst_GpBgndBlkConfig;
/* pointer Variable to load the base address of the Fgnd test block configured*/
P2CONST(FlsTstBlock_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST)
                                                      FlsTst_GpFgndBlkConfig;
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */
#define FLSTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_VAR_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* variable  to store  FlsTst execution  state  */
/* Implements:  FLSTST_ESDD_UD_065                                            */
/* Implements:  FlsTst144                                                     */
/* QAC Warning: START Msg(2:3211)-3 */
VAR(volatile FlsTst_StateType, FLSTST_INIT_DATA)FlsTst_GenExeState
                                                                = FLSTST_UNINIT;
/* Variable to store the fgnd test result  */
/* Implements:  FLSTST_ESDD_UD_069                                            */
VAR(FlsTst_TestResultFgndType, FLSTST_INIT_DATA)FlsTst_GenLastFgndResult
                                                            = FLSTST_NOT_TESTED;
/* TRACE [R4, FlsTst154] */
/* Variable to store the overall Bgnd test result  */
/* Implements: FLSTST_ESDD_UD_068                                             */
/* Implements: FlsTst154                                                      */
VAR(FlsTst_TestResultType, FLSTST_INIT_DATA)FlsTst_GenOverallBgndResult
                                                     = FLSTST_RESULT_NOT_TESTED;
/* END Msg(2:3211)-3 */
#define FLSTST_STOP_SEC_VAR_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:0862)-5 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */



/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
/* END Msg(2:0862)-5 */
