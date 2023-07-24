/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = Wdg_59_DriverB_RegWrite.h                                   */
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
 * V1.0.0:  26-Oct-2016    : Initial Version
 * V1.0.1:  14-Dec-2016    : Write-Verify option macros changed
 * V1.0.2:  16-Jan-2017    : Write-Verify option macros were added
 * V1.0.3:  27-Jan-2017    : RAM Mirroring options were added
 * V1.0.4:  13-Feb-2017    : #ARDAABD-911
 *                           1. Use common approach for macros used for writing
 *                              registers with write-verify and/or
 *                              HW consistency check options
 *                           #ARDAABD-832
 *                           1. Solved QAC 4:3410, enclosed (uiRegWriteValue)
 * V1.0.5:  24-Feb-2017    : #ARDAABD-568
 *                           1. Replaced following macro definitions:
 *                           WDG_59_DRIVERB_USE_WRITE_VERIFY_ERROR_NOTIFICATION
 *                           with WDG_59_DRIVERB_USE_WRITE_ERROR_INTERFACE and
 *                           WDG_59_DRIVERB_WRITE_VERIFY_ERROR_INTERFACE with
 *                           WDG_59_DRIVERB_ERROR_NOTIFICATION.
 * V1.0.6   09-Jul-2018    : 1. As part of ARDAABD-1897 Jira ticket, code was
 *                           updated after QAC analysis
 *                           2. As part #ARDAABD-3905, traceability
 *                           has been updated by mapping respective
 *                           WDG_ESDD_UD IDs.
 *                           3. As part of JIRA ARDAABD-3881, following changes
 *                              are made:
 *                           a. Copyright information updated.
 */
/******************************************************************************/

#ifndef WDG_59_DRIVERB_REGWRITE_H
#define WDG_59_DRIVERB_REGWRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Std_Types.h"
#include "Wdg_59_DriverB_Cbk.h"

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Since API is implemented as macro, braces cannot be        */
/*                 avoided.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-1 and                           */
/*                 END Msg(4:3458)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-2 and                           */
/*                 END Msg(4:3412)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:3453) A function could probably be used instead of   */
/*                 this function-like macro.                                  */
/* Rule          : MISRA-C:2004 19.7                                          */
/* Justification : This function macro is used here to speed up the process   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-3 and                           */
/*                 END Msg(4:3453)-3 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* Api ID of Wdg_59_DriverB_TriggerFunc. */
#define WDG_59_DRIVERB_TRIGGERFUNC_API_ID           (uint8)0x07

/* Write verify options */
#define WDG_59_DRIVERB_WV_DISABLE                     0U
#define WDG_59_DRIVERB_WV_INIT_ONLY                   1U
#define WDG_59_DRIVERB_WV_INIT_RUNTIME                2U

/* Ram Mirroring options */
#define WDG_59_DRIVERB_MIRROR_DISABLE                 3U
#define WDG_59_DRIVERB_MIRROR_ENABLE                  4U
/******************************************************************************/
/***************************Register Write and RAM Mirroring*******************/
/******************************************************************************/
/*******************************************************************************
** Macro Name            : Wdg_59_DriverB_WRITE_REG_ONLY
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
/* MISRA Violation: START Msg(4:3458)-1 */
#define WDG_59_DRIVERB_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
{ \
    (*(pWriteRegAddr)) = (uiRegWriteValue); \
}

/*******************************************************************************
** Macro Name            : INTERNAL_WDG_59_DRIVERB_WRITE_REG_AND_MIRROR
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

#define INTERNAL_WDG_59_DRIVERB_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                      pMirrorAddr, uiRegWriteValue) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
    (*(pMirrorAddr)) = (uiRegWriteValue); \
}
/* END Msg(4:3458)-1 */
/*******************************************************************************
** Macro Name            : Wdg_59_DriverB_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         Wdg_59_DriverB registers. This macro shall not be
**                         used for registers for witch Ram Mirroring
**                         is impossible.
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

#if (WDG_59_DRIVERB_RAM_MIRROR == WDG_59_DRIVERB_MIRROR_ENABLE)
#define WDG_59_DRIVERB_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue,\
                                                              pMirrorAddr) \
INTERNAL_WDG_59_DRIVERB_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr,\
                                                       uiRegWriteValue)
#else
#define WDG_59_DRIVERB_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue,\
                                                              pMirrorAddr) \
     WDG_59_DRIVERB_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)
#endif

/******************************************************************************/
/******************************WRITE-VERIFY MACROS*****************************/
/******************************************************************************/

/*******************************************************************************
** Macro Name            : WDG_59_DRIVERB_WRITE_VERIFY_REPORT_ERROR
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
**                         WDG_59_DRIVERB_ERROR_NOTIFICATION
*******************************************************************************/
/* MISRA Violation: START Msg(4:3412)-2 */
/* WDG_59_DRIVERB_REGWRITE_H_003 : WDG_ESDD_UD_071, WDG_ESDD_UD_035           */
#if ( WDG_59_DRIVERB_USE_WRITE_ERROR_INTERFACE == STD_ON )
#define INTERNAL_WDG_59_DRIVERB_WRITE_VERIFY_REPORT_ERROR(WVErrId, ErrStat,\
                                                                    ApiId) \
WDG_59_DRIVERB_ERROR_NOTIFICATION(WVErrId, ApiId);
#else
#define INTERNAL_WDG_59_DRIVERB_WRITE_VERIFY_REPORT_ERROR(WVErrId, ErrStat,\
                                                                   ApiId) \
           Dem_ReportErrorStatus(WVErrId, (Dem_EventStatusType)(ErrStat));

#endif
/*******************************************************************************
** Macro Name            : INTERNAL_WDG_59_DRIVERB_CHECK_WRITE_VERIFY
**
** Description           : This macro is to do the comparison check and do
**                         the error reporting if the comparison fails.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue,
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
#define INTERNAL_WDG_59_DRIVERB_CHECK_WRITE_VERIFY(pCompareRegAddr,\
                                        uiCheckValue, uiMaskValue, ApiId) \
  { \
    if ((uiCheckValue) != ((*(pCompareRegAddr)) & (uiMaskValue))) \
    { \
     INTERNAL_WDG_59_DRIVERB_WRITE_VERIFY_REPORT_ERROR( \
       WDG_59_DRIVERB_E_REG_WRITE_VERIFY, DEM_EVENT_STATUS_FAILED, ApiId) \
    } \
    else \
    { \
    } \
  }
/* END Msg(4:3412)-2 */
/*******************************************************************************
** Macro Name            : WDG_59_DRIVERB_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is used to do the write verify for WDTAnMD
**                         register.
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
/* WDG_59_DRIVERB_REGWRITE_H_001 : WDG_ESDD_UD_070, WDG_ESDD_UD_018 */
#if (WDG_59_DRIVERB_WRITE_VERIFY != WDG_59_DRIVERB_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-3 */
#define WDG_59_DRIVERB_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue,\
                                                        uiMaskValue, ApiId)\
INTERNAL_WDG_59_DRIVERB_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, ApiId)
/* END Msg(4:3453)-3 */
#else
#define WDG_59_DRIVERB_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue,\
                                                        uiMaskValue, ApiId)\
    {\
    }
#endif
/*******************************************************************************
** Macro Name            : WDG_59_DRIVERB_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is used to do the write verify for
**                         WDTAnMD, WDTAnWDTE, WDTAnEVAC registers.
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
/* WDG_59_DRIVERB_REGWRITE_H_002: WDG_ESDD_UD_070, WDG_ESDD_UD_018 */
#if (WDG_59_DRIVERB_WRITE_VERIFY == WDG_59_DRIVERB_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-3 */
#define WDG_59_DRIVERB_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr,\
                             uiCheckValue, uiMaskValue, ApiId)  \
INTERNAL_WDG_59_DRIVERB_CHECK_WRITE_VERIFY(pCompareRegAddr,\
                                        uiCheckValue, uiMaskValue, ApiId)
/* END Msg(4:3453)-3 */
#else
#define WDG_59_DRIVERB_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr,\
                                        uiCheckValue, uiMaskValue, ApiId) \
    {\
    }
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* WDG_59_DRIVERB_REGWRITE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
