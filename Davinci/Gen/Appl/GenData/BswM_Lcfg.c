/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: BswM
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Lcfg.c
 *   Generation Time: 2021-11-29 16:04:08
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ MISRA JUSTIFICATION
 ----------------------------------------------------------------------------- */
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif



#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_vMemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
/*!
 * \brief       Executes a rule.
 * \details     Arbitrates a rule and executes corresponding action list.
 * \param[in]   handleId       Id of the rule to execute.
 * \param[in]   partitionIdx   Current partition context.
 * \return      E_OK      No action list was executed or corresponding action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId,
                                                                   BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
/*!
 * \brief       Updates the state of a rule.
 * \details     Set rule state of passed ruleId to passed state.
 * \param[in]   ruleId         Id of the rule to update.
 * \param[in]   state          New state of the rule.
 * \param[in]   partitionIdx   Current partition context.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, 
                                                              BswM_RuleStatesType state,
                                                              BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
/*!
 * \brief       Updates a timer.
 * \details     Set timer value of passed timerId to passed value and calculates the new state.
 * \param[in]   timerId        Id of the timer to update.
 * \param[in]   value          New value of the timer.
 * \param[in]   partitionIdx   Current partition context. 
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx,
                                                         BswM_SizeOfTimerValueType timerId,
                                                         BswM_TimerValueType value);

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 *  Init
 *********************************************************************************************************************/
/*! \defgroup    Init
 * \{
 */
/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Initializes BswM.
 * \details     Part of the BswM_Init. Initializes all generated variables and executes action lists for initialization.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        May only be called by BswM_Init.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of group Init */

/**********************************************************************************************************************
 *  ImmediateSwcRequest
 *********************************************************************************************************************/
/*! \defgroup    ImmediateSwcRequest
 * \{
 */
/**********************************************************************************************************************
 *  BswM_ImmediateSwcRequest
 *********************************************************************************************************************/
/*!
 * \brief       Arbitrates depending immediate rules of a Swc Mode Request port.
 * \details     Checks if port is valid and arbitrates depending immediate rules.
 * \param[IN]   requestId     Index of a swc mode request port.
 * \param[IN]   partitionIdx  Current partition index
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        Function called by immediate swc request functions (BswMRteRequestFunctions).
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ImmediateSwcRequest(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx, BswM_SizeOfModeRequestMappingType requestId);
/*! \} */ /* End of group ImmediateSwcRequest */

/**********************************************************************************************************************
 *  Common
 *********************************************************************************************************************/
/*! \defgroup    Common
 * \{
 */
/**********************************************************************************************************************
 *  BswM_ModeNotificationFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Switch Modes of RTE and writes RTE values.
 * \details     Forwards a BswM Switch Action to the RTE and writes value of RteRequestPorts to RTE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        May only be called by BswM_MainFunction.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_ModeNotificationFct_BSWM_SINGLEPARTITION(void);
/*! \} */ /* End of group Common */

/**********************************************************************************************************************
 *  SwcModeRequestUpdate
 *********************************************************************************************************************/
/*! \defgroup    SwcModeRequestUpdate
 * \{
 */
/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Reads port values from RTE.
 * \details     Gets the current value of SwcModeRequest Ports and SwcNotification Ports from RTE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        May only be called by BswM_MainFunction.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION(void);
/*! \} */ /* End of group SwcModeRequestUpdate */

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionListFunctions
 * \{
 */

/*!
 * \{
 * \brief       Execute actions of action list.
 * \details     Generated function which depends on the configuration. Executes the actions of the action list in the
 *              configured order.
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A4_ExitRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A11_WaitForNvMToShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A3_WakeupToPrep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A10_WaitForNvMWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A2_1_DemInit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A1_InitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A8_PostRunToPrepShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A7_1_ESH_PostRunToPrepCheck(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A6_ExitPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A9_PrepShutdownToWaitForNvM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A5_RunToPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A2_WakeupToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A7_PostRunToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A12_WaitForNvMToNormalSleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A16_PreToReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A17_PreToSleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A13_PostRunToWait(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_A5_FalseAction(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A18_ReadNvMToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A15_WaitWriteToReadNVM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A19_ReadNVM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmEnable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmDisable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NONE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable_MISC(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit_MISC(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC_HEV(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC_HEV(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMActionListFunctions */
/*! \} */ /* End of group BswMActionListFunctions */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMRuleFunctions
 * \{
 */

/*!
 * \{
 * \brief       Arbitrates the configured rule.
 * \details     Generated function which depends on the configuration. Arbitrates the rule and returns the action list
 *              which shall be executed.
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no ActionList shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R5_RunToPostRunNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R11_WaitToReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R3_WakeupToPrep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R10_WaitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R2_WakeupToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_2_1_DemInit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R1_InitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R8_PostRunToPrepNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R7_PostRunNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R6_PostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R9_PrepToWait(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R4_RunToPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R12_NVMReadToSleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R16_EmergencyReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R17_EmergencySleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R13_PostToWait(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R15_WriteToReadNVM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R18_ReadToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R19_ReadNVM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R1_NORM_TX_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R2_NORM_RX_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R3_NORM_TX_DISABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R4_NORM_RX_DISABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R5_NM_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R6_NORM_TX_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R7_NORM_TX_DISABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMRuleFunctions */
/*! \} */ /* End of group BswMRuleFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_vMemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

/* PRQA S 0779 VARIABLEDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */ 


#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_vMemMap.h"


#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_vMemMap.h"

/* PRQA L:VARIABLEDECLARATIONS */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/


/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BSWM_0310 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element    Description
  FctPtr     Pointer to the array list function.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[33] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FctPtr                                                                                Comment                   Referable Keys */
  { /*     0 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable               },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable] */
  { /*     1 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit          },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit] */
  { /*     2 */ BswM_ActionList_ESH_AL_A4_ExitRun                                              },  /* [Priority: 0] */  /* [AL_ESH_AL_A4_ExitRun] */
  { /*     3 */ BswM_ActionList_ESH_AL_A11_WaitForNvMToShutdown                                },  /* [Priority: 0] */  /* [AL_ESH_AL_A11_WaitForNvMToShutdown] */
  { /*     4 */ BswM_ActionList_ESH_AL_A3_WakeupToPrep                                         },  /* [Priority: 0] */  /* [AL_ESH_AL_A3_WakeupToPrep] */
  { /*     5 */ BswM_ActionList_ESH_AL_A10_WaitForNvMWakeup                                    },  /* [Priority: 0] */  /* [AL_ESH_AL_A10_WaitForNvMWakeup] */
  { /*     6 */ BswM_ActionList_ESH_AL_A2_1_DemInit                                            },  /* [Priority: 0] */  /* [AL_ESH_AL_A2_1_DemInit] */
  { /*     7 */ BswM_ActionList_ESH_AL_A1_InitToWakeup                                         },  /* [Priority: 0] */  /* [AL_ESH_AL_A1_InitToWakeup] */
  { /*     8 */ BswM_ActionList_ESH_AL_A8_PostRunToPrepShutdown                                },  /* [Priority: 0] */  /* [AL_ESH_AL_A8_PostRunToPrepShutdown] */
  { /*     9 */ BswM_ActionList_ESH_AL_A7_1_ESH_PostRunToPrepCheck                             },  /* [Priority: 0] */  /* [AL_ESH_AL_A7_1_ESH_PostRunToPrepCheck] */
  { /*    10 */ BswM_ActionList_ESH_AL_A6_ExitPostRun                                          },  /* [Priority: 0] */  /* [AL_ESH_AL_A6_ExitPostRun] */
  { /*    11 */ BswM_ActionList_ESH_AL_A9_PrepShutdownToWaitForNvM                             },  /* [Priority: 0] */  /* [AL_ESH_AL_A9_PrepShutdownToWaitForNvM] */
  { /*    12 */ BswM_ActionList_INIT_AL_Initialize                                             },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*    13 */ BswM_ActionList_ESH_AL_A5_RunToPostRun                                         },  /* [Priority: 0] */  /* [AL_ESH_AL_A5_RunToPostRun] */
  { /*    14 */ BswM_ActionList_ESH_AL_A2_WakeupToRun                                          },  /* [Priority: 0] */  /* [AL_ESH_AL_A2_WakeupToRun] */
  { /*    15 */ BswM_ActionList_ESH_AL_A7_PostRunToRun                                         },  /* [Priority: 0] */  /* [AL_ESH_AL_A7_PostRunToRun] */
  { /*    16 */ BswM_ActionList_ESH_AL_A12_WaitForNvMToNormalSleep                             },  /* [Priority: 0] */  /* [AL_ESH_AL_A12_WaitForNvMToNormalSleep] */
  { /*    17 */ BswM_ActionList_ESH_AL_A16_PreToReset                                          },  /* [Priority: 0] */  /* [AL_ESH_AL_A16_PreToReset] */
  { /*    18 */ BswM_ActionList_ESH_AL_A17_PreToSleep                                          },  /* [Priority: 0] */  /* [AL_ESH_AL_A17_PreToSleep] */
  { /*    19 */ BswM_ActionList_ESH_AL_A13_PostRunToWait                                       },  /* [Priority: 0] */  /* [AL_ESH_AL_A13_PostRunToWait] */
  { /*    20 */ BswM_ActionList_AL_A5_FalseAction                                              },  /* [Priority: 0] */  /* [AL_AL_A5_FalseAction] */
  { /*    21 */ BswM_ActionList_ESH_AL_A18_ReadNvMToWakeup                                     },  /* [Priority: 0] */  /* [AL_ESH_AL_A18_ReadNvMToWakeup] */
  { /*    22 */ BswM_ActionList_ESH_AL_A15_WaitWriteToReadNVM                                  },  /* [Priority: 0] */  /* [AL_ESH_AL_A15_WaitWriteToReadNVM] */
  { /*    23 */ BswM_ActionList_ESH_AL_A19_ReadNVM                                             },  /* [Priority: 0] */  /* [AL_ESH_AL_A19_ReadNVM] */
  { /*    24 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmEnable                 },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmEnable] */
  { /*    25 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmDisable                },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmDisable] */
  { /*    26 */ BswM_ActionList_AL_NONE                                                        },  /* [Priority: 0] */  /* [AL_AL_NONE] */
  { /*    27 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable_MISC          },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable_MISC] */
  { /*    28 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit_MISC     },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit_MISC] */
  { /*    29 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC          },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC] */
  { /*    30 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC     },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC] */
  { /*    31 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC_HEV },  /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC_HEV] */
  { /*    32 */ BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC_HEV      }   /* [Priority: 0] */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC_HEV] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRules
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRules
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRules[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RulesIdx        Referable Keys */
  { /*     0 */       4u },  /* [R_ESH_R11_WaitToReset] */
  { /*     1 */       5u },  /* [R_ESH_R3_WakeupToPrep] */
  { /*     2 */       6u },  /* [R_ESH_R10_WaitToWakeup] */
  { /*     3 */       7u },  /* [R_ESH_R2_WakeupToRun] */
  { /*     4 */      12u },  /* [R_ESH_R6_PostRun] */
  { /*     5 */      13u },  /* [R_ESH_R9_PrepToWait] */
  { /*     6 */      14u },  /* [R_ESH_R4_RunToPostRun] */
  { /*     7 */      15u },  /* [R_ESH_R12_NVMReadToSleep] */
  { /*     8 */      18u },  /* [R_ESH_R13_PostToWait] */
  { /*     9 */      19u },  /* [R_ESH_R15_WriteToReadNVM] */
  { /*    10 */      20u },  /* [R_ESH_R18_ReadToWakeup] */
  { /*    11 */      21u },  /* [R_ESH_R19_ReadNVM] */
  { /*    12 */      23u },  /* [R_DCMIndication_R1_NORM_TX_ENABLE] */
  { /*    13 */      25u },  /* [R_DCMIndication_R3_NORM_TX_DISABLE] */
  { /*    14 */      28u },  /* [R_DCMIndication_R6_NORM_TX_ENABLE] */
  { /*    15 */      29u }   /* [R_DCMIndication_R7_NORM_TX_DISABLE] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericMapping
**********************************************************************************************************************/
/** 
  \var    BswM_GenericMapping
  \brief  Maps the external id of BswMGenericRequest to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMGenericRequest.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
  InitValue                Initialization value of port.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_GenericMappingType, BSWM_CONST) BswM_GenericMapping[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                            ImmediateUserEndIdx                          ImmediateUserStartIdx                          InitValue                                                            Referable Keys */
  { /*     0 */ BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST },  /* [GENERIC_0, MRP_ESH_ComMPendingRequests] */
  { /*     1 */ BSWM_GENERIC_ESH_DemInitStatus      ,                                          3u,                                            2u, BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_INITIALIZED           },  /* [GENERIC_1, MRP_ESH_DemInitStatus] */
  { /*     2 */ BSWM_GENERIC_ESH_DemPostRunRequested, BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING, BSWM_GENERICVALUE_ESH_DemPostRunRequested_TRUE                },  /* [GENERIC_2, MRP_ESH_DemPostRunRequested] */
  { /*     3 */ BSWM_GENERIC_ESH_NvMReadIndication  , BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING, BSWM_GENERICVALUE_ESH_NvMReadIndication_NVM_READ_OK           },  /* [GENERIC_3, MRP_ESH_NvMReadIndication] */
  { /*     4 */ BSWM_GENERIC_ESH_State              ,                                          4u,                                            3u, BSWM_GENERICVALUE_ESH_State_ESH_INIT                          }   /* [GENERIC_4, MRP_ESH_State] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  MaskedBits          contains bitcoded the boolean data of BswM_OnInitOfImmediateUser, BswM_RulesIndUsedOfImmediateUser
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  RulesIndEndIdx                         RulesIndStartIdx                               Comment                                                                 Referable Keys */
  { /*     0 */      0x01u,                                    9u,                                      0u },  /* [Name: CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b]  */  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, CANSM_CHANNEL_0] */
  { /*     1 */      0x01u,                                   20u,                                      9u },  /* [Name: CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, DCM_COM_0] */
  { /*     2 */      0x00u, BSWM_NO_RULESINDENDIDXOFIMMEDIATEUSER, BSWM_NO_RULESINDSTARTIDXOFIMMEDIATEUSER },  /* [Name: ESH_DemInitStatus]                                   */  /* [MRP_ESH_DemInitStatus, GENERIC_1] */
  { /*     3 */      0x03u,                                   33u,                                     20u },  /* [Name: ESH_State]                                           */  /* [MRP_ESH_State, GENERIC_4] */
  { /*     4 */      0x01u,                                   42u,                                     33u },  /* [Name: PowerModeShutdownReq]                                */  /* [MRP_PowerModeShutdownReq, SWC_REQUEST_2] */
  { /*     5 */      0x01u,                                   43u,                                     42u }   /* [Name: PowerModeShutdownReq_EmergencySleep]                 */  /* [MRP_PowerModeShutdownReq_EmergencySleep, SWC_REQUEST_3] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitGenVarAndInitAL
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_InitGenVarAndInitALType, BSWM_CONST) BswM_InitGenVarAndInitAL[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitGenVarAndInitAL                            */
  /*     0 */ BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeNotificationFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_ModeNotificationFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ModeNotificationFct                            */
  /*     0 */ BswM_ModeNotificationFct_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestMapping
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestMapping
  \brief  Maps the external id of BswMSwcModeRequest to an internal id and references immediate request ports.
  \details
  Element                  Description
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ModeRequestMappingType, BSWM_CONST) BswM_ModeRequestMapping[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ImmediateUserEndIdx                              ImmediateUserStartIdx                                    Referable Keys */
  { /*     0 */ BSWM_NO_IMMEDIATEUSERENDIDXOFMODEREQUESTMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFMODEREQUESTMAPPING },  /* [SWC_REQUEST_0, MRP_CanCommunicationVolEnable] */
  { /*     1 */ BSWM_NO_IMMEDIATEUSERENDIDXOFMODEREQUESTMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFMODEREQUESTMAPPING },  /* [SWC_REQUEST_1, MRP_CanServerBusStateReq] */
  { /*     2 */                                              5u,                                                4u },  /* [SWC_REQUEST_2, MRP_PowerModeShutdownReq] */
  { /*     3 */                                              6u,                                                5u },  /* [SWC_REQUEST_3, MRP_PowerModeShutdownReq_EmergencySleep] */
  { /*     4 */ BSWM_NO_IMMEDIATEUSERENDIDXOFMODEREQUESTMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFMODEREQUESTMAPPING }   /* [SWC_REQUEST_4, MRP_VehicleTypeOptionChoose] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    BswM_PartitionIdentifiers
  \brief  the partition contex in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionIdentifiersType, BSWM_CONST) BswM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          PCPartitionConfigIdx */
  { /*     0 */ BSWM_SINGLEPARTITION,                   0u }
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element          Description
  Id               External id of rule.
  RuleStatesIdx    the index of the 1:1 relation pointing to BswM_RuleStates
  FctPtr           Pointer to the rule function which does the arbitration.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[30] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id   RuleStatesIdx  FctPtr                                                    Referable Keys */
  { /*     0 */  1u,            0u, BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX    },  /* [R_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  { /*     1 */  2u,            1u, BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM },  /* [R_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  { /*     2 */  3u,            2u, BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX    },  /* [R_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  { /*     3 */ 16u,            3u, BswM_Rule_ESH_R5_RunToPostRunNested                },  /* [R_ESH_R5_RunToPostRunNested] */
  { /*     4 */ 22u,            4u, BswM_Rule_ESH_R11_WaitToReset                      },  /* [R_ESH_R11_WaitToReset, MRP_ESH_State, MRP_PowerModeShutdownReq, MRP_ESH_NvMIndication, MRP_ESH_NvM_WriteAllTimer] */
  { /*     5 */ 14u,            5u, BswM_Rule_ESH_R3_WakeupToPrep                      },  /* [R_ESH_R3_WakeupToPrep, MRP_ESH_State, MRP_ESH_NvMIndication, MRP_ESH_NvM_CancelWriteAllTimer, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ModeNotification] */
  { /*     6 */ 21u,            6u, BswM_Rule_ESH_R10_WaitToWakeup                     },  /* [R_ESH_R10_WaitToWakeup, MRP_PowerModeShutdownReq, MRP_ESH_State, MRP_ESH_ComMPendingRequests, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  { /*     7 */ 13u,            7u, BswM_Rule_ESH_R2_WakeupToRun                       },  /* [R_ESH_R2_WakeupToRun, MRP_ESH_State, MRP_ESH_ComMPendingRequests, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_NvMIndication, MRP_ESH_NvM_CancelWriteAllTimer, MRP_ESH_ModeNotification, MRP_CanCommunicationVolEnable] */
  { /*     8 */ 11u,            8u, BswM_Rule_ESH_2_1_DemInit                          },  /* [R_ESH_2_1_DemInit] */
  { /*     9 */ 12u,            9u, BswM_Rule_ESH_R1_InitToWakeup                      },  /* [R_ESH_R1_InitToWakeup, MRP_ESH_State] */
  { /*    10 */ 19u,           10u, BswM_Rule_ESH_R8_PostRunToPrepNested               },  /* [R_ESH_R8_PostRunToPrepNested] */
  { /*    11 */ 18u,           11u, BswM_Rule_ESH_R7_PostRunNested                     },  /* [R_ESH_R7_PostRunNested] */
  { /*    12 */ 17u,           12u, BswM_Rule_ESH_R6_PostRun                           },  /* [R_ESH_R6_PostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_PowerModeShutdownReq] */
  { /*    13 */ 20u,           13u, BswM_Rule_ESH_R9_PrepToWait                        },  /* [R_ESH_R9_PrepToWait, MRP_ESH_State, MRP_ESH_ModeNotification] */
  { /*    14 */ 15u,           14u, BswM_Rule_ESH_R4_RunToPostRun                      },  /* [R_ESH_R4_RunToPostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_PowerModeShutdownReq] */
  { /*    15 */ 23u,           15u, BswM_Rule_ESH_R12_NVMReadToSleep                   },  /* [R_ESH_R12_NVMReadToSleep, MRP_PowerModeShutdownReq, MRP_ESH_State, MRP_ESH_NvMReadIndication, MRP_ESH_NvM_ReadTimer, MRP_ESH_ComMPendingRequests, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  { /*    16 */ 26u,           16u, BswM_Rule_ESH_R16_EmergencyReset                   },  /* [R_ESH_R16_EmergencyReset, MRP_PowerModeShutdownReq] */
  { /*    17 */ 27u,           17u, BswM_Rule_ESH_R17_EmergencySleep                   },  /* [R_ESH_R17_EmergencySleep, MRP_PowerModeShutdownReq_EmergencySleep] */
  { /*    18 */ 24u,           18u, BswM_Rule_ESH_R13_PostToWait                       },  /* [R_ESH_R13_PostToWait, MRP_ESH_ModeNotification, MRP_ESH_State, MRP_PowerModeShutdownReq] */
  { /*    19 */ 25u,           19u, BswM_Rule_ESH_R15_WriteToReadNVM                   },  /* [R_ESH_R15_WriteToReadNVM, MRP_ESH_State, MRP_PowerModeShutdownReq, MRP_ESH_ComMPendingRequests, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_NvMIndication, MRP_ESH_NvM_WriteAllTimer] */
  { /*    20 */ 28u,           20u, BswM_Rule_ESH_R18_ReadToWakeup                     },  /* [R_ESH_R18_ReadToWakeup, MRP_PowerModeShutdownReq, MRP_ESH_State, MRP_ESH_ComMPendingRequests, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  { /*    21 */ 29u,           21u, BswM_Rule_ESH_R19_ReadNVM                          },  /* [R_ESH_R19_ReadNVM, MRP_ESH_State, MRP_ESH_ModeNotification] */
  { /*    22 */  0u,           22u, BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM    },  /* [R_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  { /*    23 */  4u,           23u, BswM_Rule_DCMIndication_R1_NORM_TX_ENABLE          },  /* [R_DCMIndication_R1_NORM_TX_ENABLE, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_VehicleTypeOptionChoose, MRP_CanServerBusStateReq] */
  { /*    24 */  6u,           24u, BswM_Rule_DCMIndication_R2_NORM_RX_ENABLE          },  /* [R_DCMIndication_R2_NORM_RX_ENABLE, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  { /*    25 */  7u,           25u, BswM_Rule_DCMIndication_R3_NORM_TX_DISABLE         },  /* [R_DCMIndication_R3_NORM_TX_DISABLE, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_VehicleTypeOptionChoose] */
  { /*    26 */  9u,           26u, BswM_Rule_DCMIndication_R4_NORM_RX_DISABLE         },  /* [R_DCMIndication_R4_NORM_RX_DISABLE, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  { /*    27 */ 10u,           27u, BswM_Rule_DCMIndication_R5_NM_ENABLE               },  /* [R_DCMIndication_R5_NM_ENABLE, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  { /*    28 */  5u,           28u, BswM_Rule_DCMIndication_R6_NORM_TX_ENABLE          },  /* [R_DCMIndication_R6_NORM_TX_ENABLE, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_VehicleTypeOptionChoose, MRP_CanServerBusStateReq] */
  { /*    29 */  8u,           29u, BswM_Rule_DCMIndication_R7_NORM_TX_DISABLE         }   /* [R_DCMIndication_R7_NORM_TX_DISABLE, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, MRP_VehicleTypeOptionChoose] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[43] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RulesInd      Referable Keys */
  /*     0 */        0u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     1 */        1u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     2 */        2u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     3 */       23u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     4 */       24u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     5 */       25u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     6 */       26u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     7 */       28u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     8 */       29u,  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*     9 */        0u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    10 */        1u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    11 */        2u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    12 */       22u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    13 */       23u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    14 */       24u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    15 */       25u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    16 */       26u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    17 */       27u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    18 */       28u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    19 */       29u,  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */
  /*    20 */        4u,  /* [MRP_ESH_State] */
  /*    21 */        5u,  /* [MRP_ESH_State] */
  /*    22 */        6u,  /* [MRP_ESH_State] */
  /*    23 */        7u,  /* [MRP_ESH_State] */
  /*    24 */        9u,  /* [MRP_ESH_State] */
  /*    25 */       12u,  /* [MRP_ESH_State] */
  /*    26 */       13u,  /* [MRP_ESH_State] */
  /*    27 */       14u,  /* [MRP_ESH_State] */
  /*    28 */       15u,  /* [MRP_ESH_State] */
  /*    29 */       18u,  /* [MRP_ESH_State] */
  /*    30 */       19u,  /* [MRP_ESH_State] */
  /*    31 */       20u,  /* [MRP_ESH_State] */
  /*    32 */       21u,  /* [MRP_ESH_State] */
  /*    33 */        4u,  /* [MRP_PowerModeShutdownReq] */
  /*    34 */        6u,  /* [MRP_PowerModeShutdownReq] */
  /*    35 */       12u,  /* [MRP_PowerModeShutdownReq] */
  /*    36 */       14u,  /* [MRP_PowerModeShutdownReq] */
  /*    37 */       15u,  /* [MRP_PowerModeShutdownReq] */
  /*    38 */       16u,  /* [MRP_PowerModeShutdownReq] */
  /*    39 */       18u,  /* [MRP_PowerModeShutdownReq] */
  /*    40 */       19u,  /* [MRP_PowerModeShutdownReq] */
  /*    41 */       20u,  /* [MRP_PowerModeShutdownReq] */
  /*    42 */       17u   /* [MRP_PowerModeShutdownReq_EmergencySleep] */
};
#define BSWM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SwcModeRequestUpdateFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_SwcModeRequestUpdateFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SwcModeRequestUpdateFct                            */
  /*     0 */ BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ActionListQueueUType, BSWM_VAR_NOINIT) BswM_ActionListQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable] */
  /*     1 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit] */
  /*     2 */  /* [AL_ESH_AL_A4_ExitRun] */
  /*     3 */  /* [AL_ESH_AL_A11_WaitForNvMToShutdown] */
  /*     4 */  /* [AL_ESH_AL_A3_WakeupToPrep] */
  /*     5 */  /* [AL_ESH_AL_A10_WaitForNvMWakeup] */
  /*     6 */  /* [AL_ESH_AL_A2_1_DemInit] */
  /*     7 */  /* [AL_ESH_AL_A1_InitToWakeup] */
  /*     8 */  /* [AL_ESH_AL_A8_PostRunToPrepShutdown] */
  /*     9 */  /* [AL_ESH_AL_A7_1_ESH_PostRunToPrepCheck] */
  /*    10 */  /* [AL_ESH_AL_A6_ExitPostRun] */
  /*    11 */  /* [AL_ESH_AL_A9_PrepShutdownToWaitForNvM] */
  /*    12 */  /* [AL_INIT_AL_Initialize] */
  /*    13 */  /* [AL_ESH_AL_A5_RunToPostRun] */
  /*    14 */  /* [AL_ESH_AL_A2_WakeupToRun] */
  /*    15 */  /* [AL_ESH_AL_A7_PostRunToRun] */
  /*    16 */  /* [AL_ESH_AL_A12_WaitForNvMToNormalSleep] */
  /*    17 */  /* [AL_ESH_AL_A16_PreToReset] */
  /*    18 */  /* [AL_ESH_AL_A17_PreToSleep] */
  /*    19 */  /* [AL_ESH_AL_A13_PostRunToWait] */
  /*    20 */  /* [AL_AL_A5_FalseAction] */
  /*    21 */  /* [AL_ESH_AL_A18_ReadNvMToWakeup] */
  /*    22 */  /* [AL_ESH_AL_A15_WaitWriteToReadNVM] */
  /*    23 */  /* [AL_ESH_AL_A19_ReadNVM] */
  /*    24 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmEnable] */
  /*    25 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmDisable] */
  /*    26 */  /* [AL_AL_NONE] */
  /*    27 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable_MISC] */
  /*    28 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit_MISC] */
  /*    29 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC] */
  /*    30 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC] */
  /*    31 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC_HEV] */
  /*    32 */  /* [AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC_HEV] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_BswMCurrentStateType, BSWM_VAR_NOINIT) BswM_CanSMChannelState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DcmComState
**********************************************************************************************************************/
/** 
  \var    BswM_DcmComState
  \brief  Variable to store current mode of BswMDcmComModeRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dcm_CommunicationModeType, BSWM_VAR_NOINIT) BswM_DcmComState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [DCM_COM_0, MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ForcedActionListPriority
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ForcedActionListPriorityType, BSWM_VAR_NOINIT) BswM_ForcedActionListPriority;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeType, BSWM_VAR_NOINIT) BswM_GenericState[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [GENERIC_0, MRP_ESH_ComMPendingRequests] */
  /*     1 */  /* [GENERIC_1, MRP_ESH_DemInitStatus] */
  /*     2 */  /* [GENERIC_2, MRP_ESH_DemPostRunRequested] */
  /*     3 */  /* [GENERIC_3, MRP_ESH_NvMReadIndication] */
  /*     4 */  /* [GENERIC_4, MRP_ESH_State] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_NOINIT) BswM_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_NOINIT) BswM_ModeRequestQueue[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_DcmComIndication_CN_B30_for_SC_CAN_V3_2_c0d6c67b, DCM_COM_0] */
  /*     2 */  /* [MRP_ESH_DemInitStatus, GENERIC_1] */
  /*     3 */  /* [MRP_ESH_State, GENERIC_4] */
  /*     4 */  /* [MRP_PowerModeShutdownReq, SWC_REQUEST_2] */
  /*     5 */  /* [MRP_PowerModeShutdownReq_EmergencySleep, SWC_REQUEST_3] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_NvMJobState
**********************************************************************************************************************/
/** 
  \var    BswM_NvMJobState
  \brief  Variable to store current mode of BswMNvMJobModeIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(NvM_RequestResultType, BSWM_VAR_NOINIT) BswM_NvMJobState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueSemaphore
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueSemaphoreType, BSWM_VAR_NOINIT) BswM_QueueSemaphore;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueWritten
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueWrittenType, BSWM_VAR_NOINIT) BswM_QueueWritten;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_RuleStatesUType, BSWM_VAR_NOINIT) BswM_RuleStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [R_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX] */
  /*     1 */  /* [R_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM] */
  /*     2 */  /* [R_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX] */
  /*     3 */  /* [R_ESH_R5_RunToPostRunNested] */
  /*     4 */  /* [R_ESH_R11_WaitToReset] */
  /*     5 */  /* [R_ESH_R3_WakeupToPrep] */
  /*     6 */  /* [R_ESH_R10_WaitToWakeup] */
  /*     7 */  /* [R_ESH_R2_WakeupToRun] */
  /*     8 */  /* [R_ESH_2_1_DemInit] */
  /*     9 */  /* [R_ESH_R1_InitToWakeup] */
  /*    10 */  /* [R_ESH_R8_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_R7_PostRunNested] */
  /*    12 */  /* [R_ESH_R6_PostRun] */
  /*    13 */  /* [R_ESH_R9_PrepToWait] */
  /*    14 */  /* [R_ESH_R4_RunToPostRun] */
  /*    15 */  /* [R_ESH_R12_NVMReadToSleep] */
  /*    16 */  /* [R_ESH_R16_EmergencyReset] */
  /*    17 */  /* [R_ESH_R17_EmergencySleep] */
  /*    18 */  /* [R_ESH_R13_PostToWait] */
  /*    19 */  /* [R_ESH_R15_WriteToReadNVM] */
  /*    20 */  /* [R_ESH_R18_ReadToWakeup] */
  /*    21 */  /* [R_ESH_R19_ReadNVM] */
  /*    22 */  /* [R_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM] */
  /*    23 */  /* [R_DCMIndication_R1_NORM_TX_ENABLE] */
  /*    24 */  /* [R_DCMIndication_R2_NORM_RX_ENABLE] */
  /*    25 */  /* [R_DCMIndication_R3_NORM_TX_DISABLE] */
  /*    26 */  /* [R_DCMIndication_R4_NORM_RX_DISABLE] */
  /*    27 */  /* [R_DCMIndication_R5_NM_ENABLE] */
  /*    28 */  /* [R_DCMIndication_R6_NORM_TX_ENABLE] */
  /*    29 */  /* [R_DCMIndication_R7_NORM_TX_DISABLE] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerState
**********************************************************************************************************************/
/** 
  \var    BswM_TimerState
  \brief  Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED).
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_TimerStateUType, BSWM_VAR_NOINIT) BswM_TimerState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_ReadTimer] */
  /*     2 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     3 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerValue
**********************************************************************************************************************/
/** 
  \var    BswM_TimerValue
  \brief  Variable to store current timer values.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_TimerValueUType, BSWM_VAR_NOINIT) BswM_TimerValue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_ReadTimer] */
  /*     2 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     3 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "BswM_vMemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */

#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_vMemMap.h"

VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NOINIT) BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
VAR(boolean, BSWM_VAR_NOINIT) BswM_RteRequest_Provide_BswMRteModeRequestPort_Element;

VAR(BswM_BswMRteShutdownReqMode, BSWM_VAR_NOINIT) Request_PowerModeShutdownReq_requestedMode;
VAR(BswM_BswMRteShutdownReqMode, BSWM_VAR_NOINIT) Request_PowerModeShutdownReq_EmergencySleep_requestedMode;
VAR(BswM_BswMRteVehicleTypeOptionChoose, BSWM_VAR_NOINIT) Request_VehicleTypeOptionChoose_requestedMode;
VAR(BswM_BswMRteModeBusStateReq, BSWM_VAR_NOINIT) Request_CanServerBusStateReq_requestedMode;
VAR(BswM_BswMRteModeVolEnable, BSWM_VAR_NOINIT) Request_CanCommunicationVolEnable_requestedMode;
VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NOINIT) BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode;


VAR(boolean, BSWM_VAR_NOINIT) BswM_PreInitialized;
#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_vMemMap.h"


#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_vMemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */
 

/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType actionListIndex;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if ( BSWM_DEV_ERROR_DETECT == STD_ON )
  if (handleId < BswM_GetSizeOfRules(partitionIdx))
#endif
  {
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    actionListIndex = BswM_GetFctPtrOfRules(handleId, partitionIdx)(partitionIdx); /* SBSW_BSWM_RULEFCTPTR */
    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(actionListIndex < BswM_GetSizeOfActionLists(partitionIdx))
    {
      retVal = BswM_GetFctPtrOfActionLists(actionListIndex, partitionIdx)(partitionIdx); /* SBSW_BSWM_ACTIONLISTFCTPTR */
    }
    else
    {
      retVal = E_OK;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  
  return retVal;
} 

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, 
                                                                   BswM_RuleStatesType state,
                                                                   BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  if (ruleId < BswM_GetSizeOfRuleStates(partitionIdx))
  {
    BswM_SetRuleStates(ruleId, state, partitionIdx); /* SBSW_BSWM_SETRULESTATE */
  }
  
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx,
                                                              BswM_SizeOfTimerValueType timerId,
                                                              BswM_TimerValueType value)
{
  if (timerId < BswM_GetSizeOfTimerValue(partitionIdx))
  {
      SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      BswM_SetTimerValue(timerId, value, partitionIdx); /* SBSW_BSWM_SETTIMER */
      BswM_SetTimerState(timerId, (BswM_TimerStateType)((value != 0u) ? BSWM_TIMER_STARTED : BSWM_TIMER_STOPPED), partitionIdx); /* SBSW_BSWM_SETTIMER */
      SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFFu;
  BswM_RteRequest_Provide_BswMRteModeRequestPort_Element = 0xFFu;
  Request_PowerModeShutdownReq_requestedMode = BswMReqNone;
  Request_PowerModeShutdownReq_EmergencySleep_requestedMode = BswMReqNone;
  Request_VehicleTypeOptionChoose_requestedMode = FUEL;
  Request_CanServerBusStateReq_requestedMode = BLOCK_STATE;
  Request_CanCommunicationVolEnable_requestedMode = Vol_Disable;
  BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_STARTUP;
  (void)BswM_ActionList_INIT_AL_Initialize(partitionIdx);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswMRteRequestFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Read_PowerModeShutdownReq
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Read_PowerModeShutdownReq(void)
{
  (void)Rte_Read_Request_PowerModeShutdownReq_requestedMode(&Request_PowerModeShutdownReq_requestedMode);  /* SBSW_BSWM_RTE_READ */
  BswM_ImmediateSwcRequest(BSWM_SINGLEPARTITION, 2);
}

/**********************************************************************************************************************
 *  BswM_Read_PowerModeShutdownReq_EmergencySleep
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Read_PowerModeShutdownReq_EmergencySleep(void)
{
  (void)Rte_Read_Request_PowerModeShutdownReq_EmergencySleep_requestedMode(&Request_PowerModeShutdownReq_EmergencySleep_requestedMode);  /* SBSW_BSWM_RTE_READ */
  BswM_ImmediateSwcRequest(BSWM_SINGLEPARTITION, 3);
}

/**********************************************************************************************************************
 *  BswM_ImmediateSwcRequest
 *********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ImmediateSwcRequest(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx, BswM_SizeOfModeRequestMappingType requestId)
{
  if(requestId < BswM_GetSizeOfModeRequestMapping(partitionIdx))
  {
    BswM_ImmediateModeRequest(BswM_GetImmediateUserStartIdxOfModeRequestMapping(requestId, partitionIdx), BswM_GetImmediateUserEndIdxOfModeRequestMapping(requestId, partitionIdx), BSWM_SWCREQUESTMODE_ID, partitionIdx);
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_ModeNotificationFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_ModeNotificationFct_BSWM_SINGLEPARTITION(void)
{
  if(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode != 0xFFu)
  {
    if(Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode) == RTE_E_OK)
    {
      BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFFu;
    }
  }
  if(BswM_RteRequest_Provide_BswMRteModeRequestPort_Element != 0xFFu)
  {
    if(Rte_Write_Provide_BswMRteModeRequestPort_Element(BswM_RteRequest_Provide_BswMRteModeRequestPort_Element) == RTE_E_OK)
    {
      BswM_RteRequest_Provide_BswMRteModeRequestPort_Element = 0xFFu;
    }
  }
}

/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION(void)
{
  uint32 mode;
  mode = Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode();
  if (mode != RTE_TRANSITION_ESH_Mode)
  {
    BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = (Rte_ModeType_ESH_Mode)mode;
  }
  (void)Rte_Read_Request_VehicleTypeOptionChoose_requestedMode(&Request_VehicleTypeOptionChoose_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_CanServerBusStateReq_requestedMode(&Request_CanServerBusStateReq_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_CanCommunicationVolEnable_requestedMode(&Request_CanCommunicationVolEnable_requestedMode); /* SBSW_BSWM_RTE_READ */
}

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComEx_DisableRxTimeout();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComEx_EnableRxTimeout();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A4_ExitRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A4_ExitRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  ESH_ComM_CheckPendingRequests();
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_R5_RunToPostRunNested, partitionIdx);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A11_WaitForNvMToShutdown
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A11_WaitForNvMToShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_WriteAllTimer, 0u);
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_SHUTDOWN);
  BswM_ESH_OnEnterShutdown();
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_OFF, 0);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A3_WakeupToPrep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A3_WakeupToPrep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_ESH_OnEnterPrepShutdown();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_SHUTDOWN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A10_WaitForNvMWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A10_WaitForNvMWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_WriteAllTimer, 0u);
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_CancelWriteAllTimer, 6000uL);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_CancelWriteAll();
  /*lint -restore */
  BswM_ESH_OnEnterWakeup();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_WAKEUP;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A2_1_DemInit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A2_1_DemInit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Init(Dem_Config_Ptr);
  /*lint -restore */
  BswM_RequestMode(BSWM_GENERIC_ESH_DemInitStatus, BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_INITIALIZED);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  VConfig_Init();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A1_InitToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A1_InitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_ESH_OnEnterWakeup();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_WAKEUP;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A8_PostRunToPrepShutdown
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A8_PostRunToPrepShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Shutdown();
  /*lint -restore */
  BswM_RequestMode(BSWM_GENERIC_ESH_DemInitStatus, BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_NOT_INITIALIZED);
  BswM_ESH_OnEnterPrepShutdown();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_SHUTDOWN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A7_1_ESH_PostRunToPrepCheck
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A7_1_ESH_PostRunToPrepCheck(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_R8_PostRunToPrepNested, partitionIdx);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A6_ExitPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A6_ExitPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  ESH_ComM_CheckPendingRequests();
  ESH_Dem_PostRunRequested();
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_R7_PostRunNested, partitionIdx);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A9_PrepShutdownToWaitForNvM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A9_PrepShutdownToWaitForNvM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_WriteAllTimer, 6000uL);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_WriteAll();
  /*lint -restore */
  ESH_ComM_CheckPendingRequests();
  BswM_ESH_OnEnterWaitForNvm();
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM);
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_NVMPROCESS;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_INIT_AL_Initialize
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_AL_SetProgrammableInterrupts();
  ReadWakeUpPattern();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Wdg_59_DriverA_Init(WdgSettingsConfig);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTrcv_30_Tja1040_Init(CanTrcv_30_Tja1040_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  LinTrcv_30_Tle7259_Init(LinTrcv_30_Tle7259_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Can_Init(Can_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Crypto_30_vHsm_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Lin_Init(Lin_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanIf_Init(CanIf_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CryIf_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  WdgM_Init(&WdgMConfig_Mode0_core0);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Com_Init(Com_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  PduR_Init(PduR_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SecOC_Init(SecOC_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanSM_Init(CanSM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanNm_Init(CanNm_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Nm_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTp_Init(CanTp_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Csm_Init();
  /*lint -restore */
  BswM_DataFlashStart();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Fls_Init(FlsConfigSet);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Fee_30_SmallSector_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_Init();
  /*lint -restore */
  BswM_INIT_NvMReadAll();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dcm_Init(NULL_PTR);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Init(Dem_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  FvM_Init(FvM_Config_Ptr);
  /*lint -restore */
  BSWMCDDInitCallout();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Rte_Start();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A5_RunToPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A5_RunToPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b, FALSE);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  EcuM_ClearValidatedWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
  /*lint -restore */
  BswM_ESH_OnEnterPostRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_POSTRUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A2_WakeupToRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A2_WakeupToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_CancelWriteAllTimer, 0u);
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_2_1_DemInit, partitionIdx);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b, TRUE);
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_SelfRunRequestTimer, 10uL);
  BswM_ESH_OnEnterRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_RUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_RUN);
  BswM_RteRequest_Provide_BswMRteModeRequestPort_Element = TRUE;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A7_PostRunToRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A7_PostRunToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b, TRUE);
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_SelfRunRequestTimer, 10uL);
  BswM_ESH_OnEnterRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_RUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_RUN);
  BswM_RteRequest_Provide_BswMRteModeRequestPort_Element = TRUE;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A12_WaitForNvMToNormalSleep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A12_WaitForNvMToNormalSleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_WriteAllTimer, 0u);
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_ReadTimer, 0u);
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_SLEEP);
  BswM_ESH_OnEnterShutdown();
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_SLEEP, EcuMConf_EcuMSleepMode_EcuMSleepMode_NormalSleep);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  BswM_Action_PostSleep();
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A16_PreToReset
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A16_PreToReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_SHUTDOWN);
  BswM_ESH_OnEnterShutdown();
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_OFF, 0);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A17_PreToSleep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A17_PreToSleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_SLEEP);
  BswM_ESH_OnEnterShutdown();
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_SLEEP, EcuMConf_EcuMSleepMode_EcuMSleepMode_LviSleep);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  BswM_Action_PostSleep();
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A13_PostRunToWait
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A13_PostRunToWait(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Shutdown();
  /*lint -restore */
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_WriteAllTimer, 6000uL);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_WriteAll();
  /*lint -restore */
  BswM_ESH_OnEnterWaitForNvm();
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_A5_FalseAction
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_A5_FalseAction(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_RteRequest_Provide_BswMRteModeRequestPort_Element = TRUE;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A18_ReadNvMToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A18_ReadNvMToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_ReadTimer, 0u);
  BSWMCancelReadNVM();
  BswM_ESH_OnEnterWakeup();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_WAKEUP;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A15_WaitWriteToReadNVM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A15_WaitWriteToReadNVM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_ReadTimer, 6000uL);
  BSWM_Enter_NVMRead();
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_READ_NVM);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_A19_ReadNVM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_A19_ReadNVM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_Process_NVMRead();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  BSWM_CheckNVMReadStatus();
  ESH_ComM_CheckPendingRequests();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmEnable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmEnable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)Nm_EnableCommunication(ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmDisable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmDisable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)Nm_DisableCommunication(ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NONE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NONE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ;
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable_MISC
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable_MISC(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Rx_4400ad35);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit_MISC
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit_MISC(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Rx_4400ad35, FALSE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_125a0ab3);
  Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_HEV);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_HEV);
  Com_IpduGroupStart(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_125a0ab3, FALSE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC_HEV
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC_HEV(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_125a0ab3);
  Com_IpduGroupStart(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_HEV, FALSE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC_HEV
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC_HEV(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_HEV);
  Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_125a0ab3);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX. */
  if((BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NORM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORMAL) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NORM_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM. */
  if((BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NORM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORMAL) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NORM_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_NONE. */
      retVal = BSWM_ID_AL_AL_NONE;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_DM, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX. */
  if((BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORMAL) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_NONE. */
      retVal = BSWM_ID_AL_AL_NONE;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R5_RunToPostRunNested
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R5_RunToPostRunNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal;
  /* Evaluate logical expression ESH_LE_ComMNoPendingRequests. */
  if((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST) || (Request_PowerModeShutdownReq_requestedMode == BswMReqShutdown))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A5_RunToPostRun. */
    retVal = BSWM_ID_AL_ESH_AL_A5_RunToPostRun;
  }
  else
  {
    /* Return conditional action list BswM_ActionList_AL_A5_FalseAction. */
    retVal = BSWM_ID_AL_AL_A5_FalseAction;
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R11_WaitToReset
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R11_WaitToReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WriteNvMToReset. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (Request_PowerModeShutdownReq_requestedMode == BswMReqShutdown) && ((BswM_GetNvMJobState(0, 0u) != NVM_REQ_PENDING) || (BswM_GetTimerState(2, 0u) != BSWM_TIMER_STARTED)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A11_WaitForNvMToShutdown. */
    retVal = BSWM_ID_AL_ESH_AL_A11_WaitForNvMToShutdown;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R3_WakeupToPrep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R3_WakeupToPrep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WakeupToPrepShutdown. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && ((BswM_GetNvMJobState(0, 0u) != NVM_REQ_PENDING) || (BswM_GetTimerState(0, 0u) != BSWM_TIMER_STARTED)) && (EcuM_GetPendingWakeupEvents() == 0u) && ((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST) && ((EcuM_GetValidatedWakeupEvents() == 0u) || (EcuM_GetValidatedWakeupEvents() == ECUM_WKSOURCE_COMMON_WAKEUP))) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A3_WakeupToPrep. */
    retVal = BSWM_ID_AL_ESH_AL_A3_WakeupToPrep;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R10_WaitToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R10_WaitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WaitForNvMToWakeup. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((Request_PowerModeShutdownReq_requestedMode != BswMReqShutdown) && (BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && ((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST) || ((EcuM_GetValidatedWakeupEvents() != 0u) && (EcuM_GetValidatedWakeupEvents() != ECUM_WKSOURCE_COMMON_WAKEUP))))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A10_WaitForNvMWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_A10_WaitForNvMWakeup;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R2_WakeupToRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R2_WakeupToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WakeupToRun. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && ((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST) || ((EcuM_GetValidatedWakeupEvents() != 0u) && (EcuM_GetValidatedWakeupEvents() != ECUM_WKSOURCE_COMMON_WAKEUP))) && ((BswM_GetNvMJobState(0, 0u) != NVM_REQ_PENDING) || (BswM_GetTimerState(0, 0u) != BSWM_TIMER_STARTED)) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP) && (Request_CanCommunicationVolEnable_requestedMode == Vol_Enable))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A2_WakeupToRun. */
    retVal = BSWM_ID_AL_ESH_AL_A2_WakeupToRun;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_2_1_DemInit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_2_1_DemInit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_DemNotInitialized. */
  if(BswM_GetGenericState(1, 0u) == BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_NOT_INITIALIZED)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A2_1_DemInit. */
    retVal = BSWM_ID_AL_ESH_AL_A2_1_DemInit;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R1_InitToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R1_InitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_InitToWakeup. */
  if(BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_INIT)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A1_InitToWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_A1_InitToWakeup;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R8_PostRunToPrepNested
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R8_PostRunToPrepNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_Dem_PostRunRequested. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(2, 0u) == BSWM_GENERICVALUE_ESH_DemPostRunRequested_FALSE) || (Request_PowerModeShutdownReq_requestedMode == BswMReqShutdown))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A8_PostRunToPrepShutdown. */
    retVal = BSWM_ID_AL_ESH_AL_A8_PostRunToPrepShutdown;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R7_PostRunNested
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R7_PostRunNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal;
  /* Evaluate logical expression ESH_LE_PostRunToRun. */
  if(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST) || ((EcuM_GetValidatedWakeupEvents() != 0u) && (EcuM_GetValidatedWakeupEvents() != ECUM_WKSOURCE_COMMON_WAKEUP))) && (Request_PowerModeShutdownReq_requestedMode != BswMReqShutdown) && (Request_CanCommunicationVolEnable_requestedMode == Vol_Enable))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A7_PostRunToRun. */
    retVal = BSWM_ID_AL_ESH_AL_A7_PostRunToRun;
  }
  else
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A7_1_ESH_PostRunToPrepCheck. */
    retVal = BSWM_ID_AL_ESH_AL_A7_1_ESH_PostRunToPrepCheck;
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R6_PostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R6_PostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_PostRun. */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_POSTRUN) && (Request_PowerModeShutdownReq_requestedMode != BswMReqShutdown))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A6_ExitPostRun. */
    retVal = BSWM_ID_AL_ESH_AL_A6_ExitPostRun;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R9_PrepToWait
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R9_PrepToWait(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_PrepShutdownToWaitForNvM. */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_SHUTDOWN))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A9_PrepShutdownToWaitForNvM. */
    retVal = BSWM_ID_AL_ESH_AL_A9_PrepShutdownToWaitForNvM;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R4_RunToPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R4_RunToPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_RunToPostRunTransition. */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_RUN) && ((Request_PowerModeShutdownReq_requestedMode == BswMReqShutdown) || (Request_PowerModeShutdownReq_requestedMode == BswMReqSleep)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A4_ExitRun. */
    retVal = BSWM_ID_AL_ESH_AL_A4_ExitRun;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R12_NVMReadToSleep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R12_NVMReadToSleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_ReadNvMToSleep. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((Request_PowerModeShutdownReq_requestedMode != BswMReqShutdown) && (BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_READ_NVM) && ((BswM_GetGenericState(3, 0u) != BSWM_GENERICVALUE_ESH_NvMReadIndication_NVM_READ_PENDING) || (BswM_GetTimerState(1, 0u) != BSWM_TIMER_STARTED)) && ((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST) && ((EcuM_GetValidatedWakeupEvents() == 0u) || (EcuM_GetValidatedWakeupEvents() == ECUM_WKSOURCE_COMMON_WAKEUP))))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A12_WaitForNvMToNormalSleep. */
    retVal = BSWM_ID_AL_ESH_AL_A12_WaitForNvMToNormalSleep;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R16_EmergencyReset
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R16_EmergencyReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_Emergency_Reset_Req. */
  if(Request_PowerModeShutdownReq_requestedMode == BswMReqShutdownEmergency)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A16_PreToReset. */
    retVal = BSWM_ID_AL_ESH_AL_A16_PreToReset;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R17_EmergencySleep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R17_EmergencySleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_Emergency_Sleep_Req. */
  if(Request_PowerModeShutdownReq_EmergencySleep_requestedMode == BswMReqSleepEmergency)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A17_PreToSleep. */
    retVal = BSWM_ID_AL_ESH_AL_A17_PreToSleep;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R13_PostToWait
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R13_PostToWait(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_PostRunToWait. */
  if((BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_POSTRUN) && (BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN) && (Request_PowerModeShutdownReq_requestedMode == BswMReqShutdown))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A13_PostRunToWait. */
    retVal = BSWM_ID_AL_ESH_AL_A13_PostRunToWait;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R15_WriteToReadNVM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R15_WriteToReadNVM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WriteToReadNVM. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (Request_PowerModeShutdownReq_requestedMode != BswMReqShutdown) && ((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST) && ((EcuM_GetValidatedWakeupEvents() == 0u) || (EcuM_GetValidatedWakeupEvents() == ECUM_WKSOURCE_COMMON_WAKEUP))) && ((BswM_GetNvMJobState(0, 0u) != NVM_REQ_PENDING) || (BswM_GetTimerState(2, 0u) != BSWM_TIMER_STARTED)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A15_WaitWriteToReadNVM. */
    retVal = BSWM_ID_AL_ESH_AL_A15_WaitWriteToReadNVM;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R18_ReadToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R18_ReadToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_ReadNvMToWakeup. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((Request_PowerModeShutdownReq_requestedMode != BswMReqShutdown) && (BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_READ_NVM) && ((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST) || ((EcuM_GetValidatedWakeupEvents() != 0u) && (EcuM_GetValidatedWakeupEvents() != ECUM_WKSOURCE_COMMON_WAKEUP))))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A18_ReadNvMToWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_A18_ReadNvMToWakeup;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_R19_ReadNVM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_R19_ReadNVM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_NVMRead. */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_READ_NVM) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_NVMPROCESS))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_A19_ReadNVM. */
    retVal = BSWM_ID_AL_ESH_AL_A19_ReadNVM;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM. */
  if((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmDisable. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmDisable;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NM, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_DCMIndication_R1_NORM_TX_ENABLE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R1_NORM_TX_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_DCM_R1. */
  if(((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_ENABLE_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_ENABLE_TX_NORM_NM)) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (Request_VehicleTypeOptionChoose_requestedMode == FUEL) && (Request_CanServerBusStateReq_requestedMode == UNBLOCK_STATE))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_DCMIndication_R1_NORM_TX_ENABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R1_NORM_TX_ENABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R1_NORM_TX_ENABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_DCMIndication_R2_NORM_RX_ENABLE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R2_NORM_RX_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_DCM_R2. */
  if(((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NORM_NM)) && (BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_DCMIndication_R2_NORM_RX_ENABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R2_NORM_RX_ENABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit_MISC. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_EnableNoinit_MISC;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R2_NORM_RX_ENABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_DCMIndication_R3_NORM_TX_DISABLE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R3_NORM_TX_DISABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_DCM_R3. */
  if(((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORMAL) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORM_NM)) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (Request_VehicleTypeOptionChoose_requestedMode == FUEL))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_DCMIndication_R3_NORM_TX_DISABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R3_NORM_TX_DISABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R3_NORM_TX_DISABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_DCMIndication_R4_NORM_RX_DISABLE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R4_NORM_RX_DISABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_DCM_R4. */
  if(((BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_ENABLE_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORMAL) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_ENABLE_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORM_NM)) && (BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_DCMIndication_R4_NORM_RX_DISABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R4_NORM_RX_DISABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable_MISC. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_RX_Disable_MISC;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R4_NORM_RX_DISABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_DCMIndication_R5_NM_ENABLE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R5_NM_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_R5_NM_RX_TX_ENABLE. */
  if((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_DCMIndication_R5_NM_ENABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R5_NM_ENABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmEnable. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_NmEnable;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R5_NM_ENABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_DCMIndication_R6_NORM_TX_ENABLE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R6_NORM_TX_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_DCM_R6. */
  if(((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_ENABLE_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_ENABLE_TX_NORM_NM)) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (Request_VehicleTypeOptionChoose_requestedMode == EV) && (Request_CanServerBusStateReq_requestedMode == UNBLOCK_STATE))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_DCMIndication_R6_NORM_TX_ENABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R6_NORM_TX_ENABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC_HEV. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_EnableNoinit_MISC_HEV;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R6_NORM_TX_ENABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_DCMIndication_R7_NORM_TX_DISABLE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_DCMIndication_R7_NORM_TX_DISABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_DCM_R7. */
  if(((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORMAL) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORM_NM)) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (Request_VehicleTypeOptionChoose_requestedMode == EV))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_DCMIndication_R7_NORM_TX_DISABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R7_NORM_TX_DISABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC_HEV. */
      retVal = BSWM_ID_AL_CC_AL_CN_B30_for_SC_CAN_V3_2_c0d6c67b_TX_Disable_MISC_HEV;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_DCMIndication_R7_NORM_TX_DISABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}


#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_vMemMap.h"

