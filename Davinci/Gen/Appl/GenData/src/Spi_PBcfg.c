/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_PBcfg.c                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2019 Renesas Electronics Corporation. All rights reserved.             */
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
/*              Devices:        R7F701651                                     */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:      12-Feb-2019:      Initial Version
 */

/*******************************************************************************
**                      Generation Tool Version                               **
*******************************************************************************/
/*                                                                            */
/* TOOL VERSION:  1.0.0                                                       */
/*                                                                            */

/*******************************************************************************
**                      Input File                                            **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5761450\Generation\Cfg_Gen-1599208913269-0\AutosarFiles_ValGen3763191865339178278\ExtGen_DrvSpi_ECUC_4.2.2_8046980392920154194.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\spi\generator\R422_SPI_F1x_BSWMDT.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\common_family\generator\Sample_Application_F1x.trxml
 * GENERATED ON:  04 9月 2020 - 06:37:12
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Spi.h" 
#include "Spi_PBTypes.h"
#include "Spi_Ram.h"
#include "Spi_CSIX_LLDriver.h"
#include "Spi_DMAC_LLDriver.h"


/*******************************************************************************
**                      QAC Warning                                           **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:0315) [I] Implicit conversion from a pointer to object  */
/*                  type to a pointer to void.                                */
/* Justification : A cast should not be performed between a pointer to object */
/*                 type and a different pointer to object type.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0315)-1 and                           */
/*                 END Msg(2:0315)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing .    */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The name of an include file has been specified using a     */
/*                 macro. This is not recommended in some coding standards.   */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-2 and                           */
/*                 END Msg(2:0832)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/*                 REFERENCE - ISO-6.3.4 Cast Operators                       */
/* Justification : For casting to 8-bit data buffer type (Spi_DataBufferType).*/
/*                 It is fixed as uint8 as per AUTOSAR SWS.                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0310)-1 and                           */
/*                 END Msg(2:0310)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:0488) Performing Pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This is to get the ID in the data structure in the code.   */
/* Verification  : However, part of code is verified manually and it is not   */
/*                 having any impact.                                         */
/* Reference     : Look for START Msg(2:0488)-2 and                           */
/*                 END Msg(2:0488)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0303)-3 and                           */
/*                 END Msg(2:0303)-3 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION            4U
#define SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION            2U
#define SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION         2U

/* File version information */
#define SPI_PBCFG_C_SW_MAJOR_VERSION                    1U
#define SPI_PBCFG_C_SW_MINOR_VERSION                    0U

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/


#if (SPI_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
         SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (SPI_PBTYPES_AR_RELEASE_MINOR_VERSION != \
         SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (SPI_PBTYPES_AR_RELEASE_REVISION_VERSION != \
         SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (SPI_PBTYPES_SW_MAJOR_VERSION != SPI_PBCFG_C_SW_MAJOR_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (SPI_PBTYPES_SW_MINOR_VERSION != SPI_PBCFG_C_SW_MINOR_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Software Minor Version"
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC warning: START Msg(2:0832)-3 */
#include  SPI_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/* This array map hardware unit CSIH to hardware unit info array */
static CONST(uint8, SPI_CONFIG_DATA) Spi_GaaCSIHToHWUnit0[] =
{
  /* Index: 0 */
  0x00U, 0x00U, 0x00U, 0x00U
};

/* This array map hardware unit CSIG to hardware unit info array */
/* static CONST(uint8, SPI_CONST) Spi_GaaCSIGToHWUnit{0}[]; */

/* Array for hardware unit information */
static CONST(Spi_HWUnitInfoType, SPI_CONFIG_DATA) Spi_GaaHWUnitInfo0[] =
{
  /* Index: 0 - CSIH3 */
  {
    /* enMacroType */
    SPI_MACRO_CSIH,

    /* ucPhysicalIndex */
    0x03U,

    /* enMemoryModeType */
    SPI_MEMMODE_FIFO,

    /* blSynchronous */
    SPI_FALSE,

    /* ucCTL0DefaultValue */
    (uint8)(SPI_CSIX_TXE | SPI_CSIX_RXE),

    /* usSTCR0MaskValue */
    (uint16)(SPI_CSIX_DCEC | SPI_CSIX_PEC | SPI_CSIX_OVEC
    | SPI_CSIH_OFEC | SPI_CSIH_PCT)
  }
};

/* This array map DMA hardware unit to hardware unit info array */
/* static CONST(uint8, SPI_CONST) Spi_GaaDMAToHWUnit0[]; */

/* This array contains list JobIds in sequence */
static CONST(Spi_JobType, SPI_CONFIG_DATA) Spi_GaaJobList000[] =
{
  /* Index: 0 */
  0x00U
};

/* This array contains list ChannelIds in job */
static CONST(Spi_ChannelType, SPI_CONFIG_DATA) Spi_GaaChannelList00[] =
{
  /* Index: 0 */
  0x00U
};

/* This array contains list Chip select index in job */
static CONST(uint8, SPI_CONFIG_DATA) Spi_GaaCSArray00[] =
{
  /* Index: 0 */
  0x00U
};

/* This array contains configuration details for Channels */
static CONST(Spi_ChannelConfigType, SPI_CONFIG_DATA) Spi_GaaChannelConfig0[] =
{
  /* Index: 0 - CSIH3 */
  {
    /* ucDataWidth */
    0x08U,

    /* ucByteSize */
    0x01U,

    /* ulDefaultData */
    0x00000000UL,

    /* enChannelBufferType */
    SPI_BUFFER_TYPE_EB,

    /* usNoOfBuffers */
    0x0100U,

    /* pTxBuffer */
    NULL_PTR,

    /* pRxBuffer */
    NULL_PTR,

    /* pEBData */
    &Spi_GaaEBData[0],

    /* ulCSIXCFG */
    SPI_CSIX_DIRM | SPI_CSIX_DLS(8),

    /* ulFirstJobIndex */
    0x00000000UL
  }
};

/* This array contains configuration details for Jobs */
static CONST(Spi_JobConfigType, SPI_CONFIG_DATA) Spi_GaaJobConfig0[] =
{
  /* Index: 0 - SpiJob1 */
  {
    /* ucNoOfChannels */
    0x01U,

    /* pChannelList */
    &Spi_GaaChannelList00[0],

    /* pJobEndNotification */
    &SpiJob0Notification,

    /* ucHWUnitIndex */
    0x00U,

    /* enCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucNoOfCS */
    0x01U,

    /* pCSArray */
    &Spi_GaaCSArray00[0],

    /* ucCSIHCSInfo */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blChannelPropertySame */
    SPI_TRUE,

    /* ulCSIXCTL1 */
    0x00000010UL,

    /* usCSIXCTL2 */
    SPI_CSIX_PRS_DIV_4,

    /* usCSIXBRS */
    SPI_CSIX_BRS(1),

    /* ulCSIXCFG */
    SPI_CSIX_PS_NONE | SPI_CSIH_BRSS(0)
    | SPI_CSIH_ID_1_5 | SPI_CSIH_HD_0_5
    | SPI_CSIH_IN_0_5 | SPI_CSIH_SP_0_5,

    /* usCSIHMCTL0 */
    0x0000U
  }
};

/* This array contains configuration details for Sequences */
static CONST(Spi_SeqConfigType, SPI_CONFIG_DATA) Spi_GaaSeqConfig0[] =
{
  /* Index: 0 - SpiSequence */
  {
    /* ulUsingHWUnits */
    0x00000001UL,

    /* pSeqEndNotification */
    &SpiSequenceEndNotification,

    /* blSynchronous */
    SPI_FALSE,

    /* blInterruptible */
    SPI_TRUE,

    /* aaJobSharedSequences */
    {
      0x00000000UL
    },
    /* aaSubSeqs */
    {
      /* ASYNCHRONOUS_FIFO_MODE */
      {
        /* ucUsingPriorities */
        0x08U,
        /* usNoOfJobs */
        0x01U,
        /* pJobList */
        &Spi_GaaJobList000[0]
      }
    }
  }
};

/* Pointer to the structure of DMA configuration array */
/* static CONST(Spi_DmaConfigType, SPI_CONFIG_DATA) Spi_GaaDmaConfig0[]; */

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC warning: START Msg(2:0832)-3 */
#include  SPI_MEMMAP_FILE
/* END Msg(2:0832)-3 */

#define SPI_START_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC warning: START Msg(2:0832)-3 */
#include  SPI_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/* Structure for SPI Init configuration */
CONST(Spi_ConfigType, SPI_CONFIG_DATA) Spi_GaaConfiguration[] =
{
  /* Index:0 - SpiDriver0 */
  {
    /* ulStartOfDbToc */
    0x0ED4C100UL,

    /* ucNoOfHWUnits */
    0x01U,

    /* ucNoOfChannels */
    0x01U,

    /* usNoOfJobs */
    0x0001U,

    /* ucNoOfSequences */
    0x01U,

    /* pHWUnitInfo */
    /* QAC warning: START Msg(2:0315)-1 */
    &Spi_GaaHWUnitInfo0[0],
    /* END Msg(2:0315)-1 */

    /* pChannelConfig */
    /* QAC warning: START Msg(2:0315)-1 */
    &Spi_GaaChannelConfig0[0],
    /* END Msg(2:0315)-1 */

    /* pJobConfig */
    /* QAC warning: START Msg(2:0315)-1 */
    &Spi_GaaJobConfig0[0],
    /* END Msg(2:0315)-1 */

    /* pSequenceConfig */
    /* QAC warning: START Msg(2:0315)-1 */
    &Spi_GaaSeqConfig0[0],
    /* END Msg(2:0315)-1 */

    /* ulTimeOutCount */
    0x2FAF0800UL,

    /* pCSIHToHWUnit */
    &Spi_GaaCSIHToHWUnit0[0]
  }
};

#define SPI_STOP_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC warning: START Msg(2:0832)-3 */
#include  SPI_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

