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
 *             File:  KeyReturn.c
 *           Config:  D:/01.Workspace/20210414/B02/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  KeyReturn
 *  Generation Time:  2021-04-15 16:12:34
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <KeyReturn>
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
 * KEY_TYPE
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_KeyReturn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "KeyReturn_Server.h"

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
 * boolean: Boolean (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * AdjVolDwnSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * AdjVolUpSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * CustomSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * CustomSwtSts_Mmed: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * EnterSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * EnterSwtSts_Mmed: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * HomeSwtSts: Enumeration of integer in interval [0...3] with enumerators
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
 * MenuReturnSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * MuteSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_Error (2U)
 *   Cx3_invalidation (3U)
 * PageDwnSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * PageLSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * PageRSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * PageUpSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalid (3U)
 * SeekDwnSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * SeekUpSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * VRSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 *
 * Array Types:
 * ============
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


#define KeyReturn_START_SEC_CODE
#include "KeyReturn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyReturn_Init
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
 *   Std_ReturnType Rte_Read_AdjVolDwnSwtSts_AdjVolDwnSwtSts(AdjVolDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_AdjVolUpSwtSts_AdjVolUpSwtSts(AdjVolUpSwtSts *data)
 *   Std_ReturnType Rte_Read_CustomSwtSts_CustomSwtSts(CustomSwtSts *data)
 *   Std_ReturnType Rte_Read_CustomSwtSts_Mmed_CustomSwtSts_Mmed(CustomSwtSts_Mmed *data)
 *   Std_ReturnType Rte_Read_EnterSwtSts_EnterSwtSts(EnterSwtSts *data)
 *   Std_ReturnType Rte_Read_EnterSwtSts_Mmed_EnterSwtSts_Mmed(EnterSwtSts_Mmed *data)
 *   Std_ReturnType Rte_Read_HomeSwtSts_HomeSwtSts(HomeSwtSts *data)
 *   Std_ReturnType Rte_Read_MenuReturnSwtSts_MenuReturnSwtSts(MenuReturnSwtSts *data)
 *   Std_ReturnType Rte_Read_MuteSwtSts_MuteSwtSts(MuteSwtSts *data)
 *   Std_ReturnType Rte_Read_PageDwnSwtSts_PageDwnSwtSts(PageDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_PageLSwtSts_PageLSwtSts(PageLSwtSts *data)
 *   Std_ReturnType Rte_Read_PageRSwtSts_PageRSwtSts(PageRSwtSts *data)
 *   Std_ReturnType Rte_Read_PageUpSwtSts_PageUpSwtSts(PageUpSwtSts *data)
 *   Std_ReturnType Rte_Read_SeekDwnSwtSts_SeekDwnSwtSts(SeekDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_SeekUpSwtSts_SeekUpSwtSts(SeekUpSwtSts *data)
 *   Std_ReturnType Rte_Read_VRSwtSts_VRSwtSts(VRSwtSts *data)
 *   boolean Rte_IsUpdated_AdjVolDwnSwtSts_AdjVolDwnSwtSts(void)
 *   boolean Rte_IsUpdated_AdjVolUpSwtSts_AdjVolUpSwtSts(void)
 *   boolean Rte_IsUpdated_CustomSwtSts_CustomSwtSts(void)
 *   boolean Rte_IsUpdated_CustomSwtSts_Mmed_CustomSwtSts_Mmed(void)
 *   boolean Rte_IsUpdated_EnterSwtSts_EnterSwtSts(void)
 *   boolean Rte_IsUpdated_EnterSwtSts_Mmed_EnterSwtSts_Mmed(void)
 *   boolean Rte_IsUpdated_HomeSwtSts_HomeSwtSts(void)
 *   boolean Rte_IsUpdated_MenuReturnSwtSts_MenuReturnSwtSts(void)
 *   boolean Rte_IsUpdated_MuteSwtSts_MuteSwtSts(void)
 *   boolean Rte_IsUpdated_PageDwnSwtSts_PageDwnSwtSts(void)
 *   boolean Rte_IsUpdated_PageLSwtSts_PageLSwtSts(void)
 *   boolean Rte_IsUpdated_PageRSwtSts_PageRSwtSts(void)
 *   boolean Rte_IsUpdated_PageUpSwtSts_PageUpSwtSts(void)
 *   boolean Rte_IsUpdated_SeekDwnSwtSts_SeekDwnSwtSts(void)
 *   boolean Rte_IsUpdated_SeekUpSwtSts_SeekUpSwtSts(void)
 *   boolean Rte_IsUpdated_VRSwtSts_VRSwtSts(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, KeyReturn_CODE) KeyReturn_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Init
 *********************************************************************************************************************/
   //  KR_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyReturn_MainFunction
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
 *   Std_ReturnType Rte_Read_AdjVolDwnSwtSts_AdjVolDwnSwtSts(AdjVolDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_AdjVolUpSwtSts_AdjVolUpSwtSts(AdjVolUpSwtSts *data)
 *   Std_ReturnType Rte_Read_CustomSwtSts_CustomSwtSts(CustomSwtSts *data)
 *   Std_ReturnType Rte_Read_CustomSwtSts_Mmed_CustomSwtSts_Mmed(CustomSwtSts_Mmed *data)
 *   Std_ReturnType Rte_Read_EnterSwtSts_EnterSwtSts(EnterSwtSts *data)
 *   Std_ReturnType Rte_Read_EnterSwtSts_Mmed_EnterSwtSts_Mmed(EnterSwtSts_Mmed *data)
 *   Std_ReturnType Rte_Read_HomeSwtSts_HomeSwtSts(HomeSwtSts *data)
 *   Std_ReturnType Rte_Read_MenuReturnSwtSts_MenuReturnSwtSts(MenuReturnSwtSts *data)
 *   Std_ReturnType Rte_Read_MuteSwtSts_MuteSwtSts(MuteSwtSts *data)
 *   Std_ReturnType Rte_Read_PageDwnSwtSts_PageDwnSwtSts(PageDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_PageLSwtSts_PageLSwtSts(PageLSwtSts *data)
 *   Std_ReturnType Rte_Read_PageRSwtSts_PageRSwtSts(PageRSwtSts *data)
 *   Std_ReturnType Rte_Read_PageUpSwtSts_PageUpSwtSts(PageUpSwtSts *data)
 *   Std_ReturnType Rte_Read_SeekDwnSwtSts_SeekDwnSwtSts(SeekDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_SeekUpSwtSts_SeekUpSwtSts(SeekUpSwtSts *data)
 *   Std_ReturnType Rte_Read_VRSwtSts_VRSwtSts(VRSwtSts *data)
 *   boolean Rte_IsUpdated_AdjVolDwnSwtSts_AdjVolDwnSwtSts(void)
 *   boolean Rte_IsUpdated_AdjVolUpSwtSts_AdjVolUpSwtSts(void)
 *   boolean Rte_IsUpdated_CustomSwtSts_CustomSwtSts(void)
 *   boolean Rte_IsUpdated_CustomSwtSts_Mmed_CustomSwtSts_Mmed(void)
 *   boolean Rte_IsUpdated_EnterSwtSts_EnterSwtSts(void)
 *   boolean Rte_IsUpdated_EnterSwtSts_Mmed_EnterSwtSts_Mmed(void)
 *   boolean Rte_IsUpdated_HomeSwtSts_HomeSwtSts(void)
 *   boolean Rte_IsUpdated_MenuReturnSwtSts_MenuReturnSwtSts(void)
 *   boolean Rte_IsUpdated_MuteSwtSts_MuteSwtSts(void)
 *   boolean Rte_IsUpdated_PageDwnSwtSts_PageDwnSwtSts(void)
 *   boolean Rte_IsUpdated_PageLSwtSts_PageLSwtSts(void)
 *   boolean Rte_IsUpdated_PageRSwtSts_PageRSwtSts(void)
 *   boolean Rte_IsUpdated_PageUpSwtSts_PageUpSwtSts(void)
 *   boolean Rte_IsUpdated_SeekDwnSwtSts_SeekDwnSwtSts(void)
 *   boolean Rte_IsUpdated_SeekUpSwtSts_SeekUpSwtSts(void)
 *   boolean Rte_IsUpdated_VRSwtSts_VRSwtSts(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, KeyReturn_CODE) KeyReturn_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_MainFunction
 *********************************************************************************************************************/
    // KR_MainFunction();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyReturn_Server_State
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <State> of PortPrototype <KeyReturn_Server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void KeyReturn_Server_State(uint8 KeyId, boolean *isPress)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_State_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, KeyReturn_CODE) KeyReturn_Server_State(uint8 KeyId, P2VAR(boolean, AUTOMATIC, RTE_KEYRETURN_APPL_VAR) isPress) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_State
 *********************************************************************************************************************/
   //  KR_State(KeyId, isPress);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyReturn_Server_disanle
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <disanle> of PortPrototype <KeyReturn_Server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void KeyReturn_Server_disanle(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_disanle_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, KeyReturn_CODE) KeyReturn_Server_disanle(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_disanle
 *********************************************************************************************************************/
   //  KR_disable();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyReturn_Server_enable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <enable> of PortPrototype <KeyReturn_Server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void KeyReturn_Server_enable(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_enable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, KeyReturn_CODE) KeyReturn_Server_enable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_enable
 *********************************************************************************************************************/
   //  KR_enable();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyReturn_Server_register
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <register> of PortPrototype <KeyReturn_Server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void KeyReturn_Server_register(const KeyAttribute_st *attribute, uint8 *KeyId)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_register_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, KeyReturn_CODE) KeyReturn_Server_register(P2CONST(KeyAttribute_st, AUTOMATIC, RTE_KEYRETURN_APPL_DATA) attribute, P2VAR(uint8, AUTOMATIC, RTE_KEYRETURN_APPL_VAR) KeyId) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_register
 *********************************************************************************************************************/
   //  KR_register(attribute, KeyId);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyReturn_Server_remove
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <remove> of PortPrototype <KeyReturn_Server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void KeyReturn_Server_remove(uint8 KeyId)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_remove_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, KeyReturn_CODE) KeyReturn_Server_remove(uint8 KeyId) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyReturn_Server_remove
 *********************************************************************************************************************/
   //  KR_remove(KeyId);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define KeyReturn_STOP_SEC_CODE
#include "KeyReturn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
