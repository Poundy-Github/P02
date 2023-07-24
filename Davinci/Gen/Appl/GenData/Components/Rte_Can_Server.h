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
 *             File:  Rte_Can_Server.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Can_Server>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CAN_SERVER_H
# define RTE_CAN_SERVER_H

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

# include "Rte_Can_Server_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_BswMRteModeBusStateReq, RTE_VAR_INIT) Rte_Can_Server_Request_CanServerBusStateReq_requestedMode;
extern VAR(BswM_BswMRteVehicleTypeOptionChoose, RTE_VAR_INIT) Rte_Can_Server_Request_VehicleTypeOptionChoose_requestedMode;
extern VAR(uint32, RTE_VAR_INIT) Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter;
extern VAR(uint8, RTE_VAR_INIT) Rte_SocDtcProcess_ClearDTC_Service0x14_StatusFlag;
extern VAR(wakeup_type, RTE_VAR_INIT) Rte_Power_ppSR_WakeupReason_data;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Can_Server_piDiagMonitorReInitFlag_ChangeCounter (0U)
#  define Rte_InitValue_ClearDTC_Service0x14_StatusFlag (0U)
#  define Rte_InitValue_KL30BRelaySts_KL30BRelaySts (0U)
#  define Rte_InitValue_RemoteModSts_RemoteModSts (0U)
#  define Rte_InitValue_SysPowerMod_SysPowerMod (0U)
#  define Rte_InitValue_SysPowerModVld_SysPowerModVld (0U)
#  define Rte_InitValue_rpSR_WakeupReason_data (0ULL)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Can_Server_Vconfig_GetKindBuffers_AllKinds(P2VAR(uint8, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Can_Server_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Can_Server_rpSR_RTCTimer_UtcTime(P2VAR(sint64, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Can_Server_tiSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(uint8, RTE_CODE) Rte_Mode_Can_Server_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) date); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Can_Server_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Can_Server_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Can_Server_piDiagMonitorReInitFlag_ChangeCounter Rte_Read_Can_Server_Can_Server_piDiagMonitorReInitFlag_ChangeCounter
#  define Rte_Read_Can_Server_Can_Server_piDiagMonitorReInitFlag_ChangeCounter(data) (*(data) = Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_ClearDTC_Service0x14_StatusFlag Rte_Read_Can_Server_ClearDTC_Service0x14_StatusFlag
#  define Rte_Read_Can_Server_ClearDTC_Service0x14_StatusFlag(data) (*(data) = Rte_SocDtcProcess_ClearDTC_Service0x14_StatusFlag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_KL30BRelaySts_KL30BRelaySts Rte_Read_Can_Server_KL30BRelaySts_KL30BRelaySts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Can_Server_KL30BRelaySts_KL30BRelaySts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RemoteModSts_RemoteModSts Rte_Read_Can_Server_RemoteModSts_RemoteModSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Can_Server_RemoteModSts_RemoteModSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SysPowerMod_SysPowerMod Rte_Read_Can_Server_SysPowerMod_SysPowerMod
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Can_Server_SysPowerMod_SysPowerMod(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SysPowerModVld_SysPowerModVld Rte_Read_Can_Server_SysPowerModVld_SysPowerModVld
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Can_Server_SysPowerModVld_SysPowerModVld(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Vconfig_GetKindBuffers_AllKinds Rte_Read_Can_Server_Vconfig_GetKindBuffers_AllKinds
#  define Rte_Read_rpSR_RTCTimer_UtcTime Rte_Read_Can_Server_rpSR_RTCTimer_UtcTime
#  define Rte_Read_rpSR_WakeupReason_data Rte_Read_Can_Server_rpSR_WakeupReason_data
#  define Rte_Read_Can_Server_rpSR_WakeupReason_data(data) (*(data) = Rte_Power_ppSR_WakeupReason_data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_tiSR_Power_Out_SystemStateOut Rte_Read_Can_Server_tiSR_Power_Out_SystemStateOut


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Request_CanServerBusStateReq_requestedMode Rte_Write_Can_Server_Request_CanServerBusStateReq_requestedMode
#  define Rte_Write_Can_Server_Request_CanServerBusStateReq_requestedMode(data) (Rte_Can_Server_Request_CanServerBusStateReq_requestedMode = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Request_VehicleTypeOptionChoose_requestedMode Rte_Write_Can_Server_Request_VehicleTypeOptionChoose_requestedMode
#  define Rte_Write_Can_Server_Request_VehicleTypeOptionChoose_requestedMode(data) (Rte_Can_Server_Request_VehicleTypeOptionChoose_requestedMode = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Mode_Can_Server_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_cpCS_IRTC_Service_UTC2PerpetualCalendar Rte_Call_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar
#  define Rte_Call_rpCS_ComEx_GetRxE2EStatus Rte_Call_Can_Server_rpCS_ComEx_GetRxE2EStatus
#  define Rte_Call_rpCS_ComEx_SendSignal Rte_Call_Can_Server_rpCS_ComEx_SendSignal


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetDTCOfEvent(Dem_EventIdType parg0, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DTCOfEvent); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)224, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType parg0, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType parg0, uint8 RecordNumber, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)224, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventFailed(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) EventFailed); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)224, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType parg0, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType parg0, uint8 RecordNumber, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)224, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventUdsStatus(Dem_EventIdType parg0, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) UDSStatusByte); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)224, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventTested(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) EventTested); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)224, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)224, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType parg0, P2VAR(sint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)224, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_ResetEventDebounceStatus(Dem_EventIdType parg0, Dem_DebounceResetStatusType DebounceResetStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)224, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_ResetEventStatus(Dem_EventIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)224)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)224, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)55, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)55, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)55, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)55)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)56, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)56, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)56, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)56, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)56, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)56, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)56, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)56, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)56, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)56)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)56, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)57, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)57, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)57, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)57, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)57, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)57, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)57, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)57, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)57, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)57)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)57, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)159, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)159, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)159, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)159, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)159, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)159, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)159, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)159, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)159, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)159)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)159, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)58, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)58, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)58, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)58)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)59, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)59, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)59, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)59)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)60, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)60, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)60, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)60)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)223, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)223, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)223, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)223, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)223, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)223, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)223, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)223, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)223, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)223)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)223, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)61, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)61, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)61, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)61)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)127, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)127, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)127, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)127, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)127, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)127, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)127, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)127, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)127, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)127)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)127, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)160, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)160, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)160, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)160, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)160, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)160, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)160, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)160, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)160, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)160)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)160, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)62, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)62, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)62, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)62)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)158, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)158, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)158, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)158, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)158, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)158, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)158, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)158, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)158, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)158)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)158, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)63, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)63, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)63, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)63)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)64, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)64, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)64, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)64)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)65, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)65, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)65, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)65, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)65, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)65, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)65, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)65, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)65, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)65)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)65, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)67, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)67, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)67, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)67, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)67, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)67, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)67, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)67, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)67, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)67)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)67, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)68, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)68, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)68, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)68, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)68, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)68, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)68, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)68, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)68, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)68)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)68, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)69, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)69, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)69, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)69, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)69, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)69, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)69, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)69, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)69, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)69)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)69, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)161, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)161, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)161, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)161, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)161, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)161, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)161, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)161, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)161, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)161)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)161, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)162, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)162, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)162, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)162, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)162, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)162, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)162, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)162, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)162, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)162)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)162, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)163, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)163, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)163, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)163, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)163, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)163, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)163, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)163, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)163, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)163)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)163, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)164, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)164, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)164, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)164, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)164, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)164, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)164, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)164, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)164, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)164)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)164, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)128, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)128, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)128, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)128, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)128, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)128, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)128, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)128, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)128, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)128)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)128, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)70, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)70, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)70, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)70, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)70, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)70, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)70, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)70, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)70, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)70)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)70, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)165, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)165, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)165, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)165, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)165, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)165, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)165, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)165, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)165, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)165)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)165, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)129, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)129, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)129, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)129, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)129, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)129, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)129, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)129, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)129, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)129)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)129, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)130, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)130, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)130, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)130, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)130, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)130, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)130, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)130, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)130, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)130)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)130, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)166, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)166, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)166, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)166, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)166, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)166, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)166, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)166, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)166, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)166)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)166, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)167, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)167, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)167, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)167, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)167, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)167, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)167, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)167, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)167, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)167)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)167, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)168, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)168, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)168, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)168, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)168, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)168, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)168, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)168, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)168, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)168)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)168, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)71, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)71, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)71, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)71, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)71, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)71, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)71, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)71, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)71, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)71)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)71, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)169, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)169, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)169, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)169, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)169, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)169, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)169, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)169, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)169, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)169)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)169, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)131, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)131, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)131, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)131, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)131, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)131, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)131, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)131, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)131, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)131)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)131, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)72, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)72, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)72, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)72, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)72, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)72, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)72, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)72, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)72, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)72)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)72, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)132, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)132, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)132, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)132, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)132, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)132, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)132, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)132, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)132, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)132)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)132, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)133, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)133, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)133, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)133, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)133, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)133, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)133, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)133, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)133, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)133)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)133, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)73, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)73, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)73, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)73, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)73, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)73, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)73, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)73, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)73, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)73)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)73, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)134, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)134, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)134, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)134, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)134, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)134, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)134, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)134, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)134, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)134)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)134, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)74, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)74, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)74, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)74, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)74, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)74, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)74, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)74, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)74, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)74)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)74, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)66, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)66, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)66, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)66, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)66, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)66, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)66, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)66, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)66, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)66)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)66, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)171, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)171, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)171, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)171, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)171, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)171, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)171, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)171, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)171, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)171)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)171, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)173, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)173, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)173, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)173, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)173, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)173, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)173, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)173, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)173, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)173)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)173, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)170, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)170, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)170, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)170, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)170, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)170, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)170, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)170, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)170, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)170)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)170, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)63, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)64, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_ComEx_ReceiveSignal ComEx_ReceiveSignal
#  define RTE_START_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_GATEWAY_APPL_CODE) IPC_API_SetEventTxSignalBuffer_Operation(uint32 EventIndex, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(arg1, arg2) (IPC_API_SetEventTxSignalBuffer_Operation(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_GATEWAY_APPL_CODE) IPC_TransmitSignal_Callback(uint32 SignalIndex, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_IPC_TransmitSignal_Callback(arg1, arg2) (IPC_TransmitSignal_Callback(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_GATEWAY_APPL_CODE) IPC_Tx_E2E_CanMsg_HUT32_CallBack(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_HUT32_CallBack() (IPC_Tx_E2E_CanMsg_HUT32_CallBack(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_GATEWAY_APPL_CODE) IPC_Tx_E2E_CanMsg_HUT_IP2_Callback(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_HUT_IP2_Callback() (IPC_Tx_E2E_CanMsg_HUT_IP2_Callback(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Can_Server_NvBlockNeed_ActiveWUCounter_DefaultValue;
extern CONST(A_80Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_NvBlockNeed_ActiveWUCounter_DefaultValue() (Rte_Can_Server_NvBlockNeed_ActiveWUCounter_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_AbnormalWakeupSleepRecords_DefaultValue() (&(Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_AbnormalWakeupSleepRecords_DefaultValue() (&Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Can_Server_NvBlockNeed_ActiveWUCounter_MirrorBlock;
extern VAR(A_80Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvBlockNeed_ActiveWUCounter_MirrorBlock() \
  (&Rte_Can_Server_NvBlockNeed_ActiveWUCounter_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock() (&((*RtePim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock() RtePim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock() \
  (&Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Can_Server_START_SEC_CODE
# include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CNA_SignalCallBack CNA_SignalCallBack
#  define RTE_RUNNABLE_CNA_SignalGroupSet CNA_SignalGroupSet
#  define RTE_RUNNABLE_CNA_SignalSet CNA_SignalSet
#  define RTE_RUNNABLE_CNA_SignalSetNoTrigger CNA_SignalSetNoTrigger
#  define RTE_RUNNABLE_CNA_SignalSet_U8N CNA_SignalSet_U8N
#  define RTE_RUNNABLE_CanFrameCounter_Can_ABS3_Counter CanFrameCounter_Can_ABS3_Counter
#  define RTE_RUNNABLE_CanFrameCounter_Can_ECM2_Counter CanFrameCounter_Can_ECM2_Counter
#  define RTE_RUNNABLE_CanFrameCounter_Can_ESP_FD2_Counter CanFrameCounter_Can_ESP_FD2_Counter
#  define RTE_RUNNABLE_CanServer_Init CanServer_Init
#  define RTE_RUNNABLE_CanServer_MainFunction CanServer_MainFunction
#  define RTE_RUNNABLE_CanServer_MainFunction_5ms CanServer_MainFunction_5ms
#  define RTE_RUNNABLE_Can_Server_AbnormalWakeupSleepRecord_Get Can_Server_AbnormalWakeupSleepRecord_Get
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished
# endif

FUNC(void, Can_Server_CODE) CNA_SignalCallBack(uint16 signalId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalGroupSet(P2CONST(EventSignalInfo_Type, AUTOMATIC, RTE_VAR_NOINIT) event_signal_info); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSet(uint16 signalId, P2VAR(uint32, AUTOMATIC, RTE_VAR_NOINIT) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSetNoTrigger(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSet_U8N(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSet_U8N(uint16 signalId, P2VAR(EventSignalType, AUTOMATIC, RTE_VAR_NOINIT) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ABS3_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_VAR_NOINIT) counter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ECM2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_VAR_NOINIT) counter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ESP_FD2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_VAR_NOINIT) counter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Can_Server_CODE) CanServer_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Can_Server_CODE) CanServer_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Can_Server_CODE) CanServer_MainFunction_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Can_Server_CODE) Can_Server_AbnormalWakeupSleepRecord_Get(P2VAR(uint8, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Can_Server_CODE) Can_Server_AbnormalWakeupSleepRecord_Get(P2VAR(A_80Bytes, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, Can_Server_CODE) NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Can_Server_CODE) NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Can_Server_STOP_SEC_CODE
# include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CNA_SignalGroupSet_Std_ReturnType (1U)

#  define RTE_E_CNA_SignalSet_Std_ReturnType (1U)

#  define RTE_E_CNA_SignalSetNoTrigger_Std_ReturnType (1U)

#  define RTE_E_CNA_SignalSet_U8N_Std_ReturnType (1U)

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_IRTC_Service_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CAN_SERVER_H */

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
