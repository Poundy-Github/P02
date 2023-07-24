/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: SecOC
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecOC_Types.h
 *   Generation Time: 2022-03-02 17:10:52
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (SECOC_TYPES_H)
# define SECOC_TYPES_H
/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"
# include "Csm.h"
# include "Rte_Type.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define SECOC_FRESHNESSVALUE_SIZE 14u

#define SECOC_E_BUSY   0x02u

#define SECOC_OVERRIDE_VERIFICATION_STATUS_FAIL 0x00u
#define SECOC_OVERRIDE_VERIFICATION_STATUS_FAIL_N_MESSAGES 0x01u
#define SECOC_OVERRIDE_VERIFICATION_STATUS_CANCEL 0x02u
#define SECOC_OVERRIDE_VERIFICATION_STATUS_PASS 0x28u
#define SECOC_OVERRIDE_VERIFICATION_STATUS_PASS_N_MESSAGES 0x29u
#define SECOC_OVERRIDE_VERIFICATION_STATUS_PASS_UNTIL_NOTICE 0x40
#define SECOC_OVERRIDE_VERIFICATION_STATUS_PASS_UNTIL_LIMIT 0x42
#define SECOC_OVERRIDE_VERIFICATION_STATUS_SKIP_UNTIL_LIMIT 0x41
#define SECOC_OVERRIDE_VERIFICATION_STATUS_SKIP_UNTIL_NOTICE 0x43

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef uint64 SecOC_FreshnessValueType;

typedef union SecOC_FreshnessValueCopy SecOC_FreshnessValueCopyType;

typedef union SecOC_FreshnessValueCopy* SecOC_FreshnessValueCopyPtrType;

typedef P2FUNC(void, SECOC_APPL_CODE, SecOCVerificationStatusCalloutType) (SecOC_VerificationStatusType verificationStatus);

typedef P2FUNC(void, SECOC_APPL_CODE, SecOCVerificationStatusCalloutWithSecuredPduType) (SecOC_VerificationStatusType verificationStatus, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) receivedSecuredPDU, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) fullfreshnessValue, uint32 fullfreshnessValueLength);

#endif  /* SECOC_TYPES_H */
/**********************************************************************************************************************
  END OF FILE: SecOC_Types.h
**********************************************************************************************************************/
