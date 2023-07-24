/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Scheduler.h                                             */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Nov-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the external declarations of global SPI Driver functions*/
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
 *          12-Nov-2019  : As per static test result, remove un-used parameter
 *                         of the function, Spi_ProcessSequence().
 */
/******************************************************************************/

#ifndef SPI_SCHEDULER_H
#define SPI_SCHEDULER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
#include "Spi_Types.h"
#include "Spi_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_SCHEDULER_AR_RELEASE_MAJOR_VERSION   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_SCHEDULER_AR_RELEASE_MINOR_VERSION   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_SCHEDULER_AR_RELEASE_REVISION_VERSION \
                                                 SPI_AR_RELEASE_REVISION_VERSION
/* File version information */
#define SPI_SCHEDULER_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION
#define SPI_SCHEDULER_SW_MINOR_VERSION SPI_SW_MINOR_VERSION

/******************************************************************************/
/**                      QAC Warning                                         **/
/******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                  directive.                                                */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The name of an include file has been specified using a     */
/*                 macro. This is not recommended in some coding standards.   */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Invalid Sequence index. Valid range is 0..254. */
#define SPI_INVALID_SEQUENCE   ((Spi_SequenceType)255U)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Status variables for each SubSeqeunce  */
typedef struct STag_Spi_SubSeqStatusType
{
  /* Remain Job count in this Queue */
  VAR(uint16, TYPEDEF) usRemainJobCount;
  /* List connectors in this Queue */
  VAR(Spi_SequenceType, TYPEDEF) aaNext[SPI_MAX_PRIORITY + SPI_ONE];
  VAR(Spi_SequenceType, TYPEDEF) aaPrev[SPI_MAX_PRIORITY + SPI_ONE];
} Spi_SubSeqStatusType;

/* Status for each Sequence */
typedef struct STag_Spi_SeqStatusType
{
  /* Sequence result status */
  VAR(Spi_SeqResultType, TYPEDEF) enResult;
  /* Whether any SubSequence failed */
  VAR(boolean, TYPEDEF) blFailed;
#if (SPI_LEVEL_DELIVERED != SPI_LEVEL_0)
#if (SPI_CANCEL_API == STD_ON)
  /* Whether cancel is requested */
  VAR(boolean, TYPEDEF) blCancelRequested;
#endif
#if ((SPI_CANCEL_API == STD_ON) || (SPI_FORCE_CANCEL_API == STD_ON))
  /* Whether any SubSequence has been canceled */
  VAR(boolean, TYPEDEF) blCanceled;
#endif
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  /* Whehter any SubSequence has been started */
  VAR(boolean, TYPEDEF) blStarted;
#endif
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
  /* Active bit array for each SubSequence */
  VAR(uint32, TYPEDEF) ulActiveSubSequences;
#endif
  /* Status for each Queue */
  VAR(Spi_SubSeqStatusType, TYPEDEF) aaSubSeqs[SPI_MAX_QUEUE];
#endif /* (SPI_LEVEL_DELIVERED != SPI_LEVEL_0) */
} Spi_SeqStatusType;

/* Status for each Job */
typedef struct STag_Spi_JobStatusType
{
  /* Job result status */
  VAR(Spi_JobResultType, TYPEDEF) enResult;
} Spi_JobStatusType;

/* Structure of Queue */
typedef struct STag_Spi_QueueType
{
  /* Existence flags for each priority */
  VAR(uint8, TYPEDEF) ucExists;
  /* The index of ongoing sequence */
  VAR(Spi_SequenceType, TYPEDEF) ucOngoingSeqIndex;
  /* List connectors of the top job for each priority */
  VAR(Spi_SequenceType, TYPEDEF) aaTop[SPI_MAX_PRIORITY + SPI_ONE];
  /* List connectors of the tail job for each priority */
  VAR(Spi_SequenceType, TYPEDEF) aaTail[SPI_MAX_PRIORITY + SPI_ONE];
} Spi_QueueType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define SPI_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
 (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

extern FUNC(void, SPI_PRIVATE_CODE) Spi_StartTransmission(
  VAR(uint32, AUTOMATIC) LulSeqIndex);

extern FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessSequence(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex);

#if ((SPI_CANCEL_API == STD_ON) || (SPI_FORCE_CANCEL_API == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CancelSequence(
  CONST(uint32, AUTOMATIC) LulSeqIndex,
  CONST(boolean, AUTOMATIC) LblIsForceStop,
  CONST(uint8, AUTOMATIC) LucApiId);
#endif

extern FUNC(void, SPI_PRIVATE_CODE) Spi_RemoveFromQueue(
  CONST(uint32, AUTOMATIC) LulQueueIndex,
  CONST(uint32, AUTOMATIC) LulSeqIndex);

#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
 (SPI_LEVEL_DELIVERED == SPI_LEEVEL_2)) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
 (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_TransmitSyncSequence(
  CONST(uint32, AUTOMATIC) LulSeqIndex);

#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
 (SPI_LEVEL_DELIVERED == SPI_LEEVEL_2)) */

#define SPI_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* SPI_SCHEDULER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
