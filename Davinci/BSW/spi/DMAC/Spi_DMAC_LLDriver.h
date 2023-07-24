/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_DMAC_LLDriver.h                                         */
/* Version      = V1.0.0                                                      */
/* Date         = 24-Oct-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions for link time parameters           */
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
 *          24-Oct-2019  : The following changes are made:
 *                         1. As per ARDAACH-88, add new macro to clear TCC
 *                         in Spi_CSIXDMACompleteISR.
 *                         2. As per ARDAACH-88, move "Spi_RegWrite.h" inclusion
 *                         from Spi_DMA_LLDriver.c to "Spi_DMAC_LLDriver.h".
 *                         3. As per ARDAACH-77, change change reserved bit as
 *                         is reset value for  macro SPI_DMA_DTCT_MASK.
 */
/******************************************************************************/

#ifndef SPI_DMAC_LLDRIVER_H
#define SPI_DMAC_LLDRIVER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi_Types.h"
#include "Spi_RegWrite.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_DMAC_LLDRIVER_AR_RELEASE_MAJOR_VERSION SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_DMAC_LLDRIVER_AR_RELEASE_MINOR_VERSION SPI_AR_RELEASE_MINOR_VERSION
#define SPI_DMAC_LLDRIVER_AR_RELEASE_REVISION_VERSION \
                                              SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_DMAC_LLDRIVER_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_DMAC_LLDRIVER_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION

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

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Attributes for Spi_DMAStart() */

#define SPI_DMA_DCEN_ENABLE           (uint32)0x00000001UL
#define SPI_DMA_DCEN_DISABLE          (uint32)0x00000000UL
#define SPI_DMA_DTCT_CLEAR            (uint32)0x00000000UL
#define SPI_DMA_TRM_BLOCK1            (uint32)0x00000001UL
#define SPI_DMA_DRS_HW_REQ            (uint32)0x04000000UL
#define SPI_DMA_STS_SR_REQ            (uint32)0x00000001UL
#define SPI_DMA_TCE                   (uint32)0x00004000UL
#define SPI_DMA_SACM_FIXED            (uint32)0x00000040UL
#define SPI_DMA_DACM_FIXED            (uint32)0x00000100UL
#define SPI_DMA_SACM_UP               (uint32)0x00000000UL
#define SPI_DMA_DACM_UP               (uint32)0x00000000UL
#define SPI_DMA_REQEN                 (uint32)0x00000001UL
#define SPI_DMA_REQDI                 (uint32)0x00000001UL
#define SPI_DMA_DISABLE               (uint32)0x00000000UL
#define SPI_DMA_DRQ_CLEAR             (uint32)0x00000001UL
#define SPI_DMA_ONCE                  (uint32)0xFFFFDFFFUL

#define SPI_DMA_ERC                   (uint32)0x00000080UL
#define SPI_DMA_TCC                   (uint32)0x00000010UL

#define SPI_DMA_8BIT                  (uint32)0x00000000UL
#define SPI_DMA_16BIT                 (uint32)0x00000004UL

/* Mask for Write verification */
#define SPI_DMA_SR_MASK               (uint32)0x00000001UL
#define SPI_DMA_DTCT_MASK             (uint32)0x0C1F7FFFUL
#define SPI_DMA_DCEN_MASK             (uint32)0x00000001UL
#define SPI_DMA_ERC_TCC_MASK          (uint32)0x00000090UL
#define SPI_DMA_TCC_MASK              (uint32)0x00000010UL

/* Macros to calculate bit position of REQSEL */
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_DMA_REQSEL_SHIFT(number)  (((uint32)(number) & 0x7FUL) << 1UL)
/* END Msg(4:3453)-1 */

/* Macro to trigger for SW transfer */
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_DMA_SW_REQ(index)         ((&Spi_GpFirstDMAUnit[\
(index)])->pDmaRegs->ulDCSTSn = SPI_DMA_STS_SR_REQ)
/* END Msg(4:3453)-1 */

/* Macro to clear transmission complete DMA */
#if (SPI_DMA_WRITE_VERIFY == SPI_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_DMA_WRITE_VERIFY_CLEAR_TCC(index)\
  SPI_WRITE_REG_ONLY(\
    &Spi_GpFirstDMAUnit[(index)].pDmaRegs->ulDCSTCn, SPI_DMA_TCC)\
  SPI_VERIFY_WRITE_REG(\
    &Spi_GpFirstDMAUnit[(index)].pDmaRegs->ulDCSTn,\
    (uint32)SPI_ZERO, SPI_DMA_TCC_MASK, SPI_ASYNCTRANSMIT_SID)
/* END Msg(4:3453)-1 */
#else
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_DMA_WRITE_VERIFY_CLEAR_TCC(index)   SPI_WRITE_REG_ONLY(\
   &Spi_GpFirstDMAUnit[(index)].pDmaRegs->ulDCSTCn, SPI_DMA_TCC)
/* END Msg(4:3453)-1 */
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* IO mapping structure for DMA register */
typedef struct STag_Spi_DMAChRegType
{
  /* Source Address Register */
  VAR(uint32, TYPEDEF) volatile ulDSAn;
  /* Destination Address Register */
  VAR(uint32, TYPEDEF) volatile ulDDAn;
  /* Transfer Count Register */
  VAR(uint32, TYPEDEF) volatile ulDTCn;
  /* Transfer Control Register */
  VAR(uint32, TYPEDEF) volatile ulDTCTn;
  /* Reload Source Address Register */
  VAR(uint32, TYPEDEF) volatile ulDRSAn;
  /* Reload Destination Address Register */
  VAR(uint32, TYPEDEF) volatile ulDRDAn;
  /* Reload Transfer Count Register */
  VAR(uint32, TYPEDEF) volatile ulDRTCn;
  /* Transfer Count Compare Register */
  VAR(uint32, TYPEDEF) volatile ulDTCCn;
  /* Channel Operation Enable Setting Register */
  VAR(uint32, TYPEDEF) volatile ulDCENn;
  /* Transfer Status Register */
  VAR(uint32, TYPEDEF) volatile ulDCSTn;
  /* Transfer Status Set Register */
  VAR(uint32, TYPEDEF) volatile ulDCSTSn;
  /* Transfer Status Clear Register */
  VAR(uint32, TYPEDEF) volatile ulDCSTCn;
  /* Trigger factor Setting Register */
  VAR(uint32, TYPEDEF) volatile ulDTFRn;
  /* Transfer Request Status Register */
  VAR(uint32, TYPEDEF) volatile ulDTFRRQn;
  /* Transfer Request Clear Register*/
  VAR(uint32, TYPEDEF) volatile ulDTFRRQCn;
} Spi_DMAChRegType;

/* Structure for DMA Ram mirror */
typedef struct STag_Spi_DMARamMirrorType
{
  /* Source Address Register */
  VAR(uint32, TYPEDEF) volatile ulDSAn;
  /* Destination Address Register */
  VAR(uint32, TYPEDEF) volatile ulDDAn;
  /* Transfer Control Register */
  VAR(uint32, TYPEDEF) volatile ulDTCTn;
  /* Trigger factor Setting Register */
  VAR(uint32, TYPEDEF) volatile ulDTFRn;
} Spi_DMARamMirrorType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_DMA_CHECK_INTERRUPT_FLAG(index) \
  (Spi_GpFirstDMAUnit[(index)].pDmaRegs->ulDCSTn & SPI_DMA_TCC)
/* END Msg(4:3453)-1 */

#define SPI_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (SPI_DMA_CONFIGURED == STD_ON)

extern FUNC(void, SPI_PRIVATE_CODE) Spi_DMAInit(void);
extern FUNC(void, SPI_PRIVATE_CODE) Spi_DMADeInit(void);
extern FUNC(void, SPI_PRIVATE_CODE) Spi_DMAStart(
  CONST(uint32, AUTOMATIC) LulDmaIndex,
  CONSTP2CONST(volatile void, AUTOMATIC, SPI_APPL_DATA) LpMemAddress,
  CONST(uint32, AUTOMATIC) LulCount,
  CONST(uint32, AUTOMATIC) LulAttributes);
extern FUNC(void, SPI_PRIVATE_CODE) Spi_DMAMaskHWUnitInterrupts(
  CONST(uint32, AUTOMATIC) LulDmaIndex,
  CONST(boolean, AUTOMATIC) LblMask,
  CONST(boolean, AUTOMATIC) LblClearEIRF);

#if (SPI_FORCE_CANCEL_API == STD_ON)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_DMAStop(
  CONST(uint32, AUTOMATIC) LulDmaIndex);
#endif

#if (SPI_DMA_RAM_MIRROR == STD_ON)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_DMARegsConsistencyCheck(
  CONST(Spi_HWConsistencyModeType, AUTOMATIC) LenHWConsistencyMode);
#endif

#endif /* (SPI_DMA_CONFIGURED == STD_ON) */

#define SPI_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* SPI_DMAC_LLDRIVER_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
