/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_Lcfg.c                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR MCU Link Time parameters                              */
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
/*              Devices:        F1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  01-Sep-2015 : Initial Version                                      *
 * V1.1.0:  31-Jan-2017 : Memmap switch added.(Ref: JIRA ARDAABD-989).         *
 * V1.2.0:  29-Aug-2017 : Added QAC/MISRA warnings justification.              *
 *                        Corrected QAC/MISRA Warning.                         *
 *                        (Ref: JIRA ARDAABD-2083)                             *
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.2.3
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\gw00188717\AppData\Local\Temp\DaVinci\Cfg-4917656\Generation\Cfg_Gen-1605096762847-0\AutosarFiles_ValGen7440281106118928693\ExtGen_DrvMcu_ECUC_4.2.2_8187792819286136148.arxml
 *                D:\SVN_Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\mcu\generator\R422_MCU_F1x_BSWMDT.arxml
 * GENERATED ON:  11 Nov 2020 - 20:17:59
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Mcu_LTTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_LCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define MCU_LCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define MCU_LCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define MCU_LCFG_C_SW_MAJOR_VERSION  1U
#define MCU_LCFG_C_SW_MINOR_VERSION  2U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Void pointer is used inorder to typecast to different      */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-1 and                           */
/*                 END Msg(4:0306)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       : (2:3211) The global identifier 'x' is defined here but is  */
/*                 not used in this translation unit.                         */
/* Justification : Implementation requirement as specified by AUTOSAR SW to   */
/*                 generate global variables and array for MCU driver.        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3211)-2 and               */
/*                 END Msg(2:3211)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:0315) Implicit conversion from a pointer to object type */
/*                 to a pointer to void.                                      */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Void pointer is used in order to typecast to different     */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0315)-3 and                           */
/*                 END Msg(2:0315)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : No implicit Cast , only special AUTOSAR construction P2VAR */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-4 and                           */
/*                 END Msg(2:3892)-4 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (MCU_LTTYPES_AR_RELEASE_MAJOR_VERSION != \
    MCU_LCFG_C_AR_RELEASE_MAJOR_VERSION)
    #error "Mcu_Lcfg.c : Mismatch in Release Major Version"
  #endif

  #if (MCU_LTTYPES_AR_RELEASE_MINOR_VERSION != \
    MCU_LCFG_C_AR_RELEASE_MINOR_VERSION)
    #error "Mcu_Lcfg.c : Mismatch in Release Minor Version"
  #endif

  #if (MCU_LTTYPES_AR_RELEASE_REVISION_VERSION != \
    MCU_LCFG_C_AR_RELEASE_REVISION_VERSION)
    #error "Mcu_Lcfg.c : Mismatch in Release Revision Version"
  #endif

  #if (MCU_LTTYPES_SW_MAJOR_VERSION != MCU_LCFG_C_SW_MAJOR_VERSION)
    #error "Mcu_Lcfg.c : Mismatch in Software Major Version"
  #endif

  #if (MCU_LTTYPES_SW_MINOR_VERSION != MCU_LCFG_C_SW_MINOR_VERSION)
    #error "Mcu_Lcfg.c : Mismatch in Software Minor Version"
  #endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/* QAC Warning: START Msg(2:3211)-2 */
/* Data Structure of RAM setting Configuration */
CONST(Mcu_RamSetting, MCU_VAR) Mcu_GstRamSetting[1] =
{
  /* Index: 0 - McuRamInitConfiguration */
  {
    /* pRamStartAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
/* QAC Warning: START Msg(2:0315)-3 */
/* QAC Warning: START Msg(2:3892)-4 */
    (P2VAR(uint8, TYPEDEF, MCU_CONFIG_DATA)) 0xFEBC0000UL,
   /* END Msg(2:3892)-4 */
   /* END Msg(2:0315)-3 */
   /* END Msg(4:0306)-1 */

    /* ulRamSectionSize */
    0x00000100UL,

    /* ucRamInitValue */
    0xFFU,

    /* enRamWriteSizeSel */
    MCU_8BIT_SIZE
  }
};


/* END Msg(2:3211)-2 */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
