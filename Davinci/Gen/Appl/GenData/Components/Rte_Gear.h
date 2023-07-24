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
 *             File:  Rte_Gear.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Gear>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_GEAR_H
# define RTE_GEAR_H

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

# include "Rte_Gear_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_DrvModDisp_DrvModDisp (0U)
#  define Rte_InitValue_DrvModDispSts_DrvModDispSts (0U)
#  define Rte_InitValue_Tgtgear_Down_Tgtgear_Down (0U)
#  define Rte_InitValue_Tgtgear_Up_Tgtgear_Up (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Gear_DrvModDisp_DrvModDisp(P2VAR(DrvModDisp, AUTOMATIC, RTE_GEAR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Gear_DrvModDispSts_DrvModDispSts(P2VAR(DrvModDispSts, AUTOMATIC, RTE_GEAR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Gear_Tgtgear_Down_Tgtgear_Down(P2VAR(Tgtgear_Down, AUTOMATIC, RTE_GEAR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Gear_Tgtgear_Up_Tgtgear_Up(P2VAR(Tgtgear_Up, AUTOMATIC, RTE_GEAR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_DrvModDisp_DrvModDisp Rte_Read_Gear_DrvModDisp_DrvModDisp
#  define Rte_Read_DrvModDispSts_DrvModDispSts Rte_Read_Gear_DrvModDispSts_DrvModDispSts
#  define Rte_Read_Tgtgear_Down_Tgtgear_Down Rte_Read_Gear_Tgtgear_Down_Tgtgear_Down
#  define Rte_Read_Tgtgear_Up_Tgtgear_Up Rte_Read_Gear_Tgtgear_Up_Tgtgear_Up


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_DrvModDisp_DrvModDisp Rte_IsUpdated_Gear_DrvModDisp_DrvModDisp
#  define Rte_IsUpdated_Gear_DrvModDisp_DrvModDisp() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Gear_DrvModDisp_DrvModDisp != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Gear_DrvModDisp_DrvModDisp_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DrvModDispSts_DrvModDispSts Rte_IsUpdated_Gear_DrvModDispSts_DrvModDispSts
#  define Rte_IsUpdated_Gear_DrvModDispSts_DrvModDispSts() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Gear_DrvModDispSts_DrvModDispSts != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Gear_DrvModDispSts_DrvModDispSts_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_Tgtgear_Down_Tgtgear_Down Rte_IsUpdated_Gear_Tgtgear_Down_Tgtgear_Down
#  define Rte_IsUpdated_Gear_Tgtgear_Down_Tgtgear_Down() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Gear_Tgtgear_Down_Tgtgear_Down != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Gear_Tgtgear_Down_Tgtgear_Down_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_Tgtgear_Up_Tgtgear_Up Rte_IsUpdated_Gear_Tgtgear_Up_Tgtgear_Up
#  define Rte_IsUpdated_Gear_Tgtgear_Up_Tgtgear_Up() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Gear_Tgtgear_Up_Tgtgear_Up != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_Gear_Tgtgear_Up_Tgtgear_Up_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


# endif /* !defined(RTE_CORE) */


# define Gear_START_SEC_CODE
# include "Gear_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Gear_Init Gear_Init
#  define RTE_RUNNABLE_Gear_MainFunction Gear_MainFunction
# endif

FUNC(void, Gear_CODE) Gear_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Gear_CODE) Gear_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Gear_STOP_SEC_CODE
# include "Gear_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_GEAR_H */

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
