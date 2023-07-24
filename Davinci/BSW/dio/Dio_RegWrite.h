/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_RegWrite.h                                              */
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
 * V1.0.0:  26-Jul-2016  : Initial Version
 * V2.0.0:  27-Oct-2016  : As part of ARDAABC-626 Jira Ticket, the following
 *                         changes are made:
 *                         1) Removed AR 3.2.2 related functionality and
 *                                  added AR 4.2.2 where applicable.
 * V2.0.1   09-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Updated copyright dates
 * V2.0.2   09-Jan-2017  : As part of ARDAABC-547 Jira ticket the following
 *                         changes made:
 *                         1) Updated traceability tags.
 * V2.0.3   17-Jan-2017  : As part of ARDAABC-707 Jira ticket the following
 *                         changes made:
 *                         1) DIO_CHECK_WRITE_VERIFY_INIT removed due to it has
 *                            not been used anywhere in the code.
 * V2.0.4   24-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Header comment updated due to acceptance team
 *                            comment
 * V2.0.5   12-Feb-2017  : Following changes are made:
 *                         1) As part of ARDAABC-753, macro names were corrected
 * V2.0.6   13-Feb-2017  : Following changes are made:
 *                         1) As part of ARDAABC-630, code was updated after QAC
 *                            analysis
 * V2.0.7   19-Feb-2017  : As part of ARDAABC-926 Jira ticket, code was
 *                         updated due to traceability
 * V2.0.8   21-Jul-2017  : As part of ARDAABD-1892 Jira ticket, qac tags added
 *                         for Msg(4:3453)
 * V2.0.9   20-June-2018 : Following changes are made:
 *                         1) As part of ARDAABD-3851 to improve traceability,
 *                            a.Removed all the redundant and obsolete
 *                              requirements.
 *                            b.Added missing requirements from requirement
 *                              documents.
 *                         2) Updated copyright year.
 */
/******************************************************************************/
/* DIO_REG_WRITE_H_006: EAAR_PN0034_FR_0001 */
#ifndef DIO_REGWRITE_H
#define DIO_REGWRITE_H

/*******************************************************************************
 **                     Include Section                                       **
 ******************************************************************************/
#include "Dio_Cfg.h"

/* DIO_REG_WRITE_H_001: DIO172, DIO067 */
/* DIO_REG_WRITE_H_008: DIO131, SWS_Dio_00131 */
/* Dem.h inclusion to get Dem_ReportErrorStatus declaration */
#if(DIO_WRITE_VERIFY != DIO_WV_DISABLE)
#include "Dem.h"
#endif

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
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
/* Message       : Msg(4:3453) A function could probably be used instead of   */
/*                 this function-like macro.                                  */
/* Rule          : MISRA-C:2004 19.7                                          */
/* Justification : This function macro is used here to speed up the process   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-2 and                           */
/*                 END Msg(4:3453)-2 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/
/*******************************************************************************
 **                     Macro Definitions                                     **
 ******************************************************************************/
/* API IDs for the private APIs */
#define DIO_WRITEPORT_API_ID                          (uint8)0x80

#define DIO_WRITECHANNEL_API_ID                       (uint8)0x81

#define DIO_FLIPCHANNEL_API_ID                        (uint8)0x82

#define DIO_WRITECHANNELGROUP_API_ID                  (uint8)0x83

/*******************************************************************************
 ** Macro Name            : DIO_WRITE_REG_ONLY
 **
 ** Description           : This macro is to perform the write operation to the
 **                         register which is passed. This macro shall be used
 **                         in the below case.
 **                         1. To write the value to the register directly for
 **                         which the RAM mirroring is neither possible nor
 **                         required.
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
/* MISRA Violation: START Msg(4:3458)-1 */
#define DIO_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
}
/* END Msg(4:3458)-1 */

/*
 *******************************************************************************
 WRITE-VERIFY MACROS
 *******************************************************************************
 */

/*******************************************************************************
 ** Macro Name            : DIO_WV_REPORT_ERROR
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
 **                         DIO_ERROR_NOTIFICATION
 ******************************************************************************/
/* DIO_REG_WRITE_H_004: EAAR_PN0034_FSR_0003 */
/* DIO_REG_WRITE_H_007: EAAR_PN0034_FSR_0004 */
/* DIO_REG_WRITE_H_002: DIO_ESDD_UD_005 */
#if ( DIO_USE_WRITE_ERROR_INTERFACE == STD_ON )
/* MISRA Violation: START Msg(4:3453)-2 */
#define DIO_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
              DIO_ERROR_NOTIFICATION(WVErrId, uiApiId)
/* END Msg(4:3453)-2 */
#else
/* MISRA Violation: START Msg(4:3453)-2 */
#define DIO_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
              Dem_ReportErrorStatus(WVErrId, (Dem_EventStatusType) (ErrStat))
/* END Msg(4:3453)-2 */
#endif
/*******************************************************************************
 ** Macro Name            : DIO_CHECK_WRITE_VERIFY
 **
 ** Description           : This macro is to do the comparison check and do
 **                         the error reporting if the comparison fails.
 **
 ** Input Parameters      : pCompareRegAddr, uiCheckValue, uiApiId,
 **                         uiuiApiId
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
/* MISRA Violation: START Msg(4:3458)-1 */
#define DIO_CHECK_WRITE_VERIFY(pCompareRegAddr,    \
                               uiCheckValue,       \
                               uiMaskValue,        \
                               uiApiId)            \
{ \
  if((uiCheckValue) != ((*(pCompareRegAddr)) & (uiMaskValue))) \
  { \
    DIO_WV_REPORT_ERROR(DIO_E_REG_WRITE_VERIFY, \
                              DEM_EVENT_STATUS_FAILED, uiApiId); \
  } \
  else \
  { \
  } \
}
/* END Msg(4:3458)-1 */
/*******************************************************************************
 ** Macro Name            : DIO_CHECK_WRITE_VERIFY_RUNTIME
 **
 ** Description           : This macro is to do the write verify call only for
 **                         the API's other than DIO_Init.
 **                         Note: the ApiID should be the AUTOSAR service ID. If
 **                         due to a design limitation (e.g. a MCAL local
 **                         function that is called from multiple AUTOSAR
 **                         services and interrupts) it is difficult to provide
 **                         the service ID, then it is acceptable to define an
 **                         ID for the MCAL local function. This local function
 **                         ID shall be unique and shall not overlap with a
 **                         defined AUTOSAR service ID.
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
/* DIO_REG_WRITE_H_005: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* DIO_REG_WRITE_H_003: DIO_ESDD_UD_004 */
#if (DIO_WRITE_VERIFY == DIO_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-2 */
#define DIO_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                        uiMaskValue, uiApiId)  \
DIO_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
#define DIO_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                        uiMaskValue, uiApiId) \
{\
}
#endif
#endif /* DIO_REGWRITE_H */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
