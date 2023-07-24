/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Internal.h                                           */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2014 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains function prototype of swg3k API of Core Test module.    */
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
 * V1.0.0:  09-Sep-2014    : Initial Version
 * V1.0.1:  09-Aug-2016    : #ARDAABD-573
 *                           1. Updated CorTst library to G3KH RC3 v1.20
 * V1.0.2:  30-Aug-2016    : #ARDAABD-476
 *                           1. Updated to ASR 4.2.2
 * V1.0.3:  06-Sep-2016    : #ARDAABD-495
 *                           1. Updated copyright year
 * V1.0.4:  09-June-2018   : #ARDAABD-495
 *                           1.Updated copyright year and revision history
 *                           2.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           3.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 */
/******************************************************************************/
#ifndef CORTST_INTERNAL_H
#define CORTST_INTERNAL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* CORTST_INTERNAL_H_001: CORTST_ESDD_UD_046 */
#include "CorTst_Cfg.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define CORTST_INTERNAL_AR_RELEASE_MAJOR_VERSION \
                                                CORTST_AR_RELEASE_MAJOR_VERSION
#define CORTST_INTERNAL_AR_RELEASE_MINOR_VERSION \
                                                CORTST_AR_RELEASE_MINOR_VERSION
#define CORTST_INTERNAL_AR_RELEASE_REVISION_VERSION \
                                             CORTST_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define CORTST_INTERNAL_SW_MAJOR_VERSION    CORTST_SW_MAJOR_VERSION
#define CORTST_INTERNAL_SW_MINOR_VERSION    CORTST_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* CORTST_INTERNAL_H_002: CorTst130_Conf, CorTst129_Conf, CorTst133_Conf */
/* CORTST_INTERNAL_H_003: CorTst128_Conf, CorTst131_Conf */
/* CORTST_INTERNAL_H_004: CorTst132_Conf, CorTst127_Conf */
#if (CORE_G3K == CORTST_SWCST)
extern void sw_cst(int test_id, int norm_val, volatile long *p_Result,
                    volatile long *p_NotResult, volatile long *p_Signature,
                    volatile long *p_NotSignature);
#else
extern void sw_cst(int test_id, int norm_val, volatile long *p_Result,
                    volatile long *p_Signature);
#endif
#endif /* CORTST_INTERNAL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
