/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Lcfg.c                                                  */
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
#include "Spi_LTTypes.h"
#include "Spi_CSIX_LLDriver.h"


/*******************************************************************************
**                      QAC Warning                                           **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:3132) Hard coded 'magic' number, '%s', used to define   */
/*                  the size of an array.                                     */
/* Justification : The hard coded is defined by configuration files.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3132)-1 and                           */
/*                 END Msg(2:3132)-1 tags in the code.                        */
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
/* Message       : (4:3408) Has external linkage and is being defined         */
/*                 without any previous declaration.                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Since number or names of symbols in this file              */
/*                 is according to a configuration,                           */
/*                 this can't be declared in a header file statically.        */
/* Verification  : This symbol is referred by an auto-generated file only.    */
/*                 It is verified by the evaluation of the Generation Tool.   */
/* Reference     : Look for START Msg(4:3408)-2 and                           */
/*                 END Msg(4:3408)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* File version information */
#define SPI_LCFG_C_AR_RELEASE_MAJOR_VERSION             4U
#define SPI_LCFG_C_AR_RELEASE_MINOR_VERSION             2U
#define SPI_LCFG_C_AR_RELEASE_REVISION_VERSION          2U

/* AUTOSAR specification version information */
#define SPI_LCFG_C_SW_MAJOR_VERSION                     1U
#define SPI_LCFG_C_SW_MINOR_VERSION                     0U

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/


#if (SPI_LTTYPES_AR_RELEASE_MAJOR_VERSION != \
         SPI_LCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Release Major Version"
#endif

#if (SPI_LTTYPES_AR_RELEASE_MINOR_VERSION != \
         SPI_LCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Release Minor Version"
#endif

#if (SPI_LTTYPES_AR_RELEASE_REVISION_VERSION != \
         SPI_LCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Release Revision Version"
#endif

#if (SPI_LTTYPES_SW_MAJOR_VERSION != SPI_LCFG_C_SW_MAJOR_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Software Major Version"
#endif

#if (SPI_LTTYPES_SW_MINOR_VERSION != SPI_LCFG_C_SW_MINOR_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Software Minor Version"
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define SPI_START_SEC_CONST_UNSPECIFIED
/* QAC warning: START Msg(2:0832)-2 */
#include  SPI_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/* CSIX Register set information */
CONST(Spi_CSIXRegisterSetType, SPI_CONFIG_DATA) Spi_GaaCSIXRegs[] =
{
  /* Index: 0 - CSIH0 */
  {
    /* pCSIXCTLRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIXCTLRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD80000UL,
    /* END Msg(4:0303)-1 */

    /* pCSIXSTRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIXSTRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD80004UL,
    /* END Msg(4:0303)-1 */

    /* pCSIHRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIHRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD81000UL,
    /* END Msg(4:0303)-1 */

    /* pICTIC */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, SPI_CONFIG_DATA, REGSPACE))0xFFFEEA3AUL,
    /* END Msg(4:0303)-1 */

    /* pICTIR */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, SPI_CONFIG_DATA, REGSPACE))0xFFFEEA3CUL
    /* END Msg(4:0303)-1 */
  },

  /* Index: 1 - CSIH1 */
  {
    /* pCSIXCTLRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIXCTLRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD82000UL,
    /* END Msg(4:0303)-1 */

    /* pCSIXSTRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIXSTRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD82004UL,
    /* END Msg(4:0303)-1 */

    /* pCSIHRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIHRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD83000UL,
    /* END Msg(4:0303)-1 */

    /* pICTIC */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, SPI_CONFIG_DATA, REGSPACE))0xFFFFB0E8UL,
    /* END Msg(4:0303)-1 */

    /* pICTIR */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, SPI_CONFIG_DATA, REGSPACE))0xFFFFB0EAUL
    /* END Msg(4:0303)-1 */
  },

  /* Index: 2 - CSIH2 */
  {
    /* pCSIXCTLRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIXCTLRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD84000UL,
    /* END Msg(4:0303)-1 */

    /* pCSIXSTRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIXSTRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD84004UL,
    /* END Msg(4:0303)-1 */

    /* pCSIHRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIHRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD85000UL,
    /* END Msg(4:0303)-1 */

    /* pICTIC */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, SPI_CONFIG_DATA, REGSPACE))0xFFFFB108UL,
    /* END Msg(4:0303)-1 */

    /* pICTIR */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, SPI_CONFIG_DATA, REGSPACE))0xFFFFB10AUL
    /* END Msg(4:0303)-1 */
  },

  /* Index: 3 - CSIH3 */
  {
    /* pCSIXCTLRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIXCTLRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD86000UL,
    /* END Msg(4:0303)-1 */

    /* pCSIXSTRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIXSTRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD86004UL,
    /* END Msg(4:0303)-1 */

    /* pCSIHRegs */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile Spi_CSIHRegType, SPI_CONFIG_DATA, REGSPACE))0xFFD87000UL,
    /* END Msg(4:0303)-1 */

    /* pICTIC */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, SPI_CONFIG_DATA, REGSPACE))0xFFFFB13CUL,
    /* END Msg(4:0303)-1 */

    /* pICTIR */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(volatile uint16, SPI_CONFIG_DATA, REGSPACE))0xFFFFB13EUL
    /* END Msg(4:0303)-1 */
  }
};

#define SPI_STOP_SEC_CONST_UNSPECIFIED
/* QAC warning: START Msg(2:0832)-2 */
#include  SPI_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

