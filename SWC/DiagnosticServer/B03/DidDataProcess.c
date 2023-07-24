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
 *             File:  DidDataProcess.c
 *           Config:  D:/Gerrit/VIPpro/B03_1/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  DidDataProcess
 *  Generation Time:  2021-04-21 17:40:01
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <DidDataProcess>
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
 * Dcm_DataElement_Data_E2ESwitchType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_DataElement_Data_E2ESwitch_PrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_DataElement_Data_SecOcSwitchType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_DataElement_Data_SecOcSwitch_PrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
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
 *********************************************************************************************************************/

#include "Rte_DidDataProcess.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "IPC_Diagnose.h"
#include "Version.h"
#include "SecOc.h"
#include "Vconfig_cfg.h"
/*DCM generi return code*/

#define DCM_E_OK                                                    ((Std_ReturnType)E_OK)       /*!< Successful operation */
#define DCM_E_NOT_OK                                                ((Std_ReturnType)E_NOT_OK)   /*!< Failed operation with no specific reason (except when NRC is returned in addition) */
#define DCM_E_PENDING                                               ((Std_ReturnType)10)         /*!< Invoked callout (operation) needs to be called again */
#define DCM_E_FORCE_RCRRP                                           ((Std_ReturnType)12)         /*!< Invoked callout (operation) requests an immediate RCR-RP response transmission and needs to be called again once it is (successfully or not) sent */
#define ROUTINE_CONTROL_TYPE_START          (1u)  
#define ROUTINE_CONTROL_TYPE_STOP           (2u)
#define ROUTINE_CONTROL_TYPE_GERESULT       (3u)
#define READ_SOC_DATA_MAX_TIME              (950u)
#define WRITE_SOC_DATA_MAX_TIME             (950u)
#define SPARE_PART_NUMBER_SIZE              (13u)
#define SPARE_PART_START_POSITION           (16u)
#define FACTORY_WORK_MODE                   (1u)
#define NORMAL_WORK_MODE                    (2u)
#define IVI_DATA_MAX_SIZE                   (500u)
#define IPC_MAX_BUF_SIZE                    (4000u)
#define WORKING_FACTORY_MODE                (1u)
#define WORKING_NORMAL_MODE                 (2u)
#define QNX_RSP_ROUTINECTRL_OK              (1u)
#define QNX_RSP_ROUTINECTRL_ERR             (0u)
#define WORK_MODE_MONITOR_PERIOD            (10u)  /*(10*10 = 100ms)*/


typedef struct LargeDataTransmitManger{
    uint16 dataLen;
    uint16 dataIndx;
    uint16 remainingDataLen;
    uint16 waitIviRspTime;
    uint8 sequenceCount;
}LargeDataTransmitManger_t;

typedef enum RoutineIdIndexMun{
    ROUTINEIDINDEX_A1A1  = 0u,
    ROUTINEIDINDEX_A1A2,
    ROUTINEIDINDEX_A1A3,
    ROUTINEIDINDEX_F030,
    ROUTINEIDINDEX_F031,
    ROUTINEIDINDEX_F033,
    ROUTINEIDINDEX_F035,
    ROUTINEIDINDEX_F036,
    ROUTINEIDINDEX_F037,
    ROUTINEIDINDEX_F038,
    ROUTINEIDINDEX_FD20,
    ROUTINEIDINDEX_FD21,
    ROUTINEIDINDEX_F020,
    ROUTINEIDINDEX_F021,
    ROUTINEIDINDEX_F022,
    ROUTINEIDINDEX_F023,
    
    ROUTINEIDINDEX_INVAILD
}RoutineIdIndexMun_t;


static LargeDataTransmitManger_t  writeIviDataManger;
static LargeDataTransmitManger_t  readIviDataManger;

static IPC_M2S_DiagnoseIVIDidWriteRequest_t iviWriteDataRequest;
static IPC_S2M_DiagnoseIVIDidWriteResponse_t iviWriteDataResponse;
static IPC_M2S_DiagnoseIVIDidReadRequest_t iviReadDataRequest;
static IPC_S2M_DiagnoseIVIDidReadResponse_t iviReadDataResponse;
static uint8 ipcDataBuf[IPC_MAX_BUF_SIZE] = {0};

    
static IPC_M2S_DiagnoseQNXDidReadRequest_t didReadRequest;
static IPC_S2M_DiagnoseQNXDidReadResponse_t didReadRsp;
static IPC_M2S_DiagnoseQNXDidWriteRequest_t didWriteRequest;
static IPC_S2M_DiagnoseQNXDidWriteResponse_t didWriteRsp;

static IPC_M2S_DiagnoseQNXRoutineControlRequest_t routineCtrlRequest;
static IPC_S2M_DiagnoseQNXRoutineControlResponse_t routineCtrlRsp;

static uint8 currentDiagnosticSession = 0;
static uint16 diagWaitSocRspTime = 0;
static uint8 workModeMonitorCnt = 0;
static uint8 factorModeWriteE2EReq = FALSE;
static uint8 factorModeWriteSecOcReq = FALSE;
static uint8 WriteVconfigRequestCounter = 0;
static uint8 WriteCconfigRequestCounter = 0;
static uint8 vConfigDataBuf[400]= {0};
static uint8  ridResetStartFlag[ROUTINEIDINDEX_INVAILD]= {0};



//static void IPC_Call_Diagnose_ReceiveData(uint8 msgMajorId, uint8 msgSubId, uint8 *param, uint16 paramLen);

static Std_ReturnType ReadQnxDidDataRequestProcess(uint16 DataId,uint8 OpStatus,uint8* ErrorCode);
static Std_ReturnType CopyQnxDidRspData(uint16 DataId,uint8* Data,uint16 Length);

static Std_ReturnType WriteQnxDidDataRequestProcess(uint16 DataId,uint8 OpStatus, const uint8 *Data,uint16 dataLen,uint8* ErrorCode);
static Std_ReturnType ReadVipDidDataReqProcess(uint16 DataId,uint8 OpStatus,uint8 *Data,uint16 Length);
static void RequestQnxRoutineControl(uint16 RoutineId,uint8 Type,const uint8* Option,uint8 OptionLen);
static Std_ReturnType QnxResponseRoutineControl(uint8* Status,uint8 StatusLen,uint8* ErrorCode);

static Std_ReturnType WriteIVIDidDataProcess(uint16 DataId,uint8 OpStatus, const uint8 *Data,uint16 dataLen);
static Std_ReturnType ReadIVIDidDataStart(uint16 DataId,Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength);
static Std_ReturnType ReadIVIDidDataRepeate(uint8 OpStatus, uint8 *Data);
static Std_ReturnType ReadIVIDidDataFixLengthProcess(uint16 DataId,uint8 OpStatus,uint8 *Data,uint16 Length);
static void ReceiveIVIResponseData(void);
static Std_ReturnType SocRspTimeOutHandle(uint8 OpStatus);


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
 * Dcm_DataElement_Data_E2ESwitchType: Integer in interval [0...255]
 * Dcm_DataElement_Data_E2ESwitch_PrimitiveType: Integer in interval [0...255]
 * Dcm_DataElement_Data_SecOcSwitchType: Integer in interval [0...255]
 * Dcm_DataElement_Data_SecOcSwitch_PrimitiveType: Integer in interval [0...255]
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...254] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_AUTHENTICATIONREQUIRED (52U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_CVF_INVALIDTIMEPERIOD (80U)
 *   DCM_E_CVF_INVALIDSIGNATURE (81U)
 *   DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
 *   DCM_E_CVF_INVALIDTYPE (83U)
 *   DCM_E_CVF_INVALIDFORMAT (84U)
 *   DCM_E_CVF_INVALIDCONTENT (85U)
 *   DCM_E_CVF_INVALIDSCOPE (86U)
 *   DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
 *   DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
 *   DCM_E_CHALLENGECALCULATIONFAILED (89U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...64] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 *   DCM_FORCE_RCRRP_NOT_OK (64U)
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
 * SysPowerMod: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ACC_reserved_ (1U)
 *   Cx2_ON (2U)
 *   Cx3_Crank (3U)
 * SysPowerModVld: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Invalid (0U)
 *   Cx1_Valid (1U)
 *
 * Array Types:
 * ============
 * A_17Bytes: Array with 17 element(s) of type uint8
 * A_1Bytes: Array with 1 element(s) of type uint8
 * A_28Bytes: Array with 28 element(s) of type uint8
 * A_8Bytes: Array with 8 element(s) of type uint8
 * Dcm_Data10ByteType: Array with 10 element(s) of type uint8
 * Dcm_Data13ByteType: Array with 13 element(s) of type uint8
 * Dcm_Data15ByteType: Array with 15 element(s) of type uint8
 * Dcm_Data17ByteType: Array with 17 element(s) of type uint8
 * Dcm_Data18ByteType: Array with 18 element(s) of type uint8
 * Dcm_Data19ByteType: Array with 19 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data200ByteType: Array with 200 element(s) of type uint8
 * Dcm_Data2048ByteType: Array with 2048 element(s) of type uint8
 * Dcm_Data20ByteType: Array with 20 element(s) of type uint8
 * Dcm_Data228ByteType: Array with 228 element(s) of type uint8
 * Dcm_Data28ByteType: Array with 28 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data3000ByteType: Array with 3000 element(s) of type uint8
 * Dcm_Data300ByteType: Array with 300 element(s) of type uint8
 * Dcm_Data30ByteType: Array with 30 element(s) of type uint8
 * Dcm_Data32ByteType: Array with 32 element(s) of type uint8
 * Dcm_Data39ByteType: Array with 39 element(s) of type uint8
 * Dcm_Data3ByteType: Array with 3 element(s) of type uint8
 * Dcm_Data40ByteType: Array with 40 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_Data5ByteType: Array with 5 element(s) of type uint8
 * Dcm_Data6ByteType: Array with 6 element(s) of type uint8
 * Dcm_Data8ByteType: Array with 8 element(s) of type uint8
 * Dcm_Data9ByteType: Array with 9 element(s) of type uint8
 * Diag_9Bytes: Array with 9 element(s) of type uint8
 * EOL_13Bytes: Array with 13 element(s) of type uint8
 * Rte_DT_s_OdoRteGetParament_t_2: Array with 3 element(s) of type uint32
 * Rte_DT_s_OdoRteGetParament_t_3: Array with 3 element(s) of type uint32
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 *
 * Record Types:
 * =============
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
 * s_OdoRteGetParament_t: Record with elements
 *   OdoKmValue_u32 of type uint32
 *   OdoMileValue_u32 of type uint32
 *   TripKmValue_u32 of type Rte_DT_s_OdoRteGetParament_t_2
 *   TripMileValue_u32 of type Rte_DT_s_OdoRteGetParament_t_3
 *   FsrvKmValue_s32 of type sint32
 *   FsrvMileValue_s32 of type sint32
 *   OdoTripIsaInvalid of type uint8
 *   OdoInputlValid of type uint8
 *   NvmBlockWriteFlag of type uint32
 *   ClearData_u32 of type uint32
 *   FsrvStatus of type uint8
 *   RunCounter_u8 of type uint8
 *   VinCheckFlag_u8 of type uint8
 *   ClearFlag_u8 of type uint8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data300ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data200ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data4ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_VIN_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_17Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data20ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data30ByteType
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_NvBlockNeed_ClusterInternalConfiguration_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data300ByteType
 *   uint8 *Rte_CData_NvBlockNeed_E2ESwitch_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *   uint8 *Rte_CData_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data200ByteType
 *   uint8 *Rte_CData_NvBlockNeed_FactoryMode_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_HUTInternalConfiguration_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data4ByteType
 *   uint8 *Rte_CData_NvBlockNeed_MasterSlaveStatus_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_8Bytes
 *   uint8 *Rte_CData_NvBlockNeed_SecOcSwitch_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *   uint8 *Rte_CData_NvBlockNeed_SwitchARLTable_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_28Bytes
 *   uint8 *Rte_CData_NvBlockNeed_VIN_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_17Bytes
 *   uint8 *Rte_CData_NvBlockNeed_VehicleMode_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data20ByteType
 *   uint8 *Rte_CData_NvBlockNeed_VehicleSoftwareVersion_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data30ByteType
 *
 *********************************************************************************************************************/


#define DidDataProcess_START_SEC_CODE
#include "DidDataProcess_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AppGetVinNumberFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_GetVinNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AppGetVinNumberFunction(uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AppGetVinNumberFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) AppGetVinNumberFunction(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AppGetVinNumberFunction
 *********************************************************************************************************************/
    (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_VIN_MirrorBlock(),sizeof(Dcm_Data17ByteType));

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_CMatrixVersion_CMatrixVersion_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_CMatrixVersion_CMatrixVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_CMatrixVersion_CMatrixVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_CMatrixVersion_CMatrixVersion_DCM_E_PENDING
 *   RTE_E_DataServices_CMatrixVersion_CMatrixVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CMatrixVersion_CMatrixVersion_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_CMatrixVersion_CMatrixVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CMatrixVersion_CMatrixVersion_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_CMatrixVersion_CMatrixVersion_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_CMatrixVersion_CMatrixVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_CMatrixVersion_CMatrixVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data19ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_CMatrixVersion_CMatrixVersion_DCM_E_PENDING
 *   RTE_E_DataServices_CMatrixVersion_CMatrixVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CMatrixVersion_CMatrixVersion_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_CMatrixVersion_CMatrixVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CMatrixVersion_CMatrixVersion_ReadData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal;
  retVal  = ReadVipDidDataReqProcess(0xF1A2,OpStatus,Data,(uint16)sizeof(Dcm_Data19ByteType));
  
  return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DID_0XFDA0_ClusterConfiguration_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0XFDA0_ClusterConfiguration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DID_0XFDA0_ClusterConfiguration_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0XFDA0_ClusterConfiguration_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0XFDA0_ClusterConfiguration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0XFDA0_ClusterConfiguration_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DID_0XFDA0_ClusterConfiguration_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0XFDA0_ClusterConfiguration_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DID_0XFDA0_ClusterConfiguration_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0XFDA0_ClusterConfiguration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DID_0XFDA0_ClusterConfiguration_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data300ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0XFDA0_ClusterConfiguration_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0XFDA0_ClusterConfiguration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0XFDA0_ClusterConfiguration_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DID_0XFDA0_ClusterConfiguration_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0XFDA0_ClusterConfiguration_ReadData (returns application error)
 *********************************************************************************************************************/
  (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock(),sizeof(Dcm_Data300ByteType));

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DID_0XFDA0_ClusterConfiguration_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_DID_0XFDA0_ClusterConfiguration>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(const uint8 *data)
 *     Argument data: uint8* is of type Dcm_Data300ByteType
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DID_0XFDA0_ClusterConfiguration_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data300ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0XFDA0_ClusterConfiguration_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0XFDA0_ClusterConfiguration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0XFDA0_ClusterConfiguration_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DID_0XFDA0_ClusterConfiguration_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0XFDA0_ClusterConfiguration_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    uint8 tConfigRsp = 0;
    uint8 fctRet = E_NOT_OK;
    switch(OpStatus)
    {
        case DCM_INITIAL:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_GetErrorStatus(&nvmStatus);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock(),(const uint8 *)Data,sizeof(Dcm_Data300ByteType));
                (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_WriteBlock(NULL_PTR);
                Rte_Write_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(Data);
                
                WriteCconfigRequestCounter += 1;
                Rte_Write_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag(WriteCconfigRequestCounter);
                ret = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                ret = E_NOT_OK;                
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_GetErrorStatus(&nvmStatus);
            Rte_Read_rpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag(&tConfigRsp);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus)&&(TRUE == tConfigRsp))
            {
              if(NVM_REQ_OK != nvmStatus)
              {
                  memset((uint8*)Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock(),0,sizeof(Dcm_Data300ByteType));
                  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                  ret = E_NOT_OK;
              }
            }
            else
            {
              ret  = DCM_E_PENDING;
            }
            break;
            default:
                ret = E_NOT_OK;
            break;

    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_FrontCameraSts_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_AVM_FrontCameraSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_FrontCameraSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_FrontCameraSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_FrontCameraSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_FrontCameraSts_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_FrontCameraSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_FrontCameraSts_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = E_NOT_OK;
  uint16 dataId = 0xFECC;
  if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
  {
      ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
  }
  else
  {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  }
  return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_FrontCameraSts_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_AVM_FrontCameraSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_FrontCameraSts_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_FrontCameraSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_FrontCameraSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_FrontCameraSts_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_FrontCameraSts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_FrontCameraSts_ReadData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xFECC;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data4ByteType));
  return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_LeftCamerSts_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_AVM_LeftCamerSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_LeftCamerSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_LeftCamerSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_LeftCamerSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_LeftCamerSts_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_LeftCamerSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_LeftCamerSts_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = E_NOT_OK;
  uint16 dataId = 0xFECA;
  if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
  {
      ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
  }
  else
  {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  }
  return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_LeftCamerSts_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_AVM_LeftCamerSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_LeftCamerSts_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_LeftCamerSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_LeftCamerSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_LeftCamerSts_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_LeftCamerSts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_LeftCamerSts_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xFECA;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data4ByteType));
  return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_RearCameraSts_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_AVM_RearCameraSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_RearCameraSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_RearCameraSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_RearCameraSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_RearCameraSts_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_RearCameraSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_RearCameraSts_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = E_NOT_OK;
  uint16 dataId = 0xFECB;
  if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
  {
      ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
  }
  else
  {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  }
  return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_RearCameraSts_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_AVM_RearCameraSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_RearCameraSts_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_RearCameraSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_RearCameraSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_RearCameraSts_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_RearCameraSts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_RearCameraSts_ReadData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xFECB;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data4ByteType));
  return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_RightCameraSts_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_AVM_RightCameraSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_RightCameraSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_RightCameraSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_RightCameraSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_RightCameraSts_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_RightCameraSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_RightCameraSts_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = E_NOT_OK;
   uint16 dataId = 0xFEC9;
  if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
  {
      ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
  }
  else
  {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  }
  return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_RightCameraSts_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_AVM_RightCameraSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_RightCameraSts_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_RightCameraSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_RightCameraSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_RightCameraSts_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_RightCameraSts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_RightCameraSts_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xFEC9;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data4ByteType));
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_deCodeSerial_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_AVM_deCodeSerial>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_deCodeSerial_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_deCodeSerial_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_deCodeSerial_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_deCodeSerial_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_deCodeSerial_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_deCodeSerial_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = E_NOT_OK;
  uint16 dataId = 0xFECD;
  if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
  {
      ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
  }
  else
  {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  }
  return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_AVM_deCodeSerial_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_AVM_deCodeSerial>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_AVM_deCodeSerial_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AVM_deCodeSerial_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AVM_deCodeSerial_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_deCodeSerial_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_AVM_deCodeSerial_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_AVM_deCodeSerial_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xFECD;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data10ByteType));
  return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCertificateSerialNumber_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_CS_ECUCertificateSerialNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCertificateSerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCertificateSerialNumber_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCertificateSerialNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSerialNumber_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCertificateSerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSerialNumber_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCertificateSerialNumber_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_CS_ECUCertificateSerialNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCertificateSerialNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data40ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCertificateSerialNumber_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCertificateSerialNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSerialNumber_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCertificateSerialNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSerialNumber_ReadData (returns application error)
 *********************************************************************************************************************/
      Std_ReturnType ret = RTE_E_OK;
      ret = ReadIVIDidDataFixLengthProcess(0xF1CC, OpStatus,Data,40);
      return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCertificateSigningRequest_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_CS_ECUCertificateSigningRequest>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCertificateSigningRequest_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCertificateSigningRequest_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCertificateSigningRequest_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSigningRequest_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCertificateSigningRequest_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSigningRequest_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCertificateSigningRequest_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_CS_ECUCertificateSigningRequest>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCertificateSigningRequest_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2048ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCertificateSigningRequest_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCertificateSigningRequest_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSigningRequest_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCertificateSigningRequest_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSigningRequest_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = DCM_E_OK;
    ret = ReadIVIDidDataRepeate(OpStatus,Data);
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCertificateSigningRequest_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Data_CS_ECUCertificateSigningRequest>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCertificateSigningRequest_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCertificateSigningRequest_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCertificateSigningRequest_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSigningRequest_ReadDataLength_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCertificateSigningRequest_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateSigningRequest_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = RTE_E_OK;


    ret = ReadIVIDidDataStart(0xF1C9,OpStatus,DataLength);


    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCertificateStatus_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_CS_ECUCertificateStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCertificateStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCertificateStatus_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCertificateStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateStatus_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCertificateStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateStatus_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCertificateStatus_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_CS_ECUCertificateStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCertificateStatus_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCertificateStatus_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCertificateStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateStatus_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCertificateStatus_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificateStatus_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = RTE_E_OK;

  ret = ReadIVIDidDataFixLengthProcess(0xf1ca,OpStatus,Data,1);

  return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCertificate_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_CS_ECUCertificate>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCertificate_WriteData(const uint8 *Data, uint16 DataLength, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data3000ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCertificate_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCertificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificate_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCertificate_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCertificate_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;

    ret = WriteIVIDidDataProcess(0xF1CB,OpStatus,Data, DataLength);
    if(E_NOT_OK == ret)
    {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCsrHash_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_CS_ECUCsrHash>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCsrHash_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCsrHash_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCsrHash_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCsrHash_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCsrHash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCsrHash_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  return RTE_E_INVALID;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_CS_ECUCsrHash_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_CS_ECUCsrHash>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_CS_ECUCsrHash_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CS_ECUCsrHash_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CS_ECUCsrHash_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCsrHash_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_CS_ECUCsrHash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_CS_ECUCsrHash_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    //ret = ReadIVIDidDataFixLengthProcess(0xF1CD, OpStatus,Data,sizeof(Dcm_Data20ByteType));
    return ret;
    

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_ClusterDisplayEcuLevelNetworkCfg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retVal = RTE_E_OK;
    uint16 dataId = 0xB001;
    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_ClusterDisplayEcuLevelNetworkCfg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retVal = RTE_E_OK;
    uint16 dataId = 0xB001;
    retVal = CopyQnxDidRspData(dataId, Data, (uint16)sizeof(Dcm_Data17ByteType));
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_ClusterDisplayEcuLevelNetworkCfg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ClusterDisplayEcuLevelNetworkCfg_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xB001;
  retVal =  WriteQnxDidDataRequestProcess(dataId,OpStatus,Data,(uint16)sizeof(Dcm_Data17ByteType),ErrorCode);
  return retVal;



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_E2ESwitch_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_E2ESwitch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_E2ESwitch_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_E2ESwitch_DCM_E_PENDING
 *   RTE_E_DataServices_Data_E2ESwitch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_E2ESwitch_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_E2ESwitch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_E2ESwitch_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_E2ESwitch_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_E2ESwitch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_E2ESwitch_ReadData(Dcm_OpStatusType OpStatus, Dcm_DataElement_Data_E2ESwitchType *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_E2ESwitch_DCM_E_PENDING
 *   RTE_E_DataServices_Data_E2ESwitch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_E2ESwitch_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_E2ESwitch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_E2ESwitchType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_E2ESwitch_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    if((0 == Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0])||( 1 == Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0]))
    {
        (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(),sizeof(Dcm_Data1ByteType));
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_E2ESwitch_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_E2ESwitch>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_piSR_E2ESwitchChangeTrigger_Element(uint8 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_E2ESwitch_WriteData(Dcm_DataElement_Data_E2ESwitchType Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_E2ESwitch_DCM_E_PENDING
 *   RTE_E_DataServices_Data_E2ESwitch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_E2ESwitch_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_E2ESwitch_WriteData(Dcm_DataElement_Data_E2ESwitchType Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_E2ESwitch_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    uint8 locData = Data;
    uint8 mirrorDataBackup;
    if(locData == 0 || locData == 1)
    {
          switch(OpStatus)
          { 
            case DCM_INITIAL:
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(&nvmStatus);       
                if(NVM_REQ_PENDING != nvmStatus)
                {
                    mirrorDataBackup = Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0];
                    (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(),(uint8 *)&locData,sizeof(Dcm_Data1ByteType));
                    if(Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_WriteBlock(NULL_PTR) == RTE_E_OK)
                    {
                        ret = DCM_E_PENDING;
                    }
                    else
                    {
                        Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0] = mirrorDataBackup;
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        ret = E_NOT_OK;
                    }
                }
                
                break;
            case DCM_PENDING:
            case DCM_FORCE_RCRRP_OK:
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(&nvmStatus); 
                if(NVM_REQ_PENDING != nvmStatus)
                {
                    if(NVM_REQ_OK == nvmStatus)
                    { /*Send data to xx Module*/
                        Rte_Write_piSR_E2ESwitchChangeTrigger_Element(locData);
                    }
                    else
                    {
                        memset((uint8*)Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(),0,sizeof(Dcm_Data1ByteType));
                        *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                        ret = E_NOT_OK;
                    }
                }
                else
                {
                    ret = DCM_E_PENDING;
                }
                break;
                default:
                ret = E_NOT_OK;
            break;
          }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret  = DCM_E_NOT_OK;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_EthernetPolarityDetectionStatus_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_EthernetPolarityDetectionStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_EthernetPolarityDetectionStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_EthernetPolarityDetectionStatus_DCM_E_PENDING
 *   RTE_E_DataServices_Data_EthernetPolarityDetectionStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_EthernetPolarityDetectionStatus_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_EthernetPolarityDetectionStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_EthernetPolarityDetectionStatus_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    ret = ReadQnxDidDataRequestProcess(0xF1E9,OpStatus,ErrorCode);
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_EthernetPolarityDetectionStatus_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_EthernetPolarityDetectionStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_EthernetPolarityDetectionStatus_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_EthernetPolarityDetectionStatus_DCM_E_PENDING
 *   RTE_E_DataServices_Data_EthernetPolarityDetectionStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_EthernetPolarityDetectionStatus_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_EthernetPolarityDetectionStatus_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_EthernetPolarityDetectionStatus_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    uint16 dataId = 0xF1E9;
    retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data8ByteType));
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Fuel_EnduranceMileage_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_Fuel_EnduranceMileage>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Fuel_EnduranceMileage_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Fuel_EnduranceMileage_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Fuel_EnduranceMileage_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Fuel_EnduranceMileage_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_Fuel_EnduranceMileage_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Fuel_EnduranceMileage_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Fuel_EnduranceMileage_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Fuel_EnduranceMileage>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TC_Api_ParamentGetCsPort_Operation(uint8 *arg)
 *     Argument arg: uint8* is of type Diag_9Bytes
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Fuel_EnduranceMileage_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data6ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Fuel_EnduranceMileage_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Fuel_EnduranceMileage_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Fuel_EnduranceMileage_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_Fuel_EnduranceMileage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Fuel_EnduranceMileage_ReadData (returns application error)
 *********************************************************************************************************************/
    Rte_Call_TC_Api_ParamentGetCsPort_Operation(Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Fuel_FuelStatus_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_Fuel_FuelStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Fuel_FuelStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Fuel_FuelStatus_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Fuel_FuelStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Fuel_FuelStatus_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_Fuel_FuelStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Fuel_FuelStatus_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Fuel_FuelStatus_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Fuel_FuelStatus>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_Fuel_Api_ParamentGetCsPort_Operation(uint8 *arg)
 *     Argument arg: uint8* is of type Diag_9Bytes
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Fuel_FuelStatus_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data9ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Fuel_FuelStatus_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Fuel_FuelStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Fuel_FuelStatus_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_Fuel_FuelStatus_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Fuel_FuelStatus_ReadData (returns application error)
 *********************************************************************************************************************/
    Rte_Call_rpCS_Fuel_Api_ParamentGetCsPort_Operation(Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_ODO_MaintenanceOdometer_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_ODO_MaintenanceOdometer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_ODO_MaintenanceOdometer_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ODO_MaintenanceOdometer_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ODO_MaintenanceOdometer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ODO_MaintenanceOdometer_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_ODO_MaintenanceOdometer_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ODO_MaintenanceOdometer_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_ODO_MaintenanceOdometer_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_ODO_MaintenanceOdometer>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(uint8 Id, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_ODO_MaintenanceOdometer_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ODO_MaintenanceOdometer_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ODO_MaintenanceOdometer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ODO_MaintenanceOdometer_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_ODO_MaintenanceOdometer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ODO_MaintenanceOdometer_ReadData (returns application error)
 *********************************************************************************************************************/
    Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(2, Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_ODO_MaintenanceOdometer_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_ODO_MaintenanceOdometer>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_cpCS_OdoSetParament_Operation(uint8 SetId, uint32 *data)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_OdoSetParament_Std_ReturnType
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_ODO_MaintenanceOdometer_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ODO_MaintenanceOdometer_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ODO_MaintenanceOdometer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ODO_MaintenanceOdometer_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_ODO_MaintenanceOdometer_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_ODO_MaintenanceOdometer_WriteData (returns application error)
 *********************************************************************************************************************/
  uint32 locData;
  uint8 fctRet;
  uint8 ret = RTE_E_OK;
  locData = Data[0];
  locData <<=8;
  locData |= Data[1];
  locData <<=8;
  locData |= Data[2];
  locData <<=8;
  locData |= Data[3];
  
  fctRet = Rte_Call_cpCS_OdoSetParament_Operation(5,&locData);
  if(FALSE == fctRet)
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    ret = E_NOT_OK;
  }
  return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Odo_BackupDistanceHistory_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_Odo_BackupDistanceHistory>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Odo_BackupDistanceHistory_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Odo_BackupDistanceHistory_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Odo_BackupDistanceHistory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Odo_BackupDistanceHistory_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_Odo_BackupDistanceHistory_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Odo_BackupDistanceHistory_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Odo_BackupDistanceHistory_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Odo_BackupDistanceHistory>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(uint8 Id, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Odo_BackupDistanceHistory_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data39ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Odo_BackupDistanceHistory_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Odo_BackupDistanceHistory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Odo_BackupDistanceHistory_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_Odo_BackupDistanceHistory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Odo_BackupDistanceHistory_ReadData (returns application error)
 *********************************************************************************************************************/
     Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(3, Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Odo_RealisticOdo_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_Odo_RealisticOdo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Odo_RealisticOdo_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Odo_RealisticOdo_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Odo_RealisticOdo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Odo_RealisticOdo_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_Odo_RealisticOdo_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Odo_RealisticOdo_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Odo_RealisticOdo_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Odo_RealisticOdo>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(uint8 Id, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Odo_RealisticOdo_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Odo_RealisticOdo_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Odo_RealisticOdo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Odo_RealisticOdo_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_Odo_RealisticOdo_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Odo_RealisticOdo_ReadData (returns application error)
 *********************************************************************************************************************/
     Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(1, Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_RVC_CameraSts_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_RVC_CameraSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_RVC_CameraSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_RVC_CameraSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_RVC_CameraSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_RVC_CameraSts_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_RVC_CameraSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_RVC_CameraSts_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    uint16 dataId = 0xFECE;
    if((vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] != 0x1)&&
        (vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] != 0x2)&&
        ((0x1 == vConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO])||(0x2 == vConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO])||(0x3 == vConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO])))
    {
        ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_RVC_CameraSts_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_RVC_CameraSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_RVC_CameraSts_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_RVC_CameraSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_RVC_CameraSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_RVC_CameraSts_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_RVC_CameraSts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_RVC_CameraSts_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xFECE;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data4ByteType));
  return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_RVC_deCodeSerialSts_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_RVC_deCodeSerialSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_RVC_deCodeSerialSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_RVC_deCodeSerialSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_RVC_deCodeSerialSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_RVC_deCodeSerialSts_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_RVC_deCodeSerialSts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_RVC_deCodeSerialSts_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = E_NOT_OK;
  uint16 dataId = 0xFECF;
  if((vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] != 0x1)&&
      (vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] != 0x2)&&
      ((0x1 == vConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO])||(0x2 == vConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO])||(0x3 == vConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO])))
  {
      ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
  }
  else
  {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  }
  return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_RVC_deCodeSerialSts_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_RVC_deCodeSerialSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_RVC_deCodeSerialSts_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_RVC_deCodeSerialSts_DCM_E_PENDING
 *   RTE_E_DataServices_Data_RVC_deCodeSerialSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_RVC_deCodeSerialSts_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_RVC_deCodeSerialSts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_RVC_deCodeSerialSts_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xFECF;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data4ByteType));
  return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_SecOcSwitch_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_SecOcSwitch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_SecOcSwitch_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_SecOcSwitch_DCM_E_PENDING
 *   RTE_E_DataServices_Data_SecOcSwitch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_SecOcSwitch_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_SecOcSwitch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_SecOcSwitch_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_SecOcSwitch_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_SecOcSwitch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_SecOcSwitch_ReadData(Dcm_OpStatusType OpStatus, Dcm_DataElement_Data_SecOcSwitchType *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_SecOcSwitch_DCM_E_PENDING
 *   RTE_E_DataServices_Data_SecOcSwitch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_SecOcSwitch_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_SecOcSwitch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SecOcSwitchType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_SecOcSwitch_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    if((0 == Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0])||(1 == Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0]))
    {
        (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(),sizeof(Dcm_Data1ByteType));
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_SecOcSwitch_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_SecOcSwitch>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_SecOcSwitch_WriteData(Dcm_DataElement_Data_SecOcSwitchType Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_SecOcSwitch_DCM_E_PENDING
 *   RTE_E_DataServices_Data_SecOcSwitch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_SecOcSwitch_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_SecOcSwitch_WriteData(Dcm_DataElement_Data_SecOcSwitchType Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_SecOcSwitch_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    uint8 locData = Data;
    uint8 mirrorDataBackup;
    if(locData == 0 || locData == 1)
    {
      switch(OpStatus)
      { 
            case DCM_INITIAL: 
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(&nvmStatus);      
                if(NVM_REQ_PENDING != nvmStatus)
                {
                    mirrorDataBackup = Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0];
                    (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(),(uint8*)&locData,sizeof(Dcm_Data1ByteType));
                    if(Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_WriteBlock(NULL_PTR) == E_OK)
                    {
                        ret = DCM_E_PENDING;
                    }
                    else
                    {   
                        Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0] = mirrorDataBackup;
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        ret = DCM_E_NOT_OK;
                    }
                } 
                break;
            case DCM_PENDING:
            case DCM_FORCE_RCRRP_OK:
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(&nvmStatus);  
                if(NVM_REQ_PENDING != nvmStatus)
                {
                    if(NVM_REQ_OK == nvmStatus)
                    {   /*Send data to xx Module*/
                        //Rte_Write_piSR_SecOcSwitchChangeTrigger_Element(locData);
                        /* SecOC Status ON, Set DevelopmentMode Disable,SecOC Status OFF, Set DevelopmentMode Enable */
                        if(locData == 0x01)
                        {
                            SecOC_SetDevelopmentMode(FALSE);
                        }
                        else
                        {
                            SecOC_SetDevelopmentMode(TRUE);
                        }
                    }
                    else
                    {
                        memset((uint8*)Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(),0,sizeof(Dcm_Data1ByteType));
                        *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                        ret = DCM_E_NOT_OK;
                    }
                }
                else
                {
                    ret  = DCM_E_PENDING;
                }
                break;
            default:
                ret = E_NOT_OK;
            break;
      }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret  = DCM_E_NOT_OK;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_VehicleSoftwareVersion_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_VehicleSoftwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_VehicleSoftwareVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data30ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleSoftwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleSoftwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_VehicleSoftwareVersion_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_VehicleSoftwareVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_VehicleSoftwareVersion_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 i;

    for(i = 0; i < sizeof(Dcm_Data30ByteType); i++)
    {
        if(Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[i] != 0xFF)
        {
            *Data = Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[i];
            Data++;
        }
        else
        {
            break;
        }
    }
    return (ret);
              
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_VehicleSoftwareVersion_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Data_VehicleSoftwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_VehicleSoftwareVersion_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleSoftwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleSoftwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_VehicleSoftwareVersion_ReadDataLength_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_VehicleSoftwareVersion_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_VehicleSoftwareVersion_ReadDataLength (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = DCM_E_OK;
    uint8 i;
    uint8 datalen = 0;
    for(i = 0; i < sizeof(Dcm_Data30ByteType); i++)
    {
        if(Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[i] != 0xFF)
        {
            datalen++;
        }
        else
        {
            break;
        }
    }
    *DataLength = datalen;
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_VehicleSoftwareVersion_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_VehicleSoftwareVersion>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_VehicleSoftwareVersion_WriteData(const uint8 *Data, uint16 DataLength, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data30ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleSoftwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleSoftwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_VehicleSoftwareVersion_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_VehicleSoftwareVersion_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_VehicleSoftwareVersion_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    
    uint8 fctRet = E_NOT_OK;
    uint8 i;
    uint8 j;
    if(0xFF != Data[0])
    {
      switch(OpStatus)
      { 
          case DCM_INITIAL:
              fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_GetErrorStatus(&nvmStatus);
              if((NVM_REQ_PENDING != nvmStatus)&&(E_OK == fctRet))
              {
                  for(i = 0;i < sizeof(Dcm_Data30ByteType); i++)
                  {
                      if((i < DataLength)&&(0xFF != Data[i]))
                      {
                          Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[i] = Data[i];
                      }
                      else
                      {
                          for(j = i; j < sizeof(Dcm_Data30ByteType); j++)
                          {
                              Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[j] = 0xFF;
                          }
                          break;
                      }
                  }
                  (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_WriteBlock(NULL_PTR);
                  ret = DCM_E_PENDING;
              }
              else
              {
                  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                  ret = E_NOT_OK;
              }
              break;
          case DCM_PENDING:
          case DCM_FORCE_RCRRP_OK:
              fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_GetErrorStatus(&nvmStatus);
              if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
              {
                  if(NVM_REQ_OK != nvmStatus)
                  {
                      memset((uint8*)Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock(),0xFF,sizeof(Dcm_Data30ByteType));
                      *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                      ret = E_NOT_OK;
                  }
              }
              else
              {
                  ret = DCM_E_PENDING;
              }
              break;
          default:
              ret = E_NOT_OK;
              break;

      }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret  = E_NOT_OK;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_WorkingMode_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_WorkingMode>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_WorkingMode_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_WorkingMode_DCM_E_PENDING
 *   RTE_E_DataServices_Data_WorkingMode_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_WorkingMode_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_WorkingMode_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_WorkingMode_ReadData (returns application error)
 *********************************************************************************************************************/
 (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(),sizeof(Dcm_Data1ByteType));
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_WorkingMode_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_WorkingMode>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_WorkingMode_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_WorkingMode_DCM_E_PENDING
 *   RTE_E_DataServices_Data_WorkingMode_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_WorkingMode_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_Data_WorkingMode_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_WorkingMode_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    const uint8 *locData = Data;
    uint8 fctRet = E_NOT_OK;

    switch(OpStatus)
    {
        case DCM_INITIAL: 
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_GetErrorStatus(&nvmStatus);    
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(),(const uint8*)locData,sizeof(Dcm_Data1ByteType));
                (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_WriteBlock(NULL_PTR);
                ret = RTE_E_DataServices_Data_WorkingMode_DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_GetErrorStatus(&nvmStatus);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(),0,sizeof(Dcm_Data1ByteType));
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret = DCM_E_PENDING;
            }
        break;
            default:
                ret = E_NOT_OK;
            break;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data200ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = DCM_E_OK;

    (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(),sizeof(Dcm_Data200ByteType));

  return (ret);
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VconfigResponseFlag_VconfigResponseFlag(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ECUlevelNetworkConfigurationDataIdentifier_Element(const uint8 *data)
 *     Argument data: uint8* is of type Dcm_Data200ByteType
 *   Std_ReturnType Rte_Write_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag(uint8 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data200ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    uint8 ipcResp;
    uint8 fctRet = E_NOT_OK;
    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_GetErrorStatus(&nvmStatus);
            if((NVM_REQ_PENDING != nvmStatus)&&(E_OK == fctRet))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(),(const uint8 *)Data,sizeof(Dcm_Data200ByteType));
                (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_WriteBlock(NULL_PTR);
                Rte_Write_ECUlevelNetworkConfigurationDataIdentifier_Element(Data);
                WriteVconfigRequestCounter += 1;
                Rte_Write_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag(WriteVconfigRequestCounter);
                ret = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_GetErrorStatus(&nvmStatus);
            Rte_Read_DidDataProcess_VconfigResponseFlag_VconfigResponseFlag(&ipcResp);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus)&&(TRUE == ipcResp))/*check IPC message*/
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(),0,sizeof(Dcm_Data200ByteType));
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret = DCM_E_PENDING;
            }
            break;
        default:
            ret = E_NOT_OK;
            break;
    
    }
  return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_GWMSparePartNumber_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_GWMSparePartNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_GWMSparePartNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_GWMSparePartNumber_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_GWMSparePartNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_GWMSparePartNumber_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_GWMSparePartNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_GWMSparePartNumber_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
 
    Std_ReturnType ret = E_NOT_OK;

    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
      ret = RTE_E_OK;
    }
    else
    {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_GWMSparePartNumber_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_GWMSparePartNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_GWMSparePartNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data13ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_GWMSparePartNumber_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_GWMSparePartNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_GWMSparePartNumber_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_GWMSparePartNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_GWMSparePartNumber_ReadData (returns application error)
 *********************************************************************************************************************/
  /*Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xFEEC,OpStatus,Data,sizeof(Dcm_Data13ByteType));
  return retVal;
  */
  return E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_HardwareVersion_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_HardwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_HardwareVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_HardwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_HardwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_HardwareVersion_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_HardwareVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_HardwareVersion_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;

    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_HardwareVersion_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_HardwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_HardwareVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_HardwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_HardwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_HardwareVersion_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_HardwareVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_HardwareVersion_ReadData (returns application error)
 *********************************************************************************************************************/
  /*Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xFEEE,OpStatus,Data,sizeof(Dcm_Data2ByteType));
  return retVal;*/
  return E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_LCDTemperature_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_LCDTemperature>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_LCDTemperature_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_LCDTemperature_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_LCDTemperature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_LCDTemperature_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_LCDTemperature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_LCDTemperature_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;

    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_LCDTemperature_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_LCDTemperature>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_LCDTemperature_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_LCDTemperature_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_LCDTemperature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_LCDTemperature_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_LCDTemperature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_LCDTemperature_ReadData (returns application error)
 *********************************************************************************************************************/
  /*Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xFEEA,OpStatus,Data,sizeof(Dcm_Data2ByteType));
  return retVal;*/
  return E_NOT_OK;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_LVDSPotocolStandard_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_LVDSPotocolStandard>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_LVDSPotocolStandard_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_LVDSPotocolStandard_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_LVDSPotocolStandard_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_LVDSPotocolStandard_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_LVDSPotocolStandard_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_LVDSPotocolStandard_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_LVDSPotocolStandard_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_LVDSPotocolStandard>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_LVDSPotocolStandard_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_LVDSPotocolStandard_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_LVDSPotocolStandard_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_LVDSPotocolStandard_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_LVDSPotocolStandard_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_LVDSPotocolStandard_ReadData (returns application error)
 *********************************************************************************************************************/
  /*Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xFEE4,OpStatus,Data,sizeof(Dcm_Data1ByteType));
  return retVal;*/
  return E_NOT_OK;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_ManufacturingDate_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_ManufacturingDate>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_ManufacturingDate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_ManufacturingDate_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_ManufacturingDate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ManufacturingDate_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_ManufacturingDate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ManufacturingDate_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_ManufacturingDate_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_ManufacturingDate>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_ManufacturingDate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_ManufacturingDate_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_ManufacturingDate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ManufacturingDate_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_ManufacturingDate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ManufacturingDate_ReadData (returns application error)
 *********************************************************************************************************************/
    /*Std_ReturnType retVal;
    retVal = ReadQnxDidDataRequestProcess(0xFEEB,OpStatus,Data,sizeof(Dcm_Data4ByteType));
    return retVal;*/
    
    return E_NOT_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_Resolution_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_Resolution>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_Resolution_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_Resolution_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_Resolution_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_Resolution_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_Resolution_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_Resolution_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_Resolution_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_Resolution>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_Resolution_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_Resolution_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_Resolution_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_Resolution_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_Resolution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_Resolution_ReadData (returns application error)
 *********************************************************************************************************************/
  /*Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xFEE6,OpStatus,Data,sizeof(Dcm_Data1ByteType));
  return retVal;*/
  return E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_ScreenSize_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_ScreenSize>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_ScreenSize_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_ScreenSize_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_ScreenSize_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ScreenSize_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_ScreenSize_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ScreenSize_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_ScreenSize_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_ScreenSize>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_ScreenSize_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_ScreenSize_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_ScreenSize_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ScreenSize_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_ScreenSize_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ScreenSize_ReadData (returns application error)
 *********************************************************************************************************************/

  /*Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xFEE7,OpStatus,Data,sizeof(Dcm_Data1ByteType));
  return retVal;*/
  
  return E_NOT_OK;  

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_ScreenType_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_ScreenType>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_ScreenType_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_ScreenType_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_ScreenType_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ScreenType_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_ScreenType_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ScreenType_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_ScreenType_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_ScreenType>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_ScreenType_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_ScreenType_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_ScreenType_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ScreenType_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_ScreenType_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_ScreenType_ReadData (returns application error)
 *********************************************************************************************************************/

  /*Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xFEE5,OpStatus,Data,sizeof(Dcm_Data1ByteType));
  return retVal;*/
  return E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_SoftwareVersion_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_SoftwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_SoftwareVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_SoftwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_SoftwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_SoftwareVersion_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_SoftwareVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_SoftwareVersion_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_SoftwareVersion_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_SoftwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_SoftwareVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_SoftwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_SoftwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_SoftwareVersion_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_SoftwareVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_SoftwareVersion_ReadData (returns application error)
 *********************************************************************************************************************/
   /*Std_ReturnType retVal;
   retVal = ReadQnxDidDataRequestProcess(0xFEED,OpStatus,Data,sizeof(Dcm_Data2ByteType));
   return retVal;
   */
   return E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_SupplierInfo_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_SupplierInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_SupplierInfo_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_SupplierInfo_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_SupplierInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_SupplierInfo_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_SupplierInfo_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_SupplierInfo_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_SupplierInfo_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_SupplierInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_SupplierInfo_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_SupplierInfo_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_SupplierInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_SupplierInfo_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_SupplierInfo_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_SupplierInfo_ReadData (returns application error)
 *********************************************************************************************************************/

    /*Std_ReturnType retVal;
    retVal = ReadQnxDidDataRequestProcess(0xFEE8,OpStatus,Data,sizeof(Dcm_Data1ByteType));
    return retVal;*/
    
    return E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_TPVersionNumber_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HVACDisplay_TPVersionNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_TPVersionNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_TPVersionNumber_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_TPVersionNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_TPVersionNumber_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_TPVersionNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_TPVersionNumber_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    if(0x01 == vConfigDataBuf[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN])
    {
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HVACDisplay_TPVersionNumber_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HVACDisplay_TPVersionNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HVACDisplay_TPVersionNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HVACDisplay_TPVersionNumber_DCM_E_PENDING
 *   RTE_E_DataServices_HVACDisplay_TPVersionNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_TPVersionNumber_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_HVACDisplay_TPVersionNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HVACDisplay_TPVersionNumber_ReadData (returns application error)
 *********************************************************************************************************************/
    /*Std_ReturnType retVal;
    retVal = ReadQnxDidDataRequestProcess(0xFEE9,OpStatus,Data,sizeof(Dcm_Data3ByteType));
    return retVal;*/
    
    return E_NOT_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_MaintenanceOdometer_Maintenance_odometer_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_MaintenanceOdometer_Maintenance_odometer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_MaintenanceOdometer_Maintenance_odometer_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_MaintenanceOdometer_Maintenance_odometer_DCM_E_PENDING
 *   RTE_E_DataServices_MaintenanceOdometer_Maintenance_odometer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MaintenanceOdometer_Maintenance_odometer_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_MaintenanceOdometer_Maintenance_odometer_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MaintenanceOdometer_Maintenance_odometer_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_MaintenanceOdometer_Maintenance_odometer_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_MaintenanceOdometer_Maintenance_odometer>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_OdoParament_Element(s_OdoRteGetParament_t *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_MaintenanceOdometer_Maintenance_odometer_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_MaintenanceOdometer_Maintenance_odometer_DCM_E_PENDING
 *   RTE_E_DataServices_MaintenanceOdometer_Maintenance_odometer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MaintenanceOdometer_Maintenance_odometer_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_MaintenanceOdometer_Maintenance_odometer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MaintenanceOdometer_Maintenance_odometer_ReadData (returns application error)
 *********************************************************************************************************************/
    s_OdoRteGetParament_t OdoParament;
    //Rte_Read_rpSR_OdoParament_Element(&OdoParament);
    Rte_Read_DidDataProcess_rpSR_OdoParament_Element(&OdoParament);

    *Data = (uint8)(OdoParament.FsrvKmValue_s32 >> 24u);
    Data++;
    *Data = (uint8)(OdoParament.FsrvKmValue_s32 >> 16u);
    Data++;
    *Data = (uint8)(OdoParament.FsrvKmValue_s32 >> 8u);
    Data++;
    *Data = (uint8)(OdoParament.FsrvKmValue_s32);
    
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retVal = RTE_E_OK;
    uint16 dataId = 0xF189;
    retVal = ReadQnxDidDataRequestProcess(dataId, OpStatus, ErrorCode);
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_DCM_E_PENDING
 *   RTE_E_DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersionNumberDataIdentifier_SoftwareVersion_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType  retVal = RTE_E_OK;
    uint16 dataId = 0xF189;
    retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data15ByteType));
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SwitchARLTable_SwitchARLTable>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SwitchARLTable_SwitchARLTable_DCM_E_PENDING
 *   RTE_E_DataServices_SwitchARLTable_SwitchARLTable_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    uint16 dataId = 0xF1D6;
    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SwitchARLTable_SwitchARLTable_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SwitchARLTable_SwitchARLTable>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SwitchARLTable_SwitchARLTable_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data28ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SwitchARLTable_SwitchARLTable_DCM_E_PENDING
 *   RTE_E_DataServices_SwitchARLTable_SwitchARLTable_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SwitchARLTable_SwitchARLTable_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SwitchARLTable_SwitchARLTable_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SwitchARLTable_SwitchARLTable_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xF1D6;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data28ByteType));
  return retVal;
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SwitchARLTable_SwitchARLTable_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_SwitchARLTable_SwitchARLTable>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SwitchARLTable_SwitchARLTable_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data28ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SwitchARLTable_SwitchARLTable_DCM_E_PENDING
 *   RTE_E_DataServices_SwitchARLTable_SwitchARLTable_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SwitchARLTable_SwitchARLTable_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SwitchARLTable_SwitchARLTable_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SwitchARLTable_SwitchARLTable_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal = RTE_E_OK;
  uint16 dataId = 0xF1D6;
  retVal =  WriteQnxDidDataRequestProcess(dataId,OpStatus,Data,(uint16)sizeof(Dcm_Data28ByteType),ErrorCode);

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SystemSupplierECUSoftwareVersionNumber_F195>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SystemSupplierECUSoftwareVersionNumber_ECUSoftwareVersionNumber_DCM_E_PENDING
 *   RTE_E_DataServices_SystemSupplierECUSoftwareVersionNumber_ECUSoftwareVersionNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retVal;
    retVal = ReadQnxDidDataRequestProcess(0xF195,OpStatus,ErrorCode);
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SystemSupplierECUSoftwareVersionNumber_F195>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data18ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SystemSupplierECUSoftwareVersionNumber_ECUSoftwareVersionNumber_DCM_E_PENDING
 *   RTE_E_DataServices_SystemSupplierECUSoftwareVersionNumber_ECUSoftwareVersionNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SystemSupplierECUSoftwareVersionNumber_F195_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal;
  retVal  = CopyQnxDidRspData(0xF195,Data,(uint16)sizeof(Dcm_Data18ByteType));
  
  return retVal;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SystemSupplierIdentifier_systemSupplierIdentifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SystemSupplierIdentifier_systemSupplierIdentifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SystemSupplierIdentifier_systemSupplierIdentifier_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal;
  retVal = ReadVipDidDataReqProcess(0xF18A,OpStatus,Data,(uint16)sizeof(Dcm_Data5ByteType));
  return retVal;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleIdentificationNumber_VIN_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_VehicleIdentificationNumber_VIN>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleIdentificationNumber_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleIdentificationNumber_VIN_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleIdentificationNumber_VIN_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleIdentificationNumber_VIN_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleIdentificationNumber_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleIdentificationNumber_VIN_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleIdentificationNumber_VIN_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_VehicleIdentificationNumber_VIN>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleIdentificationNumber_VIN_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleIdentificationNumber_VIN_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleIdentificationNumber_VIN_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleIdentificationNumber_VIN_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleIdentificationNumber_VIN_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleIdentificationNumber_VIN_ReadData (returns application error)
 *********************************************************************************************************************/

  (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_VIN_MirrorBlock(),sizeof(Dcm_Data17ByteType));

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleIdentificationNumber_VIN_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_VehicleIdentificationNumber_VIN>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_cpCS_OdoSetParament_Operation(uint8 SetId, uint32 *data)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_OdoSetParament_Std_ReturnType
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleIdentificationNumber_VIN_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleIdentificationNumber_VIN_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleIdentificationNumber_VIN_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleIdentificationNumber_VIN_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleIdentificationNumber_VIN_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleIdentificationNumber_VIN_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType vinNvmStatus = NVM_REQ_NOT_OK;
    uint8 fctRet = E_NOT_OK;

    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_GetErrorStatus(&vinNvmStatus);
            if((NVM_REQ_PENDING != vinNvmStatus)&&(E_OK == fctRet))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_VIN_MirrorBlock(),(const uint8 *)Data,sizeof(Dcm_Data17ByteType));
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_WriteBlock(NULL_PTR);
                ret  = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_GetErrorStatus(&vinNvmStatus);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != vinNvmStatus))
            {
                if(NVM_REQ_OK != vinNvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_VIN_MirrorBlock(),0,sizeof(Dcm_Data17ByteType));
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
                }
                else
                {
                    /*clear odo backup flag*/
                    Rte_Call_cpCS_OdoSetParament_Operation(9,NULL_PTR);
                }
            }
            else
            {
                ret  = DCM_E_PENDING;
            }
            break;
            default:
                ret = E_NOT_OK;
            break;

    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleManufacturerECUBootSoftwareVersionNumber_ECUBootSoftwareVersionNumber_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retVal;
    retVal  = ReadVipDidDataReqProcess(0xF1C1,OpStatus,Data,(uint16)sizeof(Dcm_Data15ByteType));

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleManufacturerECUCalibrationSoftwareVersionNumber_ECUCalibrationSoftwareVersionNumber_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retVal;
    retVal  = ReadVipDidDataReqProcess(0xF1C0,OpStatus,Data,(uint16)sizeof(Dcm_Data15ByteType));

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleModel_VehicleModel_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_VehicleModel_VehicleModel>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleModel_VehicleModel_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleModel_VehicleModel_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleModel_VehicleModel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleModel_VehicleModel_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleModel_VehicleModel_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleModel_VehicleModel_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleModel_VehicleModel_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_VehicleModel_VehicleModel>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleModel_VehicleModel_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleModel_VehicleModel_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleModel_VehicleModel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleModel_VehicleModel_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleModel_VehicleModel_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleModel_VehicleModel_ReadData (returns application error)
 *********************************************************************************************************************/
    memcpy((uint8*)Data,(uint8*)Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock(),sizeof(Dcm_Data20ByteType));
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_VehicleModel_VehicleModel_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_VehicleModel_VehicleModel>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_VehicleModel_VehicleModel_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VehicleModel_VehicleModel_DCM_E_PENDING
 *   RTE_E_DataServices_VehicleModel_VehicleModel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleModel_VehicleModel_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleModel_VehicleModel_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_VehicleModel_VehicleModel_WriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType vinNvmStatus = NVM_REQ_OK;

    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_GetErrorStatus(&vinNvmStatus);    
            if(NVM_REQ_PENDING != vinNvmStatus)
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock(),(uint8 *)Data,(uint16)sizeof(Dcm_Data20ByteType));
            } 
            (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_WriteBlock(NULL_PTR);

            ret  = RTE_E_DataServices_VehicleModel_VehicleModel_DCM_E_PENDING;
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_GetErrorStatus(&vinNvmStatus); 

            if(NVM_REQ_PENDING != vinNvmStatus)
            {
                if(NVM_REQ_OK != vinNvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock(),0,sizeof(Dcm_Data20ByteType));
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
                }
            } 
            else
            {
                ret  = DCM_E_PENDING;
            }
            break;
            default:
                ret = E_NOT_OK;
            break;

    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_BASE1000SQIThreshold_SQIThreshold>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BASE1000SQIThreshold_SQIThreshold_DCM_E_PENDING
 *   RTE_E_DataServices_BASE1000SQIThreshold_SQIThreshold_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal; 
    uint16 dataId = 0xF1E7;
    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_BASE1000SQIThreshold_SQIThreshold>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BASE1000SQIThreshold_SQIThreshold_DCM_E_PENDING
 *   RTE_E_DataServices_BASE1000SQIThreshold_SQIThreshold_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_BASE1000SQIThreshold_SQIThreshold_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal;
    uint16 dataId = 0xF1E7;
    retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data1ByteType));
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_BASE100SQIThreshold_SQIThreshold_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_BASE100SQIThreshold_SQIThreshold>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_Vconfig_KindBuffers_VconfigKind_157Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_157Bytes
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_BASE100SQIThreshold_SQIThreshold_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BASE100SQIThreshold_SQIThreshold_DCM_E_PENDING
 *   RTE_E_DataServices_BASE100SQIThreshold_SQIThreshold_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_BASE100SQIThreshold_SQIThreshold_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_BASE100SQIThreshold_SQIThreshold_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_BASE100SQIThreshold_SQIThreshold_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
    uint16 dataId = 0xF1E6;
    ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_BASE100SQIThreshold_SQIThreshold_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_BASE100SQIThreshold_SQIThreshold>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_BASE100SQIThreshold_SQIThreshold_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BASE100SQIThreshold_SQIThreshold_DCM_E_PENDING
 *   RTE_E_DataServices_BASE100SQIThreshold_SQIThreshold_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_BASE100SQIThreshold_SQIThreshold_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_BASE100SQIThreshold_SQIThreshold_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_BASE100SQIThreshold_SQIThreshold_ReadData (returns application error)
 *********************************************************************************************************************/

Std_ReturnType  retVal;
uint16 dataId = 0xF1E6;
retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data1ByteType));
return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_CompID1_CompID1_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_CompID1_CompID1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_CompID1_CompID1_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_CompID1_CompID1_DCM_E_PENDING
 *   RTE_E_DataServices_CompID1_CompID1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_CompID1_CompID1_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_CompID1_CompID1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_CompID1_CompID1_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = ReadQnxDidDataRequestProcess(0xF1B4,OpStatus,ErrorCode);
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_CompID1_CompID1_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_CompID1_CompID1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_CompID1_CompID1_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_CompID1_CompID1_DCM_E_PENDING
 *   RTE_E_DataServices_CompID1_CompID1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_CompID1_CompID1_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_CompID1_CompID1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_CompID1_CompID1_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = CopyQnxDidRspData(0xF1B4,Data,(uint16)sizeof(Dcm_Data32ByteType));
    return retVal;
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_FOTAIndentifier_New_Data_Object_1_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_FOTAIndentifier_New_Data_Object_1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_FOTAIndentifier_New_Data_Object_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_FOTAIndentifier_New_Data_Object_1_DCM_E_PENDING
 *   RTE_E_DataServices_FOTAIndentifier_New_Data_Object_1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_FOTAIndentifier_New_Data_Object_1_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_FOTAIndentifier_New_Data_Object_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_FOTAIndentifier_New_Data_Object_1_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    uint16 dataId = 0xF1B2;
    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_FOTAIndentifier_New_Data_Object_1_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_FOTAIndentifier_New_Data_Object_1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_FOTAIndentifier_New_Data_Object_1_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data9ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_FOTAIndentifier_New_Data_Object_1_DCM_E_PENDING
 *   RTE_E_DataServices_FOTAIndentifier_New_Data_Object_1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_FOTAIndentifier_New_Data_Object_1_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_FOTAIndentifier_New_Data_Object_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_FOTAIndentifier_New_Data_Object_1_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    uint16 dataId = 0xF1B2;
    retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data9ByteType));
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_FOTAName_FOTAName_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_FOTAName_FOTAName>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_FOTAName_FOTAName_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_FOTAName_FOTAName_DCM_E_PENDING
 *   RTE_E_DataServices_FOTAName_FOTAName_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_FOTAName_FOTAName_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_FOTAName_FOTAName_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_FOTAName_FOTAName_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = ReadQnxDidDataRequestProcess(0xF1B5,OpStatus,ErrorCode);
    return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_FOTAName_FOTAName_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_FOTAName_FOTAName>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_FOTAName_FOTAName_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_FOTAName_FOTAName_DCM_E_PENDING
 *   RTE_E_DataServices_FOTAName_FOTAName_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_FOTAName_FOTAName_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_FOTAName_FOTAName_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_FOTAName_FOTAName_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = CopyQnxDidRspData(0xF1B5,Data,(uint16)sizeof(Dcm_Data3ByteType));
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_LinkStatus_LinkStatus_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_LinkStatus_LinkStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_LinkStatus_LinkStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_LinkStatus_LinkStatus_DCM_E_PENDING
 *   RTE_E_DataServices_LinkStatus_LinkStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_LinkStatus_LinkStatus_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_LinkStatus_LinkStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_LinkStatus_LinkStatus_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal;
    uint16 dataId = 0xF1E5;
    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_LinkStatus_LinkStatus_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_LinkStatus_LinkStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_LinkStatus_LinkStatus_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_LinkStatus_LinkStatus_DCM_E_PENDING
 *   RTE_E_DataServices_LinkStatus_LinkStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_LinkStatus_LinkStatus_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_LinkStatus_LinkStatus_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_LinkStatus_LinkStatus_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal;
  uint16 dataId = 0xF1E5;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data8ByteType));
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_NodeAddress_NodeAddress_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_NodeAddress_NodeAddress>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_NodeAddress_NodeAddress_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_NodeAddress_NodeAddress_DCM_E_PENDING
 *   RTE_E_DataServices_NodeAddress_NodeAddress_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_NodeAddress_NodeAddress_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_NodeAddress_NodeAddress_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_NodeAddress_NodeAddress_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = ReadQnxDidDataRequestProcess(0xF1B3,OpStatus,ErrorCode);
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_NodeAddress_NodeAddress_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_NodeAddress_NodeAddress>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_NodeAddress_NodeAddress_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data9ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_NodeAddress_NodeAddress_DCM_E_PENDING
 *   RTE_E_DataServices_NodeAddress_NodeAddress_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_NodeAddress_NodeAddress_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_NodeAddress_NodeAddress_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_NodeAddress_NodeAddress_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = CopyQnxDidRspData(0xF1B3,Data,(uint16)sizeof(Dcm_Data9ByteType));
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_SQI_SQI_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SQI_SQI>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_SQI_SQI_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SQI_SQI_DCM_E_PENDING
 *   RTE_E_DataServices_SQI_SQI_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SQI_SQI_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_SQI_SQI_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SQI_SQI_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal;
    uint16 dataId = 0xF1E8;
    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_SQI_SQI_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SQI_SQI>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_SQI_SQI_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SQI_SQI_DCM_E_PENDING
 *   RTE_E_DataServices_SQI_SQI_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SQI_SQI_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_SQI_SQI_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SQI_SQI_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal;
    uint16 dataId = 0xF1E8;
    retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data8ByteType));
    return retVal;
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SignalLineCurrentStatus_SignalLineCurrentStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_DCM_E_PENDING
 *   RTE_E_DataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal;
    uint16 dataId = 0xF1D5;

    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SignalLineCurrentStatus_SignalLineCurrentStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_DCM_E_PENDING
 *   RTE_E_DataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SignalLineCurrentStatus_SignalLineCurrentStatus_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal;
  uint16 dataId = 0xF1D5;

  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data8ByteType));
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SignalLineSCOCNumber_SignalLineSCOCNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_DCM_E_PENDING
 *   RTE_E_DataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal;
    uint16 dataId = 0xF1D3;

    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SignalLineSCOCNumber_SignalLineSCOCNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_DCM_E_PENDING
 *   RTE_E_DataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SignalLineSCOCNumber_SignalLineSCOCNumber_ReadData (returns application error)
 *********************************************************************************************************************/
Std_ReturnType  retVal;
uint16 dataId = 0xF1D3;

retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data20ByteType));
return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_SwitchCounter_SwitchCounter_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SwitchCounter_SwitchCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_SwitchCounter_SwitchCounter_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SwitchCounter_SwitchCounter_DCM_E_PENDING
 *   RTE_E_DataServices_SwitchCounter_SwitchCounter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SwitchCounter_SwitchCounter_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_SwitchCounter_SwitchCounter_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SwitchCounter_SwitchCounter_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_NOT_OK;
     uint16 dataId = 0xF1EB;
    if(vConfigDataBuf[VCONFIG_KIND_HUT_ETHERNET_PORT] == 0x03)
    {
      ret = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    }
    else
    {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_SwitchCounter_SwitchCounter_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SwitchCounter_SwitchCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_SwitchCounter_SwitchCounter_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data228ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SwitchCounter_SwitchCounter_DCM_E_PENDING
 *   RTE_E_DataServices_SwitchCounter_SwitchCounter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SwitchCounter_SwitchCounter_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_SwitchCounter_SwitchCounter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_SwitchCounter_SwitchCounter_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal;
    uint16 dataId = 0xF1EB;
    retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data228ByteType));
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_TestModeStatus_TestModeStatus_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_TestModeStatus_TestModeStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_TestModeStatus_TestModeStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_TestModeStatus_TestModeStatus_DCM_E_PENDING
 *   RTE_E_DataServices_TestModeStatus_TestModeStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_TestModeStatus_TestModeStatus_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_TestModeStatus_TestModeStatus_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_TestModeStatus_TestModeStatus_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType  retVal;
    uint16 dataId = 0xF1D8;
    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_TestModeStatus_TestModeStatus_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_TestModeStatus_TestModeStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_TestModeStatus_TestModeStatus_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_TestModeStatus_TestModeStatus_DCM_E_PENDING
 *   RTE_E_DataServices_TestModeStatus_TestModeStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_TestModeStatus_TestModeStatus_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_TestModeStatus_TestModeStatus_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_TestModeStatus_TestModeStatus_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType  retVal;
  uint16 dataId = 0xF1D8;
  retVal = CopyQnxDidRspData(dataId,Data,(uint16)sizeof(Dcm_Data8ByteType));
    return retVal;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_ToolVersion_ToolVersion_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ToolVersion_ToolVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_ToolVersion_ToolVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ToolVersion_ToolVersion_DCM_E_PENDING
 *   RTE_E_DataServices_ToolVersion_ToolVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_ToolVersion_ToolVersion_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_ToolVersion_ToolVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_ToolVersion_ToolVersion_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = ReadQnxDidDataRequestProcess(0xF1B6,OpStatus,ErrorCode);
    return retVal;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDataServices_ToolVersion_ToolVersion_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ToolVersion_ToolVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDataServices_ToolVersion_ToolVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ToolVersion_ToolVersion_DCM_E_PENDING
 *   RTE_E_DataServices_ToolVersion_ToolVersion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_ToolVersion_ToolVersion_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DcmDataServices_ToolVersion_ToolVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDataServices_ToolVersion_ToolVersion_ReadData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = CopyQnxDidRspData(0xF1B6,Data,(uint16)sizeof(Dcm_Data8ByteType));
    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DidDataProcess_Init
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
 *   Std_ReturnType Rte_Read_rpSR_Vconfig_KindBuffers_VconfigKind_157Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_157Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DidDataProcess_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) DidDataProcess_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DidDataProcess_Init
 *********************************************************************************************************************/
    didReadRequest.Did = 0;
    didReadRsp.Did = 0;
    didWriteRequest.Did = 0;
    didWriteRsp.Did  = 0;
    factorModeWriteE2EReq = FALSE;
    factorModeWriteSecOcReq = FALSE;
    Rte_Read_rpSR_Vconfig_KindBuffers_VconfigKind_157Bytes(vConfigDataBuf);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DidDataProcess_MainFunction
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
 *   Std_ReturnType Rte_Read_SR_RpVehSparePartNumber_SparePartNumber(uint8 *data)
 *     Argument data: uint8* is of type EOL_13Bytes
 *   Std_ReturnType Rte_Read_kl15SysPowerMod_SysPowerMod(SysPowerMod *data)
 *   Std_ReturnType Rte_Read_kl15SysPowerModVld_SysPowerModVld(SysPowerModVld *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_tiSR_VIN_Element(const uint8 *data)
 *     Argument data: uint8* is of type A_17Bytes
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
 *   Std_ReturnType Rte_Call_IPCIviReportDtcStatus_IpcIviReportDtcSts(uint8 *data, uint8 length)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IPCSocReportDtcStatus_IpcSocReportDtcStatus(uint8 *Data, uint8 Length)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TC_Api_ParamentGetCsPort_Operation(uint8 *arg)
 *     Argument arg: uint8* is of type Diag_9Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_ppCS_GetTankResistanceValue_Operation(uint8 *TankResistanceValue)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(uint8 Id, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DidDataProcess_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) DidDataProcess_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DidDataProcess_MainFunction
 *********************************************************************************************************************/
    uint8 DiagSession ;
    uint8 fctorMode;
    RoutineIdIndexMun_t clearFlag;
    IPC_M2S_DiagnoseQNXSessionControlRequest_t sessionControl;

    Rte_Write_tiSR_VIN_Element(Rte_Pim_NvBlockNeed_VIN_MirrorBlock());  
    
    DiagSession = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
    if((RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION == DiagSession)||
        ( RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == DiagSession))
    {
        if(currentDiagnosticSession != DiagSession)
        {
            currentDiagnosticSession = DiagSession;
            sessionControl.ServiceId = 0x10;
            sessionControl.Type = currentDiagnosticSession;
            IPC_M2S_DiagnoseQNXSessionControlRequest_Transmit(&sessionControl);
        }
    }
    if(RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION == DiagSession)
    {
        for(clearFlag = ROUTINEIDINDEX_A1A1;clearFlag < ROUTINEIDINDEX_INVAILD;clearFlag++)
        {
            ridResetStartFlag[clearFlag] = (uint8)FALSE;
        }
    }

    workModeMonitorCnt++;
    if(workModeMonitorCnt >= WORK_MODE_MONITOR_PERIOD)
    {
        workModeMonitorCnt = 0;
        fctorMode = Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock()[0];
        if(fctorMode != WORKING_FACTORY_MODE)
        {
            Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_SetEventStatus(DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_SetEventStatus(DEM_EVENT_STATUS_FAILED);
        }
    }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: E2ESwitchStatusRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_E2ESwitchStatusRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void E2ESwitchStatusRead(uint8 Length, uint8 *Data, uint8 *Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: E2ESwitchStatusRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) E2ESwitchStatusRead(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: E2ESwitchStatusRead
 *********************************************************************************************************************/
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    uint8 locData;
    Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(&nvmStatus);
    if(NVM_REQ_PENDING != nvmStatus)
    {
        *Status = NVM_REQ_OK;
        *Data = Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0];

        if(factorModeWriteE2EReq)
        {
            locData = Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0];
            Rte_Write_piSR_E2ESwitchChangeTrigger_Element(locData);
            factorModeWriteE2EReq = (uint8)FALSE;
        }
    }
    else
    {
        *Status = NVM_REQ_PENDING;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: E2ESwitchStatusWrite
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_E2ESwitchStatusWrite>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void E2ESwitchStatusWrite(uint8 Length, uint8 *Data, uint8 *Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: E2ESwitchStatusWrite_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) E2ESwitchStatusWrite(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: E2ESwitchStatusWrite
 *********************************************************************************************************************/
    uint8 fctRet;
    uint8 e2eMirrorDataBackup;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    if(*Data < 2)
    {
        Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(&nvmStatus);
        if(NVM_REQ_PENDING != nvmStatus)
        {
            e2eMirrorDataBackup = Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0];
            (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(),Data,1);
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_WriteBlock(NULL_PTR);
            if(E_OK == fctRet)
            {
                factorModeWriteE2EReq = (uint8)TRUE;
                *Status = NVM_REQ_OK;
            }
            else
            {
                Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0] = e2eMirrorDataBackup;
                *Status = NVM_REQ_NOT_OK;
            }
        }
        else
        {
            *Status = NVM_REQ_NOT_OK;
        }
    }
    else
    {
        *Status = NVM_REQ_NOT_OK;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetCANMatrixVersionInfo_Data
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Data> of PortPrototype <ppCS_GetCANMatrixVersionInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetCANMatrixVersionInfo_Data(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetCANMatrixVersionInfo_Data_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) GetCANMatrixVersionInfo_Data(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetCANMatrixVersionInfo_Data
 *********************************************************************************************************************/
    Version_GetCANMatrixVersion(data,19);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetVehicleModeInfo_Data
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Data> of PortPrototype <ppCS_GetVehicleModeInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetVehicleModeInfo_Data(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetVehicleModeInfo_Data_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) GetVehicleModeInfo_Data(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetVehicleModeInfo_Data
 *********************************************************************************************************************/
    memcpy(data,(uint8*)Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock(),sizeof(Dcm_Data20ByteType));

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_E2ESwitch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_FactoryMode>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished
 *********************************************************************************************************************/
    if((NVM_WRITE_BLOCK == ServiceId)&&(E_OK == JobResult))
    {
        Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_ReadBlock((uint8* )Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock());
    }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_VIN>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished
 *********************************************************************************************************************/
    if((NVM_WRITE_BLOCK == ServiceId)&&(E_OK == JobResult))
    {
        Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_ReadBlock((uint8* )Rte_Pim_NvBlockNeed_VIN_MirrorBlock());
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_VehicleMode>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished
 *********************************************************************************************************************/
    if((NVM_WRITE_BLOCK == ServiceId)&&(E_OK == JobResult))
    {
        Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_ReadBlock((uint8* )Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock());
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMAutoCalibration_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AVMAutoCalibration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMAutoCalibration_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_AVMCalibrationResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMAutoCalibration_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMAutoCalibration_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMAutoCalibration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMAutoCalibration_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMAutoCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMCalibrationResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMAutoCalibration_RequestResults (returns application error)
 *********************************************************************************************************************/
    
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
      case DCM_INITIAL:
        if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
        {
            if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F031])
            {
                RequestQnxRoutineControl(0xF031, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
                ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                ret = E_NOT_OK;
            }
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
          break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(Out_AVMCalibrationResult,1,ErrorCode);
        break;
       default:
          ret = E_NOT_OK;
            break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMAutoCalibration_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AVMAutoCalibration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMAutoCalibration_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMAutoCalibration_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMAutoCalibration_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMAutoCalibration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMAutoCalibration_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMAutoCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMAutoCalibration_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
      case DCM_INITIAL:
        if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
        {
            RequestQnxRoutineControl(0xF031, ROUTINE_CONTROL_TYPE_START,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
        break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
      if(RTE_E_OK == ret)
      {
         ridResetStartFlag[ROUTINEIDINDEX_F031] = TRUE;
      }
        break;
      default:
          ret = E_NOT_OK;
      break;
    }
    return (ret);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMEnvironmentCheck_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AVMEnvironmentCheck>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMEnvironmentCheck_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_AVMEnvironmentCheckResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMEnvironmentCheck_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMEnvironmentCheck_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMEnvironmentCheck_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMEnvironmentCheck_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMEnvironmentCheck_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMEnvironmentCheck_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
            {
                if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F030])
                {
                    RequestQnxRoutineControl(0xF030, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
                    ret = DCM_E_FORCE_RCRRP;
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            ret = QnxResponseRoutineControl(Out_AVMEnvironmentCheckResult,1,ErrorCode);
            break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMEnvironmentCheck_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AVMEnvironmentCheck>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMEnvironmentCheck_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMEnvironmentCheck_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMEnvironmentCheck_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMEnvironmentCheck_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMEnvironmentCheck_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMEnvironmentCheck_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMEnvironmentCheck_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
            {
                RequestQnxRoutineControl(0xF030, ROUTINE_CONTROL_TYPE_START,tBuf,0);
                ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
          break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
        if(RTE_E_OK == ret)
        {
            ridResetStartFlag[ROUTINEIDINDEX_F030] = TRUE;
        }
          break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualCalibration_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AVMManualCalibration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualCalibration_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_ManualCalibrationResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualCalibration_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualCalibration_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualCalibration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCalibration_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_ManualCalibrationResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCalibration_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
            {
                if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F033])
                {
                    RequestQnxRoutineControl(0xF033, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
                    ret = DCM_E_FORCE_RCRRP;
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            ret = QnxResponseRoutineControl(Out_ManualCalibrationResult,1,ErrorCode);
            break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualCalibration_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AVMManualCalibration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualCalibration_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualCalibration_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualCalibration_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualCalibration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCalibration_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCalibration_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
            {
                RequestQnxRoutineControl(0xF033, ROUTINE_CONTROL_TYPE_START,tBuf,0);
                ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
        if(RTE_E_OK == ret)
        {
            ridResetStartFlag[ROUTINEIDINDEX_F033] = TRUE;
        }
            break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualCalibration_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <RoutineServices_AVMManualCalibration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualCalibration_Stop(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualCalibration_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualCalibration_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualCalibration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCalibration_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCalibration_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCalibration_Stop (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
            {
                if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F033])
                {
                    RequestQnxRoutineControl(0xF033, ROUTINE_CONTROL_TYPE_STOP,tBuf,0);
                    ret = DCM_E_FORCE_RCRRP;
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
            break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualConerMove_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AVMManualConerMove>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualConerMove_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_AVMManualConerMoveResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualConerMove_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualConerMove_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualConerMove_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualConerMove_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualConerMove_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMManualConerMoveResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualConerMove_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
            {
                if((uint8)TRUE == ridResetStartFlag[ROUTINEIDINDEX_F037])
                {
                    RequestQnxRoutineControl(0xF037, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
                    ret = DCM_E_FORCE_RCRRP;
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
          break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(Out_AVMManualConerMoveResult,1,ErrorCode);
          break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualConerMove_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AVMManualConerMove>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualConerMove_Start(uint8 In_AVMManualConerMove, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualConerMove_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualConerMove_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualConerMove_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualConerMove_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualConerMove_Start(uint8 In_AVMManualConerMove, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualConerMove_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    tBuf[0] = In_AVMManualConerMove;
    if((In_AVMManualConerMove > 0)&&(In_AVMManualConerMove < 5)&&( 0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION]))
    {
        switch(OpStatus)
        {
            case DCM_INITIAL:
              RequestQnxRoutineControl(0xF037, ROUTINE_CONTROL_TYPE_START,tBuf,1);
              ret = DCM_E_FORCE_RCRRP;
              break;
            case DCM_PENDING:
            case DCM_FORCE_RCRRP_OK:
              ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
            if(RTE_E_OK == ret)
            {
                ridResetStartFlag[ROUTINEIDINDEX_F037] = TRUE;
            }
              break;
             default:
                ret = E_NOT_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualConerSelect_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AVMManualConerSelect>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualConerSelect_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_AVMEnvironmentCheckResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualConerSelect_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualConerSelect_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualConerSelect_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualConerSelect_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualConerSelect_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualConerSelect_RequestResults (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = RTE_E_OK;
  uint8 tBuf[2];
  switch(OpStatus)
  {
      case DCM_INITIAL:
        if(0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
        {
            if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F036])
            {
                RequestQnxRoutineControl(0xF036, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
                ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                ret = E_NOT_OK;
            }
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
        break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(Out_AVMEnvironmentCheckResult,1,ErrorCode);
        break;
      default:
          ret = E_NOT_OK;
      break;
  }
  return (ret);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualConerSelect_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AVMManualConerSelect>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualConerSelect_Start(uint8 In_AVMManualConerSelect, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualConerSelect_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualConerSelect_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualConerSelect_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualConerSelect_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualConerSelect_Start(uint8 In_AVMManualConerSelect, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualConerSelect_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    tBuf[0] = In_AVMManualConerSelect;
    if((In_AVMManualConerSelect > 0)&&(In_AVMManualConerSelect < 0x0B)&&(0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION]))
    {
        switch(OpStatus)
        {
            case DCM_INITIAL:
              RequestQnxRoutineControl(0xF036, ROUTINE_CONTROL_TYPE_START,tBuf,1);
              ret = DCM_E_FORCE_RCRRP;
              break;
            case DCM_PENDING:
            case DCM_FORCE_RCRRP_OK:
              ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
            if(RTE_E_OK == ret)
            {
                ridResetStartFlag[ROUTINEIDINDEX_F036] = TRUE;
            }
              break;
            default:
                ret = E_NOT_OK;
            break;

        }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualCorrectValue_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AVMManualCorrectValue>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualCorrectValue_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_AVMManualCorrectValue, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualCorrectValue_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualCorrectValue_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualCorrectValue_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCorrectValue_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCorrectValue_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMManualCorrectValue, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCorrectValue_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
            {
                if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F038])
                {
                    RequestQnxRoutineControl(0xF038, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
                    ret = DCM_E_FORCE_RCRRP;
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            ret = QnxResponseRoutineControl(Out_AVMManualCorrectValue,1,ErrorCode);
            break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualCorrectValue_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AVMManualCorrectValue>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualCorrectValue_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualCorrectValue_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualCorrectValue_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualCorrectValue_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCorrectValue_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCorrectValue_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualCorrectValue_Start (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
            {
                RequestQnxRoutineControl(0xF038, ROUTINE_CONTROL_TYPE_START,tBuf,0);
                ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
          break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
        if(RTE_E_OK == ret)
        {
            ridResetStartFlag[ROUTINEIDINDEX_F038] = TRUE;
        }
          break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualViewSelect_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AVMManualViewSelect>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualViewSelect_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_AVMEnvironmentCheckResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualViewSelect_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualViewSelect_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualViewSelect_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualViewSelect_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualViewSelect_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualViewSelect_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
      case DCM_INITIAL:
            if(0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
            {
                if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F035])
                {
                        RequestQnxRoutineControl(0xF035, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
                    ret = DCM_E_FORCE_RCRRP;
                   }
                else
                {
                    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
          break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(Out_AVMEnvironmentCheckResult,1,ErrorCode);
          break;
      default:
          ret = E_NOT_OK;
      break;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMManualViewSelect_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AVMManualViewSelect>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMManualViewSelect_Start(uint8 In_AVMManualViewSelect, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMManualViewSelect_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMManualViewSelect_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMManualViewSelect_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualViewSelect_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualViewSelect_Start(uint8 In_AVMManualViewSelect, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMManualViewSelect_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    tBuf[0] = In_AVMManualViewSelect;
    if((In_AVMManualViewSelect > 0)&&(In_AVMManualViewSelect < 5)&&(0x2 == vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION]))
    {
      switch(OpStatus)
      {
          case DCM_INITIAL:
            RequestQnxRoutineControl(0xF035, ROUTINE_CONTROL_TYPE_START,tBuf,1);
            ret = DCM_E_FORCE_RCRRP;
            break;
          case DCM_PENDING:
          case DCM_FORCE_RCRRP_OK:
            ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
          if(RTE_E_OK == ret)
        {
            ridResetStartFlag[ROUTINEIDINDEX_F035] = TRUE;
        }
            break;
          default:
              ret = E_NOT_OK;
          break;
      }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_CableDiagnostics_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_CableDiagnostics>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_CableDiagnostics_Start(uint8 In_CableDiagnosticsControl, Dcm_OpStatusType OpStatus, uint8 *Out_Result, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_CableDiagnostics_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_CableDiagnostics_DCM_E_PENDING
 *   RTE_E_RoutineServices_CableDiagnostics_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_CableDiagnostics_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_CableDiagnostics_Start(uint8 In_CableDiagnosticsControl, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_CableDiagnostics_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    if((In_CableDiagnosticsControl > 0 )&&(In_CableDiagnosticsControl <= 4))
    {
        tBuf[0] = In_CableDiagnosticsControl;
        //tBuf[1] = testMode;
        switch(OpStatus)
        {
            case DCM_INITIAL:
                RequestQnxRoutineControl(0xA1A2, ROUTINE_CONTROL_TYPE_START,tBuf,1);
                ret = DCM_E_FORCE_RCRRP;
                break;
            case DCM_PENDING:
            case DCM_FORCE_RCRRP_OK:
                ret = QnxResponseRoutineControl(Out_Result,1,ErrorCode);
                if(RTE_E_OK == ret)
                {
                    ridResetStartFlag[ROUTINEIDINDEX_A1A2] = TRUE;
                }
                break;
            default:
                ret = E_NOT_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ConfigureFrontCamerParameters_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_ConfigureFrontCamerParameters>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ConfigureFrontCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_ConfigureResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ConfigureFrontCamerParameters_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ConfigureFrontCamerParameters_DCM_E_PENDING
 *   RTE_E_RoutineServices_ConfigureFrontCamerParameters_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureFrontCamerParameters_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureFrontCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_ConfigureResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureFrontCamerParameters_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F020])
        {
            RequestQnxRoutineControl(0xF020, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
         }
        else
        {
          *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
          ret = E_NOT_OK;
        }
        break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(Out_ConfigureResult,1,ErrorCode);
        break;
    default:
        ret = E_NOT_OK;
    break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ConfigureFrontCamerParameters_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_ConfigureFrontCamerParameters>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ConfigureFrontCamerParameters_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ConfigureFrontCamerParameters_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ConfigureFrontCamerParameters_DCM_E_PENDING
 *   RTE_E_RoutineServices_ConfigureFrontCamerParameters_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureFrontCamerParameters_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureFrontCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureFrontCamerParameters_Start (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = RTE_E_OK;
  uint8 tBuf[2];
  switch(OpStatus)
  {
    case DCM_INITIAL:
        if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
        {
            RequestQnxRoutineControl(0xF020, ROUTINE_CONTROL_TYPE_START,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
      break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
        if(RTE_E_OK == ret)
        {
            ridResetStartFlag[ROUTINEIDINDEX_F020] = TRUE;
        }
      break;
    default:
        ret = E_NOT_OK;
    break;
  }
  return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ConfigureLeftCamerParameters_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_ConfigureLeftCamerParameters>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ConfigureLeftCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_ConfigureResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ConfigureLeftCamerParameters_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ConfigureLeftCamerParameters_DCM_E_PENDING
 *   RTE_E_RoutineServices_ConfigureLeftCamerParameters_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureLeftCamerParameters_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureLeftCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_ConfigureResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureLeftCamerParameters_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F022])
        {
            RequestQnxRoutineControl(0xF022, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
         }
        else
        {
          *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
          ret = E_NOT_OK;
        }
        break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(Out_ConfigureResult,1,ErrorCode);
        break;
    default:
        ret = E_NOT_OK;
    break;

    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ConfigureLeftCamerParameters_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_ConfigureLeftCamerParameters>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ConfigureLeftCamerParameters_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ConfigureLeftCamerParameters_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ConfigureLeftCamerParameters_DCM_E_PENDING
 *   RTE_E_RoutineServices_ConfigureLeftCamerParameters_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureLeftCamerParameters_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureLeftCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureLeftCamerParameters_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
        {
            RequestQnxRoutineControl(0xF022, ROUTINE_CONTROL_TYPE_START,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
      break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
        if(RTE_E_OK == ret)
        {
            ridResetStartFlag[ROUTINEIDINDEX_F022] = TRUE;
        }
      break;
    default:
        ret = E_NOT_OK;
    break;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ConfigureRearCamerParameters_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_ConfigureRearCamerParameters>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ConfigureRearCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_ConfigureResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ConfigureRearCamerParameters_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ConfigureRearCamerParameters_DCM_E_PENDING
 *   RTE_E_RoutineServices_ConfigureRearCamerParameters_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureRearCamerParameters_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRearCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_ConfigureResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureRearCamerParameters_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F021])
        {
            RequestQnxRoutineControl(0xF021, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
         }
        else
        {
          *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
          ret = E_NOT_OK;
        }
        break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(Out_ConfigureResult,1,ErrorCode);
        break;
             default:
                ret = E_NOT_OK;
            break;
    }
    return (ret);



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ConfigureRearCamerParameters_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_ConfigureRearCamerParameters>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ConfigureRearCamerParameters_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ConfigureRearCamerParameters_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ConfigureRearCamerParameters_DCM_E_PENDING
 *   RTE_E_RoutineServices_ConfigureRearCamerParameters_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureRearCamerParameters_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRearCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureRearCamerParameters_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
        {
            RequestQnxRoutineControl(0xF021, ROUTINE_CONTROL_TYPE_START,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
      break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
        if(RTE_E_OK == ret)
        {
            ridResetStartFlag[ROUTINEIDINDEX_F021] = TRUE;
        }
      break;
    default:
        ret = E_NOT_OK;
    break;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ConfigureRightCamerParameters_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_ConfigureRightCamerParameters>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ConfigureRightCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_ConfigureResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ConfigureRightCamerParameters_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ConfigureRightCamerParameters_DCM_E_PENDING
 *   RTE_E_RoutineServices_ConfigureRightCamerParameters_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureRightCamerParameters_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRightCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_ConfigureResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureRightCamerParameters_RequestResults (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F023])
        {
            RequestQnxRoutineControl(0xF023, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
         }
        else
        {
          *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
          ret = E_NOT_OK;
        }
        break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(Out_ConfigureResult,1,ErrorCode);
        break;
    default:
        ret = E_NOT_OK;
    break;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ConfigureRightCamerParameters_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_ConfigureRightCamerParameters>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ConfigureRightCamerParameters_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ConfigureRightCamerParameters_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ConfigureRightCamerParameters_DCM_E_PENDING
 *   RTE_E_RoutineServices_ConfigureRightCamerParameters_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureRightCamerParameters_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRightCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ConfigureRightCamerParameters_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        if(vConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
        {
            RequestQnxRoutineControl(0xF023, ROUTINE_CONTROL_TYPE_START,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
      break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
        if(RTE_E_OK == ret)
        {
            ridResetStartFlag[ROUTINEIDINDEX_F023] = TRUE;
        }
      break;
    default:
        ret = E_NOT_OK;
    break;
    }
    return (ret);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ODOReset_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_ODOReset>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(uint8 Id, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ODOReset_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_OdoResetResult, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ODOReset_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ODOReset_DCM_E_PENDING
 *   RTE_E_RoutineServices_ODOReset_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ODOReset_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ODOReset_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_OdoResetResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ODOReset_RequestResults (returns application error)
 *********************************************************************************************************************/
    uint8 locResult;
    Std_ReturnType ret = RTE_E_OK;

    if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_FD21])
    {
        Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(4u, &locResult);
        if(4u == locResult)
        {
            ret = RTE_E_RoutineServices_ODOReset_DCM_E_PENDING;
        }
        else
        {
            *Out_OdoResetResult = locResult;
        }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        ret = RTE_E_RoutineServices_ODOReset_E_NOT_OK;
    }
    return ret;
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ODOReset_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_ODOReset>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_Power_Out_DidProcess_SystemStateOut(SystemState_RecordType *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_cpCS_OdoSetParament_Operation(uint8 SetId, uint32 *data)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_OdoSetParament_Std_ReturnType
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ODOReset_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ODOReset_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ODOReset_DCM_E_PENDING
 *   RTE_E_RoutineServices_ODOReset_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ODOReset_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ODOReset_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ODOReset_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retValue = RTE_E_OK;
    Std_ReturnType fctRet;
    uint8 signalSysPowerMode;
    fctRet = Rte_Read_kl15SysPowerMod_SysPowerMod(&signalSysPowerMode);

    if((E_OK == fctRet )&&(Cx2_ON == signalSysPowerMode))
    {
        Rte_Call_cpCS_OdoSetParament_Operation(1,NULL_PTR);
        ridResetStartFlag[ROUTINEIDINDEX_FD21] = (uint8)TRUE;
    }
    else
    {
        ridResetStartFlag[ROUTINEIDINDEX_FD21] = FALSE;
       *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
       retValue = RTE_E_RoutineServices_ODOReset_E_NOT_OK;
    }
    return (retValue);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_PhyTestMode_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_PhyTestMode>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_PhyTestMode_Start(uint8 In_PortNumber, uint8 In_TestMode, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_PhyTestMode_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_PhyTestMode_DCM_E_PENDING
 *   RTE_E_RoutineServices_PhyTestMode_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_PhyTestMode_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_PhyTestMode_Start(uint8 In_PortNumber, uint8 In_TestMode, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_PhyTestMode_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    if(((In_PortNumber > 0)&&(In_PortNumber <= 4))&&(In_TestMode < 0x08))
    {
        tBuf[0] = In_PortNumber;
        tBuf[1] = In_TestMode;
        switch(OpStatus)
        {
            case DCM_INITIAL:
                RequestQnxRoutineControl(0xA1A1, ROUTINE_CONTROL_TYPE_START,tBuf,2);
                ret = DCM_E_FORCE_RCRRP;
            
                break;
            case DCM_PENDING:
            case DCM_FORCE_RCRRP_OK:
                ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
            if(RTE_E_OK == ret)
            {
                ridResetStartFlag[ROUTINEIDINDEX_A1A1] = TRUE;
            }
                break;
            default:
                routineCtrlRequest.RoutineId = 0;
                break;
        }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_ResetSwitchStatistics_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_ResetSwitchStatistics>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_ResetSwitchStatistics_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ResetSwitchStatistics_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ResetSwitchStatistics_DCM_E_PENDING
 *   RTE_E_RoutineServices_ResetSwitchStatistics_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ResetSwitchStatistics_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ResetSwitchStatistics_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_ResetSwitchStatistics_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    //tBuf[0] = testNumber;
    //tBuf[1] = testMode;
    switch(OpStatus)
    {
        case DCM_INITIAL:
            if(0x3 == vConfigDataBuf[VCONFIG_KIND_HUT_ETHERNET_PORT])
            {
                RequestQnxRoutineControl(0xA1A3, ROUTINE_CONTROL_TYPE_START,tBuf,0);
                ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
          break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            ret = QnxResponseRoutineControl(tBuf,0,ErrorCode);
            if(RTE_E_OK == ret)
            {
                ridResetStartFlag[ROUTINEIDINDEX_A1A3] = TRUE;
            }
            break;
        default:
            routineCtrlRequest.RoutineId = 0;
            break;
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_SystemRecovery_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_SystemRecovery>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppSR_System_Recovery_System_Recovery(boolean data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_SystemRecovery_Start(Dcm_OpStatusType OpStatus, uint8 *Out_SystemRcvrySts, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_SystemRecovery_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_SystemRecovery_DCM_E_PENDING
 *   RTE_E_RoutineServices_SystemRecovery_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_SystemRecovery_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_SystemRecovery_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_SystemRcvrySts, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_SystemRecovery_Start (returns application error)
 *********************************************************************************************************************/
  Rte_Write_DidDataProcess_ppSR_System_Recovery_System_Recovery(TRUE);
  *Out_SystemRcvrySts = 0x01;
  ridResetStartFlag[ROUTINEIDINDEX_FD20] = (uint8)TRUE;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecOcSwitchStatusRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SecOcSwitchStatusRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SecOcSwitchStatusRead(uint8 Length, uint8 *Data, uint8 *Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecOcSwitchStatusRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) SecOcSwitchStatusRead(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecOcSwitchStatusRead
 *********************************************************************************************************************/
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(&nvmStatus);
    if( NVM_REQ_PENDING != nvmStatus)
    {
        *Status = NVM_REQ_OK;
        *Data   = Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0];
        if(TRUE == factorModeWriteSecOcReq)
        {
            if(0x01 == Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0])
            {
                SecOC_SetDevelopmentMode(FALSE);
            }
            else
            {
                SecOC_SetDevelopmentMode(TRUE);
            }
            factorModeWriteSecOcReq = (uint8)FALSE;
        }
    }
    else
    {
        *Status = NVM_REQ_PENDING;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecOcSwitchStatusWrite
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SecOcSwitchStatusWrite>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SecOcSwitchStatusWrite(uint8 Length, uint8 *Data, uint8 *Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecOcSwitchStatusWrite_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) SecOcSwitchStatusWrite(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecOcSwitchStatusWrite
 *********************************************************************************************************************/
    uint8 fctRet;
    uint8 secOcMirrorDataBackup;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    if(*Data < 2)
    {
        Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(&nvmStatus);
        if(NVM_REQ_PENDING != nvmStatus)
        {
            secOcMirrorDataBackup = Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0];
            (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(),Data,1);
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_WriteBlock(NULL_PTR);
            if(E_OK == fctRet)
            {
                factorModeWriteSecOcReq = (uint8)TRUE;
                *Status = NVM_REQ_OK;
            }
            else
            {
                Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0] = secOcMirrorDataBackup;
                *Status = NVM_REQ_NOT_OK;
            }
        }
        else
        {
            *Status = NVM_REQ_NOT_OK;
        }
    }
    else
    {
        *Status = NVM_REQ_NOT_OK;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ppCS_Diag_ReadDidData_Operation
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <piCS_Diag_ReadDidData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ppCS_Diag_ReadDidData_Operation(uint16 dataId, uint8 opStatus, uint8 *data, uint16 length)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_piCS_Diag_ReadDidData_DCM_E_PENDING
 *   RTE_E_piCS_Diag_ReadDidData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_Diag_ReadDidData_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) ppCS_Diag_ReadDidData_Operation(uint16 dataId, uint8 opStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_Diag_ReadDidData_Operation (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retValue = RTE_E_OK;
    uint8 ErrorCode;
    if( 0xF1C5 == dataId)/*read ivi DID data UIN*/
    {
        retValue = ReadIVIDidDataFixLengthProcess(dataId,opStatus,data,length);
    }
    else
    {
        retValue = ReadQnxDidDataRequestProcess(dataId,opStatus,&ErrorCode);
        if(RTE_E_OK == retValue)
        {
            retValue = CopyQnxDidRspData(dataId,data,length);
        }
    }
    return retValue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ppCS_Diag_WriteDidData_Operation
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <piCS_Diag_WriteDidData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ppCS_Diag_WriteDidData_Operation(uint16 dataId, uint8 opStatus, uint8 *data, uint16 length, uint8 *errorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_piCS_Diag_WriteDidData_DCM_E_PENDING
 *   RTE_E_piCS_Diag_WriteDidData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_Diag_WriteDidData_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) ppCS_Diag_WriteDidData_Operation(uint16 dataId, uint8 opStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) errorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_Diag_WriteDidData_Operation (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retValue = RTE_E_OK;
  retValue = WriteQnxDidDataRequestProcess(dataId,opStatus, data,length,errorCode);
  return retValue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <USBWriteData> of PortPrototype <ppCS_USBWriteECUlevelNetworkConfigurationData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData(uint8 *data, uint16 length, uint8 OpStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_USBWriteECUlevelNetworkConfigurationData_E_NOT_OK
 *   RTE_E_USBWriteECUlevelNetworkConfigurationData_E_OK
 *   RTE_E_USBWriteECUlevelNetworkConfigurationData_E_PENDING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length, uint8 OpStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_USBWriteECUlevelNetworkConfigurationData_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;

    uint8 fctRet = E_NOT_OK;
    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_GetErrorStatus(&nvmStatus);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus)&&(length == sizeof(Dcm_Data200ByteType)))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(),(uint8 *)data,sizeof(Dcm_Data200ByteType));
                (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_WriteBlock(NULL_PTR);
                ret = RTE_E_USBWriteECUlevelNetworkConfigurationData_E_PENDING;
            }
            else
            {
                ret = RTE_E_USBWriteECUlevelNetworkConfigurationData_E_NOT_OK;
            }
            break;
        case DCM_PENDING:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_GetErrorStatus(&nvmStatus);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(),0,sizeof(Dcm_Data200ByteType));
                    ret = RTE_E_USBWriteECUlevelNetworkConfigurationData_E_NOT_OK;
                }
            }
            else
            {
                ret = RTE_E_USBWriteECUlevelNetworkConfigurationData_E_PENDING;
            }
            break;
        default:
            ret = RTE_E_USBWriteECUlevelNetworkConfigurationData_E_NOT_OK;
            break;
    
    }
    return (ret);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DidDataProcess_STOP_SEC_CODE
#include "DidDataProcess_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
void IPC_Call_Diagnose_ReceiveData(uint8 msgMajorId, uint8 msgSubId, uint8 *param, uint16 paramLen)
{
    
    if((IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID == msgMajorId))
    {
        switch(msgSubId)
        {
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_ID:
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_ID:
                IPC_S2M_DiagnoseQNXDidReadResponse_Receive(param, &didReadRsp, paramLen);
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_ID:
                IPC_S2M_DiagnoseQNXDidWriteResponse_Receive(param,&didWriteRsp, paramLen);
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_ID:
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_ID:
                IPC_S2M_DiagnoseQNXRoutineControlResponse_Receive(param,&routineCtrlRsp, paramLen);
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_ID:
                Rte_Call_IPCSocReportDtcStatus_IpcSocReportDtcStatus(param,(uint8)paramLen);
                break;
            default:

                break;
        }

    }
    
    if(IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID == msgMajorId)
    {
        switch(msgSubId)
        {

            case IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_ID:
                IPC_S2M_DiagnoseIVIDidReadResponse_Receive(param, &iviReadDataResponse, paramLen);
                ReceiveIVIResponseData();
                break;
            case IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_ID:
                IPC_S2M_DiagnoseIVIDidWriteResponse_Receive(param, &iviWriteDataResponse, paramLen);
                break;

            case IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_ID:
                Rte_Call_IPCIviReportDtcStatus_IpcIviReportDtcSts(param,(uint8)paramLen);
                break;
            default:

                break;
        }
    }
}

static Std_ReturnType WriteQnxDidDataRequestProcess(uint16 DataId,uint8 OpStatus, const uint8 *Data,uint16 dataLen,uint8* ErrorCode)
{
    Std_ReturnType ret = DCM_E_OK;
    
    uint16 i;
    

    switch(OpStatus)
    {
        case DCM_INITIAL:
            didWriteRequest.ServiceId = 0x2E;
            didWriteRequest.Did  = DataId;
            didWriteRequest.PayloadLength = dataLen;

            for(i = 0;i < didWriteRequest.PayloadLength;i++)
            {
                didWriteRequest.Payload[i] = Data[i]; 
            }
            IPC_M2S_DiagnoseQNXDidWriteRequest_Transmit(&didWriteRequest);
            diagWaitSocRspTime = WRITE_SOC_DATA_MAX_TIME;
            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(( didWriteRequest.Did != 0 )&&(didWriteRequest.Did == didWriteRsp.Did))
            {
                if(didWriteRsp.ServiceId == (didWriteRequest.ServiceId + 0x40))
                {
                    ret = DCM_E_OK;
                }
                else if((DCM_E_GENERALPROGRAMMINGFAILURE == didWriteRsp.ServiceId)||(DCM_E_CONDITIONSNOTCORRECT == didWriteRsp.ServiceId)||
                        (DCM_E_REQUESTOUTOFRANGE == didWriteRsp.ServiceId))
                {
                    *ErrorCode = didWriteRsp.ServiceId;
                    ret = E_NOT_OK;
                }
                else
                {
                    *ErrorCode = didWriteRsp.ServiceId;
                    ret = E_NOT_OK;
                }
                didWriteRequest.Did = 0;
                didWriteRsp.Did  = 0;
            }
            else
            {
                if(diagWaitSocRspTime > 0)
                {
                    diagWaitSocRspTime--;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    didWriteRequest.Did = 0;
                    didWriteRsp.Did  = 0;
                    ret = E_NOT_OK;
                }
            }
           
        break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);

}


static Std_ReturnType ReadQnxDidDataRequestProcess(uint16 DataId,uint8 OpStatus,uint8* ErrorCode)
{
    Std_ReturnType ret = DCM_E_OK;
    


    switch(OpStatus)
    {
        case DCM_INITIAL:
            didReadRequest.ServiceId = 0x22;
            didReadRequest.Did = DataId;
            IPC_M2S_DiagnoseQNXDidReadRequest_Transmit(&didReadRequest);
            diagWaitSocRspTime = READ_SOC_DATA_MAX_TIME;
            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(( didReadRequest.Did != 0 )&&(didReadRequest.Did == didReadRsp.Did))
            {
                if(didReadRsp.ServiceId == (didReadRequest.ServiceId + 0x40))
                {
                    ret = DCM_E_OK;
                }
                else if((DCM_E_CONDITIONSNOTCORRECT == didReadRsp.ServiceId)||(DCM_E_REQUESTOUTOFRANGE == didReadRsp.ServiceId))
                {
                    *ErrorCode = didReadRsp.ServiceId;
                    ret = E_NOT_OK;
                }
                else
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                if(diagWaitSocRspTime > 0)
                {
                    diagWaitSocRspTime--;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
        break;
        default:
            ret = E_NOT_OK;
        break;
    }
    if(E_NOT_OK == ret)
    {
        didReadRequest.Did = 0;
        didReadRsp.Did = 0;
    }
    return (ret);
}

static Std_ReturnType CopyQnxDidRspData(uint16 DataId,uint8 *Data,uint16 Length)
{
    Std_ReturnType ret = E_NOT_OK;
    if(( didReadRequest.Did == DataId )&&(didReadRequest.Did == didReadRsp.Did)&&(didReadRsp.ServiceId == (didReadRequest.ServiceId + 0x40)))
    {
        memcpy(Data,&(didReadRsp.Data[0]),Length);
        ret = DCM_E_OK;
    }
    didReadRequest.Did = 0;
    didReadRsp.Did  = 0;
    return ret;
}

static Std_ReturnType ReadVipDidDataReqProcess(uint16 DataId,uint8 OpStatus,uint8 *Data,uint16 Length)
{
   Std_ReturnType ret = RTE_E_OK;
    switch(DataId)
    {
        case 0xF18A:
            Version_GetSystemSupplierIdentifier(Data,Length);
        break;
        case 0xF1A2:
            Version_GetCANMatrixVersion(Data,Length);
            break;
        case 0xF1C0:
            Version_GetGwmEcuCalibrationSoftwareVersionn(Data,Length);
            break;
        case 0xF1C1:
            Version_GetGwmEcuBootSoftwareVersion(Data,Length);
            break;
        default:
            ret = E_NOT_OK;
            break;
    }
    return (ret);

}



static void RequestQnxRoutineControl(uint16 RoutineId,uint8 Type,const uint8* Option,uint8 OptionLen)
{
    uint16 i;
    sint32 ret;
    routineCtrlRequest.ServiceId = 0x31 ;
    routineCtrlRequest.RoutineId = RoutineId;
    routineCtrlRequest.Type = Type;
    if(OptionLen)
    {
        for(i = 0;i < OptionLen;i++)
        {
            routineCtrlRequest.Option[i] = *Option;
            Option++;
        }
    }
    routineCtrlRequest.OptionLength = OptionLen;
    ret = IPC_M2S_DiagnoseQNXRoutineControlRequest_Transmit(&routineCtrlRequest);
    if(ret)
    {
        IPC_M2S_DiagnoseQNXRoutineControlRequest_Transmit(&routineCtrlRequest);
    }
    diagWaitSocRspTime = READ_SOC_DATA_MAX_TIME;
}
static Std_ReturnType QnxResponseRoutineControl(uint8* Status,uint8 StatusLen,uint8* ErrorCode)
{
    Std_ReturnType ret = DCM_E_OK;
    
    if((routineCtrlRequest.RoutineId != 0)&&
        (routineCtrlRequest.RoutineId == routineCtrlRsp.RoutineId)&&
        (routineCtrlRequest.Type == routineCtrlRsp.Type))
    {
        if(routineCtrlRsp.ServiceId ==(routineCtrlRequest.ServiceId + 0x40))
        {
            if(StatusLen > 0)
            {
                memcpy(Status,&routineCtrlRsp.State[0],StatusLen);
            }
        }
        else if(0x7F == routineCtrlRsp.ServiceId)
        {
            *ErrorCode = routineCtrlRsp.State[0];
            ret = E_NOT_OK;
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
        routineCtrlRsp.RoutineId = 0;
        routineCtrlRequest.RoutineId = 0;
    }
    else
    {
        if(diagWaitSocRspTime > 0)
        {
            diagWaitSocRspTime--;
            ret = DCM_E_PENDING;
        }
        else
        {
            routineCtrlRequest.RoutineId = 0;
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
    }
    return (ret);
}

static Std_ReturnType SocRspTimeOutHandle(uint8 OpStatus)
{
    Std_ReturnType retValue = DCM_E_PENDING;
    if(DCM_INITIAL == OpStatus )
    {
        diagWaitSocRspTime = WRITE_SOC_DATA_MAX_TIME;
    }
    if(diagWaitSocRspTime > 0)
    {
        diagWaitSocRspTime--;
    }
    else
    {
         retValue = E_NOT_OK;
    }
    return (retValue);
}


static Std_ReturnType WriteIVIDidDataProcess(uint16 DataId,uint8 OpStatus, const uint8 *Data,uint16 dataLen)
{
    Std_ReturnType ret = DCM_E_OK;
    
    uint8 reqIpcTx = 0;
    
    switch(OpStatus)
    {
        case DCM_INITIAL:
            memcpy(ipcDataBuf,Data,dataLen);
            
            writeIviDataManger.dataLen = dataLen;
            writeIviDataManger.dataIndx = 0;
            writeIviDataManger.remainingDataLen = dataLen;
            
            iviWriteDataRequest.ServiceId = 0x2E;
            iviWriteDataRequest.Did  = DataId;
            iviWriteDataRequest.TotalLenth = dataLen;
            iviWriteDataRequest.number = 0;
            
            if(writeIviDataManger.remainingDataLen  > IVI_DATA_MAX_SIZE)
            {
                memcpy((uint8*)iviWriteDataRequest.Payload,(uint8*)(&ipcDataBuf[writeIviDataManger.dataIndx]),IVI_DATA_MAX_SIZE);
                writeIviDataManger.dataIndx += IVI_DATA_MAX_SIZE;
                writeIviDataManger.remainingDataLen -= IVI_DATA_MAX_SIZE;
                iviWriteDataRequest.PayloadLength = IVI_DATA_MAX_SIZE;
                writeIviDataManger.waitIviRspTime = 15;
            
                reqIpcTx = 1;
            }
            else
            {
                if(writeIviDataManger.remainingDataLen > 0)
                {
                    memcpy((uint8*)iviWriteDataRequest.Payload,(uint8*)(&ipcDataBuf[writeIviDataManger.dataIndx]),writeIviDataManger.remainingDataLen);
                    iviWriteDataRequest.PayloadLength = writeIviDataManger.remainingDataLen;
                    writeIviDataManger.remainingDataLen = 0;
                    writeIviDataManger.waitIviRspTime = 950;/*wait 9.5s */
                    reqIpcTx = 1;
                }
            }
            if(0 != reqIpcTx)
            {
                iviWriteDataRequest.number += 1;
                IPC_M2S_DiagnoseIVIDidWriteRequest_Transmit(&iviWriteDataRequest); 
            }
         
            ret  = DCM_E_PENDING;
           
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            
            if(writeIviDataManger.remainingDataLen > 0)
            {
                if(writeIviDataManger.waitIviRspTime > 0)
                {
                    writeIviDataManger.waitIviRspTime--;
                }
                else
                {
                    if(writeIviDataManger.remainingDataLen  > IVI_DATA_MAX_SIZE)
                    {
                        memcpy((uint8*)iviWriteDataRequest.Payload,(uint8*)(&Data[writeIviDataManger.dataIndx]),IVI_DATA_MAX_SIZE);
                        writeIviDataManger.dataIndx += IVI_DATA_MAX_SIZE;
                        writeIviDataManger.remainingDataLen -= IVI_DATA_MAX_SIZE;
                        iviWriteDataRequest.PayloadLength = IVI_DATA_MAX_SIZE;
                        writeIviDataManger.waitIviRspTime = 15;
                        reqIpcTx = 1;

                    }
                    else
                    {
                        memcpy((uint8*)iviWriteDataRequest.Payload,(const uint8*)(&Data[writeIviDataManger.dataIndx]),writeIviDataManger.remainingDataLen);
                        iviWriteDataRequest.PayloadLength = writeIviDataManger.remainingDataLen;
                        writeIviDataManger.remainingDataLen = 0;
                        writeIviDataManger.waitIviRspTime = 950;/*wait 9.5s */
                        reqIpcTx = 1;
                    }
                    
                    if(reqIpcTx)
                    {
                        iviWriteDataRequest.number += 1;
                        IPC_M2S_DiagnoseIVIDidWriteRequest_Transmit(&iviWriteDataRequest); 
                    }
                }
                ret = DCM_E_PENDING;
            }
            else
            {
                if((iviWriteDataRequest.Did != 0)&&(iviWriteDataResponse.Did == iviWriteDataRequest.Did)&&
                        (iviWriteDataResponse.ServiceId == (iviWriteDataRequest.ServiceId + 0x40)))
                {
                    iviWriteDataRequest.Did = 0;
                    iviWriteDataResponse.Did = 0;
                    ret = DCM_E_OK; 
                }
                else if((iviWriteDataRequest.Did != 0)&&(iviWriteDataResponse.Did == iviWriteDataRequest.Did)&&
                        (0x7F == iviWriteDataResponse.ServiceId))
                {
                    iviWriteDataRequest.Did = 0;
                    iviWriteDataResponse.Did = 0;
                    ret = E_NOT_OK;
                }
                else
                {
                    if(writeIviDataManger.waitIviRspTime > 0)
                    {
                        writeIviDataManger.waitIviRspTime--;
                        ret = DCM_E_PENDING;
                    }
                    else
                    {
                        ret = E_NOT_OK;
                    }

                }
            }
           
        break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);


}


static void ReceiveIVIResponseData(void)
{
    uint16 tmpLen;
    if(( iviReadDataRequest.Did != 0 )&&(iviReadDataRequest.Did == iviReadDataResponse.Did)&&(iviReadDataResponse.ServiceId == (iviReadDataRequest.ServiceId + 0x40)))
    {
        if((readIviDataManger.sequenceCount + 1) == iviReadDataResponse.Number)
        {
            if(1 == iviReadDataResponse.Number)
            {
                readIviDataManger.dataLen = iviReadDataResponse.TotalLength;
                readIviDataManger.remainingDataLen = iviReadDataResponse.TotalLength;
                readIviDataManger.dataIndx = 0;
            }

            if(readIviDataManger.remainingDataLen > iviReadDataResponse.DataLength)
            {
              tmpLen = iviReadDataResponse.DataLength;  
            }
            else
            {
                tmpLen = readIviDataManger.remainingDataLen;
            }            
            memcpy((uint8*)&ipcDataBuf[readIviDataManger.dataIndx],(uint8*)&iviReadDataResponse.Data[0],tmpLen);
            readIviDataManger.dataIndx += tmpLen;
            readIviDataManger.remainingDataLen -= tmpLen; 
            if(readIviDataManger.dataIndx >= readIviDataManger.dataLen)
            {
                iviReadDataRequest.Did = 0;
                iviReadDataRequest.ServiceId = 0;
            }
            readIviDataManger.sequenceCount += 1;

            iviReadDataResponse.Did = 0;
            iviReadDataResponse.ServiceId = 0;   
        }
        else
        {

        }

    }

}



static Std_ReturnType ReadIVIDidDataStart(uint16 DataId,Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength)
{
    Std_ReturnType ret = DCM_E_OK;
 
    switch(OpStatus)
    {
        case DCM_INITIAL:
            iviReadDataRequest.ServiceId = 0x22;
            iviReadDataRequest.Did = DataId;
            readIviDataManger.waitIviRspTime = READ_SOC_DATA_MAX_TIME;
            readIviDataManger.sequenceCount = 0;
            readIviDataManger.dataLen = 0;
            IPC_M2S_DiagnoseIVIDidReadRequest_Transmit(&iviReadDataRequest);            

            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:

            if((0 != readIviDataManger.sequenceCount)&&(0 != readIviDataManger.dataLen))
            {
                *DataLength = readIviDataManger.dataLen; 
            }
            else
            { 
                if(readIviDataManger.waitIviRspTime > 0)
                {
                    readIviDataManger.waitIviRspTime--;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }             
        break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret);

}

static Std_ReturnType ReadIVIDidDataRepeate(uint8 OpStatus, uint8 *Data)
{
    Std_ReturnType ret = DCM_E_OK;
    
    if(DCM_INITIAL == OpStatus)
    {
        readIviDataManger.waitIviRspTime = READ_SOC_DATA_MAX_TIME;
    }
    
    if((readIviDataManger.dataLen > 0)&&(readIviDataManger.dataIndx >= readIviDataManger.dataLen))
    {
        memcpy(Data,ipcDataBuf,readIviDataManger.dataLen);
    }
    else
    {
        if(readIviDataManger.waitIviRspTime > 0)
        {
            readIviDataManger.waitIviRspTime--;
            ret = DCM_E_PENDING;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return (ret);
}


static Std_ReturnType ReadIVIDidDataFixLengthProcess(uint16 DataId,uint8 OpStatus,uint8 *Data,uint16 Length)
{    
    Std_ReturnType ret = DCM_E_OK;
    
    uint16 i;

    switch(OpStatus)
    {
        case DCM_INITIAL:
            iviReadDataRequest.ServiceId = 0x22;
            iviReadDataRequest.Did = DataId;
            IPC_M2S_DiagnoseIVIDidReadRequest_Transmit(&iviReadDataRequest);
            diagWaitSocRspTime = READ_SOC_DATA_MAX_TIME;
            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(( iviReadDataRequest.Did != 0 )&&(iviReadDataRequest.Did == iviReadDataResponse.Did)&&(iviReadDataResponse.ServiceId == (iviReadDataRequest.ServiceId + 0x40)))
            {
                if(iviReadDataResponse.DataLength < Length)
                {
                    ret = E_NOT_OK;
                }
                else
                {
                    for(i = 0; i < Length; i++)
                    {
                        Data[i] = iviReadDataResponse.Data[i];
                    }               
                    ret = DCM_E_OK;
                }
                iviReadDataResponse.ServiceId = 0;
                iviReadDataResponse.Did = 0;
                iviReadDataRequest.Did = 0;
            }
            else
            {
                if(diagWaitSocRspTime > 0)
                {
                    diagWaitSocRspTime--;
                    ret = DCM_E_PENDING;
                    
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
             
        break;
        default:
            ret = E_NOT_OK;
        break;
    }
    return (ret); 


}


void DidDataProcess_PreInit(void)
{
    Rte_Write_ECUlevelNetworkConfigurationDataIdentifier_Element(Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock());
    Rte_Write_tiSR_VIN_Element(Rte_Pim_NvBlockNeed_VIN_MirrorBlock());
    Rte_Write_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock());
    Rte_Write_piSR_E2ESwitchChangeTrigger_Element((uint8)(Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0]));
    //Rte_Write_piSR_SecOcSwitchChangeTrigger_Element((uint8)(Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0]));   
    if(Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0] == 0x01)
    {
        SecOC_SetDevelopmentMode(FALSE);
    }
    else
    {
        SecOC_SetDevelopmentMode(TRUE);
    } 

}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:DataServices_UIN_UIN_ReadData_doc)  *******************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_UIN_UIN_ConditionCheckRead_doc)  *********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_UIN_UIN_ReadData)  ******************/
  Std_ReturnType retVal;
  retVal  = ReadVipDidDataReqProcess(0xF1C5,OpStatus,Data,sizeof(Dcm_Data15ByteType));
  return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_UIN_UIN_ConditionCheckRead)  ********/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayHardwareVersionNumber_HUTDisplayHardwareVersionNumber_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplaySoftwareVersionNumber_HUTDisplaySoftwareVersionNumber_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplaySupplierInformation_HUT_Display_Supplier_Information_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayHardwareVersionNumber_HUTDisplayHardwareVersionNumber_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayTPVersionNumber_HUTDisplayTPVersionNumber_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_IPDisplaySparePartNumber_IPDisplaSparePartNumber_ReadData)  */

  Std_ReturnType  retVal;
  uint16 dataId = 0xFEFD;
  retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data13ByteType));
  return retVal;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplaySupplierInformation_HUT_Display_Supplier_Information_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_IPDisplaySparePartNumber_IPDisplaSparePartNumber_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayResolution_HUTDisplayResolution_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayResolution_HUTDisplayResolution_ReadData)  */

Std_ReturnType  retVal;
uint16 dataId = 0xFEF1;

retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data1ByteType));
return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayScreenType_HUTDisplayScreenType_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayManufacturingDate_HUTDisplayManufacturingDate_ReadData)  */

  Std_ReturnType  retVal;
  uint16 dataId = 0xFEF6;
retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data4ByteType));
  return retVal;
  
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayTemperature_HUT_Display_LCD_Temperature_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_IPDisplayHardwareVersionNumber_IPDisplayHardwareVersionNumber_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_IPDisplayHardwareVersionNumber_IPDisplayHardwareVersionNumber_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayTemperature_HUT_Display_LCD_Temperature_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplaySoftwareVersionNumber_HUTDisplaySoftwareVersionNumber_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayScreenType_HUTDisplayScreenType_ReadData)  */

Std_ReturnType  retVal;
uint16 dataId = 0xFEF0;

retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data1ByteType));
return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayTPVersionNumber_HUTDisplayTPVersionNumber_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_IPDisplayHardwareVersionNumber_IPDisplayHardwareVersionNumber_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayTPVersionNumber_HUTDisplayTPVersionNumber_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplaySparePartNumber_HUTDisplaySparePartNumber_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplaySparePartNumber_HUTDisplaySparePartNumber_ReadData)  */

  Std_ReturnType  retVal;
  uint16 dataId = 0xFEF7;
  retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data13ByteType));
  return retVal;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplaySoftwareVersionNumber_HUTDisplaySoftwareVersionNumber_ReadData)  */

  Std_ReturnType  retVal;
  uint16 dataId = 0xFEF8;
retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data2ByteType));
  return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayScreenType_HUTDisplayScreenType_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplaySparePartNumber_HUTDisplaySparePartNumber_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayTemperature_HUT_Display_LCD_Temperature_ReadData)  */
  Std_ReturnType  retVal;
  uint16 dataId = 0xFEF5;
retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data2ByteType));
  return retVal;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplaySparePartNumber_HUTDisplaySparePartNumber_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplaySupplierInformation_HUT_Display_Supplier_Information_ReadData)  */

   Std_ReturnType  retVal;
  uint16 dataId = 0xFEF3;
retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data1ByteType));
  return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplaySupplierInformation_HUT_Display_Supplier_Information_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayManufacturingDate_HUTDisplayManufacturingDate_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayManufacturingDate_HUTDisplayManufacturingDate_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplaySoftwareVersionNumber_HUTDisplaySoftwareVersionNumber_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayResolution_HUTDisplayResolution_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayResolution_HUTDisplayResolution_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayManufacturingDate_HUTDisplayManufacturingDate_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_IPDisplaySparePartNumber_IPDisplaSparePartNumber_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayHardwareVersionNumber_HUTDisplayHardwareVersionNumber_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayHardwareVersionNumber_HUTDisplayHardwareVersionNumber_ReadData)  */

  Std_ReturnType  retVal;
  uint16 dataId = 0xFEF9;
retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data2ByteType));
  return retVal;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_IPDisplaySparePartNumber_IPDisplaSparePartNumber_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayTPVersionNumber_HUTDisplayTPVersionNumber_ReadData)  */
  Std_ReturnType  retVal;
  uint16 dataId = 0xFEF4;
retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data3ByteType));
  return retVal;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_HUTDisplayScreenType_HUTDisplayScreenType_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_IPDisplayHardwareVersionNumber_IPDisplayHardwareVersionNumber_ReadData)  */
  Std_ReturnType  retVal;
  uint16 dataId = 0xFEFF;
retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data5ByteType));
  return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_HUTDisplayTemperature_HUT_Display_LCD_Temperature_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_MACAddress_MACAddress_ReadData)  */
  Std_ReturnType  retVal;
  uint16 dataId = 0xF1EC;
retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data6ByteType));
  return retVal;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_MasterSlaveStatus_MasterSlaveStatus_WriteData)  */
    /*Std_ReturnType  retVal;
    uint16 dataId = 0xF1D7;
    retVal =  WriteQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data8ByteType));
    return retVal;*/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_MACAddress_MACAddress_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_MasterSlaveStatus_MasterSlaveStatus_WriteData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_MasterSlaveStatus_MasterSlaveStatus_ConditionCheckRead)  */



/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead)  */



/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_SwitchARLTable_SwitchARLTable_WriteData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_SwitchARLTable_SwitchARLTable_WriteData)  */
    /*Std_ReturnType  retVal;
    uint16 dataId = 0xF1D6;
    retVal =  WriteQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data28ByteType));
    return retVal;*/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_SwitchARLTable_SwitchARLTable_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_MACAddress_MACAddress_ReadData_doc)  **/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_MACAddress_MACAddress_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_MasterSlaveStatus_MasterSlaveStatus_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_MasterSlaveStatus_MasterSlaveStatus_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_MasterSlaveStatus_MasterSlaveStatus_ReadData)  */
   /* Std_ReturnType  retVal;
    uint16 dataId = 0xF1D7;

  retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data8ByteType));
    return retVal;*/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_SwitchARLTable_SwitchARLTable_ReadData)  */

    /*Std_ReturnType  retVal;
    uint16 dataId = 0xF1D6;
  retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data28ByteType));
    return retVal;*/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:DataServices_FactoryMode_FactoryMode_ReadData_doc)  ***/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_AVMLaneCalibrationResult_ReadData)  */
  Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xF234,OpStatus,Data,1);
  return retVal;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_AVMCameraConfigurationStatus_ReadData)  */
  Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xF231,OpStatus,Data,1);
  return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_FactoryMode_FactoryMode_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_AVMCalibrationCondition_ReadData_doc)  ***/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_AVMLaneCalibrationResult_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_AVMCalibrationCondition_ReadData)  **/
    Std_ReturnType retVal;
    retVal = ReadQnxDidDataRequestProcess(0xF232,OpStatus,Data,1);
    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_AVMCalibrationResult_ReadData)  *****/
  Std_ReturnType retVal;
  retVal = ReadQnxDidDataRequestProcess(0xF233,OpStatus,Data,1);
  return retVal;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_AVMCalibrationResult_ReadData_doc)  ******/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_FactoryMode_FactoryMode_WriteData)  */
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType vinNvmStatus = NVM_REQ_OK;
     Dcm_DataElement_FactoryMode_FactoryModeType locData = Data;
    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_GetErrorStatus(&vinNvmStatus);    
            if(NVM_REQ_PENDING != vinNvmStatus)
            {
              (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(),(uint8 *)&locData,sizeof(Dcm_Data1ByteType));
            } 
            (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_WriteBlock(NULL_PTR);

            ret  = RTE_E_DataServices_FactoryMode_FactoryMode_DCM_E_PENDING;
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_GetErrorStatus(&vinNvmStatus); 

            if(NVM_REQ_PENDING != vinNvmStatus)
            {
              if(NVM_REQ_OK != vinNvmStatus)
              {
                  memset((uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(),0,sizeof(Dcm_Data1ByteType));
                  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
              }
            } 
            else
            {
              ret  = DCM_E_PENDING;
            }
          break;
        default:
            break;

    }
    return (ret);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_AVMCameraConfigurationStatus_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_FactoryMode_FactoryMode_ReadData)  **/
    (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(),sizeof(Dcm_Data1ByteType));
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_AVMLaneCalibrationResult_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_FactoryMode_FactoryMode_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_FactoryMode_FactoryMode_WriteData_doc)  **/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_AVMLaneCalibrationResult_ReadData_doc)  **/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_MaintenanceOdometer_001_Start)  **/
    Std_ReturnType retValue = RTE_E_OK;
    uint32 value = In_MaintenanceOdometerControl;
    *Out_MaintenanceOdometerStatus = Rte_Call_cpCS_OdoSetParament_Operation(5,&value);
    if(FALSE == *Out_MaintenanceOdometerStatus)
    {
        *ErrorCode = DCM_E_GENERALREJECT;
        retValue = RTE_E_RoutineServices_MaintenanceOdometer_001_E_NOT_OK;
    }
      return (retValue);


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_MaintenanceOdometer_001_Stop_doc)  ****/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_MaintenanceOdometer_001_Stop)  ***/
  *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
  return RTE_E_RoutineServices_MaintenanceOdometer_001_E_NOT_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_MaintenanceOdometer_001_Start_doc)  ***/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_CS_ECUCsrHash_ReadDataLength)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_CS_ECUCertificateSerialNumber_ReadDataLength_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_CS_ECUCertificateSerialNumber_ReadDataLength)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_CS_ECUCsrHash_ReadDataLength_doc)  **/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_ODOReset_Start_doc)  ******************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_ODOReset_Start)  *****************/
    Std_ReturnType retValue = RTE_E_OK;
    *Out_ODOReset = Rte_Call_cpCS_OdoSetParament_Operation(1,NULL_PTR);
    if(FALSE == *Out_ODOReset)
    {
        *ErrorCode = DCM_E_GENERALREJECT;
        retValue =  RTE_E_RoutineServices_ODOReset_E_NOT_OK;
    }
    return (retValue);

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_SecOCKey_SecOCKey_WriteData)  *******/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_SecOCKey_SecOCKey_ReadData_doc)  *********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_SecOCKey_SecOCKey_ReadData)  ********/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_SecOCVersionNumber_SecOCVersionNumber_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_SecOcSwitch_ReadData_doc)  **********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_SecOcSwitch_WriteData_doc)  *********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_SecOcSwitch_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_SecOcSwitch_ReadData)  *********/
   

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_SecOCVersionNumber_SecOCVersionNumber_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_SecOCKey_SecOCKey_WriteData_doc)  ********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0

#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_SecOcSwitch_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_SecOCKey_SecOCKey_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_SecOCVersionNumber_SecOCVersionNumber_ReadData)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_SecOCVersionNumber_SecOCVersionNumber_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_SecOCKey_SecOCKey_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_IPDisplaySession_IPDisplaySession_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_IPDisplaySession_IPDisplaySession_ReadData)  */
  Std_ReturnType  retVal;
  uint16 dataId = 0xFEFA;

  retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data1ByteType));
  return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_CS_ECUCertificate_ReadDataLength_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_CS_ECUCertificate_ReadData)  ***/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_IPDisplaySession_IPDisplaySession_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_CS_ECUCertificate_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_IPDisplaySession_IPDisplaySession_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_CS_ECUCertificate_ReadDataLength)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_CS_ECUCertificate_ReadData_doc)  ****/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_CS_ECUCertificate_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_MasterSlaveStatus_MasterSlaveStatus_WriteData)  */
    Std_ReturnType  retVal = RTE_E_OK;
    uint16 dataId = 0xF1D7;
    retVal =  WriteQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data8ByteType));
    if(E_NOT_OK == retVal)
    {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_MasterSlaveStatus_MasterSlaveStatus_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_MasterSlaveStatus_MasterSlaveStatus_WriteData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_MasterSlaveStatus_MasterSlaveStatus_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_MasterSlaveStatus_MasterSlaveStatus_ReadData)  */
    Std_ReturnType retVal = RTE_E_OK;
    uint16 dataId = 0xF1D7;
    retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,Data,sizeof(Dcm_Data8ByteType));
    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_MasterSlaveStatus_MasterSlaveStatus_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_DID_0XFDA1_HUTConfiguration_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_DID_0XFDA1_HUTConfiguration_WriteData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:NvMNotifyJobFinished_NvBlockNeed_HUTInternalConfiguration_JobFinished)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_DID_0XFDA1_HUTConfiguration_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_DID_0XFDA1_HUTConfiguration_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:NvMNotifyJobFinished_NvBlockNeed_HUTInternalConfiguration_JobFinished_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_DID_0XFDA1_HUTConfiguration_ReadData)  */
  (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock(),sizeof(Dcm_Data4ByteType));

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_DID_0XFDA1_HUTConfiguration_WriteData)  */
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;

    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_HUTInternalConfiguration_GetErrorStatus(&nvmStatus);    
            if(NVM_REQ_PENDING != nvmStatus)
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock(),(uint8 *)Data,sizeof(Dcm_Data4ByteType));
            } 
            (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_HUTInternalConfiguration_WriteBlock(NULL_PTR);

            ret  = DCM_E_PENDING;
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_HUTInternalConfiguration_GetErrorStatus(&nvmStatus);  
        
            if(NVM_REQ_PENDING != nvmStatus)
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock(),0,sizeof(Dcm_Data4ByteType));
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret  = DCM_E_PENDING;
            }
            break;
        default:
            break;
    
    }
  return (ret);
    
/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_RightCameraParameters_Start)  ****/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
            RequestQnxRoutineControl(0xF023, ROUTINE_CONTROL_TYPE_START,tBuf,0);
            ret = DCM_E_FORCE_RCRRP;
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            ret = QnxResponseRoutineControl(tBuf,0);
            break;
        default:
            break;
    }
    if((ret != DCM_E_PENDING)&&(ret != DCM_E_FORCE_RCRRP))
    {
        ResetRoutineControlResponseId();
    }
    return (ret);


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_RearCameraParameters_Start)  *****/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
      case DCM_INITIAL:
          RequestQnxRoutineControl(0xF021, ROUTINE_CONTROL_TYPE_START,tBuf,0);
          ret = DCM_E_FORCE_RCRRP;
          break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(tBuf,0);
          break;
      default:
          break;
    }
    if((ret != DCM_E_PENDING)&&(ret != DCM_E_FORCE_RCRRP))
    {
      ResetRoutineControlResponseId();
    }
    return (ret);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_LeftCameraParameters_RequestResults)  */
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        RequestQnxRoutineControl(0xF022, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
        ret = DCM_E_FORCE_RCRRP;
        break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(Out_LeftCameraParametersResult,1);
        break;
    default:
        break;
    }
    if((ret != DCM_E_PENDING)&&(ret != DCM_E_FORCE_RCRRP))
    {
      ResetRoutineControlResponseId();
    }
    return (ret);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_RearCameraParameters_RequestResults_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_LeftCameraParameters_RequestResults_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_FrontCameraParameters_Start)  ****/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
      case DCM_INITIAL:
          RequestQnxRoutineControl(0xF020, ROUTINE_CONTROL_TYPE_START,tBuf,0);
          ret = DCM_E_FORCE_RCRRP;
          break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(tBuf,0);
          break;
      default:
          break;
    }
    if((ret != DCM_E_PENDING)&&(ret != DCM_E_FORCE_RCRRP))
    {
      ResetRoutineControlResponseId();
    }
    return (ret);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_RightCameraParameters_RequestResults_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_LeftCameraParameters_Start)  *****/
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
      case DCM_INITIAL:
          RequestQnxRoutineControl(0xF022, ROUTINE_CONTROL_TYPE_START,tBuf,0);
          ret = DCM_E_FORCE_RCRRP;
          break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(tBuf,0);
          break;
      default:
          break;
    }
    if((ret != DCM_E_PENDING)&&(ret != DCM_E_FORCE_RCRRP))
    {
      ResetRoutineControlResponseId();
    }
    return (ret);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_FrontCameraParameters_RequestResults)  */
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
      case DCM_INITIAL:
          RequestQnxRoutineControl(0xF020, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
          ret = DCM_E_FORCE_RCRRP;
          break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(Out_FrontCameraParametersResult,1);
          break;
      default:
          break;
    }
    if((ret != DCM_E_PENDING)&&(ret != DCM_E_FORCE_RCRRP))
    {
        ResetRoutineControlResponseId();
    }
    return (ret);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_RightCameraParameters_RequestResults)  */
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
          RequestQnxRoutineControl(0xF023, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
          ret = DCM_E_FORCE_RCRRP;
          break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
          ret = QnxResponseRoutineControl(Out_RightCameraParametersResult,1);
          break;
        default:
          break;
    }
    if((ret != DCM_E_PENDING)&&(ret != DCM_E_FORCE_RCRRP))
    {
    ResetRoutineControlResponseId();
    }
    return (ret);


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_RearCameraParameters_RequestResults)  */
    Std_ReturnType ret = RTE_E_OK;
    uint8 tBuf[2];
    switch(OpStatus)
    {
    case DCM_INITIAL:
        RequestQnxRoutineControl(0xF021, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
        ret = DCM_E_FORCE_RCRRP;
        break;
    case DCM_PENDING:
    case DCM_FORCE_RCRRP_OK:
        ret = QnxResponseRoutineControl(Out_RearCameraParametersResult,1);
        break;
    default:
        break;
    }
    if((ret != DCM_E_PENDING)&&(ret != DCM_E_FORCE_RCRRP))
    {
      ResetRoutineControlResponseId();
    }
    return (ret);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_FrontCameraParameters_Start_doc)  *****/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_LeftCameraParameters_Start_doc)  ******/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_FrontCameraParameters_RequestResults_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_RearCameraParameters_Start_doc)  ******/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_RightCameraParameters_Start_doc)  *****/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_TankResistanceValue_TankResistanceValue_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_TankResistanceValue_TankResistanceValue_ReadData)  */
  Rte_Call_ppCS_GetTankResistanceValue_Operation(Data);
  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_TankResistanceValue_TankResistanceValue_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_TankResistanceValue_TankResistanceValue_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_DHCPSwitch_ReadData_doc)  ***********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_ClusterDisplayLVDSsignalstandard_Display_Type_ReadData)  */

    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_LinkAutoIpSwitch_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_ClusterDisplayLVDSsignalstandard_Display_Type_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_LinkAutoIpSwitch_WriteData_doc)  ****/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_LinkAutoIpSwitch_WriteData)  ***/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DcmDataServices_ClusterDisplayLVDSsignalstandard_Display_Type_ConditionCheckRead)  */
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_DHCPSwitch_WriteData_doc)  **********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_LinkAutoIpSwitch_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_DHCPSwitch_ReadData)  **********/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_LinkAutoIpSwitch_ReadData)  ****/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_DHCPSwitch_WriteData)  *********/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_LinkAutoIpSwitch_ReadData_doc)  *****/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_DHCPSwitch_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_DHCPSwitch_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DcmDataServices_ClusterDisplayLVDSsignalstandard_Display_Type_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

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
