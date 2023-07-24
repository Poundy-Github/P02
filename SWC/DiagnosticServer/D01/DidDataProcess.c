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
 *           Config:  D:/code/VIP-D01/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  DidDataProcess
 *  Generation Time:  2022-01-26 15:12:26
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
 * Dcm_DidSupportedType
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
 * Dcm_ProtocolType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_RequestKindType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_SecLevelType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_SesCtrlType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 *********************************************************************************************************************/

#include "Rte_DidDataProcess.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "IPC_Diagnose.h"
#include "IPC_Misc.h"
#include "DcmEx.h"
#include "DcmEx_Type.h"
#include "ComEx_Cfg.h"
#include "Version.h"
#include "VConfig_Cfg.h"
#include "SecOC.h"

/*DCM general return code*/
#define DCM_E_OK                            ((Std_ReturnType)E_OK)       /*!< Successful operation */
#define DCM_E_NOT_OK                        ((Std_ReturnType)E_NOT_OK)   /*!< Failed operation with no specific reason (except when NRC is returned in addition) */
#define DCM_E_PENDING                       ((Std_ReturnType)10)         /*!< Invoked callout (operation) needs to be called again */
#define DCM_E_FORCE_RCRRP                   ((Std_ReturnType)12)         /*!< Invoked callout (operation) requests an immediate RCR-RP response transmission and needs to be called again once it is (successfully or not) sent */
#define ROUTINE_CONTROL_TYPE_START          (1u)  
#define ROUTINE_CONTROL_TYPE_STOP           (2u)
#define ROUTINE_CONTROL_TYPE_GERESULT       (3u)
#define WORK_MODE_MONITOR_PERIOD            (10u)  /*(10*10 = 100ms)*/
#define WRITE_SOC_DATA_MAX_TIME             (950u)
#define READ_SOC_DATA_MAX_TIME              (950u)

#define WORKING_FACTORY_MODE                (1u)

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
    ROUTINEIDINDEX_CE01,
    
    ROUTINEIDINDEX_INVAILD
}RoutineIdIndexMun_t;

static uint8 currentDiagnosticSession = 0;
static uint8 workModeMonitorCnt = 0;
static uint8 factorModeWriteE2EReq = FALSE;
static uint8 factorModeWriteSecOcReq = FALSE;
VconfigKind_Allbuffers diagVConfigDataBuf= {0};
static uint8  ridResetStartFlag[ROUTINEIDINDEX_INVAILD]= {0};
extern uint8 Get_OffSet_Flag;
uint8 OffSetData[8]= {0};

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
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dcm_DidSupportedType: Enumeration of integer in interval [0...1] with enumerators
 *   DCM_DID_SUPPORTED (0U)
 *   DCM_DID_NOT_SUPPORTED (1U)
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
 * Dcm_ProtocolType: Enumeration of integer in interval [0...254] with enumerators
 *   DCM_OBD_ON_CAN (0U)
 *   DCM_OBD_ON_FLEXRAY (1U)
 *   DCM_OBD_ON_IP (2U)
 *   DCM_UDS_ON_CAN (3U)
 *   DCM_UDS_ON_FLEXRAY (4U)
 *   DCM_UDS_ON_IP (5U)
 *   DCM_NO_ACTIVE_PROTOCOL (12U)
 *   DCM_SUPPLIER_1 (240U)
 *   DCM_SUPPLIER_2 (241U)
 *   DCM_SUPPLIER_3 (242U)
 *   DCM_SUPPLIER_4 (243U)
 *   DCM_SUPPLIER_5 (244U)
 *   DCM_SUPPLIER_6 (245U)
 *   DCM_SUPPLIER_7 (246U)
 *   DCM_SUPPLIER_8 (247U)
 *   DCM_SUPPLIER_9 (248U)
 *   DCM_SUPPLIER_10 (249U)
 *   DCM_SUPPLIER_11 (250U)
 *   DCM_SUPPLIER_12 (251U)
 *   DCM_SUPPLIER_13 (252U)
 *   DCM_SUPPLIER_14 (253U)
 *   DCM_SUPPLIER_15 (254U)
 * Dcm_RequestKindType: Enumeration of integer in interval [0...2] with enumerators
 *   DCM_REQ_KIND_NONE (0U)
 *   DCM_REQ_KIND_EXTERNAL (1U)
 *   DCM_REQ_KIND_ROE (2U)
 * Dcm_SecLevelType: Enumeration of integer in interval [0...49] with enumerators
 *   DCM_SEC_LEV_LOCKED (0U)
 *   DCM_SEC_LEV_L1 (1U)
 *   DCM_SEC_LEV_L49 (49U)
 * Dcm_SesCtrlType: Enumeration of integer in interval [0...111] with enumerators
 *   DCM_DEFAULT_SESSION (1U)
 *   DCM_EXTENDED_DIAGNOSTIC_SESSION (3U)
 *   DCM_EOLDiagnosticSession (96U)
 *   DCM_UFSKeepProgrammingSession (111U)
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
 *
 * Array Types:
 * ============
 * A_17Bytes: Array with 17 element(s) of type uint8
 * A_1Bytes: Array with 1 element(s) of type uint8
 * A_200Bytes: Array with 200 element(s) of type uint8
 * A_28Bytes: Array with 28 element(s) of type uint8
 * A_300Bytes: Array with 300 element(s) of type uint8
 * A_30Bytes: Array with 30 element(s) of type uint8
 * A_80Bytes: Array with 80 element(s) of type uint8
 * A_8Bytes: Array with 8 element(s) of type uint8
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * Dcm_Data200ByteType: Array with 200 element(s) of type uint8
 * Dcm_Data20ByteType: Array with 20 element(s) of type uint8
 * Dcm_Data300ByteType: Array with 300 element(s) of type uint8
 * Dcm_Data4000ByteType: Array with 4000 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * Diag_9Bytes: Array with 9 element(s) of type uint8
 * EOL_13Bytes: Array with 13 element(s) of type uint8
 * Rte_DT_s_OdoRteGetParament_t_2: Array with 3 element(s) of type uint32
 * Rte_DT_s_OdoRteGetParament_t_3: Array with 3 element(s) of type uint32
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 * VconfigKind_Allbuffers: Array with 600 element(s) of type uint8
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
 * s_SpeedoInfo_t: Record with elements
 *   OverSpdWrnFlg of type uint8
 *   VehRunSts of type uint8
 *   IndicateSpeed of type uint16
 *   RealSpeed of type uint16
 *   IndicateSpeedMile of type uint16
 *   RealSpeedMile of type uint16
 *   RealSpeedBak of type uint16
 *   Msg_missingSts of type uint8
 *   VehSpdVld of type uint8
 * s_TachoInfo_t: Record with elements
 *   EngRunSts of type uint8
 *   EngSpd of type uint16
 *   TimeOutFlag of type uint8
 *   EngSpdBak of type uint16
 *   Msg_missingSts of type uint8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_8Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_300Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_200Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data4ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_VIN_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_17Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data20ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_30Bytes
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_8Bytes
 *   uint8 *Rte_CData_NvBlockNeed_ClusterInternalConfiguration_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_300Bytes
 *   uint8 *Rte_CData_NvBlockNeed_E2ESwitch_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_200Bytes
 *   uint8 *Rte_CData_NvBlockNeed_FactoryMode_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_HUTInternalConfiguration_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data4ByteType
 *   uint8 *Rte_CData_NvBlockNeed_MasterSlaveStatus_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_8Bytes
 *   uint8 *Rte_CData_NvBlockNeed_SecOcSwitch_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_SwitchARLTable_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_28Bytes
 *   uint8 *Rte_CData_NvBlockNeed_VIN_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_17Bytes
 *   uint8 *Rte_CData_NvBlockNeed_VehicleMode_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data20ByteType
 *   uint8 *Rte_CData_NvBlockNeed_VehicleSoftwareVersion_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_30Bytes
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
    (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_VIN_MirrorBlock(), 17u);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeDiag1_IsDidAvailable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IsDidAvailable> of PortPrototype <DataServices_DIDRange_DidRangeDiag1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeDiag1_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_DidSupportedType *supported)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeDiag1_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeDiag1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag1_IsDidAvailable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag1_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) supported) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag1_IsDidAvailable (returns application error)
 *********************************************************************************************************************/

    return DcmEx_IsAvailableDid(DID, OpStatus, supported);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeDiag1_ReadDidData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDidData> of PortPrototype <DataServices_DIDRange_DidRangeDiag1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeDiag1_ReadDidData(uint16 DID, uint8 *Data, Dcm_OpStatusType OpStatus, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4000ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeDiag1_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeDiag1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag1_ReadDidData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag1_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag1_ReadDidData (returns application error)
 *********************************************************************************************************************/

    return DcmEx_DidRead(DID, Data, OpStatus, DataLength, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeDiag1_WriteDidData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteDidData> of PortPrototype <DataServices_DIDRange_DidRangeDiag1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeDiag1_WriteDidData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4000ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeDiag1_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeDiag1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag1_WriteDidData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag1_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag1_WriteDidData (returns application error)
 *********************************************************************************************************************/

    return DcmEx_DidWrite(DID, Data, OpStatus, DataLength, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeDiag2_IsDidAvailable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IsDidAvailable> of PortPrototype <DataServices_DIDRange_DidRangeDiag2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeDiag2_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_DidSupportedType *supported)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeDiag2_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeDiag2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag2_IsDidAvailable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag2_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) supported) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag2_IsDidAvailable (returns application error)
 *********************************************************************************************************************/

  return DcmEx_IsAvailableDid(DID, OpStatus, supported);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeDiag2_ReadDidData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDidData> of PortPrototype <DataServices_DIDRange_DidRangeDiag2>
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
 *   Std_ReturnType Rte_Call_cpCS_OdoSetParament_Operation(uint8 SetId, uint32 *data)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_OdoSetParament_Std_ReturnType
 *   Std_ReturnType Rte_Call_ppCS_GetTankResistanceValue_Operation(uint8 *TankResistanceValue)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_Fuel_Api_ParamentGetCsPort_Operation(uint8 *arg)
 *     Argument arg: uint8* is of type Diag_9Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(uint8 Id, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeDiag2_ReadDidData(uint16 DID, uint8 *Data, Dcm_OpStatusType OpStatus, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data300ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeDiag2_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeDiag2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag2_ReadDidData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag2_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag2_ReadDidData (returns application error)
 *********************************************************************************************************************/

    return DcmEx_DidRead(DID, Data, OpStatus, DataLength, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeDiag2_WriteDidData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteDidData> of PortPrototype <DataServices_DIDRange_DidRangeDiag2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeDiag2_WriteDidData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data300ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeDiag2_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeDiag2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag2_WriteDidData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag2_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeDiag2_WriteDidData (returns application error)
 *********************************************************************************************************************/

    return DcmEx_DidWrite(DID, Data, OpStatus, DataLength, ErrorCode);

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
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock(),(uint8 *)Data,sizeof(Dcm_Data20ByteType));
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
            break;

    }
    return (ret);

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
    DiagInit();
    factorModeWriteE2EReq = FALSE;
    factorModeWriteSecOcReq = FALSE;
    Rte_Read_Vconfig_GetKindBuffers_AllKinds(diagVConfigDataBuf);

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
 *   Std_ReturnType Rte_Read_VconfigResponseFlag_VconfigResponseFlag(uint8 *data)
 *   Std_ReturnType Rte_Read_Vconfig_GetKindBuffers_AllKinds(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_Allbuffers
 *   Std_ReturnType Rte_Read_ppSR_Diag_SpeedoInfo_Element(s_SpeedoInfo_t *data)
 *   Std_ReturnType Rte_Read_ppSR_Diag_TachoInfo_Element(s_TachoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag(uint8 *data)
 *   Std_ReturnType Rte_Read_rpSR_OdoParament_Element(s_OdoRteGetParament_t *data)
 *   Std_ReturnType Rte_Read_rpSR_Power_Out_DidProcess_SystemStateOut(SystemState_RecordType *data)
 *   Std_ReturnType Rte_Read_rpSR_Vconfig_KindBuffers_VconfigKind_157Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_157Bytes
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag(uint8 data)
 *   Std_ReturnType Rte_Write_ECUlevelNetworkConfigurationDataIdentifier_Element(const uint8 *data)
 *     Argument data: uint8* is of type Dcm_Data200ByteType
 *   Std_ReturnType Rte_Write_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag(uint8 data)
 *   Std_ReturnType Rte_Write_piSR_E2ESwitchChangeTrigger_Element(uint8 data)
 *   Std_ReturnType Rte_Write_piSR_SecOcSwitchChangeTrigger_Element(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(const uint8 *data)
 *     Argument data: uint8* is of type Dcm_Data300ByteType
 *   Std_ReturnType Rte_Write_ppSR_System_Recovery_System_Recovery(boolean data)
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
 *   Std_ReturnType Rte_Call_Can_Server_AbnormalWakeupSleepRecord_Get(uint8 *data)
 *     Argument data: uint8* is of type A_80Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IPCIviReportDtcStatus_IpcIviReportDtcSts(uint8 *data, uint8 length)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IPCSocReportDtcStatus_IpcSocReportDtcStatus(uint8 *Data, uint8 Length)
 *     Synchronous Server Invocation. Timeout: None
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
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DCMServices_GetActiveProtocol(Dcm_ProtocolType *ActiveProtocol)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *   Std_ReturnType Rte_Call_DCMServices_GetRequestKind(uint16 TesterSourceAddress, Dcm_RequestKindType *RequestKind)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_NOT_OK
 *   Std_ReturnType Rte_Call_DCMServices_GetSecurityLevel(Dcm_SecLevelType *SecLevel)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *   Std_ReturnType Rte_Call_DCMServices_GetSesCtrlType(Dcm_SesCtrlType *SesCtrlType)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *   Std_ReturnType Rte_Call_DCMServices_ResetToDefaultSession(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *   Std_ReturnType Rte_Call_DCMServices_SetActiveDiagnostic(boolean active)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
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
    uint8 clearFlag;
    Dcm_SecLevelType securityLevel = 0u;
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
    Rte_Call_DCMServices_GetSecurityLevel(&securityLevel);
    if(DCM_SEC_LEV_LOCKED == securityLevel)
    {
        for(clearFlag = ROUTINEIDINDEX_A1A1;clearFlag < ROUTINEIDINDEX_INVAILD;clearFlag++)
        {
            ridResetStartFlag[clearFlag] = FALSE;
        }
    }

    if(Get_OffSet_Flag == TRUE)
    {
        (void)memcpy((uint8 *)OffSetData,(uint8*)Rte_Pim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock(),sizeof(Dcm_Data8ByteType));
        can_warn("IPC M2S OffSetData: %X,%X,%X,%X,%X,%X,%X,%X", OffSetData[0],OffSetData[1],OffSetData[2],OffSetData[3],OffSetData[4],OffSetData[5],OffSetData[6],OffSetData[7]);
        (void)IPC_M2S_MiscServiceOffset_Transmit(OffSetData);
        Get_OffSet_Flag = (uint8)FALSE;
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
            factorModeWriteE2EReq = FALSE;
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
                factorModeWriteE2EReq = TRUE;
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
    if(0x02 != diagVConfigDataBuf[VCONFIG_KIND_ELECTROMOTOR_POSITION]) 
    {
        Version_GetCANMatrixVersion(data,19);
    }
    else if(0x02 == diagVConfigDataBuf[VCONFIG_KIND_ELECTROMOTOR_POSITION])
    {
        Version_GetCANMatrixVersion_2(data,19);
    }

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
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished
 *********************************************************************************************************************/


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
        if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
        if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
            if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
            if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
            if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
            if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
            if(0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
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
            if(0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
            {
                if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_F037])
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
    if((In_AVMManualConerMove > 0)&&(In_AVMManualConerMove < 5)&&( 0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION]))
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
        if(0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
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
    if((In_AVMManualConerSelect > 0)&&(In_AVMManualConerSelect < 0x0B)&&(0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION]))
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
            if(0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
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
            if(0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
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
            if(0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION])
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
    if((In_AVMManualViewSelect > 0)&&(In_AVMManualViewSelect < 5)&&(0x2 == diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION]))
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
 *   Std_ReturnType RoutineServices_ConfigureFrontCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, uint8 *DcmDspRoutineRequestResOutSignal, Dcm_NegativeResponseCodeType *ErrorCode)
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

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureFrontCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
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
        ret = QnxResponseRoutineControl(DcmDspRoutineRequestResOutSignal,1,ErrorCode);
        break;
    default:
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
        if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
 *   Std_ReturnType RoutineServices_ConfigureLeftCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, uint8 *DcmDspRoutineRequestResOutSignal, Dcm_NegativeResponseCodeType *ErrorCode)
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

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureLeftCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
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
        ret = QnxResponseRoutineControl(DcmDspRoutineRequestResOutSignal,1,ErrorCode);
        break;
    default:
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
        if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
 *   Std_ReturnType RoutineServices_ConfigureRearCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, uint8 *DcmDspRoutineRequestResOutSignal, Dcm_NegativeResponseCodeType *ErrorCode)
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

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRearCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
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
        ret = QnxResponseRoutineControl(DcmDspRoutineRequestResOutSignal,1,ErrorCode);
        break;
    default:
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
        if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
 *   Std_ReturnType RoutineServices_ConfigureRightCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, uint8 *DcmDspRoutineRequestResOutSignal, Dcm_NegativeResponseCodeType *ErrorCode)
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

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRightCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
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
        ret = QnxResponseRoutineControl(DcmDspRoutineRequestResOutSignal,1,ErrorCode);
        break;
    default:
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
        if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
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
        Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(4, &locResult);
        if(4 == locResult)
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
    uint8   KL15RetValue = 0xFF;
    uint8   KL15Data  = 0x00;

    KL15RetValue = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, &KL15Data, sizeof(KL15Data));

    if(((E_OK == KL15RetValue) || (COMEX_UPDATE_RECEIVED == KL15RetValue)) && (KL15Data == 2U))
    {
        Rte_Call_cpCS_OdoSetParament_Operation(1,NULL_PTR);
        ridResetStartFlag[ROUTINEIDINDEX_FD21] = TRUE;
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
 * Runnable Entity Name: RoutineServices_RequestCertificateStatus_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_RequestCertificateStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_RequestCertificateStatus_RequestResults(Dcm_OpStatusType OpStatus, uint8 *RequestCertificateStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_RequestCertificateStatus_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_RequestCertificateStatus_DCM_E_PENDING
 *   RTE_E_RoutineServices_RequestCertificateStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_RequestCertificateStatus_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_RequestCertificateStatus_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) RequestCertificateStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_RequestCertificateStatus_RequestResults (returns application error)
 *********************************************************************************************************************/
Std_ReturnType ret = RTE_E_OK;
  uint8 tBuf[2];
  switch(OpStatus)
  {
      case DCM_INITIAL:
          if(TRUE == ridResetStartFlag[ROUTINEIDINDEX_CE01])
          {
              RequestQnxRoutineControl(0xCE01, ROUTINE_CONTROL_TYPE_GERESULT,tBuf,0);
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
          ret = QnxResponseRoutineControl(RequestCertificateStatus,1,ErrorCode);
          break;
      default:
          break;
  }
  return (ret);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_RequestCertificateStatus_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_RequestCertificateStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_RequestCertificateStatus_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_RequestCertificateStatus_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_RequestCertificateStatus_DCM_E_PENDING
 *   RTE_E_RoutineServices_RequestCertificateStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_RequestCertificateStatus_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_RequestCertificateStatus_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_RequestCertificateStatus_Start (returns application error)
 *********************************************************************************************************************/
Std_ReturnType ret = RTE_E_OK;
uint8 tBuf[2];
    switch(OpStatus)
    {
        case DCM_INITIAL:
          if(diagVConfigDataBuf[VCONFIG_KIND_SALES_AREA] != 0)
          {
              RequestQnxRoutineControl(0xCE01, ROUTINE_CONTROL_TYPE_START,tBuf,0);
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
          ridResetStartFlag[ROUTINEIDINDEX_CE01] = TRUE;
      }
          break;
        default:
          break;
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
            if(0x3 == diagVConfigDataBuf[VCONFIG_KIND_HUT_ETHERNET_PORT])
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
  ridResetStartFlag[ROUTINEIDINDEX_FD20] = TRUE;
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
            factorModeWriteSecOcReq = FALSE;
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
                factorModeWriteSecOcReq = TRUE;
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
        retValue = ReadIVIDidDataFixLengthProcess(dataId, opStatus, data, length);
    }
    else
    {
        retValue = ReadQnxDidDataRequestProcess(dataId,opStatus, &ErrorCode);
        if(RTE_E_OK == retValue)
        {
            retValue = CopyQnxDidRspData(dataId, data, length);
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
    uint8 ipcResp;
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
void DidDataProcess_PreInit(void)
{
    Rte_Write_ECUlevelNetworkConfigurationDataIdentifier_Element(Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock());
    Rte_Write_tiSR_VIN_Element(Rte_Pim_NvBlockNeed_VIN_MirrorBlock());
    Rte_Write_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock());
    Rte_Write_piSR_E2ESwitchChangeTrigger_Element((uint8)(Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0]));  
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
/***  Start of saved code (symbol: runnable implementation:ServiceRequestNotification_Indication)  **********/

    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:ServiceRequestNotification_Confirmation)  ********/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:ServiceRequestNotification_Indication_doc)  ***********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:ServiceRequestNotification_Confirmation_doc)  *********/


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
