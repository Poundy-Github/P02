/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Cfg.h                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018   Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V2.0.0:  26-Oct-2016  : ASR 4.2.2 Release - Jira Ticket #ARDAABD-493
 * V2.0.1:  14-Dec-2016  : Driver C removed
 * V2.0.2:  17-Jan-2017  : E_DISABLE_REJECTED/E_MODE_FAILED_REPORTING
 * V2.0.3:  17-Jun-2017  : Updated copyright information.
 * V2.0.4:  16-Nov-2017  : As part of ARDAABD-2734:
 *                         MEMMAP_FILE macro is replaced as WDG_MEMMAP_FILE
 * V2.0.5:  12-Apr-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3474
 *                         Replaced the GpIMR_BaseAddr and INTWDTIMR_MASK
 *                         macro with GpICR_BaseAddr and INTWDTICR_MASK,
 *                         Ref:ARDAABD-2158.
 */
/******************************************************************************/
/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.4
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-9646980\Generation\Cfg_Gen-1600914080070-0\AutosarFiles_ValGen4152929950734771046\ExtGen_DrvWdgA_ECUC_4.2.2_3359228386246730523.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\wdg\generator\R422_WDG_F1x_BSWMDT.arxml
 * GENERATED ON:  24 Sep 2020 - 13:21:07
 */

#ifndef WDG_59_DRIVERA_CFG_H
#define WDG_59_DRIVERA_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_CFG_AR_RELEASE_MAJOR_VERSION        4U
#define WDG_59_DRIVERA_CFG_AR_RELEASE_MINOR_VERSION        2U
#define WDG_59_DRIVERA_CFG_AR_RELEASE_REVISION_VERSION     2U


/* File version information */
#define WDG_59_DRIVERA_CFG_SW_MAJOR_VERSION  1U
#define WDG_59_DRIVERA_CFG_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE      4U
#define WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE      2U
#define WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE   2U

#define WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE              1U
#define WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE              0U
#define WDG_59_DRIVERA_SW_PATCH_VERSION_VALUE              7U

#define WDG_59_DRIVERA_VENDOR_ID_VALUE                     59U
#define WDG_59_DRIVERA_MODULE_ID_VALUE                     102U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#if((WDG_59_DRIVERA_CFG_AR_RELEASE_MAJOR_VERSION == 4U) && \
   (WDG_59_DRIVERA_CFG_AR_RELEASE_MINOR_VERSION== 2U )  && \
   (WDG_59_DRIVERA_CFG_AR_RELEASE_REVISION_VERSION == 2U ) )
#define WDG_MEMMAP_FILE "Wdg_MemMap.h"
#else
#define WDG_MEMMAP_FILE "MemMap.h"
#endif

/* Pre-compile option for Version information */
#define WDG_59_DRIVERA_AR_VERSION                          \
 WDG_59_DRIVERA_AR_HIGHER_VERSION

/* TRACE [R4, WDG115_Conf] */
/* TRACE [R4, WDG045] */
/* TRACE [R4, WDG064] */
/* TRACE [R4, WDG066] */
/* Pre-compile option for development error detect. */
#define WDG_59_DRIVERA_DEV_ERROR_DETECT                    STD_OFF

/* TRACE [R4, WDG131_Conf] */
/* Maximum timeout in msec to which the watchdog trigger condition can
   be initialized. */
#define WDG_59_DRIVERA_MAXIMUM_TIMEOUT                     (uint16)5000

/* TRACE [R4, WDG130_Conf] */
/* Initial timeout in msec for the trigger condition to be initialized
   during Init or set mode function. */
#define WDG_59_DRIVERA_INITIAL_TIMEOUT                     (uint16)5000

/* Represents the watchdog driver execution area is either from
   ROM(Flash) or RAM as required with the particular microcontroller. */
#define WDG_59_DRIVERA_RUN_AREA                            WDG_59_DRIVERA_ROM

/* TRACE [R4, WDG109] */
/* Pre-compile option for version info API. */
#define WDG_59_DRIVERA_VERSION_INFO_API                    STD_OFF

/* Compile switch to allow/forbid VAC. */
#define WDG_59_DRIVERA_VAC_ALLOWED                         STD_OFF

/* Pre-compile option for error mode switching */
#define WDG_59_DRIVERA_ERR_MODE_SET                        \
 WDG_59_DRIVERA_RESET_MODE

/* Pre-compile option for enable or disable inter-module dependencies. */
#define WDG_59_DRIVERA_VER_CHECK_EXT                       STD_OFF

/* Pre-compile option for critical section protection */
#define WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION         STD_ON

/* Watchdog Driver Id */
#define WDG_59_DRIVERA_INDEX                               (uint8)0

/* Enable/disable the register RAM mirroring functionality */
#define WDG_59_DRIVERA_RAM_MIRROR                          \
 WDG_59_DRIVERA_MIRROR_DISABLE

/* Enable/disable Write Verify functionality */
#define WDG_59_DRIVERA_WRITE_VERIFY                        \
 WDG_59_DRIVERA_WV_DISABLE

/* Enables/Disables WDG ERROR Notification */
#define WDG_59_DRIVERA_USE_WRITE_ERROR_INTERFACE           STD_OFF

/* Enable/disable the WAKEUP_FACTOR_CLEAR_ISR value */
#define WDG_59_DRIVERA_WAKEUP_FACTOR_CLEAR_ISR             STD_OFF


/* Compiler switch used for reporting disable reject */
#define WDG_59_DRIVERB_E_DISABLE_REJECTED_REPORTING        STD_OFF 

/* Compiler switch used for reporting mode failed */
#define WDG_59_DRIVERB_E_MODE_FAILED_REPORTING             STD_OFF 

/* Compiler switch used for reporting disable reject */
#define WDG_59_DRIVERC_E_DISABLE_REJECTED_REPORTING        STD_OFF 

/* Compiler switch used for reporting mode failed */
#define WDG_59_DRIVERC_E_MODE_FAILED_REPORTING             STD_OFF 


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Instance ID of the WDG Component */
#define WDG_59_DRIVERA_INSTANCE_ID_VALUE                   \
 0U

/* TRACE [R4, WDG127_Conf] */
/* Watchdog trigger mode */
#define WDG_59_DRIVERA_TRIGGER_MODE                        \
 WDG_59_DRIVERA_WINDOW

/* Configuration Set Handles */
#define WdgSettingsConfig                                  \
 (&Wdg_59_DriverA_GstConfiguration)


/* INTWDT Interrupt enable ICR mask */
#define WDG_59_DRIVERA_INTWDTICR_MASK                      \
 0xFF7FU

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* WDG_59_DRIVERA_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
