/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = FlsTst_Cfg.h                                                */
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
 * V1.0.0:  25-Sep-2013 : Initial Version
 * V1.0.1:  18-Sep-2014 : As per CR 012 and mantis #19850, following changes
 *                        are made:
 *                        1. Copyright information is updated.
 *                        2. Changes are made at all relevant places
 *                           accordingly to append U or UL after numeric values.
 *                        3. Marker IDs are added newly.
 * V2.0.0   30-Sep-2016 : Added WV and Ram mirror parameters
 * V2.0.1   09-Feb-2017 : As Part of JIRA ARDAABD-848 : Remove checking for ASR
 *                        version for MemMap file
 *                        As Part of JIRA ARDAABD-714: Renamed
 *                        FLSTST_CF1STERSTR_VCI register to
 *                        FLSTST_CF1STERSTR_VCILL
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.3
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-6874790\Generation\Cfg_Gen-1606880170386-0\AutosarFiles_ValGen172034617495837798\ExtGen_DrvFlsTst_ECUC_4.2.2_2026105568877334215.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\flstst\generator\R422_FLSTST_F1x_BSWMDT.arxml
 * GENERATED ON:   2 Dec 2020 - 14:23:10
 */
#ifndef FLSTST_CFG_H
#define FLSTST_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define FLSTST_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define FLSTST_CFG_AR_RELEASE_MINOR_VERSION  2U
#define FLSTST_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define FLSTST_CFG_SW_MAJOR_VERSION  2U
#define FLSTST_CFG_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define FLSTST_AR_RELEASE_MAJOR_VERSION_VALUE 4U
#define FLSTST_AR_RELEASE_MINOR_VERSION_VALUE 2U
#define FLSTST_AR_RELEASE_REVISION_VERSION_VALUE 2U

#define FLSTST_SW_MAJOR_VERSION_VALUE       2U
#define FLSTST_SW_MINOR_VERSION_VALUE       1U
#define FLSTST_SW_PATCH_VERSION_VALUE       2U

#define FLSTST_MODULE_ID_VALUE              104U
#define FLSTST_VENDOR_ID_VALUE              59U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the FLSTST Driver */
#define FLSTST_INSTANCE_ID_VALUE             0U

/* Pre-compile option for Version information */
#define FLSTST_AR_VERSION                 FLSTST_AR_HIGHER_VERSION

/* Pre-compile option for MemMap file */
#define FLSTST_MEMMAP_FILE                "FlsTst_MemMap.h"

/* TRACE [R4, FlsTst008] */
/* TRACE [R4, FlsTst083_Conf] */
/* Enables/Disables Development error detection */
#define FLSTST_DEV_ERROR_DETECT           STD_OFF

/* Enable/disable the version check of inter-module dependencies */
#define FLSTST_VERSION_CHECK_EXT_MODULES  STD_OFF

/* Pre-compile option for the critical section functionality */
#define FLSTST_CRITICAL_SECTION_PROTECTION STD_ON

/* Pre-compile option for enable or disable already DET init check */
#define FLSTST_ALREADY_INIT_DET_CHECK     STD_ON

/* TRACE [R4, FlsTst159] */
/* TRACE [R4, FlsTst084_Conf] */
/* Enables/Disables FLSTST Notification */
#define FLSTST_TEST_COMPLETED_NOTIFICATION_SUPPORTED STD_ON

/* TRACE [R4, EAAR_PN0034_FSR_0002 ] */
/* Enables/Disables registers write verify */
#define FLSTST_WRITE_VERIFY               FLSTST_WV_DISABLE

/* TRACE [R4, EAAR_PN0034_FSR_0006 ] */
/* Enables/Disables register Ram mirroring functionallity */
#define FLSTST_RAM_MIRROR                 FLSTST_DISABLE

/* TRACE [R4, EAAR_PN0034_FSR_0004 ] */
/* Enables/Disables FLSTST Notification */
#define FLSTST_USE_WV_ERROR_INTERFACE     STD_OFF

/* TRACE [R4, FlsTst160_Conf] */
/* Configures the result of the test in background mode */
#define FLSTST_TEST_RESULT_SIGNATURE      STD_OFF

/* TRACE [R4, FlsTst091] */
/* TRACE [R4, FlsTst092_Conf] */
/* Enable/disable FlsTst_GetCurrentState API */
#define FLSTST_GET_CURRENT_STATE_API      STD_OFF

/* TRACE [R4, FlsTst062] */
/* TRACE [R4, FlsTst098_Conf] */
/* Enable/disable FlsTst_GetErrorDetails API */
#define FLSTST_GET_ERROR_DETAILS_API      STD_OFF

/* TRACE [R4, FlsTst093] */
/* TRACE [R4, FlsTst094_Conf] */
/* Enables/Disables the FlsTst_GetTestResultBgnd API */
#define FLSTST_GET_TEST_RESULT_BGND_API   STD_OFF

/* TRACE [R4, FlsTst114] */
/* TRACE [R4, FlsTst150_Conf] */
/* Enables/Disables the FlsTst_GetTestResultFgnd API */
#define FLSTST_GET_TEST_RESULT_FGND_API   STD_ON

/* TRACE [R4, FlsTst096_Conf] */
/* TRACE [R4, FlsTst056] */
/* Enables/Disables the FlsTst_GetTestSignatureBgnd API */
#define FLSTST_GET_TEST_SIGNATURE_BGND_API STD_OFF

/* TRACE [R4, FlsTst059] */
/* TRACE [R4, FlsTst097_Conf] */
/* Enables/Disables FlsTst_GetTestSignatureFgnd API */
#define FLSTST_GET_TEST_SIGNATURE_FGND_API STD_ON

/* TRACE [R4, FlsTst051] */
/* TRACE [R4, FlsTst086_Conf] */
/* Enables/Disables the FlsTst_StartFgnd API */
#define FLSTST_START_FGND_API             STD_ON

/* TRACE [R4, FlsTst088] */
/* TRACE [R4, FlsTst089] */
/* TRACE [R4, FlsTst087_Conf] */
/* Enables/Disables FlsTst_Suspend and FlsTst_Resume API */
#define FLSTST_SUSPEND_RESUME_API         STD_OFF

/* TRACE [R4, FlsTst065] */
/* TRACE [R4, FlsTst099_Conf] */
/* Enable/Disable the FlsTst_TestEcc API */
#define FLSTST_TEST_ECC_API               STD_ON

/* TRACE [R4, FlsTst046] */
/* TRACE [R4, FlsTst095_Conf] */
/* Enable/Disable the FlsTst_GetVersionInfo API */
#define FLSTST_VERSION_INFO_API           STD_OFF

/* TRACE [R4, FlsTst120_Conf] */
/* Number of cells to be tested in background mode without checking user
 * requests */
#define FLSTST_NUMBER_OF_TESTED_CELLS_ATOMIC (uint32)0x00000001uL

/* TRACE [R4, FlsTst158_Conf] */
/* Defines the end value of the Test Interval Id */
#define FLSTST_TEST_INTERVAL_ID_END_VALUE (uint32)0x00000001uL

/* TRACE [R4, FlsTst171_Conf] */
/* The failure of FlsTst to write-protected register is reported to DEM */
#define FLSTST_E_FLSTST_FAILURE           \
  DemConf_DemEventParameter_AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE

/* TRACE [R4, EAAR_PN0034_FSR_0003 ] */
/* The failure of FlsTst while register check for default values 
 * is reported to DEM */
#define FLSTST_E_ECC_FAILED               \
  DemConf_DemEventParameter_AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED

/* CRC input register for Background */
#define FLSTST_DCRACINBGND                (*((volatile uint32 *)(0xfff70000uL)))

/* CRC data register for Background */
#define FLSTST_DCRACOUTBGND               (*((volatile uint32 *)(0xfff70004uL)))

/* CRC control register for Background */
#define FLSTST_DCRACTLBGND                (*((volatile uint8 *)(0xfff70020uL)))

/* CRC input register for Foreground */
#define FLSTST_DCRACINFGND                (*((volatile uint32 *)(0xfff71000uL)))

/* CRC data register for Foreground */
#define FLSTST_DCRACOUTFGND               (*((volatile uint32 *)(0xfff71004uL)))

/* CRC control register for Foreground */
#define FLSTST_DCRACTLFGND                (*((volatile uint8 *)(0xfff71020uL)))

/* Code flash 1st error address register */
#define FLSTST_CF1STEADR0_VCI             (*((volatile uint32 *)(0xffc62250uL)))

/* Code flash sub-test control register */
#define FLSTST_CFSTSTCTL_VCI              (*((volatile uint32 *)(0xffc62350uL)))

/* Macro to differentiate control values between the variants */
#define FLSTST_DEVICE_SPECIFIC            STD_OFF

/* ECC self test address */
#define FLSTST_ECC_SELF_TEST_ADDRESS      ((volatile uint32 *)0x01032000uL)


/* Code flash ECC control register */
#define FLSTST_CFECCCTL_VCIL              (*((volatile uint16 *)(0xffc62200uL)))

/* Code flash status clear register */
#define FLSTST_CFSTCLR_VCILL              (*((volatile uint8 *)(0xffc62208uL)))

/* Code flash error information control register */
#define FLSTST_CFERRINT_VCILL             (*((volatile uint8 *)(0xffc62204uL)))

/* Code flash 1st error status register */
#define FLSTST_CF1STERSTR_VCILL           (*((volatile uint8 *)(0xffc62210uL)))



/*******************************************************************************
**                             Handles                                        **
*******************************************************************************/

/* Configuration Set Handles */
#define FlsTstConfigSet  (&FlsTst_GstConfiguration[0])

/* Handles for FlsTst Block */


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* FLSTST_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
