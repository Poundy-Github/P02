/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_PBcfg.c                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019  Renesas Electronics Corporation                    */
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
 * V1.0.0:  07-Sep-2015 : Initial version
 * V1.0.1:  12-Nov-2015 : As part of JIRA #ARDAAGA-125, value generated for
 *                        'ucCntlRegsIndx' for the configured channels is
 *                        corrected.
 * V1.0.2:  30-Sep-2016 : #ARDAABD-487
 *                        1. Updated copyright
 *                        2. Added MemMap switch
 * V2.0.0   05-Oct-2016 : #ARDAABD-487
 *                        1. Updated version to 2.0.0, ASR4.2.2
 * V2.0.1   11-Jul-2017 : As part of ARDAABD-1373,
 *                        added ulWUF1MaskValue in structure Icu_GstWakeUpFactor
 * V2.0.2   23-Apr-2018 : Following changes are made:
 *                        1. As part of merging activity, #ARDAABD-3476,
 *                           a. Removed generation of pImrIntrCntlAdress and
 *                              usImrMaskValue from structure
 *                              Icu_GstChannelConfig. Ref: ARDAABD-2158
 *                           b. Mapping of memory section for global or static
 *                              variables are updated as per the AUTOSAR memory
 *                              mapping requirement MEMMAP022. Ref:ARDAABD-908
 *                           c. Copyright information is updated.
 *                        2. Storage specifier for configuration data
 *                           variables is changed from AUTOMATIC to
 *                           TYPEDEF, since it is allocated in ROM.
 *                           Ref:ARDAABD-894
 * V2.0.3   12-Aug-2019 : Following changes are made:
 *                        1. 'uiConfigurePrescaler' is changed to
 *                           'blConfigurePrescaler'
 *                           Ref:ARDAABD-3442
 */
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
 * INPUT FILE:    C:\Users\GW00190425\AppData\Local\Temp\DaVinci\Cfg-8039795\Generation\Cfg_Gen-1608098491176-0\AutosarFiles_ValGen7429727782302893839\ExtGen_DrvIcu_ECUC_4.2.2_1417467063596517592.arxml
 *                D:\SVN_Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\icu\generator\R422_ICU_F1x_BSWMDT.arxml
 * GENERATED ON:  16 Dec 2020 - 14:02:13
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Icu.h"
#include "Icu_Cbk.h"
#include "Icu_PBTypes.h"
#include "Icu_Ram.h"
#include "Iocommon_Defines.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define ICU_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define ICU_PBCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define ICU_PBCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define ICU_PBCFG_C_SW_MAJOR_VERSION  1U
#define ICU_PBCFG_C_SW_MINOR_VERSION  1U


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
/******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ICU_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
      ICU_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
 #error "Icu_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (ICU_PBTYPES_AR_RELEASE_MINOR_VERSION != \
      ICU_PBCFG_C_AR_RELEASE_MINOR_VERSION)
 #error "Icu_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (ICU_PBTYPES_AR_RELEASE_REVISION_VERSION != \
      ICU_PBCFG_C_AR_RELEASE_REVISION_VERSION)
 #error "Icu_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (ICU_PBTYPES_SW_MAJOR_VERSION != ICU_PBCFG_C_SW_MAJOR_VERSION)
  #error "Icu_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (ICU_PBTYPES_SW_MINOR_VERSION != ICU_PBCFG_C_SW_MINOR_VERSION)
  #error "Icu_PBcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"

/* RAM Allocation of Channel data */
VAR(Icu_ChannelRamDataType, ICU_NOINIT_DATA) Icu_GstChannelRamData[15];

/* RAM Allocation of Timestamp channel data */
/* VAR(Icu_TimeStampChannelRamDataType, ICU_NOINIT_DATA) 
  Icu_GstTimestampRamData[]; */

/* RAM Allocation of Signal Measure Channel data */
/* VAR(Icu_SignalMeasureChannelRamDataType, ICU_NOINIT_DATA) 
  Icu_GstSignalMeasureRamData[]; */

/* RAM Allocation of Edge Counting Channel data */
/* VAR(Icu_EdgeCountChannelRamDataType, ICU_NOINIT_DATA) 
  Icu_GstEdgeCountRamData[]; */

#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/* Structure for each Config Set */
CONST(Icu_ConfigType, ICU_CONST) Icu_GstConfiguration[] =
{
  /* Index: 0 - IcuConfigSet */
  {
    /* ulStartOfDbToc */
    0x0EDE8108UL,

    /* pChannelConfig */
    &Icu_GstChannelConfig[0],

    /* pTimerChannelConfig */
    &Icu_GstTimerChannelConfig[0],

    /* pHWUnitConfig */
    &Icu_GstTAUUnitConfig[0],

    /* pWakeUpFactorRamAddress */
    &Icu_GstWakeUpFactor[0],

    /* pRamAddress */
    &Icu_GstChannelRamData[0],

    /* pSignalMeasureAddress */
    NULL_PTR,

    /* pTimeStampAddress */
    NULL_PTR,

    /* pEdgeCountRamAddress */
    NULL_PTR
  }
};



/* Array of structures for Hardware Configuration */
CONST(Icu_TAUUnitConfigType, ICU_CONST) Icu_GstTAUUnitConfig[] =
{
  /* Index: 0 - TAUD0 */
  {
    /* ucTAUUserCntlRegIndx */
    0x00U,

    /* ucTAUOsCntlRegIndx */
    0x00U,

    /* usPrescaler */
    0xFF26U,

    /* ucIcuUnitType */
    ICU_HW_TAUD,

    /* ucBaudRate */
    0x14U,

    /* blConfigurePrescaler */
    ICU_TRUE
  }
};



/* Configuration of each ICU Channel */
CONST(Icu_ChannelConfigType, ICU_CONST) Icu_GstChannelConfig[] =
{
  /* Index: 0 - SOC_VIP_CSIH1_CS */
  {
    /* pIcuNotificationPointer */
    &IPC_IsrCsDetect,

    /* ucCntlRegsIndx */
    0x00U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR10,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICTAUD0I13,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0x2000U,

    /* usPortMaskValue */
    0x0040U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_BOTH_EDGES,

    /* uiIcuChannelType */
    ICU_HW_TAUD,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 1 - SOC_VIP_CSIH2_CS */
  {
    /* pIcuNotificationPointer */
    &IPC_IsrCsDetect_Standby,

    /* ucCntlRegsIndx */
    0x01U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR10,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICTAUD0I15,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0x8000U,

    /* usPortMaskValue */
    0x0080U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_BOTH_EDGES,

    /* uiIcuChannelType */
    ICU_HW_TAUD,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 2 - VIP_CAN0_RXD */
  {
    /* pIcuNotificationPointer */
    NULL_PTR,

    /* ucCntlRegsIndx */
    0x20U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR0,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP0,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0002U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_RISING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 3 - VIP_CAN1_RXD */
  {
    /* pIcuNotificationPointer */
    NULL_PTR,

    /* ucCntlRegsIndx */
    0x24U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR0,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP1,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0004U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_RISING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 4 - VIP_CAN3_RXD */
  {
    /* pIcuNotificationPointer */
    &Icu_EOL_CAN3Rx_WakeupNotifactionFunc,

    /* ucCntlRegsIndx */
    0x2CU,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR0,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP3,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ECUM_WKSOURCE_CN_B30_for_SC_CAN_V3_2_c0d6c67b,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0080U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_FALLING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_TRUE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_FALSE
  },

  /* Index: 5 - SOC_VIP_CSIH1_REQ2 */
  {
    /* pIcuNotificationPointer */
    &IPC_IsrSocReqDetect,

    /* ucCntlRegsIndx */
    0x30U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR8,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP4,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0001U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_RISING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 6 - SOC_VIP_CSIH2_REQ2 */
  {
    /* pIcuNotificationPointer */
    &IPC_IsrSocReqDetect2,

    /* ucCntlRegsIndx */
    0x34U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR8,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP5,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0002U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_RISING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 7 - VIP_RLIN31_RXD */
  {
    /* pIcuNotificationPointer */
    NULL_PTR,

    /* ucCntlRegsIndx */
    0x4CU,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR0,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP11,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0010U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_RISING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 8 - VIP_RLIN32_RXD */
  {
    /* pIcuNotificationPointer */
    NULL_PTR,

    /* ucCntlRegsIndx */
    0x50U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR0,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP12,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x2000U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_RISING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 9 - VIP_SI_IDH */
  {
    /* pIcuNotificationPointer */
    NULL_PTR,

    /* ucCntlRegsIndx */
    0x54U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR1,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP13,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0001U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_RISING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 10 - VIP_RLIN31_INH */
  {
    /* pIcuNotificationPointer */
    NULL_PTR,

    /* ucCntlRegsIndx */
    0xA8U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR1,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP18,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0002U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_FALLING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 11 - VIP_RLIN32_INH */
  {
    /* pIcuNotificationPointer */
    NULL_PTR,

    /* ucCntlRegsIndx */
    0xACU,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR1,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP19,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0008U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_FALLING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 12 - VIP_LVI_IDL */
  {
    /* pIcuNotificationPointer */
    &POWER_IsrLVI_IDL,

    /* ucCntlRegsIndx */
    0xB4U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR1,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP21,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0200U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_BOTH_EDGES,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 13 - VIP_8532_DIAG3 */
  {
    /* pIcuNotificationPointer */
    &AMP_IsrVIP_8532_DIAG3,

    /* ucCntlRegsIndx */
    0x44U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR8,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP9,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0020U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_BOTH_EDGES,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  },

  /* Index: 14 - VIP_AMP8532_DIAG3 */
  {
    /* pIcuNotificationPointer */
    &AMP_IsrVIP_AMP8532_DIAG3,

    /* ucCntlRegsIndx */
    0xB0U,

    /* pLevelReadPprAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &PGPPR11,
    /* END Msg(4:0303)-1 */

    /* pIntrCntlAdress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA)) &ICP20,
    /* END Msg(4:0303)-1 */

    /* ddEcuMChannelWakeupInfo */
    ICU_NOWAKEUP,

    /* usChannelMaskValue */
    0xFFFFU,

    /* usPortMaskValue */
    0x0002U,

    /* ucIcuPortType */
    ICU_NORMAL_PORT,

    /* uiIcuMeasurementMode */
    (uint8)ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    (uint8)ICU_BOTH_EDGES,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP,

    /* uiIcuWakeupCapability */
    ICU_FALSE,

    /* uiIcuDisableEcumWakeupNotification */
    ICU_TRUE
  }
};



/* Configuration of each ICU Timer Channel */
CONST(Icu_TimerChannelConfigType, ICU_CONST) Icu_GstTimerChannelConfig[] =
{
  /* Index: 0 - SOC_VIP_CSIH1_CS */
  {
    /* usChannelModeOSRegSettings */
    0x5006U,

    /* ucChannelModeUserRegSettings */
    0x02U,

    /* ucTimerUnitIndex */
    0x00U,

    /* ucRamDataIndex */
    0x00U,

    /* ucChannelProperties */
    0x00U
  },

  /* Index: 1 - SOC_VIP_CSIH2_CS */
  {
    /* usChannelModeOSRegSettings */
    0x5006U,

    /* ucChannelModeUserRegSettings */
    0x02U,

    /* ucTimerUnitIndex */
    0x00U,

    /* ucRamDataIndex */
    0x01U,

    /* ucChannelProperties */
    0x00U
  }
};



/* Array of structures for Previous Input Configuration */
/* CONST(Icu_PreviousInputUseType, ICU_CONST) Icu_GstPreviousInputConfig[]; */

/* Array of structures for Wakeup Factor Configuration */
CONST(Icu_WakeupFactorType, ICU_CONST) Icu_GstWakeUpFactor[] =
{
  /* Index: 0 - IcuConfigSet */
  {
    /* ulWUF0MaskValue */
    0x00000200UL,

    /* ulWUF1MaskValue */
    0x00000000UL,

    /* ulWUF20MaskValue */
    0x00000000UL
  }
};



/* MISRA Violation: START Msg(4:0303)-1  */
/* Array for ICU Driver 8 bit dynamic registers */
/* Implements: EAAR_PN0034_FSR_0005 */
/* CONSTP2VAR(volatile uint8, TYPEDEF, ICU_CONFIG_DATA)
                        Icu_GaaReg_8bit[ICU_MAX_8BIT_REGISTERS](); */
/* END Msg(4:0303)-1 */
/* Array for ICU Driver 8 bit dynamic mirror registers */
/* Implements: EAAR_PN0034_FSR_0005 */
/* CONSTP2VAR(volatile uint8, TYPEDEF, ICU_CONFIG_DATA)
           Icu_GaaRegMirror_8bit[ICU_MAX_8BIT_REGISTERS](); */
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
