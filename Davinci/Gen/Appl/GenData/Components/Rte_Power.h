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
 *             File:  Rte_Power.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Power>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_POWER_H
# define RTE_POWER_H

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

# include "Os.h"
# include "Rte_Power_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_Power_Ecum_Set_SystemState_Run_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_Power_IVI_10MIN_Backup_flag_Element;
extern VAR(BswM_BswMRteModeVolEnable, RTE_VAR_INIT) Rte_Power_Request_PowerVolEnable_requestedMode;
extern VAR(boolean, RTE_VAR_INIT) Rte_Power_Sd_BswM_Warm_Reset_Element;
extern VAR(wakeup_type, RTE_VAR_INIT) Rte_Power_ppSR_WakeupReason_data;
extern VAR(boolean, RTE_VAR_INIT) Rte_BswM_Provide_BswMRteModeRequestPort_ResetType_Element;
extern VAR(reset_type, RTE_VAR_INIT) Rte_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource;
extern VAR(boolean, RTE_VAR_INIT) Rte_SOCManager_SeekDwnAndPageLPress_Timeout_Element;
extern VAR(boolean, RTE_VAR_INIT) Rte_AMP_ppSR_AMPDeInitFinished_State;
extern VAR(boolean, RTE_VAR_INIT) Rte_Gyro_ppSR_GyroDeInitFinished_State;
extern VAR(uint8, RTE_VAR_INIT) Rte_SOCManager_ppSR_SocManager_SystemState;
extern VAR(uint32, RTE_VAR_INIT) Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_AWakeHold_DVRRemtCnSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_AwakeHlod_Heartbeat_counter;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AWakeHold_DVRRemtCnSts (0U)
#  define Rte_InitValue_AntitheftSts_AntitheftSts (0U)
#  define Rte_InitValue_AwakeHlod_Heartbeat_counter (0U)
#  define Rte_InitValue_CURRENT_GEAR_CURRENT_GEAR (0U)
#  define Rte_InitValue_DrvDoorLockSts_DrvDoorLockSts (0U)
#  define Rte_InitValue_DrvDoorSts_DrvDoorSts (0U)
#  define Rte_InitValue_Ecum_Set_SystemState_Run_Element (FALSE)
#  define Rte_InitValue_HUD_SwtSts_HUD_SwtSts (1U)
#  define Rte_InitValue_IVI_10MIN_Backup_flag_Element (0U)
#  define Rte_InitValue_LvPwrSysErr_LvPwrSysErr (0U)
#  define Rte_InitValue_Rc_BswM_Warm_Reset_Element (FALSE)
#  define Rte_InitValue_Rc_Cluster_Shutdown_Status_Element (0U)
#  define Rte_InitValue_Rc_ResetReason_ResetSource (0U)
#  define Rte_InitValue_Rc_Wakeup_Reason_WakeupSource (0ULL)
#  define Rte_InitValue_RemoteModSts_RemoteModSts (0U)
#  define Rte_InitValue_Request_PowerModeShutdownReq_requestedMode (0U)
#  define Rte_InitValue_Sd_BswM_Warm_Reset_Element (FALSE)
#  define Rte_InitValue_Sd_Cluster_Shutdown_Status_Element (0U)
#  define Rte_InitValue_SeekDwnAndPageLPress_Timeout_Element (FALSE)
#  define Rte_InitValue_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl (0U)
#  define Rte_InitValue_SysPowerMod_SysPowerMod (0U)
#  define Rte_InitValue_SysPowerModVld_SysPowerModVld (0U)
#  define Rte_InitValue_TranPMode_Sts_TranPMode_Sts (0U)
#  define Rte_InitValue_ppSR_WakeupReason_data (0ULL)
#  define Rte_InitValue_rpSR_AMPDeInitFinished_State (FALSE)
#  define Rte_InitValue_rpSR_GyroDeInitFinished_State (FALSE)
#  define Rte_InitValue_rpSR_RtcDeInitFinished_State (FALSE)
#  define Rte_InitValue_rpSR_SocManager_SystemState (0U)
#  define Rte_InitValue_rpSR_piDiagMonitorReInitFlag_ChangeCounter (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Power_Rc_Cluster_Shutdown_Status_Element(P2VAR(uint8, AUTOMATIC, RTE_POWER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Power_Rc_Wakeup_Reason_WakeupSource(P2VAR(wakeup_type, AUTOMATIC, RTE_POWER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_Request_PowerModeEmergencySleep_requestedMode(BswM_BswMRteShutdownReqMode data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_Request_PowerModeShutdownReq_requestedMode(BswM_BswMRteShutdownReqMode data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_Sd_Cluster_Shutdown_Status_Element(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_ppSR_Power_Out_SystemStateOut(P2CONST(SystemState_RecordType, AUTOMATIC, RTE_POWER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(uint8, RTE_CODE) Rte_Mode_Power_DcmEcuReset_DcmEcuReset(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_POWER_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_POWER_APPL_VAR) Value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_POWER_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_POWER_APPL_VAR) ElapsedValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_ADAU_server_StateToDeInit(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_ADAU_server_StateToInit(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_GW_List_Deinit(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_GW_List_Int(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_Normal_List_Deinit(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_Normal_List_Int(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_SF_List_Deinit(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_SF_List_Int(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Gyro_Init_server_Operation(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_IPC_Init_Server_Operation(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Rtc_Init_server_Operation(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_GateWay_PowerTransfer_Nomal2StandbyCallback(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_GateWay_PowerTransfer_Standby2NomalCallback(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_Nomal_PowerTransfer_Nomal2StandbyCallback(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_Nomal_PowerTransfer_Standby2NomalCallback(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_Safety_PowerTransfer_Nomal2StandbyCallback(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_Safety_PowerTransfer_Standby2NomalCallback(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AWakeHold_DVRRemtCnSts Rte_Read_Power_AWakeHold_DVRRemtCnSts
#  define Rte_Read_Power_AWakeHold_DVRRemtCnSts(data) (*(data) = Rte_Common_GateWay_AWakeHold_DVRRemtCnSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_AntitheftSts_AntitheftSts Rte_Read_Power_AntitheftSts_AntitheftSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_AntitheftSts_AntitheftSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_AwakeHlod_Heartbeat_counter Rte_Read_Power_AwakeHlod_Heartbeat_counter
#  define Rte_Read_Power_AwakeHlod_Heartbeat_counter(data) (*(data) = Rte_Common_GateWay_AwakeHlod_Heartbeat_counter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_CURRENT_GEAR_CURRENT_GEAR Rte_Read_Power_CURRENT_GEAR_CURRENT_GEAR
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_CURRENT_GEAR_CURRENT_GEAR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DrvDoorLockSts_DrvDoorLockSts Rte_Read_Power_DrvDoorLockSts_DrvDoorLockSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_DrvDoorLockSts_DrvDoorLockSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DrvDoorSts_DrvDoorSts Rte_Read_Power_DrvDoorSts_DrvDoorSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_DrvDoorSts_DrvDoorSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Ecum_Set_SystemState_Run_Element Rte_Read_Power_Ecum_Set_SystemState_Run_Element
#  define Rte_Read_Power_Ecum_Set_SystemState_Run_Element(data) (*(data) = Rte_Power_Ecum_Set_SystemState_Run_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_HUD_SwtSts_HUD_SwtSts Rte_Read_Power_HUD_SwtSts_HUD_SwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_HUD_SwtSts_HUD_SwtSts(data) (*(data) = 1U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LvPwrSysErr_LvPwrSysErr Rte_Read_Power_LvPwrSysErr_LvPwrSysErr
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_LvPwrSysErr_LvPwrSysErr(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Rc_BswM_Warm_Reset_Element Rte_Read_Power_Rc_BswM_Warm_Reset_Element
#  define Rte_Read_Power_Rc_BswM_Warm_Reset_Element(data) (*(data) = Rte_BswM_Provide_BswMRteModeRequestPort_ResetType_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_Cluster_Shutdown_Status_Element Rte_Read_Power_Rc_Cluster_Shutdown_Status_Element
#  define Rte_Read_Rc_ResetReason_ResetSource Rte_Read_Power_Rc_ResetReason_ResetSource
#  define Rte_Read_Power_Rc_ResetReason_ResetSource(data) (*(data) = Rte_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_Wakeup_Reason_WakeupSource Rte_Read_Power_Rc_Wakeup_Reason_WakeupSource
#  define Rte_Read_RemoteModSts_RemoteModSts Rte_Read_Power_RemoteModSts_RemoteModSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_RemoteModSts_RemoteModSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SeekDwnAndPageLPress_Timeout_Element Rte_Read_Power_SeekDwnAndPageLPress_Timeout_Element
#  define Rte_Read_Power_SeekDwnAndPageLPress_Timeout_Element(data) (*(data) = Rte_SOCManager_SeekDwnAndPageLPress_Timeout_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl Rte_Read_Power_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SysPowerMod_SysPowerMod Rte_Read_Power_SysPowerMod_SysPowerMod
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_SysPowerMod_SysPowerMod(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SysPowerModVld_SysPowerModVld Rte_Read_Power_SysPowerModVld_SysPowerModVld
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_SysPowerModVld_SysPowerModVld(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TranPMode_Sts_TranPMode_Sts Rte_Read_Power_TranPMode_Sts_TranPMode_Sts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_TranPMode_Sts_TranPMode_Sts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_rpSR_AMPDeInitFinished_State Rte_Read_Power_rpSR_AMPDeInitFinished_State
#  define Rte_Read_Power_rpSR_AMPDeInitFinished_State(data) (*(data) = Rte_AMP_ppSR_AMPDeInitFinished_State, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_GyroDeInitFinished_State Rte_Read_Power_rpSR_GyroDeInitFinished_State
#  define Rte_Read_Power_rpSR_GyroDeInitFinished_State(data) (*(data) = Rte_Gyro_ppSR_GyroDeInitFinished_State, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_RtcDeInitFinished_State Rte_Read_Power_rpSR_RtcDeInitFinished_State
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Power_rpSR_RtcDeInitFinished_State(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_OK))
/* PRQA L:L1 */
#  define Rte_Read_rpSR_SocManager_SystemState Rte_Read_Power_rpSR_SocManager_SystemState
#  define Rte_Read_Power_rpSR_SocManager_SystemState(data) (*(data) = Rte_SOCManager_ppSR_SocManager_SystemState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter Rte_Read_Power_rpSR_piDiagMonitorReInitFlag_ChangeCounter
#  define Rte_Read_Power_rpSR_piDiagMonitorReInitFlag_ChangeCounter(data) (*(data) = Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Ecum_Set_SystemState_Run_Element Rte_Write_Power_Ecum_Set_SystemState_Run_Element
#  define Rte_Write_Power_Ecum_Set_SystemState_Run_Element(data) (Rte_Power_Ecum_Set_SystemState_Run_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IVI_10MIN_Backup_flag_Element Rte_Write_Power_IVI_10MIN_Backup_flag_Element
#  define Rte_Write_Power_IVI_10MIN_Backup_flag_Element(data) (Rte_Power_IVI_10MIN_Backup_flag_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Power_Voltage_Element Rte_Write_Power_Power_Voltage_Element
#  define Rte_Write_Power_Power_Voltage_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Request_PowerModeEmergencySleep_requestedMode Rte_Write_Power_Request_PowerModeEmergencySleep_requestedMode
#  define Rte_Write_Request_PowerModeShutdownReq_requestedMode Rte_Write_Power_Request_PowerModeShutdownReq_requestedMode
#  define Rte_Write_Request_PowerVolEnable_requestedMode Rte_Write_Power_Request_PowerVolEnable_requestedMode
#  define Rte_Write_Power_Request_PowerVolEnable_requestedMode(data) (Rte_Power_Request_PowerVolEnable_requestedMode = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_BswM_Warm_Reset_Element Rte_Write_Power_Sd_BswM_Warm_Reset_Element
#  define Rte_Write_Power_Sd_BswM_Warm_Reset_Element(data) (Rte_Power_Sd_BswM_Warm_Reset_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_Cluster_Shutdown_Status_Element Rte_Write_Power_Sd_Cluster_Shutdown_Status_Element
#  define Rte_Write_ppSR_Power_Out_SystemStateOut Rte_Write_Power_ppSR_Power_Out_SystemStateOut
#  define Rte_Write_ppSR_WakeupReason_data Rte_Write_Power_ppSR_WakeupReason_data
#  define Rte_Write_Power_ppSR_WakeupReason_data(data) (Rte_Power_ppSR_WakeupReason_data = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_DcmEcuReset_DcmEcuReset Rte_Mode_Power_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_ComEx_GetRxE2EStatus Rte_Call_Power_ComEx_GetRxE2EStatus
#  define Rte_Call_ComEx_SendSignal Rte_Call_Power_ComEx_SendSignal
#  define Rte_Call_Os_Service_GetCounterValue Rte_Call_Power_Os_Service_GetCounterValue
#  define Rte_Call_Os_Service_GetElapsedValue Rte_Call_Power_Os_Service_GetElapsedValue


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_ADAU_server_StateToDeInit Rte_Call_Power_ADAU_server_StateToDeInit
#  define Rte_Call_ADAU_server_StateToInit Rte_Call_Power_ADAU_server_StateToInit
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComEx_ReceiveSignal ComEx_ReceiveSignal
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetCurrentComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_GetCurrentComMode(arg1) (ComM_GetCurrentComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetMaxComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_GetMaxComMode(arg1) (ComM_GetMaxComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetRequestedComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_GetRequestedComMode(arg1) (ComM_GetRequestedComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Common_GW_List_Deinit Rte_Call_Power_Common_GW_List_Deinit
#  define Rte_Call_Common_GW_List_Int Rte_Call_Power_Common_GW_List_Int
#  define Rte_Call_Common_Normal_List_Deinit Rte_Call_Power_Common_Normal_List_Deinit
#  define Rte_Call_Common_Normal_List_Int Rte_Call_Power_Common_Normal_List_Int
#  define Rte_Call_Common_SF_List_Deinit Rte_Call_Power_Common_SF_List_Deinit
#  define Rte_Call_Common_SF_List_Int Rte_Call_Power_Common_SF_List_Int
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_ResetEventStatus(Dem_EventIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DTCB12764B_OverTemperature_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)21)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DTCB12764B_OverTemperature_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)21, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTCD10016_UnderVoltage_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)126)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTCD10016_UnderVoltage_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)126, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTCD10017_OverVoltage_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)75)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTCD10017_OverVoltage_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)75, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Temperature_SensorError_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)194, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_Gyro_Init_server_Operation Rte_Call_Power_Gyro_Init_server_Operation
#  define Rte_Call_IPC_Init_Server_Operation Rte_Call_Power_IPC_Init_Server_Operation
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetVoltage(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_VAR_NOINIT) Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAb_Interface_GetVoltage IoHwAb_GetVoltage
#  define Rte_Call_Rtc_Init_server_Operation Rte_Call_Power_Rtc_Init_server_Operation
#  define RTE_START_SEC_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType CPID); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_WdgM_AliveSupervision_SystemState_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_rcCS_Common_GateWay_PowerTransfer_Nomal2StandbyCallback Rte_Call_Power_rcCS_Common_GateWay_PowerTransfer_Nomal2StandbyCallback
#  define Rte_Call_rcCS_Common_GateWay_PowerTransfer_Standby2NomalCallback Rte_Call_Power_rcCS_Common_GateWay_PowerTransfer_Standby2NomalCallback
#  define Rte_Call_rcCS_Common_Nomal_PowerTransfer_Nomal2StandbyCallback Rte_Call_Power_rcCS_Common_Nomal_PowerTransfer_Nomal2StandbyCallback
#  define Rte_Call_rcCS_Common_Nomal_PowerTransfer_Standby2NomalCallback Rte_Call_Power_rcCS_Common_Nomal_PowerTransfer_Standby2NomalCallback
#  define Rte_Call_rcCS_Common_Safety_PowerTransfer_Nomal2StandbyCallback Rte_Call_Power_rcCS_Common_Safety_PowerTransfer_Nomal2StandbyCallback
#  define Rte_Call_rcCS_Common_Safety_PowerTransfer_Standby2NomalCallback Rte_Call_Power_rcCS_Common_Safety_PowerTransfer_Standby2NomalCallback


# endif /* !defined(RTE_CORE) */


# define Power_START_SEC_CODE
# include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17 EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17
#  define RTE_RUNNABLE_Power_MainFunction Power_MainFunction
#  define RTE_RUNNABLE_power_Init power_Init
# endif

FUNC(void, Power_CODE) EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17(P2VAR(EOL_Struct_3Element, AUTOMATIC, RTE_POWER_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Power_CODE) Power_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Power_CODE) power_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Power_STOP_SEC_CODE
# include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_ComM_UserRequest_E_MODE_LIMITATION (2U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_IoHwAb_Interface_E_NOT_OK (1U)

#  define RTE_E_Os_Service_E_OK (0U)

#  define RTE_E_Os_Service_E_OS_ID (3U)

#  define RTE_E_Os_Service_E_OS_VALUE (8U)

#  define RTE_E_WdgM_AliveSupervision_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_POWER_H */

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
