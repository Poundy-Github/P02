/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Cfg.h                                                   */
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
 * V2.0.0:  31-Oct-2016 : Updated generator to support Autosar 4.2.2 and 4.0.3
 *                        version and removed 3.2.2 Autosar version support.
 *
 * V2.1.0   15-Oct-2016 : Add support for Predef Timers as part of ARDAABC-563
 *
 * V2.2.0:  28-Oct-2016 : Updated generator to support Autosar 4.2.2 and 4.0.3
 *                        MemMap section macros
 *
 * 2.3.1    06-Dec-2016 : Add one new macro GPT_PREDEF_TIMER_ENABLED
 *                        with values STD_ON and STD_OFF to simplify design of
 *                        code when differentiating code sections specific to
 *                        Predef Timer function
 *
 * 2.3.2    10-Feb-2017 : Add traceability tags as per ARDAABC-568
 *
 * 2.3.3    25-May-2017 : As per JIRA ARDAABD-1883, Timer unit macros and WUF1
 *                        support added.
 *
 * 2.3.4    18-Aug-2017 : As per JIRA ARDAABD-2305, Predef timer macros added
 *                        to support all OSTM EI interrupts.
 *
 * 2.3.5    13-Apr-2018 : As per merging activity, #ARDAABD-3489,
 *                        generation of GPT_OSTM_IMR_INTR_REGISTER and
 *                        GPT_OSTM_IMR_INTR_REGISTER_MASK are removed.
 *                        (Ref: ARDAABD-2158) 
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  2.4.10
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-7459765\Generation\Cfg_Gen-1611131101098-0\AutosarFiles_ValGen3453357088559218805\ExtGen_DrvGpt_ECUC_4.2.2_952354714322012804.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\gpt\generator\R422_GPT_F1x_BSWMDT.arxml
 * GENERATED ON:  20 Jan 2021 - 17:07:42
 */
#ifndef GPT_CFG_H
#define GPT_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define GPT_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define GPT_CFG_AR_RELEASE_MINOR_VERSION  2U
#define GPT_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define GPT_CFG_SW_MAJOR_VERSION  1U
#define GPT_CFG_SW_MINOR_VERSION  0U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define GPT_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define GPT_AR_RELEASE_MINOR_VERSION_VALUE  2U
#define GPT_AR_RELEASE_REVISION_VERSION_VALUE  2U

#define GPT_SW_MAJOR_VERSION_VALUE  1U
#define GPT_SW_MINOR_VERSION_VALUE  0U
#define GPT_SW_PATCH_VERSION_VALUE  7U

#define GPT_VENDOR_ID_VALUE  59U
#define GPT_MODULE_ID_VALUE  100U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the Gpt Component*/
/* Implements GPT_ESDD_UD_025*/
#define GPT_INSTANCE_ID_VALUE               0U

/* Pre-compile option for Version information */
/* Implements GPT_ESDD_UD_058 */
/* Implements GPT_ESDD_UD_059 */
#define GPT_AR_VERSION                      GPT_AR_HIGHER_VERSION

/* Implements GPT321_Conf */
/* Implements GPT183_Conf */
/* Implements ECUC_Gpt_00321 */
/* Implements ECUC_Gpt_00183 */
/* Enables/Disables Development error detection */
#define GPT_DEV_ERROR_DETECT                STD_OFF

/* Implements SWS_Gpt_00385 */
/* Implements ECUC_Gpt_00335 */
/* Defines if 100us Predef Timer is enabled or not */
#define GPT_PREDEF_TIMER_100US_32BIT_ENABLE STD_OFF

/* Implements SWS_Gpt_00385 */
/* Implements SWS_Gpt_00386 */
/* Implements ECUC_Gpt_00334 */
/* Provides information about 1us Predef timer configuration
 GPT_PREDEF_TIMER_1US_DISABLED
 GPT_PREDEF_TIMER_1US_16BIT_ENABLED
 GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED
 GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED */
#define GPT_PREDEF_TIMER_1US_ENABLING_GRADE \
                   GPT_PREDEF_TIMER_1US_DISABLED

/* Specifies if Predef Timer function is enabled
 STD_OFF - When all Predef Timers are disabled
 STD_ON  - When at least one Predef Timer is enabled */
#define GPT_PREDEF_TIMER_ENABLED            STD_OFF

/* Implements GPT322_Conf */
/* Implements ECUC_Gpt_00322 */
/* Enables/Disables wakeup source reporting */
#define GPT_REPORT_WAKEUP_SOURCE            STD_OFF

/* Implements GPT314_Conf */
/* Implements GPT193_Conf */
/* Implements ECUC_Gpt_00314 */
/* Implements ECUC_Gpt_00193 */
/* Enables/Disables the inclusion of Gpt_DeInit API */
#define GPT_DE_INIT_API                     STD_ON

/* Implements GPT317_Conf */
/* Implements ECUC_Gpt_00317 */
/* Enables/Disables inclusion of Gpt_GetTimeElapsedAPI */
#define GPT_TIME_ELAPSED_API                STD_ON

/* Implements GPT318_Conf */
/* Implements ECUC_Gpt_00318 */
/* Enables/Disables inclusion of Gpt_GetTimeRemaining API */
#define GPT_TIME_REMAINING_API              STD_ON

/* Implements GPT319_Conf*/
/* Implements ECUC_Gpt_00319*/
/* Enables/Disables GetVersionInfo API */
#define GPT_VERSION_INFO_API                STD_OFF

/* Implements GPT315_Conf */
/* Implements ECUC_Gpt_00315 */
/* Enables/Disables inclusion of Gpt_EnableNotification and
   Gpt_DisableNotification */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API STD_ON

/* Implements GPT320_Conf */
/* Implements ECUC_Gpt_00320 */
/* Enables/Disables inclusion of Gpt_SetMode, Gpt_EnableWakeup
   and Gpt_DisableWakeup */
#define GPT_WAKEUP_FUNCTIONALITY_API        STD_OFF

/* Enable/disable the Critical section protection */
#define GPT_CRITICAL_SECTION_PROTECTION     STD_ON

/* Enable/Disable Clearing Pending Interrupts */
#define GPT_CLEAR_PENDING_INTERRUPT         STD_ON

/* Pre-compile option for enable or disable version check of inter-module
   dependencies */
#define GPT_VERSION_CHECK_EXT_MODULES       STD_OFF

/* Pre-compile option for enable or disable already DET init check */
/* Implements GPT_ESDD_UD_101 */
#define GPT_ALREADY_INIT_DET_CHECK          STD_ON

/* Enable/Disable the TAUD unit depending on TAUD channels configured */
/* Implements GPT_ESDD_UD_036 */
#define GPT_TAUD_UNIT_USED                  STD_OFF

/* Enable/Disable the TAUB unit depending on TAUB channels configured */
/* Implements GPT_ESDD_UD_037 */
#define GPT_TAUB_UNIT_USED                  STD_OFF

/* Enable/Disable the TAUJ unit depending on TAUJ channels configured */
/* Implements GPT_ESDD_UD_038 */
#define GPT_TAUJ_UNIT_USED                  STD_ON

/* Enable/Disable the GPT OSTM unit depending on OSTM channel */
/* Implements GPT_ESDD_UD_039 */
#define GPT_OSTM_UNIT_USED                  STD_OFF

/* Total number of GPT TAUD, TAUB and TAUJ units configured */
/* Implements GPT_ESDD_UD_051 */
#define GPT_TOTAL_TAU_UNITS_CONFIGURED      1U

/* Total number of GPT TAUD units configured */
/* Implements GPT_ESDD_UD_041 */
#define GPT_TOTAL_TAUD_UNITS_CONFIG         0U

/* Total number of GPT TAUB units configured */
/* Implements GPT_ESDD_UD_042 */
#define GPT_TOTAL_TAUB_UNITS_CONFIG         0U

/* Total number of GPT TAUJ units configured */
/* Implements GPT_ESDD_UD_043 */
#define GPT_TOTAL_TAUJ_UNITS_CONFIG         1U

/* Total number of GPT TAUD channels configured */
/* Implements GPT_ESDD_UD_044 */
#define GPT_TOTAL_TAUD_CHANNELS_CONFIG      0U

/* Total number of GPT TAUB channels configured */
/* Implements GPT_ESDD_UD_045 */
#define GPT_TOTAL_TAUB_CHANNELS_CONFIG      0U

/* Total number of GPT  TAUD and TAUB channels */
/* Implements GPT_ESDD_UD_046 */
#define GPT_TOTAL_TAUDB_CHANNELS_CONFIG     0U

/* Total number of GPT  TAUD and TAUB units */
#define GPT_TOTAL_TAUDB_UNITS_CONFIG        0U

/* Total number of GPT TAUJ channels configured */
/* Implements GPT_ESDD_UD_047 */
#define GPT_TOTAL_TAUJ_CHANNELS_CONFIG      2U

/* Total number of GPT Channels configured */
/* Implements GPT_ESDD_UD_035 */
#define GPT_TOTAL_CHANNELS_CONFIG           2U

/* Total number of GPT OSTM unit depending on the OSTM channel */
/* Implements GPT_ESDD_UD_049 */
#define GPT_TOTAL_OSTM_UNITS_CONFIGURED     0U

/* Maximum GPT Channel ID configured */
/* Implements GPT_ESDD_UD_052 */
#define GPT_MAX_CHANNEL_ID_CONFIGURED       1U

/* Enable/disable the setting of baudrate
   by the GPT Driver for TAUB */
/* Implements GPT_ESDD_UD_109 */
#define GPT_TAUB_UNIT_CONFIG                STD_OFF

/* Enable/disable the setting of baudrate
   by the GPT Driver for TAUD */
/* Implements GPT_ESDD_UD_108 */
#define GPT_TAUD_UNIT_CONFIG                STD_OFF

/* Enable/disable the setting of baudrate
   by the GPT Driver for TAUJ */
/* Implements GPT_ESDD_UD_110 */
#define GPT_TAUJ_UNIT_CONFIG                STD_ON

/* Enable/disable the setting of Prescaler and
  blConfigurePrescaler by the GPT Driver */
/* Implements GPT_ESDD_UD_107 */
#define GPT_CONFIG_PRESCALER_SUPPORTED      STD_ON

/* Timeout value for updating the status registers
   of count enable status register for timer stop */
#define GPT_TIMEOUT_COUNT                   480U

/* Enable/disable the register read back for OSTM
   GPT_WV_DISABLE           0
   GPT_WV_INIT_ONLY         1
   GPT_WV_INIT_RUNTIME      2 */
#define GPT_OSTM_WRITE_VERIFY               GPT_WV_DISABLE

/* Enable/disable the register read back for TAUDB
   GPT_WV_DISABLE           0
   GPT_WV_INIT_ONLY         1
   GPT_WV_INIT_RUNTIME      2 */
#define GPT_TAUDB_WRITE_VERIFY              GPT_WV_DISABLE

/* Enable/disable the register read back for TAUJ
   GPT_WV_DISABLE           0
   GPT_WV_INIT_ONLY         1
   GPT_WV_INIT_RUNTIME      2 */
#define GPT_TAUJ_WRITE_VERIFY               GPT_WV_DISABLE

/* Enable/disable the register read back for WUF
   GPT_WV_DISABLE           0
   GPT_WV_INIT_ONLY         1
   GPT_WV_INIT_RUNTIME      2 */
#define GPT_WUF_WRITE_VERIFY                GPT_WV_DISABLE

/* Enable/disable the ram mirroring for OSTM
   GPT_MIRROR_DISABLE           0
   GPT_MIRROR_ENABLE            1 */
#define GPT_OSTM_RAM_MIRROR                 GPT_MIRROR_DISABLE

/* Enable/disable the ram mirroring for TAUDB
   GPT_MIRROR_DISABLE           0
   GPT_MIRROR_ENABLE            1 */
#define GPT_TAUDB_RAM_MIRROR                GPT_MIRROR_DISABLE

/* Enable/disable the ram mirroring for TAUJ
   GPT_MIRROR_DISABLE           0
   GPT_MIRROR_ENABLE            1 */
#define GPT_TAUJ_RAM_MIRROR                 GPT_MIRROR_DISABLE

/* Enable/disable the user error notification in case a Write-Verify
 error occurs */
#define GPT_USE_WV_ERROR_INTERFACE          STD_OFF

/* Enable/Disable the corresponding WUFflag in the ISR */
#define GPT_WAKEUP_FACTOR_CLEAR_ISR         STD_OFF

/* Enable/Disable the output functionality of TAUx, OSTM module */
#define GPT_TIMER_OUTPUT_ENABLE             STD_ON

/* Enable/Disable the WUF1 functionality if supported by device */
#define GPT_WUF1_SUPPORTED                  STD_OFF

/* DEM for timeout  GPT Driver component */
#define GPT_E_TIMEOUT_FAILURE               \
        DemConf_DemEventParameter_AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE

/* MemMap file switch */
#if(GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
/* ASR 4.2.2 */
  #define GPT_MEMMAP_FILE "Gpt_MemMap.h"
#else
/* ASR 4.0.3 */
  #define GPT_MEMMAP_FILE "MemMap.h"
#endif


/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
/*Implements GPT_ESDD_UD_050*/
/* Macros for enabling/disabling ISRS */
#define GPT_OSTM0_CH00_ISR_API    STD_OFF
#define GPT_OSTM1_CH00_ISR_API    STD_OFF
#define GPT_OSTM2_CH00_ISR_API    STD_OFF
#define GPT_OSTM3_CH00_ISR_API    STD_OFF
#define GPT_OSTM4_CH00_ISR_API    STD_OFF
#define GPT_OSTM5_CH00_ISR_API    STD_OFF
#define GPT_OSTM6_CH00_ISR_API    STD_OFF
#define GPT_OSTM7_CH00_ISR_API    STD_OFF
#define GPT_OSTM8_CH00_ISR_API    STD_OFF
#define GPT_OSTM9_CH00_ISR_API    STD_OFF
#define GPT_TAUB0_CH00_ISR_API    STD_OFF
#define GPT_TAUB0_CH01_ISR_API    STD_OFF
#define GPT_TAUB0_CH02_ISR_API    STD_OFF
#define GPT_TAUB0_CH03_ISR_API    STD_OFF
#define GPT_TAUB0_CH04_ISR_API    STD_OFF
#define GPT_TAUB0_CH05_ISR_API    STD_OFF
#define GPT_TAUB0_CH06_ISR_API    STD_OFF
#define GPT_TAUB0_CH07_ISR_API    STD_OFF
#define GPT_TAUB0_CH08_ISR_API    STD_OFF
#define GPT_TAUB0_CH09_ISR_API    STD_OFF
#define GPT_TAUB0_CH10_ISR_API    STD_OFF
#define GPT_TAUB0_CH11_ISR_API    STD_OFF
#define GPT_TAUB0_CH12_ISR_API    STD_OFF
#define GPT_TAUB0_CH13_ISR_API    STD_OFF
#define GPT_TAUB0_CH14_ISR_API    STD_OFF
#define GPT_TAUB0_CH15_ISR_API    STD_OFF
#define GPT_TAUB1_CH00_ISR_API    STD_OFF
#define GPT_TAUB1_CH01_ISR_API    STD_OFF
#define GPT_TAUB1_CH02_ISR_API    STD_OFF
#define GPT_TAUB1_CH03_ISR_API    STD_OFF
#define GPT_TAUB1_CH04_ISR_API    STD_OFF
#define GPT_TAUB1_CH05_ISR_API    STD_OFF
#define GPT_TAUB1_CH06_ISR_API    STD_OFF
#define GPT_TAUB1_CH07_ISR_API    STD_OFF
#define GPT_TAUB1_CH08_ISR_API    STD_OFF
#define GPT_TAUB1_CH09_ISR_API    STD_OFF
#define GPT_TAUB1_CH10_ISR_API    STD_OFF
#define GPT_TAUB1_CH11_ISR_API    STD_OFF
#define GPT_TAUB1_CH12_ISR_API    STD_OFF
#define GPT_TAUB1_CH13_ISR_API    STD_OFF
#define GPT_TAUB1_CH14_ISR_API    STD_OFF
#define GPT_TAUB1_CH15_ISR_API    STD_OFF
#define GPT_TAUD0_CH00_ISR_API    STD_OFF
#define GPT_TAUD0_CH01_ISR_API    STD_OFF
#define GPT_TAUD0_CH02_ISR_API    STD_OFF
#define GPT_TAUD0_CH03_ISR_API    STD_OFF
#define GPT_TAUD0_CH04_ISR_API    STD_OFF
#define GPT_TAUD0_CH05_ISR_API    STD_OFF
#define GPT_TAUD0_CH06_ISR_API    STD_OFF
#define GPT_TAUD0_CH07_ISR_API    STD_OFF
#define GPT_TAUD0_CH08_ISR_API    STD_OFF
#define GPT_TAUD0_CH09_ISR_API    STD_OFF
#define GPT_TAUD0_CH10_ISR_API    STD_OFF
#define GPT_TAUD0_CH11_ISR_API    STD_OFF
#define GPT_TAUD0_CH12_ISR_API    STD_OFF
#define GPT_TAUD0_CH13_ISR_API    STD_OFF
#define GPT_TAUD0_CH14_ISR_API    STD_OFF
#define GPT_TAUD0_CH15_ISR_API    STD_OFF
#define GPT_TAUJ0_CH00_ISR_API    STD_OFF
#define GPT_TAUJ0_CH01_ISR_API    STD_ON
#define GPT_TAUJ0_CH02_ISR_API    STD_OFF
#define GPT_TAUJ0_CH03_ISR_API    STD_OFF
#define GPT_TAUJ1_CH00_ISR_API    STD_OFF
#define GPT_TAUJ1_CH01_ISR_API    STD_OFF
#define GPT_TAUJ1_CH02_ISR_API    STD_OFF
#define GPT_TAUJ1_CH03_ISR_API    STD_OFF
#define GPT_TAUJ2_CH00_ISR_API    STD_OFF
#define GPT_TAUJ2_CH01_ISR_API    STD_OFF
#define GPT_TAUJ2_CH02_ISR_API    STD_OFF
#define GPT_TAUJ2_CH03_ISR_API    STD_OFF
#define GPT_TAUJ3_CH00_ISR_API    STD_OFF
#define GPT_TAUJ3_CH01_ISR_API    STD_OFF
#define GPT_TAUJ3_CH02_ISR_API    STD_OFF
#define GPT_TAUJ3_CH03_ISR_API    STD_OFF

/* Channel Mapping for Timer Unit Channels */
#define GPT_TAUJ0_CH00 0x00U
#define GPT_TAUJ0_CH01 0x01U

/*******************************************************************************
**                      Channel Handles                                       **
*******************************************************************************/


/* GPT Channel Handles */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_tick \
                 (Gpt_ChannelType)0x00
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_1ms_tick \
                 (Gpt_ChannelType)0x01

/* Configuration Set Handles */
/* Implements GPT269_Conf */
/* Implements GPT184_Conf */
/* Implements ECUC_Gpt_00269 */
/* Implements ECUC_Gpt_00184 */
#define GptChannelConfigSet0  (&Gpt_GstConfiguration[0])


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* GPT_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
