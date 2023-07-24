/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi.h                                                       */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Mar-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, SPI type definitions, structure data types and  */
/* API function prototypes of SPI Driver                                      */
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

#ifndef SPI_H
#define SPI_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi_Cfg.h"
#include "Spi_Types.h"      /* Included for Spi Type declaration */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define SPI_INSTANCE_ID           SPI_INSTANCE_ID_VALUE

/* Version identification */
#define SPI_VENDOR_ID              SPI_VENDOR_ID_VALUE
#define SPI_MODULE_ID              SPI_MODULE_ID_VALUE

/* AUTOSAR specification version information */
#if (SPI_AR_VERSION == SPI_AR_422_VERSION)
#define SPI_AR_RELEASE_MAJOR_VERSION       4
#define SPI_AR_RELEASE_MINOR_VERSION       2
#define SPI_AR_RELEASE_REVISION_VERSION    2
#elif (SPI_AR_VERSION == SPI_AR_403_VERSION)
#define SPI_AR_RELEASE_MAJOR_VERSION       4
#define SPI_AR_RELEASE_MINOR_VERSION       0
#define SPI_AR_RELEASE_REVISION_VERSION    3
#endif /* (SPI_AR_VERSION == SPI_AR_422_VERSION) */

/* File version information */
#define SPI_SW_MAJOR_VERSION       SPI_SW_MAJOR_VERSION_VALUE
#define SPI_SW_MINOR_VERSION       SPI_SW_MINOR_VERSION_VALUE
#define SPI_SW_PATCH_VERSION       SPI_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

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

/*******************************************************************************
**                     Service IDs                                            **
*******************************************************************************/
/* Service ID for Spi_Init() */
#define SPI_INIT_SID                  (uint8)0x00
/* Service ID for Spi_DeInit() */
#define SPI_DEINIT_SID                (uint8)0x01
/* Service ID for Spi_WriteIB() */
#define SPI_WRITEIB_SID               (uint8)0x02
/* Service ID for Spi_AsyncTransmit() */
#define SPI_ASYNCTRANSMIT_SID         (uint8)0x03
/* Service ID for Spi_ReadIB() */
#define SPI_READIB_SID                (uint8)0x04
/* Service ID for Spi_SetupEB() */
#define SPI_SETUPEB_SID               (uint8)0x05
/* Service ID for Spi_GetStatus() */
#define SPI_GETSTATUS_SID             (uint8)0x06
/* Service ID for Spi_GetJobResult() */
#define SPI_GETJOBRESULT_SID          (uint8)0x07
/* Service ID for Spi_GetSequenceResult() */
#define SPI_GETSEQUENCERESULT_SID     (uint8)0x08
/* Service ID for Spi_GetVersionInfo() */
#define SPI_GETVERSIONINFO_SID        (uint8)0x09
/* Service ID for Spi_SyncTransmit() */
#define SPI_SYNCTRANSMIT_SID          (uint8)0x0A
/* Service ID for Spi_GetHWUnitStatus() */
#define SPI_GETHWUNITSTATUS_SID       (uint8)0x0B
/* Service ID for Spi_Cancel() */
#define SPI_CANCEL_SID                (uint8)0x0C
/* Service ID for Spi_SetAsyncMode() */
#define SPI_SETASYNCMODE_SID          (uint8)0x0D
/* Service ID for Spi_MainFunction_Driving() */
#define SPI_MAINFUNCTION_HANDLING_SID (uint8)0x10
/* Service ID for Spi_ForceCancel() */
#define SPI_FORCECANCEL_SID           (uint8)0xA0
/* Service ID for Spi_SetClockMode() */
#define SPI_SETCLOCKMODE_SID          (uint8)0xA1
/* Service ID for Spi_GetErrorInfo() */
#define SPI_GETERRORINFO_SID          (uint8)0xA2
/* Service ID for Spi_SelfTest () */
#define SPI_SELFTEST_SID              (uint8)0xA3
/* Service ID for Spi_CheckHWConsistency */
#define SPI_CHECKHWCONSISTENCY_SID    (uint8)0xA4

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* API services invoked with invalid channel ID */
#define SPI_E_PARAM_CHANNEL           (uint8)0x0A
/* API services invoked with invalid job ID */
#define SPI_E_PARAM_JOB               (uint8)0x0B
/* API services invoked with invalid sequence ID */
#define SPI_E_PARAM_SEQ               (uint8)0x0C
/* Spi_SetupEB API invoked with length greater than configured length */
#define SPI_E_PARAM_LENGTH            (uint8)0x0D
/* Spi_GetHWUnitStatus API invoked with invalid hardware unit ID */
#define SPI_E_PARAM_UNIT              (uint8)0x0E
/* API services invoked before the initialization of SPI Driver */
#define SPI_E_UNINIT                  (uint8)0x1A
/* API services invoked in a wrong sequence */
#define SPI_E_SEQ_PENDING             (uint8)0x2A
/* Spi_SyncTransmit API invoked at wrong time */
#define SPI_E_SEQ_IN_PROCESS          (uint8)0x3A
/* Spi_init API service called while the Spi driver has already been
* initialized
*/
#define SPI_E_ALREADY_INITIALIZED     (uint8)0x4A
/* Spi_Init API invoked with pointer to invalid database */
#define SPI_E_INVALID_DATABASE        (uint8)0xEF

/* Spi_GetVersionInfo API invoked with invalid pointer */
#define SPI_E_PARAM_POINTER           (uint8)0x10

/* API services invoked when SPI Driver is busy */
#define SPI_E_DRIVER_BUSY             (uint8)0x20

/* API services invoked with invalid parameter */
#define SPI_E_PARAM_VALUE             (uint8)0x30

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define SPI_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

extern FUNC(void, SPI_PUBLIC_CODE) Spi_Init(
  P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr);

extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_DeInit(void);

#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_WriteIB(
  CONST(Spi_ChannelType, AUTOMATIC) Channel,
  P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr);
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_ReadIB(
  CONST(Spi_ChannelType, AUTOMATIC) Channel,
  P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPointer);
#endif

#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetupEB(
  CONST(Spi_ChannelType, AUTOMATIC) Channel,
  P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
  P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
  CONST(Spi_NumberOfDataType, AUTOMATIC) Length);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_AsyncTransmit(
  CONST(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SyncTransmit(
  CONST(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

extern FUNC(Spi_StatusType, SPI_PUBLIC_CODE) Spi_GetStatus(void);

extern FUNC(Spi_JobResultType, SPI_PUBLIC_CODE) Spi_GetJobResult(
  CONST(Spi_JobType, AUTOMATIC) Job);

extern FUNC(Spi_SeqResultType, SPI_PUBLIC_CODE) Spi_GetSequenceResult(
  CONST(Spi_SequenceType, AUTOMATIC) Sequence);

/* API to get the version information */
#if (SPI_VERSION_INFO_API == STD_ON)
extern FUNC(void, SPI_PUBLIC_CODE) Spi_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo);
#endif /* END of SPI_VERSION_INFO_API */


#if (SPI_HW_STATUS_API == STD_ON)
extern FUNC(Spi_StatusType, SPI_PUBLIC_CODE) Spi_GetHWUnitStatus(
  CONST(Spi_HWUnitType, AUTOMATIC) HWUnit);
#endif

#if (SPI_CANCEL_API == STD_ON)
extern FUNC(void, SPI_PUBLIC_CODE) Spi_Cancel(
  CONST(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetAsyncMode(
  CONST(Spi_AsyncModeType, AUTOMATIC) Mode);
extern FUNC(void, SPI_PUBLIC_CODE) Spi_MainFunction_Handling(void);
#endif

#if (SPI_FORCE_CANCEL_API == STD_ON)
extern FUNC(void, SPI_PUBLIC_CODE) Spi_ForceCancel(
  CONST(Spi_SequenceType, AUTOMATIC) LucSequence);
#endif

#if (SPI_SET_CLOCK_MODE_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetClockMode(
  CONST(Spi_ClockModeType, AUTOMATIC) LenClockMode);
#endif

#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
extern FUNC(uint8, SPI_PUBLIC_CODE) Spi_GetErrorInfo(
  P2VAR(Spi_CommErrorType, AUTOMATIC, SPI_CONFIG_DATA) LpUserBuffer,
  CONST(uint8, AUTOMATIC) LucBufferSize);
#endif

#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
extern FUNC(Spi_SelfTestReturnType, SPI_PUBLIC_CODE) Spi_SelfTest(void);
#endif

#if (SPI_CSIX_RAM_MIRROR == STD_ON) || (SPI_DMA_RAM_MIRROR == STD_ON)
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_CheckHWConsistency(
  CONST(Spi_HWConsistencyModeType, AUTOMATIC) LenHWConsistencyMode);
#endif

#define SPI_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define SPI_START_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Structure for SPI Init configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Spi_ConfigType, SPI_CONST) Spi_GaaConfiguration[];
/* END Msg(4:3684)-1 */

#define SPI_STOP_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* SPI_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
