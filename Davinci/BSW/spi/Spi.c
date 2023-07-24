/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi.c                                                       */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Nov-2019                                                 */
/*============================================================================*/
/*                               COPYRIGHT                                    */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the implementations AUTOSAR specified APIs for SPI      */
/* handler.                                                                   */
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
 *          25-Oct-2019  : The following changes are made:
 *                         1. As per ARDAACH-89, add wrapper macros for internal
 *                         vars in Spi_SetClockMode, Spi_CheckHWConsistency.
 *                         2. As per ARDAACH-99, rename LucReturnValue to
 *                         LucDetCheckResult in Spi_GetErrorInfo.
 *          12-Nov-2019  : The following changes are made:
 *                         1. As per ARDAACH-144, disable CSIX interrupts
 *                         before loopback self-test execution in Spi_Init.
 *                         2. As acceptance test 's findings, correct typo for
 *                         the source code comments.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
#include "Spi_Ram.h"
#include "Spi_Scheduler.h"
#include "Spi_CSIX_LLDriver.h"
#include "Spi_DMAC_LLDriver.h"

#if (SPI_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define SPI_C_AR_RELEASE_MAJOR_VERSION \
                                  SPI_AR_RELEASE_MAJOR_VERSION_VALUE
#define SPI_C_AR_RELEASE_MINOR_VERSION \
                                  SPI_AR_RELEASE_MINOR_VERSION_VALUE
#define SPI_C_AR_RELEASE_REVISION_VERSION \
                               SPI_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define SPI_C_SW_MAJOR_VERSION    1
#define SPI_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (SPI_AR_RELEASE_MAJOR_VERSION != SPI_C_AR_RELEASE_MAJOR_VERSION)
#error "Spi.c : Mismatch in Release Major Version"
#endif

#if (SPI_AR_RELEASE_MINOR_VERSION != SPI_C_AR_RELEASE_MINOR_VERSION)
#error "Spi.c : Mismatch in Release Minor Version"
#endif

#if (SPI_AR_RELEASE_REVISION_VERSION != SPI_C_AR_RELEASE_REVISION_VERSION)
#error "Spi.c : Mismatch in Release Revision Version"
#endif

#if (SPI_SW_MAJOR_VERSION != SPI_C_SW_MAJOR_VERSION)
#error "Spi.c : Mismatch in Software Major Version"
#endif

#if (SPI_SW_MINOR_VERSION != SPI_C_SW_MINOR_VERSION)
#error "Spi.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0316) Cast from a pointer to void to a pointer to       */
/*                 object type.                                               */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Typecasting from void* is necessary to hide internal types */
/*                 from the header files which are exposed to user.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-1 and                           */
/*                 END Msg(4:0316)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This is necessary to support multiple configuration.       */
/*                 The actuall array can't be decided statically.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-2 and                           */
/*                 END Msg(4:0491)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/*                                                                            */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : This is necessary to support AUTOSAR SWS.                  */
/*                 Pointer must be converted according to actual data size.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0310)-3 and                           */
/*                 END Msg(4:0310)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0492) Array subscripting applied to a function          */
/*                 parameter declared as a pointer.                           */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This is necessary to handle pointers passed by user code.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0492)-4 and                           */
/*                 END Msg(4:0492)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2982) This assignment is redundant. The value of this   */
/*                 object is never used before being modified.                */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable needs to be initialized before using it.      */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(4:2982)-5 and                           */
/*                 END Msg(4:2982)-5 tags in the code.                        */
/******************************************************************************/

/******************************************************************************/
/**                      QAC Warning                                         **/
/******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:3227) The parameter '%s' is never modified and          */
/*                 so it could be declared with the 'const' qualifier.        */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3227           */
/*                 REFERENCE - ISO:C90-6.5.3 Type Qualifiers                  */
/* Justification : It can be declared 'const' but it follow AutoSAR           */
/*                 and/or Renesas Specification.                              */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3227)-1 and                           */
/*                 END Msg(2:3227)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (3:3305) Pointer cast to stricter alignment.               */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3305           */
/* Justification : This is necessary to comply AUTOSAR specification.         */
/* Verification  : Upper layer should guarantee the alignment.                */
/* Reference     : Look for START Msg(3:3305)-2 and                           */
/*                 END Msg(3:3305)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3416           */
/* Justification : According to the coding guide, all global variables must   */
/*                 be declared with volatile keyword. Since these are normal  */
/*                 memory objects, there is no side effect.                   */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3416)-3 and                           */
/*                 END Msg(2:3416)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:0832) Function call argument is an expression with      */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The name of an include file has been specified using a     */
/*                 macro. This is not recommended in some coding standards.   */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-4 and                           */
/*                 END Msg(2:0832)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (4:2877) This loop will never be executed more than once.  */
/* Rule          : No MISRA-C:2004 Rules applicable to message 2877           */
/* Justification : Since SPI_MAX_QUEUE could be equal 1 in case the           */
/*                 SpiSupportConcurrentAsyncTransmit = false                  */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(4:2877)-5 and                           */
/*                 END Msg(4:2877)-5 tags in the code.                        */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : (3:3352) This 'switch' statement contains only two         */
/*                 execution paths.                                           */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3352           */
/* Justification : When using different configurations, "case" branches       */
/*                 (through Compiler switch) may no longer be present.        */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(3:3352)-6 and                           */
/*                 END Msg(3:3352)-6 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define SPI_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-4 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-4 */

/* The prototype of function which is used in this file only */
static FUNC(void, SPI_PRIVATE_CODE) Spi_SetStatus
  (CONST(boolean, AUTOMATIC) LblStatus);
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
static FUNC(void, SPI_PRIVATE_CODE) Spi_MemCopy(
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile CONSTP2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpDesPtr,
  volatile CONSTP2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpSrcPtr);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
(SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitQueue(void);
#endif

#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitErrorBuffer(void);
#endif

static FUNC(void, SPI_PRIVATE_CODE) Spi_InitHWStatus(void);
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitJobSeqStatus(void);
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitChannelBuffer(void);

#define SPI_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-4 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-4 */

#define SPI_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-4 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-4 */

/*******************************************************************************
** Function Name       : Spi_Init
**
** Service ID          : 0x00
**
** Description         : This service performs initialization of the SPI Driver
**                       component.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : ConfigPtr - Pointer to the configuration
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : void
**
** Preconditions       : None
**
** Global Variable     : Spi_GblInitialized, Spi_GenAsyncMode, Spi_GpConfigPtr,
**                       Spi_GpFirstChannel, Spi_GpFirstJob, Spi_GpFirstSeq,
**                       Spi_GpFirstHWUnit, Spi_GulActiveSyncHWUnits,
**                       Spi_GpFirstDMAUnit, Spi_GulCancelingHWUnits,
**                       Spi_GenClockModeStatus
**
** Function Invoked    : Det_ReportError, Spi_SetStatus, Spi_CSIXInit,
**                       Spi_InitHWStatus, Spi_InitQueue,
**                       Spi_DMAInit, Spi_InitJobSeqStatus,
**                       Spi_InitChannelBuffer, Spi_CSIHEccSelfTest
**                       Spi_InitErrorBuffer,
**                       Spi_CSIXTurnOffUnit, Spi_CSIXInitializeForJob,
**                       Spi_CSIXDisableAllInterrupts, Spi_CSIHInitRegs,
**                       Spi_CSIXWriteHWIB, Spi_MemCopy,
**                       Spi_EccAllZeroTest, Spi_EccAllOneTest,
**                       Spi_EccWalkOneTest, Spi_EccTwoBitTest,
**                       Spi_HWBufferLoadTxData, Dem_ReportErrorStatus
**                       Spi_LoadTxData
**
** Registers Used      : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2, CSIHnMCTL0, CSIXnTX0W,
**                       CSIGnRX0, CSIXnSTR0, ECCCSIHnCTL, CSIHnMRWP0,
**                       DCSTCn, DTFRn, DCENn, DSAn, DDAn, DTFRRQCn, CSIXnBRS,
**                       CSIGnCFG0, CSIHnCFGx, CSIGnBCTL0, CSIXnSTCR0,
**                       ECCCSIHnCTL, ECCCSIHnERDB, ECCCSIHnTED, ECCCSIHnTMC,
**                       EICn/ICxxx
*******************************************************************************/
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(void, SPI_PUBLIC_CODE) Spi_Init(
  P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-1 */
/* References: SPI_DDD_ACT_001 */
{
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Det check result */
  VAR(Std_ReturnType, AUTOMATIC) LucDetCheckResult;
#endif

  /* Self-test result */
  VAR(Std_ReturnType, AUTOMATIC) LucHWSelfTestResult;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LucHWSelfTestResult = E_OK;
  /* END Msg(4:2982)-5 */

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the DET check result */
  LucDetCheckResult = E_OK;

#if (SPI_ALREADY_INIT_DET_CHECK == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver already initialized */
  if (SPI_FALSE != Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_001_ERR001 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_INIT_SID, SPI_E_ALREADY_INITIALIZED);
    LucDetCheckResult = E_NOT_OK;
  }
  else
#endif
  /* Check if SPI configuration pointer is a NULL Pointer */
  if (NULL_PTR == ConfigPtr)
  /* References: SPI_DDD_ACT_001_ERR003 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_INIT_SID, SPI_E_PARAM_POINTER);
    LucDetCheckResult = E_NOT_OK;
  }
  else if (SPI_DBTOC_VALUE != ConfigPtr->ulStartOfDbToc)
  /* References: SPI_DDD_ACT_001_ERR002 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_INIT_SID, SPI_E_INVALID_DATABASE);
    LucDetCheckResult = E_NOT_OK;
  }
  else
  {
    /* Nothing to do */
  }

  /* Check if any DET error reported */
  if (E_OK == LucDetCheckResult)
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Load ConfigPtr to Global pointer variable  */
    Spi_GpConfigPtr = ConfigPtr;
    /* References: SPI_DDD_ACT_001_GBL001 */

    /* Get the pointer to  Channel configuration table */
    /* MISRA Violation: START Msg(4:0316)-1 */
    Spi_GpFirstChannel =
      (P2CONST(Spi_ChannelConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA))
      Spi_GpConfigPtr->pChannelConfig;
    /* END Msg(4:0316)-1 */
    /* References: SPI_DDD_ACT_001_GBL002 */

    /* Get the pointer to Job configuration table */
    /* MISRA Violation: START Msg(4:0316)-1 */
    Spi_GpFirstJob =
      (P2CONST(Spi_JobConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA))
      Spi_GpConfigPtr->pJobConfig;
    /* END Msg(4:0316)-1 */
    /* References: SPI_DDD_ACT_001_GBL003 */

    /*  Get the pointer to Sequence configuration table */
    /* MISRA Violation: START Msg(4:0316)-1 */
    Spi_GpFirstSeq =
      (P2CONST(Spi_SeqConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA))
      Spi_GpConfigPtr->pSequenceConfig;
    /* END Msg(4:0316)-1 */
    /* References: SPI_DDD_ACT_001_GBL004 */

    /* Get the poiter to SPI HWUnit configuration table */
    /* MISRA Violation: START Msg(4:0316)-1 */
    Spi_GpFirstHWUnit =
      (P2CONST(Spi_HWUnitInfoType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA))
      Spi_GpConfigPtr->pHWUnitInfo;
    /* END Msg(4:0316)-1 */
    /* References: SPI_DDD_ACT_001_GBL005 */

#if (SPI_DMA_CONFIGURED == STD_ON)
    /* Get the pointer to DMA HWUnit configuration table */
    /* MISRA Violation: START Msg(4:0316)-1 */
    Spi_GpFirstDMAUnit =
      (P2CONST(Spi_DmaConfigType, SPI_VAR_NO_INIT, SPI_CONFIG_DATA))
      Spi_GpConfigPtr->pDMAUnitInfo;
    /* END Msg(4:0316)-1 */
    /* References: SPI_DDD_ACT_001_GBL006 */
#endif

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
    /*Global variable for asynchronous mode is polling mode */
    Spi_GenAsyncMode = SPI_POLLING_MODE;
    /* References: SPI_DDD_ACT_001_GBL007 */
#endif

#if (SPI_SET_CLOCK_MODE_ENABLED == STD_ON)
    /* Global variable to store Clock Power mode status of SPI Driver */
    Spi_GenClockModeStatus = SPI_CLOCK_MODE_NORMAL;
    /* References: SPI_DDD_ACT_001_GBL009 */
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
(SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    Spi_GulActiveSyncHWUnits = SPI_ZERO;
    /* References: SPI_DDD_ACT_001_GBL008 */
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
(SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    /* Initialize Queues */
    Spi_InitQueue();
#endif
    /* Initialize HW status */
    Spi_InitHWStatus();

    /* Initialize Job and Sequence status */
    Spi_InitJobSeqStatus();

    /* Initialize each Channel buffers */
    Spi_InitChannelBuffer();

#if (SPI_FORCE_CANCEL_API == STD_ON)
    /* HW Units under processing by Spi_ForceCancel */
    Spi_GulCancelingHWUnits = SPI_ZERO;
    /* References: SPI_DDD_ACT_001_GBL039 */
#endif

#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
    /* Initialize the Error buffer */
    Spi_InitErrorBuffer();
#endif

#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) || \
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
    /* Self-test is performed by polling.
       Hence HW unit interrupts must be disabled. */
    Spi_CSIXDisableAllInterrupts();
    /* Run loop back test mode if it is configured. */
    LucHWSelfTestResult = Spi_CSIXLoopBackSelfTest(SPI_INIT_SID);
#endif /* (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) || \
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME) */

#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ECC_INIT) || \
 (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
    if (E_OK == LucHWSelfTestResult)
    {
      /* Run ECC self-test if it is configured. */
      LucHWSelfTestResult = Spi_CSIHEccSelfTest();
    }
    else
    {
      /* Do nothing */
    }
#endif /* (SPI_ECC_SELFTEST == SPI_ECC_INIT) || \
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME) */
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */

    if (E_OK == LucHWSelfTestResult)
    {
      /* Initialize CSIX registers */
      Spi_CSIXInit(SPI_INIT_SID);
#if (SPI_DMA_CONFIGURED == STD_ON)
      /* Initialize DMA registers if DMA is enabled */
      Spi_DMAInit();
#endif
      /* Set Initialized flag */
      Spi_SetStatus(SPI_TRUE);
    }
    else
    {
      /* Nothing to do */
    }
  }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Nothing to do */
  }
#endif
}

/*******************************************************************************
** Function Name       : Spi_DeInit
**
** Service ID          : 0x01
**
** Description         : This service is used for de-initialization of this
**                       module.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init must have been invoked
**
** Global Variable     : Spi_GblInitialized
**                       Spi_GulActiveSyncHWUnits, Spi_GulAllQueueSts
**
** Function invoked    : Det_ReportError, Spi_SetStatus,
**                       Spi_CSIXDeInit, Spi_DMADeInit
**                       Spi_CSIXDisableAllInterrupts, Spi_HWControlCS,
**                       Spi_CSIXTurnOffUnit, Spi_CSIHInitRegs,
**                       Spi_CSIXTurnOnUnit
**
** Registers Used      : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2, CSIGnCFG0, CSIHnCFGx,
**                       CSIHnMCTL0, CSIHnMCTL1, CSIHnMCTL2, CSIHnBRSm,
**                       CSIXnSTCR0, CSIXnBRSy, CSIXnSTR0, CSIGnBCTL0,
**                       DTFRRQCn, DCSTCn, DTCTn, DCENn, DSAn ,DDAn, DTCTm
**                       PSRn/JPSRn, EICn/ICxxx
*******************************************************************************/
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_DeInit(void)
{
  /* References: SPI_DDD_ACT_002 */
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_002_ERR001 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_DEINIT_SID, SPI_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  else
#endif
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if Global status variable is SPI_BUSY */
  if ((uint32)SPI_ZERO ==
  /* END Msg(2:3416)-3 */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_0)
    Spi_GulActiveSyncHWUnits
#elif (SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
    Spi_GulAllQueueSts
#else
    (Spi_GulActiveSyncHWUnits | Spi_GulAllQueueSts)
#endif
  )
  {
    /* Update the SPI driver status as uninitialized */
    Spi_SetStatus(SPI_FALSE);

    /* DeInit CSIX used-registers as default values */
    Spi_CSIXDeInit(SPI_DEINIT_SID);

#if (SPI_DMA_CONFIGURED == STD_ON)
    /* DeInit DMA registers if DMA is enabled */
    Spi_DMADeInit();
#endif

    LucReturnValue = E_OK;
  }
  else
  {
    LucReturnValue = E_NOT_OK;
  }

  /* Return the value */
  return(LucReturnValue);
}

/*******************************************************************************
** Function Name       : Spi_WriteIB
**
** Service ID          : 0x02
**
** Description         : This service for writing one or more data to an
**                       IB SPI Handler/Driver channel specified
**                       by parameter.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Channel - Channel ID
**                       DataBufferPtr - Pointer to source data buffer
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init must have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GpConfigPtr,
**                       Spi_GpFirstChannel
**
** Function invoked    : Det_ReportError, Spi_MemCopy, Spi_CSIXWriteHWIB
**                       Spi_HWBufferLoadTxData, Spi_LoadTxData
**
** Registers Used      : CSIHnMRWP0, CSIHnTX0W
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_WriteIB(
  CONST(Spi_ChannelType, AUTOMATIC) Channel,
  P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr)
/* END Msg(2:3227)-1 */
/* References: SPI_DDD_ACT_003 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

  /* Initialize return value as E_OK */
  LucReturnValue = E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_003_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_WRITEIB_SID,
      SPI_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  /* Check if the channel ID passed, is valid */
  else if (Spi_GpConfigPtr->ucNoOfChannels <= Channel)
    /* References: SPI_DDD_ACT_003_ERR002 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_WRITEIB_SID, SPI_E_PARAM_CHANNEL);
    LucReturnValue = E_NOT_OK;
  }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
  /* Check if the channel is configured with external buffer */
  /* MISRA Violation: START Msg(4:0491)-2 */
  else if (SPI_BUFFER_TYPE_EB ==
    Spi_GpFirstChannel[Channel].enChannelBufferType)
  /* END Msg(4:0491)-2 */
  /* References: SPI_DDD_ACT_003_ERR003 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_WRITEIB_SID, SPI_E_PARAM_CHANNEL);
    LucReturnValue = E_NOT_OK;
  }
#endif /* (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB) */
  else
  {
    /* Do nothing */
  }

  /* Check if any DET error reported */
  if (E_OK == LucReturnValue)
#endif /* End of (SPI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(4:0491)-2 */
    if (SPI_BUFFER_TYPE_IB ==
      Spi_GpFirstChannel[Channel].enChannelBufferType)
    /* END Msg(4:0491)-2 */
    {
      /* Copy operation */
      /* MISRA Violation: START Msg(4:0491)-2 */
      LpChConfig = &Spi_GpFirstChannel[Channel];
      /* END Msg(4:0491)-2 */
      Spi_MemCopy(LpChConfig, LpChConfig->pTxBuffer, DataBufferPtr);
    }
#if (SPI_DUAL_BUFFER_MODE == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-2 */
    else if (SPI_BUFFER_TYPE_DUAL_HWIB ==
      Spi_GpFirstChannel[Channel].enChannelBufferType)
    /* END Msg(4:0491)-2 */
    {
      Spi_CSIXWriteHWIB(Channel, DataBufferPtr, SPI_WRITEIB_SID);
    }
#endif
#if (SPI_TX_ONLY_MODE == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-2 */
    else if (SPI_BUFFER_TYPE_TX_HWIB ==
      Spi_GpFirstChannel[Channel].enChannelBufferType)
    /* END Msg(4:0491)-2 */
    {
      Spi_CSIXWriteHWIB(Channel, DataBufferPtr, SPI_WRITEIB_SID);
    }
#endif
    else
    {
      LucReturnValue = E_NOT_OK;
    }
  }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do nothing */
  }
#endif

  return(LucReturnValue);
}
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)) */

/*******************************************************************************
** Function Name       : Spi_AsyncTransmit
**
** Service ID          : 0x03
**
** Description         : This service for transmitting data asynchronously.
**
** Sync/Async          : Asynchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init must have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GaaSeqStatus
**                       Spi_GpConfigPtr, Spi_GpFirstSeq, Spi_GaaActiveSequence
**
** Function invoked    : Det_ReportError, Spi_StartTransmission,
**                       Spi_PushToQueue, Spi_PopFromQueue, Spi_ProcessJob
**                       Spi_CSIXProcessJob,
**                       Spi_CSIXInitializeForJob, Spi_CSIXInitializeForCh,
**                       Spi_CSIXStartChannelDirectAccessMode,
**                       Spi_CSIXStartChannelFifoMode, Spi_HWControlCS,
**                       Spi_CSIXStartChannelHwBuffer, Spi_CSIXTurnOffUnit
**                       Spi_CSIXDMAStartChannelFifoMode,
**                       Spi_LoadTxData, Spi_DMAStart,
**                       Spi_CSIXMaskHWUnitInterrupts, Spi_CSIXTurnOnUnit,
**                       Spi_HWBufferLoadTxData, Spi_CSIXMaskHWUnitRxInterrupt,
**                       Spi_CSIXMaskHWUnitTxInterrupt, Spi_CSIXDMASetUp,
**                       Spi_DMAMaskHWUnitInterrupts, Spi_CSIXWriteTX0Register,
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2, CSIXnSTCR0,
**                       CSIHnMCTL0, CSIHnMCTL1, CSIHnMCTL2, CSIXnBRS,
**                       CSIGnCFG0, CSIHnCFGx, CSIXnTX0W, PSRn/JPSRn, EICn/ICxxx
**                       DCENn, DSAn, DTCTn, DCSTCn, DTCn, DTFRRQCn, DDAn
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
    (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_AsyncTransmit(
  CONST(Spi_SequenceType, AUTOMATIC) Sequence)
/* References: SPI_DDD_ACT_004 */
{
  VAR(uint32, AUTOMATIC) LulCount;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

  /* Initialize return value as E_OK */
  LucReturnValue = E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_004_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_ASYNCTRANSMIT_SID, SPI_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  /* Check if the Sequence ID passed, is valid */
  else if (Spi_GpConfigPtr->ucNoOfSequences <= Sequence)
  /* References: SPI_DDD_ACT_004_ERR002 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_ASYNCTRANSMIT_SID, SPI_E_PARAM_SEQ);
    LucReturnValue = E_NOT_OK;
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* MISRA Violation: START Msg(4:0491)-2 */
  /*
  * Check if the HW Unit of the job is configured for synchronous
  * transmission
  */
  else if (SPI_TRUE == Spi_GpFirstSeq[Sequence].blSynchronous)
  /* END Msg(4:0491)-2 */
  /* References: SPI_DDD_ACT_004_ERR004 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_ASYNCTRANSMIT_SID, SPI_E_PARAM_SEQ);
    LucReturnValue = E_NOT_OK;
  }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */
  else
  {
    /* Do nothing */
  }

  /* Check if any DET error reported */
  if (E_OK == LucReturnValue)
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    /* Critical section required for re-entrancy of this API */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
    /* Check if the requested sequence already pending */
    if (SPI_SEQ_PENDING == Spi_GaaSeqStatus[Sequence].enResult)
    /* References: SPI_DDD_ACT_004_ERR003 */
    {
      /* This function shall return with value E_NOT_OK*/
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* References: SPI_DDD_ACT_004_CRT001 */
      /* QAC Warning: START Msg(4:2877)-5 */
      for (LulCount = SPI_ZERO;
        LulCount < SPI_BITS_TO_WORDS(SPI_MAX_SEQUENCE); LulCount++)
      /* END Msg(4:2877)-5 */
      {
        /* MISRA Violation: START Msg(4:0491)-2 */
        if ((uint32)SPI_ZERO != (Spi_GaaActiveSequence[LulCount] &
          Spi_GpFirstSeq[Sequence].aaJobSharedSequences[LulCount]))
        /* END Msg(4:0491)-2 */
        {
          LucReturnValue = E_NOT_OK;
        }
        else
        {
          /* Nothing to do */
        }
      }
      /* If OK, set active flag for this Sequence */
      if (E_OK == LucReturnValue)
      {
        Spi_GaaActiveSequence[(uint32)Sequence / (uint32)SPI_UINT32_BITS] =
          Spi_GaaActiveSequence[(uint32)Sequence / (uint32)SPI_UINT32_BITS] |
          ((uint32)SPI_ONE << ((uint32)Sequence & (SPI_UINT32_BITS - SPI_ONE)));
        /* References: SPI_DDD_ACT_004_GBL001 */
        /* Mark this Sequence as busy */
        Spi_GaaSeqStatus[Sequence].enResult = SPI_SEQ_PENDING;
        /* References: SPI_DDD_ACT_004_GBL002 */
      }
      else
      {
        /* Nothing to do */
      }
#if (SPI_CANCEL_API == STD_ON)
      /* Initialize cancel request flag by Spi_Cancel */
      Spi_GaaSeqStatus[Sequence].blCancelRequested = SPI_FALSE;
      /* References: SPI_DDD_ACT_004_GBL003 */
#endif
#if ((SPI_CANCEL_API == STD_ON) || (SPI_FORCE_CANCEL_API == STD_ON))
      /* Initialize already canceled flag for Spi_Cancel or Spi_ForceCancel */
      Spi_GaaSeqStatus[Sequence].blCanceled = SPI_FALSE;
      /* References: SPI_DDD_ACT_004_GBL004 */
#endif
    }
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
    /* References: SPI_DDD_ACT_004_CRT002 */
    /* Report to DET on the outside of critical section */
    if (E_NOT_OK == LucReturnValue)
    /* References: SPI_DDD_ACT_004_ERR005 */
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_ASYNCTRANSMIT_SID, SPI_E_SEQ_PENDING);
#endif
    }
    else
    {
      /* Transmission */
      Spi_StartTransmission((uint32)Sequence);
    }
  }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do nothing */
  }
#endif

  return(LucReturnValue);
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

/*******************************************************************************
** Function Name       : Spi_ReadIB
**
** Service ID          : 0x04
**
** Description         : This service for reading one or more data from an
**                       IB SPI Handler/Driver channel specified by
**                       parameter.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Channel - Channel ID
**                       DataBufferPointer - Pointer to destination data
**                       buffer
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init must have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GpConfigPtr,
**                       Spi_GpFirstChannel
**
** Function invoked    : Det_ReportError, Spi_MemCopy, Spi_CSIXReadHWIB
**                       Spi_HWBufferStoreRxData, Spi_StoreRxData
**                       Spi_CSIXTurnOffUnit, Spi_CSIXTurnOnUnit
**
** Registers Used      : CSIHnMRWP0, CSIHnRX0W, CSIXnCTL0
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_ReadIB(
  CONST(Spi_ChannelType, AUTOMATIC) Channel,
  P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPointer)
/* END Msg(2:3227)-1 */
/* References: SPI_DDD_ACT_005 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  LucReturnValue = E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_005_ERR001 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_READIB_SID,
      SPI_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  /* Check if the channel ID passed, is valid */
  else if (Spi_GpConfigPtr->ucNoOfChannels <= Channel)
  /* References: SPI_DDD_ACT_005_ERR002 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_READIB_SID, SPI_E_PARAM_CHANNEL);
    LucReturnValue = E_NOT_OK;
  }
  /* Check if the data buffer pointer passed, is NULL pointer */
  else if (NULL_PTR == DataBufferPointer)\
  /* References: SPI_DDD_ACT_005_ERR003 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_READIB_SID, SPI_E_PARAM_POINTER);
    LucReturnValue = E_NOT_OK;
  }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
  /* Check if the channel is configured with external buffer */
  /* MISRA Violation: START Msg(4:0491)-2 */
  else if (SPI_BUFFER_TYPE_EB ==
    (Spi_GpFirstChannel[Channel].enChannelBufferType))
  /* END Msg(4:0491)-2 */
    /* References: SPI_DDD_ACT_005_ERR004 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_READIB_SID, SPI_E_PARAM_CHANNEL);
    LucReturnValue = E_NOT_OK;
  }
#endif /* (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB) */
  else
  {
    /* Do nothing */
  }

  /* Check if any DET error reported */
  if (E_OK == LucReturnValue)
#endif /* End of SPI_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Violation: START Msg(4:0491)-2 */
    if (SPI_BUFFER_TYPE_IB ==
      Spi_GpFirstChannel[Channel].enChannelBufferType)
    /* END Msg(4:0491)-2 */
    {
      /* Copy operation */
      /* MISRA Violation: START Msg(4:0491)-2 */
      LpChConfig = &Spi_GpFirstChannel[Channel];
      /* END Msg(4:0491)-2 */
      Spi_MemCopy(LpChConfig, DataBufferPointer, LpChConfig->pRxBuffer);
    }
#if (SPI_DUAL_BUFFER_MODE == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-2 */
    else if (SPI_BUFFER_TYPE_DUAL_HWIB ==
      Spi_GpFirstChannel[Channel].enChannelBufferType)
    /* END Msg(4:0491)-2 */
    {
       Spi_CSIXReadHWIB(Channel, DataBufferPointer);
    }
#endif
#if (SPI_TX_ONLY_MODE == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-2 */
    else if (SPI_BUFFER_TYPE_TX_HWIB ==
      Spi_GpFirstChannel[Channel].enChannelBufferType)
    /* END Msg(4:0491)-2 */
    {
      /* MISRA Violation: START Msg(4:0491)-2 */
      LpChConfig = &Spi_GpFirstChannel[Channel];
      /* END Msg(4:0491)-2 */
      Spi_MemCopy(LpChConfig, DataBufferPointer, LpChConfig->pRxBuffer);
    }
#endif
    else
    {
      LucReturnValue = E_NOT_OK;
    }
  }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do nothing */
  }
#endif

  return(LucReturnValue);
}
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)) */

/*******************************************************************************
** Function Name       : Spi_SetupEB
**
** Service ID          : 0x05
**
** Description         : This service for setting the buffers and the length
**                       of data for the external buffer of the channel
**                       specified.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Channel - Channel ID
**                       SrcDataBufferPtr - Pointer to source data buffer
**                       DesDataBufferPtr - Pointer to destination data
**                       buffer in RAM
**                       Length - Number of data elements of the data to be
**                       transmitted from SrcDataBufferPtr and/or received from
**                       DesDataBufferPtr
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init must have been invoked.
**
** Global Variable     : Spi_GblInitialized,
**                       Spi_GpConfigPtr, Spi_GpFirstChannel
**
** Function invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetupEB(
  CONST(Spi_ChannelType, AUTOMATIC) Channel,
  P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
  P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
  CONST(Spi_NumberOfDataType, AUTOMATIC) Length)
/* END Msg(2:3227)-1 */
/* References: SPI_DDD_ACT_006 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_006_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETUPEB_SID,
      SPI_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  /* Check if the channel ID passed, is valid */
  else if (Spi_GpConfigPtr->ucNoOfChannels <= Channel)
  /* References: SPI_DDD_ACT_006_ERR002 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SETUPEB_SID, SPI_E_PARAM_CHANNEL);
    LucReturnValue = E_NOT_OK;
  }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
  /* Check if the requested channel is configured for internal buffer */
  /* MISRA Violation: START Msg(4:0491)-2 */
  else if (SPI_BUFFER_TYPE_EB !=
    Spi_GpFirstChannel[Channel].enChannelBufferType)
  /* END Msg(4:0491)-2 */
    /* References: SPI_DDD_ACT_006_ERR003 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SETUPEB_SID, SPI_E_PARAM_CHANNEL);
    LucReturnValue = E_NOT_OK;
  }
#endif /* (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB) */
  /*
  * Check if the 'length' parameter is greater than configured length and if
  * length is zero
  */
  /* MISRA Violation: START Msg(4:0491)-2 */
  else if ((SPI_ZERO == Length) ||
    (Length > Spi_GpFirstChannel[Channel].usNoOfBuffers))
  /* END Msg(4:0491)-2 */
    /* References: SPI_DDD_ACT_006_ERR004 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SETUPEB_SID, SPI_E_PARAM_LENGTH);
    LucReturnValue = E_NOT_OK;
  }
  else
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    /* Set pointers from user */
    /* MISRA Violation: START Msg(4:0491)-2 */
    LpChConfig = &Spi_GpFirstChannel[Channel];
    /* END Msg(4:0491)-2 */
    LpChConfig->pEBData->pSrcPtr = SrcDataBufferPtr;
    /* References: SPI_DDD_ACT_006_GBL001 */
    LpChConfig->pEBData->pDestPtr = DesDataBufferPtr;
    /* References: SPI_DDD_ACT_006_GBL002 */
    LpChConfig->pEBData->usEBLength = Length;
    /* References: SPI_DDD_ACT_006_GBL003 */
    LucReturnValue = E_OK;
  }

  return(LucReturnValue);
}
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)) */

/*******************************************************************************
** Function Name       : Spi_GetStatus
**
** Service ID          : 0x06
**
** Description         : This service is for getting the status of SPI
**                       Driver Component.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_StatusType (SPI_UNINIT/SPI_IDLE/SPI_BUSY)
**
** Preconditions       : Spi_Init must have been initialized
**
** Global Variable     : Spi_GblInitialized, Spi_GulActiveSyncHWUnits,
**                       Spi_GulAllQueueSts
**
** Function Invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
FUNC(Spi_StatusType, SPI_PUBLIC_CODE) Spi_GetStatus(void)
/* References: SPI_DDD_ACT_007 */
{
  VAR(Spi_StatusType, AUTOMATIC) LenRetValue;

  /* QAC Warning: START Msg(2:3416)-3 */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_007_ERR001 */
  {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETSTATUS_SID, SPI_E_UNINIT);
#endif
    LenRetValue = SPI_UNINIT;
  }
  /* QAC Warning: START Msg(2:3416)-3 */
  else if ((uint32)SPI_ZERO !=
  /* END Msg(2:3416)-3 */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_0)
    Spi_GulActiveSyncHWUnits
#elif (SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
    Spi_GulAllQueueSts
#else
    (Spi_GulActiveSyncHWUnits | Spi_GulAllQueueSts)
#endif
  )
  {
    LenRetValue = SPI_BUSY;
  }
  else
  {
    LenRetValue = SPI_IDLE;
  }

  return LenRetValue;
}

/*******************************************************************************
** Function Name       : Spi_GetJobResult
**
** Service ID          : 0x07
**
** Description         : This service is for getting result of the
**                       specified job.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Job - Job ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_JobResultType
**                       (SPI_JOB_OK/SPI_JOB_PENDING/SPI_JOB_FAILED)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GpConfigPtr, Spi_GaaJobStatus
**
** Function invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
FUNC(Spi_JobResultType, SPI_PUBLIC_CODE) Spi_GetJobResult(
  CONST(Spi_JobType, AUTOMATIC) Job)
/* References: SPI_DDD_ACT_008 */
{
  VAR(Spi_JobResultType, AUTOMATIC) LenJobResult;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_008_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETJOBRESULT_SID, SPI_E_UNINIT);
    LenJobResult = SPI_JOB_FAILED;
  }
  /* Check if the job ID passed, is valid */
  else if (Spi_GpConfigPtr->usNoOfJobs <= Job)
  /* References: SPI_DDD_ACT_008_ERR002 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETJOBRESULT_SID, SPI_E_PARAM_JOB);
    LenJobResult = SPI_JOB_FAILED;
  }
  else
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    LenJobResult = Spi_GaaJobStatus[Job].enResult;
  }
  return(LenJobResult);
}

/*******************************************************************************
** Function Name       : Spi_GetSequenceResult
**
** Service ID          : 0x08
**
** Description         : This service is for getting result of the specified
**                       sequence.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_SeqResultType
**                       (SPI_SEQ_OK/SPI_SEQ_PENDING/SPI_SEQ_FAILED/
**                        SPI_SEQ_CANCELED)
**
** Preconditions       : Spi_Init must have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GpConfigPtr, Spi_GaaSeqStatus
**
** Function invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
FUNC(Spi_SeqResultType, SPI_PUBLIC_CODE) Spi_GetSequenceResult(
  CONST(Spi_SequenceType, AUTOMATIC) Sequence)
/* References: SPI_DDD_ACT_009 */
{
  VAR(Spi_SeqResultType, AUTOMATIC) LenSeqResult;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_009_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETSEQUENCERESULT_SID, SPI_E_UNINIT);
    LenSeqResult = SPI_SEQ_FAILED;
  }
  /* Check if the Sequence ID passed, is valid */
  else if (Spi_GpConfigPtr->ucNoOfSequences <= Sequence)
  /* References: SPI_DDD_ACT_009_ERR002 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETSEQUENCERESULT_SID, SPI_E_PARAM_SEQ);
    LenSeqResult = SPI_SEQ_FAILED;
  }
  else
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    LenSeqResult = Spi_GaaSeqStatus[Sequence].enResult;
  }
  return(LenSeqResult);
}

/*******************************************************************************
** Function Name         : Spi_GetVersionInfo
**
** Service ID            : 0x09
**
** Description           : This API returns the version information of SPI
**                         driver component.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : versioninfo
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      : None
**
** Functions invoked     : Det_ReportError
**
** Registers Used        : None
**
*******************************************************************************/
#if (SPI_VERSION_INFO_API == STD_ON)
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(void, SPI_PUBLIC_CODE) Spi_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo)
/* END Msg(2:3227)-1 */
/* References: SPI_DDD_ACT_010 */
{
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == versioninfo)
  /* References: SPI_DDD_ACT_010_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETVERSIONINFO_SID, SPI_E_PARAM_POINTER);
  }
  else
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
  {
    versioninfo->vendorID = SPI_VENDOR_ID;
    versioninfo->moduleID = SPI_MODULE_ID;
    versioninfo->sw_major_version = SPI_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = SPI_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = SPI_SW_PATCH_VERSION;
  }
}
#endif /* (SPI_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_SyncTransmit
**
** Service ID          : 0x0A
**
** Description         : This service is for transmitting data synchronously.
**
** Sync/Async          : Synchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GpConfigPtr, Spi_GpFirstSeq,
**                       Spi_GulActiveSyncHWUnits
**
** Function invoked    : Det_ReportError, Spi_TransmitSyncSequence,
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**                       Dem_ReportErrorStatus, Spi_CSIXTransmitSyncJob
**                       Spi_CSIXProcessJob, Spi_CSIXReceiveISR,
**                       Spi_CSIXTransmitISR, Spi_CSIXInitializeForJob,
**                       Spi_CSIXInitializeForCh, Spi_HWControlCS,
**                       Spi_CSIXStartChannelDirectAccessMode,
**                       Spi_CSIXStartChannelFifoMode, Spi_CSIXProcessEndJob,
**                       Spi_CSIXStartChannelHwBuffer, Spi_CSIXTurnOffUnit
**                       Spi_CSIXTurnOnUnit, Spi_CSIXDMASetUp, Spi_DMAStart
**                       Spi_CSIXDMAStartChannelFifoMode, Spi_PopFromQueue,
**                       Spi_CSIXReceiveChannelDirectAccessMode,
**                       Spi_CSIXReceiveChannelFifoMode, Spi_RemoveFromQueue
**                       Spi_CSIXReceiveChannelTxOnlyMode,
**                       Spi_LoadTxData, Spi_CSIXWriteTX0Register,
**                       Spi_CSIXMaskHWUnitTxInterrupt, Spi_StoreRxData,
**                       Spi_CSIXMaskHWUnitInterrupts, Spi_ProcessJob,
**                       Spi_HWBufferLoadTxData, Spi_CSIXMaskHWUnitRxInterrupt,
**                       Spi_DMAMaskHWUnitInterrupts, Spi_ProcessSequence,
**                       Spi_CSIXReadRX0Register, Spi_HWBufferStoreRxData,
**                       Spi_CheckSeqFinish, Spi_InvokeNotifications
**
** Registers Used      : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2, CSIXnSTCR0,
**                       CSIXnSTR0, CSIXnBRS, EICn/ICxxx, CSIXnTX0W, CSIHnRX0W
**                       CSIHnMCTL0, CSIHnMCTL1, CSIHnMCTL2, PSRn,
**                       DCENn, DSAn, DTCTn, DCSTCn, DTCn, DTFRRQCn, DDAn,
**                       CSIGnCFG0, CSIHnCFGx, CSIHnRX0H, CSIGnRX0
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SyncTransmit(
  CONST(Spi_SequenceType, AUTOMATIC) Sequence)
/* References: SPI_DDD_ACT_011 */
{
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
  P2CONST(Spi_SeqConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpSeqConfig;
#endif
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  /* Initialize return valu as OK*/
  LucReturnValue = E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_011_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SYNCTRANSMIT_SID, SPI_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  /* Check if the sequence ID passed, is valid */
  else if (Spi_GpConfigPtr->ucNoOfSequences <= Sequence)
  /* References: SPI_DDD_ACT_011_ERR002 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SYNCTRANSMIT_SID, SPI_E_PARAM_SEQ);
    LucReturnValue = E_NOT_OK;
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* MISRA Violation: START Msg(4:0491)-2 */
  else if (SPI_FALSE == Spi_GpFirstSeq[Sequence].blSynchronous)
  /* END Msg(4:0491)-2 */
  /* References: SPI_DDD_ACT_011_ERR003 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SYNCTRANSMIT_SID, SPI_E_PARAM_SEQ);
    LucReturnValue = E_NOT_OK;
  }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */
  else
#else /* SPI_DEV_ERROR_DETECT == STD_OFF */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* MISRA Violation: START Msg(4:0491)-2 */
  if (SPI_TRUE == Spi_GpFirstSeq[Sequence].blSynchronous)
  /* END Msg(4:0491)-2 */
#endif /* SPI_LEVEL_DELIVERED == STD_ON */
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
    /* Check if the concurrent sync transmit is enabled */
    /* Get the pointer to the sequence structure */
    /* MISRA Violation: START Msg(4:0491)-2 */
    LpSeqConfig = &Spi_GpFirstSeq[Sequence];
    /* END Msg(4:0491)-2 */

    /* Check & Lock HWUnits to be used by this sequence */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
    /* References: SPI_DDD_ACT_011_CRT001 */
    /* QAC Warning: START Msg(2:3416)-3 */
    if ((uint32)SPI_ZERO == (Spi_GulActiveSyncHWUnits
    /* END Msg(2:3416)-3 */
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
      & LpSeqConfig->ulUsingHWUnits
#endif
      ))
    {
      Spi_GulActiveSyncHWUnits |= LpSeqConfig->ulUsingHWUnits;
      /* References: SPI_DDD_ACT_011_GBL001 */
    }
    else
    {
      LucReturnValue = E_NOT_OK;
    }
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
    /* References: SPI_DDD_ACT_011_CRT002 */

    if (E_OK != LucReturnValue)
    /* References: SPI_DDD_ACT_011_ERR004 */
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SYNCTRANSMIT_SID, SPI_E_SEQ_IN_PROCESS);
#endif
    }
    else
    {
      /* Transmission */
      LucReturnValue = Spi_TransmitSyncSequence((uint32)Sequence);

      /* Release locked HWUnits */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      /* References: SPI_DDD_ACT_011_CRT003 */
      Spi_GulActiveSyncHWUnits &= ~(LpSeqConfig->ulUsingHWUnits);
      /* References: SPI_DDD_ACT_011_GBL002 */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      /* References: SPI_DDD_ACT_011_CRT004 */
    }
#else
  /* Synchronous API just is applicable for direct access only.
     It returns NOT_OK if no HW unit runs with direct access mode. */
  LucReturnValue = E_NOT_OK;
#endif /* (SPI_DIRECT_ACCESS_MODE) */
  }
#if ((SPI_DEV_ERROR_DETECT == STD_OFF) &&\
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
  else
  {
    /* Nothing to do */
  }
#endif
  return(LucReturnValue);
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

/*******************************************************************************
** Function Name       : Spi_GetHWUnitStatus
**
** Service ID          : 0x0B
**
** Description         : This service is getting the status of the SPI
**                       Hardware micro-controller peripheral.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : HWUnit - ID of CSIG/CSIH Hardware Unit
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_StatusType (SPI_UNINIT/SPI_IDLE/SPI_BUSY)
**
** Preconditions       : Spi_Init must have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GpConfigPtr, Spi_GaaHWStatus
**
** Function invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
#if (SPI_HW_STATUS_API == STD_ON)
FUNC(Spi_StatusType, SPI_PUBLIC_CODE) Spi_GetHWUnitStatus(
  CONST(Spi_HWUnitType, AUTOMATIC) HWUnit)
/* References: SPI_DDD_ACT_012 */
{
  VAR(Spi_StatusType, AUTOMATIC) LenHWUnitSts;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_012_ER001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETHWUNITSTATUS_SID, SPI_E_UNINIT);
    LenHWUnitSts = SPI_UNINIT;
  }
  /* Check the range of HWUnit index */
  else if (Spi_GpConfigPtr->ucNoOfHWUnits <= HWUnit)
  /* References: SPI_DDD_ACT_012_ER002 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETHWUNITSTATUS_SID, SPI_E_PARAM_UNIT);
    LenHWUnitSts = SPI_UNINIT;
  }
  else
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    if (SPI_TRUE == Spi_GaaHWStatus[HWUnit].blActive)
    {
      LenHWUnitSts = SPI_BUSY;
    }
    else
    {
      LenHWUnitSts = SPI_IDLE;
    }
  }
  return(LenHWUnitSts);
}
#endif /* End of (SPI_HW_STATUS_API == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_Cancel
**
** Service ID          : 0x0C
**
** Description         : This service is for cancelling a on-going sequence.
**
** Sync/Async          : Asynchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi_Init must have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GpConfigPtr, Spi_GpFirstSeq
**
** Function invoked    : Det_ReportError, Spi_CancelSequence
**
** Registers Used      : None
*******************************************************************************/
#if (SPI_CANCEL_API == STD_ON)
FUNC(void, SPI_PUBLIC_CODE) Spi_Cancel(
  CONST(Spi_SequenceType, AUTOMATIC) Sequence)
/* References: SPI_DDD_ACT_013 */
{
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_013_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_CANCEL_SID, SPI_E_UNINIT);
  }
  /* Check if the sequence ID passed, is valid */
  else if (Spi_GpConfigPtr->ucNoOfSequences <= Sequence)
  /* References: SPI_DDD_ACT_013_ERR002 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_CANCEL_SID, SPI_E_PARAM_SEQ);
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /*
  * Check if the HW Unit of the job is configured for synchronous
  * transmission
  */
  /* MISRA Violation: START Msg(4:0491)-2 */
  else if (SPI_TRUE == Spi_GpFirstSeq[Sequence].blSynchronous)
  /* END Msg(4:0491)-2 */
  /* References: SPI_DDD_ACT_013_ERR003 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_CANCEL_SID, SPI_E_PARAM_SEQ);
  }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */
  else
#endif /* End of SPI_DEV_ERROR_DETECT == STD_ON */
  {
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_0)
    /* References: SPI_DDD_ACT_013_ERR004 */
    /* When LEVEL0, always raise error */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_CANCEL_SID, SPI_E_PARAM_SEQ);
#endif
#else
    Spi_CancelSequence((uint32)Sequence, SPI_FALSE, SPI_CANCEL_SID);
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_0) */
  }
}
#endif  /* End of (SPI_CANCEL_API == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_SetAsyncMode
**
** Service ID          : 0x0D
**
** Description         : This service is for setting the asynchronous mode.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : Mode - New Mode Required
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init must have been invoked.
**
** Global Variable     : Spi_GblInitialized, Spi_GulAllQueueSts,
**                       Spi_GenAsyncMode
**
** Function invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetAsyncMode(
  CONST(Spi_AsyncModeType, AUTOMATIC) Mode)
/* References: SPI_DDD_ACT_014 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-3 */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_014_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETASYNCMODE_SID,
      SPI_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  else
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    /* QAC Warning: START Msg(2:3416)-3 */
    /* Confirm no async task is operating */
    if ((uint32)SPI_ZERO != Spi_GulAllQueueSts)
    /* END Msg(2:3416)-3 */
    {
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Set global async mode as requested mode */
      Spi_GenAsyncMode = Mode;
      /* References: SPI_DDD_ACT_014_GBL001 */
      LucReturnValue = E_OK;
    }
  }
  return(LucReturnValue);
}
#endif  /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

/*******************************************************************************
** Function Name       : Spi_MainFunction_Handling
**
** Service ID          : 0x10
**
** Description         : This function is to be invoked in the scheduler
**                       loop for asynchronous transmission in polling mode.
**
** Sync/Async          : NA
**
** Re-entrancy         : Non Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : This function should be invoked only when polling
**                       mechanism is selected by Spi_SetAsyncMode API
**
** Global Variable     : Spi_GblInitialized, Spi_GenAsyncMode
**
** Function Invoked    : Spi_CSIXMainFunction_Handling, Spi_CSIXReceiveISR,
**                       Spi_CSIXTransmitISR, Spi_CSIXDMACompleteISR
**                       Spi_CSIXProcessEndJob, Spi_CSIXReceiveChannelFifoMode,
**                       Spi_CSIXReceiveChannelDirectAccessMode,
**                       Spi_CSIXReceiveChannelTxOnlyMode,
**                       Dem_ReportErrorStatus, Spi_LoadTxData,
**                       Spi_CSIXWriteTX0Register, Spi_CSIXMaskHWUnitTxInterrupt
**                       Spi_CSIXProcessJob, Spi_ProcessSequence,
**                       Spi_CSIXTurnOffUnit, Spi_HWControlCS,
**                       Spi_CSIXMaskHWUnitInterrupts, Spi_StoreRxData,
**                       Spi_CSIXReadRX0Register, Spi_HWBufferStoreRxData,
**                       Spi_CSIXInitializeForJob, Spi_CSIXInitializeForCh,
**                       Spi_CSIXStartChannelDirectAccessMode,
**                       Spi_CSIXStartChannelFifoMode, Spi_PopFromQueue,
**                       Spi_CSIXStartChannelHwBuffer, Spi_RemoveFromQueue,
**                       Spi_CSIXTurnOnUnit, Spi_CSIXDMASetUp, Spi_DMAStart
**                       Spi_CSIXDMAStartChannelFifoMode,
**                       Spi_ProcessJob, Spi_CheckSeqFinish,
**                       Spi_InvokeNotifications, Spi_DMAMaskHWUnitInterrupts,
**                       Spi_CSIXMaskHWUnitRxInterrupt, Spi_HWBufferLoadTxData,
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2,
**                       CSIHnMCTL0, CSIHnMCTL1, CSIHnMCTL2,
**                       CSIXnBRS, PSRn, CSIXnTX0W, EICn/ICxxx
**                       CSIHnRX0W, CSIGnCFG0, CSIHnCFGx
**                       CSIXnSTCR0, CSIXnSTR0, CSIHnRX0H, CSIGnRX0
**                       DCENn, DSAn, DTCTn, DCSTCn, DTCn, DTFRRQCn, DDAn
*******************************************************************************/
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
FUNC(void, SPI_PUBLIC_CODE) Spi_MainFunction_Handling(void)
 /* References: SPI_DDD_ACT_015 */
{
  /* QAC Warning: START Msg(2:3416)-3 */
  /* If SPI Driver is not initialized yet or in the interrupt mode,
     return immediately without any operation */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_015_ERR001 */
  {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_MAINFUNCTION_HANDLING_SID, SPI_E_UNINIT);
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
   }
  /* QAC Warning: START Msg(2:3416)-3 */
  else if (SPI_INTERRUPT_MODE == Spi_GenAsyncMode)
  /* END Msg(2:3416)-3 */
  {
    /* Do nothing */
  }
  else
  {
    Spi_CSIXMainFunction_Handling();
  }
}
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

/*******************************************************************************
** Function Name       : Spi_ForceCancel
**
** Service ID          : 0xA0
**
** Description         : This service cancels a on-going Sequence immediately.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant among Sequences which don't share same HW
**                       Non-Reentrant among Sequences which share same HW
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi_Init must have been invoked.
**                       This function must not be invoked in a context which
**                       has the higher priority than any SPI ISRs.
**                       If this service preempts any ISRs,
**                       the subsequent operation is not guaranteed.
**
** Global Variable     : Spi_GblInitialized, Spi_GpConfigPtr, Spi_GpFirstSeq
**
** Function invoked    : Det_ReportError, Spi_CancelSequence,
**                       Spi_RemoveFromQueue,
**                       Spi_CSIXForceStop, Spi_ProcessSequence,
**                       Spi_InvokeNotifications
**                       Spi_DMAStop, Spi_CSIXTurnOffUnit, Spi_PopFromQueue,
**                       Spi_ProcessJob, Spi_CheckSeqFinish,
**                       Dem_ReportErrorStatus, Spi_CSIXProcessJob,
**                       Spi_CSIXInitializeForJob, Spi_CSIXInitializeForCh,
**                       Spi_CSIXStartChannelDirectAccessMode,
**                       Spi_CSIXStartChannelFifoMode, Spi_HWControlCS,
**                       Spi_CSIXStartChannelHwBuffer,
**                       Spi_CSIXTurnOnUnit, Spi_CSIXDMASetUp,
**                       Spi_CSIXDMAStartChannelFifoMode, Spi_DMAStart,
**                        Spi_LoadTxData, Spi_CSIXWriteTX0Register,
**                       Spi_CSIXMaskHWUnitInterrupts,
**                       Spi_HWBufferLoadTxData, Spi_CSIXMaskHWUnitRxInterrupt,
**                       Spi_DMAMaskHWUnitInterrupts,
**                       Spi_CSIXMaskHWUnitTxInterrupt,
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2, EICn/ICxxx, CSIXnTX0W
**                       CSIHnMCTL0, CSIHnMCTL1, CSIHnMCTL2, PSRn, DCENn,
**                       DSAn, DTCTn, DTCn, DCSTCn, DCSTn, DTFRRQCn, DDAn,
**                       CSIGnCFG0, CSIHnCFGx, CSIXnBRS, CSIXnSTCR0.
*******************************************************************************/
#if (SPI_FORCE_CANCEL_API == STD_ON)
FUNC(void, SPI_PUBLIC_CODE) Spi_ForceCancel(
  CONST(Spi_SequenceType, AUTOMATIC) LucSequence)
 /* References: SPI_DDD_ACT_016 */
{
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  /* References: SPI_DDD_ACT_016_ERR001 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_FORCECANCEL_SID, SPI_E_UNINIT);
  }
  /* Check if the sequence ID passed, is valid */
  else if (Spi_GpConfigPtr->ucNoOfSequences <= LucSequence)
    /* References: SPI_DDD_ACT_016_ERR002 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_FORCECANCEL_SID, SPI_E_PARAM_SEQ);
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* MISRA Violation: START Msg(4:0491)-2 */
  else if (SPI_TRUE == Spi_GpFirstSeq[LucSequence].blSynchronous)
  /* END Msg(4:0491)-2 */
  /* References: SPI_DDD_ACT_016_ERR003 */
  {
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_FORCECANCEL_SID, SPI_E_PARAM_SEQ);
  }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */
  else
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
  {
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_0)
    /* References: SPI_DDD_ACT_016_ERR004 */
    /* When LEVEL0, always raise error */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_FORCECANCEL_SID, SPI_E_PARAM_SEQ);
#endif
#else
    Spi_CancelSequence((uint32)LucSequence, SPI_TRUE, SPI_FORCECANCEL_SID);
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_0) */
  }
}
#endif /* (SPI_FORCE_CANCEL_API == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_SetClockMode
**
** Service ID          : 0xA1
**
** Description         : This function is to set the operating mode depending on
**                       clock selected(Normal mode/Low power mode).
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : LenClockMode: Spi_ClockModeType
**                       (SPI_CLOCK_MODE_NORMAL/SPI_CLOCK_MODE_LOW_POWER)
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions       : None
**
** Global Variable     : Spi_GblInitialized, Spi_GenClockModeStatus
**                       Spi_GulActiveSyncHWUnits, Spi_GulAllQueueSts
**
** Function Invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
#if (SPI_SET_CLOCK_MODE_ENABLED == STD_ON)
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetClockMode(
  CONST(Spi_ClockModeType, AUTOMATIC) LenClockMode)
/* References: SPI_DDD_ACT_062 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Det Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  {
    /* References: SPI_DDD_ACT_062_ER001 */
    /* Report to DET module */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SETCLOCKMODE_SID, SPI_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  else if ((SPI_CLOCK_MODE_NORMAL != LenClockMode) &&
    (SPI_CLOCK_MODE_LOW_POWER != LenClockMode))
  {
    /* References: SPI_DDD_ACT_062_ER002 */
    /* Det Check if API is called with invalid arguments */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SETCLOCKMODE_SID, SPI_E_PARAM_VALUE);
    LucReturnValue = E_NOT_OK;
  }
  /* QAC Warning: START Msg(2:3416)-3 */
  else if ((uint32)SPI_ZERO !=
  /* END Msg(2:3416)-3 */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_0)
    Spi_GulActiveSyncHWUnits
    /* References: SPI_DDD_ACT_062_ER003 */
#elif (SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
    /* References: SPI_DDD_ACT_062_ER004 */
    Spi_GulAllQueueSts
#else
    (Spi_GulActiveSyncHWUnits | Spi_GulAllQueueSts)
    /* References: SPI_DDD_ACT_062_ER005 */
#endif
  )
  {
    /* Check if Driver is busy */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SETCLOCKMODE_SID, SPI_E_DRIVER_BUSY);
    /* Change clock mode not done */
    LucReturnValue = E_NOT_OK;
  }
  else
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
  {
    Spi_GenClockModeStatus = LenClockMode;
    /* References: SPI_DDD_ACT_062_GBL001 */
    /* Clock Mode set is OK */
    LucReturnValue = E_OK;
  }

  return(LucReturnValue);
}
#endif  /* End of (SPI_SET_CLOCK_MODE_ENABLED == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_GetErrorInfo
**
** Service ID          : 0xA2
**
** Description         : Function to Copy Hardware Error Details to User Buffer.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : LpUserBuffer - User Buffer pointer.
**                       LucBufferSize - Number of Errors To be copied.
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : LucNoOfErrorsCopied - Number of Errors Copied.
**
** Preconditions       : None
**
** Global Variable     : Spi_GblInitialized, Spi_GstErrorBuffer
**
** Function Invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
FUNC(uint8, SPI_PUBLIC_CODE) Spi_GetErrorInfo(
  P2VAR(Spi_CommErrorType, AUTOMATIC, SPI_CONFIG_DATA) LpUserBuffer,
  CONST(uint8, AUTOMATIC) LucBufferSize)
/* References: SPI_DDD_ACT_063 */
{
  /* Variable to count the number of errors copied to the user buffer */
  VAR(uint8, AUTOMATIC) LucNoOfErrorsCopied;
  /* Variable to hold Error Buffer index */
  VAR(uint8, AUTOMATIC) LucErrorIndex;
  /* Local pointer for error information */
  volatile P2CONST(Spi_CommErrorType, AUTOMATIC, SPI_APPL_CONST)
    LpCommErrorInfo;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Det check result */
  VAR(Std_ReturnType, AUTOMATIC) LucDetCheckResult;
  LucDetCheckResult = E_OK;
#endif

  LucNoOfErrorsCopied = SPI_ZERO;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  {
    /* References: SPI_DDD_ACT_063_ERR001 */
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETERRORINFO_SID, SPI_E_UNINIT);
    LucDetCheckResult = E_NOT_OK;
  }
  /* Check if the data buffer pointer passed, is NULL pointer */
  else if (NULL_PTR == LpUserBuffer)
  {
    /* References: SPI_DDD_ACT_063_ERR002 */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETERRORINFO_SID, SPI_E_PARAM_POINTER);
    LucDetCheckResult = E_NOT_OK;
  }
  else if ((uint8)SPI_MAX_ERROR_BUFFER_SIZE < LucBufferSize)
  {
    /* References: SPI_DDD_ACT_063_ERR003 */
    /* Det Check if API is called with invalid arguments */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_GETERRORINFO_SID, SPI_E_PARAM_VALUE);
    LucDetCheckResult = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }

  /* Check if any error reported */
  if (E_OK == LucDetCheckResult)
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check next index store error */
    if ((uint8)SPI_ZERO != Spi_GstErrorBuffer.ucNextIndex)
    {
      LucErrorIndex = (uint8)(Spi_GstErrorBuffer.ucNextIndex - (uint8)SPI_ONE);
    }
    else
    {
      LucErrorIndex = (uint8)(SPI_MAX_ERROR_BUFFER_SIZE - SPI_ONE);
    }

    /*Get the latest error information reported */
    LpCommErrorInfo = &Spi_GstErrorBuffer.aaErrorInfo[(uint32)LucErrorIndex];

    /* While loop is to copy the latest errors occurring into user buffer */
    while (((uint8)SPI_MAX_ERROR_BUFFER_SIZE > LucNoOfErrorsCopied) && \
      (LucNoOfErrorsCopied < LucBufferSize) && \
      (SPI_NO_ERROR != LpCommErrorInfo->enErrorType))
    {
      /* Copy the Hardware unit Index */
      LpUserBuffer->ucHwUnit = LpCommErrorInfo->ucHwUnit;
      /* Copy the Sequence Index */
      LpUserBuffer->ucSeqID = LpCommErrorInfo->ucSeqID;
      /* Copy the Job Index */
      LpUserBuffer->usJobID = LpCommErrorInfo->usJobID;
      /* Copy the Error */
      LpUserBuffer->enErrorType = LpCommErrorInfo->enErrorType;
      /* Increment the User Buffer Location */
      LucNoOfErrorsCopied++;
      /* MISRA Violation: START Msg(4:0489)-6 */
      LpUserBuffer++;
      /* END Msg(4:0489)-6 */
      /*
       * Since the Error Buffer is a cyclic one, update the Buffer Index with
       * Maximum Buffer size if reaches zero.
      */
      if ((uint8)SPI_ZERO == LucErrorIndex)
      {
        LucErrorIndex = (uint8)(SPI_MAX_ERROR_BUFFER_SIZE - SPI_ONE);
      }
      else
      {
        LucErrorIndex--;
      }
      /*Get the global pointer to local variable*/
      LpCommErrorInfo = &Spi_GstErrorBuffer.aaErrorInfo[LucErrorIndex];
    } /*
       * End while ((SPI_MAX_ERROR_BUFFER_SIZE > LucNoOfErrorsCopied) && \
       *          (LucNoOfErrorsCopied < LucBufferSize) && \
       *          (SPI_NO_ERROR != Spi_GstErrorBuffer.aaErrorInfo.enErrorType))
       */
  }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do nothing */
  }
#endif

  /* Return the number of errors copied*/
  return(LucNoOfErrorsCopied);
}
#endif /* (SPI_MAX_ERROR_BUFFER_SIZE > 0) */

/*******************************************************************************
** Function Name       : Spi_SelfTest
**
** Service ID          : 0xA3
**
** Description         : This function is to perform self test functionality
**                       of data transmission in loop back mode.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_SelfTestReturnType
**                      (SPI_SELFTEST_DRIVERBUSY,
**                       SPI_SELFTEST_PASSED, SPI_SELFTEST_FAILED)
**
** Preconditions       : None
**
** Global Variable     : None
**
** Function Invoked    : Spi_CSIXLoopBackSelfTest, Spi_CSIHEccSelfTest,
**                       Det_ReportError, Spi_CSIXDeInit, Spi_CSIXInit,
**                       Spi_CSIXTurnOffUnit, Dem_ReportErrorStatus,
**                       Spi_CSIXReadRX0Register, Spi_EccAllZeroTest,
**                       Spi_EccAllOneTest, Spi_CSIXTurnOnUnit
**                       Spi_EccWalkOneTest, Spi_EccTwoBitTest,
**                       Spi_CSIXDisableAllInterrupts, Spi_HWControlCS,
**                       Spi_CSIHInitRegs, Spi_CSIXInitializeForJob.
**
** Registers Used      : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2,
**                       CSIHnMCTL0,CSIHnMCTL1,CSIHnMCTL2, CSIXnSTR0,
**                       CSIXnSTCR0, CSIXnBRSy, CSIGnCFG0, CSIHnCFGx,
**                       CSIXnBRSx, ECCCSIHnCTL, ECCCSIHnTMC, CSIHnRX0H,
**                       CSIXnBRS, CSIHnBRSm, CSIGnBCTL0, PSRn, CSIGnRX0
**                       ECCCSIHnTED, ECCCSIHnTRC, ECCCSIHnERDB, EICn/ICxxx.
*******************************************************************************/
#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
FUNC(Spi_SelfTestReturnType, SPI_PUBLIC_CODE) Spi_SelfTest(void)
/* References: SPI_DDD_ACT_066 */
{
  VAR(Spi_SelfTestReturnType, AUTOMATIC) LenReturnTestStatus;
  VAR(Std_ReturnType, AUTOMATIC) LucHWSelfTestResult;

  #if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
  VAR(boolean, AUTOMATIC) LbCSIXDeInit;
  LbCSIXDeInit = SPI_FALSE;
  #endif

  /* QAC Warning: START Msg(2:3416)-3 */
  if ((uint32)SPI_ZERO !=
  /* END Msg(2:3416)-3 */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_0)
    Spi_GulActiveSyncHWUnits
/* References: SPI_DDD_ACT_066_ER001 */
#elif (SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
    Spi_GulAllQueueSts
/* References: SPI_DDD_ACT_066_ER002 */
#else
    (Spi_GulActiveSyncHWUnits | Spi_GulAllQueueSts)
/* References: SPI_DDD_ACT_066_ER003 */
#endif
  )
  {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
      SPI_SELFTEST_SID, SPI_E_DRIVER_BUSY);
#endif
    /* Set return value as driver busy */
    LenReturnTestStatus = SPI_SELFTEST_DRIVERBUSY;
  }
  else
  {
#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
    /* QAC Warning: START Msg(2:3416)-3 */
    if (SPI_TRUE == Spi_GblInitialized)
    /* END Msg(2:3416)-3 */
    {
      /* DeInit CSIX Driver if Driver already initialized */
      Spi_CSIXDeInit(SPI_SELFTEST_SID);
      LbCSIXDeInit = SPI_TRUE;
    }
    else
    {
      /* Nothing to do */
    }

    /* Call Loop Back Self Test API */
    LucHWSelfTestResult = Spi_CSIXLoopBackSelfTest(SPI_SELFTEST_SID);

    if (SPI_TRUE == LbCSIXDeInit)
    {
      /* Initialize again CSIX after performing self-test */
      Spi_CSIXInit(SPI_SELFTEST_SID);
    }
    else
    {
      /* Nothing to do */
    }
#endif /* (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)*/

#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
    /* Call ECC Self Test API */
    if (E_OK == LucHWSelfTestResult)
#endif
    {
      LucHWSelfTestResult = Spi_CSIHEccSelfTest();
    }
#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
    else
    {
      /* No action required */
    }
#endif /* (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME) */
#endif /* (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME) */
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */

    /* Check whether HW self-test is OK */
    if (E_OK == LucHWSelfTestResult)
    {
      LenReturnTestStatus = SPI_SELFTEST_PASSED;
    }
    else
    {
      LenReturnTestStatus = SPI_SELFTEST_FAILED;
    }
  }
  /* Return self test status */
  return LenReturnTestStatus;
}
#endif /* (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME) */

#if (SPI_CSIX_RAM_MIRROR == STD_ON) || (SPI_DMA_RAM_MIRROR == STD_ON)
/*******************************************************************************
** Function Name        : Spi_CheckHWConsistency
**
** Service ID           : 0xA4
**
** Description          : This API which compares the control register values
**                        with the RAM mirror/ROM as part of the hardware
**                        consistency check.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LenHWConsistencyMode - HW consistency mode type
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions        : None
**
** Global Variables     : Spi_GblInitialized
**
** Functions invoked    : Det_ReportError, Spi_CSIXRegsConsistencyCheck
**                        Spi_DMARegsConsistencyCheck,
**                        Spi_CSIHRegsConsistencyCheck,
**                        SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used       : CSIHnCTL0, CSIHnCTL1, CSIHnCTL2,
**                        CSIHnMCTL0, CSIHnMCTL1, CSIHnCFGx, CSIGnCFG0,
**                        CSIHBRSx, DTFRn, DSAn, DDAn
*******************************************************************************/
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_CheckHWConsistency(
  CONST(Spi_HWConsistencyModeType, AUTOMATIC) LenHWConsistencyMode)
/* References: SPI_DDD_ACT_079 */
{
  /* Local Variable for Status Return */
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

  /* MISRA Violation: START Msg(4:2982)-5 */
  LucReturnValue = E_OK;
  /* END Msg(4:2982)-5 */

#if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-3 */
  /* Det Check if SPI Driver is initialized */
  if (SPI_FALSE == Spi_GblInitialized)
  /* END Msg(2:3416)-3 */
  {
    /* Report to DET module */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
    SPI_CHECKHWCONSISTENCY_SID, SPI_E_UNINIT);
    /* References: SPI_DDD_ACT_079_ERR001 */
    LucReturnValue = E_NOT_OK;
  }
  /* Det Check if Spi_CheckHWConsistency is called with invalid arguments */
  else if ((SPI_DYNAMIC != LenHWConsistencyMode) &&
    (SPI_STATIC != LenHWConsistencyMode))
  {
    /* Report to DET module */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
    SPI_CHECKHWCONSISTENCY_SID, SPI_E_PARAM_VALUE);
    /* References: SPI_DDD_ACT_079_ERR002 */
    LucReturnValue = E_NOT_OK;
  }
  else
#endif  /* End of #if (SPI_DEV_ERROR_DETECT == STD_ON)*/
  {
#if (SPI_CSIX_RAM_MIRROR == STD_ON)
    /* Check Hardware consistency of CSIX registers */
    LucReturnValue = Spi_CSIXRegsConsistencyCheck(LenHWConsistencyMode);
#endif

#if (SPI_DMA_CONFIGURED == STD_ON)
#if (SPI_DMA_RAM_MIRROR == STD_ON)
    if (E_OK == LucReturnValue)
    {
      /* Check Hardware consistency of DMA registers */
      LucReturnValue = Spi_DMARegsConsistencyCheck(LenHWConsistencyMode);
    }
    else
    {
      /* Nothing to do */
    }
#endif /* (SPI_DMA_RAM_MIRROR == STD_ON) */
#endif /* (SPI_DMA_CONFIGURED == STD_ON) */
  }
  return(LucReturnValue);
}
#endif /* (SPI_CSIX_RAM_MIRROR == STD_ON) || (SPI_DMA_RAM_MIRROR == STD_ON) */

#define SPI_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-4 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-4 */

#define SPI_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-4 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-4 */

/*******************************************************************************
** Function Name       : Spi_SetStatus
**
** Service ID          : Not Applicable
**
** Description         : This function updates Spi_GblInitialized.
**                       The purpose of this function is to prevent the order of
**                       instructions being changed by the compiler.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : LblStatus: New status value
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : None
**
** Global Variable     : Spi_GblInitialized
**
** Function invoked    : None
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_SetStatus(
  CONST(boolean, AUTOMATIC) LblStatus)
/* References: SPI_DDD_ACT_017 */
{
  Spi_GblInitialized = LblStatus;
  /* References: SPI_DDD_ACT_017_GBL001 */
}

/*******************************************************************************
** Function Name       : Spi_MemCopy
**
** Service ID          : Not Applicable
**
** Description         : This function copies data from memory to memory
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : LpChConfig - Pointer to Channel configuration
**                       LpDesPtr   - Pointer to the destination address
**                       LpSrcPtr   - Pointer to the source address
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : None
**
** Global Variable     : None
**
** Function invoked    : None
**
** Registers Used      : None
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
static FUNC(void, SPI_PRIVATE_CODE) Spi_MemCopy(
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile CONSTP2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpDesPtr,
  volatile CONSTP2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpSrcPtr)
/* References: SPI_DDD_ACT_018 */
{
  VAR(uint32, AUTOMATIC) LulCounter;
  LulCounter = SPI_ZERO;
  if (NULL_PTR == LpSrcPtr)
  {
    switch (LpChConfig->ucByteSize)
    {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    case sizeof(uint32):
      /* Copy default data by 4bytes */
      do
      {
        /* MISRA Violation: START Msg(4:0310)-3 */
        /* QAC Warning: START Msg(3:3305)-2 */
        /* MISRA Violation: START Msg(4:0492)-4 */
        ((volatile uint32*)LpDesPtr)[LulCounter] =
          (uint32)LpChConfig->ulDefaultData;
        /* END Msg(4:0492)-4 */
        /* END Msg(3:3305)-2 */
        /* END Msg(4:0310)-3 */
        LulCounter++;
      } while (LulCounter < LpChConfig->usNoOfBuffers);
      break;
#endif
    case sizeof(uint16):
      /* Copy default data by 2bytes */
      do
      {
        /* MISRA Violation: START Msg(4:0310)-3 */
        /* QAC Warning: START Msg(3:3305)-2 */
        /* MISRA Violation: START Msg(4:0492)-4 */
        ((volatile uint16*)LpDesPtr)[LulCounter] =
          (uint16)LpChConfig->ulDefaultData;
        /* END Msg(4:0492)-4 */
        /* END Msg(3:3305)-2 */
        /* END Msg(4:0310)-3 */
        LulCounter++;
      } while (LulCounter < LpChConfig->usNoOfBuffers);
      break;
    default:
      /* Copy default data by byte */
      do
      {
        /* MISRA Violation: START Msg(4:0492)-4 */
        LpDesPtr[LulCounter] = (uint8)LpChConfig->ulDefaultData;
        /* END Msg(4:0492)-4 */
        LulCounter++;
      } while (LulCounter < LpChConfig->usNoOfBuffers);
      break;
    /* QAC Warning: START Msg(3:3352)-6 */
    }
    /* END Msg(3:3352)-6 */
  }
  else
  {
    switch (LpChConfig->ucByteSize)
    {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    case sizeof(uint32):
      /* Copy memory by 4bytes */
      do
      {
        /* MISRA Violation: START Msg(4:0310)-3 */
        /* QAC Warning: START Msg(3:3305)-2 */
        /* MISRA Violation: START Msg(4:0492)-4 */
        ((volatile uint32*)LpDesPtr)[LulCounter] =
          ((const volatile uint32*)LpSrcPtr)[LulCounter];
        /* END Msg(4:0492)-4 */
        /* END Msg(3:3305)-2 */
        /* END Msg(4:0310)-3 */
        LulCounter++;
      } while (LulCounter < LpChConfig->usNoOfBuffers);
      break;
#endif
    case sizeof(uint16):
      /* Copy memory by 2bytes */
      do
      {
        /* MISRA Violation: START Msg(4:0310)-3 */
        /* QAC Warning: START Msg(3:3305)-2 */
        /* MISRA Violation: START Msg(4:0492)-4 */
        ((volatile uint16*)LpDesPtr)[LulCounter] =
          ((const volatile uint16*)LpSrcPtr)[LulCounter];
        /* END Msg(4:0492)-4 */
        /* END Msg(3:3305)-2 */
        /* END Msg(4:0310)-3 */
        LulCounter++;
      } while (LulCounter < LpChConfig->usNoOfBuffers);
      break;
    default:
      /* Copy memory by byte */
      do
      {
        /* MISRA Violation: START Msg(4:0492)-4 */
        LpDesPtr[LulCounter] = LpSrcPtr[LulCounter];
        /* END Msg(4:0492)-4 */
        LulCounter++;
      } while (LulCounter < LpChConfig->usNoOfBuffers);
      break;
    /* QAC Warning: START Msg(3:3352)-6 */
    }
    /* END Msg(3:3352)-6 */
  }
}
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
(SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/*******************************************************************************
** Function Name       : Spi_InitQueue
**
** Service ID          : Not Applicable
**
** Description         : This function initialize global variables related to
**                       queue.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : None
**
** Global Variable     : Spi_GulAllQueueSts, Spi_GaaQueue
**
** Function invoked    : None
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitQueue(void)
/* References: SPI_DDD_ACT_082 */
{
  VAR(uint32, AUTOMATIC) LulIndex;
  VAR(uint32, AUTOMATIC) LulPriorityIndex;

  /* Initialize Queues */
  Spi_GulAllQueueSts = SPI_ZERO;
  /* References: SPI_DDD_ACT_082_GBL001 */
  /* QAC Warning: START Msg(4:2877)-5 */
  for (LulIndex = SPI_ZERO; (uint32)SPI_MAX_QUEUE > LulIndex; LulIndex++)
  /* END Msg(4:2877)-5 */
  {
    Spi_GaaQueue[LulIndex].ucExists = SPI_ZERO;
    /* References: SPI_DDD_ACT_082_GBL002 */
    Spi_GaaQueue[LulIndex].ucOngoingSeqIndex = SPI_INVALID_SEQUENCE;
    /* References: SPI_DDD_ACT_082_GBL003 */
    /* The following variable must be written before the first reading,
       but initialize with zero just in case */
    for (LulPriorityIndex = SPI_ZERO;
      LulPriorityIndex < ((uint32)SPI_MAX_PRIORITY + (uint32)SPI_ONE);
      LulPriorityIndex++)
    {
      Spi_GaaQueue[LulIndex].aaTop[LulPriorityIndex] = SPI_ZERO;
      /* References: SPI_DDD_ACT_082_GBL004 */
      Spi_GaaQueue[LulIndex].aaTail[LulPriorityIndex] = SPI_ZERO;
      /* References: SPI_DDD_ACT_082_GBL005 */
    }
  }
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

/*******************************************************************************
** Function Name       : Spi_InitHWStatus
**
** Service ID          : Not Applicable
**
** Description         : This function initialize global variable
**                       Hardware status.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi_GpConfigPtr was assigned to ConfigPtr.
**
** Global Variable     : Spi_GaaHWStatus, Spi_GpConfigPtr
**
** Function invoked    : None
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitHWStatus(void)
/* References: SPI_DDD_ACT_083 */
{
  VAR(uint32, AUTOMATIC) LulIndex;

  for (LulIndex = SPI_ZERO;
    LulIndex < Spi_GpConfigPtr->ucNoOfHWUnits; LulIndex++)
  {
#if (SPI_HW_STATUS_API == STD_ON)
    Spi_GaaHWStatus[LulIndex].blActive = SPI_FALSE;
   /* References: SPI_DDD_ACT_083_GBL001 */
#endif
    /* The following variable must be written before the first reading,
       but initialize with zero just in case */
    Spi_GaaHWStatus[LulIndex].ucOngoingSeqIndex = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL002 */
    Spi_GaaHWStatus[LulIndex].usOngoingJobIndex = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL003 */
    Spi_GaaHWStatus[LulIndex].ulOngoingQueueIndex = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL016 */
    Spi_GaaHWStatus[LulIndex].ucTxChannelCount = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL004 */
    Spi_GaaHWStatus[LulIndex].ucRxChannelCount = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL005 */
    Spi_GaaHWStatus[LulIndex].usRemainedTxCount = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL006 */
    Spi_GaaHWStatus[LulIndex].usRemainedRxCount = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL007 */
#if ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON) || \
  (SPI_TX_ONLY_MODE == STD_ON))
    Spi_GaaHWStatus[LulIndex].pTxPtr = NULL_PTR;
    /* References: SPI_DDD_ACT_083_GBL008 */
    Spi_GaaHWStatus[LulIndex].pRxPtr = NULL_PTR;
    /* References: SPI_DDD_ACT_083_GBL009 */
#endif
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    Spi_GaaHWStatus[LulIndex].blTxEDLOngoing = SPI_FALSE;
    /* References: SPI_DDD_ACT_083_GBL010 */
    Spi_GaaHWStatus[LulIndex].blRxEDLOngoing = SPI_FALSE;
    /* References: SPI_DDD_ACT_083_GBL011 */
    Spi_GaaHWStatus[LulIndex].ulTxEDLSecondWord = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL012 */
    Spi_GaaHWStatus[LulIndex].usRxEDLFirstWord = SPI_ZERO;
    /* References: SPI_DDD_ACT_083_GBL013 */
#endif
#if (SPI_FIFO_MODE == STD_ON)
    Spi_GaaHWStatus[LulIndex].blIsTxBufferFull = SPI_FALSE;
    /* References: SPI_DDD_ACT_083_GBL014 */
    Spi_GaaHWStatus[LulIndex].blIsRxBufferFull = SPI_FALSE;
    /* References: SPI_DDD_ACT_083_GBL015 */
#endif
  }
}

/*******************************************************************************
** Function Name       : Spi_InitJobSeqStatus
**
** Service ID          : Not Applicable
**
** Description         : This function initialize global variables -
**                       Job status and Sequence status.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi_GpConfigPtr was assigned to ConfigPtr.
**
** Global Variable     : Spi_GpConfigPtr, Spi_GaaJobStatus, Spi_GaaSeqStatus,
**                       Spi_GaaActiveSequence
**
** Function invoked    : None
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitJobSeqStatus(void)
/* References: SPI_DDD_ACT_084 */
{
  VAR(uint32, AUTOMATIC) LulNumJobs;
  VAR(uint32, AUTOMATIC) LulNumSeq;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
(SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
  VAR(uint32, AUTOMATIC) LulSubIndex;
  VAR(uint32, AUTOMATIC) LulPriorityIndex;
#endif

  /* Initialize Job results */
  for (LulNumJobs = SPI_ZERO;
    Spi_GpConfigPtr->usNoOfJobs > LulNumJobs; LulNumJobs++)
  {
    Spi_GaaJobStatus[LulNumJobs].enResult = SPI_JOB_OK;
    /* References: SPI_DDD_ACT_084_GBL001 */
  }

  /* Initialize Sequence results */
  for (LulNumSeq = SPI_ZERO;
    Spi_GpConfigPtr->ucNoOfSequences > LulNumSeq; LulNumSeq++)
  {
    Spi_GaaSeqStatus[LulNumSeq].enResult = SPI_SEQ_OK;
    /* References: SPI_DDD_ACT_084_GBL002 */
#if (SPI_LEVEL_DELIVERED != SPI_LEVEL_0)
#if (SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT == STD_ON)
    Spi_GaaSeqStatus[LulNumSeq].ulActiveSubSequences = (uint32)SPI_ZERO;
    /* References: SPI_DDD_ACT_084_GBL006 */
#endif
#endif
    /* The following variable must be written before the first reading,
       but initialize with zero just in case */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
(SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    /* QAC Warning: START Msg(4:2877)-5 */
    for (LulSubIndex = SPI_ZERO;
      LulSubIndex < (uint32)SPI_MAX_QUEUE; LulSubIndex++)
    /* END Msg(4:2877)-5 */
    {
      Spi_GaaSeqStatus[LulNumSeq].aaSubSeqs[
        LulSubIndex].usRemainJobCount = SPI_ZERO;
      /* References: SPI_DDD_ACT_084_GBL003 */
      for (LulPriorityIndex = SPI_ZERO;
        LulPriorityIndex < ((uint32)SPI_MAX_PRIORITY + (uint32)SPI_ONE);
        LulPriorityIndex++)
      {
        Spi_GaaSeqStatus[LulNumSeq].aaSubSeqs[
          LulSubIndex].aaPrev[LulPriorityIndex] = SPI_ZERO;
        /* References: SPI_DDD_ACT_084_GBL004 */
        Spi_GaaSeqStatus[LulNumSeq].aaSubSeqs[
          LulSubIndex].aaNext[LulPriorityIndex] = SPI_ZERO;
        /* References: SPI_DDD_ACT_084_GBL005 */
      }
    }
#endif
  }

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
  /* Initialize Sequence activation status */
  /* QAC Warning: START Msg(4:2877)-5 */
  for (LulSubIndex = SPI_ZERO;
    SPI_BITS_TO_WORDS(SPI_MAX_SEQUENCE) > LulSubIndex; LulSubIndex++)
  /* END Msg(4:2877)-5 */
  {
    Spi_GaaActiveSequence[LulSubIndex] = SPI_ZERO;
    /* References: SPI_DDD_ACT_084_GBL007 */
  }
#endif
}

/*******************************************************************************
** Function Name       : Spi_InitChannelBuffer
**
** Service ID          : Not Applicable
**
** Description         : This function initialize each Channel buffers.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi_GpConfigPtr was assigned to ConfigPtr.
**
** Global Variable     : Spi_GpConfigPtr, Spi_GpFirstChannel,
**                       Spi_GaaChannelBuffer
**
** Function invoked    : Spi_CSIXWriteHWIB, Spi_MemCopy,
**                       Spi_HWBufferLoadTxData, Spi_LoadTxData
**
** Registers Used      : CSIHnMRWP0, CSIXnTX0W
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitChannelBuffer(void)
/* References: SPI_DDD_ACT_085 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(Spi_ChannelType, AUTOMATIC) LulNumChannel;
#if (SPI_MAX_CHANNEL_BUFFER_SIZE > SPI_ZERO)
  VAR(uint32, AUTOMATIC) LulIndex;
  /* Initialize entire internal buffer */
  for (LulIndex = SPI_ZERO; LulIndex <
    ((uint32)SPI_MAX_CHANNEL_BUFFER_SIZE / (uint32)sizeof(uint32)); LulIndex++)
  {
    Spi_GaaChannelBuffer[LulIndex] = SPI_ZERO;
    /* References: SPI_DDD_ACT_085_GBL001 */
  }
#endif

  /* Initialize each Channel buffers */
  for (LulNumChannel = SPI_ZERO;
    Spi_GpConfigPtr->ucNoOfChannels > LulNumChannel; LulNumChannel++)
  {
    /* MISRA Violation: START Msg(4:0491)-2 */
    LpChConfig = &Spi_GpFirstChannel[LulNumChannel];
    /* END Msg(4:0491)-2 */
    if (SPI_BUFFER_TYPE_EB == LpChConfig->enChannelBufferType)
    {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
(SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
      /* When EB, initialize user pointers as NULL */
      LpChConfig->pEBData->usEBLength = (LpChConfig->usNoOfBuffers);
      /* References: SPI_DDD_ACT_085_GBL002 */
      LpChConfig->pEBData->pSrcPtr = NULL_PTR;
      /* References: SPI_DDD_ACT_085_GBL003 */
      LpChConfig->pEBData->pDestPtr = NULL_PTR;
      /* References: SPI_DDD_ACT_085_GBL004 */
#endif
    }
#if (STD_ON == SPI_DUAL_BUFFER_MODE)
    else if (SPI_BUFFER_TYPE_DUAL_HWIB == LpChConfig->enChannelBufferType)
    {
      Spi_CSIXWriteHWIB(LulNumChannel, NULL_PTR, SPI_INIT_SID);
    }
#endif
#if (STD_ON == SPI_TX_ONLY_MODE)
    else if (SPI_BUFFER_TYPE_TX_HWIB == LpChConfig->enChannelBufferType)
    {
      Spi_CSIXWriteHWIB(LulNumChannel, NULL_PTR, SPI_INIT_SID);
    }
#endif
    else
    {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
(SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
      /* When IB, initialize buffer with default data */
      Spi_MemCopy(LpChConfig, LpChConfig->pTxBuffer, NULL_PTR);
#endif
    }
  }
}

#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
/*******************************************************************************
** Function Name       : Spi_InitErrorBuffer
**
** Service ID          : Not Applicable
**
** Description         : This function initialize error buffer structure.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : None
**
** Global Variable     : Spi_GstErrorBuffer
**
** Function invoked    : None
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_InitErrorBuffer(void)
/* References: SPI_DDD_ACT_086 */
{
  volatile P2VAR(Spi_CommErrorType, AUTOMATIC, SPI_APPL_CONST) LpCommErrorInfo;
  VAR(uint32, AUTOMATIC) LulIndex;

  /* Initialize the Error index with zero */
  Spi_GstErrorBuffer.ucNextIndex = SPI_ZERO;
  /* References: SPI_DDD_ACT_086_GBL001 */
   /* Initialise the Error Information buffer with no error */
  for (LulIndex = SPI_ZERO;
    LulIndex < (uint32)SPI_MAX_ERROR_BUFFER_SIZE; LulIndex++)
  {
    LpCommErrorInfo = &Spi_GstErrorBuffer.aaErrorInfo[LulIndex];
    /* Clear the Hardware unit Index */
    LpCommErrorInfo->ucHwUnit = SPI_ZERO;
    /* References: SPI_DDD_ACT_086_GBL002 */
    /* Clear the Sequence Index */
    LpCommErrorInfo->ucSeqID = SPI_ZERO;
    /* References: SPI_DDD_ACT_086_GBL003 */
    /* Clear the Job Index */
    LpCommErrorInfo->usJobID = SPI_ZERO;
    /* References: SPI_DDD_ACT_086_GBL004 */
    /* Clear the Error */
    LpCommErrorInfo->enErrorType = SPI_NO_ERROR;
    /* References: SPI_DDD_ACT_086_GBL005 */
  } /* End while (SPI_MAX_ERROR_BUFFER_SIZE > LucVariable) */
}
#endif

#define SPI_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-4 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-4 */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
