/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_RegWrite.h                                              */
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
/* Implements EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V2.0.0:  04-Aug-2016    : Initial Version
 * V2.1.0:  12-Sep-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                           Missing ADC_DMAISR_API_ID was introduced.
 *                           2. As a part of JIRA ticket ARDAABC-745,
 *                           Unused ADC_DMAISR_API_ID was removed.
 *                           3. As part of JIRA ticket ARDAABC-810,
 *                           add traces in code for WV, HWCC and Endless Loop
 *                           FUSA requirements.
 * V2.1.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE, replaced
 *                              WV error notification function pointer
 *                              with a macro, updated WV check to have only one
 *                              DEM event.
 * V2.1.2:  21-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              updated the WV and HWCC macros based on new
 *                              FUSA design proposal.
 * V2.2.0:  25-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated includes
 * V2.3.0:  09-Feb-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-586,
 *                              Updated macros to avoid MISRA violations:
 *                              ADC_REG_ULLMTBR_ARRAY_SIZE,
 *                              ADC_REG_VCR_ARRAY_SIZE,
 *                              ADC_REG_PVCR_ARRAY_SIZE.
 * V2.3.1:  23-Mar-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-586,
 *                              added MISRA rule violations comments.
 * V2.3.2:  22-Jun-2017    : The following changes are made :
 *                           1. MISRA message tags are added.
 *                           2. Missing banner added
 * V2.4.0:  07-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1725 , updated the value
 *                              of ADC_REG_ULLMTBR_ARRAY_SIZE macro for
 *                              Enhanced limit check functionality.
 * V2.4.1:  27-Jun-2018    : Following change made:
 *                            As part of traceability improvement activity
 *                            ticket ARDAABD-2101, requirements and UD Ids are
 *                            added.
 */
/******************************************************************************/
/* ADC_REGWRITE_H_022: EAAR_PN0034_FR_0001 */
#ifndef ADC_REG_WRITE_H
#define ADC_REG_WRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* ADC_REGWRITE_H_001: EAAR_PN0034_FSR_0004 */
/* ADC_REGWRITE_H_024: ADC267, SWS_Adc_00267, ADC235 */
/* Dem.h inclusion to get Dem_ReportErrorStatus declaration */
#if( ADC_USE_WV_ERROR_INTERFACE == STD_OFF )
#include "Dem.h"
#endif

#include "Std_Types.h"
#include "Adc_Types.h"
#include "Adc_Cfg.h"
#include "Adc_Cbk.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* Implements EAAR_PN0034_NR_0026 */

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
/* Message       : Msg(4:3457) Macro defines a braced initializer.            */
/* Rule          : MISRA-C:2004 19.4                                          */
/* Justification : Since API is implemented as macro, braces cannot be        */
/*                 avoided.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3457)-2 and                           */
/*                 END Msg(4:3457)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Needed terminator token for macro code line                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-3 and                           */
/*                 END Msg(4:3412)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:3453) A function could probably be used instead of   */
/*                 this function-like macro.                                  */
/* Rule          : MISRA-C:2004 19.7                                          */
/* Justification : This function macro is used here to speed up the process   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-4 and                           */
/*                 END Msg(4:3453)-4 tags in the code.                        */
/******************************************************************************/
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* API IDs for the private APIs */
#define   ADC_HWINIT_API_ID                           (uint8)0x80
#define   ADC_HWDEINIT_API_ID                         (uint8)0x81
#define   ADC_HWSTARTGROUPCONVERSION_API_ID           (uint8)0x82
#define   ADC_HWSTOPGROUPCONVERSION_API_ID            (uint8)0x83
#define   ADC_ISR_API_ID                              (uint8)0x84
#define   ADC_CHANNELCOMPLETEMODE_API_ID              (uint8)0x85
#define   ADC_GROUPCOMPLETEMODE_API_ID                (uint8)0x86
#define   ADC_CONFIGUREGROUPFORCONVERSION_API_ID      (uint8)0x87
#define   ADC_ENABLEHWGROUP_API_ID                    (uint8)0x88
#define   ADC_DISABLEHWGROUP_API_ID                   (uint8)0x89
#define   ADC_INTENABLEHWTRIGGER_API_ID               (uint8)0x8A
#define   ADC_INTDISABLEHWTRIGGER_API_ID              (uint8)0x8B
#define   ADC_INTHWRESULTREADGROUP_API_ID             (uint8)0x8C
#define   ADC_POLLINGREADGROUP_API_ID                 (uint8)0x8D
#define   ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID   (uint8)0x8E
#define   ADC_ERRISR_API_ID                           (uint8)0x8F
#define   ADC_HALTSCANGROUP_API_ID                    (uint8)0x90
#define   ADC_HWCUSSETSAMPLINGCLOCK_API_ID            (uint8)0x91

/*
 Define the sizse of mirror register based on number of limit check
 register available.
*/
#if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
#define ADC_REG_ULLMTBR_ARRAY_SIZE  8U
#else
#define ADC_REG_ULLMTBR_ARRAY_SIZE  3U
#endif

#define ADC_REG_VCR_ARRAY_SIZE      (sizeof(((AdcVirChReg*)0)->ulVCR) / \
                                    sizeof(((AdcVirChReg*)0)->ulVCR[0]))

#define ADC_REG_PVCR_ARRAY_SIZE     (sizeof(((PWSAReg*)0)->ulPVCR) / \
                                    sizeof(((PWSAReg*)0)->ulPVCR[0]))

/*
********************************************************************************
                           Register Write and RAM Mirroring
********************************************************************************
*/

/* ADC_REGWRITE_H_023: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/*******************************************************************************
** Macro Name            : ADC_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed. This macro shall be used
**                         in the below case.
**                         1. By ADC_<INSTANCE_NAME>_WRITE_REG_AND_MIRROR macro
**                         for writing the registers when the RAM mirroring is
**                         is disabled for the respective instance.
**                         2. To write the value to the register directly for
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
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-1 */
#define ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
  { \
    (*(pWriteRegAddr)) = (uiRegWriteValue); \
  }
/* END Msg(4:3458)-1 */
/*******************************************************************************
** Macro Name            : ADC_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to perform the write operation to the
**                         register and respective RAM mirroring.
**                         This macro shall be used by the
**                         ADC_<INSTANCE_NAME>_WRITE_REG_AND_MIRROR macro
**                         for writing the registers when the RAM mirroring is
**                         is enabled for the respective instance.
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
#define ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue) \
  { \
    (*(pWriteRegAddr)) = (uiRegWriteValue); \
    (*(pMirrorAddr)) = (uiRegWriteValue); \
  }
/* END Msg(4:3458)-1 */
/*******************************************************************************
** Macro Name            : ADC_ADCA_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         ADCA registers. This macro shall be used for writing
**                         the registers which need Ram Mirroring.
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
/* ADC_REGWRITE_H_002: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0005 */
/* ADC_REGWRITE_H_003: EAAR_PN0034_FSR_0006 */
/* MISRA Violation: START Msg(4:3457)-2 */
#if (ADC_ADCA_RAM_MIRROR != ADC_MIRROR_DISABLE)
#define ADC_ADCA_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                 uiRegWriteValue, \
                                                 pMirrorAddr) \
  { \
    ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue ) \
  }
#else
#define ADC_ADCA_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                 uiRegWriteValue, \
                                                 pMirrorAddr) \
  { \
    ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
/* END Msg(4:3457)-2 */
/*******************************************************************************
** Macro Name            : ADC_PWMDIAG_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         PWMDIAG registers. This macro shall be used for
**                         writing the registers which need Ram Mirroring.
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
/* ADC_REGWRITE_H_004: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0005 */
/* ADC_REGWRITE_H_005: EAAR_PN0034_FSR_0006 */
/* MISRA Violation: START Msg(4:3457)-2 */
#if (ADC_PWMDIAG_RAM_MIRROR != ADC_MIRROR_DISABLE)
#define ADC_PWMDIAG_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                 uiRegWriteValue, \
                                                 pMirrorAddr) \
  { \
    ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue ) \
  }
#else
#define ADC_PWMDIAG_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                 uiRegWriteValue, \
                                                 pMirrorAddr) \
  { \
    ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
/* END Msg(4:3457)-2 */
/*******************************************************************************
** Macro Name            : ADC_DMAC_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         DMAC registers. This macro shall be used for writing
**                         the registers which need Ram Mirroring.
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
/* ADC_REGWRITE_H_006: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0005 */
/* ADC_REGWRITE_H_007: EAAR_PN0034_FSR_0006 */
/* MISRA Violation: START Msg(4:3457)-2 */
#if (ADC_DMAC_RAM_MIRROR != ADC_MIRROR_DISABLE)
#define ADC_DMAC_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                 uiRegWriteValue, \
                                                 pMirrorAddr) \
  { \
    ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue ) \
  }
#else
#define ADC_DMAC_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                 uiRegWriteValue, \
                                                 pMirrorAddr) \
  { \
    ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
/* END Msg(4:3457)-2 */
/*
********************************************************************************
                               WRITE-VERIFY MACROS
********************************************************************************
*/

/*******************************************************************************
** Macro Name            : ADC_WV_REPORT_ERROR
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
**                         ADC_WRITE_VERIFY_ERROR_INTERFACE
*******************************************************************************/
/* ADC_REGWRITE_H_008: EAAR_PN0034_FSR_0003 */
/* ADC_REGWRITE_H_018: ADC_ESDD_UD_047 */
/* ADC_REGWRITE_H_019: ADC_ESDD_UD_048 */
/* MISRA Violation: START Msg(4:3412)-3 */
#if ( ADC_USE_WV_ERROR_INTERFACE == STD_ON )
#define ADC_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
  ADC_WRITE_VERIFY_ERROR_INTERFACE(WVErrId, uiApiId);
#else
#define ADC_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
  Dem_ReportErrorStatus(WVErrId, (Dem_EventStatusType)(ErrStat));
#endif
/* END Msg(4:3412)-3 */
/*******************************************************************************
** Macro Name            : ADC_CHECK_WRITE_VERIFY
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
*******************************************************************************/
/* ADC_REGWRITE_H_020: ADC_ESDD_UD_123 */
/* MISRA Violation: START Msg(4:3412)-3 */
#define ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, \
                               uiApiId) \
  { \
    if((uiCheckValue) != ((*(pCompareRegAddr)) & (uiMaskValue))) \
    { \
        ADC_WV_REPORT_ERROR(ADC_E_REG_WRITE_VERIFY, DEM_EVENT_STATUS_FAILED, \
                            uiApiId) \
    } \
    else \
    { \
    } \
  }
/* END Msg(4:3412)-3 */
/*******************************************************************************
** Macro Name            : ADC_ADCA_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
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
*******************************************************************************/
/* ADC_REGWRITE_H_009: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* ADC_REGWRITE_H_021: ADC_ESDD_UD_046 */
/* MISRA Violation: START Msg(4:3453)-4 */
/* MISRA Violation: START Msg(4:3412)-3 */
#if (ADC_ADCA_WRITE_VERIFY != ADC_WV_DISABLE)
#define ADC_ADCA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define ADC_ADCA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3412)-3 */
/* END Msg(4:3453)-4 */
/*******************************************************************************
** Macro Name            : ADC_PWMDIAG_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
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
*******************************************************************************/
/* ADC_REGWRITE_H_010: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* ADC_REGWRITE_H_017: ADC_ESDD_UD_046 */
/* MISRA Violation: START Msg(4:3453)-4 */
/* MISRA Violation: START Msg(4:3412)-3 */
#if (ADC_PWMDIAG_WRITE_VERIFY != ADC_WV_DISABLE)
#define ADC_PWMDIAG_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define ADC_PWMDIAG_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg((4:3412)-3 */
/* END Msg(4:3453)-4 */
/*******************************************************************************
** Macro Name            : ADC_DMAC_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
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
*******************************************************************************/
/* ADC_REGWRITE_H_011: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* MISRA Violation: START Msg(4:3453)-4 */
/* MISRA Violation: START Msg(4:3412)-3 */

#if (ADC_DMAC_WRITE_VERIFY != ADC_WV_DISABLE)
#define ADC_DMAC_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define ADC_DMAC_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3412)-3 */
/* END Msg(4:3453)-4 */
/*******************************************************************************
** Macro Name            : ADC_WUF_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
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
*******************************************************************************/
/* ADC_REGWRITE_H_012: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* MISRA Violation: START Msg(4:3453)-4 */
/* MISRA Violation: START Msg(4:3412)-3 */
#if (ADC_WUF_WRITE_VERIFY != ADC_WV_DISABLE)
#define ADC_WUF_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define ADC_WUF_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                         uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3412)-3 */
/* END Msg(4:3453)-4 */
/*******************************************************************************
** Macro Name            : ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
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
*******************************************************************************/
/* ADC_REGWRITE_H_013: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* MISRA Violation: START Msg(4:3453)-4 */
/* MISRA Violation: START Msg(4:3412)-3 */
#if (ADC_ADCA_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)
#define ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                            uiMaskValue, uiApiId)  \
  ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                            uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3412)-3 */
/* END Msg(4:3453)-4 */
/*******************************************************************************
** Macro Name            : ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
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
*******************************************************************************/
/* ADC_REGWRITE_H_014: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* MISRA Violation: START Msg(4:3453)-4 */
/* MISRA Violation: START Msg(4:3412)-3 */
#if (ADC_PWMDIAG_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)
#define ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                               uiMaskValue, uiApiId)  \
  ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                               uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3412)-3 */
/* END Msg(4:3453)-4 */
/*******************************************************************************
** Macro Name            : ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
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
*******************************************************************************/
/* ADC_REGWRITE_H_015: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* MISRA Violation: START Msg(4:3453)-4 */
/* MISRA Violation: START Msg(4:3412)-3 */
#if (ADC_DMAC_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)
#define ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                            uiMaskValue, uiApiId)  \
  ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                            uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3453)-4 */
/* END Msg(4:3412)-3 */
/*******************************************************************************
** Macro Name            : ADC_WUF_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
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
*******************************************************************************/
/* ADC_REGWRITE_H_016: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* MISRA Violation: START Msg(4:3453)-4 */
/* MISRA Violation: START Msg(4:3412)-3 */
#if (ADC_WUF_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)
#define ADC_WUF_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                           uiMaskValue, uiApiId)  \
  ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define ADC_WUF_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                           uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3412)-3 */
/* END Msg(4:3453)-4 */
#endif /* ADC_REG_WRITE_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
