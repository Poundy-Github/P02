/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Hardware.c                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018   Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file shall contain the structure pointer for accessing the hardware   */
/* registers belongs the WDG module                                           */
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
 *                         As part of ARDAABD-2466:
 *                         ->Iocommon_Defines.h added instead of Iocommon.h
 *                         2. As part of ARDAABD-2734:
 *                         MEMMAP_FILE macro is replaced as WDG_MEMMAP_FILE
 * V2.0.4:  05-Dec-2017  : Following changes are made:
 *                         1. As part of ARDAABD-2158:
 *                         Replaced the GpIMR_BaseAddr and INTWDTIMR_MASK
 *                         macro with GpICR_BaseAddr and INTWDTICR_MASK.
 *                         2. As part of ARDAABD-908: Memory Section is renamed.
 * V2.0.4:  12-Apr-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3474
 *                         a. Replaced the GpIMR_BaseAddr and INTWDTIMR_MASK
 *                         macro with GpICR_BaseAddr and INTWDTICR_MASK,
 *                         Ref:ARDAABD-2158.
 *                         b. Memory Section is renamed,Ref:ARDAABD-908.
 */
/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.4
 */
/*******************************************************************************
**                      Input File                                            **
*******************************************************************************/
 /*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-9646980\Generation\Cfg_Gen-1600914080070-0\AutosarFiles_ValGen4152929950734771046\ExtGen_DrvWdgA_ECUC_4.2.2_3359228386246730523.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\wdg\generator\R422_WDG_F1x_BSWMDT.arxml
 * GENERATED ON:  24 Sep 2020 - 13:21:07
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Wdg_59_DriverA_Hardware.h"
#include "Iocommon_Defines.h"
#include "Wdg_59_DriverA_PBTypes.h"
/*******************************************************************************
**                     Version Information                                    **
*******************************************************************************/

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_HARDWARE_C_AR_RELEASE_MAJOR_VERSION  4U
#define WDG_59_DRIVERA_HARDWARE_C_AR_RELEASE_MINOR_VERSION  2U
#define WDG_59_DRIVERA_HARDWARE_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define WDG_59_DRIVERA_WDG_HARDWARE_C_SW_MAJOR_VERSION  1U
#define WDG_59_DRIVERA_WDG_HARDWARE_C_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
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
/* Message       : (4:3408) Has external linkage and is being defined without */
/*                 any previous declaration.                                  */
/* Rule          : MISRA-C:2004 Rule 8.8                                      */
/* Justification : This sub structure is accessed as a member in main         */
/*                 structure and hence declaration is not required.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3408)-2 and                           */
/*                 END Msg(4:3408)-2 tags in the code.                        */
/******************************************************************************/
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : This is to get the value to pointer.                       */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0310)-3 and                           */
/*                 END Msg(4:0310)-3 tags in the code.                        */

/******************************************************************************/
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include WDG_MEMMAP_FILE
/* MISRA Violation: START Msg(4:0303)-1 */
/* Structure pointer for WDTAreg */
volatile WDTAReg* const  WDG_59_DriverA_GpWDTAReg_BaseAddr =
                  (volatile  WDTAReg *) &WDTA0  ;
/*Structure pointer for INTWDT ICR*/
/* MISRA Violation: START Msg(4:0310)-3 */

volatile  unsigned long* const WDG_59_DriverA_GpICR_BaseAddr =
                  (volatile  unsigned long*) &ICWDTA0  ;
/* END Msg(4:0310)-3 */
/*Structure pointer for WUF0 */

/*Structure pointer for WUFREG20 */
/* MISRA Violation: START Msg(4:3408)-2 */

/* END Msg(4:3408)-2 */
/* END Msg(4:0303)-1 */
#define WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include WDG_MEMMAP_FILE


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
