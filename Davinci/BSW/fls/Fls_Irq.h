/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Irq.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision for prototypes of Interrupt Service Routines.                    */
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
 * V1.0.0:  08-Oct-2015  : Initial Version
 *
 * V1.1.0:  28-Sep-2016  :  #ARDAABD-843
 *                          1. Removed support for
 *                             FLS_AR_HIGHER_VERSION / FLS_AR_LOWER_VERSION
 * V2.0.0:  11-Nov-2016  : #ARDAABD-732 - Added interrupt mapping for DMA ISRs
 * V2.0.1:  02-Oct-2017  : #ARDAABD-2489 Support is added for DMA interrupts of
 *                         F1KM-S4 devices.
 * V2.0.2:  17-Apr-2018  : Following changes were made:
 *                         1. As per merging activity, #ARDAABD-3466
 *                            below changes were made (Ref:ARDAABD-3257):
 *                          a. Support is added for DMA interrupts of
 *                             F1KH devices.
 *                          b. Copyright information is updated.
 */
/******************************************************************************/
#ifndef FLS_IRQ_H
#define FLS_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fls_Ram.h"
#include "Fls_Types.h"
/* Included for interrupt category definitions */
#include "Os.h"
/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* AUTOSAR Release version information */
#define FLS_IRQ_AR_RELEASE_MAJOR_VERSION        FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_IRQ_AR_RELEASE_MINOR_VERSION        FLS_AR_RELEASE_MINOR_VERSION
#define FLS_IRQ_AR_RELEASE_REVISION_VERSION     FLS_AR_RELEASE_REVISION_VERSION


/* File version information */
#define FLS_IRQ_SW_MAJOR_VERSION                FLS_SW_MAJOR_VERSION
#define FLS_IRQ_SW_MINOR_VERSION                FLS_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define FLS_START_SEC_CODE_FAST
#include FLS_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_FLENDNM_CAT2_ISR) || defined (FLS_FLENDNM_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_FLENDNM_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA00_CAT2_ISR) || defined (FLS_DMA00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA00_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA01_CAT2_ISR) || defined (FLS_DMA01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA01_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA02_CAT2_ISR) || defined (FLS_DMA02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA02_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA03_CAT2_ISR) || defined (FLS_DMA03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA03_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA04_CAT2_ISR) || defined (FLS_DMA04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA04_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA05_CAT2_ISR) || defined (FLS_DMA05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA05_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA06_CAT2_ISR) || defined (FLS_DMA06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA06_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA07_CAT2_ISR) || defined (FLS_DMA07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA07_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA08_CAT2_ISR) || defined (FLS_DMA08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA08_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA09_CAT2_ISR) || defined (FLS_DMA09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA09_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA10_CAT2_ISR) || defined (FLS_DMA10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA10_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA11_CAT2_ISR) || defined (FLS_DMA11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA11_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA12_CAT2_ISR) || defined (FLS_DMA12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA12_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA13_CAT2_ISR) || defined (FLS_DMA13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA13_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA14_CAT2_ISR) ||  defined (FLS_DMA14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA14_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA15_CAT2_ISR) || defined (FLS_DMA15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA15_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA16_CAT2_ISR) || defined (FLS_DMA16_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA16_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA17_CAT2_ISR) || defined (FLS_DMA17_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA17_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA18_CAT2_ISR) || defined (FLS_DMA18_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA18_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA19_CAT2_ISR) || defined (FLS_DMA19_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA19_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA20_CAT2_ISR) || defined (FLS_DMA20_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA20_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA21_CAT2_ISR) || defined (FLS_DMA21_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA21_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA22_CAT2_ISR) || defined (FLS_DMA22_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA22_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA23_CAT2_ISR) || defined (FLS_DMA23_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA23_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA24_CAT2_ISR) || defined (FLS_DMA24_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA24_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA25_CAT2_ISR) || defined (FLS_DMA25_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA25_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA26_CAT2_ISR) || defined (FLS_DMA26_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA26_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA27_CAT2_ISR) || defined (FLS_DMA27_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA27_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA28_CAT2_ISR) || defined (FLS_DMA28_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA28_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA29_CAT2_ISR) || defined (FLS_DMA29_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA29_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA30_CAT2_ISR) || defined (FLS_DMA30_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA30_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA31_CAT2_ISR) || defined (FLS_DMA31_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA31_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA32_CAT2_ISR) || defined (FLS_DMA32_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA32_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA33_CAT2_ISR) || defined (FLS_DMA33_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA33_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA34_CAT2_ISR) || defined (FLS_DMA34_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA34_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA35_CAT2_ISR) || defined (FLS_DMA35_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA35_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA36_CAT2_ISR) || defined (FLS_DMA36_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA36_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA37_CAT2_ISR) || defined (FLS_DMA37_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA37_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA38_CAT2_ISR) || defined (FLS_DMA38_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA38_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA39_CAT2_ISR) || defined (FLS_DMA39_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA39_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA40_CAT2_ISR) || defined (FLS_DMA40_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA40_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA41_CAT2_ISR) || defined (FLS_DMA41_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA41_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA42_CAT2_ISR) || defined (FLS_DMA42_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA42_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA43_CAT2_ISR) || defined (FLS_DMA43_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA43_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA44_CAT2_ISR) || defined (FLS_DMA44_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA44_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA45_CAT2_ISR) || defined (FLS_DMA45_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA45_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA46_CAT2_ISR) ||  defined (FLS_DMA46_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA46_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA47_CAT2_ISR) || defined (FLS_DMA47_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA47_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA48_CAT2_ISR) || defined (FLS_DMA48_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA48_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA49_CAT2_ISR) || defined (FLS_DMA49_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA49_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA50_CAT2_ISR) || defined (FLS_DMA50_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA50_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA51_CAT2_ISR) || defined (FLS_DMA51_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA51_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA52_CAT2_ISR) || defined (FLS_DMA52_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA52_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA53_CAT2_ISR) || defined (FLS_DMA53_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA53_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA54_CAT2_ISR) || defined (FLS_DMA54_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA54_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA55_CAT2_ISR) || defined (FLS_DMA55_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA55_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA56_CAT2_ISR) || defined (FLS_DMA56_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA56_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA57_CAT2_ISR) || defined (FLS_DMA57_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA57_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA58_CAT2_ISR) || defined (FLS_DMA58_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA58_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA59_CAT2_ISR) || defined (FLS_DMA59_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA59_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA60_CAT2_ISR) || defined (FLS_DMA60_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA60_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA61_CAT2_ISR) || defined (FLS_DMA61_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA61_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA62_CAT2_ISR) || defined (FLS_DMA62_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA62_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_DMA63_CAT2_ISR) || defined (FLS_DMA63_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_DMA63_ISR(void);
#endif

#define FLS_STOP_SEC_CODE_FAST
#include FLS_MEMMAP_FILE

#endif  /* FLS_IRQ_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
