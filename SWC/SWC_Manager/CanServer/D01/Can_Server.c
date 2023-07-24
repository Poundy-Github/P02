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
 *           Config:  E:/06.Code/VIP_MCU_3.5/Gwm_v3.5_dev/Davinci_d01/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Can_Server
 *  Generation Time:  2022-01-27 18:40:52
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
 * BswM_BswMRteModeCanBusState
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BswM_BswMRteVehicleTypeOptionChoose
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ComEx_SignalGroupIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * ComEx_SignalIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
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
#define  DISABLE_RX_PDU_NUMBER                          (6u)
#define  CanServer_Disable_Rx_PDU_Number()              (6u)
#define  VEHICLE_TYPE_FUEL                              ((uint8)(0u))
#define  VEHICLE_TYPE_EV                                ((uint8)(1u))
#define  Com_IPduEnable_VarPtr()                        (Com_Disable_CurrentRxPdu_Record)
#define  Com_IPduEnable_VarCfgPtr()                     (Com_Disable_RxPdu_Receive_Cfg)
#define  Com_SetRxPduEnableFlag(index,value)            ((Com_Disable_CurrentRxPdu_Record.RxPduEnableFlag[index]) = (value))
#define  Com_GetRxPduEnableFlag(index)                  (Com_Disable_CurrentRxPdu_Record.RxPduEnableFlag[index])

extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length);
extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendGroup(ComTxCanPduValueInfor ComTxGroupValueInfor);

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
static Nm_StateType pre_nm_state = NM_STATE_UNINIT;
static const Com_Disable_Pdu_SendorReceive_Info Com_Disable_Pdu_SendorReceive_Cfg = 
{
    {0x19}, //HUT40
};

static const Com_Disable_RxPdu_Receive_Info Com_Disable_RxPdu_Receive_Cfg = 
{
    /* V3.5_SRS_SWR19_HardKey_V2.8_20220127.pdf */
    /*CSA3  BCM6(GW)  BCM11  BCM10  BCM8  STBS1*/
    {
		CanIfConf_CanIfRxPduCfg_CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx,
		CanIfConf_CanIfRxPduCfg_BCM6_oB30_for_SC_CAN_V3_2_f11643ac_Rx,
		CanIfConf_CanIfRxPduCfg_BCM11_oB30_for_SC_CAN_V3_2_6e8f2dfc_Rx,
		0xFFFF,
		CanIfConf_CanIfRxPduCfg_BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx,
		0xFFFF
		
	}, //PduId in Com Layer
    {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE},  //Pdu receive status
    {0x244, 0x28C, 0x305, 0x2E7, 0x29F, 0x21F},  //CanId
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

#define Decimal_to_BCD(dec)    ((((dec) / 10) << 4) + ((dec) % 10))
#define LOCAL_INTERRUPT_CAN    0x200
#define LOCAL_INTERRUPT_LVI    0x20
#define NA_MCU_ISO_RESET       (uint32)0x00000400UL

#define ERR_STATUS_UNSLEEP     0x00
#define ERR_STATUS_WAKEUP      0x01

#define ERR_ABNORMAL_NM        0x00
#define ERR_ABNORMAL_SW        0x01
#define ERR_ABNORMAL_FOTA      0x02

//#define ABNORMAL_NOSLEEP_TIMEOUT 360000  // unit:10ms  360000
#define ABNORMAL_NOSLEEP_TIMEOUT 6000  // unit:10ms  360000
#define ACTIVE_WU_COUNTER_THRESHOLD 20   // 20

#define NETWORK_ABNORMAL_DETECT                 (0u)
#define NETWORK_ABNORMAL_WRITENVM               (1u)
#define NETWORK_ABNORMAL_PENDING                (2u)
#define NETWORK_ABNORMAL_WRITEACTIVEWU          (3u)
#define NETWORK_ABNORMAL_ACTIVEWU_PENDING       (4u)

typedef enum
{
    NA_DTC_STATUS_IDLE = 0,
    NA_DTC_STATUS_PASS,
    NA_DTC_STATUS_FAIL
} NA_DtcStatus;

typedef struct
{
    uint8 Time_Year;
    uint8 Time_Month;
    uint8 Time_Day;
    uint8 Time_Hour;
    uint8 Time_Minutes;
    uint8 Time_Second;
    uint8 RecordType;
    uint8 AwakeReason;
} AbnormalWakeupSleepRecord;

typedef struct
{
    AbnormalWakeupSleepRecord records[10];
    uint8  unsleep_status;
    uint32 unsleep_counter;
    uint8  wakeup_status;
    uint16  wakeup_counter;
    uint8  activeWU_counter;
    uint16  nvm_counter;
    NA_DtcStatus dtcStatus;
}NetWork_Abnormal;

extern uint32 Ecum_RstReason;

NetWork_Abnormal na_data = {0};


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
static FUNC(void, Can_Server_CODE) CanServer_DetermineTxGroup( void );
static void NS_BusOffForSecocMainFunction(void);
static void NS_NetworkBusStateHandle(void);

static CNA_Type cna = {0};

static Std_ReturnType CNA_Init(const CNA_ConfigType *config);
static Std_ReturnType CNA_DeInit(void);

static void CNA_BehaviorNoneHandle(ComEx_SignalIdType cna_Id);
static void CNA_BehaviorUnsendHandle(ComEx_SignalIdType cna_Id);
static void CNA_BehaviorSendHandle(ComEx_SignalIdType cna_Id);
static void CNA_BehaviorCycleHandle(ComEx_SignalIdType cna_Id);

static void Canserver_NetWorkAbnormal_Init(void);
static void CanServer_NetWorkAbnormal_record(uint8 errmode, uint8 errsource);
static void CanServer_NetWorkAbnormal_Unsleep(void);
static void CanServer_NetWorkAbnormal_Wakeup(void);
static void Canserver_NetWorkAbnormal_DtcMonitor(void);

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
 * ComEx_ConstSignalDataType: DataReference
 * ComEx_SignalGroupIdType: Integer in interval [0...65535]
 * ComEx_SignalIdType: Integer in interval [0...65535]
 * Rte_DT_EventSignalInfo_Type_1: Integer in interval [0...255]
 * Rte_DT_EventSignalType_0: Integer in interval [0...65535]
 * Rte_DT_EventSignalType_1: Integer in interval [0...4294967295]
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * sint64: Integer in interval [-9223372036854775808...9223372036854775807] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BswM_BswMRteModeCanBusState: Enumeration of integer in interval [0...255] with enumerators
 *   BLOCK_STATE (0U)
 *   UNBLOCK_STATE (1U)
 * BswM_BswMRteVehicleTypeOptionChoose: Enumeration of integer in interval [0...255] with enumerators
 *   FUEL (0U)
 *   EV (1U)
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
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
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
 *   SYSTEMSTATE_IVI_REMOTE (4U)
 *   SYSTEMSTATE_IVI_DEMO (5U)
 *   SYSTEMSTATE_IVI_AWAKEHOLD (6U)
 *   SYSTEMSTATE_IVI_ON_NORMAL (7U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (8U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (9U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (10U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (11U)
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
 * A_80Bytes: Array with 80 element(s) of type uint8
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * EventSignalList_Type: Array with 30 element(s) of type EventSignalType
 * EventSignalType64Byte: Array with 64 element(s) of type uint8
 * VconfigKind_Allbuffers: Array with 600 element(s) of type uint8
 *
 * Record Types:
 * =============
 * CanFrameCounterType: Record with elements
 *   Counter of type uint16
 *   Data of type uint16
 * DateTimeType_t: Record with elements
 *   u16Year of type uint16
 *   u8Month of type uint8
 *   u8Day of type uint8
 *   u8Hour of type uint8
 *   u8Minutes of type uint8
 *   u8Seconds of type uint8
 *   u8TimeMode of type uint8
 * EventSignalInfo_Type: Record with elements
 *   event_signal_list of type EventSignalList_Type
 *   event_signal_length of type Rte_DT_EventSignalInfo_Type_1
 * EventSignalType: Record with elements
 *   event_id of type Rte_DT_EventSignalType_0
 *   request_value of type Rte_DT_EventSignalType_1
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
 *   uint8 *Rte_Pim_NvBlockNeed_ActiveWUCounter_MirrorBlock(void)
 *   uint8 *Rte_Pim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_80Bytes
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 Rte_CData_NvBlockNeed_ActiveWUCounter_DefaultValue(void)
 *   uint8 *Rte_CData_NvBlockNeed_AbnormalWakeupSleepRecords_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_80Bytes
 *
 *********************************************************************************************************************/


#define Can_Server_START_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CNA_SignalCallBack
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallBack> of PortPrototype <ppCS_CNA_Signal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CNA_SignalCallBack(uint16 signalId)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalCallBack_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CNA_SignalCallBack(uint16 signalId) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalCallBack
 *********************************************************************************************************************/

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

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CNA_SignalGroupSet
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CNA_SignalGroupSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CNA_SignalGroupSet(const EventSignalInfo_Type *event_signal_info)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CNA_SignalGroupSet_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalGroupSet_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalGroupSet(P2CONST(EventSignalInfo_Type, AUTOMATIC, RTE_CAN_SERVER_APPL_DATA) event_signal_info) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalGroupSet (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    ComTxCanPduValueInfor AlcmPduTxCanOutput;
    uint16 index; 
    const CNA_SignalConfigType *signalCfg;
    uint8 addCnt = 0 ;

    uint8  AlcmSigSumNum,AlcmSigNum,PduIdxN,PduNum;
    uint8  AlcmSigIn = 0;
    uint8  PduIdIn = 0;
    uint16 AlcmEventId,PduTemp;
    uint16 ComexSignalId;
    AlcmSigSumNum = event_signal_info->event_signal_length;   
   
    /* error check */
        if((FALSE == cna.isInit) || (NULL_PTR == event_signal_info))
        {
            ret = E_NOT_OK;
        }
        else 
        {
            for(PduNum = 0;PduNum < Com_LINKAGE_Group_NUMBER ;PduNum++)
            {
                AlcmPduTxCanOutput.PduInfor.AlcmPduIndex[PduNum] = 0xffff;
            }

           for(AlcmSigNum = 0; AlcmSigNum < AlcmSigSumNum; AlcmSigNum++)
           {
                PduIdxN = 0;
               AlcmEventId = event_signal_info->event_signal_list[AlcmSigNum].event_id;
        
                if(AlcmEventId >= cna.config->signalNumber)     
                {
                  //do nothing
                }
                else
                {
                    uint8 *AlcmValue = (uint8 *)(&event_signal_info->event_signal_list[AlcmSigNum].request_value);  
                    signalCfg = &cna.config->signalConfigs[AlcmEventId];
                    ComexSignalId = cna.config->signalConfigs[AlcmEventId].comSignalId;  
                                    
                    if(COMEX_TX_PDU_STATUS_START_SEND == ComEx_SignalGetSendStatus(ComexSignalId))
                    {
                        addCnt = 1;
                    } 

                    /* set counter */
                    if(CNA_BEHAVIOR_SEND == signalCfg->behavior)
                    {
                        cna.config->signalDatas[AlcmEventId].counter = (signalCfg->repetition << 1) - 1u + addCnt;
                    }
                    else
                    {
                        cna.config->signalDatas[AlcmEventId].counter = signalCfg->repetition + addCnt;
                    }

                    for(index = 0u; index < cna.config->signalConfigs[AlcmEventId].currentSize; index++)
                    {
                        cna.config->currentBuffer[signalCfg->currentStart + index] = AlcmValue[index];
                    }

                    PduTemp = cna.config->signalConfigs[AlcmEventId].comIPduId;
                    for(PduNum = 0;PduNum < Com_LINKAGE_Group_NUMBER ;PduNum++)
                    {
                        if(AlcmPduTxCanOutput.PduInfor.AlcmPduIndex[PduNum] != PduTemp)
                        {
                            PduIdxN++;                      
                        }
                        else
                        {
                            PduIdxN = 0;
                            break;
                        }
                    }
                    if(PduIdxN == 10)
                    {
                        AlcmPduTxCanOutput.PduInfor.AlcmPduIndex[PduIdIn] = PduTemp;
                        PduIdIn++;
                  //     can_warn("AMPduId =%d", PduTemp);
                    }
                   
                    AlcmPduTxCanOutput.SigInfor[AlcmSigIn].SigId = ComexSignalId;
                    AlcmPduTxCanOutput.SigInfor[AlcmSigIn].SigValue = event_signal_info->event_signal_list[AlcmSigNum].request_value;
                    AlcmSigIn++;

                    // if(( AlcmEventId > 83) && ( AlcmEventId < 101))
                    // {
                    //     can_err("ALCMSig ID=%d,conut = %d",AlcmEventId,cna.config->signalDatas[AlcmEventId].counter);
                    // }

                }              
           }  

            AlcmPduTxCanOutput.AlcmSigSumNum = AlcmSigIn;
            AlcmPduTxCanOutput.PduInfor.AlcmPduSumNum = PduIdIn;
            ComEx_SendGroup(AlcmPduTxCanOutput);
        }   
      return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
 *   Std_ReturnType CNA_SignalSet(uint16 signalId, uint32 *value)
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
        uint16 ComexSignalId = cna.config->signalConfigs[signalId].comSignalId;

        uint8 addCnt = 0 ;

        if(COMEX_TX_PDU_STATUS_START_SEND == ComEx_SignalGetSendStatus(ComexSignalId))
        {
            addCnt = 1;
        } 

        if(CNA_BEHAVIOR_NONE == signalCfg->behavior)
        {
            can_verbose("CNA ID=%d",signalId);
        }
        else
        {
            can_warn("CNA ID=%d",signalId);
        }

        /* set counter */
        if(CNA_BEHAVIOR_SEND == signalCfg->behavior)
        {
            cna.config->signalDatas[signalId].counter = (signalCfg->repetition << 1) - 1u + addCnt;
        }
        else
        {
            cna.config->signalDatas[signalId].counter = signalCfg->repetition + addCnt;
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

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CNA_SignalSetNoTrigger
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CNA_SignalSetNoTrigger>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CNA_SignalSetNoTrigger(uint16 signalId, uint8 *value)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CNA_SignalSetNoTrigger_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSetNoTrigger_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

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
         /*can tool no action test fail: P01OS-130,delete the following code */
        // uint16 ComexSignalId = cna.config->signalConfigs[signalId].comSignalId;

        // uint8 addCnt = 0 ;

        // if(COMEX_TX_PDU_STATUS_START_SEND == ComEx_SignalGetSendStatus(ComexSignalId))
        // {
        //     addCnt = 1;
        // } 

        // /* set counter */
        // if(CNA_BEHAVIOR_SEND == signalCfg->behavior)
        // {
        //     cna.config->signalDatas[signalId].counter = (signalCfg->repetition << 1) - 1u + addCnt;
        // }
        // else
        // {
        //     cna.config->signalDatas[signalId].counter = signalCfg->repetition + addCnt;
        // }

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
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CNA_SignalSet_U8N
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CNA_SignalSet_U8N>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CNA_SignalSet_U8N(uint16 signalId, uint8 *value)
 *     Argument value: uint8* is of type EventSignalType64Byte
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CNA_SignalSet_U8N_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSet_U8N_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSet_U8N(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) value) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSet_U8N (returns application error)
 *********************************************************************************************************************/

     Std_ReturnType ret = RTE_E_OK;
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
        uint16 ComexSignalId = cna.config->signalConfigs[signalId].comSignalId;
        uint8 addCnt = 0 ;
        if(COMEX_TX_PDU_STATUS_START_SEND == ComEx_SignalGetSendStatus(ComexSignalId))
        {
            addCnt = 1;
        } 
        can_warn("CNA ID=%d",signalId);
        if(CNA_BEHAVIOR_SEND == signalCfg->behavior)
        {
			cna.config->signalDatas[signalId].counter = (signalCfg->repetition << 1) - 1u + addCnt;
        }
        else
        {
			cna.config->signalDatas[signalId].counter = signalCfg->repetition + addCnt;
        }
        for(index = 0u; index < cna.config->signalConfigs[signalId].currentSize; index++)
        {
            cna.config->currentBuffer[signalCfg->currentStart + index] = ((uint8 *)value)[index];
        }
        if(CNA_BEHAVIOR_CYCLE == signalCfg->behavior)
        {
            Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(signalId, value);
        }
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
 *   Std_ReturnType Rte_Read_Vconfig_GetKindBuffers_AllKinds(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_Allbuffers
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Request_VehicleTypeOptionChoose_requestedMode(BswM_BswMRteVehicleTypeOptionChoose data)
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
    CanServer_DetermineTxGroup();
    CanServer_SecOCBusOffEndStatusSet(FALSE);
    CNA_Init(&cna_config);
    Com_IPduReceiveCallout_Init();
    MD_Init();

    Canserver_NetWorkAbnormal_Init();
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
 *   Std_ReturnType Rte_Read_Can_Server_piDiagMonitorReInitFlag_ChangeCounter(uint32 *data)
 *   Std_ReturnType Rte_Read_KL30BRelaySts_KL30BRelaySts(KL30BRelaySts *data)
 *   Std_ReturnType Rte_Read_RemoteModSts_RemoteModSts(RemoteModSts *data)
 *   Std_ReturnType Rte_Read_SysPowerMod_SysPowerMod(SysPowerMod *data)
 *   Std_ReturnType Rte_Read_SysPowerModVld_SysPowerModVld(SysPowerModVld *data)
 *   Std_ReturnType Rte_Read_rpSR_RTCTimer_UtcTime(sint64 *data)
 *   Std_ReturnType Rte_Read_rpSR_WakeupReason_data(wakeup_type *data)
 *   Std_ReturnType Rte_Read_tiSR_Power_Out_SystemStateOut(SystemState_RecordType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Request_CanBusStateReq_requestedMode(BswM_BswMRteModeCanBusState data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void)
 *   Modes of Rte_ModeType_DcmDiagnosticSessionControl:
 *   - RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession
 *   - RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_UFSKeepProgrammingSession
 *   - RTE_TRANSITION_DcmDiagnosticSessionControl
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_cpCS_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IRTC_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, uint8 *SignalDataPtr, uint8 Length)
 *     Argument SignalDataPtr: uint8* is of type ComEx_SignalDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED, RTE_E_ComEx_COMEX_NEVER_RECEIVED, RTE_E_ComEx_COMEX_UPDATE_RECEIVED, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
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
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
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
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_SetEventStatus(Dem_EventStatusType EventStatus)
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
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_SetEventStatus(Dem_EventStatusType EventStatus)
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
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_SetEventStatus(Dem_EventStatusType EventStatus)
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
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
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
    NS_NetworkBusStateHandle();

    CanServer_NetWorkAbnormal_Unsleep();
    CanServer_NetWorkAbnormal_Wakeup();
    Canserver_NetWorkAbnormal_DtcMonitor();

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

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Can_Server_AbnormalWakeupSleepRecord_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <Can_Server_AbnormalWakeupSleepRecord>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Can_Server_AbnormalWakeupSleepRecord_Get(uint8 *data)
 *     Argument data: uint8* is of type A_80Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Can_Server_AbnormalWakeupSleepRecord_Get_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) Can_Server_AbnormalWakeupSleepRecord_Get(P2VAR(uint8, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Can_Server_AbnormalWakeupSleepRecord_Get
 *********************************************************************************************************************/
    (void)memcpy((uint8 *)data, (uint8*)Rte_Pim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock(), sizeof(A_80Bytes));

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished
 *********************************************************************************************************************/
    can_warn("AbnormalWakeupSleepRecords_JobFinished %d, %d", ServiceId, JobResult);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished
 *********************************************************************************************************************/
    can_warn("ActiveWUCounter_JobFinished %d, %d", ServiceId, JobResult);
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
    can_warn("Busoff end");
}

FUNC(void, CANSM_APPL_CODE) CanServer_BusOffBegin( NetworkHandleType  NetworkHandle, P2VAR(uint8, AUTOMATIC, CANSM_APPL_VAR) OnlineDelayCyclesPtr )
{
    can_warn("Busoff begin");
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

static void NS_NetworkBusStateHandle(void)
{/* Add for first frame is not NM frame */
    Std_ReturnType canNmRet = E_OK;
    Nm_StateType nmState = NM_STATE_UNINIT;
    Nm_ModeType nmMode = NM_STATE_UNINIT;
    canNmRet = CanNm_GetState(0, &nmState, &nmMode);
     if(E_OK == canNmRet)
     {
         if((nmState == NM_STATE_PREPARE_BUS_SLEEP) || (nmState == NM_STATE_BUS_SLEEP) || (nmState == NM_STATE_UNINIT))
         {
            if((pre_nm_state != NM_STATE_PREPARE_BUS_SLEEP) && (pre_nm_state != NM_STATE_BUS_SLEEP))
            { 
                Rte_Write_Request_CanBusStateReq_requestedMode(BLOCK_STATE);
            }
         }
         else
         {
         }
         pre_nm_state = nmState;
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
    boolean                 Dcm_State = FALSE;

    ComM_GetDcmRequestStatus(0u,&Dcm_State);
	
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
        
        if(((pre_nm_state == NM_STATE_PREPARE_BUS_SLEEP) || (pre_nm_state == NM_STATE_BUS_SLEEP)) && (Cannm_Status >= NM_STATE_READY_SLEEP))
        {
            Rte_Write_Request_CanBusStateReq_requestedMode(UNBLOCK_STATE);
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
        || (TRUE == Dcm_State)
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
* @brief   :   determine Tx group
* @param   :   none
* @retval  :   none
*/
static FUNC(void, Can_Server_CODE) CanServer_DetermineTxGroup( void )
{
    VconfigKind_Allbuffers VConfigInfo = {0x00};
    uint8 u8ret = E_NOT_OK;

    /* Get vehicle type configuration info and determine Tx group */
    u8ret = Rte_Read_Vconfig_GetKindBuffers_AllKinds(VConfigInfo);
    if (E_NOT_OK != u8ret)
    {
        if ((0x3 != (VConfigInfo[VCONFIG_KIND_FUEL])) && (0x4 != (VConfigInfo[VCONFIG_KIND_FUEL])))
        {
            Rte_Write_Request_VehicleTypeOptionChoose_requestedMode(VEHICLE_TYPE_FUEL);
        }
        else
        {
            Rte_Write_Request_VehicleTypeOptionChoose_requestedMode(VEHICLE_TYPE_EV);
        }
    }
    else
    {
        /* Default Tx Group */
        Rte_Write_Request_VehicleTypeOptionChoose_requestedMode(VEHICLE_TYPE_FUEL);
    }
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
            can_verbose("CNA ID=%d,value=%d",cna_Id,cna.config->currentBuffer[signalCfg->currentStart]);
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
    md_cfg.messages[MD_MESSAGE_NMRANGE].status = MD_MESSAGE_STATUS_NOT_DETERMINED;

    /* read vconfig */
    Rte_Read_Vconfig_GetKindBuffers_AllKinds(md_cfg.vconfig);

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

    can_warn("Missing DTC reset");
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
                            can_warn("Dtc %d report fail", dtcId);
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
                            can_warn("Dtc %d report success", dtcId);
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
                can_warn("NS active ign on recovery");
            }
        }
        break;

        case NS_STATUS_ACTIVE_IGN_ON_RECOVERY:
        {
            if(NS_SIGNAL_NOT_OK(kL15RetStatus) || (DIAG_SYSTEM_POWER_MODE != kL15Value))
            {
                ns_data.activeData.statusIgn = NS_STATUS_ACTIVE_IGN_OFF;
                ns_data.activeData.countIgn = ns_cfg.activeCfg.countIgn;
                can_warn("NS active ign off");
            }
            else
            {
                if(ns_data.activeData.countIgn > 0u)
                {
                    ns_data.activeData.countIgn--;
                    if(ns_data.activeData.countIgn == 0u)
                    {
                        ns_data.activeData.statusIgn = NS_STATUS_ACTIVE_IGN_ON;
                        can_warn("NS active ign on");
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
                can_warn("NS active ign off");
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
                can_warn("NS active voltage abnormal");
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
                        can_warn("Busoff prepassed");
                    }
                    else 
                    {
                        ns_data.busOffData.countPass = 0;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREFAILED;
                        can_warn("Busoff prefailed");
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
                                can_warn("Event report BusOff pass");
                            }
                        }
                    }
                    else
                    {
                        ns_data.busOffData.countPass = 0u;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREFAILED;
                        can_warn("Busoff prefailed");
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
                        can_warn("Busoff prefailed");
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
                        can_warn("Busoff prepassed");
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
                                can_warn("Event report BusOff fail");
                            }
                        }
                    }
                }
            }
            break;

            case NS_STATUS_BUSOFF_FAILED:
            {
                if(E_OK == retBor)
                {
                    if(CANSM_BOR_NONE == bor)
                    {
                        ns_data.busOffData.countPass = 0u;
                        ns_data.busOffData.countFail = 0u;
                        ns_data.busOffData.statusBusOff = NS_STATUS_BUSOFF_PREPASSED;
                        can_warn("Busoff prepassed");
                    }
                }

                if(ns_data.busOffData.reportcounter <= BUSOFF_REPORT_CYC)
                {
                    ns_data.busOffData.reportcounter++;
                    if(ns_data.busOffData.reportcounter >= BUSOFF_REPORT_CYC)
                    {
                        ns_data.busOffData.reportcounter = 0u;
                        retDTC = Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(DEM_EVENT_STATUS_FAILED);
                        can_verbose("Cycle report BusOff fail");
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

    if(E_OK == retBor)
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

boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId)
{
    Com_RxPdu_SizeOfType   PduIdIndex = 0x00;
    Com_RxPdu_SizeOfType   CanIdMapIndex = 0xFF;
    boolean                retValue = (boolean)E_OK;
    Com_Disable_RxPdu_Receive_Info Com_Disable_CurrentRxPdu_Cfg;
    Com_Disable_RxPdu_Receive_Info Com_Disable_CurrentRxPdu_Local;
    
    Com_Disable_CurrentRxPdu_Cfg = Com_IPduEnable_VarCfgPtr();
    Com_Disable_CurrentRxPdu_Local = Com_IPduEnable_VarPtr();

    /* get index CanId in arr*/
    for(PduIdIndex = 0x00; PduIdIndex < CanServer_Disable_Rx_PDU_Number();PduIdIndex++)
    {
        if((Com_Disable_CurrentRxPdu_Cfg.RxPduId[PduIdIndex]) == PduId)
        {
            CanIdMapIndex = PduIdIndex;
        }
    }

    if(CanIdMapIndex != 0xFF)
    {
        if(Com_Disable_CurrentRxPdu_Local.RxPduEnableFlag[CanIdMapIndex])
        {
            /* disable notify Up Layer*/
            retValue = E_NOT_OK;
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

static void Canserver_NetWorkAbnormal_Init(void)
{
    uint8 i = 0;

    na_data.unsleep_counter = 0u;
    na_data.wakeup_counter  = 0u;
    na_data.nvm_counter     = 0u;
    na_data.unsleep_status  = NETWORK_ABNORMAL_DETECT;
    na_data.wakeup_status   = NETWORK_ABNORMAL_DETECT;
    na_data.dtcStatus       = NA_DTC_STATUS_IDLE;

    na_data.activeWU_counter = *Rte_Pim_NvBlockNeed_ActiveWUCounter_MirrorBlock();

    (void)memcpy((uint8 *)&na_data.records[0],(uint8*)Rte_Pim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock(), sizeof(A_80Bytes));

    can_warn("NA activeWU counter = %d", na_data.activeWU_counter);
    for(i = 0; i < 10; i++)
    {
        can_info("NA record %d, %s", i+1, Hex2Str((uint8*)&na_data.records[i], sizeof(AbnormalWakeupSleepRecord)));
    }
}

static void CanServer_NetWorkAbnormal_record(uint8 recordType, uint8 awakeReason)
{
    uint8 i = 0u;
    sint64 tUtcTime;
    DateTimeType_t currentDate;

    Rte_Read_rpSR_RTCTimer_UtcTime(&tUtcTime);
    Rte_Call_cpCS_IRTC_Service_UTC2PerpetualCalendar(tUtcTime, &currentDate);

    // new record
    na_data.records[0].Time_Year    = Decimal_to_BCD(currentDate.u16Year % 100u);
    na_data.records[0].Time_Month   = Decimal_to_BCD(currentDate.u8Month + 1);
    na_data.records[0].Time_Day     = Decimal_to_BCD(currentDate.u8Day);
    na_data.records[0].Time_Hour    = Decimal_to_BCD(currentDate.u8Hour);
    na_data.records[0].Time_Minutes = Decimal_to_BCD(currentDate.u8Minutes);
    na_data.records[0].Time_Second  = Decimal_to_BCD(currentDate.u8Seconds);
    na_data.records[0].RecordType   = recordType;
    na_data.records[0].AwakeReason  = awakeReason;

    // history record
    (void)memcpy((uint8 *)&na_data.records[1],(uint8*)Rte_Pim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock(), (sizeof(A_80Bytes)-8));

    // dtc
    na_data.dtcStatus = NA_DTC_STATUS_FAIL;
    Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    can_warn("NA 0xF01200 report FAIL");

    for(i = 0; i < 10; i++)
    {
        can_info("NA append record %d, %s", i+1, Hex2Str((uint8*)&na_data.records[i], sizeof(AbnormalWakeupSleepRecord)));
    }
}


static void CanServer_NetWorkAbnormal_Unsleep(void)
{
    uint8 err_status = 0u;
    NvM_RequestResultType NvmStatus = NVM_REQ_NOT_OK;
    uint8 fctRet = E_NOT_OK;

    switch(na_data.unsleep_status)
    {
        case NETWORK_ABNORMAL_DETECT:
            if((NS_STATUS_ACTIVE_IGN_ON == ns_data.activeData.statusIgn) && (md_cfg.messages[MD_MESSAGE_NMRANGE].status == MD_MESSAGE_STATUS_OK_CONFIRM))
            {
                na_data.unsleep_counter = 0u;
                na_data.dtcStatus = NA_DTC_STATUS_PASS;
            }
            else if((NS_STATUS_ACTIVE_IGN_ON != ns_data.activeData.statusIgn) || (md_cfg.messages[MD_MESSAGE_NMRANGE].status == MD_MESSAGE_STATUS_MISSING_CONFIRM))
            {
                if(na_data.unsleep_counter < ABNORMAL_NOSLEEP_TIMEOUT)
                {
                    na_data.unsleep_counter++;
                    if(0 == na_data.unsleep_counter%6000) // 1min
                    {
                        can_warn("NA unsleep_counter++ %d", na_data.unsleep_counter);
                    }
                    if(na_data.unsleep_counter == ABNORMAL_NOSLEEP_TIMEOUT)
                    {
                        if(1u == Power_FotaSts_Get())
                        {
                            err_status = ERR_ABNORMAL_FOTA;
                        }
                        else if(md_cfg.messages[MD_MESSAGE_NMRANGE].status == MD_MESSAGE_STATUS_OK_CONFIRM)
                        {
                            err_status = ERR_ABNORMAL_NM;
                        }
                        else
                        {
                            err_status = ERR_ABNORMAL_SW;
                        }
                        na_data.unsleep_status = NETWORK_ABNORMAL_WRITENVM;
                        CanServer_NetWorkAbnormal_record(ERR_STATUS_UNSLEEP, err_status);
                    }
                }
            }
        break;

        case NETWORK_ABNORMAL_WRITENVM:
            /*  write nvm */
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_GetErrorStatus(&NvmStatus);
            if((E_OK == fctRet) && (NVM_REQ_PENDING != NvmStatus))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock(), (uint8 *)na_data.records, sizeof(A_80Bytes));
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_WriteBlock(NULL_PTR);
                na_data.nvm_counter = 0u;
                na_data.unsleep_status  = NETWORK_ABNORMAL_PENDING;
                can_warn("NA unsleep record WriteBlock");
            }
            else
            {
                na_data.unsleep_status  = NETWORK_ABNORMAL_DETECT;
                na_data.unsleep_counter = ABNORMAL_NOSLEEP_TIMEOUT - 30000;
                can_warn("NA unsleep record write failed!");
            }
        break;

        case NETWORK_ABNORMAL_PENDING:
            na_data.nvm_counter++;
            if(na_data.nvm_counter < 200u)
            {
                fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_GetErrorStatus(&NvmStatus);
                if((E_OK == fctRet)&&(NVM_REQ_OK == NvmStatus))
                {
                    na_data.unsleep_status  = NETWORK_ABNORMAL_DETECT;
                }
            }
            else
            {
                na_data.unsleep_status  = NETWORK_ABNORMAL_DETECT;
                can_warn("NA unsleep record write timeout!");
            }
        break;

        default:
        break;
    }
    
}

static void CanServer_NetWorkAbnormal_Wakeup(void)
{
    volatile uint32 Loc_WakeUp_CAN = *((volatile unsigned long *)0xfff80400UL);
    volatile uint32 Loc_WakeUp_LVI = *((volatile unsigned long *)0xFFF80410UL);
    uint8 DatafctRet     = E_NOT_OK;
    uint8 ActiveWUfctRet = E_NOT_OK;
    NvM_RequestResultType DataNvmStatus     = NVM_REQ_NOT_OK;
    NvM_RequestResultType ActiveWUNvmStatus = NVM_REQ_NOT_OK;

    switch(na_data.wakeup_status)
    {
        case NETWORK_ABNORMAL_DETECT:
            if(  (0 != (Ecum_RstReason & NA_MCU_ISO_RESET))
               &&(LOCAL_INTERRUPT_CAN != (Loc_WakeUp_CAN & LOCAL_INTERRUPT_CAN))
               &&(LOCAL_INTERRUPT_LVI != (Loc_WakeUp_LVI & LOCAL_INTERRUPT_LVI))
              )
            {
                if(na_data.wakeup_counter < 1000u) // 1000u
                {
                    na_data.wakeup_counter++;
                    if(na_data.wakeup_counter == 1000u)
                    {
                        //na_data.wakeup_counter = 0u;
                        na_data.activeWU_counter++;
                        if(na_data.activeWU_counter >= ACTIVE_WU_COUNTER_THRESHOLD)
                        {
                            na_data.activeWU_counter = ACTIVE_WU_COUNTER_THRESHOLD;
                        }
                        na_data.wakeup_status  = NETWORK_ABNORMAL_WRITEACTIVEWU;
                        can_warn("NA activeWU_counter add!, 0x%x, %x, %x", Ecum_RstReason, Loc_WakeUp_CAN, Loc_WakeUp_LVI);
                    }
                }
            }
            else if(NS_STATUS_ACTIVE_IGN_ON == ns_data.activeData.statusIgn)
            {
                if(na_data.activeWU_counter != 0u)
                {
                    na_data.activeWU_counter = 0u;
                    na_data.wakeup_status  = NETWORK_ABNORMAL_WRITEACTIVEWU;
                }
            }
        break;

        case NETWORK_ABNORMAL_WRITEACTIVEWU:
            ActiveWUfctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_GetErrorStatus(&ActiveWUNvmStatus);
            if((E_OK == ActiveWUfctRet) && (NVM_REQ_PENDING != ActiveWUNvmStatus))
            {
                *Rte_Pim_NvBlockNeed_ActiveWUCounter_MirrorBlock() = na_data.activeWU_counter;
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_WriteBlock(NULL_PTR);
                na_data.nvm_counter = 0u;
                na_data.wakeup_status  = NETWORK_ABNORMAL_ACTIVEWU_PENDING;
                can_warn("NA activeWU_counter %d WriteBlock.", na_data.activeWU_counter);
            }
            else
            {
                if(na_data.activeWU_counter >= ACTIVE_WU_COUNTER_THRESHOLD)
                {
                    na_data.wakeup_status  = NETWORK_ABNORMAL_WRITENVM;
                }
                else
                {
                    na_data.wakeup_status  = NETWORK_ABNORMAL_DETECT;
                }

                can_warn("NA activeWU_counter write failed!");
            }
        break;

        case NETWORK_ABNORMAL_ACTIVEWU_PENDING:
            na_data.nvm_counter++;
            if(na_data.nvm_counter < 200u)
            {
                ActiveWUfctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ActiveWUCounter_GetErrorStatus(&ActiveWUNvmStatus);
                if((E_OK == ActiveWUfctRet) && (NVM_REQ_OK == ActiveWUNvmStatus))
                {
                    if(na_data.activeWU_counter >= ACTIVE_WU_COUNTER_THRESHOLD)
                    {
                        // na_data.activeWU_counter = 0u;
                        na_data.wakeup_status  = NETWORK_ABNORMAL_WRITENVM;
                    }
                    else
                    {
                        na_data.wakeup_status  = NETWORK_ABNORMAL_DETECT;
                    }
                }
            }
            else
            {
                if(na_data.activeWU_counter >= ACTIVE_WU_COUNTER_THRESHOLD)
                {
                    na_data.wakeup_status  = NETWORK_ABNORMAL_WRITENVM;
                }
                else
                {
                    na_data.wakeup_status  = NETWORK_ABNORMAL_DETECT;
                }
                can_warn("NA activeWU_counter write timeout!");
            }
        break;

        case NETWORK_ABNORMAL_WRITENVM:
            CanServer_NetWorkAbnormal_record(ERR_STATUS_WAKEUP, ERR_ABNORMAL_SW);
            DatafctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_GetErrorStatus(&DataNvmStatus);
            if((NVM_REQ_PENDING != DataNvmStatus)&&(E_OK == DatafctRet))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock(), (uint8 *)na_data.records, sizeof(A_80Bytes));
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_WriteBlock(NULL_PTR);
                na_data.nvm_counter = 0u;
                na_data.wakeup_status  = NETWORK_ABNORMAL_PENDING;
                can_warn("NA wakeup record WriteBlock.");
            }
            else
            {
                na_data.wakeup_status  = NETWORK_ABNORMAL_DETECT;
                can_warn("NA wakeup record write failed!");
            }
            
        break;

        case NETWORK_ABNORMAL_PENDING:
            na_data.nvm_counter++;
            if(na_data.nvm_counter < 200u)
            {
                DatafctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_AbnormalWakeupSleepRecords_GetErrorStatus(&DataNvmStatus);
                if((E_OK == DatafctRet)&&(NVM_REQ_OK == DataNvmStatus))
                {
                    na_data.wakeup_status  = NETWORK_ABNORMAL_DETECT;
                }
            }
            else
            {
                na_data.wakeup_status  = NETWORK_ABNORMAL_DETECT;
                can_warn("NA wakeup record write timeout!");
            }
        break;

        default:
        break;
    }
}

void Canserver_NetWorkAbnormal_DtcMonitor(void)
{
    Std_ReturnType retDTC = E_NOT_OK;
    static uint8 time100ms = 0;
    static uint8 dtcStatusLast = NA_DTC_STATUS_IDLE;

    if ((10 < time100ms++) || (dtcStatusLast != na_data.dtcStatus))
    {
        time100ms = 0;
        if (NA_DTC_STATUS_PASS == na_data.dtcStatus)
        {
            retDTC = Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_SetEventStatus(DEM_EVENT_STATUS_PASSED);
        }
        else if (NA_DTC_STATUS_FAIL == na_data.dtcStatus)
        {
            retDTC = Rte_Call_DiagnosticMonitor_AbnormalWakeupSleep_0xF01200_SetEventStatus(DEM_EVENT_STATUS_FAILED);
        }
        if((retDTC == E_OK) && (dtcStatusLast != na_data.dtcStatus))
        {
            dtcStatusLast = na_data.dtcStatus;
            can_warn("NA 0xF01200 report %s ", na_data.dtcStatus == NA_DTC_STATUS_FAIL ? "FAIL" : "PASS");
        }
    }
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
