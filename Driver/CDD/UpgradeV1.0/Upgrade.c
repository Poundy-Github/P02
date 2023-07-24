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
 *             File:  Upgrade.c
 *           Config:  D:/01.Workspace/20210414/B02/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Upgrade
 *  Generation Time:  2021-04-15 16:12:35
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Upgrade>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
#include "Compiler.h"
#include "IPC_SWUM.h"
#include "Os.h"
#include "uds/Uds.h"
#include "Fcl/Fcl_Api.h"
#include "SysRecKey/SysRecKey.h"
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
 * KEY_TYPE
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

#include "Rte_Upgrade.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * AdjVolUpSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * KEY_TYPE: Enumeration of integer in interval [0...255] with enumerators
 *   UnKey (0U)
 *   AdjVolDwn (1U)
 *   AdjVolUp (2U)
 *   Custom (3U)
 *   CustomMmed (4U)
 *   Enter (5U)
 *   EnterMmed (6U)
 *   Home (7U)
 *   MenuReturn (8U)
 *   Mute (9U)
 *   PageDwn (10U)
 *   PageL (11U)
 *   PageR (12U)
 *   PageUp (13U)
 *   SeekDwn (14U)
 *   SeekUp (15U)
 *   VR (16U)
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
 * PageUpSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalid (3U)
 *
 * Array Types:
 * ============
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * KeyTypeArray: Array with 30 element(s) of type KEY_TYPE
 *
 * Record Types:
 * =============
 * KeyAttribute_st: Record with elements
 *   KeyList of type KeyTypeArray
 *   KeyCnt of type uint8
 *   PressTime of type uint32
 *   PressCnt of type uint8
 *   OnlyKey of type boolean
 *   EventCallout of type uint32
 *   FreeCallout of type uint32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_NvBlockNeed_UpgradeResetFlag_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint32 Rte_CData_NvBlockNeed_UpgradeFlag_DefaultValue(void)
 *   uint32 Rte_CData_NvBlockNeed_UpgradeResetFlag_DefaultValue(void)
 *   uint32 Rte_CData_NvBlockNeed_Upgrade_Flag_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define Upgrade_START_SEC_CODE
#include "Upgrade_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Upgrade_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppSR_Upgrade_System_Recovery_System_Recovery(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_KeyReturn_Server_State(uint8 KeyId, boolean *isPress)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_KeyReturn_Server_disanle(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_KeyReturn_Server_enable(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_KeyReturn_Server_register(const KeyAttribute_st *attribute, uint8 *KeyId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_KeyReturn_Server_remove(uint8 KeyId)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Upgrade_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Upgrade_CODE) Upgrade_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Upgrade_Init
 *********************************************************************************************************************/
    // SysRecKey_Init();
    Rte_Write_Sd_Upgrade_flag_Element(Rte_Upgrade_NvBlockNeed_UpgradeResetFlag_MirrorBlock);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Upgrade_MainFunction
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
 *   Std_ReturnType Rte_Read_AdjVolUpSwtSts_AdjVolUpSwtSts(AdjVolUpSwtSts *data)
 *   Std_ReturnType Rte_Read_PageUpSwtSts_PageUpSwtSts(PageUpSwtSts *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Sd_Upgrade_flag_Element(uint32 data)
 *   Std_ReturnType Rte_Write_ppSR_Upgrade_System_Recovery_System_Recovery(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_KeyReturn_Server_State(uint8 KeyId, boolean *isPress)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_KeyReturn_Server_disanle(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_KeyReturn_Server_enable(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_KeyReturn_Server_register(const KeyAttribute_st *attribute, uint8 *KeyId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_KeyReturn_Server_remove(uint8 KeyId)
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
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_UpgradeResetFlag_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_UpgradeResetFlag_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_UpgradeResetFlag_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_UpgradeResetFlag_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_UpgradeResetFlag_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Upgrade_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Upgrade_CODE) Upgrade_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Upgrade_MainFunction
 *********************************************************************************************************************/
    // SysRecKey_Mainfunction();
    Uds_MainFunction();
    Fcl_MainFunction();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Upgrade_STOP_SEC_CODE
#include "Upgrade_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
void Upgrade_Ipc_UpgrdMsgRcvCall(uint8 msgMajorId, uint8 msgSubId, uint8 *param, uint16 paramLen)
{
    // uint8 object;
    if (IPC_S2M_SWUM_MSGMAJOR_SWUM_UDS_ID == msgMajorId)
    {
        switch (msgSubId)
        {
        case IPC_S2M_SWUM_SWUM_UDS_MSGSUB_SESSIONCONTROL_ID:
            Uds_PushUdsData(param, paramLen);
            break;
        case IPC_S2M_SWUM_SWUM_UDS_MSGSUB_REQUEST_ID:
            Uds_PushUdsData(&(param[2]), (uint32)(paramLen-2));
            break;
        default:
            break;
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
