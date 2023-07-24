/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Scheduler.c                                             */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Nov-2019                                                 */
/*============================================================================*/
/*                               COPYRIGHT                                    */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low level driver function definitions of the SPI        */
/* Driver                                                                     */
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
 *                         1. As per ARDAACH-73, remove duplicated loop
 *                         processing in Spi_CancelSequence().
 *                         2. As per ARDAACH-88, remove the implementation and
 *                         reference of Spi_MaskSequenceInterrupts.
 *                         3. As per ARDAACH-98, use Spi_GulCancelingHWUnits to
 *                         prevent transmission/reception of related HW units
 *                         in Spi_CancelSequence.
 *                         4. As per ARDAACH-93, move calling of the function
 *                         pSeqStartNotification before job started in
 *                         Spi_StartTransmission.
 *          12-Nov-2019  : The following changes are made:
 *                         1. As per static test result, remove un-used
 *                         parameter-in of the function, Spi_ProcessSequence().
 *                         2. As acceptance test 's findings, correct typo for
 *                         the source code comments.
 *                         3. As per review of ARDAACH-98, add condition to
 *                         check for force-cancel.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Spi.h"
#include "Spi_Ram.h"
#include "Spi_Scheduler.h"
#include "Spi_CSIX_LLDriver.h"
#include "Dem.h"
#include "rh850_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define SPI_SCHEDULER_C_AR_RELEASE_MAJOR_VERSION \
                                  SPI_AR_RELEASE_MAJOR_VERSION_VALUE
#define SPI_SCHEDULER_C_AR_RELEASE_MINOR_VERSION \
                                  SPI_AR_RELEASE_MINOR_VERSION_VALUE
#define SPI_SCHEDULER_C_AR_RELEASE_REVISION_VERSION \
                               SPI_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define SPI_SCHEDULER_C_SW_MAJOR_VERSION    SPI_SW_MAJOR_VERSION_VALUE
#define SPI_SCHEDULER_C_SW_MINOR_VERSION    SPI_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (SPI_SCHEDULER_AR_RELEASE_MAJOR_VERSION != \
                                       SPI_SCHEDULER_C_AR_RELEASE_MAJOR_VERSION)
#error "Spi_Scheduler.c : Mismatch in Release Major Version"
#endif

#if (SPI_SCHEDULER_AR_RELEASE_MINOR_VERSION != \
                                       SPI_SCHEDULER_C_AR_RELEASE_MINOR_VERSION)
#error "Spi_Scheduler.c : Mismatch in Release Minor Version"
#endif

#if (SPI_SCHEDULER_AR_RELEASE_REVISION_VERSION != \
                                    SPI_SCHEDULER_C_AR_RELEASE_REVISION_VERSION)
#error "Spi_Scheduler.c : Mismatch in Release Revision Version"
#endif

#if (SPI_SCHEDULER_SW_MAJOR_VERSION != SPI_SCHEDULER_C_SW_MAJOR_VERSION)
#error "Spi_Scheduler.c : Mismatch in Software Major Version"
#endif

#if (SPI_SCHEDULER_SW_MINOR_VERSION != SPI_SCHEDULER_C_SW_MINOR_VERSION)
#error "Spi_Scheduler.c : Mismatch in Software Minor Version"
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
/* Message       : (4:3218) File scope static, 'symbol', is only accessed in  */
/*                 one function.                                              */
/* Rule          : MISRA-C:2004 Rule 8.7                                      */
/* Justification : To control the memory location by memmap.h, static symbols */
/*                 must be declared in the global scope.                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3218)-2 and                           */
/*                 END Msg(4:3218)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2962) Apparent: Using value of uninitialized automatic  */
/*                 object '%s'.                                               */
/* Rule          : MISRA-C:2004 Rule 9.1                                      */
/* Justification : It will be initialized based on scope of 'if' statements   */
/*                 where at least an 'if' statement will be executed that     */
/*                 will initialize the variable in question.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2962)-3 and                           */
/*                 END Msg(4:2962)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation is redundant. The value of the     */
/*                 result is always '1'.                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : If user configures more than one queue, this warning will  */
/*                 not occur.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-4 and                           */
/*                 END Msg(4:2984)-4 tags in the code.                        */
/******************************************************************************/

/* 5.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2983) This assignment is redundant. The value of this   */
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : If user configures more than one queue, this warning will  */
/*                 not occur.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-5 and                           */
/*                 END Msg(4:2983)-5 tags in the code.                        */
/******************************************************************************/

/******************************************************************************/
/**                      QAC Warning                                         **/
/******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:3441) Function call argument is an expression with      */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3441           */
/* Justification : According to the coding guide, all global variables must   */
/*                 be declared with volatile keyword. Since these are normal  */
/*                 memory objects, there is no side effect.                   */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3441)-1 and                           */
/*                 END Msg(2:3441)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:0832) Function call argument is an expression with      */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The name of an include file has been specified using a     */
/*                 macro. This is not recommended in some coding standards.   */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-2 and                           */
/*                 END Msg(2:0832)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (4:2877) This loop will never be executed more than once.  */
/* Rule          : No MISRA-C:2004 Rules applicable to message 2877           */
/* Justification : If user configures more than one queue, this warning will  */
/*                 not occur.                                                 */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(4:2877)-3 and                           */
/*                 END Msg(4:2877)-3 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

#define SPI_START_SEC_CONST_8
/* QAC Warning: START Msg(2:0832)-2 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/* Lookup table to get the highest bit position */
/* MISRA Violation: START Msg(4:3218)-2 */
static CONST(uint8, SPI_CONST) Spi_GaaPriorityTable[] =
/* END Msg(4:3218)-2 */
{
  0U, /* 0x00(unavailable) */
  0U, /* 0x01: 00000001 */
  1U, /* 0x02: 00000010 */
  1U, /* 0x03: 00000011 */
  2U, /* 0x04: 00000100 */
  2U, /* 0x05: 00000101 */
  2U, /* 0x06: 00000110 */
  2U, /* 0x07: 00000111 */
  3U, /* 0x08: 00001000 */
  3U, /* 0x09: 00001001 */
  3U, /* 0x0A: 00001010 */
  3U, /* 0x0B: 00001011 */
  3U, /* 0x0C: 00001100 */
  3U, /* 0x0D: 00001101 */
  3U, /* 0x0E: 00001110 */
  3U  /* 0x0F: 00001111 */
};

#define SPI_STOP_SEC_CONST_8
/* QAC Warning: START Msg(2:0832)-2 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-2 */

#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define SPI_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-2 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-2 */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

/* Prototype of functions which are used in this file only */
static FUNC(void, SPI_PRIVATE_CODE) Spi_PushToQueue(
  CONST(uint32, AUTOMATIC) LulQueueIndex,
  CONST(uint32, AUTOMATIC) LulSeqIndex);

static FUNC(boolean, SPI_PRIVATE_CODE) Spi_PopFromQueue(
  CONST(uint32, AUTOMATIC) LulQueueIndex,
  CONSTP2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpSeqIndex,
  CONSTP2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpJobIndex);

static FUNC(void, SPI_PRIVATE_CODE) Spi_InvokeNotifications(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) LpPrevJobConfig,
  CONSTP2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_APPL_CONST) LpPrevSeqConfig,
  CONST(boolean, AUTOMATIC) LblSeqFinished
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  ,
  CONSTP2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_APPL_CONST) LpNextSeqConfig,
  CONST(boolean, AUTOMATIC) LblSeqAlreadyStarted
#endif
  );

static FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessJob(
  CONST(uint32, AUTOMATIC) LulJobIndex);

static FUNC(boolean, SPI_PRIVATE_CODE) Spi_CheckSeqFinish(
  CONST(uint32, AUTOMATIC) LulQueueIndex,
  CONST(uint32, AUTOMATIC) LulSeqIndex);


#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
    (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

/*******************************************************************************
** Function Name       : Spi_PushToQueue
**
** Service ID          : Not Applicable
**
** Description         : This function pushes a Sequence to a Queue structure.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant for different Queue,
**                       Non-Reentrant for same Queue
**
** Input Parameters    : LulQueueIndex - Index of a Queue
**                       LulSeqIndex   - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Queue must be initialized
**
** Global Variable     : Spi_GaaQueue,
**                       Spi_GpFirstSeq, Spi_GpFirstJob, Spi_GaaSeqStatus
**
** Function Invoked    : None
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_PushToQueue(
  CONST(uint32, AUTOMATIC) LulQueueIndex,
  CONST(uint32, AUTOMATIC) LulSeqIndex)
/* References: SPI_DDD_ACT_051 */
{
  volatile P2VAR(Spi_QueueType, AUTOMATIC, SPI_APPL_DATA) LpQueue;
  P2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSeqConfig;
  P2CONST(Spi_SubSeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSubSeqConfig;
  VAR(uint32, AUTOMATIC) LulHighestJobIndex;
  VAR(uint32, AUTOMATIC) LulPriority;
  VAR(uint32, AUTOMATIC) LulMaxPriority;
  VAR(uint32, AUTOMATIC) LulMinPriority;
  VAR(Spi_SequenceType, AUTOMATIC) LucLastSeq;

  LpQueue = &Spi_GaaQueue[LulQueueIndex];
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpSeqConfig = &Spi_GpFirstSeq[LulSeqIndex];
  /* END Msg(4:0491)-1 */
  LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[LulQueueIndex];
  /* Get index of the Job which has the highest priority */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LulHighestJobIndex = LpSubSeqConfig->pJobList[SPI_ZERO];
  /* END Msg(4:0491)-1 */
  /* Get the highest priority among remaining Jobs */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LulMaxPriority = Spi_GpFirstJob[LulHighestJobIndex].ucJobPriority;
  /* END Msg(4:0491)-1 */
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
  if (SPI_TRUE == LpSeqConfig->blInterruptible)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulMinPriority = Spi_GpFirstJob[
      LpSubSeqConfig->pJobList[LpSubSeqConfig->usNoOfJobs - SPI_ONE]
    ].ucJobPriority;
    /* END Msg(4:0491)-1 */
  }
  else
#endif
  {
    /* If the Sequence is non-interruptible, enqueue the first Job only */
    LulMinPriority = LulMaxPriority;
  }
  /* Add this Sequence to the end of each priority list */
  for (LulPriority = LulMinPriority;
    LulPriority <= LulMaxPriority; LulPriority++)
  {
    /* If Seq has Job which has this priority, add it to the end of the list */
    if ((uint32)SPI_ZERO !=
      (LpSubSeqConfig->ucUsingPriorities & (((uint32)SPI_ONE << LulPriority))))
    {
      if (SPI_ZERO == (LpQueue->ucExists &
          (uint8)((uint32)SPI_ONE << LulPriority)))
      {
        /* If the list is empty, add this Sequence to the Top of the list */
        LpQueue->aaTop[LulPriority] = (Spi_SequenceType)LulSeqIndex;
        /* References: SPI_DDD_ACT_051_GBL001 */
        LpQueue->ucExists =
          (uint8)(LpQueue->ucExists | ((uint32)SPI_ONE << LulPriority));
        /* References: SPI_DDD_ACT_051_GBL002 */
      }
      else
      {
        /* If the list isn't empty, add this Sequence to the end of the list */
        LucLastSeq = LpQueue->aaTail[LulPriority];
        Spi_GaaSeqStatus[LucLastSeq].aaSubSeqs[
          LulQueueIndex].aaNext[LulPriority] = (Spi_SequenceType)LulSeqIndex;
        /* References: SPI_DDD_ACT_051_GBL003 */
        Spi_GaaSeqStatus[LulSeqIndex].aaSubSeqs[
          LulQueueIndex].aaPrev[LulPriority] = (Spi_SequenceType)LucLastSeq;
        /* References: SPI_DDD_ACT_051_GBL004 */
      }
      LpQueue->aaTail[LulPriority] = (Spi_SequenceType)LulSeqIndex;
      /* References: SPI_DDD_ACT_051_GBL005 */
    }
    else
    {
      /* Nothing to do */
    }
  }
  /* Initialize number of Jobs remain in the Queue */
  Spi_GaaSeqStatus[LulSeqIndex].aaSubSeqs[LulQueueIndex].usRemainJobCount =
    LpSubSeqConfig->usNoOfJobs;
  /* References: SPI_DDD_ACT_051_GBL006 */
}

/*******************************************************************************
** Function Name       : Spi_PopFromQueue
**
** Service ID          : Not Applicable
**
** Description         : This function pops a Job which should be performed next
**                       from a Queue.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant for different Queue,
**                       Non-Reentrant for same Queue
**
** Input Parameters    : LulQueueIndex - Index of a Queue
**
** Output Parameters   : LpSeqIndex    - Pointer to receive Sequence ID
**                       LpJobIndex    - Pointer to receive Job ID
**
** Return parameter    : If a Queue is not empty, return true.
**                       If a Queue is empty, return false.
**
** Preconditions       : Queue must be initialized
**
** Global Variable     : Spi_GaaQueue, Spi_GaaPriorityTable
**                       Spi_GpFirstJob, Spi_GpFirstSeq, Spi_GaaSeqStatus
**
** Function Invoked    : None
**
** Registers Used      : None
*******************************************************************************/
static FUNC(boolean, SPI_PRIVATE_CODE) Spi_PopFromQueue(
  CONST(uint32, AUTOMATIC) LulQueueIndex,
  CONSTP2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpSeqIndex,
  CONSTP2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpJobIndex)
/* References: SPI_DDD_ACT_052 */
{
  volatile P2VAR(Spi_QueueType, AUTOMATIC, SPI_APPL_DATA) LpQueue;
  volatile P2VAR(Spi_SubSeqStatusType, AUTOMATIC, SPI_APPL_DATA) LpSubSeqStat;
  P2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSeqConfig;
  P2CONST(Spi_SubSeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSubSeqConfig;
  VAR(uint32, AUTOMATIC) LulPriority;
  VAR(boolean, AUTOMATIC) LblIsAvailable;
  VAR(boolean, AUTOMATIC) LblRemove;

  LpQueue = &Spi_GaaQueue[LulQueueIndex];
  if (SPI_ZERO == LpQueue->ucExists)
  {
    /* There is no Job in this Queue */
    LblIsAvailable = SPI_FALSE;
  }
  else
  {
    LblIsAvailable = SPI_TRUE;
    if ((SPI_INVALID_SEQUENCE == LpQueue->ucOngoingSeqIndex)
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-1 */
      || (SPI_TRUE ==
        Spi_GpFirstSeq[LpQueue->ucOngoingSeqIndex].blInterruptible)
      /* END Msg(4:0491)-1 */
#endif
    )
    {
      /* If no Seq is on-going or interruptible Seq is on-going,
      use a seq that is in the top of the highest priority list */
      LulPriority = Spi_GaaPriorityTable[LpQueue->ucExists];
      *LpSeqIndex = LpQueue->aaTop[LulPriority];
      LpQueue->ucOngoingSeqIndex = (Spi_SequenceType)(*LpSeqIndex);
      /* References: SPI_DDD_ACT_052_GBL001 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      LpSeqConfig = &Spi_GpFirstSeq[*LpSeqIndex];
      /* END Msg(4:0491)-1 */
      LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[LulQueueIndex];
    }
    else
    {
      /* If non-interruptible Seq is on-going, continue the current Seq */
      *LpSeqIndex = LpQueue->ucOngoingSeqIndex;
      /* MISRA Violation: START Msg(4:0491)-1 */
      LpSeqConfig = &Spi_GpFirstSeq[*LpSeqIndex];
      /* END Msg(4:0491)-1 */
      LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[LulQueueIndex];
      /* MISRA Violation: START Msg(4:0491)-1 */
      LulPriority =
        Spi_GpFirstJob[LpSubSeqConfig->pJobList[SPI_ZERO]].ucJobPriority;
      /* END Msg(4:0491)-1 */
    }
    LpSubSeqStat = &Spi_GaaSeqStatus[*LpSeqIndex].aaSubSeqs[LulQueueIndex];

    /* MISRA Violation: START Msg(4:0491)-1 */
    *LpJobIndex = LpSubSeqConfig->pJobList[
      LpSubSeqConfig->usNoOfJobs - LpSubSeqStat->usRemainJobCount];
    /* END Msg(4:0491)-1 */

    LpSubSeqStat->usRemainJobCount--;
    /* References: SPI_DDD_ACT_052_GBL002 */
    /* Check whether all jobs in this sequence are completed */
    if (SPI_ZERO == LpSubSeqStat->usRemainJobCount)
    {
      /* If there is no remaining Job in this Sequence, remove it */
      LblRemove = SPI_TRUE;
    }
    else
    {
      /*
       * If this sequence is interruptible and
       * the next Job has different priority,
       * remove this sequence from this priority list.
       */
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-1 */
      if ((SPI_TRUE == LpSeqConfig->blInterruptible) &&
        (Spi_GpFirstJob[*LpJobIndex].ucJobPriority !=
          Spi_GpFirstJob[LpSubSeqConfig->pJobList[LpSubSeqConfig->usNoOfJobs -
          LpSubSeqStat->usRemainJobCount]].ucJobPriority))
      /* END Msg(4:0491)-1 */
      {
        LblRemove = SPI_TRUE;
      }
      else
#endif
      {
        LblRemove = SPI_FALSE;
      }
    }
    if (SPI_TRUE == LblRemove)
    {
      /* Remove Sequence from this priority list */
      if (LpQueue->aaTail[LulPriority] == LpQueue->aaTop[LulPriority])
      {
        /* If there is no sequence in this list, clear exist flag */
        LpQueue->ucExists =
          (uint8)(LpQueue->ucExists & ~((uint32)SPI_ONE << LulPriority));
        /* References: SPI_DDD_ACT_052_GBL003 */
      }
      else
      {
        /* Update top pointer to the next Sequence */
        LpQueue->aaTop[LulPriority] = LpSubSeqStat->aaNext[LulPriority];
        /* References: SPI_DDD_ACT_052_GBL004 */
      }
      /* Since Sequence finished, set on-going Sequence as invalid. */
      LpQueue->ucOngoingSeqIndex = SPI_INVALID_SEQUENCE;
      /* References: SPI_DDD_ACT_052_GBL005 */
    }
    else
    {
      /* Nothing to do */
    }
  }

  return LblIsAvailable;
}

/*******************************************************************************
** Function Name       : Spi_RemoveFromQueue
**
** Service ID          : Not Applicable
**
** Description         : This function removes a Sequence from a Queue.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant for different Queue,
**                       Non-Reentrant for same Queue
**
** Input Parameters    : LulQueueIndex - Index of a Queue
**                       LulSeqIndex   - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Specified Sequence must be enqueued.
**
** Global Variable     : Spi_GaaQueue, Spi_GpFirstSeq, Spi_GaaSeqStatus,
**                       Spi_GpFirstJob
**
** Function Invoked    : None
**
** Registers Used      : None
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_RemoveFromQueue(
  CONST(uint32, AUTOMATIC) LulQueueIndex,
  CONST(uint32, AUTOMATIC) LulSeqIndex)
/* References: SPI_DDD_ACT_053 */
{
  volatile P2VAR(Spi_QueueType, AUTOMATIC, SPI_APPL_DATA) LpQueue;
  P2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSeqConfig;
  P2CONST(Spi_SubSeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSubSeqConfig;
  volatile P2VAR(Spi_SubSeqStatusType, AUTOMATIC, SPI_APPL_DATA) LpSubSeqStat;
  VAR(uint32, AUTOMATIC) LulPriority;
  VAR(uint32, AUTOMATIC) LulMaxPriority;
  VAR(uint32, AUTOMATIC) LulMinPriority;

  LpQueue = &Spi_GaaQueue[LulQueueIndex];
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpSeqConfig = &Spi_GpFirstSeq[LulSeqIndex];
  /* END Msg(4:0491)-1 */
  LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[LulQueueIndex];
  LpSubSeqStat = &Spi_GaaSeqStatus[LulSeqIndex].aaSubSeqs[LulQueueIndex];
  /* Get the highest priority among remaining Jobs */
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
  if (SPI_TRUE == LpSeqConfig->blInterruptible)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulMaxPriority = Spi_GpFirstJob[
      LpSubSeqConfig->pJobList[
        LpSubSeqConfig->usNoOfJobs - LpSubSeqStat->usRemainJobCount]
      ].ucJobPriority;
    LulMinPriority = Spi_GpFirstJob[
      LpSubSeqConfig->pJobList[LpSubSeqConfig->usNoOfJobs - SPI_ONE]
    ].ucJobPriority;
    /* END Msg(4:0491)-1 */
  }
  else
#endif
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulMaxPriority =
      Spi_GpFirstJob[LpSubSeqConfig->pJobList[SPI_ZERO]].ucJobPriority;
    /* END Msg(4:0491)-1 */
    LulMinPriority = LulMaxPriority;
  }

  /* Remove the Sequence from all priority lists */
  for (LulPriority = LulMinPriority;
    LulPriority <= LulMaxPriority; LulPriority++)
  {
    /* If Seq has Job which has this priority, remove it from the list */
    if ((uint32)SPI_ZERO !=
      (LpSubSeqConfig->ucUsingPriorities & ((uint32)SPI_ONE << LulPriority)))
    {
      if (LpQueue->aaTop[LulPriority] == LpQueue->aaTail[LulPriority])
      {
        /* If this is the last sequence in the list, clear existence flag */
        LpQueue->ucExists =
          (uint8)(LpQueue->ucExists & ~((uint32)SPI_ONE << LulPriority));
        /* References: SPI_DDD_ACT_053_GBL001 */
      }
      else if (LpQueue->aaTop[LulPriority] == LulSeqIndex)
      {
        /* If this is the top sequence in the list, update top pointer */
        LpQueue->aaTop[LulPriority] = LpSubSeqStat->aaNext[LulPriority];
        /* References: SPI_DDD_ACT_053_GBL002 */
      }
      else if (LpQueue->aaTail[LulPriority] == LulSeqIndex)
      {
        /* If this is the tail sequence in the list, update tail pointer */
        LpQueue->aaTail[LulPriority] = LpSubSeqStat->aaPrev[LulPriority];
        /* References: SPI_DDD_ACT_053_GBL003 */
      }
      else
      {
        /*
         * If this is the intermediate sequence in the list,
         * update previous and next sequence's pointers.
         */
        Spi_GaaSeqStatus[LpSubSeqStat->aaPrev[
          LulPriority]].aaSubSeqs[LulQueueIndex].aaNext[
            LulPriority] = LpSubSeqStat->aaNext[LulPriority];
        /* References: SPI_DDD_ACT_053_GBL004 */
        Spi_GaaSeqStatus[LpSubSeqStat->aaNext[
          LulPriority]].aaSubSeqs[LulQueueIndex].aaPrev[
            LulPriority] = LpSubSeqStat->aaPrev[LulPriority];
        /* References: SPI_DDD_ACT_053_GBL005 */
      }
    }
    else
    {
      /* Nothing to do */
    }
  }
  /* If the on-going Sequence is removed, invalidate it */
  if (LpQueue->ucOngoingSeqIndex == LulSeqIndex)
  {
    LpQueue->ucOngoingSeqIndex = SPI_INVALID_SEQUENCE;
    /* References: SPI_DDD_ACT_053_GBL006 */
  }
  else
  {
    /* Nothing to do */
  }
}

/*******************************************************************************
** Function Name       : Spi_StartTransmission
**
** Service ID          : Not Applicable
**
** Description         : This function pushes a Sequence and starts it if HWUnit
**                       is idle.
**
** Sync/Async          : Asynchronous
**
** Re-entrancy         : Reentrant for different Sequence,
**                       Non-Reentrant for same Sequence
**
** Input Parameters    : LulSeqIndex - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : Spi_GpFirstJob, Spi_GpFirstSeq, Spi_GulAllQueueSts
**                       Spi_GaaJobStatus, Spi_GaaSeqStatus, Spi_GaaHWStatus,
**
** Function Invoked    : Spi_PushToQueue, Spi_PopFromQueue, Spi_ProcessJob
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : None
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_StartTransmission(
  VAR(uint32, AUTOMATIC) LulSeqIndex)
/* References: SPI_DDD_ACT_054 */
{
  P2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSeqConfig;
  P2CONST(Spi_SubSeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSubSeqConfig;
  volatile P2VAR(Spi_SeqStatusType, AUTOMATIC, SPI_APPL_DATA) LpSeqStat;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  VAR(uint32, AUTOMATIC) LulJobListIndex;
  VAR(uint32, AUTOMATIC) LulJobIndex;
  VAR(uint32, AUTOMATIC) LulQueueIndex;
  VAR(boolean, AUTOMATIC) LblNeedToInitiate;
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  VAR(boolean, AUTOMATIC) LblSeqStartRequired;
  VAR(boolean, AUTOMATIC) LblSeqStartAlreadyCalled;
#endif

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpSeqConfig = &Spi_GpFirstSeq[LulSeqIndex];
  /* END Msg(4:0491)-1 */
  LpSeqStat = &Spi_GaaSeqStatus[LulSeqIndex];

  /* Initialize Sequence Status */
  LpSeqStat->blFailed = SPI_FALSE;
  /* References: SPI_DDD_ACT_054_GBL001 */

  /* Initialize start job flag */
  LblNeedToInitiate = SPI_FALSE;

#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  /* Initialize already started flag for SeqStartNotification */
  LpSeqStat->blStarted = SPI_FALSE;
  /* References: SPI_DDD_ACT_054_GBL005 */
  LblSeqStartRequired = SPI_FALSE;
  LblSeqStartAlreadyCalled = SPI_FALSE;
#endif

  /* Initiate each SubSequences */
  /* QAC Warning: START Msg(4:2877)-3 */
  for (LulQueueIndex = SPI_ZERO; LulQueueIndex < (uint32)SPI_MAX_QUEUE;
    LulQueueIndex++)
  /* END Msg(4:2877)-3 */
  {
    LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[LulQueueIndex];
    if (SPI_ZERO < LpSubSeqConfig->usNoOfJobs)
    {
      /*
       * Check whether the Queue is running already.
       * Critical section is required to avoid racing condition with ISR.
       */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      /* References: SPI_DDD_ACT_054_CRT001 */
#if (SPI_CANCEL_API == STD_ON) || (SPI_FORCE_CANCEL_API == STD_ON)
      /* Check whether the sequence is canceled before transmission started */
      if (SPI_SEQ_CANCELED != LpSeqStat->enResult)
#endif
      {
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
        /* Set active bits for each SubSequences.
          When this variable becomes 0, it means all SubSequences completed */
        LpSeqStat->ulActiveSubSequences |= ((uint32)SPI_ONE << LulQueueIndex);
        /* References: SPI_DDD_ACT_054_GBL002 */
#endif
        /* Push this sequence to the queue */
        Spi_PushToQueue(LulQueueIndex, LulSeqIndex);
        /* Update all Job statuses to SPI_JOB_QUEUED */
        for (LulJobListIndex = SPI_ZERO;
          LulJobListIndex < (uint32)LpSubSeqConfig->usNoOfJobs;
          LulJobListIndex++)
        {
          /* MISRA Violation: START Msg(4:0491)-1 */
          LulJobIndex = LpSubSeqConfig->pJobList[LulJobListIndex];
          /* END Msg(4:0491)-1 */
          Spi_GaaJobStatus[LulJobIndex].enResult = SPI_JOB_QUEUED;
          /* References: SPI_DDD_ACT_054_GBL006 */
        }
        /* MISRA Violation: START Msg(4:2984)-4 */
        if ((uint32)SPI_ZERO == (Spi_GulAllQueueSts &
            ((uint32)SPI_ONE << LulQueueIndex)))
        /* END Msg(4:2984)-4 */
        {
          /* If queue is not running, initiation is required */
          LblNeedToInitiate = SPI_TRUE;
          /* MISRA Violation: START Msg(4:2984)-4 */
          Spi_GulAllQueueSts |= ((uint32)SPI_ONE << LulQueueIndex);
          /* END Msg(4:2984)-4 */
          /* References: SPI_DDD_ACT_054_GBL007 */
          /* Pop the first job */
          (void)Spi_PopFromQueue(LulQueueIndex, &LulSeqIndex, &LulJobIndex);
          /* Sequence will be started by this function,
          so set started flag in this critical section */
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
          LpSeqStat->blStarted = SPI_TRUE;
          /* References: SPI_DDD_ACT_054_GBL008 */
          LblSeqStartRequired = SPI_TRUE;
#endif
          /* MISRA Violation: START Msg(4:0491)-1 */
          LpJobConfig = &Spi_GpFirstJob[LulJobIndex];
          /* END Msg(4:0491)-1 */
          /* Update HW status */
          Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].ucOngoingSeqIndex =
            (Spi_SequenceType)LulSeqIndex;
          /* References: SPI_DDD_ACT_054_GBL009 */
          Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].usOngoingJobIndex =
            (Spi_JobType)LulJobIndex;
          /* References: SPI_DDD_ACT_054_GBL010 */
          Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].ulOngoingQueueIndex =
            LulQueueIndex;
          /* References: SPI_DDD_ACT_054_GBL013 */
#if (SPI_HW_STATUS_API == STD_ON)
          Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].blActive = SPI_TRUE;
          /* References: SPI_DDD_ACT_054_GBL011 */
#endif
          /* Update Job status */
           Spi_GaaJobStatus[LulJobIndex].enResult = SPI_JOB_PENDING;
          /* References: SPI_DDD_ACT_054_GBL012 */
        }
        else
        {
          /* Nothing to do */
          /* If the Queue is already running, it will be started by ISR */
        }
      } /* if (SPI_SEQ_CANCELED != LpSeqStat->enResult) */
#if (SPI_CANCEL_API == STD_ON) || (SPI_FORCE_CANCEL_API == STD_ON)
      else
      {
        /* If sequence is cancelled before start, do nothing */
      }
#endif
      /* Exit critical section */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      /* References: SPI_DDD_ACT_054_CRT002 */
      /* Invoke SeqStartNotification if necessary */
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
      if ((SPI_TRUE == LblSeqStartRequired) &&
        (SPI_FALSE == LblSeqStartAlreadyCalled) &&
        (NULL_PTR != LpSeqConfig->pSeqStartNotification))
      {
        LpSeqConfig->pSeqStartNotification();
        /* MISRA Violation: START Msg(4:2983)-5 */
        LblSeqStartAlreadyCalled = SPI_TRUE;
        /* END Msg(4:2983)-5 */
      }
      else
      {
        /* Nothing to do */
      }
#endif
      /* If the initiation is required, run the first job */
      if (SPI_TRUE == LblNeedToInitiate)
      {
        /* Start transmission */
        /* MISRA Violation: START Msg(4:2962)-3 */
        Spi_ProcessJob(LulJobIndex);
        /* END Msg(4:2962)-3 */
      } /* if (SPI_TRUE == LblNeedToInitiate) */
      else
      {
        /* Nothing to do */
      }
    } /* if (SPI_ZERO < LpSubSeqConfig->usNoOfJobs) */
    else
    {
      /* Nothing to do */
    }
  } /* for (LulQueueIndex) */
}

/*******************************************************************************
** Function Name       : Spi_ProcessSequence
**
** Service ID          : Not Applicable
**
** Description         : This function performs the scheduling above Job layer.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant for different HWUnit,
**                       Non-Reentrant for same HWUnit
**
** Input Parameters    : LulHWUnitIndex - Index of the HWUnit which the Sequence
**                                        is currently going on.
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : Spi_GpFirstJob, Spi_GpFirstSeq, Spi_GulAllQueueSts
**                       Spi_GaaJobStatus, Spi_GaaSeqStatus, Spi_GaaHWStatus
**
** Function Invoked    : Spi_PopFromQueue,
**                       Spi_ProcessJob, Spi_CheckSeqFinish,
**                       Spi_InvokeNotifications, Dem_ReportErrorStatus,
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : None
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessSequence(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex)
/* References: SPI_DDD_ACT_055 */
{
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  VAR(uint32, AUTOMATIC) LulPrevJobIndex;
  VAR(uint32, AUTOMATIC) LulPrevSeqIndex;
  VAR(uint32, AUTOMATIC) LulJobIndex;
  VAR(uint32, AUTOMATIC) LulSeqIndex;
  VAR(boolean, AUTOMATIC) LblAvailable;
  VAR(boolean, AUTOMATIC) LblSeqFinished;
  VAR(uint32, AUTOMATIC) LulQueueIndex;

#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  P2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSeqConfig;
  VAR(boolean, AUTOMATIC) LblSeqAlreadyStarted;
  LpSeqConfig = NULL_PTR;
  LblSeqAlreadyStarted = SPI_FALSE;
#endif

  /* Keep finished Seq&Job index to invoke notification handlers later */
  LulQueueIndex = Spi_GaaHWStatus[LulHWUnitIndex].ulOngoingQueueIndex;
  LulPrevSeqIndex = Spi_GaaHWStatus[LulHWUnitIndex].ucOngoingSeqIndex;
  LulPrevJobIndex = Spi_GaaHWStatus[LulHWUnitIndex].usOngoingJobIndex;

  /* Check the Sequence is finished or aborted */
  LblSeqFinished = Spi_CheckSeqFinish(LulQueueIndex, LulPrevSeqIndex);

  /*
   * Critical section is required to avoid conflict with
   * StartTransmission and ProcessSequence from other sequence
   */
  /* References: SPI_DDD_ACT_055_CRT003 */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  /* Pop the next Job from the Queue */
  LblAvailable = Spi_PopFromQueue(LulQueueIndex, &LulSeqIndex, &LulJobIndex);
  if (SPI_TRUE == LblAvailable)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpJobConfig = &Spi_GpFirstJob[LulJobIndex];
    /* END Msg(4:0491)-1 */
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpSeqConfig = &Spi_GpFirstSeq[LulSeqIndex];
    /* END Msg(4:0491)-1 */
    LblSeqAlreadyStarted = Spi_GaaSeqStatus[LulSeqIndex].blStarted;
    Spi_GaaSeqStatus[LulSeqIndex].blStarted = SPI_TRUE;
    /* References: SPI_DDD_ACT_055_GBL005 */
#endif

#if ((SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_OFF) && \
  (SPI_HW_STATUS_API == STD_ON))
    /*
     * If the next Job is assigned to other HWUnit, clear HW associated with
     * completed job, set other HWUnit activated.
     * If parallel transmission is enabled, a Queue is assigned to a HWUnit,
     * so this operation is not necessary.
     */
    if (LpJobConfig->ucHWUnitIndex != LulHWUnitIndex)
    {
      Spi_GaaHWStatus[LulHWUnitIndex].blActive = SPI_FALSE;
      /* References: SPI_DDD_ACT_055_GBL006 */
      Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].blActive = SPI_TRUE;
      /* References: SPI_DDD_ACT_055_GBL007 */
    }
    else
    {
      /* Nothing to do */
    }
#endif

    /* Initialize HW status */
    Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].ucOngoingSeqIndex =
      (Spi_SequenceType)LulSeqIndex;
    /* References: SPI_DDD_ACT_055_GBL008 */
    Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].usOngoingJobIndex =
      (Spi_JobType)LulJobIndex;
    /* References: SPI_DDD_ACT_055_GBL009 */
    /* Update Job status */
    Spi_GaaJobStatus[LulJobIndex].enResult = SPI_JOB_PENDING;
    /* References: SPI_DDD_ACT_055_GBL010 */
  }
  else
  {
    /* If the Queue is empty, clear the active flag of this Queue */
    Spi_GulAllQueueSts &= ~((uint32)SPI_ONE << LulQueueIndex);
    /* References: SPI_DDD_ACT_055_GBL011 */
#if (SPI_HW_STATUS_API == STD_ON)
    Spi_GaaHWStatus[LulHWUnitIndex].blActive = SPI_FALSE;
    /* References: SPI_DDD_ACT_055_GBL012 */
#endif
  }
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  /* References: SPI_DDD_ACT_055_CRT004 */

  /* Report PASS to DEM when Sequence finished successfully */
#if (SPI_AR_VERSION == SPI_AR_422_VERSION)
#if defined(SPI_E_HARDWARE_ERROR)
  if (SPI_SEQ_OK == Spi_GaaSeqStatus[LulPrevSeqIndex].enResult)
  /* References: SPI_DDD_ACT_055_ERR001 */
  {
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    /* Nothing to do */
  }
#endif /* (defined(SPI_E_HARDWARE_ERROR)) */
#endif /* (SPI_AR_VERSION == SPI_AR_422_VERSION) */

  /* If the Queue was not empty, transmit the popped Job */
  if (SPI_TRUE == LblAvailable)
  {
    /* Start Job */
    Spi_ProcessJob(LulJobIndex);
  }
  else
  {
    /* Nothing to do */
  }

  /* Invoke JobEnd, SeqEnd, SeqStart notification if necessary */
  /* QAC Warning: START Msg(2:3441)-1 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  Spi_InvokeNotifications(
    &Spi_GpFirstJob[LulPrevJobIndex],
    &Spi_GpFirstSeq[LulPrevSeqIndex], LblSeqFinished
  /* END Msg(4:0491)-1 */
  /* END Msg(2:3441)-1 */
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
    , LpSeqConfig, LblSeqAlreadyStarted
#endif
  );
}

/*******************************************************************************
** Function Name       : Spi_CancelSequence
**
** Service ID          : Not Applicable
**
** Description         : This function cancels on-going Sequence.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant among Sequences which don't share same HW
**                       Non-Reentrant among Sequence which share same HW
**
** Input Parameters    : LulSeqIndex    : Index of a Sequence which is canceled
**                       LblIsForceStop : Behavior when Job(s) are on-going:
**                         SPI_TRUE : Stop the HW immediately.
**                         SPI_FALSE: Set cancel request flag and a sequence.
**                           will be canceled at the next Job end timing.
**                       LucApiId - Service ID of API invoking this function.
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : Spi_GpFirstJob, Spi_GpFirstSeq, Spi_GaaSeqStatus,
**                       Spi_GaaJobStatus, Spi_GaaActiveSequence,
**                       Spi_GulCancelingHWUnits
**
** Function Invoked    : Spi_RemoveFromQueue,
**                       Spi_CSIXForceStop, Spi_ProcessSequence,
**                       Spi_InvokeNotifications
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : None
*******************************************************************************/
#if ((SPI_CANCEL_API == STD_ON) || (SPI_FORCE_CANCEL_API == STD_ON))
FUNC(void, SPI_PRIVATE_CODE) Spi_CancelSequence(
  CONST(uint32, AUTOMATIC) LulSeqIndex,
  CONST(boolean, AUTOMATIC) LblIsForceStop,
  CONST(uint8, AUTOMATIC) LucApiId)
/* References: SPI_DDD_ACT_056 */
{
#if (SPI_FORCE_CANCEL_API == STD_ON)
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
#endif
  P2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSeqConfig;
  P2CONST(Spi_SubSeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSubSeqConfig;
  volatile P2VAR(Spi_SubSeqStatusType, AUTOMATIC, SPI_APPL_DATA) LpSubSeqStat;
  VAR(uint32, AUTOMATIC) LulJobIndex;
  VAR(uint32, AUTOMATIC) LulQueueIndex;
  VAR(uint32, AUTOMATIC) LulRequireScheduling;
  VAR(boolean, AUTOMATIC) LblRequireSeqEndNotification;

  LulRequireScheduling = SPI_ZERO;
  LblRequireSeqEndNotification = SPI_FALSE;
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpSeqConfig = &Spi_GpFirstSeq[LulSeqIndex];
  /* END Msg(4:0491)-1 */

#if (SPI_FORCE_CANCEL_API == STD_ON)
  if (SPI_TRUE == LblIsForceStop)
  {
    /* Set/Clear cancel on-going bits for the target HWUnits */
    /* Interrupt disabling is required for:
       - Exclusive control for re-entrant call of Spi_ForceCancel
       - Prevent invoking of Spi_MainFunction_Handling (ISR) */
    SPI_ENTER_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
    /* References: SPI_DDD_ACT_056_CRT003 */
    Spi_GulCancelingHWUnits |= LpSeqConfig->ulUsingHWUnits;
    /* References: SPI_DDD_ACT_056_GBL008 */
    SPI_EXIT_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
    /* References: SPI_DDD_ACT_056_CRT004 */
  }
  else
  {
    /* Nothing to do */
  }
#endif

  /* RAM_DATA_PROTECTION is required to manipulate the statuses and Queues */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  /* References: SPI_DDD_ACT_056_CRT001 */
  if (SPI_SEQ_PENDING == Spi_GaaSeqStatus[LulSeqIndex].enResult)
  {
    /* Loop to find queue index of on-going sequence */
    /* QAC Warning: START Msg(4:2877)-3 */
    for (LulQueueIndex = SPI_ZERO; LulQueueIndex < (uint32)SPI_MAX_QUEUE;
      LulQueueIndex++)
    /* END Msg(4:2877)-3 */
    {
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
      if ((uint32)SPI_ZERO ==
        (Spi_GaaSeqStatus[LulSeqIndex].ulActiveSubSequences &
        ((uint32)SPI_ONE << LulQueueIndex)))
      {
        /* This Sequence doesn't have Jobs on this Queue */
      }
      else
      {
#else
      LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[LulQueueIndex];
      if (SPI_ZERO < LpSubSeqConfig->usNoOfJobs)
      {
#endif /* End of (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON) */
        LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[LulQueueIndex];
        LpSubSeqStat = &Spi_GaaSeqStatus[LulSeqIndex].aaSubSeqs[LulQueueIndex];
        /*
         * Check whether this SubSequence is on-going on the HW now:
         * If this SubSequence is already started (NoOfJobs > RemainJobs) and
         * the latest Job (NoOfJobs - 1 - RemainJobs) is not finished
         */
        if (LpSubSeqConfig->usNoOfJobs > LpSubSeqStat->usRemainJobCount)
        {
          /* MISRA Violation: START Msg(4:0491)-1 */
          LulJobIndex =
            LpSubSeqConfig->pJobList[(LpSubSeqConfig->usNoOfJobs - SPI_ONE) -
              LpSubSeqStat->usRemainJobCount];
          /* END Msg(4:0491)-1 */
          if (SPI_JOB_PENDING == Spi_GaaJobStatus[LulJobIndex].enResult)
          {
#if (SPI_FORCE_CANCEL_API == STD_ON)
            /* If ForceStop is required, stop HW immediately */
            if (SPI_TRUE == LblIsForceStop)
            {
              /* If the Sequence is on-going now, stop the HW */
              /* MISRA Violation: START Msg(4:0491)-1 */
              LulHWUnitIndex = Spi_GpFirstJob[LulJobIndex].ucHWUnitIndex;
              /* END Msg(4:0491)-1 */
              /* Force stop CSIX operation */
              Spi_CSIXForceStop(LulHWUnitIndex);
              /* Set the result as FAILED for the force canceled Job */
              Spi_GaaJobStatus[LulJobIndex].enResult = SPI_JOB_FAILED;
              /* References: SPI_DDD_ACT_056_GBL001 */
              /* Set Canceled flag so that this sequence results CANCELED
                 even if this is the last Job in the Sequence */
              Spi_GaaSeqStatus[LulSeqIndex].blCanceled = SPI_TRUE;
              /* References: SPI_DDD_ACT_056_GBL002 */
            }
            else
#endif /* (SPI_FORCE_CANCEL_API == STD_ON) */
            {
#if (SPI_CANCEL_API == STD_ON)
              /* Set CancelRequest flag,
                this flag is ignored if this is the last Job */
              Spi_GaaSeqStatus[LulSeqIndex].blCancelRequested = SPI_TRUE;
              /* References: SPI_DDD_ACT_056_GBL003 */
#endif
            }
            /* Scheduling is required to complete cancellation */
            /* MISRA Violation: START Msg(4:2984)-4 */
            LulRequireScheduling =
              LulRequireScheduling | ((uint32)SPI_ONE << LulQueueIndex);
            /* END Msg(4:2984)-4 */
          }
          else if (SPI_JOB_QUEUED == Spi_GaaJobStatus[LulJobIndex].enResult)
            /* If the SubSequence is not on-going now, remove directly */
          {
            /* Remove all jobs belonging to sequence */
            Spi_RemoveFromQueue(LulQueueIndex, LulSeqIndex);
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
           /* Clear SubSequence Active flag */
           Spi_GaaSeqStatus[LulSeqIndex].ulActiveSubSequences =
             Spi_GaaSeqStatus[LulSeqIndex].ulActiveSubSequences &
             ~((uint32)SPI_ONE << LulQueueIndex);
           /* References: SPI_DDD_ACT_056_GBL004 */
#endif
          }
          else
          {
             /* Do nothing */
          }
        }
        else /* Sequence has not been started, remove all jobs in queue*/
        {
           /* Remove all jobs belonging to sequence */
           Spi_RemoveFromQueue(LulQueueIndex, LulSeqIndex);
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
           /* Clear SubSequence Active flag */
           Spi_GaaSeqStatus[LulSeqIndex].ulActiveSubSequences =
             Spi_GaaSeqStatus[LulSeqIndex].ulActiveSubSequences &
             ~((uint32)SPI_ONE << LulQueueIndex);
           /* References: SPI_DDD_ACT_056_GBL007 */
#endif
        }
      }
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_OFF)
      else
      {
        /* Nothing to do */
      }/* if (SPI_ZERO < LpSubSeqConfig->usNoOfJobs) */
#endif
    } /* for (LulQueueIndex) */

    if ((uint32)SPI_ZERO == LulRequireScheduling)
    {
      /* If all SubSequences were not on-going and removed directly,
        Spi_ProcessSequence is not invoked.
        So SeqEndNotification has to be invoked in this function. */
      Spi_GaaSeqStatus[LulSeqIndex].enResult = SPI_SEQ_CANCELED;
      /* References: SPI_DDD_ACT_056_GBL005 */
      LblRequireSeqEndNotification = SPI_TRUE;
      /* Clear Sequence active bit */
      Spi_GaaActiveSequence[LulSeqIndex / (uint32)SPI_UINT32_BITS] &=
        ~((uint32)SPI_ONE << (LulSeqIndex & (SPI_UINT32_BITS - SPI_ONE)));
      /* References: SPI_DDD_ACT_056_GBL006 */
    }
    else
    {
      /* Nothing to do */
    }
  } /* (SPI_SEQ_PENDING == Spi_GaaSeqStatus[LulSeqIndex].enResult) */
  else
  {
    /* Sequence is not queued, do nothing */
  }
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  /* References: SPI_DDD_ACT_056_CRT002 */

#if (SPI_FORCE_CANCEL_API == STD_ON)
  if (SPI_TRUE == LblIsForceStop)
  {
    /* Interrupt disabling is required for:
       - Exclusive control for re-entrant call of Spi_ForceCancel
       - Prevent invoking of Spi_MainFunction_Handling (ISR) */
    SPI_ENTER_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
    /* References: SPI_DDD_ACT_056_CRT005 */
    Spi_GulCancelingHWUnits &= ~LpSeqConfig->ulUsingHWUnits;
    /* References: SPI_DDD_ACT_056_GBL009 */
    SPI_EXIT_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
    /* References: SPI_DDD_ACT_056_CRT006 */
  }
  else
  {
    /* Nothing to do */
  }
#endif

#if (SPI_FORCE_CANCEL_API == STD_ON)
  /* Invoke Scheduler for each HWUnit which ForceStop is performed on */
  if (((uint32)SPI_ZERO != LulRequireScheduling) &&
      (SPI_TRUE == LblIsForceStop))
  {
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
    for (LulQueueIndex = SPI_ZERO; LulQueueIndex < (uint32)SPI_MAX_QUEUE;
      LulQueueIndex++)
    {
      if ((uint32)SPI_ZERO != (LulRequireScheduling &
        ((uint32)SPI_ONE << LulQueueIndex)))
      {
        /* Get Sub sequence from queue index */
        LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[LulQueueIndex];
        LpSubSeqStat = &Spi_GaaSeqStatus[LulSeqIndex].aaSubSeqs[LulQueueIndex];
        /* MISRA Violation: START Msg(4:0491)-1 */
        LulJobIndex =
          LpSubSeqConfig->pJobList[(LpSubSeqConfig->usNoOfJobs - SPI_ONE) -
            LpSubSeqStat->usRemainJobCount];
        LulHWUnitIndex = Spi_GpFirstJob[LulJobIndex].ucHWUnitIndex;
        /* END Msg(4:0491)-1 */
#endif
        /* MISRA Violation: START Msg(4:2962)-3 */
        Spi_ProcessSequence(LulHWUnitIndex);
        /* END Msg(4:2962)-3 */
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
      }
      else
      {
        /* Nothing to do */
      }
    }
#endif
  }
  else
#endif
  {
    /* If a seq is canceled before start, invoke the notification here */
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
    Spi_InvokeNotifications(NULL_PTR, LpSeqConfig,
      LblRequireSeqEndNotification, NULL_PTR, SPI_FALSE);
#else
    Spi_InvokeNotifications(NULL_PTR, LpSeqConfig,
      LblRequireSeqEndNotification);
#endif
  }
}
#endif /* ((SPI_CANCEL_SPI == STD_ON) || (SPI_FORCE_CANCEL_API == STD_ON)) */

/*******************************************************************************
** Function Name       : Spi_InvokeNotifications
**
** Service ID          : Not Applicable
**
** Description         : This function invokes notification handlers.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : LpPrevJobConfig      - Pointer to Job configuration
**                       LpPrevSeqConfig      - Pointer to Seq configuration
**                       LblSeqFinished       - Whether the prev seq is finished
**                       LpNextSeqConfig      - Pointer to Seq configuration
**                       LblSeqAlreadyStarted - Whether the next Seq has been
**                                              started already
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : None
**
** Function Invoked    : user call back functions
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_InvokeNotifications(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) LpPrevJobConfig,
  CONSTP2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_APPL_CONST) LpPrevSeqConfig,
  CONST(boolean, AUTOMATIC) LblSeqFinished
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  ,
  CONSTP2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_APPL_CONST) LpNextSeqConfig,
  CONST(boolean, AUTOMATIC) LblSeqAlreadyStarted
#endif
  )
/* References: SPI_DDD_ACT_058 */
{
  if ((NULL_PTR != LpPrevJobConfig) &&
    (NULL_PTR != LpPrevJobConfig->pJobEndNotification))
  {
    LpPrevJobConfig->pJobEndNotification();
  }
  else
  {
    /* Nothing to do */
  }

  if ((SPI_TRUE == LblSeqFinished) &&
    (NULL_PTR != LpPrevSeqConfig->pSeqEndNotification))
  {
    LpPrevSeqConfig->pSeqEndNotification();
  }
  else
  {
    /* Nothing to do */
  }

#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  if ((SPI_FALSE == LblSeqAlreadyStarted) &&
    (NULL_PTR != LpNextSeqConfig) &&
    (NULL_PTR != LpNextSeqConfig->pSeqStartNotification))
  {
    LpNextSeqConfig->pSeqStartNotification();
  }
  else
  {
    /* Nothing to do */
  }
#endif
}

/*******************************************************************************
** Function Name       : Spi_ProcessJob
**
** Service ID          : Not Applicable
**
** Description         : This function starts a Job.
**
** Sync/Async          : Asynchronous
**
** Re-entrancy         : Reentrant for different Job
**                       Non-Reentrant for same Job
**
** Input Parameters    : LulJobIndex - Index of the Job
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : Spi_GpFirstJob
**
** Function Invoked    : Spi_CSIXProcessJob
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessJob(
  CONST(uint32, AUTOMATIC) LulJobIndex)
/* References: SPI_DDD_ACT_061 */
{
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpJobConfig = &Spi_GpFirstJob[LulJobIndex];
  /* END Msg(4:0491)-1 */

  /* Process job associated with CSIX */
  Spi_CSIXProcessJob(SPI_TRUE, LpJobConfig, SPI_ASYNCTRANSMIT_SID);
}

/*******************************************************************************
** Function Name       : Spi_CheckSeqFinish
**
** Service ID          : Not Applicable
**
** Description         : This function will handle when a Sequence finished
**                       or aborted
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant for different HWUnit,
**                       Non-Reentrant for same HWUnit
**
** Input Parameters    : LulQueueIndex - Queue index.
**                       LulSeqIndex - Sequence index.
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : Spi_GaaSeqStatus, Spi_GaaActiveSequence
**
** Function Invoked    : Spi_RemoveFromQueue
**
** Registers Used      : None
*******************************************************************************/
static FUNC(boolean, SPI_PRIVATE_CODE) Spi_CheckSeqFinish(
  CONST(uint32, AUTOMATIC) LulQueueIndex,
  CONST(uint32, AUTOMATIC) LulSeqIndex)
/* References: SPI_DDD_ACT_088 */
{
  VAR(uint32, AUTOMATIC) LulRemainJobs;
  VAR(Spi_SeqResultType, AUTOMATIC) LenLastSeqState;
  VAR(boolean, AUTOMATIC) LblSeqFinished;

  LblSeqFinished = SPI_FALSE;

  /*
   * Critical section is required to avoid conflict with
   * StartTransmission and ProcessSequence from other HWUnits
   */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  /* References: SPI_DDD_ACT_088_CRT001 */
  LulRemainJobs =
    Spi_GaaSeqStatus[LulSeqIndex].aaSubSeqs[LulQueueIndex].usRemainJobCount;
  /*
   * If Sequence finished or aborted,
   * clear Sequence active bit and set Sequence result code.
   * If multiple events occur at same time, the priority order of the result is:
   * FAILED > CANCELED(by Spi_ForceCancel) > OK > CANCELED(by Spi_Cancel)
   */
  if (((uint32)SPI_ZERO == LulRemainJobs) ||
      (SPI_TRUE == Spi_GaaSeqStatus[LulSeqIndex].blFailed)
#if (SPI_CANCEL_API == STD_ON)
    || (SPI_TRUE == Spi_GaaSeqStatus[LulSeqIndex].blCancelRequested)
#endif
#if (SPI_FORCE_CANCEL_API == STD_ON)
    || (SPI_TRUE == Spi_GaaSeqStatus[LulSeqIndex].blCanceled)
#endif
  )
  {
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
    /* Clear SubSequence Active flag */
    Spi_GaaSeqStatus[LulSeqIndex].ulActiveSubSequences =
      Spi_GaaSeqStatus[LulSeqIndex].ulActiveSubSequences &
      (uint32)(~((uint32)SPI_ONE << LulQueueIndex));
    /* References: SPI_DDD_ACT_088_GBL001 */
#endif

    /* If a SubSequence is aborted by some reason, remove remained Jobs */
    if ((uint32)SPI_ZERO != LulRemainJobs)
    {
      Spi_RemoveFromQueue(LulQueueIndex, LulSeqIndex);
#if (SPI_CANCEL_API == STD_ON)
      /* If cancel is requested before finish, set the canceled flag */
      Spi_GaaSeqStatus[LulSeqIndex].blCanceled =
        Spi_GaaSeqStatus[LulSeqIndex].blCanceled |
        Spi_GaaSeqStatus[LulSeqIndex].blCancelRequested;
      /* References: SPI_DDD_ACT_088_GBL002 */
#endif
    }
    else
    {
      /* Nothing to do */
    }

    /* When all SubSequences finished, finish Sequence */
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
    if ((uint32)SPI_ZERO !=
      Spi_GaaSeqStatus[LulSeqIndex].ulActiveSubSequences)
    {
      /* There are still active SubSequences, continue the Sequence */
    }
    else
#endif
    {
      LblSeqFinished = SPI_TRUE;
      /* Clear Sequence active bit */
      Spi_GaaActiveSequence[LulSeqIndex / (uint32)SPI_UINT32_BITS] =
        Spi_GaaActiveSequence[LulSeqIndex / (uint32)SPI_UINT32_BITS] &
        ~((uint32)SPI_ONE << (LulSeqIndex & (SPI_UINT32_BITS - SPI_ONE)));
      /* References: SPI_DDD_ACT_088_GBL003 */
      /* Update Sequence Result */
      if (SPI_TRUE == Spi_GaaSeqStatus[LulSeqIndex].blFailed)
      {
        LenLastSeqState = SPI_SEQ_FAILED;
      }
#if ((SPI_CANCEL_API == STD_ON) || (SPI_FORCE_CANCEL_API == STD_ON))
      else if (SPI_TRUE == Spi_GaaSeqStatus[LulSeqIndex].blCanceled)
      {
        LenLastSeqState = SPI_SEQ_CANCELED;
      }
#endif
      else
      {
        LenLastSeqState = SPI_SEQ_OK;
      }
      Spi_GaaSeqStatus[LulSeqIndex].enResult = LenLastSeqState;
      /* References: SPI_DDD_ACT_088_GBL004 */
    }
  } /* if (SubSequence finished) */
  else
  {
    /* Nothing to do */
  }
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  /* References: SPI_DDD_ACT_088_CRT002 */

  return LblSeqFinished;
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
    (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/*******************************************************************************
** Function Name       : Spi_TransmitSyncSequence
**
** Service ID          : Not applicable
**
** Description         : This function transmits a Sequence synchronously.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : LulSeqIndex - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GpFirstSeq, Spi_GaaJobStatus, Spi_GaaSeqStatus
**                       Spi_GaaHWStatus, Spi_GpFirstJob
**
** Function invoked    : Dem_ReportErrorStatus,
**                       Spi_CSIXTransmitSyncJob
**
** Registers Used      : None
*******************************************************************************/
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_TransmitSyncSequence(
  CONST(uint32, AUTOMATIC) LulSeqIndex)
/* References: SPI_DDD_ACT_059 */
{
  P2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSeqConfig;
  P2CONST(Spi_SubSeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSubSeqConfig;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  VAR(uint32, AUTOMATIC) LulJobIndex;
  VAR(uint32, AUTOMATIC) LulJobListIndex;
  VAR(Std_ReturnType, AUTOMATIC) LucResult;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpSeqConfig = &Spi_GpFirstSeq[LulSeqIndex];
  /* END Msg(4:0491)-1 */
  LpSubSeqConfig = &LpSeqConfig->aaSubSeqs[SPI_ZERO];

  /* Update the sequence result variable to SPI_SEQ_PENDING */
  Spi_GaaSeqStatus[LulSeqIndex].enResult = SPI_SEQ_PENDING;
  /* References: SPI_DDD_ACT_059_GBL001 */

  /* Initialize Sequence Status */
  Spi_GaaSeqStatus[LulSeqIndex].blFailed = SPI_FALSE;
  /* References: SPI_DDD_ACT_059_GBL009 */

  /* Update all Job statuses to SPI_JOB_PENDING */
  for (LulJobListIndex = SPI_ZERO;
    LulJobListIndex < (uint32)LpSubSeqConfig->usNoOfJobs;
    LulJobListIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulJobIndex = LpSubSeqConfig->pJobList[LulJobListIndex];
    /* END Msg(4:0491)-1 */
    Spi_GaaJobStatus[LulJobIndex].enResult = SPI_JOB_PENDING;
    /* References: SPI_DDD_ACT_059_GBL002 */
  }

#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  /* Invoke the start sequence notification function */
  if (NULL_PTR != LpSeqConfig->pSeqStartNotification)
  {
    LpSeqConfig->pSeqStartNotification();
  }
  else
  {
    /* No action required */
  }
#endif /* (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON) */

  /* Loop for each Job until any error occurs */
  LucResult = E_OK;
  for (LulJobListIndex = SPI_ZERO;
    ((E_OK == LucResult) && (LulJobListIndex < LpSubSeqConfig->usNoOfJobs));
    LulJobListIndex++)
  {
    /* Transmit a Job */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulJobIndex = LpSubSeqConfig->pJobList[LulJobListIndex];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpJobConfig = &Spi_GpFirstJob[LulJobIndex];
    /* END Msg(4:0491)-1 */
    /* Set HW status */
#if (SPI_HW_STATUS_API == STD_ON)
    Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].blActive = SPI_TRUE;
    /* References: SPI_DDD_ACT_059_GBL003 */
#endif
    Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].ucOngoingSeqIndex =
      (Spi_SequenceType)LulSeqIndex;
    /* References: SPI_DDD_ACT_059_GBL004 */
    Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].usOngoingJobIndex =
      (Spi_JobType)LulJobIndex;
    /* References: SPI_DDD_ACT_059_GBL005 */

    /* Process synchronous job associated with CSIX */
    LucResult = Spi_CSIXTransmitSyncJob(LpJobConfig, SPI_SYNCTRANSMIT_SID);

#if (SPI_HW_STATUS_API == STD_ON)
    /* If this was the last Job or the next Job is assigned to other HW,
       de-activate HW unit */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if ((E_NOT_OK == LucResult) ||
      (LulJobListIndex ==
      ((uint32)LpSubSeqConfig->usNoOfJobs - (uint32)SPI_ONE)) ||
      (Spi_GpFirstJob[LpSubSeqConfig->pJobList[LulJobListIndex +
      (uint32)SPI_ONE]].ucHWUnitIndex != LpJobConfig->ucHWUnitIndex))
    /* END Msg(4:0491)-1 */
    {
      Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex].blActive = SPI_FALSE;
      /* References: SPI_DDD_ACT_059_GBL006 */
    }
    else
    {
      /* Nothing to do */
    }
#endif
  }

  /* Set Sequence result code */
  if (E_OK == LucResult)
  /* References: SPI_DDD_ACT_059_ERR001 */
  {
#if (SPI_AR_VERSION == SPI_AR_422_VERSION)
#if defined(SPI_E_HARDWARE_ERROR)
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
#endif /* (defined(SPI_E_HARDWARE_ERROR)) */
#endif /* (SPI_AR_VERSION == SPI_AR_422_VERSION) */
    Spi_GaaSeqStatus[LulSeqIndex].enResult = SPI_SEQ_OK;
    /* References: SPI_DDD_ACT_059_GBL008 */
  }
  else
  {
    Spi_GaaSeqStatus[LulSeqIndex].enResult = SPI_SEQ_FAILED;
    /* References: SPI_DDD_ACT_059_GBL007 */
  }

#if (SPI_SYNC_SEQ_ENDNOTIFICATION_ENABLED == STD_ON)
  /* Check if the notification function is configured */
  if (NULL_PTR != LpSeqConfig->pSeqEndNotification)
  {
    /* Invoke the notification function */
    LpSeqConfig->pSeqEndNotification();
  }
  else
  {
    /* No action required */
  }
#endif /* (SPI_SYNC_SEQ_ENDNOTIFICATION_ENABLED == STD_ON) */

  return LucResult;
}
#endif /* (SPI_DIRECT_ACCESS_MODE == STD_ON) */
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

#define SPI_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-2 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
