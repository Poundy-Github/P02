/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Hardware.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
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
 * V1.0.0:  17-Sep-2015 : Initial Version
 *
 * V2.0.0:  31-Oct-2016 : Updated generator to support Autosar 4.2.2 and 4.0.3
 *                        version and removed 3.2.2 Autosar version support.
 *
 * V2.1.0:  15-Oct-2016 : Add support for Predef Timers as part of ARDAABC-563
 *
 * V2.1.1:  07-Jul-2017 : As per JIRA ARDAABD-1883, support for WUF1 added.
 *
 * V2.1.2:  25-Sep-2017 : Following changes are made:
 *                        1. As per ARDAABD-2425, QAC level 2 warning
 *                           Justification tags are added.
 *                        2. As per ARDAABD-2471, naming convention of
 *                           global variables updated.
 *                        3. As per ARDAABD-2461, 'Iocommon_Defines.h'
 *                           is included.
 */
/******************************************************************************/
/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    2.4.10
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-7459765\Generation\Cfg_Gen-1611131101098-0\AutosarFiles_ValGen3453357088559218805\ExtGen_DrvGpt_ECUC_4.2.2_952354714322012804.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\gpt\generator\R422_GPT_F1x_BSWMDT.arxml
 * GENERATED ON:  20 Jan 2021 - 17:07:41
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Gpt_Hardware.h"
#include "Gpt.h"
#include "Iocommon_Defines.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define GPT_HARDWARE_AR_RELEASE_MAJOR_VERSION  4U
#define GPT_HARDWARE_AR_RELEASE_MINOR_VERSION  2U
#define GPT_HARDWARE_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define GPT_HARDWARE_C_SW_MAJOR_VERSION  1U
#define GPT_HARDWARE_C_SW_MINOR_VERSION  0U

/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message      : (2:3211) The global identifier is defined                   */
/*                here but is not used in this translation unit.              */
/* Rule         : No Rule                                                     */
/* Justification: As per AUTOSAR,all global variables with extern declaration */
/*                shall be given in Gpt_Ram.h.                                */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for QAC Warning START Msg(2:3211)-1 and                */
/*                END Msg(2:3211)-1 tags in the code.                         */
/******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define GPT_START_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"
/* QAC Warning: START Msg(2:3211)-1 */
/* MISRA Violation: START Msg(4:0303)-1 */

/* Structure for TAUDB Unit User Registers */
/* volatile  TAUDBUserReg * const
Gpt_GaaTAUDBUserReg_BaseAddress[GPT_NUM_OF_TAUDB_REG]; */
/* Structure for TAUJ Unit User Registers */
volatile TAUJUserReg * const
Gpt_GaaTAUJUserReg_BaseAddress[GPT_NUM_OF_TAUJ_REG] =
{
  /* Index: 0 - 0 */
  (volatile TAUJUserReg *) &TAUJ0USERREG
};


/* Structure for TAUDB Unit OS Registers */
/* volatile TAUDBOsReg * const
Gpt_GaaTAUDBOsReg_BaseAddress[GPT_NUM_OF_TAUDB_REG]; */
/* Structure for TAUJ Unit OS Registers */
volatile TAUJOsReg * const
Gpt_GaaTAUJOsReg_BaseAddress[GPT_NUM_OF_TAUJ_REG] =
{
  /* Index: 0 - 0 */
  (volatile TAUJOsReg *) &TAUJ0OSREG
};


/* Structure for TAUDB Unit Channel Registers */
/* volatile TAUDBChReg * const
Gpt_GaaTAUDBChReg_BaseAddress[GPT_NUM_OF_TAUDB_CH_REG]; */
/* Structure for TAUJ Unit Channel Registers */
volatile TAUJChReg * const
Gpt_GaaTAUJChReg_BaseAddress[GPT_NUM_OF_TAUJ_CH_REG] =
{
  /* Index: 0 - 0 */
  (volatile TAUJChReg *) &TAUJ0CH0REG,

  /* Index: 1 - 1 */
  (volatile TAUJChReg *) &TAUJ0CH1REG
};


/* Structure for OSTM Unit Registers */
/* volatile OSTMReg * const
Gpt_GaaOSTMReg_BaseAddress[GPT_NUM_OF_OSTM_REG]; */
/* Structure pointer for WUF0 */
/* volatile WUFReg * const Gpt_GpWUF0Reg_BaseAddress; */
/* Structure pointer for WUF1 */
/* volatile WUFReg * const Gpt_GpWUF1Reg_BaseAddress; */
/* Structure pointer for WUF20 */
/* volatile WUFReg * const Gpt_GpWUF20Reg_BaseAddress; */
/* Structure pointer for OSTM channel used by Predef Timer functionality */

/* END Msg(4:0303)-1 */
/* END Msg(2:3211)-1 */
#define GPT_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
