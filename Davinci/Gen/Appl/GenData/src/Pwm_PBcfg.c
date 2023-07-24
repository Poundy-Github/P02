/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_PBcfg.c                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
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
 * V1.0.1:  14-Jan-2016 : As part of F1K V4.00.01 development activity,
 *                        following changes are made:
 *                        1. As part of JIRA #ARDAAGA-186, TOC, TOL and TOE
 *                           mask values are corrected.
 * V2.0.0:  26-Oct-2016 : As part of F1K V42.00.00 development activity,
 *                        following changes are made:
 *                        1. #ARDAABD-494 AUTOSAR 4.2 is supported.
 *                        2. #ARDAABD-671 Channels configured for complex driver
 *                           start during Pwm_Init.
 * V2.1.0:  11-Jul-2017 : As per JIRA ticket #ARDAABD-1726, following changes
 *                        are made:
 *                        1. Added elements 'ulGroup0', 'ulGroup1' and
 *                           'ulGroup2' in 'Pwm_GstConfiguration' structure.
 *                        2. Update the value of 'ucDiagClockCtl' for F1KM
 *                           devices in 'Pwm_GstDiagChannelConfig' structure.
 *                        3. Added element 'usDiagPeriod' in the
 *                           'Pwm_GstDiagUnitConfig' structure.
 *                        4. Copyright information updated.
 *                        5. Updated the generation of 'pDiagIntrCntlAddress'
 *                        6. Removed unused MISRA Message(4:0306)
 * V2.1.1:  22-Sep-2017 : Following changes are made:
 *                        1. As per JIRA ticket #ARDAABD-2476, structure naming
 *                           is corrected.
 *                        2. As per JIRA ticket #ARDAABD-2465, inclusion of
 *                           Iocommon_Defines.h is added.
 * V2.1.2:  23-May-2018 : Following changes are made:
 *                        1. As part of merging activity, #ARDAABD-3454
 *                           a. Parameters pImrIntrCntlRegs, usImrMaskValue,
 *                              pDiagImrIntrCntlRegs and usDiagImrMaskValue are
 *                              removed from Pwm_GstTAUChannelConfig and
 *                              Pwm_GstDiagChannelConfig structures.
 *                              Ref: ARDAABD-2158.
 *                           b. Removed following memory sections
 *                              PWM_START_SEC_CONFIG_DATA_UNSPECIFIED,
 *                              PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED,
 *                              PWM_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED and
 *                              PWM_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED.
 *                              Ref: ARDAABD-908.
 *                           c. Added new memory section
 *                              PWM_<START/STOP>_SEC_CONFIG_DATA_32 for
 *                              arrays Pwm_GaaDiagSyncInitMask and
 *                              Pwm_GaaDiagComplexInitMask.
 *                              Ref: ARDAABD-908.
 *                           d. Structure Pwm_GstConfiguration is mapped in
 *                              PWM_START_SEC_CONFIG_DATA_UNSPECIFIED and
 *                              PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED memory
 *                              section.
 *                              Ref: ARDAABD-908.
 *                           e. Updated Copyright information.
 *                        2. As per JIRA ticket ARDAABD-880, parameter
 *                           usDiagTimeOutValue is added in the
 *                           Pwm_GstDiagChannelConfig sturcture.
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


#include "Pwm.h"
#include "Pwm_PBTypes.h"
#include "Pwm_Cbk.h"
#include "Iocommon_Defines.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PWM_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define PWM_PBCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define PWM_PBCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PWM_PBCFG_C_SW_MAJOR_VERSION  1U
#define PWM_PBCFG_C_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3635) Function identifier used as a pointer without     */
/*                  a preceding & operator                                    */
/* Rule          : MISRA-C:2004 Rule 16.9                                     */
/* Justification : Function pointer is used as pointer without a preceding &  */
/*                 operator since this function will be invoked during        */
/*                 notification                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3635)-1 and                           */
/*                 END Msg(4:3635)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3408) Has external linkage and is being defined without */
/*                 any previous declaration.                                  */
/* Rule          : MISRA-C:2004 Rule 8.8                                      */
/* Justification : This sub structure is accessed as a member in main         */
/*                 structure and hence declaration is not required.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3408)-2 and                           */
/*                 END Msg(4:3408)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Void pointer is used inorder to typecast to different      */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-3 and                           */
/*                 END Msg(4:0303)-3 tags in the code.                        */
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
/* 4. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type.                                           */
/* Rule          : NA                                                         */
/* Justification : The result of this cast is implicitly converted            */
/*                 to another type.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:3892)-4 and              */
/*                 END Msg(2:3892)-4 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
      PWM_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
 #error "Pwm_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (PWM_PBTYPES_AR_RELEASE_MINOR_VERSION != \
      PWM_PBCFG_C_AR_RELEASE_MINOR_VERSION)
 #error "Pwm_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (PWM_PBTYPES_AR_RELEASE_REVISION_VERSION != \
      PWM_PBCFG_C_AR_RELEASE_REVISION_VERSION)
 #error "Pwm_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (PWM_PBTYPES_SW_MAJOR_VERSION != PWM_PBCFG_C_SW_MAJOR_VERSION)
  #error "Pwm_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (PWM_PBTYPES_SW_MINOR_VERSION != PWM_PBCFG_C_SW_MINOR_VERSION)
  #error "Pwm_PBcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED

/* QAC Warning: START Msg(2:0890)-3 */
#include "Pwm_MemMap.h"
/* END Msg(2:0890)-3 */

/* TRACE [R4.2, PWM077] */
/* Structure for each Config Set */
/* QAC Warning: START Msg(2:3211)-1 */
CONST(Pwm_ConfigType, PWM_CONST) Pwm_GstConfiguration[] =
{
  /* Index: 0 - PwmChannelConfigSet0 */
  {
    /* ulStartOfDbToc */
    0x0EDE4108UL,

    /* pTAUDBUnitConfig */
    &Pwm_GstTAUDBUnitConfig[0],

    /* pTAUJUnitConfig */
    &Pwm_GstTAUJUnitConfig[0],

    /* pChannelConfig */
    &Pwm_GstTAUChannelConfig[0]
  }
};


/* END Msg(2:3211)-1 */

/* Structure for each TAUD and TAUB Unit Configuration set */
CONST(Pwm_TAUDBUnitConfigType,PWM_CONST) Pwm_GstTAUDBUnitConfig[] =
{
  /* Index: 0 - TAUB0 */
  {
    /* ucUserCntlRegsIndx */
    0x00U,

    /* ucOsCntlRegsIndx */
    0x00U,

    /* usTAUChannelMask */
    0x0003U,

    /* usTOMMask */
    0x0002U,

    /* usTOCMask */
    0x0000U,

    /* usTOLMask */
    0x0002U,

    /* usTOMask */
    0x0000U,

    /* usTOEMask */
    0x0002U,

    /* usPrescaler */
    0xFFF0U,

    /* blConfigurePrescaler */
    PWM_TRUE,

    /* uiPwmTAUType */
    PWM_HW_TAUB
  }
};


/* Structure for each TAUJ Unit Configuration set */
CONST(Pwm_TAUJUnitConfigType,PWM_CONST) Pwm_GstTAUJUnitConfig[] =
{
  /* Index: 0 - TAUJ3 */
  {
    /* ucUserCntlRegsIndx */
    0x00U,

    /* ucOsCntlRegsIndx */
    0x00U,

    /* usPrescaler */
    0xF063U,

    /* ucBaudRate */
    0xFFU,

    /* blConfigurePrescaler */
    PWM_TRUE,

    /* ucTAUChannelMask */
    0x0FU,

    /* ucTOMMask */
    0x0AU,

    /* ucTOLMask */
    0x00U,

    /* ucTOMask */
    0x00U,

    /* ucTOEMask */
    0x0AU
  },

  /* Index: 1 - TAUJ1 */
  {
    /* ucUserCntlRegsIndx */
    0x01U,

    /* ucOsCntlRegsIndx */
    0x01U,

    /* usPrescaler */
    0xFFF0U,

    /* ucBaudRate */
    0xFFU,

    /* blConfigurePrescaler */
    PWM_TRUE,

    /* ucTAUChannelMask */
    0x03U,

    /* ucTOMMask */
    0x02U,

    /* ucTOLMask */
    0x00U,

    /* ucTOMask */
    0x02U,

    /* ucTOEMask */
    0x02U
  }
};


/* Structure for each Diagnostic Unit Configuration set */
/* CONST(Pwm_DiagUnitConfigType,PWM_CONST) Pwm_GstDiagUnitConfig[]; */
/* Structure for TAUD or TAUB Channel */
/* MISRA Violation: START Msg(4:3408)-2 */
CONST(Pwm_TAUDBProperties,PWM_CONST) Pwm_GstTAUDBChannelConfig[] =
{
  /* Index: 0 - VIP_VD3V3_SYNC_MASTER */
  {
    /* usDefaultPeriod */
    0x0050U,

    /* usChannelMask */
    0x0003U
  },

  /* Index: 1 - VIP_VD3V3_SYNC_SLAVE */
  {
    /* usDefaultDuty */
    0x0000U,

    /* usChannelMask */
    0x0002U
  }
};


/* END Msg(4:3408)-2 */

/* Structure for TAUJ Channel */
/* MISRA Violation: START Msg(4:3408)-2 */
CONST(Pwm_TAUJProperties,PWM_CONST) Pwm_GstTAUJChannelConfig[] =
{
  /* Index: 0 - VIP_USB1_SYNC_MASTER */
  {
    /* ulDefaultPeriod */
    0x000003E8UL,

    /* ucChannelMask */
    0x03U
  },

  /* Index: 1 - VIP_USB1_SYNC_SLAVE */
  {
    /* ulDefaultDuty */
    0x00000000UL,

    /* ucChannelMask */
    0x02U
  },

  /* Index: 2 - VIP_ETN_1V_SYNC_MASTER */
  {
    /* ulDefaultPeriod */
    0x00000020UL,

    /* ucChannelMask */
    0x0CU
  },

  /* Index: 3 - VIP_ETN_1V_SYNC_SLAVE */
  {
    /* ulDefaultDuty */
    0x00000000UL,

    /* ucChannelMask */
    0x08U
  },

  /* Index: 4 - VIP_PWR_VG10V_SYNC_MASTER */
  {
    /* ulDefaultPeriod */
    0x00000050UL,

    /* ucChannelMask */
    0x03U
  },

  /* Index: 5 - VIP_PWR_VG10V_SYNC_SLAVE */
  {
    /* ulDefaultDuty */
    0x00008000UL,

    /* ucChannelMask */
    0x02U
  }
};


/* END Msg(4:3408)-2 */

/* Structure for channel Configuration set */
/* QAC Warning: START Msg(2:3892)-4 */
CONST(Pwm_ChannelConfigType,PWM_CONST) Pwm_GstTAUChannelConfig[] =
{
  /* Index: 0 - VIP_USB1_SYNC_MASTER */
  {
    /* pChannelProp */
    &Pwm_GstTAUJChannelConfig[0],

    /* ucCntlRegsIndx */
    0x00U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
    (P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)) &ICTAUJ3I0,
    /* END Msg(4:0303)-3 */

    /* usCMORegSettingsMask */
    0x0801U,

    /* ucMasterOffset */
    0x00U,

    /* ucTimerUnitIndex */
    0x00U,

    /* uiPwmTAUType */
    PWM_HW_TAUJ,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    (uint8)PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL,

    /* ucNumSlaveChannnel */
    0x01U
  },

  /* Index: 1 - VIP_USB1_SYNC_SLAVE */
  {
    /* pChannelProp */
    &Pwm_GstTAUJChannelConfig[1],

    /* ucCntlRegsIndx */
    0x01U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
    (P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)) &ICTAUJ3I1,
    /* END Msg(4:0303)-3 */

    /* usCMORegSettingsMask */
    0x0409U,

    /* ucMasterOffset */
    0x01U,

    /* ucTimerUnitIndex */
    0x00U,

    /* uiPwmTAUType */
    PWM_HW_TAUJ,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    (uint8)PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL,

    /* ucNumSlaveChannnel */
    0x00U
  },

  /* Index: 2 - VIP_ETN_1V_SYNC_MASTER */
  {
    /* pChannelProp */
    &Pwm_GstTAUJChannelConfig[2],

    /* ucCntlRegsIndx */
    0x02U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
    (P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)) &ICTAUJ3I2,
    /* END Msg(4:0303)-3 */

    /* usCMORegSettingsMask */
    0x8801U,

    /* ucMasterOffset */
    0x00U,

    /* ucTimerUnitIndex */
    0x00U,

    /* uiPwmTAUType */
    PWM_HW_TAUJ,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    (uint8)PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL,

    /* ucNumSlaveChannnel */
    0x01U
  },

  /* Index: 3 - VIP_ETN_1V_SYNC_SLAVE */
  {
    /* pChannelProp */
    &Pwm_GstTAUJChannelConfig[3],

    /* ucCntlRegsIndx */
    0x03U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
    (P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)) &ICTAUJ3I3,
    /* END Msg(4:0303)-3 */

    /* usCMORegSettingsMask */
    0x8409U,

    /* ucMasterOffset */
    0x01U,

    /* ucTimerUnitIndex */
    0x00U,

    /* uiPwmTAUType */
    PWM_HW_TAUJ,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    (uint8)PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL,

    /* ucNumSlaveChannnel */
    0x00U
  },

  /* Index: 4 - VIP_PWR_VG10V_SYNC_MASTER */
  {
    /* pChannelProp */
    &Pwm_GstTAUJChannelConfig[4],

    /* ucCntlRegsIndx */
    0x04U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
    (P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)) &ICTAUJ1I0,
    /* END Msg(4:0303)-3 */

    /* usCMORegSettingsMask */
    0x0801U,

    /* ucMasterOffset */
    0x00U,

    /* ucTimerUnitIndex */
    0x01U,

    /* uiPwmTAUType */
    PWM_HW_TAUJ,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    (uint8)PWM_HIGH,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL,

    /* ucNumSlaveChannnel */
    0x01U
  },

  /* Index: 5 - VIP_PWR_VG10V_SYNC_SLAVE */
  {
    /* pChannelProp */
    &Pwm_GstTAUJChannelConfig[5],

    /* ucCntlRegsIndx */
    0x05U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
    (P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)) &ICTAUJ1I1,
    /* END Msg(4:0303)-3 */

    /* usCMORegSettingsMask */
    0x0409U,

    /* ucMasterOffset */
    0x01U,

    /* ucTimerUnitIndex */
    0x01U,

    /* uiPwmTAUType */
    PWM_HW_TAUJ,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    (uint8)PWM_HIGH,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL,

    /* ucNumSlaveChannnel */
    0x00U
  },

  /* Index: 6 - VIP_VD3V3_SYNC_MASTER */
  {
    /* pChannelProp */
    &Pwm_GstTAUDBChannelConfig[0],

    /* ucCntlRegsIndx */
    0x00U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
    (P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)) &ICTAUB0I0,
    /* END Msg(4:0303)-3 */

    /* usCMORegSettingsMask */
    0x0801U,

    /* ucMasterOffset */
    0x00U,

    /* ucTimerUnitIndex */
    0x00U,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    (uint8)PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL,

    /* ucNumSlaveChannnel */
    0x01U
  },

  /* Index: 7 - VIP_VD3V3_SYNC_SLAVE */
  {
    /* pChannelProp */
    &Pwm_GstTAUDBChannelConfig[1],

    /* ucCntlRegsIndx */
    0x01U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
    (P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)) &ICTAUB0I1,
    /* END Msg(4:0303)-3 */

    /* usCMORegSettingsMask */
    0x0409U,

    /* ucMasterOffset */
    0x01U,

    /* ucTimerUnitIndex */
    0x00U,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    (uint8)PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL,

    /* ucNumSlaveChannnel */
    0x00U
  }
};


/* END Msg(2:3892)-4 */
/* Structure for Diagnostic channel Configuration set */
/* CONST(Pwm_DiagChannelConfigType, PWM_CONST) Pwm_GstDiagChannelConfig[]; */
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONFIG_DATA_32
#include "Pwm_MemMap.h"
/* Array of Pwm Diagnostic channels for simultaneous Start/Stop operation */
/* CONST(uint32,PWM_CONST) Pwm_GaaDiagSyncInitMask[]; */
/* Array of Pwm Diagnostic channels complex device drivers */
/* CONST(uint32,PWM_CONST) Pwm_GaaDiagComplexInitMask[]; */
#define PWM_STOP_SEC_CONFIG_DATA_32
#include "Pwm_MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
