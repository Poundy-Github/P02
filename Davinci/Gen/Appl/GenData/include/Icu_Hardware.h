/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Hardware.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas.            */
/* Any warranty is expressly disclaimed and excluded by Renesas, either       */
/* expressed or implied, including but not limited to those for               */
/* non-infringement of intellectual property, merchantability                 */
/* and/or fitness for the particular purpose                                  */
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
 * V1.0.0:  01-Sep-2015 : Initial version
 * V1.0.1:  10-Dec-2015 : As part of JIRA #ARDAAGA-87, prefix of module name
 *                        is added to variables to avoid conflict between
 *                        different modules.
 * V1.0.2:  30-Sep-2016 : #ARDAABD-487
 *                        1. Updated copyright
 * V2.0.0   05-Oct-2016 : #ARDAABD-487
 *                        1. Updated version to 2.0.0, ASR4.2.2
 * V2.0.1   19-Sep-2017 : #ARDAABD-2444
 *                        1. Updated HW registers names
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.6
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-3172246\Generation\Cfg_Gen-1608012232511-0\AutosarFiles_ValGen3681391169905066537\ExtGen_DrvIcu_ECUC_4.2.2_2473770010070680912.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\icu\generator\R422_ICU_F1x_BSWMDT.arxml
 * GENERATED ON:  15 Dec 2020 - 14:04:36
 */
#ifndef ICU_HARDWARE_H
#define ICU_HARDWARE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Iocommon_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define ICU_HARDWARE_AR_RELEASE_MAJOR_VERSION  4U
#define ICU_HARDWARE_AR_RELEASE_MINOR_VERSION  2U
#define ICU_HARDWARE_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define ICU_HARDWARE_SW_MAJOR_VERSION  1U
#define ICU_HARDWARE_SW_MINOR_VERSION  1U

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* TAU instances to be saved */

#define ICU_TAUDBUSERREG_INSTANCES          0x1U

#define ICU_TAUJUSERREG_INSTANCES           0x0U

#define ICU_TAUDBOSREG_INSTANCES            0x1U

#define ICU_TAUJOSREG_INSTANCES             0x0U

#define ICU_TAUDBCHREG_INSTANCES            0x2U

#define ICU_TAUJCHREG_INSTANCES             0x0U

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*Structure of TAUDB Os registers*/
extern volatile TAUDBOsReg* const
                      Icu_GaaTAUDBOsReg_BaseAddress[ICU_TAUDBOSREG_INSTANCES];

/*Structure of TAUJ Os registers*/
/*extern volatile TAUJOsReg* const
             Icu_GaaTAUJOsReg_BaseAddress [ICU_TAUJOSREG_INSTANCES];*/

/*Structure of TAUDB User registers*/
extern volatile TAUDBUserReg* const
                  Icu_GaaTAUDBUserReg_BaseAddress[ICU_TAUDBUSERREG_INSTANCES];

/*Structure of TAUJ User registers*/
/*extern volatile TAUJUserReg* const
             Icu_GaaTAUJUserReg_BaseAddress [ICU_TAUJUSERREG_INSTANCES];*/

/*Structure of TAUDB Channel registers*/
extern volatile TAUDBChReg* const
                      Icu_GaaTAUDBChReg_BaseAddress[ICU_TAUDBCHREG_INSTANCES];

/*Structure of TAUJ Channel registers*/
/*extern volatile TAUJChReg* const Icu_GaaTAUJChReg_BaseAddress[ICU_TAUJCHREG_INSTANCES];*/

/* Structure for the FCLA registers */
extern volatile  FCLAReg* const Icu_GpfclaReg_BaseAddress;

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ICU_HARDWARE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
