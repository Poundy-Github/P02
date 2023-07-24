/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_RegWrite.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2018 Renesas Electronics Corporation                     */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  02-Aug-2016 : Initial Version
 *
 * V2.0.0:  31-Oct-2016 : Added missing file specific version information
 *                        as part of ARDAABC-564
 *
 * V2.1.0   14-Nov-2016 : Ecode GPT_ENABLE and GPT_DISABLE macros were renamed
 *                        to GPT_MIRROR_ENABLE and GPT_MIRROR_DISABLE as part
 *                        of ARDAABC-769
 *
 * V2.2.0   21-Nov-2016 : Added masks for all Write Verify checks.Minor changes
 *                        in names of macros used for Write-Verify and HWCC as
 *                        part of ARDAABC-926
 *
 * V2.2.1   12-Dec-2016 : Fixed minor review findings as part of ARDAABC-692
 *
 * V2.2.2   26-Jun-2017 : Following changes are made:
 *                        1. MISRA Justification tag added.
 *                        2. Copyright information updated.
 *
 * V2.2.3   14-Jul-2017 : MISRA Justification tag corrected.
 *
 * V2.2.4   18-Aug-2017 : Following changes are made:
 *                        1. MISRA Justification tag(4:3412) added.
 *                        2. Non MISRA Justification(2:3457) removed.
 *
 * V2.2.5:  18-Sep-2017 : Following changes are made:
 *                        1. As per ARDAABD-2425, QAC level 2 warning
 *                           Justification tags are added.
 *                        2. As per ARDAABD-2570, typo errors corrected.
 *
 * V2.2.6:  18-Jun-2018 : Following changes are made:
 *                        1. As per ARDAABD-3841, traceability updated.
 *                        2. Copyright information updated.
 */
/******************************************************************************/

#ifndef GPT_REG_WRITE_H
#define GPT_REG_WRITE_H
/* GPT_REG_WRITE_H_001: EAAR_PN0034_FR_0001 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* GPT_REG_WRITE_H_002: GPT172 */
#include "Dem.h"
#include "Std_Types.h"
#include "Gpt_Cfg.h"

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* GPT_REG_WRITE_H_003: EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_REG_WRITE_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION
#define GPT_REG_WRITE_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION
#define GPT_REG_WRITE_AR_RELEASE_REVISION_VERSION \
          GPT_AR_RELEASE_REVISION_VERSION

/* File version information */
#define GPT_REG_WRITE_SW_MAJOR_VERSION    GPT_SW_MAJOR_VERSION
#define GPT_REG_WRITE_SW_MINOR_VERSION    GPT_SW_MINOR_VERSION
/*******************************************************************************
 **                      Global Data Types                                    **
 ******************************************************************************/

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/

/*******************************************************************************
**                              QAC Warning                                   **
*******************************************************************************/
/******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:3457) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule NA                                       */
/* Justification : Since the macros are implemented as function macros braces */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3457)-1 and                           */
/*                 END Msg(2:3457)-1 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognised code-fragment.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Needed terminator token for macro code line                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/* Justification : Necessary for the practical extension of functionality to  */
/*                  multiple registers                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-2 and                           */
/*                 END Msg(4:3453)-2 tags in the code.                        */

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Necessary for defining a new scope                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-3 and                           */
/*                 END Msg(4:3458)-3 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
 **                     Macro Definitions                                     **
 ******************************************************************************/

/* API IDs for the private APIs */
#define  GPT_HWINIT_API_ID                          (uint8)0x80
#define  GPT_HWDEINIT_API_ID                        (uint8)0x81
#define  GPT_GETTIMEELAPSED_API_ID                  (uint8)0x82
#define  GPT_GETTIMEREMAINING_API_ID                (uint8)0x83
#define  GPT_STARTTIMER_API_ID                      (uint8)0x84
#define  GPT_STOPTIMER_API_ID                       (uint8)0x85
#define  GPT_ENABLEINT_API_ID                       (uint8)0x86
#define  GPT_DISABLEINT_API_ID                      (uint8)0x87
#define  GPT_CBKNOTIFICATION_API_ID                 (uint8)0x88
#define  GPT_STARTPREDEFTIMER_API_ID                (uint8)0x89

/******************************************************************************/
/***************************Register Write and RAM Mirroring*******************/
/******************************************************************************/
/*******************************************************************************
 ** Macro Name            : GPT_WRITE_REG_ONLY
 **
 ** Description           : This macro is to perform the write operation of the
 **                         register which is passed as a parameter. This macro
 **                         shall be used for registers for which Ram Mirroring
 **                         is not possible (Write-Only or Static registers)
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
 ******************************************************************************/
 /* MISRA Violation: START Msg(4:3458)-3 */
#define GPT_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
}
/* END Msg(4:3458)-3 */
/*******************************************************************************
 ** Macro Name            : GPT_WRITE_OSTM_MIRROR_ONLY
 **
 ** Description           : This macro is to perform the write operation of the
 **                         OSTM mirror which is passed as a parameter.
 **
 ** Input Parameters      : pMirrorAddr, uiWriteValue
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
 ******************************************************************************/
#if (GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE)
  /* MISRA Violation: START Msg(4:3458)-3 */
#define GPT_WRITE_OSTM_MIRROR_ONLY(pMirrorAddr, uiWriteValue)  \
{ \
  (*(pMirrorAddr)) = (uiWriteValue); \
}
/* END Msg(4:3458)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_WRITE_OSTM_MIRROR_ONLY(pMirrorAddr, uiWriteValue)  \
{ \
}
#endif
/* END Msg(4:3412)-1 */

/*******************************************************************************
 ** Macro Name            : GPT_WRITE_TAUDB_MIRROR_ONLY
 **
 ** Description           : This macro is to perform the write operation of the
 **                         TAUDB mirror which is passed as a parameter.
 **
 ** Input Parameters      : pMirrorAddr, uiWriteValue
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
 ******************************************************************************/
#if (GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE)
/* MISRA Violation: START Msg(4:3458)-3 */
#define GPT_WRITE_TAUDB_MIRROR_ONLY(pMirrorAddr, uiWriteValue)  \
{ \
  (*(pMirrorAddr)) = (uiWriteValue); \
}
/* END Msg(4:3458)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_WRITE_TAUDB_MIRROR_ONLY(pMirrorAddr, uiWriteValue)  \
{ \
}
#endif
/* END Msg(4:3412)-1 */

/*******************************************************************************
 ** Macro Name            : GPT_WRITE_TAUJ_MIRROR_ONLY
 **
 ** Description           : This macro is to perform the write operation of the
 **                         TAUJ mirror which is passed as a parameter.
 **
 ** Input Parameters      : pMirrorAddr, uiWriteValue
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
 ******************************************************************************/
#if (GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE)
/* MISRA Violation: START Msg(4:3458)-3 */
#define GPT_WRITE_TAUJ_MIRROR_ONLY(pMirrorAddr, uiWriteValue)  \
{ \
  (*(pMirrorAddr)) = (uiWriteValue); \
}
/* END Msg(4:3458)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_WRITE_TAUJ_MIRROR_ONLY(pMirrorAddr, uiWriteValue)  \
{ \
}
#endif
/* END Msg(4:3412)-1 */

/*******************************************************************************
 ** Macro Name            : GPT_WRITE_REG_AND_MIRROR
 **
 ** Description           : This macro is to perform the write operation of the
 **                         register passed as parameter and respective RAM
 **                         mirror
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
 ******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-3 */
/* GPT_REG_WRITE_H_004: EAAR_PN0034_FSR_0005 */
#define GPT_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, \
                                          uiRegWriteValue) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
  (*(pMirrorAddr)) = (uiRegWriteValue); \
}
/* END Msg(4:3458)-3 */

/*******************************************************************************
 ** Macro Name            : GPT_OSTM_WRITE_REG_AND_MIRROR
 **
 ** Description           : This macro is used to perform the write and RAM
 **                         mirroring of GPT_OSTM registers.
 **                         This macro shall be used for registers
 **                         for witch Ram Mirroring is possible.
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
 ******************************************************************************/
/* QAC Warning: START Msg(2:3457)-1 */
/* GPT_REG_WRITE_H_005: EAAR_PN0034_FSR_0006 */
#if (GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE)
#define GPT_OSTM_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                      pMirrorAddr) \
{ \
  GPT_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, \
                                    uiRegWriteValue ) \
}
#else
#define GPT_OSTM_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                      pMirrorAddr) \
{ \
  GPT_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
}
#endif
/* END Msg(2:3457)-1 */
/*******************************************************************************
 ** Macro Name            : GPT_TAUDB_WRITE_REG_AND_MIRROR
 **
 ** Description           : This macro is used to perform the write and RAM
 **                         mirroring of  GPT_TAUDB registers. This macro shall
 **                         be used for registers for witch Ram Mirroring is
 **                         possible.
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
 ******************************************************************************/
/* QAC Warning: START Msg(2:3457)-1 */
/* GPT_REG_WRITE_H_006: EAAR_PN0034_FSR_0006 */
#if (GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE)
#define GPT_TAUDB_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                       pMirrorAddr) \
{ \
  GPT_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, \
                                    uiRegWriteValue ) \
}
#else
#define GPT_TAUDB_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue,\
                                       pMirrorAddr) \
{ \
  GPT_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
}
#endif
/* END Msg(2:3457)-1 */
/*******************************************************************************
 ** Macro Name            : GPT_TAUJ_WRITE_REG_AND_MIRROR
 **
 ** Description           : This macro is used to perform the write and RAM
 **                         mirroring of   GPT_TAUJ registers. This macro shall
 **                         be used for registers for witch Ram Mirroring is
 **                         possible.
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
 ******************************************************************************/
/* QAC Warning: START Msg(2:3457)-1 */
/* GPT_REG_WRITE_H_007: EAAR_PN0034_FSR_0006 */
#if (GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE)
  /* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_TAUJ_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                      pMirrorAddr) \
{ \
  GPT_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr,\
                           uiRegWriteValue ) \
}
/* END Msg(4:3453)-2 */
#else
#define GPT_TAUJ_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue,   \
                                      pMirrorAddr) \
{ \
  GPT_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
}
#endif
/* END Msg(2:3457)-1 */
/******************************************************************************/
/******************************WRITE-VERIFY MACROS*****************************/
/******************************************************************************/

/*******************************************************************************
 ** Macro Name            : GPT_WV_REPORT_ERROR
 **
 ** Description           : This macro is used to report a Write Verify error
 **                         through DEM or user defined callback
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
 **                         GPT_ERROR_NOTIFICATION
 ******************************************************************************/
/* GPT_REG_WRITE_H_008: EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004 */
/* GPT_REG_WRITE_H_009: GPT_ESDD_UD_142,GPT_ESDD_UD_143 */
#if ( GPT_USE_WV_ERROR_INTERFACE == STD_ON )
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
  GPT_ERROR_NOTIFICATION(WVErrId, uiApiId);
#else
#define GPT_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
    Dem_ReportErrorStatus(WVErrId, (GPT_DEM_TYPE)(ErrStat));
/* END Msg(4:3412)-1 */
#endif
/*******************************************************************************
 ** Macro Name            : GPT_CHECK_WRITE_VERIFY
 **
 ** Description           : This macro is used to perform the comparison check
 **                         and do the error reporting if the comparison fails.
 **
 ** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue,
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
 ******************************************************************************/
 /* GPT_REG_WRITE_H_010: GPT_ESDD_UD_074 */
/* MISRA Violation: START Msg(4:3412)-1 */
/* GPT_REG_WRITE_H_011: EAAR_PN0034_FSR_0003 */
#define GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                               uiMaskValue, uiApiId) \
{ \
  if ((uiCheckValue) != ((*(pCompareRegAddr)) & (uiMaskValue))) \
  { \
  GPT_WV_REPORT_ERROR(GPT_E_REG_WRITE_VERIFY, DEM_EVENT_STATUS_FAILED,\
                               uiApiId) \
  } \
  else \
  { \
  } \
}
/* END Msg(4:3412)-1 */
/* GPT_REG_WRITE_H_012: EAAR_PN0034_FSR_0001 */
/*******************************************************************************
 ** Macro Name            : GPT_OSTM_CHECK_WRITE_VERIFY_INIT
 **
 ** Description           : This macro is used for the WriteVerify check only
 **                         for GPT_Init and Gpt_Deinit APIs.
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
 ******************************************************************************/
/* MISRA Violation: START Msg(4:3453)-2 */
/* GPT_REG_WRITE_H_013: EAAR_PN0034_FSR_0002, GPT_ESDD_UD_122 */
#if (GPT_OSTM_WRITE_VERIFY != GPT_WV_DISABLE)

#define GPT_OSTM_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_OSTM_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
{\
}
#endif
/* END Msg(4:3412)-1 */
/* END Msg(4:3453)-2 */

/*******************************************************************************
 ** Macro Name            : GPT_TAUDB_CHECK_WRITE_VERIFY_INIT
 **
 ** Description           : This macro is used for the WriteVerify check only
 **                         for GPT_Init and Gpt_Deinit APIs.
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
 ******************************************************************************/
/* GPT_REG_WRITE_H_014: EAAR_PN0034_FSR_0002, GPT_ESDD_UD_136 */
#if (GPT_TAUDB_WRITE_VERIFY != GPT_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                          uiMaskValue, uiApiId)\
  GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue,  \
                                          uiMaskValue, uiApiId)\
{\
}
#endif
/* END Msg(4:3412)-1 */

/*******************************************************************************
 ** Macro Name            : GPT_TAUJ_CHECK_WRITE_VERIFY_INIT
 **
 ** Description           : This macro is used for the WriteVerify check only
 **                         for GPT_Init and Gpt_Deinit APIs.
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
 ******************************************************************************/
/* GPT_REG_WRITE_H_015: EAAR_PN0034_FSR_0002, GPT_ESDD_UD_137 */
#if (GPT_TAUJ_WRITE_VERIFY != GPT_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
{\
}
#endif
/* END Msg(4:3412)-1 */
/*******************************************************************************
 ** Macro Name            : GPT_WUF_CHECK_WRITE_VERIFY_INIT
 **
 ** Description           :This macro is used for the WriteVerify check only for
 **                        GPT_Init and Gpt_Deinit APIs.
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
 ******************************************************************************/
/* GPT_REG_WRITE_H_016: EAAR_PN0034_FSR_0002, GPT_ESDD_UD_138 */
#if (GPT_WUF_WRITE_VERIFY != GPT_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-2 */
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_WUF_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                        uiMaskValue, uiApiId) \
  GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
#define GPT_WUF_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                        uiMaskValue, uiApiId) \
{\
}
/* END Msg(4:3412)-1 */
#endif
/*******************************************************************************
 ** Macro Name            : GPT_OSTM_CHECK_WRITE_VERIFY_RUNTIME
 **
 ** Description           : This macro is used for the WriteVerify check only
 **                         for functions other than GPT_Init and Gpt_Deinit.
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
 ******************************************************************************/
/* GPT_REG_WRITE_H_017: EAAR_PN0034_FSR_0002 */
#if (GPT_OSTM_WRITE_VERIFY == GPT_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3412)-1 */
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_OSTM_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue,  \
                                            uiMaskValue, uiApiId)  \
  GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define GPT_OSTM_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                            uiMaskValue, uiApiId) \
{\
}
/* END Msg(4:3453)-2 */
/* END Msg(4:3412)-1 */
#endif

/*******************************************************************************
 ** Macro Name            : GPT_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
 **
 ** Description           : This macro is used for the WriteVerify check only
 **                         for functions other than GPT_Init and Gpt_Deinit.
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
 ******************************************************************************/
/* GPT_REG_WRITE_H_018: EAAR_PN0034_FSR_0002 */
#if (GPT_TAUDB_WRITE_VERIFY == GPT_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                             uiMaskValue, uiApiId) \
  GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                             uiMaskValue, uiApiId) \
{\
}
/* END Msg(4:3412)-1 */
#endif

/*******************************************************************************
 ** Macro Name            : GPT_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
 **
 ** Description           : This macro is used for the WriteVerify check only
 **                         for functions other than GPT_Init and Gpt_Deinit.
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
 ******************************************************************************/
/* GPT_REG_WRITE_H_019: EAAR_PN0034_FSR_0002 */
#if (GPT_TAUJ_WRITE_VERIFY == GPT_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                            uiMaskValue, uiApiId) \
  GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue,  \
                                            uiMaskValue, uiApiId) \
{\
}
/* END Msg(4:3412)-1 */
#endif

/*******************************************************************************
 ** Macro Name            : GPT_WUF_CHECK_WRITE_VERIFY_RUNTIME
 **
 ** Description           : This macro is used for the WriteVerify check only
 **                         for functions other than GPT_Init and Gpt_Deinit.
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
 ******************************************************************************/
/* GPT_REG_WRITE_H_020: EAAR_PN0034_FSR_0002 */
#if (GPT_WUF_WRITE_VERIFY == GPT_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_WUF_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                           uiMaskValue, uiApiId) \
  GPT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define GPT_WUF_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                            uiMaskValue, uiApiId) \
{\
}
/* END Msg(4:3412)-1 */
#endif

#endif /* GPT_REG_WRITE_H */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
