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
 *             File:  Rte_SocDtcProcess.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <SocDtcProcess>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SOCDTCPROCESS_H
# define RTE_SOCDTCPROCESS_H

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

# include "Rte_SocDtcProcess_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SocDtcProcess_ClearDTC_Service0x14_StatusFlag;
extern VAR(uint8, RTE_VAR_INIT) Rte_SocDtcProcess_ppSR_DtcInfoForIPErrorStatus_Element;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ClearDTC_Service0x14_StatusFlag (0U)
#  define Rte_InitValue_pPSR_DiagMonitorReInitFlag_ChangeCounter (0U)
#  define Rte_InitValue_ppSR_DtcInfoForIPErrorStatus_Element (0U)
#  define Rte_InitValue_rpSR_EngSpd_EngSpd (0U)
#  define Rte_InitValue_rpSR_RTCTimer_SleepDateTime (0LL)
#  define Rte_InitValue_rpSR_TMCU_ActSpd_RM_TMCU_ActSpd_RM (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_ppSR_DTC_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_ppSR_DTC_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_rpSR_OdoParament_Element(P2VAR(s_OdoRteGetParament_t, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_rpSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_rpSR_RTCTimer_SleepDateTime(P2VAR(sint64, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_rpSR_RTCTimer_UtcTime(P2VAR(sint64, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter(uint32 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) date); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SocDtcProcess_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */


# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ppSR_DTC_SpeedoInfo_Element Rte_Read_SocDtcProcess_ppSR_DTC_SpeedoInfo_Element
#  define Rte_Read_ppSR_DTC_TachoInfo_Element Rte_Read_SocDtcProcess_ppSR_DTC_TachoInfo_Element
#  define Rte_Read_rpSR_EngSpd_EngSpd Rte_Read_SocDtcProcess_rpSR_EngSpd_EngSpd
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SocDtcProcess_rpSR_EngSpd_EngSpd(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_rpSR_OdoParament_Element Rte_Read_SocDtcProcess_rpSR_OdoParament_Element
#  define Rte_Read_rpSR_Power_Out_SystemStateOut Rte_Read_SocDtcProcess_rpSR_Power_Out_SystemStateOut
#  define Rte_Read_rpSR_RTCTimer_SleepDateTime Rte_Read_SocDtcProcess_rpSR_RTCTimer_SleepDateTime
#  define Rte_Read_rpSR_RTCTimer_UtcTime Rte_Read_SocDtcProcess_rpSR_RTCTimer_UtcTime
#  define Rte_Read_rpSR_SG_ABS3_SG_ABS3 Rte_Read_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3(data) (*(data) = Rte_C_SG_ABS3_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_rpSR_TMCU_ActSpd_RM_TMCU_ActSpd_RM Rte_Read_SocDtcProcess_rpSR_TMCU_ActSpd_RM_TMCU_ActSpd_RM
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SocDtcProcess_rpSR_TMCU_ActSpd_RM_TMCU_ActSpd_RM(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_rpSR_SG_ABS3_SG_ABS3 Rte_IsUpdated_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3
#  define Rte_IsUpdated_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ClearDTC_Service0x14_StatusFlag Rte_Write_SocDtcProcess_ClearDTC_Service0x14_StatusFlag
#  define Rte_Write_SocDtcProcess_ClearDTC_Service0x14_StatusFlag(data) (Rte_SocDtcProcess_ClearDTC_Service0x14_StatusFlag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_pPSR_DiagMonitorReInitFlag_ChangeCounter Rte_Write_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter
#  define Rte_Write_ppSR_DtcInfoForIPErrorStatus_Element Rte_Write_SocDtcProcess_ppSR_DtcInfoForIPErrorStatus_Element
#  define Rte_Write_SocDtcProcess_ppSR_DtcInfoForIPErrorStatus_Element(data) (Rte_SocDtcProcess_ppSR_DtcInfoForIPErrorStatus_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Rte_Call_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#  define Rte_Call_cpCS_IRTC_Service_UTC2PerpetualCalendar Rte_Call_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar
#  define Rte_Call_rpCS_ComEx_GetRxE2EStatus Rte_Call_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus
#  define Rte_Call_rpCS_ComEx_SendSignal Rte_Call_SocDtcProcess_rpCS_ComEx_SendSignal


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_ClearDTC(uint8 parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ClearDTC_ClearDTC() (Dem_ClearDTC((uint8)0)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SelectDTC(uint8 parg0, uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ClearDTC_SelectDTC(arg1, arg2, arg3) (Dem_SelectDTC((uint8)0, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetEnableCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EnableCondition_BatteryVoltage_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)1, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_EnableCondition_BatteryVoltage2_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)2, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_EnableCondition_BatteryVoltage3_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)3, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_EnableCondition_BatteryVoltage4_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_EnableCondition_IgnOn_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)5, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DTCOfEvent); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetDTCOfEvent Dem_GetDTCOfEvent
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetDebouncingOfEvent(Dem_EventIdType EventId, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DebouncingState); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetDebouncingOfEvent Dem_GetDebouncingOfEvent
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventEnableCondition(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) ConditionFullfilled); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetEventEnableCondition Dem_GetEventEnableCondition
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetEventExtendedDataRecordEx Dem_GetEventExtendedDataRecordEx
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventFailed(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventFailed); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetEventFailed Dem_GetEventFailed
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx Dem_GetEventFreezeFrameDataEx
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) UDSStatusByte); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetEventStatus Dem_GetEventUdsStatus
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventTested(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventTested); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetEventTested Dem_GetEventTested
#  define Rte_Call_GeneralDiagnosticInfo_GetEventUdsStatus Dem_GetEventUdsStatus
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetFaultDetectionCounter Dem_GetFaultDetectionCounter
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetMonitorStatus(Dem_EventIdType EventId, P2VAR(Dem_MonitorStatusType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) MonitorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetMonitorStatus Dem_GetMonitorStatus
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetOperationCycleState(uint8 parg0, P2VAR(Dem_OperationCycleStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) CycleState); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_OperationCycle_Ign_on_off_GetOperationCycleState(arg1) (Dem_GetOperationCycleState((uint8)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetOperationCycleState(uint8 parg0, Dem_OperationCycleStateType CycleState); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_OperationCycle_Ign_on_off_SetOperationCycleState(arg1) (Dem_SetOperationCycleState((uint8)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_OperationCycle_Power_up_down_GetOperationCycleState(arg1) (Dem_GetOperationCycleState((uint8)1, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_OperationCycle_Power_up_down_SetOperationCycleState(arg1) (Dem_SetOperationCycleState((uint8)1, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
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


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_SocDtcPorcessExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_Exit_SocDtcPorcessExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


# endif /* !defined(RTE_CORE) */


# define SocDtcProcess_START_SEC_CODE
# include "SocDtcProcess_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CSDataServices_DID_0xd001_Vehicle_Speed_ReadData CSDataServices_DID_0xd001_Vehicle_Speed_ReadData
#  define RTE_RUNNABLE_CSDataServices_DID_0xd002_EngineSpeed_ReadData CSDataServices_DID_0xd002_EngineSpeed_ReadData
#  define RTE_RUNNABLE_CSDataServices_DID_0xd003_OperatingVoltage_ReadData CSDataServices_DID_0xd003_OperatingVoltage_ReadData
#  define RTE_RUNNABLE_CSDataServices_DID_0xd004_Odometer_ReadData CSDataServices_DID_0xd004_Odometer_ReadData
#  define RTE_RUNNABLE_CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData
#  define RTE_RUNNABLE_CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData
#  define RTE_RUNNABLE_CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData
#  define RTE_RUNNABLE_ClearDtcNotificationFinish_ClearDtcNotification ClearDtcNotificationFinish_ClearDtcNotification
#  define RTE_RUNNABLE_ClearDtcNotificationStart_ClearDtcNotification ClearDtcNotificationStart_ClearDtcNotification
#  define RTE_RUNNABLE_IPCIviReportDtcStatus_IpcIviReportDtcSts IPCIviReportDtcStatus_IpcIviReportDtcSts
#  define RTE_RUNNABLE_IPCSocReportDtcStatus_IpcSocReportDtcStatus IPCSocReportDtcStatus_IpcSocReportDtcStatus
#  define RTE_RUNNABLE_PpCS_AppClearDTCInfo_AppClearDTCInfo PpCS_AppClearDTCInfo_AppClearDTCInfo
#  define RTE_RUNNABLE_PpCS_AppReadDtcInfomation_AppReadDtcInformation PpCS_AppReadDtcInfomation_AppReadDtcInformation
#  define RTE_RUNNABLE_SocDtcProcess_Init SocDtcProcess_Init
#  define RTE_RUNNABLE_SocDtcProcess_MainFunction SocDtcProcess_MainFunction
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd001_Vehicle_Speed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd001_Vehicle_Speed_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd002_EngineSpeed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd002_EngineSpeed_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd003_OperatingVoltage_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd003_OperatingVoltage_ReadData(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd004_Odometer_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd004_Odometer_ReadData(P2VAR(DataArrayType_uint8_3, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData(P2VAR(DataArrayType_uint8_4, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SocDtcProcess_CODE) ClearDtcNotificationFinish_ClearDtcNotification(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SocDtcProcess_CODE) ClearDtcNotificationStart_ClearDtcNotification(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SocDtcProcess_CODE) IPCIviReportDtcStatus_IpcIviReportDtcSts(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data, uint8 length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SocDtcProcess_CODE) IPCSocReportDtcStatus_IpcSocReportDtcStatus(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SocDtcProcess_CODE) PpCS_AppClearDTCInfo_AppClearDTCInfo(uint8 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SocDtcProcess_CODE) PpCS_AppReadDtcInfomation_AppReadDtcInformation(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) DtcInfo); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SocDtcProcess_CODE) SocDtcProcess_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SocDtcProcess_CODE) SocDtcProcess_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SocDtcProcess_STOP_SEC_CODE
# include "SocDtcProcess_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_DID_0xd001_Vehicle_Speed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd002_EngineSpeed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd003_OperatingVoltage_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd004_Odometer_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd005_DTC_Occurrence_Timer_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd006_ActualRotationSpeed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd007_ActualRotationSpeed02_E_NOT_OK (1U)

#  define RTE_E_ClearDTC_DEM_CLEAR_BUSY (5U)

#  define RTE_E_ClearDTC_DEM_CLEAR_FAILED (7U)

#  define RTE_E_ClearDTC_DEM_CLEAR_MEMORY_ERROR (6U)

#  define RTE_E_ClearDTC_DEM_PENDING (4U)

#  define RTE_E_ClearDTC_DEM_WRONG_DTC (8U)

#  define RTE_E_ClearDTC_DEM_WRONG_DTCORIGIN (9U)

#  define RTE_E_ClearDTC_E_NOT_OK (1U)

#  define RTE_E_ClearDTC_E_OK (0U)

#  define RTE_E_ClearDtcNotification_E_OK (0U)

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_EnableCondition_E_NOT_OK (1U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_GeneralDiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_IRTC_Service_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_OK (0U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SOCDTCPROCESS_H */

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
