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
 *             File:  Rte_Tacho.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Tacho>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_TACHO_H
# define RTE_TACHO_H

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

# include "Rte_Tacho_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EngSpdVldty_EngSpdVldty (0U)
#  define Rte_InitValue_EngSpd_ForIP_EngSpd_ForIP (0U)
#  define Rte_InitValue_TgtEngSpdIP_TgtEngSpdIP (0U)
#  define Rte_InitValue_TgtEngSpdIPValid_TgtEngSpdIPValid (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Tacho_EngSpdVldty_EngSpdVldty(P2VAR(EngSpdVldty, AUTOMATIC, RTE_TACHO_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Tacho_EngSpd_ForIP_EngSpd_ForIP(P2VAR(EngSpd_ForIP, AUTOMATIC, RTE_TACHO_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Tacho_TgtEngSpdIP_TgtEngSpdIP(P2VAR(TgtEngSpdIP, AUTOMATIC, RTE_TACHO_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Tacho_TgtEngSpdIPValid_TgtEngSpdIPValid(P2VAR(TgtEngSpdIPValid, AUTOMATIC, RTE_TACHO_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_EngSpdVldty_EngSpdVldty Rte_Read_Tacho_EngSpdVldty_EngSpdVldty
#  define Rte_Read_EngSpd_ForIP_EngSpd_ForIP Rte_Read_Tacho_EngSpd_ForIP_EngSpd_ForIP
#  define Rte_Read_TgtEngSpdIP_TgtEngSpdIP Rte_Read_Tacho_TgtEngSpdIP_TgtEngSpdIP
#  define Rte_Read_TgtEngSpdIPValid_TgtEngSpdIPValid Rte_Read_Tacho_TgtEngSpdIPValid_TgtEngSpdIPValid


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_EngSpdVldty_EngSpdVldty Rte_IsUpdated_Tacho_EngSpdVldty_EngSpdVldty
#  define Rte_IsUpdated_Tacho_EngSpdVldty_EngSpdVldty() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Tacho_EngSpdVldty_EngSpdVldty != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Tacho_EngSpdVldty_EngSpdVldty_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EngSpd_ForIP_EngSpd_ForIP Rte_IsUpdated_Tacho_EngSpd_ForIP_EngSpd_ForIP
#  define Rte_IsUpdated_Tacho_EngSpd_ForIP_EngSpd_ForIP() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Tacho_EngSpd_ForIP_EngSpd_ForIP != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Tacho_EngSpd_ForIP_EngSpd_ForIP_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TgtEngSpdIP_TgtEngSpdIP Rte_IsUpdated_Tacho_TgtEngSpdIP_TgtEngSpdIP
#  define Rte_IsUpdated_Tacho_TgtEngSpdIP_TgtEngSpdIP() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Tacho_TgtEngSpdIP_TgtEngSpdIP != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Tacho_TgtEngSpdIP_TgtEngSpdIP_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TgtEngSpdIPValid_TgtEngSpdIPValid Rte_IsUpdated_Tacho_TgtEngSpdIPValid_TgtEngSpdIPValid
#  define Rte_IsUpdated_Tacho_TgtEngSpdIPValid_TgtEngSpdIPValid() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Tacho_TgtEngSpdIPValid_TgtEngSpdIPValid != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Tacho_TgtEngSpdIPValid_TgtEngSpdIPValid_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


# endif /* !defined(RTE_CORE) */


# define Tacho_START_SEC_CODE
# include "Tacho_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Tacho_Init Tacho_Init
#  define RTE_RUNNABLE_Tacho_MainFunction Tacho_MainFunction
# endif

FUNC(void, Tacho_CODE) Tacho_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Tacho_CODE) Tacho_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Tacho_STOP_SEC_CODE
# include "Tacho_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_TACHO_H */

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
