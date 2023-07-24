/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_PBTypes.h                                               */
/* Version      = V1.0.0                                                      */
/* Date         = 25-Oct-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions for post-build time parameters     */
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
 * V1.0.0:  12-Mar-2019  : Initial Version.
 *          25-Oct-2019  : Add QAC message (4:0857).
 */
/******************************************************************************/

#ifndef SPI_PBTYPES_H
#define SPI_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
/* Included for Spi type declarations */
#include "Spi_Types.h"
#include "Spi_LTTypes.h"
#include "Spi_DMAC_LLDriver.h"
#if (SPI_AR_VERSION == SPI_AR_403_VERSION)
#include "Spi_Cbk.h"
#endif
#if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Spi.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_PBTYPES_AR_RELEASE_MAJOR_VERSION    SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_PBTYPES_AR_RELEASE_MINOR_VERSION    SPI_AR_RELEASE_MINOR_VERSION
#define SPI_PBTYPES_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_PBTYPES_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION
#define SPI_PBTYPES_SW_MINOR_VERSION SPI_SW_MINOR_VERSION

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/* Justification : Function can't be used in initializing expressions of      */
/*                 const value, or macro is better in point of performance.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-1 and                           */
/*                 END Msg(4:3453)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) [L] Number of macro definitions exceeds 1024 -    */
/*                  program does not conform strictly to ISO:C90.             */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-2 and                           */
/*                 END Msg(4:0857)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Calculate word size to hold bits */
/* MISRA Violation: START Msg(4:3453)-1 */
/* MISRA Violation: START Msg(4:0857)-2 */
#define SPI_BITS_TO_WORDS(bits) (((uint32)(bits) + 31UL) / 32UL)
/* END Msg(4:0857)-2 */
/* END Msg(4:3453)-1 */
/* Extend address to the next 64bit align. Add 7 and clear the lowest 3bits.  */
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_ALIGN_8(address)   (((uint32)(address) + 7UL) & (uint32)(~7UL))
/* END Msg(4:3453)-1 */

/* Bit length */
#define SPI_UINT32_BITS         32U

/* CS polarity */
#define SPI_CS_HIGH             SPI_TRUE
#define SPI_CS_LOW              SPI_FALSE

/* Macro for unit not configured DMA */
#define SPI_INVALID_DMAUNIT     (uint8)0xFF

/*******************************************************************************
**                      SchM Critical Section Protection Macros               **
*******************************************************************************/
#if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
#define SPI_ENTER_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Enter_Spi_##Exclusive_Area()

/* MISRA Violation: START Msg(4:0857)-2 */
#define SPI_EXIT_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Exit_Spi_##Exclusive_Area()
/* END Msg(4:0857)-2 */
#else
#define SPI_ENTER_CRITICAL_SECTION(Exclusive_Area)
#define SPI_EXIT_CRITICAL_SECTION(Exclusive_Area)
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Definition of macro types */
typedef enum ETag_Spi_HWUnitMacroType
{
  /* CSIG */
  SPI_MACRO_CSIG,
  /* CSIH */
  SPI_MACRO_CSIH
} Spi_HWUnitMacroType;

/* Definition of MemoryMode for CSIH */
typedef enum ETag_Spi_MemoryModeType
{
  /* Direct access mode */
  SPI_MEMMODE_DIRECT_ACCESS,
  /* Fifo buffer mode */
  SPI_MEMMODE_FIFO,
  /* Dual buffer mode */
  SPI_MEMMODE_DUAL_BUFFER,
  /* Tx only mode */
  SPI_MEMMODE_TX_ONLY
} Spi_MemoryModeType;

/* Definition of Channel buffer types */
typedef enum ETag_Spi_ChannelBufferType
{
  /* Software internal buffer */
  SPI_BUFFER_TYPE_IB = 0,
  /* External buffer from user application */
  SPI_BUFFER_TYPE_EB,
  /* Hardware TX internal buffer */
  SPI_BUFFER_TYPE_TX_HWIB,
  /* Both Hardware TX and RX internal buffer */
  SPI_BUFFER_TYPE_DUAL_HWIB
} Spi_ChannelBufferType;

/* Definition of chip select type */
typedef enum ETagSpi_CSType
{
  SPI_DISABLE_CS = 0,
  SPI_GPIO_CS,
  SPI_PERIPHERAL_ENGINE_CS
} Spi_CSType;

/* Structure for channel configuration */
typedef struct STag_Spi_ChannelConfigType
{
  /* Bit width of each data element (2 to 32) */
  VAR(uint8, TYPEDEF) ucDataWidth;
  /* Byte size of each data element in memory (1, 2, 4) */
  VAR(uint8, TYPEDEF) ucByteSize;
  /* Default value of the channel */
  VAR(uint32, TYPEDEF) ulDefaultData;
  /* Channel buffer type (IB, EB, TX_HWIB, DUAL_HWIB) */
  VAR(Spi_ChannelBufferType, TYPEDEF) enChannelBufferType;
  /* Number of IB or maximum size of EB */
  VAR(uint16, TYPEDEF) usNoOfBuffers;
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
  /* Pointer to the tx data buffer */
  volatile P2VAR(Spi_DataBufferType, TYPEDEF, SPI_CONFIG_DATA) pTxBuffer;
  /* Pointer to the rx data buffer */
  volatile P2VAR(Spi_DataBufferType, TYPEDEF, SPI_CONFIG_DATA) pRxBuffer;
#endif
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
  /* Pointer to the EB information structure */
  volatile P2VAR(Spi_EBDataType, TYPEDEF, SPI_CONFIG_DATA) pEBData;
#endif
  /* DLS and DIR field of CSIHnCFG register */
  VAR(uint32, TYPEDEF) ulCSIXCFG;
#if ((SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) ||\
  (SPI_TX_ONLY_MODE == STD_ON))
  /* Index of first job that channel linked to */
  VAR(uint32, TYPEDEF) ulFirstJobIndex;
#endif
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  /* HW buffer index corresponding to CSIH HW buffer */
  VAR(uint32, TYPEDEF) ulHWBufferIndex;
#endif
} Spi_ChannelConfigType;

/* Structure for job configuration */
typedef struct STag_Spi_JobConfigType
{
  /* Number of channels in the list */
  VAR(uint8, TYPEDEF) ucNoOfChannels;
  /* Pointer to list of channels */
  P2CONST(Spi_ChannelType, TYPEDEF, SPI_CONFIG_DATA) pChannelList;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
  /* Pointer to callback notification */
  P2FUNC(void, SPI_APPL_DATA, pJobEndNotification)(void);
#endif
  /* Index of HWUnit which this Job associated to */
  VAR(Spi_HWUnitType, TYPEDEF) ucHWUnitIndex;
  /* Chip select type which this Job associated to */
  VAR(Spi_CSType, TYPEDEF) enCSType;
#if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Number of CS to be activated when HWUnit is CSIH */
  VAR(uint8, TYPEDEF) ucNoOfCS;
  /* Index of CSIHnCFGx register for each CS */
  P2CONST(uint8, TYPEDEF, SPI_CONFIG_DATA) pCSArray;
  /* CSIHnCS0..7 bits of CSIHnTX0W register */
  VAR(uint8, TYPEDEF) ucCSIHCSInfo;
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
  /* Job priority */
  VAR(uint8, TYPEDEF) ucJobPriority;
#endif
  /* All Channels properties for CSIX are same*/
  VAR(boolean, TYPEDEF) blChannelPropertySame;
  /* Value of CSIXnCTL1 register */
  VAR(uint32, TYPEDEF) ulCSIXCTL1;
  /* Value of CSIXnCTL2 register */
  VAR(uint16, TYPEDEF) usCSIXCTL2;
  /* Value of CSIXnBRS register */
  VAR(uint16, TYPEDEF) usCSIXBRS;
#if (SPI_SET_CLOCK_MODE_ENABLED == STD_ON)
  /* Value of CSIXnCTL2 register in low power mode */
  VAR(uint16, TYPEDEF) usCSIXCTL2LowPower;
  /* Value of CSIXnBRS register in low power mode */
  VAR(uint16, TYPEDEF) usCSIXBRSLowPower;
#endif
  /* Value of CSIXnCFG register except DLS and DIR fields */
  VAR(uint32, TYPEDEF) ulCSIXCFG;
#if (SPI_DMA_CONFIGURED == STD_ON)
  /* Index of DMA for Tx side */
  VAR(uint8, TYPEDEF) ucTxDmaIndex;
  /* Index of DMA for Rx side */
  VAR(uint8, TYPEDEF) ucRxDmaIndex;
#endif /* (SPI_DMA_CONFIGURED == STD_ON) */
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON) || \
  (SPI_TX_ONLY_MODE == STD_ON))
  /* Value of CSIHMCTL0 register including memory mode selected and
     time-out setting in FIFO mode*/
  VAR(uint16, TYPEDEF) usCSIHMCTL0;
#endif
#if (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)
  /* Total 16-bit Hw buffers in all channels associated with this job */
  VAR(uint16, TYPEDEF) usNoOfHwBuffers;
#endif
#if (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON)
  /* Address of PSR of gpio chip select port associated with this job */
  volatile P2VAR(uint32, TYPEDEF, REGSPACE) pPSRReg;
  /* Port pin mask of gpio chip select port pin associated with this job */
  VAR(uint32, TYPEDEF) ulPortPinMask;
  /* Timing between clock start and chip select activated */
  VAR(uint32, TYPEDEF) ulClk2CsCount;
  /* Chip select polarity */
  VAR(boolean, TYPEDEF) blCsPolarity;
#endif /* (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON) */
} Spi_JobConfigType;

/* Structure contains Job list for each Queue */
typedef struct STag_Spi_SubSeqConfigType
{
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
  /* Bit array indicating priorities used byte this Sequence */
  VAR(uint8, TYPEDEF) ucUsingPriorities;
#endif
  /* Number of Jobs in the list */
  VAR(uint16, TYPEDEF) usNoOfJobs;
  /* Pointer to the array of Jobs */
  P2CONST(Spi_JobType, TYPEDEF, SPI_CONFIG_DATA) pJobList;
} Spi_SubSeqConfigType;

/* Structure for sequence configuration */
typedef struct STag_Spi_SeqConfigType
{
  /* Bit array indicating HWUnits used by this Sequence */
  VAR(uint32, TYPEDEF) ulUsingHWUnits;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
  (SPI_SYNC_SEQ_ENDNOTIFICATION_ENABLED == STD_ON))
  /* Pointer to start sequence callback notification */
  P2FUNC(void, SPI_APPL_DATA, pSeqEndNotification)(void);
#endif
#if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  /* Pointer to start sequence callback notification */
  P2FUNC(void, SPI_APPL_DATA, pSeqStartNotification)(void);
#endif
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* Sequence is synchronous or asynchronous */
  VAR(boolean, TYPEDEF) blSynchronous;
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
  /* Sequence to be interrupted or not */
  VAR(boolean, TYPEDEF) blInterruptible;
#endif
  /* Bit array indicating other Sequences that share Jobs with this Sequence */
  VAR(uint32, TYPEDEF)
    aaJobSharedSequences[SPI_BITS_TO_WORDS(SPI_MAX_SEQUENCE)];
#endif
  /* Job list for each Queue */
  VAR(Spi_SubSeqConfigType, TYPEDEF) aaSubSeqs[SPI_MAX_QUEUE];
} Spi_SeqConfigType;

/*******************************************************************************
** Structure for DMAC Registers, which are used to read or write              **
** the status or configured values for proper working of the DMAC             **
*******************************************************************************/
/* Structure for DMA channel configuration */
typedef struct STag_Spi_DmaConfigType
{
  /* Base address of DMA channel registers */
  volatile P2VAR(Spi_DMAChRegType, TYPEDEF, REGSPACE) pDmaRegs;
  /* EIC register address for DMA interrupt */
  volatile P2VAR(uint16, TYPEDEF, REGSPACE) pICDma;
  /* Tx/Rx DMA transfer source number of assigned CSIH unit */
  VAR(uint8, TYPEDEF) ucTriggerNumber;
  /* Index of HWUnitInfo for assigned SPI unit */
  VAR(Spi_HWUnitType, TYPEDEF) ucSPIHWUnit;
  /* Indicate this DMA assigned to Rx side or Tx side */
  VAR(boolean, TYPEDEF) blRxSide;
} Spi_DmaConfigType;

/* Structure for hardware unit information */
typedef struct STag_Spi_HWUnitInfoType
{
  /* Macro type of this HWUnit */
  VAR(Spi_HWUnitMacroType, TYPEDEF) enMacroType;
  /* The physical index of HWUnit, 'n' of CSIXn */
  VAR(uint8, TYPEDEF) ucPhysicalIndex;
  /* Memory mode when macro is CSIH */
  VAR(Spi_MemoryModeType, TYPEDEF) enMemoryMode;
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* Whether the HW Unit is synchronous or asynchronous */
  VAR(boolean, TYPEDEF) blSynchronous;
#endif
  /* Default value of CSIXnCTL0 register */
  VAR(uint8, TYPEDEF) ucCTL0DefaultValue;
  /* Value of status bits in CSIXnSTCR0/CSIXnSTCR0 register */
  VAR(uint16, TYPEDEF) usSTCR0MaskValue;
} Spi_HWUnitInfoType;

/*******************************************************************************
**                      Global Declarations                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* SPI_PBTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
