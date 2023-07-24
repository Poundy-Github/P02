/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Irq.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISRs prototypes for all Timers of ADC Driver            */
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

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V2.0.0:  28-Oct-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.1.0   16-Nov-2016    : The following changes are made:
 *                           1. As part of JIRA ticket ARDAABC-909
 *                              removed the ADC0_SG0, ADC1_SG0, ADC0_SG4 and
 *                              ADC1_SG4 interrupts.
 * V2.2.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage
 * V2.2.1:  27-Jun-2018     : Following change is made:
 *                            1.As part of merging activity ticket ARDAABD-3452,
 *                              a.Heading for MISRA rule violations is
 *                                corrected.
 *                              b.Copyright updated.
 *                            2.As part of merging activity ticket ARDAABD-3453,
 *                              a. DMA channel mappings are added.
 *                              Ref: ARDAABD-3114
 *                            3.As part of traceability improvement activity
 *                              ticket ARDAABD-2101, requirements and UD Ids
 *                              are added.
 */
/******************************************************************************/
/* ADC_IRQ_H_002: EAAR_PN0034_FR_0001 */
#ifndef ADC_IRQ_H
#define ADC_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* ADC_IRQ_H_003: ADC267, SWS_Adc_00267 */
/* ADC_IRQ_H_001: EAAR_PN0034_FR_0024 */
/* Included for interrupt category definitions */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ADC_IRQ_AR_RELEASE_MAJOR_VERSION      ADC_TYPES_AR_RELEASE_MAJOR_VERSION
#define ADC_IRQ_AR_RELEASE_MINOR_VERSION      ADC_TYPES_AR_RELEASE_MINOR_VERSION
#define ADC_IRQ_AR_RELEASE_REVISION_VERSION   \
                                           ADC_TYPES_AR_RELEASE_REVISION_VERSION

/* File version information */
#define ADC_IRQ_SW_MAJOR_VERSION    ADC_TYPES_SW_MAJOR_VERSION
#define ADC_IRQ_SW_MINOR_VERSION    ADC_TYPES_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (6:0857)Number of macro definitions exceeds 1024 - program */
/*                 does not conform strictly to ISO:C99.                      */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(6:0857)-1 and                           */
/*                 END Msg(6:0857)-1 tags in the code.                        */
/******************************************************************************
**                      Global Data Types                                    **
******************************************************************************/

/******************************************************************************
**                      Function Prototypes                                  **
******************************************************************************/

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC0_SG1_CAT2_ISR) || defined (ADC0_SG1_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC0_SG1_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC0_SG2_CAT2_ISR) || defined (ADC0_SG2_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC0_SG2_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC0_SG3_CAT2_ISR) || defined (ADC0_SG3_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC0_SG3_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC0_ERR_CAT2_ISR) || defined (ADC0_ERR_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC0_ERR_ISR(void);
#endif

#if ( ADC_PWSA_INT_QFULL_ISR == STD_ON )
/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWSA_QUE_CAT2_ISR) || defined (PWSA_QUE_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) PWSA_QUE_ISR(void);
#endif
#endif /* #if ( ADC_PWSA_INT_QFULL_ISR == STD_ON ) */
/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC1_SG1_CAT2_ISR) || defined (ADC1_SG1_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC1_SG1_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC1_SG2_CAT2_ISR) || defined (ADC1_SG2_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC1_SG2_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC1_SG3_CAT2_ISR) || defined (ADC1_SG3_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC1_SG3_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC1_ERR_CAT2_ISR) || defined (ADC1_ERR_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC1_ERR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH00_CAT2_ISR) || defined (ADC_DMA_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH00_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH01_CAT2_ISR) || defined (ADC_DMA_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH01_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH02_CAT2_ISR) || defined (ADC_DMA_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH02_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH03_CAT2_ISR) || defined (ADC_DMA_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH03_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH04_CAT2_ISR) || defined (ADC_DMA_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH04_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH05_CAT2_ISR) || defined (ADC_DMA_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH05_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH06_CAT2_ISR) || defined (ADC_DMA_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH06_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH07_CAT2_ISR) || defined (ADC_DMA_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH07_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH08_CAT2_ISR) || defined (ADC_DMA_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH08_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH09_CAT2_ISR) || defined (ADC_DMA_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH09_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH10_CAT2_ISR) || defined (ADC_DMA_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH10_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH11_CAT2_ISR) || defined (ADC_DMA_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH11_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH12_CAT2_ISR) || defined (ADC_DMA_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH12_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH13_CAT2_ISR) || defined (ADC_DMA_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH13_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH14_CAT2_ISR) || defined (ADC_DMA_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH14_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH15_CAT2_ISR) || defined (ADC_DMA_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH15_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH16_CAT2_ISR) || defined (ADC_DMA_CH16_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH16_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH17_CAT2_ISR) || defined (ADC_DMA_CH17_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH17_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH18_CAT2_ISR) || defined (ADC_DMA_CH18_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH18_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH19_CAT2_ISR) || defined (ADC_DMA_CH19_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH19_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH20_CAT2_ISR) || defined (ADC_DMA_CH20_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH20_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH21_CAT2_ISR) || defined (ADC_DMA_CH21_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH21_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH22_CAT2_ISR) || defined (ADC_DMA_CH22_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH22_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH23_CAT2_ISR) || defined (ADC_DMA_CH23_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH23_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH24_CAT2_ISR) || defined (ADC_DMA_CH24_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH24_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH25_CAT2_ISR) || defined (ADC_DMA_CH25_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH25_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH26_CAT2_ISR) || defined (ADC_DMA_CH26_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH26_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH27_CAT2_ISR) || defined (ADC_DMA_CH27_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH27_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH28_CAT2_ISR) || defined (ADC_DMA_CH28_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH28_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH29_CAT2_ISR) || defined (ADC_DMA_CH29_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH29_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH30_CAT2_ISR) || defined (ADC_DMA_CH30_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH30_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH31_CAT2_ISR) || defined (ADC_DMA_CH31_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH31_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH32_CAT2_ISR) || defined (ADC_DMA_CH32_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH32_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH33_CAT2_ISR) || defined (ADC_DMA_CH33_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH33_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH34_CAT2_ISR) || defined (ADC_DMA_CH34_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH34_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH35_CAT2_ISR) || defined (ADC_DMA_CH35_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH35_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH36_CAT2_ISR) || defined (ADC_DMA_CH36_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH36_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH37_CAT2_ISR) || defined (ADC_DMA_CH37_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH37_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH38_CAT2_ISR) || defined (ADC_DMA_CH38_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH38_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH39_CAT2_ISR) || defined (ADC_DMA_CH39_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH39_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH40_CAT2_ISR) || defined (ADC_DMA_CH40_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH40_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH41_CAT2_ISR) || defined (ADC_DMA_CH41_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH41_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH42_CAT2_ISR) || defined (ADC_DMA_CH42_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH42_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH43_CAT2_ISR) || defined (ADC_DMA_CH43_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH43_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH44_CAT2_ISR) || defined (ADC_DMA_CH44_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH44_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH45_CAT2_ISR) || defined (ADC_DMA_CH45_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH45_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH46_CAT2_ISR) || defined (ADC_DMA_CH46_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH46_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH47_CAT2_ISR) || defined (ADC_DMA_CH47_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH47_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH48_CAT2_ISR) || defined (ADC_DMA_CH48_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH48_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH49_CAT2_ISR) || defined (ADC_DMA_CH49_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH49_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH50_CAT2_ISR) || defined (ADC_DMA_CH50_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH50_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH51_CAT2_ISR) || defined (ADC_DMA_CH51_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH51_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH52_CAT2_ISR) || defined (ADC_DMA_CH52_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH52_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH53_CAT2_ISR) || defined (ADC_DMA_CH53_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH53_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH54_CAT2_ISR) || defined (ADC_DMA_CH54_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH54_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH55_CAT2_ISR) || defined (ADC_DMA_CH55_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH55_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH56_CAT2_ISR) || defined (ADC_DMA_CH56_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH56_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH57_CAT2_ISR) || defined (ADC_DMA_CH57_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH57_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH58_CAT2_ISR) || defined (ADC_DMA_CH58_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH58_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH59_CAT2_ISR) || defined (ADC_DMA_CH59_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH59_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH60_CAT2_ISR) || defined (ADC_DMA_CH60_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH60_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH61_CAT2_ISR) || defined (ADC_DMA_CH61_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH61_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH62_CAT2_ISR) || defined (ADC_DMA_CH62_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH62_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_ADC_DMA_CH63_CAT2_ISR) || defined (ADC_DMA_CH63_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ADC_FAST_CODE) ADC_DMA_CH63_ISR(void);
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* ADC_IRQ_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
