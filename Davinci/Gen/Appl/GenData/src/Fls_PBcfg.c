/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_PBcfg.c                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
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
 * V1.0.0:  05-Oct-2015 : Initial Version
 *
 * V1.0.1:  03-Dec-2015 : The following changes were made:
 *                        1. Removed the parameter ulFlsSlowModeMaxWriteBytes
 *                           from Fls_GstConfiguration structure.
 *
 * V2.0.0:  14-Nov-2016 : 1. Added WV and Ram mirror parameters
 *                        2. #ARDAABD-731: Defined Fls_GstDmaUnitConfig array
 *                        3. #ARDAABD-929: Structure's Fls_ConfigType field
 *                           pFlEndImrAddress type changed to TYPEDEF
 * V2.0.1:  24-Aug-2017 : ARDAABD-2151 - Added QAC/MISRA Warning justifications
 * V2.0.2:  19-Sep-2017 : ARDAABD-2160
 *                        1. Iocommon split
 *
 * V2.0.3:  13-Apr-2018 : 1. As part of merging activity, #ARDAABD-3465
 *                           following changes are made:
 *                           Ref : ARDAABD-908,
 *                        a. FLS_START_SEC_BUFFER_CODE has been
 *                           changed to FLS_START_SEC_VAR_NO_INIT_32
 *                           and FLS_STOP_SEC_BUFFER_CODE has been changed to
 *                           FLS_STOP_SEC_VAR_NO_INIT_32.
 *                        b. FLS_START_SEC_DBTOC_DATA_UNSPECIFIED
 *                           has been changed to
 *                           FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
 *                           and FLS_STOP_SEC_DBTOC_DATA_UNSPECIFIED has been
 *                           changed to FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED.
 *                           Ref : ARDAABD-2158,
 *                        a. Removed fields pFlEndImrAddress and
 *                           usFlEndImrMask from the structure
 *                           Fls_GstConfiguration.
 *                        b. Removed fields pDmaImrIntCntlReg and
 *                           usDmaImrMask from the structure
 *                           Fls_GstDmaUnitConfig.
 *                        c. Copyright information is updated.
 */
/******************************************************************************/
/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    2.0.4
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-6874790\Generation\Cfg_Gen-1606880170386-0\AutosarFiles_ValGen5137770938767767548\ExtGen_DrvFls_ECUC_4.2.2_8247066206533904749.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\fls\generator\R422_FLS_F1x_BSWMDT.arxml
 * GENERATED ON:   2 Dec 2020 - 13:03:23
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Iocommon_Defines.h"
#include "Fls.h"
#include "Fls_PBTypes.h"
#include "Fls_Cbk.h"

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

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3635) Function identifier used as a pointer without     */
/*                  a preceding & operator                                    */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Function pointer is used as pointer without a preceding &  */
/*                 operator since this function will be invoked during        */
/*                 notification                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3635)-2 and                           */
/*                 END Msg(4:3635)-2 tags in the code.                        */

/******************************************************************************/
/* 3.  MISRA C RULE VIOLATION:                                                */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-3 and                           */
/*                 END Msg(2:0832)-3 tags in the code.                        */

/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message      : (2:3211) The global identifier '' is defined                */
/*                here but is not used in this translation unit.              */
/* Rule         : MISRA-C:2004 Message 3211                                   */
/* Justification: Global identifiers extern declaration                       */
/*                shall be given in driver .h (Fls.h and Fls_PBTypes.h) files.*/
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:3211)-4 and                            */
/*                END Msg(2:3211)-4 tags in the code.                         */

/******************************************************************************/
/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:3674) Array size defined implicitly by the number of    */
/*                 initializers.                                              */
/* Rule          : MISRA-C:2004 Message 3674                                  */
/* Justification : Array size vary in different configurations.               */
/*                 So giving fixed array size is not possible.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3674)-5 and                           */
/*                 END Msg(2:3674)-5 tags in the code.                        */

/******************************************************************************/
/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message      : (2:2022) This is a tentative definition and according to    */
/*                the ISO:C Standard, the object will automatically be        */
/*                initialized to zero.                                        */
/* Rule         : MISRA-C:2004 Message 2022                                   */
/* Justification: The object's initialisation to zero will not affect the     */
/*                functionality.                                              */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:2022)-6 and                            */
/*                END Msg(2:2022)-6 tags in the code.                         */

/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:3132) Hard coded 'magic' number, '', used to define the */
/*                 size of an array.                                          */
/* Rule          : MISRA-C:2004 Message 3132                                  */
/* Justification : Hard coded Numbers are added instead of macros for better  */
/*                 readability.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3132)-7 and                           */
/*                 END Msg(2:3132)-7 tags in the code.                        */

/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0312) Dangerous pointer cast results in loss of         */
/*                  volatile qualification.                                   */
/* Rule          : MISRA-C:2004 Rule 11.5                                     */
/* Justification : This is to access the SELB_TAUD0I Register.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0312)-8 and                           */
/*                 END Msg(4:0312)-8 tags in the code.                        */
/******************************************************************************/

/* 9.  MISRA C RULE VIOLATION:                                                */
/* Message       : (2:0862) This #include '' directive is redundant.          */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Each header has implemented safety for multiple inclusion. */
/*                 Header will not be included multiple times.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-9 and                           */
/*                 END Msg(2:0862)-9 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define FLS_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define FLS_PBCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define FLS_PBCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define FLS_PBCFG_C_SW_MAJOR_VERSION  1U
#define FLS_PBCFG_C_SW_MINOR_VERSION  1U

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (FLS_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
      FLS_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
 #error "Fls_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (FLS_PBTYPES_AR_RELEASE_MINOR_VERSION != \
      FLS_PBCFG_C_AR_RELEASE_MINOR_VERSION)
 #error "Fls_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (FLS_PBTYPES_AR_RELEASE_REVISION_VERSION != \
      FLS_PBCFG_C_AR_RELEASE_REVISION_VERSION)
 #error "Fls_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (FLS_PBTYPES_SW_MAJOR_VERSION != FLS_PBCFG_C_SW_MAJOR_VERSION)
  #error "Fls_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (FLS_PBTYPES_SW_MINOR_VERSION != FLS_PBCFG_C_SW_MINOR_VERSION)
  #error "Fls_PBcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* MISRA Violation: START Msg(2:0862)-9 */
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
/* MISRA Violation: START Msg(2:0832)-3 */
#include FLS_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/* MISRA Violation: START Msg(2:3211)-4 */
/* MISRA Violation: START Msg(2:3674)-5 */
/* Structure for each Config Set */
CONST(Fls_ConfigType, FLS_CONST) Fls_GstConfiguration[] =
{
  /* Index: 0 - FlsConfigSet */
  {
    /* ulStartOfDbToc */
    0x0ED70108UL,

    /* pJobEndNotificationPointer */
    /* MISRA Violation: START Msg(4:3635)-2 */
    NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* pJobErrorNotificationPointer */
    /* MISRA Violation: START Msg(4:3635)-2 */
    NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* pEccSEDNotificationPointer */
    /* MISRA Violation: START Msg(4:3635)-2 */
    NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* pEccDEDNotificationPointer */
    /* MISRA Violation: START Msg(4:3635)-2 */
    NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ulFlsSlowModeMaxReadBytes */
    0x00000004UL,

    /* ulFlsFastModeMaxReadBytes */
    0x00000004UL,

    /* ddDefaultMode */
    MEMIF_MODE_SLOW,

    /* pDmaUnitConfig */
    NULL_PTR
  }
};


/* END Msg(2:3211)-4 */

/* Structure for DMA channel configuration */
/* CONST(Fls_DmaUnitConfig, FLS_CONST) Fls_GstDmaUnitConfig[]; */
/* END Msg(2:3674)-5 */
/* FCU Descriptor Structure*/
/* CONST(Fcu_DescriptorType, FLS_CONST) Fcu_Config[]; */

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* MISRA Violation: START Msg(2:0832)-3 */
#include FLS_MEMMAP_FILE
/* END Msg(2:0832)-3 */

#define FLS_START_SEC_VAR_NO_INIT_32
/* MISRA Violation: START Msg(2:0832)-3 */
#include FLS_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/* MISRA Violation: START Msg(2:2022)-6 */
/* MISRA Violation: START Msg(2:3211)-4 */
/* MISRA Violation: START Msg(2:3132)-7 */
/* Global array with max buffer size */
 VAR(uint32, AUTOMATIC) Fls_GulTempBuffer[1];
/* END Msg(2:2022)-6 */
/* END Msg(2:3211)-4 */
/* END Msg(2:3132)-7 */
#define FLS_STOP_SEC_VAR_NO_INIT_32
/* MISRA Violation: START Msg(2:0832)-3 */
#include FLS_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* END Msg(2:0862)-9 */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
