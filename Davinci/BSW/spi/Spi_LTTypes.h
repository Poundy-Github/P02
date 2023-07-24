/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_LTTypes.h                                               */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Mar-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions for link time parameters           */
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
 */
/******************************************************************************/

#ifndef SPI_LTTYPES_H
#define SPI_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_LTTYPES_AR_RELEASE_MAJOR_VERSION   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_LTTYPES_AR_RELEASE_MINOR_VERSION   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_LTTYPES_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_LTTYPES_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_LTTYPES_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define SPI_DBTOC_VALUE (uint32)(((uint32)SPI_VENDOR_ID_VALUE << 22U) | \
                                  ((uint32)SPI_MODULE_ID_VALUE << 14U) | \
                                  ((uint32)SPI_SW_MAJOR_VERSION_VALUE << 8U) | \
                                  ((uint32)SPI_SW_MINOR_VERSION_VALUE << 3U))

#define SPI_ZERO                      0x00U
#define SPI_ONE                       0x01U
#define SPI_TWO                       0x02U
#define SPI_THREE                     0x03U
#define SPI_FOUR                      0x04U
#define SPI_FIVE                      0x05U
#define SPI_SIX                       0x06U
#define SPI_SEVEN                     0x07U
#define SPI_EIGHT                     0x08U
#define SPI_NINE                      0x09U
#define SPI_TEN                       0x0AU
#define SPI_ELEVEN                    0x0BU
#define SPI_TWELVE                    0x0CU
#define SPI_THIRTEEN                  0x0DU
#define SPI_FOURTEEN                  0x0EU
#define SPI_FIFTEEN                   0x0FU
#define SPI_SIXTEEN                   0x10U
#define SPI_THIRTY                    0x1EU

#define SPI_TRUE                      (boolean)0x01
#define SPI_FALSE                     (boolean)0x00

#define SPI_MAX_PRIORITY              (uint8)0x03

/* Structure for storing external buffer attributes */
typedef struct STag_Spi_EBDataType
{
  /* Pointer to external buffer source data */
  P2CONST(Spi_DataBufferType, TYPEDEF, SPI_APPL_DATA) pSrcPtr;
  /* Pointer to external buffer destination data */
  P2VAR(Spi_DataBufferType, TYPEDEF, SPI_APPL_DATA) pDestPtr;
  /* Length of external buffer */
  VAR(Spi_NumberOfDataType, TYPEDEF) usEBLength;
} Spi_EBDataType;

/* Structure for the status for each CSIX unit */
typedef struct STag_Spi_HWStatusType
{
#if (SPI_HW_STATUS_API == STD_ON)
  /* Whether this HWUnit is active */
  VAR(boolean, TYPEDEF) blActive;
#endif
  /* Index of Sequence which is going on this HWUnit */
  VAR(Spi_SequenceType, TYPEDEF) ucOngoingSeqIndex;
  /* Index of Job which is going on this HWUnit */
  VAR(Spi_JobType, TYPEDEF) usOngoingJobIndex;
  /* Index of queue corresponding to on-going job on this HWUnit */
  VAR(uint32, TYPEDEF) ulOngoingQueueIndex;
  /* Index of Channel which should be accessed at the next transmission */
  VAR(Spi_ChannelType, TYPEDEF) ucTxChannelCount;
  /* Index of Channel which should be accessed at the next reception */
  VAR(Spi_ChannelType, TYPEDEF) ucRxChannelCount;
  /* Number of remained tx data elements of the current Channel
     in Direct Access or Fifo mode or of the current Job in Dual buffer mode */
  VAR(Spi_NumberOfDataType, TYPEDEF) usRemainedTxCount;
  /* Number of remained rx data elements of the current Channel
     in Direct Access or Fifo mode or of the current Job in Dual buffer mode */
  VAR(Spi_NumberOfDataType, TYPEDEF) usRemainedRxCount;
#if ((SPI_FIFO_MODE == STD_ON) || (SPI_DIRECT_ACCESS_MODE == STD_ON)) || \
  (SPI_TX_ONLY_MODE == STD_ON)
  /* Pointer to tx buffer */
  volatile P2CONST(Spi_DataBufferType, TYPEDEF, SPI_APPL_DATA) pTxPtr;
  /* Pointer to rx buffer */
  volatile P2VAR(Spi_DataBufferType, TYPEDEF, SPI_APPL_DATA) pRxPtr;
#endif /* ((SPI_FIFO_MODE == STD_ON) || (SPI_DIRECT_ACCESS_MODE == STD_ON)) || \
  (SPI_TX_ONLY_MODE == STD_ON) */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* Whether the first half of 32bit data is going on tx side */
  VAR(boolean, TYPEDEF) blTxEDLOngoing;
  /* Whether the second half of 32bit data is going on rx side */
  VAR(boolean, TYPEDEF) blRxEDLOngoing;
  /* Second half of 32bit data that will be written in the next transmission */
  VAR(uint32, TYPEDEF) ulTxEDLSecondWord;
  /* First half of 32bit data that was received */
  VAR(uint16, TYPEDEF) usRxEDLFirstWord;
#endif /* (SPI_EXTENDED_DATA_LENGTH == STD_ON)*/
#if (SPI_FIFO_MODE == STD_ON)
  /* Fifo Tx buffer status */
  VAR(boolean, TYPEDEF) blIsTxBufferFull;
  /* Fifo Rx buffer status */
  VAR(boolean, TYPEDEF) blIsRxBufferFull;
#endif /* (SPI_FIFO_MODE == STD_ON) */
} Spi_HWStatusType;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* SPI_LTTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
