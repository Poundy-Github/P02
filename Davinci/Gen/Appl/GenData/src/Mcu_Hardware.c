/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_Hardware.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR MCU post build parameters.                            */
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
* V1.1.0:  07-Nov-2016 : Type qualifier 'const' added for all variables        *
*                        from Mcu_Hardware.c file(CONFIG_DATA sec.) and        *
*                        declared as constants (Ref: JIRA ARDAABD-865)         *
* V1.2.0:  05-Dec-2016 : Export of 'ClkSrcRegAdrr', 'ClkSrcActRegAdrr',        *
*                        'ClkDivRegAdrr', 'ClkDivActRegAdrr' and               *
*                        'ClkStpMskRegAdrr' removed                            *
*                        (Ref: JIRA ARDAABD-865)                               *
* V1.3.0:  31-Jan-2017 : Memmap switch added.(Ref: JIRA ARDAABD-989).          *
* V1.4.0:  05-Jul-2017   Mcu_clma3_BaseAddress exported(Ref: JIRA ARDAABD-1959)*
* V1.5.0:  29-Aug-2017 : Added QAC/MISRA warnings justification.               *
*                        Corrected QAC/MISRA Warning.                          *
*                        (Ref: JIRA ARDAABD-2083)                              *
* V1.5.1:  20-Sep-2017 : Iocommon split                                        *
*                        (Ref: JIRA ARDAABD-2160)                              *
* V1.5.2:  29-Dec-2017 : Added MISRA warning (4:0310) justification.           *
* V1.5.3:  21-Jun-2018 : Following changes are made:                           *
*                        1. As part of ARDAABD-3179, Address of                *
*                        Mcu_ICCWEND_IMRAddress is corrected from IMR0L        *
*                        to IMR3H.                                            */
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
#include "Iocommon_Defines.h"
#include "Mcu_Hardware.h"

/******************************************************************************/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_HARDWARE_C_AR_RELEASE_MAJOR_VERSION  4U
#define MCU_HARDWARE_C_AR_RELEASE_MINOR_VERSION  2U
#define MCU_HARDWARE_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define MCU_HARDWARE_C_SW_MAJOR_VERSION  1U
#define MCU_HARDWARE_C_SW_MINOR_VERSION  2U


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
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0310)-2 and                           */
/*                 END Msg(4:0310)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:3211) The global identifier 'x' is defined here but is  */
/*                 not used in this translation unit.                         */
/* Justification : Implementation requirement as specified by AUTOSAR SW to   */
/*                 generate global variables and array for CorTst driver.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3211)-3 and               */
/*                 END Msg(2:3211)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:4153) The identifier 'Mcu_Tauj0OsReg_BaseAddress' may   */
/*                 cause confusion because the letter 'O' and the number '0'  */
/*                 are adjacent.                                              */
/* Justification : Indentifier name is according to the naming convention     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:4153)-4 and               */
/*                 END Msg(2:4153)-4 tags in the code.                        */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/* MISRA Violation: START Msg(4:0303)-1 */
/* QAC Warning: START Msg(2:3211)-3 */

/*Structure of MCU Write Protection registers*/
volatile WPROTReg* const Mcu_WriteProtReg_BaseAddress =
                                   (volatile WPROTReg*)&WPROTREG; 

/*Structure of MCU LVI registers*/
volatile LVIReg* const LviReg_BaseAddress =
                                   (volatile LVIReg*)&LVIREG; 

/*Structure of MCU Low Power Sequence registers*/
/* volatile LPSReg* const Mcu_LpsRegisters_BaseAddress =
                                   (volatile LPSReg*)&LPSREG;  */ 

/*Structure of MCU IOHOLD registers*/
volatile unsigned long* const Mcu_IoHoldRegister_BaseAddress =
                                   (volatile unsigned long*)&STBC_IOHOLD;    

/*Structure of MCU Reset Factor registers*/
volatile RESFReg* const Mcu_ResfRegister_BaseAddress =
                                      (volatile RESFReg*)&RESFREG; 

/*Structure of MCU CLMA0 registers*/
volatile ClkMntrReg* const Clma0Reg_BaseAddress =                                    (volatile ClkMntrReg*)&CLKMNTRREG0;

/*Structure of MCU CLMA1 registers*/
volatile ClkMntrReg* const Clma1Reg_BaseAddress=                                    (volatile ClkMntrReg*)&CLKMNTRREG1;

/*Structure of MCU CLMA2 registers*/
/*volatile ClkMntrReg* const Clma2Reg_BaseAddress =
                                   (volatile ClkMntrReg*)&CLKMNTRREG2;*/

/*Structure of MCU CLMA3 registers*/
/*volatile ClkMntrReg* const Clma3Reg_BaseAddress =
                                   (volatile ClkMntrReg*)&CLKMNTRREG3;*/

/*Structure of MCU STBC0 registers*/
volatile STBC0Reg* const Mcu_Stbc0Register_BaseAddress = 
                                   (volatile STBC0Reg*)&STBC0REG;

/*Structure of MCU Wake-up factor registers*/
volatile WUFReg* const WufReg_BaseAddress =
                                   (volatile WUFReg*)&WUFREG0;
         volatile WUFReg* const Wuf10Reg_BaseAddress =
                                            (volatile WUFReg*)&WUFREG1;
         volatile WUFReg* const Wuf20Reg_BaseAddress =
                                            (volatile WUFReg*)&WUFREG20;
         volatile WUFReg* const WufIsoReg_BaseAddress =
                                   (volatile WUFReg*)&WUFREGISO; 

/*Structure of MCU FE Interrupt Mask registers*/
volatile FEINTReg* const FEIntMsk_BaseAddress =
                                   (volatile FEINTReg*)&FEINTREG; 

/* QAC Warning: START Msg(2:4153)-4 */
/*Structure of TAUJ0 timer registers*/
/*volatile TAUJUserReg* const Mcu_Tauj0UserReg_BaseAddress = 
                               (volatile TAUJUserReg*)&TAUJ0USERREG;*/
/*volatile TAUJOsReg* const Mcu_Tauj0OsReg_BaseAddress = 
                               (volatile TAUJOsReg*)&TAUJ0OSREG;*/

/* END Msg(2:4153)-4 */

/* MISRA Violation: START Msg(4:0310)-2 */
/*Structure of MCU Clock registers*/
volatile ClkCntlReg_S4* const Mcu_ClkCtrlReg_BaseAddress =
                                   (volatile ClkCntlReg_S4*)&CLKCNTLREG;
/* END Msg(4:0310)-2 */

/*Pointer for MCU ICCWEND IMR*/
/*volatile unsigned short* const Mcu_ICCWEND_IMRAddress =
                                   (volatile unsigned short*)&IMR3H;*/
/* END Msg(2:3211)-3 */
/* END Msg(4:0303)-1 */
#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
