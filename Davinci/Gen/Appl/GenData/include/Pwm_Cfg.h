/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  05-Sep-2015 : Initial Version
 * V2.0.0:  29-Sep-2015 : #ARDAABD-494 AUTOSAR 4.2 is supported.
 * V3.0.0:  14-Nov-2016 : #ARDAABD-565 Implement FuSa requirements for ASIL-B.
 * V3.0.1:  27-May-2017 : As part of JIRA #ARDAABD-1726, macros for TAUJ3 unit
 *                        is added.
 * V3.1.0:  11-Jul-2017 : As per JIRA ticket #ARDAABD-1726, following changes
 *                        are made:
 *                        1. Removed macro 'PWM_F1KX_DEVICE_SUPPORT'.
 *                        2. Added macros 'PWM_PERIOD_SELECTION_SUPPORT' and
 *                           'PWM_CONTROL_TRIGGER_OUTPUT_API'.
 *                        3. Added macros 'PWM_DIAG_CHANNELGROUP_SUPPORT' and
 *                           'PWM_PWGA_CHGRP0m_ISR_API'(where m=0,1,2) to
 *                           support F1KM features.
 * V3.1.1:  22-Sep-2017 : As per JIRA ticket #ARDAABD-2476, structure naming
 *                        is corrected.
 * V3.1.2:  23-May-2018 : Following changes are made:
 *                        1. As part of merging activity, #ARDAABD-3454
 *                           a. Pre compile switches PWM_DIAG_MAX_GROUP1_ID,
 *                              PWM_DIAG_MAX_GROUP2_ID, PWM_DIAG_MAX_GROUP3_ID
 *                              PWM_DIAG_GROUP2_ID_SUPPORT  and
 *                              PWM_DIAG_GROUP3_ID_SUPPORT are added.
 *                              Ref: ARDAABD-883.
 *                           b. Updated Copyright information.
 *                        2. As per JIRA ticket ARDAABD-1627, added macro
 *                          'PWM_SELB_INTC2_SUPPORT'.
#                         3. As part of JIRA ticket ARDAABD-2659, DEM
#                            parameter PWM_E_REWRITE_FAILED is added.
#                         4. As part of JIRA ticket ARDAABD-880, DEM
#                            parameter PWM_E_TIMEOUT_FAILURE is added.
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

#ifndef PWM_CFG_H
#define PWM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PWM_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define PWM_CFG_AR_RELEASE_MINOR_VERSION  2U
#define PWM_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PWM_CFG_SW_MAJOR_VERSION  1U
#define PWM_CFG_SW_MINOR_VERSION  1U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define PWM_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define PWM_AR_RELEASE_MINOR_VERSION_VALUE  2U
#define PWM_AR_RELEASE_REVISION_VERSION_VALUE  2U

#define PWM_SW_MAJOR_VERSION_VALUE  1U
#define PWM_SW_MINOR_VERSION_VALUE  1U
#define PWM_SW_PATCH_VERSION_VALUE  4U

#define PWM_VENDOR_ID_VALUE  59U
#define PWM_MODULE_ID_VALUE  121U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the PWM Driver*/
#define PWM_INSTANCE_ID_VALUE               0U

/* Pre-compile option for Version information */
#define PWM_AR_VERSION                      PWM_AR_HIGHER_VERSION

/* TRACE [R4, PWM078, PWM003a, PWM003b, PWM131_Conf] */
/* Enables/Disables Development error detection */
#define PWM_DEV_ERROR_DETECT                STD_OFF

/* TRACE [R4, PWM115c, PWM115b, PWM115a, PWM133_Conf] */
/* Enables/Disables Pwm Notification */
#define PWM_NOTIFICATION_SUPPORTED          STD_OFF

/* Enable/Disable Clearing Pending Interrupts */
#define PWM_CLEAR_PENDING_INTERRUPT         STD_ON

/* Enable/disable the Critical section protection */
#define PWM_CRITICAL_SECTION_PROTECTION     STD_ON

/* Pre-compile option for enable or disable version check of
   inter-module dependencies */
#define PWM_VERSION_CHECK_EXT_MODULES       STD_OFF

/* TRACE [R4, PWM141, PWM141_Conf] */
/* Enables/Disables the Pwm_DeInit API */
#define PWM_DE_INIT_API                     STD_ON

/* TRACE [R4, PWM127_Conf] */
/* Enables/Disables the Pwm_GetOutputState API */
#define PWM_GET_OUTPUT_STATE_API            STD_ON

/* TRACE [R4, PWM128_Conf] */
/* Enables/Disables the Pwm_SetDutyCycle API */
#define PWM_SET_DUTY_CYCLE_API              STD_ON

/* TRACE [R4, PWM129_Conf] */
/* Enables/Disables the Pwm_SetOutputToIdle API */
#define PWM_SET_OUTPUT_TO_IDLE_API          STD_ON

/* TRACE [R4, PWM130_Conf, PWM069a, PWM069b] */
/* Enables/Disables the Pwm_SetPeriodAndDuty API */
#define PWM_SET_PERIOD_AND_DUTY_API         STD_ON

/* TRACE [R4, PWM135_Conf] */
/* Enables/Disables GetVersionInfo API */
#define PWM_VERSION_INFO_API                STD_OFF

/* Enable/Disable the TAUD unit depending on the TAUD channels configured */
#define PWM_TAUD_UNIT_USED                  STD_OFF

/* Enable/Disable the TAUB unit depending on the TAUB channels configured */
#define PWM_TAUB_UNIT_USED                  STD_ON

/* Enable/Disable the TAUJ unit depending on the TAUJ channels configured */
#define PWM_TAUJ_UNIT_USED                  STD_ON

/* Enable/Disable the TAU unit depending on the TAU channels configured */
#define PWM_TAU_UNIT_USED                   STD_ON

/* Enable/disable the setting of Prescaler, baudrate and
   blConfigurePrescaler by the PWM Driver for TAUD */
#define PWM_TAUD_PRESCALER                  STD_OFF

/* Enable/disable the setting of Prescaler, baudrate and
   blConfigurePrescaler by the PWM Driver for TAUB */
#define PWM_TAUB_PRESCALER                  STD_ON

/* Enable/disable the setting of Prescaler, baudrate and
   blConfigurePrescaler by the PWM Driver for TAUJ */
#define PWM_TAUJ_PRESCALER                  STD_ON

/* Total number of PWM  TAUD and TAUB channels configured */
#define PWM_TOTAL_TAUDB_CHANNELS_CONFIG     2U

/* Total number of PWM TAUJ channels configured */
#define PWM_TOTAL_TAUJ_CHANNELS_CONFIG      6U

/* Total number channels configured including Diagnostic channels */
#define PWM_TOTAL_PWM_CHANNELS_CONFIG       8U

/* Total number channels configured */
#define PWM_TOTAL_TAU_CHANNELS_CONFIG       8U

/* Total number of PWM TAUD and TAUB units configured */
#define PWM_TOTAL_TAUDB_UNITS_CONFIG        1U

/* Total number of PWM TAUJ units configured */
#define PWM_TOTAL_TAUJ_UNITS_CONFIG         2U

/* Maximum PWM Channel ID configured including Diagnostic channels */
#define PWM_MAX_CHANNEL_ID_CONFIGURED       7U

/* Enable/Disable the Diagnostic unit depending on the Diagnostic
channels configured */
#define PWM_DIAG_UNIT_USED                  STD_OFF

/* Enables/Disables the PWM_E_ALREADY_INITIALIZED Det check in Pwm_Init API */
#define PWM_ALREADY_INIT_DET_CHECK          STD_ON

/* Enables/Disables the Pwm_SetTriggerDelay API */
#define PWM_SET_TRIGGER_DELAY_API           STD_ON

/* Enables/Disables the Pwm_SetChannelClk API */
#define PWM_SELECT_CHANNEL_CLK_API          STD_ON

/* Enables/Disables the Pwm_SetChannelOutput API */
#define PWM_SET_CHANNEL_OUTPUT_API          STD_ON

/* Enables/Disables Synchronous start/stop of timer functionality */
#define PWM_SYNC_START_SUPPORT              STD_OFF

/* Enables / Disables write verify for TAUDB peripheral group */
#define PWM_TAUDB_WRITE_VERIFY              PWM_WV_DISABLE

/* Enables / Disables write verify for TAUJ peripheral group */
#define PWM_TAUJ_WRITE_VERIFY               PWM_WV_DISABLE

/* Enables / Disables write verify for PWGA peripheral group */
#define PWM_PWGA_WRITE_VERIFY               PWM_WV_DISABLE

/* Enables / Disables ram mirror for TAUDB peripheral group */
#define PWM_TAUDB_RAM_MIRROR                PWM_MIRROR_DISABLE

/* Enables / Disables ram mirror for TAUJ peripheral group */
#define PWM_TAUJ_RAM_MIRROR                 PWM_MIRROR_DISABLE

/* Enables / Disables ram mirror for PWGA peripheral group */
#define PWM_PWGA_RAM_MIRROR                 PWM_MIRROR_DISABLE

/* Enables / Disables usage of write verify error interface */
#define PWM_USE_WRITE_VERIFY_ERROR_INTERFACE STD_OFF

/* Enables / Disables the suppport for Period Selection */
#define PWM_PERIOD_SELECTION_SUPPORT        STD_OFF

/* Enables/Disables the PwmControlTriggerOutput API */
#define PWM_CONTROL_TRIGGER_OUTPUT_API      STD_ON

/* Enables / Disables PWM Diag channel group support */
#define PWM_DIAG_CHANNELGROUP_SUPPORT       STD_OFF

/* Enable/disable Support for SLPWGA group2 channels  */
#define PWM_DIAG_GROUP2_ID_SUPPORT          STD_OFF

/* Enable/disable Support for SLPWGA group3 channels */
#define PWM_DIAG_GROUP3_ID_SUPPORT          STD_OFF

/* Enables / Disables SELB register support */
#define PWM_SELB_INTC2_SUPPORT              STD_OFF

/* DEM for TAU channels start/stop failure */
#define PWM_E_TIMER_FAILURE                 \
  DemConf_DemEventParameter_AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE

/* DEM for DIAG channels start/stop failure */
#define PWM_E_DIAG_FAILURE                  \
  DemConf_DemEventParameter_AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE

/* DEM for PWM TAU channels simultaneous rewrite failure */
#define PWM_E_REWRITE_FAILED                \
  DemConf_DemEventParameter_AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED



/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/* Macros for enabling/disabling ISRS */
#define PWM_TAUB0_CH00_ISR_API    STD_ON
#define PWM_TAUB0_CH01_ISR_API    STD_ON
#define PWM_TAUB0_CH02_ISR_API    STD_OFF
#define PWM_TAUB0_CH03_ISR_API    STD_OFF
#define PWM_TAUB0_CH04_ISR_API    STD_OFF
#define PWM_TAUB0_CH05_ISR_API    STD_OFF
#define PWM_TAUB0_CH06_ISR_API    STD_OFF
#define PWM_TAUB0_CH07_ISR_API    STD_OFF
#define PWM_TAUB0_CH08_ISR_API    STD_OFF
#define PWM_TAUB0_CH09_ISR_API    STD_OFF
#define PWM_TAUB0_CH10_ISR_API    STD_OFF
#define PWM_TAUB0_CH11_ISR_API    STD_OFF
#define PWM_TAUB0_CH12_ISR_API    STD_OFF
#define PWM_TAUB0_CH13_ISR_API    STD_OFF
#define PWM_TAUB0_CH14_ISR_API    STD_OFF
#define PWM_TAUB0_CH15_ISR_API    STD_OFF
#define PWM_TAUB1_CH00_ISR_API    STD_OFF
#define PWM_TAUB1_CH01_ISR_API    STD_OFF
#define PWM_TAUB1_CH02_ISR_API    STD_OFF
#define PWM_TAUB1_CH03_ISR_API    STD_OFF
#define PWM_TAUB1_CH04_ISR_API    STD_OFF
#define PWM_TAUB1_CH05_ISR_API    STD_OFF
#define PWM_TAUB1_CH06_ISR_API    STD_OFF
#define PWM_TAUB1_CH07_ISR_API    STD_OFF
#define PWM_TAUB1_CH08_ISR_API    STD_OFF
#define PWM_TAUB1_CH09_ISR_API    STD_OFF
#define PWM_TAUB1_CH10_ISR_API    STD_OFF
#define PWM_TAUB1_CH11_ISR_API    STD_OFF
#define PWM_TAUB1_CH12_ISR_API    STD_OFF
#define PWM_TAUB1_CH13_ISR_API    STD_OFF
#define PWM_TAUB1_CH14_ISR_API    STD_OFF
#define PWM_TAUB1_CH15_ISR_API    STD_OFF
#define PWM_TAUB2_CH00_ISR_API    STD_OFF
#define PWM_TAUB2_CH01_ISR_API    STD_OFF
#define PWM_TAUB2_CH02_ISR_API    STD_OFF
#define PWM_TAUB2_CH03_ISR_API    STD_OFF
#define PWM_TAUB2_CH04_ISR_API    STD_OFF
#define PWM_TAUB2_CH05_ISR_API    STD_OFF
#define PWM_TAUB2_CH06_ISR_API    STD_OFF
#define PWM_TAUB2_CH07_ISR_API    STD_OFF
#define PWM_TAUB2_CH08_ISR_API    STD_OFF
#define PWM_TAUB2_CH09_ISR_API    STD_OFF
#define PWM_TAUB2_CH10_ISR_API    STD_OFF
#define PWM_TAUB2_CH11_ISR_API    STD_OFF
#define PWM_TAUB2_CH12_ISR_API    STD_OFF
#define PWM_TAUB2_CH13_ISR_API    STD_OFF
#define PWM_TAUB2_CH14_ISR_API    STD_OFF
#define PWM_TAUB2_CH15_ISR_API    STD_OFF
#define PWM_TAUB3_CH00_ISR_API    STD_OFF
#define PWM_TAUB3_CH01_ISR_API    STD_OFF
#define PWM_TAUB3_CH02_ISR_API    STD_OFF
#define PWM_TAUB3_CH03_ISR_API    STD_OFF
#define PWM_TAUB3_CH04_ISR_API    STD_OFF
#define PWM_TAUB3_CH05_ISR_API    STD_OFF
#define PWM_TAUB3_CH06_ISR_API    STD_OFF
#define PWM_TAUB3_CH07_ISR_API    STD_OFF
#define PWM_TAUB3_CH08_ISR_API    STD_OFF
#define PWM_TAUB3_CH09_ISR_API    STD_OFF
#define PWM_TAUB3_CH10_ISR_API    STD_OFF
#define PWM_TAUB3_CH11_ISR_API    STD_OFF
#define PWM_TAUB3_CH12_ISR_API    STD_OFF
#define PWM_TAUB3_CH13_ISR_API    STD_OFF
#define PWM_TAUB3_CH14_ISR_API    STD_OFF
#define PWM_TAUB3_CH15_ISR_API    STD_OFF
#define PWM_TAUB4_CH00_ISR_API    STD_OFF
#define PWM_TAUB4_CH01_ISR_API    STD_OFF
#define PWM_TAUB4_CH02_ISR_API    STD_OFF
#define PWM_TAUB4_CH03_ISR_API    STD_OFF
#define PWM_TAUB4_CH04_ISR_API    STD_OFF
#define PWM_TAUB4_CH05_ISR_API    STD_OFF
#define PWM_TAUB4_CH06_ISR_API    STD_OFF
#define PWM_TAUB4_CH07_ISR_API    STD_OFF
#define PWM_TAUB4_CH08_ISR_API    STD_OFF
#define PWM_TAUB4_CH09_ISR_API    STD_OFF
#define PWM_TAUB4_CH10_ISR_API    STD_OFF
#define PWM_TAUB4_CH11_ISR_API    STD_OFF
#define PWM_TAUB4_CH12_ISR_API    STD_OFF
#define PWM_TAUB4_CH13_ISR_API    STD_OFF
#define PWM_TAUB4_CH14_ISR_API    STD_OFF
#define PWM_TAUB4_CH15_ISR_API    STD_OFF
#define PWM_TAUB5_CH00_ISR_API    STD_OFF
#define PWM_TAUB5_CH01_ISR_API    STD_OFF
#define PWM_TAUB5_CH02_ISR_API    STD_OFF
#define PWM_TAUB5_CH03_ISR_API    STD_OFF
#define PWM_TAUB5_CH04_ISR_API    STD_OFF
#define PWM_TAUB5_CH05_ISR_API    STD_OFF
#define PWM_TAUB5_CH06_ISR_API    STD_OFF
#define PWM_TAUB5_CH07_ISR_API    STD_OFF
#define PWM_TAUB5_CH08_ISR_API    STD_OFF
#define PWM_TAUB5_CH09_ISR_API    STD_OFF
#define PWM_TAUB5_CH10_ISR_API    STD_OFF
#define PWM_TAUB5_CH11_ISR_API    STD_OFF
#define PWM_TAUB5_CH12_ISR_API    STD_OFF
#define PWM_TAUB5_CH13_ISR_API    STD_OFF
#define PWM_TAUB5_CH14_ISR_API    STD_OFF
#define PWM_TAUB5_CH15_ISR_API    STD_OFF
#define PWM_TAUB6_CH00_ISR_API    STD_OFF
#define PWM_TAUB6_CH01_ISR_API    STD_OFF
#define PWM_TAUB6_CH02_ISR_API    STD_OFF
#define PWM_TAUB6_CH03_ISR_API    STD_OFF
#define PWM_TAUB6_CH04_ISR_API    STD_OFF
#define PWM_TAUB6_CH05_ISR_API    STD_OFF
#define PWM_TAUB6_CH06_ISR_API    STD_OFF
#define PWM_TAUB6_CH07_ISR_API    STD_OFF
#define PWM_TAUB6_CH08_ISR_API    STD_OFF
#define PWM_TAUB6_CH09_ISR_API    STD_OFF
#define PWM_TAUB6_CH10_ISR_API    STD_OFF
#define PWM_TAUB6_CH11_ISR_API    STD_OFF
#define PWM_TAUB6_CH12_ISR_API    STD_OFF
#define PWM_TAUB6_CH13_ISR_API    STD_OFF
#define PWM_TAUB6_CH14_ISR_API    STD_OFF
#define PWM_TAUB6_CH15_ISR_API    STD_OFF
#define PWM_TAUB7_CH00_ISR_API    STD_OFF
#define PWM_TAUB7_CH01_ISR_API    STD_OFF
#define PWM_TAUB7_CH02_ISR_API    STD_OFF
#define PWM_TAUB7_CH03_ISR_API    STD_OFF
#define PWM_TAUB7_CH04_ISR_API    STD_OFF
#define PWM_TAUB7_CH05_ISR_API    STD_OFF
#define PWM_TAUB7_CH06_ISR_API    STD_OFF
#define PWM_TAUB7_CH07_ISR_API    STD_OFF
#define PWM_TAUB7_CH08_ISR_API    STD_OFF
#define PWM_TAUB7_CH09_ISR_API    STD_OFF
#define PWM_TAUB7_CH10_ISR_API    STD_OFF
#define PWM_TAUB7_CH11_ISR_API    STD_OFF
#define PWM_TAUB7_CH12_ISR_API    STD_OFF
#define PWM_TAUB7_CH13_ISR_API    STD_OFF
#define PWM_TAUB7_CH14_ISR_API    STD_OFF
#define PWM_TAUB7_CH15_ISR_API    STD_OFF
#define PWM_TAUB8_CH00_ISR_API    STD_OFF
#define PWM_TAUB8_CH01_ISR_API    STD_OFF
#define PWM_TAUB8_CH02_ISR_API    STD_OFF
#define PWM_TAUB8_CH03_ISR_API    STD_OFF
#define PWM_TAUB8_CH04_ISR_API    STD_OFF
#define PWM_TAUB8_CH05_ISR_API    STD_OFF
#define PWM_TAUB8_CH06_ISR_API    STD_OFF
#define PWM_TAUB8_CH07_ISR_API    STD_OFF
#define PWM_TAUB8_CH08_ISR_API    STD_OFF
#define PWM_TAUB8_CH09_ISR_API    STD_OFF
#define PWM_TAUB8_CH10_ISR_API    STD_OFF
#define PWM_TAUB8_CH11_ISR_API    STD_OFF
#define PWM_TAUB8_CH12_ISR_API    STD_OFF
#define PWM_TAUB8_CH13_ISR_API    STD_OFF
#define PWM_TAUB8_CH14_ISR_API    STD_OFF
#define PWM_TAUB8_CH15_ISR_API    STD_OFF
#define PWM_TAUD0_CH00_ISR_API    STD_OFF
#define PWM_TAUD0_CH01_ISR_API    STD_OFF
#define PWM_TAUD0_CH02_ISR_API    STD_OFF
#define PWM_TAUD0_CH03_ISR_API    STD_OFF
#define PWM_TAUD0_CH04_ISR_API    STD_OFF
#define PWM_TAUD0_CH05_ISR_API    STD_OFF
#define PWM_TAUD0_CH06_ISR_API    STD_OFF
#define PWM_TAUD0_CH07_ISR_API    STD_OFF
#define PWM_TAUD0_CH08_ISR_API    STD_OFF
#define PWM_TAUD0_CH09_ISR_API    STD_OFF
#define PWM_TAUD0_CH10_ISR_API    STD_OFF
#define PWM_TAUD0_CH11_ISR_API    STD_OFF
#define PWM_TAUD0_CH12_ISR_API    STD_OFF
#define PWM_TAUD0_CH13_ISR_API    STD_OFF
#define PWM_TAUD0_CH14_ISR_API    STD_OFF
#define PWM_TAUD0_CH15_ISR_API    STD_OFF
#define PWM_TAUD1_CH00_ISR_API    STD_OFF
#define PWM_TAUD1_CH01_ISR_API    STD_OFF
#define PWM_TAUD1_CH02_ISR_API    STD_OFF
#define PWM_TAUD1_CH03_ISR_API    STD_OFF
#define PWM_TAUD1_CH04_ISR_API    STD_OFF
#define PWM_TAUD1_CH05_ISR_API    STD_OFF
#define PWM_TAUD1_CH06_ISR_API    STD_OFF
#define PWM_TAUD1_CH07_ISR_API    STD_OFF
#define PWM_TAUD1_CH08_ISR_API    STD_OFF
#define PWM_TAUD1_CH09_ISR_API    STD_OFF
#define PWM_TAUD1_CH10_ISR_API    STD_OFF
#define PWM_TAUD1_CH11_ISR_API    STD_OFF
#define PWM_TAUD1_CH12_ISR_API    STD_OFF
#define PWM_TAUD1_CH13_ISR_API    STD_OFF
#define PWM_TAUD1_CH14_ISR_API    STD_OFF
#define PWM_TAUD1_CH15_ISR_API    STD_OFF
#define PWM_TAUD2_CH00_ISR_API    STD_OFF
#define PWM_TAUD2_CH01_ISR_API    STD_OFF
#define PWM_TAUD2_CH02_ISR_API    STD_OFF
#define PWM_TAUD2_CH03_ISR_API    STD_OFF
#define PWM_TAUD2_CH04_ISR_API    STD_OFF
#define PWM_TAUD2_CH05_ISR_API    STD_OFF
#define PWM_TAUD2_CH06_ISR_API    STD_OFF
#define PWM_TAUD2_CH07_ISR_API    STD_OFF
#define PWM_TAUD2_CH08_ISR_API    STD_OFF
#define PWM_TAUD2_CH09_ISR_API    STD_OFF
#define PWM_TAUD2_CH10_ISR_API    STD_OFF
#define PWM_TAUD2_CH11_ISR_API    STD_OFF
#define PWM_TAUD2_CH12_ISR_API    STD_OFF
#define PWM_TAUD2_CH13_ISR_API    STD_OFF
#define PWM_TAUD2_CH14_ISR_API    STD_OFF
#define PWM_TAUD2_CH15_ISR_API    STD_OFF
#define PWM_TAUD3_CH00_ISR_API    STD_OFF
#define PWM_TAUD3_CH01_ISR_API    STD_OFF
#define PWM_TAUD3_CH02_ISR_API    STD_OFF
#define PWM_TAUD3_CH03_ISR_API    STD_OFF
#define PWM_TAUD3_CH04_ISR_API    STD_OFF
#define PWM_TAUD3_CH05_ISR_API    STD_OFF
#define PWM_TAUD3_CH06_ISR_API    STD_OFF
#define PWM_TAUD3_CH07_ISR_API    STD_OFF
#define PWM_TAUD3_CH08_ISR_API    STD_OFF
#define PWM_TAUD3_CH09_ISR_API    STD_OFF
#define PWM_TAUD3_CH10_ISR_API    STD_OFF
#define PWM_TAUD3_CH11_ISR_API    STD_OFF
#define PWM_TAUD3_CH12_ISR_API    STD_OFF
#define PWM_TAUD3_CH13_ISR_API    STD_OFF
#define PWM_TAUD3_CH14_ISR_API    STD_OFF
#define PWM_TAUD3_CH15_ISR_API    STD_OFF
#define PWM_TAUD4_CH00_ISR_API    STD_OFF
#define PWM_TAUD4_CH01_ISR_API    STD_OFF
#define PWM_TAUD4_CH02_ISR_API    STD_OFF
#define PWM_TAUD4_CH03_ISR_API    STD_OFF
#define PWM_TAUD4_CH04_ISR_API    STD_OFF
#define PWM_TAUD4_CH05_ISR_API    STD_OFF
#define PWM_TAUD4_CH06_ISR_API    STD_OFF
#define PWM_TAUD4_CH07_ISR_API    STD_OFF
#define PWM_TAUD4_CH08_ISR_API    STD_OFF
#define PWM_TAUD4_CH09_ISR_API    STD_OFF
#define PWM_TAUD4_CH10_ISR_API    STD_OFF
#define PWM_TAUD4_CH11_ISR_API    STD_OFF
#define PWM_TAUD4_CH12_ISR_API    STD_OFF
#define PWM_TAUD4_CH13_ISR_API    STD_OFF
#define PWM_TAUD4_CH14_ISR_API    STD_OFF
#define PWM_TAUD4_CH15_ISR_API    STD_OFF
#define PWM_TAUD5_CH00_ISR_API    STD_OFF
#define PWM_TAUD5_CH01_ISR_API    STD_OFF
#define PWM_TAUD5_CH02_ISR_API    STD_OFF
#define PWM_TAUD5_CH03_ISR_API    STD_OFF
#define PWM_TAUD5_CH04_ISR_API    STD_OFF
#define PWM_TAUD5_CH05_ISR_API    STD_OFF
#define PWM_TAUD5_CH06_ISR_API    STD_OFF
#define PWM_TAUD5_CH07_ISR_API    STD_OFF
#define PWM_TAUD5_CH08_ISR_API    STD_OFF
#define PWM_TAUD5_CH09_ISR_API    STD_OFF
#define PWM_TAUD5_CH10_ISR_API    STD_OFF
#define PWM_TAUD5_CH11_ISR_API    STD_OFF
#define PWM_TAUD5_CH12_ISR_API    STD_OFF
#define PWM_TAUD5_CH13_ISR_API    STD_OFF
#define PWM_TAUD5_CH14_ISR_API    STD_OFF
#define PWM_TAUD5_CH15_ISR_API    STD_OFF
#define PWM_TAUD6_CH00_ISR_API    STD_OFF
#define PWM_TAUD6_CH01_ISR_API    STD_OFF
#define PWM_TAUD6_CH02_ISR_API    STD_OFF
#define PWM_TAUD6_CH03_ISR_API    STD_OFF
#define PWM_TAUD6_CH04_ISR_API    STD_OFF
#define PWM_TAUD6_CH05_ISR_API    STD_OFF
#define PWM_TAUD6_CH06_ISR_API    STD_OFF
#define PWM_TAUD6_CH07_ISR_API    STD_OFF
#define PWM_TAUD6_CH08_ISR_API    STD_OFF
#define PWM_TAUD6_CH09_ISR_API    STD_OFF
#define PWM_TAUD6_CH10_ISR_API    STD_OFF
#define PWM_TAUD6_CH11_ISR_API    STD_OFF
#define PWM_TAUD6_CH12_ISR_API    STD_OFF
#define PWM_TAUD6_CH13_ISR_API    STD_OFF
#define PWM_TAUD6_CH14_ISR_API    STD_OFF
#define PWM_TAUD6_CH15_ISR_API    STD_OFF
#define PWM_TAUD7_CH00_ISR_API    STD_OFF
#define PWM_TAUD7_CH01_ISR_API    STD_OFF
#define PWM_TAUD7_CH02_ISR_API    STD_OFF
#define PWM_TAUD7_CH03_ISR_API    STD_OFF
#define PWM_TAUD7_CH04_ISR_API    STD_OFF
#define PWM_TAUD7_CH05_ISR_API    STD_OFF
#define PWM_TAUD7_CH06_ISR_API    STD_OFF
#define PWM_TAUD7_CH07_ISR_API    STD_OFF
#define PWM_TAUD7_CH08_ISR_API    STD_OFF
#define PWM_TAUD7_CH09_ISR_API    STD_OFF
#define PWM_TAUD7_CH10_ISR_API    STD_OFF
#define PWM_TAUD7_CH11_ISR_API    STD_OFF
#define PWM_TAUD7_CH12_ISR_API    STD_OFF
#define PWM_TAUD7_CH13_ISR_API    STD_OFF
#define PWM_TAUD7_CH14_ISR_API    STD_OFF
#define PWM_TAUD7_CH15_ISR_API    STD_OFF
#define PWM_TAUD8_CH00_ISR_API    STD_OFF
#define PWM_TAUD8_CH01_ISR_API    STD_OFF
#define PWM_TAUD8_CH02_ISR_API    STD_OFF
#define PWM_TAUD8_CH03_ISR_API    STD_OFF
#define PWM_TAUD8_CH04_ISR_API    STD_OFF
#define PWM_TAUD8_CH05_ISR_API    STD_OFF
#define PWM_TAUD8_CH06_ISR_API    STD_OFF
#define PWM_TAUD8_CH07_ISR_API    STD_OFF
#define PWM_TAUD8_CH08_ISR_API    STD_OFF
#define PWM_TAUD8_CH09_ISR_API    STD_OFF
#define PWM_TAUD8_CH10_ISR_API    STD_OFF
#define PWM_TAUD8_CH11_ISR_API    STD_OFF
#define PWM_TAUD8_CH12_ISR_API    STD_OFF
#define PWM_TAUD8_CH13_ISR_API    STD_OFF
#define PWM_TAUD8_CH14_ISR_API    STD_OFF
#define PWM_TAUD8_CH15_ISR_API    STD_OFF
#define PWM_TAUJ0_CH00_ISR_API    STD_OFF
#define PWM_TAUJ0_CH01_ISR_API    STD_OFF
#define PWM_TAUJ0_CH02_ISR_API    STD_OFF
#define PWM_TAUJ0_CH03_ISR_API    STD_OFF
#define PWM_TAUJ1_CH00_ISR_API    STD_ON
#define PWM_TAUJ1_CH01_ISR_API    STD_ON
#define PWM_TAUJ1_CH02_ISR_API    STD_OFF
#define PWM_TAUJ1_CH03_ISR_API    STD_OFF
#define PWM_TAUJ2_CH00_ISR_API    STD_OFF
#define PWM_TAUJ2_CH01_ISR_API    STD_OFF
#define PWM_TAUJ2_CH02_ISR_API    STD_OFF
#define PWM_TAUJ2_CH03_ISR_API    STD_OFF
#define PWM_TAUJ3_CH00_ISR_API    STD_ON
#define PWM_TAUJ3_CH01_ISR_API    STD_ON
#define PWM_TAUJ3_CH02_ISR_API    STD_ON
#define PWM_TAUJ3_CH03_ISR_API    STD_ON

/* Macros for enabling/disabling PWM Diagnostic ISRs */

/* Channel Mapping for Timer Unit Channels */
#define PWM_TAUJ3_CH00 0x00U
#define PWM_TAUJ3_CH01 0x01U
#define PWM_TAUJ3_CH02 0x02U
#define PWM_TAUJ3_CH03 0x03U
#define PWM_TAUJ1_CH00 0x04U
#define PWM_TAUJ1_CH01 0x05U
#define PWM_TAUB0_CH00 0x06U
#define PWM_TAUB0_CH01 0x07U


/*******************************************************************************
**                      Channel Handles                                       **
*******************************************************************************/


/* TRACE [R4.2, PWM027] */
/* PWM Channel Handles */
#define PwmConf_PwmChannel_VIP_USB1_SYNC_MASTER (Pwm_ChannelType)0x00
#define PwmConf_PwmChannel_VIP_USB1_SYNC_SLAVE (Pwm_ChannelType)0x01
#define PwmConf_PwmChannel_VIP_ETN_1V_SYNC_MASTER (Pwm_ChannelType)0x02
#define PwmConf_PwmChannel_VIP_ETN_1V_SYNC_SLAVE (Pwm_ChannelType)0x03
#define PwmConf_PwmChannel_VIP_PWR_VG10V_SYNC_MASTER (Pwm_ChannelType)0x04
#define PwmConf_PwmChannel_VIP_PWR_VG10V_SYNC_SLAVE (Pwm_ChannelType)0x05
#define PwmConf_PwmChannel_VIP_VD3V3_SYNC_MASTER (Pwm_ChannelType)0x06
#define PwmConf_PwmChannel_VIP_VD3V3_SYNC_SLAVE (Pwm_ChannelType)0x07

/* Configuration Set Handles */
#define PwmChannelConfigSet0  (&Pwm_GstConfiguration[0])


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PWM_CFG_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
