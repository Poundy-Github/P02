/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V2.1.0:  28-Oct-2016 : Updated generator to support Autosar 4.2.2 and 4.0.3
 *                        MemMap section macros
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
 * GENERATED ON:  20 Jan 2021 - 17:07:42
 */

#ifndef GPT_CBK_H
#define GPT_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Gpt_Cfg.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define GPT_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define GPT_CBK_AR_RELEASE_MINOR_VERSION  2U
#define GPT_CBK_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define GPT_CBK_SW_MAJOR_VERSION  1U
#define GPT_CBK_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define GPT_START_SEC_CALLOUT_CODE_ASIL_B
#include "Gpt_MemMap.h"


/* Implements GPT362 */
/* Implements GPT292 */
/* Implements GPT312_Conf */
/* Implements SWS_Gpt_00362 */
/* Implements SWS_Gpt_00292 */
/* Implements ECUC_Gpt_00312 */
extern FUNC(void, GPT_APPL_CODE) GptIsr_1ms_tick (void);



#define GPT_STOP_SEC_CALLOUT_CODE_ASIL_B
#include "Gpt_MemMap.h"

#endif /* GPT_CBK_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
