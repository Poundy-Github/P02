/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_LTTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of RAM configuration Parameters    */
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

/* Implements: EAAR_PN0034_NR_0045                                            */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
* V1.0.0:  07-Sep-2015 : Initial Version                                       *
* V2.0.0:  14-Oct-2016 : ARDAABD-473 - AUTOSAR 3.2.2 is not supported anymore  *
*                           - MCU_AR_HIGHER_VERSION is changed to 4.2.2        *
*                           - MCU_AR_LOWER_VERSION is changed to 4.0.3         *
*                           - removed code related to AUTOSAR 3.2.2            *
* V2.0.1:  28-Oct-2016 : ARDAABD-473 - History numbering changed according to  *
*                        projects requirements                                 *
* V2.1.0:  11-Nov-2016 : ARDAABD-918 - Memory class for pRamStartAddress       *
*                        changed to TYPEDEF                                    *
* V2.2.0:  31-Jan-2017 : ARDAABD-989 - Included macro MCU_MEMMAP_FILE instead  *
*                         Memmap.h file                                        *
* V2.3.0:  10-Mar-2017 : ARDAABD-1210 - Add Traceability                       *
* V2.4.0:  29-Aug-2017 : ARDAABD-2150 -Added QAC/MISRA Warnings justification. *
*                        Corrected QAC/MISRA Warning.                          *
* V2.4.1:  20-Jun-2018 : 1.As part of #ARDAABD-3850, traceability              *
*                        inconsistencies are corrected and requirement         *
*                        mapping is done.                                      *
*                        2.Updated Copyright year.                            */
/******************************************************************************/

#ifndef MCU_LTTYPES_H
#define MCU_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information */
#include "Mcu.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */

#define MCU_LTTYPES_AR_RELEASE_MAJOR_VERSION  MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_LTTYPES_AR_RELEASE_MINOR_VERSION  MCU_AR_RELEASE_MINOR_VERSION
#define MCU_LTTYPES_AR_RELEASE_REVISION_VERSION  MCU_AR_RELEASE_REVISION_VERSION


/* File version information */
#define MCU_LTTYPES_SW_MAJOR_VERSION    MCU_SW_MAJOR_VERSION
#define MCU_LTTYPES_SW_MINOR_VERSION    MCU_SW_MINOR_VERSION
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/
/* 2.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-2 and               */
/*                 END Msg(2:0832)-2 tags in the code.                        */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* RAM Sector Data Structure */
/* MCULLTYPES_H_001:  MCU_ESDD_UD_058                                        */
/* MCULLTYPES_H_002:  EAAR_PN0075_FR_0022 , EAAR_PN0075_FR_0023              */
typedef struct STag_Mcu_RamSetting
{
  /* Value of RAM Starting Address */
  P2VAR(void, TYPEDEF, MCU_CONFIG_DATA)pRamStartAddress;
  /* Size of RAM Section  */
  uint32 ulRamSectionSize;
  /* RAM Initial Value */
  uint32  ulRamInitValue;
  /* Ram write size selection */
  Mcu_RamWriteSizeType enRamWriteSizeSel;
} Mcu_RamSetting;
/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
/* MCULLTYPES_H_004: MCU_ESDD_UD_072                                   */
/* QAC Warning: START Msg(2:0832)-2 */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/* Array of structures for RAM Sector */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Mcu_RamSetting, MCU_CONST) Mcu_GstRamSetting[];
/* END Msg(4:3684)-1 */
/* QAC Warning: START Msg(2:0832)-2 */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/

#endif /* MCU_LTTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
