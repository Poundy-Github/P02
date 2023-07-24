/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_DMAC_LLDriver.c                                         */
/* Version      = V1.0.0                                                      */
/* Date         = 24-Oct-2019                                                 */
/*============================================================================*/
/*                               COPYRIGHT                                    */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low level driver function definitions of the SPI        */
/* Driver                                                                     */
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
 *                         1. As per ARDAACH-73, remove setting of SW DMA
 *                         transfer request flag in FIFO mode in Spi_DMAInit.
 *                         2. As per ARDAACH-83, correct condition to set
 *                         DTFRn and DTCTn in Spi_DMAInit.
 *                         3. As per ARDAACH-91, add REG mirroring for DSAn
 *                         and DDAn in Spi_DMAInit, Spi_DMARegsConsistencyCheck.
 *                         4. As per ARDAACH-87, add setting defaul value for
 *                         DTFRn in Spi_DMADeInit.
 *                         5. As per ARDAACH-88, move "Spi_RegWrite.h" inclusion
 *                         to "Spi_DMAC_LLDriver.h".
 *                         6. As per ARDAACH-74, remove setting of DCSTSm.SRS
 *                         in Spi_DMAInit().
 *                         7. As per ARDAACH-155, correct used write verify
 *                         macros used in Spi_DMADeInit.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "rh850_Types.h"
#include "Spi.h"
#include "Spi_Ram.h"
#include "Spi_DMAC_LLDriver.h"
#include "Spi_Irq.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define SPI_DMAC_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION \
                                  SPI_AR_RELEASE_MAJOR_VERSION_VALUE
#define SPI_DMAC_LLDRIVER_C_AR_RELEASE_MINOR_VERSION \
                                  SPI_AR_RELEASE_MINOR_VERSION_VALUE
#define SPI_DMAC_LLDRIVER_C_AR_RELEASE_REVISION_VERSION \
                               SPI_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define SPI_DMAC_LLDRIVER_C_SW_MAJOR_VERSION    SPI_SW_MAJOR_VERSION_VALUE
#define SPI_DMAC_LLDRIVER_C_SW_MINOR_VERSION    SPI_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (SPI_DMAC_LLDRIVER_AR_RELEASE_MAJOR_VERSION != \
                               SPI_DMAC_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Spi_DMAC_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (SPI_DMAC_LLDRIVER_AR_RELEASE_MINOR_VERSION != \
                               SPI_DMAC_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Spi_DMAC_LLDriverDMA.c : Mismatch in Release Minor Version"
#endif

#if (SPI_DMAC_LLDRIVER_AR_RELEASE_REVISION_VERSION != \
                               SPI_DMAC_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Spi_DMAC_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (SPI_DMAC_LLDRIVER_SW_MAJOR_VERSION != \
                               SPI_DMAC_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Spi_DMAC_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (SPI_DMAC_LLDRIVER_SW_MINOR_VERSION != \
                               SPI_DMAC_LLDRIVER_C_SW_MINOR_VERSION)
#error "Spi_DMAC_LLDriver.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This is necessary to support multiple configuration.       */
/*                 The actuall array can't be decided statically.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-1 and                           */
/*                 END Msg(4:0491)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 3.1, 11.3                                */
/* Justification : This is necessary to set pointer value to DMA register.    */
/*                                                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-2 and                           */
/*                 END Msg(4:0303)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : EIC register allows both 16 bit and 8 bit accesses.        */
/*                 8 bit access is necessary to modify only EIMK bit.         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0310)-3 and                           */
/*                 END Msg(4:0310)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:1055) [C99] The keyword 'inline' has been used.         */
/*                 result is always that of the left-hand operand.            */
/* Rule          : MISRA-C:2004                                               */
/* Justification : It is used to achieve better throughput instead of         */
/*                 invoking a function call.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:1055)-4 and                           */
/*                 END Msg(4:1055)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognised code-fragment.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-5 and                           */
/*                 END Msg(4:3412)-5 tags in the code.                        */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/* Justification : Function used for write-verify will impact a lot to time   */
/*                 execution. Using macros is better in point of performance. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-6 and                           */
/*                 END Msg(4:3453)-6 tags in the code.                        */
/******************************************************************************/

/******************************************************************************/
/**                      QAC Warning                                         **/
/******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Function call argument is an expression with      */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The name of an include file has been specified using a     */
/*                 macro. This is not recommended in some coding standards.   */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:3206) The parameter is not used in this function.       */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3206           */
/* Justification : This is done as per implementation requirement             */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3206)-2 and                           */
/*                 END Msg(2:3206)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

#if (SPI_DMA_CONFIGURED == STD_ON)

#define SPI_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/*******************************************************************************
**                      Inline Function Definitions                           **
*******************************************************************************/

#if (SPI_DMA_WRITE_VERIFY != SPI_WV_DISABLE)
/*******************************************************************************
** Function Name         : Spi_DMAVerifyWriteReg32
**
** Description           : This function is to do the write, RAM mirroring and
**                         check write verify for DMA registers in Spi_Init
**                         functions. This function shall be used for writing
**                         the registers which need Ram Mirroring.
**
** Input Parameters      : LpWriteRegAddr, LulRegWriteValue, LpMirrorAddr,
**                         LulMaskValue, LucApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : SPI_VERIFY_WRITE_REG
*******************************************************************************/
/* MISRA Violation: START Msg(4:1055)-4 */
/* QAC Warning: START Msg(2:3206)-2 */
static INLINE FUNC(void, SPI_PRIVATE_CODE) Spi_DMAVerifyWriteReg32(
  CONSTP2CONST(volatile uint32, AUTOMATIC, REGSPACE) LpWriteRegAddr,
  CONST(uint32, AUTOMATIC) LulRegWriteValue,
  CONST(uint32, AUTOMATIC) LulMaskValue,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-2 */
/* END Msg(4:1055)-4 */
  /* References: SPI_DDD_ACT_104 */
{
  SPI_VERIFY_WRITE_REG(
    LpWriteRegAddr, LulRegWriteValue,
    LulMaskValue, LucApiId)
}
#endif /* End of #if (SPI_DMA_WRITE_VERIFY != SPI_WV_DISABLE) */

/* Code snippet to perform write-verify and ram mirror */
#if (SPI_DMA_WRITE_VERIFY != SPI_WV_DISABLE)
  /* Macro for write-verify and mirror register accessed in an internal
    function which is invoked in both init/de-init API. */
  /* MISRA Violation: START Msg(4:3412)-5 */
  #define SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(\
    pWriteRegAddr, RegWriteValue, pMirrorAddr, MaskValue, RegSize, ApiId) \
  SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
  Spi_DMAVerifyWriteReg##RegSize(\
    pWriteRegAddr, RegWriteValue, MaskValue, ApiId);\
  SPI_DMA_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue)
  /* END Msg(4:3412)-5 */

  /* Macro for write-verify only register accessed in an internal
    function which is invoked in init/de-init API. */
  /* MISRA Violation: START Msg(4:3412)-5 */
  #define SPI_DMA_WRITE_VERIFY_INIT(\
    pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
  SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
  Spi_DMAVerifyWriteReg##RegSize(\
    pWriteRegAddr, RegWriteValue, MaskValue, ApiId);
  /* END Msg(4:3412)-5 */

  /* Macro for checking writing register accessed in an internal function
     which is invoked in init/de-init API. */
  /* MISRA Violation: START Msg(4:3412)-5 */
  #define SPI_DMA_VERIFY_WRITE_INIT(\
    pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
  Spi_DMAVerifyWriteReg##RegSize(\
    pWriteRegAddr, RegWriteValue, MaskValue, ApiId);
  /* END Msg(4:3412)-5 */

  #if (SPI_DMA_WRITE_VERIFY == SPI_WV_INIT_ONLY)
    /* Macro for write-verify and mirror register accessed in an internal
    function which is invoked in run-time API. */
    /* MISRA Violation: START Msg(4:3453)-6 */
    #define SPI_DMA_WRITE_VERIFY_AND_MIRROR_RUNTIME(\
      pWriteRegAddr, RegWriteValue, pMirrorAddr, MaskValue, RegSize, ApiId) \
    SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
    SPI_DMA_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue)
    /* END Msg(4:3453)-6 */

     /* Macro for write-verify only register accessed in an internal
    function which is invoked in run-time API. */
    /* MISRA Violation: START Msg(4:3453)-6 */
    #define SPI_DMA_WRITE_VERIFY_RUNTIME(\
      pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
    SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)
    /* END Msg(4:3453)-6 */

    /* Macro for checking writing register accessed in an internal function
     which is invoked invoked in run-time API. */
    /* MISRA Violation: START Msg(4:3412)-5 */
    #define SPI_DMA_VERIFY_WRITE_RUNTIME(\
      pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
    {\
    }
    /* END Msg(4:3412)-5 */
  #else
    /* Macro for write-verify and mirror register accessed in an internal
    function which is invoked in run-time API. */
    #define SPI_DMA_WRITE_VERIFY_AND_MIRROR_RUNTIME \
                                          SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT
     /* Macro for write-verify only register accessed in an internal
    function which is invoked in run-time API. */
    #define SPI_DMA_WRITE_VERIFY_RUNTIME \
                                         SPI_DMA_WRITE_VERIFY_INIT
    /* Macro for checking writing register accessed in an internal function
     which is invoked invoked in run-time API. */
    #define SPI_DMA_VERIFY_WRITE_RUNTIME \
                                         SPI_DMA_VERIFY_WRITE_INIT
  #endif
#else
  /* Macro for write-verify and mirror register accessed in an internal
    function which is invoked in both init/de-init API. */
  /* MISRA Violation: START Msg(4:3453)-6 */
  #define SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(\
    pWriteRegAddr, RegWriteValue, pMirrorAddr, MaskValue, RegSize, ApiId) \
  SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
  SPI_DMA_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue)
  /* END Msg(4:3453)-6 */

  /* Macro for write-verify only register accessed in an internal
    function which is invoked in init/de-init API. */
  /* MISRA Violation: START Msg(4:3453)-6 */
  #define SPI_DMA_WRITE_VERIFY_INIT(\
    pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
  SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)
  /* END Msg(4:3453)-6 */

  /* Macro for checking writing register accessed in an internal function
     which is invoked in init/de-init API. */
  /* MISRA Violation: START Msg(4:3412)-5 */
  #define SPI_DMA_VERIFY_WRITE_INIT(\
      pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
   {\
   }
  /* END Msg(4:3412)-5 */

  /* Macro for write-verify and mirror register accessed in an internal
  function which is invoked in run-time API. */
  #define SPI_DMA_WRITE_VERIFY_AND_MIRROR_RUNTIME \
                                        SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT

   /* Macro for write-verify only register accessed in an internal
  function which is invoked in run-time API. */
  #define SPI_DMA_WRITE_VERIFY_RUNTIME \
                                       SPI_DMA_WRITE_VERIFY_INIT

  /* Macro for checking writing register accessed in an internal function
   which is invoked invoked in run-time API. */
  #define SPI_DMA_VERIFY_WRITE_RUNTIME \
                                       SPI_DMA_VERIFY_WRITE_INIT
#endif


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Spi_DMAInit
**
** Service ID         : Not Applicable
**
** Description        : This function initializes all configured DMA units.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpFirstHWUnit, Spi_GpFirstDMAUnit,
**                      Spi_GaaCSIHRegs
**
** Function invoked   : None
**
** Registers Used     : EICn/ICxxx, DCSTCn, DTFRn, DCENn, DSAn, DDAn, DTFRRQCn
**
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_DMAInit(void)
/* References: SPI_DDD_ACT_080 */
{
  P2CONST(Spi_DmaConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) LpCSIXTX0H;
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) LpCSIXRX0H;
  VAR(uint32, AUTOMATIC) LulDmaIndex;
  VAR(uint32, AUTOMATIC) LulCSIXIndex;
  VAR(uint32, AUTOMATIC) LulDTFRRegValue;
#if (SPI_FIFO_MODE == STD_ON)
  VAR(uint32, AUTOMATIC) LulDTCTRegValue;
#endif

  for (LulDmaIndex = SPI_ZERO;
    LulDmaIndex < Spi_GpConfigPtr->ucNoOfDMAChannels; LulDmaIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpDmaConfig = &Spi_GpFirstDMAUnit[LulDmaIndex];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpHWInfo = &Spi_GpFirstHWUnit[LpDmaConfig->ucSPIHWUnit];
    /* END Msg(4:0491)-1 */
    LulCSIXIndex = LpHWInfo->ucPhysicalIndex;
    /* Stop DMA by disabling channel operation */
    SPI_DMA_WRITE_VERIFY_INIT(&LpDmaConfig->pDmaRegs->ulDCENn,
      SPI_DMA_DCEN_DISABLE, SPI_DMA_DCEN_MASK, 32, SPI_INIT_SID)
    /* References: SPI_DDD_ACT_080_REG001 */
    /* Clear DMA Transfer Request */
    SPI_WRITE_REG_ONLY(&LpDmaConfig->pDmaRegs->ulDTFRRQCn, SPI_DMA_DRQ_CLEAR)
    /* References: SPI_DDD_ACT_080_REG002 */
    /* Check for Write verification */
    SPI_DMA_VERIFY_WRITE_INIT(&LpDmaConfig->pDmaRegs->ulDTFRRQn,
      (uint32)SPI_ZERO, SPI_DMA_DRQ_CLEAR, 32, SPI_INIT_SID)
    /* Clear flags */
    SPI_WRITE_REG_ONLY(&LpDmaConfig->pDmaRegs->ulDCSTCn,
      (SPI_DMA_ERC | SPI_DMA_TCC))
    /* References: SPI_DDD_ACT_080_REG003 */
    /* Check for Write verification */
    SPI_DMA_VERIFY_WRITE_INIT(&LpDmaConfig->pDmaRegs->ulDCSTn,
      (uint32)SPI_ZERO, SPI_DMA_ERC_TCC_MASK, 32, SPI_INIT_SID)

#if ((SPI_FIFO_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
    if ((SPI_TRUE == LpDmaConfig->blRxSide) ||
      (SPI_MEMMODE_DIRECT_ACCESS == LpHWInfo->enMemoryMode))
#endif
    {
      /* Load the trigger factor configured */
      LulDTFRRegValue =
        SPI_DMA_REQSEL_SHIFT(LpDmaConfig->ucTriggerNumber) | SPI_DMA_REQEN;
      SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(&LpDmaConfig->pDmaRegs->ulDTFRn,
        LulDTFRRegValue,
        &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTFRn,
        CTLREG_8_BIT_MASK, 32, SPI_INIT_SID)
      /* References: SPI_DDD_ACT_080_REG004 */
      /* Configure HW request transfer mode */
      SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(&LpDmaConfig->pDmaRegs->ulDTCTn,
        SPI_DMA_DRS_HW_REQ,
        &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTCTn,
        SPI_DMA_DTCT_MASK, 32, SPI_INIT_SID)
      /* References: SPI_DDD_ACT_080_REG005 */
    }
#if ((SPI_FIFO_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
    else
    {
      /* Not configure trigger factor for Tx DMA in FIFO and Tx only mode */
      SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(&LpDmaConfig->pDmaRegs->ulDTFRn,
        (uint32)SPI_ZERO, &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTFRn,
        CTLREG_8_BIT_MASK, 32, SPI_INIT_SID)
      /* References: SPI_DDD_ACT_080_REG006 */
    }
#endif

#if (SPI_FIFO_MODE == STD_ON)
    if (SPI_MEMMODE_FIFO == LpHWInfo->enMemoryMode)
    {
      /* Configure block transfer in FIFO Mode*/
      LulDTCTRegValue = LpDmaConfig->pDmaRegs->ulDTCTn | SPI_DMA_TRM_BLOCK1;
      SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(&LpDmaConfig->pDmaRegs->ulDTCTn,
        LulDTCTRegValue, &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTCTn,
        SPI_DMA_DTCT_MASK, 32, SPI_INIT_SID)
      /* References: SPI_DDD_ACT_080_REG008 */
    }
    else
    {
      /* Nothing to do */
    }
#endif

  /* Set source/destination address of register side */
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
  /* Check physical index corresponding to CSIH */
    if (NULL_PTR != Spi_GaaCSIXRegs[LulCSIXIndex].pCSIHRegs)
#endif
    {
#if (SPI_CSIH_CONFIGURED == STD_ON)
      LpCSIXTX0H = &Spi_GaaCSIXRegs[LulCSIXIndex].pCSIHRegs->usTX0H;
      LpCSIXRX0H = &Spi_GaaCSIXRegs[LulCSIXIndex].pCSIHRegs->usRX0H;
#endif
    }
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
    else
#endif
    {
#if (SPI_CSIG_CONFIGURED == STD_ON)
      LpCSIXTX0H = &Spi_GaaCSIXRegs[LulCSIXIndex].pCSIGRegs->usTX0H;
      LpCSIXRX0H = &Spi_GaaCSIXRegs[LulCSIXIndex].pCSIGRegs->usRX0H;
#endif
    }

    /* Check whether DMA is assigned to Rx */
    if (SPI_TRUE == LpDmaConfig->blRxSide)
    {
      /* DMA channel for reception. Hence load the source address register */
      /* MISRA Violation: START Msg(4:0303)-2 */
      SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(&LpDmaConfig->pDmaRegs->ulDSAn,
        (uint32)(LpCSIXRX0H), &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDSAn,
        CTLREG_32_BIT_MASK, 32, SPI_INIT_SID)
      /* END Msg(4:0303)-2 */
      /* References: SPI_DDD_ACT_080_REG009 */
    }
    else
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(&LpDmaConfig->pDmaRegs->ulDDAn,
        (uint32)(LpCSIXTX0H), &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDDAn,
        CTLREG_32_BIT_MASK, 32, SPI_INIT_SID)
      /* END Msg(4:0303)-2 */
      /* References: SPI_DDD_ACT_080_REG010 */
      /* Set interrupt mask, disable Tx interrupt of DMA completion */
      /* MISRA Violation: START Msg(4:0310)-3 */
      RH850_SV_SET_ICR_SYNCP(8, LpDmaConfig->pICDma, (uint8)SPI_EIC_EIMK_MASK);
      /* END Msg(4:0310)-3 */
      /* References: SPI_DDD_ACT_080_REG011 */
    }
  }
}

/*******************************************************************************
** Function Name      : Spi_DMADeInit
**
** Service ID         : Not Applicable
**
** Description        : This function de-initializes all configured DMA units.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Spi_Init should have been invoked.
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpFirstDMAUnit
**
** Function invoked   : None
**
** Registers Used     : EICn/ICxxx, DTFRRQCn, DCSTCn, DTCTn, DCENn, DSAn, DDAn
**
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_DMADeInit(void)
/* References: SPI_DDD_ACT_044 */
{
  VAR(uint32, AUTOMATIC) LulDmaIndex;
  P2CONST(Spi_DmaConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;

  for (LulDmaIndex = SPI_ZERO;
    LulDmaIndex < Spi_GpConfigPtr->ucNoOfDMAChannels; LulDmaIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpDmaConfig = &Spi_GpFirstDMAUnit[LulDmaIndex];
    /* END Msg(4:0491)-1 */
    /* Stop DMA by disabling channel operation */
    SPI_DMA_VERIFY_WRITE_INIT(&LpDmaConfig->pDmaRegs->ulDCENn,
      SPI_DMA_DCEN_DISABLE, SPI_DMA_DCEN_MASK, 32, SPI_DEINIT_SID)
    /* References: SPI_DDD_ACT_044_REG001 */
    /* Clear DMA Transfer Request */
    SPI_WRITE_REG_ONLY(&LpDmaConfig->pDmaRegs->ulDTFRRQCn, SPI_DMA_DRQ_CLEAR)
    /* References: SPI_DDD_ACT_044_REG002 */
    /* Check for Write verification */
    SPI_DMA_VERIFY_WRITE_INIT(&LpDmaConfig->pDmaRegs->ulDTFRRQn,
      (uint32)SPI_ZERO, SPI_DMA_DRQ_CLEAR, 32, SPI_DEINIT_SID)
    /* Clear flags */
    SPI_WRITE_REG_ONLY(&LpDmaConfig->pDmaRegs->ulDCSTCn,
      (SPI_DMA_ERC | SPI_DMA_TCC))
    /* References: SPI_DDD_ACT_044_REG003 */
    /* Check for Write verification */
    SPI_DMA_VERIFY_WRITE_INIT(&LpDmaConfig->pDmaRegs->ulDCSTn,
      (uint32)SPI_ZERO, SPI_DMA_ERC_TCC_MASK, 32, SPI_DEINIT_SID)
    /* Clear DMAC Transfer Control Register */
    SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(&LpDmaConfig->pDmaRegs->ulDTCTn,
      SPI_DMA_DTCT_CLEAR, &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTCTn,
      SPI_DMA_DTCT_MASK, 32, SPI_DEINIT_SID)
    /* References: SPI_DDD_ACT_044_REG004 */
    /* Clear source address register */
    SPI_DMA_VERIFY_WRITE_INIT(&LpDmaConfig->pDmaRegs->ulDSAn,
      (uint32)SPI_ZERO, CTLREG_32_BIT_MASK, 32, SPI_DEINIT_SID)
    /* References: SPI_DDD_ACT_044_REG005 */
    /* Clear destination address register */
    SPI_DMA_VERIFY_WRITE_INIT(&LpDmaConfig->pDmaRegs->ulDDAn,
      (uint32)SPI_ZERO, CTLREG_32_BIT_MASK, 32, SPI_DEINIT_SID)
    /* References: SPI_DDD_ACT_044_REG006 */
    /* Clear factor setting register */
    SPI_DMA_WRITE_VERIFY_AND_MIRROR_INIT(&LpDmaConfig->pDmaRegs->ulDTFRn,
      (uint32)SPI_ZERO, &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTFRn,
      CTLREG_8_BIT_MASK, 32, SPI_DEINIT_SID)
    /* References: SPI_DDD_ACT_044_REG009 */
    /* Set interrupt mask to disable DMA interrupt  */
    /* MISRA Violation: START Msg(4:0310)-3 */
    RH850_SV_SET_ICR_SYNCP(8, LpDmaConfig->pICDma, (uint8)SPI_EIC_EIMK_MASK);
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_044_REG007 */
    /* Clear interrupt request */
    RH850_SV_CLEAR_ICR_SYNCP(16, LpDmaConfig->pICDma,
      (uint16)(~SPI_EIC_EIRF_MASK));
    /* References: SPI_DDD_ACT_044_REG008 */
  }
}

/*******************************************************************************
** Function Name      : Spi_DMAStart
**
** Service ID         : Not Applicable
**
** Description        : This function starts DMA transfer.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW,
**                      Non-Reentrant for same HW
**
** Input Parameters   : LulDmaIndex   - Index of DMAUnit
**                      LpMemAddress  - Address of memory side
**                      LulCount      - Transfer count
**                      LulAttributes - Transfer attributes
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Spi_Init should have been invoked.
**
** Global Variable    : Spi_GpFirstDMAUnit
**
** Function invoked   : None
**
** Registers Used     : DCENn, DSAn, DTCTn, DCSTCn, DTCn, DTFRRQCn, DDAn
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_DMAStart(
  CONST(uint32, AUTOMATIC) LulDmaIndex,
  volatile CONSTP2CONST(void, AUTOMATIC, SPI_APPL_DATA) LpMemAddress,
  CONST(uint32, AUTOMATIC) LulCount,
  CONST(uint32, AUTOMATIC) LulAttributes)
/* References: SPI_DDD_ACT_045 */
{
  VAR(uint32, AUTOMATIC) LulDTCTRegValue;
  P2CONST(Spi_DmaConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpDmaConfig = &Spi_GpFirstDMAUnit[LulDmaIndex];
  /* END Msg(4:0491)-1 */

  if (SPI_TRUE == LpDmaConfig->blRxSide)
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    SPI_DMA_WRITE_VERIFY_RUNTIME(&LpDmaConfig->pDmaRegs->ulDDAn,
      (uint32)LpMemAddress, CTLREG_32_BIT_MASK, 32, SPI_ASYNCTRANSMIT_SID)
    /* END Msg(4:0303)-2 */
    /* References: SPI_DDD_ACT_045_REG001 */
  }
  else
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    SPI_DMA_WRITE_VERIFY_RUNTIME(&LpDmaConfig->pDmaRegs->ulDSAn,
      (uint32)LpMemAddress, CTLREG_32_BIT_MASK, 32, SPI_ASYNCTRANSMIT_SID)
    /* END Msg(4:0303)-2 */
    /* References: SPI_DDD_ACT_045_REG002 */
  }
  /* Clear DMA completion and DMA error flag for next transmission */
  SPI_WRITE_REG_ONLY(&LpDmaConfig->pDmaRegs->ulDCSTCn,
    (SPI_DMA_ERC | SPI_DMA_TCC))
  /* References: SPI_DDD_ACT_045_REG003 */
  /* Check for Write verification */
  SPI_DMA_VERIFY_WRITE_RUNTIME(&LpDmaConfig->pDmaRegs->ulDCSTn,
    (uint32)SPI_ZERO, SPI_DMA_ERC_TCC_MASK, 32, SPI_ASYNCTRANSMIT_SID)

  /* Clear DMA HW Transfer Request */
  SPI_WRITE_REG_ONLY(&LpDmaConfig->pDmaRegs->ulDTFRRQCn, SPI_DMA_DRQ_CLEAR)
  /* References: SPI_DDD_ACT_045_REG004 */
  /* Check for Write verification */
  SPI_DMA_VERIFY_WRITE_RUNTIME(&LpDmaConfig->pDmaRegs->ulDTFRRQn,
    (uint32)SPI_ZERO, SPI_DMA_DRQ_CLEAR, 32, SPI_ASYNCTRANSMIT_SID)

  /* Load the control register with input setting */
  LulDTCTRegValue = LpDmaConfig->pDmaRegs->ulDTCTn | LulAttributes;
  SPI_DMA_WRITE_VERIFY_AND_MIRROR_RUNTIME(&LpDmaConfig->pDmaRegs->ulDTCTn,
    LulDTCTRegValue, &Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTCTn,
    SPI_DMA_DTCT_MASK, 32, SPI_ASYNCTRANSMIT_SID)
  /* References: SPI_DDD_ACT_045_REG005 */

  /* Configure the number of buffers to transfer */
  SPI_DMA_WRITE_VERIFY_RUNTIME(&LpDmaConfig->pDmaRegs->ulDTCn, LulCount,
    CTLREG_32_BIT_MASK, 32, SPI_ASYNCTRANSMIT_SID)
  /* References: SPI_DDD_ACT_045_REG006 */

  /* DMA transfer enable, start DMA*/
  SPI_DMA_WRITE_VERIFY_RUNTIME(
    &LpDmaConfig->pDmaRegs->ulDCENn, SPI_DMA_DCEN_ENABLE,
    SPI_DMA_DCEN_MASK, 32, SPI_ASYNCTRANSMIT_SID)
  /* References: SPI_DDD_ACT_045_REG007 */
}

/*******************************************************************************
** Function Name      : Spi_DMAMaskHWUnitInterrupts
**
** Service ID         : NA
**
** Description        : This function manipulates interrupt masks of a HWUnit.
**                      This function modifies EIMK bit only,
**                      EIRF bit is not affected.
**                      This function doesn't perform disabling interruption,
**                      dummyread & SYNP. These should be done in a caller.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HWUnit
**                      Non-Reentrant for same HWUnit
**
** Input Parameters   : LulDmaIndex  - Index of HW
**                      LblMask      - TRUE: set mask, FALSE: reset mask
**                      LblClearEIRF - TRUE: clear interrupt request
**                                   - FAlSE: do not clear interrupt request
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Global variables must be initialized
**
** Global Variable    : Spi_GpFirstDMAUnit
**
** Function invoked   : None
**
** Registers Used     : EICn/ICxxx
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_DMAMaskHWUnitInterrupts(
  CONST(uint32, AUTOMATIC) LulDmaIndex,
  CONST(boolean, AUTOMATIC) LblMask,
  CONST(boolean, AUTOMATIC) LblClearEIRF)
/* References: SPI_DDD_ACT_046 */
{
  /* Write the lower byte of EIC registres to avoid modifing EIRF bit */
  if (SPI_TRUE == LblMask)
  {
    /* MISRA Violation: START Msg(4:0310)-3 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    RH850_SV_SET_ICR_SYNCP(8,
      Spi_GpFirstDMAUnit[LulDmaIndex].pICDma,
      (uint8)SPI_EIC_EIMK_MASK);
    /* END Msg(4:0491)-1 */
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_046_REG003 */
  }
  else
  {
    /* Check if request to clear pending interrupt */
    if (SPI_TRUE == LblClearEIRF)
    {
      /* Clear interrupt request flag */
      /* MISRA Violation: START Msg(4:0491)-1 */
      RH850_SV_CLEAR_ICR_SYNCP(16,
        Spi_GpFirstDMAUnit[LulDmaIndex].pICDma,
        (uint16)(~SPI_EIC_EIRF_MASK));
      /* END Msg(4:0491)-1 */
      /* References: SPI_DDD_ACT_046_REG002 */
    }
    else
    {
      /* Nothing to do*/
    }
    /* MISRA Violation: START Msg(4:0310)-3 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    RH850_SV_CLEAR_ICR_SYNCP(8,
      Spi_GpFirstDMAUnit[LulDmaIndex].pICDma,
      (uint8)(~SPI_EIC_EIMK_MASK));
    /* END Msg(4:0491)-1 */
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_046_REG001 */
  }
}

#if (SPI_FORCE_CANCEL_API == STD_ON)
/*******************************************************************************
** Function Name      : Spi_DMAStop
**
** Service ID         : Not Applicable
**
** Description        : This function stops DMA unit unconditionally.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW,
**                      Non-Reentrant for same HW
**
** Input Parameters   : LulDMAIndex - Index of DMAUnit
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Assigned SPI unit must be stopped
**
** Global Variable    : Spi_GpFirstDMAUnit
**
** Function invoked   : None
**
** Registers Used     : DCENn, DTFRRQCn, DCSTCn, DCSTn
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_DMAStop(
  CONST(uint32, AUTOMATIC) LulDmaIndex)
/* References: SPI_DDD_ACT_047 */
{
  P2CONST(Spi_DmaConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpDmaConfig = &Spi_GpFirstDMAUnit[LulDmaIndex];
  /* END Msg(4:0491)-1 */

  /* Stop DMA by disabling channel operation */
  SPI_DMA_WRITE_VERIFY_RUNTIME(&LpDmaConfig->pDmaRegs->ulDCENn,
    SPI_DMA_DCEN_DISABLE, SPI_DMA_DCEN_MASK, 32, SPI_FORCECANCEL_SID)
  /* References: SPI_DDD_ACT_047_REG001 */

  /* Clear DMA Transfer Request */
  SPI_WRITE_REG_ONLY(&LpDmaConfig->pDmaRegs->ulDTFRRQCn, SPI_DMA_DRQ_CLEAR)
  /* References: SPI_DDD_ACT_047_REG002 */

  /* Check for Write verification */
  SPI_DMA_VERIFY_WRITE_RUNTIME(&LpDmaConfig->pDmaRegs->ulDTFRRQn,
    (uint32)SPI_ZERO, SPI_DMA_DRQ_CLEAR, 32, SPI_FORCECANCEL_SID)

  /* Clear flags */
  SPI_WRITE_REG_ONLY(&LpDmaConfig->pDmaRegs->ulDCSTCn,
    (SPI_DMA_ERC | SPI_DMA_TCC))
  /* References: SPI_DDD_ACT_047_REG003 */

#if ((SPI_CSIX_WRITE_VERIFY == SPI_WV_DISABLE) && \
  (SPI_CSIX_RAM_MIRROR == STD_OFF))
  /* Dummy read if write-verify and ram mirror are disabled */
  RH850_IOREG_READ_ONLY(32, &LpDmaConfig->pDmaRegs->ulDCSTn)
#else
  /* Check for status register after write */
  SPI_DMA_VERIFY_WRITE_RUNTIME(&LpDmaConfig->pDmaRegs->ulDCSTn,
    (uint32)SPI_ZERO, SPI_DMA_ERC_TCC_MASK, 32, SPI_FORCECANCEL_SID)
#endif
  EXECUTE_SYNCP();
}
#endif /* (SPI_FORCE_CANCEL_SPI == STD_ON) */

#if (SPI_DMA_RAM_MIRROR == STD_ON)
/*******************************************************************************
** Function Name      : Spi_DMARegsConsistencyCheck
**
** Service ID         : Not Applicable
**
** Description        : This function is to check consistency DMA registers.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LenHWConsistencyMode - HW consistency mode type
**                                             (SPI_DYNAMIC/SPI_STATIC)
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpFirstHWUnit, Spi_GpFirstDMAUnit,
**                      Spi_GaaCSIHRegs
**
** Function invoked   : None
**
** Registers Used     : DTFRn, DSAn, DDAn
**
*******************************************************************************/
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_DMARegsConsistencyCheck(
  CONST(Spi_HWConsistencyModeType, AUTOMATIC) LenHWConsistencyMode)
/* References: SPI_DDD_ACT_081 */
{
  VAR(uint32, AUTOMATIC) LulDmaIndex;
  P2CONST(Spi_DmaConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

  LucReturnValue = E_OK;
  for (LulDmaIndex = SPI_ZERO;
    LulDmaIndex < Spi_GpConfigPtr->ucNoOfDMAChannels; LulDmaIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpDmaConfig = &Spi_GpFirstDMAUnit[LulDmaIndex];
    /* END Msg(4:0491)-1 */
    /* Check HW consistency mode */
    if (SPI_STATIC == LenHWConsistencyMode)
    {
      if (LpDmaConfig->pDmaRegs->ulDTFRn !=
        Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTFRn)
      {
        /* Update return status to E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      }
      else
      {
        /* Check whether DMA is assigned to Rx */
        if (SPI_TRUE == LpDmaConfig->blRxSide)
        {
          if (LpDmaConfig->pDmaRegs->ulDSAn !=
           Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDSAn)
          {
            /* Update return status to E_NOT_OK */
            LucReturnValue = E_NOT_OK;
          }
          else
          {
             /* Nothing to do */
          }
        }
        else
        {
          if (LpDmaConfig->pDmaRegs->ulDDAn !=
           Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDDAn)
          {
            /* Update return status to E_NOT_OK */
            LucReturnValue = E_NOT_OK;
          }
          else
          {
            /* Nothing to do */
          }
        }
      }
    }
    else
    {
      SPI_ENTER_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
      /* References: SPI_DDD_ACT_081_CRT001 */
      if ((LpDmaConfig->pDmaRegs->ulDTCTn !=
         Spi_GaaDMAChannelRegsMirror[LulDmaIndex].ulDTCTn))
      {
        /* Update return status to E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      }
      else
      {
        /* Nothing to do */
      }
      SPI_EXIT_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
      /* References: SPI_DDD_ACT_081_CRT002 */
    }
  }
  return LucReturnValue;
}
#endif /* (SPI_DMA_RAM_MIRROR == STD_ON) */

#define SPI_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* (SPI_DMA_CONFIGURED == STD_ON) */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
