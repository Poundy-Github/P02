/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_RegWrite.h                                             */
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

/* PORT_REGWRITE_H_015: EAAR_PN0034_NR_0045 */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V2.0.0:  26-Jul-2016  : Initial Version
 * V2.0.1:  20-Oct-2016  : After review on ARDAABC-757 Jira Ticket,
 *                         the following were made:
 *                         1. Renamed PORT_WV_ERROR_INTERFACE_API to
 *                            PORT_WV_ERROR_INTERFACE.
 * V2.0.2:  16-Nov-2016  : As part of ARDAABC-758, API IDs were added for
 *                         private functions.
 * V2.0.3:  16-Nov-2016  : As part of ARDAABC-757, the following changes are
 *                         made:
 *                         1. API IDs were added for private functions.
 *                         2. API IDs for public functions are removed.
 *                         3. Verify macros are updated to use masks.
 * V2.0.4:  24-Nov-2016  : As part of ARDAABC-757 Jira Ticket, the following
 *                         changes are made:
 *                         1. Write-Verify error interface name was updated.
 *                         2. Comments and parameter names were updated.
 * V2.0.5:  25-Nov-2016  : As part of ARDAABC-629 Jira ticket the following
 *                         changes are made:
 *                         1. Add braces around operands to avoid Misra
 *                            warnings.
 * V2.0.6:  07-Feb-2017  : As part of ARDAABC-763 Jira ticket the following
 *                         changes are made:
 *                         1. Renamed PORT_E_REG_WRITE_VERIFY_FAILURE to
 *                            PORT_E_REG_WRITE_VERIFY.
 * V2.0.7:  02-Mar-2017  : As per ticket ARDAABC-926 the following
 *                            changes are made:
 *                         1. Delete INTERNAL macros
 *                         2. Add QAC comments
 * V2.0.8:  29-Jun-2017  : Following change is made:
 *                         1. QAC justification given for Msg(4:3412)-3
 *                         message.
 * V2.0.9:  21-Jun-2018  : 1. As part of ARDAABD-3549, MISRA C Rule Violations
 *                         is updated to add Msg(4:0857)-4 message.
 *                         2. As part of ARDAABD-3844, Requirements and
 *                         Design ID's are mapped to the implementation in
 *                         order to improve coverage.
 */
/******************************************************************************/
/* PORT_REGWRITE_H_014: EAAR_PN0034_FR_0001 */
#ifndef PORT_REG_WRITE_H
#define PORT_REG_WRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

#include "Std_Types.h"
#include "Port_Cfg.h"
/* PORT_REGWRITE_H_010: PORT_ESDD_UD_145 */
/* Dem.h inclusion to get Dem_ReportErrorStatus declaration */
#if( PORT_USE_WV_ERROR_INTERFACE == STD_OFF )
#include "Dem.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* PORT_REGWRITE_H_012: EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026*/
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

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:3412) Macro defines an unrecognized code-fragment    */
/* Rule          : MISRA-C:2004 19.4                                          */
/* Justification : This function macro is used here to speed up the process   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-3 and                           */
/*                 END Msg(4:3412)-3 tags in the code.                        */

/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-4 and                           */
/*                 END Msg(4:0857)-4 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* API IDs for the private APIs */
#define PORT_INIT_CONFIG_API_ID                   (uint8)0x80

#define PORT_FILTER_CONFIG_API_ID                 (uint8)0x81

#define PORT_REFRESH_PORT_INTERNAL_API_ID         (uint8)0x82

#define PORT_SET_DIO_ALT_MODE_API_ID              (uint8)0x83

/* PORT_REGWRITE_H_011: PORT133, SWS_Port_00133 */
/*PORT_REGWRITE_H_013: EAAR_PN0034_NR_0025*/
/*******************************************************************************
** Macro Name            : PORT_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed.
**
** Input Parameters      : pWriteRegAddr, pMirrorAddr,
**                         uiRegWriteValue
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
/* PORT_REGWRITE_H_008: PORT_ESDD_UD_141*/
/* MISRA Violation: START Msg(4:3458)-1 */
#define PORT_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
}
/* END Msg(4:3458)-1 */
/*******************************************************************************
** Macro Name            : PORT_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         PORT registers.
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
/* PORT_REGWRITE_H_001: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0005 */
/* PORT_REGWRITE_H_002: EAAR_PN0034_FSR_0006 */
/* PORT_REGWRITE_H_007: PORT_ESDD_UD_142 */
#if (PORT_RAM_MIRROR != PORT_RAM_MIRROR_DISABLE)
/* MISRA Violation: START Msg(4:3458)-1 */
#define PORT_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  { \
    (*(pWriteRegAddr)) = (uiRegWriteValue); \
      (*(pMirrorAddr)) = (uiRegWriteValue); \
  }
/* END Msg(4:3458)-1 */
#else
#define PORT_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  { \
     PORT_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif

/*******************************************************************************
** Macro Name            : PORT_WV_REPORT_ERROR
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
** Functions invoked     : Dem_ReportErrorStatus, PORT_ERROR_NOTIFICATION
*******************************************************************************/
/* PORT_REGWRITE_H_003: EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004 */
/* PORT_REGWRITE_H_009: PORT_ESDD_UD_145 */
#if ( PORT_USE_WV_ERROR_INTERFACE == STD_ON )
/* MISRA Violation: START Msg(4:3412)-3 */
#define PORT_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                    PORT_ERROR_NOTIFICATION(WVErrId, uiApiId);
/* END Msg(4:3412)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-3 */
#define PORT_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                    Dem_ReportErrorStatus(WVErrId, (PORT_DEM_TYPE) (ErrStat));
/* END Msg(4:3412)-3 */
#endif
/*******************************************************************************
** Macro Name            : PORT_CHECK_WRITE_VERIFY
**
** Description           : This macro is to do the comparison check and do
**                         the error reporting if the comparison fails.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue
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
/* PORT_REGWRITE_H_004: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* MISRA Violation: START Msg(4:3412)-3 */
#define PORT_CHECK_WRITE_VERIFY(pCompareRegAddr, \
                                       uiCheckValue, uiMaskValue, uiApiId) \
  { \
    if((uiCheckValue) != ((*(pCompareRegAddr)) & (uiMaskValue))) \
    { \
        PORT_WV_REPORT_ERROR(PORT_E_REG_WRITE_VERIFY, \
                                  DEM_EVENT_STATUS_FAILED, uiApiId) \
    } \
    else \
    { \
    } \
  }
/* END Msg(4:3412)-3 */
/*******************************************************************************
** Macro Name            : PORT_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         Port_Init API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiApiId. uiMaskValue
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
/* PORT_REGWRITE_H_005: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
#if (PORT_WRITE_VERIFY != PORT_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-2 */
#define PORT_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                   uiMaskValue, uiApiId) \
        PORT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                   uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
#define PORT_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                   uiMaskValue, uiApiId) \
  {\
  }
#endif

/*******************************************************************************
** Macro Name            : PORT_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than Port_Init.
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
/* PORT_REGWRITE_H_006: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
#if (PORT_WRITE_VERIFY == PORT_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-2 */
#define PORT_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, \
                                        uiCheckValue, uiMaskValue, uiApiId)  \
        PORT_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                   uiMaskValue, uiApiId)
/* END Msg(4:3453)-2 */
#else
#define PORT_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                        uiMaskValue, uiApiId) \
{\
}
#endif
#endif /* PORT_REG_WRITE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
