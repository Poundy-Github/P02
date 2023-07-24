/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_RegWrite.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 - 2018 Renesas Electronics Corporation                   */
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
 * V1.0.1:  24-Nov-2016  : #ARDAABD-570
 *                         1. Initial Version
 * V1.0.2:  06-Dec-2016  : #ARDAABD-583
 *                         1. Minor corrections
 *                         2. Removed ASR 3.2.2 support
 *                         3. Removed ICU_HW_STARTCOUNTMEASUREMENT_API_ID
 *                            and ICU_HW_STOPCOUNTMEASUREMENT_API_ID
 * V1.0.3:  02-Feb-2017  : #ARDAABD-830
 *                         1. Solved QAC 4:3410, eclosed (uiRegWriteValue)
 * V1.0.4:  21-Jun-2018  : Following changes are made:
 *                         1. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 *                         2. Copyright information is updated.
 */
/******************************************************************************/

#ifndef ICU_REG_WRITE_H
#define ICU_REG_WRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Std_Types.h"
#include "Icu_Cfg.h"
#include "Icu_Cbk.h"

/* ICU_H_066: ICU116, SWS_Icu_00116 */
/* Dem.h inclusion to get Dem_ReportErrorStatus declaration */
#if ( ICU_USE_WRITE_VERIFY_ERROR_INTERFACE == STD_OFF )
#include "Dem.h"
#endif


/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
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
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* API IDs for the private APIs */
#define ICU_TIMERISR_LL_ID                          (uint8)0x82

#define ICU_EXTERNALINTERRUPTISR_LL_ID              (uint8)0x83

/* Macro for Register readback disable */
#define ICU_WV_DISABLE                     0U
/* Macro for Register readback INIT_ONLY */
#define ICU_WV_INIT_ONLY                   1U
/* Macro for Register readback INIT_RUNTIME */
#define ICU_WV_INIT_RUNTIME                2U
/* Macro for RAM Mirror Disable */
#define ICU_MIRROR_DISABLE                 3U
/* Macro for RAM Mirror Enable */
#define ICU_MIRROR_ENABLE                  4U

/*******************************************************************************
** Macro Name            : ICU_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed and respective RAM mirroring
**
** Input Parameters      : pWriteRegAddr, pMirrorAddr, uiRegWriteValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : RAM Mirror should be ON
**
** Functions invoked     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-1 */
/* ICU_H_048: ICU_ESDD_UD_224 */
/* ICU_H_049: EAAR_PN0034_FSR_0005, EAAR_PN0034_FSR_0006 */
#define ICU_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
    (*(pMirrorAddr)) = (uiRegWriteValue); \
}
/*******************************************************************************
** Macro Name            : ICU_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed.
**
** Input Parameters      : pWriteRegAddr,uiRegWriteValue
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
/* ICU_H_050: ICU_ESDD_UD_224 */
#define ICU_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
}
/* END Msg(4:3458)-1 */
/*******************************************************************************
** Macro Name            : ICU_WRITEVERIFY_REPORT_ERROR
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
** Functions invoked     : Dem_ReportErrorStatus, ICU_ERROR_INTERFACE
*******************************************************************************/
/* ICU_H_051: ICU_ESDD_UD_227 */
/* MISRA Violation: START Msg(4:3412)-2 */
#if ( ICU_USE_WRITE_VERIFY_ERROR_INTERFACE == STD_ON )
#define ICU_WRITEVERIFY_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                            ICU_WRITE_VERIFY_ERROR_INTERFACE(WVErrId, uiApiId);
#else
#define ICU_WRITEVERIFY_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                            Dem_ReportErrorStatus(WVErrId, \
                                   (Dem_EventStatusType) (ErrStat));
#endif
/*******************************************************************************
** Macro Name            : ICU_CHECK_WRITE_VERIFY
**
** Description           : This macro is to do the comparison check and do
**                         the error reporting if the comparison fails.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
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
/* ICU_H_052: ICU_ESDD_UD_224, EAAR_PN0034_FSR_0001 */
/* ICU_H_065: ICU_ESDD_UD_237, ICU003 */
/* ICU_H_053: EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0003 */
/* ICU_H_054: EAAR_PN0034_FSR_0004 */
#define ICU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
    if ((uiCheckValue) != ((*(pCompareRegAddr)) & (uiWCMaskValue))) \
    { \
        ICU_WRITEVERIFY_REPORT_ERROR(ICU_E_REG_WRITE_VERIFY, \
                            DEM_EVENT_STATUS_FAILED, uiApiId) \
    } \
    else \
    { \
    } \
  }
/* END Msg(4:3412)-2 */
/*******************************************************************************
** Macro Name            : ICU_TAUDB_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         the TAUDB unit registers.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue, pMirrorAddr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_TAUD_UNIT_USED, ICU_TAUB_UNIT_USED should be
**                         enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_055: ICU_ESDD_UD_224 */
#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
#if (ICU_TAUDB_RAM_MIRROR != ICU_MIRROR_DISABLE)
#define ICU_TAUDB_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                        pMirrorAddr) \
  { \
     ICU_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  }
#else
#define ICU_TAUDB_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                        pMirrorAddr) \
  { \
     ICU_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
#endif

/*******************************************************************************
** Macro Name            : ICU_TAUJ_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                          the TAUJ unit registers.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue, pMirrorAddr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_TAUJ_UNIT_USED should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_056: ICU_ESDD_UD_224, ICU_ESDD_UD_226 */
#if (ICU_TAUJ_UNIT_USED == STD_ON)
#if (ICU_TAUJ_RAM_MIRROR != ICU_MIRROR_DISABLE)
#define ICU_TAUJ_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                      pMirrorAddr) \
  { \
     ICU_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  }
#else
#define ICU_TAUJ_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                        pMirrorAddr) \
  { \
     ICU_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
#endif

/*******************************************************************************
** Macro Name            : ICU_FCLA_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         the FCLA registers.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue, pMirrorAddr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_EDGE_DETECT_API should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_057: ICU_ESDD_UD_032, ICU_ESDD_UD_224, ICU_ESDD_UD_226 */
#if ( (ICU_EDGE_DETECT_API == STD_ON) && \
      (ICU_FCLA_RAM_MIRROR == ICU_MIRROR_ENABLE) )
#define ICU_FCLA_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                      pMirrorAddr) \
  { \
     ICU_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  }
#else
#define ICU_FCLA_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                        pMirrorAddr) \
  { \
     ICU_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif  /* End of #if ( (ICU_EDGE_DETECT_API == STD_ON) && \
         *              (ICU_FCLA_RAM_MIRROR != ICU_MIRROR_DISABLE) )
         */

/*******************************************************************************
** Macro Name            : ICU_FCLA_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the FCLA
**                         unit registers in Icu_Init API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_EDGE_DETECT_API should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_058: ICU_ESDD_UD_032, ICU_ESDD_UD_225 */
#if (ICU_EDGE_DETECT_API == STD_ON)
#if (ICU_FCLA_WRITE_VERIFY != ICU_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-3 */
#define ICU_FCLA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
    ICU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-2 */
#define ICU_FCLA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-2 */
#endif
#endif  /* End of #if (ICU_EDGE_DETECT_API == STD_ON) */

/*******************************************************************************
** Macro Name            : ICU_TAUDB_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the TAUDB
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_TAUD_UNIT_USED, ICU_TAUB_UNIT_USED should be
**                         enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_059: ICU_ESDD_UD_225, ICU_ESDD_UD_224 */
#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
#if (ICU_TAUDB_WRITE_VERIFY != ICU_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-3 */
#define ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
    ICU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-2 */
#define ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-2 */
#endif
#endif
/*******************************************************************************
** Macro Name            : ICU_TAUJ_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the TAUJ
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_TAUJ_UNIT_USED should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_060: ICU_ESDD_UD_225, ICU_ESDD_UD_224 */
#if (ICU_TAUJ_UNIT_USED == STD_ON)
#if (ICU_TAUJ_WRITE_VERIFY != ICU_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-3 */
#define ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
    ICU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-2 */
#define ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-2 */
#endif
#endif

/*******************************************************************************
** Macro Name            : ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the TAUDB
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_TAUDB_UNIT_USED should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_061: ICU_ESDD_UD_225, ICU_ESDD_UD_224 */
#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
#if (ICU_TAUDB_WRITE_VERIFY == ICU_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-3 */
#define ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
    ICU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-2 */
#define ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-2 */
#endif
#endif

/*******************************************************************************
** Macro Name            : ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the TAUJ
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_TAUJ_UNIT_USED should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_062: ICU_ESDD_UD_225, ICU_ESDD_UD_224 */
#if (ICU_TAUJ_UNIT_USED == STD_ON)
#if (ICU_TAUJ_WRITE_VERIFY == ICU_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-3 */
#define ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
    ICU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-2 */
#define ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-2 */
#endif
#endif

/*******************************************************************************
** Macro Name            : ICU_FCLA_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the FCLA
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_EDGE_DETECT_API should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_063: ICU_ESDD_UD_225, ICU_ESDD_UD_224 */
#if ( (ICU_EDGE_DETECT_API == STD_ON) && \
      (ICU_FCLA_WRITE_VERIFY == ICU_WV_INIT_RUNTIME) )
/* MISRA Violation: START Msg(4:3453)-3 */
#define ICU_FCLA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
    ICU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-2 */
#define ICU_FCLA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-2 */
#endif /* End of #if ( (ICU_EDGE_DETECT_API == STD_ON) && \
        *              (ICU_FCLA_WRITE_VERIFY == ICU_WV_INIT_RUNTIME) )
        */

/*******************************************************************************
** Macro Name            : ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the FCLA
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ICU_WAKEUP_FACTOR_CLEAR_ISR and
**                         ICU_REPORT_WAKEUP_SOURCE should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/* ICU_H_064: ICU_ESDD_UD_225, ICU_ESDD_UD_224, ICU_ESDD_UD_156 */
#if ( (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON) && \
      (ICU_WUF_WRITE_VERIFY == ICU_WV_INIT_RUNTIME) )
/* MISRA Violation: START Msg(4:3453)-3 */
#define ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
    ICU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-2 */
#define ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-2 */
#endif /* End of #if ( (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON) && \
        *              (ICU_WUF_WRITE_VERIFY == ICU_WV_INIT_RUNTIME) )
        */

#endif /* ICU_REG_WRITE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
