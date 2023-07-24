/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  AMP.c
 *           Config:  D:/Workspace/Project_gwm_v3.5_dev_byme/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  AMP
 *  Generation Time:  2021-05-15 17:12:28
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <AMP>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dem_DTCFormatType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_DebounceResetStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_UdsStatusByteType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TimeInMicrosecondsType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 *
 * Operation Prototypes:
 * =====================
 * GetCounterValue of Port Interface Os_Service
 *   This service reads the current count value of a counter (returning either the hardware timer ticks if counter is driven by hardware or the software ticks when user drives counter).
 *
 * GetElapsedValue of Port Interface Os_Service
 *   This service gets the number of ticks between the current tick value and a previously read tick value.
 *
 *********************************************************************************************************************/

#include "Rte_AMP.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "AMP.h"
#include "AMP_Cfg.h"
#include "AMP_DTC.h"
#include "Logger_Cfg.h"
#include "logger.h"
#include "AMP_StartUp.h"
#include "AMP_Normal.h"
#include "AMP_Common.h"
#include "AMP_ShutDown.h"
#include "AMP_LCCalib.h"



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


static void AMP_Ipc_Init(void);
static void AMP_Debug_Info(void);
static void AMPSM_Main(uint8 dev_id);
static void AMPDeviceStsTransfer(uint8 dev_id);


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"


#define AMP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"


extern I2C_AMPReq_t I2C_Req_AMPData[DEVICE_NUM];

s_AMP_State_Type AMP_State_Data[DEVICE_NUM];

static IPC_S2M_AudioAMPGetStartupDiagResult_t GetAMPStartupDiagResult;
static IPC_S2M_AudioAMPAudioDriverReady_t audioAudioDriverReady;
static IPC_S2M_AudioAMPAmpFastMuteNotify_t FastMuteNotify;
static IPC_S2M_AudioAMPAmpGainSet_t AmpGainSet;
static IPC_S2M_AudioAMPPWMSet_t AmpPwmSet;
static IPC_S2M_AudioAMPAudioGet_t AudioGet;
static IPC_S2M_AudioAMPSOC_to_MCU_ACK_t soc_to_mcu_ack;
static boolean AMPRun = FALSE;


#define AMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Rte_DT_AVASDTCRet_0: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_1: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_2: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_3: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_4: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_5: Integer in interval [0...255]
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_DTCFormatType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_DebounceResetStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DEBOUNCE_STATUS_FREEZE (0U)
 *   DEM_DEBOUNCE_STATUS_RESET (1U)
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
 *   DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED (5U)
 *   DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED (6U)
 *   DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED (7U)
 *   DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED (8U)
 * Dem_UdsStatusByteType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_UDS_STATUS_TF (1U)
 *   DEM_UDS_STATUS_TF_BflMask 1U (0b00000001)
 *   DEM_UDS_STATUS_TF_BflPn 0
 *   DEM_UDS_STATUS_TF_BflLn 1
 *   DEM_UDS_STATUS_TFTOC (2U)
 *   DEM_UDS_STATUS_TFTOC_BflMask 2U (0b00000010)
 *   DEM_UDS_STATUS_TFTOC_BflPn 1
 *   DEM_UDS_STATUS_TFTOC_BflLn 1
 *   DEM_UDS_STATUS_PDTC (4U)
 *   DEM_UDS_STATUS_PDTC_BflMask 4U (0b00000100)
 *   DEM_UDS_STATUS_PDTC_BflPn 2
 *   DEM_UDS_STATUS_PDTC_BflLn 1
 *   DEM_UDS_STATUS_CDTC (8U)
 *   DEM_UDS_STATUS_CDTC_BflMask 8U (0b00001000)
 *   DEM_UDS_STATUS_CDTC_BflPn 3
 *   DEM_UDS_STATUS_CDTC_BflLn 1
 *   DEM_UDS_STATUS_TNCSLC (16U)
 *   DEM_UDS_STATUS_TNCSLC_BflMask 16U (0b00010000)
 *   DEM_UDS_STATUS_TNCSLC_BflPn 4
 *   DEM_UDS_STATUS_TNCSLC_BflLn 1
 *   DEM_UDS_STATUS_TFSLC (32U)
 *   DEM_UDS_STATUS_TFSLC_BflMask 32U (0b00100000)
 *   DEM_UDS_STATUS_TFSLC_BflPn 5
 *   DEM_UDS_STATUS_TFSLC_BflLn 1
 *   DEM_UDS_STATUS_TNCTOC (64U)
 *   DEM_UDS_STATUS_TNCTOC_BflMask 64U (0b01000000)
 *   DEM_UDS_STATUS_TNCTOC_BflPn 6
 *   DEM_UDS_STATUS_TNCTOC_BflLn 1
 *   DEM_UDS_STATUS_WIR (128U)
 *   DEM_UDS_STATUS_WIR_BflMask 128U (0b10000000)
 *   DEM_UDS_STATUS_WIR_BflPn 7
 *   DEM_UDS_STATUS_WIR_BflLn 1
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_ServiceIdType: Enumeration of integer in interval [6...12] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 * Rte_DT_SystemState_RecordType_0: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_Cluster_OFF (0U)
 *   SYSTEMSTATE_Cluster_STANDBY (1U)
 *   SYSTEMSTATE_Cluster_ON (2U)
 *   SYSTEMSTATE_Cluster_STARTUP (3U)
 *   SYSTEMSTATE_Cluster_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_1: Enumeration of integer in interval [0.0...255] with enumerators
 *   SYSTEMSTATE_IVI_OFF (0U)
 *   SYSTEMSTATE_IVI_STANDBY (1U)
 *   SYSTEMSTATE_IVI_ON (2U)
 *   SYSTEMSTATE_IVI_SHUTDOWN (3U)
 *   SYSTEMSTATE_IVI_ON_NORMAL (5U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (6U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (7U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (8U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (9U)
 *   SYSTEMSTATE_IVI_REMOTE (4U)
 * Rte_DT_SystemState_RecordType_2: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_HUD_OFF (0U)
 *   SYSTEMSTATE_HUD_STANDBY (1U)
 *   SYSTEMSTATE_HUD_ON (2U)
 *   SYSTEMSTATE_HUD_STARTUP (3U)
 *   SYSTEMSTATE_HUD_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_3: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_CONSOLE_OFF (0U)
 *   SYSTEMSTATE_CONSOLE_STANDBY (1U)
 *   SYSTEMSTATE_CONSOLE_ON (2U)
 *   SYSTEMSTATE_CONSOLE_STARTUP (3U)
 *   SYSTEMSTATE_CONSOLE_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_4: Enumeration of integer in interval [0...255] with enumerators
 *   KL15OFF (0U)
 *   KL15ON (1U)
 * Rte_DT_SystemState_RecordType_5_0: Enumeration of integer in interval [0...255] with enumerators
 *   VOLTAGE_OUT_LOWSLEEP (0U)
 *   VOLTAGE_OUT_NORMAL (1U)
 *   VOLTAGE_OUT_HIGHALARM (2U)
 *   VOLTAGE_OUT_HIGHSLEEP (3U)
 *   VOLTAGE_OUT_LOWALARM (4U)
 *   VOLTAGE_OUT_NUM (5U)
 * Rte_DT_SystemState_RecordType_6: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_SP_OFF (0U)
 *   SYSTEMSTATE_SP_SHUTDOWN (1U)
 *   SYSTEMSTATE_SP_STANDBY (2U)
 *   SYSTEMSTATE_SP_SOCOFF (3U)
 * Rte_DT_SystemState_RecordType_7_0: Enumeration of integer in interval [0...255] with enumerators
 *   TEMP_LOW_SLEEP (0U)
 *   TEMP_NORMAL (1U)
 *   TEMP_HIGH_PROTECT (2U)
 *   TEMP_HIGH_SLEEP (3U)
 *   TEMP_STATE_NUM (4U)
 *   TEMP_STATE_INIT (255U)
 *
 * Array Types:
 * ============
 * A_U8_10: Array with 10 element(s) of type uint8
 * A_u8_20: Array with 20 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * EOL9Bytes: Array with 9 element(s) of type uint8
 * EOL_4Bytes: Array with 4 element(s) of type Rte_DT_EOL_4Bytes_0
 * Rte_DT_EOL_4Bytes_0: Array with 1 element(s) of type uint8
 * VconfigKind_400Bytes: Array with 400 element(s) of type uint8
 *
 * Record Types:
 * =============
 * AVASDTCRet: Record with elements
 *   Open of type Rte_DT_AVASDTCRet_0
 *   ShortAcross of type Rte_DT_AVASDTCRet_1
 *   ShorttoGND of type Rte_DT_AVASDTCRet_2
 *   Clip of type Rte_DT_AVASDTCRet_3
 *   OutofRange of type Rte_DT_AVASDTCRet_4
 *   ShorttoBAT of type Rte_DT_AVASDTCRet_5
 * Rte_DT_SystemState_RecordType_5: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_5_0
 *   value of type Rte_DT_SystemState_RecordType_5_1
 * Rte_DT_SystemState_RecordType_7: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_7_0
 *   temperature of type Rte_DT_SystemState_RecordType_7_1
 * SystemState_RecordType: Record with elements
 *   ClusterState of type Rte_DT_SystemState_RecordType_0
 *   IVIState of type Rte_DT_SystemState_RecordType_1
 *   HUDState of type Rte_DT_SystemState_RecordType_2
 *   ConsoleState of type Rte_DT_SystemState_RecordType_3
 *   KL15State of type Rte_DT_SystemState_RecordType_4
 *   s_PowerVoltage of type Rte_DT_SystemState_RecordType_5
 *   SP_State of type Rte_DT_SystemState_RecordType_6
 *   s_TempVoltage of type Rte_DT_SystemState_RecordType_7
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_NvBlockNeed_LC_Calibration2_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_u8_20
 *   uint8 *Rte_Pim_NvBlockNeed_LC_Calibration_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_u8_20
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_NvBlockNeed_LC_Calibration2_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_u8_20
 *   uint8 *Rte_CData_NvBlockNeed_LC_Calibration_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_u8_20
 *
 *********************************************************************************************************************/


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AMP_EOL_Read_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <AMP_EOL_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AMP_EOL_Read_Operation(uint8 *value)
 *     Argument value: uint8* is of type A_U8_10
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AMP_EOL_Read_N_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AMP_EOL_Read_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, AMP_CODE) AMP_EOL_Read_Operation(P2VAR(uint8, AUTOMATIC, RTE_AMP_APPL_VAR) value) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AMP_EOL_Read_Operation (returns application error)
 *********************************************************************************************************************/
    A_U8_10 EOLReport;
    EOLDataReport(&EOLReport);
    (void)memcpy(value,&EOLReport,sizeof(A_U8_10));
    if( AMODIAGCALIB_NOTCALIB == EOLReport[0] )
    {
        return E_NOT_OK;
    }
    else
    {
        return E_OK;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AMP_Event_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Element> of PortPrototype <Rc_AMP_Notify_Message>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rc_AMP_Notify_Message_Element(uint8 *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DTC9A0101_FLShortAcross_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0101_FLShortAcross_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0111_FLShortToGND_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0111_FLShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0112_FLShorttoBAT_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0112_FLShorttoBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0113_FLOpen_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0113_FLOpen_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A011E_FLResistanceOutRange_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A011E_FLResistanceOutRange_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0125_FLOutputClip_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0125_FLOutputClip_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0201_FRShortAcross_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0201_FRShortAcross_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0211_FRShortToGND_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0211_FRShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0212_FRShorttoBAT_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0212_FRShorttoBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0213_FROpen_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0213_FROpen_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A021E_FRResistanceOutRange_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A021E_FRResistanceOutRange_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0225_FROutputClip_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0225_FROutputClip_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0301_RLShortAcross_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0301_RLShortAcross_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0311_RLShortToGND_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0311_RLShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0312_RLShorttoBAT_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0312_RLShorttoBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0313_RLOpen_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0313_RLOpen_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A031E_RLResistanceOutRange_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A031E_RLResistanceOutRange_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0325_RLOutputClip_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0325_RLOutputClip_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0401_RRShortAcross_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0401_RRShortAcross_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0411_RRShortToGND_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0411_RRShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0412_RRShorttoBAT_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0412_RRShorttoBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0413_RROpen_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0413_RROpen_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A041E_RRResistanceOutRange_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A041E_RRResistanceOutRange_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0425_RROutputClip_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0425_RROutputClip_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0501_CenterShortAcross_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0501_CenterShortAcross_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0511_CneterShortToGND_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0511_CneterShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0512_CenterShorttoBAT_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0512_CenterShorttoBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0513_CenterOpen_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0513_CenterOpen_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A051E_CenterResistanceOutRange_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A051E_CenterResistanceOutRange_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0525_CenterOutputClip_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0525_CenterOutputClip_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0601_WooferShortAcross_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0601_WooferShortAcross_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0611_WooferShortToGND_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0611_WooferShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0612_WooferShorttoBAT_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0612_WooferShorttoBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0613_WooferOpen_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0613_WooferOpen_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A061E_WooferResistanceOutRange_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A061E_WooferResistanceOutRange_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0625_WooferOutputClip_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0625_WooferOutputClip_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0701_AVASShortAcross_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0711_AVASShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0712_AVASShorttoBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0713_AVASOpen_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A071E_AVASResistanceOutRange_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC9A0725_AVASOutputClip_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID
 *   Std_ReturnType Rte_Call_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID, RTE_E_Os_Service_E_OS_VALUE
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AMP_Event_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AMP_CODE) AMP_Event_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AMP_Event_MainFunction
 *********************************************************************************************************************/
    uint8 event = 0;
    IPC_M2S_AudioAMPMCU_To_SOC_ACK_t FastmuteACK;

    (void)Rte_Read_Rc_AMP_Notify_Message_Element(&event);

    switch (event)
    {
        case AMP_HWMUTE_EVENT:
            if(VCONFIG_BOTHAMP == AMPDevVCfg)
            {
                AMP_HWMuteOperate(DEVICE_AMP1,FastMuteNotify.MuteOnOff);
                AMP_HWMuteOperate(DEVICE_AMP2,FastMuteNotify.MuteOnOff);
            }
            else if(VCONFIG_BOTHAMP > AMPDevVCfg)
            {
                AMP_HWMuteOperate(AMPDevVCfg,FastMuteNotify.MuteOnOff);
            }
			else
			{
				/* do nothing */
			}
            FastmuteACK.major_msg_id = IPC_S2M_AUDIO_MSGMAJOR_AMP_ID;
            FastmuteACK.ACK = ACK_OK;
            FastmuteACK.sub_msg_id = IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_ID;
            /*if audio not receive after send ipc 200ms, aduio will retry.so not need check */
            (void)IPC_M2S_AudioAMPMCU_To_SOC_ACK_Transmit(&FastmuteACK);

            break;
        case AMP_STARTDIAGRESULT_EVENT:
            AMPSendAudioStartupResult();

            break;
        case AMP_SOC_MCU_EVENT:
            if (IPC_M2S_AUDIO_AMP_MSGSUB_AMP1PERIODDIAGRESULTS_ID == soc_to_mcu_ack.sub_msg_id)
            {
                AMPIPCReceiveACK(DEVICE_AMP1);
            }
            else if(IPC_M2S_AUDIO_AMP_MSGSUB_AMP2PERIODDIAGRESULTS_ID == soc_to_mcu_ack.sub_msg_id)
            {
                AMPIPCReceiveACK(DEVICE_AMP2);
            }

            break;
        default:
			/* do nothing */
            break;
    }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AMP_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EOL_AMPCalibration_AMPCalibration(uint16 *data)
 *   Std_ReturnType Rte_Read_Vconfig_KindBuffers_400bytes_VconfigKind_400Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_400Bytes
 *   Std_ReturnType Rte_Read_rpSR_Power_Out_SystemStateOut(SystemState_RecordType *data)
 *   Std_ReturnType Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter(uint32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_Sd_IIC0_Notify_Message_Message(uint16 data)
 *   Std_ReturnType Rte_Write_AVASDTCResults_AVASDTC(const AVASDTCRet *data)
 *   Std_ReturnType Rte_Write_EOL_AMPCalibrationRece_EOLReceive(const uint8 *data)
 *     Argument data: uint8* is of type A_U8_10
 *   Std_ReturnType Rte_Write_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(const uint8 *data)
 *     Argument data: uint8* is of type EOL9Bytes
 *   Std_ReturnType Rte_Write_Sd_AMP_Notify_Message_Element(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_AMPDeInitFinished_State(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AMP_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AMP_CODE) AMP_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AMP_MainFunction
 *********************************************************************************************************************/
    if(VCONFIG_NONE != AMPDevVCfg)
    {
        if(TRUE == AMPRun)
        {
            AMPDiag_LCCalibLogic();
            if(VCONFIG_BOTHAMP == AMPDevVCfg)
            {
                AMPSM_Main(DEVICE_AMP1);
                AMPSM_Main(DEVICE_AMP2);
            }
            else if(VCONFIG_BOTHAMP > AMPDevVCfg)
            {
                AMPSM_Main(AMPDevVCfg);
            }
			else
			{
				/* do nothing */
			}
        }
    }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EOL_Get_SpeakerStatus_0xFDD2> of PortPrototype <EOL_Get_SpeakerStatus_0xFDD2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_4Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AMP_CODE) EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(P2VAR(uint8, AUTOMATIC, RTE_AMP_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2
 *********************************************************************************************************************/
    uint8 array[4] = {0u};
    AMP_EOLSpeakerSts(array,4);
    (void)memcpy(arg,array,4u);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvBlockNeed_LC_Calibration2_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_LC_Calibration2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvBlockNeed_LC_Calibration2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockNeed_LC_Calibration2_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AMP_CODE) NvBlockNeed_LC_Calibration2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockNeed_LC_Calibration2_JobFinished
 *********************************************************************************************************************/
if(NVM_WRITE_BLOCK == ServiceId)
{
    if(E_OK == JobResult)
    {
        /*write job success*/
        LCCalibNVMWriteDone(DEVICE_AMP2);
    }
    else
    {
        /*write Fail, start retry process*/
    }
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvBlockNeed_LC_Calibration_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_LC_Calibration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvBlockNeed_LC_Calibration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockNeed_LC_Calibration_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AMP_CODE) NvBlockNeed_LC_Calibration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockNeed_LC_Calibration_JobFinished
 *********************************************************************************************************************/
    if(NVM_WRITE_BLOCK == ServiceId)
    {
        if(E_OK == JobResult)
        {
            /*write job success*/
            LCCalibNVMWriteDone(DEVICE_AMP1);
        }
        else
        {
            /*write fail, start retry process*/
        }
    }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPChilpInit(uint8 dev_id) 
{
    AMP_State_Data[dev_id].DeviceState = AMP_STARTUP;
    AMP_State_Data[dev_id].NextState = AMP_STARTUP;
    AMP_State_Data[dev_id].Major_State = (uint8)Startup_Idle;
    AMP_CommonInit(dev_id);
    AMP_StartUpInit(dev_id);
    AMP_NormalInit(dev_id);
    AMP_DTCInit(dev_id);
    LCCalib_Init(dev_id);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
FUNC(void, AMP_CODE) AMP_Init(void)  
{
    AMP_CfgMain();
    AMP_Ipc_Init();
	AMP_ShutDownInit();
    AMPChilpInit(DEVICE_AMP1);
    AMPChilpInit(DEVICE_AMP2);
    AMPRun = TRUE;
    (void)amp_warn("InitCalled Ver06 CfgVer220402");
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_Ipc_Init(void)
{
    (void)memset(&GetAMPStartupDiagResult, 0, sizeof(IPC_S2M_AudioAMPGetStartupDiagResult_t));
    (void)memset(&audioAudioDriverReady, 0, sizeof(IPC_S2M_AudioAMPAudioDriverReady_t));
    (void)memset(&soc_to_mcu_ack, 0, sizeof(IPC_S2M_AudioAMPSOC_to_MCU_ACK_t));
    (void)memset(&FastMuteNotify, 0, sizeof(IPC_S2M_AudioAMPAmpFastMuteNotify_t));
    (void)memset(&AmpGainSet, 0, sizeof(IPC_S2M_AudioAMPAmpGainSet_t));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_ReceiveIPCData(uint8 Major_msg_id, uint8 Sub_msg_id, uint8 * param, uint16_t param_len)
{
	(void)param_len;
    if (IPC_S2M_AUDIO_MSGMAJOR_AMP_ID == Major_msg_id)
    {
        IPC_S2M_AudioAMPGWMTest_t GWMTestSetData;
        switch (Sub_msg_id)
        {
            case IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_ID:
                IPC_S2M_AudioAMPAudioDriverReady_Receive(param, &audioAudioDriverReady,
                     IPC_S2M_AUDIO_AMP_MSGSUB_AUDIODRIVERREADY_LENGTH);
                /*do nthing , no use this ipc */
                break;

            case IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_ID:
                IPC_S2M_AudioAMPGetStartupDiagResult_Receive(param, &GetAMPStartupDiagResult,
                     IPC_S2M_AUDIO_AMP_MSGSUB_GETSTARTUPDIAGRESULT_LENGTH);
                (void)Rte_Write_Sd_AMP_Notify_Message_Element(AMP_STARTDIAGRESULT_EVENT);
                break;

            case IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_ID:
                IPC_S2M_AudioAMPSOC_to_MCU_ACK_Receive(param, &soc_to_mcu_ack,
                     IPC_S2M_AUDIO_AMP_MSGSUB_SOC_TO_MCU_ACK_LENGTH);
                (void)Rte_Write_Sd_AMP_Notify_Message_Element(AMP_SOC_MCU_EVENT);
                break;

            case IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_ID:
                IPC_S2M_AudioAMPAmpFastMuteNotify_Receive(param, &FastMuteNotify,
                     IPC_S2M_AUDIO_AMP_MSGSUB_AMPFASTMUTENOTIFY_LENGTH);
                (void)Rte_Write_Sd_AMP_Notify_Message_Element(AMP_HWMUTE_EVENT);
                break;

            case IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_ID:
                    IPC_S2M_AudioAMPAmpGainSet_Receive(param, &AmpGainSet, IPC_S2M_AUDIO_AMP_MSGSUB_AMPGAINSET_LENGTH);
                    AMP_AudioSetGain((S_AmpGainSet_Type *)(void *)(&AmpGainSet));
                    (void)AMPNormalBuf_Insert(AmpGainSet.DeviceId, (uint8)NORMALAMPSET_GAIN);
                break;
            case IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_ID:
                IPC_S2M_AudioAMPPWMSet_Receive(param,&AmpPwmSet,IPC_S2M_AUDIO_AMP_MSGSUB_PWMSET_LENGTH);
                AMP_TunerSetPwmValue(AmpPwmSet.DividerSetting);
                if(VCONFIG_BOTHAMP == AMPDevVCfg)
                {
                    (void)AMPNormalBuf_Insert(DEVICE_AMP1, (uint8)NORMALAMP_CHANGEPWM);
                    (void)AMPNormalBuf_Insert(DEVICE_AMP1, (uint8)NORMALAMP_CHANGEPWM);
                    (void)AMPNormalBuf_Insert(DEVICE_AMP2, (uint8)NORMALAMP_CHANGEPWM);
                    (void)AMPNormalBuf_Insert(DEVICE_AMP2, (uint8)NORMALAMP_CHANGEPWM);
                }
                else if(VCONFIG_BOTHAMP > AMPDevVCfg)
                {
                    (void)AMPNormalBuf_Insert(AMPDevVCfg, (uint8)NORMALAMP_CHANGEPWM);
                    (void)AMPNormalBuf_Insert(AMPDevVCfg, (uint8)NORMALAMP_CHANGEPWM);
                }
				else
				{
					/* do nothing */
				}
                break;
            case IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_ID:
                IPC_S2M_AudioAMPAudioGet_Receive(param,&AudioGet,IPC_S2M_AUDIO_AMP_MSGSUB_AUDIOGET_LENGTH);
                if((VCONFIG_BOTHAMP == AMPDevVCfg) || (AMPDevVCfg == AudioGet.DeviceID))
                {
                    AMP_Debug_Info();
                }
                break;
            case IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_ID:
                IPC_S2M_AudioAMPGWMTest_Receive(param,&GWMTestSetData,IPC_S2M_AUDIO_AMP_MSGSUB_GWMTEST_LENGTH);
                AMPClipParSet(&GWMTestSetData);
                break;
            default:
				/* do nothing */
                break;
        }
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Std_ReturnType AMP_CDDInit(void)
{
      Std_ReturnType ret = RTE_E_OK;
      AMP_Init();
      return ret;
}

/***********************************************************************
 * @brief       : recover IIC idle & 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_Debug_Info(void)
{
    if(1u == AudioGet.cmd)
    {
        (void)AMPNormalBuf_Insert(AudioGet.DeviceID, (uint8)DEBUGAMPGET_DEVICESTATE);
    }
    else if(2u == AudioGet.cmd)
    {
        (void)AMPNormalBuf_Insert(AudioGet.DeviceID, (uint8)DEBUGAMPGET_CHANNELSTATE);
    }
}

/***********************************************************************
 * @brief       : AMP Main StateMachine
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPSM_Main(uint8 dev_id)
{
    AMPDeviceStsTransfer(dev_id);
    switch(AMP_State_Data[dev_id].DeviceState)
    {
        case AMP_STARTUP:
            AMP_StartupMainLogic(dev_id);
            break;
        case AMP_NORMAL:
            AMP_NormalMainLogic(dev_id);
            break;
        case AMP_LCCALIB:
            (void)LCCalib_MainLogic(dev_id);
            break;
        case AMP_SHUTDOWN:
            (void)AMP_ShutDownMainLogic(dev_id);
            break;
        case AMP_OFF:
            break;
        default:
        	/* do nothing */
            break;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDeviceStsTransfer(uint8 dev_id) 
{
    if((I2C_Req_AMPData[dev_id].Sts == I2C_Req_Idle) && (AMP_State_Data[dev_id].DeviceState != AMP_State_Data[dev_id].NextState))
    {
        AMP_State_Data[dev_id].DeviceState = AMP_State_Data[dev_id].NextState;
        AMP_State_Data[dev_id].Major_State = 0u;
        AMP_State_Data[dev_id].Sub_State = 0u;
    }
}


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
