/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = FlsTst_PBcfg.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 Renesas Electronics Corporation                          */
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
 * V1.0.0:  25-Sep-2013 : Initial Version
 * V1.0.1:  28-Mar-2014 : As per CR 440, following change is made:
 *                        1. Unwanted new line is removed.
 *                        2. Copyright information is updated.
 * V1.0.2:  18-Sep-2014 : As per CR 012 and mantis #19850, following changes are
 *                        made:
 *                        1. MISRA C Rule Violations are added.
 *                        2. Changes are made at all relevant places
 *                           accordingly to append U or UL after numeric values.
 * V2.0.0:  30-Sep-2016 : Added WV and Ram mirror parameters
 * V2.0.1:  21-Aug-2017 : Justifications added for QAC warnings which cannot
 *                        be removed.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.3
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-6874790\Generation\Cfg_Gen-1606880170386-0\AutosarFiles_ValGen172034617495837798\ExtGen_DrvFlsTst_ECUC_4.2.2_2026105568877334215.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\flstst\generator\R422_FLSTST_F1x_BSWMDT.arxml
 * GENERATED ON:   2 Dec 2020 - 14:23:10
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FlsTst.h"
#include "FlsTst_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define FLSTST_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define FLSTST_PBCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define FLSTST_PBCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define FLSTST_PBCFG_C_SW_MAJOR_VERSION  2U
#define FLSTST_PBCFG_C_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3635) Function identifier used as a pointer without     */
/*                 a preceding & operator.                                    */
/* Rule          : MISRA-C:2004 Rule 16.9                                     */
/* Justification : Function pointer is used as pointer without a preceding &  */
/*                 operator, since this function will be invoked during       */
/*                 notification.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3635)-1 and                           */
/*                 END Msg(4:3635)-1 tags in the code.                        */

/******************************************************************************/

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
/* Message       : (2:3211) The global identifier 'x' is defined here but is  */
/*                 not used in this translation unit.                         */
/* Justification : Implementation requirement as specified by AUTOSAR SWS to  */
/*                 generate global variables and array for FlsTst drive.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-3 and                           */
/*                 END Msg(2:3211)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:3674) Array size defined implicitly by the number of    */
/*                 initializers.                                              */
/* Justification : Specific arrays is generated as specified by AUTOSAR SWS.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3674)-4 and                           */
/*                 END Msg(2:3674)-4 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Specification Major Version Check */
#if (FLSTST_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
      FLSTST_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
 #error "FlsTst_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (FLSTST_PBTYPES_AR_RELEASE_MINOR_VERSION != \
      FLSTST_PBCFG_C_AR_RELEASE_MINOR_VERSION)
 #error "FlsTst_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (FLSTST_PBTYPES_AR_RELEASE_REVISION_VERSION != \
      FLSTST_PBCFG_C_AR_RELEASE_REVISION_VERSION)
 #error "FlsTst_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (FLSTST_PBTYPES_SW_MAJOR_VERSION != FLSTST_PBCFG_C_SW_MAJOR_VERSION)
  #error "FlsTst_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (FLSTST_PBTYPES_SW_MINOR_VERSION != FLSTST_PBCFG_C_SW_MINOR_VERSION)
  #error "FlsTst_PBcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define FLSTST_START_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* QAC Warning: START Msg(2:3674)-4 */
/* QAC Warning: START Msg(2:3211)-3 */
/* Structure for FLSTST Driver Init configuration */
CONST(FlsTst_ConfigType, FLSTST_CONFIG_CONST) FlsTst_GstConfiguration[] =
{
  /* Index: 0 - FlsTstConfigSet */
  {
    /* ulStartOfDbToc */
    0x0EDA0208UL,

    /* pTestCompleteNotifyFunc */
    /* MISRA Violation: START Msg(4:3635)-1 */
    NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* pFlsTstBgndBlkConfig */
    NULL_PTR,

    /* pFlsTstFgndBlkConfig */
    NULL_PTR,

    /* ulFlsTstMaxBgndBlkNo */
    0x00000000UL,

    /* ulFlsTstMaxFgndBlkNo */
    0x00000000UL
  }
};


/* END Msg(2:3211)-3 */
/* END Msg(2:3674)-4 */

#define FLSTST_STOP_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* QAC Warning: START Msg(2:3674)-4 */
/* Structure of FLSTST test block  Configuration for background test */
/* CONST (FlsTstBlock_ConfigType, FLSTST_CONST) FlsTst_GstFlsTstBlockBgndConfig[]; */
/* END Msg(2:3674)-4 */

/* QAC Warning: START Msg(2:3674)-4 */
/* Structure of FLSTST test block  Configuration for foreground test */
/* CONST (FlsTstBlock_ConfigType, FLSTST_CONST) FlsTst_GstFlsTstBlockFgndConfig[]; */
/* END Msg(2:3674)-4 */

#define FLSTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0862)-2 */
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
