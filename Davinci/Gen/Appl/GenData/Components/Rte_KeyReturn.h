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
 *             File:  Rte_KeyReturn.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <KeyReturn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_KEYRETURN_H
# define RTE_KEYRETURN_H

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

# include "Rte_KeyReturn_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AdjVolDwnSwtSts_AdjVolDwnSwtSts (0U)
#  define Rte_InitValue_AdjVolUpSwtSts_AdjVolUpSwtSts (0U)
#  define Rte_InitValue_CustomSwtSts_CustomSwtSts (0U)
#  define Rte_InitValue_CustomSwtSts_Mmed_CustomSwtSts_Mmed (0U)
#  define Rte_InitValue_EnterSwtSts_EnterSwtSts (0U)
#  define Rte_InitValue_EnterSwtSts_Mmed_EnterSwtSts_Mmed (0U)
#  define Rte_InitValue_HomeSwtSts_HomeSwtSts (0U)
#  define Rte_InitValue_MenuReturnSwtSts_MenuReturnSwtSts (0U)
#  define Rte_InitValue_MuteSwtSts_MuteSwtSts (0U)
#  define Rte_InitValue_PageDwnSwtSts_PageDwnSwtSts (0U)
#  define Rte_InitValue_PageLSwtSts_PageLSwtSts (0U)
#  define Rte_InitValue_PageRSwtSts_PageRSwtSts (0U)
#  define Rte_InitValue_PageUpSwtSts_PageUpSwtSts (0U)
#  define Rte_InitValue_SeekDwnSwtSts_SeekDwnSwtSts (0U)
#  define Rte_InitValue_SeekUpSwtSts_SeekUpSwtSts (0U)
#  define Rte_InitValue_VRSwtSts_VRSwtSts (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AdjVolDwnSwtSts_AdjVolDwnSwtSts Rte_Read_KeyReturn_AdjVolDwnSwtSts_AdjVolDwnSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_AdjVolDwnSwtSts_AdjVolDwnSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_AdjVolUpSwtSts_AdjVolUpSwtSts Rte_Read_KeyReturn_AdjVolUpSwtSts_AdjVolUpSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_AdjVolUpSwtSts_AdjVolUpSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CustomSwtSts_CustomSwtSts Rte_Read_KeyReturn_CustomSwtSts_CustomSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_CustomSwtSts_CustomSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CustomSwtSts_Mmed_CustomSwtSts_Mmed Rte_Read_KeyReturn_CustomSwtSts_Mmed_CustomSwtSts_Mmed
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_CustomSwtSts_Mmed_CustomSwtSts_Mmed(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EnterSwtSts_EnterSwtSts Rte_Read_KeyReturn_EnterSwtSts_EnterSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_EnterSwtSts_EnterSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EnterSwtSts_Mmed_EnterSwtSts_Mmed Rte_Read_KeyReturn_EnterSwtSts_Mmed_EnterSwtSts_Mmed
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_EnterSwtSts_Mmed_EnterSwtSts_Mmed(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HomeSwtSts_HomeSwtSts Rte_Read_KeyReturn_HomeSwtSts_HomeSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_HomeSwtSts_HomeSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_MenuReturnSwtSts_MenuReturnSwtSts Rte_Read_KeyReturn_MenuReturnSwtSts_MenuReturnSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_MenuReturnSwtSts_MenuReturnSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_MuteSwtSts_MuteSwtSts Rte_Read_KeyReturn_MuteSwtSts_MuteSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_MuteSwtSts_MuteSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PageDwnSwtSts_PageDwnSwtSts Rte_Read_KeyReturn_PageDwnSwtSts_PageDwnSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_PageDwnSwtSts_PageDwnSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PageLSwtSts_PageLSwtSts Rte_Read_KeyReturn_PageLSwtSts_PageLSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_PageLSwtSts_PageLSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PageRSwtSts_PageRSwtSts Rte_Read_KeyReturn_PageRSwtSts_PageRSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_PageRSwtSts_PageRSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PageUpSwtSts_PageUpSwtSts Rte_Read_KeyReturn_PageUpSwtSts_PageUpSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_PageUpSwtSts_PageUpSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SeekDwnSwtSts_SeekDwnSwtSts Rte_Read_KeyReturn_SeekDwnSwtSts_SeekDwnSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_SeekDwnSwtSts_SeekDwnSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SeekUpSwtSts_SeekUpSwtSts Rte_Read_KeyReturn_SeekUpSwtSts_SeekUpSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_SeekUpSwtSts_SeekUpSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_VRSwtSts_VRSwtSts Rte_Read_KeyReturn_VRSwtSts_VRSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KeyReturn_VRSwtSts_VRSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_AdjVolDwnSwtSts_AdjVolDwnSwtSts Rte_IsUpdated_KeyReturn_AdjVolDwnSwtSts_AdjVolDwnSwtSts
#  define Rte_IsUpdated_KeyReturn_AdjVolDwnSwtSts_AdjVolDwnSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_AdjVolUpSwtSts_AdjVolUpSwtSts Rte_IsUpdated_KeyReturn_AdjVolUpSwtSts_AdjVolUpSwtSts
#  define Rte_IsUpdated_KeyReturn_AdjVolUpSwtSts_AdjVolUpSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CustomSwtSts_CustomSwtSts Rte_IsUpdated_KeyReturn_CustomSwtSts_CustomSwtSts
#  define Rte_IsUpdated_KeyReturn_CustomSwtSts_CustomSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CustomSwtSts_Mmed_CustomSwtSts_Mmed Rte_IsUpdated_KeyReturn_CustomSwtSts_Mmed_CustomSwtSts_Mmed
#  define Rte_IsUpdated_KeyReturn_CustomSwtSts_Mmed_CustomSwtSts_Mmed() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EnterSwtSts_EnterSwtSts Rte_IsUpdated_KeyReturn_EnterSwtSts_EnterSwtSts
#  define Rte_IsUpdated_KeyReturn_EnterSwtSts_EnterSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EnterSwtSts_Mmed_EnterSwtSts_Mmed Rte_IsUpdated_KeyReturn_EnterSwtSts_Mmed_EnterSwtSts_Mmed
#  define Rte_IsUpdated_KeyReturn_EnterSwtSts_Mmed_EnterSwtSts_Mmed() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HomeSwtSts_HomeSwtSts Rte_IsUpdated_KeyReturn_HomeSwtSts_HomeSwtSts
#  define Rte_IsUpdated_KeyReturn_HomeSwtSts_HomeSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_MenuReturnSwtSts_MenuReturnSwtSts Rte_IsUpdated_KeyReturn_MenuReturnSwtSts_MenuReturnSwtSts
#  define Rte_IsUpdated_KeyReturn_MenuReturnSwtSts_MenuReturnSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_MuteSwtSts_MuteSwtSts Rte_IsUpdated_KeyReturn_MuteSwtSts_MuteSwtSts
#  define Rte_IsUpdated_KeyReturn_MuteSwtSts_MuteSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PageDwnSwtSts_PageDwnSwtSts Rte_IsUpdated_KeyReturn_PageDwnSwtSts_PageDwnSwtSts
#  define Rte_IsUpdated_KeyReturn_PageDwnSwtSts_PageDwnSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PageLSwtSts_PageLSwtSts Rte_IsUpdated_KeyReturn_PageLSwtSts_PageLSwtSts
#  define Rte_IsUpdated_KeyReturn_PageLSwtSts_PageLSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PageRSwtSts_PageRSwtSts Rte_IsUpdated_KeyReturn_PageRSwtSts_PageRSwtSts
#  define Rte_IsUpdated_KeyReturn_PageRSwtSts_PageRSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PageUpSwtSts_PageUpSwtSts Rte_IsUpdated_KeyReturn_PageUpSwtSts_PageUpSwtSts
#  define Rte_IsUpdated_KeyReturn_PageUpSwtSts_PageUpSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SeekDwnSwtSts_SeekDwnSwtSts Rte_IsUpdated_KeyReturn_SeekDwnSwtSts_SeekDwnSwtSts
#  define Rte_IsUpdated_KeyReturn_SeekDwnSwtSts_SeekDwnSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SeekUpSwtSts_SeekUpSwtSts Rte_IsUpdated_KeyReturn_SeekUpSwtSts_SeekUpSwtSts
#  define Rte_IsUpdated_KeyReturn_SeekUpSwtSts_SeekUpSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_VRSwtSts_VRSwtSts Rte_IsUpdated_KeyReturn_VRSwtSts_VRSwtSts
#  define Rte_IsUpdated_KeyReturn_VRSwtSts_VRSwtSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


# endif /* !defined(RTE_CORE) */


# define KeyReturn_START_SEC_CODE
# include "KeyReturn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_KeyReturn_Init KeyReturn_Init
#  define RTE_RUNNABLE_KeyReturn_MainFunction KeyReturn_MainFunction
#  define RTE_RUNNABLE_KeyReturn_Server_State KeyReturn_Server_State
#  define RTE_RUNNABLE_KeyReturn_Server_disanle KeyReturn_Server_disanle
#  define RTE_RUNNABLE_KeyReturn_Server_enable KeyReturn_Server_enable
#  define RTE_RUNNABLE_KeyReturn_Server_register KeyReturn_Server_register
#  define RTE_RUNNABLE_KeyReturn_Server_remove KeyReturn_Server_remove
# endif

FUNC(void, KeyReturn_CODE) KeyReturn_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, KeyReturn_CODE) KeyReturn_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, KeyReturn_CODE) KeyReturn_Server_State(uint8 KeyId, P2VAR(boolean, AUTOMATIC, RTE_KEYRETURN_APPL_VAR) isPress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, KeyReturn_CODE) KeyReturn_Server_disanle(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, KeyReturn_CODE) KeyReturn_Server_enable(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, KeyReturn_CODE) KeyReturn_Server_register(P2CONST(KeyAttribute_st, AUTOMATIC, RTE_KEYRETURN_APPL_DATA) attribute, P2VAR(uint8, AUTOMATIC, RTE_KEYRETURN_APPL_VAR) KeyId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, KeyReturn_CODE) KeyReturn_Server_remove(uint8 KeyId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define KeyReturn_STOP_SEC_CODE
# include "KeyReturn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_KEYRETURN_H */

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
