/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019  Renesas Electronics Corporation                    */
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
 * V1.0.0:  07-Sep-2015 : Initial version
 * V1.0.1:  10-Dec-2015 : As part of JIRA #ARDAAGA-100, Generation of Wake up
 *                        factor register name has been updated in
 *                        generate_precompile_options function.
 * V1.0.2:  12-Sep-2016 : JIRA #ARDAAGA-529
 *                        1. Added ICU_ALREADY_ENABLED_DISABLED_DET_CHECK
 * V1.0.3:  30-Sep-2016 : #ARDAABD-487
 *                        1. Updated copyright
 *                        2. Added MemMap switch
 * V2.0.0   05-Oct-2016 : #ARDAABD-487
 *                        1. Updated version to 2.0.0, ASR4.2.2
 * V2.0.1   11-Jul-2017 : As part of JIRA #ARDAABD-1373,
 *                        1. Added ICU_WAKEUP_FACTOR1_REG and ICU_WUF1_SUPPORTED
 * V2.0.2:  12-Aug-2019 : #ARDAABD-977
 *                        1. Updated copyright
 *                        2. Added ICU_BUSY_OPERATION_DET_CHECK
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
#ifndef ICU_CFG_H
#define ICU_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define ICU_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define ICU_CFG_AR_RELEASE_MINOR_VERSION  2U
#define ICU_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define ICU_CFG_SW_MAJOR_VERSION  1U
#define ICU_CFG_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

/* TRACE [R4, ICU379] */
#define ICU_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define ICU_AR_RELEASE_MINOR_VERSION_VALUE  2U
#define ICU_AR_RELEASE_REVISION_VERSION_VALUE  2U

#define ICU_SW_MAJOR_VERSION_VALUE  1U
#define ICU_SW_MINOR_VERSION_VALUE  1U
#define ICU_SW_PATCH_VERSION_VALUE  6U

#define ICU_VENDOR_ID_VALUE  59U
#define ICU_MODULE_ID_VALUE  122U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the ICU Driver*/
#define ICU_INSTANCE_ID_VALUE               0U

/* Pre-compile option for Version information */
#define ICU_AR_VERSION                                     ICU_AR_HIGHER_VERSION

/* TRACE [R4, ICU220_Conf] */
/* Maximum number of channels configured */
#define ICU_MAX_CHANNEL                                    15U

/* Total number of timer channels configured */
#define ICU_MAX_TIMER_CHANNELS_CONFIGURED                  2U

/* Total number of ICU TAU units configured for previous input used */
#define ICU_TOTAL_UNITS_FOR_PREVINPUT                      0U

/* Total number of ICU TAU units configured */
#define ICU_TOTAL_TAU_UNITS_CONFIGURED                     1U

/* Maximum ICU Channel ID configured */
#define ICU_MAX_CHANNEL_ID_CONFIGURED                      14U

/* enable/disable the check and the generation of ICU_E_BUSY_OPERATION DET */
#define ICU_BUSY_OPERATION_DET_CHECK                       STD_OFF

/* TRACE [R4, ICU002] */
/* TRACE [R4, ICU111] */
/* TRACE [R4, ICU112] */
/* TRACE [R4, ICU232_Conf] */
/* TRACE [R4, ICU026_Conf] */
/* TRACE [R4, ICU273] */
/* TRACE [R4, ICU274] */
/* Enables/Disables Development error detection */
#define ICU_DEV_ERROR_DETECT                               STD_OFF

/* TRACE [R4, ICU233_Conf] */
/* TRACE [R4, ICU360] */
/* Enables/Disables wakeup source reporting */
#define ICU_REPORT_WAKEUP_SOURCE                           STD_ON

/* TRACE [R4, ICU234_Conf] */
/* TRACE [R4, ICU301] */
/* TRACE [R4, ICU114] */
/* Enables/Disables the inclusion of Icu_DeInit API */
#define ICU_DE_INIT_API                                    STD_ON

/* TRACE [R4, ICU347] */
/* TRACE [R4, ICU240_Conf] */
/* Enables/Disables the inclusion of modules version information */
#define ICU_GET_VERSION_INFO_API                           STD_ON

/* TRACE [R4, ICU303] */
/* TRACE [R4, ICU241_Conf] */
/*Enables/Disables the inclusion of Icu_SetMode API */
#define ICU_SET_MODE_API                                   STD_ON

/* TRACE [R4, ICU306] */
/* TRACE [R4, ICU235_Conf] */
/* Enables/Disables the inclusion of Icu_DisableWakeup */
#define ICU_DISABLE_WAKEUP_API                             STD_ON

/* TRACE [R4, ICU308] */
/* TRACE [R4, ICU236_Conf] */
/* Enables/Disables the inclusion of Icu_EnableWakeup API */
#define ICU_ENABLE_WAKEUP_API                              STD_ON

/* TRACE [R4, ICU315] */
/* TRACE [R4, ICU238_Conf] */
/* Enables/Disables the inclusion of Icu_GetInputState API */
#define ICU_GET_INPUT_STATE_API                            STD_ON

/* TRACE [R4, ICU123_Conf] */
/* TRACE [R4, ICU325] */
/* TRACE [R4, ICU321] */
/* TRACE [R4, ICU323] */
/* TRACE [R4, ICU218] */
/* Enables/Disables the inclusion of Icu_StartTimestamp,
  Icu_StopTimestamp and Icu_GetTimestampIndex APIs */
#define ICU_TIMESTAMP_API                                  STD_ON

/* TRACE [R4, ICU124_Conf] */
/* TRACE [R4, ICU329] */
/* TRACE [R4, ICU327] */
/* TRACE [R4, ICU331] */
/* TRACE [R4, ICU333] */
/* Enables/Disables the inclusion of Icu_ResetEdgeCount,
  Icu_EnableEdgeCount, Icu_DisableEdgeCount and Icu_GetEdgeNumbers APIs */
#define ICU_EDGE_COUNT_API                                 STD_ON

/* TRACE [R4, ICU341] */
/* TRACE [R4, ICU239_Conf] */
/* Enables/Disables the inclusion of Icu_GetTimeElapsed API */
#define ICU_GET_TIME_ELAPSED_API                           STD_ON

/* TRACE [R4, ICU345] */
/* TRACE [R4, ICU237_Conf] */
/* Enables/Disables the inclusion of Icu_GetDutyCycleValues API */
#define ICU_GET_DUTY_CYCLE_VALUES_API                      STD_ON

/* TRACE [R4, ICU337] */
/* TRACE [R4, ICU335] */
/* TRACE [R4, ICU242_Conf] */
/* Enables/Disables Icu_StartSignalMeasurement and
  Icu_StopSignalMeasurement APIs */
#define ICU_SIGNAL_MEASUREMENT_API                         STD_ON

/* Enables/Disables the spilt of one Port pin signal to two TAU inputs */
#define ICU_PREVIOUS_INPUT_USED                            STD_OFF

/* TRACE [R4, ICU362] */
/* TRACE [R4, ICU355_Conf] */
/* Enables/Disables the inclusion of Icu_CheckWakeup API */
#define ICU_WAKEUP_FUNCTIONALITY_API                       STD_ON

/* TRACE [R4, ICU375] */
/* TRACE [R4, ICU370] */
/* TRACE [R4, ICU356_Conf] */
/* Enables/Disables the inclusion of Icu_EnableEdgeDetection and
  Icu_DisableEdgeDetection APIs */
#define ICU_EDGE_DETECT_API                                STD_ON

/* Macro for critical section */
#define ICU_CRITICAL_SECTION_PROTECTION                    STD_ON

/* Enable/disable the setting of Prescaler, baudrate and
  blConfigurePrescaler by the ICU Driver */
#define ICU_PRESCALER_CONFIGURED                           STD_ON

/* Indicates the inclusion of notification function */
#define ICU_NOTIFICATION_CONFIG                            STD_ON

/* Enables/Disables the notification and wakeup */
#define ICU_NOTIFY_WAKEUP_INTERRUPT                        STD_ON

/* Enables/Disables the use of TAUD unit depending on the
  TAUD channels configured */
#define ICU_TAUD_UNIT_USED                                 STD_ON

/* Enables/Disables the use of TAUB unit depending on the
  TAUB channels configured */
#define ICU_TAUB_UNIT_USED                                 STD_OFF

/* Enables/Disables the use of TAUJ unit depending on the
  TAUJ channels configured */
#define ICU_TAUJ_UNIT_USED                                 STD_OFF

/* Indicates whether the timer channels configured or not */
#define ICU_TIMER_CH_CONFIGURED                            STD_ON

/* Pre-compile option for enable or disable version check of inter-module
  dependencies */
#define ICU_VERSION_CHECK_EXT_MODULES                      STD_OFF

/* Enable/Disable Clearing Pending Interrupts */
#define ICU_CLEAR_PENDING_INTERRUPT                        STD_ON

/* Enable/disable the setting of baudrate by the
 ICU Driver for TAUD */
#define ICU_TAUD_UNIT_CONFIG                               STD_ON

/* Enable/disable the setting of baudrate by the
 ICU Driver for TAUB */
#define ICU_TAUB_UNIT_CONFIG                               STD_OFF

/* Enable/disable the setting of baudrate
 by the ICU Driver for TAUJ */
#define ICU_TAUJ_UNIT_CONFIG                               STD_OFF

/* Pre-compile option for enable or disable
already DET init check */
#define ICU_ALREADY_INIT_DET_CHECK                         STD_ON

/* Enables/Disables the inclusion of Icu_GetInputLevel API */
#define ICU_GET_INPUT_LEVEL_API                            STD_ON

/* Enables/Disables the counter value of TAU timer */
#define ICU_GET_TAU_COUNT_VALUE_API                        STD_ON

/* Enables/Disables the Synchronous start of timer functionality */
#define ICU_SYNC_START_STOP_SUPPORT                        STD_OFF

/* Enables/Disables the corresponding WUF flag in the ISR */
#define ICU_WAKEUP_FACTOR_CLEAR_ISR                        STD_ON

/* Enables / Disables generation of DET ICU_E_ALREADY_ENABLED */
/* and ICU_E_ALREADY_DISABLED in the enable/disable notification API */
#define ICU_ALREADY_ENABLED_DISABLED_DET_CHECK             STD_ON

/* Maximum 8-bit Registers configured */
#define ICU_MAX_8BIT_REGISTERS                             (uint8)0

/* ICU_CFG_H_001: EAAR_PN0034_FSR_0002 */
/* Enables / Disables write verify for TAUDB peripheral group */
#define ICU_TAUDB_WRITE_VERIFY                             ICU_WV_DISABLE

/* ICU_CFG_H_002: EAAR_PN0034_FSR_0002 */
/* Enables / Disables write verify for TAUJ peripheral group */
#define ICU_TAUJ_WRITE_VERIFY                              ICU_WV_DISABLE

/* ICU_CFG_H_003: EAAR_PN0034_FSR_0002 */
/* Enables / Disables write verify for FCLA peripheral group */
#define ICU_FCLA_WRITE_VERIFY                              ICU_WV_DISABLE

/* ICU_CFG_H_004: EAAR_PN0034_FSR_0002 */
/* Enables / Disables write verify for WUF peripheral group */
#define ICU_WUF_WRITE_VERIFY                               ICU_WV_DISABLE

/* ICU_CFG_H_005: EAAR_PN0034_FSR_0006 */
/* Enables / Disables ram mirror for TAUDB peripheral group */
#define ICU_TAUDB_RAM_MIRROR                               ICU_MIRROR_DISABLE

/* ICU_CFG_H_006: EAAR_PN0034_FSR_0006 */
/* Enables / Disables ram mirror for TAUJ peripheral group */
#define ICU_TAUJ_RAM_MIRROR                                ICU_MIRROR_DISABLE

/* ICU_CFG_H_007: EAAR_PN0034_FSR_0006 */
/* Enables / Disables ram mirror for FCLA peripheral group */
#define ICU_FCLA_RAM_MIRROR                                ICU_MIRROR_DISABLE

/* ICU_CFG_H_008: EAAR_PN0034_FSR_0004 */
/* Enables / Disables usage of write verify error interface */
#define ICU_USE_WRITE_VERIFY_ERROR_INTERFACE               STD_OFF

/* Enables/Disable the WUF1 functionality if supported by device */
#define ICU_WUF1_SUPPORTED                                 STD_ON

/* Address of Wakeup Factor Registers */
#define ICU_WAKEUP_FACTOR0_REG              (&WUFREG0)
#define ICU_WAKEUP_FACTOR20_REG             (&WUFREG20)
#define ICU_WAKEUP_FACTOR1_REG              (&WUFREG1)


/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
/* Macros for enabling/disabling ISRS */
#define ICU_EXT_INTP_CH00_ISR_API    STD_ON
#define ICU_EXT_INTP_CH01_ISR_API    STD_ON
#define ICU_EXT_INTP_CH02_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH03_ISR_API    STD_ON
#define ICU_EXT_INTP_CH04_ISR_API    STD_ON
#define ICU_EXT_INTP_CH05_ISR_API    STD_ON
#define ICU_EXT_INTP_CH06_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH07_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH08_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH09_ISR_API    STD_ON
#define ICU_EXT_INTP_CH10_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH11_ISR_API    STD_ON
#define ICU_EXT_INTP_CH12_ISR_API    STD_ON
#define ICU_EXT_INTP_CH13_ISR_API    STD_ON
#define ICU_EXT_INTP_CH14_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH15_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH16_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH17_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH18_ISR_API    STD_ON
#define ICU_EXT_INTP_CH19_ISR_API    STD_ON
#define ICU_EXT_INTP_CH20_ISR_API    STD_ON
#define ICU_EXT_INTP_CH21_ISR_API    STD_ON
#define ICU_EXT_INTP_CH22_ISR_API    STD_OFF
#define ICU_EXT_INTP_CH23_ISR_API    STD_OFF
#define ICU_TAUB0_CH00_ISR_API    STD_OFF
#define ICU_TAUB0_CH01_ISR_API    STD_OFF
#define ICU_TAUB0_CH02_ISR_API    STD_OFF
#define ICU_TAUB0_CH03_ISR_API    STD_OFF
#define ICU_TAUB0_CH04_ISR_API    STD_OFF
#define ICU_TAUB0_CH05_ISR_API    STD_OFF
#define ICU_TAUB0_CH06_ISR_API    STD_OFF
#define ICU_TAUB0_CH07_ISR_API    STD_OFF
#define ICU_TAUB0_CH08_ISR_API    STD_OFF
#define ICU_TAUB0_CH09_ISR_API    STD_OFF
#define ICU_TAUB0_CH10_ISR_API    STD_OFF
#define ICU_TAUB0_CH11_ISR_API    STD_OFF
#define ICU_TAUB0_CH12_ISR_API    STD_OFF
#define ICU_TAUB0_CH13_ISR_API    STD_OFF
#define ICU_TAUB0_CH14_ISR_API    STD_OFF
#define ICU_TAUB0_CH15_ISR_API    STD_OFF
#define ICU_TAUB1_CH00_ISR_API    STD_OFF
#define ICU_TAUB1_CH01_ISR_API    STD_OFF
#define ICU_TAUB1_CH02_ISR_API    STD_OFF
#define ICU_TAUB1_CH03_ISR_API    STD_OFF
#define ICU_TAUB1_CH04_ISR_API    STD_OFF
#define ICU_TAUB1_CH05_ISR_API    STD_OFF
#define ICU_TAUB1_CH06_ISR_API    STD_OFF
#define ICU_TAUB1_CH07_ISR_API    STD_OFF
#define ICU_TAUB1_CH08_ISR_API    STD_OFF
#define ICU_TAUB1_CH09_ISR_API    STD_OFF
#define ICU_TAUB1_CH10_ISR_API    STD_OFF
#define ICU_TAUB1_CH11_ISR_API    STD_OFF
#define ICU_TAUB1_CH12_ISR_API    STD_OFF
#define ICU_TAUB1_CH13_ISR_API    STD_OFF
#define ICU_TAUB1_CH14_ISR_API    STD_OFF
#define ICU_TAUB1_CH15_ISR_API    STD_OFF
#define ICU_TAUD0_CH00_ISR_API    STD_OFF
#define ICU_TAUD0_CH01_ISR_API    STD_OFF
#define ICU_TAUD0_CH02_ISR_API    STD_OFF
#define ICU_TAUD0_CH03_ISR_API    STD_OFF
#define ICU_TAUD0_CH04_ISR_API    STD_OFF
#define ICU_TAUD0_CH05_ISR_API    STD_OFF
#define ICU_TAUD0_CH06_ISR_API    STD_OFF
#define ICU_TAUD0_CH07_ISR_API    STD_OFF
#define ICU_TAUD0_CH08_ISR_API    STD_OFF
#define ICU_TAUD0_CH09_ISR_API    STD_OFF
#define ICU_TAUD0_CH10_ISR_API    STD_OFF
#define ICU_TAUD0_CH11_ISR_API    STD_OFF
#define ICU_TAUD0_CH12_ISR_API    STD_OFF
#define ICU_TAUD0_CH13_ISR_API    STD_ON
#define ICU_TAUD0_CH14_ISR_API    STD_OFF
#define ICU_TAUD0_CH15_ISR_API    STD_ON
#define ICU_TAUJ0_CH00_ISR_API    STD_OFF
#define ICU_TAUJ0_CH01_ISR_API    STD_OFF
#define ICU_TAUJ0_CH02_ISR_API    STD_OFF
#define ICU_TAUJ0_CH03_ISR_API    STD_OFF
#define ICU_TAUJ1_CH00_ISR_API    STD_OFF
#define ICU_TAUJ1_CH01_ISR_API    STD_OFF
#define ICU_TAUJ1_CH02_ISR_API    STD_OFF
#define ICU_TAUJ1_CH03_ISR_API    STD_OFF
#define ICU_TAUJ2_CH00_ISR_API    STD_OFF
#define ICU_TAUJ2_CH01_ISR_API    STD_OFF
#define ICU_TAUJ2_CH02_ISR_API    STD_OFF
#define ICU_TAUJ2_CH03_ISR_API    STD_OFF
#define ICU_TAUJ3_CH00_ISR_API    STD_OFF
#define ICU_TAUJ3_CH01_ISR_API    STD_OFF
#define ICU_TAUJ3_CH02_ISR_API    STD_OFF
#define ICU_TAUJ3_CH03_ISR_API    STD_OFF


/* MemMap file switch */
#if(ICU_AR_VERSION == ICU_AR_HIGHER_VERSION)
/* ASR 4.2.2 */
#define ICU_MEMMAP_FILE "Icu_MemMap.h"
#else
/* ASR 4.0.3 */
#define ICU_MEMMAP_FILE "MemMap.h"
#endif

/*******************************************************************************
**                      Channel Handles                                       **
*******************************************************************************/

/* Channel Mapping for Timer and External Unit Channels */
#define ICU_TAUD0_CH13 0x00U
#define ICU_TAUD0_CH15 0x01U
#define ICU_EXT_INTP_CH00 0x02U
#define ICU_EXT_INTP_CH01 0x03U
#define ICU_EXT_INTP_CH03 0x04U
#define ICU_EXT_INTP_CH04 0x05U
#define ICU_EXT_INTP_CH05 0x06U
#define ICU_EXT_INTP_CH11 0x07U
#define ICU_EXT_INTP_CH12 0x08U
#define ICU_EXT_INTP_CH13 0x09U
#define ICU_EXT_INTP_CH18 0x0AU
#define ICU_EXT_INTP_CH19 0x0BU
#define ICU_EXT_INTP_CH21 0x0CU
#define ICU_EXT_INTP_CH09 0x0DU
#define ICU_EXT_INTP_CH20 0x0EU

/* TRACE [R4, ICU221_Conf] */
/* TRACE [R4, ICU354_Conf] */
/* ICU Channel Handles */
#define IcuConf_IcuChannel_SOC_VIP_CSIH1_CS (Icu_ChannelType)0x00
#define IcuConf_IcuChannel_SOC_VIP_CSIH2_CS (Icu_ChannelType)0x01
#define IcuConf_IcuChannel_VIP_CAN0_RXD (Icu_ChannelType)0x02
#define IcuConf_IcuChannel_VIP_CAN1_RXD (Icu_ChannelType)0x03
#define IcuConf_IcuChannel_VIP_CAN3_RXD (Icu_ChannelType)0x04
#define IcuConf_IcuChannel_SOC_VIP_CSIH1_REQ2 (Icu_ChannelType)0x05
#define IcuConf_IcuChannel_SOC_VIP_CSIH2_REQ2 (Icu_ChannelType)0x06
#define IcuConf_IcuChannel_VIP_RLIN31_RXD (Icu_ChannelType)0x07
#define IcuConf_IcuChannel_VIP_RLIN32_RXD (Icu_ChannelType)0x08
#define IcuConf_IcuChannel_VIP_SI_IDH (Icu_ChannelType)0x09
#define IcuConf_IcuChannel_VIP_RLIN31_INH (Icu_ChannelType)0x0A
#define IcuConf_IcuChannel_VIP_RLIN32_INH (Icu_ChannelType)0x0B
#define IcuConf_IcuChannel_VIP_LVI_IDL (Icu_ChannelType)0x0C
#define IcuConf_IcuChannel_VIP_8532_DIAG3 (Icu_ChannelType)0x0D
#define IcuConf_IcuChannel_VIP_AMP8532_DIAG3 (Icu_ChannelType)0x0E

/* TRACE [R4, ICU219_Conf] */
/* Configuration Set Handles */
#define IcuConfigSet  (&Icu_GstConfiguration[0])


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ICU_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
