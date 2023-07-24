/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Ram.h                                                   */
/* Version      = V1.0.0                                                      */
/* Date         = 24-Oct-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of SPI  */
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
 *                         1. As per ARDAACH-98, use Spi_GulCancelingHWUnits to
 *                         prevent transmission/reception of related HW units
 *                         during force cancel operation.
 */
/******************************************************************************/

#ifndef SPI_RAM_H
#define SPI_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
#include "Spi_LTTypes.h"
#include "Spi_PBTypes.h"
#include "Spi_Scheduler.h"
#include "Spi_CSIX_LLDriver.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define SPI_RAM_AR_RELEASE_MAJOR_VERSION    SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_RAM_AR_RELEASE_MINOR_VERSION    SPI_AR_RELEASE_MINOR_VERSION
#define SPI_RAM_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_RAM_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION
#define SPI_RAM_SW_MINOR_VERSION SPI_SW_MINOR_VERSION

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
**                      Global Data Types                                     **
*******************************************************************************/
#define SPI_START_SEC_VAR_INIT_BOOLEAN
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Global variable to store the initialization status of SPI Driver */
extern volatile VAR(boolean, SPI_VAR_INIT) Spi_GblInitialized;

#define SPI_STOP_SEC_VAR_INIT_BOOLEAN
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */


#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/* Global variable to store the asynchronous transmission mechanism */
extern volatile VAR(Spi_AsyncModeType, SPI_VAR_NO_INIT) Spi_GenAsyncMode;
#endif

/* Global variable to store config pointer */
extern P2CONST(Spi_ConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA)
  volatile Spi_GpConfigPtr;

/* Global variable to store first channel structure */
extern P2CONST(Spi_ChannelConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA)
  volatile Spi_GpFirstChannel;

/* Global variable to store first job structure */
extern P2CONST(Spi_JobConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA)
  volatile Spi_GpFirstJob;

/* Global variable to store first sequence structure */
extern P2CONST(Spi_SeqConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA)
  volatile Spi_GpFirstSeq;

/* Global variable to store HWUnit information table */
extern P2CONST(Spi_HWUnitInfoType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA)
  volatile Spi_GpFirstHWUnit;

#if (SPI_DMA_CONFIGURED == STD_ON)
/* Global pointer variable for HW group configuration */
extern P2CONST(Spi_DmaConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA)
  volatile Spi_GpFirstDMAUnit;
#endif

/* Hardware statuses */
extern volatile VAR(Spi_HWStatusType, SPI_VAR_NO_INIT)
  Spi_GaaHWStatus[SPI_MAX_HWUNIT];

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/* Queue structures */
extern volatile VAR(Spi_QueueType, SPI_VAR_NO_INIT) Spi_GaaQueue[SPI_MAX_QUEUE];
#endif
/* Sequence statuses and results */
extern volatile VAR(Spi_SeqStatusType, SPI_VAR_NO_INIT)
  Spi_GaaSeqStatus[SPI_MAX_SEQUENCE];
/* Job statuses and results */
extern volatile VAR(Spi_JobStatusType, SPI_VAR_NO_INIT)
  Spi_GaaJobStatus[SPI_MAX_JOB];

#if (SPI_EBDATA_SIZE > 0)
extern volatile VAR(Spi_EBDataType, SPI_VAR_NO_INIT)
  Spi_GaaEBData[SPI_EBDATA_SIZE];
#endif

#if (SPI_SET_CLOCK_MODE_ENABLED == STD_ON)
/* Global variable to store Clock Power mode status of SPI Driver */
extern volatile VAR(Spi_ClockModeType, SPI_VAR_NO_INIT) Spi_GenClockModeStatus;
#endif

/* If Internal Diagnosis Error Buffer size is Greater than Zero */
#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
/* Structure to store hardware error details */
extern volatile VAR(Spi_ErrorBufferType, SPI_VAR_NO_INIT) Spi_GstErrorBuffer;
#endif

#if (SPI_CSIX_RAM_MIRROR == STD_ON)
  /* Global Array for storing Mirror Data */
extern volatile VAR(Spi_CSIXCTLRamMirrorType, SPI_VAR_NO_INIT)
  Spi_GaaCTLRegMirror[SPI_MAX_HWUNIT];
#if (SPI_CSIH_CONFIGURED == STD_ON)
extern volatile VAR(Spi_CSIHRamMirrorType, SPI_VAR_NO_INIT)
  Spi_GaaCSIHRegMirror[SPI_MAX_HWUNIT];
#endif
#if (SPI_CSIG_CONFIGURED == STD_ON)
extern volatile VAR(Spi_CSIGRamMirrorType, SPI_VAR_NO_INIT)
  Spi_GaaCSIGRegMirror[SPI_MAX_HWUNIT];
#endif
#endif /* (SPI_CSIX_RAM_MIRROR == STD_ON) */

#if (SPI_DMA_CONFIGURED == STD_ON) && (SPI_DMA_RAM_MIRROR == STD_ON)
/* Global array to store DMA Register Mirror data */
extern volatile VAR(Spi_DMARamMirrorType, SPI_VAR_NO_INIT)
  Spi_GaaDMAChannelRegsMirror[SPI_MAX_DMA_CHANNELS];
#endif


#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */


#define SPI_START_SEC_VAR_NO_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/* Bit array indicates active HWUnitIndexes used by sync transmission */
extern volatile VAR(uint32, SPI_VAR_NO_INIT) Spi_GulActiveSyncHWUnits;
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/* Bit array indicates active Queues */
extern volatile VAR(uint32, SPI_VAR_NO_INIT) Spi_GulAllQueueSts;
/* Bit array indicates active Sequences */
extern volatile VAR(uint32, SPI_VAR_NO_INIT)
  Spi_GaaActiveSequence[SPI_BITS_TO_WORDS(SPI_MAX_SEQUENCE)];
#endif

#if (SPI_MAX_CHANNEL_BUFFER_SIZE > SPI_ZERO)
/* Channel buffer, includes all tx and rx buffers for all channels
   This buffer should be aligned to 4byte for 32bit access */
extern volatile VAR(uint32, SPI_VAR_NO_INIT)
  Spi_GaaChannelBuffer[SPI_MAX_CHANNEL_BUFFER_SIZE / sizeof(uint32)];
#endif

#if (SPI_DMA_CONFIGURED == STD_ON)
/* Dummy destination if read data is not necessary */
extern volatile VAR(uint32, SPI_VAR_NO_INIT) Spi_GaaDmaRxData[SPI_MAX_HWUNIT];
#endif

#if (SPI_FORCE_CANCEL_API == STD_ON)
/* Bit array indicates HWUnits is being canceled by Spi_ForceCacel */
extern volatile VAR(uint32, SPI_VAR_NO_INIT) Spi_GulCancelingHWUnits;
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* SPI_RAM_H */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
