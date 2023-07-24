/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Irq.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISRs for all Timers of GPT Driver                       */
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

/*******************************************************************************
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  17-Sep-2015    : Initial Version
 * V2.0.0:  28-Oct-2016    : Added support for FE level interrupts in order to
 *                            be able to use OSTM channels 1-4 as part of
 *                           ARDAABC-875
 *
 * V2.1.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 *
 * V2.1.1:  25-May-2017    : Added ISRs for TAUJ3 to add F1KM Device support
 *                           and copyright year updated as part of JIRA
 *                           ARDAABD-1883.
 *
 * V2.1.2:  18-Sep-2017    : Following changes are made:
 *                           1. As part of JIRA ARDAABD-2305, ISR for for new
 *                              OSTM timer unit added.
 *                           2. As per ARDAABD-2425, QAC level 2 warning
 *                              Justification tags are added.
 * V2.1.3:  27-Apr-2018    : Following changes were made:
 *                           1. As part of ARDAABD-2986, Statement
 *                             'ISR(GPT_FEINT_CAT2_ISR)' is removed.
 *                           2. Copyright information updated.
 */
/******************************************************************************/

/******************************************************************************/
#ifndef GPT_IRQ_H
#define GPT_IRQ_H
/* GPT_IRQ_H_001: EAAR_PN0034_FR_0001 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* GPT_IRQ_H_003: EAAR_PN0034_FR_0024 */
/* Included for interrupt category definitions */
#include "Os.h"
/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* GPT_IRQ_H_002: EAAR_PN0034_FR_0055 */
/* AUTOSAR release version information */
#define GPT_IRQ_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION
#define GPT_IRQ_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION
#define GPT_IRQ_AR_RELEASE_REVISION_VERSION \
    GPT_AR_RELEASE_REVISION_VERSION


/* File version information */
#define GPT_IRQ_SW_MAJOR_VERSION    GPT_SW_MAJOR_VERSION
#define GPT_IRQ_SW_MINOR_VERSION    GPT_SW_MINOR_VERSION

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/

/*******************************************************************************
 **                      Global Data Types                                    **
 ******************************************************************************/

/*******************************************************************************
 **                         QAC Warning                                       **
 ******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : None                                                       */
/* Justification : These Macro substitution is required to optimize MemMap    */
/*                 inclusion.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/

/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_FAST_ASIL_B
#else
  #define GPT_START_SEC_CODE_FAST
#endif
#include GPT_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_OSTM0_CH00_CAT2_ISR) || defined (OSTM0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) OSTM0_CH00_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_OSTM5_CH00_CAT2_ISR) || defined (OSTM5_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) OSTM5_CH00_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined  (Os_GPT_FEINT_CAT2_ISR) || defined (GPT_FEINT_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
FUNC(void, GPT_FAST_CODE) GPT_FEINT_ISR(void);
#endif /* defined  (Os_GPT_FEINT_CAT2_ISR) || defined (GPT_FEINT_CAT2_ISR) */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH00_CAT2_ISR) || defined (TAUD0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH01_CAT2_ISR) || defined (TAUD0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH02_CAT2_ISR) || defined (TAUD0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH03_CAT2_ISR) || defined (TAUD0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH04_CAT2_ISR) || defined (TAUD0_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH05_CAT2_ISR) || defined (TAUD0_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH06_CAT2_ISR) || defined (TAUD0_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH07_CAT2_ISR) || defined (TAUD0_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH08_CAT2_ISR) || defined (TAUD0_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH09_CAT2_ISR) || defined (TAUD0_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH10_CAT2_ISR) || defined (TAUD0_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH11_CAT2_ISR) || defined (TAUD0_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH12_CAT2_ISR) || defined (TAUD0_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH13_CAT2_ISR) || defined (TAUD0_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH14_CAT2_ISR) || defined (TAUD0_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH15_CAT2_ISR) || defined (TAUD0_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD0_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH00_CAT2_ISR) || defined (TAUD1_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH01_CAT2_ISR) || defined (TAUD1_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH02_CAT2_ISR) || defined (TAUD1_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH03_CAT2_ISR) || defined (TAUD1_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH04_CAT2_ISR) || defined (TAUD1_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH05_CAT2_ISR) || defined (TAUD1_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH06_CAT2_ISR) || defined (TAUD1_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH07_CAT2_ISR) || defined (TAUD1_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH08_CAT2_ISR) || defined (TAUD1_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH09_CAT2_ISR) || defined (TAUD1_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH10_CAT2_ISR) || defined (TAUD1_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH11_CAT2_ISR) || defined (TAUD1_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH12_CAT2_ISR) || defined (TAUD1_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH13_CAT2_ISR) || defined (TAUD1_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH14_CAT2_ISR) || defined (TAUD1_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH15_CAT2_ISR) || defined (TAUD1_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD1_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH00_CAT2_ISR) || defined (TAUD2_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH01_CAT2_ISR) || defined (TAUD2_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH02_CAT2_ISR) || defined (TAUD2_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH03_CAT2_ISR) || defined (TAUD2_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH04_CAT2_ISR) || defined (TAUD2_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH05_CAT2_ISR) || defined (TAUD2_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH06_CAT2_ISR) || defined (TAUD2_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH07_CAT2_ISR) || defined (TAUD2_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH08_CAT2_ISR) || defined (TAUD2_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH09_CAT2_ISR) || defined (TAUD2_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH10_CAT2_ISR) || defined (TAUD2_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH11_CAT2_ISR) || defined (TAUD2_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH12_CAT2_ISR) || defined (TAUD2_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH13_CAT2_ISR) || defined (TAUD2_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH14_CAT2_ISR) || defined (TAUD2_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH15_CAT2_ISR) || defined (TAUD2_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUD2_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH00_CAT2_ISR) || defined (TAUB0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH01_CAT2_ISR) || defined (TAUB0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH02_CAT2_ISR) || defined (TAUB0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH03_CAT2_ISR) || defined (TAUB0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH04_CAT2_ISR) || defined (TAUB0_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH05_CAT2_ISR) || defined (TAUB0_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH06_CAT2_ISR) || defined (TAUB0_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH07_CAT2_ISR) || defined (TAUB0_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH08_CAT2_ISR) || defined (TAUB0_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH09_CAT2_ISR) || defined (TAUB0_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH10_CAT2_ISR) || defined (TAUB0_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH11_CAT2_ISR) || defined (TAUB0_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH12_CAT2_ISR) || defined (TAUB0_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH13_CAT2_ISR) || defined (TAUB0_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH14_CAT2_ISR) || defined (TAUB0_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH15_CAT2_ISR) || defined (TAUB0_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB0_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH00_CAT2_ISR) || defined (TAUB1_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH01_CAT2_ISR) || defined (TAUB1_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH02_CAT2_ISR) || defined (TAUB1_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH03_CAT2_ISR) || defined (TAUB1_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH04_CAT2_ISR) || defined (TAUB1_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH05_CAT2_ISR) || defined (TAUB1_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH06_CAT2_ISR) || defined (TAUB1_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH07_CAT2_ISR) || defined (TAUB1_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH08_CAT2_ISR) || defined (TAUB1_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH09_CAT2_ISR) || defined (TAUB1_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH10_CAT2_ISR) || defined (TAUB1_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH11_CAT2_ISR) || defined (TAUB1_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH12_CAT2_ISR) || defined (TAUB1_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH13_CAT2_ISR) || defined (TAUB1_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH14_CAT2_ISR) || defined (TAUB1_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH15_CAT2_ISR) || defined (TAUB1_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUB1_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH00_CAT2_ISR) || defined (TAUJ0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH01_CAT2_ISR) || defined (TAUJ0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH02_CAT2_ISR) || defined (TAUJ0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH03_CAT2_ISR) || defined (TAUJ0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH00_CAT2_ISR) || defined (TAUJ1_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ1_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH01_CAT2_ISR) || defined (TAUJ1_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ1_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH02_CAT2_ISR) || defined (TAUJ1_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ1_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH03_CAT2_ISR) || defined (TAUJ1_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ1_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH00_CAT2_ISR) || defined (TAUJ2_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ2_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH01_CAT2_ISR) || defined (TAUJ2_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ2_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH02_CAT2_ISR) || defined (TAUJ2_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ2_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH03_CAT2_ISR) || defined (TAUJ2_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ2_CH03_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH00_CAT2_ISR) || defined (TAUJ3_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ3_CH00_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH01_CAT2_ISR) || defined (TAUJ3_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ3_CH01_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH02_CAT2_ISR) || defined (TAUJ3_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ3_CH02_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH03_CAT2_ISR) || defined (TAUJ3_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_FAST_CODE) TAUJ3_CH03_ISR(void);
#endif

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define GPT_STOP_SEC_CODE_FAST
#endif
#include GPT_MEMMAP_FILE
#endif  /* GPT_IRQ_H */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
