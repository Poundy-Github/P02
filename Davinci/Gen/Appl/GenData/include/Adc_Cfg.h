/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Cfg.h                                                   */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  03-Sep-2015  : Initial Version
 * V2.0.0   05-Aug-2016  : The following changes are made:
 *                         1. As a part of JIRA ticket ARDAABC-788,
 *                            added FUSA implementation.
 * V2.0.1:  01-Nov-2016  : The following changes are made:
 *                         1. As a part of JIRA ticket ARDAABC-788,
 *                            updated the copyright to 2016, added Write-Verify
 *                            error interface as a macro.
 * V2.1.0   25-Nov-2016  : The following changes are made:
 *                         1. As part of JIRA ticket ARDAABC-940
 *                            ADC_MEMMAP_FILE macro is introduced.
 * V2.1.1:  21-May-2018  : The following changes are made:
 *                         1.As part of merging activity  #ARDAABD-3452,
 *                           a.Macro ADC_ICR_QFULL,
 *                             ADC_IMR_QFULL_REGISTER_ADDRESS,
 *                             ADC_IMR_QFULL_MASK_VALUE removed.Ref:ARDAABD-2158
 *                           b.Copyright updated.
 *                         2.As part of ARDAABD-1711, macro ADC_MAX_DIAG_IDS
 *                           added.
 * V2.1.2   19-Jul-2019    Following changes are made:
 *                         1.As part of ARDAABD-4074, Added
 *                           ADC_FLEX_LIMITCHECK_RANGE macro.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.15.3
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5446369\Generation\Cfg_Gen-1602315694632-0\AutosarFiles_ValGen2648245967057569354\ExtGen_DrvAdc_ECUC_4.2.2_178175295851930220.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\adc\generator\R422_ADC_F1x_BSWMDT.arxml
 * GENERATED ON:  10 Oct 2020 - 15:52:13
 */

#ifndef ADC_CFG_H
#define ADC_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ADC_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define ADC_CFG_AR_RELEASE_MINOR_VERSION  2U
#define ADC_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define ADC_CFG_SW_MAJOR_VERSION  1U
#define ADC_CFG_SW_MINOR_VERSION  1U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define ADC_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define ADC_AR_RELEASE_MINOR_VERSION_VALUE  2U
#define ADC_AR_RELEASE_REVISION_VERSION_VALUE  2U

#define ADC_SW_MAJOR_VERSION_VALUE  1U
#define ADC_SW_MINOR_VERSION_VALUE  1U
#define ADC_SW_PATCH_VERSION_VALUE  3U

#define ADC_VENDOR_ID_VALUE  59U
#define ADC_MODULE_ID_VALUE  123U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the ADC Driver */
/* Implements ADC_ESDD_UD_014 */
#define ADC_INSTANCE_ID_VALUE               0U

/* Pre-compile option for Version information*/
/* Implements ADC_ESDD_UD_038 */
#define ADC_AR_VERSION                      ADC_AR_HIGHER_VERSION

/* Enables/Disables Development error detection */
#define ADC_DEV_ERROR_DETECT                STD_OFF

/* Enables/Disables DEM error detection*/
/* Implements ADC_ESDD_UD_176 */
#define ADC_DEM_ERROR_DETECT                STD_OFF

/*  Enables/Disables GetVersionInfo API */
#define ADC_VERSION_INFO_API                STD_OFF

/* Enables/Disables the inclusion of Adc_DeInit API */
#define ADC_DEINIT_API                      STD_ON

/* Enables/Disables the inclusion of first come first serve mechanism */
#define ADC_ENABLE_QUEUING                  STD_OFF

/* Enables/Disables Adc_StartGroupConversion and
   Adc_StopGroupConversion functions */
#define ADC_ENABLE_START_STOP_GROUP_API     STD_ON

/* Enables/Disables Adc_EnableHardwareTrigger and
   Adc_DisableHardwareTrigger functions */
#define ADC_HW_TRIGGER_API                  STD_ON

/* Enables/Disables Adc_ReadGroup function */
#define ADC_READ_GROUP_API                  STD_ON

/* Enables/Disables Adc_GetStreamLastPointer function*/
/* Implements ADC_ESDD_UD_022 */
#define ADC_GETSTREAMLASTPOINTER_API        STD_OFF

/* Enables/Disables Notification functions */
#define ADC_GRP_NOTIF_CAPABILITY            STD_ON

/* Enables/Disables priority mechanism functions */
#define ADC_PRIORITY_IMPLEMENTATION         ADC_PRIORITY_NONE

/* Enables/Disables limit checking functionality */
#define ADC_ENABLE_LIMIT_CHECK              STD_OFF

/* Number of hardware units configured*/
/* Implements ADC_ESDD_UD_025 */
#define ADC_MAX_HW_UNITS                    2U

/* Enables/Disables DMA ISR for DMA channel */
#define ADC_DMA_MODE_ENABLE                 STD_OFF

/* Enables/Disables the enter/exit critical section functionality */
#define ADC_CRITICAL_SECTION_PROTECTION     STD_ON

/*  Enables/Disables Track and Hold feature */
#define ADC_TRACK_AND_HOLD                  STD_ON

/* Enables/Disables version check of Adc with dependent module */
#define ADC_VERSION_CHECK_EXT_MODULES       STD_OFF

/* Enables/Disables ISR for SG1 unit of HW 0*/
/* Implements ADC_ESDD_UD_026 */
#define ADC0_SG1_ISR_API                    STD_ON

/* Enables/Disables ISR for SG2 unit of HW 0 */
#define ADC0_SG2_ISR_API                    STD_OFF

/* Enables/Disables ISR for SG3 unit of HW 0 */
#define ADC0_SG3_ISR_API                    STD_OFF

/* Enables/Disables ISR for SG1 unit of HW 1 */
#define ADC1_SG1_ISR_API                    STD_ON

/* Enables/Disables ISR for SG2 unit of HW 1 */
#define ADC1_SG2_ISR_API                    STD_OFF

/* Enables/Disables ISR for SG3 unit of HW 1 */
#define ADC1_SG3_ISR_API                    STD_OFF

/* Enables/Disables DMA ISR for DMA channel 0*/
/* Implements ADC_ESDD_UD_027 */
#define ADC_DMA_ISR_CH00_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 1 */
#define ADC_DMA_ISR_CH01_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 2 */
#define ADC_DMA_ISR_CH02_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 3 */
#define ADC_DMA_ISR_CH03_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 4 */
#define ADC_DMA_ISR_CH04_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 5 */
#define ADC_DMA_ISR_CH05_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 6 */
#define ADC_DMA_ISR_CH06_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 7 */
#define ADC_DMA_ISR_CH07_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 8 */
#define ADC_DMA_ISR_CH08_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 9 */
#define ADC_DMA_ISR_CH09_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 10 */
#define ADC_DMA_ISR_CH10_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 11 */
#define ADC_DMA_ISR_CH11_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 12 */
#define ADC_DMA_ISR_CH12_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 13 */
#define ADC_DMA_ISR_CH13_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 14 */
#define ADC_DMA_ISR_CH14_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 15 */
#define ADC_DMA_ISR_CH15_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 16 */
#define ADC_DMA_ISR_CH16_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 17 */
#define ADC_DMA_ISR_CH17_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 18 */
#define ADC_DMA_ISR_CH18_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 19 */
#define ADC_DMA_ISR_CH19_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 20 */
#define ADC_DMA_ISR_CH20_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 21 */
#define ADC_DMA_ISR_CH21_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 22 */
#define ADC_DMA_ISR_CH22_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 23 */
#define ADC_DMA_ISR_CH23_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 24 */
#define ADC_DMA_ISR_CH24_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 25 */
#define ADC_DMA_ISR_CH25_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 26 */
#define ADC_DMA_ISR_CH26_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 27 */
#define ADC_DMA_ISR_CH27_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 28 */
#define ADC_DMA_ISR_CH28_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 29 */
#define ADC_DMA_ISR_CH29_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 30 */
#define ADC_DMA_ISR_CH30_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 31 */
#define ADC_DMA_ISR_CH31_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 32 */
#define ADC_DMA_ISR_CH32_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 33 */
#define ADC_DMA_ISR_CH33_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 34 */
#define ADC_DMA_ISR_CH34_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 35 */
#define ADC_DMA_ISR_CH35_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 36 */
#define ADC_DMA_ISR_CH36_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 37 */
#define ADC_DMA_ISR_CH37_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 38 */
#define ADC_DMA_ISR_CH38_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 39 */
#define ADC_DMA_ISR_CH39_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 40 */
#define ADC_DMA_ISR_CH40_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 41 */
#define ADC_DMA_ISR_CH41_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 42 */
#define ADC_DMA_ISR_CH42_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 43 */
#define ADC_DMA_ISR_CH43_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 44 */
#define ADC_DMA_ISR_CH44_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 45 */
#define ADC_DMA_ISR_CH45_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 46 */
#define ADC_DMA_ISR_CH46_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 47 */
#define ADC_DMA_ISR_CH47_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 48 */
#define ADC_DMA_ISR_CH48_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 49 */
#define ADC_DMA_ISR_CH49_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 50 */
#define ADC_DMA_ISR_CH50_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 51 */
#define ADC_DMA_ISR_CH51_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 52 */
#define ADC_DMA_ISR_CH52_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 53 */
#define ADC_DMA_ISR_CH53_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 54 */
#define ADC_DMA_ISR_CH54_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 55 */
#define ADC_DMA_ISR_CH55_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 56 */
#define ADC_DMA_ISR_CH56_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 57 */
#define ADC_DMA_ISR_CH57_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 58 */
#define ADC_DMA_ISR_CH58_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 59 */
#define ADC_DMA_ISR_CH59_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 60 */
#define ADC_DMA_ISR_CH60_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 61 */
#define ADC_DMA_ISR_CH61_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 62 */
#define ADC_DMA_ISR_CH62_API                STD_OFF

/* Enables/Disables DMA ISR for DMA channel 63 */
#define ADC_DMA_ISR_CH63_API                STD_OFF

/* Number of SGm units enabled */
#define ADC_NUMBER_OF_SG_UNITS              2U

/* Enables/Disables the PWM diagnostic functionality */
#define ADC_ENABLE_DIAGNOSTIC_SUPPORT       STD_OFF

/* Enables/Disables the External multiplexer functionality */
#define ADC_ENABLE_EXTERNAL_MUX             STD_OFF

/* Indicates whether Hardware delay is supported in Mux */
#define ADC_HW_MUX_STAB_SUPPORT             STD_OFF

/* Enables/Disables Adc_EnableChannel and Adc_DisableChannel functions */
#define ADC_ENABLE_DISABLE_CHANNEL          STD_OFF

/* Enables/Disables the ADC_E_ALREADY_INITIALIZED Det check in Adc_Init API*/
/* Implements ADC_ESDD_UD_114 */
#define ADC_ALREADY_INIT_DET_CHECK          STD_OFF

/* Enables/Disables the RAM allocation for result buffer */
#define ADC_ENABLE_BUFFER_ALLOCATION        STD_OFF

/* Enables/Disables the streaming functionality*/
/* Implements ADC_ESDD_UD_128 */
#define ADC_ENABLE_STREAMING                STD_OFF

/* Enables/Disables the flexibility to change physical channel*/
/*   threshold during run time*/
/* Implements ADC_ESDD_UD_161 */
#define ADC_FLEXIBLE_THRESHOLD              STD_OFF

/* Enables/Disables self-diagnostic functionality*/
/* Implements ADC_ESDD_UD_164 */
#define ADC_SELF_DIAG_SUPPORT               STD_OFF

/* Enables/Disables clearing WakeUpFactor functionality */
#define ADC_WAKEUPFACTOR_CLEAR_ISR          STD_OFF

/* Enables/Disables the Error Interrupt*/
/* Implements ADC_ESDD_UD_150 */
#define ADC_ERROR_SUPPORT                   STD_OFF

/* Selected functionality mode*/
/* Implements ADC_ESDD_UD_162 */
#define ADC_FUNCTIONALITY_MODE              ADC_POLLING_INTERRUPT

/* Enables/Disables pin level self diagnostic support*/
/* Implements ADC_ESDD_UD_165 */
#define ADC_ENABLE_SELF_DIAG_PIN_LVL        STD_OFF

/* Enable support to stop the scan group using using ADCAnSGSTPCRx Resistor. */
#define ADC_HARD_STOP                       STD_ON

/* Enable support for additional limit check selections. */
#define ADC_ENHANCED_LIMIT_CHECK            STD_ON

/* Enables/Disables open pin self diag support*/
/* Implements ADC_ESDD_UD_166 */
#define ADC_ENABLE_SELF_DIAG_WIRE_BRK       STD_OFF

/* Enables/Disables ISR Queue full for PWM Diagnostic*/
/* Implements ADC_ESDD_UD_153 */
#define ADC_PWSA_INT_QFULL_ISR              STD_OFF

/* ONE-SHOT scan group conversions using ADHALT bit setting*/
/* Implements ADC_ESDD_UD_174 */
#define ADC_SOFT_STOP                       STD_OFF

/* Total number of diagnostic channels available */
#define ADC_MAX_DIAG_CHANNEL                79U

/* Enables/Disables double buffer functionality */
#define ADC_PWM_DIAG_DOUBLE_BUFF            STD_OFF

/* Implements EAAR_PN0034_FSR_0011 */
/* Implements EAAR_PN0034_FSR_0013 */
/* Value of loop timeout (loops count) */
#define ADC_LOOP_TIMEOUT                    65535U

/* Implements EAAR_PN0034_FSR_0002 */
/* Set mode for Write-Verify of ADCA registers */
#define ADC_ADCA_WRITE_VERIFY               ADC_WV_DISABLE

/* Implements EAAR_PN0034_FSR_0002 */
/* Set mode for Write-Verify of PWMDIAG registers */
#define ADC_PWMDIAG_WRITE_VERIFY            ADC_WV_DISABLE

/* Implements EAAR_PN0034_FSR_0002 */
/* Set mode for Write-Verify of DMAC registers */
#define ADC_DMAC_WRITE_VERIFY               ADC_WV_DISABLE

/* Implements EAAR_PN0034_FSR_0002 */
/* Set mode for Write-Verify of WUF registers */
#define ADC_WUF_WRITE_VERIFY                ADC_WV_DISABLE

/* Implements EAAR_PN0034_FSR_0006 */
/* Set mode for RAM Mirror of ADCA registers */
#define ADC_ADCA_RAM_MIRROR                 ADC_MIRROR_DISABLE

/* Implements EAAR_PN0034_FSR_0006 */
/* Set mode for RAM Mirror of PWMDIAG registers */
#define ADC_PWMDIAG_RAM_MIRROR              ADC_MIRROR_DISABLE

/* Implements EAAR_PN0034_FSR_0006 */
/* Set mode for RAM Mirror of DMAC registers */
#define ADC_DMAC_RAM_MIRROR                 ADC_MIRROR_DISABLE

/* Implements EAAR_PN0034_FSR_0003 */
/* Set use of error interface for Write-Verify Functional Safety */
#define ADC_USE_WV_ERROR_INTERFACE          STD_OFF





/* ADC Group Handles */
#define AdcConf_AdcGroup_AdcGroup0 (Adc_GroupType)0x00
#define AdcConf_AdcGroup_AdcGroup1 (Adc_GroupType)0x01

/* Configuration Set Handles */
/* Implements ADC_ESDD_UD_030 */
#define AdcConfigSet0  (&Adc_GstConfiguration[0])





/* MemMap file switch */
#if(ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
/* ASR 4.2.2 */
#define ADC_MEMMAP_FILE "Adc_MemMap.h"
#else
/* ASR 4.0.3 */
#define ADC_MEMMAP_FILE "MemMap.h"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ADC_CFG_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
