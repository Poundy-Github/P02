/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Hardware.c                                              */
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
 * V1.0.0:  05-Sep-2015 : Initial Version
 * V1.0.1:  10-Dec-2015 : As part of F1K V4.00.01 development activity,
 *                        following changes are made:
 *                        1. As part of JIRA #ARDAAGA-87, prefix of
 *                           module name is added to variables to avoid
 *                           conflict between different modules.
 * V2.0.0:  29-Sep-2016 : #ARDAABD-494 AUTOSAR 4.2 is supported.
 * V2.1.0:  11-Jul-2017 : As per JIRA ticket #ARDAABD-1726, following changes
 *                        are made:
 *                        1. Added the structure 'PwmPWGAINTFReg_BaseAddress'.
 * V2.1.1:  22-Sep-2017 : Following changes are made:
 *                        1. As per JIRA ticket #ARDAABD-2476, structure naming
 *                           is corrected and magic numbers generation are
 *                           replaced with macros.
 *                        2. As per JIRA ticket #ARDAABD-2465, inclusion of
 *                           Iocommon_Defines.h is added.
 *                        3. Copyright information updated.
 */
/******************************************************************************/
/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    2.2.2
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5761450\Generation\Cfg_Gen-1599208913269-0\AutosarFiles_ValGen3763191865339178278\ExtGen_DrvPwm_ECUC_4.2.2_6870692216107392404.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\pwm\generator\R422_PWM_F1x_BSWMDT.arxml
 * GENERATED ON:   4 Sep 2020 - 18:35:51
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "pwm_hardware.h"
#include "Iocommon_Defines.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PWM_HW_C_AR_RELEASE_MAJOR_VERSION  4U
#define PWM_HW_C_AR_RELEASE_MINOR_VERSION  2U
#define PWM_HW_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PWM_HARDWARE_C_SW_MAJOR_VERSION  1U
#define PWM_HARDWARE_C_SW_MINOR_VERSION  1U


/******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Void pointer is used inorder to typecast to different      */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       :(2:3211) The global identifier is defined here but is       */
/*                 not used in this translation unit.                         */
/* Rule          : NA                                                         */
/* Justification : The Global Post Build variables are defined in this        */
/*                 translation unit and is used in the other files.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: QAC Warning: START Msg(2:3211)-1 and */
/*                 END Msg(2:3211)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       :(2:0862) #include 'MemMap.h' directive is redundant.        */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0862)-2 and               */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:0890) This #include #ifdef refers to a macro that has   */
/*                 been #undef'd in a previous #if block.                     */
/* Rule          : NA                                                         */
/* Justification : This is done for proper memory mapping of code and data    */
/*                 for PWM.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:0890)-3 and              */
/*                 END Msg(2:0890)-3 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0890)-3 */
#include "Pwm_MemMap.h"
/* END Msg(2:0890)-3 */

/* MISRA Violation: START Msg(4:0303)-1 */
/* QAC Warning: START Msg(2:3211)-1 */

/*Structure of TAUDB Os registers*/
volatile TAUDBOsReg* const
Pwm_GaaTAUDBOsReg_BaseAddress[PWM_TOTAL_TAUDB_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile TAUDBOsReg *) &TAUB0OSREG
};



/*Structure of TAUJ Os registers*/
volatile TAUJOsReg* const
Pwm_GaaTAUJOsReg_BaseAddress[PWM_TOTAL_TAUJ_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile TAUJOsReg *) &TAUJ3OSREG,

  /* Index: 1 - 1 */
  (volatile TAUJOsReg *) &TAUJ1OSREG
};



/*Structure of TAUDB User registers*/
volatile TAUDBUserReg* const
Pwm_GaaTAUDBUserReg_BaseAddress[PWM_TOTAL_TAUDB_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile TAUDBUserReg *) &TAUB0USERREG
};



/*Structure of TAUJ User registers*/
volatile TAUJUserReg* const
Pwm_GaaTAUJUserReg_BaseAddress[PWM_TOTAL_TAUJ_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile TAUJUserReg *) &TAUJ3USERREG,

  /* Index: 1 - 1 */
  (volatile TAUJUserReg *) &TAUJ1USERREG
};



/*Structure of TAUDB Channel registers*/
volatile TAUDBChReg* const
Pwm_GaaTAUDBChReg_BaseAddress[PWM_TOTAL_TAUDB_CHANNELS_INSTANCE] =
{
  /* Index: 0 - 0 */
  (volatile TAUDBChReg *) &TAUB0CH0REG,

  /* Index: 1 - 1 */
  (volatile TAUDBChReg *) &TAUB0CH1REG
};



/*Structure of TAUJ Channel registers*/
volatile TAUJChReg* const
Pwm_GaaTAUJChReg_BaseAddress[PWM_TOTAL_TAUJ_CHANNELS_INSTANCE] =
{
  /* Index: 0 - 0 */
  (volatile TAUJChReg *) &TAUJ3CH0REG,

  /* Index: 1 - 1 */
  (volatile TAUJChReg *) &TAUJ3CH1REG,

  /* Index: 2 - 2 */
  (volatile TAUJChReg *) &TAUJ3CH2REG,

  /* Index: 3 - 3 */
  (volatile TAUJChReg *) &TAUJ3CH3REG,

  /* Index: 4 - 4 */
  (volatile TAUJChReg *) &TAUJ1CH0REG,

  /* Index: 5 - 5 */
  (volatile TAUJChReg *) &TAUJ1CH1REG
};



/*Structure of Pwm Diagnostic Channel registers*/
/* volatile PWGAReg* const
Pwm_GaaPWGAReg_BaseAddress[PWM_TOTAL_DIAGNOSTIC_INSTANCES]; */

/*Structure of Pwm Diagnostic unit registers*/
/* volatile PWBAReg* const Pwm_GaaPWBAReg_BaseAddress */

/*Structure of Diagnostic unit interrupt registers*/
/* volatile PWGAINTFReg* const Pwm_GaaPWGAINTFReg_BaseAddress[PWM_PWGA_INTF_REG]; */

/* END Msg(4:0303)-1 */
/* END Msg(2:3211)-1 */

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0862)-2 */
#include "Pwm_MemMap.h"
/* END Msg(2:0862)-2 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
