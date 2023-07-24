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
 *             File:  Rte_BswM.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <BswM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BSWM_H
# define RTE_BSWM_H

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

# include "Rte_BswM_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Provide_BswMRteModeRequestPort_Element (FALSE)
#  define Rte_InitValue_Provide_BswMRteModeRequestPort_ResetReason_ResetSource (0U)
#  define Rte_InitValue_Provide_BswMRteModeRequestPort_ResetType_Element (FALSE)
#  define Rte_InitValue_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource (0ULL)
#  define Rte_InitValue_Request_CanCommunicationVolEnable_requestedMode (0U)
#  define Rte_InitValue_Request_CanServerBusStateReq_requestedMode (1U)
#  define Rte_InitValue_Request_ESH_PostRunRequest_0_requestedMode (0U)
#  define Rte_InitValue_Request_ESH_PostRunRequest_1_requestedMode (0U)
#  define Rte_InitValue_Request_ESH_RunRequest_0_requestedMode (0U)
#  define Rte_InitValue_Request_ESH_RunRequest_1_requestedMode (0U)
#  define Rte_InitValue_Request_PowerModeShutdownReq_requestedMode (0U)
#  define Rte_InitValue_Request_PowerModeShutdownReq_EmergencySleep_requestedMode (0U)
#  define Rte_InitValue_Request_VehicleTypeOptionChoose_requestedMode (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_CanCommunicationVolEnable_requestedMode(P2VAR(BswM_BswMRteModeVolEnable, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_CanServerBusStateReq_requestedMode(P2VAR(BswM_BswMRteModeBusStateReq, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_PowerModeShutdownReq_requestedMode(P2VAR(BswM_BswMRteShutdownReqMode, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_PowerModeShutdownReq_EmergencySleep_requestedMode(P2VAR(BswM_BswMRteShutdownReqMode, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_VehicleTypeOptionChoose_requestedMode(P2VAR(BswM_BswMRteVehicleTypeOptionChoose, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_Element(boolean data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource(reset_type data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_ResetType_Element(boolean data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource(wakeup_type data); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(BswM_ESH_Mode, RTE_CODE) Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode nextMode);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Request_CanCommunicationVolEnable_requestedMode Rte_Read_BswM_Request_CanCommunicationVolEnable_requestedMode
#  define Rte_Read_Request_CanServerBusStateReq_requestedMode Rte_Read_BswM_Request_CanServerBusStateReq_requestedMode
#  define Rte_Read_Request_ESH_PostRunRequest_0_requestedMode Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode
#  define Rte_Read_Request_ESH_PostRunRequest_1_requestedMode Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode
#  define Rte_Read_Request_ESH_RunRequest_0_requestedMode Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode
#  define Rte_Read_Request_ESH_RunRequest_1_requestedMode Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode
#  define Rte_Read_Request_PowerModeShutdownReq_requestedMode Rte_Read_BswM_Request_PowerModeShutdownReq_requestedMode
#  define Rte_Read_Request_PowerModeShutdownReq_EmergencySleep_requestedMode Rte_Read_BswM_Request_PowerModeShutdownReq_EmergencySleep_requestedMode
#  define Rte_Read_Request_VehicleTypeOptionChoose_requestedMode Rte_Read_BswM_Request_VehicleTypeOptionChoose_requestedMode


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Provide_BswMRteModeRequestPort_Element Rte_Write_BswM_Provide_BswMRteModeRequestPort_Element
#  define Rte_Write_Provide_BswMRteModeRequestPort_ResetReason_ResetSource Rte_Write_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource
#  define Rte_Write_Provide_BswMRteModeRequestPort_ResetType_Element Rte_Write_BswM_Provide_BswMRteModeRequestPort_ResetType_Element
#  define Rte_Write_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource Rte_Write_BswM_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode


# endif /* !defined(RTE_CORE) */


# define BswM_START_SEC_CODE
# include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BswM_MainFunction BswM_MainFunction
#  define RTE_RUNNABLE_BswM_Read_PowerModeShutdownReq BswM_Read_PowerModeShutdownReq
#  define RTE_RUNNABLE_BswM_Read_PowerModeShutdownReq_EmergencySleep BswM_Read_PowerModeShutdownReq_EmergencySleep
# endif

FUNC(void, BswM_CODE) BswM_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, BswM_CODE) BswM_Read_PowerModeShutdownReq(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, BswM_CODE) BswM_Read_PowerModeShutdownReq_EmergencySleep(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define BswM_STOP_SEC_CODE
# include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BSWM_H */

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
