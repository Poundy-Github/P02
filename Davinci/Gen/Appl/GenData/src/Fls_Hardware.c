/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Hardware.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c)2015-2017 Renesas Electronics Corporation                      */
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
 * V1.0.0:  05-Oct-2015 : Initial Version
 * V2.0.0:  14-Nov-2016 : 1. Changes to memmap file inclusion according
 *                           to ASR4.2.2
 *                        2. #ARDAABD-731: Defined FlsDmaReg_BaseAddress array.
 * V2.0.1:  24-Aug-2017 : ARDAABD-2151 - Added QAC/MISRA Warning justifications
 * V2.0.2:  08-Nov-2017 : ARDAABD-2370 - Te following variable names has been
 *                        changed:
 *                        - FACIReg_BaseAddress to  FLS_GpFACIReg_BaseAddress
 *                        - ECCReg_BaseAddress to FLS_GpECCReg_BaseAddress
 *                        - FlsDmaReg_BaseAddress to Fls_GaaDmaReg_BaseAddress
 */
/******************************************************************************/
/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    2.0.4
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-6874790\Generation\Cfg_Gen-1606880170386-0\AutosarFiles_ValGen5137770938767767548\ExtGen_DrvFls_ECUC_4.2.2_8247066206533904749.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\fls\generator\R422_FLS_F1x_BSWMDT.arxml
 * GENERATED ON:   2 Dec 2020 - 13:03:23
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Iocommon_Defines.h"
#include "Fls_Hardware.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define FLS_HW_C_AR_RELEASE_MAJOR_VERSION  4U
#define FLS_HW_C_AR_RELEASE_MINOR_VERSION  2U
#define FLS_HW_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define FLS_HW_C_SW_MAJOR_VERSION  1U
#define FLS_HW_C_SW_MINOR_VERSION  1U

/******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Void pointer is used inorder to typecast to different      */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */

/******************************************************************************/
/* 2.  MISRA C RULE VIOLATION:                                                */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-2 and                           */
/*                 END Msg(2:0832)-2 tags in the code.                        */

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:3211) The global identifier '' is defined here but is   */
/*                 not used in this translation unit.                         */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Global identifier generated by the code generator tool     */
/*                 and used in static translation unit.                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-3 and                           */
/*                 END Msg(2:3211)-3 tags in the code.                        */

/******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
/* MISRA Violation: START Msg(2:0832)-2 */
#include FLS_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/* MISRA Violation: START Msg(4:0303)-1 */
/* MISRA Violation: START Msg(2:3211)-3 */

/*Structure of Fls FACI unit registers*/
volatile FlsFACIReg* const FLS_GpFACIReg_BaseAddress =
                                            (volatile FlsFACIReg *) &FACIREG;

/*Structure of Fls ECC unit registers*/
volatile FlsECCReg* const FLS_GpECCReg_BaseAddress =
                                              (volatile FlsECCReg *) &ECCREG;

/* Structure of DMA registers */
/* volatile DmaReg* const Fls_GaaDmaReg_BaseAddress[FLS_DMA_INSTANCES];*/

/* END Msg(4:0303)-1 */
/* END Msg(2:3211)-3 */

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* MISRA Violation: START Msg(2:0832)-2 */
#include FLS_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

