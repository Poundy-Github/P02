/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst_RegWrite.h                                           */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the macro definitions of Pwrite verify and hardware     */
/* consistency check functionallity                                           */
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
 * V1.0.0:  17-Aug-2016    : Initial Version
 * V1.0.1:  02-Nov-2016    : Add MISRA violation comments
 * V1.0.2:  14-Mar-2017    : Macros moved from FlsTst_Cfg to FlsTst_RegWrite.h
 *                           Replaced FLSTST_MIRROR_ENABLE with FLSTST_ENABLE
 *                           Added traceability comments as part of JIRA
 *                           ARDAABD-1211.
 * V1.0.3:  28-Aug-2017    : Justification added for QAC warning which cannot
 *                           be removed.
 * V1.0.4:  21-Jun-2018    : 1. As part of #ARDAABD-3842, Removed duplicate
 *                              Requirement id's and mapped the required
 *                              Requirements for traceability
 *                           2. Updated copy-rights information
 */
/******************************************************************************/
/* FLSTST_REGWRITE_H_002: EAAR_PN0034_NR_0026                                 */
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/* Justification : REE aproach                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-1 and                           */
/*                 END Msg(4:3453)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment.      */
/* Rule          : MISRA-C:2004 Rule 10.7                                     */
/* Justification : Pointer to function is used                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-2 and                           */
/*                 END Msg(4:3412)-2 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                             QAC Warnings                                   **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:3459) Macro defines a 'do-while-zero' construct.        */
/* Justification : Implementation with the purpose to remove the              */
/*                 MISRA Violation (4:3458).                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3459)-1 and                           */
/*                 END Msg(2:3459)-1 tags in the code.                        */
/******************************************************************************/
/* FLSTST_REGWRITE_H_003:  EAAR_PN0034_FR_0001                                */
/* FLSTST_REGWRITE_H_006:  AR_PN0078_FR_0036, AR_PN0078_NR_0102               */
#ifndef FLSTST_REGWRITE_H
#define FLSTST_REGWRITE_H

#include "Std_Types.h"
#include "FlsTst_Cfg.h"

/* FLSTST_REGWRITE_H_001: FLSTST_ESDD_UD_055                                  */
/* Write verify options */
#define FLSTST_WV_DISABLE                    0U
#define FLSTST_WV_INIT_ONLY                  1U
#define FLSTST_WV_INIT_RUNTIME               2U
#define FLSTST_DISABLE                       3U
#define FLSTST_ENABLE                        4U

/******************************************************************************/
/***************************Register Write and RAM Mirroring*******************/
/******************************************************************************/
/*******************************************************************************
** Macro Name            : FLSTST_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed. This macro shall be used
**                         for registers for witch Ram Mirroring is not possible
**                         (Write-Only or Static registers)
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue
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
/* QAC Warning: START Msg(2:3459)-1 */
#define FLSTST_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
do \
{ \
  (pWriteRegAddr) = (uiRegWriteValue); \
} \
while(0)
/* END Msg(2:3459)-1 */
/*******************************************************************************
** Macro Name            : INTERNAL_FLSTST_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to perform the write operation to the
**                         register and respective RAM mirroring
**
** Input Parameters      : pWriteRegAddr, pMirrorAddr, uiRegWriteValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : RAM Mirror ON
**
** Functions invoked     : None
*******************************************************************************/
/* QAC Warning: START Msg(2:3459)-1 */
#define INTERNAL_FLSTST_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, \
                                             uiRegWriteValue) \
do \
{ \
  (pWriteRegAddr) = (uiRegWriteValue); \
    (pMirrorAddr) = (uiRegWriteValue); \
} \
while(0)
/* END Msg(2:3459)-1 */
/*******************************************************************************
** Macro Name            : FLSTST_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         FlsTst registers. This macro shall not be used for
**                         registers for witch Ram Mirroring is impossible.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue, pMirrorAddr
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

#if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)
/* MISRA Violation: START Msg(4:3453)-1 */
#define FLSTST_WRITE_REG_AND_MIRROR(pWriteRegAddr,uiRegWriteValue,pMirrorAddr) \
     INTERNAL_FLSTST_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, \
                                          uiRegWriteValue )
#else
#define FLSTST_WRITE_REG_AND_MIRROR(pWriteRegAddr,uiRegWriteValue,pMirrorAddr) \
     FLSTST_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)
/* END Msg(4:3453)-1 */
#endif

/******************************************************************************/
/******************************WRITE-VERIFY MACROS*****************************/
/******************************************************************************/

/* FLSTST_REGWRITE_H_005: FLSTST_ESDD_UD_056, FLSTST_ESDD_UD_057              */
/*******************************************************************************
** Macro Name            : FLSTST_WV_REPORT_ERROR
**
** Description           : This macro is to report the error to respective
**                         interface.
**
** Input Parameters      : WVErrId, ErrStat, uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : Dem_ReportErrorStatus
**                         FLSTST_ERROR_NOTIFICATION
*******************************************************************************/
#if ( FLSTST_USE_WV_ERROR_INTERFACE == STD_ON )
/* MISRA Violation: START Msg(4:3412)-2 */
#define FLSTST_WV_REPORT_ERROR(WVErrId, ErrStat, ApiId) \
                        FLSTST_ERROR_NOTIFICATION(WVErrId, ApiId);
#else
#define FLSTST_WV_REPORT_ERROR(WVErrId, ErrStat, ApiId) \
                 Dem_ReportErrorStatus(WVErrId, (Dem_EventStatusType)(ErrStat));
/* END Msg(4:3412)-2 */
#endif
/*******************************************************************************
** Macro Name            : INTERNAL_FLSTST_CHECK_WRITE_VERIFY
**
** Description           : This macro is to do the comparison check and do
**                         the error reporting if the comparison fails.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, ApiId, uiMaskValue
**                         uiApiId
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
/* FLSTST_REGWRITE_H_004: FLSTST_ESDD_UD_063                                  */
/* QAC Warning: START Msg(2:3459)-1 */
#define INTERNAL_FLSTST_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                           uiMaskValue, ApiId) \
do \
  { \
    if((uiCheckValue) != ((pCompareRegAddr) & (uiMaskValue))) \
    { \
        FLSTST_WV_REPORT_ERROR(FLSTST_E_REG_WRITE_VERIFY, \
                               DEM_EVENT_STATUS_FAILED, ApiId) \
    } \
    else \
    { \
    } \
  } \
while(0)
/* END Msg(2:3459)-1 */
/*******************************************************************************
** Macro Name            : FLSTST_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         FLSTST_Init API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, ApiId.
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
#if (FLSTST_WRITE_VERIFY != FLSTST_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-1 */
#define FLSTST_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                       uiMaskValue, ApiId) \
  INTERNAL_FLSTST_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                     uiMaskValue, ApiId)
#else
#define FLSTST_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                       uiMaskValue, ApiId) \
  {\
  }
/* END Msg(4:3453)-1 */
#endif

/*******************************************************************************
** Macro Name            : FLSTST_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than FLSTST_Init.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, ApiId.
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
#if (FLSTST_WRITE_VERIFY == FLSTST_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-1 */
#define FLSTST_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                          uiMaskValue, ApiId)  \
  INTERNAL_FLSTST_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                     uiMaskValue, ApiId)
#else
#define FLSTST_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                          uiMaskValue, ApiId ) \
  {\
  }
/* END Msg(4:3453)-1 */
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* FLSTST_REGWRITE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
