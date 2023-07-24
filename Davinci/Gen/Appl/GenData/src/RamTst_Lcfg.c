/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = RamTst_Lcfg.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2017 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains post-build time parameters.                             */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V1.0.0:  10-Oct-2013  : Initial Version
 * V1.0.1:  17-Feb-2014  : As per CR 076 for mantis #18116, Tool version
 *                         updated for merge activity.
 * V1.0.2:  08-May-2014  : As per CR 505, Unwanted new line at EOF removed.
 * V1.0.3:  11-Sep-2014  : As per CR 009 and mantis #19850, Changes are made at
 *                         all relevant places accordingly to append U or UL
 *                         after numeric values.
 * V1.0.4:  13-Feb-2015  : As part of merging activity (mantis #26024),
 *                         following changes are made:
 *                         1. P1X file is adapted from P1X branch.
 *                         2. Copyright information is updated.
 * V1.0.5:  10-Apr-2015  : As per mantis #23550,
 *                         1. MISRA C Rule Violations are added.
 * V2.0.0:  07-Nov-2016  : As part of ARDAABC-939 the following changes made
 *                         1. MemMap.h replaced with RAMTST_MEMMAP_FILE
 *                         2. Updated memory section names
 * V2.0.1:  16-Nov-2016  : As part of the review activity the variable
 *                         RamTst_TestResultBuffer moved into section
 *                         VAR_POWER_ON_INIT_UNSPECIFIED (ARDAABC-726)
 * V2.0.2:  07-Dec-2016  : As part of ARDAABC-588 the following changes made
 *                         1. New SWS_BSW_nnnnn traceability tags added.
 * V2.0.3:  18-Jul-2017  : As part of ARDAABD-1658 parameters
 *                         RamTstExtNumberOfTestedCells and
 *                         RamTstMaxNumberOfTestedCells swapped positions.
 * V2.0.4:  02-Aug-2017  : Justification added for QAC warnings which cannot
 *                         be removed. Updated code with corresponding tags.
 * V2.0.5:  08-Aug-2017  : Removed justification for invalid MISRA C Rule
 *                         Violation.
 * V2.0.6:  26-Sep-2017  : As part of ARDAABD-2319, the format of the generated
 *                         source file is changed, a static buffer is added for
 *                         NONDESTRUCTIVE mode and a added a pointer to the
 *                         buffer in the RamTst_BlockConfigType structure.
 *                         Added QAC message justification for (2:2022).
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.6
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-7459765\Generation\Cfg_Gen-1611131101098-0\AutosarFiles_ValGen173292231004072736\ExtGen_DrvRamTst_ECUC_4.2.2_8146757055081404526.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\ramtst\generator\R422_RAMTST_F1x_BSWMDT.arxml
 * GENERATED ON:  20 Jan 2021 - 19:11:56
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "RamTst.h"
#include "RamTst_Cbk.h"
#include "RamTst_Types.h"

/*******************************************************************************
**                             QAC Warnings                                   **
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
/* Message       : (2:0862) This #include 'MemMap.h' directive is redundant.  */
/* Justification : Each header has implemented safety for multiple inclusion. */
/*                 Header will not be included multiple times.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3132) Hard coded 'magic' number, 'x', used to define    */
/*                 the size of an array.                                      */
/* Justification : Implementation requirement for configurable array size.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3132)-3 and                           */
/*                 END Msg(2:3132)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:3211) The global identifier 'x' is defined here but is  */
/*                 not used in this translation unit.                         */
/* Justification : Implementation requirement as specified by AUTOSAR SW to   */
/*                 generate global variables and array for RamTst drive.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-4 and                           */
/*                 END Msg(2:3211)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:2022) A tentative definition is being used. It is       */
/*                 appropriate to include an explicit initializer?            */
/* Justification : The array is used to store information from the tested     */
/*                 memory block, the initial values stored have no impact.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-5 and                           */
/*                 END Msg(2:2022)-5 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define RAMTST_LCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define RAMTST_LCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define RAMTST_LCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define RAMTST_LCFG_C_SW_MAJOR_VERSION  2U
#define RAMTST_LCFG_C_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (RAMTST_TYPES_AR_RELEASE_MAJOR_VERSION != \
          RAMTST_LCFG_C_AR_RELEASE_MAJOR_VERSION)
      #error "RamTst_Lcfg.c : Mismatch in Release Major Version"
    #endif

    #if (RAMTST_TYPES_AR_RELEASE_MINOR_VERSION != \
          RAMTST_LCFG_C_AR_RELEASE_MINOR_VERSION)
      #error "RamTst_Lcfg.c : Mismatch in Release Minor Version"
    #endif

    #if (RAMTST_TYPES_AR_RELEASE_REVISION_VERSION != \
          RAMTST_LCFG_C_AR_RELEASE_REVISION_VERSION)
      #error "RamTst_Lcfg.c : Mismatch in Release Revision Version"
    #endif

    #if (RAMTST_TYPES_SW_MAJOR_VERSION != RAMTST_LCFG_C_SW_MAJOR_VERSION)
      #error "RamTst_Lcfg.c : Mismatch in Software Major Version"
    #endif

    #if (RAMTST_TYPES_SW_MINOR_VERSION != RAMTST_LCFG_C_SW_MINOR_VERSION)
      #error "RamTst_Lcfg.c : Mismatch in Software Minor Version"
    #endif
/*******************************************************************************
**            Buffer or storing the test result of the configured blocks      **
*******************************************************************************/
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* QAC Warning: START Msg(2:3132)-3 */
/* QAC Warning: START Msg(2:3211)-4 */
VAR(RamTst_TestResultType, RAMTST_CONST) RamTst_TestResultBuffer[40]=
{
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_NOT_TESTED
};

/* END Msg(2:3132)-3 */
/* END Msg(2:3211)-4 */

/* QAC Warning: START Msg(2:2022)-5 */
STATIC VAR(RamTst_TestDataType, RAMTST_VAR_FAST)
    RamTst_TestBuffer[RAMTST_MAX_TESTED_CELLS];
/* END Msg(2:2022)-5 */

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_ASIL_B_UNSPECIFIED
#else
#define RAMTST_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#endif

/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
#define RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements SWS_BSW_00184 */
/* Structure of RAM test driver block parameters */
/* QAC Warning: START Msg(2:3132)-3 */
STATIC CONST (RamTst_BlockConfigType,
    RAMTST_CONST) RamTst_BlockConfiguration[40] =
{
  /* Index: 0 - RamTstBlockParams */
  {
    /* RamTstBlockId */
    0x0001U,

    /* RamTstEndAddress */
    0xFEBC0FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC0000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 1 - RamTstBlockParams_001 */
  {
    /* RamTstBlockId */
    0x0002U,

    /* RamTstEndAddress */
    0xFEBC1FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC1000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 2 - RamTstBlockParams_002 */
  {
    /* RamTstBlockId */
    0x0003U,

    /* RamTstEndAddress */
    0xFEBC2FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC2000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 3 - RamTstBlockParams_003 */
  {
    /* RamTstBlockId */
    0x0004U,

    /* RamTstEndAddress */
    0xFEBC3FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC3000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 4 - RamTstBlockParams_004 */
  {
    /* RamTstBlockId */
    0x0005U,

    /* RamTstEndAddress */
    0xFEBC4FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC4000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 5 - RamTstBlockParams_005 */
  {
    /* RamTstBlockId */
    0x0006U,

    /* RamTstEndAddress */
    0xFEBC5FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC5000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 6 - RamTstBlockParams_006 */
  {
    /* RamTstBlockId */
    0x0007U,

    /* RamTstEndAddress */
    0xFEBC6FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC6000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 7 - RamTstBlockParams_007 */
  {
    /* RamTstBlockId */
    0x0008U,

    /* RamTstEndAddress */
    0xFEBC7FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC7000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 8 - RamTstBlockParams_008 */
  {
    /* RamTstBlockId */
    0x0009U,

    /* RamTstEndAddress */
    0xFEBC8FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC8000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 9 - RamTstBlockParams_009 */
  {
    /* RamTstBlockId */
    0x000AU,

    /* RamTstEndAddress */
    0xFEBC9FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBC9000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 10 - RamTstBlockParams_010 */
  {
    /* RamTstBlockId */
    0x000BU,

    /* RamTstEndAddress */
    0xFEBCAFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBCA000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 11 - RamTstBlockParams_011 */
  {
    /* RamTstBlockId */
    0x000CU,

    /* RamTstEndAddress */
    0xFEBCBFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBCB000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 12 - RamTstBlockParams_012 */
  {
    /* RamTstBlockId */
    0x000DU,

    /* RamTstEndAddress */
    0xFEBCCFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBCC000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 13 - RamTstBlockParams_013 */
  {
    /* RamTstBlockId */
    0x000EU,

    /* RamTstEndAddress */
    0xFEBCDFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBCD000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 14 - RamTstBlockParams_014 */
  {
    /* RamTstBlockId */
    0x000FU,

    /* RamTstEndAddress */
    0xFEBCEFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBCE000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 15 - RamTstBlockParams_015 */
  {
    /* RamTstBlockId */
    0x0010U,

    /* RamTstEndAddress */
    0xFEBCFFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBCF000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 16 - RamTstBlockParams_016 */
  {
    /* RamTstBlockId */
    0x0011U,

    /* RamTstEndAddress */
    0xFEBD0FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD0000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 17 - RamTstBlockParams_017 */
  {
    /* RamTstBlockId */
    0x0012U,

    /* RamTstEndAddress */
    0xFEBD1FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD1000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 18 - RamTstBlockParams_018 */
  {
    /* RamTstBlockId */
    0x0013U,

    /* RamTstEndAddress */
    0xFEBD2FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD2000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 19 - RamTstBlockParams_019 */
  {
    /* RamTstBlockId */
    0x0014U,

    /* RamTstEndAddress */
    0xFEBD3FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD3000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 20 - RamTstBlockParams_020 */
  {
    /* RamTstBlockId */
    0x0015U,

    /* RamTstEndAddress */
    0xFEBD4FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD4000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 21 - RamTstBlockParams_021 */
  {
    /* RamTstBlockId */
    0x0016U,

    /* RamTstEndAddress */
    0xFEBD5FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD5000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 22 - RamTstBlockParams_022 */
  {
    /* RamTstBlockId */
    0x0017U,

    /* RamTstEndAddress */
    0xFEBD6FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD6000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 23 - RamTstBlockParams_023 */
  {
    /* RamTstBlockId */
    0x0018U,

    /* RamTstEndAddress */
    0xFEBD7FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD7000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 24 - RamTstBlockParams_024 */
  {
    /* RamTstBlockId */
    0x0019U,

    /* RamTstEndAddress */
    0xFEBD8FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD8000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 25 - RamTstBlockParams_025 */
  {
    /* RamTstBlockId */
    0x001AU,

    /* RamTstEndAddress */
    0xFEBD9FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBD9000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 26 - RamTstBlockParams_026 */
  {
    /* RamTstBlockId */
    0x001BU,

    /* RamTstEndAddress */
    0xFEBDAFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBDA000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 27 - RamTstBlockParams_027 */
  {
    /* RamTstBlockId */
    0x001CU,

    /* RamTstEndAddress */
    0xFEBDBFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBDB000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 28 - RamTstBlockParams_028 */
  {
    /* RamTstBlockId */
    0x001DU,

    /* RamTstEndAddress */
    0xFEBDCFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBDC000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 29 - RamTstBlockParams_029 */
  {
    /* RamTstBlockId */
    0x001EU,

    /* RamTstEndAddress */
    0xFEBDDFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBDD000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 30 - RamTstBlockParams_030 */
  {
    /* RamTstBlockId */
    0x001FU,

    /* RamTstEndAddress */
    0xFEBDEFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBDE000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 31 - RamTstBlockParams_031 */
  {
    /* RamTstBlockId */
    0x0020U,

    /* RamTstEndAddress */
    0xFEBDFFFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBDF000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 32 - RamTstBlockParams_032 */
  {
    /* RamTstBlockId */
    0x0021U,

    /* RamTstEndAddress */
    0xFEBE0FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBE0000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 33 - RamTstBlockParams_033 */
  {
    /* RamTstBlockId */
    0x0022U,

    /* RamTstEndAddress */
    0xFEBE1FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBE1000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 34 - RamTstBlockParams_034 */
  {
    /* RamTstBlockId */
    0x0023U,

    /* RamTstEndAddress */
    0xFEBE2FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBE2000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 35 - RamTstBlockParams_035 */
  {
    /* RamTstBlockId */
    0x0024U,

    /* RamTstEndAddress */
    0xFEBE3FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBE3000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 36 - RamTstBlockParams_036 */
  {
    /* RamTstBlockId */
    0x0025U,

    /* RamTstEndAddress */
    0xFEBE4FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBE4000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 37 - RamTstBlockParams_037 */
  {
    /* RamTstBlockId */
    0x0026U,

    /* RamTstEndAddress */
    0xFEBE5FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBE5000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 38 - RamTstBlockParams_038 */
  {
    /* RamTstBlockId */
    0x0027U,

    /* RamTstEndAddress */
    0xFEBE6FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBE6000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  },

  /* Index: 39 - RamTstBlockParams_039 */
  {
    /* RamTstBlockId */
    0x0028U,

    /* RamTstEndAddress */
    0xFEBE7FFFUL,

    /* RamTstFillPattern */
    0x00000000UL,

    /* RamTstStartAddress */
    0xFEBE7000UL,

    /* RamTstTestPolicy */
    RAMTST_NON_DESTRUCTIVE,

    /* RamTstBufferAddress */
    &RamTst_TestBuffer[RAMTST_ZERO]
  }
};


/* END Msg(2:3132)-3 */

/* Implements SWS_BSW_00184 */
/* Structure of RAM test driver algorithm parameters */
/* QAC Warning: START Msg(2:3132)-3 */
STATIC CONST (RamTst_AlgConfigType,
    RAMTST_CONST) RamTst_AlgConfiguration[1] =
{
  /* Index: 0 - RamTstAlgParams_CHECKERBOARD */
  {
    /* RamTst_BlockConfig */
    &RamTst_BlockConfiguration[0],

    /* RamTstAlgParamsId */
    0x01U,

    /* RamTstAlgorithm */
    RAMTST_CHECKERBOARD_TEST,

    /* RamTstExtNumberOfTestedCells */
    0x00040000UL,

    /* RamTstMaxNumberOfTestedCells */
    0x00001004UL,

    /* RamTstNumberOfBlocks */
    0x0028U,

    /* RamTstNumberOfTestedCells */
    0x00000008UL
  }
};


/* END Msg(2:3132)-3 */

/* Implements SWS_BSW_00184 */
/* Structure for RAM test driver configuration parameters */
/* QAC Warning: START Msg(2:3211)-4 */
CONST(RamTst_ConfigType, RAMTST_CONST) RamTst_59_93_Config[1] =
{
  /* Index: 0 - RamTstConfigParams */
  {
    /* RamTstAlgConfig */
    RamTst_AlgConfiguration,

    /* RamTstDefaultAlgParamsId */
    0x01U,

    /* RamTstMinNumberOfTestedCells */
    0x0001U,

    /* RamTstNumberOfAlgParamSets */
    0x01U,

    /* RamTstCompletedNotification */
    &RamTst_CompletedNotification,

    /* RamTstErrorNotification */
    NULL_PTR
  }
};


/* END Msg(2:3211)-4 */
#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
#define RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

/* QAC Warning: START Msg(2:0862)-2 */
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
