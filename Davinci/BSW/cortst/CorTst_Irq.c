/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Irq.c                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 - 2018 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Interrupt Routine implementations of Core Test Driver   */
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
 * V1.0.1:  31-Aug-2016    : #ARDAABD-476
 *                           1. Updated CorTst to ASR 4.2.2
 * V1.0.2:  06-Sep-2016    : #ARDAABD-495
 *                           1. Updated Copyright year
 * V1.0.3:  07-Sep-2016    : #ARDAABD-476
 *                           1. Updated Copyright year and Revision History
 * V1.0.4:  22-Sep-2016    : #ARDAABD-476
 *                           1. Improved MemMap inclusion for 4.0.3 and 4.2.2
 * V1.0.5:  19-Jul-2018    : #ARDAABD-580
 *                           1.Added asm("POPSP        R12-R13") after
 *                             _EITRAP0_EXEC_USER_ROUTINE
 *                             _FETRAP_EXEC_USER_ROUTINE
 *                             _MAE_EXEC_USER_ROUTINE
 *                             to be in sync with CorTst RC3 library sample and
 *                             with the rest of the irq implementation
 *                           2.As a part of ARDAABD-3845,
 *                             Added UD IDs for requirement traceability.
 *                           3.As a part of ARDAABD-3845,
 *                             Added Requirements for Requirement traceability.
 *                           4.Copyright information is updated.
 */
/******************************************************************************/
#include "CorTst_Irq.h"

/*******************************************************************************
* Defined Symbol
*******************************************************************************/

/*******************************************************************************
* External Reference
*******************************************************************************/

/*******************************************************************************
*
* G3KH EITRAP0 ISR
*
* action: ISR called from EITRAP0 vector
*
*******************************************************************************/
#define CORTST_START_SEC_CODE_FAST
#include MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
/* Implements CorTst002 */
#if defined (Os_CORTST_G3KH_EITRAP0_CAT2_ISR) || \
                                   defined (CORTST_G3KH_EITRAP0_CAT2_ISR)
ISR(CORTST_G3KH_EITRAP0_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements EAAR_PN0077_FR_0008 */
FUNC(void, CORTST_FAST_CODE) CORTST_G3KH_EITRAP0_ISR(void)
#endif
{
  asm("PUSHSP       LP-LP");
  asm("PUSHSP       R11-R14");
  asm("STSR     EIPC,  R11, 0");
  asm("STSR     EIPSW, R12, 0");
  asm("STSR     EIIC,  R13, 0");
  asm("STSR     EIWR,  R14, 0");
  asm("PUSHSP       R11-R14");
#if CST_EXECUTE_TRAP0_TEST
  asm("PUSHSP       R12-R13");
  /* if (EIPC == _CST_CPU_trap0_inst+4)*/
  asm("STSR     EIPC, R12, 0");
  asm("MOV      _CST_CPU_trap0_inst, R13");
  asm("ADD      4, R13");
  asm("CMP      R12, R13");
  asm("BNZ      _EITRAP0_EXEC_USER_ROUTINE");
  /* then (execute SW CST routine)*/
  asm("POPSP        R12-R13");
  /*-- call signature calculation routine*/
  asm("JARL     _CST_CPU_trap0_signature, LP");
  asm("JR       _SWG3KH_EITRAP0");
  /* else (execute USER routine)*/
  asm("_EITRAP0_EXEC_USER_ROUTINE:");
  asm("POPSP        R12-R13");
#endif
  asm("JR       _CorTst_EITRAP0_Notification");
  asm("_SWG3KH_EITRAP0:");
  asm("POPSP        R11-R14 ");
  asm("LDSR     R14, EIWR,  0");
  asm("LDSR     R13, EIIC,  0");
  asm("LDSR     R12, EIPSW, 0");
  asm("LDSR     R11, EIPC,  0");
  asm("POPSP        R11-R14 ");
  asm("POPSP        LP-LP   ");
  asm("EIRET");
}
#define CORTST_STOP_SEC_CODE_FAST
#include MEMMAP_FILE

/*******************************************************************************
*
* G3KH EITRAP1 ISR
*
* action: ISR called from EITRAP1 vector
*
*******************************************************************************/
#define CORTST_START_SEC_CODE_FAST
#include MEMMAP_FILE

/* Implements CorTst009, CorTst008 */
/* Defines the CAT2 interrupt mapping */
#if defined (Os_CORTST_G3KH_EITRAP1_CAT2_ISR) || \
                                   defined (CORTST_G3KH_EITRAP1_CAT2_ISR)
ISR(CORTST_G3KH_EITRAP1_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements EAAR_PN0077_FR_0005, EAAR_PN0077_FR_0003, EAAR_PN0077_FR_0004 */
/* Implements CorTst012, CorTst013, CorTst014, CorTst009, CorTst011 */
/* Implements CorTst010 */
FUNC(void, CORTST_FAST_CODE) CORTST_G3KH_EITRAP1_ISR(void)
#endif
{
  asm("PUSHSP       LP-LP");
  asm("PUSHSP       R11-R14");
  asm("STSR     EIPC,  R11, 0");
  asm("STSR     EIPSW, R12, 0");
  asm("STSR     EIIC,  R13, 0");
  asm("STSR     EIWR,  R14, 0");
  asm("PUSHSP       R11-R14");
#if CST_EXECUTE_TRAP1_TEST
  asm("PUSHSP       R12-R13");
  /* if (EIPC == _CST_CPU_trap1_inst+4)*/
  asm("STSR     EIPC, R12, 0");
  asm("MOV      _CST_CPU_trap1_inst, R13");
  asm("ADD      4, R13");
  asm("CMP      R12, R13");
  asm("BNZ      _EITRAP1_EXEC_USER_ROUTINE");
  /* then (execute SW CST routine)*/
  asm("POPSP        R12-R13");
  /*-- call signature calculation routine*/
  asm("JARL     _CST_CPU_trap1_signature, LP");
  asm("JR       _SWG3KH_EITRAP1");
  /* else (execute USER routine)*/
  asm("_EITRAP1_EXEC_USER_ROUTINE:");
  asm("POPSP        R12-R13");
#endif
  asm("JR       _CorTst_EITRAP1_Notification");
  asm("_SWG3KH_EITRAP1:");
  asm("POPSP        R11-R14 ");
  asm("LDSR     R14, EIWR,  0");
  asm("LDSR     R13, EIIC,  0");
  asm("LDSR     R12, EIPSW, 0");
  asm("LDSR     R11, EIPC,  0");
  asm("POPSP        R11-R14 ");
  asm("POPSP        LP-LP   ");
  asm("EIRET");
}
#define CORTST_STOP_SEC_CODE_FAST
#include MEMMAP_FILE

/*******************************************************************************
*
* G3KH FETRAP ISR
*
* action: ISR called from FETRAP vector
*
*******************************************************************************/
#define CORTST_START_SEC_CODE_FAST
#include MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */

#if defined (Os_CORTST_G3KH_FETRAP_CAT2_ISR) || \
                                   defined (CORTST_G3KH_FETRAP_CAT2_ISR)
ISR(CORTST_G3KH_FETRAP_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements EAAR_PN0077_FR_0008 */
FUNC(void, CORTST_FAST_CODE) CORTST_G3KH_FETRAP_ISR(void)
#endif
{
  asm("PUSHSP       LP-LP       ");
  asm("PUSHSP       R11-R14     ");
  asm("STSR     FEPC,  R11, 0   ");
  asm("STSR     FEPSW, R12, 0   ");
  asm("STSR     FEIC,  R13, 0   ");
  asm("STSR     FEWR,  R14, 0   ");
  asm("PUSHSP       R11-R14     ");
#if CST_EXECUTE_FETRAP_TEST
  asm("PUSHSP       R12-R13 ");
  /* if (FEPC == _CST_CPU_fetrap_inst+2)*/
  asm("STSR     FEPC, R12, 0");
  asm("MOV      _CST_CPU_fetrap_inst, R13");
  asm("ADD      2, R13");
  asm("CMP      R12, R13");
  asm("BNZ      _FETRAP_EXEC_USER_ROUTINE");
  /* then (execute SW CST routine)*/
  asm("POPSP        R12-R13");
  /* call signature calculation routine*/
  asm("JARL     _CST_CPU_fetrap_signature, LP");
  asm("JR       _SWG3KH_FETRAP");
  /* else (execute USER routine)*/
  asm("_FETRAP_EXEC_USER_ROUTINE:");
  asm("POPSP        R12-R13");
#endif
  asm("JR       _CorTst_FETRAP_Notification");
  asm("_SWG3KH_FETRAP:");
  asm("POPSP        R11-R14 ");
  asm("LDSR     R14, FEWR,  0");
  asm("LDSR     R13, FEIC,  0");
  asm("LDSR     R12, FEPSW, 0");
  asm("LDSR     R11, FEPC,  0");
  asm("POPSP        R11-R14 ");
  asm("POPSP        LP-LP   ");
  asm("FERET");
}
#define CORTST_STOP_SEC_CODE_FAST
#include MEMMAP_FILE

/*******************************************************************************
*
* G3KH MAE ISR
*
* action: ISR called from MAE vector
*
*******************************************************************************/
#define CORTST_START_SEC_CODE_FAST
#include MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */

#if defined (Os_CORTST_G3KH_MAE_CAT2_ISR) || \
                                   defined (CORTST_G3KH_MAE_CAT2_ISR)
ISR(CORTST_G3KH_MAE_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements EAAR_PN0077_FR_0008 */
FUNC(void, CORTST_FAST_CODE) CORTST_G3KH_MAE_ISR(void)
#endif
{
  asm("PUSHSP       LP-LP   ");
  asm("PUSHSP       R11-R14 ");
  asm("STSR     FEPC,  R11, 0   ");
  asm("STSR     FEPSW, R12, 0   ");
  asm("STSR     FEIC,  R13, 0   ");
  asm("STSR     FEWR,  R14, 0   ");
  asm("PUSHSP       R11-R14 ");
#if CST_EXECUTE_MAE_TEST
  asm("PUSHSP       R12-R13 ");
  /* if (FEPC == _CST_SRU_mae_inst)*/
  asm("STSR     FEPC, R12, 0");
  asm("MOV      _CST_SRU_mae_inst, R13");
  asm("CMP      R12, R13");
  asm("BNZ      _MAE_EXEC_USER_ROUTINE");
  /* then (execute SW CST routine)*/
  asm("POPSP        R12-R13 ");
  /* call signature calculation routine*/
  asm("JARL     _CST_SRU_mae_signature, LP  ");
  asm("JR       _SWG3KH_MAE  ");
  /* else (execute USER routine)*/
  asm("_MAE_EXEC_USER_ROUTINE:");
  asm("POPSP        R12-R13 ");
#endif
  asm("JR       _CorTst_MAE_Notification    ");
  asm("_SWG3KH_MAE:  ");
  asm("POPSP        R11-R14 ");
  asm("LDSR     R14, FEWR,  0   ");
  asm("LDSR     R13, FEIC,  0   ");
  asm("LDSR     R12, FEPSW, 0   ");
  asm("ADD      6, R11  "); /* FOR RESUMABLE EXCEPTIONS*/
  asm("LDSR     R11, FEPC,  0   ");
  asm("POPSP        R11-R14 ");
  asm("POPSP        LP-LP   ");
  asm("FERET ");
}
#define CORTST_STOP_SEC_CODE_FAST
#include MEMMAP_FILE

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
