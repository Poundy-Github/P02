/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Hardware.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSARICU post build parameters.                             */
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
/*              Devices:        F1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  01-Sep-2015 :  Initial Version
 * V1.0.1:  10-Dec-2015 :  1. As part of JIRA #ARDAAGA-87, prefix of module name
 *                            is added to variables to avoid conflict between
 *                            different modules.
 *                         2. As part of JIRA #ARDAAGA-126, Timer unit base
 *                            address generation is corrected.
 * V1.0.2:  30-Sep-2016 : #ARDAABD-487
 *                        1. Updated copyright
 *                        2. Added MemMap switch
 * V2.0.0   05-Oct-2016 : #ARDAABD-487
 *                        1. Updated version to 2.0.0, ASR4.2.2
 * V2.0.1   19-Sep-2017 : #ARDAABD-2444
 *                        1.  Updated HW registers names
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Iocommon_Defines.h"
#include "Icu_Hardware.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ICU_HARDWARE_C_AR_RELEASE_MAJOR_VERSION  4U
#define ICU_HARDWARE_C_AR_RELEASE_MINOR_VERSION  2U
#define ICU_HARDWARE_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define ICU_HARDWARE_C_SW_MAJOR_VERSION  1U
#define ICU_HARDWARE_C_SW_MINOR_VERSION  1U

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Void pointer is used in order to typecast to different     */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include"Icu_MemMap.h"

/* MISRA Violation: START Msg(4:0303)-1 */
/*Structure of TAUDB Os registers*/
volatile TAUDBOsReg* const
              Icu_GaaTAUDBOsReg_BaseAddress[ICU_TAUDBOSREG_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile TAUDBOsReg *) &TAUD0OSREG
};


/*Structure of TAUJ Os registers*/
/* volatile TAUJOsReg* const
              Icu_GaaTAUJOsReg_BaseAddress[ICU_TAUJOSREG_INSTANCES]; */
/*Structure of TAUDB User registers*/
volatile TAUDBUserReg* const
              Icu_GaaTAUDBUserReg_BaseAddress[ICU_TAUDBUSERREG_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile TAUDBUserReg *) &TAUD0USERREG
};


/*Structure of TAUJ User registers*/
/* volatile TAUJUserReg* const
              Icu_GaaTAUJUserReg_BaseAddress[ICU_TAUJUSERREG_INSTANCES]; */
/*Structure of TAUDB Channel registers*/
volatile TAUDBChReg* const
              Icu_GaaTAUDBChReg_BaseAddress[ICU_TAUDBCHREG_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile TAUDBChReg *) &TAUD0CH13REG,

  /* Index: 1 - 1 */
  (volatile TAUDBChReg *) &TAUD0CH15REG
};


/*Structure of TAUJ Channel registers*/
/* volatile TAUJChReg* const
              Icu_GaaTAUJChReg_BaseAddress[ICU_TAUJCHREG_INSTANCES]; */
/* Structure for the FCLA registers */
volatile  FCLAReg* const Icu_GpfclaReg_BaseAddress =
                                                  &FCLAREG;
/* END Msg(4:0303)-1 */

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include"Icu_MemMap.h"

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
