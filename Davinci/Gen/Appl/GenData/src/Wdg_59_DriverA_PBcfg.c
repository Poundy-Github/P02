/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_PBcfg.c                                      */
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
 * V1.0.0:  03-Sep-2015  : Initial Version
 * V2.0.0:  26-Oct-2016  : ASR 4.2.2 Release - Jira Ticket #ARDAABD-493
 * V2.0.1:  14-Dec-2016  : Driver C removed
 * V2.0.2:  17-Jun-2017  : Updated copyright information.
 * V2.0.3:  16-Nov-2017  : Following changes are made:
 *                         1. As part of ARDAABD-2266:
 *                         -> WDG_59_DriverA_WDTAReg_BaseAddr is renamed to
 *                         WDG_59_DriverA_GpWDTAReg_BaseAddr(Global Pointer)
 *                         -> WDG_59_DriverA_IMR_BaseAddr is renamed to
 *                         WDG_59_DriverA_GpIMR_BaseAddr(Global Pointer)
 *                         -> WDG_59_DriverA_WUFRG0_BasAddr is renamed to
 *                         WDG_59_DriverA_GpWUFReg_BaseAddr(Global Pointer)
 *                         -> WDG_59_DriverA_WUFRG20_BasAddr is renamed to
 *                         WDG_59_DriverA_GpWUFReg20_BaseAddr(Global Pointer)
 *                         2. As part of ARDAABD-2734:
 *                         MEMMAP_FILE macro is replaced as WDG_MEMMAP_FILE
 * V2.0.4:  12-Apr-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3474
 *                         a. Memory Section is renamed,Ref:ARDAABD-908.
 *
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Wdg_59_DriverA_PBTypes.h"

/*******************************************************************************
**                     Version Information                                    **
*******************************************************************************/

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define WDG_59_DRIVERA_PBCFG_C_SW_MAJOR_VERSION  1U
#define WDG_59_DRIVERA_PBCFG_C_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (WDG_59_DRIVERA_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
                        WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_PBTYPES_AR_RELEASE_MINOR_VERSION != \
                        WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_PBTYPES_AR_RELEASE_REVISION_VERSION != \
                       WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (WDG_59_DRIVERA_PBTYPES_SW_MAJOR_VERSION != \
                        WDG_59_DRIVERA_PBCFG_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_PBTYPES_SW_MINOR_VERSION != \
                        WDG_59_DRIVERA_PBCFG_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include WDG_MEMMAP_FILE

/* Structure for Watchdog Driver Init configuration */
CONST(Wdg_59_DriverA_ConfigType,WDG_59_DRIVERA_CONFIG_CONST)
Wdg_59_DriverA_GstConfiguration =
{
  /* ulStartOfDbToc */
  0x0ED98100UL,

  /* usInitTimerCountValue */
  0x000CU,

  /* usSlowTimeValue */
  0x6666U,

  /* usFastTimeValue */
  0x0199U,

  /* ucWdtamdSlowValue */
  0x7FU,

  /* ucWdtamdFastValue */
  0x1FU,

  /* ucWdtamdDefaultValue */
  0x1FU,

  /* ddWdtamdDefaultMode */
  WDGIF_FAST_MODE
};

#define WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include WDG_MEMMAP_FILE


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
