/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Types.h                                                 */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Mar-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
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
 * V1.0.0:  12-Mar-2019  : Initial Version
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef SPI_TYPES_H
#define SPI_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for pre-compile options */
#include "Spi_Cfg.h"

/* AUTOSAR standard types */
#include "ComStack_Types.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_AR_422_VERSION                    422
#define SPI_AR_403_VERSION                    403
#define SPI_TYPES_AR_RELEASE_MAJOR_VERSION    SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_TYPES_AR_RELEASE_MINOR_VERSION    SPI_AR_RELEASE_MINOR_VERSION
#define SPI_TYPES_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_TYPES_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_TYPES_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define SPI_LEVEL_0                0U
#define SPI_LEVEL_1                1U
#define SPI_LEVEL_2                2U
#define SPI_IB                     0U
#define SPI_EB                     1U
#define SPI_IBEB                   2U

#define SPI_LB_NONE                0U
#define SPI_LB_INIT                1U
#define SPI_LB_INIT_RUNTIME        2U

#define SPI_ECC_NONE               0U
#define SPI_ECC_INIT               1U
#define SPI_ECC_INIT_RUNTIME       2U

/*******************************************************************************
**                         DEM TYPE CASTING                                   **
*******************************************************************************/

/*******************************************************************************
**                      SPI TYPE DEFINITION                                   **
*******************************************************************************/

/* Definition of status type */
typedef enum ETagSpi_StatusType
{
  /* The SPI Handler/Driver is not initialized or not usable */
  SPI_UNINIT = 0,
  /* The SPI Handler/Driver is not currently transmitting any Job */
  SPI_IDLE,
  /* The SPI Handler/Driver is performing a SPI Job */
  SPI_BUSY
} Spi_StatusType;

typedef enum ETagSpi_JobResultType
{
  /* The last transmission of the Job has been finished successfully */
  SPI_JOB_OK = 0,
  /* The Job is ongoing */
  SPI_JOB_PENDING,
  /* The last transmission of the Job has failed */
  SPI_JOB_FAILED,
  /* The transmission request has been accepted but not started yet */
  SPI_JOB_QUEUED
} Spi_JobResultType;

typedef enum ETagSpi_SeqReultType
{
  /* The last transmission of the Sequence has been finished successfully */
  SPI_SEQ_OK = 0,
  /* The Sequence is ongoing or queued but not finished yet */
  SPI_SEQ_PENDING,
  /* The last transmission of the Sequence has failed */
  SPI_SEQ_FAILED,
  /* The last transmission of the Sequence has been canceled */
  SPI_SEQ_CANCELED
} Spi_SeqResultType;

/* Definition of type for asynchronous mode */
typedef enum ETag_Spi_AsyncModeType
{
  /* Polling mode  for async transmission */
  SPI_POLLING_MODE = 0,
  /* Interrupt mode for async transmission */
  SPI_INTERRUPT_MODE
} Spi_AsyncModeType;

/* Definition of type for application data buffer elements */
#if (SPI_AR_VERSION == SPI_AR_422_VERSION)
/* In AR4.2.2, Type of application data buffer elements is uint8 */
typedef uint8 Spi_DataBufferType;
#elif (SPI_AR_VERSION == SPI_AR_403_VERSION)
/* In ARS4.0.3, Spi_DataType is fixed as unit8 same as ARS4.2.2 */
typedef uint8 Spi_DataType;
#define Spi_DataBufferType    Spi_DataType
#endif

/* Definition of type for number of data elements */
typedef uint16 Spi_NumberOfDataType;

/* Definition of type for channel ID */
typedef uint8 Spi_ChannelType;

/* Definition of type for job ID */
typedef uint16 Spi_JobType;

/* Definition of type for sequence ID */
typedef uint8 Spi_SequenceType;

/* Definition of type for hardware unit ID */
typedef uint8 Spi_HWUnitType;

#if (SPI_SET_CLOCK_MODE_ENABLED == STD_ON)
/* Definition of type for Clock mode */
typedef enum ETagSpi_ClockModeType
{
  SPI_CLOCK_MODE_NORMAL = 0,
  SPI_CLOCK_MODE_LOW_POWER
} Spi_ClockModeType;
#endif

/* If Internal Diagnosis Error Buffer size is Greater than Zero */
#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
/* Type of Different Hardware Errors */
typedef enum  ETag_Spi_HWErrorsType
{
  /* No Hardware Error */
  SPI_NO_ERROR = 0,
  /* Over Run Error */
  SPI_OVERRUN_ERROR,
  /* Parity Error */
  SPI_PARITY_ERROR,
  /* Data Consistency Error */
  SPI_DATA_CONSISTENCY_ERROR,
  /* Overflow Error */
  SPI_OVERFLOW_ERROR,
  /* Slave time out Error */
  SPI_SLAVE_TIME_OUT_ERROR
}Spi_HWErrorsType;

/* Structure for Hardware Error Reporting */
typedef struct STag_Spi_CommErrorType
{
  /* Type of the Hardware Error */
  VAR(Spi_HWErrorsType, TYPEDEF) enErrorType;
  /* HW unit in which error is reported */
  VAR(Spi_HWUnitType, TYPEDEF) ucHwUnit;
  /* Sequence id for which error is reported */
  VAR(Spi_SequenceType, TYPEDEF) ucSeqID;
  /* Job id for which error is reported */
  VAR(Spi_JobType, TYPEDEF) usJobID;
}Spi_CommErrorType;

/* Structure for Diag buffer */
typedef struct Stag_Spi_ErrorBufferType
{
  /* Buffer contains error information */
  Spi_CommErrorType aaErrorInfo[SPI_MAX_ERROR_BUFFER_SIZE];
  /* Buffer index to store next error */
  VAR(uint8, TYPEDEF) ucNextIndex;
}Spi_ErrorBufferType;
#endif

/* Definition of type for self test */
#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
typedef enum ETag_Spi_SelfTestReturnType
{
  SPI_SELFTEST_DRIVERBUSY = 0,
  SPI_SELFTEST_PASSED,
  SPI_SELFTEST_FAILED
}Spi_SelfTestReturnType;
#endif

/* Structure for HW consistency check */
typedef enum Etag_Spi_HWConsistencyModeType
{
  /* Hardware Consistency type Static */
  SPI_STATIC = 0,
  /* Hardware Consistency type Dynamic */
  SPI_DYNAMIC
}Spi_HWConsistencyModeType;

/*******************************************************************************
**                      Structure declarations                                **
*******************************************************************************/

/* Data Structure for SPI Handler/Driver initialization */
typedef struct STag_Spi_ConfigType
{
  /* Database start value */
  VAR(uint32, TYPEDEF) ulStartOfDbToc;
  /* Element number of pHWUnitInfo */
  VAR(uint8, TYPEDEF) ucNoOfHWUnits;
  /* Element number of pChannelConfig */
  VAR(uint8, TYPEDEF) ucNoOfChannels;
  /* Element number of pJobConfig */
  VAR(uint16, TYPEDEF) usNoOfJobs;
  /* Element number of pSequenceConfig */
  VAR(uint8, TYPEDEF) ucNoOfSequences;
#if (SPI_DMA_CONFIGURED == STD_ON)
  /* Element number of pDMAUnitInfo */
  VAR(uint8, TYPEDEF) ucNoOfDMAChannels;
#endif
  /* Pointer to HW Info configuration */
  P2CONST(void, TYPEDEF, SPI_CONFIG_DATA) pHWUnitInfo;
  /* Pointer to Channel configuration */
  P2CONST(void, TYPEDEF, SPI_CONFIG_DATA) pChannelConfig;
  /* Pointer to Job configuration */
  P2CONST(void, TYPEDEF, SPI_CONFIG_DATA) pJobConfig;
  /* Pointer to Sequence configuration */
  P2CONST(void, TYPEDEF, SPI_CONFIG_DATA) pSequenceConfig;
#if (SPI_DMA_CONFIGURED == STD_ON)
  /* Pointer to DMA configuration */
  P2CONST(void, TYPEDEF, SPI_CONFIG_DATA) pDMAUnitInfo;
#endif
  /* Timeout loop count */
  VAR(uint32, TYPEDEF) ulTimeoutCount;
#if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Lookup table to get HWUnitIndex from physical index of CSIH */
  P2CONST(uint8, TYPEDEF, SPI_CONFIG_DATA) pCSIHToHWUnit;
#endif
#if (SPI_CSIG_CONFIGURED == STD_ON)
  /* Lookup table to get HWUnitIndex from physical index of CSIG */
  P2CONST(uint8, TYPEDEF, SPI_CONFIG_DATA) pCSIGToHWUnit;
#endif
#if (SPI_DMA_CONFIGURED == STD_ON)
  /* Lookup table to get HWUnitIndex of CSIX from physical index of DMA*/
  P2CONST(uint8, TYPEDEF, SPI_CONFIG_DATA) pDMAToHWUnit;
#endif
} Spi_ConfigType;


#endif /* SPI_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
