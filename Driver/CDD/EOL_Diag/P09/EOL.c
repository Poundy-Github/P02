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
 *             File:  EOL.c
 *           Config:  C:/projects/product/V35/P03/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  EOL
 *  Generation Time:  2021-06-03 19:53:16
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <EOL>
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

#include "Rte_EOL.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EOL_Diag.h"
#include "IoHwAb_Cfg_RI.h"
#include "Crc.h"
#include "Icu.h"
#include "CanIf.h"
#include "EcuM.h"
#include "logger.h"
#include "ComEx_Cfg.h"
#include "ComEx.h"
#include "DcmEx.h"

#define UFSKEEPPROGRAMMINGSTART                      ((uint16)1u)
#define UFSKEEPPROGRAMMINGSTOP                       ((uint16)2u)

#define EOL_CBK_CODE
#define EOL_CODE



#define UFSKEEPPROGRAMMINGMAXTIME                    ((uint16)50u)
#define WRITE_SECURITYDATA_TIMEMONITOR               ((uint16)500u)
#define EOL_SetUFSKeepProgramming_Flag(value)         ((UFSKeepProgrammingRecord[0].UFSKeepProgrammingFlag) = ((boolean)(value)))
#define EOL_GetUFSKeepProgramming_Flag()              (UFSKeepProgrammingRecord[0].UFSKeepProgrammingFlag)
#define EOL_SetUFSKeepProgramming_Timer(value)        ((UFSKeepProgrammingRecord[0].UFSKeepProgrammingTimer) = ((uint16)(value)))
#define EOL_GetUFSKeepProgramming_Timer()             (UFSKeepProgrammingRecord[0].UFSKeepProgrammingTimer)
#define EOL_GetEnterEOL_Flag()                        (EnterEOLRecord[0].EnterEOLFlag)
#define EOL_SetEnterEOL_Flag(value)                   ((EnterEOLRecord[0].EnterEOLFlag) = ((boolean)(value)))
#define EOL_GetExitEOL_Flag()                        (EnterEOLRecord[0].ExitEOLFlag)
#define EOL_SetExitEOL_Flag(value)                   ((EnterEOLRecord[0].ExitEOLFlag) = ((boolean)(value)))

typedef struct UFSKeepProgramming_Tag
{
    uint16  UFSKeepProgrammingTimer;
    boolean UFSKeepProgrammingFlag;
}UFSKeepProgrammingInfo;

typedef struct EnterEOLInfo_Tag
{
    boolean EnterEOLFlag;
    boolean ExitEOLFlag;
}EnterEOLInfo;

typedef struct Service31NRCInfo_Tag
{
    boolean AMPCalibration_StartFlag;
    boolean AVMRegister_StartFlag;
    boolean CheckEthernetIPPINGFunction_StartFlag;
    boolean IVITouchTest_StartFlag;
}Service31NRCInfo;

typedef struct WriteSecurityDataTimeHandleInfo_Tag
{
    uint16  timeoutTime;
    boolean timeMonitorFlag;
    boolean timeoutFlag;
}WriteSecurityDataTimeHandleInfo;

static UFSKeepProgrammingInfo UFSKeepProgrammingRecord[1] = {UFSKEEPPROGRAMMINGMAXTIME, FALSE};
static EnterEOLInfo EnterEOLRecord[1] = {FALSE, FALSE};
static Service31NRCInfo Service31NRCRecord[1] = {FALSE, FALSE, FALSE, FALSE};
static WriteSecurityDataTimeHandleInfo WriteSecurityDataTimeHandleRecord[1] = {0x00, FALSE, FALSE};

static FUNC(void, EOL_CODE) EOL_UFSKeepProgrammingTimeHandler(void);
static FUNC(void, EOL_CODE) EOL_UFSKeepJudgmentHandler(void);
static FUNC(void, EOL_CODE) EOL_EnterEOLHandler(void);

static FUNC(void, EOL_CODE) EOL_Service31NRCHandler(void);
static FUNC(boolean , EOL_CODE) EOL_WriteSecurityDataPreFunction(P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) Data, uint16 DataLength);
static FUNC(void, EOL_CODE) EOL_WriteSecurityDataTimeMonitorHandler(void);
static FUNC(void , EOL_CODE) EOL_WriteSecurityDataInit(void);
static FUNC(void , EOL_CODE) EOL_Icu_Can3RxWakeupHandler(void);

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetPin(uint8 Id, P2VAR(boolean, AUTOMATIC, RTE_VAR_NOINIT) Pin);
FUNC(void, EOL_CODE) EOL_PreInit(void);
extern uint16 AMP_ChCfgSts(void);


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
 * A_17Bytes: Array with 17 element(s) of type uint8
 * A_1Bytes: Array with 1 element(s) of type uint8
 * A_20Bytes: Array with 20 element(s) of type uint8
 * A_U8_10: Array with 10 element(s) of type uint8
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * Dcm_Data10ByteType: Array with 10 element(s) of type uint8
 * Dcm_Data20ByteType: Array with 20 element(s) of type uint8
 * Dcm_Data4000ByteType: Array with 4000 element(s) of type uint8
 * EOL13Bytes: Array with 13 element(s) of type uint8
 * EOL3Bytes: Array with 3 element(s) of type uint8
 * EOL4Bytes: Array with 4 element(s) of type uint8
 * EOL9Bytes: Array with 9 element(s) of type uint8
 * EOL_13Bytes: Array with 13 element(s) of type uint8
 * EOL_15Bytes: Array with 15 element(s) of type uint8
 * EOL_2Bytes: Array with 2 element(s) of type Rte_DT_EOL_2Bytes_0
 * EOL_3Bytes: Array with 3 element(s) of type Rte_DT_EOL_3Bytes_0
 * EOL_4Bytes: Array with 4 element(s) of type Rte_DT_EOL_4Bytes_0
 * EOL_64Bytes: Array with 64 element(s) of type Rte_DT_EOL_64Bytes_0
 * EOL_6Bytes: Array with 6 element(s) of type Rte_DT_EOL_6Bytes_0
 * RW_0xFD00: Array with 4 element(s) of type Rte_DT_RW_0xFD00_0
 * Rte_DT_EOL_2Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_EOL_3Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_EOL_4Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_EOL_64Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_EOL_6Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_RW_0xFD00_0: Array with 1 element(s) of type uint8
 *
 * Record Types:
 * =============
 * EOL_Struct_3Element: Record with elements
 *   MCUTemperature of type uint8
 *   AMP1Temperature of type uint8
 *   AMP2Temperature of type uint8
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
 *   uint8 *Rte_Pim_NvBlockNeed_0xF187_MirrorBlock(void)
 *     Returnvalue: uint8* is of type EOL_13Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xF18C_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_20Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xF193_MirrorBlock(void)
 *     Returnvalue: uint8* is of type EOL_15Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xF195_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_17Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xFD00_MirrorBlock(void)
 *     Returnvalue: uint8* is of type RW_0xFD00
 *   uint8 *Rte_Pim_NvBlockNeed_0xFD19_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xFE20_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xFE21_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xFE22_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xFE23_MirrorBlock(void)
 *     Returnvalue: uint8* is of type EOL_2Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xFE24_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_Pim_NvBlockNeed_0xFE25_MirrorBlock(void)
 *     Returnvalue: uint8* is of type EOL_2Bytes
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_NvBlockNeed_0xF187_DefaultValue(void)
 *     Returnvalue: uint8* is of type EOL_13Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xF18C_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_20Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xF193_DefaultValue(void)
 *     Returnvalue: uint8* is of type EOL_15Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xF195_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_17Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xFD00_DefaultValue(void)
 *     Returnvalue: uint8* is of type RW_0xFD00
 *   uint8 *Rte_CData_NvBlockNeed_0xFD19_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xFDD9_DefaultValue(void)
 *     Returnvalue: uint8* is of type EOL_2Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xFE20_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xFE21_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xFE22_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xFE23_DefaultValue(void)
 *     Returnvalue: uint8* is of type EOL_2Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xFE24_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *   uint8 *Rte_CData_NvBlockNeed_0xFE25_DefaultValue(void)
 *     Returnvalue: uint8* is of type EOL_2Bytes
 *   uint8 *Rte_CData_NvBlockNeed_EOLUIN_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_20Bytes
 *   uint8 *Rte_CData_NvBlockNeed_EnterEOLSession_DefaultValue(void)
 *     Returnvalue: uint8* is of type EOL4Bytes
 *   uint8 *Rte_CData_NvBlockNeed_UIN_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_20Bytes
 *
 *********************************************************************************************************************/


#define EOL_START_SEC_CODE
#include "EOL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeEol1_IsDidAvailable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IsDidAvailable> of PortPrototype <DataServices_DIDRange_DidRangeEol1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeEol1_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_DidSupportedType *supported)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeEol1_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeEol1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeEol1_IsDidAvailable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) DataServices_DIDRange_DidRangeEol1_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_EOL_APPL_VAR) supported) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeEol1_IsDidAvailable (returns application error)
 *********************************************************************************************************************/

    return DcmEx_IsAvailableDid(DID, OpStatus, supported);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeEol1_ReadDidData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDidData> of PortPrototype <DataServices_DIDRange_DidRangeEol1>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EOL_BatteryVoltage_0xFD10_SystemStateOut(SystemState_RecordType *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_6Bytes
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeEol1_ReadDidData(uint16 DID, uint8 *Data, Dcm_OpStatusType OpStatus, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4000ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeEol1_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeEol1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeEol1_ReadDidData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) DataServices_DIDRange_DidRangeEol1_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_EOL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeEol1_ReadDidData (returns application error)
 *********************************************************************************************************************/

    return DcmEx_DidRead(DID, Data, OpStatus, DataLength, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DIDRange_DidRangeEol1_WriteDidData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteDidData> of PortPrototype <DataServices_DIDRange_DidRangeEol1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DIDRange_DidRangeEol1_WriteDidData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4000ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DIDRange_DidRangeEol1_DCM_E_PENDING
 *   RTE_E_DataServices_DIDRange_DidRangeEol1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeEol1_WriteDidData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) DataServices_DIDRange_DidRangeEol1_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DIDRange_DidRangeEol1_WriteDidData (returns application error)
 *********************************************************************************************************************/

    return DcmEx_DidWrite(DID, Data, OpStatus, DataLength, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_Init
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
 *   Std_ReturnType Rte_Read_EOL_AMPCalibrationRece_EOLReceive(uint8 *data)
 *     Argument data: uint8* is of type A_U8_10
 *   Std_ReturnType Rte_Read_EOL_BatteryVoltage_0xFD10_SystemStateOut(SystemState_RecordType *data)
 *   Std_ReturnType Rte_Read_EOL_KL15Status_0xFD15_SystemStateOut(SystemState_RecordType *data)
 *   Std_ReturnType Rte_Read_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(uint8 *data)
 *     Argument data: uint8* is of type EOL3Bytes
 *   Std_ReturnType Rte_Read_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(uint8 *data)
 *     Argument data: uint8* is of type EOL9Bytes
 *   Std_ReturnType Rte_Read_EOL_ReadGPSSatelliteCount_GPSSatelliteCount(uint8 *data)
 *   Std_ReturnType Rte_Read_rpSR_SocManager_SocFactoryResetState_SocFactoryResetReady(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_EOL_AMPCalibration_AMPCalibration(uint16 data)
 *   Std_ReturnType Rte_Write_EOL_KeepDownload_keepDownloadRID(uint16 data)
 *   Std_ReturnType Rte_Write_EOL_PartNumber_0xF187_PartNumber_0xF187(const uint8 *data)
 *     Argument data: uint8* is of type EOL13Bytes
 *   Std_ReturnType Rte_Write_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(const uint8 *data)
 *     Argument data: uint8* is of type EOL_15Bytes
 *   Std_ReturnType Rte_Write_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(const uint8 *data)
 *     Argument data: uint8* is of type A_20Bytes
 *   Std_ReturnType Rte_Write_EOL_SRpVehSparePartNumber_SparePartNumber(const uint8 *data)
 *     Argument data: uint8* is of type EOL_13Bytes
 *   Std_ReturnType Rte_Write_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(const uint8 *data)
 *     Argument data: uint8* is of type EOL4Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) EOL_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_Init
 *********************************************************************************************************************/
    EOL_SetUFSKeepProgramming_Flag(FALSE);
    EOL_SetEnterEOL_Flag(FALSE);
    EOL_SetExitEOL_Flag(FALSE);
    EOL_Service31NRCHandler();
    EOL_WriteSecurityDataInit();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_SocManager_SocFactoryResetState_SocFactoryResetReady(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_EOL_KeepDownload_keepDownloadRID(uint16 data)
 *   Std_ReturnType Rte_Write_EOL_SRpVehSparePartNumber_SparePartNumber(const uint8 *data)
 *     Argument data: uint8* is of type EOL_13Bytes
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_DcmControlDtcSetting_DcmControlDtcSetting(void)
 *   Modes of Rte_ModeType_DcmControlDtcSetting:
 *   - RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING
 *   - RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING
 *   - RTE_TRANSITION_DcmControlDtcSetting
 *   uint8 Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void)
 *   Modes of Rte_ModeType_DcmDiagnosticSessionControl:
 *   - RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession
 *   - RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_UFSKeepProgrammingSession
 *   - RTE_TRANSITION_DcmDiagnosticSessionControl
 *   uint8 Rte_Mode_DcmEcuReset_DcmEcuReset(void)
 *   Modes of Rte_ModeType_DcmEcuReset:
 *   - RTE_MODE_DcmEcuReset_EXECUTE
 *   - RTE_MODE_DcmEcuReset_HARD
 *   - RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_KEYONOFF
 *   - RTE_MODE_DcmEcuReset_NONE
 *   - RTE_MODE_DcmEcuReset_SOFT
 *   - RTE_TRANSITION_DcmEcuReset
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_AMP_EOL_Read_Operation(uint8 *value)
 *     Argument value: uint8* is of type A_U8_10
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AMP_EOL_Read_N_OK
 *   Std_ReturnType Rte_Call_EOL_0xFD16_EOL_FactoryReset(uint8 *arg)
 *     Argument arg: uint8* is of type A_1Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17(EOL_Struct_3Element *arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_EOL_0xFDD1_EOL_ReadMICStatus(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_3Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_EOL_0xFDD9_EOL_WriteValueForDispalyEnable(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_2Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_EOL_0xFDE1_EOL_ReadWatchDogCnt(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_4Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_EOL_0xFDE2_EOL_ReadResetInformation(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_64Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_EOL_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_EOL_ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, uint8 *SignalDataPtr, uint8 Length)
 *     Argument SignalDataPtr: uint8* is of type ComEx_SignalDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED, RTE_E_ComEx_COMEX_NEVER_RECEIVED, RTE_E_ComEx_COMEX_UPDATE_RECEIVED, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_EOL_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_4Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetKindConfig_Std_ReturnType
 *   Std_ReturnType Rte_Call_ppCS_Diag_ReadDidData_Operation(uint16 dataId, uint8 opStatus, uint8 *data, uint16 length)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_piCS_Diag_ReadDidData_DCM_E_PENDING, RTE_E_piCS_Diag_ReadDidData_E_NOT_OK
 *   Std_ReturnType Rte_Call_ppCS_Diag_WriteDidData_Operation(uint16 dataId, uint8 opStatus, uint8 *data, uint16 length, uint8 *errorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_piCS_Diag_WriteDidData_DCM_E_PENDING, RTE_E_piCS_Diag_WriteDidData_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_EOL_Odo_Api_ParamentGetCsPort_Operation(uint8 Id, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
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
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF187_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF187_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF187_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF187_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF18C_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF18C_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF18C_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF18C_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF193_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF193_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF193_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF193_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF195_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF195_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF195_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xF195_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFD00_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFD00_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFD00_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFD00_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFD19_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFD19_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFD19_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFD19_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE20_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE20_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE20_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE20_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE21_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE21_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE21_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE21_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE22_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE22_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE22_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE22_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE23_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE23_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE23_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE23_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE24_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE24_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE24_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE24_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE25_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE25_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE25_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_0xFE25_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) EOL_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_MainFunction
 *********************************************************************************************************************/
    EOL_DiagTransferHandler();
    EOL_UFSKeepJudgmentHandler();
    EOL_EnterEOLHandler();
    EOL_Service31NRCHandler();
    EOL_WriteSecurityDataTimeMonitorHandler();
    EOL_Icu_Can3RxWakeupHandler();
    EOL_MutiPackageSendHandler();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xF187_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xF187>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xF187_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xF187_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xF187_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xF187_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xF18C_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xF18C>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xF18C_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xF18C_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xF18C_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xF18C_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xF193_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xF193>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xF193_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xF193_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xF193_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xF193_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xF195_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xF195>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xF195_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xF195_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xF195_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xF195_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xFD00_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xFD00>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xFD00_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFD00_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFD00_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFD00_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xFD19_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xFD19>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xFD19_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFD19_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFD19_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFD19_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xFE20_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xFE20>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xFE20_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE20_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE20_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE20_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xFE21_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xFE21>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xFE21_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE21_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE21_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE21_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xFE22_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xFE22>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xFE22_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE22_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE22_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE22_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xFE23_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xFE23>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xFE23_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE23_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE23_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE23_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xFE24_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xFE24>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xFE24_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE24_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE24_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE24_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_0xFE25_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_0xFE25>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_0xFE25_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE25_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE25_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_0xFE25_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AMPCalibration_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AMPCalibration>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EOL_AMPCalibrationRece_EOLReceive(uint8 *data)
 *     Argument data: uint8* is of type A_U8_10
 *   Std_ReturnType Rte_Read_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(uint8 *data)
 *     Argument data: uint8* is of type EOL9Bytes
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_EOL_AMPCalibration_AMPCalibration(uint16 data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AMPCalibration_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_AmpValue, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Out_AmpValue: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AMPCalibration_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AMPCalibration_DCM_E_PENDING
 *   RTE_E_RoutineServices_AMPCalibration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AMPCalibration_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AMPCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AmpValue, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AMPCalibration_RequestResults (returns application error)
 *********************************************************************************************************************/
  uint8 index = 0x00;
  uint8 AMPCalVal[10] = {0x00};
  Std_ReturnType retAMP = RTE_E_INVALID;
  Std_ReturnType ret = RTE_E_RoutineServices_AMPCalibration_DCM_E_PENDING;
  
  Rte_Write_EOL_AMPCalibration_AMPCalibration(0x02);
  retAMP = Rte_Call_AMP_EOL_Read_Operation(AMPCalVal);

  if(( RTE_E_OK == retAMP) && (Service31NRCRecord[0].AMPCalibration_StartFlag == TRUE))
  {
      while(index < 0x0A)
      {
        Out_AmpValue[index] = AMPCalVal[index];
        index++;
      }
      ret = RTE_E_OK;
  }
  else if(Service31NRCRecord[0].AMPCalibration_StartFlag == FALSE)
  {
    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    ret = RTE_E_INVALID;
  }

  return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AMPCalibration_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AMPCalibration>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_EOL_AMPCalibration_AMPCalibration(uint16 data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AMPCalibration_Start(Dcm_OpStatusType OpStatus, uint8 *Out_RoutineStatusRecord, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AMPCalibration_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AMPCalibration_DCM_E_PENDING
 *   RTE_E_RoutineServices_AMPCalibration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AMPCalibration_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AMPCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_RoutineStatusRecord, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AMPCalibration_Start (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retAMP = RTE_E_INVALID;
  Std_ReturnType ret = RTE_E_RoutineServices_AMPCalibration_DCM_E_PENDING;
  uint16 AMPChnSts = 0u;

  AMPChnSts = AMP_ChCfgSts();
  
  if(0u == AMPChnSts)
  {
        *Out_RoutineStatusRecord = 0x00;
        return RTE_E_OK;
  }
  else
  {
        retAMP = Rte_Write_EOL_AMPCalibration_AMPCalibration(0x01);
        Service31NRCRecord[0].AMPCalibration_StartFlag = (boolean)TRUE;

        if( RTE_E_OK == retAMP)
        {
            /* Routine started successfully*/
            *Out_RoutineStatusRecord = 0x01;
            return RTE_E_OK;
        }
  }

  return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMRegister_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_AVMRegister>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMRegister_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_AVMRegister, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMRegister_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMRegister_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMRegister_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMRegister_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AVMRegister_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AVMRegister, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMRegister_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_RoutineServices_AVMRegister_DCM_E_PENDING;

    if(Service31NRCRecord[0].AVMRegister_StartFlag == TRUE)
    {
        ret = EOL_DiagTransferRoutineControlHandle_0x31(0x0402, Out_AVMRegister, 0x01, 0x03, IPC_M2S_EOL_MSGMAJOR_IVI_ID,ErrorCode);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        ret = RTE_E_INVALID;
    }
    
    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_AVMRegister_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_AVMRegister>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_AVMRegister_Start(Dcm_OpStatusType OpStatus, uint8 *Out_AVMRegister, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_AVMRegister_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_AVMRegister_DCM_E_PENDING
 *   RTE_E_RoutineServices_AVMRegister_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMRegister_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AVMRegister_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AVMRegister, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_AVMRegister_Start (returns application error)
 *********************************************************************************************************************/
  Service31NRCRecord[0].AVMRegister_StartFlag = TRUE;

  return EOL_DiagTransferRoutineControlHandle_0x31(0x0402, Out_AVMRegister, 0x01, 0x01, IPC_M2S_EOL_MSGMAJOR_IVI_ID,ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_CheckEthernetIPPINGFunction_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_CheckEthernetIPPINGFunction>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_CheckEthernetIPPINGFunction_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_0xF003, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_PENDING
 *   RTE_E_RoutineServices_CheckEthernetIPPINGFunction_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_CheckEthernetIPPINGFunction_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) RoutineServices_CheckEthernetIPPINGFunction_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF003, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_CheckEthernetIPPINGFunction_RequestResults (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_PENDING;

    if(Service31NRCRecord[0].CheckEthernetIPPINGFunction_StartFlag == TRUE)
    {
        ret = EOL_DiagTransferRoutineControlHandle_0x31(0x0400, Out_0xF003, 0x01, 0x03, IPC_M2S_EOL_MSGMAJOR_IVI_ID,ErrorCode);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        ret = RTE_E_INVALID;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_CheckEthernetIPPINGFunction_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_CheckEthernetIPPINGFunction>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_CheckEthernetIPPINGFunction_Start(uint32 In_Start, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_PENDING
 *   RTE_E_RoutineServices_CheckEthernetIPPINGFunction_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_CheckEthernetIPPINGFunction_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) RoutineServices_CheckEthernetIPPINGFunction_Start(uint32 In_Start, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_CheckEthernetIPPINGFunction_Start (returns application error)
 *********************************************************************************************************************/
  uint8 sendData[4] = {0};

  Service31NRCRecord[0].CheckEthernetIPPINGFunction_StartFlag = TRUE;

  sendData[0] = (uint8)(In_Start >> 24);
  sendData[1] = (uint8)(In_Start >> 16);
  sendData[2] = (uint8)(In_Start >> 8);
  sendData[3] = (uint8)(In_Start);
  
  return EOL_DiagTransferRoutineControlHandle_0x31(0x0400, sendData, 0x04, 0x01, IPC_M2S_EOL_MSGMAJOR_IVI_ID,ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_IVITouchTest_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_IVITouchTest>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_IVITouchTest_RequestResults(Dcm_OpStatusType OpStatus, uint8 *Out_0xF004, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Out_0xF004: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_IVITouchTest_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_IVITouchTest_DCM_E_PENDING
 *   RTE_E_RoutineServices_IVITouchTest_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_IVITouchTest_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) RoutineServices_IVITouchTest_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF004, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_IVITouchTest_RequestResults (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = RTE_E_RoutineServices_IVITouchTest_DCM_E_PENDING;

    if(Service31NRCRecord[0].IVITouchTest_StartFlag == TRUE)
    {
        ret = EOL_DiagTransferRoutineControlHandle_0x31(0x0401, Out_0xF004, 0x14, 0x03, IPC_M2S_EOL_MSGMAJOR_IVI_ID,ErrorCode);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        ret = RTE_E_INVALID;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_IVITouchTest_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_IVITouchTest>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_IVITouchTest_Start(Dcm_OpStatusType OpStatus, uint8 *Out_0xF004, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_IVITouchTest_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_IVITouchTest_DCM_E_PENDING
 *   RTE_E_RoutineServices_IVITouchTest_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_IVITouchTest_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EOL_CODE) RoutineServices_IVITouchTest_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF004, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_IVITouchTest_Start (returns application error)
 *********************************************************************************************************************/
  Service31NRCRecord[0].IVITouchTest_StartFlag = TRUE;

  return EOL_DiagTransferRoutineControlHandle_0x31(0x0401, Out_0xF004, 0x4, 0x01, IPC_M2S_EOL_MSGMAJOR_IVI_ID,ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define EOL_STOP_SEC_CODE
#include "EOL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
static FUNC(void, EOL_CODE) EOL_UFSKeepProgrammingTimeHandler(void)
{
    if (EOL_GetUFSKeepProgramming_Flag())
    {
        if( EOL_GetUFSKeepProgramming_Timer() > 0)
        {
            EOL_GetUFSKeepProgramming_Timer()--;
            if( 0 == EOL_GetUFSKeepProgramming_Timer())
            {
                Rte_Write_EOL_KeepDownload_keepDownloadRID(UFSKEEPPROGRAMMINGSTOP);
                EOL_SetUFSKeepProgramming_Flag(FALSE);
            }
        }
    }
    else
    {
        Rte_Write_EOL_KeepDownload_keepDownloadRID(UFSKEEPPROGRAMMINGSTOP);
        EOL_SetUFSKeepProgramming_Flag(FALSE);
    }
}

static FUNC(void, EOL_CODE) EOL_UFSKeepJudgmentHandler(void)
{
    uint8 SessionMode;
    uint8 ResetType;
    
    SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
    ResetType = Rte_Mode_DcmEcuReset_DcmEcuReset();
    
    if(RTE_MODE_DcmDiagnosticSessionControl_UFSKeepProgrammingSession == SessionMode)
    {
        uint8 ControllerMode;
    
        ControllerMode = Rte_Mode_DcmControlDtcSetting_DcmControlDtcSetting();
        
        if (RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING == ControllerMode)
        {
            if(FALSE == EOL_GetUFSKeepProgramming_Flag())
            {
                EOL_SetUFSKeepProgramming_Flag(TRUE);
                Rte_Write_EOL_KeepDownload_keepDownloadRID(UFSKEEPPROGRAMMINGSTART);
            }
            else
            {
                
            }
        }
        else if((RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING == ControllerMode) 
            && (TRUE == EOL_GetUFSKeepProgramming_Flag()))
        {
            EOL_SetUFSKeepProgramming_Flag(FALSE);
            Rte_Write_EOL_KeepDownload_keepDownloadRID(UFSKEEPPROGRAMMINGSTOP);
        }
        else
        {
            
        }
    }
    else
    {
        if(TRUE == EOL_GetUFSKeepProgramming_Flag())
        {
            EOL_SetUFSKeepProgramming_Flag(FALSE);
            Rte_Write_EOL_KeepDownload_keepDownloadRID(UFSKEEPPROGRAMMINGSTOP);
        }
    }
}

static FUNC(void, EOL_CODE) EOL_EnterEOLHandler(void)
{
    uint8 SessionMode;
    uint8 ResetType;
    
    SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
    ResetType = Rte_Mode_DcmEcuReset_DcmEcuReset();

    /* Notice QNX / IVI to implement job*/
    if((RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession == SessionMode) && 
        (FALSE == EOL_GetEnterEOL_Flag()))
    {
        EOL_SetEnterEOL_Flag(TRUE);
        EOL_DiagTransferSessionControl_TransmitQNX_0x10(SessionMode);
        EOL_DiagTransferSessionControl_TransmitIVI_0x10(SessionMode);
    }
    else
    {
        if ((TRUE == EOL_GetEnterEOL_Flag()) && (RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession != SessionMode))
        {
            EOL_SetEnterEOL_Flag(FALSE);
            EOL_DiagTransferSessionControl_TransmitQNX_0x10(SessionMode);
            EOL_DiagTransferSessionControl_TransmitIVI_0x10(SessionMode);
        }
    }
}

FUNC(void, EOL_CODE) EOL_PreInit(void) 
{
    uint8 VIPSoftwareVersion[4] = {0};
    Version_GetSoftwareVersionVIP(VIPSoftwareVersion,4);

    Rte_Write_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(VIPSoftwareVersion);
    Rte_Write_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(RtePim_NvBlockNeed_0xF193_MirrorBlock());
    Rte_Write_EOL_PartNumber_0xF187_PartNumber_0xF187(RtePim_NvBlockNeed_0xF187_MirrorBlock());
    Rte_Write_EOL_SRpVehSparePartNumber_SparePartNumber(RtePim_NvBlockNeed_0xF187_MirrorBlock());
    Rte_Write_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(RtePim_NvBlockNeed_0xF18C_MirrorBlock());
}

/******************************************************************************/
/**
* @brief               <EOL_Service31NRCHandler>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <status>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static FUNC(void, EOL_CODE) EOL_Service31NRCHandler(void)
{
    uint8 SessionMode;
    
    SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();

    if(RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession != SessionMode) 
    {
        Service31NRCRecord[0].IVITouchTest_StartFlag = FALSE;
        Service31NRCRecord[0].AMPCalibration_StartFlag = FALSE;
        Service31NRCRecord[0].AVMRegister_StartFlag = FALSE;
        Service31NRCRecord[0].CheckEthernetIPPINGFunction_StartFlag = FALSE;
    }
}

/******************************************************************************/
/**
* @brief               <EOL_WriteSecurityDataHandler>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <status>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static FUNC(void, EOL_CODE) EOL_WriteSecurityDataTimeMonitorHandler(void)
{
    
      if((WriteSecurityDataTimeHandleRecord[0].timeMonitorFlag == TRUE) && 
        (WriteSecurityDataTimeHandleRecord[0].timeoutTime > 0))
    {
        WriteSecurityDataTimeHandleRecord[0].timeoutTime--;
        if(WriteSecurityDataTimeHandleRecord[0].timeoutTime == 0)
        {
            WriteSecurityDataTimeHandleRecord[0].timeoutFlag = TRUE;
        }
    }
}

/******************************************************************************/
/**
* @brief               <EOL_WriteSecurityDataPreFunction>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <status>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static FUNC(boolean , EOL_CODE) EOL_WriteSecurityDataPreFunction(P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) Data, uint16 DataLength)
{
    if((Data[0] == Data[1]) && (Data[1] == 0x01))
    {
        WriteSecurityDataTimeHandleRecord[0].timeMonitorFlag = FALSE;
    }
    else if((Data[0] != Data[1]) && (Data[1] == 0x01))
    {
        WriteSecurityDataTimeHandleRecord[0].timeMonitorFlag = TRUE;
    }
    else if((Data[0] == Data[1]) && (Data[1] != 0x01))
    {
        WriteSecurityDataTimeHandleRecord[0].timeMonitorFlag = FALSE;
    }

    return (WriteSecurityDataTimeHandleRecord[0].timeMonitorFlag);
}

/******************************************************************************/
/**
* @brief               <EOL_WriteSecurityDataInit>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <status>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static FUNC(void , EOL_CODE) EOL_WriteSecurityDataInit(void)
{
    WriteSecurityDataTimeHandleRecord[0].timeMonitorFlag = FALSE;
    WriteSecurityDataTimeHandleRecord[0].timeoutFlag = FALSE;
    WriteSecurityDataTimeHandleRecord[0].timeoutTime = 0;
}

/******************************************************************************/
/**
* @brief               <EOL_Icu_Can3RxWakeupHandler>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <status>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static FUNC(void , EOL_CODE) EOL_Icu_Can3RxWakeupHandler(void)
{
    uint8 ControllerModePtr = 0x00;

    CanIf_GetControllerMode(0x00, &ControllerModePtr);

    if(CANIF_CS_STARTED == ControllerModePtr)
    { 
        /* Disable interrupt wakeup checking*/
        Icu_DisableEdgeDetection(IcuConf_IcuChannel_VIP_CAN3_RXD);
        Icu_DisableNotification(IcuConf_IcuChannel_VIP_CAN3_RXD);
    }
    else if((CANIF_CS_STOPPED == ControllerModePtr) || (CANIF_CS_SLEEP == ControllerModePtr))
    {
        /* Enable interrupt wakeup checking*/
        Icu_EnableNotification(IcuConf_IcuChannel_VIP_CAN3_RXD);
        Icu_EnableEdgeDetection(IcuConf_IcuChannel_VIP_CAN3_RXD);
    }

}

/******************************************************************************/
/**
* @brief               <Icu_EOL_CAN3Rx_WakeupNotifactionFunc>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <status>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
FUNC(void, ICU_APPL_CODE) Icu_EOL_CAN3Rx_WakeupNotifactionFunc (void)
{
    /* Disable interrupt wakeup checking*/
    Icu_DisableEdgeDetection(IcuConf_IcuChannel_VIP_CAN3_RXD);
    Icu_DisableNotification(IcuConf_IcuChannel_VIP_CAN3_RXD);
    
    EcuM_CheckWakeup(ECUM_WKSOURCE_CN_B30_for_SC_CAN_V3_2_c0d6c67b);
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:EOL_MainFunction1ms_doc)  *****************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:EOL_MainFunction1ms)  ****************************/

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
