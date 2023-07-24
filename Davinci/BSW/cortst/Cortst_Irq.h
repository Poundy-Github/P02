/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Irq.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Interrupt Routine definitions of Core Test Driver       */
/* Component.                                                                 */
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
 * V1.0.0:  16-Aug-2016    : #ARDAABD-573
 *                           1. Initial Revision
 *                           2. CorTst library G3KH RC3 v1.20
 * V2.0.0:  31-Aug-2016    : #ARDAABD-476
 *                           1. Updated CorTst to ASR 4.2.2
 * V2.0.1:  06-Sep-2016    : #ARDAABD-495
 *                           1. Updated Copyright year
 * V2.0.2:  07-Sep-2016    : #ARDAABD-476
 *                           1. Updated Copyright year and Revision History
 * V2.0.3:  29-June-2018   : #ARDAABD-476
 *                           1.Improved MemMap inclusion for 4.0.3 and 4.2.2
 *                           2.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           3.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 */
/******************************************************************************/
#ifndef CORTST_IRQ_H
#define CORTST_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CST_if.h"
/* CORTST_IRQ_H_001: CORTST_ESDD_UD_046 */
#include "CorTst_Cfg.h"
#include "CorTst.h"
/* Included for interrupt category definitions */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define CORTST_IRQ_AR_RELEASE_MAJOR_VERSION \
                                                CORTST_AR_RELEASE_MAJOR_VERSION
#define CORTST_IRQ_AR_RELEASE_MINOR_VERSION \
                                                CORTST_AR_RELEASE_MINOR_VERSION
#define CORTST_IRQ_AR_RELEASE_REVISION_VERSION \
                                             CORTST_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define CORTST_IRQ_SW_MAJOR_VERSION    CORTST_SW_MAJOR_VERSION
#define CORTST_IRQ_SW_MINOR_VERSION    CORTST_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CORTST_START_SEC_CODE_FAST
#include MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* CORTST_IRQ_H_002: EAAR_PN0077_FR_0008 */
#if defined (Os_CORTST_G3KH_EITRAP0_CAT2_ISR) || \
                                   defined (CORTST_G3KH_EITRAP0_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern FUNC(void, CORTST_FAST_CODE) CORTST_G3KH_EITRAP0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
/* CORTST_IRQ_H_003: EAAR_PN0077_FR_0008 */
#if defined (Os_CORTST_G3KH_EITRAP1_CAT2_ISR) || \
                                   defined (CORTST_G3KH_EITRAP1_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
/* CORTST_IRQ_H_004: EAAR_PN0077_NR_0001 */
#else
extern FUNC(void, CORTST_FAST_CODE) CORTST_G3KH_EITRAP1_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
/* CORTST_IRQ_H_005: EAAR_PN0077_FR_0008 */
#if defined (Os_CORTST_G3KH_FETRAP_CAT2_ISR) || \
                                   defined (CORTST_G3KH_FETRAP_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern FUNC(void, CORTST_FAST_CODE) CORTST_G3KH_FETRAP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
/* CORTST_IRQ_H_006: EAAR_PN0077_FR_0008 */
#if defined (Os_CORTST_G3KH_MAE_CAT2_ISR) || \
                                   defined (CORTST_G3KH_MAE_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern FUNC(void, CORTST_FAST_CODE) CORTST_G3KH_MAE_ISR(void);
#endif

#define CORTST_STOP_SEC_CODE_FAST
#include MEMMAP_FILE

/* The notification functions being defined in user application */
extern void CorTst_EITRAP0_Notification(void);
extern void CorTst_EITRAP1_Notification(void);
extern void CorTst_FETRAP_Notification(void);
extern void CorTst_MAE_Notification(void);

/* The relevant assembly functions of exception handler */
#if CST_EXECUTE_TRAP0_TEST
extern void CST_CPU_trap0_inst(void);
extern void CST_CPU_trap0_signature(void);
#endif
#if CST_EXECUTE_TRAP1_TEST
extern void CST_CPU_trap1_inst(void);
extern void CST_CPU_trap1_signature(void);
#endif
#if CST_EXECUTE_FETRAP_TEST
extern void CST_CPU_fetrap_inst(void);
extern void CST_CPU_fetrap_signature(void);
#endif
#if CST_EXECUTE_MAE_TEST
extern void CST_SRU_mae_inst(void);
extern void CST_SRU_mae_signature(void);
#endif
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
