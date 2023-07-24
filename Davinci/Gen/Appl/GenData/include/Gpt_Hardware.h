/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Hardware.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains hardware pre-compile time parameters.                   */
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
 * V2.1.0   15-Oct-2016 : Add support for Predef Timers as part of ARDAABC-563
 *
 * V2.2.0:  28-Oct-2016 : Updated generator to support Autosar 4.2.2 and 4.0.3
 *                        MemMap section macros
 *
 * V2.2.1:  07-Jul-2017 : As per JIRA ARDAABD-1883, support added for WUF1.
 *
 * V2.2.2:  25-Sep-2017 : Following changes are made:
 *                        1.As per ARDAABD-2471, naming convention of
 *                          global variables updated.
 *                        2.As per ARDAABD-2461, 'Iocommon_Types.h'
 *                          is included.
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  2.4.10
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-7459765\Generation\Cfg_Gen-1611131101098-0\AutosarFiles_ValGen3453357088559218805\ExtGen_DrvGpt_ECUC_4.2.2_952354714322012804.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\gpt\generator\R422_GPT_F1x_BSWMDT.arxml
 * GENERATED ON:  20 Jan 2021 - 17:07:42
 */
#ifndef GPT_HARDWARE_H
#define GPT_HARDWARE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Iocommon_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define GPT_HW_AR_RELEASE_MAJOR_VERSION  4U
#define GPT_HW_AR_RELEASE_MINOR_VERSION  2U
#define GPT_HW_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define GPT_HW_SW_MAJOR_VERSION  1U
#define GPT_HW_SW_MINOR_VERSION  0U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define GPT_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define GPT_AR_RELEASE_MINOR_VERSION_VALUE  2U
#define GPT_AR_RELEASE_REVISION_VERSION_VALUE  2U

#define GPT_SW_MAJOR_VERSION_VALUE  1U
#define GPT_SW_MINOR_VERSION_VALUE  0U
#define GPT_SW_PATCH_VERSION_VALUE  7U

#define GPT_VENDOR_ID_VALUE  59U
#define GPT_MODULE_ID_VALUE  100U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Instance ID of the Gpt Component*/

#define GPT_NUM_OF_TAUDB_REG                0x0U

#define GPT_NUM_OF_TAUDB_CH_REG             0x0U

#define GPT_NUM_OF_TAUJ_REG                 0x1U

#define GPT_NUM_OF_TAUJ_CH_REG              0x2U

#define GPT_NUM_OF_OSTM_REG                 0x0U
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define GPT_START_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"
/* Extern Deceleration of pointer used in Driver code */

/* Structure of TAUDB User Registers */
/* Extern declaration for Gpt_GaaTAUDBUserReg_BaseAddress */
/* Structure of TAUJ User Registers */
extern volatile TAUJUserReg* const
                            Gpt_GaaTAUJUserReg_BaseAddress[GPT_NUM_OF_TAUJ_REG];
/* Structure of TAUDB OS Registers */
/* Extern declaration for Gpt_GaaTAUDBOsReg_BaseAddress */
/* Structure of TAUJ OS Registers */
extern volatile TAUJOsReg * const
                              Gpt_GaaTAUJOsReg_BaseAddress[GPT_NUM_OF_TAUJ_REG];
/* Structure of TAUDB Channel Registers */
/* Extern declaration for Gpt_GaaTAUDBChReg_BaseAddress */
/* Structure of TAUJ Channel Registers */
extern volatile TAUJChReg * const
                      Gpt_GaaTAUJChReg_BaseAddress[GPT_NUM_OF_TAUJ_CH_REG];
/* Structure of OSTM Registers */
/* Extern declaration for Gpt_GaaOSTMReg_BaseAddress */
/* Structure of WUF0 Register */
/* Extern declaration for Gpt_GpWUF0Reg_BaseAddress */
/* Structure of WUF1 Register */
/* Extern declaration for Gpt_GpWUF1Reg_BaseAddress */
/* Structure of WUF20 Register */
/* Extern declaration for Gpt_GpWUF20Reg_BaseAddress */
/* Structure pointer for OSTM channel used by Predef Timer functionality */


#define GPT_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* GPT_HARDWARE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
