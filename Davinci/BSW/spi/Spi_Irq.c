/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Irq.c                                                   */
/* Version      = V1.0.0                                                      */
/* Date         = 24-Oct-2019                                                 */
/*============================================================================*/
/*                               COPYRIGHT                                    */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the ISR implementations for SPI                         */
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
 *                         1. As per ARDAACH-98, use Spi_GulCancelingHWUnits to
 *                         prevent transmission/reception of related HW units
 *                         during force cancel operation.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Spi.h"
#include "Spi_Irq.h"
#include "Spi_CSIX_LLDriver.h"
#include "Spi_Ram.h"
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define SPI_IRQ_C_AR_RELEASE_MAJOR_VERSION \
                                  SPI_AR_RELEASE_MAJOR_VERSION_VALUE
#define SPI_IRQ_C_AR_RELEASE_MINOR_VERSION \
                                  SPI_AR_RELEASE_MINOR_VERSION_VALUE
#define SPI_IRQ_C_AR_RELEASE_REVISION_VERSION \
                               SPI_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define SPI_IRQ_C_SW_MAJOR_VERSION    SPI_SW_MAJOR_VERSION_VALUE
#define SPI_IRQ_C_SW_MINOR_VERSION    SPI_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (SPI_IRQ_AR_RELEASE_MAJOR_VERSION != \
                                       SPI_IRQ_C_AR_RELEASE_MAJOR_VERSION)
#error "Spi_Irq.c : Mismatch in Release Major Version"
#endif

#if (SPI_IRQ_AR_RELEASE_MINOR_VERSION != \
                                       SPI_IRQ_C_AR_RELEASE_MINOR_VERSION)
#error "Spi_Irq.c : Mismatch in Release Minor Version"
#endif

#if (SPI_IRQ_AR_RELEASE_REVISION_VERSION != \
                                       SPI_IRQ_C_AR_RELEASE_REVISION_VERSION)
#error "Spi_Irq.c : Mismatch in Release Revision Version"
#endif

#if (SPI_IRQ_SW_MAJOR_VERSION != SPI_IRQ_C_SW_MAJOR_VERSION)
#error "Spi_Irq.c : Mismatch in Software Major Version"
#endif

#if (SPI_IRQ_SW_MINOR_VERSION != SPI_IRQ_C_SW_MINOR_VERSION)
#error "Spi_Irq.c : Mismatch in Software Minor Version"
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
/* Message       : (4:3412) Macro defines an unrecognized code-fragment.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : There are same code for each ISRs, this macro is necessary */
/*                 to reduce redundant code and maintenance effort.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-2 and                           */
/*                 END Msg(4:3412)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : There are same code for each ISRs, this macro is necessary */
/*                 to reduce redundant code and maintenance effort.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-3 and                           */
/*                 END Msg(4:3458)-3 tags in the code.                        */
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
/* Message       : (2:3441) Function call argument is an expression with      */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3441           */
/* Justification : According to the coding guide, all global variables must   */
/*                 be declared with volatile keyword. Since these are normal  */
/*                 memory objects, there is no side effect.                   */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3441)-2 and                           */
/*                 END Msg(2:3441)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* Code snippet to perform interrupt consistency checking */
#if (SPI_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
/* MISRA Violation: START Msg(4:3412)-2 */
#define SPI_CSIG_INT_ASSERTION(index, intname) \
  if (SPI_ZERO != \
    (*Spi_GaaCSIXRegs[(uint32)((&Spi_GpFirstHWUnit[(uint32)\
    Spi_GpConfigPtr->pCSIGToHWUnit[index]])->ucPhysicalIndex)].pIC##intname\
    & SPI_EIC_EIMK_MASK)) \
  { \
    Dem_ReportErrorStatus(SPI_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED); \
  } \
  else \
/* END Msg(4:3412)-2 */

/* MISRA Violation: START Msg(4:3412)-2 */
#define SPI_CSIH_INT_ASSERTION(index, intname) \
  if (SPI_ZERO != \
    (*Spi_GaaCSIXRegs[(uint32)((&Spi_GpFirstHWUnit[(uint32)\
    Spi_GpConfigPtr->pCSIHToHWUnit[index]])->ucPhysicalIndex)].pIC##intname\
    & SPI_EIC_EIMK_MASK)) \
  { \
    Dem_ReportErrorStatus(SPI_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED); \
  } \
  else \
/* END Msg(4:3412)-2 */

/* MISRA Violation: START Msg(4:3412)-2 */
#define SPI_DMA_INT_ASSERTION(index) \
  if ((SPI_ZERO != \
    (*Spi_GpFirstDMAUnit[Spi_GpConfigPtr->pDMAToHWUnit[(index)]].pICDma \
    & SPI_EIC_EIMK_MASK))) \
  { \
    Dem_ReportErrorStatus(SPI_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED); \
  } \
  else \
/* END Msg(4:3412)-2 */
#else
#define SPI_CSIH_INT_ASSERTION(index, intname)
#define SPI_CSIG_INT_ASSERTION(index, intname)
#define SPI_DMA_INT_ASSERTION(index)
#endif /* (SPI_INTERRUPT_CONSISTENCY_CHECK == STD_ON) */

#if (SPI_FORCE_CANCEL_API == STD_ON)
/* MISRA Violation: START Msg(4:3412)-2 */
/* Check whether Spi_ForceCancel is called for on-going unit */
#define SPI_SEQ_CANCELED_ASSERTION(index) \
  if ((uint32)SPI_ZERO != \
    (Spi_GulCancelingHWUnits & ((uint32)SPI_ONE << (index)))) \
  { \
    /* Nothing to do */\
  } \
  else \
/* END Msg(4:3412)-2 */
/* Process data transmission or reception */
#else
#define SPI_SEQ_CANCELED_ASSERTION(index)
#endif

/* All functions in this file have same attribute */
#define SPI_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name     : SPI_CSIGn_TIC_ISR
**
** Service ID        : Not Applicable
**
** Description       : Interrupt Service Routine for CSIGn transmit interrupt
**
** Re-entrancy       : Non Reentrant
**
** Input Parameters  : None
**
** InOut Parameters  : None
**
** Output Parameters : None
**
** Return Value      : void
**
** Pre-condition     : Not Applicable
**
** Global Variable   : None
**
** Function invoked  : Spi_CSIXTransmitISR
**
** Registers Used    : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-3 */
#define SPI_CSIG_TIC_ISR_TEMPLATE(phyidx) \
/* References: SPI_DDD_ACT_048 */ \
{ \
  SPI_CSIG_INT_ASSERTION(phyidx, TIC) \
  /* References: SPI_DDD_ACT_048_ERR001 */ \
  { \
    SPI_SEQ_CANCELED_ASSERTION((uint32)Spi_GpConfigPtr->pCSIGToHWUnit[phyidx]) \
    { \
      Spi_CSIXTransmitISR((uint32)Spi_GpConfigPtr->pCSIGToHWUnit[phyidx]); \
    } \
  } \
}
/* END Msg(4:3458)-3 */

/* CH0 ************************************************************************/
#if defined (SPI_CSIG0_TIC_ISR_API)
#if (SPI_CSIG0_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG0_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG0_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG0_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIG0)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG0_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG0_TIC_ISR_API) */

/* CH1 ************************************************************************/
#if defined (SPI_CSIG1_TIC_ISR_API)
#if (SPI_CSIG1_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG1_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG1_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG1_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIG1)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG1_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG1_TIC_ISR_API) */

/* CH2 ************************************************************************/
#if defined (SPI_CSIG2_TIC_ISR_API)
#if (SPI_CSIG2_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG2_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG2_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG2_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIG2)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG2_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG2_TIC_ISR_API) */

/* CH3 ************************************************************************/
#if defined (SPI_CSIG3_TIC_ISR_API)
#if (SPI_CSIG3_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG3_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG3_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG3_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIG3)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG3_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG3_TIC_ISR_API) */

/* CH4 ************************************************************************/
#if defined (SPI_CSIG4_TIC_ISR_API)
#if (SPI_CSIG4_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG4_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG4_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG4_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIG4)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG4_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG4_TIC_ISR_API) */

/*******************************************************************************
** Function Name     : SPI_CSIGn_TIR_ISR
**
** Service ID        : Not Applicable
**
** Description       : Interrupt Service Routine for CSIGn receive interrupt
**
** Re-entrancy       : Non Reentrant
**
** Input Parameters  : None
**
** InOut Parameters  : None
**
** Output Parameters : None
**
** Return Value      : void
**
** Pre-condition     : Not Applicable
**
** Global Variable   : None
**
** Function invoked  : Spi_CSIXReceiveISR
**
** Registers Used    : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-3 */
#define SPI_CSIG_TIR_ISR_TEMPLATE(phyidx) \
/* References: SPI_DDD_ACT_049 */ \
{ \
  SPI_CSIG_INT_ASSERTION(phyidx, TIR) \
  /* References: SPI_DDD_ACT_049_ERR001 */ \
  { \
    SPI_SEQ_CANCELED_ASSERTION((uint32)Spi_GpConfigPtr->pCSIGToHWUnit[phyidx]) \
    { \
      Spi_CSIXReceiveISR((uint32)Spi_GpConfigPtr->pCSIGToHWUnit[phyidx]); \
    } \
  } \
}
/* END Msg(4:3458)-3 */

/* CH0 ************************************************************************/
#if defined (SPI_CSIG0_TIR_ISR_API)
#if (SPI_CSIG0_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG0_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG0_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG0_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIG0)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG0_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG0_TIR_ISR_API) */

/* CH1 ************************************************************************/
#if defined (SPI_CSIG1_TIR_ISR_API)
#if (SPI_CSIG1_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG1_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG1_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG1_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIG1)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG1_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG1_TIR_ISR_API) */

/* CH2 ************************************************************************/
#if defined (SPI_CSIG2_TIR_ISR_API)
#if (SPI_CSIG2_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG2_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG2_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG2_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIG2)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG2_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG2_TIR_ISR_API) */

/* CH3 ************************************************************************/
#if defined (SPI_CSIG3_TIR_ISR_API)
#if (SPI_CSIG3_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG3_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG3_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG3_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIG3)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG3_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG3_TIR_ISR_API) */

/* CH4 ************************************************************************/
#if defined (SPI_CSIG4_TIR_ISR_API)
#if (SPI_CSIG4_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIG4_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIG4_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG4_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIG_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIG4)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIG4_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIG4_TIR_ISR_API) */


/*******************************************************************************
** Function Name     : SPI_CSIHn_TIC_ISR
**
** Service ID        : Not Applicable
**
** Description       : Interrupt Service Routine for CSIHn transmit interrupt
**
** Re-entrancy       : Non Reentrant
**
** Input Parameters  : None
**
** InOut Parameters  : None
**
** Output Parameters : None
**
** Return Value      : void
**
** Pre-condition     : Not Applicable
**
** Global Variable   : None
**
** Function invoked  : Spi_CSIXTransmitISR
**
** Registers Used    : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-3 */
#define SPI_CSIH_TIC_ISR_TEMPLATE(phyidx) \
/* References: SPI_DDD_ACT_048 */ \
{ \
  SPI_CSIH_INT_ASSERTION(phyidx, TIC) \
  /* References: SPI_DDD_ACT_048_ERR001 */ \
  { \
    SPI_SEQ_CANCELED_ASSERTION((uint32)Spi_GpConfigPtr->pCSIHToHWUnit[phyidx]) \
    { \
      Spi_CSIXTransmitISR((uint32)Spi_GpConfigPtr->pCSIHToHWUnit[phyidx]); \
    } \
  } \
}
/* END Msg(4:3458)-3 */

/* CH0 ************************************************************************/
#if defined (SPI_CSIH0_TIC_ISR_API)
#if (SPI_CSIH0_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH0_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH0_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH0_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIH0)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH0_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH0_TIC_ISR_API) */

/* CH1 ************************************************************************/
#if defined (SPI_CSIH1_TIC_ISR_API)
#if (SPI_CSIH1_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH1_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH1_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH1_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIH1)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH1_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH1_TIC_ISR_API) */

/* CH2 ************************************************************************/
#if defined (SPI_CSIH2_TIC_ISR_API)
#if (SPI_CSIH2_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH2_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH2_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH2_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIH2)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH2_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH2_TIC_ISR_API) */

/* CH3 ************************************************************************/
#if defined (SPI_CSIH3_TIC_ISR_API)
#if (SPI_CSIH3_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH3_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH3_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH3_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIH3)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH3_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH3_TIC_ISR_API) */

/* CH4 ************************************************************************/
#if defined (SPI_CSIH4_TIC_ISR_API)
#if (SPI_CSIH4_TIC_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH4_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH4_TIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH4_TIC_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIC_ISR_TEMPLATE(SPI_PHYIDX_CSIH4)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH4_TIC_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH4_TIC_ISR_API) */

/*******************************************************************************
** Function Name     : SPI_CSIHn_TIR_ISR
**
** Service ID        : Not Applicable
**
** Description       : Interrupt Service Routine for CSIHn receive interrupt
**
** Re-entrancy       : Non Reentrant
**
** Input Parameters  : None
**
** InOut Parameters  : None
**
** Output Parameters : None
**
** Return Value      : void
**
** Pre-condition     : Not Applicable
**
** Global Variable   : None
**
** Function invoked  : Spi_CSIXReceiveISR
**
** Registers Used    : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-3 */
#define SPI_CSIH_TIR_ISR_TEMPLATE(phyidx) \
/* References: SPI_DDD_ACT_049 */ \
{ \
  SPI_CSIH_INT_ASSERTION(phyidx, TIR) \
  /* References: SPI_DDD_ACT_049_ERR001 */ \
  { \
    SPI_SEQ_CANCELED_ASSERTION((uint32)Spi_GpConfigPtr->pCSIHToHWUnit[phyidx]) \
    { \
      Spi_CSIXReceiveISR((uint32)Spi_GpConfigPtr->pCSIHToHWUnit[phyidx]); \
    } \
  } \
}
/* END Msg(4:3458)-3 */

/* CH0 ************************************************************************/
#if defined (SPI_CSIH0_TIR_ISR_API)
#if (SPI_CSIH0_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH0_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH0_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH0_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIH0)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH0_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH0_TIR_ISR_API) */

/* CH1 ************************************************************************/
#if defined (SPI_CSIH1_TIR_ISR_API)
#if (SPI_CSIH1_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH1_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH1_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH1_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIH1)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH1_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH1_TIR_ISR_API) */

/* CH2 ************************************************************************/
#if defined (SPI_CSIH2_TIR_ISR_API)
#if (SPI_CSIH2_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH2_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH2_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH2_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIH2)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH2_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH2_TIR_ISR_API) */

/* CH3 ************************************************************************/
#if defined (SPI_CSIH3_TIR_ISR_API)
#if (SPI_CSIH3_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH3_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH3_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH3_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIH3)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH3_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH3_TIR_ISR_API) */

/* CH4 ************************************************************************/
#if defined (SPI_CSIH4_TIR_ISR_API)
#if (SPI_CSIH4_TIR_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_CSIH4_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_CSIH4_TIR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH4_TIR_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_CSIH_TIR_ISR_TEMPLATE(SPI_PHYIDX_CSIH4)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_CSIH4_TIR_ISR_API == STD_ON) */
#endif /* End of (SPI_CSIH4_TIR_ISR_API) */


/*******************************************************************************
** Function Name     : SPI_DMA_mm_ISR
**
** Service ID        : Not Applicable
**
** Description       : Interrupt Service Routine for DMA interrupt
**
** Reentrancy        : Non Reentrant
**
** Input Parameters  : None
**
** InOut Parameters  : None
**
** Output Parameters : None
**
** Return Value      : void
**
** Pre-condition     : Not Applicable
**
** Global Variable   : None
**
** Function invoked  : Spi_CSIXDMACompleteISR
**
** Registers Used    : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-3 */
#define SPI_DMA_ISR_TEMPLATE(phyidx) \
/* References: SPI_DDD_ACT_050 */ \
{ \
  SPI_DMA_INT_ASSERTION(phyidx) \
  /* References: SPI_DDD_ACT_050_ERR001 */ \
  SPI_SEQ_CANCELED_ASSERTION((uint32)Spi_GpConfigPtr->pDMAToHWUnit[phyidx]) \
  { \
    { \
      Spi_CSIXDMACompleteISR((uint32)Spi_GpConfigPtr->pDMAToHWUnit[phyidx]); \
    } \
  } \
}
/* END Msg(4:3458)-3 */

/* CH00 *********************************************************************/
#if (SPI_DMA00_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA00_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA00_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_00)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA00_ISR_API == STD_ON) */

/* CH01 *********************************************************************/
#if (SPI_DMA01_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA01_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA01_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_01)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA01_ISR_API == STD_ON) */

/* CH02 *********************************************************************/
#if (SPI_DMA02_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA02_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA02_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_02)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA02_ISR_API == STD_ON) */

/* CH03 *********************************************************************/
#if (SPI_DMA03_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA03_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* MISRA Violation: START Msg(4:0491)-1 */
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA03_ISR(void)
#endif
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_03)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA03_ISR_API == STD_ON) */

/* CH04 *********************************************************************/
#if (SPI_DMA04_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA04_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* MISRA Violation: START Msg(4:0491)-1 */
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA04_ISR(void)
#endif
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_04)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA04_ISR_API == STD_ON) */

/* CH05 *********************************************************************/
#if (SPI_DMA05_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA05_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA05_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_05)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA05_ISR_API == STD_ON) */

/* CH06 *********************************************************************/
#if (SPI_DMA06_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA06_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA06_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_06)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA06_ISR_API == STD_ON) */

/* CH07 *********************************************************************/
#if (SPI_DMA07_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA07_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA07_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_07)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA07_ISR_API == STD_ON) */

/* CH08 *********************************************************************/
#if (SPI_DMA08_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA08_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA08_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_08)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA08_ISR_API == STD_ON) */

/* CH09 *********************************************************************/
#if (SPI_DMA09_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA09_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA09_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_09)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA09_ISR_API == STD_ON) */

/* CH10 *********************************************************************/
#if (SPI_DMA10_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA10_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA10_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_10)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA10_ISR_API == STD_ON) */

/* CH11 *********************************************************************/
#if (SPI_DMA11_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA11_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA11_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_11)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA11_ISR_API == STD_ON) */

/* CH12 *********************************************************************/
#if (SPI_DMA12_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA12_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA12_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_12)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA12_ISR_API == STD_ON) */

/* CH13 *********************************************************************/
#if (SPI_DMA13_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA13_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA13_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_13)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA13_ISR_API == STD_ON) */

/* CH14 *********************************************************************/
#if (SPI_DMA14_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA14_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA14_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_14)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA14_ISR_API == STD_ON) */

/* CH15 *********************************************************************/
#if (SPI_DMA15_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA15_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA15_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_15)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA15_ISR_API == STD_ON) */

/* CH16 *********************************************************************/
#if (SPI_DMA16_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA16_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA16_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA16_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_16)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA16_ISR_API == STD_ON) */

/* CH17 *********************************************************************/
#if (SPI_DMA17_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA17_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA17_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA17_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_17)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA17_ISR_API == STD_ON) */

/* CH18 *********************************************************************/
#if (SPI_DMA18_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA18_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA18_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA18_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_18)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA18_ISR_API == STD_ON) */

/* CH19 *********************************************************************/
#if (SPI_DMA19_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA19_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA19_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA19_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_19)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA19_ISR_API == STD_ON) */

/* CH20 *********************************************************************/
#if (SPI_DMA20_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA20_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA20_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA20_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_20)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA20_ISR_API == STD_ON) */

/* CH21 *********************************************************************/
#if (SPI_DMA21_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA21_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA21_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA21_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_21)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA21_ISR_API == STD_ON) */

/* CH22 *********************************************************************/
#if (SPI_DMA22_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA22_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA22_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA22_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_22)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA22_ISR_API == STD_ON) */

/* CH23 *********************************************************************/
#if (SPI_DMA23_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA23_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA23_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA23_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_23)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA23_ISR_API == STD_ON) */

/* CH24 *********************************************************************/
#if (SPI_DMA24_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA24_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA24_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA24_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_24)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA24_ISR_API == STD_ON) */

/* CH25 *********************************************************************/
#if (SPI_DMA25_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA25_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA25_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA25_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_25)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA25_ISR_API == STD_ON) */

/* CH26 *********************************************************************/
#if (SPI_DMA26_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA26_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA26_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA26_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_26)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA26_ISR_API == STD_ON) */

/* CH27 *********************************************************************/
#if (SPI_DMA27_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA27_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA27_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA27_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_27)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA27_ISR_API == STD_ON) */

/* CH28 *********************************************************************/
#if (SPI_DMA28_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA28_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA28_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA28_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_28)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA28_ISR_API == STD_ON) */

/* CH29 *********************************************************************/
#if (SPI_DMA29_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA29_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA29_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA29_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_29)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA29_ISR_API == STD_ON) */

/* CH30 *********************************************************************/
#if (SPI_DMA30_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA30_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA30_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA30_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_30)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA30_ISR_API == STD_ON) */

/* CH31 *********************************************************************/
#if (SPI_DMA31_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA31_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA31_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA31_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_31)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA31_ISR_API == STD_ON) */

/* CH32 *********************************************************************/
#if (SPI_DMA32_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA32_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA32_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA32_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_32)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA32_ISR_API == STD_ON) */

/* CH33 *********************************************************************/
#if (SPI_DMA33_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA33_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA33_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA33_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_33)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA33_ISR_API == STD_ON) */

/* CH34 *********************************************************************/
#if (SPI_DMA34_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA34_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA34_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA34_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_34)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA34_ISR_API == STD_ON) */

/* CH35 *********************************************************************/
#if (SPI_DMA35_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA35_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA35_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA35_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_35)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA35_ISR_API == STD_ON) */

/* CH36 *********************************************************************/
#if (SPI_DMA36_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA36_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA36_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA36_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_36)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA36_ISR_API == STD_ON) */

/* CH37 *********************************************************************/
#if (SPI_DMA37_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA37_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA37_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA37_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_37)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA37_ISR_API == STD_ON) */

/* CH38 *********************************************************************/
#if (SPI_DMA38_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA38_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA38_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA38_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_38)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA38_ISR_API == STD_ON) */

/* CH39 *********************************************************************/
#if (SPI_DMA39_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA39_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA39_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA39_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_39)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA39_ISR_API == STD_ON) */

/* CH40 *********************************************************************/
#if (SPI_DMA40_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA40_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA40_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA40_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_40)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA40_ISR_API == STD_ON) */

/* CH41 *********************************************************************/
#if (SPI_DMA41_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA41_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA41_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA41_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_41)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA41_ISR_API == STD_ON) */

/* CH42 *********************************************************************/
#if (SPI_DMA42_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA42_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA42_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA42_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_42)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA42_ISR_API == STD_ON) */

/* CH43 *********************************************************************/
#if (SPI_DMA43_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA43_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA43_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA43_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_43)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA43_ISR_API == STD_ON) */

/* CH44 *********************************************************************/
#if (SPI_DMA44_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA44_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA44_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA44_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_44)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA44_ISR_API == STD_ON) */

/* CH45 *********************************************************************/
#if (SPI_DMA45_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA45_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA45_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA45_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_45)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA45_ISR_API == STD_ON) */

/* CH46 *********************************************************************/
#if (SPI_DMA46_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA46_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA46_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA46_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_46)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA46_ISR_API == STD_ON) */

/* CH47 *********************************************************************/
#if (SPI_DMA47_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA47_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA47_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA47_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_47)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA47_ISR_API == STD_ON) */

/* CH48 *********************************************************************/
#if (SPI_DMA48_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA48_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA48_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA48_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_48)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA48_ISR_API == STD_ON) */

/* CH49 *********************************************************************/
#if (SPI_DMA49_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA49_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA49_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA49_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_49)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA49_ISR_API == STD_ON) */

/* CH50 *********************************************************************/
#if (SPI_DMA50_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA50_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA50_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA50_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_50)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA50_ISR_API == STD_ON) */

/* CH51 *********************************************************************/
#if (SPI_DMA51_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA51_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA51_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA51_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_51)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA51_ISR_API == STD_ON) */

/* CH52 *********************************************************************/
#if (SPI_DMA52_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA52_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA52_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA52_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_52)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA52_ISR_API == STD_ON) */

/* CH53 *********************************************************************/
#if (SPI_DMA53_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA53_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA53_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA53_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_53)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA53_ISR_API == STD_ON) */

/* CH54 *********************************************************************/
#if (SPI_DMA54_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA54_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA54_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA54_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_54)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA54_ISR_API == STD_ON) */

/* CH55 *********************************************************************/
#if (SPI_DMA55_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA55_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA55_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA55_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_55)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA55_ISR_API == STD_ON) */

/* CH56 *********************************************************************/
#if (SPI_DMA56_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA56_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA56_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA56_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_56)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA56_ISR_API == STD_ON) */

/* CH57 *********************************************************************/
#if (SPI_DMA57_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA57_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA57_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA57_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_57)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA57_ISR_API == STD_ON) */

/* CH58 *********************************************************************/
#if (SPI_DMA58_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA58_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA58_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA58_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_58)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA58_ISR_API == STD_ON) */

/* CH59 *********************************************************************/
#if (SPI_DMA59_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA59_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA59_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA59_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_59)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA59_ISR_API == STD_ON) */

/* CH60 *********************************************************************/
#if (SPI_DMA60_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA60_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA60_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA60_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_60)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA60_ISR_API == STD_ON) */

/* CH61 *********************************************************************/
#if (SPI_DMA61_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA61_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA61_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA61_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_61)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA61_ISR_API == STD_ON) */

/* CH62 *********************************************************************/
#if (SPI_DMA62_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA62_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA62_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA62_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_62)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA62_ISR_API == STD_ON) */

/* CH63 *********************************************************************/
#if (SPI_DMA63_ISR_API == STD_ON)
/* Defines the CAT2interrupt mapping */
#if defined (Os_SPI_DMA63_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
ISR(SPI_DMA63_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA63_ISR(void)
#endif
/* MISRA Violation: START Msg(4:0491)-1 */
/* QAC Warning: START Msg(2:3441)-2 */
SPI_DMA_ISR_TEMPLATE(SPI_PHYIDX_DMA_63)
/* END Msg(2:3441)-2 */
/* END Msg(4:0491)-1 */
#endif /* End of (SPI_DMA63_ISR_API == STD_ON) */


#define SPI_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
