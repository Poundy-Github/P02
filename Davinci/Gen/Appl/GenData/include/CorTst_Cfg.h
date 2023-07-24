/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Cfg.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 Renesas Electronics Corporation                          */
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
 * V1.0.0:  27-Nov-2013 : Initial Version
 * V1.0.1:  15-Jan-2014 : As per CR 348, for the mantis issue #18244,
 *                        Copyright information is updated.
 * V1.0.2:  06-Aug-2014 : As per CR 604, for the mantis #22252, changes are
 *                        made at all relevant places accordingly to append
 *                        U or UL after numeric values.
 * V2.0.0:  07-Sep-2016 : #ARDAABD-492
 *                        1. Updated to ASR 4.2.2
 * V2.0.1:  19-Oct-2016 : #ARDAABD-889
 *                        1. Remove unwanted macros
 * V2.0.2   20-Oct-2016   #ARDAABD-899
 *                        1.Change Memmap macro generation
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.5
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-6874790\Generation\Cfg_Gen-1606880170386-0\AutosarFiles_ValGen172034617495837798\ExtGen_DrvCorTst_ECUC_4.2.2_8597882667511532847.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\cortst\generator\R422_CORTST_F1x_BSWMDT.arxml
 * GENERATED ON:   2 Dec 2020 - 14:23:32
 */
#ifndef CORTST_CFG_H
#define CORTST_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define CORTST_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define CORTST_CFG_AR_RELEASE_MINOR_VERSION  2U
#define CORTST_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define CORTST_CFG_SW_MAJOR_VERSION  1U
#define CORTST_CFG_SW_MINOR_VERSION  1U
#define CORTST_CFG_SW_PATCH_VERSION  5U


/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define CORTST_AR_RELEASE_MAJOR_VERSION_VALUE 4U
#define CORTST_AR_RELEASE_MINOR_VERSION_VALUE 2U
#define CORTST_AR_RELEASE_REVISION_VERSION_VALUE 2U

#define CORTST_SW_MAJOR_VERSION_VALUE       1U
#define CORTST_SW_MINOR_VERSION_VALUE       1U
#define CORTST_SW_PATCH_VERSION_VALUE       5U

#define CORTST_MODULE_ID_VALUE              103U
#define CORTST_VENDOR_ID_VALUE              59U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* CORTST_CFG_H_001: CORTST_ESDD_UD_010, CORTST_ESDD_UD_046, CORTST_ESDD_UD_047 */
/* Instance ID of the CORTST Driver */
#define CORTST_INSTANCE_ID_VALUE             0U

/* Macros for G3K Core  */
#define CORE_G3K                             0U

/* Macros for G3KH Core  */
#define CORE_G3KH                            1U

/* CORTST_CFG_H_002: CORTST_ESDD_UD_063 */
/* Pre-compile option for Version information */
#define CORTST_AR_VERSION                 CORTST_AR_HIGHER_VERSION

/* Pre-compile option for MemMap file */
#define MEMMAP_FILE                       "CorTst_MemMap.h"

/* CORTST_CFG_H_003: CORTST_ESDD_UD_011 */
/* Pre-compile option for development error detect */
#define CORTST_DEV_ERROR_DETECT           STD_OFF

/* CORTST_CFG_H_004: CORTST_ESDD_UD_023 */
/* Total number of Test Configurations available in Foreground mode */
#define CORTST_FGND_TEST_NUMBER           0x00000001UL

/* CORTST_CFG_H_005: CORTST_ESDD_UD_024 */
/* Core Test Interval Id End value */
#define CORTST_TEST_INTERVAL_ID_END_VALUE 0x00000000UL

/* CORTST_CFG_H_006: CORTST_ESDD_UD_020 */
/*Enable/disable the version check of inter-module dependencies */
#define CORTST_VERSION_CHECK_EXT_MODULES  STD_OFF

/* CORTST_CFG_H_007: CORTST_ESDD_UD_022 */
/* Enable/disable the Critical section protection */
#define CORTST_CRITICAL_SECTION_PROTECTION STD_ON

/* CORTST_CFG_H_008: CORTST_ESDD_UD_012 */
/* Pre-compile option for Core Test completed notification */
#define CORTST_NOTIFICATION_SUPPORTED     STD_ON

/* CORTST_CFG_H_009: CORTST_ESDD_UD_013 */
/* Enable/Disable the CorTst_Abort function  */
#define CORTST_ABORT_API                  STD_OFF

/* CORTST_CFG_H_010: CORTST_ESDD_UD_014 */
/* Enable/Disable the CorTst_GetCurrentStatus function */
#define CORTST_GET_CURRENT_STATUS_API     STD_ON

/* CORTST_CFG_H_011: CORTST_ESDD_UD_015 */
/* Enable/Disable the CorTst_GetFgndSignature function */
#define CORTST_GET_FGND_SIGNATURE_API     STD_ON

/* CORTST_CFG_H_012: CORTST_ESDD_UD_016 */
/* Enable/Disable the CorTst_GetSignature function */
#define CORTST_GET_SIGNATURE_API          STD_ON

/* CORTST_CFG_H_013: CORTST_ESDD_UD_017 */
/* Enable/Disable the CorTst_GetState function  */
#define CORTST_GET_STATE_API              STD_ON

/* CORTST_CFG_H_014: CORTST_ESDD_UD_018 */
/* Enable/Disable the CorTst_Start function  */
#define CORTST_START_API                  STD_ON

/* CORTST_CFG_H_015: CORTST_ESDD_UD_019 */
/* Enable/Disable the CorTst_GetVersionInfo function */
#define CORTST_VERSION_INFO_API           STD_OFF

/* CORTST_CFG_H_016: CORTST_ESDD_UD_025 */
/* Total number of Test Configurations available in Background mode */
#define CORTST_BGND_TEST_NUMBER           0x00000000UL

/* CORTST_CFG_H_017: CORTST_ESDD_UD_026 */
/* Total number of ST modules to be tested within Core Test module */
#define CORTST_NUM_TEST_AVAILABLE         90U

/* CORTST_CFG_H_018: CORTST_ESDD_UD_021 */
/* Enables/Disables the CORTST_E_ALREADY_INITIALIZED Det check in CorTst_Init API */
#define CORTST_ALREADY_INIT_DET_CHECK     STD_ON

/* CORTST_CFG_H_019: CORTST_ESDD_UD_027 */
/* Inclusion/Exclusion of Back Ground test functionality since one/none of Bgnd config set is configurred */
#define CORTST_BGND_TEST_CFG_AVAILABLE    STD_OFF

/* CORTST_CFG_H_020: CORTST_ESDD_UD_035 */
/* Report error to DEM that CORTST job failed  */
#define CORTST_E_CORE_FAILURE             DemConf_DemEventParameter_AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core



/* Defines either G3K or G3KH core */
#define CORTST_SWCST                      CORE_G3KH


/*******************************************************************************
**                             Handles                                        **
*******************************************************************************/



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CORTST_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
