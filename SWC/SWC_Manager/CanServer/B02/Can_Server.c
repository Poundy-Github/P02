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
 *             File:  Can_Server.c
 *           Config:  D:/Code_Project/Vector35_02_07/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Can_Server
 *  Generation Time:  2021-02-07 09:47:45
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Can_Server>
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
 * KL30BRelaySts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RemoteModSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * SysPowerMod
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SysPowerModVld
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * wakeup_type
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 *********************************************************************************************************************/

#include "Rte_Can_Server.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Com_Types.h"
#include "Compiler_Cfg.h"
#include "Compiler.h"
#include "Com_Cfg.h"
#include "ComM.h"
#include "CanIf.h"
#include "ComNoAction.h"
#include "ComStack_Types.h"
#include "logger.h"
#include "CanSM.h"
#include "CanNm.h"
#include "VConfig_Cfg.h"
#include "CanSM_BswM.h"
#include "CanSM_ComM.h"
#include "ComEx_Cfg.h"
#include "ComEx.h"
#include "MissingDTC_Cfg.h"
#include "NetStatus.h"
#include "SystemState_IVI_Condition.h"


#define  DISABLE_PDU_NUMBER                             (1u)
#define  DISABLE_RX_PDU_NUMBER                          (4u)
#define  CanServer_Disable_Rx_PDU_Number()              (4u)
#define  Com_IPduEnable_VarPtr()                        (Com_Disable_CurrentRxPdu_Record)
#define  Com_IPduEnable_VarCfgPtr()                     (Com_Disable_RxPdu_Receive_Cfg)
#define  Com_SetRxPduEnableFlag(index,value)            ((Com_Disable_CurrentRxPdu_Record.RxPduEnableFlag[index]) = (value))
#define  Com_GetRxPduEnableFlag(index)                  (Com_Disable_CurrentRxPdu_Record.RxPduEnableFlag[index])

extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length);

extern CanFrameCounterType ABS3_counter;
extern CanFrameCounterType ESP_FD2_counter;
extern CanFrameCounterType ECM2_counter;

typedef uint16        Com_RxPduId_Type;
typedef uint16        Com_RxPduId_Map_CanId_Type;
typedef boolean       Com_RxPduId_EnableType;
typedef uint16        CanIdType;
typedef uint16        Com_RxPdu_SizeOfType;

typedef struct Com_Disable_Pdu_SendorReceive_Tag
{
    uint16     TxPduId[DISABLE_PDU_NUMBER];
}Com_Disable_Pdu_SendorReceive_Info;

typedef struct Com_Disable_RxPdu_Receive_Tag
{
    Com_RxPduId_Type            RxPduId[DISABLE_RX_PDU_NUMBER];
    Com_RxPduId_EnableType      RxPduEnableFlag[DISABLE_RX_PDU_NUMBER];
    Com_RxPduId_Map_CanId_Type  RxPduMapCanId[DISABLE_RX_PDU_NUMBER];
}Com_Disable_RxPdu_Receive_Info;

typedef struct SecOCBusOffInfo_Tag
{
   boolean BusOffStatusFlag;
}SecOCBusOff;

typedef struct CANFormatErrCfgInfo_Tag
{
   uint32  CANChanErrFlagRegisterAddr;
   uint32  CANChanFormatErrMask;
   uint8   CANChanNum;
   boolean CAN3FormatErrFlag;
}CANFormatErrCfgInfo;

static SecOCBusOff SecOCBusOffReocrd = 
{
   (boolean)FALSE,
};

static uint8 ChangeCounter_0x14 = 0;
static const Com_Disable_Pdu_SendorReceive_Info Com_Disable_Pdu_SendorReceive_Cfg = 
{
    {0x19}, //HUT40
};

static const Com_Disable_RxPdu_Receive_Info Com_Disable_RxPdu_Receive_Cfg = 
{
    /*CSA1  CSA3   BCM6   BCM11*/
    {
		ComConf_ComIPdu_CSA1_oB30_for_SC_CAN_V3_2_bec912dc_Rx,
		ComConf_ComIPdu_CSA3_oB30_for_SC_CAN_V3_2_9099db5c_Rx,
		0xFFFF,
		0xFFFF
	}, //PduId in Com Layer
    {FALSE, FALSE, FALSE, FALSE},  //Pdu receive status
    {0x165, 0x244, 0x28C, 0x305},  //CanId
};

Com_Disable_RxPdu_Receive_Info Com_Disable_CurrentRxPdu_Record = {0x00};

#define       NOACKINGADERRMASK                            ((uint8)0x04)
#define       ERR_PASSIVE_MASK                             ((uint8)0x04)
#define       CAN_FORMATERR_NUMBER                         (1u)
#define       DIAG_SYSTEM_POWER_MODE                       (2u)
/*! Avoid warnings of unused API parameters */
#define       CAN_SERVER_IGNORE_UNREF_PARAM(param)         ((void)(param))

#define  	  OVER_VOLTAGE_VALUE							(1600)
#define  	  OVER_VOLTAGE_RECOVER_VALUE					(1500)
#define  	  UNDER_VOLTAGE_VALUE							(900)
#define  	  UNDER_VOLTAGE_RECOVER_VALUE					(1000)
#define		  NM_RMS_FLAG_INDEX								0
#define		  NM_WAKEUP_REASON_INDEX						1
#define	      NM_STAY_AWAKE_REASON_INDEX					2
#define		  NM_SYSTEM_INFORMATION_INDEX					3

#define 	  NM_WKSOURCE_CAN 								(32uL) 
#define 	  NM_WKSOURCE_POWER 							(1uL) 
#define	 	  NM_EcuMWakeupSource_POWER_OFFSET				0
#define	 	  NM_EcuMWakeupSource_CAN_OFFSET				5

#define		  NM_BIT0										(0x01)
#define		  NM_BIT1										(0x01<<1)
#define		  NM_BIT2										(0x01<<2)
#define		  NM_CLEAR_BITS									(0x00)

#define       BUSOFF_REPORT_CYC                              200u
/* can format error cfg information*/
const static CANFormatErrCfgInfo CANFormatErrCfgInfoRecord[CAN_FORMATERR_NUMBER] = 
{
    /* Channel Error Flag Register Address, Format Error mask, Can Cannel Num, format error flag */
    {  0xFFD0003C,                          0x00000200,        3,              FALSE}, //CAN3
};

static boolean ErrorTimeCnt = FALSE;

extern FUNC(void, COM_APPL_CODE) SECOC_PDU_Message_ReqSet(boolean flag);
static FUNC(void, Can_Server_CODE) CanServer_FormatErrorHandle(void);
static FUNC(void , Can_Server_CODE) CanServer_Service0x14_Discovery(void);
static FUNC(void, Can_Server_CODE) Com_IPduReceiveCallout_Init(void);
FUNC(boolean, Can_Server_CODE) Com_IPduEnableHandle(CanIdType CanId, boolean EnableFlag);

FUNC(void , Can_Server_CODE) CanServer_SecOCBusOffEndStatusSet(boolean busoffEndFlag);
FUNC(boolean , Can_Server_CODE) CanServer_SecOCBusOffEndStatusGet(void);

extern const MD_Cfg md_cfg;
extern MD_Data md_data;

extern const NS_Cfg ns_cfg;
extern NS_Data ns_data;

static void MD_Init(void);
static void MD_Reset(void);
static void MD_MainFunction(void);

static void MD_MainFunctionInternal(void);
static void MD_MissingStartJudge(uint8 messageId);
static void MD_OkStartJudge(uint8 messageId);
static void MD_MissingConfirmJudge(uint8 messageId);
static void MD_OkConfirmJudge(uint8 messageId);
static void MD_MainFunctionMessage(uint8 messageId);
static void MD_MainFunctionDtc(uint8 dtcId);
static void NS_VoltageMainFunction(void);
static void NS_ActiveWakeMainFuncntion(void);
static void NS_ActiveIgnMainFuncntion(void);
static void NS_ActiveVoltageMainFuncntion(void);
static void NS_NetworkDiagActiveMainFuncntion(void);
static void NS_NoAckMainFuncntion(void);
static void NS_ControllerMainFuncntion(void);
static void NS_BusOffReset(void);
static void NS_BusOffMainFunction(void);
static void NS_BusOffForSecocMainFunction(void);



static CNA_Type cna = {0};

static Std_ReturnType CNA_Init(const CNA_ConfigType *config);
static Std_ReturnType CNA_DeInit(void);

static void CNA_BehaviorNoneHandle(ComEx_SignalIdType cna_Id);
static void CNA_BehaviorUnsendHandle(ComEx_SignalIdType cna_Id);
static void CNA_BehaviorSendHandle(ComEx_SignalIdType cna_Id);
static void CNA_BehaviorCycleHandle(ComEx_SignalIdType cna_Id);


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
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * boolean: Boolean (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
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
 * KL30BRelaySts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 * RemoteModSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Normal_mode (0U)
 *   Cx1_Remote_mode (1U)
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
 *   SYSTEMSTATE_IVI_ON_NORMAL (4U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (5U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (6U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (7U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (8U)
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
 * SysPowerMod: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ACC_reserved_ (1U)
 *   Cx2_ON (2U)
 *   Cx3_Crank (3U)
 * SysPowerModVld: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Invalid (0U)
 *   Cx1_Valid (1U)
 * wakeup_type: Enumeration of integer in interval [0...18446744073709551615] with enumerators
 *   value0 (0U)
 *   bit1 (1U)
 *   bit2 (2U)
 *
 * Array Types:
 * ============
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 *
 * Record Types:
 * =============
 * CanFrameCounterType: Record with elements
 *   Counter of type uint16
 *   Data of type uint16
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


#define Can_Server_START_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CNA_SignalSet
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CNA_SignalSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CNA_SignalSet(uint16 signalId, uint8 *value)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CNA_SignalSet_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSet_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSet(uint16 signalId, P2VAR(uint32, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) value) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSet (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = RTE_E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(FALSE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else if((signalId >= cna.config->signalNumber) || (NULL_PTR == value))
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];
        uint16 index; 

        can_warn("CNA ID=%d",signalId);

        /* set counter */
        if(CNA_BEHAVIOR_SEND == signalCfg->behavior)
        {
            cna.config->signalDatas[signalId].counter = (signalCfg->repetition << 1) - 1u;
        }
        else
        {
            cna.config->signalDatas[signalId].counter = signalCfg->repetition;
        }

        for(index = 0u; index < cna.config->signalConfigs[signalId].currentSize; index++)
        {
            cna.config->currentBuffer[signalCfg->currentStart + index] = ((uint8 *)value)[index];
        }

        if(CNA_BEHAVIOR_CYCLE == signalCfg->behavior)
        {
            Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(signalId, value);
        }
        /* trigger transmit */
        ComEx_SendSignal(signalCfg->comSignalId, value, signalCfg->currentSize);
        if(CNA_BEHAVIOR_CYCLE != signalCfg->behavior)
        {
            Com_TriggerIPDUSend(signalCfg->comIPduId);
        }
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSetNoTrigger(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) value) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSetNoTrigger (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = RTE_E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(FALSE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else if((signalId >= cna.config->signalNumber) || (NULL_PTR == value))
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];
        uint16 index; 

        /* set counter */
        if(CNA_BEHAVIOR_SEND == signalCfg->behavior)
        {
            cna.config->signalDatas[signalId].counter = (signalCfg->repetition << 1) - 1u;
        }
        else
        {
            cna.config->signalDatas[signalId].counter = signalCfg->repetition;
        }

        for(index = 0u; index < cna.config->signalConfigs[signalId].currentSize; index++)
        {
            cna.config->currentBuffer[signalCfg->currentStart + index] = ((uint8 *)value)[index];
        }

        if(CNA_BEHAVIOR_CYCLE == signalCfg->behavior)
        {
            Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(signalId, value);
        }

        ComEx_SendSignalBuffer(signalCfg->comSignalId, value, signalCfg->currentSize);
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanFrameCounter_Can_ABS3_Counter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Can_ABS3_Counter> of PortPrototype <CanFrameCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CanFrameCounter_Can_ABS3_Counter(CanFrameCounterType *counter)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ABS3_Counter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ABS3_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) counter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ABS3_Counter
 *********************************************************************************************************************/
    counter->Counter = ABS3_counter.Counter;
    counter->Data = ABS3_counter.Data;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanFrameCounter_Can_ECM2_Counter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Can_ECM2_Counter> of PortPrototype <CanFrameCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CanFrameCounter_Can_ECM2_Counter(CanFrameCounterType *counter)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ECM2_Counter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ECM2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) counter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ECM2_Counter
 *********************************************************************************************************************/
    counter->Counter = ECM2_counter.Counter;
    counter->Data = ECM2_counter.Data;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanFrameCounter_Can_ESP_FD2_Counter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Can_ESP_FD2_Counter> of PortPrototype <CanFrameCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CanFrameCounter_Can_ESP_FD2_Counter(CanFrameCounterType *counter)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ESP_FD2_Counter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ESP_FD2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) counter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ESP_FD2_Counter
 *********************************************************************************************************************/
    counter->Counter = ESP_FD2_counter.Counter;
    counter->Data = ESP_FD2_counter.Data;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanServer_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Vconfig_KindBuffers_VconfigKind_157Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_157Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanServer_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_Init
 *********************************************************************************************************************/
    CanServer_SecOCBusOffEndStatusSet(FALSE);
    CNA_Init(&cna_config);
    Com_IPduReceiveCallout_Init();
    MD_Init();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanServer_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_KL30BRelaySts_KL30BRelaySts(KL30BRelaySts *data)
 *   Std_ReturnType Rte_Read_RemoteModSts_RemoteModSts(RemoteModSts *data)
 *   Std_ReturnType Rte_Read_SysPowerMod_SysPowerMod(SysPowerMod *data)
 *   Std_ReturnType Rte_Read_SysPowerModVld_SysPowerModVld(SysPowerModVld *data)
 *   Std_ReturnType Rte_Read_rpSR_WakeupReason_data(wakeup_type *data)
 *   Std_ReturnType Rte_Read_tiSR_Power_Out_SystemStateOut(SystemState_RecordType *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(uint32 EventIndex, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_IPC_TransmitSignal_Callback(uint32 SignalIndex, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_HUT32_CallBack(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_HUT_IP2_Callback(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanServer_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_MainFunction
 *********************************************************************************************************************/
    NS_VoltageMainFunction();
    NS_ActiveWakeMainFuncntion();
    NS_ActiveIgnMainFuncntion();
    NS_ActiveVoltageMainFuncntion();
    NS_NetworkDiagActiveMainFuncntion();
    NS_NoAckMainFuncntion();
    NS_ControllerMainFuncntion();
    MD_MainFunction();
    NS_BusOffForSecocMainFunction();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanServer_MainFunction_5ms
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
 *   Std_ReturnType Rte_Read_ClearDTC_Service0x14_StatusFlag(uint8 *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_MainFunction_5ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanServer_MainFunction_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_MainFunction_5ms
 *********************************************************************************************************************/
    CanServer_FormatErrorHandle();
    CanServer_Service0x14_Discovery();
    NS_BusOffMainFunction();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Can_Server_STOP_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, CANSM_APPL_CODE) CanServer_BusOffEnd( NetworkHandleType  NetworkHandle )
{
    can_verbose("Busoff end");
}

FUNC(void, CANSM_APPL_CODE) CanServer_BusOffBegin( NetworkHandleType  NetworkHandle, P2VAR(uint8, AUTOMATIC, CANSM_APPL_VAR) OnlineDelayCyclesPtr )
{
    can_verbose("Busoff begin");
    if(0u == NetworkHandle)
    {
        if(ns_data.busOffData.countFail < ns_cfg.busOffCfg.countFail)
        {
            ns_data.busOffData.countFail++;
        }
    }
}

FUNC(boolean , Can_Server_CODE) SECOC_PDU_Message_Received_Callout(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    /*monitor Secoc Message,set Flag*/
    SECOC_PDU_Message_ReqSet(TRUE);

    return TRUE;
}


static FUNC(void , Can_Server_CODE) CanServer_Service0x14_Discovery(void)
{
    uint8 localDtcCnt = 0x00;
    Std_ReturnType ret = RTE_E_INVALID;

    localDtcCnt = ChangeCounter_0x14;
    ret = Rte_Read_Can_Server_piDiagMonitorReInitFlag_ChangeCounter(&ChangeCounter_0x14);

    if((ret == RTE_E_OK) && (localDtcCnt != ChangeCounter_0x14))
    {
        /* receive 0x14 service,reset Monitor info */
        MD_Reset();
        NS_BusOffReset();
    }
}

FUNC(boolean, COM_APPL_CODE) ComIPdu_userData_Callback_tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    Std_ReturnType         ret = RTE_E_INVALID;
    Std_ReturnType         resultRet = E_OK;
    uint16                 voltageValue = 0;
    SystemState_RecordType SysValue;
    uint8                     WakeupReason = 0;
    uint8                    Cannm_Status = 0;
    uint8                    Cannm_Mode = 0;
    uint8                   IVIPowerMode = 0;

    uint8                   SysPowerMod = 0;
	boolean                 SysPowerModVld = FALSE;
    uint8                   retSysPowerMod = RTE_E_INVALID;
	uint8                   retSysPowerModVld = RTE_E_INVALID;

    uint8                   SessionMode;
	
    if(NULL_PTR == PduInfoPtr->SduDataPtr)
    {
        resultRet = E_NOT_OK;
    }
    else
    {
        /*CANNM REPEAT STATUS*/
        CanNm_GetState(0,&Cannm_Status,&Cannm_Mode);
        if(Cannm_Status == NM_STATE_REPEAT_MESSAGE)
        {
            PduInfoPtr->SduDataPtr[NM_RMS_FLAG_INDEX] &= NM_CLEAR_BITS;
        }
        else
        {
            PduInfoPtr->SduDataPtr[NM_RMS_FLAG_INDEX] |= NM_BIT0;
        }
        /*Wake-Up Reason*/
        ret = Rte_Read_rpSR_WakeupReason_data(&WakeupReason);
        if(ret == RTE_E_OK)
        {
            /* if((WakeupReason & ECUM_WKSOURCE_CAN_WAKEUP_MASK) == NM_WKSOURCE_CAN) */
            {
                PduInfoPtr->SduDataPtr[NM_WAKEUP_REASON_INDEX] |= NM_BIT1;
            }
        }
        else
        {
        
        }
        
        /*Stay awake reason*/
        retSysPowerMod    = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD,    &SysPowerMod,    sizeof(SysPowerMod));
        retSysPowerModVld = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMODVLD, &SysPowerModVld, sizeof(SysPowerModVld));
        if(NS_SIGNAL_NOT_OK(retSysPowerMod))
        {
            SysPowerMod = 0;
        }
        else
        {
            /* do nothing */
        }

        if(NS_SIGNAL_NOT_OK(retSysPowerModVld))
        {
            SysPowerModVld = FALSE;
        }
        else
        {
            /* do nothing */
        }

        ret = Rte_Read_tiSR_Power_Out_SystemStateOut(&SysValue);
        
        /* CR : V35-51706*/
        if(ret == RTE_E_OK)
        {
            IVIPowerMode = SysValue.IVIState;
        }
        SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
        if(
           ((IVIPowerMode >= SYSTEMSTATE_IVI_ON_NORMAL) && (IVIPowerMode <= SYSTEMSTATE_IVI_ON_LOCAL))
        || (1u == Power_FotaSts_Get())
        || ((RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == SessionMode) || (RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession == SessionMode))
        )
        {
            PduInfoPtr->SduDataPtr[NM_STAY_AWAKE_REASON_INDEX] |= NM_BIT0;
        }
        else
        {
            PduInfoPtr->SduDataPtr[NM_STAY_AWAKE_REASON_INDEX] &= ~NM_BIT0;
        }

        if(
            (((1u == SysPowerMod) || (2u == SysPowerMod) || (3u == SysPowerMod)) && (TRUE == SysPowerModVld)) 
        || (1u == Power_FotaSts_Get()) 
        )
        {
            PduInfoPtr->SduDataPtr[NM_STAY_AWAKE_REASON_INDEX] |= NM_BIT1;
        }
        else
        {
            PduInfoPtr->SduDataPtr[NM_STAY_AWAKE_REASON_INDEX] &= ~NM_BIT1;
        }

        if(ret == RTE_E_OK)
        {
            voltageValue = (uint16)((SysValue.s_PowerVoltage.value) * 100);

            /*System Infromation*/
            if(voltageValue >= OVER_VOLTAGE_VALUE)
            {
                PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] &= ~NM_BIT0;
                PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] |= NM_BIT1;
            }
            else if(voltageValue <= UNDER_VOLTAGE_VALUE)
            {
                PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] |= NM_BIT0;
                PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] &= ~NM_BIT1;
            }
            else
            {    if(((PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] & NM_BIT1) == NM_BIT1) && (voltageValue <= OVER_VOLTAGE_RECOVER_VALUE))
                {
                    PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] &= NM_CLEAR_BITS;
                }
                if(((PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] & NM_BIT0) == NM_BIT0) && (voltageValue >= UNDER_VOLTAGE_RECOVER_VALUE))
                {
                    PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] &= NM_CLEAR_BITS;
                }
            }        
        }
    }
    return resultRet;
}

/*
 *  %function definition%
 */
/*
* @brief   :   init com no action module
* @param   :   config: config of no action module config
* @retval  :   E_OK: initialize success
* @retval  :   E_NOT_OK: parameter error
* @retval  :   E_NOT_OK: module is already initialized
* @retval  :   E_NOT_OK: config error
*/
static Std_ReturnType CNA_Init(const CNA_ConfigType *config)
{
    Std_ReturnType ret = E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(TRUE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else if(NULL_PTR == config)
    {
        ret = E_NOT_OK;
    }
    else if((NULL_PTR == config->signalConfigs) || 
        (NULL_PTR == config->signalDatas) ||
        (NULL_PTR == config->noActionBuffer))
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        cna.config = config;
        cna.isInit = TRUE;
    }

    return ret;
}

/*
* @brief   :   deinit com no action module
* @param   :   none
* @retval  :   E_OK: initialize success
* @retval  :   E_NOT_OK: module is not initialized
*/
static Std_ReturnType CNA_DeInit(void)
{
    Std_ReturnType ret = E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(FALSE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        cna.isInit = FALSE;
        cna.config = NULL_PTR;
    }

    return ret;
}

/*
* @brief   :   callback function used in signal confirmation
* @param   :   signalId: signal id to set
* @retval  :   none
*/
FUNC(void, Can_Server_CODE) CNA_SignalCallBack(uint16 signalId)
{
    Std_ReturnType ret = E_OK;
    

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(FALSE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else if(signalId >= cna.config->CNAIdTableSize)
    {
        ret = E_NOT_OK;
    }
    else if(cna.config->CNAIdTable[signalId] >= cna.config->signalNumber)
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        ComEx_SignalIdType CNA_Id = cna.config->CNAIdTable[signalId];
        const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[CNA_Id];
        uint8 count = cna.config->signalDatas[CNA_Id].counter;

        switch(signalCfg->behavior)
        {
            case CNA_BEHAVIOR_NONE:
            CNA_BehaviorNoneHandle(CNA_Id);
            break;

            case CNA_BEHAVIOR_UNSEND:
            CNA_BehaviorUnsendHandle(CNA_Id);
            break;

            case CNA_BEHAVIOR_SEND:
            CNA_BehaviorSendHandle(CNA_Id);
            break;

            case CNA_BEHAVIOR_CYCLE:
            CNA_BehaviorCycleHandle(CNA_Id);
            break;

            default:
            ret = E_NOT_OK;
            break;
        }
    }

    (void)ret;
}

/*
* @brief   :   behavior none handle
* @param   :   cna_Id:   CNA id to set
* @retval  :   none
*/
static void CNA_BehaviorNoneHandle(ComEx_SignalIdType cna_Id)
{
    const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[cna_Id];
    uint8 count = cna.config->signalDatas[cna_Id].counter;

    if(count > 0u)
    {
        count--;
        if(0u == count)
        {
            Rte_Call_rpCS_IPC_TransmitSignal_Callback(cna_Id, &cna.config->currentBuffer[signalCfg->currentStart]);
            can_warn("CNA ID=%d,value=%d",cna_Id,cna.config->currentBuffer[signalCfg->currentStart]);
        }
        else
        {
            Com_TriggerIPDUSend(signalCfg->comIPduId);
        }
        cna.config->signalDatas[cna_Id].counter = count;
    }
}

/*
* @brief   :   behavior unsend handle
* @param   :   cna_Id:   CNA id to set
* @retval  :   none
*/
static void CNA_BehaviorUnsendHandle(ComEx_SignalIdType cna_Id)
{
    const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[cna_Id];
    uint8 count = cna.config->signalDatas[cna_Id].counter;

    if(count > 0u)
    {
        count--;
        if(0u == count)
        {
            ComEx_SendSignalBuffer(signalCfg->comSignalId, &cna.config->noActionBuffer[signalCfg->noActionStart], signalCfg->currentSize);
            Rte_Call_rpCS_IPC_TransmitSignal_Callback(cna_Id, &cna.config->currentBuffer[signalCfg->currentStart]);
            can_warn("CNA ID=%d,value=%d",cna_Id,cna.config->currentBuffer[signalCfg->currentStart]);
        }
        else
        {
            Com_TriggerIPDUSend(signalCfg->comIPduId);
        }
        cna.config->signalDatas[cna_Id].counter = count;
    }
}

/*
* @brief   :   behavior send handle
* @param   :   cna_Id:   CNA id to set
* @retval  :   none
*/
static void CNA_BehaviorSendHandle(ComEx_SignalIdType cna_Id)
{
    const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[cna_Id];
    uint8 count = cna.config->signalDatas[cna_Id].counter;

    if(count > 0u)
    {
        count--;
        if((signalCfg->repetition - 1u) == count)
        {
            ComEx_SendSignal(signalCfg->comSignalId, &cna.config->noActionBuffer[signalCfg->noActionStart], signalCfg->currentSize);
            Rte_Call_rpCS_IPC_TransmitSignal_Callback(cna_Id, &cna.config->currentBuffer[signalCfg->currentStart]);
            can_warn("CNA ID=%d,value=%d",cna_Id,cna.config->currentBuffer[signalCfg->currentStart]);
        }
        Com_TriggerIPDUSend(signalCfg->comIPduId);
        cna.config->signalDatas[cna_Id].counter = count;
    }
}

/*
* @brief   :   behavior cycle handle
* @param   :   cna_Id:   CNA id to set
* @retval  :   none
*/
static void CNA_BehaviorCycleHandle(ComEx_SignalIdType cna_Id)
{
    const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[cna_Id];
    uint8 count = cna.config->signalDatas[cna_Id].counter;

    if(count > 0u)
    {
        count--;
        if(0u == count)
        {
            ComEx_SendSignal(signalCfg->comSignalId, &cna.config->noActionBuffer[signalCfg->noActionStart], signalCfg->currentSize);
            Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(cna_Id, (uint8 *)&cna.config->noActionBuffer[signalCfg->noActionStart]);
            can_warn("CNA ID=%d,value=%d",cna_Id,cna.config->currentBuffer[signalCfg->currentStart]);
        }
        cna.config->signalDatas[cna_Id].counter = count;
    }
}

void MD_Init(void)
{
    uint8 i;

    /* initialize message */
    for (i = 0u; i < md_cfg.messageNumber; i++)
    {
        md_cfg.messages[i].receiveCount = 0u;
        md_cfg.messages[i].discontinuosCount = 0u;
        md_cfg.messages[i].cycleCount = md_cfg.messageCfgs[i].cycle;
        md_cfg.messages[i].status = MD_MESSAGE_STATUS_NOT_ENABLED;
    }

    /* read vconfig */
    Rte_Read_Vconfig_KindBuffers_VconfigKind_157Bytes(md_cfg.vconfig);

    /* initialize dtc */
    for (i = 0u; i < md_cfg.dtcNumber; i++)
    {
        if (NULL_PTR == md_cfg.dtcCfgs[i].enableFunc)
        {
            md_cfg.dtcs[i].status = MD_DTC_STATUS_NOT_ENABLED;
        }
        else
        {
            md_cfg.dtcs[i].cfgId = md_cfg.dtcCfgs[i].enableFunc();
            if (MD_DTC_DISABLE != md_cfg.dtcs[i].cfgId)
            {
                md_cfg.dtcs[i].status = MD_DTC_STATUS_NOT_REPORTED;
            }
            else
            {
                md_cfg.dtcs[i].status = MD_DTC_STATUS_NOT_ENABLED;
            }
            
        }
    }
}

void MD_Reset(void)
{
    uint8 i;

    can_verbose("Missing DTC reset");
    for (i = 0u; i < md_cfg.messageNumber; i++)
    {
        md_cfg.messages[i].receiveCount = 0u;
        md_cfg.messages[i].discontinuosCount = 0u;
        md_cfg.messages[i].cycleCount = md_cfg.messageCfgs[i].cycle;
        if (MD_MESSAGE_STATUS_NOT_ENABLED != md_cfg.messages[i].status)
        {
            md_cfg.messages[i].status = MD_MESSAGE_STATUS_NOT_DETERMINED;
        }
    }

    for (i = 0u; i < md_cfg.dtcNumber; i++)
    {
        if (MD_DTC_STATUS_NOT_ENABLED != md_cfg.dtcs[i].status)
        {
            md_cfg.dtcs[i].status = MD_DTC_STATUS_NOT_REPORTED;
        }
    }
}

void MD_PduCallback(uint16 pduId, uint8 length)
{
    if (FALSE != md_data.globalStatus)
    {
        /* Check pdu id */
        if (pduId < md_cfg.pduNumber)
        {
            /* Check length */
            if (md_cfg.pduCfgs[pduId].length == length)
            {
                uint16 messageId = md_cfg.pduCfgs[pduId].messageId;
                /* Check message id */
                if (messageId < md_cfg.messageNumber)
                {
                    if (md_cfg.messages[messageId].receiveCount < 0xFFFFu)
                    {
                        md_cfg.messages[messageId].receiveCount++;
                    }
                }
            }
        }
    }
}

void MD_MainFunction(void)
{
    boolean globalRet = TRUE;

    /* global enable judge */
    if (NULL_PTR != md_cfg.globalFunc)
    {
        globalRet = md_cfg.globalFunc();
    }

    if (md_data.globalStatus != globalRet)
    {
        MD_Reset();
        md_data.globalStatus = globalRet;
    }

    if (FALSE != globalRet)
    {
        MD_MainFunctionInternal();
    }
}

static void MD_MainFunctionInternal(void)
{
    uint8 i;

    for (i = 0u; i < md_cfg.messageNumber; i++)
    {
        MD_MainFunctionMessage(i);
    }

    for (i = 0u; i < md_cfg.dtcNumber; i++)
    {
        MD_MainFunctionDtc(i);
    }
}

static void MD_NotDeterminedJudge(uint8 messageId)
{
    MD_Message *message = &md_cfg.messages[messageId];
    const MD_MessageCfg *messageCfg = &md_cfg.messageCfgs[messageId];

    /* no message arrive in cycle */
    if (message->receiveCount <= message->receiveCountLastCycle)
    {
        message->discontinuosCount++;
        /* missing count over or equal missing threshold */
        if (message->discontinuosCount >= md_cfg.discontinuosThreshold)
        {
            /* discontinous confirm */
            can_verbose("Message %d missing start", messageId);
            message->status = MD_MESSAGE_STATUS_MISSING_START;
            message->discontinuosCount = 0u;
            message->cycleConfirm = messageCfg->missingCycle;
            message->receiveCount = 0u;
            message->receiveCountLastCycle = 0u;
        }
    }
    else
    {
        /* receive */
        can_verbose("Message %d ok start", messageId);
        message->status = MD_MESSAGE_STATUS_OK_START;
        message->discontinuosCount = 0u;
        message->cycleConfirm = messageCfg->okCycle;
        message->receiveCountLastCycle = message->receiveCount;
    }
}

static void MD_MissingStartJudge(uint8 messageId)
{
    MD_Message *message = &md_cfg.messages[messageId];
    const MD_MessageCfg *messageCfg = &md_cfg.messageCfgs[messageId];

    /* message arrive in cycle */
    if (message->receiveCount > message->receiveCountLastCycle)
    {
        /* receive */
        can_verbose("Message %d ok start", messageId);
        message->status = MD_MESSAGE_STATUS_OK_START;
        message->discontinuosCount = 0u;
        message->cycleConfirm = messageCfg->okCycle;
        message->receiveCountLastCycle = message->receiveCount;
    }
    else
    {
        if (message->cycleConfirm > 0u)
        {
            message->cycleConfirm--;
        }

        if (message->cycleConfirm == 0u)
        {
            /* miss confirm */
            can_verbose("Message %d missing confirm", messageId);
            message->status = MD_MESSAGE_STATUS_MISSING_CONFIRM;
            message->receiveCount = 0u;
            message->receiveCountLastCycle = 0u;
            message->discontinuosCount = 0u;
        }
        else
        {
            /* miss not confirm */
            message->receiveCount = 0u;
            message->receiveCountLastCycle = 0u;
            message->discontinuosCount = 0u;
        }
    }
}

static void MD_OkStartJudge(uint8 messageId)
{
    MD_Message *message = &md_cfg.messages[messageId];
    const MD_MessageCfg *messageCfg = &md_cfg.messageCfgs[messageId];

    /* message arrive in cycle */
    if (message->receiveCount > message->receiveCountLastCycle)
    {
        if (message->cycleConfirm > 0u)
        {
            /* receive not confirm */
            message->cycleConfirm--;
            message->discontinuosCount = 0u;
            message->receiveCountLastCycle = message->receiveCount;
        }

        if ((message->cycleConfirm == 0u) && (message->receiveCount >= messageCfg->okCounter))
        {
            /* receive confirm */
            can_verbose("Message %d ok confirm", messageId);
            message->status = MD_MESSAGE_STATUS_OK_CONFIRM;
            message->receiveCount = 0u;
            message->receiveCountLastCycle = 0u;
            message->discontinuosCount = 0u;
        }
    }
    else
    {
        message->discontinuosCount++;
        /* missing count over or equal missing threshold */
        if (message->discontinuosCount >= md_cfg.discontinuosThreshold)
        {
            /* discontinous confirm */
            can_verbose("Message %d missing start", messageId);
            message->status = MD_MESSAGE_STATUS_MISSING_START;
            message->discontinuosCount = 0u;
            message->cycleConfirm = messageCfg->missingCycle;
            message->receiveCount = 0u;
            message->receiveCountLastCycle = 0u;
        }
    }
}

static void MD_MissingConfirmJudge(uint8 messageId)
{
    MD_Message *message = &md_cfg.messages[messageId];
    const MD_MessageCfg *messageCfg = &md_cfg.messageCfgs[messageId];

    /* message arrive in cycle */
    if (message->receiveCount > message->receiveCountLastCycle)
    {
        /* receive */
        can_verbose("Message %d ok start", messageId);
        message->status = MD_MESSAGE_STATUS_OK_START;
        message->discontinuosCount = 0u;
        message->cycleConfirm = messageCfg->okCycle;
        message->receiveCountLastCycle = message->receiveCount;
    }
    else
    {
        message->discontinuosCount = 0u;
        message->receiveCount = 0u;
        message->receiveCountLastCycle = 0u;
        message->cycleConfirm = 0u;
    }
}

static void MD_OkConfirmJudge(uint8 messageId)
{
    MD_Message *message = &md_cfg.messages[messageId];
    const MD_MessageCfg *messageCfg = &md_cfg.messageCfgs[messageId];

    /* message not arrive in cycle */
    if (message->receiveCount <= message->receiveCountLastCycle)
    {
        message->discontinuosCount++;
        /* missing count over or equal missing threshold */
        if (message->discontinuosCount >= md_cfg.discontinuosThreshold)
        {
            /* discontinous confirm */
            can_verbose("Message %d missing start", messageId);
            message->status = MD_MESSAGE_STATUS_MISSING_START;
            message->discontinuosCount = 0u;
            message->cycleConfirm = messageCfg->missingCycle;
            message->receiveCount = 0u;
            message->receiveCountLastCycle = 0u;
        }
        else
        {
            /* discontinous not confirm */
            message->receiveCount = 0u;
            message->receiveCountLastCycle = 0u;
            message->cycleConfirm = 0u;
        }
    }
    else
    {
        /* receive */
        message->discontinuosCount = 0u;
        message->receiveCount = 0u;
        message->receiveCountLastCycle = 0u;
        message->cycleConfirm = 0u;
    }
}

static void MD_MainFunctionMessage(uint8 messageId)
{
    MD_Message *message = &md_cfg.messages[messageId];
    const MD_MessageCfg *messageCfg = &md_cfg.messageCfgs[messageId];

    if (message->status != MD_MESSAGE_STATUS_NOT_ENABLED)
    {
        /* cycle count */
        if (message->cycleCount > 0u)
        {
            message->cycleCount--;
        }

        /* cycle timeout, handle message*/
        if (0u == message->cycleCount)
        {
            /* reset message cycle counter */
            message->cycleCount = messageCfg->cycle;

            switch(message->status)
            {
                case MD_MESSAGE_STATUS_NOT_DETERMINED:
                {
                    MD_NotDeterminedJudge(messageId);
                }
                break;

                case MD_MESSAGE_STATUS_MISSING_START:
                {
                    MD_MissingStartJudge(messageId);
                }
                break;

                case MD_MESSAGE_STATUS_OK_START:
                {
                    MD_OkStartJudge(messageId);
                }
                break;

                case MD_MESSAGE_STATUS_MISSING_CONFIRM:
                {
                    MD_MissingConfirmJudge(messageId);
                }
                break;
                
                case MD_MESSAGE_STATUS_OK_CONFIRM:
                {
                    MD_OkConfirmJudge(messageId);
                }
                break;

                default:
                break;
            }
        }
    }
}

static void MD_MainFunctionDtc(uint8 dtcId)
{
    MD_Dtc *dtc = &md_cfg.dtcs[dtcId];
    const MD_DtcCfg *dtcCfg = &md_cfg.dtcCfgs[dtcId];

    if (MD_DTC_STATUS_NOT_ENABLED != dtc->status)
    {
        if (NULL_PTR != dtcCfg->judgeFunc)
        {
            uint8 result = dtcCfg->judgeFunc(dtc->cfgId);
            if (MD_DTC_JUDGE_RESULT_FAILED == result)
            {
                if ((MD_DTC_STATUS_NOT_REPORTED == dtc->status) || (MD_DTC_STATUS_PASSED_REPORTED == dtc->status))
                {
                    if (NULL_PTR != dtcCfg->reportFunc)
                    {
                        Std_ReturnType ret = dtcCfg->reportFunc(DEM_EVENT_STATUS_FAILED);
                        if (E_OK == ret)
                        {
                            can_verbose("Dtc %d report success", dtcId);
                            dtc->status = MD_DTC_STATUS_FAILED_REPORTED;
                            dtc->cycleReport = dtcCfg->cycleReport;
                        }
                    }
                }
                else if(MD_DTC_STATUS_FAILED_REPORTED == dtc->status)
                {
                    if(dtc->cycleReport > 0u)
                    {
                        dtc->cycleReport--;
                    }
                    if(0u == dtc->cycleReport)
                    {
                        if (NULL_PTR != dtcCfg->reportFunc)
                        {
                            Std_ReturnType ret = dtcCfg->reportFunc(DEM_EVENT_STATUS_FAILED);
                            if (E_OK == ret)
                            {
                                dtc->cycleReport = dtcCfg->cycleReport;
                            }
                        }
                    }
                }
                else
                {
                    /* nothing to do */
                }
            }
            else if(MD_DTC_JUDGE_RESULT_PASSED == result)
            {
                if ((MD_DTC_STATUS_NOT_REPORTED == dtc->status) || (MD_DTC_STATUS_FAILED_REPORTED == dtc->status))
                {
                    if (NULL_PTR != dtcCfg->reportFunc)
                    {
                        Std_ReturnType ret = dtcCfg->reportFunc(DEM_EVENT_STATUS_PASSED);
                        if (E_OK == ret)
                        {
                            can_verbose("Dtc %d report success", dtcId);
                            dtc->status = MD_DTC_STATUS_PASSED_REPORTED;
                            dtc->cycleReport = dtcCfg->cycleReport;
                        }
                    }
                }
                else if(MD_DTC_STATUS_PASSED_REPORTED == dtc->status)
                {
                    if(dtc->cycleReport > 0u)
                    {
                        dtc->cycleReport--;
                    }
                    if(0u == dtc->cycleReport)
                    {
                        if (NULL_PTR != dtcCfg->reportFunc)
                        {
                            Std_ReturnType ret = dtcCfg->reportFunc(DEM_EVENT_STATUS_PASSED);
                            if (E_OK == ret)
                            {
                                dtc->cycleReport = dtcCfg->cycleReport;
                            }
                        }
                    }
                }
                else
                {
                    /* nothing to do */
                }
            }
            else
            {
                /* result not ready */
            }
        }
    }
}

static void NS_VoltageMainFunction(void)
{
    SystemState_RecordType systemState = {0x00};
    uint8 volRet = FALSE;
    float64 vol = (float64)0.0f;

    volRet = Rte_Read_tiSR_Power_Out_SystemStateOut(&systemState);
    vol = systemState.s_PowerVoltage.value;

    switch(ns_data.voltageData.statusVoltage)
    {
        case NS_STATUS_VOLTAGE_NORMAL:
        {
            if((E_OK != volRet) || (vol <= (float64)5.0f) || (vol >= (float64)24.0f))
            {
                ns_data.voltageData.statusVoltage = NS_STATUS_VOLTAGE_ABNORMAL;
                //(void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( 0x00 ), CANIF_SET_TX_OFFLINE );
                can_verbose("NS voltage abnormal");
            }
        }
        break;

        case NS_STATUS_VOLTAGE_ABNORMAL:
        {
            if((E_OK == volRet) && (vol >= (float64)6.0f) && (vol <= (float64)23.0f))
            {
                ns_data.voltageData.statusVoltage = NS_STATUS_VOLTAGE_NORMAL;
                //(void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( 0x00 ), CANIF_SET_TX_ONLINE );
                can_verbose("NS voltage normal");
            }
        }
        break;

        dafault:
        break;
    }
}

static void NS_ActiveWakeMainFuncntion(void)
{
    Std_ReturnType canNmRet = E_OK;
    Nm_StateType nmState = NM_STATE_UNINIT;
    Nm_ModeType nmMode = NM_STATE_UNINIT;

    canNmRet = CanNm_GetState(0, &nmState, &nmMode);
    switch(ns_data.activeData.statusWake)
    {
        case NS_STATUS_ACTIVE_SLEEP:
        {
            if((E_OK == canNmRet) && (nmState >= NM_STATE_READY_SLEEP))
            {
                ns_data.activeData.statusWake = NS_STATUS_ACTIVE_WAKE_RECOVERY;
                ns_data.activeData.countWake = ns_cfg.activeCfg.countWake;
                can_verbose("NS active wake recovery");
            }
        }
        break;

        case NS_STATUS_ACTIVE_WAKE_RECOVERY:
        {
            if((E_OK != canNmRet) || (NM_STATE_BUS_SLEEP == nmState) || (NM_STATE_PREPARE_BUS_SLEEP == nmState))
            {
                ns_data.activeData.statusWake = NS_STATUS_ACTIVE_SLEEP;
                ns_data.activeData.countWake = 0u;
                can_verbose("NS active sleep");
            }
            else
            {
                if(ns_data.activeData.countWake > 0u)
                {
                    ns_data.activeData.countWake--;
                    if(ns_data.activeData.countWake == 0u)
                    {
                        ns_data.activeData.statusWake = NS_STATUS_ACTIVE_WAKE;
                        can_verbose("NS active wake");
                    }
                }
            }
        }
        break;

        case NS_STATUS_ACTIVE_WAKE:
        {
            if((E_OK != canNmRet) || (nmState == NM_STATE_BUS_SLEEP) || (NM_STATE_PREPARE_BUS_SLEEP == nmState))
            {
                ns_data.activeData.statusWake = NS_STATUS_ACTIVE_SLEEP;
                can_verbose("NS active sleep");
            }
        }
        break;

        default:
        break;
    }
}

static void NS_ActiveIgnMainFuncntion(void)
{
    SysPowerMod kL15Value = 0;
    Std_ReturnType kL15RetStatus = E_NOT_OK;

    kL15RetStatus = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, &kL15Value, sizeof(kL15Value));
    switch(ns_data.activeData.statusIgn)
    {
        case NS_STATUS_ACTIVE_IGN_OFF:
        {
            if(NS_SIGNAL_OK(kL15RetStatus) && (DIAG_SYSTEM_POWER_MODE == kL15Value))
            {
                ns_data.activeData.statusIgn = NS_STATUS_ACTIVE_IGN_ON_RECOVERY;
                ns_data.activeData.countIgn = ns_cfg.activeCfg.countIgn;
                can_verbose("NS active ign on recovery");
            }
        }
        break;

        case NS_STATUS_ACTIVE_IGN_ON_RECOVERY:
        {
            if(NS_SIGNAL_NOT_OK(kL15RetStatus) || (DIAG_SYSTEM_POWER_MODE != kL15Value))
            {
                ns_data.activeData.statusIgn = NS_STATUS_ACTIVE_IGN_OFF;
                ns_data.activeData.countIgn = ns_cfg.activeCfg.countIgn;
                can_verbose("NS active ign off");
            }
            else
            {
                if(ns_data.activeData.countIgn > 0u)
                {
                    ns_data.activeData.countIgn--;
                    if(ns_data.activeData.countIgn == 0u)
                    {
                        ns_data.activeData.statusIgn = NS_STATUS_ACTIVE_IGN_ON;
                        can_verbose("NS active ign on");
                    }
                }
            }
        }
        break;

        case NS_STATUS_ACTIVE_IGN_ON:
        {
            if(NS_SIGNAL_NOT_OK(kL15RetStatus) || (DIAG_SYSTEM_POWER_MODE != kL15Value))
            {
                ns_data.activeData.statusIgn = NS_STATUS_ACTIVE_IGN_OFF;
                can_verbose("NS active ign off");
            }
        }
        break;

        default:
        break;
    }
}

static void NS_ActiveVoltageMainFuncntion(void)
{
    SystemState_RecordType systemState = {0x00};
    uint8 volRet = FALSE;
    float64 vol = (float64)0.0f;

    volRet = Rte_Read_tiSR_Power_Out_SystemStateOut(&systemState);
    vol = systemState.s_PowerVoltage.value;

    switch(ns_data.activeData.statusVoltage)
    {
        case NS_STATUS_ACTIVE_VOLTAGE_ABNORMAL:
        {
            if(NS_STATUS_ACTIVE_SLEEP == ns_data.activeData.statusWake)
            {
                ns_data.activeData.statusVoltage = NS_STATUS_ACTIVE_VOLTAGE_NORMAL;
                ns_data.activeData.countVoltage = 0u;
                can_verbose("NS active voltage normal");
            }
            else if((E_OK == volRet) && (vol >= (float64)10.0f) && (vol <= (float64)15.0f))
            {
                ns_data.activeData.statusVoltage = NS_STATUS_ACTIVE_VOLTAGE_NORMAL_RECOVERY;
                ns_data.activeData.countVoltage = ns_cfg.activeCfg.countVoltage;
                can_verbose("NS active voltage normal recovery");
            }
        }
        break;

        case NS_STATUS_ACTIVE_VOLTAGE_NORMAL_RECOVERY:
        {
            if(NS_STATUS_ACTIVE_SLEEP == ns_data.activeData.statusWake)
            {
                ns_data.activeData.statusVoltage = NS_STATUS_ACTIVE_VOLTAGE_NORMAL;
                ns_data.activeData.countVoltage = 0u;
                can_verbose("NS active voltage normal");
            }
            else
            {
                if(ns_data.activeData.countVoltage > 0u)
                {
                    ns_data.activeData.countVoltage--;
                    if(ns_data.activeData.countVoltage == 0u)
                    {
                        ns_data.activeData.statusVoltage = NS_STATUS_ACTIVE_VOLTAGE_NORMAL;
                        can_verbose("NS active voltage normal");
                    }
                }
            }
        }
        break;

        case NS_STATUS_ACTIVE_VOLTAGE_NORMAL:
        {
            if(((E_OK != volRet) || (vol <= (float64)9.0f) || (vol >= (float64)16.0f)) && (NS_STATUS_ACTIVE_WAKE == ns_data.activeData.statusWake))
            {
                ns_data.activeData.statusVoltage = NS_STATUS_ACTIVE_VOLTAGE_ABNORMAL;
                ns_data.activeData.countVoltage = ns_cfg.activeCfg.countVoltage;
                can_verbose("NS active voltage abnormal");
            }
        }
        break;

        default:
        break;
    }
}

static void NS_NetworkDiagActiveMainFuncntion(void)
{
    switch(ns_data.activeData.statusActive)
    {
        case NS_STATUS_ACTIVE_INACTIVE:
        {
            if((NS_STATUS_ACTIVE_WAKE == ns_data.activeData.statusWake) && (NS_STATUS_ACTIVE_IGN_ON == ns_data.activeData.statusIgn) && (NS_STATUS_ACTIVE_VOLTAGE_NORMAL == ns_data.activeData.statusVoltage))
            {
                ns_data.activeData.statusActive = NS_STATUS_ACTIVE_ACTIVE;
                can_warn("NS active,Sts=%d,Ign=%d,Vol=%d", ns_data.activeData.statusWake, ns_data.activeData.statusIgn, ns_data.activeData.statusVoltage);
            }
        }
        break;

        case NS_STATUS_ACTIVE_ACTIVE:
        {
            if((NS_STATUS_ACTIVE_WAKE != ns_data.activeData.statusWake) || (NS_STATUS_ACTIVE_IGN_ON != ns_data.activeData.statusIgn) || (NS_STATUS_ACTIVE_VOLTAGE_NORMAL != ns_data.activeData.statusVoltage))
            {
                ns_data.activeData.statusActive = NS_STATUS_ACTIVE_INACTIVE;
                can_warn("NS active,Sts=%d,Ign=%d,Vol=%d", ns_data.activeData.statusWake, ns_data.activeData.statusIgn, ns_data.activeData.statusVoltage);
            }
        }
        break;

        default:
        break;
    }
}

static void NS_NoAckMainFuncntion(void)
{
    boolean noAckFlag = FALSE;
    volatile uint8 tec = *((volatile uint8*)(0xFFD0003B));
    volatile uint8 adErr = *((volatile uint8*)(0xFFD0003D));
    volatile uint8 passiveErr = *((volatile uint8*)(0xFFD0003C));

    if((tec >= 128u) && ((adErr & NOACKINGADERRMASK) != 0u) && ((passiveErr & ERR_PASSIVE_MASK) != 0u) && (NS_STATUS_ACTIVE_VOLTAGE_NORMAL == ns_data.activeData.statusVoltage))
    {
        noAckFlag = TRUE;
    }

    switch(ns_data.noAckData.statusNoAck)
    {
        case NS_STATUS_NOACK_DISAPPEAR:
        {
            if(TRUE == noAckFlag)
            {
                ns_data.noAckData.statusNoAck = NS_STATUS_NOACK_WAITING;
                ns_data.noAckData.countNoAck = ns_cfg.noAckCfg.countNoAck;
                can_warn("No ACK Happen!");
            }
        }
        break;

        case NS_STATUS_NOACK_WAITING:
        {
            if(FALSE == noAckFlag)
            {
                ns_data.noAckData.statusNoAck = NS_STATUS_NOACK_DISAPPEAR;
                ns_data.noAckData.countNoAck = 0u;
                can_warn("No ACK Disappear!");
            }
            else
            {
                if(ns_data.noAckData.countNoAck > 0u)
                {
                    ns_data.noAckData.countNoAck--;
                    if(ns_data.noAckData.countNoAck == 0u)
                    {
                        ns_data.noAckData.statusNoAck = NS_STATUS_NOACK_RECOVERY;
                        ns_data.noAckData.countNoAck = ns_cfg.noAckCfg.countNoAck;
                    }
                }
            }
        }
        break;

        case NS_STATUS_NOACK_RECOVERY:
        {
            if(ns_data.noAckData.countNoAck > 0u)
            {
                ns_data.noAckData.countNoAck--;
                if(ns_data.noAckData.countNoAck == 0u)
                {
                    ns_data.noAckData.statusNoAck = NS_STATUS_NOACK_DISAPPEAR;
                    ns_data.noAckData.countNoAck = 0u;
                }
            }
        }
        break;

        default:
        break;
    }
}

static void NS_ControllerMainFuncntion(void)
{
    uint8 status = 0u;
    uint8 statusBefore = ns_data.controllerData.statusController;

    if(NS_STATUS_NOACK_RECOVERY == ns_data.noAckData.statusNoAck)
    {
        status |= NS_STATUS_CONTROLLER_NO_ACK_WAITING;
    }

    if((NS_STATUS_BUSOFF_PREFAILED == ns_data.busOffData.statusBusOff) || (NS_STATUS_BUSOFF_FAILED == ns_data.busOffData.statusBusOff))
    {
        status |= NS_STATUS_CONTROLLER_BUSOFF;
    }

    
    if(status != statusBefore)
    {
        can_verbose("NS controller change from %d to %d", ns_data.controllerData.statusController, status);
        if((NS_STATUS_CONTROLLER_OK == statusBefore) && (status < NS_STATUS_CONTROLLER_BUSOFF))
        {
            CanIf_SetControllerMode(0u, CANIF_CS_STOPPED);
            can_verbose("NS set controller stop");
        }
        else if((statusBefore < NS_STATUS_CONTROLLER_BUSOFF) && (NS_STATUS_CONTROLLER_OK == status))
        {
            CanIf_SetControllerMode(0u, CANIF_CS_STARTED);
            can_verbose("NS set controller start");
        }
        ns_data.controllerData.statusController = status;
    }
}

static void NS_BusOffReset(void)
{
    ns_data.busOffData.countFail = 0u;
    ns_data.busOffData.countPass = 0u;
    ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_NOT_DETERMINED;
}

static void NS_BusOffMainFunction(void)
{
    Std_ReturnType retDTC = E_NOT_OK;
    Std_ReturnType retBor = E_NOT_OK;
    CanSM_BorStateType bor = CANSM_BOR_NONE;

    retBor = CanSM_CheckBorLevel(0u, &bor);
    
    if(NS_STATUS_ACTIVE_ACTIVE == ns_data.activeData.statusActive)
    {
        if(NS_STATUS_ACTIVE_ACTIVE != ns_data.busOffData.PrestatusActive)
        {
            NS_BusOffReset();
        }
        
        switch(ns_data.busOffData.statusBusOff)
        {
            case NS_STATUS_BUSOFF_NOT_DETERMINED:
            {
                if(E_OK == retBor)
                {
                    if(CANSM_BOR_NONE == bor)
                    {
                        ns_data.busOffData.countPass = 0;
                        ns_data.busOffData.countFail = 0;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREPASSED;
                        can_verbose("Busoff prepassed");
                    }
                    else 
                    {
                        ns_data.busOffData.countPass = 0;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREFAILED;
                        can_verbose("Busoff prefailed");
                    }
                }
            }
            break;

            case NS_STATUS_BUSOFF_PREPASSED:
            {
                if(E_OK == retBor)
                {
                    if(CANSM_BOR_NONE == bor)
                    {
                        if(ns_data.busOffData.countPass < ns_cfg.busOffCfg.countPass)
                        {
                            ns_data.busOffData.countPass++;
                            ns_data.busOffData.countFail = 0u;
                        }

                        if(ns_data.busOffData.countPass == ns_cfg.busOffCfg.countPass)
                        {
                            retDTC = Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(DEM_EVENT_STATUS_PASSED);
                            if(E_OK == retDTC)
                            {
                                ns_data.busOffData.countPass = 0u;
                                ns_data.busOffData.reportcounter = 0u;
                                ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PASSED;
                                can_warn("Busoff passed");
                            }
                        }
                    }
                    else
                    {
                        ns_data.busOffData.countPass = 0u;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREFAILED;
                        can_verbose("Busoff prefailed");
                    }
                }
            }
            break;

            case NS_STATUS_BUSOFF_PASSED:
            {
                if(E_OK == retBor)
                {
                    if(CANSM_BOR_NONE != bor)
                    {
                        ns_data.busOffData.countPass = 0u;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREFAILED;
                        can_verbose("Busoff prefailed");
                    }
                }

                if(ns_data.busOffData.reportcounter <= BUSOFF_REPORT_CYC)
                {
                    ns_data.busOffData.reportcounter++;
                    if(ns_data.busOffData.reportcounter >= BUSOFF_REPORT_CYC)
                    {
                        ns_data.busOffData.reportcounter = 0u;
                        retDTC = Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(DEM_EVENT_STATUS_PASSED);
                    }
                }
            }
            break;

            case NS_STATUS_BUSOFF_PREFAILED:
            {
                if(E_OK == retBor)
                {
                    if(CANSM_BOR_NONE == bor)
                    {
                        ns_data.busOffData.countPass = 0u;
                        ns_data.busOffData.countFail = 0u;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREPASSED;
                        can_verbose("Busoff prepassed");
                    }
                    else
                    {
                        if((ns_cfg.busOffCfg.countFail == ns_data.busOffData.countFail) || (CANSM_BOR_LEVEL2 == bor))
                        {
                            ns_data.busOffData.countPass = 0u;
                            retDTC = Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(DEM_EVENT_STATUS_FAILED);
                            if(E_OK == retDTC)
                            {
                                ns_data.busOffData.countFail = 0u;
                                ns_data.busOffData.reportcounter = 0u;
                                ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_FAILED;
                                can_warn("Busoff failed");
                            }
                        }
                    }
                }
            }

            case NS_STATUS_BUSOFF_FAILED:
            {
                if(E_OK == retBor)
                {
                    if(CANSM_BOR_NONE == bor)
                    {
                        ns_data.busOffData.countPass = 0u;
                        ns_data.busOffData.countFail = 0u;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREPASSED;
                        can_verbose("Busoff prepassed");
                    }
                }

                if(ns_data.busOffData.reportcounter <= BUSOFF_REPORT_CYC)
                {
                    ns_data.busOffData.reportcounter++;
                    if(ns_data.busOffData.reportcounter >= BUSOFF_REPORT_CYC)
                    {
                        ns_data.busOffData.reportcounter = 0u;
                        retDTC = Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(DEM_EVENT_STATUS_FAILED);
                    }
                }
            }
            break;

            default:
            break;
        }
    }

    ns_data.busOffData.PrestatusActive = ns_data.activeData.statusActive;
}

static void NS_BusOffForSecocMainFunction(void)
{
    Std_ReturnType retBor = E_NOT_OK;
    CanSM_BorStateType bor = CANSM_BOR_NONE;

    retBor = CanSM_CheckBorLevel(0u, &bor);

    if((E_OK == retBor) && (NS_STATUS_ACTIVE_IGN_ON == ns_data.activeData.statusIgn))
    {
        if((CANSM_BOR_NONE == bor) && (CANSM_BOR_NONE != ns_data.busOffData.prestatusBusOff))
        {
            CanServer_SecOCBusOffEndStatusSet(TRUE);
        }
        
        ns_data.busOffData.prestatusBusOff = bor;
    }
}

boolean MD_GlobalEnableFuncntion(void)
{
    uint8 kL30 = 0u;
    uint8 remoteModSts = 0u;
    Std_ReturnType kL30dataRet = E_NOT_OK;
    Std_ReturnType remoteModStsRet = E_NOT_OK;
    boolean ret = FALSE;

    kL30dataRet = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &kL30, sizeof(kL30));
    remoteModStsRet = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &remoteModSts, sizeof(remoteModSts));
    if(NS_SIGNAL_NOT_OK(kL30dataRet))
    {
        kL30 = 0u;
    }
    
    if(NS_SIGNAL_NOT_OK(remoteModStsRet))
    {
        remoteModSts = 0u;
    }

    if((1u == remoteModSts) && (0u == kL30))
    {
        ret = FALSE;
    }
    else if(ns_data.busOffData.statusBusOff != NS_STATUS_BUSOFF_PASSED)
    {
        ret = FALSE;
    }
    else if(NS_STATUS_ACTIVE_ACTIVE == ns_data.activeData.statusActive)
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}

FUNC(boolean, COM_APPL_CODE) Com_IPduTransmitCallout(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint16   PduIdIndex = 0x00;
    boolean  retValue = TRUE;
    
    CAN_SERVER_IGNORE_UNREF_PARAM(PduId);
    CAN_SERVER_IGNORE_UNREF_PARAM(PduInfoPtr);
    
    return retValue;
}

/******************************************************************************/
/**
* @brief               <Com_IPduReceiveCallout_Init>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static FUNC(void, Can_Server_CODE) Com_IPduReceiveCallout_Init(void)
{
    Com_RxPdu_SizeOfType   PduIdIndex = 0x00;

    /* get index CanId in arr*/
    for(PduIdIndex = 0x00; PduIdIndex < CanServer_Disable_Rx_PDU_Number();PduIdIndex++)
    {
        /* Pdu notify up layer in default */
        Com_SetRxPduEnableFlag(PduIdIndex,FALSE);
    }
}

/******************************************************************************/
/**
* @brief               <Com_IPduEnableHandle>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <CanIdType CanId,boolean EnableFlag:TRUE will disable Pdu Receive,FALSE 
                        will receive the Pdu>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <retValue:type boolean,call the function successful will return TRUE>    
*/
/******************************************************************************/
FUNC(boolean, Can_Server_CODE) Com_IPduEnableHandle(CanIdType CanId, boolean EnableFlag)
{
    Com_RxPdu_SizeOfType   PduIdIndex = 0x00;
    Com_RxPdu_SizeOfType   CanIdMapIndex = 0xFF;
    boolean                retValue = FALSE;
    Com_Disable_RxPdu_Receive_Info Com_Disable_CurrentRxPdu_Cfg;
    
    Com_Disable_CurrentRxPdu_Cfg = Com_IPduEnable_VarCfgPtr();

    /* get index CanId in arr*/
    for(PduIdIndex = 0x00; PduIdIndex < CanServer_Disable_Rx_PDU_Number();PduIdIndex++)
    {
        if((Com_Disable_CurrentRxPdu_Cfg.RxPduMapCanId[PduIdIndex]) == CanId)
        {
            CanIdMapIndex = PduIdIndex;
        }
    }

    if(CanIdMapIndex != 0xFF)
    {
        /* set target Pdu enable status */
        Com_SetRxPduEnableFlag(CanIdMapIndex,EnableFlag);

        if(Com_GetRxPduEnableFlag(CanIdMapIndex) == EnableFlag)
        {
            retValue = TRUE;
        }
    }

    return retValue;
}

FUNC(void, CANIF_CODE) CanIf_TransmitSubDataChecksumTxAppend(P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR_STACK) txPduInfoPtr, P2VAR(uint8, AUTOMATIC, CANIF_VAR_STACK) txPduDataWithChecksumPtr)
{
    uint8 index = 0;

    if((0x7B3 & (txPduInfoPtr->id)) == 0x7B3) 
    {
        if((txPduInfoPtr->sdu[0] == 0x03)  && (txPduInfoPtr->sdu[1] == 0x7F) && (txPduInfoPtr->sdu[3] == 0x31))
        {
            can_info("Service=0x%x,NRC=0x%x",txPduInfoPtr->sdu[2],txPduInfoPtr->sdu[3]);
        }
        else if((txPduInfoPtr->sdu[0] == 0x03)  && (txPduInfoPtr->sdu[1] == 0x7F) && (txPduInfoPtr->sdu[2] == 0x27) && (txPduInfoPtr->sdu[3] == 0x35))
        {
            can_info("Service=0x%x,NRC=0x%x",txPduInfoPtr->sdu[2],txPduInfoPtr->sdu[3]);
        }

        
        for(index = 0; index < txPduInfoPtr->length;index++)
        {
            txPduDataWithChecksumPtr[index] = txPduInfoPtr->sdu[index];
        }
    }
}

/* Can format error will report SOC*/
static FUNC(void, Can_Server_CODE) CanServer_FormatErrorHandle(void)
{
    uint8 formatErrIndex = 0x00;

    while(formatErrIndex < CAN_FORMATERR_NUMBER)
    {
        if((*((uint32*)(CANFormatErrCfgInfoRecord[formatErrIndex].CANChanErrFlagRegisterAddr))) & CANFormatErrCfgInfoRecord[formatErrIndex].CANChanFormatErrMask)
        {
            if(ErrorTimeCnt == FALSE)
            {
                ErrorTimeCnt = TRUE;
                can_info("Can %d Format Error.",CANFormatErrCfgInfoRecord[formatErrIndex].CANChanNum);
            }
        }
        formatErrIndex++;
    }
}


FUNC(void , Can_Server_CODE) CanServer_SecOCBusOffEndStatusSet(boolean busoffEndFlag)
{
    SecOCBusOffReocrd.BusOffStatusFlag = busoffEndFlag;
}

FUNC(boolean , Can_Server_CODE) CanServer_SecOCBusOffEndStatusGet(void)
{
    return SecOCBusOffReocrd.BusOffStatusFlag;
}
 

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
