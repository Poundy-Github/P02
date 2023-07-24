/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Irq.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISRs prototypes for all Timers of ICU Driver            */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas.            */
/* Any warranty is expressly disclaimed and excluded by Renesas, either       */
/* expressed or implied, including but not limited to those for               */
/* non-infringement of intellectual property, merchantability                 */
/* and/or fitness for the particular purpose                                  */
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
 * V1.0.0:  16-Sep-2015  : Initial Version.
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  06-Jun-2017  : Following changes are made:
 *                         1. As part of Jira #ARDAABD-1373, Additional timer
 *                            interrupts and external interrupts are added and
 *                            TAUD1 and TAUD2 interrupts have been removed for
 *                            F1KM support.
 * V2.0.2:  11-Jul-2018  : Following changes are made:
 *                         2. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 *                         3. Copyright information is updated.
 */
/******************************************************************************/
#ifndef ICU_IRQ_H
#define ICU_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for interrupt category definitions */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ICU_IRQ_AR_RELEASE_MAJOR_VERSION     ICU_AR_RELEASE_MAJOR_VERSION
#define ICU_IRQ_AR_RELEASE_MINOR_VERSION     ICU_AR_RELEASE_MINOR_VERSION
#define ICU_IRQ_AR_RELEASE_REVISION_VERSION  ICU_AR_RELEASE_REVISION_VERSION

/* File version information */
#define ICU_IRQ_SW_MAJOR_VERSION    ICU_SW_MAJOR_VERSION
#define ICU_IRQ_SW_MINOR_VERSION    ICU_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/******************************************************************************
**                      Global Data Types                                    **
******************************************************************************/

/******************************************************************************
**                      Function Prototypes                                  **
******************************************************************************/

#define ICU_START_SEC_CODE_FAST
#include ICU_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH00_CAT2_ISR) || defined (EXT_INTP_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH01_CAT2_ISR) || defined (EXT_INTP_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH02_CAT2_ISR) || defined (EXT_INTP_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH03_CAT2_ISR) || defined (EXT_INTP_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH04_CAT2_ISR) || defined (EXT_INTP_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH05_CAT2_ISR) || defined (EXT_INTP_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH06_CAT2_ISR) || defined (EXT_INTP_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH07_CAT2_ISR) || defined (EXT_INTP_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH08_CAT2_ISR) || defined (EXT_INTP_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH09_CAT2_ISR) || defined (EXT_INTP_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH10_CAT2_ISR) || defined (EXT_INTP_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH11_CAT2_ISR) || defined (EXT_INTP_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH12_CAT2_ISR) || defined (EXT_INTP_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH13_CAT2_ISR) || defined (EXT_INTP_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH14_CAT2_ISR) || defined (EXT_INTP_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH15_CAT2_ISR) || defined (EXT_INTP_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH16_CAT2_ISR) || defined (EXT_INTP_CH16_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH16_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH17_CAT2_ISR) || defined (EXT_INTP_CH17_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH17_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH18_CAT2_ISR) || defined (EXT_INTP_CH18_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH18_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH19_CAT2_ISR) || defined (EXT_INTP_CH19_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH19_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH20_CAT2_ISR) || defined (EXT_INTP_CH20_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH20_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH21_CAT2_ISR) || defined (EXT_INTP_CH21_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH21_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH22_CAT2_ISR) || defined (EXT_INTP_CH22_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH22_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_EXT_INTP_CH23_CAT2_ISR) || defined (EXT_INTP_CH23_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) EXT_INTP_CH23_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH00_CAT2_ISR) || defined (TAUD0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH01_CAT2_ISR) || defined (TAUD0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH02_CAT2_ISR) || defined (TAUD0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH03_CAT2_ISR) || defined (TAUD0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH04_CAT2_ISR) || defined (TAUD0_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH05_CAT2_ISR) || defined (TAUD0_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH06_CAT2_ISR) || defined (TAUD0_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH07_CAT2_ISR) || defined (TAUD0_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH08_CAT2_ISR) || defined (TAUD0_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH09_CAT2_ISR) || defined (TAUD0_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH10_CAT2_ISR) || defined (TAUD0_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH11_CAT2_ISR) || defined (TAUD0_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH12_CAT2_ISR) || defined (TAUD0_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH13_CAT2_ISR) || defined (TAUD0_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH14_CAT2_ISR) || defined (TAUD0_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH15_CAT2_ISR) || defined (TAUD0_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUD0_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH00_CAT2_ISR) || defined (TAUB0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH01_CAT2_ISR) || defined (TAUB0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH02_CAT2_ISR) || defined (TAUB0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH03_CAT2_ISR) || defined (TAUB0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH04_CAT2_ISR) || defined (TAUB0_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH05_CAT2_ISR) || defined (TAUB0_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH06_CAT2_ISR) || defined (TAUB0_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH07_CAT2_ISR) || defined (TAUB0_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH08_CAT2_ISR) || defined (TAUB0_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH09_CAT2_ISR) || defined (TAUB0_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH10_CAT2_ISR) || defined (TAUB0_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH11_CAT2_ISR) || defined (TAUB0_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH12_CAT2_ISR) || defined (TAUB0_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH13_CAT2_ISR) || defined (TAUB0_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH14_CAT2_ISR) || defined (TAUB0_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH15_CAT2_ISR) || defined (TAUB0_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB0_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH00_CAT2_ISR) || defined (TAUB1_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH01_CAT2_ISR) || defined (TAUB1_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH02_CAT2_ISR) || defined (TAUB1_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH03_CAT2_ISR) || defined (TAUB1_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH04_CAT2_ISR) || defined (TAUB1_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH05_CAT2_ISR) || defined (TAUB1_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH06_CAT2_ISR) || defined (TAUB1_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH07_CAT2_ISR) || defined (TAUB1_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH08_CAT2_ISR) || defined (TAUB1_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH09_CAT2_ISR) || defined (TAUB1_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH10_CAT2_ISR) || defined (TAUB1_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH11_CAT2_ISR) || defined (TAUB1_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH12_CAT2_ISR) || defined (TAUB1_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH13_CAT2_ISR) || defined (TAUB1_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH14_CAT2_ISR) || defined (TAUB1_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH15_CAT2_ISR) || defined (TAUB1_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUB1_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH00_CAT2_ISR) || defined (TAUJ0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH01_CAT2_ISR) || defined (TAUJ0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH02_CAT2_ISR) || defined (TAUJ0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH03_CAT2_ISR) || defined (TAUJ0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH00_CAT2_ISR) || defined (TAUJ1_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ1_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH01_CAT2_ISR) || defined (TAUJ1_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ1_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH02_CAT2_ISR) || defined (TAUJ1_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ1_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH03_CAT2_ISR) || defined (TAUJ1_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ1_CH03_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH00_CAT2_ISR) || defined (TAUJ2_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ2_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH01_CAT2_ISR) || defined (TAUJ2_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ2_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH02_CAT2_ISR) || defined (TAUJ2_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ2_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH03_CAT2_ISR) || defined (TAUJ2_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ2_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH00_CAT2_ISR) || defined (TAUJ3_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ3_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH01_CAT2_ISR) || defined (TAUJ3_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ3_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH02_CAT2_ISR) || defined (TAUJ3_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ3_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH03_CAT2_ISR) || defined (TAUJ3_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, ICU_FAST_CODE) TAUJ3_CH03_ISR(void);
#endif

#define ICU_STOP_SEC_CODE_FAST
#include ICU_MEMMAP_FILE
#endif  /* ICU_IRQ_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
