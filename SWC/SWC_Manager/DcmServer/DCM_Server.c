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
 *             File:  DCM_Server.c
 *           Config:  D:/code/VIP_P05/VIP_P05/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  DCM_Server
 *  Generation Time:  2022-01-04 10:33:37
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <DCM_Server>
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
 * Dcm_ConfirmationStatusType
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
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_DCM_Server.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "stdlib.h"
#include "dr7f701651.dvf.h"
#include "Vconfig.h"
#include "DcmEx.h"
#include "logger.h"

#if (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_P02) || (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_P05) || \
    (defined GWM_V35_PROJECT_TYPE_D01) || (defined GWM_V35_PROJECT_TYPE_D02) || (defined GWM_V35_PROJECT_TYPE_D03) || (defined GWM_V35_PROJECT_TYPE_A07) || \
    (defined GWM_V35_PROJECT_TYPE_A08) || (defined GWM_V35_PROJECT_TYPE_EC24)|| (defined GWM_V35_PROJECT_TYPE_ES13)|| (defined GWM_V35_PROJECT_TYPE_ES24) || \
    (defined GWM_V35_PROJECT_TYPE_B16) || (defined GWM_V35_PROJECT_TYPE_P01) || (defined GWM_V35_PROJECT_TYPE_P09)

    #define USECOMEXIF TRUE
    #include "ComEx_Cfg.h"

#if (defined GWM_V35_PROJECT_TYPE_P05) || (defined GWM_V35_PROJECT_TYPE_A08)
    #define USE_MULTI_CAN_BUS TRUE
#else 
    #define USE_MULTI_CAN_BUS FALSE
#endif

#else
    #define USECOMEXIF FALSE
#endif

#define UNUSED(x) ((void)(x))

#define DCM_CONDITION_SPEED_THRESH           22u     /*1.25kph/0.05625 */

#define     EOL_SEEDNUMBER                 (0x04u)
#define     EOL_KEYNUMBER                  (0x04u)
#define     EOL_EOLCODENUMBER              (0x04u)
#define     GWM_DIAGNOSTIC_SECUIRITY_MASK   0x48205554

static uint8 EOL_Seed[4];
static uint32 DiagnosticSeed = 0;

static const uint8 EOLCodeDefault[EOL_EOLCODENUMBER] = {0x11,0x22,0x33,0x44};
static SG_ABS3 sgAbsPtr;
static uint16 lastVehSpd = 0;
static boolean lastVehSpdVld = 0;

static void EOL_SetDeed(uint8* seed);
static Std_ReturnType EOL_GetDeed(uint8* seed);
static uint32 GWM_SeedToKey(uint32 seed,uint32 MASK);

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
 * ABSActv_0x265: Boolean
 * ABSFailSts_0x265: Boolean
 * ComEx_ConstSignalDataType: DataReference
 * ComEx_SignalGroupIdType: Integer in interval [0...65535]
 * ComEx_SignalIdType: Integer in interval [0...65535]
 * EBDFailSts_0x265: Boolean
 * Rte_DT_s_PowerOut_t_0: Integer in interval [0...255]
 * Rte_DT_s_PowerOut_t_1: Integer in interval [0...65535]
 * VehOdoInfoSts_0x265: Boolean
 * VehSpdVld_0x265: Boolean
 * VehSpd_0x265: Integer in interval [0...65535]
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * dummy_ABS3_0: Integer in interval [0...255]
 * dummy_ABS3_1: Integer in interval [0...255]
 * dummy_ABS3_2: Integer in interval [0...255]
 * dummy_ABS3_3: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * CheckSum_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * Dcm_ConfirmationStatusType: Enumeration of integer in interval [0...3] with enumerators
 *   DCM_RES_POS_OK (0U)
 *   DCM_RES_POS_NOT_OK (1U)
 *   DCM_RES_NEG_OK (2U)
 *   DCM_RES_NEG_NOT_OK (3U)
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
 * RollingCounter_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * VehOdoInfo_0x265: Enumeration of integer in interval [0...65535] with enumerators
 *   Cx000_Valid_values (0U)
 *   Cx3E7_Valid_values (999U)
 *   Cx3E8_Reserved (1000U)
 *   Cx3FF_Reserved (1023U)
 *
 * Array Types:
 * ============
 * A_1Bytes: Array with 1 element(s) of type uint8
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * Dcm_Data19ByteType: Array with 19 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data300ByteType: Array with 300 element(s) of type uint8
 * Dcm_Data4095ByteType: Array with 4095 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_Data8ByteType: Array with 8 element(s) of type uint8
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 *
 * Record Types:
 * =============
 * SG_ABS3: Record with elements
 *   ABSActv_0x265 of type ABSActv_0x265
 *   ABSFailSts_0x265 of type ABSFailSts_0x265
 *   CheckSum_ABS3_0x265 of type CheckSum_ABS3_0x265
 *   dummy_ABS3_0 of type dummy_ABS3_0
 *   dummy_ABS3_1 of type dummy_ABS3_1
 *   dummy_ABS3_2 of type dummy_ABS3_2
 *   dummy_ABS3_3 of type dummy_ABS3_3
 *   EBDFailSts_0x265 of type EBDFailSts_0x265
 *   RollingCounter_ABS3_0x265 of type RollingCounter_ABS3_0x265
 *   VehOdoInfo_0x265 of type VehOdoInfo_0x265
 *   VehOdoInfoSts_0x265 of type VehOdoInfoSts_0x265
 *   VehSpd_0x265 of type VehSpd_0x265
 *   VehSpdVld_0x265 of type VehSpdVld_0x265
 * s_PowerOut_t: Record with elements
 *   state of type Rte_DT_s_PowerOut_t_0
 *   value of type Rte_DT_s_PowerOut_t_1
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
 *   uint8 *Rte_Pim_NvBlockNeedSecAttemptCount_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *   uint8 *Rte_Pim_NvBlockNeedSecAttmptCount_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data300ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_Dcm_VIN_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data19ByteType
 *   uint8 *Rte_Pim_NvBlockNeed_EOLUnlockCnt_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_NvBlockNeedSecAttemptCount_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *   uint8 *Rte_CData_NvBlockNeed_EOLUnlockCnt_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_1Bytes
 *
 *********************************************************************************************************************/


#define DCM_Server_START_SEC_CODE
#include "DCM_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DCM_Server_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DCM_Server_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DCM_Server_CODE) DCM_Server_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DCM_Server_Init
 *********************************************************************************************************************/




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DCM_Server_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DcmRpSR_SG_ABS3_SG_ABS3(SG_ABS3 *data)
 *   Std_ReturnType Rte_Read_Vconfig_KindBuffers_VconfigKind_157Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_157Bytes
 *   Std_ReturnType Rte_Read_rpSR_DCMSever_SpeedoInfo_Element(s_SpeedoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_DCMSever_TachoInfo_Element(s_TachoInfo_t *data)
 *   boolean Rte_IsUpdated_DcmRpSR_SG_ABS3_SG_ABS3(void)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_PiDcmUserCondition_Mode(uint8 mode)
 *   Modes of Rte_ModeType_DcmUserConditionMode:
 *   - RTE_MODE_DcmUserConditionMode_DCM_USER_CONDITION_OK
 *   - RTE_MODE_DcmUserConditionMode_DCM_USER_CONDITON_NOT_OK
 *   - RTE_TRANSITION_DcmUserConditionMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetKindConfig_Std_ReturnType
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
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DCM_Server_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DCM_Server_CODE) DCM_Server_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DCM_Server_MainFunction
 *********************************************************************************************************************/
    SG_ABS3 absframe;
    Std_ReturnType fctRet = E_NOT_OK;

#if (USE_MULTI_CAN_BUS == TRUE)
    uint8 DcmVConfig_CanBusType;/* 0:CAN; 1:CAN FD */
    VConfig_GetKindConfig(VCONFIG_KIND_PT_CAN_BUS_TYPE,&DcmVConfig_CanBusType);
    if (DcmVConfig_CanBusType == 1u)
    {
        fctRet = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD_0X137, &absframe.VehSpdVld_0x265, (uint8)sizeof(absframe.VehSpdVld_0x265));
        Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD_0X137, &absframe.VehSpd_0x265, (uint8)sizeof(absframe.VehSpd_0x265));
    }
    else
    {
        fctRet = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD_0X265, &absframe.VehSpdVld_0x265, (uint8)sizeof(absframe.VehSpdVld_0x265));
        Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD_0X265, &absframe.VehSpd_0x265, (uint8)sizeof(absframe.VehSpd_0x265));
    }
#else
        fctRet = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, &absframe.VehSpdVld_0x265, (uint8)sizeof(absframe.VehSpdVld_0x265));
        Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, &absframe.VehSpd_0x265, (uint8)sizeof(absframe.VehSpd_0x265));
#endif // (USE_MULTI_CAN_BUS == TRUE)

    if((RTE_E_OK != fctRet) && (COMEX_UPDATE_RECEIVED != fctRet))
    {
      sgAbsPtr.VehSpdVld_0x265 = lastVehSpdVld;
      sgAbsPtr.VehSpd_0x265 = lastVehSpd;
    }
    else
    {
      sgAbsPtr.VehSpdVld_0x265 = absframe.VehSpdVld_0x265;
      sgAbsPtr.VehSpd_0x265 = absframe.VehSpd_0x265;
    }


    lastVehSpdVld = sgAbsPtr.VehSpdVld_0x265;
    lastVehSpd = sgAbsPtr.VehSpd_0x265;


    if(((sgAbsPtr.VehSpdVld_0x265 == TRUE)&&(sgAbsPtr.VehSpd_0x265 <= DCM_CONDITION_SPEED_THRESH))||(sgAbsPtr.VehSpdVld_0x265 != TRUE))
    {
        (void)Rte_Switch_DCM_Server_PiDcmUserCondition_Mode(RTE_MODE_DcmUserConditionMode_DCM_USER_CONDITION_OK);
    }
    else
    {
        (void)Rte_Switch_DCM_Server_PiDcmUserCondition_Mode(RTE_MODE_DCM_Server_DcmUserConditionMode_DCM_USER_CONDITON_NOT_OK);
    }
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecurityAccess_Level_EOL_Unlocked_CompareKey
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CompareKey> of PortPrototype <SecurityAccess_Level_EOL_Unlocked>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SecurityAccess_Level_EOL_Unlocked_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Key: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_COMPARE_KEY_FAILED
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_PENDING
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_Level_EOL_Unlocked_CompareKey_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_Level_EOL_Unlocked_CompareKey (returns application error)
 *********************************************************************************************************************/
    uint8 index;
    uint8 attempCnt;
    uint8 keyValue[EOL_KEYNUMBER] = {0x00};
    uint8 ret = RTE_E_INVALID;
    Std_ReturnType KeyRet = RTE_E_INVALID;
    UNUSED(OpStatus);
    UNUSED(ErrorCode);

    if(Key != NULL_PTR)
    {
        KeyRet = EOL_GetDeed(keyValue);
        if(KeyRet == RTE_E_OK)
        {
            for(index = 0; index < EOL_KEYNUMBER; index++)
            {
                if(Key[index] != (uint8)(~keyValue[index]))
                {
                    (void)SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter(1,&attempCnt);
                    attempCnt += 1;
                    (void)SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter(1, attempCnt);
                    return RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_COMPARE_KEY_FAILED;
                }
            }

            for(index = 4; index < (EOL_KEYNUMBER + 4); index++)
            {
                if(Key[index] != EOLCodeDefault[index - 4])
                {
                    (void)SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter(1,&attempCnt);
                    attempCnt += 1;
                    (void)SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter(1, attempCnt);
                    return RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_COMPARE_KEY_FAILED;
                }
            }
        }
        ret = RTE_E_OK;
    }
    
    (void)SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter(1, 0);
    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSecurityAttemptCounter> of PortPrototype <SecurityAccess_Level_EOL_Unlocked>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 *AttemptCounter)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_PENDING
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) AttemptCounter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter (returns application error)
 *********************************************************************************************************************/
    UNUSED(OpStatus);
    UNUSED(AttemptCounter);
    *AttemptCounter = Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_MirrorBlock[0];
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecurityAccess_Level_EOL_Unlocked_GetSeed
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSeed> of PortPrototype <SecurityAccess_Level_EOL_Unlocked>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SecurityAccess_Level_EOL_Unlocked_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Seed: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_PENDING
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_Level_EOL_Unlocked_GetSeed_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_Level_EOL_Unlocked_GetSeed (returns application error)
 *********************************************************************************************************************/
    uint8 index;
    Std_ReturnType ret = RTE_E_INVALID;
    /* Get Rand Value from HSM */
    uint8 seedValue[EOL_SEEDNUMBER] = {0x00};
    uint32 tick = TAUJ0CNT0;

    UNUSED(OpStatus);
    UNUSED(ErrorCode);

    srand(tick);
    for(index = 0; index < EOL_SEEDNUMBER; index++)
   {
        seedValue[index] = (uint8)rand();
    }

    if(Seed != NULL_PTR)
    {
        for(index = 0; index < EOL_SEEDNUMBER; index++)
        {
            Seed[index] = seedValue[index];
        }
        EOL_SetDeed(seedValue);
        ret = RTE_E_OK;
    }

    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSecurityAttemptCounter> of PortPrototype <SecurityAccess_Level_EOL_Unlocked>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_PENDING
 *   RTE_E_SecurityAccess_Level_EOL_Unlocked_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter (returns application error)
 *********************************************************************************************************************/
#if (defined GWM_V35_PROJECT_TYPE_P02) || (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_P05) || (defined GWM_V35_PROJECT_TYPE_D01) || \
    (defined GWM_V35_PROJECT_TYPE_D02) || (defined GWM_V35_PROJECT_TYPE_D03) || (defined GWM_V35_PROJECT_TYPE_A07) || (defined GWM_V35_PROJECT_TYPE_A08) || \
    (defined GWM_V35_PROJECT_TYPE_EC24) || (defined GWM_V35_PROJECT_TYPE_ES13) || (defined GWM_V35_PROJECT_TYPE_ES24) || (defined GWM_V35_PROJECT_TYPE_B16) || (defined GWM_V35_PROJECT_TYPE_P01) || (defined GWM_V35_PROJECT_TYPE_P09)

    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    Std_ReturnType fctRet = E_NOT_OK;

    switch(OpStatus)
    {
      case DCM_INITIAL:

        if(Rte_Pim_NvBlockNeed_EOLUnlockCnt_MirrorBlock()[0] != AttemptCounter)
        {
          fctRet = Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_GetErrorStatus(&nvmStatus);
          if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
          {
            Rte_Pim_NvBlockNeed_EOLUnlockCnt_MirrorBlock()[0] = AttemptCounter;
            (void)Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_WriteBlock(NULL_PTR);
            ret  = RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_PENDING;
          }
          else
          {
            ret  = RTE_E_SecurityAccess_Level_EOL_Unlocked_E_NOT_OK;
          }
        }
         break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
          fctRet = Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_GetErrorStatus(&nvmStatus);
          if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
          {
            if(NVM_REQ_OK != nvmStatus)
            {
             ret = RTE_E_SecurityAccess_Level_EOL_Unlocked_E_NOT_OK;
            }
          }
          else
          {
             ret = RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_PENDING;
          }
         break;
        default:
        ret = RTE_E_OK;
        break;
    
    }
    return ret;
#else
    UNUSED(OpStatus);
    Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_MirrorBlock[0] = AttemptCounter;
    (void)Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_WriteBlock(NULL_PTR);
    return RTE_E_OK;
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecurityAccess_UnlockedL1_CompareKey
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CompareKey> of PortPrototype <SecurityAccess_UnlockedL1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SecurityAccess_UnlockedL1_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Key: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED
 *   RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING
 *   RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_UnlockedL1_CompareKey_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_UnlockedL1_CompareKey (returns application error)
 *********************************************************************************************************************/
    uint32 reqKey;
    uint32 locKey;
    Std_ReturnType  retValue = RTE_E_OK;

    UNUSED(OpStatus);
    UNUSED(ErrorCode);

    reqKey = Key[0];
    reqKey <<= 8;
    reqKey |= Key[1];
    reqKey <<= 8;
    reqKey |= Key[2];
    reqKey <<= 8;
    reqKey |= Key[3];

    locKey = GWM_SeedToKey(DiagnosticSeed,GWM_DIAGNOSTIC_SECUIRITY_MASK);
    if(reqKey != locKey)
    {
        retValue = RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED;
    }
    return (retValue);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecurityAccess_UnlockedL1_GetSecurityAttemptCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSecurityAttemptCounter> of PortPrototype <SecurityAccess_UnlockedL1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SecurityAccess_UnlockedL1_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 *AttemptCounter)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING
 *   RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_UnlockedL1_GetSecurityAttemptCounter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) AttemptCounter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_UnlockedL1_GetSecurityAttemptCounter (returns application error)
 *********************************************************************************************************************/
    UNUSED(OpStatus);

    *AttemptCounter = Rte_Pim_NvBlockNeedSecAttemptCount_MirrorBlock()[0];


    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecurityAccess_UnlockedL1_GetSeed
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSeed> of PortPrototype <SecurityAccess_UnlockedL1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Seed: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING
 *   RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_UnlockedL1_GetSeed_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_UnlockedL1_GetSeed (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retValue = RTE_E_OK;
    uint32 tSeed;
    uint32 tick = TAUJ0CNT0;

    UNUSED(OpStatus);
    UNUSED(ErrorCode);

    srand(tick);
    tSeed = (uint32)rand();
    tSeed <<= 16;
    tSeed |= (uint32)rand();
    if(tSeed)
    {
        DiagnosticSeed = tSeed;
        *Seed = (uint8)(DiagnosticSeed >> 24);
        Seed++;
        *Seed = (uint8)(DiagnosticSeed >> 16);
        Seed++;
        *Seed = (uint8)(DiagnosticSeed >> 8);
        Seed++;
        *Seed = (uint8)DiagnosticSeed;
    }
    else
    {
        retValue = RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING;
    }

    return (retValue);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SecurityAccess_UnlockedL1_SetSecurityAttemptCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSecurityAttemptCounter> of PortPrototype <SecurityAccess_UnlockedL1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SecurityAccess_UnlockedL1_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING
 *   RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_UnlockedL1_SetSecurityAttemptCounter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SecurityAccess_UnlockedL1_SetSecurityAttemptCounter (returns application error)
 *********************************************************************************************************************/
#if (defined GWM_V35_PROJECT_TYPE_P02) || (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_P05) || (defined GWM_V35_PROJECT_TYPE_D01) || \
    (defined GWM_V35_PROJECT_TYPE_D02) || (defined GWM_V35_PROJECT_TYPE_D03) || (defined GWM_V35_PROJECT_TYPE_A07) || (defined GWM_V35_PROJECT_TYPE_A08) || \
    (defined GWM_V35_PROJECT_TYPE_EC24) || (defined GWM_V35_PROJECT_TYPE_ES13) || (defined GWM_V35_PROJECT_TYPE_ES24) || (defined GWM_V35_PROJECT_TYPE_B16) || (defined GWM_V35_PROJECT_TYPE_P01) || (defined GWM_V35_PROJECT_TYPE_P09)

    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    Std_ReturnType fctRet = E_NOT_OK;

    switch(OpStatus)
    {
      case DCM_INITIAL:

        if(Rte_Pim_NvBlockNeedSecAttemptCount_MirrorBlock()[0] != AttemptCounter)
        {
          fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_GetErrorStatus(&nvmStatus);
          if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
          {
            Rte_Pim_NvBlockNeedSecAttemptCount_MirrorBlock()[0] = AttemptCounter;
            (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_WriteBlock(NULL_PTR);
            ret  = RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING;
          }
          else
          {
            ret  = RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK;
          }
        }
         break;
      case DCM_PENDING:
      case DCM_FORCE_RCRRP_OK:
          fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_GetErrorStatus(&nvmStatus);
          if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
          {
            if(NVM_REQ_OK != nvmStatus)
            {
             ret = RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK;
            }
          }
          else
          {
             ret = RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING;
          }
         break;
        default:
        ret = RTE_E_OK;
        break;
    
    }
    return ret;

#else
    UNUSED(OpStatus);

    Rte_Pim_NvBlockNeedSecAttemptCount_MirrorBlock()[0] = AttemptCounter;
    (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_WriteBlock(NULL_PTR);

    return RTE_E_OK;

#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ServiceRequestNotificationGwm_Confirmation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Confirmation> of PortPrototype <ServiceRequestNotificationGwm>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ServiceRequestNotificationGwm_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ServiceRequestNotification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceRequestNotificationGwm_Confirmation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) ServiceRequestNotificationGwm_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceRequestNotificationGwm_Confirmation (returns application error)
 *********************************************************************************************************************/
    UNUSED(SID);
    UNUSED(ReqType);
    UNUSED(SourceAddress);
    UNUSED(ConfirmationStatus);

    return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ServiceRequestNotificationGwm_Indication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Indication> of PortPrototype <ServiceRequestNotificationGwm>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ServiceRequestNotificationGwm_Indication(uint8 SID, const uint8 *RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument RequestData: uint8* is of type Dcm_Data4095ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ServiceRequestNotification_E_NOT_OK
 *   RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceRequestNotificationGwm_Indication_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_Server_CODE) ServiceRequestNotificationGwm_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceRequestNotificationGwm_Indication (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = RTE_E_OK;

    UNUSED(SourceAddress);

    if(1 == ReqType)
    {
        if((0x27 == SID)||(0x2e == SID)||(0x31 == SID ))
        {
            ret = RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED;
        }
    }

    if(0x14 == SID)
    {
        if(DataSize != 3)
        {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = RTE_E_ServiceRequestNotification_E_NOT_OK;
        }
        else
        {
            if((0xFF != RequestData[0])||(0xFF != RequestData[1])||(0xFF != RequestData[2]))
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                 ret = RTE_E_ServiceRequestNotification_E_NOT_OK;
            }
        }
    }
    #if (DIAG_USE_DCMEX == TRUE)
    if((0x22 == SID) || (0x2E == SID))
    {
        DcmEx_SetCurrentSid(SID);
    }
    #endif // (DIAG_USE_DCMEX == TRUE)

    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DCM_Server_STOP_SEC_CODE
#include "DCM_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
static void EOL_SetDeed(uint8* seed)
{
    uint8 index;
    
    if(seed != NULL_PTR)
    {
        for(index = 0; index < EOL_SEEDNUMBER; index++)
        {
            EOL_Seed[index] = seed[index];
        }
    }
}

static Std_ReturnType EOL_GetDeed(uint8* seed)
{
    uint8 index;
    uint8 ret = RTE_E_INVALID;
    
    if(seed != NULL_PTR)
    {
        for(index = 0; index < EOL_SEEDNUMBER; index++)
        {
            seed[index] = EOL_Seed[index];
        }
        ret = RTE_E_OK;
    }

    return ret;
}

static uint32 GWM_SeedToKey(uint32 seed,uint32 MASK)
{
    uint8 i;
    uint32 key = 0;
    if(seed != 0)
    {
        for(i = 0;i < 35;i++)
        {
            if(seed & 0x80000000)
            {
                seed = seed << 1;
                seed = seed ^ MASK;
            }
            else
            {
                seed = seed << 1;
            }
        }
        key = seed;
    }
    return (key);
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
