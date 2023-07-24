/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_Hardware.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
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
/*                                                                             *
* V1.0.0:  01-Sep-2015 : Initial Version                                       *
* V1.0.1:  08-Jan-2016 : 1. The structure name of clock monitoring             *
*                        register base address is changed to ClkMntrReg.       *
*                        (Ref: JIRA #ARDAAGA-42)                               *
* V1.1.0:  07-Nov-2016   Type qualifier 'const' added for all variables        *
*                        from Mcu_Hardware.c file(CONFIG_DATA sec.) and        *
*                        declared as constants (Ref: JIRA ARDAABD-865)         *
* V1.2.0:  05-Dec-2016   Export of 'ClkSrcRegAdrr', 'ClkSrcActRegAdrr',        *
*                        'ClkDivRegAdrr', 'ClkDivActRegAdrr' and               *
*                        'ClkStpMskRegAdrr' removed                            *
*                        (Ref: JIRA ARDAABD-865)                               *
* V1.3.0:  28-Dec-2016   Common published information removed from             *
*                        Mcu_Hardware.h (Ref: JIRA ARDAABD-831)                *
* V1.4.0:  31-Jan-2017   Memmap switch added.(Ref: JIRA ARDAABD-989)           *
* V1.5.0:  30-May-2017   Include protection compile switch corrected           *
*                        (Ref: JIRA ARDAABD-1584)                              *
* V1.6.0:  12-Jun-2017   Modifications according to ARDAABD-1584 reverted      *
*                        (Ref: JIRA ARDAABD-1584)                              *
* V1.7.0:  05-Jul-2017   Mcu_clma3_BaseAddress exported(Ref: JIRA ARDAABD-1959)*
* V1.8.0:  19-Jul-2017   Include guards changed to MCU_HARDWARE_H              *
*                        (Ref: JIRA ARDAABD-1584)                              *
* V1.8.1:  29-Aug-2017   Added QAC/MISRA warnings justification.               *
*                        Corrected QAC/MISRA Warning.                          *
*                        (Ref: JIRA ARDAABD-2083)                              *
* V1.8.2:  20-Sep-2017   Iocommon split                                        *
*                        (Ref: JIRA ARDAABD-2160)                              *
*                                                                             */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.2.3
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\gw00188717\AppData\Local\Temp\DaVinci\Cfg-4917656\Generation\Cfg_Gen-1605096762847-0\AutosarFiles_ValGen7440281106118928693\ExtGen_DrvMcu_ECUC_4.2.2_8187792819286136148.arxml
 *                D:\SVN_Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\mcu\generator\R422_MCU_F1x_BSWMDT.arxml
 * GENERATED ON:  11 Nov 2020 - 20:17:59
 */

#ifndef MCU_HARDWARE_H
#define MCU_HARDWARE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Iocommon_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_HARDWARE_AR_RELEASE_MAJOR_VERSION  4U
#define MCU_HARDWARE_AR_RELEASE_MINOR_VERSION  2U
#define MCU_HARDWARE_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define MCU_HARDWARE_H_SW_MAJOR_VERSION  1U
#define MCU_HARDWARE_H_SW_MINOR_VERSION  2U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:4153) The identifier 'Mcu_Tauj0OsReg_BaseAddress' may   */
/*                 cause confusion because the letter 'O' and the number '0'  */
/*                 are adjacent.                                              */
/* Justification : Indentifier name is according to the naming convention     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:4153)-1 and               */
/*                 END Msg(2:4153)-1 tags in the code.                        */
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Port instances to be saved */
#define MCU_PORT_INSTANCES  0

#define MCU_APORT_INSTANCES 0

#define MCU_TOTAL_CLK_SRC_REG_INSTANCES     (unsigned char)12



#define MCU_TOTAL_CLK_SRC_ACTVC_REG_INSTANCES (unsigned char)12



#define MCU_TOTAL_CLK_DIV_REG_INSTANCES     (unsigned char)8



#define MCU_TOTAL_CLK_DIV_ACTV_REG_INSTANCES (unsigned char)8



#define MCU_TOTAL_CLK_STPMSK_INSTANCES      (unsigned char)8


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/* Global register structure addresses */

/*Structure of MCU Write Protection registers*/
extern volatile WPROTReg* const Mcu_WriteProtReg_BaseAddress; 

/*Structure of MCU LVI registers*/
extern volatile LVIReg* const LviReg_BaseAddress; 

/*Structure of MCU LPS registers*/
/*extern volatile LPSReg * const Mcu_LpsRegisters_BaseAddress;*/

/*Structure of MCU IOHOLD registers*/
extern volatile unsigned long * const Mcu_IoHoldRegister_BaseAddress;

/*Structure of MCU Reset factor registers*/
extern volatile RESFReg * const Mcu_ResfRegister_BaseAddress;

/*Structure of MCU CLMA0 registers*/
extern volatile ClkMntrReg* const Clma0Reg_BaseAddress;

/*Structure of MCU CLMA1 registers*/
extern volatile ClkMntrReg* const Clma1Reg_BaseAddress;

/*Structure of MCU CLMA2 registers*/
/*extern volatile ClkMntrReg* const Clma2Reg_BaseAddress;*/

/*Structure of MCU CLMA3 registers*/
/*extern volatile ClkMntrReg* const Clma3Reg_BaseAddress;*/

/*Structure of MCU STBC0 registers*/
extern volatile STBC0Reg* const Mcu_Stbc0Register_BaseAddress;

/*Structure of MCU Wake-up factor registers*/
extern volatile WUFReg* const WufReg_BaseAddress;
extern volatile WUFReg* const Wuf10Reg_BaseAddress;
extern volatile WUFReg* const Wuf20Reg_BaseAddress;
extern volatile WUFReg* const WufIsoReg_BaseAddress;

/*Structure of MCU FE Interrupt Mask registers*/
extern volatile FEINTReg* const FEIntMsk_BaseAddress;
/* QAC Warning: START Msg(2:4153)-1 */
/*Structure of TAUJ0 timer registers*/
/*extern volatile TAUJUserReg* const Mcu_Tauj0UserReg_BaseAddress;*/
/*extern volatile TAUJOsReg* const Mcu_Tauj0OsReg_BaseAddress;*/

/* END Msg(2:4153)-1 */
/*Structure of MCU Clock registers*/
extern volatile ClkCntlReg_S4* const Mcu_ClkCtrlReg_BaseAddress;

/*Ponter for MCU ICCWEND IMR*/
/*extern volatile unsigned short* const Mcu_ICCWEND_IMRAddress; */

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_HARDWARE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
