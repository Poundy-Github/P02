/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = RamTst_Cbk.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2017 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Prototype Declarations for RamTst callback Notification */
/* Functions.                                                                 */
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
 * V1.0.0:  10-Oct-2013 : Initial version
 * V1.0.1:  17-Feb-2014 : As per CR 076 for mantis #18116, Tool version
 *                         updated for merge activity.
 * V1.0.2:  11-Sep-2014 :  As per CR 009 and mantis #19850, Changes are made at
 *                         all relevant places accordingly to append U or UL
 *                         after numeric values.
 * V1.0.3:  13-Feb-2015 :  As part of merging activity (mantis #26024),
 *                         following changes are made:
 *                         1. P1X file is adapted from P1X branch.
 *                         2. Copyright information is updated.
 * V1.1.0:  06-Oct-2016    User configured error notification interface for
 *                         write verify added. (ARDAABC-725)
 * V2.0.0:  07-Nov-2016    As part of ARDAABC-939 the following changes made
 *                         1. MemMap.h changed to RAMTST_MEMMAP_FILE
 *                         2. Updated memory section names
 * V2.0.1:  02-Aug-2017    Justification added for QAC warnings which cannot
 *                         be removed. Updated code with corresponding tags.
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    2.0.6
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-7459765\Generation\Cfg_Gen-1611131101098-0\AutosarFiles_ValGen173292231004072736\ExtGen_DrvRamTst_ECUC_4.2.2_8146757055081404526.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\ramtst\generator\R422_RAMTST_F1x_BSWMDT.arxml
 * GENERATED ON:  20 Jan 2021 - 19:11:56
 */

#ifndef RamTst_CBK_H
#define RamTst_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/



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

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define RAMTST_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define RAMTST_CBK_AR_RELEASE_MINOR_VERSION  2U
#define RAMTST_CBK_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define RAMTST_CBK_C_SW_MAJOR_VERSION  2U
#define RAMTST_CBK_C_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_START_SEC_CODE_ASIL_B
#else
#define RAMTST_START_SEC_CODE
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */


extern void  RamTst_CompletedNotification (void);


#if (RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
#define RAMTST_STOP_SEC_CODE_ASIL_B
#else
#define RAMTST_STOP_SEC_CODE
#endif
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements SWS_BSW_00006 */
#include RAMTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* RamTst_CBK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
