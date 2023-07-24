/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_RegWrite.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the macro definitions of write verify and hardware      */
/* consistency check functionality                                            */
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
/*              Devices:        F1x                                           */
/*============================================================================*/

/* Implements: EAAR_PN0034_NR_0045                                            */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*                                                                             *
* V1.0.0:  01-Nov-2016    : Initial Version                                    *
* V1.1.0:  18-Nov-2016    : As part of JIRA ARDAABD-569 - Extend the           *
*                              implementation of RAM mirror by adding          *
*                              MCU_WRITE_MIRROR_ONLY  to be used for           *
*                              write-protected registers to store just the Ram *
*                              mirror value                                    *
* V1.1.1:  28-Dec-2016    : The following changes were performed :             *
*                           1. As part of JIRA ARDAABD-831 - Fix QAC warnings  *
*                              related to macros required additional           *
*                              parenthesis                                     *
*                           2. As part of JIRA ARDAABD-831 - Add identifiers   *
*                              to MCU_WV_ERROR_NOTIFICATION arguments          *
* V1.2.0:  17-Jan-2017    : The following changes were performed :             *
*                           1. As part of JIRA ARDAABD-569 - Parameter         *
*                              uiMaskValue added in the                        *
*                              MCU_CHECK_WRITE_VERIFY_INIT,                    *
*                              MCU_CHECK_WRITE_VERIFY_RUNTIME, and             *
*                              MCU_CHECK_WRITE_VERIFY_RUNTIME macros           *
*                           2. As part of JIRA ARDAABD-569 -                   *
*                              MCU_USE_WV_ERROR_NOTIFICATION changed to        *
*                              MCU_USE_WV_ERROR_INTERFACE                      *
* V1.3.0:  08-Feb-2017    : The following changes were performed :             *
*                           1. As part of JIRA ARDAABD-569 - Added uiMaskValue *
*                              usage in INTERNAL_MCU_CHECK_WRITE_VERIFY        *
*                           2. As part of JIRA ARDAABD-569 - Added identifiers *
*                              MCU_MIRROR_DISABLE and MCU_MIRROR_ENABLE        *
* V1.4.0:  17-Feb-2017      As part of JIRA ARDAABD-831 - Corrected the        *
*                              parameter types for MCU_WV_ERROR_NOTIFICATION   *
* V1.5.0:  10-Mar-2017    : As part of JIRA ARDAABD-1210 - Traceability        *
*                           was added                                          *
* V1.6.0:  29-Aug-2017    : As part of JIRA ARDAABD-2150 -Added QAC/MISRA      *
*                           Warnings justification.Corrected QAC/MISRA Warning.*
* V1.7.0:  05-Oct-2017    : As part of JIRA ARDAABD-2588 - Added changes after *
*                           FuSa checklist                                     *
* V1.7.1:  20-Jun-2018    : 1.As part of #ARDAABD-3850, traceability           *
*                           inconsistencies are corrected and requirement      *
*                           mapping is done.                                   *
*                           2.Updated Copyright year.                          *
*                                                                             */
/******************************************************************************/

#ifndef MCU_REGWRITE_H
#define MCU_REGWRITE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"
/*******************************************************************************
**                      Symbols                                               **
*******************************************************************************/
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-2 and                           */
/*                 END Msg(4:3458)-2 tags in the code.                        */
/******************************************************************************/
/* API IDs for the private functions */
#define MCU_CKSCCONFIGURE_API_ID                 (uint8)0x80
#define MCU_RRAMCYCLICRUN_API_ID                 (uint8)0x81
#define MCU_MAINOSCDISABLE_API_ID                (uint8)0x82
#define MCU_MAINOSCENABLE_API_ID                 (uint8)0x83
#define MCU_RELOADCLKDISTPM_API_ID               (uint8)0x84
#define MCU_WAKEUPFACTORPRE_API_ID               (uint8)0x85
#define MCU_STARTPLL_API_ID                      (uint8)0x86
#define MCU_INTCWEND_ISR_API_ID                  (uint8)0x87

/* MCUREGWRITE_H_006: MCU_ESDD_UD_102, MCU_ESDD_UD_166                       */
/* MCUREGWRITE_H_001: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002             */
/* MCUREGWRITE_H_002: EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004             */
/* Macro for Register readback disable */
#define MCU_WV_DISABLE                     0U
/* Macro for Register readback INIT_ONLY */
#define MCU_WV_INIT_ONLY                   1U
/* Macro for Register readback INIT_RUNTIME */
#define MCU_WV_INIT_RUNTIME                2U
/* MCUREGWRITE_H_003: MCU_ESDD_UD_167                                        */
/* MCUREGWRITE_H_004: EAAR_PN0034_FSR_0003                                   */
/* Macro for RAM Mirror Disable */
#define MCU_MIRROR_DISABLE                 3U
/* Macro for RAM Mirror Enable */
#define MCU_MIRROR_ENABLE                  4U


/* MISRA Violation: START Msg(4:3412)-1 */
/* MISRA Violation: START Msg(4:3458)-2 */
#if (MCU_WRITE_VERIFY != MCU_WV_DISABLE) && \
  (MCU_USE_WV_ERROR_INTERFACE == STD_ON)
extern FUNC(void, MCU_APPL_CODE) MCU_WV_ERROR_NOTIFICATION
                                       (Dem_EventIdType WVErrId, uint8 uiApiId);
#endif

/******************************************************************************/
/***************************Register Write and RAM Mirroring*******************/
/******************************************************************************/
/*******************************************************************************
** Macro Name            : MCU_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed. This macro shall be used
**                         for registers for which Ram Mirroring is not possible
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
#define MCU_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
}

/*******************************************************************************
** Macro Name            : MCU_WRITE_MIRROR_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register mirror which is passed. This macro shall be
**                         used for write-protected registers to perform just
**                         RAM mirroring used for consistency check
**
** Input Parameters      : pMirrorAddr, uiRegWriteValue
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
#define MCU_WRITE_MIRROR_ONLY(pMirrorAddr, uiRegWriteValue)  \
{ \
  (*(pMirrorAddr)) = (uiRegWriteValue); \
}

/*******************************************************************************
** Macro Name            : INTERNAL_MCU_WRITE_REG_AND_MIRROR
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
/* MISRA Violation: START Msg(4:3458)-1 */
#define INTERNAL_MCU_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, \
                                          uiRegWriteValue) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
  (*(pMirrorAddr)) = (uiRegWriteValue); \
}
/*******************************************************************************
** Macro Name            : MCU_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         Mcu registers. This macro shall not be used for
**                         registers for which Ram Mirroring is impossible.
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

#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
#define MCU_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
     INTERNAL_MCU_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, \
                                      uiRegWriteValue );
#else
#define MCU_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
     MCU_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue);
#endif

/******************************************************************************/
/*******************************WRITE-VERIFY MACROS****************************/
/******************************************************************************/

/*******************************************************************************
** Macro Name            : MCU_WV_REPORT_ERROR
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
**                         MCU_WV_ERROR_NOTIFICATION
*******************************************************************************/
/* MCUREGWRITE_H_007: MCU_ESDD_UD_168, MCU_ESDD_UD_169                       */
#if ( MCU_USE_WV_ERROR_INTERFACE == STD_ON )
#define INTERNAL_MCU_WV_REPORT_ERROR(WVErrId, ErrStat, ApiId) \
                        MCU_WV_ERROR_NOTIFICATION(WVErrId, ApiId);
#else
#define INTERNAL_MCU_WV_REPORT_ERROR(WVErrId, ErrStat, ApiId) \
        Dem_ReportErrorStatus(WVErrId, (Dem_EventStatusType)(ErrStat));

#endif
/*******************************************************************************
** Macro Name            : INTERNAL_MCU_CHECK_WRITE_VERIFY
**
** Description           : This macro is to do the comparison check and do
**                         the error reporting if the comparison fails.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, ApiId,
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
/* MCUREGWRITE_H_005: MCU_ESDD_UD_170                                        */
#define INTERNAL_MCU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                              uiMaskValue, ApiId) \
  { \
    if ((uiCheckValue) != ((*(pCompareRegAddr)) & (uiMaskValue))) \
    { \
        INTERNAL_MCU_WV_REPORT_ERROR(MCU_E_REG_WRITE_VERIFY, \
        DEM_EVENT_STATUS_FAILED, ApiId) \
    } \
    else \
    { \
    } \
  }
/*******************************************************************************
** Macro Name            : MCU_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         Initialization API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, ApiId.
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
#if (MCU_WRITE_VERIFY != MCU_WV_DISABLE)

#define MCU_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                    uiMaskValue, ApiId) \
  INTERNAL_MCU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                                      uiMaskValue, ApiId)
#else
#define MCU_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                     uiMaskValue, ApiId) \
  {\
  }
#endif

/*******************************************************************************
** Macro Name            : MCU_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than MCU_Init.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
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
#if (MCU_WRITE_VERIFY == MCU_WV_INIT_RUNTIME)

#define MCU_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                            uiMaskValue, ApiId)  \
  INTERNAL_MCU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                          uiMaskValue, ApiId)
#else
#define MCU_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                           uiMaskValue, ApiId ) \
  {\
  }

#endif
/* END Msg(4:3412)-1 */
/* END Msg(4:3458)-2 */
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_REGWRITE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
