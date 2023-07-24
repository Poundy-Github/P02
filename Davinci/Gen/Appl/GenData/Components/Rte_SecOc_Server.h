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
 *             File:  Rte_SecOc_Server.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <SecOc_Server>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SECOC_SERVER_H
# define RTE_SECOC_SERVER_H

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

# include "Rte_SecOc_Server_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_INIT) Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */

# ifndef RTE_CORE

#  define RTE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* RTE Helper-Functions */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);

#  define RTE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_SyncRequestMessageId_SyncRequestMessageId (17U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SecOc_Server_VerificationStatus_verificationStatus(P2VAR(SecOC_VerificationStatusType, AUTOMATIC, RTE_SECOC_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SecOc_Server_tiSR_VIN_Element(P2VAR(uint8, AUTOMATIC, RTE_SECOC_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SecOc_Server_tiSR_VIN_Element(P2VAR(A_17Bytes, AUTOMATIC, RTE_SECOC_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SecOc_Server_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_VerificationStatus_verificationStatus Rte_Read_SecOc_Server_VerificationStatus_verificationStatus
#  define Rte_Read_piDiagMonitorReInitFlag_ChangeCounter Rte_Read_SecOc_Server_piDiagMonitorReInitFlag_ChangeCounter
#  define Rte_Read_SecOc_Server_piDiagMonitorReInitFlag_ChangeCounter(data) (*(data) = Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_tiSR_VIN_Element Rte_Read_SecOc_Server_tiSR_VIN_Element


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SyncRequestMessageId_SyncRequestMessageId Rte_Write_SecOc_Server_SyncRequestMessageId_SyncRequestMessageId
#  define Rte_Write_SecOc_Server_SyncRequestMessageId_SyncRequestMessageId(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SyncRequstReseverData1_SyncRequstReseverData1 Rte_Write_SecOc_Server_SyncRequstReseverData1_SyncRequstReseverData1
#  define Rte_Write_SecOc_Server_SyncRequstReseverData1_SyncRequstReseverData1(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_ComEx_SendSignal Rte_Call_SecOc_Server_ComEx_SendSignal


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetCurrentComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_GetCurrentComMode(arg1) (ComM_GetCurrentComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_HSM_APPL_CODE) HsmGetCmacKey(P2VAR(uint8, AUTOMATIC, RTE_HSM_APPL_VAR) key, P2VAR(uint32, AUTOMATIC, RTE_HSM_APPL_VAR) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_HSM_APPL_CODE) HsmGetCmacKey(P2VAR(IdtHsmKeyArray, AUTOMATIC, RTE_HSM_APPL_VAR) key, P2VAR(uint32, AUTOMATIC, RTE_HSM_APPL_VAR) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_HsmKeyM_GetCmacKey(arg1, arg2) (HsmGetCmacKey(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_HSM_APPL_CODE) HsmGetCmacKeyState(P2VAR(HSM_KeyStateEnum, AUTOMATIC, RTE_HSM_APPL_VAR) state); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_HsmKeyM_GetCmacKeyState(arg1) (HsmGetCmacKeyState(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_HSM_APPL_CODE) HsmSetCmacKey(P2CONST(uint8, AUTOMATIC, RTE_HSM_APPL_DATA) vin, uint32 vin_len, P2CONST(uint8, AUTOMATIC, RTE_HSM_APPL_DATA) key, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_HSM_APPL_CODE) HsmSetCmacKey(P2CONST(IdtHsmVinArray, AUTOMATIC, RTE_HSM_APPL_DATA) vin, uint32 vin_len, P2CONST(IdtHsmKeyArray, AUTOMATIC, RTE_HSM_APPL_DATA) key, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_HsmKeyM_SetCmacKey(arg1, arg2, arg3, arg4) (HsmSetCmacKey(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_Monitor_Fvm_TripCount_NVM_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)117, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_FV_synchronization_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)76, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_GWSecOcFailure_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)81, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_SecOcFailure_ESP_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)222, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_SecOcFailure_IDC_L2_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)218, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_SecOcFailure_IDC_L3_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)219, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_SecOcFailure_IFC_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)220, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_SecOcFailure_TCU_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)221, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_TBoxSecOcFailure_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)78, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_key_UsageTime_SetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Monitor_SecOC_key_storage_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)77, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_SECOC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_SECOC_APPL_CODE) SecOC_VerifyStatusOverride(uint16 freshnessValueID, uint8 overrideStatus, uint8 numberOfMessagesToOverride); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_SECOC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_VerifyStatusConfiguration_VerifyStatusOverride SecOC_VerifyStatusOverride


# endif /* !defined(RTE_CORE) */


# define SecOc_Server_START_SEC_CODE
# include "SecOc_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished
#  define RTE_RUNNABLE_SecOc_Server_Init SecOc_Server_Init
#  define RTE_RUNNABLE_SecOc_Server_MainFunction SecOc_Server_MainFunction
# endif

FUNC(void, SecOc_Server_CODE) NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SecOc_Server_CODE) SecOc_Server_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SecOc_Server_CODE) SecOc_Server_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SecOc_Server_STOP_SEC_CODE
# include "SecOc_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_SecOC_VerifyStatusConfiguration_E_NOT_OK (1U)

#  define RTE_E_SecOC_VerifyStatusConfiguration_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SECOC_SERVER_H */

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
