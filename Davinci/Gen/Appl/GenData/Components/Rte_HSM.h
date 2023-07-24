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
 *             File:  Rte_HSM.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <HSM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_HSM_H
# define RTE_HSM_H

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

# include "Rte_HSM_Type.h"
# include "Rte_DataHandleType.h"


# define HSM_START_SEC_CODE
# include "HSM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_HsmGetAes128Key HsmGetAes128Key
#  define RTE_RUNNABLE_HsmGetCmacKey HsmGetCmacKey
#  define RTE_RUNNABLE_HsmGetCmacKeyState HsmGetCmacKeyState
#  define RTE_RUNNABLE_HsmSetAes128Key HsmSetAes128Key
#  define RTE_RUNNABLE_HsmSetCmacKey HsmSetCmacKey
#  define RTE_RUNNABLE_HsmTrngGenerate HsmTrngGenerate
#  define RTE_RUNNABLE_Hsm_MainFunction Hsm_MainFunction
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, HSM_CODE) HsmGetAes128Key(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) IV, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) KEY, P2VAR(uint32, AUTOMATIC, RTE_VAR_NOINIT) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, HSM_CODE) HsmGetAes128Key(P2VAR(A_17Bytes, AUTOMATIC, RTE_VAR_NOINIT) IV, P2VAR(A_16Bytes, AUTOMATIC, RTE_VAR_NOINIT) KEY, P2VAR(uint32, AUTOMATIC, RTE_VAR_NOINIT) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, HSM_CODE) HsmGetCmacKey(P2VAR(uint8, AUTOMATIC, RTE_HSM_APPL_VAR) key, P2VAR(uint32, AUTOMATIC, RTE_HSM_APPL_VAR) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, HSM_CODE) HsmGetCmacKey(P2VAR(IdtHsmKeyArray, AUTOMATIC, RTE_HSM_APPL_VAR) key, P2VAR(uint32, AUTOMATIC, RTE_HSM_APPL_VAR) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, HSM_CODE) HsmGetCmacKeyState(P2VAR(HSM_KeyStateEnum, AUTOMATIC, RTE_HSM_APPL_VAR) state); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, HSM_CODE) HsmSetAes128Key(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) IV, P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) KEY, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, HSM_CODE) HsmSetAes128Key(P2CONST(A_16Bytes, AUTOMATIC, RTE_VAR_NOINIT) IV, P2CONST(A_16Bytes, AUTOMATIC, RTE_VAR_NOINIT) KEY, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, HSM_CODE) HsmSetCmacKey(P2CONST(uint8, AUTOMATIC, RTE_HSM_APPL_DATA) vin, uint32 vin_len, P2CONST(uint8, AUTOMATIC, RTE_HSM_APPL_DATA) key, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, HSM_CODE) HsmSetCmacKey(P2CONST(IdtHsmVinArray, AUTOMATIC, RTE_HSM_APPL_DATA) vin, uint32 vin_len, P2CONST(IdtHsmKeyArray, AUTOMATIC, RTE_HSM_APPL_DATA) key, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, HSM_CODE) HsmTrngGenerate(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Trng, P2VAR(uint32, AUTOMATIC, RTE_VAR_NOINIT) len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, HSM_CODE) HsmTrngGenerate(P2VAR(A_16Bytes, AUTOMATIC, RTE_VAR_NOINIT) Trng, P2VAR(uint32, AUTOMATIC, RTE_VAR_NOINIT) len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, HSM_CODE) Hsm_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define HSM_STOP_SEC_CODE
# include "HSM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_HSM_H */

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

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
