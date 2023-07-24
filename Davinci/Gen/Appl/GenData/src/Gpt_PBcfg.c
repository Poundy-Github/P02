/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_PBcfg.c                                                 */
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
 * V1.0.0:  17-Sep-2015 : Initial Version
 *
 * V1.0.1:  01-Aug-2016 : Change generation of ddWakeupSource by
 *                        shifting the Wakeup Source reference bit in the
 *                        generator instead of the code. Ticket id ARDAABC-751.
 *
 * V1.0.2:  18-Oct-2016 : Change generation of ddWakeupSource without shifting
 *                        GPT generator shall only take care to copy the
 *                        parameter name from ECUM and reference the value of
 *                        ECUM without adding any shifting or other operation.
 *                        Ticket id ARDAABC-751.
 *
 * V2.0.0:  27-Oct-2016 : As part of ticket ARDAABC-937, changed storage
 *                        specifier from AUTOMATIC to TYPEDEF where was the
 *                        case.
 *
 * V2.1.0:  29-Oct-2016 : As part of ARDAABC-875,
 *                        1. Added support for OSMT1-4 timers which use FE level
 *                        interrupts.
 *                        2. defined one new value for uiTimerType:
 *                        GPT_HW_OSTM_FEINT for timers OSTM1-4
 *
 * V2.2.0:  31-Oct-2016 : Updated generator to support Autosar 4.2.2 and 4.0.3
 *                        version and removed 3.2.2 Autosar version support.
 *
 * V2.3.0:  15-Oct-2016 : Add support for Predef Timers as part of ARDAABC-563
 *
 * V2.4.0:  28-Oct-2016 : Updated generator to support Autosar 4.2.2 and 4.0.3
 *                        MemMap section macros
 *
 * V2.4.1:  07-Jul-2017 : As per JIRA ARDAABD-1883, Gpt_GstWakeUpFactor
 *                        updated to support WUF1.
 *
 * V2.4.2:  18-Aug-2017 : As per JIRA ARDAABD-2305, generation of
 *                        usImrMaskValue , uiTimerType and ucTimerUnitIndex
 *                        updated to support all OSTM channels.
 *
 * V2.4.3:  26-Sep-2017 : Following changes are made:
 *                        1. As per ARDAABD-2425, QAC level 2 warning
 *                           Justification tags are added.
 *                        2. As per ARDAABD-2461, 'Iocommon_Defines.h'
 *                           is included.
 *
 * V2.4.4:  13-Apr-2018 : As per merging activity #ARDAABD-3489,
 *                       'pImrIntrCntlAddress' is removed from 
 *                        STag_Gpt_ChannelConfigType for denying access to
 *                        IMR register and usImrMaskValue is renamed to
 *                        usFeIntMaskValue for updating FE Interrupt mask
 *                        register. (Ref: ARDAABD-2158)
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Gpt.h"
#include "Gpt_PBTypes.h"
#include "Iocommon_Defines.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define GPT_PBCFG_C_SW_MAJOR_VERSION  1U
#define GPT_PBCFG_C_SW_MINOR_VERSION  0U


/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message      : (2:3211) The global identifier is defined                   */
/*                here but is not used in this translation unit.              */
/* Rule         : No Rule                                                     */
/* Justification: As per AUTOSAR,all global variables with extern declaration */
/*                shall be given in Gpt_Ram.h.                                */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for QAC Warning START Msg(2:3211)-1 and                */
/*                END Msg(2:3211)-1 tags in the code.                         */
/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       : Msg(2:3674) Array size defined implicitly by the           */
/*                 number of initializers.                                    */
/* Rule          : No Rule                                                    */
/* Justification : Hard coded Numbers are added instead of macros for better  */
/*                 readability.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3674)-2 and                           */
/*                 END Msg(2:3674)- 2 tags in the code.                       */
/******************************************************************************/
/* 3. QAC WARNING:                                                            */
/* Message       : Msg(2:2022) A tentative definition is being used. Is it    */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : NA                                                         */
/* Justification : Initialization of all members is ensured in Gpt_Init() API.*/
/*                 So explicit initialization during definition is not        */
/*                 required.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-3 and                           */
/*                 END Msg(2:2022)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:3132) Hard coded 'magic' number, '', used to define the */
/*                 size of an array.                                          */
/* Justification : Hard coded Numbers are added instead of macros for better  */
/*                 readability.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3132)-4 and                           */
/*                 END Msg(2:3132)-4 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

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
/* Message       : (4:3635) Function identifier used as a pointer without     */
/*                 a preceding & operator.                                    */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Function pointer is used as pointer without a preceding &  */
/*                 operator, since this function will be invoked during       */
/*                 notification.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3635)-2 and                           */
/*                 END Msg(4:3635)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0310)-3 and                           */
/*                 END Msg(4:0310)-3 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
      GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
 #error "Gpt_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (GPT_PBTYPES_AR_RELEASE_MINOR_VERSION != \
      GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION)
 #error "Gpt_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (GPT_PBTYPES_AR_RELEASE_REVISION_VERSION != \
      GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION)
 #error "Gpt_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (GPT_PBTYPES_SW_MAJOR_VERSION != GPT_PBCFG_C_SW_MAJOR_VERSION)
  #error "Gpt_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (GPT_PBTYPES_SW_MINOR_VERSION != GPT_PBCFG_C_SW_MINOR_VERSION)
  #error "Gpt_PBcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define GPT_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"
/* QAC Warning: START Msg(2:3211)-1 */
/* QAC Warning: START Msg(2:3674)-2 */
/* Structure for each Config Set */
CONST(Gpt_ConfigType, GPT_CONST) Gpt_GstConfiguration[] =
{
  /* Index: 0 - GptChannelConfigSet0 */
  {
    /* ulStartOfDbToc */
    0x0ED90100UL,

    /* pTAUUnitConfig */
    &Gpt_GstTAUUnitConfig[0],

    /* pChannelConfig */
    &Gpt_GstChannelConfig[0],

    /* pChannelRamData */
    &Gpt_GstChannelRamData[0]
  }
};


/* END Msg(2:3211)-1 */
/* END Msg(2:3674)-2 */
#define GPT_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"
#define GPT_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"
/* QAC Warning: START Msg(2:3674)-2 */
/* Structure for each TAU Unit Configuration set */
CONST(Gpt_TAUUnitConfigType,GPT_CONST) Gpt_GstTAUUnitConfig[] =
{
  /* Index: 0 - TAUJ0 */
  {
    /* ucTAUUnitUserCntlRegIndex */
    0x00U,

    /* ucTAUUnitOsCntlRegIndex */
    0x00U,

    /* usTAUChannelMaskValue */
    0x0003U,

    /* usPrescaler */
    0xFF61U,

    /* ucBaudRate */
    0x00U,

    /* blConfigurePrescaler */
    GPT_TRUE
  }
};


/* END Msg(2:3674)-2 */
/* QAC Warning: START Msg(2:3674)-2 */
/* Initialization of GPT Channel Configuration */
CONST(Gpt_ChannelConfigType, GPT_CONST) Gpt_GstChannelConfig[] =
{
  /* Index: 0 - GptChannelConfiguration_tick */
  {
    /* pGptNotificationPointer */
    /* MISRA Violation: START Msg(4:3635)-2 */
    NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ucBaseCtlRegIndex */
    0x00U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, GPT_CONFIG_DATA)) &ICTAUJ0I0,
    /* END Msg(4:0303)-1 */

    /* usChannelMask */
    0x0001U,

    /* usModeSettingsMask */
    0x0000U,

    /* usFeIntMaskValue */
    0xFFFFU,

    /* ucTimerUnitIndex */
    0x00U,

    /* uiTimerType */
    GPT_HW_TAUJ,

    /* uiGptWakeupSupport */
    GPT_FALSE,

    /* uiGptChannelMode */
    GPT_CH_MODE_CONTINUOUS
  },

  /* Index: 1 - GptChannelConfiguration_1ms_tick */
  {
    /* pGptNotificationPointer */
    /* MISRA Violation: START Msg(4:3635)-2 */
    GptIsr_1ms_tick,
    /* END Msg(4:3635)-2 */

    /* ucBaseCtlRegIndex */
    0x01U,

    /* pIntrCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, GPT_CONFIG_DATA)) &ICTAUJ0I1,
    /* END Msg(4:0303)-1 */

    /* usChannelMask */
    0x0002U,

    /* usModeSettingsMask */
    0x4000U,

    /* usFeIntMaskValue */
    0xFFFFU,

    /* ucTimerUnitIndex */
    0x00U,

    /* uiTimerType */
    GPT_HW_TAUJ,

    /* uiGptWakeupSupport */
    GPT_FALSE,

    /* uiGptChannelMode */
    GPT_CH_MODE_CONTINUOUS
  }
};


/* END Msg(2:3674)-2 */
/* QAC Warning: START Msg(2:3674)-2 */
/* Array of structures for Wakeup Factor Configuration */
/* CONST(Gpt_WakeupFactorType, GPT_CONST) Gpt_GstWakeUpFactor[]; */
/* END Msg(2:3674)-2 */
#define GPT_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"
/* QAC Warning: START Msg(2:3132)-4 */
/* Qac Warning: START Msg(2:2022)-3 */
/* RAM Allocation of Channel data */
VAR(Gpt_ChannelRamData,GPT_NOINIT_DATA) Gpt_GstChannelRamData[2];
/* END Msg(2:2022)-3 */
/* END Msg(2:3132)-4 */
#define GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#include "Gpt_MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
