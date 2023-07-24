/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Irq.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the ADC Driver Component                                  */
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
/* Implements EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */
/* Implements AR_PN0076_FR_0027 */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V1.0.1:  12-Jan-2016    : The following changes are made:
 *                           1. Include section updated.
 *                           2. Misra justification added.
 * V2.1.0:  28-Oct-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.2.0   16-Nov-2016    : The following changes are made:
 *                           1. As part of JIRA ticket ARDAABC-909
 *                              removed the ADC0_SG0, ADC1_SG0, ADC0_SG4 and
 *                              ADC1_SG4 interrupts.
 * V2.3.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage
 * V2.3.1:  20-May-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABD-1725,
 *                              Support is added for DMA interrupts of F1KM
 *                              ADC_DMA_CH16_ISR to ADC_DMA_CH31_ISR.
 * V2.3.2:  10-Aug-2017    : The following changes are made:
 *                           1. Support is added for DMA interrupts of F1KH
 *                              ADC_DMA_CH32_ISR to ADC_DMA_CH63_ISR.
 * V2.3.3:  28-Jun-2018    : The following changes are made:
 *                           1.As part of merging activity ticket ARDAABD-3453,
 *                             a.ISR mapping for ADC_DMA_CH63_ISR is corrected.
 *                             Ref : ARDAABD-3114.
 *                           2.As part of ARDAABD-3638, the function banners
 *                             are updated with the list registers and
 *                             functions invoked.
 *                           3.As part of traceability improvement activity
 *                             ticket ARDAABD-2101, requirements and UD Ids are
 *                             added.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements: ADC267, SWS_Adc_00267 */
/* Included for the declaration of Adc_Isr() */
#include "Adc_Private.h"
/* Included for macro definitions and structure declarations */
#include "Adc_PBTypes.h"
/* Included for the declaration of ISR prototypes */
#include "Adc_Irq.h"
/* Included for the declaration of DMA global pointer declarations */
#include "Adc_Ram.h"


/* Implements EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : Pointer to the configuration array is used and its size is */
/*                 known before applying the indexing and is verified before  */
/*                 accessing the value.                                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-1 and                           */
/*                 END Msg(4:0491)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ADC_IRQ_C_AR_RELEASE_MAJOR_VERSION    ADC_AR_RELEASE_MAJOR_VERSION_VALUE
#define ADC_IRQ_C_AR_RELEASE_MINOR_VERSION    ADC_AR_RELEASE_MINOR_VERSION_VALUE
#define ADC_IRQ_C_AR_RELEASE_REVISION_VERSION \
                                           ADC_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ADC_IRQ_C_SW_MAJOR_VERSION    ADC_SW_MAJOR_VERSION_VALUE
#define ADC_IRQ_C_SW_MINOR_VERSION    ADC_SW_MINOR_VERSION_VALUE

/* Implements EAAR_PN0034_FR_0055 */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ADC_IRQ_AR_RELEASE_MAJOR_VERSION != ADC_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Adc_Irq.c : Mismatch in Release Major Version"
#endif

#if (ADC_IRQ_AR_RELEASE_MINOR_VERSION != ADC_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Adc_Irq.c : Mismatch in Release Minor Version"
#endif

#if (ADC_IRQ_AR_RELEASE_REVISION_VERSION != \
                                          ADC_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Adc_Irq.c : Mismatch in Release Patch Version"
#endif

#if (ADC_IRQ_SW_MAJOR_VERSION != ADC_IRQ_C_SW_MAJOR_VERSION)
  #error "Adc_Irq.c : Mismatch in Software Major Version"
#endif

#if (ADC_IRQ_SW_MINOR_VERSION != ADC_IRQ_C_SW_MINOR_VERSION)
  #error "Adc_Irq.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : ADCn_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt Service routines for the ADC where
**                        n represents instances of the hardware unit.
**                        component.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return Parameter     : None
**
** Preconditions        : None
**
** Global Variables     : None
**
** Functions invoked    : Adc_Isr
**
** Registers Used       : WUF0, WUFC0 ADCAnECR, ADCAnDGCTL0, ADCAnDGCTL1,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR,  ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER,  ADCAnTHCR,
**                        ADCAnSGVCSPx, ADCAnSGVCEPx,  ADCAnSGSTCRx, ADCAnDIRj
**                        ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm, DSAm, DDAm,
**                        DTCm, DRSAm, DRDAm, DRTCm, DTCTm, ADCAnDRj, ADCAnVCRj
**                        ICDMAm, ICADCAnIm, ADCAnADCR, ADCAnULER
*******************************************************************************/
#if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)

#if (ADC0_SG1_ISR_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements ADC_ESDD_UD_094 */
/* Implements ADC_ESDD_UD_026 */
/* Implements AR_PN0076_NR_0021 */
/* Implements EAAR_PN0034_FR_0024, EAAR_PN0034_FR_0060 */
#if defined (Os_ADC0_SG1_CAT2_ISR) || defined (ADC0_SG1_CAT2_ISR)
ISR(ADC0_SG1_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
/* Implements ADC_ESDD_UD_093 */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC0_SG1_ISR(void)
#endif
{
  /* HW unit 0 and SGm unit 1 */
  Adc_Isr(ADC_ZERO, ADC_ZERO);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC0_SG1_ISR_API == STD_ON) */


#if (ADC0_SG2_ISR_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC0_SG2_CAT2_ISR) || defined (ADC0_SG2_CAT2_ISR)
ISR(ADC0_SG2_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC0_SG2_ISR(void)
#endif
{
  /* HW unit 0 and SGm unit 2 */
  Adc_Isr(ADC_ZERO, ADC_ONE);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC0_SG2_ISR_API == STD_ON) */


#if (ADC0_SG3_ISR_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC0_SG3_CAT2_ISR) || defined (ADC0_SG3_CAT2_ISR)
ISR(ADC0_SG3_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC0_SG3_ISR(void)
#endif
{
  /* HW unit 0 and SGm unit 3 */
  Adc_Isr(ADC_ZERO, ADC_TWO);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC0_SG3_ISR_API == STD_ON) */

  /* Implements AR_PN0076_FSR_0016 */
#if (ADC_ERROR_SUPPORT == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC0_ERR_CAT2_ISR) || defined (ADC0_ERR_CAT2_ISR)
ISR(ADC0_ERR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC0_ERR_ISR(void)
#endif
{
  /* HW unit 0 */
  Adc_ErrIsr(ADC_ZERO);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC_ERROR_SUPPORT == STD_ON) */

#if (ADC1_SG1_ISR_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC1_SG1_CAT2_ISR) || defined (ADC1_SG1_CAT2_ISR)
ISR(ADC1_SG1_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC1_SG1_ISR(void)
#endif
{
  /* HW unit 1 and SGm unit 1 */
  Adc_Isr(ADC_ONE, ADC_ZERO);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC1_SG1_ISR_API == STD_ON) */


#if (ADC1_SG2_ISR_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC1_SG2_CAT2_ISR) || defined (ADC1_SG2_CAT2_ISR)
ISR(ADC1_SG2_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC1_SG2_ISR(void)
#endif
{
  /* HW unit 1 and SGm unit 2 */
  Adc_Isr(ADC_ONE, ADC_ONE);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC1_SG2_ISR_API == STD_ON) */


#if (ADC1_SG3_ISR_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC1_SG3_CAT2_ISR) || defined (ADC1_SG3_CAT2_ISR)
ISR(ADC1_SG3_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC1_SG3_ISR(void)
#endif
{
  /* HW unit 1 and SGm unit 3 */
  Adc_Isr(ADC_ONE, ADC_TWO);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC1_SG3_ISR_API == STD_ON) */

  /* Implements AR_PN0076_FSR_0016 */
#if (ADC_ERROR_SUPPORT == STD_ON)
/* Implements AR_PN0076_FSR_0016 */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC1_ERR_CAT2_ISR) || defined (ADC1_ERR_CAT2_ISR)
ISR(ADC1_ERR_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC1_ERR_ISR(void)
#endif
{
  /* HW unit 1 */
  Adc_ErrIsr(ADC_ONE);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC_ERROR_SUPPORT == STD_ON) */

/* Implements ADC_ESDD_UD_153 */
/* Implements AR_PN0076_FR_0301 */
#if (ADC_PWSA_INT_QFULL_ISR == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWSA_QUE_CAT2_ISR) || defined (PWSA_QUE_CAT2_ISR)
ISR(PWSA_QUE_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) PWSA_QUE_ISR(void)
#endif
{
  /* HW unit 1 */
  Adc_GpQueueFullNotificationPointer();
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif /* #if (ADC_PWSA_INT_QFULL_ISR == STD_ON) */

#endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING) */

/*******************************************************************************
** Function Name        : ADC_DmaIsrn
**
** Service ID           : NA
**
** Description          : These are DMA Interrupt Service routines for the ADC
**                        where n represents DMA channel Id
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : None
**
** Functions invoked    : Adc_DmaIsr
**
** Registers Used       : ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm, DSAm, DDAm,
**                        DTCm, DRSAm, DRDAm, DRTCm, DTCTm, ADCAnADCR,
**                        ADCAnDGCTL0, ADCAnDGCTL1, ADCAnPDCTL1, ADCAnPDCTL2
**                        ADCAnSGVCSPx, ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR,
**                        ADCAnSGSTCRx, ADCAnDRj, ADCAnVCRj, ICDMAm, ICADCAnIm
*******************************************************************************/

/* Implements ADC_ESDD_UD_027 */
#if (ADC_DMA_ISR_CH00_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH00_CAT2_ISR) || defined (ADC_DMA_CH00_CAT2_ISR)
ISR(ADC_DMA_CH00_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH00_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[0], Adc_GpDmaSGUnitMapping[0]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH01_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH01_CAT2_ISR) || defined (ADC_DMA_CH01_CAT2_ISR)
ISR(ADC_DMA_CH01_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH01_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[1], Adc_GpDmaSGUnitMapping[1]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH02_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH02_CAT2_ISR) || defined (ADC_DMA_CH02_CAT2_ISR)
ISR(ADC_DMA_CH02_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH02_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[2], Adc_GpDmaSGUnitMapping[2]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH03_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH03_CAT2_ISR) || defined (ADC_DMA_CH03_CAT2_ISR)
ISR(ADC_DMA_CH03_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH03_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[3], Adc_GpDmaSGUnitMapping[3]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH04_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH04_CAT2_ISR) || defined (ADC_DMA_CH04_CAT2_ISR)
ISR(ADC_DMA_CH04_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH04_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[4], Adc_GpDmaSGUnitMapping[4]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH05_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH05_CAT2_ISR) || defined (ADC_DMA_CH05_CAT2_ISR)
ISR(ADC_DMA_CH05_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH05_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[5], Adc_GpDmaSGUnitMapping[5]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH06_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH06_CAT2_ISR) || defined (ADC_DMA_CH06_CAT2_ISR)
ISR(ADC_DMA_CH06_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH06_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[6], Adc_GpDmaSGUnitMapping[6]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH07_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH07_CAT2_ISR) || defined (ADC_DMA_CH07_CAT2_ISR)
ISR(ADC_DMA_CH07_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH07_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[7], Adc_GpDmaSGUnitMapping[7]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH08_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH08_CAT2_ISR) || defined (ADC_DMA_CH08_CAT2_ISR)
ISR(ADC_DMA_CH08_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH08_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[8], Adc_GpDmaSGUnitMapping[8]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH09_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH09_CAT2_ISR) || defined (ADC_DMA_CH09_CAT2_ISR)
ISR(ADC_DMA_CH09_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH09_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[9], Adc_GpDmaSGUnitMapping[9]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH10_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH10_CAT2_ISR) || defined (ADC_DMA_CH10_CAT2_ISR)
ISR(ADC_DMA_CH10_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH10_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[10], Adc_GpDmaSGUnitMapping[10]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH11_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH11_CAT2_ISR) || defined (ADC_DMA_CH11_CAT2_ISR)
ISR(ADC_DMA_CH11_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH11_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[11], Adc_GpDmaSGUnitMapping[11]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH12_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH12_CAT2_ISR) || defined (ADC_DMA_CH12_CAT2_ISR)
ISR(ADC_DMA_CH12_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH12_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[12], Adc_GpDmaSGUnitMapping[12]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH13_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH13_CAT2_ISR) || defined (ADC_DMA_CH13_CAT2_ISR)
ISR(ADC_DMA_CH13_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH13_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[13], Adc_GpDmaSGUnitMapping[13]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH14_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH14_CAT2_ISR) || defined (ADC_DMA_CH14_CAT2_ISR)
ISR(ADC_DMA_CH14_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH14_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[14], Adc_GpDmaSGUnitMapping[14]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH15_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH15_CAT2_ISR) || defined (ADC_DMA_CH15_CAT2_ISR)
ISR(ADC_DMA_CH15_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH15_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[15], Adc_GpDmaSGUnitMapping[15]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH16_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH16_CAT2_ISR) || defined (ADC_DMA_CH16_CAT2_ISR)
ISR(ADC_DMA_CH16_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH16_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[16], Adc_GpDmaSGUnitMapping[16]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH17_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH17_CAT2_ISR) || defined (ADC_DMA_CH17_CAT2_ISR)
ISR(ADC_DMA_CH17_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH17_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[17], Adc_GpDmaSGUnitMapping[17]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH18_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH18_CAT2_ISR) || defined (ADC_DMA_CH18_CAT2_ISR)
ISR(ADC_DMA_CH18_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH18_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[18], Adc_GpDmaSGUnitMapping[18]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH19_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH19_CAT2_ISR) || defined (ADC_DMA_CH19_CAT2_ISR)
ISR(ADC_DMA_CH19_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH19_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[19], Adc_GpDmaSGUnitMapping[19]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH20_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH20_CAT2_ISR) || defined (ADC_DMA_CH20_CAT2_ISR)
ISR(ADC_DMA_CH20_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH20_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[20], Adc_GpDmaSGUnitMapping[20]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH21_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH21_CAT2_ISR) || defined (ADC_DMA_CH21_CAT2_ISR)
ISR(ADC_DMA_CH21_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH21_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[21], Adc_GpDmaSGUnitMapping[21]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH22_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH22_CAT2_ISR) || defined (ADC_DMA_CH22_CAT2_ISR)
ISR(ADC_DMA_CH22_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH22_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[22], Adc_GpDmaSGUnitMapping[22]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH23_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH23_CAT2_ISR) || defined (ADC_DMA_CH23_CAT2_ISR)
ISR(ADC_DMA_CH23_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH23_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[23], Adc_GpDmaSGUnitMapping[23]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH24_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH24_CAT2_ISR) || defined (ADC_DMA_CH24_CAT2_ISR)
ISR(ADC_DMA_CH24_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH24_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[24], Adc_GpDmaSGUnitMapping[24]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH25_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH25_CAT2_ISR) || defined (ADC_DMA_CH25_CAT2_ISR)
ISR(ADC_DMA_CH25_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH25_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[25], Adc_GpDmaSGUnitMapping[25]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH26_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH26_CAT2_ISR) || defined (ADC_DMA_CH26_CAT2_ISR)
ISR(ADC_DMA_CH26_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH26_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[26], Adc_GpDmaSGUnitMapping[26]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH27_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH27_CAT2_ISR) || defined (ADC_DMA_CH27_CAT2_ISR)
ISR(ADC_DMA_CH27_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH27_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[27], Adc_GpDmaSGUnitMapping[27]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH28_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH28_CAT2_ISR) || defined (ADC_DMA_CH28_CAT2_ISR)
ISR(ADC_DMA_CH28_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH28_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[28], Adc_GpDmaSGUnitMapping[28]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH29_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH29_CAT2_ISR) || defined (ADC_DMA_CH29_CAT2_ISR)
ISR(ADC_DMA_CH29_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH29_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[29], Adc_GpDmaSGUnitMapping[29]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH30_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH30_CAT2_ISR) || defined (ADC_DMA_CH30_CAT2_ISR)
ISR(ADC_DMA_CH30_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH30_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[30], Adc_GpDmaSGUnitMapping[30]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH31_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH31_CAT2_ISR) || defined (ADC_DMA_CH31_CAT2_ISR)
ISR(ADC_DMA_CH31_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH31_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[31], Adc_GpDmaSGUnitMapping[31]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH32_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH32_CAT2_ISR) || defined (ADC_DMA_CH32_CAT2_ISR)
ISR(ADC_DMA_CH32_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH32_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[32], Adc_GpDmaSGUnitMapping[32]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH33_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH33_CAT2_ISR) || defined (ADC_DMA_CH33_CAT2_ISR)
ISR(ADC_DMA_CH33_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH33_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[33], Adc_GpDmaSGUnitMapping[33]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH34_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH34_CAT2_ISR) || defined (ADC_DMA_CH34_CAT2_ISR)
ISR(ADC_DMA_CH34_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH34_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[34], Adc_GpDmaSGUnitMapping[34]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH35_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH35_CAT2_ISR) || defined (ADC_DMA_CH35_CAT2_ISR)
ISR(ADC_DMA_CH35_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH35_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[35], Adc_GpDmaSGUnitMapping[35]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH36_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH36_CAT2_ISR) || defined (ADC_DMA_CH36_CAT2_ISR)
ISR(ADC_DMA_CH36_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH36_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[36], Adc_GpDmaSGUnitMapping[36]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH37_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH37_CAT2_ISR) || defined (ADC_DMA_CH37_CAT2_ISR)
ISR(ADC_DMA_CH37_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH37_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[37], Adc_GpDmaSGUnitMapping[37]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH38_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH38_CAT2_ISR) || defined (ADC_DMA_CH38_CAT2_ISR)
ISR(ADC_DMA_CH38_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH38_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[38], Adc_GpDmaSGUnitMapping[38]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH39_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH39_CAT2_ISR) || defined (ADC_DMA_CH39_CAT2_ISR)
ISR(ADC_DMA_CH39_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH39_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[39], Adc_GpDmaSGUnitMapping[39]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH40_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH40_CAT2_ISR) || defined (ADC_DMA_CH40_CAT2_ISR)
ISR(ADC_DMA_CH40_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH40_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[40], Adc_GpDmaSGUnitMapping[40]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH41_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH41_CAT2_ISR) || defined (ADC_DMA_CH41_CAT2_ISR)
ISR(ADC_DMA_CH41_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH41_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[41], Adc_GpDmaSGUnitMapping[41]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH42_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH42_CAT2_ISR) || defined (ADC_DMA_CH42_CAT2_ISR)
ISR(ADC_DMA_CH42_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH42_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[42], Adc_GpDmaSGUnitMapping[42]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH43_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH43_CAT2_ISR) || defined (ADC_DMA_CH43_CAT2_ISR)
ISR(ADC_DMA_CH43_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH43_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[43], Adc_GpDmaSGUnitMapping[43]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH44_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH44_CAT2_ISR) || defined (ADC_DMA_CH44_CAT2_ISR)
ISR(ADC_DMA_CH44_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH44_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[44], Adc_GpDmaSGUnitMapping[44]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH45_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH45_CAT2_ISR) || defined (ADC_DMA_CH45_CAT2_ISR)
ISR(ADC_DMA_CH45_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH45_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[45], Adc_GpDmaSGUnitMapping[45]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH46_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH46_CAT2_ISR) || defined (ADC_DMA_CH46_CAT2_ISR)
ISR(ADC_DMA_CH46_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH46_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[46], Adc_GpDmaSGUnitMapping[46]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH47_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH47_CAT2_ISR) || defined (ADC_DMA_CH47_CAT2_ISR)
ISR(ADC_DMA_CH47_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH47_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[47], Adc_GpDmaSGUnitMapping[47]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH48_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH48_CAT2_ISR) || defined (ADC_DMA_CH48_CAT2_ISR)
ISR(ADC_DMA_CH48_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH48_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[48], Adc_GpDmaSGUnitMapping[48]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH49_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH49_CAT2_ISR) || defined (ADC_DMA_CH49_CAT2_ISR)
ISR(ADC_DMA_CH49_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH49_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[49], Adc_GpDmaSGUnitMapping[49]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH50_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH50_CAT2_ISR) || defined (ADC_DMA_CH50_CAT2_ISR)
ISR(ADC_DMA_CH50_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH50_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[50], Adc_GpDmaSGUnitMapping[50]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif
#if (ADC_DMA_ISR_CH51_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH51_CAT2_ISR) || defined (ADC_DMA_CH51_CAT2_ISR)
ISR(ADC_DMA_CH51_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH51_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[51], Adc_GpDmaSGUnitMapping[51]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH52_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH52_CAT2_ISR) || defined (ADC_DMA_CH52_CAT2_ISR)
ISR(ADC_DMA_CH52_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH52_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[52], Adc_GpDmaSGUnitMapping[52]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH53_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH53_CAT2_ISR) || defined (ADC_DMA_CH53_CAT2_ISR)
ISR(ADC_DMA_CH53_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH53_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[53], Adc_GpDmaSGUnitMapping[53]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH54_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH54_CAT2_ISR) || defined (ADC_DMA_CH54_CAT2_ISR)
ISR(ADC_DMA_CH54_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH54_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[54], Adc_GpDmaSGUnitMapping[54]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH55_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH55_CAT2_ISR) || defined (ADC_DMA_CH55_CAT2_ISR)
ISR(ADC_DMA_CH55_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH55_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[55], Adc_GpDmaSGUnitMapping[55]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH56_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH56_CAT2_ISR) || defined (ADC_DMA_CH56_CAT2_ISR)
ISR(ADC_DMA_CH56_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH56_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[56], Adc_GpDmaSGUnitMapping[56]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH57_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH57_CAT2_ISR) || defined (ADC_DMA_CH57_CAT2_ISR)
ISR(ADC_DMA_CH57_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH57_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[57], Adc_GpDmaSGUnitMapping[57]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH58_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH58_CAT2_ISR) || defined (ADC_DMA_CH58_CAT2_ISR)
ISR(ADC_DMA_CH58_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH58_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[58], Adc_GpDmaSGUnitMapping[58]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH59_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH59_CAT2_ISR) || defined (ADC_DMA_CH59_CAT2_ISR)
ISR(ADC_DMA_CH59_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH59_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[59], Adc_GpDmaSGUnitMapping[59]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH60_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH60_CAT2_ISR) || defined (ADC_DMA_CH60_CAT2_ISR)
ISR(ADC_DMA_CH60_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH60_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[60], Adc_GpDmaSGUnitMapping[60]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH61_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH61_CAT2_ISR) || defined (ADC_DMA_CH61_CAT2_ISR)
ISR(ADC_DMA_CH61_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH61_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[61], Adc_GpDmaSGUnitMapping[61]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH62_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH62_CAT2_ISR) || defined (ADC_DMA_CH62_CAT2_ISR)
ISR(ADC_DMA_CH62_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH62_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[62], Adc_GpDmaSGUnitMapping[62]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

#if (ADC_DMA_ISR_CH63_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH63_CAT2_ISR) || defined (ADC_DMA_CH63_CAT2_ISR)
ISR(ADC_DMA_CH63_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH63_ISR(void)
#endif
{
  /* MISRA Violation: START Msg(4:0491)-1 */
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[63], Adc_GpDmaSGUnitMapping[63]);
  /* END Msg(4:0491)-1 */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
