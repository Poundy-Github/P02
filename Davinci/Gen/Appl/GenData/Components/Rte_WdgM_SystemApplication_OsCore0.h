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
 *             File:  Rte_WdgM_SystemApplication_OsCore0.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <WdgM_SystemApplication_OsCore0>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_H
# define RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_H

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

# include "Rte_WdgM_SystemApplication_OsCore0_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SystemApplication_OsCore0_globalStateChangeCbk_Core0_GlobalStatusCallback(WdgM_GlobalStatusType Status); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_GEAR_LocalStatusCallback(WdgM_LocalStatusType Status); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_TT_LocalStatusCallback(WdgM_LocalStatusType Status); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_test_LocalStatusCallback(WdgM_LocalStatusType Status); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_globalStateChangeCbk_Core0_GlobalStatusCallback Rte_Call_WdgM_SystemApplication_OsCore0_globalStateChangeCbk_Core0_GlobalStatusCallback
#  define Rte_Call_localStateChangeCbk_WdgMSupervisedEntity_GEAR_LocalStatusCallback Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_GEAR_LocalStatusCallback
#  define Rte_Call_localStateChangeCbk_WdgMSupervisedEntity_TT_LocalStatusCallback Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_TT_LocalStatusCallback
#  define Rte_Call_localStateChangeCbk_WdgMSupervisedEntity_test_LocalStatusCallback Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_test_LocalStatusCallback


# endif /* !defined(RTE_CORE) */


# define WdgM_SystemApplication_OsCore0_START_SEC_CODE
# include "WdgM_SystemApplication_OsCore0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CheckpointReached WdgM_CheckpointReached
#  define RTE_RUNNABLE_GetFirstExpiredSEID WdgM_GetFirstExpiredSEID
#  define RTE_RUNNABLE_GetGlobalStatus WdgM_GetGlobalStatus
#  define RTE_RUNNABLE_GetLocalStatus WdgM_GetLocalStatus
#  define RTE_RUNNABLE_GetMode WdgM_GetMode
#  define RTE_RUNNABLE_PerformReset WdgM_PerformReset
#  define RTE_RUNNABLE_SetMode WdgM_SetMode
#  define RTE_RUNNABLE_WdgM_MainFunction WdgM_MainFunction
# endif

FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType CPID); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_GetFirstExpiredSEID(P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) SEID); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_GetGlobalStatus(P2VAR(WdgM_GlobalStatusType, AUTOMATIC, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) Status); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, P2VAR(WdgM_LocalStatusType, AUTOMATIC, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) Status); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_GetMode(P2VAR(WdgM_ModeType, AUTOMATIC, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) Mode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_PerformReset(void); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, WdgM_SystemApplication_OsCore0_CODE) WdgM_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define WdgM_SystemApplication_OsCore0_STOP_SEC_CODE
# include "WdgM_SystemApplication_OsCore0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_WdgM_AliveSupervision_E_NOT_OK (1U)

#  define RTE_E_WdgM_General_E_NOT_OK (1U)

#  define RTE_E_WdgM_LocalStatus_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_H */

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
