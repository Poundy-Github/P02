/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Irq.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISRs prototypes for all Timers of PWM Driver            */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Sep-2015  : Initial Version
 * V2.0.0:  19-Oct-2016  : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                            ASR 4.0.3.
 * V2.0.1:  19-May-2017  : 1. As part of JIRA ARDAABD-1726, added ISRs for
 *                            TAUJ3.
 *                         2. Updated Copyright(c)
 * V2.1.0:  12-Jul-2017  : As part of JIRA ARDAABD-1726, added ISRs
 *                         PWM_INTPWGAG0m_ISR (where m=0,1,2) for PWM Diag
 *                         channel groups.
 * V2.1.1:  15-Jun-2018  : As part of JIRA ARDAABD-3839, following changes are
 *                         made:
 *                         1. Added PWM_IRQ_H_001 to PWM_IRQ_H_005.
 *                         2. Updated Copyright(c) information.
 */
/******************************************************************************/
/* PWM_IRQ_H_005: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045                    */
/* PWM_IRQ_H_003: EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0018                    */
#ifndef PWM_IRQ_H
#define PWM_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* PWM_IRQ_H_004: EAAR_PN0034_FR_0024                                         */
/* Included for interrupt category definitions */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* PWM_IRQ_H_001:  PWM_ESDD_UD_128, EAAR_PN0066_FR_0045                       */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_IRQ_AR_RELEASE_MAJOR_VERSION    PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_IRQ_AR_RELEASE_MINOR_VERSION    PWM_AR_RELEASE_MINOR_VERSION
#define PWM_IRQ_AR_RELEASE_REVISION_VERSION PWM_AR_RELEASE_REVISION_VERSION

/* PWM_IRQ_H_002:  PWM_ESDD_UD_129, EAAR_PN0066_FR_0045                       */
#elif (PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_IRQ_AR_RELEASE_MAJOR_VERSION    PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_IRQ_AR_RELEASE_MINOR_VERSION    PWM_AR_RELEASE_MINOR_VERSION
#define PWM_IRQ_AR_RELEASE_REVISION_VERSION PWM_AR_RELEASE_REVISION_VERSION
#endif /* End of PWM_AR_VERSION */

/* Module software version information */
#define PWM_IRQ_SW_MAJOR_VERSION    PWM_SW_MAJOR_VERSION
#define PWM_IRQ_SW_MINOR_VERSION    PWM_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define PWM_START_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH00_CAT2_ISR) || defined (TAUD0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH01_CAT2_ISR) || defined (TAUD0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH02_CAT2_ISR) || defined (TAUD0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH03_CAT2_ISR) || defined (TAUD0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH04_CAT2_ISR) || defined (TAUD0_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH05_CAT2_ISR) || defined (TAUD0_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH06_CAT2_ISR) || defined (TAUD0_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH07_CAT2_ISR) || defined (TAUD0_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH08_CAT2_ISR) || defined (TAUD0_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH09_CAT2_ISR) || defined (TAUD0_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH10_CAT2_ISR) || defined (TAUD0_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH11_CAT2_ISR) || defined (TAUD0_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH12_CAT2_ISR) || defined (TAUD0_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH13_CAT2_ISR) || defined (TAUD0_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH14_CAT2_ISR) || defined (TAUD0_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD0_CH15_CAT2_ISR) || defined (TAUD0_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD0_CH15_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH00_CAT2_ISR) || defined (TAUD1_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH01_CAT2_ISR) || defined (TAUD1_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH02_CAT2_ISR) || defined (TAUD1_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH03_CAT2_ISR) || defined (TAUD1_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH04_CAT2_ISR) || defined (TAUD1_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH05_CAT2_ISR) || defined (TAUD1_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH06_CAT2_ISR) || defined (TAUD1_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH07_CAT2_ISR) || defined (TAUD1_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH08_CAT2_ISR) || defined (TAUD1_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH09_CAT2_ISR) || defined (TAUD1_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH10_CAT2_ISR) || defined (TAUD1_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH11_CAT2_ISR) || defined (TAUD1_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH12_CAT2_ISR) || defined (TAUD1_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH13_CAT2_ISR) || defined (TAUD1_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH14_CAT2_ISR) || defined (TAUD1_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD1_CH15_CAT2_ISR) || defined (TAUD1_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD1_CH15_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH00_CAT2_ISR) || defined (TAUD2_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH01_CAT2_ISR) || defined (TAUD2_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH02_CAT2_ISR) || defined (TAUD2_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH03_CAT2_ISR) || defined (TAUD2_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH04_CAT2_ISR) || defined (TAUD2_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH05_CAT2_ISR) || defined (TAUD2_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH06_CAT2_ISR) || defined (TAUD2_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH07_CAT2_ISR) || defined (TAUD2_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH08_CAT2_ISR) || defined (TAUD2_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH09_CAT2_ISR) || defined (TAUD2_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH10_CAT2_ISR) || defined (TAUD2_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH11_CAT2_ISR) || defined (TAUD2_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH12_CAT2_ISR) || defined (TAUD2_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH13_CAT2_ISR) || defined (TAUD2_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH14_CAT2_ISR) || defined (TAUD2_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUD2_CH15_CAT2_ISR) || defined (TAUD2_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUD2_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH00_CAT2_ISR) || defined (TAUB0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH01_CAT2_ISR) || defined (TAUB0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH02_CAT2_ISR) || defined (TAUB0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH03_CAT2_ISR) || defined (TAUB0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH04_CAT2_ISR) || defined (TAUB0_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH05_CAT2_ISR) || defined (TAUB0_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH06_CAT2_ISR) || defined (TAUB0_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH07_CAT2_ISR) || defined (TAUB0_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH08_CAT2_ISR) || defined (TAUB0_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH09_CAT2_ISR) || defined (TAUB0_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH10_CAT2_ISR) || defined (TAUB0_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH11_CAT2_ISR) || defined (TAUB0_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH12_CAT2_ISR) || defined (TAUB0_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH13_CAT2_ISR) || defined (TAUB0_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH14_CAT2_ISR) || defined (TAUB0_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB0_CH15_CAT2_ISR) || defined (TAUB0_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB0_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH00_CAT2_ISR) || defined (TAUB1_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH01_CAT2_ISR) || defined (TAUB1_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH02_CAT2_ISR) || defined (TAUB1_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH03_CAT2_ISR) || defined (TAUB1_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH04_CAT2_ISR) || defined (TAUB1_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH05_CAT2_ISR) || defined (TAUB1_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH06_CAT2_ISR) || defined (TAUB1_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH07_CAT2_ISR) || defined (TAUB1_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH08_CAT2_ISR) || defined (TAUB1_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH09_CAT2_ISR) || defined (TAUB1_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH10_CAT2_ISR) || defined (TAUB1_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH11_CAT2_ISR) || defined (TAUB1_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH12_CAT2_ISR) || defined (TAUB1_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH13_CAT2_ISR) || defined (TAUB1_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH14_CAT2_ISR) || defined (TAUB1_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUB1_CH15_CAT2_ISR) || defined (TAUB1_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUB1_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH00_CAT2_ISR) || defined (TAUJ0_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ0_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH01_CAT2_ISR) || defined (TAUJ0_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ0_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH02_CAT2_ISR) || defined (TAUJ0_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ0_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ0_CH03_CAT2_ISR) || defined (TAUJ0_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ0_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH00_CAT2_ISR) || defined (TAUJ1_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ1_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH01_CAT2_ISR) || defined (TAUJ1_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ1_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH02_CAT2_ISR) || defined (TAUJ1_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ1_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ1_CH03_CAT2_ISR) || defined (TAUJ1_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ1_CH03_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH00_CAT2_ISR) || defined (TAUJ2_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ2_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH01_CAT2_ISR) || defined (TAUJ2_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ2_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH02_CAT2_ISR) || defined (TAUJ2_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ2_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ2_CH03_CAT2_ISR) || defined (TAUJ2_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ2_CH03_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH00_CAT2_ISR) || defined (TAUJ3_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ3_CH00_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH01_CAT2_ISR) || defined (TAUJ3_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ3_CH01_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH02_CAT2_ISR) || defined (TAUJ3_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ3_CH02_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_TAUJ3_CH03_CAT2_ISR) || defined (TAUJ3_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) TAUJ3_CH03_ISR(void);
#endif

#if (PWM_DIAG_UNIT_USED == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH00_CAT2_ISR) || defined (PWGA_CH00_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH00_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH01_CAT2_ISR) || defined (PWGA_CH01_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH01_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH02_CAT2_ISR) || defined (PWGA_CH02_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH02_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH03_CAT2_ISR) || defined (PWGA_CH03_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH03_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH04_CAT2_ISR) || defined (PWGA_CH04_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH04_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH05_CAT2_ISR) || defined (PWGA_CH05_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH05_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH06_CAT2_ISR) || defined (PWGA_CH06_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH06_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH07_CAT2_ISR) || defined (PWGA_CH07_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH07_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH08_CAT2_ISR) || defined (PWGA_CH08_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH08_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH09_CAT2_ISR) || defined (PWGA_CH09_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH09_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH10_CAT2_ISR) || defined (PWGA_CH10_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH10_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH11_CAT2_ISR) || defined (PWGA_CH11_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH11_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH12_CAT2_ISR) || defined (PWGA_CH12_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH12_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH13_CAT2_ISR) || defined (PWGA_CH13_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH13_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH14_CAT2_ISR) || defined (PWGA_CH14_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH14_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH15_CAT2_ISR) || defined (PWGA_CH15_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH15_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH16_CAT2_ISR) || defined (PWGA_CH16_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH16_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH17_CAT2_ISR) || defined (PWGA_CH17_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH17_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH18_CAT2_ISR) || defined (PWGA_CH18_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH18_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH19_CAT2_ISR) || defined (PWGA_CH19_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH19_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH20_CAT2_ISR) || defined (PWGA_CH20_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH20_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH21_CAT2_ISR) || defined (PWGA_CH21_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH21_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH22_CAT2_ISR) || defined (PWGA_CH22_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH22_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH23_CAT2_ISR) || defined (PWGA_CH23_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH23_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH24_CAT2_ISR) || defined (PWGA_CH24_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH24_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH25_CAT2_ISR) || defined (PWGA_CH25_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH25_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH26_CAT2_ISR) || defined (PWGA_CH26_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH26_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH27_CAT2_ISR) || defined (PWGA_CH27_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH27_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH28_CAT2_ISR) || defined (PWGA_CH28_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH28_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH29_CAT2_ISR) || defined (PWGA_CH29_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH29_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH30_CAT2_ISR) || defined (PWGA_CH30_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH30_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH31_CAT2_ISR) || defined (PWGA_CH31_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH31_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH32_CAT2_ISR) || defined (PWGA_CH32_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH32_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH33_CAT2_ISR) || defined (PWGA_CH33_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH33_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH34_CAT2_ISR) || defined (PWGA_CH34_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH34_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH35_CAT2_ISR) || defined (PWGA_CH35_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH35_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH36_CAT2_ISR) || defined (PWGA_CH36_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH36_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH37_CAT2_ISR) || defined (PWGA_CH37_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH37_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH38_CAT2_ISR) || defined (PWGA_CH38_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH38_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH39_CAT2_ISR) || defined (PWGA_CH39_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH39_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH40_CAT2_ISR) || defined (PWGA_CH40_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH40_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH41_CAT2_ISR) || defined (PWGA_CH41_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH41_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH42_CAT2_ISR) || defined (PWGA_CH42_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH42_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH43_CAT2_ISR) || defined (PWGA_CH43_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH43_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH44_CAT2_ISR) || defined (PWGA_CH44_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH44_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH45_CAT2_ISR) || defined (PWGA_CH45_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH45_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH46_CAT2_ISR) || defined (PWGA_CH46_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH46_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH47_CAT2_ISR) || defined (PWGA_CH47_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH47_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH48_CAT2_ISR) || defined (PWGA_CH48_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH48_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH49_CAT2_ISR) || defined (PWGA_CH49_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH49_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH50_CAT2_ISR) || defined (PWGA_CH50_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH50_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH51_CAT2_ISR) || defined (PWGA_CH51_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH51_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH52_CAT2_ISR) || defined (PWGA_CH52_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH52_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH53_CAT2_ISR) || defined (PWGA_CH53_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH53_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH54_CAT2_ISR) || defined (PWGA_CH54_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH54_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH55_CAT2_ISR) || defined (PWGA_CH55_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH55_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH56_CAT2_ISR) || defined (PWGA_CH56_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH56_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH57_CAT2_ISR) || defined (PWGA_CH57_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH57_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH58_CAT2_ISR) || defined (PWGA_CH58_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH58_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH59_CAT2_ISR) || defined (PWGA_CH59_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH59_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH60_CAT2_ISR) || defined (PWGA_CH60_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH60_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH61_CAT2_ISR) || defined (PWGA_CH61_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH61_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH62_CAT2_ISR) || defined (PWGA_CH62_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH62_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH63_CAT2_ISR) || defined (PWGA_CH63_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH63_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH64_CAT2_ISR) || defined (PWGA_CH64_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH64_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH65_CAT2_ISR) || defined (PWGA_CH65_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH65_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH66_CAT2_ISR) || defined (PWGA_CH66_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH66_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH67_CAT2_ISR) || defined (PWGA_CH67_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH67_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH68_CAT2_ISR) || defined (PWGA_CH68_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH68_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH69_CAT2_ISR) || defined (PWGA_CH69_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH69_ISR(void);
#endif


/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH70_CAT2_ISR) || defined (PWGA_CH70_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH70_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_PWGA_CH71_CAT2_ISR) || defined (PWGA_CH71_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWGA_CH71_ISR(void);
#endif

#if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
 /* Defines the CAT2 interrupt mapping */
 #if defined (Os_PWGA_CHGRP00_CAT2_ISR) || defined (PWGA_CHGRP00_CAT2_ISR)
 /* Use ISR() macro from Os.h */
 /* Defines the CAT1 interrupt mapping */
 #else
 extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWM_INTPWGAG00_ISR(void);
 #endif

 /* Defines the CAT2 interrupt mapping */
 #if defined (Os_PWGA_CHGRP01_CAT2_ISR) || defined (PWGA_CHGRP01_CAT2_ISR)
 /* Use ISR() macro from Os.h */
 /* Defines the CAT1 interrupt mapping */
 #else
 extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWM_INTPWGAG01_ISR(void);
 #endif

 /* Defines the CAT2 interrupt mapping */
 #if defined (Os_PWGA_CHGRP02_CAT2_ISR) || defined (PWGA_CHGRP02_CAT2_ISR)
 /* Use ISR() macro from Os.h */
 /* Defines the CAT1 interrupt mapping */
 #else
 extern _INTERRUPT_ FUNC(void, PWM_FAST_CODE) PWM_INTPWGAG02_ISR(void);
 #endif
 #endif
#endif /* End of PWM_DIAG_UNIT_USED == STD_ON */

#define PWM_STOP_SEC_CODE_FAST
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif  /* PWM_IRQ_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
