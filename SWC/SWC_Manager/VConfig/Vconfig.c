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
 *             File:  Vconfig.c
 *           Config:  D:/code/VIP-P05/VIP_P05/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Vconfig
 *  Generation Time:  2022-01-13 10:31:44
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Vconfig>
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
 *********************************************************************************************************************/

#include "Rte_Vconfig.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*
 *  %header file in this project/library%
 */
#include "VConfig.h"
#include "IPC_Misc.h"
#include "AMPVCfg.h"
#include "DcmEx.h"
#include "logger.h"

/*
 *  %third-party header file%
 */

/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */
#define VCONFIG_GET_NBIT(byte,begin,end) \
    (((byte) & ((255u >> (7u - (end))) & (255u << (begin)))) >> (begin))

#define BIG_TO_LIT(x)  (((x&0x000000ff)<<24u) | ((x&0x0000ff00)<<8u) | ((x&0x00ff0000 )>>8u) | ((x&0xff000000)>>24u))

#ifndef DCM_INITIAL
#define DCM_INITIAL (0U)
#endif

#ifndef DCM_PENDING
#define DCM_PENDING (1U)
#endif


/*
 *  %forward declaration%
 */
static void VConfig_Parse(void);

static void Dtc_SwitchCalculation(void);
static void Dtc_RetrySetEventAvailable(void);


/*
 *  %global definition%
 */
typedef struct dtcSwitchState
{
    boolean calculateResult;
    uint8 fctCallRet;
}dtcSwitchState_t;

extern const Std_ReturnType(*EventAavailableFunctionTable[DTC_SWITCH_NUMBER])(boolean result);

#define VCONFIG_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "VConfig_MemMap.h"
 VConfig_Type vConfig = {(boolean)FALSE, 0, &vconfig_config};
static dtcSwitchState_t dtcSwitchStatus[DTC_SWITCH_NUMBER] = {(boolean)0};
#define VCONFIG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "VConfig_MemMap.h"

uint8 Get_Vconfig_Flag = FALSE;
uint8 Vconfig_Response_Flag = FALSE;
uint8 Usb_Update_Request_Flag = FALSE;
uint8 Usb_Updata_Data[200] = { 57U, 105U, 19U, 7U, 1U, 4U, 0U, 5U, 96U, 81U, 53U, 97U, 88U, 17U, 84U, 64U, 65U, 97U, 32U, 68U, 137U, 48U, 5U, 5U, 33U, 33U, 66U, 13U, 144U, 0U, 0U, 59U, 72U, 81U, 0U, 0U, 18U, 52U, 81U, 10U, 0U, 5U, 9U, 21U, 1U, 41U, 44U, 20U, 3U, 3U, 68U, 80U, 1U, 0U, 39U, 35U, 0U, 0U, 0U, 0U, 0U, 48U, 0U, 97U, 72U, 32U, 0U, 0U, 129U, 1U, 0U, 0U, 0U, 0U, 0U, 72U, 0U, 0U, 52U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U };
uint8 Usb_Updata_OpStatus = DCM_INITIAL;

uint8 VconfigRequestUpdateLatestCount = 0;
uint8 VconfigRequestUpdatePreCount = 0;

IPC_M2S_MiscServiceVreply_Usb_t Response_Data = {E_NOT_OK};
#define VCONFIG_START_SEC_CODE
#include "VConfig_MemMap.h"

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
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Dcm_Data200ByteType: Array with 200 element(s) of type uint8
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 * VconfigKind_400Bytes: Array with 400 element(s) of type uint8
 * VconfigKind_Allbuffers: Array with 600 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define Vconfig_START_SEC_CODE
#include "Vconfig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation_VConfig_GetKindConfig> of PortPrototype <VConfig_GetKindConfig>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_VConfig_GetKindConfig_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: VConfig_GetKindConfig_Operation_VConfig_GetKindConfig_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Vconfig_CODE) VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_VCONFIG_APPL_VAR) kindConfig) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VConfig_GetKindConfig_Operation_VConfig_GetKindConfig (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_OK;

#if(VCONFIG_DEV_ERROR_DETECT == STD_ON)
    if((kindId >= vConfig.config->kindNumber) ||
			(NULL_PTR == kindConfig))
    {
        ret = E_NOT_OK;
    }
    else if(FALSE == vConfig.isInit)
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        *kindConfig = vConfig.config->kindDatas[kindId].configGet;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <OperationVConfig_GetUpdateTick> of PortPrototype <VConfig_GetUpdateTick>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(TimeInMicrosecondsType *updateTick)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_VConfig_GetUpdateTick_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Vconfig_CODE) VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_VCONFIG_APPL_VAR) updateTick) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_OK;

#if(VCONFIG_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == updateTick)
    {
        ret = E_NOT_OK;
    }
    else if(FALSE == vConfig.isInit)
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        *updateTick = vConfig.updateTime;
    }

    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VConfig_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ECUlevelNetworkConfigurationDataIdentifier_Element(uint8 *data)
 *     Argument data: uint8* is of type Dcm_Data200ByteType
 *   Std_ReturnType Rte_Read_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VconfigResponseFlag_VconfigResponseFlag(uint8 data)
 *   Std_ReturnType Rte_Write_Vconfig_GetKindBuffers_AllKinds(const uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_Allbuffers
 *   Std_ReturnType Rte_Write_Vconfig_KindBuffers_VconfigKind_157Bytes(const uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_157Bytes
 *   Std_ReturnType Rte_Write_Vconfig_KindBuffers_400bytes_VconfigKind_400Bytes(const uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_400Bytes
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_USBWriteECUlevelNetworkConfigurationData_USBWriteData(uint8 *data, uint16 length, uint8 OpStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_USBWriteECUlevelNetworkConfigurationData_E_NOT_OK, RTE_E_USBWriteECUlevelNetworkConfigurationData_E_OK, RTE_E_USBWriteECUlevelNetworkConfigurationData_E_PENDING
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EventAvailable_0x908487_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908487_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908587_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908587_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908687_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908687_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908887_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908887_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908A87_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908A87_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x908B87_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910011_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910011_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910012_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910012_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910013_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910013_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910087_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910087_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910111_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910111_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910112_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910112_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910113_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910113_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910187_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910187_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910287_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910287_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910387_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910387_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910487_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910487_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910511_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910512_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910513_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910611_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910612_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910613_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910711_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910712_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910713_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910811_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910812_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910813_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910887_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x910887_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x927312_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x927312_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x927412_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x927412_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x93F511_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x93F512_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x93F513_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x95F811_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x95F812_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x95F813_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0101_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0111_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0112_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0113_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A011E_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0125_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0201_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0211_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0212_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0213_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A021E_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0225_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0301_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0311_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0312_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0313_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A031E_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0325_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0401_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0411_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0412_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0413_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A041E_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0425_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0501_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0511_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0512_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0513_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A051E_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0525_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0601_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0611_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0612_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0613_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A061E_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0625_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0701_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0711_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0712_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0713_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A071E_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0725_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0811_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0812_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0813_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0x9A0819_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA13011_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA13011_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA13111_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA13111_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30008_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30008_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30017_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30017_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30093_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30093_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30116_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30116_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30149_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30149_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30157_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30157_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30249_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30249_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30349_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30349_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30449_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30449_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30549_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30549_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30649_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA30649_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA50157_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xA50157_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC10087_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC10087_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC10187_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC10187_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC10487_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC10487_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC11187_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC11187_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC11487_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC11487_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC11587_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC11587_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC12287_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC12287_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC12787_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC12787_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC12887_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC12887_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC13187_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC13187_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC14087_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC14187_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC14187_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC14387_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC14387_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC15887_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC15887_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC15C87_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC15C87_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC16487_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC16487_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC19887_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC19887_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC19987_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC19987_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC1BB87_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC1BB87_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC20087_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC20087_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC20887_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC20887_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC23087_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC23087_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC23387_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC23387_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24187_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24187_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24287_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24287_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24387_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24387_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24687_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24687_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24787_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC24787_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC25E87_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC25E87_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC29387_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC29387_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC2B387_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC2B387_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC2B587_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xC2B587_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD00487_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD00487_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD00987_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD00987_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD01587_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD01587_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD02687_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD02687_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD02987_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD02987_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD10887_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD10887_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD10987_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD10987_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD10B87_GetEventAvailable(boolean *AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD10B87_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_EventAvailable_0xD12387_SetEventAvailable(boolean AvailableStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EventAvailable_E_NOT_OK, RTE_E_EventAvailable_E_OK
 *   Std_ReturnType Rte_Call_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: VConfig_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Vconfig_CODE) VConfig_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VConfig_MainFunction
 *********************************************************************************************************************/


	uint8 ret = RTE_E_USBWriteECUlevelNetworkConfigurationData_E_NOT_OK;
    uint8 i =0;
	Rte_Read_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag(&VconfigRequestUpdateLatestCount);
	//VConfig_Data_Process();
	if(((VconfigRequestUpdateLatestCount -1) == VconfigRequestUpdatePreCount) || (Get_Vconfig_Flag == TRUE))
	{
		(void)Rte_Read_ECUlevelNetworkConfigurationDataIdentifier_Element(vConfig.config->rawData);
		/* check config change */
		/*
		for(pos = 0u; pos < vConfig.config->rawDataSize; pos++)
		{
			if(vConfig.config->rawData[pos] != vConfig.config->rawDataBackup[pos])
			{
				//parseNeed = TRUE;
				vConfig.config->rawData[pos] = vConfig.config->rawDataBackup[pos];
			}
		}
		*/
		VConfig_Parse();
        (void)Rte_Call_Os_Service_GetCounterValue(&vConfig.updateTime);
	
        (void)Rte_Write_Vconfig_Vconfig_GetKindBuffers_AllKinds(vConfig.config->kindDatas);
        /* Send ipc data to SOC */
		(void)IPC_M2S_MiscServiceVconfig_Transmit(vConfig.config->rawData);
        /* print Vconfig to SOC log */
        for(i = 0; i < 10u; i++)
        {
            can_warn("M2S %d:%08X %08x %08X %08X %08X", i,
                BIG_TO_LIT(((uint32 *)(vConfig.config->rawData))[i * 5 + 0]), BIG_TO_LIT(((uint32 *)(vConfig.config->rawData))[i * 5 + 1]),
                BIG_TO_LIT(((uint32 *)(vConfig.config->rawData))[i * 5 + 2]), BIG_TO_LIT(((uint32 *)(vConfig.config->rawData))[i * 5 + 3]),
                BIG_TO_LIT(((uint32 *)(vConfig.config->rawData))[i * 5 + 4]));
        }
        Get_Vconfig_Flag = (uint8)FALSE;
		VconfigRequestUpdatePreCount = VconfigRequestUpdateLatestCount;
		if(VconfigRequestUpdatePreCount == 255)
		{
			VconfigRequestUpdatePreCount = 0;
		}
	}
  
    if(Vconfig_Response_Flag == TRUE)
    {
         Rte_Write_Vconfig_VconfigResponseFlag_VconfigResponseFlag(TRUE);
         Vconfig_Response_Flag = (uint8)FALSE;
    }
   
	if(Usb_Update_Request_Flag == TRUE)
	{
		ret = Rte_Call_USBWriteECUlevelNetworkConfigurationData_USBWriteData(Usb_Updata_Data,VCONFIG_RAW_DATA_SIZE,Usb_Updata_OpStatus);/*writer usb vconfig data to NVM*/
		if(ret == RTE_E_USBWriteECUlevelNetworkConfigurationData_E_OK)
		{
			Usb_Update_Request_Flag = (uint8)FALSE;
			Response_Data.u8Channel = E_OK;
			(void)IPC_M2S_MiscServiceVreply_Usb_Transmit(&Response_Data); /*send usb update vconfig reply*/
		}
		else if(ret == RTE_E_USBWriteECUlevelNetworkConfigurationData_E_PENDING)
		{
			Usb_Updata_OpStatus = DCM_PENDING;
		}
		else
		{
			Usb_Update_Request_Flag = (uint8)FALSE;
			Response_Data.u8Channel = E_NOT_OK;
			(void)IPC_M2S_MiscServiceVreply_Usb_Transmit(&Response_Data); /*send usb update vconfig reply*/
		}
		
	}

    #if (DIAG_USE_DCMEX == TRUE)
    DcmEx_DtcRetryAvailable();
    #else
    Dtc_RetrySetEventAvailable();
    #endif // (DIAG_USE_DCMEX == TRUE)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Vconfig_STOP_SEC_CODE
#include "Vconfig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*
* @brief   :   Get kind config of kindId to kindConfig
* @param   :   kindId [IN]: kind Id which indicate a kind of config
* @param   :   kindConfig [OUT]: pointer to location to store kind config
* @retval  :   VCONFIG_SUCCESS: get config success
* @retval  :   VCONFIG_E_PARAM: parameter error
* @retval  :   VCONFIG_E_INIT: module is not initialized
*/
Std_ReturnType VConfig_GetKindConfig(uint16 kindId, uint8* kindConfig)
{
    Std_ReturnType ret = E_OK;

#if(VCONFIG_DEV_ERROR_DETECT == STD_ON)
    if((kindId >= vConfig.config->kindNumber) ||
        (NULL_PTR == kindConfig))
    {
        ret = E_NOT_OK;
    }
    else if(FALSE == vConfig.isInit)
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        *kindConfig = vConfig.config->kindDatas[kindId].configGet;
    }

    return ret;
}

/*
* @brief   :   Get update tick information
* @param   :   updateTick [OUT]: pointer location to store update tick
* @retval  :   VCONFIG_SUCCESS: get tick success
* @retval  :   VCONFIG_E_PARAM: parameter error
* @retval  :   VCONFIG_E_INIT: module is not initialized
*/
Std_ReturnType VConfig_GetUpdateTick(TimeInMicrosecondsType *updateTick)
{
    Std_ReturnType ret = E_OK;

#if(VCONFIG_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == updateTick)
    {
        ret = E_NOT_OK;
    }
    else if(FALSE == vConfig.isInit)
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        *updateTick = vConfig.updateTime;
    }

    return ret;
}

/*
* @brief   :   Internal parse function to convert raw config data to kind config data
* @param   :   none
* @retval  :   none
*/
static void VConfig_Parse(void)
{
    uint16 kind;
    uint8 status;

    for(kind = 0u; kind < ((vConfig.config->kindNumber)-1); kind++)
    {
        const VConfig_KindConfigType *kindConfig = &vConfig.config->kindConfigs[kind];
        VConfig_KindType *kindData = &vConfig.config->kindDatas[kind];

        status = vConfig.config->rawData[kindConfig->byte];
        kindData->configGet = VCONFIG_GET_NBIT(status, kindConfig->startBit, kindConfig->endBit);
    }
    vConfig.config->kindDatas[VCONFIG_KIND_INIT_FLAG].configGet = (uint8)TRUE;
}

FUNC(void, Vconfig_CODE) VConfig_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{

    Std_ReturnType ret = E_OK;
    VConfig_ConfigType *config = vConfig.config;

#if(VCONFIG_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == config)
    {
        ret = E_NOT_OK;
    }
    else if((0u == config->kindNumber) ||
        (NULL_PTR == config->kindConfigs) ||
        (NULL_PTR == config->kindDatas))
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
		
        (void)Rte_Read_ECUlevelNetworkConfigurationDataIdentifier_Element(vConfig.config->rawDataBackup);
        (void)Rte_Read_ECUlevelNetworkConfigurationDataIdentifier_Element(vConfig.config->rawData);

        VConfig_Parse();		
        (void)Rte_Write_Vconfig_Vconfig_GetKindBuffers_AllKinds(vConfig.config->kindDatas);

        /* Clear get tick */
        vConfig.updateTime = 0u;
        /* set config to module config */
        vConfig.isInit = TRUE;

        #if (DIAG_USE_DCMEX == TRUE)
        DcmEx_AvailableCheck();
        #else
        Dtc_SwitchCalculation();
        #endif // (DIAG_USE_DCMEX == TRUE)
    }

    if(E_OK != ret)
    {
        /* Report */
    }

}

static void Dtc_RetrySetEventAvailable(void)
{
    uint16 i;
    uint8 ret;
    for(i = 0 ;i < DTC_SWITCH_NUMBER;i++)
    {
        if(E_NOT_OK == dtcSwitchStatus[i].fctCallRet)
        {
            if(EventAavailableFunctionTable[i] != NULL_PTR)
            {
                ret = EventAavailableFunctionTable[i](dtcSwitchStatus[i].calculateResult);
                dtcSwitchStatus[i].fctCallRet = ret;
            }
            else
            {
                dtcSwitchStatus[i].fctCallRet = E_OK;
            }
        }
    }
}

#if (DIAG_USE_DCMEX != TRUE)
static void Dtc_SwitchCalculation(void)
{
    boolean result = FALSE;
    Std_ReturnType ret = E_OK;
#if (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_A07) || (defined GWM_V35_PROJECT_TYPE_B03) || (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_P05)
    uint16 ampChnSts = 0;
    ampChnSts = AMP_ChCfgSts();
    if((ampChnSts & (uint16)AMP_FL_CHN_ENABLE_MASK) == (uint16)AMP_FL_CHN_ENABLE_MASK)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0101_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0101].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0101].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0111_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0111].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0111].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0112_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0112].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0112].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0113_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0113].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0113].fctCallRet = ret;

    ret = Rte_Call_EventAvailable_0x9A011E_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A011E].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A011E].fctCallRet = ret;
    
    ret = Rte_Call_EventAvailable_0x9A0125_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0125].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0125].fctCallRet = ret;

    if((ampChnSts & (uint16)AMP_FR_CHN_ENABLE_MASK) == (uint16)AMP_FR_CHN_ENABLE_MASK)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0201_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0201].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0201].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0211_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0211].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0211].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0212_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0212].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0212].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0213_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0213].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0213].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A021E_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A021E].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A021E].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0225_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0225].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0225].fctCallRet = ret;

    if((ampChnSts & (uint16)AMP_RL_CHN_ENABLE_MASK) == (uint16)AMP_RL_CHN_ENABLE_MASK)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0301_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0301].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0301].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0311_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0311].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0311].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0312_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0312].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0312].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0313_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0313].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0313].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A031E_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A031E].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A031E].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0325_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0325].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0325].fctCallRet = ret;
    
    if((ampChnSts & (uint16)AMP_RR_CHN_ENABLE_MASK) == (uint16)AMP_RR_CHN_ENABLE_MASK)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0401_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0401].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0401].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0411_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0411].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0411].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0412_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0412].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0412].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0413_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0413].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0413].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A041E_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A041E].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A041E].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0425_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0425].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0425].fctCallRet = ret;
    if((ampChnSts & (uint16)AMP_CENTER_CHN_ENABLE_MASK) == (uint16)AMP_CENTER_CHN_ENABLE_MASK)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0501_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0501].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0501].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0511_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0511].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0511].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0512_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0512].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0512].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0513_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0513].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0513].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A051E_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A051E].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A051E].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0525_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0525].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0525].fctCallRet = ret;

    if(((ampChnSts & (uint16)AMP_WOOFER1_CHN_ENABLE_MASK) == (uint16)AMP_WOOFER1_CHN_ENABLE_MASK)||
        ((ampChnSts & (uint16)AMP_WOOFER2_CHN_ENABLE_MASK) == (uint16)AMP_WOOFER2_CHN_ENABLE_MASK))
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0601_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0601].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0601].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0611_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0611].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0611].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0612_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0612].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0612].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0613_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0613].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0613].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A061E_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A061E].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A061E].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0625_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0625].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0625].fctCallRet = ret;

    if((ampChnSts & (uint16)AMP_AVAS_CHN_ENABLE_MASK) == (uint16)AMP_AVAS_CHN_ENABLE_MASK)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0701_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0701].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0701].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0711_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0711].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0711].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0712_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0712].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0712].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0713_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0713].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0713].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A071E_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A071E].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A071E].fctCallRet = ret;
    ret = Rte_Call_EventAvailable_0x9A0725_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0725].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0725].fctCallRet = ret;
#endif

#ifdef GWM_V35_PROJECT_TYPE_P05
    /* start of DTC 0x95F811 switch state */
    if((ampChnSts  == (uint16)AMP_CHANNEL_NONE) || (ampChnSts  == (uint16)AMP_AVAS_CHN_ENABLE_MASK))
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x95F811_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x95F811].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x95F811].fctCallRet = ret;
    /* end of DTC 0x95F811 switch state */
    
    /* start of DTC 0x95F812 switch state */
    if((ampChnSts  == (uint16)AMP_CHANNEL_NONE) || (ampChnSts == (uint16)AMP_AVAS_CHN_ENABLE_MASK))
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x95F812_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x95F812].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x95F812].fctCallRet = ret;
    /* end of DTC 0x95F812 switch state */
    
    /* start of DTC 0x95F813 switch state */
    if((ampChnSts  == (uint16)AMP_CHANNEL_NONE) || (ampChnSts  == (uint16)AMP_AVAS_CHN_ENABLE_MASK))
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x95F813_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x95F813].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x95F813].fctCallRet = ret;
    /* end of DTC 0x9A0813 switch state */
#endif

    /* start of DTC 0xA13011 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet != 0x0)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA13011_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA13011].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA13011].fctCallRet = ret;
    /* end of DTC 0xA13011 switch state */

    /* start of DTC 0x927312 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet != 0x0)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x927312_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x927312].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x927312].fctCallRet = ret;
    /* end of DTC 0x927312 switch state */

    /* start of DTC 0xA13111 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet == 0x4)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA13111_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA13111].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA13111].fctCallRet = ret;
    /* end of DTC 0xA13111 switch state */

    /* start of DTC 0x927412 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet == 0x4)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x927412_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x927412].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x927412].fctCallRet = ret;
    /* end of DTC 0x927412 switch state */
    
    /* start of DTC 0x908B87 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x3)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x908B87_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x908B87].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x908B87].fctCallRet = ret;
    /* end of DTC 0x908B87 switch state */

    /* start of DTC 0x908887 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
        || 
        (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1G) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_YY) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_XDL)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_2ND_ROW_SEAT_CENTRE_ARMREST].configGet == 0x1)
            )
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x908887_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x908887].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x908887].fctCallRet = ret;
    /* end of DTC 0x908887 switch state */

    /* start of DTC 0x908A87 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x5)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x908A87_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x908A87].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x908A87].fctCallRet = ret;
    /* end of DTC 0x908A87 switch state */

    /* start of DTC 0x908687 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x908687_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x908687].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x908687].fctCallRet = ret;
    /* end of DTC 0x908687 switch state */

    /* start of DTC 0x908587 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DVR].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x908587_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x908587].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x908587].fctCallRet = ret;
    /* end of DTC 0x908587 switch state */

    /* start of DTC 0x908487 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMS_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x908487_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x908487].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x908487].fctCallRet = ret;
    /* end of DTC 0x908487 switch state */

    /* start of DTC 0xA30017 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30017_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30017].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30017].fctCallRet = ret;
    /* end of DTC 0xA30017 switch state */

    /* start of DTC 0xA30116 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30116_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30116].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30116].fctCallRet = ret;
    /* end of DTC 0xA30116 switch state */

    /* start of DTC 0xA30008 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30008_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30008].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30008].fctCallRet = ret;
    /* end of DTC 0xA30008 switch state */

    /* start of DTC 0xA30149 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30149_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30149].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30149].fctCallRet = ret;
    /* end of DTC 0xA30149 switch state */

    /* start of DTC 0xA30249 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30249_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30249].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30249].fctCallRet = ret;
    /* end of DTC 0xA30249 switch state */

    /* start of DTC 0xA30349 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30349_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30349].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30349].fctCallRet = ret;
    /* end of DTC 0xA30349 switch state */

    /* start of DTC 0xA30449 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30449_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30449].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30449].fctCallRet = ret;
    /* end of DTC 0xA30449 switch state */

    /* start of DTC 0xA30549 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30549_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30549].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30549].fctCallRet = ret;
    /* end of DTC 0xA30549 switch state */

    /* start of DTC 0xA30649 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30649_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30649].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30649].fctCallRet = ret;
    /* end of DTC 0xA30649 switch state */

    /* start of DTC 0xA30093 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            ||(((VCONFIG_PROJECT_P03_1G == vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet)||
                 (VCONFIG_PROJECT_P03_1 == vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet)||
                 (VCONFIG_PROJECT_P03_YY == vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet)||
                 (VCONFIG_PROJECT_P03_XDL == vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet)
                )&&(0x01 == vConfig.config->kindDatas[VCONFIG_KIND_2ND_ROW_SEAT_CENTRE_ARMREST].configGet)
              )
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30093_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30093].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30093].fctCallRet = ret;
    /* end of DTC 0xA30093 switch state */

    /* start of DTC 0xA30157 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
            ||(((VCONFIG_PROJECT_P03_1G == vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet)||
                 (VCONFIG_PROJECT_P03_1 == vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet)||
                 (VCONFIG_PROJECT_P03_YY == vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet)||
                 (VCONFIG_PROJECT_P03_XDL == vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet)
                )&&(0x01 == vConfig.config->kindDatas[VCONFIG_KIND_2ND_ROW_SEAT_CENTRE_ARMREST].configGet)
              )
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA30157_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA30157].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA30157].fctCallRet = ret;
    /* end of DTC 0xA30157 switch state */

    /* start of DTC 0xA50157 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x3)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xA50157_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xA50157].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xA50157].fctCallRet = ret;
    /* end of DTC 0xA50157 switch state */

    /* start of DTC 0x910011 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_REVERSE_VIDEO].configGet != 0x0)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910011_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910011].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910011].fctCallRet = ret;
    /* end of DTC 0x910011 switch state */

    /* start of DTC 0x910012 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_REVERSE_VIDEO].configGet != 0x0)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910012_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910012].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910012].fctCallRet = ret;
    /* end of DTC 0x910012 switch state */

    /* start of DTC 0x910013 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_REVERSE_VIDEO].configGet != 0x0)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910013_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910013].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910013].fctCallRet = ret;
    /* end of DTC 0x910013 switch state */

    /* start of DTC 0x910087 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_REVERSE_VIDEO].configGet != 0x0)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910087_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910087].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910087].fctCallRet = ret;
    /* end of DTC 0x910087 switch state */

    /* start of DTC 0x910111 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910111_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910111].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910111].fctCallRet = ret;
    /* end of DTC 0x910111 switch state */

    /* start of DTC 0x910112 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910112_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910112].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910112].fctCallRet = ret;
    /* end of DTC 0x910112 switch state */

    /* start of DTC 0x910113 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910113_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910113].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910113].fctCallRet = ret;
    /* end of DTC 0x910113 switch state */

    /* start of DTC 0x910187 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910187_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910187].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910187].fctCallRet = ret;
    /* end of DTC 0x910187 switch state */

    /* start of DTC 0x910287 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910287_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910287].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910287].fctCallRet = ret;
    /* end of DTC 0x910287 switch state */

    /* start of DTC 0x910387 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910387_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910387].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910387].fctCallRet = ret;
    /* end of DTC 0x910387 switch state */

    /* start of DTC 0x910487 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910487_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910487].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910487].fctCallRet = ret;
    /* end of DTC 0x910487 switch state */

    /* start of DTC 0xC10087 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x6) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x7)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC10087_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC10087].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC10087].fctCallRet = ret;
    /* end of DTC 0xC10087 switch state */

    /* start of DTC 0xC12287 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_SERVICE_BRAKE].configGet == 0x2)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_PT_CAN_BUS_TYPE].configGet == 0x0) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_PT_CAN_BUS_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC12287_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC12287].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC12287].fctCallRet = ret;
    /* end of DTC 0xC12287 switch state */

    /* start of DTC 0xC10187 switch state */
    if
    (
            (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x7) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x26) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x29) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x0F) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x10)
            )
            && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_PT_CAN_BUS_TYPE].configGet == 0x0)
            )
           )
          || 
           (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x7) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x26) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x29) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x0F) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x10)
            )
            && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_PT_CAN_BUS_TYPE].configGet == 0x1)
            )
           )
          || 
           (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x13)
           )
          || 
           (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x27) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x28)
           )
          || 
           (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x8)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC10187_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC10187].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC10187].fctCallRet = ret;
    /* end of DTC 0xC10187 switch state */

    /* start of DTC 0xC24187 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC24187_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC24187].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC24187].fctCallRet = ret;
    /* end of DTC 0xC24187 switch state */

    /* start of DTC 0xC24287 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC24287_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC24287].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC24287].fctCallRet = ret;
    /* end of DTC 0xC24287 switch state */

    /* start of DTC 0xD10B87 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FRT_SEAT_BELT].configGet == 0x8)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD10B87_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD10B87].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD10B87].fctCallRet = ret;
    /* end of DTC 0xD10B87 switch state */

    /* start of DTC 0xD02687 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x5)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD02687_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD02687].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD02687].fctCallRet = ret;
    /* end of DTC 0xD02687 switch state */

#if (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_P05) || (defined GWM_V35_PROJECT_TYPE_A07)
    /* start of DTC 0xC14087 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_STARTING_SYSTEM].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_STARTING_SYSTEM].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC14087_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC14087].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC14087].fctCallRet = ret;
    /* end of DTC 0xC14087 switch state */
#else
    /* start of DTC 0xD00287 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_STARTING_SYSTEM].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_STARTING_SYSTEM].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD00287_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD00287].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD00287].fctCallRet = ret;
    /* end of DTC 0xD00287 switch state */
#endif

    /* start of DTC 0xC16487 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AIR_CONDITIONER].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AIR_CONDITIONER].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AIR_CONDITIONER].configGet == 0x4)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC16487_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC16487].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC16487].fctCallRet = ret;
    /* end of DTC 0xC16487 switch state */

    /* start of DTC 0xC13187 switch state */
    if
    (
        (vConfig.config->kindDatas[VCONFIG_KIND_STEERING_SYSTEM ].configGet == 0x1)
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC13187_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC13187].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC13187].fctCallRet = ret;
    /* end of DTC 0xC13187 switch state */

    /* start of DTC 0xC12887 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_PARKING_BRAKE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC12887_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC12887].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC12887].fctCallRet = ret;
    /* end of DTC 0xC12887 switch state */

    /* start of DTC 0xC20887 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x6)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC20887_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC20887].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC20887].fctCallRet = ret;
    /* end of DTC 0xC20887 switch state */

    /* start of DTC 0xC19987 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DOOR_MODULE_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC19987_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC19987].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC19987].fctCallRet = ret;
    /* end of DTC 0xC19987 switch state */

    /* start of DTC 0xC20087 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DOOR_MODULE_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC20087_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC20087].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC20087].fctCallRet = ret;
    /* end of DTC 0xC20087 switch state */

    /* start of DTC 0xC24687 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x6)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FRT_SEAT__HEATING_LEVEL_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC24687_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC24687].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC24687].fctCallRet = ret;
    /* end of DTC 0xC24687 switch state */

    /* start of DTC 0xC24787 switch state */

        result = FALSE;

    ret = Rte_Call_EventAvailable_0xC24787_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC24787].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC24787].fctCallRet = ret;
    /* end of DTC 0xC24787 switch state */

    /* start of DTC 0xC24387 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x6)
            )
        || 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FRONT_SENSOR].configGet != 0x0)
            )
        || 
            (
                (
                (vConfig.config->kindDatas[VCONFIG_KIND_FRONT_SENSOR].configGet == 0x0)
                )
            && 
                (
                (vConfig.config->kindDatas[VCONFIG_KIND_REAR_PAS_SENSOR].configGet != 0x0)
                )
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC24387_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC24387].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC24387].fctCallRet = ret;
    /* end of DTC 0xC24387 switch state */

    /* start of DTC 0xC2B387 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC2B387_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC2B387].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC2B387].fctCallRet = ret;
    /* end of DTC 0xC2B387 switch state */

    /* start of DTC 0xC19887 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE].configGet == 0xa)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC19887_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC19887].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC19887].fctCallRet = ret;
    /* end of DTC 0xC19887 switch state */

    /* start of DTC 0xC12787 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_TPMS].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC12787_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC12787].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC12787].fctCallRet = ret;
    /* end of DTC 0xC12787 switch state */

    /* start of DTC 0xC29387 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL].configGet == 0xa)
            )
        || 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC29387_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC29387].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC29387].fctCallRet = ret;
    /* end of DTC 0xC29387 switch state */

    /* start of DTC 0xC11187 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC11187_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC11187].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC11187].fctCallRet = ret;
    /* end of DTC 0xC11187 switch state */

    /* start of DTC 0xC1BB87 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL].configGet == 0xa)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC1BB87_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC1BB87].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC1BB87].fctCallRet = ret;
    /* end of DTC 0xC1BB87 switch state */

    /* start of DTC 0xD10887 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_SMART_JUNCTION_BOX].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD10887_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD10887].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD10887].fctCallRet = ret;
    /* end of DTC 0xD10887 switch state */

    /* start of DTC 0xD10987 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_SMART_JUNCTION_BOX].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD10987_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD10987].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD10987].fctCallRet = ret;
    /* end of DTC 0xD10987 switch state */

    /* start of DTC 0xD00487 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x3)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD00487_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD00487].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD00487].fctCallRet = ret;
    /* end of DTC 0xD00487 switch state */

    /* start of DTC 0xC10487 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_HIGHWAY_ASSIST].configGet != 0x1)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC10487_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC10487].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC10487].fctCallRet = ret;
    /* end of DTC 0xC10487 switch state */

    /* start of DTC 0xC14387 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_HIGHWAY_ASSIST].configGet != 0x1)
            )
        && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC14387_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC14387].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC14387].fctCallRet = ret;
    /* end of DTC 0xC14387 switch state */

    /* start of DTC 0xD00987 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_SIDE_STEP].configGet == 0x6)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD00987_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD00987].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD00987].fctCallRet = ret;
    /* end of DTC 0xD00987 switch state */

    /* start of DTC 0xC23087 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_RR_DOOR_OPENING].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_RR_DOOR_OPENING].configGet == 0x3)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC23087_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC23087].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC23087].fctCallRet = ret;
    /* end of DTC 0xC23087 switch state */

    /* start of DTC 0xC15C87 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_HIGHWAY_ASSIST].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC15C87_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC15C87].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC15C87].fctCallRet = ret;
    /* end of DTC 0xC15C87 switch state */

    /* start of DTC 0xC11587 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL].configGet == 0x4)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC11587_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC11587].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC11587].fctCallRet = ret;
    /* end of DTC 0xC11587 switch state */

    /* start of DTC 0xD01587 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_B06)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD01587_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD01587].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD01587].fctCallRet = ret;
    /* end of DTC 0xD01587 switch state */

    /* start of DTC 0xC14187 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRAILING_HOOK].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRAILING_HOOK].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRAILING_HOOK].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRAILING_HOOK].configGet == 0x6)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC14187_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC14187].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC14187].fctCallRet = ret;
    /* end of DTC 0xC14187 switch state */

    /* start of DTC 0xD02987 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_WIRELESS_POWER_CHARGER].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_WIRELESS_POWER_CHARGER].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xD02987_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD02987].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD02987].fctCallRet = ret;
    /* end of DTC 0xD02987 switch state */

    /* start of DTC 0xC11487 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSFER_CASE].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSFER_CASE].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSFER_CASE].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSFER_CASE].configGet == 0x5)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC11487_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC11487].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC11487].fctCallRet = ret;
    /* end of DTC 0xC11487 switch state */

    /* start of DTC 0xC15887 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x3)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC15887_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC15887].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC15887].fctCallRet = ret;
    /* end of DTC 0xC15887 switch state */

    /* start of DTC 0xC23387 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_LANE_CHANGE_ASSIST].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC23387_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC23387].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC23387].fctCallRet = ret;
    /* end of DTC 0xC23387 switch state */

    /* start of DTC 0xC2B587 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC2B587_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC2B587].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC2B587].fctCallRet = ret;
    /* end of DTC 0xC2B587 switch state */

    /* start of DTC 0xC25E87 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_TYPE_OF_BOOSTER_BRAKE_PUMP].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0xC25E87_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xC25E87].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xC25E87].fctCallRet = ret;
    /* end of DTC 0xC25E87 switch state */

    /* start of DTC 0x910511 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910511_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910511].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910511].fctCallRet = ret;
    /* end of DTC 0x910511 switch state */

    /* start of DTC 0x910512 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910512_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910512].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910512].fctCallRet = ret;
    /* end of DTC 0x910512 switch state */

    /* start of DTC 0x910513 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910513_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910513].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910513].fctCallRet = ret;
    /* end of DTC 0x910513 switch state */

    /* start of DTC 0x910611 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DVR].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910611_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910611].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910611].fctCallRet = ret;
    /* end of DTC 0x910611 switch state */

    /* start of DTC 0x910612 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DVR].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910612_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910612].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910612].fctCallRet = ret;
    /* end of DTC 0x910612 switch state */

    /* start of DTC 0x910613 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_DVR].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910613_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910613].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910613].fctCallRet = ret;
    /* end of DTC 0x910613 switch state */

    /* start of DTC 0x910711 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMS_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910711_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910711].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910711].fctCallRet = ret;
    /* end of DTC 0x910711 switch state */

    /* start of DTC 0x910712 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMS_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910712_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910712].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910712].fctCallRet = ret;
    /* end of DTC 0x910712 switch state */

    /* start of DTC 0x910713 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMS_TYPE].configGet == 0x1)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x910713_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910713].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910713].fctCallRet = ret;
    /* end of DTC 0x910713 switch state */

#if (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_P05)
    /* start of DTC 0x9A0811 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0811_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0811].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0811].fctCallRet = ret;
    /* end of DTC 0x9A0811 switch state */

    /* start of DTC 0x9A0812 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0812_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0812].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0812].fctCallRet = ret;
    /* end of DTC 0x9A0812 switch state */

    /* start of DTC 0x9A0813 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0813_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0813].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0813].fctCallRet = ret;
    /* end of DTC 0x9A0813 switch state */

    /* start of DTC 0x9A0819 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2)
            )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    ret = Rte_Call_EventAvailable_0x9A0819_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x9A0819].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x9A0819].fctCallRet = ret;
    /* end of DTC 0x9A0819 switch state */
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            &&(vConfig.config->kindDatas[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM].configGet == 0x1)
            )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }
    ret = Rte_Call_EventAvailable_0x910811_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910811].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910811].fctCallRet = ret;
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            &&(vConfig.config->kindDatas[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM].configGet == 0x1)
            )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }
    ret = Rte_Call_EventAvailable_0x910812_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910812].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910812].fctCallRet = ret;
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            &&(vConfig.config->kindDatas[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM].configGet == 0x1)
            )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }
    ret = Rte_Call_EventAvailable_0x910813_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910813].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910813].fctCallRet = ret;
    if
    (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            &&(vConfig.config->kindDatas[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM].configGet == 0x1)
            )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }
    ret = Rte_Call_EventAvailable_0x910887_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0x910887].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0x910887].fctCallRet = ret;
#endif
#ifdef GWM_V35_PROJECT_TYPE_P05
   /* start of DTC 0xD12387 switch state */
    if
    (
         (vConfig.config->kindDatas[VCONFIG_KIND_WATER_DEPTH_DETECTION].configGet == 0x1)
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }
    ret = Rte_Call_EventAvailable_0xD12387_SetEventAvailable(result);
    dtcSwitchStatus[DTC_SWITCH_0xD12387].calculateResult = result;
    dtcSwitchStatus[DTC_SWITCH_0xD12387].fctCallRet = ret;
    /* end of DTC 0xD12387 switch state */

    /* start of DTC 0x93F511 switch state */
     if
     (
         (
         (vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet != 0x2)
          &&(vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet != 0x3)
         )
     )
     {
          result = TRUE;
     }
     else
     {
          result = FALSE; 
     }
     ret = Rte_Call_EventAvailable_0x93F511_SetEventAvailable(result);
     dtcSwitchStatus[DTC_SWITCH_0x93F511].calculateResult = result;
     dtcSwitchStatus[DTC_SWITCH_0x93F511].fctCallRet = ret;
     /* end of DTC 0x93F511 switch state */

     /* start of DTC 0x93F512 switch state */
     if
     (
        (
        (vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet != 0x2)
         &&(vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet != 0x3)
        )
     )
     {
         result = TRUE;
     }
     else
     {
         result = FALSE; 
     }
     ret = Rte_Call_EventAvailable_0x93F512_SetEventAvailable(result);
     dtcSwitchStatus[DTC_SWITCH_0x93F512].calculateResult = result;
     dtcSwitchStatus[DTC_SWITCH_0x93F512].fctCallRet = ret;
     /* end of DTC 0x93F512 switch state */

     /* start of DTC 0x93F513 switch state */
     if
     (
        (
        (vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet != 0x2)
         &&(vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet != 0x3)
        )
     )
     {
         result = TRUE;
     }
     else
     {
         result = FALSE; 
     }
     ret = Rte_Call_EventAvailable_0x93F513_SetEventAvailable(result);
     dtcSwitchStatus[DTC_SWITCH_0x93F513].calculateResult = result;
     dtcSwitchStatus[DTC_SWITCH_0x93F513].fctCallRet = ret;
     /* end of DTC 0x93F513 switch state */
#endif
}
#endif // (DIAG_USE_DCMEX != TRUE)


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
