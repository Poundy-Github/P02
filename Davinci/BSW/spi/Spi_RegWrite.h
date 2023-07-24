/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_RegWrite.h                                              */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Apr-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is to have macro definitions for the registers write, ram        */
/* mirroring and verification.                                                */
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
 * V1.0.0:  12-Apr-2019  : Initial Version.
 */
/******************************************************************************/
#ifndef SPI_REG_WRITE_H
#define SPI_REG_WRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Std_Types.h"
#include "Spi_Cfg.h"
/* Dem.h inclusion to get Dem_ReportErrorStatus declaration */
#include "Dem.h"
#if (SPI_AR_VERSION == SPI_AR_403_VERSION)
#if (SPI_USE_WRITE_VERIFY_ERROR_INTERFACE == STD_ON)
#include "Spi_Cbk.h"
#endif
#endif

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Since the macros are implemented as function macros braces */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for  MISRA Violation: START Msg(4:3458)-1 and         */
/*                 END Msg(4:3458)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognised code-fragment.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-2 and                           */
/*                 END Msg(4:3412)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* Macro for Register readback disable */
#define SPI_WV_DISABLE                 0U
/* Macro for Register readback INIT_ONLY */
#define SPI_WV_INIT_ONLY               1U
/* Macro for Register readback INIT_RUNTIME */
#define SPI_WV_INIT_RUNTIME            2U

/* Macro for Register mask */
#define CTLREG_8_BIT_MASK              (uint8)0xFFU
#define CTLREG_16_BIT_MASK             (uint16)0xFFFFU
#define CTLREG_32_BIT_MASK             (uint32)0xFFFFFFFFUL

/*******************************************************************************
** Macro Name            : SPI_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed.
**
** Input Parameters      : pWriteRegAddr, RegWriteValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-1 */
#define SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
{ \
  (*(pWriteRegAddr)) = (RegWriteValue);\
}
/* END Msg(4:3458)-1 */

/*******************************************************************************
** Macro Name            : SPI_CSIX_WRITE_RAM_MIRROR
**
** Description           : This macro is to perform RAM mirroring for CSIX
**                         control registers.
**
** Input Parameters      : pMirrorAddr, RegWriteValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : CSIX RAM Mirror ON
**
** Functions invoked     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-1 */
#if (SPI_CSIX_RAM_MIRROR == STD_ON)
#define SPI_CSIX_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue) \
{ \
  (*(pMirrorAddr)) = (RegWriteValue); \
}
#else
#define SPI_CSIX_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue) \
{ \
}
#endif
/* END Msg(4:3458)-1 */

/*******************************************************************************
** Macro Name            : SPI_DMA_WRITE_RAM_MIRROR
**
** Description           : This macro is to perform RAM mirrorring for DMA
**                         control registers.
**
** Input Parameters      : pMirrorAddr, RegWriteValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : DMA RAM Mirror ON
**
** Functions invoked     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-1 */
#if (SPI_DMA_RAM_MIRROR == STD_ON)
#define SPI_DMA_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue) \
{ \
  (*(pMirrorAddr)) = (RegWriteValue); \
}
#else
#define SPI_DMA_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue) \
{ \
}
#endif
/* END Msg(4:3458)-1 */

/*******************************************************************************
** Macro Name            : SPI_WV_REPORT_ERROR
**
** Description           : This macro is to report the error to respective
**                         interface.
**
** Input Parameters      : WVErrId, ErrStat, ApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : Dem_ReportErrorStatus, SPI_WV_ERROR_NOTIFICATION
*******************************************************************************/
#if (SPI_USE_WRITE_VERIFY_ERROR_INTERFACE == STD_ON)
  /* MISRA Violation: START Msg(4:3412)-2 */
  #define SPI_WV_REPORT_ERROR(WVErrId, ErrStat, ApiId) \
              SPI_WV_ERROR_NOTIFICATION (WVErrId, ApiId);
  /* END Msg(4:3412)-2 */
#else
  /* MISRA Violation: START Msg(4:3412)-2 */
  #define SPI_WV_REPORT_ERROR(WVErrId, ErrStat, ApiId) \
              Dem_ReportErrorStatus(WVErrId, ErrStat);
  /* END Msg(4:3412)-2 */
#endif

/*******************************************************************************
** Macro Name            : SPI_VERIFY_WRITE_REG
**
** Description           : This macro is to do the comparison check and do
**                         the error reporting if the comparison is failed.
**
** Input Parameters      : pWriteRegAddr, RegWriteValue, MaskValue,
**                         ApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
#if ((SPI_CSIX_WRITE_VERIFY != SPI_WV_DISABLE) ||\
  (SPI_DMA_WRITE_VERIFY != SPI_WV_DISABLE))
  /* MISRA Violation: START Msg(4:3412)-2 */
  #define SPI_VERIFY_WRITE_REG(pWriteRegAddr, RegWriteValue, MaskValue, \
                                                                    ApiId) \
  { \
    if ((RegWriteValue) != (((*(pWriteRegAddr)) & (MaskValue)))) \
    { \
      SPI_WV_REPORT_ERROR(SPI_E_REG_WRITE_VERIFY, DEM_EVENT_STATUS_FAILED, \
                                                                    ApiId) \
    } \
    else \
    { \
    } \
  }
  /* END Msg(4:3412)-2 */
#else
  /* MISRA Violation: START Msg(4:3412)-2 */
  #define SPI_VERIFY_WRITE_REG(pWriteRegAddr, RegWriteValue, MaskValue, \
                                                                    ApiId) \
  {\
  }
  /* END Msg(4:3412)-2 */
#endif

#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
