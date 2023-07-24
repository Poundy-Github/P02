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
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Cfg.h
 *   Generation Time: 2022-04-12 19:43:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_RH850_1651
#define PDUR_PROCESSOR_RH850_1651
#endif
#ifndef PDUR_COMP_GREENHILLS
#define PDUR_COMP_GREENHILLS
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



#define PDUR_DEV_ERROR_DETECT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_EXTENDED_ERROR_CHECKS STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRExtendedErrorChecks] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

#define PDUR_ERROR_NOTIFICATION STD_OFF

#define PDUR_MAIN_FUNCTION STD_OFF

#define PDUR_MULTICORE STD_OFF /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] */

#define PduR_PBConfigIdType uint32

 
 /*  DET Error define list  */ 
#define PDUR_FCT_CANIFRXIND 0x01u 
#define PDUR_FCT_CANIFTX 0x09u 
#define PDUR_FCT_CANIFTXCFM 0x02u 
#define PDUR_FCT_CANNMRXIND 0x11u 
#define PDUR_FCT_CANNMTX 0x19u 
#define PDUR_FCT_CANNMTXCFM 0x12u 
#define PDUR_FCT_CANNMTT 0x13u 
#define PDUR_FCT_CANTPRXIND 0x05u 
#define PDUR_FCT_CANTPTX 0x09u 
#define PDUR_FCT_CANTPTXCFM 0x08u 
#define PDUR_FCT_CANTPSOR 0x06u 
#define PDUR_FCT_CANTPCPYRX 0x04u 
#define PDUR_FCT_CANTPCPYTX 0x07u 
#define PDUR_FCT_COMTX 0x89u 
#define PDUR_FCT_DCMTX 0x99u 
#define PDUR_FCT_SECOCRXIND 0x71u 
#define PDUR_FCT_SECOCTX 0x79u 
#define PDUR_FCT_SECOCTXCFM 0x72u 
 /*   PduR_CanIfIfRxIndication  PduR_CanIfTransmit  PduR_CanIfTxConfirmation  PduR_CanNmIfRxIndication  PduR_CanNmTransmit  PduR_CanNmTxConfirmation  PduR_CanNmTriggerTransmit  PduR_CanTpTpRxIndication  PduR_CanTpTransmit  PduR_CanTpTxConfirmation  PduR_CanTpStartOfReception  PduR_CanTpCopyRxData  PduR_CanTpCopyTxData  PduR_ComTransmit  PduR_DcmTransmit  PduR_SecOCIfRxIndication  PduR_SecOCTransmit  PduR_SecOCTxConfirmation  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_ABM1_Sc_oB30_for_SC_CAN_V3_2_bdd35fd4_Rx_8d822981_Rx 0u
#define PduRConf_PduRDestPdu_ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx    1u
#define PduRConf_PduRDestPdu_ABM2_oB30_for_SC_CAN_V3_2_5851072c_Rx_bd6a4cb0_Rx 2u
#define PduRConf_PduRDestPdu_ABS1_oB30_for_SC_CAN_V3_2_a04728c8_Rx_ec961e65_Rx 3u
#define PduRConf_PduRDestPdu_ABS2_oB30_for_SC_CAN_V3_2_25753a3c_Rx_5424b305_Rx 4u
#define PduRConf_PduRDestPdu_AC1_oB30_for_SC_CAN_V3_2_3243b46e_Rx_b0ba9a32_Rx 5u
#define PduRConf_PduRDestPdu_AC2_oB30_for_SC_CAN_V3_2_b771a69a_Rx_889f2060_Rx 6u
#define PduRConf_PduRDestPdu_AC3_oB30_for_SC_CAN_V3_2_7d4f5509_Rx_c31e0157_Rx 7u
#define PduRConf_PduRDestPdu_AC4_oB30_for_SC_CAN_V3_2_66648533_Rx_30c11829_Rx 8u
#define PduRConf_PduRDestPdu_AC6_oB30_for_SC_CAN_V3_2_29686454_Rx_e64ce2e4_Rx 9u
#define PduRConf_PduRDestPdu_AC7_oB30_for_SC_CAN_V3_2_e35697c7_Rx_7d545289_Rx 10u
#define PduRConf_PduRDestPdu_AC8_oB30_for_SC_CAN_V3_2_1f3fc420_Rx_554b1989_Rx 11u
#define PduRConf_PduRDestPdu_AC14_oB30_for_SC_CAN_V3_2_a43f90b0_Rx_12ca8017_Rx 12u
#define PduRConf_PduRDestPdu_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_c90195d6_Rx_0408d396_Rx 13u
#define PduRConf_PduRDestPdu_ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx 14u
#define PduRConf_PduRDestPdu_ACC_FD3_oB30_for_SC_CAN_V3_2_e2f593d9_Rx_f74b7e59_Rx 15u
#define PduRConf_PduRDestPdu_ACC_FD4_oB30_for_SC_CAN_V3_2_f9de43e3_Rx_211c2779_Rx 16u
#define PduRConf_PduRDestPdu_AEB_FD1_oB30_for_SC_CAN_V3_2_c284a95c_Rx_c16dc352_Rx 17u
#define PduRConf_PduRDestPdu_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_2f1f8022_Rx_eb545357_Rx 18u
#define PduRConf_PduRDestPdu_AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx 19u
#define PduRConf_PduRDestPdu_ALS1_oB30_for_SC_CAN_V3_2_3dc20185_Rx_96315e5d_Rx 20u
#define PduRConf_PduRDestPdu_AMP1_oB30_for_SC_CAN_V3_2_f94fb5d3_Rx_fd9dde52_Rx 21u
#define PduRConf_PduRDestPdu_AMP2_Sc_oB30_for_SC_CAN_V3_2_2fb79ac1_Rx_fc5d70a1_Rx 22u
#define PduRConf_PduRDestPdu_AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx    23u
#define PduRConf_PduRDestPdu_AMP3_oB30_for_SC_CAN_V3_2_b64354b4_Rx_d7346016_Rx 24u
#define PduRConf_PduRDestPdu_AMP4_ANC1_oB30_for_SC_CAN_V3_2_e4b31b97_Rx_a3a226e0_Rx 25u
#define PduRConf_PduRDestPdu_BCM1_Sc_oB30_for_SC_CAN_V3_2_89b93aaf_Rx_0aa73261_Rx 26u
#define PduRConf_PduRDestPdu_BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx    27u
#define PduRConf_PduRDestPdu_BCM3_Sc_oB30_for_SC_CAN_V3_2_8af269c3_Rx_4e859835_Rx 28u
#define PduRConf_PduRDestPdu_BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx    29u
#define PduRConf_PduRDestPdu_BCM7_oB30_for_SC_CAN_V3_2_70407cea_Rx_2618f07c_Rx 30u
#define PduRConf_PduRDestPdu_BCM8_oB30_for_SC_CAN_V3_2_8c292f0d_Rx_4ea26dbe_Rx 31u
#define PduRConf_PduRDestPdu_BCM11_oB30_for_SC_CAN_V3_2_b554eb73_Rx_4ae12c6a_Rx 32u
#define PduRConf_PduRDestPdu_BCM12_oB30_for_SC_CAN_V3_2_3066f987_Rx_5945cf07_Rx 33u
#define PduRConf_PduRDestPdu_BCM14_oB30_for_SC_CAN_V3_2_e173da2e_Rx_feec0bf6_Rx 34u
#define PduRConf_PduRDestPdu_BCM18_oB30_for_SC_CAN_V3_2_98289b3d_Rx_4b8049e3_Rx 35u
#define PduRConf_PduRDestPdu_BCM19_oB30_for_SC_CAN_V3_2_521668ae_Rx_ff0f949a_Rx 36u
#define PduRConf_PduRDestPdu_BLE1_oB30_for_SC_CAN_V3_2_ba8d2aa5_Rx_dd38072b_Rx 37u
#define PduRConf_PduRDestPdu_BLE5_oB30_for_SC_CAN_V3_2_2494e86b_Rx_3bf59e98_Rx 38u
#define PduRConf_PduRDestPdu_BMS4_oB30_for_SC_CAN_V3_2_15d37a43_Rx_60681d02_Rx 39u
#define PduRConf_PduRDestPdu_BMS8_oB30_for_SC_CAN_V3_2_6c883b50_Rx_04314b70_Rx 40u
#define PduRConf_PduRDestPdu_BMS19_oB30_for_SC_CAN_V3_2_472ce4f3_Rx_f51f0976_Rx 41u
#define PduRConf_PduRDestPdu_BMS22_oB30_for_SC_CAN_V3_2_9f0971cd_Rx_e1c6fd7b_Rx 42u
#define PduRConf_PduRDestPdu_BMS30_oB30_for_SC_CAN_V3_2_b9c96ca7_Rx_7b4ae3ad_Rx 43u
#define PduRConf_PduRDestPdu_BMS35_oB30_for_SC_CAN_V3_2_edee5dfa_Rx_a928d770_Rx 44u
#define PduRConf_PduRDestPdu_BMS65_oB30_for_SC_CAN_V3_2_f8605782_Rx_567eb873_Rx 45u
#define PduRConf_PduRDestPdu_BMS66_oB30_for_SC_CAN_V3_2_7d524576_Rx_bcc5be8a_Rx 46u
#define PduRConf_PduRDestPdu_BMS_FD14_oB30_for_SC_CAN_V3_2_69b2ad5e_Rx_fe5d78f6_Rx 47u
#define PduRConf_PduRDestPdu_CP1_oB30_for_SC_CAN_V3_2_5fdd0f6e_Rx_05f449b1_Rx 48u
#define PduRConf_PduRDestPdu_CR_FD1_oB30_for_SC_CAN_V3_2_ae29d598_Rx_8df8116a_Rx 49u
#define PduRConf_PduRDestPdu_CSA1_oB30_for_SC_CAN_V3_2_a478f17e_Rx_a4a64142_Rx 50u
#define PduRConf_PduRDestPdu_CSA2_oB30_for_SC_CAN_V3_2_214ae38a_Rx_cca3ad41_Rx 51u
#define PduRConf_PduRDestPdu_CSA3_oB30_for_SC_CAN_V3_2_eb741019_Rx_9d6b32ca_Rx 52u
#define PduRConf_PduRDestPdu_DCT3_oB30_for_SC_CAN_V3_2_50b784e2_Rx_2768582c_Rx 53u
#define PduRConf_PduRDestPdu_DCT5_oB30_for_SC_CAN_V3_2_81a2a74b_Rx_57f99d13_Rx 54u
#define PduRConf_PduRDestPdu_DCT_FD4_oB30_for_SC_CAN_V3_2_207dfaa4_Rx_d36fcffa_Rx 55u
#define PduRConf_PduRDestPdu_DDCM1_oB30_for_SC_CAN_V3_2_b3033028_Rx_79c46baf_Rx 56u
#define PduRConf_PduRDestPdu_DDCM3_oB30_for_SC_CAN_V3_2_fc0fd14f_Rx_ad774806_Rx 57u
#define PduRConf_PduRDestPdu_DOCK1_oB30_for_SC_CAN_V3_2_131b892d_Rx_f8ac6ad4_Rx 58u
#define PduRConf_PduRDestPdu_DOCK2_oB30_for_SC_CAN_V3_2_96299bd9_Rx_b60b7e4e_Rx 59u
#define PduRConf_PduRDestPdu_DSC4_oB30_for_SC_CAN_V3_2_27be643b_Rx_859010d7_Rx 60u
#define PduRConf_PduRDestPdu_DSM1_oB30_for_SC_CAN_V3_2_24c7b7e3_Rx_4b2a6812_Rx 61u
#define PduRConf_PduRDestPdu_DWD1_oB30_for_SC_CAN_V3_2_959d6041_Rx_e3728613_Rx 62u
#define PduRConf_PduRDestPdu_EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_9ce048b8_Rx_3dbe82da_Rx 63u
#define PduRConf_PduRDestPdu_ECM1_oB30_for_SC_CAN_V3_2_a52d0341_Rx_1a24f822_Rx 64u
#define PduRConf_PduRDestPdu_ECM2_oB30_for_SC_CAN_V3_2_201f11b5_Rx_d8f14722_Rx 65u
#define PduRConf_PduRDestPdu_ECM3_oB30_for_SC_CAN_V3_2_ea21e226_Rx_e6e62af0_Rx 66u
#define PduRConf_PduRDestPdu_ECM4_oB30_for_SC_CAN_V3_2_f10a321c_Rx_b939ffb6_Rx 67u
#define PduRConf_PduRDestPdu_ECM7_oB30_for_SC_CAN_V3_2_743820e8_Rx_c2625a73_Rx 68u
#define PduRConf_PduRDestPdu_ECM9_oB30_for_SC_CAN_V3_2_426f809c_Rx_3d5474ec_Rx 69u
#define PduRConf_PduRDestPdu_ECM11_oB30_for_SC_CAN_V3_2_5b5ef203_Rx_403eb9f2_Rx 70u
#define PduRConf_PduRDestPdu_ECM16_oB30_for_SC_CAN_V3_2_40752239_Rx_47890b95_Rx 71u
#define PduRConf_PduRDestPdu_ECM19_oB30_for_SC_CAN_V3_2_bc1c71de_Rx_ba5a64c9_Rx 72u
#define PduRConf_PduRDestPdu_ECM20_oB30_for_SC_CAN_V3_2_2b350587_Rx_027a79b1_Rx 73u
#define PduRConf_PduRDestPdu_ECM24_oB30_for_SC_CAN_V3_2_b52cc749_Rx_4ded5b6d_Rx 74u
#define PduRConf_PduRDestPdu_ECM_PT5_oB30_for_SC_CAN_V3_2_21b9a807_Rx_504d8e4d_Rx 75u
#define PduRConf_PduRDestPdu_ECM_PT6_oB30_for_SC_CAN_V3_2_a48bbaf3_Rx_f7d6c790_Rx 76u
#define PduRConf_PduRDestPdu_ECM_PT7_oB30_for_SC_CAN_V3_2_6eb54960_Rx_e6e6b472_Rx 77u
#define PduRConf_PduRDestPdu_EEM1_oB30_for_SC_CAN_V3_2_788fa486_Rx_a19a19e9_Rx 78u
#define PduRConf_PduRDestPdu_ELD1_oB30_for_SC_CAN_V3_2_d7398aaa_Rx_d642fa01_Rx 79u
#define PduRConf_PduRDestPdu_EPB1_oB30_for_SC_CAN_V3_2_9899d01e_Rx_f0fd4aaa_Rx 80u
#define PduRConf_PduRDestPdu_EPS_FD1_oB30_for_SC_CAN_V3_2_a6650fa5_Rx_bbdca1bb_Rx 81u
#define PduRConf_PduRDestPdu_ESCL2_oB30_for_SC_CAN_V3_2_63dcaaa3_Rx_698f1b71_Rx 82u
#define PduRConf_PduRDestPdu_ESP8_oB30_for_SC_CAN_V3_2_cf6f571c_Rx_97f4128e_Rx 83u
#define PduRConf_PduRDestPdu_ESP11_oB30_for_SC_CAN_V3_2_dfa78df9_Rx_e7765f6f_Rx 84u
#define PduRConf_PduRDestPdu_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_dec71f3e_Rx_84656837_Rx 85u
#define PduRConf_PduRDestPdu_ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx 86u
#define PduRConf_PduRDestPdu_ETC2_oB30_for_SC_CAN_V3_2_5474f9a2_Rx_f70df294_Rx 87u
#define PduRConf_PduRDestPdu_ETC3_oB30_for_SC_CAN_V3_2_9e4a0a31_Rx_5bb67826_Rx 88u
#define PduRConf_PduRDestPdu_ETC4_oB30_for_SC_CAN_V3_2_8561da0b_Rx_eef15a54_Rx 89u
#define PduRConf_PduRDestPdu_F_PBOX1_oB30_for_SC_CAN_V3_2_d5db6bdb_Rx_b00d5adc_Rx 90u
#define PduRConf_PduRDestPdu_GLO_NASS1_oB30_for_SC_CAN_V3_2_c0d601c5_Rx_49fe1e9a_Rx 91u
#define PduRConf_PduRDestPdu_GW_FD1_oB30_for_SC_CAN_V3_2_7270e594_Rx_c82f5918_Rx 92u
#define PduRConf_PduRDestPdu_GW_OTA_oB30_for_SC_CAN_V3_2_0f39012b_Rx_32aaa87e_Rx 93u
#define PduRConf_PduRDestPdu_GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_21657c6a_Rx_9dcf459c_Rx 94u
#define PduRConf_PduRDestPdu_GW_Sync_Req_oB30_for_SC_CAN_V3_2_6800966b_Rx 95u
#define PduRConf_PduRDestPdu_HAP_FD1_oB30_for_SC_CAN_V3_2_6083faa7_Rx_2b821b4f_Rx 96u
#define PduRConf_PduRDestPdu_HAP_FD2_oB30_for_SC_CAN_V3_2_e5b1e853_Rx_bcb0e91f_Rx 97u
#define PduRConf_PduRDestPdu_HAP_FD3_oB30_for_SC_CAN_V3_2_2f8f1bc0_Rx_fc620f42_Rx 98u
#define PduRConf_PduRDestPdu_HAP_FD6_oB30_for_SC_CAN_V3_2_7ba82a9d_Rx_2db827e1_Rx 99u
#define PduRConf_PduRDestPdu_HAP_FD7_oB30_for_SC_CAN_V3_2_b196d90e_Rx_9b8498a5_Rx 100u
#define PduRConf_PduRDestPdu_HCM_L1_oB30_for_SC_CAN_V3_2_54b1f0b3_Rx_696d66e7_Rx 101u
#define PduRConf_PduRDestPdu_HCM_L2_oB30_for_SC_CAN_V3_2_d183e247_Rx_baba8622_Rx 102u
#define PduRConf_PduRDestPdu_HCM_R1_oB30_for_SC_CAN_V3_2_2995cda3_Rx_0a0aa92e_Rx 103u
#define PduRConf_PduRDestPdu_HCM_R2_oB30_for_SC_CAN_V3_2_aca7df57_Rx_69d7721a_Rx 104u
#define PduRConf_PduRDestPdu_HCU_FD1_oB30_for_SC_CAN_V3_2_f1a4a259_Rx_41111e75_Rx 105u
#define PduRConf_PduRDestPdu_HCU_HC3_oB30_for_SC_CAN_V3_2_e53a9811_Rx_e2c2cfc0_Rx 106u
#define PduRConf_PduRDestPdu_HCU_HC6_oB30_for_SC_CAN_V3_2_b11da94c_Rx_600d7519_Rx 107u
#define PduRConf_PduRDestPdu_HCU_HC7_oB30_for_SC_CAN_V3_2_7b235adf_Rx_41a1d6df_Rx 108u
#define PduRConf_PduRDestPdu_HCU_HC8_oB30_for_SC_CAN_V3_2_874a0938_Rx_fa951420_Rx 109u
#define PduRConf_PduRDestPdu_HCU_HC16_oB30_for_SC_CAN_V3_2_f8c79c4c_Rx_2b350323_Rx 110u
#define PduRConf_PduRDestPdu_HCU_HP5_oB30_for_SC_CAN_V3_2_a400603a_Rx_a92a2a41_Rx 111u
#define PduRConf_PduRDestPdu_HCU_HP6_oB30_for_SC_CAN_V3_2_213272ce_Rx_e4bf60e1_Rx 112u
#define PduRConf_PduRDestPdu_HCU_HP8_oB30_for_SC_CAN_V3_2_1765d2ba_Rx_b4401e79_Rx 113u
#define PduRConf_PduRDestPdu_HCU_PT4_oB30_for_SC_CAN_V3_2_d214f642_Rx_e5bf4bed_Rx 114u
#define PduRConf_PduRDestPdu_HCU_PT5_oB30_for_SC_CAN_V3_2_182a05d1_Rx_178af415_Rx 115u
#define PduRConf_PduRDestPdu_HCU_PT7_oB30_for_SC_CAN_V3_2_5726e4b6_Rx_e8995c05_Rx 116u
#define PduRConf_PduRDestPdu_HCU_PT8_oB30_for_SC_CAN_V3_2_ab4fb751_Rx_0dc46ad2_Rx 117u
#define PduRConf_PduRDestPdu_HUD1_oB30_for_SC_CAN_V3_2_6397ebab_Rx_9f68183c_Rx 118u
#define PduRConf_PduRDestPdu_IFC1_oB30_for_SC_CAN_V3_2_a7037da8_Rx_2f545f03_Rx 119u
#define PduRConf_PduRDestPdu_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_3e25ea9f_Rx_1086a37c_Rx 120u
#define PduRConf_PduRDestPdu_IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx 121u
#define PduRConf_PduRDestPdu_IFC_FD3_oB30_for_SC_CAN_V3_2_4c625c72_Rx_d6092b8e_Rx 122u
#define PduRConf_PduRDestPdu_IFC_FD5_oB30_for_SC_CAN_V3_2_9d777fdb_Rx_083bbb40_Rx 123u
#define PduRConf_PduRDestPdu_IFC_FD6_oB30_for_SC_CAN_V3_2_18456d2f_Rx_d470f3a2_Rx 124u
#define PduRConf_PduRDestPdu_Ibooster_FD2_oB30_for_SC_CAN_V3_2_055eeaf7_Rx_b05d026c_Rx 125u
#define PduRConf_PduRDestPdu_OBC1_oB30_for_SC_CAN_V3_2_82cd4f59_Rx_5b2f6325_Rx 126u
#define PduRConf_PduRDestPdu_OBC2_oB30_for_SC_CAN_V3_2_07ff5dad_Rx_7dbaec87_Rx 127u
#define PduRConf_PduRDestPdu_P2M1_oB30_for_SC_CAN_V3_2_f19378e0_Rx_27578a55_Rx 128u
#define PduRConf_PduRDestPdu_P2M3_oB30_for_SC_CAN_V3_2_be9f9987_Rx_b5841b10_Rx 129u
#define PduRConf_PduRDestPdu_PDCM1_oB30_for_SC_CAN_V3_2_76a5c7ab_Rx_3e9300cb_Rx 130u
#define PduRConf_PduRDestPdu_PEPS2_oB30_for_SC_CAN_V3_2_8c308c2e_Rx_9304c641_Rx 131u
#define PduRConf_PduRDestPdu_PEPS4_oB30_for_SC_CAN_V3_2_5d25af87_Rx_f3ee8ef3_Rx 132u
#define PduRConf_PduRDestPdu_RFCM_L1_oB30_for_SC_CAN_V3_2_e13f7fa1_Rx_b0c290b6_Rx 133u
#define PduRConf_PduRDestPdu_RFCM_R1_oB30_for_SC_CAN_V3_2_9c1b42b1_Rx_7d041acd_Rx 134u
#define PduRConf_PduRDestPdu_RSDS_FD1_oB30_for_SC_CAN_V3_2_b597372e_Rx_7ec73d99_Rx 135u
#define PduRConf_PduRDestPdu_RSDS_FD2_oB30_for_SC_CAN_V3_2_30a525da_Rx_1479e4f3_Rx 136u
#define PduRConf_PduRDestPdu_R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_4d1c68c6_Rx_6da5275e_Rx 137u
#define PduRConf_PduRDestPdu_R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx 138u
#define PduRConf_PduRDestPdu_SCM1_oB30_for_SC_CAN_V3_2_baaa6d95_Rx_e351b728_Rx 139u
#define PduRConf_PduRDestPdu_TOD1_oB30_for_SC_CAN_V3_2_4faf68bf_Rx_0f6d129e_Rx 140u
#define PduRConf_PduRDestPdu_TPMS1_Sc_oB30_for_SC_CAN_V3_2_026ce1da_Rx_31a98ace_Rx 141u
#define PduRConf_PduRDestPdu_TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx   142u
#define PduRConf_PduRDestPdu_TPMS2_Sc_oB30_for_SC_CAN_V3_2_00821b00_Rx_ddd1fb68_Rx 143u
#define PduRConf_PduRDestPdu_TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx   144u
#define PduRConf_PduRDestPdu_T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_3a52a1a3_Rx_8bd0b3d2_Rx 145u
#define PduRConf_PduRDestPdu_T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx 146u
#define PduRConf_PduRDestPdu_T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_3919f2cf_Rx_3e24f09b_Rx 147u
#define PduRConf_PduRDestPdu_T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx 148u
#define PduRConf_PduRDestPdu_T_BOX_FD4_oB30_for_SC_CAN_V3_2_b9da4418_Rx_096bddaf_Rx 149u
#define PduRConf_PduRDestPdu_T_BOX_FD9_oB30_for_SC_CAN_V3_2_0abff698_Rx_7abf872e_Rx 150u
#define PduRConf_PduRDestPdu_T_BOX_FD10_oB30_for_SC_CAN_V3_2_964515ff_Rx_67c45ddd_Rx 151u
#define PduRConf_PduRDestPdu_Trailer1_oB30_for_SC_CAN_V3_2_f8a7c92e_Rx_4c55e876_Rx 152u
#define PduRConf_PduRDestPdu_VMDR1_oB30_for_SC_CAN_V3_2_01b65f56_Rx_519dd205_Rx 153u
#define PduRConf_PduRDestPdu_WPC1_oB30_for_SC_CAN_V3_2_e844e41f_Rx_b0737289_Rx 154u
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0a0aa92e                       103u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0aa73261                       26u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0dc46ad2                       117u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0f6d129e                       140u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1a24f822                       64u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2b821b4f                       96u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2b350323                       110u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2db827e1                       99u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2f545f03                       119u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3bf59e98                       38u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3d5474ec                       69u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3dbe82da                       63u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3e24f09b                       147u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3e9300cb                       130u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4ae12c6a                       32u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4b2a6812                       61u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4b8049e3                       35u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4bb0d0d6                       138u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4c55e876                       152u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4ded5b6d                       74u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4e859835                       28u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4ea26dbe                       31u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5b2f6325                       126u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5bb67826                       88u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6da5275e                       137u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7abf872e                       150u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7b4ae3ad                       43u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7d041acd                       134u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7d545289                       10u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7dbaec87                       127u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7ec73d99                       135u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8bd0b3d2                       145u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8d822981                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8df8116a                       49u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9b8498a5                       100u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9d6b32ca                       52u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9dcf459c                       94u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9f2d3fb1                       19u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9f68183c                       118u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_05f449b1                       48u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_12ca8017                       12u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_22dd6f7f                       29u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_30c11829                       8u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_31a98ace                       141u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_32aaa87e                       93u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_39a1bd74                       121u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_41a1d6df                       108u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_49fe1e9a                       91u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_57f99d13                       54u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_67c45ddd                       151u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_69d7721a                       104u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_79c46baf                       56u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_97f4128e                       83u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_027a79b1                       73u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_083bbb40                       123u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_096bddaf                       149u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_098f2493                       146u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_118b1947                       148u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_178af415                       115u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_211c2779                       16u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_403eb9f2                       70u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_504d8e4d                       75u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_519dd205                       153u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_554b1989                       11u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_567eb873                       45u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_600d7519                       107u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_696d66e7                       101u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_698f1b71                       82u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_889f2060                       6u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0408d396                       13u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1086a37c                       120u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1479e4f3                       136u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2618f07c                       30u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5424b305                       4u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5945cf07                       33u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9304c641                       131u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_04314b70                       40u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_27578a55                       128u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_41111e75                       105u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_47890b95                       71u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_60681d02                       39u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_94956a34                       142u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_96315e5d                       20u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_859010d7                       60u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2768582c                       53u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_84656837                       85u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a3a226e0                       25u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a4a64142                       50u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a19a19e9                       78u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a92a2a41                       111u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a928d770                       44u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ad774806                       57u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b0ba9a32                       5u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b0c290b6                       133u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b00d5adc                       90u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b05d026c                       125u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b60b7e4e                       59u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b145d381                       23u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b939ffb6                       67u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b4401e79                       113u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b5841b10                       129u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b0737289                       154u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ba5a64c9                       72u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_baba8622                       102u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bbdca1bb                       81u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bcb0e91f                       97u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bcc5be8a                       46u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bd6a4cb0                       2u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c16dc352                       17u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c31e0157                       7u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c82f5918                       92u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c2625a73                       68u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cca3ad41                       51u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d8f14722                       65u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d36fcffa                       55u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d470f3a2                       124u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d642fa01                       79u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d6092b8e                       122u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d83550c6                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d7346016                       24u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dd38072b                       37u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ddd1fb68                       143u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e1c6fd7b                       42u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e2c2cfc0                       106u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e4bf60e1                       112u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e5bf4bed                       114u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e6e6b472                       77u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e6e62af0                       66u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e64ce2e4                       9u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e351b728                       139u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e7765f6f                       84u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e8995c05                       116u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e3728613                       62u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_eb545357                       18u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ec961e65                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_eef15a54                       89u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f0fd4aaa                       80u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f3e4daaa                       27u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f3ee8ef3                       132u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f7d6c790                       76u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f8ac6ad4                       58u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f51f0976                       41u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f58e3bbb                       14u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f70df294                       87u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f74b7e59                       15u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f6108157                       95u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fa951420                       109u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fb298bdb                       86u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fc5d70a1                       22u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fc620f42                       98u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fd9dde52                       21u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fd18d504                       144u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fe5d78f6                       47u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_feec0bf6                       34u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ff0f949a                       36u
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu                                53u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0f850d95                       44u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1f585097                       10u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3a743072                       15u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3fa05c2d                       5u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5e49194f                       35u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6a585e62                       17u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8fde98af                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9d723d5a                       9u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_04ed2d31                       32u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_07e616e9                       31u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_38bf1469                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_76b56aac                       25u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_87aa4973                       51u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_87ca608c                       43u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_95a4b083                       33u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_102e7b25                       20u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_166e979b                       27u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_194d5c53                       12u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_246b4cd2                       42u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_373da34d                       40u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_476d2d57                       2u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2557c8cf                       26u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3497f533                       21u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_26157a10                       7u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_16816632                       13u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_39982944                       39u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_86466688                       45u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a20b870e                       4u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a3417c57                       14u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b4b2a68d                       16u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b19a5ca2                       30u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bb663806                       50u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bee506b7                       11u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c6e0d207                       41u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c088a30b                       29u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c66043fb                       46u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cbf8145f                       22u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ccf5ed2e                       47u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d46dc62c                       24u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d67ab583                       49u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d6198e5a                       18u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d33918c1                       6u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_da813e58                       28u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dab69b66                       48u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dc1a8f7b                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e0ec9ecc                       52u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ed0f687f                       19u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ee72d6e4                       38u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ef1c313e                       23u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f0d8b89d                       36u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f748710b                       34u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fbf75239                       37u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ff58ef59                       8u
#define PduRConf_PduRSrcPdu_SRC_ZCluster_Debug_Msg_0x7AB_Tx           54u
#define PduRConf_PduRSrcPdu_SRC_ZCluster_Debug_Msg_0x7AC_Tx           55u
#define PduRConf_PduRSrcPdu_SRC_ZCluster_Debug_Msg_0x7AD_Tx           56u
#define PduRConf_PduRSrcPdu_SRC_ZCluster_Debug_Msg_0x7AE_Tx           57u
#define PduRConf_PduRSrcPdu_SRC_ZCluster_Debug_Msg_0x7AF_Tx           58u
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DMS_FD1_oB30_for_SC_CAN_V3_2_3b8624c3_Tx 0u
#define PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AB_Tx          52u
#define PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AC_Tx          53u
#define PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AD_Tx          54u
#define PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AE_Tx          55u
#define PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AF_Tx          56u
#define PduRConf_PduRDestPdu_DVR_FD1_oB30_for_SC_CAN_V3_2_d1b20623_Tx 1u
#define PduRConf_PduRDestPdu_HUT1_oB30_for_SC_CAN_V3_2_49ed343e_Tx    2u
#define PduRConf_PduRDestPdu_HUT2_oB30_for_SC_CAN_V3_2_ccdf26ca_Tx    3u
#define PduRConf_PduRDestPdu_HUT3_oB30_for_SC_CAN_V3_2_06e1d559_Tx    4u
#define PduRConf_PduRDestPdu_HUT4_oB30_for_SC_CAN_V3_2_1dca0563_Tx    5u
#define PduRConf_PduRDestPdu_HUT6_oB30_for_SC_CAN_V3_2_52c6e404_Tx    6u
#define PduRConf_PduRDestPdu_HUT7_oB30_for_SC_CAN_V3_2_98f81797_Tx    7u
#define PduRConf_PduRDestPdu_HUT10_oB30_for_SC_CAN_V3_2_5136ad0a_Tx   8u
#define PduRConf_PduRDestPdu_HUT12_oB30_for_SC_CAN_V3_2_1e3a4c6d_Tx   9u
#define PduRConf_PduRDestPdu_HUT13_oB30_for_SC_CAN_V3_2_d404bffe_Tx   10u
#define PduRConf_PduRDestPdu_HUT15_Sc_oB30_for_SC_CAN_V3_2_03f030a3_Tx 11u
#define PduRConf_PduRDestPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx   12u
#define PduRConf_PduRDestPdu_HUT16_oB30_for_SC_CAN_V3_2_80238ea3_Tx   13u
#define PduRConf_PduRDestPdu_HUT17_oB30_for_SC_CAN_V3_2_4a1d7d30_Tx   14u
#define PduRConf_PduRDestPdu_HUT19_oB30_for_SC_CAN_V3_2_7c4add44_Tx   15u
#define PduRConf_PduRDestPdu_HUT20_oB30_for_SC_CAN_V3_2_eb63a91d_Tx   16u
#define PduRConf_PduRDestPdu_HUT21_oB30_for_SC_CAN_V3_2_215d5a8e_Tx   17u
#define PduRConf_PduRDestPdu_HUT22_oB30_for_SC_CAN_V3_2_a46f487a_Tx   18u
#define PduRConf_PduRDestPdu_HUT23_oB30_for_SC_CAN_V3_2_6e51bbe9_Tx   19u
#define PduRConf_PduRDestPdu_HUT25_oB30_for_SC_CAN_V3_2_bf449840_Tx   20u
#define PduRConf_PduRDestPdu_HUT26_oB30_for_SC_CAN_V3_2_3a768ab4_Tx   21u
#define PduRConf_PduRDestPdu_HUT27_oB30_for_SC_CAN_V3_2_f0487927_Tx   22u
#define PduRConf_PduRDestPdu_HUT30_oB30_for_SC_CAN_V3_2_82af5510_Tx   23u
#define PduRConf_PduRDestPdu_HUT31_oB30_for_SC_CAN_V3_2_4891a683_Tx   24u
#define PduRConf_PduRDestPdu_HUT32_oB30_for_SC_CAN_V3_2_cda3b477_Tx   25u
#define PduRConf_PduRDestPdu_HUT33_oB30_for_SC_CAN_V3_2_079d47e4_Tx   26u
#define PduRConf_PduRDestPdu_HUT34_oB30_for_SC_CAN_V3_2_1cb697de_Tx   27u
#define PduRConf_PduRDestPdu_HUT35_oB30_for_SC_CAN_V3_2_d688644d_Tx   28u
#define PduRConf_PduRDestPdu_HUT36_oB30_for_SC_CAN_V3_2_53ba76b9_Tx   29u
#define PduRConf_PduRDestPdu_HUT37_oB30_for_SC_CAN_V3_2_9984852a_Tx   30u
#define PduRConf_PduRDestPdu_HUT38_oB30_for_SC_CAN_V3_2_65edd6cd_Tx   31u
#define PduRConf_PduRDestPdu_HUT39_oB30_for_SC_CAN_V3_2_afd3255e_Tx   32u
#define PduRConf_PduRDestPdu_HUT40_oB30_for_SC_CAN_V3_2_44b8a772_Tx   33u
#define PduRConf_PduRDestPdu_HUT41_oB30_for_SC_CAN_V3_2_8e8654e1_Tx   34u
#define PduRConf_PduRDestPdu_HUT42_oB30_for_SC_CAN_V3_2_0bb44615_Tx   35u
#define PduRConf_PduRDestPdu_HUT43_oB30_for_SC_CAN_V3_2_c18ab586_Tx   36u
#define PduRConf_PduRDestPdu_HUT45_oB30_for_SC_CAN_V3_2_109f962f_Tx   37u
#define PduRConf_PduRDestPdu_HUT46_oB30_for_SC_CAN_V3_2_95ad84db_Tx   38u
#define PduRConf_PduRDestPdu_HUT49_oB30_for_SC_CAN_V3_2_69c4d73c_Tx   39u
#define PduRConf_PduRDestPdu_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_37cb1482_Tx 40u
#define PduRConf_PduRDestPdu_HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx 41u
#define PduRConf_PduRDestPdu_HUT_FD2_oB30_for_SC_CAN_V3_2_19cb507e_Tx 42u
#define PduRConf_PduRDestPdu_HUT_FD3_oB30_for_SC_CAN_V3_2_d3f5a3ed_Tx 43u
#define PduRConf_PduRDestPdu_HUT_FD4_oB30_for_SC_CAN_V3_2_c8de73d7_Tx 44u
#define PduRConf_PduRDestPdu_HUT_FD5_oB30_for_SC_CAN_V3_2_02e08044_Tx 45u
#define PduRConf_PduRDestPdu_HUT_Sync_Req_oB30_for_SC_CAN_V3_2_850087bd_Tx 46u
#define PduRConf_PduRDestPdu_IP1_oB30_for_SC_CAN_V3_2_e24be166_Tx     47u
#define PduRConf_PduRDestPdu_IP2_Sc_oB30_for_SC_CAN_V3_2_3598fa68_Tx  48u
#define PduRConf_PduRDestPdu_IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx     49u
#define PduRConf_PduRDestPdu_IP3_oB30_for_SC_CAN_V3_2_ad470001_Tx     50u
#define PduRConf_PduRDestPdu_PduRDestPdu                              51u
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DiagFuncReq_oB30_for_SC_CAN_V3_2_20_4d8be182_Rx_9ca86fd2_Rx 0u
#define PduRConf_PduRDestPdu_DiagFuncReq_oB30_for_SC_CAN_V3_2_93239eac_Rx_bdc20d60_Rx 1u
#define PduRConf_PduRDestPdu_HUT_Phy_Req_oB30_for_SC_CAN_V3_2_20_98e0d928_Rx_f0c5fe46_Rx 2u
#define PduRConf_PduRDestPdu_HUT_Phy_Req_oB30_for_SC_CAN_V3_2_6551238f_Rx_669c96c2_Rx 3u
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9ca86fd2                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_669c96c2                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bdc20d60                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f0c5fe46                       2u
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_HUT_Phy_Resp_oB30_for_SC_CAN_V3_2_20_e2aa5bb4_Tx 0u
#define PduRConf_PduRDestPdu_HUT_Phy_Resp_oB30_for_SC_CAN_V3_2_69356df1_Tx 1u
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

