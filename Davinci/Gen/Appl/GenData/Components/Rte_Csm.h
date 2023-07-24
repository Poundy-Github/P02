/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Csm.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Csm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CSM_H
# define RTE_CSM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Csm_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Csm_CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Csm_CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification Rte_Call_Csm_CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification
#  define Rte_Call_CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification Rte_Call_Csm_CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification


# endif /* !defined(RTE_CORE) */


# define Csm_START_SEC_CODE
# include "Csm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CancelJob Csm_CancelJob
#  define RTE_RUNNABLE_CertificateParse Csm_CertificateParse
#  define RTE_RUNNABLE_CertificateVerify Csm_CertificateVerify
#  define RTE_RUNNABLE_Csm_MainFunction Csm_MainFunction
#  define RTE_RUNNABLE_Decrypt Csm_Decrypt
#  define RTE_RUNNABLE_Encrypt Csm_Encrypt
#  define RTE_RUNNABLE_KeyCopy Csm_KeyCopy
#  define RTE_RUNNABLE_KeyDerive Csm_KeyDerive
#  define RTE_RUNNABLE_KeyElementCopy Csm_KeyElementCopy
#  define RTE_RUNNABLE_KeyElementCopyPartial Csm_KeyElementCopyPartial
#  define RTE_RUNNABLE_KeyElementGet Csm_KeyElementGet
#  define RTE_RUNNABLE_KeyElementSet Csm_KeyElementSet
#  define RTE_RUNNABLE_KeyExchangeCalcPubVal Csm_KeyExchangeCalcPubVal
#  define RTE_RUNNABLE_KeyExchangeCalcSecret Csm_KeyExchangeCalcSecret
#  define RTE_RUNNABLE_KeyGenerate Csm_KeyGenerate
#  define RTE_RUNNABLE_KeySetValid Csm_KeySetValid
#  define RTE_RUNNABLE_RandomSeed Csm_RandomSeed
# endif

FUNC(Std_ReturnType, Csm_CODE) Csm_CancelJob(uint32 parg0, Crypto_OperationModeType parg1); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Csm_CODE) Csm_CertificateParse(uint32 parg0); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Csm_CODE) Csm_CertificateVerify(uint32 parg0, uint32 verifyKeyId, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_CSM_APPL_VAR) verifyPtr); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Csm_CODE) Csm_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Csm_CODE) Csm_Decrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Csm_CODE) Csm_Decrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Csm_CODE) Csm_Encrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Csm_CODE) Csm_Encrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyCopy(uint32 parg0, uint32 targetKeyId); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyDerive(uint32 parg0, uint32 targetKeyId); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyElementCopy(uint32 parg0, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyElementCopyPartial(uint32 parg0, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetKeyId, uint32 targetKeyElementId); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyElementGet(uint32 parg0, uint32 keyElementId, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) keyPtr, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) keyLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyElementGet(uint32 parg0, uint32 keyElementId, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) keyPtr, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) keyLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyElementSet(uint32 parg0, uint32 keyElementId, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) keyPtr, uint32 keyLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyElementSet(uint32 parg0, uint32 keyElementId, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) keyPtr, uint32 keyLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyExchangeCalcPubVal(uint32 parg0, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) publicValuePtr, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) publicValueLengthPtr); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyExchangeCalcPubVal(uint32 parg0, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) publicValuePtr, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) publicValueLengthPtr); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyExchangeCalcSecret(uint32 parg0, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) partnerPublicValuePtr, uint32 partnerPublicValueLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyExchangeCalcSecret(uint32 parg0, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) partnerPublicValuePtr, uint32 partnerPublicValueLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Csm_CODE) Csm_KeyGenerate(uint32 parg0); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Csm_CODE) Csm_KeySetValid(uint32 parg0); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Csm_CODE) Csm_RandomSeed(uint32 parg0, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) seedPtr, uint32 seedLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Csm_CODE) Csm_RandomSeed(uint32 parg0, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) seedPtr, uint32 seedLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define Csm_STOP_SEC_CODE
# include "Csm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_BUSY (2U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_JOB_CANCELED (12U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_E_NOT_OK (1U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_BUSY (2U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_JOB_CANCELED (12U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_CsmKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_CsmKey_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_CsmKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_CsmKey_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_CsmKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_CsmKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_CsmKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_CsmKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_CsmKey_RandomSeed_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_CsmKey_RandomSeed_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_CsmKey_RandomSeed_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_CsmKey_RandomSeed_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_CsmKey_RandomSeed_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_CsmKey_RandomSeed_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_CsmKey_RandomSeed_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_CsmKey_RandomSeed_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CSM_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
