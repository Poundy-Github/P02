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
 *            Module: SecOC
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecOC_Cfg.h
 *   Generation Time: 2022-03-02 17:10:51
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (SECOC_CFG_H)
# define SECOC_CFG_H
 
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "SecOC_Types.h"
 
/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef SECOC_USE_DUMMY_STATEMENT
#define SECOC_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SECOC_DUMMY_STATEMENT
#define SECOC_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SECOC_DUMMY_STATEMENT_CONST
#define SECOC_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SECOC_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SECOC_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SECOC_ATOMIC_VARIABLE_ACCESS
#define SECOC_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SECOC_PROCESSOR_RH850_1651
#define SECOC_PROCESSOR_RH850_1651
#endif
#ifndef SECOC_COMP_GREENHILLS
#define SECOC_COMP_GREENHILLS
#endif
#ifndef SECOC_GEN_GENERATOR_MSR
#define SECOC_GEN_GENERATOR_MSR
#endif
#ifndef SECOC_CPUTYPE_BITORDER_LSB2MSB
#define SECOC_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SECOC_CONFIGURATION_VARIANT_PRECOMPILE
#define SECOC_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SECOC_CONFIGURATION_VARIANT_LINKTIME
#define SECOC_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SECOC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SECOC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SECOC_CONFIGURATION_VARIANT
#define SECOC_CONFIGURATION_VARIANT SECOC_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SECOC_POSTBUILD_VARIANT_SUPPORT
#define SECOC_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* SecOC APIs */
#define SECOC_COMMUNICATION_INTERFACE     STD_ON  /**< /ActiveEcuC/PduR/SecOC[0:PduRCommunicationInterface] */
#define SECOC_TRANSPORT_PROTOCOL          STD_OFF  /**< /ActiveEcuC/PduR/SecOC[0:PduRTransportProtocol] */
#define SECOC_VERSION_INFO_API            STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCVersionInfoApi] */

#define SECOC_DEV_ERROR_DETECT            STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCSafeBswChecks] || /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCDevErrorDetect] */
#define SECOC_DEV_ERROR_REPORT            STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCDevErrorDetect] */

#define SECOC_TRIGGER_TRANSMIT_API        STD_OFF  /**< /ActiveEcuC/PduR/SecOC[0:PduRTriggertransmit] */
#define SECOC_TX_CONFIRMATION_API         STD_ON  /**< /ActiveEcuC/PduR/SecOC[0:PduRTxConfirmation] */

#define SECOC_USE_GET_RX_FRESHNESS_API    STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseGetRxFreshness] */
#define SECOC_USE_GET_RX_FRESHNESS_AUTH_DATA_API  STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseGetRxFreshnessAuthData] */
#define SECOC_USE_GET_TX_FRESHNESS_API    STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseGetTxFreshness] */
#define SECOC_USE_GET_TX_FRESHNESS_TRUNC_DATA_API STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseGetTxFreshnessTruncData] */

#define SECOC_CANCEL_TRANSMIT_API         STD_OFF  /**< /ActiveEcuC/PduR/SecOC[0:PduRCancelTransmit] */

#define SECOC_IGNORE_VERIFICATION_RESULT  STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOcIgnoreVerificationResult] */

#define SECOC_CUSTOM_AUTHENTICATION_API  STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableCustomAuthenticationAPI] */

#define SECOC_PROPAGATE_ONLY_FINAL_VERIFICATION_STATUS STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCPropagateOnlyFinalVerificationStatus] */

#define SECOC_RETRY_FAILED_TRANSMIT_REQUEST STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCRetryFailedTransmitRequest]*/

#define SECOC_USE_MSB_ALIGNED_TRUNCATED_FRESHNESS_VALUE_IN_FVM STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseMSBAlignedTruncatedFreshnessValueInFvM]*/

#define SECOC_NONE                        0
#define SECOC_CFUNC                       1
#define SECOC_RTE                         2

#define SECOC_ENABLE_FORCED_PASS_OVERRIDESTATUS STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableForcedPassOverride] */
 
#define SECOC_TRUNC_AUTHENTIC_DATA_SIZE_RXPDUS 11
#define SECOC_TRUNC_AUTHENTIC_DATA_SIZE_TXPDUS 6

#define SECOC_TRUNC_FRESHNESS_SIZE_RXPDUS      8
#define SECOC_TRUNC_FRESHNESS_SIZE_TXPDUS      8

#define SECOC_FRESHNESS_SIZE_RXPDUS      8
#define SECOC_FRESHNESS_SIZE_TXPDUS      8
 
#define SECOC_MESSAGE_LINKER_SIZE_RXPDUS 0

#define SECOC_DEFAULT_AUTHENTICATION_INFORMATION_PATTERN 255
 



/**
 * \defgroup SecOCHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SecOCConf_SecOCRxSecuredPdu_ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx 0u
#define SecOCConf_SecOCRxSecuredPdu_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx 1u
#define SecOCConf_SecOCRxSecuredPdu_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx 2u
#define SecOCConf_SecOCRxSecuredPdu_AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx 3u
#define SecOCConf_SecOCRxSecuredPdu_BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx 4u
#define SecOCConf_SecOCRxSecuredPdu_BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx 5u
#define SecOCConf_SecOCRxSecuredPdu_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx 6u
#define SecOCConf_SecOCRxSecuredPdu_GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx 7u
#define SecOCConf_SecOCRxSecuredPdu_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx 8u
#define SecOCConf_SecOCRxSecuredPdu_R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx 9u
#define SecOCConf_SecOCRxSecuredPdu_TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx 10u
#define SecOCConf_SecOCRxSecuredPdu_TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx 11u
#define SecOCConf_SecOCRxSecuredPdu_T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx 12u
#define SecOCConf_SecOCRxSecuredPdu_T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx 13u
/**\} */




/**
 * \defgroup SecOCHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SecOCConf_SecOCTxAuthenticPduLayer_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx 0u
#define SecOCConf_SecOCTxAuthenticPduLayer_HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx 1u
#define SecOCConf_SecOCTxAuthenticPduLayer_IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx 2u
/**\} */




/**
 * \defgroup SecOCHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SecOCConf_SecOCTxSecuredPdu_HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx 0u
#define SecOCConf_SecOCTxSecuredPdu_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx 1u
#define SecOCConf_SecOCTxSecuredPdu_IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx 2u
/**\} */
 
/* User Config File Start */

/* User Config File End */

 
/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
 
 #endif  /* SECOC_CFG_H */
/**********************************************************************************************************************
  END OF FILE: SecOC_Cfg.h
**********************************************************************************************************************/
