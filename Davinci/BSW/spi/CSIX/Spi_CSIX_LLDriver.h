/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_CSIX_LLDriver.h                                         */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Nov-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions for link time parameters, CSIX     */
/* macros and internal function declarations for upper layers in SPI Driver.  */
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
 * V1.0.0:  12-Mar-2019  : Initial Version
 *          12-Nov-2019  : The following changes are made:
 *                         1. As per ARDAACH-147, macro for Bit8 of CSIXnSTR0
 *                         is removed and macro for Bit8 of CSIXnSTCR0 is
 *                         renamed to SPI_CSIH_PCT.
 *                         2. As per ARDAACH-140, add macros for performing
 *                         ECC code (7 bits) walk-1 test.
 *                         3. As per ARDAACH-156, change macro value for CFGx
 *                         to verify parity error in Spi_CSIXLoopbackSelfTest.
 */
/******************************************************************************/
#ifndef SPI_CSIX_LLDRIVER_H
#define SPI_CSIX_LLDRIVER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi_LTTypes.h"
#include "Spi_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_CSIX_LLDRIVER_AR_RELEASE_MAJOR_VERSION SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_CSIX_LLDRIVER_AR_RELEASE_MINOR_VERSION SPI_AR_RELEASE_MINOR_VERSION
#define SPI_CSIX_LLDRIVER_AR_RELEASE_REVISION_VERSION \
                                               SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_CSIX_LLDRIVER_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION
#define SPI_CSIX_LLDRIVER_SW_MINOR_VERSION SPI_SW_MINOR_VERSION

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/* Justification : Function can't be used in initializing expressions of      */
/*                 const value, or macro is better in point of performance.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-1 and                           */
/*                 END Msg(4:3453)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-2 and                           */
/*                 END Msg(4:3684)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) [L] Number of macro definitions exceeds 1024 -    */
/*                  program does not conform strictly to ISO:C90.             */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-3 and                           */
/*                 END Msg(4:0857)-3 tags in the code.                        */
/******************************************************************************/

/******************************************************************************/
/**                      QAC Warning                                         **/
/******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                  directive.                                                */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The name of an include file has been specified using a     */
/*                 macro. This is not recommended in some coding standards.   */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:3132) Hard coded 'magic' number, 'n', used to define    */
/*                 the size of an array.                                      */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3132           */
/* Justification : These numbers are used to define register structures.      */
/*                 These completely depend on H/W and it is impossible to     */
/*                 define particular symbolic names.                          */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3132)-2 and                           */
/*                 END Msg(2:3132)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Maximum bit length of single transmit for CSIX */
#define SPI_CSIX_WORD            16U

/* Hardware unit bits mask */
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIX_BITS_MASK       0xFFFFFFFFUL
/* END Msg(4:0857)-3 */

/* CSIXnCTL0 */
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIX_CTL0_DEFAULT    (uint8)0x00U
/* END Msg(4:0857)-3 */
#define SPI_CSIX_PWR             (uint8)0x80U
#define SPI_CSIX_TXE             (uint8)0x40U
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIX_RXE             (uint8)0x20U
/* END Msg(4:0857)-3 */
#define SPI_CSIX_MBS             (uint8)0x01U

/* CSIXnCTL1 */
#define SPI_CSIX_CTL1_DEFAULT    0x00000000UL
#define SPI_CSIH_SLRS            0x01000000UL
#define SPI_CSIX_CKR             0x00020000UL
#define SPI_CSIX_SLIT            0x00010000UL
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIX_CSL(x)          ((uint32)(x) << 8UL)
/* END Msg(4:3453)-1 */
#define SPI_CSIX_EDLE            0x00000080UL
#define SPI_CSIX_DCS             0x00000020UL
#define SPI_CSIH_CSRI            0x00000010UL
#define SPI_CSIX_LBM             0x00000008UL
#define SPI_CSIX_HSE             0x00000002UL
#define SPI_CSIX_SSE             0x00000001UL

/* CSIXnCTL2 */
#define SPI_CSIX_CTL2_DEFAULT    (uint16)0xE000U
#define SPI_CSIX_PRS_DIV_1       (uint16)0x0000U
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIX_PRS_DIV_2       (uint16)0x2000U
/* END Msg(4:0857)-3 */
#define SPI_CSIX_PRS_DIV_4       (uint16)0x4000U
#define SPI_CSIX_PRS_DIV_8       (uint16)0x6000U
#define SPI_CSIX_PRS_DIV_16      (uint16)0x8000U
#define SPI_CSIX_PRS_DIV_32      (uint16)0xA000U
#define SPI_CSIX_PRS_DIV_64      (uint16)0xC000U
#define SPI_CSIX_PRS_SLAVE       (uint16)0xE000U
#define SPI_CSIX_PRS_MASK        (uint16)0xE000U

/* CSIHnMCLT0 */
#define SPI_CSIH_MCTL0_DEFAULT   (uint16)0x001FU
#define SPI_CSIH_TO_MASK         (uint16)0xFFE0U
#define SPI_CSIH_MMS_MASK        (uint16)0x0300U

/* CSIHnMCTL1 */
#define SPI_CSIH_MCTL1_DEFAULT   0x00000000UL
/* To Mask FFS Bits of MCTL1 Register */
#define SPI_MCTL1_FFS_MASK       0x0000007FUL

/* CSIHnBRS */
#define SPI_CSIH_BRS_NUM         4UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_BRS_DEFAULT     (uint16)0x0000U
/* END Msg(4:0857)-3 */
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIX_BRS(x)          (uint16)(x)
/* END Msg(4:3453)-1 */

/* CSIXnSTR0 */
#define SPI_CSIH_TMOE            (uint16)0x8000UL
#define SPI_CSIH_OFE             (uint16)0x4000UL
#define SPI_CSIX_TSF             (uint16)0x0080UL
#define SPI_CSIH_FLF             (uint16)0x0020UL
#define SPI_CSIH_EMF             (uint16)0x0010UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIX_DCE             (uint16)0x0008UL
#define SPI_CSIX_PE              (uint16)0x0002UL
#define SPI_CSIX_OVE             (uint16)0x0001UL
/* END Msg(4:3453)-1 */
#define SPI_CSIX_ERR_MASK        (uint16)(SPI_CSIH_TMOE | SPI_CSIH_OFE | \
 SPI_CSIX_DCE | SPI_CSIX_PE | SPI_CSIX_OVE)

/* CSIXnSTCR0 */
#define SPI_CSIH_TMOEC           (uint16)0x8000U
#define SPI_CSIH_OFEC            (uint16)0x4000U
#define SPI_CSIH_PCT             (uint16)0x0100U
#define SPI_CSIX_DCEC            (uint16)0x0008U
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIX_PEC             (uint16)0x0002U
/* END Msg(4:0857)-3 */
#define SPI_CSIX_OVEC            (uint16)0x0001U

/* CSIXnCFGx */
#define SPI_CSIX_CFG_DEFAULT     0x00000000UL
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_BRSS(x)         ((uint32)(x) << 30UL)
/* END Msg(4:3453)-1 */
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_BRSS_GET(x)     ((uint32)(x) >> 30UL)
/* END Msg(4:3453)-1 */
#define SPI_CSIX_PS_NONE         0x00000000UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIX_PS_ZERO         0x10000000UL
#define SPI_CSIX_PS_ODD          0x20000000UL
/* END Msg(4:0857)-3 */
#define SPI_CSIX_PS_EVEN         0x30000000UL
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIX_DLS(x)          (((uint32)(x) % 16UL) << 24UL)
/* END Msg(4:3453)-1 */
#define SPI_CSIH_RCB             0x00080000UL
#define SPI_CSIX_DIRM            0x00000000UL
#define SPI_CSIX_DIRL            0x00040000UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIX_CKP             0x00020000UL
#define SPI_CSIX_DAP             0x00010000UL
#define SPI_CSIH_IDL             0x00008000UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_ID_0_5          0x00000000UL
#define SPI_CSIH_ID_1            0x00001000UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_ID_1_5          0x00002000UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_ID_2_5          0x00003000UL
#define SPI_CSIH_ID_3_5          0x00004000UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_ID_4_5          0x00005000UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_ID_6_5          0x00006000UL
#define SPI_CSIH_ID_8_5          0x00007000UL
#define SPI_CSIH_HD_0_5          0x00000000UL
#define SPI_CSIH_HD_1            0x00000100UL
#define SPI_CSIH_HD_1_5          0x00000200UL
#define SPI_CSIH_HD_2_5          0x00000300UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_HD_3_5          0x00000400UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_HD_4_5          0x00000500UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_HD_6_5          0x00000600UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_HD_8_5          0x00000700UL
#define SPI_CSIH_HD_9_5          0x00000800UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_HD_10_5         0x00000900UL
/* END Msg(4:0857)-3 */
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_HD_11_5         0x00000A00UL
#define SPI_CSIH_HD_12_5         0x00000B00UL
/* END Msg(4:0857)-3 */
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_HD_14_5         0x00000C00UL
#define SPI_CSIH_HD_16_5         0x00000D00UL
#define SPI_CSIH_HD_18_5         0x00000E00UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_HD_20_5         0x00000F00UL
#define SPI_CSIH_IN_0            0x00000000UL
#define SPI_CSIH_IN_0_5          0x00000010UL
#define SPI_CSIH_IN_1            0x00000020UL
#define SPI_CSIH_IN_2            0x00000030UL
#define SPI_CSIH_IN_3            0x00000040UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_IN_4            0x00000050UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_IN_6            0x00000060UL
#define SPI_CSIH_IN_8            0x00000070UL
#define SPI_CSIH_IN_9            0x00000080UL
#define SPI_CSIH_IN_10           0x00000090UL
#define SPI_CSIH_IN_11           0x000000A0UL
#define SPI_CSIH_IN_12           0x000000B0UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_IN_14           0x000000C0UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_IN_16           0x000000D0UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_IN_18           0x000000E0UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_IN_20           0x000000F0UL
#define SPI_CSIH_SP_0_5          0x00000000UL
#define SPI_CSIH_SP_1            0x00000001UL
#define SPI_CSIH_SP_1_5          0x00000002UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_SP_2_5          0x00000003UL
#define SPI_CSIH_SP_3_5          0x00000004UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_SP_4_5          0x00000005UL
#define SPI_CSIH_SP_6_5          0x00000006UL
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_SP_8_5          0x00000007UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_SP_9_5          0x00000008UL
#define SPI_CSIH_SP_10_5         0x00000009UL
#define SPI_CSIH_SP_11_5         0x0000000AUL
#define SPI_CSIH_SP_12_5         0x0000000BUL
#define SPI_CSIH_SP_14_5         0x0000000CUL
#define SPI_CSIH_SP_16_5         0x0000000DUL
#define SPI_CSIH_SP_18_5         0x0000000EUL
#define SPI_CSIH_SP_20_5         0x0000000FUL

/* CSIXnTX0W */
#define SPI_CSIX_EDL             0x20000000UL

/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_CS(x)           ((uint32)(x) << 16UL)
/* END Msg(4:3453)-1 */

/* CSIHnMRWP0 */
#define SPI_CSIH_TRWA_MASK       0xFFFFFF80UL
#define SPI_CSIH_RRA_MASK        0xFF80FFFFUL
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_SET_TRWA(x)     ((uint32)(x))
/* END Msg(4:3453)-1 */
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_SET_RRA(x)      ((uint32)(x) << 16UL)
/* END Msg(4:3453)-1 */

/* CSIHnMCLT2 */
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_CSIH_ND_MASK         0x00FF0000UL
/* END Msg(4:0857)-3 */
#define SPI_CSIH_SET_BTST        0x80000000UL
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_SET_ND(x)       (((uint32)(x) << 16UL) & SPI_CSIH_ND_MASK)
/* END Msg(4:3453)-1 */
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_GET_ND(x)       (((uint32)(x) & SPI_CSIH_ND_MASK) >> 16UL)
/* END Msg(4:3453)-1 */
#define SPI_CSIH_SOP_MASK        0x0000007FUL
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_GET_SOP(x)      ((uint32)(x) & SPI_CSIH_SOP_MASK)
/* END Msg(4:3453)-1 */
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_CSIH_SET_SOP(x)      ((uint32)(x) & SPI_CSIH_SOP_MASK)
/* END Msg(4:3453)-1 */
#define SPI_CSIH_MCTL2_DEFAULT   (uint32)0x00000000UL

/* For CSIG specific registers */
#define SPI_CSIG_BCTL0_DEFAULT   (uint8)0x01U

/* For Loopback test */
#define SPI_CSIX_LOOPBACK_CFG    0x18000000UL
#define SPI_CSIX_LOOPBACK_BRS    (uint16)0x0640U
#define SPI_CSIX_LOOPBACK_DATA   (uint16)0x00A5U

/* For ECC Self test */
#define ECC_CTL_SET_EC1EDIC_EC2EDIC      (uint16)0x0018U
#define ECC_CTL_CLEAR_EC1EDIC_EC2EDIC    (uint16)0x0000U
#define ECC_CTL_1BIT_ERRCLR_FLAG         (uint16)0x0200U
#define ECC_CTL_2BIT_ERRCLR_FLAG         (uint16)0x0400U
#define ECC_CTL_ECER1F_ECER2F_CLEAR      (uint16)0x0600U
#define ECC_CTL_ERR_FLAG                 (uint16)0x0006U
#define ECC_CTL_1BIT_ERR_FLAG            0x00000002UL
#define ECC_CTL_2BIT_ERR_FLAG            0x00000004UL
#define ECC_CTL_ECEMF_SET                0x00000001UL
#define ECC_TMC_SET_TEST_DISABLE         (uint16)0x8000U
#define ECC_TMC_SET_BITS                 (uint16)0x8093U
#define ECC_TED_RAM_INITIALIZE           0x00000000UL
#define ECC_TRC_ALL_ZERO_PATTERN         0x00000000UL
#define ECC_TRC_ALL_ONE_PATTERN          0xFFFFFFFFUL
#define ECC_TRC_TWO_BIT_PATTERN          0x00000003UL
#define ECC_TRC_ERDB_INITIALIZE          (uint8)0x00U
#define ECC_TEST_TOTAL_PATTERNS          0x00000027UL
#define ECC_CODE_TOTAL_PATTERNS          0x00000007UL

/* Port pin mask */
#define SPI_PORT_PIN_MASK                (uint32)0xFFFF0000UL
/* Port pin mask */
#define SPI_PORT_PIN_VALUE_MASK          (uint32)0x0000FFFFUL

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* IO mapping structure for BRS register */
typedef struct STag_Spi_BRSRegType
{
  VAR(uint16, TYPEDEF) usBRS;                     /* BRS              */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved[2];              /* Reserved         */
  /* END Msg(2:3132)-2 */
} Spi_BRSRegType;

/* IO mapping structure for CSIX control registers */
typedef struct STag_Spi_CSIXCTLRegType
{
  VAR(uint8, TYPEDEF) ucCTL0;                     /* +0000H CTL0      */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved0[15];            /* Reserved         */
  /* END Msg(2:3132)-2 */
  VAR(uint32, TYPEDEF) ulCTL1;                    /* +0010H CTL1      */
  VAR(uint16, TYPEDEF) usCTL2;                    /* +0014H CTL2      */
}Spi_CSIXCTLRegType;

/* IO mapping structure for CSIX status registers */
typedef struct STag_Spi_CSIXSTRegType
{
  VAR(uint32, TYPEDEF) ulSTR0;                    /* STR0      */
  VAR(uint16, TYPEDEF) usSTCR0;                   /* STCR0     */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved0[2];             /* Reserved         */
  /* END Msg(2:3132)-2 */
}Spi_CSIXSTRegType;

/* IO mapping structure for CSIH registers */
typedef struct STag_Spi_CSIHRegType
{
  VAR(uint32, TYPEDEF) ulMCTL1;                   /* +1000H MCTL1     */
  VAR(uint32, TYPEDEF) ulMCTL2;                   /* +1004H MCTL2     */
  VAR(uint32, TYPEDEF) ulTX0W;                    /* +1008H TX0W      */
  VAR(uint16, TYPEDEF) usTX0H;                    /* +100CH TX0H      */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved3[2];             /* Reserved         */
  /* END Msg(2:3132)-2 */
  VAR(uint32, TYPEDEF) ulRX0W;                    /* +1010H RX0W      */
  VAR(uint16, TYPEDEF) usRX0H;                    /* +1014H RX0H      */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF)  aaReserved4[2];            /* Reserved         */
  /* END Msg(2:3132)-2 */
  VAR(uint32, TYPEDEF) ulMRWP0;                   /* +1018H MRWP0     */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved5[36];            /* Reserved         */
  /* END Msg(2:3132)-2 */
  VAR(uint16, TYPEDEF) usMCTL0;                   /* +1040H MCTL0     */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved6[2];             /* Reserved         */
  /* END Msg(2:3132)-2 */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint32, TYPEDEF) aaCFG[8];                  /* +1044H CFG       */
  /* END Msg(2:3132)-2 */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF)  aaReserved7[4];            /* Reserved         */
  /* END Msg(2:3132)-2 */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(Spi_BRSRegType, TYPEDEF) aaBRS[4];          /* +1068H BRS       */
  /* END Msg(2:3132)-2 */
} Spi_CSIHRegType;

/* IO mapping structure for CSIG registers */
typedef struct STag_Spi_CSIGRegType
{
  VAR(uint8, TYPEDEF) ucBCTL0;                    /* +1000H BCTL0     */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved0[3];             /* Reserved         */
  /* END Msg(2:3132)-2 */
  VAR(uint32, TYPEDEF) ulTX0W;                    /* +1004H TX0W      */
  VAR(uint16, TYPEDEF) usTX0H;                    /* +1008H TX0H      */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved1[2];             /* Reserved         */
  /* END Msg(2:3132)-2 */
  VAR(uint16, TYPEDEF) usRX0H;                    /* +100CH RX0H      */
  VAR(uint32, TYPEDEF) ulCFG0;                    /* +1010H CFG       */
} Spi_CSIGRegType;

/* Structure of the register ECCCSIHnTRC */
typedef struct STag_Spi_EccTrcRegType
{
  VAR(uint8, TYPEDEF) ucErdb;
  VAR(uint8, TYPEDEF) ucEcrd;
  VAR(uint8, TYPEDEF) ucHord;
  VAR(uint8, TYPEDEF) ucSynd;
}Spi_EccTrcRegType;

/* IO mapping structure for ECCCSIH registers */
typedef struct STag_Spi_CSIHECCRegType
{
  VAR(uint16, TYPEDEF) usEccCtl;                  /* + 00H CTL */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved0[2];             /* Reserved  */
  /* END Msg(2:3132)-2 */
  VAR(uint16, TYPEDEF) usEccTmc;                  /* + 04H TMC */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint8, TYPEDEF) aaReserved1[2];             /* Reserved  */
  /* END Msg(2:3132)-2 */
  VAR(Spi_EccTrcRegType, TYPEDEF) stEccTrc;       /* + 08H TRC */
  VAR(uint32, TYPEDEF) ulEccTed;                  /* + 0CH TED */
}Spi_CSIHECCRegType;

/* Structure for the register information for each CSIX unit */
typedef struct STag_Spi_CSIXRegisterSetType
{
  /* Base address of CSIX control registers (CSIXnCTL0) */
  volatile P2VAR(Spi_CSIXCTLRegType, TYPEDEF, REGSPACE) pCSIXCTLRegs;
  /* Base address of CSIX status registers (CSIXnSTR0) */
  volatile P2VAR(Spi_CSIXSTRegType, TYPEDEF, REGSPACE) pCSIXSTRegs;
#if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Base address of CSIH specific registers (CSIHnMCTL1) */
  volatile P2VAR(Spi_CSIHRegType, TYPEDEF, REGSPACE) pCSIHRegs;
#if (SPI_ECC_SELFTEST == SPI_ECC_INIT) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
  /* Base address of ECC CISH registers (ECCCSIHnCTL) */
  volatile P2VAR(Spi_CSIHECCRegType, TYPEDEF, REGSPACE) pCSIHECCRegs;
#endif /* (SPI_ECC_SELFTEST == SPI_ECC_INIT) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME) */
#endif /* SPI_CSIH_CONFIGURED == STD_ON) */
  /* Base address of CSIG specific registers (CSIGnBCTL0) */
#if (SPI_CSIG_CONFIGURED == STD_ON)
  volatile P2VAR(Spi_CSIGRegType, TYPEDEF, REGSPACE) pCSIGRegs;
#endif
  /* EIC register address for CSIXnTIC interrupt */
  volatile P2VAR(uint16, TYPEDEF, REGSPACE) pICTIC;
  /* EIC register address for CSIXnTIR interrupt */
  volatile P2VAR(uint16, TYPEDEF, REGSPACE) pICTIR;
} Spi_CSIXRegisterSetType;

/* Structure for CSIXCTL Ram mirror */
typedef struct STag_Spi_CSIXCTLRamMirrorType
{
  VAR(uint32, TYPEDEF) ulCTL1;
  VAR(uint16, TYPEDEF) usCTL2;
  VAR(uint8, TYPEDEF) ucCTL0;
} Spi_CSIXCTLRamMirrorType;

/* Structure for CSIH Ram mirror */
typedef struct STag_Spi_CSIHRamMirrorType
{
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint32, TYPEDEF) aaCFG[8];
  /* END Msg(2:3132)-2 */
  /* QAC Warning: START Msg(2:3132)-2 */
  VAR(uint16, TYPEDEF) aaBRS[4];
  /* END Msg(2:3132)-2 */
  VAR(uint32, TYPEDEF) ulMCTL1;
  VAR(uint16, TYPEDEF) usMCTL0;
} Spi_CSIHRamMirrorType;

/* Structure for CSIG Ram mirror */
typedef struct STag_Spi_CSIGRamMirrorType
{
  VAR(uint32, TYPEDEF) ulCFG0;
  VAR(uint8, TYPEDEF) ucBCTL0;
} Spi_CSIGRamMirrorType;

#define SPI_START_SEC_CONST_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* The instance is declared in Spi_Lcfg.c */
/* MISRA Violation: START Msg(4:3684)-2 */
extern CONST(Spi_CSIXRegisterSetType, SPI_CONST) Spi_GaaCSIXRegs[];
/* END Msg(4:3684)-2 */

#define SPI_STOP_SEC_CONST_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define SPI_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXInit(
  CONST(uint8, AUTOMATIC) LucApiId);
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDeInit(
  CONST(uint8, AUTOMATIC) LucApiId);

extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXProcessJob(
  CONST(boolean, AUTOMATIC)  LblFirst,
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(uint8, AUTOMATIC) LucApiId);

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIXTransmitSyncJob(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(uint8, AUTOMATIC) LucApiId);
#endif
#endif

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXMainFunction_Handling(void);
#endif

#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXTransmitISR(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex);
#endif

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXWriteHWIB(
  CONST(Spi_ChannelType, AUTOMATIC) LucChannel,
  P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpDataBufferPtr,
  CONST(uint8, AUTOMATIC) LucApiId);
#endif

#if (SPI_DUAL_BUFFER_MODE == STD_ON)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReadHWIB(
  CONST(Spi_ChannelType, AUTOMATIC) LucChannel,
  P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpDataBufferPtr);
#endif

extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReceiveISR(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex);

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
   (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#if (SPI_DMA_CONFIGURED == STD_ON)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDMACompleteISR(
  CONST(uint32, AUTOMATIC) LulDMAUnitIndex);
#endif
#endif

extern FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDisableAllInterrupts(void);

#if (((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) && \
  (SPI_FORCE_CANCEL_API == STD_ON))
extern FUNC(void, SPI_FAST_CODE) Spi_CSIXForceStop(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex);
#endif

#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIXLoopBackSelfTest(
  CONST(uint8, AUTOMATIC) LucApiId);
#endif

#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ECC_INIT) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIHEccSelfTest(void);
#endif
#endif

#if (SPI_CSIX_RAM_MIRROR == STD_ON)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIXRegsConsistencyCheck(
  CONST(Spi_HWConsistencyModeType, AUTOMATIC) LenHWConsistencyMode);
#endif

#define SPI_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* SPI_CSIX_LLDRIVER_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
