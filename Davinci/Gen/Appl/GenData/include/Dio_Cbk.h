/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
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
 * V1.0.0:  09-Dec-2016 : Initial Version
 * V1.0.1:  28-Feb-2017 : Input files and date printed into Dio_Cbk.h
 * V1.0.2:  03-Mar-2017 : Common publish information printed into Dio_Cbk.h
 * V1.0.3:  05-Jul-2017 : As part of ARDAABD-1703 Jira Ticket,Removed common
 *                        published information.
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    2.2.5
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5734869\Generation\Cfg_Gen-1607756599923-0\AutosarFiles_ValGen5020245192776930963\ExtGen_DrvDio_ECUC_4.2.2_6230620678829164241.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\dio\generator\R422_DIO_F1x_BSWMDT.arxml
 * GENERATED ON:  12 Dec 2020 - 15:04:55
 */

#ifndef DIO_CBK_H
#define DIO_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dio_Cfg.h"
#include "Std_Types.h"
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define DIO_CBK_H_AR_RELEASE_MAJOR_VERSION  4U
#define DIO_CBK_H_AR_RELEASE_MINOR_VERSION  2U
#define DIO_CBK_H_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define DIO_CBK_H_SW_MAJOR_VERSION  2U
#define DIO_CBK_H_SW_MINOR_VERSION  0U
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
 **                        QAC Warning                                        **
 ******************************************************************************/
/* 1.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-1 and               */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
 #define DIO_START_SEC_CODE_ASIL_B
#else
 #define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */


#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
 #define DIO_STOP_SEC_CODE_ASIL_B
#else
 #define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* DIO_CBK_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
